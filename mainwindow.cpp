#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "graphics/viewinterface.hpp"
#include "controller/maincontroller.hpp"
#include "network/networkcontroller.hpp"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	scene(new Scene)
{
	ui->setupUi(this);

	ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::initialize(QString address, int port)
{
	NetworkController *netCtrlr = new NetworkController(address, port, this);
	ViewInterface *viewInt = new ViewInterface(scene);
	MainController *mainCtrlr = new MainController(viewInt, netCtrlr, this);
}

void MainWindow::initialize(QString address, int port, int sport)
{
	NetworkController *netCtrlr = new NetworkController(address, port, sport, this);
	ViewInterface *viewInt = new ViewInterface(scene);
	MainController *mainCtrlr = new MainController(viewInt, netCtrlr, this);
}
