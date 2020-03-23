#include "Scene.h"
#include <qgraphicsitem.h>
#include "HelperMath.h"
#include "Matrix.h"
#include "Matrix1x3.h"

Scene::Scene(QGraphicsView* view)
{
	this->view = view;
	scene = new QGraphicsScene(view);
	ResizeScene();
}

void Scene::DrawCoordinateSystem()
{
	int w_2 = scene->width() / 2;
	int h_2 = scene->height() / 2;
	
	scene->addLine(2 * w_2 - 20, h_2 - 5, 2 * w_2, h_2);
	scene->addLine(0, h_2, 2 * w_2, h_2);
	scene->addLine(2 * w_2 - 20, h_2 + 5, 2 * w_2, h_2);

	scene->addLine(w_2, 0, w_2 - 5, 20);
	scene->addLine(w_2, 0, w_2, 2 * h_2);
	scene->addLine(w_2, 0, w_2 + 5, 20);
}
	
void Scene::ShowScene()
{
	view->setScene(scene);
}

void Scene::ClearScene()
{
	delete view->scene();
	scene = new QGraphicsScene(view);
	ResizeScene();
}

void Scene::ResizeScene()
{
	scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(view->width() - e_margin, view->height() - e_margin)));
	int w_2 = scene->width() / 2;
	int h_2 = scene->height() / 2;
	
	Matrix3x3 Buf;
	Matrix3x3 Transform;

	Buf.SetScale(1, -1);
	Transform.SetMove(w_2, h_2);
	View.GetProduct(Buf, Transform);
}


// нарисовать линию
void Scene::DrawLine(Vector2D& A, Vector2D& B, unsigned int color)
{
	scene->addLine(A.x, A.y, B.x, B.y, QPen(color));
}


// нарисовать многоугольник
void Scene::DrawPolygon(Polygon_t& polygon)
{
	int n = polygon.points.size() - 1;
	for (size_t i = 0; i < n; i++)
		DrawLine(polygon.points[i], polygon.points[i + 1], polygon.color);

	// если n = 1, то многоугольник является прямой
	// иначе замкнуть
	if (n > 1)
		DrawLine(polygon.points[0], polygon.points[n], polygon.color);
}

void Scene::DrawModel(Model& model)
{
	// итоговая матрица преобразований
	Matrix3x3 MV;
	MV.GetProduct(model.GetMatrixModel(), View);

	Matrix1x3 bufPointScreen;
	Matrix1x3 bufPoint;
	
	for (size_t i = 0; i < model.polygons.size(); i++)
	{
		// умножить каждую точку полигона на матрицу преобразований
		// получить преобразованный полигон
		Polygon_t transformPolygon = GetTransformPolygon(model.polygons[i], MV, bufPoint, bufPointScreen);
		DrawPolygon(transformPolygon);
	}
}