#ifndef VIEWINTERFACE_HPP
#define VIEWINTERFACE_HPP

#include <QObject>
#include <QColor>
#include <QGraphicsScene>
#include "hexagon.hpp"
#include "unit.hpp"


class ViewInterface : public QObject
{
		Q_OBJECT
	public:
		explicit ViewInterface(QObject *parent = 0);

		void setScene(QGraphicsScene *s);
		Hexagon* createHexagon(int x, int y);
		Unit* createUnit(int x, int y, QColor color);

	signals:

	public slots:

	private:
		QGraphicsScene *scene;
};

#endif // VIEWINTERFACE_HPP
