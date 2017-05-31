#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T14:11:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToDoListManager
TEMPLATE = app
CONFIG += C++11#支持C++11,有的不需要写

SOURCES += main.cpp\
        widget.cpp \
    lineeditex.cpp \
    basewidget.cpp \
    listwidgetex.cpp \
    planwidgetitem.cpp

HEADERS  += widget.h \
    lineeditex.h \
    basewidget.h \
    listwidgetex.h \
    planwidgetitem.h

FORMS    +=

RESOURCES += \
    res.qrc
