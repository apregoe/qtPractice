#ifndef CHECKABLEADDRESSBOOKMODEL_H
#define CHECKABLEADDRESSBOOKMODEL_H

#include <QtGui>
#include <QtCore>
#include "AddressModel.h"

class CheckableAddressBookModel : public AddressModel{
Q_OBJECT
public:
   CheckableAddressBookModel(QString& addresses, QObject* parent = 0);
   QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
   bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
   Qt::ItemFlags flags(const QModelIndex &index) const;
private:
   QList<bool> checkedBoxes;
};

#endif