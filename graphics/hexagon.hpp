#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include <QGraphicsPolygonItem>



class Hexagon
{
	public:
		enum Type {
			GROUND,
			WATER
		};


		/*!
		 * \brief Return the size of an horizontal hexagon.
		 */
		static QPointF getHorizontalSize();
		/*!
		 * \brief Return the size of a vertical hexagon.
		 */
		static QPointF getVerticalSize();


		/*!
		 * \brief Create an hexagon at the given position.
		 */
		Hexagon(QPointF pos, QGraphicsItem *parent = 0);


		/*!
		 * \brief Set the orientation to horizontal.
		 * Horizontal hexagons have two vertical edges on sides
		 * and two edges on the top and the down each.
		 */
		void setHorizontal();

		/*!
		 * \brief Set the orientation to vertical.
		 * Vertical hexagons have two horizontal edges on the top and the down
		 * and two edges on each sides.
		 */
		void setVertical();

		/*!
		 * \brief Set type of the hexagon.
		 * The type is WATER or GROUND.
		 */
		void setType(Type type);

		QGraphicsItem* getGraphicsItem();

	private:
		QGraphicsPolygonItem *item;
};

#endif // HEXAGON_HPP
