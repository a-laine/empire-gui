#include "mainwindow.hpp"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <iostream>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCoreApplication::setApplicationName("empire-gui");

	// Configure parser for command line arguments
	QCommandLineParser parser;
	parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
	parser.addHelpOption();
	QCommandLineOption modeOption("obs", "Start the client as observer.");
	parser.addOption(modeOption);
	QCommandLineOption addressOption("saddr", "Server address.", "port", "localhost");
	parser.addOption(addressOption);
	QCommandLineOption portOption("sport", "Server port.", "port", "0");
	parser.addOption(portOption);

	// Get arguments values
	parser.process(a);

	MainWindow w;

	// Process arguments
	QStringList args = parser.positionalArguments();
	QString address = parser.value("saddr");
	int port = parser.value("sport").toInt();
	w.initialize(address, port, parser.isSet(modeOption));
	w.show();

	return a.exec();
}
