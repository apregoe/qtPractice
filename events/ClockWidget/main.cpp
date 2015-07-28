#include <QApplication>
#include "ClockWidget.h"

int main(int argc, char *argv[]){

	QApplication a(argc,argv);
	ClockWidget w;
	w.show();
	return a.exec();
}