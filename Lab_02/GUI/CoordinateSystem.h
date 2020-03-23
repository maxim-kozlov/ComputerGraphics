#pragma once
#include "Matrix3x3.h"

class CoordinateSystem
{
public:
	CoordinateSystem(float angle, float x0, float y0, float kx, float ky);

	void GetMatrixTransform(Matrix3x3& matrix);


	float angle; // ось x' повёрнута на угол angel относительно оси x
	
	float x0; // начало координат в точке x0, y0
	float y0;

	float kx; // связь между ед. отрезком по оси х новой системы координат к новой (масштабирование по x)
	float ky; // связь между ед. отрезком по оси y новой системы координат к новой (масштабирование по y)
};

