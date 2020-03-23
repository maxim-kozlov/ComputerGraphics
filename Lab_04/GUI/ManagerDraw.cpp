#include "ManagerDraw.h"
#include <qvariant.h>

#define _USE_MATH_DEFINES
#include <math.h>

void SetColorLabel(QLabel* label, QColor color);

ManagerDraw::ManagerDraw(int w, int h, QLabel* labelMainColor, QLabel* labelColorBackGround)
{
	this->canvas = QImage(w, h, QImage::Format_ARGB32);
	this->labelMainColor = labelMainColor;
	this->labelColorBackGround = labelColorBackGround;

	SetMainColor(QColor(0, 0, 0));
	SetColorBackGround(QColor(0xFF, 0xFF, 0xFF)); // QColor(0xFC, 0xFC, 0xAF)

	this->painter = nullptr;
}

ManagerDraw::~ManagerDraw()
{
	
}

void ManagerDraw::SetPainter(IPainter* painter)
{
	this->painter = painter;
}

void ManagerDraw::ClearCanvas()
{
	canvas.fill(colorBackGround);
}

void ManagerDraw::DrawEllipse(int x, int y, int a, int b)
{
	if (a == b)
		painter->DrawCicrle(canvas, x, y, a, mainColor.rgba());
	else
		painter->DrawEllipse(canvas, x, y, a, b, mainColor.rgba());
}

void ManagerDraw::DrawSpectrum(int x, int y, int a, int b, int dr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		DrawEllipse(x, y, a + dr * i, b + dr * i);
	}
}

void ManagerDraw::SetMainColor(QColor color)
{
	mainColor = color;
	SetColorLabel(labelMainColor, color);
}

void ManagerDraw::SetColorBackGround(QColor color)
{
	colorBackGround = color;
	SetColorLabel(labelColorBackGround, color);
}

void ManagerDraw::SwapColor()
{
	QColor temp = mainColor;
	SetMainColor(colorBackGround);
	SetColorBackGround(temp);
}

void SetColorLabel(QLabel* label, QColor color)
{
	QVariant variant = color;
	QString colcode = variant.toString();
	label->setStyleSheet("QLabel { background-color :" + colcode + ";}");
}
