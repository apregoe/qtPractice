#include "DragLabel.h"

DragLabel::DragLabel(const char* pPath, QWidget* parent) 
	: QLabel(parent), picPath(pPath){
		this->setPixmap(QPixmap(picPath));
}

QMimeData* DragLabel::prepareImageDrag(const QString path){
	QImage pic(path);
	QMimeData* mimedata = new QMimeData;
	mimedata->setImageData(pic);
	QList<QUrl> urls;//QUrl resolves problems with relative paths
	QUrl imageUrl(path);
	urls.append(imageUrl);
	mimedata->setUrls(urls);
	mimedata->setText(imageUrl.path());
	return mimedata;
}

void DragLabel::mousePressEvent(QMouseEvent* event){
	if(event->button() == Qt::LeftButton){
		QMimeData* mimedata =  prepareImageDrag(picPath);
		QDrag* drag = new QDrag(this);
		drag->setMimeData(mimedata);
		if(pixmap()){
			drag->setPixmap(pixmap()->scaled(150,150, Qt::KeepAspectRatio));
		}
		drag->start();
	}
}