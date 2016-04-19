#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "graphics/scene.hpp"



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

	private:
		Ui::MainWindow *ui;
		Scene *scene;
};

#endif // MAINWINDOW_HPP
