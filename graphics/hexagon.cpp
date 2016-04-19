#include "hexagon.hpp"

#include <QBrush>

Hexagon::Hexagon(QGraphicsItem* parent) : QGraphicsPolygonItem(parent)
{
	setHorizontal();
	setBrush(QBrush(Qt::green));
}

void Hexagon::setHorizontal()
{
	QPolygonF polygon;

	const qreal w = 25;
	const qreal h = 25 * 0.866;
	polygon << QPointF( 0*h,-2*w)
			<< QPointF(-2*h,-1*w)
			<< QPointF(-2*h, 1*w)
			<< QPointF( 0*h, 2*w)
			<< QPointF( 2*h, 1*w)
			<< QPointF( 2*h,-1*w);

	setPolygon(polygon);
}

void Hexagon::setVertical()
{
	QPolygonF polygon;

	const qreal w = 25 * 0.866;
	const qreal h = 25;
	polygon << QPointF(-2*h, 0*w)
			<< QPointF(-1*h, 2*w)
			<< QPointF( 1*h, 2*w)
			<< QPointF( 2*h, 0*w)
			<< QPointF( 1*h,-2*w)
			<< QPointF(-1*h,-2*w);

	setPolygon(polygon);
}
