#include "scene.hpp"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
	addText("Hello World");
}
