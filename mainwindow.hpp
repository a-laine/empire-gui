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

		void initialize(QString address, int port);
		void initialize(QString address, int port, int sport);

	public slots:
		void observerMode(bool enabled);

	private:
		Ui::MainWindow *ui;
		QLabel *statusMessage;

		MainController *mainCtrlr;
		Scene *scene;
};

#endif // MAINWINDOW_HPP
