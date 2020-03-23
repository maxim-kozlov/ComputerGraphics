#include "MiddleDot.h"
#define _USE_MATH_DEFINES
#include <math.h>

void MiddleDot::DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color)
{
	int i = 0, j = r;
	// t = x^2 + y^2 - r^2
	// t(1, r-1/2.)
	// t = 5 / 4 - r
	// 0,25 можно отбросить
	// начинаем с целого числа и каждый раз прибавляем целое число
	// невозможна ситация целое число + 0,25 получить ноль
	int t = 1 - r;
	
	// t += 2 * i + 3; при горизонтальном шаге
	// t += 2 * (i - j) + 5 при диагональном шаге
	int incrA = 3; // i = 0
	int incrB = 5 - 2 * r; // i = 0, j = r
	while(i < j)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);

		canvas.setPixel(x + j, y + i, color);
		canvas.setPixel(x + j, y - i, color);
		canvas.setPixel(x - j, y + i, color);
		canvas.setPixel(x - j, y - i, color);

		// если диагональный пиксель ближе
		if (t >= 0)
		{
			// скорректировать пробную функцию
			// x^2 + (y-1-1/2)^2 - r^2 - (x^2 + (y-1-1/2)^2 - r^2) = 
			// -2y + 2
			// 
			t += incrB;
			incrB += 4;
			// t += 2 * (1 - j);
			j--;
		}
		else
		{
			t += incrA;
			incrB += 2;
		}
		incrA += 2;
		i++;
		//  t += 2 * i + 1;
	}
	canvas.setPixel(x + i, y + j, color);
	canvas.setPixel(x + i, y - j, color);
	canvas.setPixel(x - i, y + j, color);
	canvas.setPixel(x - i, y - j, color);
}


void MiddleDot::DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color)
{
	int a2 = a * a;
	int b2 = b * b;

	int ad = 2 * a2;
	int bd = 2 * b2;

	int i = 0, j = b;

	// tпр = b^2*x^2 + a^2*y^2 - a^2 * b^2;
	// начальное значение средней точки M(1, b-1/2.)
	float t = a2 / 4. - a2 * b + b2;
	float dt = 0;
	float dy = -ad;

	// Производная при y'= -1 , является границей для оптимального рисования
	// y'= -b^2/a^2 * x/y
	while (b2 * i < a2 * j)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);


		// M вне эллипса, ближе диагональный пиксель
		if (t >= 0)
		{
			j--;
			t -= ad * j;
		}

		i++;
		t += bd * i + b2;
	}

	t += 3 / 4. * (a2 - b2) - (b2 * i + a2 * j);

	while (j > 0)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);

		// M внутри эллипса, ближе диагональный пиксель
		if (t <= 0)
		{
			i++;
			t += bd * i;
		}
		j--;
		t += -ad * j + a2;
	}
	
	canvas.setPixel(x + i, y + j, color);
	canvas.setPixel(x + i, y - j, color);
	canvas.setPixel(x - i, y + j, color);
	canvas.setPixel(x - i, y - j, color);
}

void MiddleDot::TestDrawCicrle(QImage& canvas, int x, int y, int r)
{
	int i = 0, j = r;
	// t = x^2 + y^2 - r^2
	// t(1, r-1/2.)
	// t = 5 / 4 - r
	// 0,25 можно отбросить
	// начинаем с целого числа и каждый раз прибавляем целое число
	// невозможна ситация целое число + 0,25 получить ноль
	int t = 1 - r;

	// t += 2 * i + 3; при горизонтальном шаге
	// t += 2 * (i - j) + 5 при диагональном шаге
	int incrA = 3; // i = 0
	int incrB = 5 - 2 * r; // i = 0, j = r
	while (i < j)
	{
		// если диагональный пиксель ближе
		if (t >= 0)
		{
			// скорректировать пробную функцию
			// x^2 + (y-1-1/2)^2 - r^2 - (x^2 + (y-1-1/2)^2 - r^2) = 
			// -2y + 2
			// 
			t += incrB;
			incrB += 4;
			j--;
		}
		else
		{
			t += incrA;
			incrB += 2;
		}
		incrA += 2;
		i++;
	}
}

void MiddleDot::TestDrawEllipse(QImage& canvas, int x, int y, int a, int b)
{
	int a2 = a * a;
	int b2 = b * b;

	int ad = 2 * a2;
	int bd = 2 * b2;

	int i = 0, j = b;

	// tпр = b^2*x^2 + a^2*y^2 - a^2 * b^2;
	// начальное значение средней точки M(1, b-1/2.)
	float t = a2 / 4. - a2 * b + b2;
	float dt = 0;
	float dy = -ad;

	// Производная при y'= -1 , является границей для оптимального рисования
	// y'= -b^2/a^2 * x/y
	while (b2 * i < a2 * j)
	{
		// M вне эллипса, ближе диагональный пиксель
		if (t >= 0)
		{
			j--;
			t -= ad * j;
		}

		i++;
		t += bd * i + b2;
	}

	t += 3 / 4. * (a2 - b2) - (b2 * i + a2 * j);

	while (j > 0)
	{
		// M внутри эллипса, ближе диагональный пиксель
		if (t <= 0)
		{
			i++;
			t += bd * i;
		}
		j--;
		t += -ad * j + a2;
	}
}