#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "pch.h"
#include <string>

class MATHLIBRARY_API Vector2D
{
	public:
		Vector2D();
		Vector2D(float x, float y);
		
		float GetX();
		void SetX(float x);

		float GetY();
		void SetY(float y);

		float GetScalarProduct(const Vector2D& other);
		
		// для двумерного случая это ориентированая площадь
		float GetVectorProduct(const Vector2D& other);

		// получить квадрат длины 
		float GetSquareLenght();

		// получить длину вектора
		float GetLenght();

		// сложение векторов
		Vector2D operator + (const Vector2D& other);

		// разность векторов
		Vector2D operator - (const Vector2D& other);

		// умножение вектора на число
		Vector2D operator * (float number);

		// деление вектора на число
		Vector2D operator / (float number);

		std::string ToString();
	private:
		float x;
		float y;
};

#endif
