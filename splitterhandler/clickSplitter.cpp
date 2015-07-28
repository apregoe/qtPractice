#include "clickSplitter.h"

clickSplitterHandle::clickSplitterHandle(Qt::Orientation orientation, QApplication* app_,
	QSplitter* parent) : QSplitterHandle(orientation, parent), app(app_){
	lastUncollapsedSize = 0;
}

void clickSplitterHandle::mouseDoubleClickEvent(QMouseEvent* event){
	QSplitter* splitter = this->splitter();
	Qt::Orientation orientation = splitter->orientation();
	int pos = splitter->indexOf(this);

	QWidget* widget = splitter->widget(pos);

	if(lastUncollapsedSize == 0){
		if(orientation == Qt::Horizontal){
			lastUncollapsedSize = widget->sizeHint().width();
		}
		else{
			lastUncollapsedSize = widget->sizeHint().height();
		}
	}

	int currentSize = 0;
	if(app->isRightToLeft()){
		currentSize = splitter->sizes().value(pos);
	}
	else{
		currentSize = splitter->sizes().value(pos-1);
	}

	if(currentSize == 0){
		moveSplitter(lastUncollapsedSize);
	}
	else{
		lastUncollapsedSize = currentSize;
		moveSplitter(0);
	}


}