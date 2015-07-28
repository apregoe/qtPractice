#ifndef DRAG2CLIPWIDGET_H
#define DRAG2CLIPWIDGET_H
#include <QtGui>
#include <QtCore>

class Drag2ClipWidget : public QLabel{
	Q_OBJECT
	
public:
	Drag2ClipWidget(QWidget* parent = 0);

protected:
	void mousePressEvent(QMouseEvent* event);
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* event);
	QMimeData* cloneMimeData(const QMimeData* mimedata);
};

#endif