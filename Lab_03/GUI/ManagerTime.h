#pragma once
#include "IDeterminateTime.h"
#include "QtPainter.h"
#include "DDA_Painter.h"
#include "BreshenhamFloat.h"
#include "BreshenhamInt.h"
#include "BreshenhamSmoothing.h"
#include "WooPainter.h"
#include <QtCharts/QtCharts>

class ManagerTime
{
public:
	ManagerTime(QChartView* chartView);
	void ShowTime(float R = 200., float angle = 1.);

private:
	QChartView* view;
};

