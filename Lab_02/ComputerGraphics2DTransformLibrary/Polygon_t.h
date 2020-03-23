#pragma once
#include "pch.h"
#include "Vector2D.h"
#include <vector>

class CG_2D_TRANSFORM_LIBRARY_API Polygon_t
{
public:
	Polygon_t();
	Polygon_t(std::vector<Vector2D>& points, unsigned int color = 0x000000);
	std::vector<Vector2D> points;
	unsigned int color;
};

