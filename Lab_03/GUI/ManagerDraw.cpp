#include "ManagerDraw.h"
#include <qvariant.h>

#define _USE_MATH_DEFINES
#include <math.h>

void SetColorLabel(QLabel* label, QColor color);

ManagerDraw::ManagerDraw(int w, int h, QLabel* labelColorLine, QLabel* labelColorBackGround)
{
	this->canvas = QImage(w, h, QImage::Format_ARGB32);
	this->labelColorLine = labelColorLine;
	this->labelColorBackGround = labelColorBackGround;

	SetColorLine(QColor(0, 0, 0));
	SetColorBackGround(QColor(0xFC, 0xFC, 0xAF));

	this->painter = nullptr;
}

ManagerDraw::~ManagerDraw()
{
	delete painter;
}

void ManagerDraw::ChangePainter(IPainter* newPainter)
{
	if (painter)
		delete painter;
	painter = newPainter;
}

void ManagerDraw::ClearCanvas()
{
	canvas.fill(colorBackGround);
}

void ManagerDraw::DrawLine(int ax, int ay, int bx, int by)
{
	bool correctEnd = painter->DrawLine(canvas, ax, ay, bx, by, colorLine.rgba());
	if (!correctEnd)
		DrawRect(bx - 3, by + 3, 6, 6, 0xFF0000);
}

void ManagerDraw::DrawSun(int x, int y, int angleStep, int radius)
{
	float radStep = angleStep * M_PI / 180;
	int count = 360 / angleStep;
	for (int i = 0; i < count; i++)
	{
		float t = radStep * i;
		float rx = x + radius * cosf(t);
		float ry = y + radius * sinf(t);
		DrawLine(x, y, rx, ry);
	}
}

void ManagerDraw::SetColorLine(QColor color)
{
	colorLine = color;
	SetColorLabel(labelColorLine, color);
}

void ManagerDraw::SetColorBackGround(QColor color)
{
	colorBackGround = color;
	SetColorLabel(labelColorBackGround, color);
}

void ManagerDraw::SwapColor()
{
	QColor temp = colorLine;
	SetColorLine(colorBackGround);
	SetColorBackGround(temp);
}

void ManagerDraw::DrawRect(int x, int y, int w, int h, unsigned int color)
{
	// нижняя сторона квадрата
	painter->DrawLine(canvas, x, y, x + w, y, color);

	// правая сторона
	painter->DrawLine(canvas, x + w, y, x + w, y - h, color);

	// верхняя сторона
	painter->DrawLine(canvas, x + w, y - h, x, y - h, color);

	// левая сторона
	painter->DrawLine(canvas, x, y - h, x, y, color);
}

void SetColorLabel(QLabel* label, QColor color)
{
	QVariant variant = color;
	QString colcode = variant.toString();
	label->setStyleSheet("QLabel { background-color :" + colcode + ";}");
}
