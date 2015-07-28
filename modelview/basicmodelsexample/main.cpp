#include <QApplication>
#include <QtGui>
#include <QtCore>
#include "DirWidget.h"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	DirWidget h;
	h.show();
	return a.exec();
}