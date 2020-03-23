#pragma once
#include <qimage.h>
#include <qlabel.h>
#include "IPainter.h"

class ManagerDraw
{
public:
	ManagerDraw(int w, int h, QLabel* labelMainColor, QLabel* labelColorBackGround);
	~ManagerDraw();

	void SetPainter(IPainter* painter);
	void ClearCanvas();

	void DrawEllipse(int x, int y, int a, int b);
	void DrawSpectrum(int x, int y, int a, int b, int dr, int n);


	void SetMainColor(QColor color);
	void SetColorBackGround(QColor color);
	void SwapColor();

	QImage GetCanvas() { return canvas; }

private:
	QImage canvas;
	IPainter* painter;

	QColor mainColor;
	QLabel* labelMainColor;

	QColor colorBackGround;
	QLabel* labelColorBackGround;
};

