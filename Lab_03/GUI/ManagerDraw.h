#pragma once
#include <qimage.h>
#include <qlabel.h>
#include "IPainter.h"

class ManagerDraw
{
public:
	ManagerDraw(int w, int h, QLabel* labelColorLine, QLabel* labelColorBackGround);
	~ManagerDraw();

	void ChangePainter(IPainter* newPainter);
	void ClearCanvas();

	void DrawLine(int ax, int ay, int bx, int by);
	void DrawSun(int x, int y, int angleStep, int radius);


	void SetColorLine(QColor color);
	void SetColorBackGround(QColor color);
	void SwapColor();

	QImage GetCanvas() { return canvas; }

	void DrawRect(int x, int y, int w, int h, unsigned int color);

private:
	QImage canvas;
	IPainter* painter;

	QColor colorLine;
	QLabel* labelColorLine;

	QColor colorBackGround;
	QLabel* labelColorBackGround;
};

