#include "TrasposeProxyModel.h"

TrasposeProxyModel::TrasposeProxyModel(QObject* parent)
		: QAbstractProxyModel(parent){
}

QModelIndex TrasposeProxyModel::mapFromSource(const QModelIndex & sourceIndex) const{
	return index(sourceIndex.column(), sourceIndex.row());
}

QModelIndex QAbstractProxyModel::mapToSource(const QModelIndex & proxyIndex) const{
	return sourceModel()->index(proxyIndex.column(), proxyIndex.row());
}

QVariant TrasposeProxyModel::headerData(int section, Qt::Orientation orientation, int role) const{ 
	if (orientation == Qt::Horizontal){
		return sourceModel()->headerData(section, Qt::Vertical, role);
	}
	else{
		return sourceModel()->headerData(section, Qt::Horizontal, role);
	}
}

QVariant TrasposeProxyModel::data(const QModelIndex& index, int role) const{ 
	if (!index.isValid()) return QVariant();
	return sourceModel()->data(mapToSource(index), role);
}

int TrasposeProxyModel::rowCount(const QModelIndex& parent) const{
	return sourceModel()->columnCount(parent);
}

int TrasposeProxyModel::columnCount(const QModelIndex& parent) const {
	return sourceModel()->rowCount(parent);
}

QModelIndex TrasposeProxyModel::parent(const QModelIndex& index) const {
	Q_UNUSED(index);
	return QModelIndex();
}

QModelIndex TrasposeProxyModel::index(int row, int column, const QModelIndex& parent) const{
	Q_UNUSED(parent);
	return createIndex(row, column);
}


