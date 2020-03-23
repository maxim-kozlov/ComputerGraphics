#ifndef HELPER_MATH_H
#define HELPER_MATH_H

#include "pch.h"
#include <vector>
#include "Vector2D.h"

#define SUCCESS 0
#define FIND_DEGENERATE_TRIANGLE -1
#define NOT_ENOUGH_POINT -2

// �������� ������� ����������� ����� ������� ������������
extern "C++" MATHLIBRARY_API float GetMinSquareLenghtMedian(Vector2D& A, Vector2D& B, Vector2D& C);

// ����� ����������� � ��������� �� ��-�� �����, � �������� ����� ������� ����������
// ������������ ��� ������ 
// (FIND_DEGENERATE_TRIANGLE - ���� ������, ���� �� ���� ����������� ��-���)
extern "C++" MATHLIBRARY_API int FindTriangleMinLenghtMedian(std::vector<Vector2D> & points, Vector2D & Amin, Vector2D & Bmin, Vector2D & Cmin);

// �������� ������ CM, ��� M �������� ������� AB 
extern "C++" MATHLIBRARY_API Vector2D GetVectorMediana(Vector2D & A, Vector2D & B, Vector2D & C);

extern "C++" MATHLIBRARY_API void GetMinMedian(Vector2D & A, Vector2D & B, Vector2D & C, Vector2D & Mmin, Vector2D & Pstart);

extern "C++" MATHLIBRARY_API  float GetMinThreeValue(float a, float b, float c);
extern "C++" MATHLIBRARY_API  float GetMaxThreeValue(float a, float b, float c);

// ����������� ������������������ ����� k = lenB / lenA
extern "C++" MATHLIBRARY_API float GetKoef(float lenA, float lenB);

#endif
