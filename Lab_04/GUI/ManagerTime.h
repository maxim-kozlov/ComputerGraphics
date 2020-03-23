#pragma once
#include "IDeterminateTime.h"
#include <QtCharts/QtCharts>

class ManagerTime
{
public:
	ManagerTime(QChartView* chartView);
	void ShowTimeCircle(int rStart, int dr, int n, int countRepetitions);
	void ShowTimeEllipse(int a, int b, int dr, int n, int countRepetitions);
private:
	QChartView* view;
};

