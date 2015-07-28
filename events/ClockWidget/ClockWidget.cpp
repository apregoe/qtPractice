#include "ClockWidget.h"

ClockWidget::ClockWidget(QWidget* parent) :
	QLCDNumber(parent), showClock(true){
	this->setFrameShape(QFrame::Box);
	this->setSegmentStyle(QLCDNumber::Flat);

	updateTimer = QObject::startTimer(100);//routine from QObject class
	switchTimer = QObject::startTimer(10000);//routine call ffrom QObject call

	QTimerEvent* timerEvent = new QTimerEvent(updateTimer);
	QCoreApplication::postEvent(this, timerEvent);

}


/***Using timer Event***/
void ClockWidget::timerEvent(QTimerEvent* event){//this occur each 100ms and 10000 ms
	if(!event) return;

	if(event->timerId() == switchTimer){
		showClock = !showClock;
		//qDebug() << event->timerId();
	}

	if(event->timerId() == updateTimer){
		qDebug() << event->timerId();
		if(showClock){
			QTime time_ = QTime::currentTime();
			QString string = time_.toString();
			setNumDigits(string.length());
			display(string); 
		}
		else{
			QDate date = QDate::currentDate();
			QString string = date.toString(Qt::LocalDate);
			setNumDigits(string.length());
			display(string);
		}
	}
}


/**Using general Event***(Dont use it)
/**
bool ClockWidget::event(QEvent* event){
	if(event == NULL){return true;}

	if(event->type() == QEvent::Timer){
		QTimerEvent* e = static_cast<QTimerEvent*>(event);
		if(e->timerId() == switchTimer){
			showClock = !showClock;
			return true;
		}
		if(e->timerId() == updateTimer){
			if(showClock){
				QTime time_ = QTime::currentTime();
				QString string = time_.toString(Qt::LocalDate);
				setNumDigits(string.length());
				display(string);
				return true;
			}
			else{
				QDate date = QDate::currentDate();
				QString string = date.toString(Qt::LocalDate);
				setNumDigits(string.length());
				display(string);
				return true;
			}
		}
	}
	return QObject::event(event);
}*/