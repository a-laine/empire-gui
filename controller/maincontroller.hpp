#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <QObject>
#include "graphics/viewinterface.hpp"
#include "network/networkcontroller.hpp"


class MainController : public QObject
{
		Q_OBJECT
	public:
		explicit MainController(ViewInterface *view, NetworkController *net, QObject *parent = 0);

	signals:

	public slots:

	private:
		ViewInterface *viewInterface;
		NetworkController *networkCtrlr;
};

#endif // MAINCONTROLLER_HPP
