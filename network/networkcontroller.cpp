#include "networkcontroller.hpp"

NetworkController::NetworkController(QString address, int port, int sport, QObject* parent) :
	QObject(parent),
	serverSocket(0),
	clientServer(0),
	clientSocket(0)
{
	serverAddress = address;
	serverPort = port;
	clientPort = sport;
}

NetworkController::connectServer()
{
	// test serverAddress && serverPort
}

NetworkController::connectServer(QString address, int port)
{
	serverAddress = address;
	serverPort = port;
	connectServer();
}

void NetworkController::waitClientConnection()
{
	// test clientPort
}

void NetworkController::waitClientConnection(int port)
{
	clientPort = port;
	waitClientConnection();
}
