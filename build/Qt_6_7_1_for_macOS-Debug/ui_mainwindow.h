/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelPosX;
    QLabel *labelPosY;
    QLabel *labelTheta;
    QProgressBar *speedLProgressBar;
    QProgressBar *pwmLProgressBar;
    QProgressBar *speedRProgressBar;
    QProgressBar *pwmRProgressBar;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *ledIndicator;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(962, 534);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelPosX = new QLabel(centralwidget);
        labelPosX->setObjectName("labelPosX");
        labelPosX->setGeometry(QRect(60, 300, 300, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(36);
        labelPosX->setFont(font);
        labelPosY = new QLabel(centralwidget);
        labelPosY->setObjectName("labelPosY");
        labelPosY->setGeometry(QRect(60, 180, 300, 100));
        labelPosY->setFont(font);
        labelTheta = new QLabel(centralwidget);
        labelTheta->setObjectName("labelTheta");
        labelTheta->setGeometry(QRect(60, 60, 300, 100));
        labelTheta->setFont(font);
        labelTheta->setLineWidth(1);
        speedLProgressBar = new QProgressBar(centralwidget);
        speedLProgressBar->setObjectName("speedLProgressBar");
        speedLProgressBar->setGeometry(QRect(450, 270, 400, 60));
        speedLProgressBar->setAutoFillBackground(false);
        speedLProgressBar->setMaximum(100);
        speedLProgressBar->setValue(24);
        pwmLProgressBar = new QProgressBar(centralwidget);
        pwmLProgressBar->setObjectName("pwmLProgressBar");
        pwmLProgressBar->setGeometry(QRect(450, 50, 400, 60));
        pwmLProgressBar->setMaximum(100);
        pwmLProgressBar->setValue(0);
        speedRProgressBar = new QProgressBar(centralwidget);
        speedRProgressBar->setObjectName("speedRProgressBar");
        speedRProgressBar->setGeometry(QRect(450, 360, 400, 60));
        speedRProgressBar->setMaximum(100);
        speedRProgressBar->setValue(24);
        pwmRProgressBar = new QProgressBar(centralwidget);
        pwmRProgressBar->setObjectName("pwmRProgressBar");
        pwmRProgressBar->setGeometry(QRect(450, 140, 400, 60));
        pwmRProgressBar->setMaximum(100);
        pwmRProgressBar->setValue(0);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 20, 400, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(18);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 110, 400, 50));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 240, 300, 50));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(450, 330, 300, 50));
        label_4->setFont(font1);
        ledIndicator = new QLabel(centralwidget);
        ledIndicator->setObjectName("ledIndicator");
        ledIndicator->setGeometry(QRect(30, 20, 30, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 962, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelPosX->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPosY->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTheta->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 wype\305\202nienia PWM lewego silnika ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 wype\305\202nienia PWM prawego silnika ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pr\304\231dko\305\233\304\207 lewego silnika ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Pr\304\231dko\305\233\304\207 prawego silnika ", nullptr));
        ledIndicator->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
