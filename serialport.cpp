#include "serialport.h"
#include "mainwindow.h"
#include "draw.h"
#include <QSerialPortInfo>
#include <QDebug>

serialport::serialport(QObject *parent) : QObject(parent)
{
    serialPort = new QSerialPort(this);

    connect(serialPort, &QSerialPort::readyRead, this, [this]() {
        QList<QByteArray> data;
        while (serialPort->canReadLine()) {
            QByteArray line = serialPort->readLine().trimmed();
            data.append(line);
        }
        emit serialDataReceived(data);
    });

    connect(serialPort, &QSerialPort::errorOccurred, this, [this](QSerialPort::SerialPortError error) {
        if (error == QSerialPort::ResourceError) {
            serialPort->close();
            emit portStatusChanged(false, QString());
        }
    });
}

void serialport::connectSerialPort(const QString &portName)
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        emit portStatusChanged(true, portName);
    } else {
        emit portStatusChanged(false, portName);
    }
}

void serialport::refreshConnection(Ui::MainWindow *ui)
{
    connectSerialPort(ui->comboBoxSerialPorts->currentText());
}

void serialport::sendTargetCoordinates(Ui::MainWindow *ui)
{
    bool okX, okY;
    float targetX = ui->lineEditTargetX->text().toFloat(&okX);
    float targetY = ui->lineEditTargetY->text().toFloat(&okY);

    if (okX && okY) {
        QByteArray data;
        data.append(reinterpret_cast<const char*>(&targetX), sizeof(targetX));
        data.append(reinterpret_cast<const char*>(&targetY), sizeof(targetY));
        for (int i = 0; i < 10; i++) {
            serialPort->write(data);
        }
    } else {
        qDebug() << "Invalid target coordinates";
    }
}

void serialport::handlePortStatusChanged(Ui::MainWindow *ui, bool connected, const QString &portName)
{
    if (connected) {
        ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");
        ui->statusLabel->setText(QObject::tr("Connected to ") + portName);
    } else {
        ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
        ui->statusLabel->setText(QObject::tr("Disconnected"));
    }
}

void serialport::populateAvailablePorts(Ui::MainWindow *ui)
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        ui->comboBoxSerialPorts->addItem(serialPortInfo.portName());
    }
}

void serialport::handleSerialData(Ui::MainWindow *ui, QGraphicsScene *scene, QList<QPointF> &pathPoints, QList<QGraphicsEllipseItem *> &pathItems, const QList<QByteArray> &values)
{
    for (const auto &line : values) {
        QList<QByteArray> splitValues = line.split(' ');

        if (splitValues.size() == 9) {
            ui->speedLProgressBar->setValue(QString(splitValues[0]).toFloat());
            ui->speedRProgressBar->setValue(QString(splitValues[1]).toFloat());
            ui->pwmLProgressBar->setValue(QString(splitValues[2]).toFloat());
            ui->pwmRProgressBar->setValue(QString(splitValues[3]).toFloat());
            float posX = QString(splitValues[4]).toFloat();
            float posY = QString(splitValues[5]).toFloat();
            ui->labelPosX->setText(" X: " + QString::number(posX));
            ui->labelPosY->setText(" Y: " + QString::number(posY));
            ui->labelTheta->setText("Theta: " + QString(splitValues[6]));
            ui->labelTargetX->setText(" X: " + QString(splitValues[7]));
            ui->labelTargetY->setText(" Y: " + QString(splitValues[8]));

            Draw::updatePath(ui, scene, pathPoints, pathItems, posX, posY);
        } else if (splitValues.size() == 2) {
            float targetX = QString(splitValues[0]).toFloat();
            float targetY = QString(splitValues[1]).toFloat();
            qDebug() << "Received echoed target coordinates: X =" << targetX << ", Y =" << targetY;
        } else {
            qDebug() << "Unexpected data size: " << splitValues.size();
        }
    }
}
