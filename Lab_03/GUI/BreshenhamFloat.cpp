#include "BreshenhamFloat.h"
#include "HelperMath.h"

bool BreshenhamFloat::DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color)
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

	float m = (float)dy / dx;
	float e = m - 0.5;

	int x = xn;
	int y = yn;
	for (size_t i = 1; i < dx + 1; i++)
	{
		canvas.setPixel(x, y, color);
		if (e > 0)
		{
			if (!exchange)
				y = y + deltaY;
			else
				x = x + deltaX;
			e--;
		}

		if (!exchange)
			x = x + deltaX;
		else
			y = y + deltaY;

		e += m;
	}
	canvas.setPixel(x, y, color);

	return x == xk && y == yk;
}

void BreshenhamFloat::TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by)
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

	float m = (float)dy / dx;
	float e = m - 0.5;

	int x = xn;
	int y = yn;
	if (!exchange)
	{
		for (size_t i = 1; i < dx + 1; i++)
		{
			if (e > 0)
			{
				y = y + deltaY;
				e--;
			}
			x = x + deltaX;
			e += m;
		}
	}
	else
	{
		for (size_t i = 1; i < dx + 1; i++)
		{
			if (e > 0)
			{
				x = x + deltaX;
				e--;
			}
			y = y + deltaY;
			e += m;
		}
	}
}

int BreshenhamFloat::GetCountStep(float ax, float ay, float bx, float by)
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

	float m = (float)dy / dx;
	float e = m - 0.5;

	int x = xn;
	int y = yn;
	for (size_t i = 1; i < dx + 1; i++)
	{
		if (e > 0)
		{
			if (!exchange)
				y = y + deltaY;
			else
				x = x + deltaX;
			e--;

			count += 1;
		}

		if (!exchange)
			x = x + deltaX;
		else
			y = y + deltaY;

		e += m;
	}

	return count;
}