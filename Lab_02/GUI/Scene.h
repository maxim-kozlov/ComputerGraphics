#pragma once
#include <QtWidgets/QGraphicsView>
#include "Model.h"
#include "Polygon_t.h"

class Scene
{
public:
	Scene(QGraphicsView* view);

	// ���������� ������� ���������
	void DrawCoordinateSystem();

	// ���������� �� ����� ������
	void DrawModel(Model& model);

	// �������� ����� �� ������
	void ShowScene();

	// �������� �����
	void ClearScene();

private:
	const static int e_margin = 2;
	QGraphicsView* view;
	QGraphicsScene* scene;
	
	// ������� ������������� ������ � �������� ������
	Matrix3x3 View;

	// ���������� �����
	void DrawLine(Vector2D& A, Vector2D& B, unsigned int color = 0x000000);

	// ���������� �������
	void DrawPolygon(Polygon_t& polygon);

	// �������� ������ ������ � ����������� � QGraphicsView
	void ResizeScene();
};