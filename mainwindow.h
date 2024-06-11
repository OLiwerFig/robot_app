#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QPushButton>
#include <QLabel>

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

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QTimer *connectionTimer;
    QTimer *readTimer;
    QTimer *refreshTimer;
};

#endif // MAINWINDOW_H
