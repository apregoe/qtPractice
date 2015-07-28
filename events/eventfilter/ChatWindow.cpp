#include "ChatWindow.h"

ChatWindow::ChatWindow(QWidget* parent) : QWidget(parent){
	setWindowTitle(tr("Chat :)"));
	QVBoxLayout* vlay = new QVBoxLayout(this);
	QSplitter* splitter = new QSplitter(Qt::Vertical, this);
	vlay->addWidget(splitter);
	conversationView = new QTextBrowser;
	chatEdit = new QTextEdit;
	splitter->addWidget(conversationView);
	splitter->addWidget(chatEdit);
	chatEdit->installEventFilter(this);
	setTabOrder(chatEdit, conversationView);
	setLayout(vlay);
}

bool ChatWindow::eventFilter(QObject* watched, QEvent* e){
	if((watched == chatEdit) && (e->type() == QEvent::KeyPress)){
		QKeyEvent* ke = (QKeyEvent*)e;
		if((ke->key() == Qt::Key_Enter) ||
			(ke->key() == Qt::Key_Return)){
			submitChat();
			return true;
		}
	}
	return QWidget::eventFilter(watched, e);
}

void ChatWindow::submitChat(){
	conversationView->append(chatEdit->toPlainText());
	chatEdit->setText("");
}