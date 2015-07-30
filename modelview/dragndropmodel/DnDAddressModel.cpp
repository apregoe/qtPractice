#include "DnDAddressModel.h"

DnDAddressModel::DnDAddressModel(QString& addresses, QObject* parent)
		: AddressModel(addresses, parent){
}

Qt::ItemFlags DnDAddressModel::flags(const QModelIndex & index) const{
	Qt::ItemFlags flags = AddressModel::flags(index);

	if(index.isValid()){
		return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | flags;
	}
	else{
		return Qt::ItemIsDropEnabled | flags;
	}
}

QStringList DnDAddressModel::mimeTypes() const{
	QStringList types;
	types << "application/x-osp.text.csv";
	return types;
}

QMimeData* DnDAddressModel::mimeData(const QModelIndexList &indexes) const{
	QMimeData* mimeData = new QMimeData();
	QList<int> rows;
	foreach(QModelIndex index, indexes){
		if(index.isValid()){
			if(!rows.contains(index.row())){
				rows += index.row();
			}
		}
	}
	QByteArray encodedData;
	QDataStream stream(&encodedData, QIODevice::WriteOnly);
	foreach(int row, rows){
		stream << addressBook.at(row+1);
	}
	mimeData->setData("application/x-osp.text.csv", encodedData);
	return mimeData;
}

bool DnDAddressModel::dropMimeData( const QMimeData *data, Qt::DropAction action,
         int row, int column, const QModelIndex &parent ){
	Q_UNUSED(column); Q_UNUSED(parent);
	if(action == Qt::IgnoreAction){
		return true;
	}
	else if(!data->hasFormat("application/x-osp.text.csv")){
		return false;
	}

	if(row == -1){
		row = rowCount();
	}
	QByteArray encodedData = data->data("application/x-osp.text.csv");
	QDataStream stream(&encodedData, QIODevice::ReadOnly);
	QList<QStringList> lists;
	while(!stream.atEnd()){
		stream >> lists;
	}

	int rows = lists.size();
	insertRows(row, rows, QModelIndex());
	foreach(QStringList line, lists){
		addressBook.replace(row+1, line);
		++row;
	}
	return true;
}

















