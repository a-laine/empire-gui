#include "viewinterface.hpp"
#include "controller/maincontroller.hpp"
#include <QGraphicsScene>
#include <QMessageBox>



ViewInterface::ViewInterface(QGraphicsScene* scene, Ui::MainWindow* mainWindowUi) :
	QObject(scene),
	scene(scene),
	ui(mainWindowUi),
	controller(0),
	turnNumber(1),
	selected(0)
{
	connect(scene, SIGNAL(selectionChanged()), this, SLOT(unitSelected()));
	ui->groupBoxView->setTitle(QString("Turn number : %1").arg(turnNumber));
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
	connect(ui->listTransported, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(selectedInList(QModelIndex)));
	connect(ui->listInCity, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(selectedInList(QModelIndex)));
	connect(ui->productButton, SIGNAL(pressed()), this, SLOT(productUnit()));
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

Unit* ViewInterface::createUnit(int x, int y, int id, Unit::Type type, int team)
{
	QPointF pos = toGraphicsCoordinates(x, y);
	Unit *unit = new Unit(pos, id);
	unit->setTeam(team);
	unit->setType(type);
	scene->addItem(unit->getGraphicsItem());
	objectList.insert(unit);

	return unit;
}

void ViewInterface::move(Unit* unit, int x, int y)
{
	if(unit == 0)
		return;
	QPointF pos = toGraphicsCoordinates(x, y);
	unit->getGraphicsItem()->setPos(pos);
}

void ViewInterface::remove(Unit* unit)
{
	if(unit == 0)
		return;
	scene->removeItem(unit->getGraphicsItem());
	delete unit;
	objectList.remove(unit);
}

void ViewInterface::remove(Hexagon* hexagon)
{
	if(hexagon == 0)
		return;
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
	controller->movePiece(selected, "NE");
}

void ViewInterface::actionMoveNW()
{
	controller->movePiece(selected, "NW");
}

void ViewInterface::actionMoveE()
{
	controller->movePiece(selected, "E");
}

void ViewInterface::actionMoveW()
{
	controller->movePiece(selected, "W");
}

void ViewInterface::actionMoveSE()
{
	controller->movePiece(selected, "SE");
}

void ViewInterface::actionMoveSW()
{
	controller->movePiece(selected, "SW");
}

void ViewInterface::actionEndTurn()
{
	scene->clearSelection();
	ui->groupBoxAction->setEnabled(false);
	ui->stackedWidget->setCurrentIndex(0);
	controller->endTurn();
	turnNumber++;
	ui->groupBoxView->setTitle(QString("Turn number : %1").arg(turnNumber));
}

void ViewInterface::newTurn()
{
	ui->groupBoxAction->setEnabled(true);
}

void ViewInterface::unitSelected()
{
	QList<QGraphicsItem*> items = scene->selectedItems();
	if(items.size() == 0)
	{
		selected = 0;
		ui->stackedWidget->setCurrentIndex(0);
	}
	else if(items.size() == 1)
	{
		selected = items.at(0)->data(0).toInt();
		if(selected == 0)
			return;

		QString type;
		QVector<QPair<QString,int>> transported;
		controller->getInfo(selected, type, transported);
		showInformations(type, transported);
	}
}

void ViewInterface::selectedInList(QModelIndex index)
{
	selected = selectedTransported[index.row()];
	if(selected == 0)
		return;

	QString type;
	QVector<QPair<QString,int>> transported;
	controller->getInfo(selected, type, transported);
	showInformations(type, transported);
}

void ViewInterface::productUnit()
{
	controller->setProduction(selected, ui->unitTypeCombo->currentText());
}



QPointF ViewInterface::toGraphicsCoordinates(int x, int y)
{
	QPointF size = Hexagon::getHorizontalSize();
	qreal hHex = size.x();
	qreal wHex = size.y()*0.75;
	return QPointF(x*hHex+y*0.5*hHex, y*wHex);
}

void ViewInterface::showInformations(QString type, QVector<QPair<QString,int>> transported)
{
	QListWidget* listTransported;
	if(type == "CITY")
	{
		ui->stackedWidget->setCurrentIndex(2);
		listTransported = ui->listInCity;
	}
	else
	{
		ui->stackedWidget->setCurrentIndex(1);
		ui->labelUnit->setText("Unit type : " + type);
		listTransported = ui->listTransported;
	}
	listTransported->clear();
	selectedTransported.clear();
	for(QVector<QPair<QString,int> >::iterator it = transported.begin();
		it != transported.end(); it++)
	{
		listTransported->addItem(it->first);
		selectedTransported.push_back(it->second);
	}
}

