#pragma once
#include <qimage.h>

class IDeterminateTime
{
public:
	// ��� �������� �������� ������ ���������
	virtual void TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by) = 0;
};