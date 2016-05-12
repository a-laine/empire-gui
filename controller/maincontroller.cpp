#include "maincontroller.hpp"
#include <QMessageBox>


MainController::MainController(ViewInterface *view, NetworkController *net, QObject *parent) :
	QObject(parent),
	viewInterface(view),
	networkCtrlr(net),
	observerMode(true)
{
	viewInterface->createHexagon(0,0,Hexagon::GROUND);
	viewInterface->createUnit(0,0,QColor(Qt::red));

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

void MainController::processMessage(QString message)
{
	QStringList l = message.split(' ', QString::SkipEmptyParts);
	QString command = l.at(0);

	// Inital configuration
	if(command == "width")
	{

	}
	else if(command == "height")
	{

	}
	else if(command == "piece_types")
	{

	}
	else if(command == "player_id")
	{

	}
	// Changes on situation
	else if(command == "set_visible")
	{

	}
	else if (command == "set_explored")
	{

	}
	else if(command == "delete_piece")
	{

	}
	else if(command == "create_piece")
	{

	}
	else if(command == "enter_piece")
	{

	}
	else if(command == "enter_city")
	{

	}
	else if(command == "leave_piece")
	{

	}
	else if(command == "leave_city")
	{

	}
	else if(command == "leave_terrain")
	{

	}
	else if(command == "lose_city")
	{

	}
	else if(command == "move")
	{

	}
	else if(command == "invade_city")
	{

	}
	else if(command == "winner")
	{

	}
	// Useless
	else if(command == "get_action") {}
	// Errors
	else if(command == "error")
	{
		emit gameError(message.right(7));
	}
	// Not handeled messages
	else
	{
		// all messages from server are not handeled
		// QMessageBox::information(0, "Debug info", QString("Message not handeled : %1.").arg(command));
	}
}

void MainController::disconnected()
{

}

