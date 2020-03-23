#include "WooPainter.h"
#include "HelperMath.h"

WooPainter::WooPainter(float Imax)
{
	this->Imax = Imax;
}

bool WooPainter::DrawLine(QImage& canvas, float ax, float ay, float bx, float by, unsigned int color)
{
	// разложить цвет на rgb
	unsigned char r, g, b;
	ConvertToRGB(r, g, b, color);

	float deltaX = bx - ax;
	float deltaY = by - ay;

	float dx = fabs(deltaX);
	float dy = fabs(deltaY);

	float l;
	bool exchange = dy > dx;
	if (exchange)
		l = dy;
	else
		l = dx;
	deltaX /= l;
	deltaY /= l;

	float x = ax;
	float y = ay;
	for (size_t i = 1; i < l + 1; i++)
	{
		if (!exchange)
		{
			float d1 = Imax * (1 - y + int(y));
			SetPixel(canvas, x, y, r, g, b, d1);
			SetPixel(canvas, x, y + 1, r, g, b, Imax - d1);
		}
		else
		{
			float d1 = Imax * (1 - x + int(x));
			SetPixel(canvas, x, y, r, g, b, d1);
			SetPixel(canvas, x + 1, y, r, g, b, Imax - d1);
		}
		x = x + deltaX;
		y = y + deltaY;
	}
	
	if (!exchange)
	{
		float d1 = Imax * (1 - y + int(y));
		SetPixel(canvas, x, y, r, g, b, d1);
		SetPixel(canvas, x, y + 1, r, g, b, Imax - d1);
	}
	else
	{
		float d1 = Imax * (1 - x + int(x));
		SetPixel(canvas, x, y, r, g, b, d1);
		SetPixel(canvas, x + 1, y, r, g, b, Imax - d1);
	}

	return roundf(x) == roundf(bx) && roundf(y) == roundf(by);
}

void WooPainter::TestDrawLine(QImage& canvas, float ax, float ay, float bx, float by)
{
	float deltaX = bx - ax;
	float deltaY = by - ay;

	float dx = fabs(deltaX);
	float dy = fabs(deltaY);

	float l;
	bool exchange = dy > dx;
	if (exchange)
		l = dy;
	else
		l = dx;
	deltaX /= l;
	deltaY /= l;

	float x = ax;
	float y = ay;
	for (size_t i = 1; i < l + 1; i++)
	{
		if (!exchange)
		{
			float d1 = Imax * (1 - y + int(y));
		}
		else
		{
			float d1 = Imax * (1 - x + int(x));
		}
		x = x + deltaX;
		y = y + deltaY;
	}

	if (!exchange)
	{
		float d1 = Imax * (y - int(y));
	}
	else
	{
		float d1 = Imax * (x - int(x));
	}
}

int WooPainter::GetCountStep(float ax, float ay, float bx, float by)
{
	int count = 0;
	float deltaX = bx - ax;
	float deltaY = by - ay;

	float dx = fabs(deltaX);
	float dy = fabs(deltaY);

	float l;
	bool exchange = dy > dx;
	if (exchange)
		l = dy;
	else
		l = dx;
	deltaX /= l;
	deltaY /= l;

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