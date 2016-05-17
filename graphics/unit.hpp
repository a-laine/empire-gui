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
			NOTHING,
			CITY,
			FIGHT,
			ARMY,
			TRANSPORT,
			PATROL,
			BATTLESHIP
		};


		Unit(QPointF pos, int id, QGraphicsItem *parent = 0);
		~Unit();

		void setType(Type t);
		void setTeam(int t);
		QGraphicsItem* getGraphicsItem();

	private:
		QGraphicsPixmapItem *item;
		int unitId;
		int team;
		Type type;
		void setImage();
};

#endif // UNIT_HPP
