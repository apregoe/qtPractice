#include <QApplication>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[]){
	QApplication a(argc,argv);
	QRect rec(0,0,800,1000);
	QPixmap pixMap(rec.size());
	pixMap.fill();

	QPainter painter(&pixMap);
	painter.setRenderHint(QPainter::Antialiasing, true);
	QPen pen(Qt::blue, 2);
	painter.setPen(pen);
	QBrush brush(Qt::green);
	painter.setBrush(brush);
	painter.drawEllipse(rec.adjusted(0,0,400,500));
	QLabel label;
	label.setPixmap(pixMap);
	label.show();

	return a.exec();
}