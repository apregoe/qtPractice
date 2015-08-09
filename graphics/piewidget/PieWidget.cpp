#include "PieWidget.h"

PieWidget::PieWidget(QWidget* parent) : QWidget(parent){ }

void PieWidget::addEntry(const QString& key, int val){
	values.insert(key, val);
}

void PieWidget::paintEvent(QPaintEvent* event){
	QWidget::paintEvent(event);
	//calculating total
	QHash<QString, int>::const_iterator it;
	int total = 0;
	for (it = values.begin(); it != values.end(); ++it){
		total += it.value();
	}

	//prepare painter
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing, true);

	//prepare color
	QStringList colorNames = QColor::colorNames();
	int colorPosition = 13;

	int height = rect().height();
	QRect pieRect(0,0,height,height);
	pieRect.adjust(10,10,-10,-10);

	//dedicate right hand to legend
	QRect legendRect = rect();
	legendRect.setLeft(pieRect.width());
	legendRect.adjust(10,10,-10,-10);

	int lastAngleOffSet = 0;
	int currentPos = 0;

	//create an entry for every piece of the pie
	for(it = values.begin(); it != values.end(); ++it){
		int value = it.value();
		QString text = it.key();

		int angle = (int)(16*360*(value/(double)total));
		QColor col(colorNames.at(colorPosition%colorNames.count()));
		colorPosition++;

		//gradient for the pie pieces
		QRadialGradient radGradient(pieRect.center(), pieRect.width()/2, pieRect.topLeft());
		radGradient.setColorAt(0, Qt::white);
		radGradient.setColorAt(1,col);
		p.setBrush(radGradient);
		QPen pen = p.pen();
		p.setPen(Qt::NoPen);

		p.drawPie(pieRect, lastAngleOffSet, angle);
		lastAngleOffSet += angle;
	
		//calculate the squares for the legend
		int fh = fontMetrics().height();
		QRect legendEntryRect(0,fh*2*currentPos,fh,fh);
		currentPos++;
		legendEntryRect.translate(legendRect.topLeft());

		//define gradient for the legend squares
		QLinearGradient linearGradient(legendEntryRect.topLeft(), legendEntryRect.bottomRight());
		linearGradient.setColorAt(0,col);
		linearGradient.setColorAt(1,Qt::white);
		p.setBrush(linearGradient);
		p.drawRect(legendEntryRect);

		//Inserting legend text, behind squares
		QPoint textStart(legendEntryRect.topRight());
		textStart += QPoint(fontMetrics().width('K'),0);
		QPoint textEnd(legendRect.right(), legendEntryRect.bottom());
		QRect textEntryRect(textStart, textEnd);
		p.setPen(pen);
		p.drawText(textEntryRect, Qt::AlignVCenter, text);
	}
}

QSize PieWidget::minimumSizeHint() const{
	int fh = fontMetrics().height();
	int height = fh*2*values.count();
	int longest = 0;
	QHash<QString, int>::const_iterator it;
	QFontMetrics fm = fontMetrics();
	//I could use a max heap instead of looping in the hash
	for(it = values.begin(); it != values.end(); ++it){
		longest = qMax(fm.width(it.key()), longest);
	}
	int width = height + longest + fontMetrics().width("xx") + (2*10);
	QSize minSize(width, height);
	return minSize;
}

QSize PieWidget::sizeHint() const{
	return minimumSizeHint();
}





















