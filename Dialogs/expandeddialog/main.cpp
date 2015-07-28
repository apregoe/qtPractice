#include <QApplication>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[]) {
	QApplication a(argc,argv);
	QDialog dlg;
	dlg.setOrientation(Qt::Vertical);
	QPushButton *btn = new QPushButton(QObject::tr("Expand/Collapse"),
	&dlg);
	btn->setCheckable(true);
	QVBoxLayout *lay = new QVBoxLayout(&dlg); lay->addWidget(btn);
	QLabel *ext = new QLabel(QObject::tr("<center><b>Extension</b></center>")); dlg.setExtension(ext);
	QObject::connect(btn, SIGNAL(toggled(bool)),
	                  &dlg, SLOT(showExtension(bool)));

	dlg.exec();
	return a.exec();
}