#ifndef NETWORKCONTROLLER_HPP
#define NETWORKCONTROLLER_HPP

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>



class NetworkController : public QObject
{
		Q_OBJECT
	public:
		NetworkController(QString address, int port, int sport = 0, QObject *parent = 0);

		void connectServer();
		void connectServer(QString address, int port);
		void waitClientConnection();
		void waitClientConnection(int port);

	signals:
		void serverMessage(QString message);
		void clientMessage(QString message);
		void disconnected();

	public slots:
		void sendMessageToServer(QString message);
		void sendMessageToClient(QString message);

	private slots:
		void messageFromServer();
		void messageFromClient();
		void socketError(QAbstractSocket::SocketError socketError);
		void clientConnexion();
		void disconnectedFromClient();
		void disconnectedFromServer();

	private:
		QTcpSocket *serverSocket;
		QTcpSocket *clientSocket;
		QTcpServer *clientServer;

		QString serverAddress;
		int serverPort;
		int clientPort;

		QString serverMsg;
		QString clientMsg;
};

#endif // NETWORKCONTROLLER_HPP
