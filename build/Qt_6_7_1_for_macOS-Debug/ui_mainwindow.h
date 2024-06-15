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
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *main;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *ledIndicator;
    QLabel *statusLabel;
    QPushButton *refreshButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *languageButton;
    QComboBox *comboBoxSerialPorts;
    QPushButton *buttonConnect;
    QVBoxLayout *verticalLayout_6;
    QGraphicsView *graphicsView;
    QPushButton *clearButton;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *pwn_text_L;
    QProgressBar *pwmLProgressBar;
    QLabel *pwn_text_R;
    QProgressBar *pwmRProgressBar;
    QLabel *speed_text_L;
    QProgressBar *speedLProgressBar;
    QLabel *speed_text_R;
    QProgressBar *speedRProgressBar;
    QVBoxLayout *verticalLayout_3;
    QLabel *actual_position;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPosY;
    QLabel *labelPosX;
    QLabel *labelTheta;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *actualTarget;
    QLabel *send_target;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTargetX;
    QLabel *labelTargetY;
    QLineEdit *lineEditTargetX;
    QLineEdit *lineEditTargetY;
    QPushButton *buttonSendTarget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(962, 534);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_6 = new QHBoxLayout(centralwidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        main = new QHBoxLayout();
        main->setObjectName("main");
        main->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        ledIndicator = new QLabel(centralwidget);
        ledIndicator->setObjectName("ledIndicator");

        horizontalLayout_5->addWidget(ledIndicator);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        horizontalLayout_5->addWidget(statusLabel);

        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName("refreshButton");

        horizontalLayout_5->addWidget(refreshButton);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 6);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        languageButton = new QPushButton(centralwidget);
        languageButton->setObjectName("languageButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(languageButton->sizePolicy().hasHeightForWidth());
        languageButton->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(languageButton);

        comboBoxSerialPorts = new QComboBox(centralwidget);
        comboBoxSerialPorts->setObjectName("comboBoxSerialPorts");

        horizontalLayout_4->addWidget(comboBoxSerialPorts);

        buttonConnect = new QPushButton(centralwidget);
        buttonConnect->setObjectName("buttonConnect");

        horizontalLayout_4->addWidget(buttonConnect);

        horizontalLayout_4->setStretch(1, 84884);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(200, 200));
        graphicsView->setMaximumSize(QSize(2000, 2000));
        graphicsView->setSizeIncrement(QSize(1000, 1000));

        verticalLayout_6->addWidget(graphicsView);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setEnabled(true);
        clearButton->setAcceptDrops(false);
        clearButton->setLayoutDirection(Qt::LeftToRight);
        clearButton->setAutoFillBackground(false);

        verticalLayout_6->addWidget(clearButton);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 4);

        main->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pwn_text_L = new QLabel(centralwidget);
        pwn_text_L->setObjectName("pwn_text_L");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        pwn_text_L->setFont(font);

        verticalLayout->addWidget(pwn_text_L);

        pwmLProgressBar = new QProgressBar(centralwidget);
        pwmLProgressBar->setObjectName("pwmLProgressBar");
        pwmLProgressBar->setMaximum(150);
        pwmLProgressBar->setValue(0);

        verticalLayout->addWidget(pwmLProgressBar);

        pwn_text_R = new QLabel(centralwidget);
        pwn_text_R->setObjectName("pwn_text_R");
        pwn_text_R->setFont(font);

        verticalLayout->addWidget(pwn_text_R);

        pwmRProgressBar = new QProgressBar(centralwidget);
        pwmRProgressBar->setObjectName("pwmRProgressBar");
        pwmRProgressBar->setMaximum(150);
        pwmRProgressBar->setValue(0);

        verticalLayout->addWidget(pwmRProgressBar);

        speed_text_L = new QLabel(centralwidget);
        speed_text_L->setObjectName("speed_text_L");
        speed_text_L->setFont(font);

        verticalLayout->addWidget(speed_text_L);

        speedLProgressBar = new QProgressBar(centralwidget);
        speedLProgressBar->setObjectName("speedLProgressBar");
        speedLProgressBar->setAutoFillBackground(false);
        speedLProgressBar->setMaximum(100);
        speedLProgressBar->setValue(24);

        verticalLayout->addWidget(speedLProgressBar);

        speed_text_R = new QLabel(centralwidget);
        speed_text_R->setObjectName("speed_text_R");
        speed_text_R->setFont(font);

        verticalLayout->addWidget(speed_text_R);

        speedRProgressBar = new QProgressBar(centralwidget);
        speedRProgressBar->setObjectName("speedRProgressBar");
        speedRProgressBar->setMaximum(150);
        speedRProgressBar->setValue(24);

        verticalLayout->addWidget(speedRProgressBar);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        actual_position = new QLabel(centralwidget);
        actual_position->setObjectName("actual_position");
        actual_position->setFont(font);

        verticalLayout_3->addWidget(actual_position);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelPosY = new QLabel(centralwidget);
        labelPosY->setObjectName("labelPosY");
        labelPosY->setFont(font);

        horizontalLayout_2->addWidget(labelPosY);

        labelPosX = new QLabel(centralwidget);
        labelPosX->setObjectName("labelPosX");
        labelPosX->setFont(font);

        horizontalLayout_2->addWidget(labelPosX);

        labelTheta = new QLabel(centralwidget);
        labelTheta->setObjectName("labelTheta");
        labelTheta->setFont(font);
        labelTheta->setLineWidth(1);

        horizontalLayout_2->addWidget(labelTheta);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(1, 4);

        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        actualTarget = new QLabel(centralwidget);
        actualTarget->setObjectName("actualTarget");
        actualTarget->setFont(font);

        horizontalLayout_3->addWidget(actualTarget);

        send_target = new QLabel(centralwidget);
        send_target->setObjectName("send_target");
        send_target->setFont(font);

        horizontalLayout_3->addWidget(send_target);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelTargetX = new QLabel(centralwidget);
        labelTargetX->setObjectName("labelTargetX");
        labelTargetX->setFont(font);

        horizontalLayout->addWidget(labelTargetX);

        labelTargetY = new QLabel(centralwidget);
        labelTargetY->setObjectName("labelTargetY");
        labelTargetY->setFont(font);

        horizontalLayout->addWidget(labelTargetY);

        lineEditTargetX = new QLineEdit(centralwidget);
        lineEditTargetX->setObjectName("lineEditTargetX");

        horizontalLayout->addWidget(lineEditTargetX);

        lineEditTargetY = new QLineEdit(centralwidget);
        lineEditTargetY->setObjectName("lineEditTargetY");

        horizontalLayout->addWidget(lineEditTargetY);

        buttonSendTarget = new QPushButton(centralwidget);
        buttonSendTarget->setObjectName("buttonSendTarget");
        buttonSendTarget->setAutoDefault(false);

        horizontalLayout->addWidget(buttonSendTarget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 1);

        main->addLayout(verticalLayout_4);


        horizontalLayout_6->addLayout(main);

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
        statusLabel->setText(QString());
        refreshButton->setText(QString());
        languageButton->setText(QString());
        buttonConnect->setText(QString());
        clearButton->setText(QString());
        pwn_text_L->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pwn_text_R->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        speed_text_L->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        speed_text_R->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        actual_position->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPosY->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        labelPosX->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        labelTheta->setText(QCoreApplication::translate("MainWindow", "Theta", nullptr));
        actualTarget->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        send_target->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTargetX->setText(QString());
        labelTargetY->setText(QString());
        buttonSendTarget->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
