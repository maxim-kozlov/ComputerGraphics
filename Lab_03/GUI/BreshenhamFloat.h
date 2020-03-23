#pragma once
#include "IPainter.h"
#include "IDeterminateTime.h"
#include "IDeterminateRungs.h"

class BreshenhamFloat : public IPainter, public IDeterminateTime, public IDeterminateRungs
{
public:
	bool DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color);

	void TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by);

	int GetCountStep(float ax, float ay, float bx, float by);
};

