#include "generatefrontend.h"
#include <QtGui/QApplication>
#include "ConfigParser.h"

ConfigParser* FrmMain = NULL;

int main(int argc, char *argv[])
{
	FrmMain = new ConfigParser;
	QApplication a(argc, argv);
	GenerateFrontEnd w;
	w.show();
	return a.exec();
}
