#include "Parametric.h"

#define _USE_MATH_DEFINES	
#include <math.h>

void Parametric::DrawCicrle(QImage& canvas, int x, int y, int r, unsigned int color)
{
	float step = 1 / (float)r;
	int i, j;
	for (float t = 0; t < M_PI_4; t += step)
	{
		i = roundf(r * cosf(t));
		j = roundf(r * sinf(t));

		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);

		canvas.setPixel(x + j, y + i, color);
		canvas.setPixel(x + j, y - i, color);
		canvas.setPixel(x - j, y + i, color);
		canvas.setPixel(x - j, y - i, color);
	}
	// t = pi/4
	i = roundf(r * M_SQRT1_2);
	j = i;
	canvas.setPixel(x + i, y + j, color);
	canvas.setPixel(x + i, y - j, color);
	canvas.setPixel(x - i, y + j, color);
	canvas.setPixel(x - i, y - j, color);
}

void Parametric::DrawEllipse(QImage& canvas, int x, int y, int a, int b, unsigned int color)
{
	// кривизна кривой 1/ R = K = lim da/ds
	// ds - смещение вдоль дуги кривой
	// da - изменение угла наклона касательной

	// K = |x'*y'' - y'*x''| / (x'^2 + y'^2)^(3/2)

	// x = cos(t)
	// y = sin(t)

	// K = ab/(a^2*sin^2(t) + b^2*cos^2(t))^(3/2)

	// в вершинах t = 0 K = a/b^2
	// t = pi/2 K = b/a^2

	float step = a > b ? (float)b / (a * a) : (float)a / (b * b);
	int i, j;
	for (float t = 0; t < M_PI_2 + step / 2; t += step)
	{
		i = roundf(a * cosf(t));
		j = roundf(b * sinf(t));

		canvas.setPixel(x + i, y + j, color);
		canvas.setPixel(x + i, y - j, color);
		canvas.setPixel(x - i, y + j, color);
		canvas.setPixel(x - i, y - j, color);
	}
}


void Parametric::TestDrawCicrle(QImage& canvas, int x, int y, int r)
{
	float step = 1 / (float)r;
	int i, j;
	for (float t = 0; t < M_PI_4 + step / 2; t += step)
	{
		i = roundf(r * cosf(t));
		j = roundf(r * sinf(t));
	}
}

void Parametric::TestDrawEllipse(QImage& canvas, int x, int y, int a, int b)
{
	float step = a > b ? (float)b / (a * a) : (float)a / (b * b);
	int i, j;
	for (float t = 0; t < M_PI_2 + step / 2; t += step)
	{
		i = roundf(a * cosf(t));
		j = roundf(b * sinf(t));
	}
}