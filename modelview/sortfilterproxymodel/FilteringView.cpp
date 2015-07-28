#include "FilteringView.h"

FilteringView::FilteringView(QAbstractItemModel* model, QWidget * parent, Qt::WindowFlags f)
		: QWidget(parent, f){
	this->setWindowTitle(tr("Filter View"));
	proxyModel = new QSortFilterProxyModel(this);
	proxyModel->setSourceModel(model);

	QVBoxLayout *lay = new QVBoxLayout(this);
	QHBoxLayout *hlay = new QHBoxLayout;
	QLineEdit *edit = new QLineEdit;
	QComboBox *comboBox = new QComboBox;

	for (int i = 0; i < model->columnCont(); ++i){
		comboBox->addItem(model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
	}

	hlay->addWidget(edit);
	hlay->addWidget(comboBox);

	QTreeView* treeView = new QTreeView;
	treeView->setM
}