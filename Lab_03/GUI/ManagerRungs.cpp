#include "ManagerRungs.h"

#define _USE_MATH_DEFINES
#include <math.h>]

ManagerRungs::ManagerRungs(QChartView* chartView)
{
	view = chartView;

	QChart* chart = new QChart();
	chart->setTitle("Rungs analyze");
	// chart->setAnimationOptions(QChart::SeriesAnimations);

	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	view->setChart(chart);
}

void ManagerRungs::ShowRungs(float R, float startAngle, float endAngle, float step)
{
	const int len = 5;
	IDeterminateRungs** painters = new IDeterminateRungs * [len];
	painters[0] = new DDA_Painter();
	painters[1] = new BreshenhamFloat();
	painters[2] = new BreshenhamInt();
	painters[3] = new BreshenhamSmoothing();
	painters[4] = new WooPainter();
	// painters[5] = new QtPainter();

	auto chart = view->chart();
	chart->series().clear();

	QValueAxis* axisX = new QValueAxis;
	axisX->setTickCount(10);
	axisX->setLabelFormat("%.0f");
	axisX->setTitleText("angle");
	chart->addAxis(axisX, Qt::AlignBottom);
	

	QValueAxis* axisY = new QValueAxis;
	axisY->setLabelFormat("%i");
	axisY->setTitleText("Rungs (lenght line = " + QString::number(R) + ")");
	chart->addAxis(axisY, Qt::AlignLeft);
	
	QString names[] = { "DDA", "Breshenham\nFloat", "Breshenham\nInt", "Breshenham\nSmoothing", "Woo" };

	for (size_t i = 0; i < len; i++)
	{
		QLineSeries* series = new QLineSeries();
		for (float t = startAngle; t <= endAngle; t += step)
		{
			float rx = R * cosf(t * M_PI / 180);
			float ry = R * sinf(t * M_PI / 180);
			int c = painters[i]->GetCountStep(0, 0, rx, ry);
			series->append(t, c);
		}
		chart->addSeries(series);
		series->setName(names[i]);
		series->attachAxis(axisX);
		series->attachAxis(axisY);
	}

	delete[] painters;
}