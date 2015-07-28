#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QtCore>
#include <QtGui>

class ChatWindow : public QWidget{
Q_OBJECT
public:
	ChatWindow(QWidget* parent = 0);
	bool eventFilter(QObject* watched, QEvent* e);
	void submitChat();
private:
	QTextBrowser* conversationView;
	QTextEdit* chatEdit;
	
};

#endif