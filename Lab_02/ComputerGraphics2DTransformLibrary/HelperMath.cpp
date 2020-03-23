#include "pch.h"
#include "HelperMath.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define max(a, b) max()
#include <limits>

float GetRadians(float degree)
{
	return degree / 180 * M_PI;
}

float GetDegrees(float radians)
{
	return radians * 180.0 / M_PI;
}

float GetMaxFloat()
{
	return std::numeric_limits<float>::max();
}

Polygon_t GetTransformPolygon(Polygon_t& polygon,
	Matrix3x3& MV, Matrix1x3& bufPoint, Matrix1x3& bufPointScreen)
{
	Polygon_t transformPolygon;
	transformPolygon.color = polygon.color;
	int countPoints = polygon.points.size();
	transformPolygon.points.resize(countPoints);

	std::vector<Vector2D> points;
	for (size_t i = 0; i < countPoints; i++)
	{
		bufPoint.SetMatrix(polygon.points[i]);
		transformPolygon.points[i] =  bufPointScreen.GetProductVector(bufPoint, MV);
	}
	return transformPolygon;
}

Vector2D GetCenteCircleTangentToEllipse(float a, float b, float r, Vector2D touchPoint)
{
	// коэффициент наклона касательной к эллипсу в точку touchPoint
	// касательная к эллипсу к канонической ск
	// x*x0/a^2 + y*y0/b^2 = 1
	// y = b^2(1 - x*x0/a^2)/y0
	// y = -(x0*b^2)/(y0*a^2)x + b^2/(y0*a^2)
	Vector2D center;
	if (touchPoint.y != 0)
	{
		float k = -(touchPoint.x * b * b) / (touchPoint.y * a * a);

		// для круга значение k должно совпадать
		// k = -x'/y' в каноничной ск

		// k(y-yc) = -(x-xc)
		// (x-xc)^2 + (y-yc)^2 = r^2

		// r^2 - k^2(y-yc)^2 = (y-yc)^2

		// (y-yc)^2 = r^2/(1+k^2)

		// xc  = x - k(y-yc)
		// yc(1,2) = y +- r / √(1+k^2) 


		float shift = r / sqrtf(1 + k * k);

		if (touchPoint.y < 0)
			center.y = touchPoint.y - shift;
		else
			center.y = touchPoint.y + shift;

		center.x = touchPoint.x + k * (touchPoint.y - center.y);
	}
	else
	{
		center.y = 0;
		if (touchPoint.x > 0)
			center.x = touchPoint.x + r;
		else
			center.x = touchPoint.x - r;
	}

	return center;
}