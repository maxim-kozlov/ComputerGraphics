#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QStandardItemModel.h>
#include "Matrix.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void on_pushButtonAddPoint_clicked();
	void on_pushButtonDeletePoint_clicked();
	void on_pushButtonDeleteAll_clicked();
	void on_pushButtonSearch_clicked();
	void on_helpmenu_triggered();

private:
	Ui::MainWindow* ui;
	QStandardItemModel* table;
	Matrix ViewPort;
};