#include "unit.hpp"

#include <QBrush>
#include <QFont>


Unit::Unit(QPointF pos, int id, QGraphicsItem *parent) :
	item(new QGraphicsItemGroup(parent)),
	rect(new QGraphicsRectItem(0)),
	text(new QGraphicsSimpleTextItem(0)),
	unitId(id)
{
	item->addToGroup(rect);
	item->setFlag(QGraphicsItem::ItemIsSelectable);
	item->setData(0, id);
	rect->setPos(0,0);
	rect->setRect(-25,-25,50,50);

	item->addToGroup(text);
	text->setPos(-15,-29);
	text->setFont(QFont("monospace", 40, 100));
	text->setBrush(QBrush(Qt::black));

	item->setPos(pos);
}

Unit::~Unit()
{
	delete item;
}

void Unit::setType(Unit::Type type)
{
	switch (type) {
		case CITY:
			text->setText("O");
			break;
		case FIGHT:
			text->setText("F");
			break;
		case ARMY:
			text->setText("A");
			break;
		case TRANSPORT:
			text->setText("T");
			break;
		case PATROL:
			text->setText("P");
			break;
		case BATTLESHIP:
			text->setText("B");
			break;
		default:
			break;
	}
}

void Unit::setColor(QColor color)
{
	rect->setBrush(QBrush(color));
}

QGraphicsItem* Unit::getGraphicsItem()
{
	return item;
}
