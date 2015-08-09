#include <QApplication>
#include <QtGui>
#include <QtCore>

QImage rotateRgb(const QImage & in){
	QImage out(in.size(), in.format());
	for(int line = 0; line < in.height(); ++line){
		const QRgb* inPixels = reinterpret_cast<const QRgb*>(in.scanLine(line));
		QRgb* outPixels = reinterpret_cast<QRgb*>(out.scanLine(line));
		for(int position = 0; position < in.width(); ++position){
			int red = qRed(inPixels[position]);
			int green = qGreen(inPixels[position]);
			int blue = qBlue(inPixels[position]);
			int alpha = qAlpha(inPixels[position]);
			outPixels[position] = qRgba(blue,red,green,alpha);
		}
	}
	return out;
}

int main(int argc, char *argv[]){
	QApplication a(argc,argv);
	QImage img("image.jpg");
	QLabel rgb, brg, grb;
	
	//
	img = rotateRgb(img);
	brg.setPixmap(QPixmap::fromImage(img));
	brg.show();
	//
	img = rotateRgb(img);
	grb.setPixmap(QPixmap::fromImage(img));
	grb.show();
	//
	img = rotateRgb(img);
	rgb.setPixmap(QPixmap::fromImage(img));
	rgb.show();

	return a.exec();
}