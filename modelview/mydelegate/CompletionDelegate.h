		/*CompletionDelegate completes the entry on the
		basis of other entries in the same column of
		the source model.*/
#ifndef COMPLETIONDELEGATE_H
#define COMPLETIONDELEGATE_H
#include <QtGui>
#include <QtCore>

class CompletionDelegate : public QItemDelegate{
public:
	CompletionDelegate(QObject* parent = 0);
	QWidget * createEditor(QWidget * parent,
			const QStyleOptionViewItem & option, const QModelIndex & index) const;
	void setEditorData(QWidget * editor, const QModelIndex & index) const;
	void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex & index) const;

};

#endif