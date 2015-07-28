#include <QApplication>
#include "ChatWindow.h"

int main(int argc, char *argv[]){
	QApplication a(argc,argv);
	//b->installFilterEvent(this);
	ChatWindow w;
	w.show();
	return a.exec();
}