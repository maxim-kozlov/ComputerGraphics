#pragma once
#include "pch.h"

// проверки на корретность не производятся
class MATRIX_API Matrix
{
public:
	Matrix(int n, int m);
	~Matrix();

	static Matrix IdentityMatrix(int n);

	// сделать единичной
	void IdentityMatrix();

	float GetValue(int i, int j);
	void SetValue(int i, int j, float value);
	
	void GetProduct(Matrix& A, Matrix& B);

private:
	int n;
	int m;
	float** data;
};