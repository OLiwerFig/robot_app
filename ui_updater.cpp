#include "ui_updater.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTranslator>

UiUpdater::UiUpdater(MainWindow *mainWindow)
    : mainWindow(mainWindow), translator(new QTranslator(mainWindow))
{
}

void UiUpdater::toggleLanguage()
{
    static bool isEnglish = false;
    isEnglish = !isEnglish;

    bool loaded = false;

    if (isEnglish) {
        loaded = translator->load(":/translations/app_en.qm");
        mainWindow->ui->languageButton->setIcon(QIcon(":/images/ang.png"));
    } else {
        loaded = translator->load(":/translations/app_pl.qm");
        mainWindow->ui->languageButton->setIcon(QIcon(":/images/pol.png"));
    }

    if (!loaded) {
        qDebug() << "Failed to load translation file.";
    } else {
        qApp->installTranslator(translator);
        mainWindow->ui->retranslateUi(mainWindow);
        updateTexts();
    }
}

void UiUpdater::updateTexts()
{
    mainWindow->ui->speed_text_L->setText(mainWindow->tr("Prędkość lewego silnika"));
    mainWindow->ui->speed_text_R->setText(mainWindow->tr("Prędkość prawego silnika"));
    mainWindow->ui->pwn_text_R->setText(mainWindow->tr("Wartość wypełnienia PWM prawego silnika"));
    mainWindow->ui->pwn_text_L->setText(mainWindow->tr("Wartość wypełnienia PWM lewego silnika"));
    mainWindow->ui->actualTarget->setText(mainWindow->tr("Aktualny Target"));
    mainWindow->ui->actual_position->setText(mainWindow->tr("Aktualna Pozycja"));
    mainWindow->ui->send_target->setText(mainWindow->tr("Wpisz target"));
    mainWindow->ui->buttonSendTarget->setText(mainWindow->tr("Send"));
    mainWindow->ui->statusLabel->setText(mainWindow->tr("Disconnected"));
    mainWindow->ui->buttonConnect->setText(mainWindow->tr("Connect"));
    mainWindow->ui->refreshButton->setText(mainWindow->tr("Refresh"));
    mainWindow->ui->clearButton->setText(mainWindow->tr("Clear"));
}
