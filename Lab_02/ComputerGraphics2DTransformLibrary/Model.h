#pragma once
#include "pch.h"
#include <vector>
#include "Ellipse_t.h"
#include "Polygon_t.h"

#include "Memento.h"

class CG_2D_TRANSFORM_LIBRARY_API Model
{
public:
	Model();

	std::vector<Polygon_t> polygons;
	
	Matrix3x3& GetMatrixModel();

	// ��������� ������ �� angle � ��������
	// ������������ ����� (xc, yc)
	void Rotate(float angleDegree, float xc = 0, float yc = 0);

	// ���������� �������������� (kx, ky)
	// ������������ ����� (xm, ym)
	void Scale(float kx, float ky, float xm = 0, float ym = 0);

	// ���������� ������� �� (dx, dy)
	void Move(float dx, float dy);

	// �������� ��������
	// return - ��������� �� ��������� ��������
	bool Cancel();
private:
	// ��������� �������
	Matrix3x3 Buffer;
	Matrix3x3 BufferTransform;

	// ������� ������
	Matrix3x3 MatrixModel;

	// ��������� ���������
	Memento memento;
};

