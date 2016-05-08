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
		 * \brief Initialize network related components.
		 * Initialize main controller and network controller
		 * considering the given server address and port.
		 * The application is launched in interactive mode.
		 */
		void initialize(QString address, int port);

		/*!
		 * \brief Initialize network related components.
		 * Initialize main controller and network controller
		 * considering the given server address and port
		 * and the given client port.
		 * The application is launched in observer mode.
		 */
		void initialize(QString address, int port, int sport);

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
