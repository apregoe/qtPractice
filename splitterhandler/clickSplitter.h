#ifndef CLICKSPLITTER_H
#define CLICKSPLITTER_H

#include <QtGui>
#include <QtCore>

class clickSplitterHandle : public QSplitterHandle{
Q_OBJECT
public:
	clickSplitterHandle(Qt::Orientation orientation, QApplication* app_, QSplitter* parent = 0);
	void mouseDoubleClickEvent(QMouseEvent* event);
private:
	int lastUncollapsedSize;
	QApplication* app;
};

class clickSplitter : public QSplitter{
Q_OBJECT

friend class clickSplitterHandle;

public:
	clickSplitter(Qt::Orientation orientation, QApplication* a_, QWidget* parent = 0)
		: QSplitter(orientation, parent), a(a_){}
	clickSplitter(QWidget* parent = 0)
		: QSplitter(parent){}

protected:
	QSplitterHandle* createHandle(){
		return new clickSplitterHandle(this->orientation(), a, this);
	}

private:
	QApplication* a;

};

#endif