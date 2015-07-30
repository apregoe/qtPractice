#include <QApplication>
#include <iostream>
#include <fstream>
#include "CheckableAddressBookModel.h"
#include "FilteringView.h"

int main(int argc, char *argv[]){
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
    CheckableAddressBookModel g(filetext);
    FilteringView h(&g);
    h.show();
    return a.exec();
}