#include "hexagon.hpp"

#include <QBrush>



QPointF Hexagon::getHorizontalSize()
{
	return QPointF(25, 25*0.866);
}

QPointF Hexagon::getVerticalSize()
{
	return QPointF(25*0.866, 25);
}





Hexagon::Hexagon(QPointF pos, QGraphicsItem* parent) :
	item(new QGraphicsPolygonItem(parent))
{
	item->setPos(pos);
}

void Hexagon::setHorizontal()
{
	QPolygonF polygon;

	const qreal w = getHorizontalSize().y();
	const qreal h = getHorizontalSize().x();
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

	const qreal w = getVerticalSize().y();
	const qreal h = getVerticalSize().x();
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
