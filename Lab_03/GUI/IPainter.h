#pragma once
#include <qimage.h>

class IPainter
{
public:
	// нарисовать линию
	// вернуть была ли высвечена конечная точка
	virtual bool DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color) = 0;
};

