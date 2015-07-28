#include <QApplication>
#include "ConfigWidget.h"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	ConfigWidget* w = new ConfigWidget;
	QIcon icon("../../reall/images/menuactionicons/new.png");
	w->addPage("1st page", icon, new QLabel("1"));
	w->addPage("2st page", icon, new QLabel("2"));
	w->addPage("3st page", icon, new QLabel("3"));
	w->show();
	return a.exec();
}