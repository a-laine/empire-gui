#include "scene.hpp"
#include <QBrush>

#include "hexagon.hpp"
#include "unit.hpp"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
	setBackgroundBrush(QBrush(Qt::black));

	addItem(new Hexagon);
	addItem(new Unit);
}
