#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "Scene.h"
#include "Model.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

protected:
	virtual void resizeEvent(QResizeEvent*);

private slots:
	void on_pushButtonScale_clicked();
	void on_pushButtonMove_clicked();
	void on_pushButtonRotate_clicked();
	void on_pushButtonCancel_clicked();
	void on_menuhelp_triggered();

private:
	Ui::MainWindow* ui;
	Model model;
	Scene* scene;
};
