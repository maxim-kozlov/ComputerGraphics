#pragma once
#include <qimage.h>

class IDeterminateTime
{
public:
	// для проверки скорости работы алгоритма
	virtual void TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by) = 0;
};