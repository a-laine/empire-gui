#ifndef UNIT_HPP
#define UNIT_HPP

#include "graphicsobject.hpp"

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
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


		Unit(QPointF pos, int id, QGraphicsItem *parent = 0);
		~Unit();

		void setType(Type type);
		void setColor(QColor color);
		QGraphicsItem* getGraphicsItem();

	private:
		QGraphicsItemGroup *item;
		QGraphicsRectItem *rect;
		QGraphicsSimpleTextItem *text;
		int unitId;
};

#endif // UNIT_HPP
