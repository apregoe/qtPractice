#include "RotationWidget.h"

RotationWidget::RotationWidget(QWidget* parent)
	: QWidget(parent), degree(0), timerId(0){}

void RotationWidget::paintEvent(QPaintEvent* ev){
	QWidget::paintEvent(ev);
	QRect paintRect(rect());
	paintRect.setWidth(paintRect.height());
	paintRect.adjust(2,2,-2,-2);
	QPainter p (this);
	p.setRenderHint(QPainter::Antialiasing, true);

	QMatrix matrix;
	matrix.translate(paintRect.height()/2, paintRect.width()/2);
	matrix.rotate(degree);
	matrix.translate(-paintRect.height()/2, -paintRect.width()/2);
	p.setMatrix(matrix);

	QPoint center(paintRect.center());
	p.setBrush(QPixmap("image.jpg"));
	p.setPen(QPen(Qt::black, 2, Qt::DashLine));
	p.drawEllipse(paintRect);
}

void RotationWidget::mousePressEvent(QMouseEvent* event){
	if(event->button() != Qt::LeftButton){
		return;
	}
	if(timerId == 0){
		timerId = startTimer(20);
	}
	else{
		killTimer(timerId);
		timerId = 0;
	}
}

void RotationWidget::timerEvent(QTimerEvent* event){
	if(event->timerId() == timerId){
		rotate(1);
	}
}

void RotationWidget::wheelEvent(QWheelEvent* event){
	rotate(event->delta()/8);
}

void RotationWidget::rotate(int deg){
	degree = degree + (deg%360);
	update();
}











