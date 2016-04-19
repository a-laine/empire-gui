#include "mainwindow.hpp"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCoreApplication::setApplicationName("empire-gui");

	QCommandLineParser parser;
	parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
	parser.addHelpOption();
	parser.addPositionalArgument("address", "Server address.");
	parser.addPositionalArgument("port", "Server port.");
	QCommandLineOption portOption(QStringList() << "sport", "Source port for client connection.", "sport");
	parser.addOption(portOption);

	parser.process(a);

	MainWindow w;
	QStringList args = parser.positionalArguments();
	if(args.size() != 2)
	{
		parser.showHelp(1); // exit error
	}
	QString address = args.at(0);
	int port = args.at(1).toInt();
	if(address.isEmpty() || port<1024 || port>65535)
	{
		parser.showHelp(1); // exit error
	}
	if(parser.isSet(portOption) && !parser.value(portOption).isEmpty())
	{
		int sport = parser.value(portOption).toInt();
		if(sport<1024 || sport>65535)
		{
			parser.showHelp(1); // exit error
		}
		w.initialize(address, port, sport);
	}
	else
	{
		w.initialize(address, port);
	}
	w.show();

	return a.exec();
}
