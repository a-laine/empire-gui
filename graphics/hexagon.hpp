#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include <QGraphicsPolygonItem>



class Hexagon
{
	public:
		enum Type {
			GROUND,
			WATER
		};

		static QPointF getHorizontalSize();
		static QPointF getVerticalSize();


		Hexagon(QPointF pos, QGraphicsItem *parent = 0);

		void setHorizontal();
		void setVertical();
		void setType(Type type);
		QGraphicsItem* getGraphicsItem();

	private:
		QGraphicsPolygonItem *item;
};

#endif // HEXAGON_HPP
