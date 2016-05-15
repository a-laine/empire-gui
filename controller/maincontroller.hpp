#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <QObject>
#include "graphics/viewinterface.hpp"
#include "network/networkcontroller.hpp"
#include "model/gamemodel.hpp"


class MainController : public QObject
{
		Q_OBJECT
	public:
		explicit MainController(ViewInterface *view, NetworkController *net, QObject *parent = 0);

		void setObserverMode(bool enabled);
		bool getObserverMode();

	signals:
		void sendMessage(QString message);
		void gameError(QString error);
		void gameEnd(bool win);

	public slots:
		void processMessage(QString message);
		void disconnected();

	private:
		void createTile(int x, int y, QString type, bool visible);
		void createCity(int x, int y, int id, int owner);
		void createUnit(int x, int y, int id, int owner, int type);


		ViewInterface *viewInterface;
		NetworkController *networkCtrlr;
		GameModel *model;

		bool observerMode;
};

#endif // MAINCONTROLLER_HPP
