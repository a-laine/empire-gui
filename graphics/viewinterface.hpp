#ifndef VIEWINTERFACE_HPP
#define VIEWINTERFACE_HPP

#include <QObject>
#include <QColor>
#include <QPointF>
#include <QSet>
#include <QVector>
#include <QPair>
#include "ui_mainwindow.h"
#include "hexagon.hpp"
#include "unit.hpp"


class QGraphicsScene;
class MainController;


class ViewInterface : public QObject
{
		Q_OBJECT
	public:

		explicit ViewInterface(QGraphicsScene *scene, Ui::MainWindow* mainWindowUi);


		void setController(MainController* ctrlr);

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
		Unit* createUnit(int x, int y, int id, Unit::Type type, int team);

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
		void actionMoveNE();
		void actionMoveNW();
		void actionMoveE();
		void actionMoveW();
		void actionMoveSE();
		void actionMoveSW();
		void actionEndTurn();
		void actionNextUnit();
		void actionPrevUnit();
		void newTurn();
		void unitSelected();
		void selectedInList(QModelIndex index);
		void productUnit();

	private:
		/*!
		 * \brief Converts game coordinates in graphics coordinates.
		 * This convertion is dependent of the hexagon orientation,
		 * the hexagon size and game coordinates system.
		 */
		static QPointF toGraphicsCoordinates(int x, int y);

		void showInformations(QString type, QVector<QPair<QString, int> > transported);


		QGraphicsScene *scene;
		QSet<GraphicsObject*> objectList;
		Ui::MainWindow* ui;
		MainController* controller;
		int turnNumber;
		int selected;
		QVector<int> selectedTransported;
};

#endif // VIEWINTERFACE_HPP
