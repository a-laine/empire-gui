#ifndef UNIT_HPP
#define UNIT_HPP

#include "graphicsobject.hpp"

#include <QGraphicsRectItem>
#include <QColor>


class Unit : public GraphicsObject
{
	public:
		enum Type {
			CITY,
			FIGHT,
			ARMY,
			TRANSPORT,
			PATROL,
			BATTLESHIP
		};


		Unit(QPointF pos, QGraphicsItem *parent = 0);
		~Unit();

		void setType(Type type);
		void setColor(QColor color);
		QGraphicsItem* getGraphicsItem();

	private:
		QGraphicsRectItem *item;
};

#endif // UNIT_HPP
