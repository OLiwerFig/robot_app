#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
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
    ui->refreshButton->setIconSize(QSize(32, 32));

    // Configure serial port
    serialPort->setPortName("/dev/tty.usbmodem1303");
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Connect serial port signal
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // Initialize LED indicator
    ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
    ui->statusLabel->setText("Disconnected");

    // Open serial port
    if (serialPort->open(QIODevice::ReadOnly)) {
        ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");
        ui->statusLabel->setText("Connected");
    } else {
        ui->statusLabel->setText("Disconnected");
        qDebug() << "Error opening serial port";
    }


    // czyta dane
    readTimer = new QTimer(this);
    connect(readTimer, &QTimer::timeout, this, &MainWindow::readSerialData);
    readTimer->start(100); // Read data every 100 ms

    // Sprawdza czy dlej jest polaczenie
    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &MainWindow::refreshConnection);
    refreshTimer->start(5000);

    // funkjca do przycisku refresh
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::refreshConnection);
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
            ui->labelPosX->setText("Pozycja X: " + QString(values[4]));
            ui->labelPosY->setText("Pozycja Y: " + QString(values[5]));
            ui->labelTheta->setText("Kąt Theta: " + QString(values[6]));
            ui->labelTargetX->setText("Target X: " + QString(values[7]));
            ui->labelTargetY->setText("Target Y: " + QString(values[8]));
        }
    }
}


void MainWindow::refreshConnection()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    if (serialPort->open(QIODevice::ReadOnly)) {
        ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");
        ui->statusLabel->setText("Connected");
        qDebug() << "Reopened serial port";
    } else {
        ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
        ui->statusLabel->setText("Disconnected");
        qDebug() << "Error reopening serial port";
    }
}
