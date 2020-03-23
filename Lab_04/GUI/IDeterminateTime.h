#pragma once

#include <qimage.h>

class IDeterminateTime
{
public:
	// для проверки скорости работы алгоритма
	virtual void TestDrawCicrle(QImage& canvas, int x, int y, int r) = 0;
	virtual void TestDrawEllipse(QImage& canvas, int x, int y, int a, int b) = 0;
	virtual QString GetName() = 0;
};