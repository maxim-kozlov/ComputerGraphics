#include "pch.h"
#include "Matrix3x3.h"
#include <cmath>

Matrix3x3::Matrix3x3() : Matrix(3, 3)
{
	
}

// матрица переноса
void Matrix3x3::SetMove(float dx, float dy)
{
	this->IdentityMatrix();
	data[2][0] = dx;
	data[2][1] = dy;
}

// матрица масштабирования
void Matrix3x3::SetScale(float kx, float ky)
{
	this->IdentityMatrix();
	data[0][0] = kx;
	data[1][1] = ky;
}

// матрица поворота
void Matrix3x3::SetRotate(float angle)
{
	this->IdentityMatrix();
	float sinx = sinf(angle);
	float cosx = cosf(angle);
	data[0][0] =  cosx; data[0][1] = sinx;
	data[1][0] = -sinx; data[1][1] = cosx;
}