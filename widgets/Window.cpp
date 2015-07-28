#include "Window.h"

Window::Window(){
//	QDesktopWidget desktop;
//	this->resize(desktop.width()*0.7, desktop.height()*0.7);



/*****Example 1*******/
/*
	QPushButton* button = new QPushButton("click", this);
	//button->setGeometry(590, 570, 100,20);
	//button->setSizePolicy(QSizePolicy::Preferred);

	QTextEdit* text = new QTextEdit(this);
	//text->setGeometry(10,10,680,560);


	QVBoxLayout* vlayout = new QVBoxLayout(this);
	//vertical layout
	hlayout->addLayout(vlayout);
	vlayout->addWidget(text);
	vlayout->addWidget(button, 0, Qt::AlignRight);
*/

/*****Example 2*******/
	//horizontal layout, stretches
	/*QHBoxLayout* hlayout = new QHBoxLayout(this);
	QTextEdit* righttexts = 0;
	for(int i = 1; i <= 5; ++i){
		righttexts = new QTextEdit(this);
		hlayout->addWidget(righttexts, i);
	}
	this->setLayout(hlayout); */


/*****Example 3*******/
	/*QGridLayout* glayout = new QGridLayout(this);
	QTextEdit* text = new  QTextEdit(this);
	glayout->addWidget(text, 0, 0, 3,5);
	QPushButton* button = new QPushButton("click",this);
	glayout->addWidget(button,3,4, Qt::AlignRight);
	this->setLayout(glayout);*/

/***Example 4****/
	//NestedLayouts
	/*QHBoxLayout *mainLayout = new QHBoxLayout(this);
		QTextEdit *txtEdit = new QTextEdit(this);
		QVBoxLayout *vlayout = new QVBoxLayout;
			QPushButton *cancelBtn = new QPushButton(QObject::tr("&Cancel"), this);
			QPushButton *okBtn = new QPushButton(QObject::tr("&OK"), this);
			QPushButton *defaultBtn = new QPushButton(QObject::tr("&Default"), this);
	
	mainLayout->addWidget(txtEdit);
	vlayout->addWidget(defaultBtn);
	vlayout->addWidget(cancelBtn);
	vlayout->addWidget(okBtn);
	vlayout->addStretch();
	mainLayout->addLayout(vlayout);
	this->setLayout(mainLayout);*/

/***Example 5****///Change inheritance to : public QSplitter
		//QSplitter
	/*QTextEdit* text = NULL;

	for(int stretch = 0; stretch < 3; ++stretch){
		text = new QTextEdit(this);
		addWidget(text);
	//	setStretchFactor(indexOf(text), stretch);
	}

	QList<int> sizes;
	sizes << 50 << 90 <<200;
	this->setSizes(sizes);
	setOpaqueResize(false);*/
}