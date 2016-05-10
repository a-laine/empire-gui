#ifndef NETWORKCONTROLLER_HPP
#define NETWORKCONTROLLER_HPP

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>



class NetworkController : public QObject
{
		Q_OBJECT
	public:
		NetworkController(QString address, int port, QObject *parent = 0);
		NetworkController(QObject *parent = 0);


		void connectServer();
		void connectServer(QString address, int port);

	signals:
		void serverMessage(QString message);
		void disconnected();

	public slots:
		void sendMessageToServer(QString message);

	private slots:
		void messageReceived();
		void socketError(QAbstractSocket::SocketError socketError);
		void disconnectedFromServer();

	private:
		QTcpSocket *serverSocket;

		QString serverAddress;
		int serverPort;

		QString serverMsg;
};

#endif // NETWORKCONTROLLER_HPP
