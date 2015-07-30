#include "AddressModel.h"
#include <iostream>
#include <sstream>
using namespace std;
	
AddressModel::AddressModel(QString & addresses, QObject* parent ) 
		: QAbstractTableModel(parent){
	splitCVSLines(addresses);
}


void AddressModel::splitCVSLines(QString & addresses){
	QStringList records = addresses.split('\n');
	foreach(QString record, records){
		QStringList line;
		std::string str= record.toStdString();
		stringstream a;
		a << str;
		string boxinfo;
		string foo;
		while(a >> foo){
			if(foo == "|"){
				boxinfo.erase(boxinfo.begin() + boxinfo.size()-1);//erasing the las space
				line << QString::fromStdString(boxinfo);
				boxinfo = "";
				continue;
			}
			boxinfo.append(foo);
			boxinfo.append(" ");
			foo = "";
		}
		addressBook.append(line);
	}
}

int AddressModel::rowCount(const QModelIndex & parent) const{
	Q_UNUSED(parent);
	return addressBook.count()-2;
}

int AddressModel::columnCount(const QModelIndex & parent) const{
	Q_UNUSED(parent);
	return addressBook.at(0).size();
}


QVariant AddressModel::data(const QModelIndex & index, int role) const{
	if(!index.isValid()){
		return QVariant();
	}
	//We are working with the row, always
	QStringList addressRecord = addressBook.at(index.row() +1);
	if(role == Qt::DisplayRole || role == Qt::EditRole){
		return addressRecord.at(index.column());
	}
	if(role == Qt::ToolTipRole){
		QString returnTip, key, value;
		returnTip = "<qt><table>";
		for (int i = 0; i < addressRecord.count(); ++i){
			key = this->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString();
			value = addressRecord.at(i);
			if(!value.isEmpty()){
				returnTip += QString("<tr><td><b>%1</b>: %2</td></tr>").arg(key, value);
			}
		}
		returnTip += "</table></qt>";
		return returnTip;
	}
	return QVariant();
}

QVariant AddressModel::headerData(int section, Qt::Orientation orientation,
		int role) const{
	if(orientation == Qt::Horizontal){
		if(role == Qt::DisplayRole){
			return (addressBook[0]).at(section);
		}
	}
	return QAbstractTableModel::headerData(section, orientation, role);
}

QModelIndex AddressModel::index(int row, int column, const QModelIndex & parent) const{
	Q_UNUSED(parent);
	return QAbstractTableModel::createIndex(row, column);
}

QModelIndex AddressModel::parent(const QModelIndex & index) const{
	Q_UNUSED(index);
	return QModelIndex();
}

Qt::ItemFlags AddressModel::flags(const QModelIndex & index) const{
	if (!index.isValid()){
		return 0;
	}
	else{
		return QAbstractTableModel::flags(index);
	}
}
bool AddressModel::setData(const QModelIndex & index,
		const QVariant & value, int role){
	if((index.isValid()) && ((role == Qt::EditRole)/*||(Qt::DisplayRole)*/)){
		addressBook[index.row() +1][index.column()] = value.toString();
		emit dataChanged(index, index);
		return true;
	}
	else{
		return false;
	}
}
bool AddressModel::insertRows(int row, int count, const QModelIndex & parent){
	QStringList newRow;
	Q_UNUSED(parent);
	for(int i = 0; i < (addressBook[0]).size(); ++i){
		newRow << "";
	}
	beginInsertRows(QModelIndex(), row, row+count-1);
	for(int i = 0; i < count; ++i){
		addressBook.insert(row+i, newRow);
	}
	endInsertRows();
	return true;
}

bool AddressModel::removeRows(int row, int count, const QModelIndex & parent){
	Q_UNUSED(parent);
	if(row-count > addressBook.size()){return false;}
	beginRemoveRows(QModelIndex(), row, count+row-1);
	for (int i = 0; i < count; ++i){
		addressBook.removeAt(row+1);
	}
	endRemoveRows();
	return true;
}











