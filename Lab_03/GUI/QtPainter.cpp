#include "QtPainter.h"
#include <qpainter.h>

bool QtPainter::DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color)
{
	int xn = roundf(ax);
	int yn = roundf(ay);
	int xk = roundf(bx);
	int yk = roundf(by);

	QRgb background = ~color;
	canvas.setPixel(xk, yk, background);

	QPainter painter(&canvas);

	painter.setPen(QPen(color));
	// painter.setRenderHint(QPainter::Antialiasing);
	painter.drawLine(xn, yn, xk, yk);
	painter.end();

	QRgb ColorEndPoint = canvas.pixel(xk, yk);
	return ColorEndPoint != background;
}

void QtPainter::TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by)
{
	int xn = roundf(ax);
	int yn = roundf(ay);
	int xk = roundf(bx);
	int yk = roundf(by);

	QRgb background = canvas.pixel(xk, yk);
	QPainter painter(&canvas);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawLine(xn, yn, xk, yk);
	painter.end();
}