#include <QApplication>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[]){
	QApplication a(argc,argv);
	QRect rec(0,0,800,800);
	QPixmap pixMap(rec.width(), rec.height());
	pixMap.fill();

	QPainter painter(&pixMap);
	painter.setRenderHint(QPainter::Antialiasing, true);
	QPen pen(Qt::blue, 2);
	painter.setPen(pen);
	QBrush brush(Qt::green);
	//painter.setBrush(brush);
	painter.drawEllipse(rec.adjusted(10,10,-100,-100));
	QLabel label;
	label.setPixmap(pixMap);
	label.resize(900,900);
	label.show();

	return a.exec();
}