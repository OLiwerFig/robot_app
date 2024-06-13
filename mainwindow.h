#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSerialData();
    void refreshConnection();
    void sendTargetCoordinates();
    void connectSerialPort();
    void clearPathHistory();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QTimer *readTimer;
    QTimer *refreshTimer;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *gridPixmapItem;
    QList<QGraphicsItem*> pathItems;
    QList<QPointF> pathPoints;
};

#endif // MAINWINDOW_H
