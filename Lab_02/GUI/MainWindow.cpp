#include "MainWindow.h"
#include <qmessagebox.h>
#include <vector>
#include "Bird.h"
#include "HelperMath.h"

void SetMaxSpinBox(QDoubleSpinBox* doubleSpinBox)
{
	doubleSpinBox->setMinimum(-GetMaxFloat());
	doubleSpinBox->setMaximum(GetMaxFloat());
}

void Draw(Scene* scene, Model& model)
{
	scene->ClearScene();
	scene->DrawCoordinateSystem();
	scene->DrawModel(model);
	scene->ShowScene();
}

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// задать максимально возможное значения в doubleSpinBox-ах
	SetMaxSpinBox(ui->doubleSpinBoxMoveDx);
	SetMaxSpinBox(ui->doubleSpinBoxMoveDy);
	SetMaxSpinBox(ui->doubleSpinBoxRotateXc);
	SetMaxSpinBox(ui->doubleSpinBoxRotateYc);
	SetMaxSpinBox(ui->doubleSpinBoxScaleKx);
	SetMaxSpinBox(ui->doubleSpinBoxScaleKy);
	SetMaxSpinBox(ui->doubleSpinBoxScaleXm);
	SetMaxSpinBox(ui->doubleSpinBoxScaleYm);

	// задать модель птицы
	SetBird(model);

	scene = new Scene(ui->graphicsView);
}

MainWindow::~MainWindow()
{
	delete ui;
	delete scene;
}

void MainWindow::resizeEvent(QResizeEvent* resizeEvent)
{
	// при изменение размера экрана
	// перерисовать модель
	Draw(scene, model);
	QMainWindow::resizeEvent(resizeEvent);
}

void MainWindow::on_pushButtonScale_clicked()
{
	// считать данные
	float kx = ui->doubleSpinBoxScaleKx->value();
	float ky = ui->doubleSpinBoxScaleKy->value();
	float xm = ui->doubleSpinBoxScaleXm->value();
	float ym = ui->doubleSpinBoxScaleYm->value();
	
	// промасштабировать модель
	model.Scale(kx, ky, xm, ym);
	
	// нарисовать модель
	Draw(scene, model);
}

void MainWindow::on_pushButtonMove_clicked()
{
	// считать данные
	float dx = ui->doubleSpinBoxMoveDx->value();
	float dy = ui->doubleSpinBoxMoveDy->value();
	
	// перенести модель
	model.Move(dx, dy);

	// нарисовать модель
	Draw(scene, model);
}

void MainWindow::on_pushButtonRotate_clicked()
{
	// считать данные
	float teta = ui->spinBoxRotateTeta->value();
	float xc = ui->doubleSpinBoxRotateXc->value();
	float yc = ui->doubleSpinBoxRotateYc->value();
	
	// повернуть модель
	model.Rotate(teta, xc, yc);

	// нарисовать модель
	Draw(scene, model);
}

void MainWindow::on_pushButtonCancel_clicked()
{
	// если операция отмены прошла успешно
	if (model.Cancel())
	{
		// нарисовать модель
		Draw(scene, model);
	}
	else
	{
		// иначе выдать сообщение
		QMessageBox::warning(this, "Warning", "No more cancellation");
	}
}

void MainWindow::on_menuhelp_triggered()
{
	// сообщение-справка
	QMessageBox::information(this, "Help", 
		tr("laboratory #2\n") +
		tr("Draw the image, with the possibility move, scale and rotate."));
}