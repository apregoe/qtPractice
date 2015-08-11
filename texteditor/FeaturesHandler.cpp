#include "FeaturesHandler.h"

FeaturesHandler::FeaturesHandler(QListView* mListView, QTextEdit* mtext,
	QObject* parent_) : mView(mListView), mTextEdit(mtext),  QObject(parent_){

	mModel = new QStringListModel(this);
	QStringList features;
	features << "<html>"<<"</html>"<<"<body>"<<"</body>";
	mModel->setStringList(features); 
	mView->setModel(mModel);
	connect(mView, SIGNAL(clicked(const QModelIndex &)), this,
		SLOT(insertText(const QModelIndex &)));
}
 
void FeaturesHandler::insertText(const QModelIndex& index){
	QString temptext = mModel->data(index, Qt::DisplayRole).toString();
	QTextCursor cursor = mTextEdit->textCursor();
	cursor.insertText(temptext);
	mTextEdit->setTextCursor(cursor); 
}
 