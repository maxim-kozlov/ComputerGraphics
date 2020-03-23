#include "HelperDraw.h"
#include <limits>
#define max(a, b) max()

QGraphicsScene* CreateScene(QGraphicsView* view)
{
	QGraphicsScene* scene = new QGraphicsScene(view);
	if (scene)
		scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(view->width() - E_MARGIN, view->height() - E_MARGIN)));
	return scene;
}

void SetScene(QGraphicsView* view, QGraphicsScene* scene)
{
	delete view->scene();
	view->setScene(scene);
}


float GetHeightScene(QGraphicsScene* scene)
{
	return scene->height() - E_MARGIN;
}

float GetWidthScene(QGraphicsScene* scene)
{
	return scene->width() - E_MARGIN;
}


void WriteText(QGraphicsScene* scene, QString text, QPoint pos)
{
	QGraphicsTextItem* textItem = scene->addText(text);
	textItem->setPos(pos);
}

void WritePoint(QGraphicsScene* scene, Vector2D& point, Vector2D& pos, float w)
{
	QString str = ConvertStringToQString(point.ToString());
	QPoint position((int)pos.GetX(), (int)pos.GetY());
	int lenStr = str.length();
	w -= MARGIN;
	if (position.x() + lenStr > w)
	{
		position.setX(w - 5 * lenStr);
	}
	WriteText(scene, str, position);
}

QString ConvertStringToQString(std::string str)
{
	return QString(str.c_str());
}


void DrawLine(QGraphicsScene* scene, Vector2D& A, Vector2D& B, unsigned int color)
{
	scene->addLine(A.GetX(), A.GetY(), B.GetX(), B.GetY(), QPen(color));
}

void DrawTriangle(QGraphicsScene* scene, Vector2D& A, Vector2D& B, Vector2D& C, unsigned int color)
{
	DrawLine(scene, A, B, color);
	DrawLine(scene, B, C, color);
	DrawLine(scene, C, A, color);
}


void SetMaximumPossibleValuesSpinBox(QDoubleSpinBox* spinBox)
{
	spinBox->setMinimum(-std::numeric_limits<float>::max());
	spinBox->setMaximum(std::numeric_limits<float>::max());
}