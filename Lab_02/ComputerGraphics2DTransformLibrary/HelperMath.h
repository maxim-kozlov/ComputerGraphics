#pragma once
#include "pch.h"
#include "Polygon_t.h"
#include "Matrix1x3.h"
#include "Matrix3x3.h"

extern "C" CG_2D_TRANSFORM_LIBRARY_API float GetRadians(float degree);

extern "C" CG_2D_TRANSFORM_LIBRARY_API float GetDegrees(float radians);

// получить максимальное значение float
extern "C" CG_2D_TRANSFORM_LIBRARY_API float GetMaxFloat();


extern "C" CG_2D_TRANSFORM_LIBRARY_API Polygon_t GetTransformPolygon(Polygon_t& polygon, 
	Matrix3x3& MV, Matrix1x3& bufPoint, Matrix1x3& bufPointScreen);


// получить координаты центра окружности касающейся внешним образом эллипса.
// эллипс расположен в канонической системе координат
extern "C" CG_2D_TRANSFORM_LIBRARY_API Vector2D GetCenteCircleTangentToEllipse(float a, float b, float r, Vector2D touchPoint);