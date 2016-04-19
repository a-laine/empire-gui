#include "viewinterface.hpp"


ViewInterface::Orientation ViewInterface::sens = ViewInterface::HORIZONTAL;



ViewInterface::ViewInterface(QGraphicsScene* parent) : QObject(parent)
{
	scene = parent;
}

void ViewInterface::setMapSize(int x, int y, Orientation orientation)
{
	QPointF sizeMap;
	QPointF sizeH;
	sens = orientation;
	switch (sens) {
		case HORIZONTAL:
			sizeMap = toGraphicsCoordinates(x, y);
			sizeH = Hexagon::getHorizontalSize();
			scene->setSceneRect(-sizeH.x()/2, -sizeH.y()/2,
								sizeMap.y()+sizeH.y()/2, sizeMap.x()+sizeH.x()/2);
			break;
		case VERTICAL:
			sizeMap = toGraphicsCoordinates(x, y);
			sizeH = Hexagon::getVerticalSize();
			scene->setSceneRect(-sizeH.x()/2, -sizeH.y()/2,
								sizeMap.y()+sizeH.y()/2, sizeMap.x()+sizeH.x()/2);
			break;
	}
}

Hexagon* ViewInterface::createHexagon(int x, int y, Hexagon::Type type)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Hexagon *hex = new Hexagon(pos);
	switch (sens) {
		case HORIZONTAL:
			hex->setHorizontal();
			break;
		case VERTICAL:
			hex->setVertical();
			break;
	}
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
	QPointF size;
	switch (sens) {
		case HORIZONTAL:
			size = Hexagon::getHorizontalSize();
			return QPointF(size.x()*x + size.x()/2,
						   size.y()*y + size.y()/2);
		case VERTICAL:
			size = Hexagon::getVerticalSize();
			return QPointF(size.x()*x + size.x()/2,
						   size.y()*y + size.y()/2);
	}
	Q_UNREACHABLE();
}

