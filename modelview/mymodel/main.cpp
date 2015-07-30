#include <QApplication>
#include <iostream>
#include <fstream>
#include "../mydelegate/CompletionDelegate.h"
#include <QtGui>
#include <QtCore>
#include "AddressModel.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 2){
		return std::cerr<<"No!"<<std::endl;
	}
    QApplication a(argc,argv);

    ifstream file;

    file.open(argv[1]);
    string line;
    string alltext;
    while(getline(file, line)){
    	alltext += line;
       	alltext += "\n";
    }
    file.close();
    QString filetext(QString::fromStdString(alltext));
   	AddressModel g(filetext);

 	QTableView table;
 	table.setModel(&g);
    CompletionDelegate delegate;
    for (int i = 0; i < g.rowCount(); ++i){
        table.setItemDelegateForRow(i, &delegate);
    }
 	table.show();

    return a.exec();
}