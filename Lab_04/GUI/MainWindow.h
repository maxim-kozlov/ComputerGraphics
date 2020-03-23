#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "ManagerDraw.h"
#include <QtCharts/QtCharts>

#define COUNT_PAINTERS 5

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);	
	~MainWindow();

private slots:
	void on_pushButtonDrawEllipse_clicked();
	void on_pushButtonDrawSpectrum_clicked();
	void on_pushButtonClear_clicked();

	void on_pushButtonChangeMainColor_clicked();
	void on_pushButtonChangeColorBackGround_clicked();
	void on_pushButtonSwapColor_clicked();

	void on_comboBoxPainters_currentIndexChanged();

	void on_tabWidget_currentChanged();

private:
	void ShowCanvas();
	Ui::MainWindow *ui;
	IPainter* painters[COUNT_PAINTERS];
	ManagerDraw* manager;

	QChartView* chartViewTimeCircle;
	QChartView* chartViewTimeEllipse;

	void InitManagerDraw();
	void InitPainters();
	void InitComboBoxPainters();
};
