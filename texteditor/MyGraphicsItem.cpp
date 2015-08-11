#include "MyGraphicsItem.h"
#include <iostream>

MyGraphicsItem::MyGraphicsItem(){
	//random start rotation
	angle = qrand() % 360;
	setRotation(angle);

	//set the speed
	speed = 5;//5pixels at a time

	//random start position
	int startx, starty;
	if(qrand()%1){
		startx = (qrand() % 200);
		starty = (qrand() % 200);
	}
	else{
		startx = (qrand() % -100);
		starty = (qrand() % -100);
	}
	std::cout << startx<<" "<<starty<<std::endl;

	this->setPos(mapToParent(starty, starty));
}

QRectF MyGraphicsItem::boundingRect() const{
	return QRectF(0,0,20,20);
}
void MyGraphicsItem::paint(QPainter* painter, QStyleOptionGraphicsItem* option, QWidget* widget){
	QRectF rec = boundingRect();
	QBrush brush(Qt::black);
	//basic collition detection
	if(this->scene()->collidingItems(this).isEmpty()){//we want to know if <i>this</i> item is colliding with anything
		//no collition
		brush.setColor(Qt::black);
	}
	else{
		//collition!!
		brush.setColor(Qt::red);
		DoCollision();
	}

	painter->fillRect(rec, brush);
	painter->drawRect(rec);
}

void MyGraphicsItem::advance(int phase){

	if(!phase){
		return;
	}
	QPointF location = this->pos();
	this->setPos(mapToParent(0, -(speed)));

}

void MyGraphicsItem::DoCollision(){

}
