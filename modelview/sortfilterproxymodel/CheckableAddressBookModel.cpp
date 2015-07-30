#include "CheckableAddressBookModel.h"

CheckableAddressBookModel::CheckableAddressBookModel(QString& addresses, QObject* parent)
		: AddressModel(addresses, parent){
	for(int i = 0; i < rowCount(); ++i){
		checkedBoxes.append(false);
	}
}

Qt::ItemFlags CheckableAddressBookModel::flags(const QModelIndex &index) const{
	if(!index.isValid()){
		return 0;
	}
	else{
		if(index.column() == 0){
			return AddressModel::flags(index) | Qt::ItemIsUserCheckable;
		}
		else{	
			return AddressModel::flags(index);
		}
	}
}


QVariant CheckableAddressBookModel::data(const QModelIndex & index, int role) const{
	if(!index.isValid()){
		return QVariant();
	}
	else if((index.column() == 0 )&& (role == Qt::CheckStateRole)){
		if(checkedBoxes[index.row()] == true){
			return Qt::Checked;
		}
		else{
			return Qt::Unchecked;
		}
	}
	return AddressModel::data(index, role);
}

bool CheckableAddressBookModel::setData(const QModelIndex & index, const QVariant & value, int role){
	if(!index.isValid()){
		return false;
	}
	else if(role == Qt::CheckStateRole && index.column() == 0){
		checkedBoxes[index.row()] = !checkedBoxes[index.row()];
		emit dataChanged(index,index);
		return true;
	}
	else{
		return AddressModel::setData(index,value,role);
	}
}










