#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialPort = new QSerialPort(this);

    // Set icon for refresh button
    QIcon refreshIcon(":/images/retry.png");
    ui->refreshButton->setIcon(refreshIcon);
    ui->refreshButton->setIconSize(QSize(24, 24));

    ui->clearButton->setIcon(refreshIcon);
    ui->clearButton->setIconSize(QSize(26, 26));


    QIcon conIcon(":/images/con.jpg");
    ui->buttonConnect->setIcon(conIcon);
    ui->buttonConnect->setIconSize(QSize(32, 32));

    ui->speed_text_L->setText("Prędkość lewego silnika ");
    ui->speed_text_R->setText("Prędkość prawego silnika ");

    ui->pwn_text_L->setText("Wartość wypełnienia PWM prawego silnika ");
    ui->pwn_text_L->setText("Wartość wypełnienia PWM lewego silnika ");

    ui->actualTarget->setText("Aktualny Target ");
    ui->actual_position->setText("Aktualna Pozycja ");
    ui->send_target->setText("Wpisz target ");

    ui->buttonSendTarget->setText("Send");

    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        ui->comboBoxSerialPorts->addItem(serialPortInfo.portName());
    }

    // Connect signals and slots
    connect(ui->buttonConnect, &QPushButton::clicked, this, &MainWindow::connectSerialPort);
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::refreshConnection);
    connect(ui->buttonSendTarget, &QPushButton::clicked, this, &MainWindow::sendTargetCoordinates);
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // Initialize LED indicator
    ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
    ui->statusLabel->setText("Disconnected");

    // Timer to read data from the serial port
    readTimer = new QTimer(this);
    connect(readTimer, &QTimer::timeout, this, &MainWindow::readSerialData);
    readTimer->start(50); // Read data every 50 ms

    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &MainWindow::refreshConnection);
    refreshTimer->start(1000); // Refresh every second

    // Initialize the graphics scene for the map
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-10, -10, 20, 20);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Load the grid image and add it to the scene
    QPixmap gridPixmap(":/images/grid.png"); // Ensure the image path is correct
    gridPixmapItem = scene->addPixmap(gridPixmap);
    gridPixmapItem->setPos(-gridPixmap.width() / 2, -gridPixmap.height() / 2);

    // Draw the coordinate axes
    scene->addLine(-10, 0, 10, 0, QPen(Qt::black)); // X-axis
    scene->addLine(0, -10, 0, 10, QPen(Qt::black)); // Y-axis

    // Connect the clear button
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearPathHistory);

    // Attempt to open serial port on start
    if (serialPort->open(QIODevice::ReadWrite)) { // Change to ReadWrite mode
        ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");
        ui->statusLabel->setText("Connected");
        qDebug() << "Serial port opened successfully";
    } else {
        ui->statusLabel->setText("Disconnected");
        qDebug() << "Error opening serial port";
    }
}

MainWindow::~MainWindow()
{
    serialPort->close();
    delete ui;
}



void MainWindow::readSerialData()
{
    while (serialPort->canReadLine()) {
        QByteArray data = serialPort->readLine().trimmed();
        QList<QByteArray> values = data.split(' ');

        if (values.size() == 9) {
            ui->speedLProgressBar->setValue(QString(values[0]).toFloat());
            ui->speedRProgressBar->setValue(QString(values[1]).toFloat());
            ui->pwmLProgressBar->setValue(QString(values[2]).toFloat());
            ui->pwmRProgressBar->setValue(QString(values[3]).toFloat());
            float posX = QString(values[4]).toFloat();
            float posY = QString(values[5]).toFloat();
            ui->labelPosX->setText(" X: " + QString::number(posX));
            ui->labelPosY->setText(" Y: " + QString::number(posY));
            ui->labelTheta->setText("Theta: " + QString(values[6]));
            ui->labelTargetX->setText(QString(values[7]));
            ui->labelTargetY->setText(QString(values[8]));

            // Add the new position to the path
            QPointF newPoint(posX, posY);
            pathPoints.append(newPoint);

            // Clear path items but keep the gridPixmapItem
            for (auto item : pathItems) {
                scene->removeItem(item);
                delete item;
            }
            pathItems.clear();

            QPen pen(Qt::blue);
            QBrush brush(Qt::blue);
            for (const QPointF &point : pathPoints) {
                QGraphicsEllipseItem *ellipse = scene->addEllipse((point.x()) * 12, (point.y()) * -12, 5, 5, pen, brush);
                pathItems.append(ellipse);
            }

            // Optionally adjust the view to always fit the scene
            //ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        } else if (values.size() == 2) {
            // Echoed target coordinates
            float targetX = QString(values[0]).toFloat();
            float targetY = QString(values[1]).toFloat();
            qDebug() << "Received echoed target coordinates: X =" << targetX << ", Y =" << targetY;
        }
    }
}


void MainWindow::refreshConnection()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    QString selectedPort = ui->comboBoxSerialPorts->currentText();
    serialPort->setPortName(selectedPort);

    if (serialPort->open(QIODevice::ReadWrite)) {
        ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");
        ui->statusLabel->setText("Connected to " + selectedPort);
        qDebug() << "Reopened serial port";
    } else {
        ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
        ui->statusLabel->setText("Disconnected");
        qDebug() << "Error reopening serial port";
    }
}

void MainWindow::sendTargetCoordinates()
{
    bool okX, okY;
    float targetX = ui->lineEditTargetX->text().toFloat(&okX);
    float targetY = ui->lineEditTargetY->text().toFloat(&okY);

    if (okX && okY) {
        QByteArray data;
        data.append(reinterpret_cast<const char*>(&targetX), sizeof(targetX));
        data.append(reinterpret_cast<const char*>(&targetY), sizeof(targetY));
        for (int i = 0; i < 10; i++) serialPort->write(data);
        qDebug() << "Sent new target coordinates";
    } else {
        qDebug() << "Invalid target coordinates";
    }
}

void MainWindow::connectSerialPort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    QString selectedPort = ui->comboBoxSerialPorts->currentText();
    serialPort->setPortName(selectedPort);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");
        ui->statusLabel->setText("Connected to " + selectedPort);
        qDebug() << "Connected to" << selectedPort;
    } else {
        ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
        ui->statusLabel->setText("Disconnected");
        qDebug() << "Error opening serial port" << selectedPort;
    }
}

void MainWindow::clearPathHistory()
{
    // Clear path points
    pathPoints.clear();

    // Remove and delete path items from the scene
    for (auto item : pathItems) {
        scene->removeItem(item);
        delete item;
    }
    pathItems.clear();

    // Re-add the grid pixmap item if necessary
    if (!scene->items().contains(gridPixmapItem)) {
        scene->addItem(gridPixmapItem);
        gridPixmapItem->setPos(-gridPixmapItem->pixmap().width() / 2, -gridPixmapItem->pixmap().height() / 2);
    }

    // Redraw the coordinate axes
    scene->addLine(-10, 0, 10, 0, QPen(Qt::black)); // X-axis
    scene->addLine(0, -10, 0, 10, QPen(Qt::black)); // Y-axis
}


