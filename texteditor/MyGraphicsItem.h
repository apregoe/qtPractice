#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QRectF>
#include <QStyleOptionGraphicsItem>
#include <iostream>

/**This Class is an abstract class that is going to
 be inherited by all of our items (MyGraphicsSquareItem, etc...)
 that will connect to each other once they
 are in the canvas/central\ widget/Graphics\ View**/

class MyGraphicsItem : public QGraphicsItem {
//Q_OBJECT

public:
	MyGraphicsItem();
	QRectF boundingRect() const;
	void paint(QPainter* painter, QStyleOptionGraphicsItem* option, QWidget* widget);
protected:
	void advance(int phase);

private:
	qreal angle;
	qreal speed;
	void DoCollision();
	
};

#endif