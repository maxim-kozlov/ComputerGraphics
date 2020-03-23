#pragma once
#include "IPainter.h"
#include "IDeterminateTime.h"

class QtPainter : public IPainter, public IDeterminateTime
{
public:
	bool DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color);

	void TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by);
};