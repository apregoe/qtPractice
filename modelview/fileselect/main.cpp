#include <QApplication>
#include "Window.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //////////////////////
    Window h;
    h.show();
    ///////////////////////////////////////
    QStringListModel model;
    QStringList toBuy;
	toBuy << "butter" << "milk"<< "cherries" << "bananas";
	model.setStringList(toBuy);
	QListView view;
	view.setModel(&model);
	view.show();
	return a.exec();
}