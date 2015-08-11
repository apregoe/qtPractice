#ifndef FEATURESHANDLER_H
#define FEATURESHANDLER_H

#include <QListView>
#include <QStringList>
#include <QDockWidget>
#include <QModelIndex>
#include <QString>
#include <QObject>
#include <QTextEdit>
#include <QStringListModel>
#include <QDebug>

class FeaturesHandler : public QObject{
Q_OBJECT

public:
	FeaturesHandler(QListView*, QTextEdit*, QObject*);

private slots:
	void insertText(const QModelIndex &);

private:
	QListView* mView;
	QTextEdit* mTextEdit;
	QStringListModel* mModel;
};

#endif