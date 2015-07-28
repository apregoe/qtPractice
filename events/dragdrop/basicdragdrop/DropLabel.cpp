#include "DropLabel.h"

DropLabel::DropLabel(QWidget* parent) : QLabel(parent){
	this->setAcceptDrops(true);
}

void DropLabel::dragEnterEvent(QDragEnterEvent* event){
	if(event && event->mimeData()){
		const QMimeData* mdata= event->mimeData();
		if(mdata->hasImage() || mdata->hasText() || mdata->hasUrls()){
			event->acceptProposedAction();
		}
	}
}

void DropLabel::dropEvent(QDropEvent* event){
	QPixmap pix;
	if(event && event->mimeData()){
		const QMimeData* mdata = event->mimeData();
		if(mdata->hasImage()){
			pix = qvariant_cast<QPixmap>(mdata->imageData());
		}
		else if(mdata->hasUrls()){
			foreach(QUrl u, mdata->urls()){
				QFileInfo info(u.toLocalFile());
				if(info.exists() && info.isFile()){
					pix = QPixmap(u.toLocalFile());
				}
				if(pixmap() && !pixmap()->isNull()){
					break;
				}
			}
		}
		else if(mdata->hasText()){
			QUrl u(mdata->text());
			QFileInfo info(u.toLocalFile());
			if(info.exists() && info.isFile()){
				pix = QPixmap(u.toLocalFile());
			}
		}
	}
	if(!pix.isNull()){
		setPixmap(pix);
		resize(pix.size());
	}
}




