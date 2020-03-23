#pragma once
#include "pch.h"
#include <vector>
#include "Ellipse_t.h"
#include "Polygon_t.h"

#include "Memento.h"

class CG_2D_TRANSFORM_LIBRARY_API Model
{
public:
	Model();

	std::vector<Polygon_t> polygons;
	
	Matrix3x3& GetMatrixModel();

	// повернуть модель на angle в градусах
	// относительно точки (xc, yc)
	void Rotate(float angleDegree, float xc = 0, float yc = 0);

	// произвести маштабирование (kx, ky)
	// относительно точки (xm, ym)
	void Scale(float kx, float ky, float xm = 0, float ym = 0);

	// произвести перенос на (dx, dy)
	void Move(float dx, float dy);

	// отменить действие
	// return - произошло ли отменение операции
	bool Cancel();
private:
	// буфферные матрицы
	Matrix3x3 Buffer;
	Matrix3x3 BufferTransform;

	// матрица модели
	Matrix3x3 MatrixModel;

	// хранитель состояний
	Memento memento;
};

