#include "Drag2ClipWidget.h"

Drag2ClipWidget::Drag2ClipWidget(QWidget* parent) : QLabel(parent) {
	QDesktopWidget desk;
	this->resize(desk.height()*0.4, desk.width()*0.4);
	this->setWordWrap(true);
	this->setText(tr("<center> Drag from here to retrieve the text currently <br/>" 
		"located in the clipboard or fill the clipboard by dragging text <br/>"
		"from abitrary places and dropping it here. </center>"));
	this->setAcceptDrops(true);
}

void Drag2ClipWidget::mousePressEvent(QMouseEvent* event){
	if(!event){return;}

	if(event->button() == Qt::LeftButton){
		const QMimeData* tempdata = QApplication::clipboard()->mimeData();
		if(!tempdata){return;}
		QDrag* drag = new QDrag(this);
		drag->setMimeData(cloneMimeData(tempdata));
		drag->start();
	}
}
void Drag2ClipWidget::dragEnterEvent(QDragEnterEvent* event){
		event->acceptProposedAction();
}
void Drag2ClipWidget::dropEvent(QDropEvent* event){
	if(event && event->mimeData()){
		QApplication::clipboard()->setMimeData(cloneMimeData(event->mimeData()));
	}

}

//basically returns a QMimedata that is not constant type
QMimeData* Drag2ClipWidget::cloneMimeData(const QMimeData* mimedata){
	if(!mimedata){return NULL;}

	QMimeData* newData = new QMimeData;
	foreach(QString format, mimedata->formats()){
		newData->setData(format, mimedata->data(format));
	}

	return newData;
}