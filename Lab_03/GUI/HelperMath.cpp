#include "HelperMath.h"

int sign(int value)
{
	if (value > 0)
		return 1;
	if (value < 0)
		return -1;
	return 0;
}

float fractionalPart(float value)
{
	return value - (int)value;
}

void ConvertToRGB(unsigned char& r, unsigned char& g, unsigned char& b, unsigned int color)
{
	b = color % 256;
	color /= 256;
	g = color % 256;
	color /= 256;
	r = color;
}

void SetPixel(QImage& canvas, int x, int y, unsigned char r, unsigned char g, unsigned char b, float a)
{
	unsigned int back = canvas.pixel(x, y);
	unsigned char backR, backG, backB;
	ConvertToRGB(backR, backG, backB, back);

	float a1 = 1 - a;
	unsigned char resR = backR * a1 + r * a;
	unsigned char resG = backG * a1 + g * a;
	unsigned char resB = backB * a1 + b * a;

	canvas.setPixel(x, y, qRgb(resR, resG, resB));
}