#include "DirWidget.h"

DirWidget::DirWidget(QWidget* parent) : QWidget(parent){
	QDesktopWidget d;
	resize(d.height()*0.65, d.width()*0.65);
	mLayout = new QGridLayout(this);
	mDirModel = new QFileSystemModel;
	mDirModel->setRootPath(QDir::currentPath());
	top_left = new QListView;
	top_right = new QListView;
	button_left = new QTreeView;
	button_right = new QTableView;

	setupWidgets();

	this->setLayout(mLayout);

}

void DirWidget::setupWidgets(){
	mLayout->addWidget(top_left, 0,0,1,1);
	top_left->setViewMode(QListView::ListMode);
	top_left->setModel(mDirModel);

	mLayout->addWidget(top_right, 0,1,1,1);
	top_right->setViewMode(QListView::IconMode);
	top_right->setModel(mDirModel);

	mLayout->addWidget(button_left,1,0,1,1);
	button_left->setModel(mDirModel);

	mLayout->addWidget(button_right,1,1,1,1);
	button_right->setModel(mDirModel);

	top_left->setRootIndex(mDirModel->index(QDir::currentPath()));
	top_right->setRootIndex(mDirModel->index(QDir::currentPath()));
	button_left->setRootIndex(mDirModel->index(QDir::currentPath()).parent());
	button_right->setRootIndex(mDirModel->index(QDir::currentPath()));

}