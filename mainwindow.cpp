#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "draw.h"
#include "serialport.h"
#include <QSerialPortInfo>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QResizeEvent>
#include <QTranslator>
#include <QLibraryInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serialPortHandler(new serialport(this))
    , setViewHandler(new SetView(this))
    , translator(new QTranslator(this))
{
    ui->setupUi(this);

    setViewHandler->setIcons(ui);
    setViewHandler->setTexts(ui, translator, this, false);
    setViewHandler->initializeLEDIndicator(ui);
    Draw::initializeGraphicsScene(ui, scene, gridPixmapItem);

    serialPortHandler->populateAvailablePorts(ui);

    // Connect signals and slots
    connect(ui->buttonConnect, &QPushButton::clicked, this, [this]() {
        serialPortHandler->connectSerialPort(ui->comboBoxSerialPorts->currentText());
    });
    connect(ui->refreshButton, &QPushButton::clicked, this, [this]() {
        serialPortHandler->refreshConnection(ui);
    });
    connect(ui->buttonSendTarget, &QPushButton::clicked, this, [this]() {
        serialPortHandler->sendTargetCoordinates(ui);
    });
    connect(serialPortHandler, &serialport::serialDataReceived, this, [this](const QList<QByteArray> &data) {
        serialPortHandler->handleSerialData(ui, scene, pathPoints, pathItems, data);
    });
    connect(serialPortHandler, &serialport::portStatusChanged, this, [this](bool connected, const QString &portName) {
        serialPortHandler->handlePortStatusChanged(ui, connected, portName);
    });
    connect(ui->languageButton, &QPushButton::clicked, this, [this]() {
        setViewHandler->toggleLanguage(ui, translator, this);
    });

    connect(ui->clearButton, &QPushButton::clicked, this, [this]() {
        Draw::clearPathHistory(scene, pathPoints, pathItems, gridPixmapItem);
    });

    // Attempt to open serial port on start
    serialPortHandler->connectSerialPort(ui->comboBoxSerialPorts->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}
