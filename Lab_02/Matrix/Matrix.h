#pragma once
#include "pch.h"

// �������� �� ����������� �� ������������
class MATRIX_API Matrix
{
public:
	Matrix(int n, int m);
	~Matrix();

	// �������� ��������� �������
	static Matrix IdentityMatrix(int n);

	// ������� ���������
	void IdentityMatrix();
	
	// �������� � �������� ������� ��������� A*B
	void GetProduct(Matrix& A, Matrix& B);

	// ����������� � �������
	Matrix& CopyTo(Matrix& matrix);

protected:
	float** data;
	int n;
	int m;
};