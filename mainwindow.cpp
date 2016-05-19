#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "graphics/viewinterface.hpp"
#include "controller/maincontroller.hpp"
#include "network/networkcontroller.hpp"
#include <QFormLayout>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	statusMessage(new QLabel),
	mainCtrlr(0),
	scene(new Scene)
{
	// ui
	ui->setupUi(this);

	//Scene
	ui->graphicsView->setScene(scene);

	// connections
	connect(ui->actionObserver_Mode, SIGNAL(toggled(bool)), this, SLOT(observerMode(bool)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::initialize(QString address, int port, bool observer)
{
	NetworkController *netCtrlr = new NetworkController(address, port, this);
	ViewInterface *viewInt = new ViewInterface(scene, ui);
	mainCtrlr = new MainController(viewInt, netCtrlr, this);
	viewInt->setController(mainCtrlr);

	ui->actionObserver_Mode->setChecked(observer);
	observerMode(observer);

	netCtrlr->connectServer();
}

void MainWindow::initialize(bool observer)
{
	NetworkController *netCtrlr = new NetworkController(this);
	ViewInterface *viewInt = new ViewInterface(scene, ui);
	mainCtrlr = new MainController(viewInt, netCtrlr, this);
	viewInt->setController(mainCtrlr);

	ui->actionObserver_Mode->setChecked(observer);
	observerMode(observer);
}

void MainWindow::observerMode(bool enabled)
{
	if(enabled)
		statusMessage->setText("Observer mode");
	else
		statusMessage->setText("Player mode");
	ui->groupBoxAction->setVisible(!enabled);
	mainCtrlr->setObserverMode(enabled);
}
