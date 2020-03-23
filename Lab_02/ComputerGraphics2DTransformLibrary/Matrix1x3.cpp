#include "pch.h"
#include "Matrix1x3.h"

Matrix1x3::Matrix1x3() : Matrix(1, 3)
{

}

void Matrix1x3::SetMatrix(Vector2D& vector)
{
	data[0][0] = vector.x;
	data[0][1] = vector.y;
	data[0][2] = 1;
}

Vector2D Matrix1x3::GetVector()
{
	Vector2D vector;
	vector.x = data[0][0] / data[0][2];
	vector.y = data[0][1] / data[0][2];
	return vector;
}

Vector2D Matrix1x3::GetProductVector(Matrix1x3& point, Matrix3x3& MatrixTransform)
{
	this->GetProduct(point, MatrixTransform);
	return this->GetVector();
}