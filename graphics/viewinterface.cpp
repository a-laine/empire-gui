#include "viewinterface.hpp"





ViewInterface::ViewInterface(QGraphicsScene* parent) : QObject(parent)
{
	scene = parent;
}

void ViewInterface::setMapSize(int x, int y)
{
	QPointF sizeMap = toGraphicsCoordinates(x, y);
	QPointF sizeH = Hexagon::getHorizontalSize();
	qreal hHex = sizeH.x();
	qreal wHex = sizeH.y();
	scene->setSceneRect(-hHex/2, -wHew/2, sizeMap.y()+wHex/2, sizeMap.x()+hHex/2);
}

Hexagon* ViewInterface::createHexagon(int x, int y, Hexagon::Type type)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Hexagon *hex = new Hexagon(pos);
	hex->setHorizontal();
	hex->setType(type);
	scene->addItem(hex->getGraphicsItem());

	return hex;
}

Unit* ViewInterface::createUnit(int x, int y, QColor color)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Unit *unit = new Unit(pos);
	unit->setColor(color);
	scene->addItem(unit->getGraphicsItem());

	return unit;
}

void ViewInterface::move(Unit* unit, int x, int y)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	unit->getGraphicsItem()->setPos(pos);
}

void ViewInterface::remove(Unit* unit)
{
	scene->removeItem(unit->getGraphicsItem());
	delete unit->getGraphicsItem();
	delete unit;
}

void ViewInterface::remove(Hexagon* hexagon)
{
	scene->removeItem(hexagon->getGraphicsItem());
	delete hexagon->getGraphicsItem();
	delete hexagon;
}



QPointF ViewInterface::toGraphicsCoordinates(int x, int y)
{
	QPointF size = Hexagon::getHorizontalSize();
	qreal hHex;
	qreal wHex;
	return QPointF(y*wHex, x*0.5*hHex);
}

