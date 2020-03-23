#include "pch.h"
#include "Matrix.h"

Matrix::Matrix(int n, int m)
{
	this->n = n;
	this->m = m;
	data = new float*[n];
	for (size_t i = 0; i < n; i++)
		data[i] = new float[m];
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < n; i++)
		delete[] data[i];
	delete[] data;
}

Matrix Matrix::IdentityMatrix(int n)
{
	Matrix identity(n, n);
	identity.IdentityMatrix();
	return identity;
}

void Matrix::IdentityMatrix()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
			data[i][j] = i == j;
	}
}

// «аписать в исходную матрицу результат A*B
void Matrix::GetProduct(Matrix& A, Matrix& B)
{
	for (size_t i = 0; i < A.n; i++)
	{
		for (size_t j = 0; j < B.m; j++)
		{
			data[i][j] = 0;
			for (size_t k = 0; k < m; k++)
				data[i][j] += A.data[i][k] * B.data[k][j];
		}
	}
}

// скопировать исходную матрицу в matrix
Matrix& Matrix::CopyTo(Matrix& matrix)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
			matrix.data[i][j] = data[i][j];
	}
	return matrix;
}