#ifndef ADDRESSMODEL_H
#define ADDRESSMODEL_H

#include <QtGui>
#include <QtCore>

class AddressModel : public QAbstractTableModel{

private:
	void splitCVSLines(QString &);
protected:
	QList<QStringList> addressBook;
public:
	AddressModel(QString& addresses, QObject* parent = 0);
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	int columnCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex & index) const;
	Qt::ItemFlags flags(const QModelIndex & index) const;
	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
};
#endif