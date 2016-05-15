#include "viewinterface.hpp"
#include <QGraphicsScene>
#include "controller/maincontroller.hpp"
#include <QMessageBox>



ViewInterface::ViewInterface(QGraphicsScene* scene, Ui::MainWindow* mainWindowUi) :
	QObject(scene),
	scene(scene),
	ui(mainWindowUi),
	controller(0),
	selected(0)
{
	connect(scene, SIGNAL(selectionChanged()), this, SLOT(unitSelected()));
}

void ViewInterface::setController(MainController* ctrlr)
{
	controller = ctrlr;

	connect(ui->moveE,  SIGNAL(pressed()), this, SLOT(actionMoveE()));
	connect(ui->moveNE, SIGNAL(pressed()), this, SLOT(actionMoveNE()));
	connect(ui->moveNW, SIGNAL(pressed()), this, SLOT(actionMoveNW()));
	connect(ui->moveSE, SIGNAL(pressed()), this, SLOT(actionMoveSE()));
	connect(ui->moveSW, SIGNAL(pressed()), this, SLOT(actionMoveSW()));
	connect(ui->moveW,  SIGNAL(pressed()), this, SLOT(actionMoveW()));
	connect(ui->endTurnButton, SIGNAL(pressed()), this, SLOT(actionEndTurn()));
	connect(ui->nextUnitButton, SIGNAL(pressed()), this, SLOT(actionNextUnit()));
	connect(ui->prevUnitButton, SIGNAL(pressed()), this, SLOT(actionPrevUnit()));
}

void ViewInterface::setMapSize(int x, int y)
{
	QPointF sizeMap = toGraphicsCoordinates(x, y);
	QPointF sizeH = Hexagon::getHorizontalSize();
	qreal hHex = sizeH.x();
	qreal wHex = sizeH.y();
	scene->setSceneRect(-hHex/2, -wHex/2, sizeMap.y()+wHex/2, sizeMap.x()+hHex/2);
}

Hexagon* ViewInterface::createHexagon(int x, int y, Hexagon::Type type)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Hexagon *hex = new Hexagon(pos);
	hex->setHorizontal();
	hex->setType(type);
	scene->addItem(hex->getGraphicsItem());
	objectList.insert(hex);

	return hex;
}

Unit* ViewInterface::createUnit(int x, int y, int id, Unit::Type type, QColor color)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Unit *unit = new Unit(pos, id);
	unit->setColor(color);
	unit->setType(type);
	scene->addItem(unit->getGraphicsItem());
	objectList.insert(unit);

	return unit;
}

void ViewInterface::move(Unit* unit, int x, int y)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	unit->getGraphicsItem()->setPos(pos);
}

void ViewInterface::remove(Unit* unit)
{
	scene->removeItem(unit->getGraphicsItem());
	delete unit;
	objectList.remove(unit);
}

void ViewInterface::remove(Hexagon* hexagon)
{
	scene->removeItem(hexagon->getGraphicsItem());
	delete hexagon;
	objectList.remove(hexagon);
}

void ViewInterface::clearView()
{
	for(QSet<GraphicsObject*>::iterator it = objectList.begin();
		it != objectList.end(); it++)
	{
		scene->removeItem((*it)->getGraphicsItem());
		delete (*it);
	}
	objectList.clear();
}

void ViewInterface::actionMoveNE()
{

}

void ViewInterface::actionMoveNW()
{

}

void ViewInterface::actionMoveE()
{

}

void ViewInterface::actionMoveW()
{

}

void ViewInterface::actionMoveSE()
{

}

void ViewInterface::actionMoveSW()
{

}

void ViewInterface::actionEndTurn()
{
	controller->endTurn();
	ui->groupBoxAction->setEnabled(false);
}

void ViewInterface::actionNextUnit()
{

}

void ViewInterface::actionPrevUnit()
{

}

void ViewInterface::newTurn()
{
	ui->groupBoxAction->setEnabled(true);
}

void ViewInterface::unitSelected()
{

}



QPointF ViewInterface::toGraphicsCoordinates(int x, int y)
{
	QPointF size = Hexagon::getHorizontalSize();
	qreal hHex = size.x();
	qreal wHex = size.y()*0.75;
	return QPointF(x*hHex+y*0.5*hHex, y*wHex);
}

void ViewInterface::showInformations()
{

}

