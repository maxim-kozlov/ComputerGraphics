#pragma once

#include "pch.h"
#include "Matrix.h"


class CG_2D_TRANSFORM_LIBRARY_API Matrix3x3 : public Matrix
{
public:
	Matrix3x3();

	// матрица переноса
	void SetMove(float dx, float dy);

	// матрица масштабирования
	void SetScale(float kx, float ky);

	// матрица поворота
	void SetRotate(float angle);
};