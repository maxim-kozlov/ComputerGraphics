#pragma once
#include <QtWidgets/QGraphicsView>
#include "Model.h"
#include "Polygon_t.h"

class Scene
{
public:
	Scene(QGraphicsView* view);

	// нарисовать систему координат
	void DrawCoordinateSystem();

	// нарисовать на сцене модель
	void DrawModel(Model& model);

	// показать сцену на экране
	void ShowScene();

	// очистить сцену
	void ClearScene();

private:
	const static int e_margin = 2;
	QGraphicsView* view;
	QGraphicsScene* scene;
	
	// матрица передвигающая начало в середину экрана
	Matrix3x3 View;

	// нарисовать линию
	void DrawLine(Vector2D& A, Vector2D& B, unsigned int color = 0x000000);

	// нарисовать полигон
	void DrawPolygon(Polygon_t& polygon);

	// изменить размер экрана в соотвествии с QGraphicsView
	void ResizeScene();
};