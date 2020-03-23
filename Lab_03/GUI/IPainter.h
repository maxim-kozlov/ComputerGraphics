#pragma once
#include <qimage.h>

class IPainter
{
public:
	// ���������� �����
	// ������� ���� �� ��������� �������� �����
	virtual bool DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color) = 0;
};

