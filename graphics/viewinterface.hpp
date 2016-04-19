#ifndef VIEWINTERFACE_HPP
#define VIEWINTERFACE_HPP

#include <QObject>
#include <QColor>
#include <QGraphicsScene>
#include <QPointF>
#include "hexagon.hpp"
#include "unit.hpp"


class ViewInterface : public QObject
{
		Q_OBJECT
	public:
		enum Orientation {
			HORIZONTAL,
			VERTICAL
		};


		explicit ViewInterface(QGraphicsScene *parent = 0);

		void setMapSize(int x, int y, Orientation orientation);
		Hexagon* createHexagon(int x, int y, Hexagon::Type type);
		Unit* createUnit(int x, int y, QColor color);
		void move(Unit* unit, int x, int y);
		void remove(Unit* unit);
		void remove(Hexagon* hexagon);

	signals:

	public slots:

	private:
		static QPointF toGraphicsCoordinates(int x, int y);

		static Orientation sens;

		QGraphicsScene *scene;
};

#endif // VIEWINTERFACE_HPP
