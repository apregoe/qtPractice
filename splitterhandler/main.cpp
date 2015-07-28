#include <QApplication>
#include "clickSplitter.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setLayoutDirection(Qt::RightToLeft);
	clickSplitter* s = new clickSplitter(Qt::Horizontal, &a);
	s->addWidget(new QTextEdit);
	s->addWidget(new QLabel("label"));
	s->show();
	return a.exec();
}