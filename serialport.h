#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include "ui_mainwindow.h"

class serialport : public QObject
{
    Q_OBJECT

public:
    explicit serialport(QObject *parent = nullptr);
    void connectSerialPort(const QString &portName);
    void refreshConnection(Ui::MainWindow *ui);
    void sendTargetCoordinates(Ui::MainWindow *ui);
    void handlePortStatusChanged(Ui::MainWindow *ui, bool connected, const QString &portName);
    void populateAvailablePorts(Ui::MainWindow *ui);
    void handleSerialData(Ui::MainWindow *ui, QGraphicsScene *scene, QList<QPointF> &pathPoints, QList<QGraphicsEllipseItem *> &pathItems, const QList<QByteArray> &values);

signals:
    void serialDataReceived(const QList<QByteArray> &data);
    void portStatusChanged(bool connected, const QString &portName);

private:
    QSerialPort *serialPort;
};

#endif // SERIALPORT_H
