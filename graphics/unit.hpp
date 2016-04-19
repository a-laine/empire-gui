#ifndef UNIT_HPP
#define UNIT_HPP

#include <QGraphicsRectItem>
#include <QColor>


class Unit : public QGraphicsRectItem
{
	public:
		Unit(QPointF pos, QGraphicsItem *parent = 0);

		void setColor(QColor color);
		QGraphicsItem* getGraphicsItem();

	private:
		QGraphicsRectItem *item;
};

#endif // UNIT_HPP
