#include "PaintWidget.h"

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent), x(0){
}

void PaintWidget::paintEvent(QPaintEvent * event){
	//QWidget::paintEvent(event);
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing, true);
	QPen pen(Qt::blue, 2);
	p.setPen(pen);
	QBrush brush(Qt::green);
	brush.setStyle(Qt::Dense4Pattern);
	p.setBrush(brush);
	QRect rec = rect().adjusted(10,10,-10,-10);
	p.drawEllipse(rec);
	++x;
	qDebug() << x <<endl;
}