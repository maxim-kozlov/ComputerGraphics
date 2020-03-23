#include "pch.h"
#include "Polygon_t.h"

Polygon_t::Polygon_t()
{
	color = 0x000000;
}

Polygon_t::Polygon_t(std::vector<Vector2D>& points, unsigned int color)
{
	this->points = points;
	this->color = color;
}