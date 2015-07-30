#ifndef TRASPOSEPROXYMODEL_H
#define TRASPOSEPROXYMODEL_H
#include <QtGui>
#include <QtCore>

class TrasposeProxyModel : public QAbstractProxyModel{
Q_OBJECT
public:
	TrasposeProxyModel(QObject *parent = 0);
	QModelIndex mapFromSource(const QModelIndex& sourceIndex) const;
	QModelIndex mapToSource(const QModelIndex& proxyIndex) const;
	QModelIndex index(int, int,const QModelIndex& parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex& index) const;
	int rowCount(const QModelIndex& parent) const;
	int columnCount(const QModelIndex& parent) const;
	QVariant data(const QModelIndex& index,int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const;
};

#endif