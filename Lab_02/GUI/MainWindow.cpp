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

	// ������ ����������� ��������� �������� � doubleSpinBox-��
	SetMaxSpinBox(ui->doubleSpinBoxMoveDx);
	SetMaxSpinBox(ui->doubleSpinBoxMoveDy);
	SetMaxSpinBox(ui->doubleSpinBoxRotateXc);
	SetMaxSpinBox(ui->doubleSpinBoxRotateYc);
	SetMaxSpinBox(ui->doubleSpinBoxScaleKx);
	SetMaxSpinBox(ui->doubleSpinBoxScaleKy);
	SetMaxSpinBox(ui->doubleSpinBoxScaleXm);
	SetMaxSpinBox(ui->doubleSpinBoxScaleYm);

	// ������ ������ �����
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
	// ��� ��������� ������� ������
	// ������������ ������
	Draw(scene, model);
	QMainWindow::resizeEvent(resizeEvent);
}

void MainWindow::on_pushButtonScale_clicked()
{
	// ������� ������
	float kx = ui->doubleSpinBoxScaleKx->value();
	float ky = ui->doubleSpinBoxScaleKy->value();
	float xm = ui->doubleSpinBoxScaleXm->value();
	float ym = ui->doubleSpinBoxScaleYm->value();
	
	// ����������������� ������
	model.Scale(kx, ky, xm, ym);
	
	// ���������� ������
	Draw(scene, model);
}

void MainWindow::on_pushButtonMove_clicked()
{
	// ������� ������
	float dx = ui->doubleSpinBoxMoveDx->value();
	float dy = ui->doubleSpinBoxMoveDy->value();
	
	// ��������� ������
	model.Move(dx, dy);

	// ���������� ������
	Draw(scene, model);
}

void MainWindow::on_pushButtonRotate_clicked()
{
	// ������� ������
	float teta = ui->spinBoxRotateTeta->value();
	float xc = ui->doubleSpinBoxRotateXc->value();
	float yc = ui->doubleSpinBoxRotateYc->value();
	
	// ��������� ������
	model.Rotate(teta, xc, yc);

	// ���������� ������
	Draw(scene, model);
}

void MainWindow::on_pushButtonCancel_clicked()
{
	// ���� �������� ������ ������ �������
	if (model.Cancel())
	{
		// ���������� ������
		Draw(scene, model);
	}
	else
	{
		// ����� ������ ���������
		QMessageBox::warning(this, "Warning", "No more cancellation");
	}
}

void MainWindow::on_menuhelp_triggered()
{
	// ���������-�������
	QMessageBox::information(this, "Help", 
		tr("laboratory #2\n") +
		tr("Draw the image, with the possibility move, scale and rotate."));
}