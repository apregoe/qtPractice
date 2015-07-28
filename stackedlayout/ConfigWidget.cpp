#include "ConfigWidget.h"

ConfigWidget::ConfigWidget(){
	QHBoxLayout* lay = new QHBoxLayout(this);

	widgetList = new QListWidget;
	widgetStack = new QStackedWidget;

	lay->addWidget(widgetList);
	lay->addWidget(widgetStack);

	widgetList->setMaximumWidth(180);

	setLayout(lay);

	connect(widgetList, SIGNAL(currentRowChanged(int)), widgetStack, SLOT(setCurrentIndex(int)));
}

void ConfigWidget::addPage(const QString& title, const QIcon& icon, QWidget* page){
	QListWidgetItem* item = new QListWidgetItem;
	item->setText(title);
	item->setIcon(icon);
	widgetList->addItem(item);
	widgetStack->addWidget(page);
}