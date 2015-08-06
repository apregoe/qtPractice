#include <QApplication>
#include "PaintWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc,argv);
	PaintWidget h;
	h.show();
	return a.exec();
}