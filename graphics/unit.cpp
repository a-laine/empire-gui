#include "unit.hpp"

#include <QBrush>


Unit::Unit(QPointF pos, QGraphicsItem *parent) :
	item(new QGraphicsRectItem(parent))
{
	item->setPos(pos);
	item->setRect(-25,-25,50,50);
	item->setFlag(QGraphicsItem::ItemIsSelectable);
}

Unit::~Unit()
{
	delete item;
}

void Unit::setType(Unit::Type type)
{
	switch (type) {
		case CITY:
			break;
		case FIGHT:
			break;
		case ARMY:
			break;
		case TRANSPORT:
			break;
		case PATROL:
			break;
		case BATTLESHIP:
			break;
		default:
			break;
	}
}

void Unit::setColor(QColor color)
{
	item->setBrush(QBrush(color));
}

QGraphicsItem* Unit::getGraphicsItem()
{
	return item;
}
