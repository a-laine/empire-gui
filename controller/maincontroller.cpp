#include "maincontroller.hpp"

MainController::MainController(ViewInterface *view, NetworkController *net, QObject *parent) :
	QObject(parent),
	viewInterface(view),
	networkCtrlr(net),
	observerMode(true)
{
	viewInterface->createHexagon(0,0,Hexagon::GROUND);
	viewInterface->createUnit(0,0,QColor(Qt::red));
}

void MainController::setObserverMode(bool enabled)
{
	observerMode = enabled;
}

bool MainController::getObserverMode()
{
	return observerMode;
}

