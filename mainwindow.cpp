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
	ui->statusBar->addWidget(statusMessage);

	//Scene
	ui->graphicsView->setScene(scene);

	// connections
	connect(ui->actionObserver_Mode, SIGNAL(toggled(bool)), this, SLOT(observerMode(bool)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::initialize(QString address, int port)
{
	NetworkController *netCtrlr = new NetworkController(address, port, 0, this);
	ViewInterface *viewInt = new ViewInterface(scene);
	mainCtrlr = new MainController(viewInt, netCtrlr, this);
	ui->actionObserver_Mode->setChecked(true);
	observerMode(true);

	netCtrlr->connectServer();
}

void MainWindow::initialize(QString address, int port, int sport)
{
	NetworkController *netCtrlr = new NetworkController(address, port, sport, this);
	ViewInterface *viewInt = new ViewInterface(scene);
	mainCtrlr = new MainController(viewInt, netCtrlr, this);

	ui->actionObserver_Mode->setChecked(false);
	observerMode(false);

	netCtrlr->connectServer();
	netCtrlr->waitClientConnection();
}

void MainWindow::observerMode(bool enabled)
{
	if(enabled)
		statusMessage->setText("Observer mode");
	else
		statusMessage->setText("Player mode");
	mainCtrlr->setObserverMode(enabled);
}
