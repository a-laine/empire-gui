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
    graphics/unit.cpp \
    controller/maincontroller.cpp \
    graphics/viewinterface.cpp \
    graphics/graphicsview.cpp \
    model/gamemodel.cpp \
    model/tile.cpp \
    model/piece.cpp

HEADERS  += mainwindow.hpp \
	network/networkcontroller.hpp \
	graphics/scene.hpp \
    graphics/hexagon.hpp \
    graphics/unit.hpp \
    controller/maincontroller.hpp \
    graphics/viewinterface.hpp \
    graphics/graphicsview.hpp \
    model/gamemodel.hpp \
    model/tile.hpp \
    model/piece.hpp

FORMS    += mainwindow.ui
