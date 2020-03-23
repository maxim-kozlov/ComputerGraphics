#include "pch.h"
#include "Ellipse_t.h"
#include "HelperMath.h"

#define _USE_MATH_DEFINES
#include <math.h>

Ellipse_t::Ellipse_t(float h, float w, Vector2D center, float angle, unsigned int color): center(center)
{
	this->h = h;
	this->w = w;
	this->angle = angle;
	this->color = color;
}

Polygon_t Ellipse_t::GetPolygon()
{
	Polygon_t ellipse;

	Matrix1x3 bufPoint;
	Matrix1x3 bufPointScreen;
	Matrix3x3 Buf;
	Matrix3x3 Transform;
	Matrix3x3 Model;

	Buf.SetRotate(angle);
	Transform.SetMove(center.x, center.y);
	Model.GetProduct(Buf, Transform);

	ellipse.color = color;

	// кривизна кривой 1/ R = K = lim da/ds
	// ds - смещение вдоль дуги кривой
	// da - изменение угла наклона касательной

	// K = |x'*y'' - y'*x''| / (x'^2 + y'^2)^(3/2)

	// x = cos(t)
	// y = sin(t)

	// K = ab/(a^2*sin^2(t) + b^2*cos^2(t))^(3/2)

	// в вершинах t = 0 K = a/b^2
	// t = pi/2 K = b/a^2

	float t = 0;
	float a = w / 2;
	float b = h / 2;

	float step = a > b ? b / (a * a) : a / (b * b); //0.1;
	step *= 2;
	int count = 2 * M_PI / step;

	for (size_t i = 0; i < count; i++)
	{
		t = step * i;
		Vector2D A(a * cosf(t), b * sinf(t));
		bufPoint.SetMatrix(A);
		Vector2D B = bufPointScreen.GetProductVector(bufPoint, Model);

		ellipse.points.push_back(B);
	}

	return ellipse;
}