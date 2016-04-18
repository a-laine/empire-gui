#include "scene.hpp"
#include <QBrush>

#include "graphics/hexagon.hpp"
#include "graphics/unit.hpp"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
	setBackgroundBrush(QBrush(Qt::black));

	addItem(new Hexagon);
	addItem(new Unit);
}
