#include "StopWatch.h"

StopWatch::StopWatch(QWidget* parent) : QWidget(parent), state(0){
	seconds = new QTimer(this);
	display = new QLCDNumber(this);
	sec = 0;
	setWindowTitle("My babyboo <3");
	QVBoxLayout* lay = new QVBoxLayout(this);

	QPushButton* reset = new QPushButton("Start/Stop/Reset");

	connect(seconds, SIGNAL(timeout()), this, SLOT(update_()));
	seconds->start(1000);
	seconds->stop();

	lay->addWidget(display);
	lay->addWidget(reset);

	//connect buttons
	connect(reset, SIGNAL(clicked()), this, SLOT(button_clicked()));
	setLayout(lay);
}

void StopWatch::button_clicked(){
	if(state == 0){
		seconds->start(1000);
		state = 1;
	}
	else if(state== 1){
		seconds->stop();
		state = 2;
	}
	else if (state == 2){
		sec = 0;
		wipe();
		state = 0;
	}
}

void StopWatch::wipe(){
	display->display(0);
}

void StopWatch::update_(){
	sec ++;
	display->display(sec);
}