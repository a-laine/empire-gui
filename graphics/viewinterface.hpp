#ifndef VIEWINTERFACE_HPP
#define VIEWINTERFACE_HPP

#include <QObject>
#include <QColor>
#include <QGraphicsScene>
#include <QPointF>
#include <QSet>
#include "hexagon.hpp"
#include "unit.hpp"


class ViewInterface : public QObject
{
		Q_OBJECT
	public:

		explicit ViewInterface(QGraphicsScene *parent = 0);


		/*!
		 * \brief Set the size of the map and the hexagon orientation.
		 * Setting the size of the map improve rendering efficiency
		 * and initial camera position.
		 */
		void setMapSize(int x, int y);

		/*!
		 * \brief Create an hexagon on the view.
		 * The hexagon is set at the given coordinates
		 * and with a colour dependent of the given type.
		 * Ownership is kept by this class.
		 */
		Hexagon* createHexagon(int x, int y, Hexagon::Type type);

		/*!
		 * \brief Create a unit on the view.
		 * The hexagon is set at the given coordinates
		 * and with the given colour.
		 * Ownership is kept by this class.
		 */
		Unit* createUnit(int x, int y, Unit::Type type, QColor color);

		/*!
		 * \brief Move the unit to the given coordinates.
		 */
		void move(Unit* unit, int x, int y);

		/*!
		 * \brief Remove the unit from the view.
		 * After call, the object passed in argument is deleted.
		 */
		void remove(Unit* unit);

		/*!
		 * \brief Remove the hexagon from the view.
		 * After call, the object passed in argument is deleted.
		 */
		void remove(Hexagon* hexagon);

		/*!
		 * \brief Remove and delete all componants in the scene.
		 */
		void clearView();

	signals:

	public slots:

	private:
		/*!
		 * \brief Converts game coordinates in graphics coordinates.
		 * This convertion is dependent of the hexagon orientation,
		 * the hexagon size and game coordinates system.
		 */
		static QPointF toGraphicsCoordinates(int x, int y);

		QGraphicsScene *scene;
		QSet<GraphicsObject*> objectList;
};

#endif // VIEWINTERFACE_HPP
