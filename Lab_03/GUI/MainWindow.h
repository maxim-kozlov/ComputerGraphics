#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "ManagerDraw.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void on_pushButtonDrawLine_clicked();
	void on_pushButtonChangeColorLine_clicked();
	void on_pushButtonChangeColorBackGround_clicked();
	void on_pushButtonSwapColor_clicked();
	void on_pushButtonClear_clicked();
	void on_pushButtonDrawSun_clicked();

	void on_comboBoxPainters_currentIndexChanged();

private:
	void ShowCanvas();	

	Ui::MainWindow* ui;
	ManagerDraw* manager;
};
