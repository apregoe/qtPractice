#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H
#include <QtGui>
#include <QtCore>

class PaintWidget : public QWidget{
Q_OBJECT
public:
	PaintWidget(QWidget* parent = 0);
	~PaintWidget() {}
	void paintEvent(QPaintEvent * event);
	QSize sizeHint() const {return QSize(200,500);}
	int x;
};

#endif