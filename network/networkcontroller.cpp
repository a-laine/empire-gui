#include "networkcontroller.hpp"

#include <QMessageBox>
#include <QTextStream>
#include <iostream>


NetworkController::NetworkController(QString address, int port, QObject* parent) :
	QObject(parent),
	serverPort(port),
	serverAddress(address),
	serverSocket(new QTcpSocket(this))


{
	connect(serverSocket, SIGNAL(readyRead()), this, SLOT(messageReceived()));
	connect(serverSocket, SIGNAL(disconnected()), this, SLOT(disconnectedFromServer()));
	connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(socketError(QAbstractSocket::SocketError)));
}

NetworkController::NetworkController(QObject* parent) :
	QObject(parent),
	serverAddress("localhost"),
	serverPort(0),
	serverSocket(new QTcpSocket(this))
{
	connect(serverSocket, SIGNAL(readyRead()), this, SLOT(messageReceived()));
	connect(serverSocket, SIGNAL(disconnected()), this, SLOT(disconnectedFromServer()));
	connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(socketError(QAbstractSocket::SocketError)));
}

void NetworkController::connectServer()
{
	serverSocket->abort();
	serverSocket->connectToHost(serverAddress, serverPort);
}

void NetworkController::connectServer(QString address, int port)
{
	serverAddress = address;
	serverPort = port;
	connectServer();
}


// ###########################
// #            SLOTS
// ###########################

void NetworkController::sendMessageToServer(QString message)
{
	QByteArray block;
	QTextStream out(&block, QIODevice::WriteOnly);
	out << message;
	serverSocket->write(block);
}

void NetworkController::messageReceived()
{
	QTextStream in(serverSocket);
	QString message = in.readAll();

	QStringList list = message.split('\n');
	int size = list.size();
	QString last = list.at(list.size()-1);
	if(!last.isEmpty())
		size--;
	for(int i = 0; i<size; i++)
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
							QString("An error occured : %1.").arg(serverSocket->errorString()));
			break;
	}
	serverSocket->abort();
	emit disconnected();
}

void NetworkController::disconnectedFromServer()
{
	serverSocket->abort();
	emit disconnected();
}
