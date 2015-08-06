#ifndef PIEWIDGET_H
#define PIEWIDGET_H

#include <QtGui>
#include <QtCore>

class PieWidget : public QWidget{
Q_OBJECT
public:
	PieWidget(QWidget* parent = 0);
	QSize sizeHint() const;
	QSize minimumSizeHint() const;
	void addEntry(const QString& key, int val);
protected:
	void paintEvent(QPaintEvent* event);
private:
	QHash<QString, int> values;

};

#endif // PIEWIDGET_H

