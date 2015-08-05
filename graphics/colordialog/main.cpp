#include <QApplication>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[]){
	QApplication a(argc,argv);
	bool ok;
	QRgb rgb = QColorDialog::getRgba(qRgba(43,24,12,127), &ok);
	QColor color(rgb);
	if(ok){
		qDebug() << ok;
	}
	else{
		qDebug() << ok;
	}

	QColorDialog::setCustomColor(0, qRgba(43,13,12,43));

	return a.exec();
}