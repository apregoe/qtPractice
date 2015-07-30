#include <QApplication>
#include <QtGui>
#include <iostream>
#include <fstream>
#include "DnDAddressModel.h"

int main( int argc, char* argv[] ){
	if(argc != 2){
		return std::cerr<<"No!"<<std::endl;
	}
    QApplication a(argc,argv);

    std::ifstream file;

    file.open(argv[1]);
    std::string line;
    std::string alltext;
    while(getline(file, line)){
    	alltext += line;
       	alltext += "\n";
    }
    file.close();
    QString filetext(QString::fromStdString(alltext));

	DnDAddressModel model(filetext);

	QListView listView;
	listView.setModel(&model);
	listView.setModelColumn(0);
	listView.show();

	QTreeView treeView;
	treeView.setModel(&model);
	treeView.show();

	QTableView tableView;
	tableView.setModel(&model);
	tableView.show();

	return a.exec();
}