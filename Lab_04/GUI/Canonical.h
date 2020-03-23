#pragma once
#include "IPainter.h"
#include "IDeterminateTime.h"

class Canonical : public IPainter, public IDeterminateTime
{
public:
	void DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color);
	void DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color);

	void TestDrawCicrle(QImage& canvas, int x, int y, int r);
	void TestDrawEllipse(QImage& canvas, int x, int y, int a, int b);

	QString GetName() { return QString("Canonical"); }
};

