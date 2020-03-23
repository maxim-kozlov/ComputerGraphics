#pragma once
#include "pch.h"
#include "Matrix.h"
class CG_2D_TRANSFORM_LIBRARY_API Vector2D
{
public:
	Vector2D(float x = 0, float y = 0);

	float GetLenght();

	float GetVectorProduct(Vector2D& Other);
	float GetScalarProduct(Vector2D& Other);

	void Normalize();

	Vector2D operator +(Vector2D& Other);
	Vector2D operator -(Vector2D& Other);

	Vector2D operator *(float k);
	Vector2D operator /(float k);

	void operator +=(Vector2D& Other);
	void operator -= (Vector2D& Other);

	float x;
	float y;
};

