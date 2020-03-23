#include "ManagerTime.h"
#include "AlgorithmEnum.h"
#include <time.h> 

#define _USE_MATH_DEFINES
#include <math.h>


ManagerTime::ManagerTime(QChartView* chartView)
{
	this->view = chartView;

	QChart* chart = new QChart();
	chart->setTitle("Time analyze");
	chart->setAnimationOptions(QChart::SeriesAnimations);

	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	view->setChart(chart);
}

void ManagerTime::ShowTime(float R, float angle)
{
	const int len = 5;
	IDeterminateTime** painters = new IDeterminateTime * [len];
	painters[0] = new DDA_Painter();
	painters[1] = new BreshenhamFloat();
	painters[2] = new BreshenhamInt();
	painters[3] = new BreshenhamSmoothing();
	painters[4] = new WooPainter();
	// painters[5] = new QtPainter();
	QImage image(2 * R, 2 * R, QImage::Format_ARGB32);

	float time[len] = { 0 };

	float radStep = angle * M_PI / 180;

	int N = 10;
	int count = N * 360 / angle;
	for (size_t i = 0; i < len; i++)
	{
		for (int j = 0; j < count * N; j++)
		{
			float t = radStep * j;
			float rx = 500 + R * cosf(t);
			float ry = 500 + R * sinf(t);
			float fTimeStart = clock();
			painters[i]->TestDrawLine(image, 500, 500, rx, ry);
			float fTimeStop = clock();

			time[i] += fTimeStop - fTimeStart;
		}
		time[i] /= count;
		// time[i] /= CLOCKS_PER_SEC;
	}
	auto chart = view->chart();
	chart->series().clear();

	QValueAxis* axisY = new QValueAxis;
	axisY->setLabelFormat("%.4f ms");
	axisY->setTitleText("Time (lenght line = " + QString::number(R) + ")");

	QString names[] = { "DDA", "Breshenham\nnFloat", "Breshenham\nInt", "Breshenham\nSmoothing", "Woo" };

	QBarSeries* series = new QBarSeries();
	for (size_t i = 0; i < len; i++)
	{
		QBarSet* set = new QBarSet(names[i]);
		*set << time[i];
		series->append(set);
	}
	
	chart->addSeries(series);
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);
	
	

	// chart->createDefaultAxes();
	
	delete[] painters;
}

