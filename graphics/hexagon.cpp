#include "hexagon.hpp"

#include <QBrush>

Hexagon::Hexagon(QGraphicsItem* parent) : QGraphicsPolygonItem(parent)
{
	QPolygonF polygon;

	/* HORIZONTAL */
	const qreal w = 25;
	const qreal h = 25 * 0.866;
	polygon << QPointF( 0*h,-2*w)
			<< QPointF(-2*h,-1*w)
			<< QPointF(-2*h, 1*w)
			<< QPointF( 0*h, 2*w)
			<< QPointF( 2*h, 1*w)
			<< QPointF( 2*h,-1*w);

	/* VERTICAL
	const qreal w = 100 * 0.866;
	const qreal h = 100;
	polygon << QPointF(-2*h, 0*w)
			<< QPointF(-1*h, 2*w)
			<< QPointF( 1*h, 2*w)
			<< QPointF( 2*h, 0*w)
			<< QPointF( 1*h,-2*w)
			<< QPointF(-1*h,-2*w);
	*/

	setPolygon(polygon);
	setBrush(QBrush(Qt::green));
}
