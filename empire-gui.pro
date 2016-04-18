#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T19:01:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = empire-gui
TEMPLATE = app


SOURCES += main.cpp\
	mainwindow.cpp \
	network/networkcontroller.cpp \
	graphics/scene.cpp \
    graphics/hexagon.cpp \
    graphics/unit.cpp

HEADERS  += mainwindow.hpp \
	network/networkcontroller.hpp \
	graphics/scene.hpp \
    graphics/hexagon.hpp \
    graphics/unit.hpp

FORMS    += mainwindow.ui
