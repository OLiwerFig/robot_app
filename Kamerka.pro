QT       += core gui
QT       += core gui serialport
QT       += core gui charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    draw.cpp \
    main.cpp \
    mainwindow.cpp \
    serialport.cpp \
    setview.cpp

HEADERS += \
    draw.h \
    mainwindow.h \
    serialport.h \
    setview.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
        app_pl.ts \
        app_en.ts


CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
