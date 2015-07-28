#ifndef DRAGLABEL_H
#define DRAGLABEL_H

#include <QtGui>
#include <QtCore>

class DragLabel : public QLabel {
public:
	DragLabel(const char* pPath, QWidget* parent = 0);
	
private:
	QString picPath;
	QMimeData* prepareImageDrag(const QString path);

protected:
	void mousePressEvent(QMouseEvent* event);
	
};

#endif