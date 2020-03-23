#include "QtPainter.h"
#include <qpainter.h>

void QtPainter::DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color)
{
	DrawEllipse(canvas, x, y, r, r, color);
}

void QtPainter::DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color)
{
	QPainter painter(&canvas);
	painter.setPen(QPen(color));
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawEllipse(x - a, y - b, 2 * a, 2 * b);
	painter.end();
}