QT += core gui widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SeaBattle
TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS += MainWindow.h

FORMS += MainWindow.ui

RESOURCES += images.qrc\
             musics.qrc
