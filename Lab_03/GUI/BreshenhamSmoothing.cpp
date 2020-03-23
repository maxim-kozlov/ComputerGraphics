#include "BreshenhamSmoothing.h"
#include "HelperMath.h"

BreshenhamSmoothing::BreshenhamSmoothing(float Imax)
{
	this->Imax = Imax;
}

bool BreshenhamSmoothing::DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color)
{
	int xn = roundf(ax);
	int yn = roundf(ay);
	int xk = roundf(bx);
	int yk = roundf(by);

	unsigned char r, g, b;
	ConvertToRGB(r, g, b, color);

	int dx = xk - xn;
	int dy = yk - yn;

	int deltaX = sign(dx);
	int deltaY = sign(dy);

	dx = fabs(dx);
	dy = fabs(dy);

	bool exchange = dy > dx;
	if (exchange)
		std::swap(dx, dy);

	float m = Imax * (float)dy / dx;
	float w = Imax - m;
	float e = Imax / 2; // dy/dx - 1/2 + 1 - dy/dx = 1/2

	int x = xn;
	int y = yn;
	for (size_t i = 1; i < dx + 1; i++)
	{
		SetPixel(canvas, x, y, r, g, b, e);
		if (e > w)
		{
			if (!exchange)
				y = y + deltaY;
			else
				x = x + deltaX;
			e -= w;
		}
		else
			e += m;

		if (!exchange)
			x = x + deltaX;
		else
			y = y + deltaY;
	}
	canvas.setPixel(x, y, color);
	return x == xk && y == yk;
}

void BreshenhamSmoothing::TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by)
{
	int xn = roundf(ax);
	int yn = roundf(ay);
	int xk = roundf(bx);
	int yk = roundf(by);

	int dx = xk - xn;
	int dy = yk - yn;

	int deltaX = sign(dx);
	int deltaY = sign(dy);

	dx = fabs(dx);
	dy = fabs(dy);

	bool exchange = dy > dx;
	if (exchange)
		std::swap(dx, dy);

	float m = Imax * (float)dy / dx;
	float w = Imax - m;
	float e = Imax / 2;

	int x = xn;
	int y = yn;
	unsigned int color = 1;
	unsigned int resColor;
	for (size_t i = 1; i < dx + 1; i++)
	{
		// вычисление результирующего пикселя
		resColor = color * e;
		if (e > w)
		{
			if (!exchange)
				y = y + deltaY;
			else
				x = x + deltaX;
			e -= w;
		}
		else
			e += m;

		if (!exchange)
			x = x + deltaX;
		else
			y = y + deltaY;
	}
}

int BreshenhamSmoothing::GetCountStep(float ax, float ay, float bx, float by)
{
	int count = 0;
	int xn = roundf(ax);
	int yn = roundf(ay);
	int xk = roundf(bx);
	int yk = roundf(by);

	int dx = xk - xn;
	int dy = yk - yn;

	int deltaX = sign(dx);
	int deltaY = sign(dy);

	dx = fabs(dx);
	dy = fabs(dy);

	bool exchange = dy > dx;
	if (exchange)
		std::swap(dx, dy);

	float m = Imax * (float)dy / dx;
	float w = Imax - m;
	float e = Imax / 2;

	int x = xn;
	int y = yn;
	for (size_t i = 1; i < dx + 1; i++)
	{
		if (e > w)
		{
			if (!exchange)
				y = y + deltaY;
			else
				x = x + deltaX;
			e -= w;

			count += 1;
		}
		else
			e += m;

		if (!exchange)
			x = x + deltaX;
		else
			y = y + deltaY;
	}
	return count;
}