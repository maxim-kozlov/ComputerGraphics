#pragma once

#include "Vector2D.h"
#include "Matrix.h"

Vector2D Zoom(Vector2D& A, float kx, float ky);
Vector2D& Flip(Vector2D& A, float h);

void SetViewPort(Matrix& viewPort, Vector2D& shift, float kx, float ky, float h);
Vector2D Scaling(Matrix& viewPort, Vector2D& A);

float GetScaleX(float xMax, float xMin, float w);
float GetScaleY(float yMax, float yMin, float h);

Vector2D GetMaxPoint(Vector2D& A, Vector2D& B, Vector2D& C);
Vector2D GetMinPoint(Vector2D& A, Vector2D& B, Vector2D& C);