#pragma once
#include "IPainter.h"

class QtPainter : public IPainter
{
public:
	void DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color);
	void DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color);
	QString GetName() { return QString("Qt"); }
};