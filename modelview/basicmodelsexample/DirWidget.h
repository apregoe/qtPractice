#ifndef DIRWIDGET_H
#define DIRWIDGET_H

#include <QtGui>
#include <QtCore>

class DirWidget : public QWidget {
Q_OBJECT
public:
	DirWidget(QWidget* parent = 0);
private:
	QFileSystemModel* mDirModel;
	QGridLayout* mLayout;

	QListView* top_left;
	QListView* top_right;
	QTreeView* button_left;
	QTableView* button_right;

	void setupWidgets();

};

#endif