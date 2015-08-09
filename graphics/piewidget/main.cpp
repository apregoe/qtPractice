#include <QApplication>
#include "PieWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc,argv);
	PieWidget h;
	h.addEntry("choice 1", 1);
	h.addEntry("choice 2", 1);
	h.addEntry("choice 3", 1);
	h.addEntry("choice 4", 1);
	h.addEntry("choice 5", 1);
	h.addEntry("choice 6", 1);
	h.addEntry("choice 7", 1);
	h.addEntry("choice 8", 1);
	h.addEntry("choice 9", 1);
	h.addEntry("choice 10", 1);
	h.addEntry("choice 11", 1);
	h.addEntry("choice 12", 1);
	h.addEntry("choice 13", 1);
	h.addEntry("choice 14", 1);
	h.addEntry("choice 15", 1);
	/*h.addEntry("choice 16", 1);
	h.addEntry("choice 17", 1);
	h.addEntry("choice 18", 1);
	h.addEntry("choice 19", 1);
	h.addEntry("choice 20", 1);
	h.addEntry("choice 21", 1);
	h.addEntry("choice 22", 1);
	h.addEntry("choice 23", 1);
	h.addEntry("choice 24", 1);
	h.addEntry("choice 25", 1);
	h.addEntry("choice 26", 1);
	h.addEntry("choice 27", 1);
	h.addEntry("choice 28", 1);
	h.addEntry("choice 29", 1);
	h.addEntry("choice 30", 1);*/
	h.show();


	return a.exec();
}