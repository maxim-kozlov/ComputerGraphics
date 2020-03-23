#include "DDA_Painter.h"
#include "HelperMath.h"

bool DDA_Painter::DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color)
{
	float deltaX = bx - ax;
	float deltaY = by - ay;

	float dx = fabs(deltaX);
	float dy = fabs(deltaY);

	float l = dx > dy ? dx : dy;

	deltaX = deltaX / l;
	deltaY = deltaY / l;

	float x = ax;
	float y = ay;
	for (size_t i = 1; i < l + 1; i++)
	{
		canvas.setPixel(roundf(x), roundf(y), color);
		x = x + deltaX;
		y = y + deltaY;
	}
	canvas.setPixel(roundf(x), roundf(y), color);

	return roundf(x) == roundf(bx) && roundf(y) == roundf(by);
}

void DDA_Painter::TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by)
{
	float deltaX = bx - ax;
	float deltaY = by - ay;

	float dx = fabs(deltaX);
	float dy = fabs(deltaY);

	float l = dx > dy ? dx : dy;

	deltaX = deltaX / l;
	deltaY = deltaY / l;

	float x = ax;
	float y = ay;
	for (size_t i = 1; i < l + 1; i++)
	{
		x = x + deltaX;
		y = y + deltaY;
	}
}

int DDA_Painter::GetCountStep(float ax, float ay, float bx, float by)
{
	int count = 0;

	float deltaX = bx - ax;
	float deltaY = by - ay;

	float dx = fabs(deltaX);
	float dy = fabs(deltaY);

	bool exchange = dy > dx;
	float l = exchange ? dy : dx;

	deltaX = deltaX / l;
	deltaY = deltaY / l;

	float x = ax;
	float y = ay;
	int xi = roundf(x);
	int yi = roundf(y);
	for (size_t i = 1; i < l + 1; i++)
	{
		if (!exchange)
		{
			if (yi != roundf(y))
			{
				count += 1;
				yi = roundf(y);
			}
		}
		else
		{
			if (xi != roundf(x))
			{
				count += 1;
				xi = roundf(x);
			}
		}
		x = x + deltaX;
		y = y + deltaY;
	}

	return count;
}