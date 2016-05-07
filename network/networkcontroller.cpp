#include "networkcontroller.hpp"

#include <QMessageBox>
#include <QDataStream>


NetworkController::NetworkController(QString address, int port, int sport, QObject* parent) :
	QObject(parent),
	serverSocket(new QTcpSocket(this)),
	clientServer(new QTcpServer(this)),
	clientSocket(0)
{
	serverAddress = address;
	serverPort = port;
	clientPort = sport;

	connect(serverSocket, SIGNAL(readyRead()), this, SLOT(messageFromServer()));
	connect(serverSocket, SIGNAL(disconnected()), this, SLOT(disconnectedFromServer()));
	connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(socketError(QAbstractSocket::SocketError)));
	connect(clientServer, SIGNAL(newConnection()), this, SLOT(clientConnexion()));
}

void NetworkController::connectServer()
{
	// TODO: check serverAddress && serverPort

	serverSocket->abort();
	serverSocket->connectToHost(serverAddress, serverPort);
}

void NetworkController::connectServer(QString address, int port)
{
	serverAddress = address;
	serverPort = port;
	connectServer();
}

void NetworkController::waitClientConnection()
{
	// TODO: check clientPort

	if(!clientServer->listen(QHostAddress::Any, clientPort))
	{
		QMessageBox::information(0, "Network error",
						"Source port for client connections already used.");
	}
}

void NetworkController::waitClientConnection(int port)
{
	clientPort = port;
	waitClientConnection();
}


// ###########################
// #            SLOTS
// ###########################

void NetworkController::sendMessageToServer(QString message)
{

}

void NetworkController::sendMessageToClient(QString message)
{

}

void NetworkController::messageFromServer()
{
	QTextStream in(serverSocket);
	QString message = in.readAll();

	QStringList list = message.split('\n');
	int size = list.size();
	QString last = list.at(list.size()-1);
	if(!last.isEmpty())
		size--;
	for(int i = 1; i<size; i++)
	{
		QString msg = list.at(i);
		if(i == 0)
			msg.append(serverMsg);
		emit serverMessage(msg);
	}
	if(!last.isEmpty())
		serverMsg = last;
	else
		serverMsg = "";
}

void NetworkController::messageFromClient()
{
	QTextStream in(clientSocket);
	QString message = in.readAll();

	QStringList list = message.split('\n');
	int size = list.size();
	QString last = list.at(list.size()-1);
	if(!last.isEmpty())
		size--;
	for(int i = 1; i<size; i++)
	{
		QString msg = list.at(i);
		if(i == 0)
			msg.append(clientMsg);
		emit clientMessage(msg);
	}
	if(!last.isEmpty())
		clientMsg = last;
	else
		clientMsg = "";
}

void NetworkController::socketError(QAbstractSocket::SocketError socketError)
{
	switch (socketError) {
		case QAbstractSocket::RemoteHostClosedError:
			break;
		case QAbstractSocket::HostNotFoundError:
			QMessageBox::information(0, "Network error",
							"The host was not found. Please check the host name and port settings.");
			break;
		case QAbstractSocket::ConnectionRefusedError:
			QMessageBox::information(0, "Network error",
							"The connection was refused by the peer. Make sure the server is running, "
							"or check that the host name and port are correct.");
			break;
		default:
			QMessageBox::information(0, "Network error",
							"An error from network occured.");
			break;
	}
	if(clientSocket)
		clientSocket->abort();
	serverSocket->abort();
	emit disconnected();
}

void NetworkController::clientConnexion()
{
	clientSocket = clientServer->nextPendingConnection();
	connect(clientSocket, SIGNAL(readyRead()), this, SLOT(messageFromClient()));
	connect(clientSocket, SIGNAL(disconnected()), this, SLOT(disconnectedFromClient()));
	connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(socketError(QAbstractSocket::SocketError)));
}

void NetworkController::disconnectedFromClient()
{
	clientSocket->abort();
	serverSocket->abort();
	emit disconnected();
}

void NetworkController::disconnectedFromServer()
{
	if(clientSocket)
		clientSocket->abort();
	serverSocket->abort();
	emit disconnected();
}
