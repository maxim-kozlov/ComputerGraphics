#pragma once
#include <qimage.h>

class IDeterminateRungs
{
public:
	// для проверки скорости работы алгоритма
	virtual int GetCountStep(float ax, float ay, float bx, float by) = 0;
};