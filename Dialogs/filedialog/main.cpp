#include <QApplication>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[]){
	
	QApplication a(argc, argv);
	QWidget e;
	QFileDialog fdialog(&e);
/*	fdialog.setOptions(QFileDialog::ShowDirsOnly);
	QString string = fdialog.getOpenFileName(&e, "Pick file test", "/home/student/reall/images",
		QObject::tr("Images (*.jpg *.png);;Text (*.txt *.doc *docx)"));//remember to use 2 ;
	if (string.isNull()){
		qDebug() << "No File Selected";
	}
	else{
		qDebug() << "File selected : " + string;
	}

	QMessageBox::information(&e, "Title", "Now you will be able to  \n choose multiple files");

	QStringList files = fdialog.getOpenFileNames(&e, "Pick files", "/home/student/reall/images",
		QObject::tr("Images (*.jpg *.png);;Text (*.txt *.doc *docx)"));//remember to use 2 ;
	foreach(QString file, files){
		QFile f(file);
		qDebug() << f.fileName();
	}

	QMessageBox::information(&e, "Title", "Now you will be able to \n only choose an existing directory");

	qDebug() << fdialog.getExistingDirectory(&e, "Pick directory", QDir::homePath());

	QMessageBox::information(&e, "Title", "Now you will be able to \n save a file");

	qDebug() << fdialog.getSaveFileName(&e, "Save File As..", QDir::currentPath());

	QStringList languages;
	bool ok = false;
	languages << "English" << "German" << "French" << "Spanish";
	QString language = QInputDialog::getItem(&e, QObject::tr("Select Language"),
	QObject::tr("Please select your language"), languages, 0, true, &ok);

	if (ok) {qDebug() << ok;}
	else if (!ok){qDebug() << false;}

	QString resource = QObject::tr("this");
	qDebug() << QInputDialog::getText(&e,QObject::tr("Please Enter Password"),
		QObject::tr("Please enter a password for %1").arg(resource),
		QLineEdit::Password, QString(), 0);
*/

	QFont font("Abyssinica SIL", 30);
	bool ok;
	QFont newFont = QFontDialog::getFont(&ok, font, &e, "Select your font");
	if(newFont == font){
		qDebug() << font.toString();
	}
	else{
		qDebug() << newFont.toString();
	}
	return a.exec();
}	//88879202 dr.gustavo sequeira