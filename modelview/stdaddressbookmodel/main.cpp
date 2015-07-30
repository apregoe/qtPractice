#include <QApplication>
#include <QtGui>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QtCore>

using namespace std;

QStringList splitCVSLines(const QString & addresses){
   QStringList records = addresses.split('\n');
   QStringList returnList;
   foreach(QString record, records){
      QStringList line;
      std::string str= record.toStdString();
      stringstream a;
      a << str;
      string boxinfo;
      string foo;
      while(a >> foo){
         if(foo == "|"){
            boxinfo.erase(boxinfo.begin() + boxinfo.size()-1);//erasing the las space
            line << QString::fromStdString(boxinfo);
            boxinfo = "";
            continue;
         }
         boxinfo.append(foo);
         boxinfo.append(" ");
         foo = "";
      }
      returnList.append(line);
   }
   return returnList;
}

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
   QStringList records = filetext.split('\n');
   QString header = records.takeFirst();
   QStringList headers = splitCVSLines(header);

   QStandardItemModel model(records.count(), headers.count());
   //add headers
   for (int i = 0; i < headers.count(); ++i){
      model.setHeaderData(i, Qt::Horizontal, headers.at(i));
   }

   //add content
   for (int i = 0; i < records.count(); ++i){
      QStringList cells = splitCVSLines(records.at(i));
      for (int j = 0; j < cells.count(); ++j){
      	QModelIndex index = model.index(i, j, QModelIndex());
      	model.setData(index, cells.at(j));
      }
   }
	// Create, set and show model
	QTreeView treeView; treeView.setWindowTitle(QObject::tr("Addressbook via QStandardItemModel"));
	treeView.setModel(&model);
	treeView.show();

   return a.exec();
}









