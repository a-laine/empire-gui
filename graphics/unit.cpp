#include "unit.hpp"

#include <QBrush>


Unit::Unit(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
	setRect(-25,-25,50,50);
	setBrush(QBrush(Qt::red));
	setFlag(QGraphicsItem::ItemIsSelectable);
}
