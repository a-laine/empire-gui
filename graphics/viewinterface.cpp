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
	scene->setSceneRect(-hHex/2, -wHex/2, sizeMap.y()+wHex/2, sizeMap.x()+hHex/2);
}

Hexagon* ViewInterface::createHexagon(int x, int y, Hexagon::Type type)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Hexagon *hex = new Hexagon(pos);
	hex->setHorizontal();
	hex->setType(type);
	scene->addItem(hex->getGraphicsItem());
	objectList.insert(hex);

	return hex;
}

Unit* ViewInterface::createUnit(int x, int y, Unit::Type type, QColor color)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Unit *unit = new Unit(pos);
	unit->setColor(color);
	unit->setType(type);
	scene->addItem(unit->getGraphicsItem());
	objectList.insert(unit);

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
	delete unit;
	objectList.remove(unit);
}

void ViewInterface::remove(Hexagon* hexagon)
{
	scene->removeItem(hexagon->getGraphicsItem());
	delete hexagon;
	objectList.remove(hexagon);
}

void ViewInterface::clearView()
{
	for(QSet<GraphicsObject*>::iterator it = objectList.begin();
		it != objectList.end(); it++)
	{
		scene->removeItem((*it)->getGraphicsItem());
		delete (*it);
	}
	objectList.clear();
}



QPointF ViewInterface::toGraphicsCoordinates(int x, int y)
{
	QPointF size = Hexagon::getHorizontalSize();
	qreal hHex = size.x();
	qreal wHex = size.y()*0.75;
	return QPointF(x*hHex+y*0.5*hHex, y*wHex);
}

