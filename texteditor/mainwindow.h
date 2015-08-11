#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QRectF>
#include <QPushButton>
#include <QBrush>
#include <QTimer>
#include <QSplitter>
#include <QGraphicsView>
#include <QDebug>
#include <QLabel>
#include <QGraphicsItem>
#include <QPen>
#include <QObject>
#include <QIODevice>
#include <QFileDialog>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QScrollArea>
#include <QToolBar>
#include <QWidget>
#include <QDesktopWidget>
#include <QListView>
#include <QAction>
#include <QSettings>
#include <QKeySequence>
#include <QTextEdit>
#include <QDockWidget>
#include <QMessageBox>

#include "FeaturesHandler.h"

class MainWindow : public QMainWindow{
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void Save_as_file();
	void Exit_file();
	void Save_File();
	void Undo_routine();
	void Redo_routine();
	void New_routine();
	void Load_File();

	void hide_statusbar();

private:
    QMenu* MainWindow_QMenu;
    QMenu* View_Menu;
    QMenu* Edit_Menu;
    QToolBar* MainWindow_ToolBar;

    //Central Widget
   	QGraphicsView* Canvas_GView;
   	QGraphicsScene* Canvas_GScene;
   	QTextEdit* text;

   	//DockWidget
   	QDockWidget* Features_DockWidget;
   		QListView* docklist;

   	//Splitter for central widget ad dockwidget
   	QSplitter* DockWidget_CentralWidget_Splitter;

    //Menu Actions
    QAction* NewAction;
    QAction* SaveAsAction;
    QAction* SaveAction;
    QAction* ExitAction; 
    QAction* UndoAction;
    QAction* RedoAction;
    QAction* CopyAction;
    QAction* LoadAction;
    	QString Filepath;//file path in which the widget is

    //
    void setupActions();
    void createMenu();
    void createToolBar();
    void setupCentralWidget();
    void createDockWidget();
    bool MayDiscard();
    void writeSettings();
    void readSettings();


};

#endif
