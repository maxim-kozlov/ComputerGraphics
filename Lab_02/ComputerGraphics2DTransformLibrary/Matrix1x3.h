#pragma once

#include "pch.h"
#include "Matrix.h"
#include "Vector2D.h"
#include "Matrix3x3.h"

class CG_2D_TRANSFORM_LIBRARY_API Matrix1x3 : public Matrix
{
public:
	Matrix1x3();

	// задать матрицу по вектору
	void SetMatrix(Vector2D& vector);

	// получить по матрице вектор
	Vector2D GetVector();

	// return point * MatrixTransform
	Vector2D GetProductVector(Matrix1x3& point, Matrix3x3& MatrixTransform);
};