#include "maincontroller.hpp"

#include "graphics/viewinterface.hpp"
#include "network/networkcontroller.hpp"
#include "model/gamemodel.hpp"
#include "model/tile.hpp"
#include "model/piece.hpp"
#include <QMessageBox>
#include <iostream>


MainController::MainController(ViewInterface *view, NetworkController *net, QObject *parent) :
	QObject(parent),
	viewInterface(view),
	networkCtrlr(net),
	model(new GameModel()),
	observerMode(true)
{
	connect(networkCtrlr, SIGNAL(serverMessage(QString)), this, SLOT(processMessage(QString)));
	connect(networkCtrlr, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(this, SIGNAL(sendMessage(QString)), networkCtrlr, SLOT(sendMessageToServer(QString)));
}

void MainController::setObserverMode(bool enabled)
{
	observerMode = enabled;
}

bool MainController::getObserverMode()
{
	return observerMode;
}

void MainController::endTurn()
{
	networkCtrlr->sendMessageToServer("end_turn\n");
}

void MainController::movePiece()
{

}

void MainController::processMessage(QString message)
{
	QStringList l = message.split(' ');

	QString command = l.at(0);
	std::cout << message.toStdString() << std::endl;

	// Inital configuration
	if(command == "width")
	{
		model->setMapWidth(l.at(1).toInt());
	}
	else if(command == "height")
	{
		model->setMapHeight(l.at(1).toInt());
		// height is received in second then set the map size in view
		//viewInterface->setMapSize(model->getMapHeight(),model->getMapWidth());
	}
	else if(command == "player_id")
	{
		model->setPlayerId(l.at(1).toInt());
	}
	// Changes on situation
	else if(command == "set_visible")
	{
		int x = l.at(1).toInt();
		int y = l.at(2).toInt();
		QString type = l.at(3);
		QString onTile = l.at(4);

		createTile(x, y, type, true);

		if(onTile != "none")
		{
			if(onTile == "owned_city")
				createCity(x, y, l.at(5).toInt(), l.at(6).toInt());
			else if(onTile == "city")
				createCity(x, y, l.at(5).toInt(), -1);
			else if(onTile == "piece")
				createUnit(x, y, l.at(6).toInt(), l.at(5).toInt(), l.at(7).toInt());
		}
	}
	else if (command == "set_explored")
	{
		int x = l.at(1).toInt();
		int y = l.at(2).toInt();
		QString type = l.at(3);

		Tile* tile = model->getTile(QPoint(x,y));
		tile->setVisible(false);
		Hexagon* hex2 = (Hexagon*) tile->getGraphicsObject();
		hex2->setVisible(false);
	}
	else if(command == "delete_piece")
	{
		int id = l.at(1).toInt();
		Piece* p = model->getPiece(id);
		viewInterface->remove((Unit*) p->getGraphicsObject());
		model->removePiece(id);
		delete p;
	}
	else if(command == "create_piece")
	{
		int type = l.at(2).toInt();
		int id = l.at(1).toInt();
		int owner = model->getPlayerId();
		int cityId = l.at(3).toInt();
		Piece* p = new Piece(id, type, owner);
		model->addPiece(id, p);
		model->getPiece(cityId)->addTransported(p);

	}
	else if(command == "enter_piece" || command == "enter_city")
	{
		int pieceId = l.at(1).toInt();
		int containerId = l.at(2).toInt();
		model->getPiece(containerId)->addTransported(model->getPiece(pieceId));
	}
	else if(command == "leave_piece" || command == "leave_city")
	{
		int pieceId = l.at(1).toInt();
		int containerId = l.at(2).toInt();
		model->getPiece(containerId)->removeTransported(model->getPiece(pieceId));
	}
	else if(command == "leave_terrain")
	{
		int id = l.at(1).toInt();
		int x = l.at(2).toInt();
		int y = l.at(3).toInt();
		if(model->getTile(QPoint(x,y))->getPiece() == model->getPiece(id))
			model->getTile(QPoint(x,y))->putPiece(0);
	}
	else if(command == "lose_city")
	{
		int id = l.at(1).toInt();
		Piece* p = model->getPiece(id);
		viewInterface->remove((Unit*) p->getGraphicsObject());
		p->setGraphicsObject(0);
	}
	else if(command == "move")
	{
		int id = l.at(1).toInt();
		int x = l.at(2).toInt();
		int y = l.at(3).toInt();
		model->getTile(QPoint(x,y))->putPiece(model->getPiece(id));
	}
	else if(command == "invade_city")
	{
		int id = l.at(1).toInt();
		//int x = l.at(2).toInt();
		//int y = l.at(3).toInt();
		Piece* p = model->getPiece(id);
		viewInterface->remove((Unit*) p->getGraphicsObject());
		p->setGraphicsObject(0);
	}
	else if(command == "winner")
	{
		int id = l.at(1).toInt();
		if(id == model->getPlayerId())
		{
			QMessageBox::information(0, "Game ends", "Congratulation, you win!");
			emit gameEnd(true);
		}
		else
		{
			QMessageBox::information(0, "Game ends", "You loose :(");
			emit gameEnd(false);
		}
	}
	// Errors
	else if(command == "error")
	{
		emit gameError(message.right(7));
		//QMessageBox::information(0, "Game error", message);
	}
}

void MainController::disconnected()
{
	// TODO : clear view and model
}

void MainController::createTile(int x, int y, QString type, bool visible)
{
	Hexagon::Type th;
	Tile::Type tt;
	if(type == "ground") {
		th = Hexagon::GROUND;
		tt = Tile::GROUND;
	}
	else {
		th = Hexagon::WATER;
		tt = Tile::WATER;
	}
	Hexagon* hex = viewInterface->createHexagon(x,y,th);
	hex->setVisible(visible);
	if(model->getTile(QPoint(x,y)) == 0)
	{

		Tile* tile = new Tile(tt);
		tile->setVisible(visible);
		tile->setGraphicsObject(hex);
		model->setTile(QPoint(x,y), tile);
	}
	else
	{
		Tile* tile = model->getTile(QPoint(x,y));
		tile->setVisible(visible);
		Hexagon* hex2 = (Hexagon*) tile->getGraphicsObject();
		if(hex2 != 0)
			viewInterface->remove(hex2);
		tile->setGraphicsObject(hex);
	}
}

void MainController::createCity(int x, int y, int id, int owner)
{

	QColor color;
	switch (owner) {
		case -1:
			color = Qt::white;
			break;
		case 0:
			color = Qt::yellow;
			break;
		case 1:
			color = Qt::red;
			break;
		default:
			break;
	}
	Unit* u1 = viewInterface->createUnit(x, y, id, Unit::CITY, color);
	if(model->getPiece(id) == 0)
	{
		Piece* p = new Piece(id, Piece::CITY, owner);
		p->setGraphicsObject(u1);
		model->addPiece(id, p);
	}
	else
	{
		Piece* p = model->getPiece(id);
		Unit* u2 = (Unit*) p->getGraphicsObject();
		if(u2 != 0)
			viewInterface->remove(u2);
		p->setGraphicsObject(u1);
	}
}

void MainController::createUnit(int x, int y, int id, int owner, int type)
{
	Unit::Type tu;
	QColor c = (owner==0)? Qt::yellow : Qt::red;
	switch (type) {
		case 0:
			tu = Unit::ARMY;
			break;
		case 1:
			tu = Unit::FIGHT;
			break;
		case 2:
			tu = Unit::TRANSPORT;
			break;
		case 3:
			tu = Unit::PATROL;
			break;
		case 4:
			tu = Unit::BATTLESHIP;
			break;
	}
	Unit* u1 = viewInterface->createUnit(x, y, id, tu, c);
	if(model->getPiece(id) == 0)
	{
		Piece* p = new Piece(id, type, owner);
		p->setGraphicsObject(u1);
		model->addPiece(id, p);
	}
	else
	{
		Piece* p = model->getPiece(id);
		Unit* u2 = (Unit*) p->getGraphicsObject();
		if(u2 != 0)
			viewInterface->remove(u2);
		p->setGraphicsObject(u1);
	}
}

