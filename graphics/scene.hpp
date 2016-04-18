#ifndef SCENE_HPP
#define SCENE_HPP

#include <QGraphicsScene>


class Scene : public QGraphicsScene
{
	Q_OBJECT
	public:
		explicit Scene(QObject *parent = 0);

	signals:

	public slots:
};

#endif // SCENE_HPP
