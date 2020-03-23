#pragma once
#include "Matrix3x3.h"

class CoordinateSystem
{
public:
	CoordinateSystem(float angle, float x0, float y0, float kx, float ky);

	void GetMatrixTransform(Matrix3x3& matrix);


	float angle; // ��� x' �������� �� ���� angel ������������ ��� x
	
	float x0; // ������ ��������� � ����� x0, y0
	float y0;

	float kx; // ����� ����� ��. �������� �� ��� � ����� ������� ��������� � ����� (��������������� �� x)
	float ky; // ����� ����� ��. �������� �� ��� y ����� ������� ��������� � ����� (��������������� �� y)
};

