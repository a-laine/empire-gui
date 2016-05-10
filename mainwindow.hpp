#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QLabel>
#include "graphics/scene.hpp"
#include "controller/maincontroller.hpp"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		/*!
		 * \brief Initialize all non GUI components.
		 * Initialize main controller and network controller
		 * considering the given server port.
		 * The application is launched in observer mode if
		 * observer is set to true and in interactive mode if not.
		 */
		void initialize(QString address, int port, bool observer);

		/*!
		 * \brief Initialize all non GUI components.
		 * Initialize main controller and network controller
		 * but don't connect to server.
		 * The application is launched in observer mode if
		 * observer is set to true and in interactive mode if not.
		 */
		void initialize(bool observer);

	public slots:
		/*!
		 * \brief Set the mode.
		 * Set the mode to interactive (false) or observer (true).
		 * This slot is connected with UI buttons.
		 */
		void observerMode(bool enabled);

	private:
		Ui::MainWindow *ui;
		QLabel *statusMessage;

		MainController *mainCtrlr;
		Scene *scene;
};

#endif // MAINWINDOW_HPP
