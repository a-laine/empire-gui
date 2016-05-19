#include "unit.hpp"

#include <QBrush>
#include <QFont>
#include <QMessageBox>


Unit::Unit(QPointF pos, int id, QGraphicsItem *parent) :
	item(new QGraphicsItemGroup(parent)),
	image(new QGraphicsPixmapItem),
	unitId(id),
	team(-2),
	type(NOTHING)
{
	item->setPos(pos);
	item->addToGroup(image);
	item->setFlag(QGraphicsItem::ItemIsSelectable);
	item->setData(0, id);
	item->setZValue(10);

	image->setPos(-32,-32);
}

Unit::~Unit()
{
	delete item;
}

void Unit::setType(Unit::Type t)
{
	type = t;
	if(team != -2)
		setImage();
}

void Unit::setTeam(int t)
{
	team = t;
	if(type != NOTHING)
		setImage();
}

QGraphicsItem* Unit::getGraphicsItem()
{
	return item;
}

void Unit::setImage()
{
	QString name = ":/ressources/";
	switch (type) {
		case CITY:
			name += "TOWN";
			break;
		case FIGHT:
			name += "FIGHT";
			break;
		case ARMY:
			name += "ARMY";
			break;
		case TRANSPORT:
			name += "TRANSPORT";
			break;
		case PATROL:
			name += "PATROL";
			break;
		case BATTLESHIP:
			name += "BATTLESHIP";
			break;
		default:
			break;
	}
	if(team == 0)
		name += " blue.png";
	else if(team == 1)
		name += " red.png";
	else
		name += " neutral.png";

	image->setPixmap(QPixmap(name));
}
