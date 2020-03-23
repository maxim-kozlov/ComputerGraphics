#pragma once
#include "pch.h"

// проверки на корретность не производятся
class MATRIX_API Matrix
{
public:
	Matrix(int n, int m);
	~Matrix();

	// получить единичную матрицу
	static Matrix IdentityMatrix(int n);

	// сделать единичной
	void IdentityMatrix();
	
	// записать в исходную матрицу результат A*B
	void GetProduct(Matrix& A, Matrix& B);

	// скопировать в матрицу
	Matrix& CopyTo(Matrix& matrix);

protected:
	float** data;
	int n;
	int m;
};