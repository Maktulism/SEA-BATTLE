QT += core gui widgets network

TARGET = naval_battle
TEMPLATE = app

SOURCES += main.cpp \
           bot.cpp \
           cell.cpp \
           gamelogic.cpp \
           gameloop.cpp \
           jsonutils.cpp \
           maincontroller.cpp \
           processing.cpp \
           tablecell.cpp \
           waiting.cpp \
           network.cpp

HEADERS += bot.h \
           cell.h \
           gamelogic.h \
           gameloop.h \
           jsonutils.h \
           maincontroller.h \
           processing.h \
           tablecell.h \
           waiting.h \
           network.h

FORMS += create.ui \
         find.ui \
         game.ui \
         mainwindow.ui \
         network.ui

RESOURCES += resources.qrc
