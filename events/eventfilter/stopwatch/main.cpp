#include <QApplication>
#include "StopWatch.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StopWatch w;
	w.show();
	return a.exec();
}