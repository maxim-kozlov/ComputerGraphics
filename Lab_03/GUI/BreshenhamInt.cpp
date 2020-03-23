#include "BreshenhamInt.h"
#include "HelperMath.h"

bool BreshenhamInt::DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color)
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

	int dy2 = 2 * dy;
	int dx2 = 2 * dx;

	int e2dx = dy2 - dx;

	int x = xn;
	int y = yn;
	for (size_t i = 1; i < dx + 1; i++)
	{
		canvas.setPixel(x, y, color);

		if (e2dx > 0)
		{
			if (!exchange)
				y = y + deltaY;
			else
				x = x + deltaX;
			e2dx -= dx2;
		}

		if (!exchange)
			x = x + deltaX;
		else
			y = y + deltaY;

		e2dx += dy2;
	}
	canvas.setPixel(x, y, color);

	return x == xk && y == yk;
}

void BreshenhamInt::TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by)
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

	int dy2 = 2 * dy;
	int dx2 = 2 * dx;

	int e2dx = dy2 - dx;

	int x = xn;
	int y = yn;
	if (!exchange)
	{
		for (size_t i = 1; i < dx + 1; i++)
		{
			if (e2dx > 0)
			{
				y = y + deltaY;
				e2dx -= dx2;
			}
			x = x + deltaX;
			e2dx += dy2;
		}
	}
	else
	{
		for (size_t i = 1; i < dx + 1; i++)
		{
			if (e2dx > 0)
			{
				x = x + deltaX;
				e2dx -= dx2;
			}
			y = y + deltaY;
			e2dx += dy2;
		}
	}
}

int BreshenhamInt::GetCountStep(float ax, float ay, float bx, float by)
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

	int dy2 = 2 * dy;
	int dx2 = 2 * dx;

	int e2dx = dy2 - dx;

	int x = xn;
	int y = yn;
	for (size_t i = 1; i < dx + 1; i++)
	{
		if (e2dx > 0)
		{
			if (!exchange)
				y = y + deltaY;
			else
				x = x + deltaX;
			e2dx -= dx2;

			count += 1;
		}

		if (!exchange)
			x = x + deltaX;
		else
			y = y + deltaY;

		e2dx += dy2;
	}
	return count;
}