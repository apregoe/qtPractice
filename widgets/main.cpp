#include <QApplication>
#include "Window.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Window w;
	a.setQuitOnLastWindowClosed(1);
	w.setAttribute(Qt::WA_QuitOnClose,1);
	w.show();

	return a.exec();
}