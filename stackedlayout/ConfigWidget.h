#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>

class ConfigWidget : public QWidget{
Q_OBJECT
public:
	ConfigWidget();
	void addPage(const QString& title, const QIcon& icon, QWidget* page);
private:
	QStackedWidget* widgetStack;
	QListWidget* widgetList;
};

#endif