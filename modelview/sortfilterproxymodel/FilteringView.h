#ifndef FILTERINGVIEW_H
#define FILTERINGVIEW_H
#include <QtGui>
#include <QtCore>

class FilteringView : public QWidget{
Q_OBJECT
public:
	FilteringView(QAbstractItemModel* model, QWidget * parent = 0, Qt::WindowFlags f = 0);
private:
	QSortFilterProxyModel* proxyModel;
	
};

#endif