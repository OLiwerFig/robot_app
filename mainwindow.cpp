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

    // Configure serial port
    serialPort->setPortName("/dev/tty.usbmodem1303");
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Connect serial port signal
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");


    // Open serial port
    if (!serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "Error opening serial port";
        ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
        return;
    }

    timer = new QTimer(this);
    timer->start(100); // Read data every 100 ms
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

        if (values.size() == 7) {
            ui->speedLProgressBar->setValue(QString(values[0]).toFloat());
            ui->speedRProgressBar->setValue(QString(values[1]).toFloat());
            ui->pwmLProgressBar->setValue(QString(values[2]).toFloat());
            ui->pwmRProgressBar->setValue(QString(values[3]).toFloat());
            ui->labelPosX->setText("Pozycja X: " + QString(values[4]));
            ui->labelPosY->setText("Pozycja Y: " + QString(values[5]));
            ui->labelTheta->setText("Kąt Theta: " + QString(values[6]));
        }
    }
}



