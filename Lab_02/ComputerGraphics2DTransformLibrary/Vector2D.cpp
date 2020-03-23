#include "pch.h"
#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2D::GetLenght()
{
	return hypotf(x, y);
}

Vector2D Vector2D::operator +(Vector2D& Other)
{
	return Vector2D(this->x + Other.x, this->y + Other.y);
}

Vector2D Vector2D::operator -(Vector2D& Other)
{
	return Vector2D(this->x - Other.x, this->y - Other.y);
}

void Vector2D::operator +=(Vector2D& Other)
{
	this->x += Other.x;
	this->y += Other.y;
}

void Vector2D::operator -= (Vector2D& Other)
{
	this->x -= Other.x;
	this->y -= Other.y;
}

Vector2D Vector2D::operator *(float k)
{
	return Vector2D(k * x, k * y);
}

Vector2D Vector2D::operator /(float k)
{
	return Vector2D(x / k, y / k);
}

float Vector2D::GetScalarProduct(Vector2D& Other)
{
	return x * Other.x + y * Other.y;
}

void Vector2D::Normalize()
{
	float len = GetLenght();
	x /= len;
	y /= len;
}

float Vector2D::GetVectorProduct(Vector2D& Other)
{
	return x * Other.y - y * Other.x;
}