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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *ledIndicator;
    QPushButton *refreshButton;
    QLabel *statusLabel;
    QComboBox *comboBoxSerialPorts;
    QPushButton *buttonConnect;
    QLabel *send_target;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTargetX;
    QLabel *labelTargetY;
    QLineEdit *lineEditTargetX;
    QLineEdit *lineEditTargetY;
    QPushButton *buttonSendTarget;
    QLabel *actualTarget;
    QLabel *actual_position;
    QGraphicsView *graphicsView;
    QPushButton *clearButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *pwn_text_L;
    QProgressBar *pwmLProgressBar;
    QLabel *pwn_text_P;
    QProgressBar *pwmRProgressBar;
    QLabel *speed_text_L;
    QProgressBar *speedLProgressBar;
    QLabel *speed_text_R;
    QProgressBar *speedRProgressBar;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPosY;
    QLabel *labelPosX;
    QLabel *labelTheta;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(962, 534);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ledIndicator = new QLabel(centralwidget);
        ledIndicator->setObjectName("ledIndicator");
        ledIndicator->setGeometry(QRect(70, 50, 30, 30));
        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(350, 50, 32, 32));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(110, 50, 230, 30));
        comboBoxSerialPorts = new QComboBox(centralwidget);
        comboBoxSerialPorts->setObjectName("comboBoxSerialPorts");
        comboBoxSerialPorts->setGeometry(QRect(60, 90, 281, 30));
        buttonConnect = new QPushButton(centralwidget);
        buttonConnect->setObjectName("buttonConnect");
        buttonConnect->setGeometry(QRect(350, 90, 30, 30));
        send_target = new QLabel(centralwidget);
        send_target->setObjectName("send_target");
        send_target->setGeometry(QRect(610, 380, 111, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        send_target->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(470, 420, 331, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelTargetX = new QLabel(layoutWidget);
        labelTargetX->setObjectName("labelTargetX");
        labelTargetX->setFont(font);

        horizontalLayout->addWidget(labelTargetX);

        labelTargetY = new QLabel(layoutWidget);
        labelTargetY->setObjectName("labelTargetY");
        labelTargetY->setFont(font);

        horizontalLayout->addWidget(labelTargetY);

        lineEditTargetX = new QLineEdit(layoutWidget);
        lineEditTargetX->setObjectName("lineEditTargetX");

        horizontalLayout->addWidget(lineEditTargetX);

        lineEditTargetY = new QLineEdit(layoutWidget);
        lineEditTargetY->setObjectName("lineEditTargetY");

        horizontalLayout->addWidget(lineEditTargetY);

        buttonSendTarget = new QPushButton(layoutWidget);
        buttonSendTarget->setObjectName("buttonSendTarget");
        buttonSendTarget->setAutoDefault(false);

        horizontalLayout->addWidget(buttonSendTarget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        actualTarget = new QLabel(centralwidget);
        actualTarget->setObjectName("actualTarget");
        actualTarget->setGeometry(QRect(470, 380, 151, 31));
        actualTarget->setFont(font);
        actual_position = new QLabel(centralwidget);
        actual_position->setObjectName("actual_position");
        actual_position->setGeometry(QRect(470, 280, 241, 31));
        actual_position->setFont(font);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(70, 150, 300, 300));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(330, 410, 30, 35));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(470, 40, 391, 221));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pwn_text_L = new QLabel(layoutWidget1);
        pwn_text_L->setObjectName("pwn_text_L");
        pwn_text_L->setFont(font);

        verticalLayout->addWidget(pwn_text_L);

        pwmLProgressBar = new QProgressBar(layoutWidget1);
        pwmLProgressBar->setObjectName("pwmLProgressBar");
        pwmLProgressBar->setMaximum(150);
        pwmLProgressBar->setValue(0);

        verticalLayout->addWidget(pwmLProgressBar);

        pwn_text_P = new QLabel(layoutWidget1);
        pwn_text_P->setObjectName("pwn_text_P");
        pwn_text_P->setFont(font);

        verticalLayout->addWidget(pwn_text_P);

        pwmRProgressBar = new QProgressBar(layoutWidget1);
        pwmRProgressBar->setObjectName("pwmRProgressBar");
        pwmRProgressBar->setMaximum(150);
        pwmRProgressBar->setValue(0);

        verticalLayout->addWidget(pwmRProgressBar);

        speed_text_L = new QLabel(layoutWidget1);
        speed_text_L->setObjectName("speed_text_L");
        speed_text_L->setFont(font);

        verticalLayout->addWidget(speed_text_L);

        speedLProgressBar = new QProgressBar(layoutWidget1);
        speedLProgressBar->setObjectName("speedLProgressBar");
        speedLProgressBar->setAutoFillBackground(false);
        speedLProgressBar->setMaximum(100);
        speedLProgressBar->setValue(24);

        verticalLayout->addWidget(speedLProgressBar);

        speed_text_R = new QLabel(layoutWidget1);
        speed_text_R->setObjectName("speed_text_R");
        speed_text_R->setFont(font);

        verticalLayout->addWidget(speed_text_R);

        speedRProgressBar = new QProgressBar(layoutWidget1);
        speedRProgressBar->setObjectName("speedRProgressBar");
        speedRProgressBar->setMaximum(150);
        speedRProgressBar->setValue(24);

        verticalLayout->addWidget(speedRProgressBar);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(470, 310, 331, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelPosY = new QLabel(layoutWidget2);
        labelPosY->setObjectName("labelPosY");
        labelPosY->setFont(font);

        horizontalLayout_2->addWidget(labelPosY);

        labelPosX = new QLabel(layoutWidget2);
        labelPosX->setObjectName("labelPosX");
        labelPosX->setFont(font);

        horizontalLayout_2->addWidget(labelPosX);

        labelTheta = new QLabel(layoutWidget2);
        labelTheta->setObjectName("labelTheta");
        labelTheta->setFont(font);
        labelTheta->setLineWidth(1);

        horizontalLayout_2->addWidget(labelTheta);

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
        ledIndicator->setText(QString());
        refreshButton->setText(QString());
        statusLabel->setText(QString());
        buttonConnect->setText(QString());
        send_target->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTargetX->setText(QString());
        labelTargetY->setText(QString());
        buttonSendTarget->setText(QString());
        actualTarget->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        actual_position->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        clearButton->setText(QString());
        pwn_text_L->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pwn_text_P->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        speed_text_L->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        speed_text_R->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPosY->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPosX->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTheta->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
