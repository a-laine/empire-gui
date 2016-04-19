#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include <QGraphicsPolygonItem>



class Hexagon : public QGraphicsPolygonItem
{
	public:
		Hexagon(QGraphicsItem *parent = 0);

		void setHorizontal();
		void setVertical();
};

#endif // HEXAGON_HPP
