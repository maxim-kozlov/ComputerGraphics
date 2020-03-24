#include "Canonical.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Canonical::DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color)
{
	int r2 = r * r;
	int i = 0, j = r;
	while (i < j)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);

		canvas.setPixel(x + j, y + i, color);
		canvas.setPixel(x + j, y - i, color);
		canvas.setPixel(x - j, y + i, color);
		canvas.setPixel(x - j, y - i, color);

		i++;
		j = roundf(sqrtf(r2 - i * i));
	}
	canvas.setPixel(x + i, y + j, color);
	canvas.setPixel(x + i, y - j, color);
	canvas.setPixel(x - i, y + j, color);
	canvas.setPixel(x - i, y - j, color);
}

void Canonical::DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color)
{
	int a2 = a * a;
	int b2 = b * b;

	// Производная при y'= -1 , является границей для оптимального рисования
	// y'= -b^2/a^2 * x/y
	// b^2 * x = a^2 * y

	int i = 0, j = b;
	// dx = 1
	while (b2 * i < a2 * j)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);
		
		i++;
		j = roundf(b / (float)a * sqrtf(a2 - i * i));
	}

	// dy = -1
	while (j >= 0)
	{
		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);
		
		j--;
		i = roundf(a / (float)b * sqrtf(b2 - j * j));
	}
}

void Canonical::TestDrawCicrle(QImage& canvas, int x, int y, int r)
{
	int r2 = r * r;
	int i = 0, j = r;
	while (i < j)
	{
		i++;
		j = roundf(sqrtf(r2 - i * i));
	}
}

void Canonical::TestDrawEllipse(QImage& canvas, int x, int y, int a, int b)
{
	int a2 = a * a;
	int b2 = b * b;

	// Производная при y'= -1 , является границей для оптимального рисования
	// y'= -b^2/a^2 * x/y
	// b^2 * x = a^2 * y

	int i = 0, j = b;
	// dx = 1
	while (b2 * i < a2 * j)
	{
		i++;
		j = roundf(b / (float)a * sqrtf(a2 - i * i));
	}

	// dy = -1
	while (j > 0)
	{
		j--;
		i = roundf(a / (float)b * sqrtf(b2 - j * j));
	}
}