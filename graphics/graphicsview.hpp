#ifndef GRAPHICSVIEW_HPP
#define GRAPHICSVIEW_HPP

#include <QGraphicsView>


// This class is used to implement wheel zoom
class GraphicsView : public QGraphicsView
{
		Q_OBJECT
	public:
		explicit GraphicsView(QWidget *parent = 0);

	signals:

	public slots:

	protected:
		void wheelEvent(QWheelEvent *event);
};

#endif // GRAPHICSVIEW_HPP
