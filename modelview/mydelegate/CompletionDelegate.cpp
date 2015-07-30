#include "CompletionDelegate.h"

CompletionDelegate::CompletionDelegate(QObject* parent)
		: QItemDelegate(parent){
}

QWidget * CompletionDelegate::createEditor(QWidget * parent,
		const QStyleOptionViewItem & option, const QModelIndex & index) const{
	const QAbstractItemModel* model = index.model();
	if(!model){
		return QItemDelegate::createEditor(parent, option, index);
	}
	else{
		QComboBox* box = new QComboBox(parent);
		box->setEditable(true);
		box->setAutoCompletion(true);
		box->setModel(const_cast<QAbstractItemModel*>(model));
		box->setModelColumn(index.column());
		/*. 	Now we would have to overwrite the eventFilter() method to intercept
			the keystrokes. In practice, however, QComboBox has such an event
			filter in the private (that is, internally hidden)
			QComboBoxPrivateContainer class,7 which is undocumented, however.
				This means that in theory, the filter may disappear in each new Qt
			release. If you want to be completely sure, you should write your
			own event filter, based on the implementation of this Qt class.*/
		box->installEventFilter(const_cast<CompletionDelegate*>(this));
		return box;
	}
}

void CompletionDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const{
	QComboBox* box = qobject_cast<QComboBox*>(editor);
	if(index.isValid()){
		const QAbstractItemModel* model = index.model();
		if(!model || !box){
			QItemDelegate::setEditorData(editor, index);
		}
		box->setCurrentIndex(index.row());
	}
	else{
		QItemDelegate::setEditorData(editor, index);
	}
	return;
}

void CompletionDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex & index) const{
	if(index.isValid()){
		QComboBox* box = qobject_cast<QComboBox*>(editor);
		if(!box){
			return QItemDelegate::setModelData(editor, model, index);
		}
		else{
			model->setData(index, box->currentText(), Qt::DisplayRole);
			model->setData(index, box->currentText(), Qt::EditRole);
		}
	}
}













