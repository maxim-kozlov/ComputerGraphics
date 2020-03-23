#include "pch.h"
#include "HelperMath.h"
#include "CombinatoricsLibrary.h"
#include <cmath>
#include <limits>

// проверить является ли треугольник вырожденным
bool isDegenerateTriangle(Vector2D& A, Vector2D& B, Vector2D& C)
{
	return fabs((B - A).GetVectorProduct(C - A)) < 1e-9;
}

// получить вектор CM, где M середина стороны AB 
Vector2D GetVectorMediana(Vector2D & A, Vector2D & B, Vector2D & C)
{
	return (A + B) / 2 - C;
}

// получить квадрат минимальной длины медианы треугольника
float GetMinSquareLenghtMedian(Vector2D& A, Vector2D& B, Vector2D& C)
{
	float CM = GetVectorMediana(A, B, C).GetSquareLenght(); // CM
	float AM = GetVectorMediana(B, C, A).GetSquareLenght(); // AM
	float BM = GetVectorMediana(C, A, B).GetSquareLenght(); // BM

	return GetMinThreeValue(CM, AM, BM);
}

// получить точку M, соотвествующей минимальной медиане треугольника MP (где P \in {a, b, c})
void GetMinMedian(Vector2D& A, Vector2D& B, Vector2D& C, Vector2D& Mmin, Vector2D& Pstart)
{
	Vector2D M;
	M = GetVectorMediana(A, B, C);
	float minSquareLenghtMedian = M.GetSquareLenght(); // CM

	Pstart = C;
	Mmin = Pstart + M;

	M = GetVectorMediana(B, C, A);
	float squareLenghtMedian = M.GetSquareLenght();    // AM

	if (squareLenghtMedian < minSquareLenghtMedian)
	{
		minSquareLenghtMedian = squareLenghtMedian;
		Pstart = A;
		Mmin = Pstart + M;
	}

	M = GetVectorMediana(C, A, B);
	squareLenghtMedian = M.GetSquareLenght();          // BM
	if (squareLenghtMedian < minSquareLenghtMedian)
	{
		minSquareLenghtMedian = squareLenghtMedian;
		Pstart = B;
		Mmin = Pstart + M;
	}
}

// найти треугольник с вершинами на мн-ве точек, у которого длина медианы минимальна
// возвращается код ошибки 
// (FIND_DEGENERATE_TRIANGLE - если найден, хотя бы один вырожденный тр-ник)
int FindTriangleMinLenghtMedian(std::vector<Vector2D>& points, Vector2D& Amin, Vector2D& Bmin, Vector2D& Cmin)
{
	int code_error = FIND_DEGENERATE_TRIANGLE;
	int n = points.size();
	if (n > 2)
	{
		int* indexArray = new int[n];
		for (size_t i = 0; i < n; i++)
			indexArray[i] = i;

		Amin = points[0];
		Bmin = points[1];
		Cmin = points[2];

		float minSquareLen = -1;
		float squareLen;

		if (!isDegenerateTriangle(Amin, Bmin, Cmin))
		{
			code_error = SUCCESS;
			minSquareLen = GetMinSquareLenghtMedian(Amin, Bmin, Cmin);
		}

		
		Vector2D A, B, C;
		while (NextCombination(indexArray, n, 3))
		{
			A = points[indexArray[0]];
			B = points[indexArray[1]];
			C = points[indexArray[2]];

			// если треугольник не вырожденный
			if (!isDegenerateTriangle(A, B, C))
			{
				code_error = SUCCESS;

				squareLen = GetMinSquareLenghtMedian(A, B, C);
				if (squareLen < minSquareLen || minSquareLen < 0)
				{
					minSquareLen = squareLen;
					Amin = A;
					Bmin = B;
					Cmin = C;
				}
			}
		}

		delete[] indexArray;
	}
	else
		code_error = NOT_ENOUGH_POINT;
	return code_error;
}

float GetMinThreeValue(float a, float b, float c)
{
	float minValue = a;
	if (b < minValue)
		minValue = b;
	if (c < minValue)
		minValue = c;
	return minValue;
}

float GetMaxThreeValue(float a, float b, float c)
{
	float maxValue = a;
	if (b > maxValue)
		maxValue = b;
	if (c > maxValue)
		maxValue = c;
	return maxValue;
}

float GetKoef(float lenA, float lenB)
{
	float answer = 1;
	if (lenA)
		answer = lenB / lenA;
	return answer;
}