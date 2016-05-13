#ifndef UNIT_HPP
#define UNIT_HPP

#include "graphicsobject.hpp"

#include <QGraphicsRectItem>
#include <QColor>


class Unit : public GraphicsObject
{
	public:
		Unit(QPointF pos, QGraphicsItem *parent = 0);
		~Unit();

		void setColor(QColor color);
		QGraphicsItem* getGraphicsItem();

	private:
		QGraphicsRectItem *item;
};

#endif // UNIT_HPP
