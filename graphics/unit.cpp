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

void Unit::setColor(QColor color)
{
	item->setBrush(QBrush(color));
}

QGraphicsItem* Unit::getGraphicsItem()
{
	return item;
}
