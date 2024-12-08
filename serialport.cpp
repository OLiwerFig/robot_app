/**
 * \file serialport.cpp
 * \brief Implementacja klasy serialport.
 */

#include "serialport.h"
#include "mainwindow.h"
#include "draw.h"
#include "ui_mainwindow.h"
#include <QMetaObject>
#include <QSerialPortInfo>
#include <QDataStream>

/**
 * \brief Konstruktor klasy serialport.
 *
 * Inicjalizuje port szeregowy i ustawia połączenia sygnałów z odpowiednimi slotami.
 * Port szeregowy jest dynamicznie tworzony wewnątrz konstruktora.
 *
 * \param parent Wskaźnik na obiekt nadrzędny, zazwyczaj główne okno aplikacji.
 */
serialport::serialport(QObject *parent) : QObject(parent)
{
    serialPort = new QSerialPort(this);

    connect(serialPort, &QSerialPort::readyRead, this, [this]() {
        QList<QByteArray> data;
        while (serialPort->canReadLine()) {
            data.append(serialPort->readLine().trimmed());
        }
        emit serialDataReceived(data);
    });

    connect(serialPort, &QSerialPort::errorOccurred, this, [this](QSerialPort::SerialPortError error) {
        if (error == QSerialPort::ResourceError) {
            serialPort->close();
            emit portStatusChanged(false, "");
        }
    });
}

/**
 * \brief Łączy się z wybranym portem szeregowym.
 *
 * Ustawia parametry portu szeregowego i próbuje otworzyć połączenie.
 *
 * \param portName Nazwa portu szeregowego, który ma być otwarty.
 */
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

/**
 * \brief Odświeża połączenie z portem szeregowym.
 *
 * Ponownie łączy się z portem wybranym w interfejsie użytkownika.
 *
 * \param ui Wskaźnik do interfejsu użytkownika, z którego pobierana jest nazwa portu.
 */
void serialport::refreshConnection(Ui::MainWindow *ui)
{
    connectSerialPort(ui->comboBoxSerialPorts->currentText());
}

/**
 * \brief Wysyła współrzędne celu do portu szeregowego.
 *
 * Konwertuje tekstowe współrzędne na liczby zmiennoprzecinkowe i wysyła je przez port szeregowy.
 *
 * \param ui Wskaźnik do interfejsu użytkownika, z którego pobierane są współrzędne celu.
 */

void serialport::sendTargetCoordinates(Ui::MainWindow *ui)
{
    bool okX, okY;
    float targetX = ui->lineEditTargetX->text().toFloat(&okX);
    float targetY = ui->lineEditTargetY->text().toFloat(&okY);

    if (okX && okY) {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);

        stream.setFloatingPointPrecision(QDataStream::SinglePrecision);
        stream.setByteOrder(QDataStream::LittleEndian);


        stream << static_cast<float>(targetX) << static_cast<float>(targetY);

        data.append('\n');
         serialPort->write(data);

        qDebug() << "Wysłano dane: " << data.toHex();
    } else {
        qDebug() << "Invalid target coordinates";
    }
}


/**
 * \brief Obsługuje odebrane dane szeregowe.
 *
 * Rozdziela otrzymane dane na poszczególne wartości, aktualizuje interfejs użytkownika oraz ścieżkę ruchu na scenie graficznej.
 *
 * \param mainWindow Wskaźnik na główne okno aplikacji, wykorzystywany do wykonania metod w głównym wątku.
 * \param ui Wskaźnik do interfejsu użytkownika, służący do aktualizacji elementów UI.
 * \param scene Wskaźnik do sceny graficznej, na której aktualizowana jest ścieżka.
 * \param pathPoints Lista punktów ścieżki, aktualizowana o nowe punkty.
 * \param pathItems Lista elementów graficznych ścieżki, aktualizowana o nowe elementy.
 * \param values Lista odebranych wartości szeregowych, które są przetwarzane.
 */
void serialport::handleSerialData(MainWindow *mainWindow, Ui::MainWindow *ui, QGraphicsScene *scene, QList<QPointF> &pathPoints, QList<QGraphicsEllipseItem *> &pathItems, const QList<QByteArray> &values)
{
    for (const auto &line : values) {
        QList<QByteArray> splitValues = line.split(' ');

        if (splitValues.size() == 9) {
            QMetaObject::invokeMethod(mainWindow, [ui, scene, &pathPoints, &pathItems, splitValues]() {
                    float speedL = QString(splitValues[0]).toFloat();
                    float speedR = QString(splitValues[1]).toFloat();
                    float pwmL = QString(splitValues[2]).toFloat();
                    float pwmR = QString(splitValues[3]).toFloat();
                    float posX = QString(splitValues[4]).toFloat();
                    float posY = QString(splitValues[5]).toFloat();
                    float theta = QString(splitValues[6]).toFloat();
                    float targetX = QString(splitValues[7]).toFloat();
                    float targetY = QString(splitValues[8]).toFloat();

                    ui->speedLProgressBar->setValue(static_cast<int>(speedL));
                    ui->speedLProgressBar->setFormat(QString("%1").arg(speedL, 0, 'f', 2));

                    ui->speedRProgressBar->setValue(static_cast<int>(speedR));
                    ui->speedRProgressBar->setFormat(QString("%1").arg(speedR, 0, 'f', 2));

                    ui->pwmLProgressBar->setValue(static_cast<int>(pwmL));
                    ui->pwmLProgressBar->setFormat(QString("%1").arg(pwmL, 0, 'f', 2));

                    ui->pwmRProgressBar->setValue(static_cast<int>(pwmR));
                    ui->pwmRProgressBar->setFormat(QString("%1").arg(pwmR, 0, 'f', 2));

                    ui->labelPosX->setText(" X: " + QString::number(posX));
                    ui->labelPosY->setText(" Y: " + QString::number(posY));
                    ui->labelTheta->setText("Theta: " + QString::number(theta, 'f', 2));
                    ui->labelTargetX->setText(" X: " + QString::number(targetX));
                    ui->labelTargetY->setText(" Y: " + QString::number(targetY));

                    Draw::updatePath(ui, scene, pathPoints, pathItems, posX, posY);
                }, Qt::QueuedConnection);
        } else if (splitValues.size() == 2) {
            float targetX = QString(splitValues[0]).toFloat();
            float targetY = QString(splitValues[1]).toFloat();
            qDebug() << "Received echoed target coordinates: X =" << targetX << ", Y =" << targetY;
        } else {
            qDebug() << "Unexpected data size: " << splitValues.size();
        }
    }
}

/**
 * \brief Obsługuje zmianę statusu portu szeregowego.
 *
 * Aktualizuje interfejs użytkownika w zależności od statusu połączenia.
 *
 * \param ui Wskaźnik do interfejsu użytkownika.
 * \param connected Status połączenia (true, jeśli połączony).
 * \param portName Nazwa portu szeregowego, który został połączony lub rozłączony.
 */
void serialport::handlePortStatusChanged(Ui::MainWindow *ui, bool connected, const QString &portName)
{
    if (connected) {
        ui->ledIndicator->setStyleSheet("background-color: green; border-radius: 10px;");
        ui->statusLabel->setText(tr("Connected to ") + portName);
    } else {
        ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
        ui->statusLabel->setText(tr("Disconnected"));
    }
}

/**
 * \brief Wypełnia listę dostępnych portów szeregowych.
 *
 * Pobiera dostępne porty szeregowe i umieszcza je w rozwijanym menu w interfejsie użytkownika.
 *
 * \param ui Wskaźnik do interfejsu użytkownika, w którym aktualizowana jest lista portów.
 */
void serialport::populateAvailablePorts(Ui::MainWindow *ui)
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        ui->comboBoxSerialPorts->addItem(serialPortInfo.portName());
    }
}
