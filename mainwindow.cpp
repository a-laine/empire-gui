#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	scene(new Scene),
	netCtrlr(new NetworkController)
{
	ui->setupUi(this);

	ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
	delete ui;
}
