#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSerialData();
    void refreshConnection();
    void sendTargetCoordinates();
    void connectSerialPort();
    void clearPathHistory();
    void toggleLanguage();
    void updateTexts();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QTimer *readTimer;
    QTimer *refreshTimer;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *gridPixmapItem;
    QList<QPointF> pathPoints;
    QList<QGraphicsEllipseItem *> pathItems;
    QTranslator *translator;
};

#endif // MAINWINDOW_H
