#ifndef NETWORKCONTROLLER_HPP
#define NETWORKCONTROLLER_HPP

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>


// http://doc.qt.io/qt-5/qtnetwork-fortuneclient-example.html
// http://doc.qt.io/qt-5/qtnetwork-fortuneserver-example.html

class NetworkController : public QObject
{
		Q_OBJECT
	public:
		NetworkController(QString address, int port, int sport = 0, QObject *parent = 0);

		connectServer();
		connectServer(QString address, int port);
		void waitClientConnection();
		void waitClientConnection(int port);

	signals:
		void serverMessage(QString message);
		void clientMessage(QString message);

	public slots:

	private:
		QTcpSocket *serverSocket;
		QTcpSocket *clientSocket;
		QTcpServer *clientServer;

		QString serverAddress;
		int serverPort;
		int clientPort;
};

#endif // NETWORKCONTROLLER_HPP
