#pragma once
#include <qimage.h>

class IDeterminateRungs
{
public:
	// ��� �������� �������� ������ ���������
	virtual int GetCountStep(float ax, float ay, float bx, float by) = 0;
};