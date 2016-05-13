#include "hexagon.hpp"

#include <QBrush>



QPointF Hexagon::getHorizontalSize()
{
	return QPointF(25*0.866, 25);
}

QPointF Hexagon::getVerticalSize()
{
	return QPointF(25, 25*0.866);
}





Hexagon::Hexagon(QPointF pos, QGraphicsItem* parent) :
	item(new QGraphicsPolygonItem(parent))
{
	item->setPos(pos);
}

Hexagon::~Hexagon()
{
	delete item;
}

void Hexagon::setHorizontal()
{
	QPolygonF polygon;

	const qreal h = getHorizontalSize().x();
	const qreal w = getHorizontalSize().y();
	polygon << QPointF( 0*h,-2*w)
			<< QPointF(-2*h,-1*w)
			<< QPointF(-2*h, 1*w)
			<< QPointF( 0*h, 2*w)
			<< QPointF( 2*h, 1*w)
			<< QPointF( 2*h,-1*w);

	item->setPolygon(polygon);
}

void Hexagon::setVertical()
{
	QPolygonF polygon;

	const qreal h = getVerticalSize().x();
	const qreal w = getVerticalSize().y();
	polygon << QPointF(-2*h, 0*w)
			<< QPointF(-1*h, 2*w)
			<< QPointF( 1*h, 2*w)
			<< QPointF( 2*h, 0*w)
			<< QPointF( 1*h,-2*w)
			<< QPointF(-1*h,-2*w);

	item->setPolygon(polygon);
}

void Hexagon::setType(Hexagon::Type type)
{
	switch (type) {
		case GROUND:
			item->setBrush(QBrush(Qt::darkGreen));
			break;
		case WATER:
			item->setBrush(QBrush(Qt::darkBlue));
			break;
		default:
			break;
	}
}

QGraphicsItem* Hexagon::getGraphicsItem()
{
	return item;
}
