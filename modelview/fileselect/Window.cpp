#include "Window.h"

Window::Window(QWidget* parent) : QDialog(parent){
	this->resize(this->sizeHint());
	this->allocate();
	this->setupLayout();
	this->setupModels();

	for(int row = 0; row < sysModel->rowCount(QModelIndex()); ++row){
		QModelIndex index = sysModel->index(row, 0, QModelIndex());
		qDebug() << sysModel->rowCount(QModelIndex());
		if(index.isValid()){
			mComboBox->addItem(sysModel->fileIcon(index), sysModel->filePath(index));
		}
	}

	setupConnections();
}

void Window::allocate(){
	mLayout = new QVBoxLayout(this);
		mBoxLayout = new QHBoxLayout;
			mComboBox = new QComboBox;
			mToolButton = new QToolButton;
		mStackedWidget = new QStackedWidget;
			mTreeView = new QTreeView;
			mListView = new QListView;
			mTableView = new QTableView;
		mBoxButtonLayout = new QHBoxLayout;
			openButton = new QPushButton("Open");
			cancelButton = new QPushButton("Cancel");

	t = new QTabBar(this);
	t->addTab("1");
	t->addTab("2");
	t->addTab("3");
}

void Window::setupLayout(){
	mLayout->addLayout(mBoxLayout);
		mLayout->addWidget(t);
		mBoxLayout->addWidget(mComboBox, Qt::AlignRight);
		mBoxLayout->addWidget(mToolButton, Qt::AlignRight);
			mToolButton->setCheckable(true);
			mToolButton->setAutoRaise(true);
			mToolButton->setArrowType(Qt::DownArrow);
			toolButtonMenu = new QMenu("Change View");
				tableAction = new QAction("Table View", toolButtonMenu);
				listAction = new QAction("List View", toolButtonMenu);
				treeAction = new QAction("Tree View", toolButtonMenu);
				toolButtonMenu->addAction(treeAction);
				toolButtonMenu->addAction(listAction);
				toolButtonMenu->addAction(tableAction);
			mToolButton->setPopupMode(QToolButton::InstantPopup);
			mToolButton->setMenu(toolButtonMenu);


	mLayout->addWidget(mStackedWidget);
		mStackedWidget->addWidget(mTreeView);
		mStackedWidget->addWidget(mListView);
		mStackedWidget->addWidget(mTableView);
	mLayout->addLayout(mBoxButtonLayout);
		mBoxButtonLayout->addStretch(2);
		mBoxButtonLayout->addWidget(openButton,Qt::AlignRight);
		openButton->setFixedSize(openButton->sizeHint());
		mBoxButtonLayout->addWidget(cancelButton,Qt::AlignRight);
		cancelButton->setFixedSize(cancelButton->sizeHint());
	this->setLayout(mLayout);
}

void Window::setupModels(){
	sysModel = new QFileSystemModel;
	selModel = new QItemSelectionModel(sysModel);

	mListView->setModel(sysModel);
	mTableView->setModel(sysModel);
	mTreeView->setModel(sysModel);

	mListView->setSelectionModel(selModel);
	mTableView->setSelectionModel(selModel);
	mTreeView->setSelectionModel(selModel);

	QModelIndex mModelIndex = sysModel->setRootPath(QDir::rootPath());

	mListView->setRootIndex(mModelIndex);
	mTableView->setRootIndex(mModelIndex);
	mTreeView->setRootIndex(mModelIndex);
}

void Window::setupConnections(){

	connect(mListView, SIGNAL(activated(const QModelIndex&)),
		this, SLOT(switchToDir(const QModelIndex&)));
	connect(mTreeView, SIGNAL(activated(const QModelIndex&)),
		this, SLOT(switchToDir(const QModelIndex&)));
	connect(mTableView, SIGNAL(activated(const QModelIndex&)),
		this, SLOT(switchToDir(const QModelIndex&)));

	connect(mListView, SIGNAL(clicked(const QModelIndex&)), 
		this, SLOT(syncActive(const QModelIndex&)));
	connect(mTreeView, SIGNAL(clicked(const QModelIndex&)), 
		this, SLOT(syncActive(const QModelIndex&)));
	connect(mTableView, SIGNAL(clicked(const QModelIndex&)), 
		this, SLOT(syncActive(const QModelIndex&)));

	connect(toolButtonMenu, SIGNAL(triggered(QAction*)),
		this, SLOT(switchView(QAction*)));
}

void Window::syncActive(const QModelIndex& index){
	if(index.isValid()){
		mListView->setCurrentIndex(index);
		mTableView->setCurrentIndex(index);
		mTreeView->setCurrentIndex(index);
	}
}

void Window::switchToDir(const QModelIndex& index){
	if(sysModel->isDir(index)){
		mListView->setRootIndex(index);
		mTableView->setRootIndex(index);
		mTreeView->setRootIndex(index);
	}
}
void Window::switchView(QAction* action){
	if(action->text() == "Table View"){
		mStackedWidget->setCurrentIndex(mStackedWidget->indexOf(mTableView));
	}
	else if(action->text() == "List View"){
		mStackedWidget->setCurrentIndex(mStackedWidget->indexOf(mListView));
	}
	else if(action->text() == "Tree View"){
		mStackedWidget->setCurrentIndex(mStackedWidget->indexOf(mTreeView));
	}
}


























