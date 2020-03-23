#include "HelperScale.h"
#include "HelperMath.h"
#include "HelperDraw.h"

void SetShift(Matrix& matrix, float dx, float dy)
{
	matrix.IdentityMatrix();
	matrix.SetValue(2, 0, dx);
	matrix.SetValue(2, 1, dy);
}

void SetScale(Matrix& matrix, float kx, float ky)
{
	matrix.IdentityMatrix();
	matrix.SetValue(0, 0, kx);
	matrix.SetValue(1, 1, ky);
}

Vector2D& Flip(Vector2D& A, float h)
{
	A.SetY(h - A.GetY());
	return A;
}

Vector2D Zoom(Vector2D& A, float kx, float ky)
{
	return Vector2D(A.GetX() * kx, A.GetY() * ky);
}


Vector2D GetMinPoint(Vector2D& A, Vector2D& B, Vector2D& C)
{
	float xmin = GetMinThreeValue(A.GetX(), B.GetX(), C.GetX());
	float ymin = GetMinThreeValue(A.GetY(), B.GetY(), C.GetY());
	return Vector2D(xmin, ymin);
}

Vector2D GetMaxPoint(Vector2D& A, Vector2D& B, Vector2D& C)
{
	float xmax = GetMaxThreeValue(A.GetX(), B.GetX(), C.GetX());
	float ymax = GetMaxThreeValue(A.GetY(), B.GetY(), C.GetY());

	return Vector2D(xmax, ymax);
}

void SetViewPort(Matrix& viewPort, Vector2D& shift,  float kx, float ky, float h)
{
	Matrix transform(3, 3);
	Matrix buf(3, 3);

	SetShift(viewPort, -shift.GetX(), -shift.GetY());
	SetScale(transform, kx, -ky); // масштаб + отражение оси y

	buf.GetProduct(viewPort, transform);
	SetShift(transform, 20, 20 + h);
	viewPort.GetProduct(buf, transform);
}

// shift = minPoint
Vector2D Scaling(Matrix& viewPort, Vector2D& A)
{
	// деконструктор должен сработать перед return 
	Matrix mA(1, 3);
	Matrix AScaling(1, 3);
	

	mA.SetValue(0, 0, A.GetX());
	mA.SetValue(0, 1, A.GetY());
	mA.SetValue(0, 2, 1);

	AScaling.GetProduct(mA, viewPort);

	/*Vector2D margin(MARGIN, MARGIN); // т.к. произошёл flip вверх внизу
	return Flip(Zoom(A - shift, kx, ky), h) + margin;*/
	// проецирования нет => делить не надо
	Vector2D answer(AScaling.GetValue(0, 0), AScaling.GetValue(0, 1));
	
	return answer;
}

float GetScaleX(float xMax, float xMin, float w)
{
	return GetKoef(xMax - xMin, w);
}

float GetScaleY(float yMax, float yMin, float h)
{
	return GetKoef(yMax - yMin, h);
}