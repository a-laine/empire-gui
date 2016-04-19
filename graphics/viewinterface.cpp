#include "viewinterface.hpp"
#include <QBrush>



ViewInterface::ViewInterface(QObject *parent) : QObject(parent)
{
}

void ViewInterface::setScene(QGraphicsScene* s)
{
	scene = s;
}

Hexagon* ViewInterface::createHexagon(int x, int y)
{
	Hexagon *hex = new Hexagon;
	hex->setPos(x, y);
	scene->addItem(hex);
}

Unit* ViewInterface::createUnit(int x, int y, QColor color)
{
	Unit *unit = new Unit;
	unit->setPos(x, y);
	unit->setBrush(QBrush(color));
	scene->addItem(unit);
}
