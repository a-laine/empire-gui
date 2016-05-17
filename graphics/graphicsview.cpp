#include "graphicsview.hpp"

#include <QWheelEvent>


GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{
}

void GraphicsView::wheelEvent(QWheelEvent* event)
{
	if(event->modifiers() & Qt::ControlModifier)
	{
		qreal ratio;
		if(event->delta() >= 0)
			ratio = 1.1;
		else
			ratio = 1.0 / 1.1;

		setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
		scale(ratio, ratio);
	}
}
