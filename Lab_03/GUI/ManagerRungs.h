#pragma once
#include "IDeterminateRungs.h"
#include "QtPainter.h"
#include "DDA_Painter.h"
#include "BreshenhamFloat.h"
#include "BreshenhamInt.h"
#include "BreshenhamSmoothing.h"
#include "WooPainter.h"
#include <QtCharts/QtCharts>

class ManagerRungs
{
public:
	ManagerRungs(QChartView* chartView);
	void ShowRungs(float R = 200, float startAngle = 0, float endAngle = 90, float step = 0.1);

private:
	QChartView* view;
};

