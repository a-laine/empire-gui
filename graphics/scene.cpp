#include "scene.hpp"
#include <QBrush>
#include <QGraphicsView>
#include <QGraphicsSceneWheelEvent>



Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
	setBackgroundBrush(QBrush(Qt::black));
}
