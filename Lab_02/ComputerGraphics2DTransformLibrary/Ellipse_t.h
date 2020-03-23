#pragma once

#include "pch.h"
#include "Vector2D.h"
#include "Matrix1x3.h"
#include "Matrix3x3.h"

#include "Polygon_t.h"

class CG_2D_TRANSFORM_LIBRARY_API Ellipse_t
{
public:
	Ellipse_t(float h, float w, Vector2D center, float angle = 0.0, unsigned int color = 0x000000);

	// получить по эллипсу полигон
	Polygon_t GetPolygon();

private:
	float h;
	float w;
	float angle;
	Vector2D center;
	unsigned int color;
};

