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
		
		// ��� ���������� ������ ��� �������������� �������
		float GetVectorProduct(const Vector2D& other);

		// �������� ������� ����� 
		float GetSquareLenght();

		// �������� ����� �������
		float GetLenght();

		// �������� ��������
		Vector2D operator + (const Vector2D& other);

		// �������� ��������
		Vector2D operator - (const Vector2D& other);

		// ��������� ������� �� �����
		Vector2D operator * (float number);

		// ������� ������� �� �����
		Vector2D operator / (float number);

		std::string ToString();
	private:
		float x;
		float y;
};

#endif
