#include <QApplication>
#include <QMessageBox>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[])
{
	QApplication a(argc,argv);
	a.setApplicationName("test");
	QWidget widget;

	//0 is for default button (Enter), 1 is for exit (escape) button
	qDebug() << QMessageBox::question(&widget, "Question", "Banana or potatoe?", 
		"Banana", "Potatoe", "kjbkb", 0, 1);

	QMessageBox::aboutQt(&widget, "ofwneonwr");


	//QErrorMessage Example
	QErrorMessage* m = new QErrorMessage(&widget);
	m->showMessage("Do you want to show <br/>this message Again?");
	m->showMessage("Do you want to show <br/>this message Again?");
	m->showMessage("2nd message");

	return a.exec();
}