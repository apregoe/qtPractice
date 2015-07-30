#include "FilteringView.h"

FilteringView::FilteringView(QAbstractItemModel* model, QWidget * parent, Qt::WindowFlags f)
		: QWidget(parent, f){
	this->setWindowTitle(tr("Filter View"));
	proxyModel = new TrasposeProxyModel(this);
	proxyModel->setSourceModel(model);

	QVBoxLayout *lay = new QVBoxLayout(this);
	QHBoxLayout *hlay = new QHBoxLayout;
	QLineEdit *edit = new QLineEdit;
	QComboBox *comboBox = new QComboBox;

	for (int i = 0; i < model->columnCount(); ++i){
		comboBox->addItem(model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
	}

	hlay->addWidget(edit);
	hlay->addWidget(comboBox);

	QTreeView* treeView = new QTreeView;
	treeView->setModel(proxyModel);
	treeView->setAlternatingRowColors(true);

	//Make the header clickable
	treeView->header()->setClickable(true);
	//sort indicator festlegen (Ascending order)
	treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
	treeView->header()->setSortIndicatorShown(true);
	//initial sort
	treeView->sortByColumn(0, Qt::AscendingOrder);

	lay->addLayout(hlay);
	lay->addWidget(treeView);
	this->setLayout(lay);

	//setFilterFixedString() || setFilteredWildcard()
	connect(edit, SIGNAL(textChanged(const QString &)),
			proxyModel, SLOT(setFilterRegExp(const QString &)));
}













