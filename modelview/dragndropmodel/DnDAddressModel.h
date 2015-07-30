#ifndef DNDADDRESSMODEL_H
#define DNDADDRESSMODEL_H
#include <QtGui>
#include <QtCore>
#include "AddressModel.h"

class DnDAddressModel : public AddressModel{
public:
   DnDAddressModel(QString& addresses, QObject* parent = 0);
   Qt::ItemFlags flags(const QModelIndex & index) const;
   QStringList mimeTypes() const;
   QMimeData *mimeData( const QModelIndexList &indexes ) const;
   bool dropMimeData( const QMimeData *data, Qt::DropAction action,
         int row, int column, const QModelIndex &parent );
};

#endif