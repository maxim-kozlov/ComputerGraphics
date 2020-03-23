#pragma once
#include <qimage.h>
#include <qstring.h>

class IPainter
{
public:
	virtual void DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color) = 0;
	virtual void DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color) = 0;
	virtual QString GetName() = 0;
};