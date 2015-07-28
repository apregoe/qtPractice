#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include "ClockWidget.h"
#include <QtGui>
#include <QtCore>

class ClockWidget : public QLCDNumber{
Q_OBJECT
public:
	ClockWidget(QWidget* parent =0);

protected:
	void timerEvent(QTimerEvent* event);
	//bool event(QEvent* event);

private:
	int updateTimer, switchTimer;
	bool showClock;
	
};

#endif