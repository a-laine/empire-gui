#ifndef GRAPHICSOBJECT_HPP
#define GRAPHICSOBJECT_HPP

#include <QGraphicsItem>


class GraphicsObject
{
	public:
		GraphicsObject();
		virtual ~GraphicsObject();

		virtual QGraphicsItem* getGraphicsItem() = 0;

	private:

};

#endif // GRAPHICSOBJECT_HPP
