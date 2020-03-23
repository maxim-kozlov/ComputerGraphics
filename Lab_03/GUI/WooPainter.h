#pragma once
#include "IPainter.h"
#include "IDeterminateTime.h"
#include "IDeterminateRungs.h"

class WooPainter: public IPainter, public IDeterminateTime, public IDeterminateRungs
{
public:
	WooPainter(float Imax = 1);
	bool DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color);

	void TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by);

	int GetCountStep(float ax, float ay, float bx, float by);
private:
	float Imax;
};

