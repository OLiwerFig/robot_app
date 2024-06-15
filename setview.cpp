#include "setview.h"
#include <QDebug>

SetView::SetView(QObject *parent) : QObject(parent) {}

void SetView::setIcons(Ui::MainWindow *ui)
{
    QIcon refreshIcon(":/images/retry.png");
    ui->refreshButton->setIcon(refreshIcon);
    ui->refreshButton->setIconSize(QSize(24, 24));

    ui->clearButton->setIcon(refreshIcon);
    ui->clearButton->setIconSize(QSize(26, 26));

    QIcon conIcon(":/images/con.png");
    ui->buttonConnect->setIcon(conIcon);
    ui->buttonConnect->setIconSize(QSize(32, 32));

    ui->languageButton->setIcon(QIcon(":/images/pol.png"));
    ui->languageButton->setIconSize(QSize(32, 32));
}

void SetView::setTexts(Ui::MainWindow *ui, QTranslator *translator, QMainWindow *mainWindow, bool isEnglish)
{
    bool loaded = false;
    if (isEnglish) {
        loaded = translator->load(":/translations/app_en.qm");
        ui->languageButton->setIcon(QIcon(":/images/ang.png"));
    } else {
        loaded = translator->load(":/translations/app_pl.qm");
        ui->languageButton->setIcon(QIcon(":/images/pol.png"));
    }

    if (!loaded) {
        qDebug() << "Failed to load translation file.";
    } else {
        qApp->installTranslator(translator);
        ui->retranslateUi(mainWindow);
        updateTexts(ui);
    }
}

void SetView::toggleLanguage(Ui::MainWindow *ui, QTranslator *translator, QMainWindow *mainWindow)
{
    static bool isEnglish = false;
    isEnglish = !isEnglish;
    setTexts(ui, translator, mainWindow, isEnglish);
}

void SetView::initializeLEDIndicator(Ui::MainWindow *ui)
{
    ui->ledIndicator->setStyleSheet("background-color: red; border-radius: 10px;");
    ui->statusLabel->setText(QObject::tr("Disconnected"));
}

void SetView::updateTexts(Ui::MainWindow *ui)
{
    ui->speed_text_L->setText(QObject::tr("Prędkość lewego silnika"));
    ui->speed_text_R->setText(QObject::tr("Prędkość prawego silnika"));
    ui->pwn_text_R->setText(QObject::tr("Wartość wypełnienia PWM prawego silnika"));
    ui->pwn_text_L->setText(QObject::tr("Wartość wypełnienia PWM lewego silnika"));
    ui->actualTarget->setText(QObject::tr("Aktualny Target"));
    ui->actual_position->setText(QObject::tr("Aktualna Pozycja"));
    ui->send_target->setText(QObject::tr("Wpisz target"));
    ui->buttonSendTarget->setText(QObject::tr("Send"));
    ui->statusLabel->setText(QObject::tr("Disconnected"));
    ui->buttonConnect->setText(QObject::tr("Connect"));
    ui->refreshButton->setText(QObject::tr("Refresh"));
    ui->clearButton->setText(QObject::tr("Clear"));
}
