#include "mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){

    this->setWindowTitle("Re:all - Infogram Software");
    QDesktopWidget dw;

    this->resize(dw.width()*0.65, dw.height()*0.65);

    
    setupCentralWidget();
    
    setupActions();
    
    createDockWidget();
    
	createToolBar();
	
    createMenu();
	readSettings();

}

MainWindow::~MainWindow(){
	qDebug() << "It did It!";\
	writeSettings();
	delete this;
}

void MainWindow::Save_as_file(){
	Filepath = QFileDialog::getSaveFileName(this, "Save File", Filepath);
	if(!Filepath.isEmpty()) Save_File();
}

void MainWindow::Save_File(){
	if(Filepath.isEmpty() || Filepath == "Untitled.txt") {
		Save_as_file();
		return;
	}

	QFile file(Filepath);
	if(file.open(QIODevice::WriteOnly)){
		file.write(text->toPlainText().toUtf8());
		statusBar()->showMessage("Succesfully saved to" + Filepath);
	}
}

void MainWindow::Exit_file(){
	this->close();
}

bool MainWindow::MayDiscard(){
	if(text->document()->isModified()){
		if(Filepath.isEmpty()) Filepath = "Untitled.txt";
		if(!QMessageBox::question(this, "Save Document?",
			QString("Do you want to save the changes made in ") +  Filepath,
			"Save Document", "Discard Changes")){
			qDebug()<<"ou!";
			Save_as_file();
		}
		return true;
	}
	return false;
}

void MainWindow::hide_statusbar(){statusBar()->hide();}

void MainWindow::Undo_routine(){text->document()->undo();}

void MainWindow::Redo_routine(){text->document()->redo();}

void MainWindow::New_routine(){
	if(!MayDiscard());
	text->setText("");
	Filepath = "";
}
void MainWindow::Load_File(){
	Filepath = QFileDialog::getOpenFileName(this);
	qDebug() << Filepath;
	QFile file(Filepath);
	if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
		text->setPlainText(QString::fromUtf8(file.readAll()));
		statusBar()->showMessage("Succesfully loaded File", 3000);
	}
}

void MainWindow::setupCentralWidget(){
	text = new QTextEdit("Write Here",this);
	Canvas_GScene = new QGraphicsScene(-200,-200,400,400, this);
	Canvas_GView = new QGraphicsView(Canvas_GScene);

	setCentralWidget(text);
}

void MainWindow::setupActions(){
	SaveAsAction = new QAction(QIcon("images/menuactionicons/Save_as.png"), "Save As", this);
	SaveAsAction->setShortcut(QKeySequence("Ctrl+S"));
	SaveAsAction->setStatusTip("Save Infographic to a file");
	connect(SaveAsAction, SIGNAL(triggered(bool)), this, SLOT(Save_as_file()));

	SaveAction = new QAction(QIcon("images/menuactionicons/save.png"), "Save", this);
	SaveAction->setShortcut(QKeySequence("Ctr+S"));
	SaveAsAction->setStatusTip("Save Infographic to a file");
	connect(SaveAction,SIGNAL(triggered(bool)), this,SLOT(Save_File()));

	ExitAction = new QAction(QIcon("images/menuactionicons/exit.png"), "Exit", this);
	ExitAction->setShortcut(QKeySequence::Close);
	ExitAction->setStatusTip("Exit Program");
	connect(ExitAction, SIGNAL(triggered(bool)), this, SLOT(Exit_file()));

	LoadAction = new QAction(QIcon("images/menuactionicons/load.png"), "Load", this);
	LoadAction->setShortcut(QKeySequence::Open);
	LoadAction->setStatusTip("Load File");
	LoadAction->setWhatsThis("Load an exixsting file, just click \n here and choose one");
	connect(LoadAction, SIGNAL(triggered(bool)), this, SLOT(Load_File()));

	UndoAction = new QAction(QIcon("images/menuactionicons/undo.png"), "Undo", this);
	UndoAction->setShortcut(QKeySequence::Undo);
	UndoAction->setToolTip("Erase/Write what you just did rite/delete.");
	connect(UndoAction, SIGNAL(triggered(bool)), this, SLOT(Undo_routine()));

	RedoAction = new QAction(QIcon("images/menuactionicons/redo.png"), "Redo", this);
	RedoAction->setShortcut(QKeySequence::Redo);
	RedoAction->setToolTip("Erase/Write what you just did rite/delete.");
	connect(RedoAction, SIGNAL(triggered(bool)), this, SLOT(Redo_routine()));

	CopyAction = new QAction(QIcon("images/menuactionicons/copy.png"),"Copy", this);
	CopyAction->setShortcut(QKeySequence::Copy);
	CopyAction->setToolTip("Copy");
	connect(CopyAction, SIGNAL(triggered(bool)), text, SLOT(copy()));

	NewAction = new QAction(QIcon("images/menuactionicons/new.png"), "New File", this);
	NewAction->setShortcut(QKeySequence::New);
	NewAction->setToolTip("Create New File");
	connect(NewAction, SIGNAL(triggered()), this, SLOT(New_routine()));
}

void MainWindow::createDockWidget(){
	Features_DockWidget = new QDockWidget("Features", this);
	Features_DockWidget->setFloating(false);
	Features_DockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
	Features_DockWidget->toggleViewAction()->setText("Features");
	Features_DockWidget->toggleViewAction()->setIcon(QIcon("images/menuactionicons/hidedock.png"));
	Features_DockWidget->toggleViewAction()->setToolTip("<i>Hide Features</i>");
	docklist = new QListView();
	Features_DockWidget->setWidget(docklist);
	new FeaturesHandler(docklist,text, this);
	this->addDockWidget(Qt::LeftDockWidgetArea, Features_DockWidget);
}

void MainWindow::createToolBar(){
	MainWindow_ToolBar = new QToolBar("File", this);
	MainWindow_ToolBar->addAction(NewAction);
	MainWindow_ToolBar->addAction(SaveAsAction);
	MainWindow_ToolBar->addAction(LoadAction);
	MainWindow_ToolBar->addSeparator();
	MainWindow_ToolBar->addAction(UndoAction);
	MainWindow_ToolBar->addAction(RedoAction);
	MainWindow_ToolBar->addAction(CopyAction);
	MainWindow_ToolBar->addSeparator();
	MainWindow_ToolBar->addAction(ExitAction);
	MainWindow_ToolBar->setMovable(true);
	MainWindow_ToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::RightToolBarArea);
	MainWindow_ToolBar->toggleViewAction()->setIcon(QIcon("images/menuactionicons/closetoolbar.png"));
	MainWindow_ToolBar->toggleViewAction()->setText("Tool Bar");
	MainWindow_ToolBar->toggleViewAction()->setToolTip("Close toolbar");
	MainWindow_ToolBar->addAction(MainWindow_ToolBar->toggleViewAction());
	MainWindow_ToolBar->addAction(Features_DockWidget->toggleViewAction());
//	MainWindow_ToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	this->addToolBar(MainWindow_ToolBar);
}


void MainWindow::createMenu(){
	MainWindow_QMenu = this->menuBar()->addMenu("File");
	MainWindow_QMenu->addAction(NewAction);
	MainWindow_QMenu->addAction(SaveAsAction);
	MainWindow_QMenu->addAction(LoadAction);	
	MainWindow_QMenu->addSeparator();
	MainWindow_QMenu->addAction(ExitAction);
	Edit_Menu = this->menuBar()->addMenu("Edit");
	Edit_Menu->addAction(UndoAction);
	Edit_Menu->addAction(RedoAction);
	Edit_Menu->addSeparator();
	Edit_Menu->addAction(CopyAction);
	View_Menu = this->menuBar()->addMenu("View");
	View_Menu->addAction(MainWindow_ToolBar->toggleViewAction());
	View_Menu->addAction(Features_DockWidget->toggleViewAction());
}

void MainWindow::writeSettings(){
	QSettings settings(this);
	settings.setPath(QSettings::NativeFormat, QSettings::SystemScope, "$HOME/.config");
	settings.setValue("MainWindow/Size", this->size());
	settings.setValue("MainWindow/Properties", this->saveState());
}

void MainWindow::readSettings(){
	QSettings settings(this);
	settings.setPath(QSettings::NativeFormat, QSettings::SystemScope, "$HOME/.config");
	this->resize(settings.value("MainWindow/Size", this->sizeHint()).toSize());
	this->restoreState(settings.value("MainWindow/Properties").toByteArray());
}