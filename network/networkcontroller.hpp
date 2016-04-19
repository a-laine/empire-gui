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
		NetworkController(QString address, int port, int sport, QObject *parent);
		NetworkController(QString address, int port, QObject *parent);

	signals:

	public slots:

};

#endif // NETWORKCONTROLLER_HPP
