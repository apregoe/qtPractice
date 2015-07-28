#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QtCore>

class Window : public QDialog {
	Q_OBJECT
public:
	Window(QWidget* parent = 0);

private:

QVBoxLayout* mLayout;
	QHBoxLayout* mBoxLayout;
		QComboBox* mComboBox;
		QToolButton* mToolButton;
			QMenu* toolButtonMenu;
				QAction* tableAction;
				QAction* listAction;
				QAction* treeAction;

	QStackedWidget* mStackedWidget;
		QTreeView* mTreeView;
		QListView* mListView;
		QTableView* mTableView;

	QHBoxLayout* mBoxButtonLayout;
		QPushButton* openButton;
		QPushButton* cancelButton;
	
//Models
	QFileSystemModel* sysModel;
	QItemSelectionModel* selModel;
	void allocate();
	void setupLayout();
	void setupModels();
	void setupConnections();

	QTabBar* t;

protected slots:
void syncActive(const QModelIndex& index);
void switchToDir(const QModelIndex& index);
void switchView(QAction* action);


	
};

#endif