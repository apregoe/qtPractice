#ifndef DROPLABEL_H
#define DROPLABEL_H

#include <QtGui>
#include <QtCore>

class DropLabel : public QLabel {
public:
	DropLabel(QWidget* parent = 0);

protected:
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* event);
};

#endif