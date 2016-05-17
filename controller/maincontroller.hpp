#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <QObject>
#include <QVector>
#include <QPair>


class GameModel;
class ViewInterface;
class NetworkController;


class MainController : public QObject
{
		Q_OBJECT
	public:
		explicit MainController(ViewInterface *view, NetworkController *net, QObject *parent = 0);

		void setObserverMode(bool enabled);
		bool getObserverMode();
		void getInfo(int id, QString& type, QVector<QPair<QString,int>>& transported);
		void endTurn();
		void movePiece(int id, QString direction);
		void setProduction(int idCity, QString type);

	signals:
		void sendMessage(QString message);
		void gameError(QString error);
		void gameEnd(bool win);

	public slots:
		void processMessage(QString message);
		void disconnected();

	private:
		QString typeToString(int type);
		int stringToType(QString type);
		void createTile(int x, int y, QString type, bool visible);
		void createCity(int x, int y, int id, int owner);
		void createUnit(int x, int y, int id, int owner, int type);


		ViewInterface *viewInterface;
		NetworkController *networkCtrlr;
		GameModel *model;

		bool observerMode;
};

#endif // MAINCONTROLLER_HPP
