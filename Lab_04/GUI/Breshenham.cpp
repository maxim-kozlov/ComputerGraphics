#include "Breshenham.h"
#define _USE_MATH_DEFINES	
#include <math.h>

// < 0 внутри, > 0 вне, = 0 на окружности 
inline int tCicrle(int x, int y, int r)
{
	return x * x + y * y - r * r;
}

inline void DiagonalStepCicrle(int& x, int& y, int& d)
{
	x++;
	y--;
	d += 2 * (x - y + 1);
}

inline void HorizontalStepCicrle(int& x, int& y, int& d)
{
	x++;
	d += 2 * x + 1;
}

inline void VerticalStepCicrle(int& x, int& y, int& d)
{
	y--;
	d += -2 * y + 1;
}


void Breshenham::DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color)
{
	int r2 = r * r;
	int d = 2 * (1 - r); // первоначальная ошибка

	int lx = ceilf(r * M_SQRT1_2); // 1 / √2

	int i = 0, j = r;
	while (i < lx)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);

		canvas.setPixel(x + j, y + i, color);
		canvas.setPixel(x + j, y - i, color);
		canvas.setPixel(x - j, y + i, color);
		canvas.setPixel(x - j, y - i, color);

		if (d == 0) // диагональная точка лежит на окружности
			DiagonalStepCicrle(i, j, d);
		else if (d < 0) // диагональная точка внутри окружности
		{
			//  раст. до гор пикселя      раст. до диаг. пикселя
			// |(xi+1)^2 + yi^2 - r^2| - |(xi+1)^2 + (yi-1)^2 - r^2|
			int delta1 = 2 * (d + j) - 1;
			if (delta1 > 0)
				DiagonalStepCicrle(i, j, d);
			else
				HorizontalStepCicrle(i, j, d);
		}

		else // диагональная точка вне окружности
		{
			//  раст. до диаг. пикселя        раст. до верт пикселя   
			// |(xi+1)^2 + (yi-1)^2 - r^2| - |xi^2 + (yi-1)^2 - r^2|
			int delta2 = 2 * (d - i) - 1;
			if (delta2 < 0)
				DiagonalStepCicrle(i, j, d);
			else
				VerticalStepCicrle(i, j, d);
		}
	}
	canvas.setPixel(x + i, y + j, color);
	canvas.setPixel(x + i, y - j, color);
	canvas.setPixel(x - i, y + j, color);
	canvas.setPixel(x - i, y - j, color);
}

// < 0 внутри, > 0 вне, = 0 на окружности 
inline int tEllipse(int x, int y, int a2, int b2)
{
	return b2 * x * x + a2 * y * y - a2 * b2;
}

inline void DiagonalStepEllipse(int& x, int& y, int a2, int b2, int& d)
{
	x++;
	y--;
	d += b2 * (2 * x + 1) + a2 * (1 - 2 * y);
}

inline void HorizontalStepEllipse(int& x, int& y, int a2, int b2, int& d)
{
	x++;
	d += b2 * (2 * x + 1);
}

inline void VerticalStepEllipse(int& x, int& y, int a2, int b2, int& d)
{
	y--;
	d += a2 * (1 - 2 * y);
}


void Breshenham::DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color)
{
	int a2 = a * a;
	int b2 = b * b;
	int d = a2 + b2 - 2 * a2 * b;
	int i = 0, j = b;
	while (j > 0)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);

		if (d == 0) // диагональная точка лежит на эллипсе
			DiagonalStepEllipse(i, j, a2, b2, d);
		else if (d < 0) // диагональная точка внутри эллипса
		{
			//  раст. до гор пикселя      раст. до диаг. пикселя
			// |b^2(xi+1)^2 + a^2yi^2 - a^2b^2| - |b^2(xi+1)^2 + a^2(yi-1)^2 - a^2b^2|
			int delta1 = 2 * (d + a2 * j) - a2;
			if (delta1 > 0)
				DiagonalStepEllipse(i, j, a2, b2, d);
			else
				HorizontalStepEllipse(i, j, a2, b2, d);
		}

		else // диагональная точка вне эллипса
		{
			//  раст. до диаг. пикселя        раст. до верт пикселя   
			// |b^2(xi+1)^2 + a^2(yi-1)^2 - a^2b^2| - |b^2xi^2 + a^2(yi-1)^2 - a^2b^2|
			int delta2 = 2 * (d - b2 * i) - b2;
			if (delta2 < 0)
				DiagonalStepEllipse(i, j, a2, b2, d);
			else
				VerticalStepEllipse(i, j, a2, b2, d);
		}
	}
	canvas.setPixel(x + i, y + j, color);
	canvas.setPixel(x + i, y - j, color);
	canvas.setPixel(x - i, y + j, color);
	canvas.setPixel(x - i, y - j, color);
}


void Breshenham::TestDrawCicrle(QImage& canvas, int x, int y, int r)
{
	int r2 = r * r;
	int d = 2 * (1 - r); // первоначальная ошибка

	int lx = ceilf(r * M_SQRT1_2); // 1 / √2

	int i = 0, j = r;
	while (i < lx)
	{
		if (d == 0) // диагональная точка лежит на окружности
			DiagonalStepCicrle(i, j, d);
		else if (d < 0) // диагональная точка внутри окружности
		{
			//  раст. до гор пикселя      раст. до диаг. пикселя
			// |(xi+1)^2 + yi^2 - r^2| - |(xi+1)^2 + (yi-1)^2 - r^2|
			int delta1 = 2 * (d + j) - 1;
			if (delta1 > 0)
				DiagonalStepCicrle(i, j, d);
			else
				HorizontalStepCicrle(i, j, d);
		}

		else // диагональная точка вне окружности
		{
			//  раст. до диаг. пикселя        раст. до верт пикселя   
			// |(xi+1)^2 + (yi-1)^2 - r^2| - |xi^2 + (yi-1)^2 - r^2|
			int delta2 = 2 * (d - i) - 1;
			if (delta2 < 0)
				DiagonalStepCicrle(i, j, d);
			else
				VerticalStepCicrle(i, j, d);
		}
	}
}

void Breshenham::TestDrawEllipse(QImage& canvas, int x, int y, int a, int b)
{
	int a2 = a * a;
	int b2 = b * b;
	int d = a2 + b2 - 2 * a2 * b;
	int i = 0, j = b;
	while (j > 0)
	{
		if (d == 0) // диагональная точка лежит на эллипсе
			DiagonalStepEllipse(i, j, a2, b2, d);
		else if (d < 0) // диагональная точка внутри эллипса
		{
			//  раст. до гор пикселя      раст. до диаг. пикселя
			// |b^2(xi+1)^2 + a^2yi^2 - a^2b^2| - |b^2(xi+1)^2 + a^2(yi-1)^2 - a^2b^2|
			int delta1 = 2 * (d + a2 * j) - a2;
			if (delta1 > 0)
				DiagonalStepEllipse(i, j, a2, b2, d);
			else
				HorizontalStepEllipse(i, j, a2, b2, d);
		}

		else // диагональная точка вне эллипса
		{
			//  раст. до диаг. пикселя        раст. до верт пикселя   
			// |b^2(xi+1)^2 + a^2(yi-1)^2 - a^2b^2| - |b^2xi^2 + a^2(yi-1)^2 - a^2b^2|
			int delta2 = 2 * (d - b2 * i) - b2;
			if (delta2 < 0)
				DiagonalStepEllipse(i, j, a2, b2, d);
			else
				VerticalStepEllipse(i, j, a2, b2, d);
		}
	}
}