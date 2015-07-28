#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QtGui>
#include <QtCore>

class StopWatch : public QWidget{
Q_OBJECT
public:
	StopWatch(QWidget* parent = 0);

private:
	QTimer* seconds;
	QLCDNumber* display;
	int state; //0 = 0.0, 1= 0.0+ 
	int sec;
	void wipe();
private slots:
    void update_();
    void button_clicked();

};

#endif