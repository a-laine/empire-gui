#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T19:01:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = empire-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    network/networkcontroller.cpp

HEADERS  += mainwindow.hpp \
    scene.hpp \
    network/networkcontroller.hpp

FORMS    += mainwindow.ui
