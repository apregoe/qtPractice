#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include "DragLabel.h"
#include "DropLabel.h"

int main(int argc, char *argv[]){
	if(argc != 2){
		std::cerr << "please provide a filepath to an image" <<std::endl;
		return 1;
	}
	QFile file(argv[1]);
	if(!file.open(QIODevice::ReadOnly)){
		std::cerr << "please provide a valid filepath" <<std::endl;;
		return 1;
	}
	file.close();

	QApplication a(argc, argv);
	DragLabel w(argv[1]);
	w.show();
	DropLabel h;
	h.show();
	return a.exec();
}