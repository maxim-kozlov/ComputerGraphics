#include "pch.h"
#include "Vector2D.h"

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D() : Vector2D(0.0, 0.0) { }

float Vector2D::GetX()
{
	return x;
}

void Vector2D::SetX(float x)
{
	this->x = x;
}

float Vector2D::GetY()
{
	return y;
}

void Vector2D::SetY(float y)
{
	this->y = y;
}

float Vector2D::GetScalarProduct(const Vector2D& other)
{
	return this->x * other.x + this->y * other.y;
}

float Vector2D::GetVectorProduct(const Vector2D& other)
{
	return this->x * other.y - this->y * other.x;
}

float Vector2D::GetSquareLenght()
{
	return this->GetScalarProduct(*this);
}

float Vector2D::GetLenght()
{
	return sqrt(this->GetSquareLenght());
}

Vector2D Vector2D::operator +(const Vector2D& other)
{
	return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator -(const Vector2D& other)
{
	return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator * (float number)
{
	return Vector2D(this->x * number, this->y * number);
}

Vector2D Vector2D::operator / (float number)
{
	return Vector2D(this->x / number, this->y / number);
}

std::string Vector2D::ToString()
{
	char buf[32];
	sprintf_s<32>(buf, "(%.3lf, %.3lf)", this->x, this->y);
	return std::string(buf);
}