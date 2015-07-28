#include <QApplication>
#include "Drag2ClipWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc,argv);
	Drag2ClipWidget h;
	h.show();
	return a.exec();
}