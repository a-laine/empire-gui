#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <QObject>

class MainController : public QObject
{
		Q_OBJECT
	public:
		explicit MainController(QObject *parent = 0);

	signals:

	public slots:
};

#endif // MAINCONTROLLER_HPP