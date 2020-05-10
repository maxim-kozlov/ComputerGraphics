#include "ManagerTime.h"
#include <time.h> 

#include <qdebug.h>
#include <vector>

#include "Canonical.h"
#include "Parametric.h"
#include "Breshenham.h"
#include "MiddleDot.h"

#define COUNT_TEST_PAINTERS 4

#define WINDOW_WIDTH 5

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

double running_average(double a, double b, double k)
{
	return a * (1 - k) + b * k;
}

double middle_of_3(double a, double b, double c)
{
	double middle;
	if ((a <= b) && (a <= c)) 
	{
		middle = (b <= c) ? b : c;
	}
	else 
	{
		if ((b <= a) && (b <= c))
			middle = (a <= c) ? a : c;
		else
			middle = (a <= b) ? a : b;
	}
	return middle;
}

double getAverage(std::vector<double> mass, int i, int N)
{
	double sum = 0;
	for (int j = - N / 2; j < N / 2; j++)
		sum += mass[i + j];
	return sum / N;
}

double GetTimeCircle(IDeterminateTime* painter, QImage& image, int r, int countRepetitions)
{
	double time = 0;
	double fTimeStart, fTimeStop;

	int n = 0;
	for (int j = 0; j < countRepetitions && time < 10; j++)
	{
		fTimeStart = clock();
		painter->TestDrawCicrle(image, r, r, r);
		fTimeStop = clock();

		time += fTimeStop - fTimeStart;
		n++;
	}
	time /= n;
	return time;
}

double GetTimeEllipse(IDeterminateTime* painter, QImage& image, int a, int b, int countRepetitions)
{
	double time = 0;
	double fTimeStart, fTimeStop;
	int n = 0;
	for (int j = 0; j < countRepetitions && time < 10; j++)
	{
		fTimeStart = clock();
		painter->TestDrawEllipse(image, a, b, a, b);
		fTimeStop = clock();

		time += fTimeStop - fTimeStart;
		n++;
	}
	time /= n;
	return time;
}

void ManagerTime::ShowTimeCircle(int rStart, int dr, int n, int countRepetitions)
{
	IDeterminateTime** painters = new IDeterminateTime*[COUNT_TEST_PAINTERS];
	painters[0] = new Canonical();
	painters[1] = new Parametric();
	painters[2] = new Breshenham();
	painters[3] = new MiddleDot();

	int rEnd = rStart + dr * (n - 1);
	QImage image(2 * rEnd, 2 * rEnd, QImage::Format_ARGB32);

	auto chart = view->chart();
	chart->series().clear();

	QValueAxis* axisX = new QValueAxis;
	axisX->setLabelFormat("%d");
	axisX->setTitleText("R");
	chart->addAxis(axisX, Qt::AlignBottom);


	QValueAxis* axisY = new QValueAxis;
	axisY->setLabelFormat("%.4f ms");
	axisY->setTitleText("Time");
	chart->addAxis(axisY, Qt::AlignLeft);

	std::vector<double> massTime(n);
	// COUNT_TEST_PAINTERS
	srand(time(NULL));
	for (size_t i = 0; i < COUNT_TEST_PAINTERS; i++)
	{
		for (int r = rStart, k = 0; k < n; k++, r += dr)
			massTime[k] = GetTimeCircle(painters[i], image, r, countRepetitions);

		for (size_t k = 2; k < n; k++)
			massTime[k - 2] = middle_of_3(massTime[k - 2], massTime[k - 1], massTime[k]);
		
		for (size_t k = 1; k < n; k++)
			massTime[k - 1] = running_average(massTime[k - 1], massTime[k], 0.1);
		
		for (size_t k = 1; k < n - 1; k++)
			massTime[k] = getAverage(massTime, k, 3);


		QLineSeries* filterSeries = new QLineSeries();
		for (int r = rStart, k = 0; k < n; k++, r += dr)
			filterSeries->append(r, massTime[k]);

		chart->addSeries(filterSeries);
		filterSeries->setName(painters[i]->GetName());
		filterSeries->attachAxis(axisX);
		filterSeries->attachAxis(axisY);
	}

	delete[] painters;
}

void ManagerTime::ShowTimeEllipse(int a, int b, int dr, int n, int countRepetitions)
{
	IDeterminateTime** painters = new IDeterminateTime * [COUNT_TEST_PAINTERS];
	painters[0] = new Canonical();
	painters[1] = new Parametric();
	painters[2] = new Breshenham();
	painters[3] = new MiddleDot();

	QImage image(2 * (a + dr * n), 2 * (b + dr * n), QImage::Format_ARGB32);

	auto chart = view->chart();
	chart->series().clear();

	QValueAxis* axisX = new QValueAxis;
	axisX->setLabelFormat("%d");
	axisX->setTitleText("a");
	chart->addAxis(axisX, Qt::AlignBottom);


	QValueAxis* axisY = new QValueAxis;
	axisY->setLabelFormat("%.4f ms");
	axisY->setTitleText("Time");
	chart->addAxis(axisY, Qt::AlignLeft);

	std::vector<double> massTime(n);
	// COUNT_TEST_PAINTERS
	srand(time(NULL));
	for (size_t i = 0; i < COUNT_TEST_PAINTERS; i++)
	{
		int ta = a, tb = b;
		for (int k = 0; k < n; k++)
		{
			massTime[k] = GetTimeEllipse(painters[i], image, ta, tb, countRepetitions);
			ta += dr;
			tb += dr;
		}
		
		for (size_t k = 2; k < n; k++)
			massTime[k - 2] = middle_of_3(massTime[k - 2], massTime[k - 1], massTime[k]);

		for (size_t k = 1; k < n; k++)
			massTime[k - 1] = running_average(massTime[k - 1], massTime[k], 0.1);

		for (size_t k = 1; k < n - 1; k++)
			massTime[k] = getAverage(massTime, k, 3);
		

		QLineSeries* filterSeries = new QLineSeries();
		ta = a, tb = b;
		for (int k = 0; k < n; k++)
		{
			filterSeries->append(ta, massTime[k]);
			ta += dr;
			tb += dr;
		}
			
		chart->addSeries(filterSeries);
		filterSeries->setName(painters[i]->GetName());
		filterSeries->attachAxis(axisX);
		filterSeries->attachAxis(axisY);
	}

	delete[] painters;
}