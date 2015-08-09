#include <QApplication>
#include "RotationWidget.h"

int main(int argc, char *argv[]){
	QApplication a(argc,argv);
	RotationWidget h;
	h.show();
	return a.exec();
}