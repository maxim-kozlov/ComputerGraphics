#pragma once

#include "pch.h"
#include "Matrix.h"


class CG_2D_TRANSFORM_LIBRARY_API Matrix3x3 : public Matrix
{
public:
	Matrix3x3();

	// ������� ��������
	void SetMove(float dx, float dy);

	// ������� ���������������
	void SetScale(float kx, float ky);

	// ������� ��������
	void SetRotate(float angle);
};