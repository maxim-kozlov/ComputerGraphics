#pragma once
#include <qimage.h>

int sign(int value);

void ConvertToRGB(unsigned char& r, unsigned char& g, unsigned char& b, unsigned int color);

float fractionalPart(float value);

void SetPixel(QImage& canvas, int x, int y, unsigned char r, unsigned char g, unsigned char b, float a);