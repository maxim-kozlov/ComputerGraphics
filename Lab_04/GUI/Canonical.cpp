#include "Canonical.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Canonical::DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color)
{
	int r2 = r * r;
	int l = ceilf(r * M_SQRT1_2); // 1 / √2
	int i = 0, j;
	for (i = 0; i <= l; i++)
	{
		j = roundf(sqrtf(r2 - i * i));

		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);

		canvas.setPixel(x + j, y + i, color);
		canvas.setPixel(x + j, y - i, color);
		canvas.setPixel(x - j, y + i, color);
		canvas.setPixel(x - j, y - i, color);
	}
}

void Canonical::DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color)
{
	int a2 = a * a;
	int b2 = b * b;

	// Производная при y'= -1 , является границей для оптимального рисования
	// y'= -b^2/a^2 * x/y
	// y^2 = b^4 / (a^2 + b^2)
	// x^2 = a^4 / (a^2 + b^2)

	float znam = sqrtf(a2 + b2);
	int lx = ceilf(a2 / znam);
	int i, j;
	// dx = 1
	for (i = 0; i < lx; i++)
	{
		j = roundf(b / (float)a * sqrtf(a2 - i * i));

		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);
	}

	// dy = -1
	for (; j > 0; j--)
	{
		i = roundf(a / (float)b * sqrtf(b2 - j * j));

		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);
	}

	canvas.setPixel(x + i, y + j, color);
	canvas.setPixel(x + i, y - j, color);
	canvas.setPixel(x - i, y + j, color);
	canvas.setPixel(x - i, y - j, color);
}

void Canonical::TestDrawCicrle(QImage& canvas, int x, int y, int r)
{
	int r2 = r * r;
	int l = ceilf(r * M_SQRT1_2); // 1 / √2
	int i = 0, j;
	for (i = 0; i <= l; i++)
	{
		j = roundf(sqrtf(r2 - i * i));
	}
}

void Canonical::TestDrawEllipse(QImage& canvas, int x, int y, int a, int b)
{
	int a2 = a * a;
	int b2 = b * b;

	// Производная при y'= -1 , является границей для оптимального рисования
	// y'= -b^2/a^2 * x/y
	// y^2 = b^4 / (a^2 + b^2)
	// x^2 = a^4 / (a^2 + b^2)

	float znam = sqrtf(a2 + b2);
	int lx = ceilf(a2 / znam);
	int i, j;
	// dx = 1
	for (i = 0; i < lx; i++)
	{
		j = roundf(b / (float)a * sqrtf(a2 - i * i));
	}

	// dy = -1
	for (; j > 0; j--)
	{
		i = roundf(a / (float)b * sqrtf(b2 - j * j));
	}
}