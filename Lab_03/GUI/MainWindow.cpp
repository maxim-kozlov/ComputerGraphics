#include "MainWindow.h"
#include "AlgorithmEnum.h"
#include "QtPainter.h"
#include "DDA_Painter.h"
#include "BreshenhamFloat.h"
#include "BreshenhamInt.h"
#include "BreshenhamSmoothing.h"
#include "WooPainter.h"
#include <qdebug.h>
#include <QColorDialog>

#include <QtCharts/QtCharts>
#include <QtCharts/qchartview.h>

#include <qgraphicsscene.h>

#include "ManagerTime.h"
#include "ManagerRungs.h"

using namespace QtCharts;



QColor GetColor(QWidget* parent);

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	auto qsene = new QGraphicsScene(ui->graphicsView);
	ui->graphicsView->setScene(qsene);

	int w = ui->graphicsView->width() - 2;
	int h = ui->graphicsView->height() - 2;
	manager = new ManagerDraw(w, h, ui->labelColorLine, ui->labelColorBackGround);

	ui->comboBoxPainters->clear();
	ui->comboBoxPainters->insertItem(DDA_algorithm, "DDA");
	ui->comboBoxPainters->insertItem(Breshenham_float_algorithm, "Breshenham float");
	ui->comboBoxPainters->insertItem(Breshenham_int_algorithm, "Breshenham int");
	ui->comboBoxPainters->insertItem(Breshenham_smoothing_algorithm, "Breshenham smoothing");
	ui->comboBoxPainters->insertItem(Woo_algorithm, "Woo");
	ui->comboBoxPainters->insertItem(Qt_algorithm, "Qt");

	ui->comboBoxPainters->setCurrentIndex(0);
	manager->ClearCanvas();
	ShowCanvas();

	QChartView* chartViewTime = new QChartView();
	chartViewTime->setRenderHint(QPainter::Antialiasing);
	ui->horizontalLayoutTabTime->addWidget(chartViewTime);

	ManagerTime managerTime(chartViewTime);
	managerTime.ShowTime(500, 0.5);

	QChartView* chartViewRungs = new QChartView();
	chartViewRungs->setRenderHint(QPainter::Antialiasing);
	ui->horizontalLayoutTabRungs->addWidget(chartViewRungs);

	ManagerRungs managerRungs(chartViewRungs);
	managerRungs.ShowRungs(100., 0., 360., 1);
}

MainWindow::~MainWindow()
{
	delete ui->graphicsView->scene();
	delete manager;
}

void MainWindow::ShowCanvas()
{
	auto qscene = ui->graphicsView->scene();
	qscene->clear();
	qscene->addPixmap(QPixmap::fromImage(manager->GetCanvas()));
}

void MainWindow::on_pushButtonDrawLine_clicked()
{
	int ax = ui->spinBoxStartX->value();
	int ay = ui->spinBoxStartY->value();
	int bx = ui->spinBoxEndX->value();
	int by = ui->spinBoxEndY->value();

	manager->DrawLine(ax, ay, bx, by);
	ShowCanvas();
}

void MainWindow::on_pushButtonDrawSun_clicked()
{
	int x = ui->spinBoxSunCenterX->value();
	int y = ui->spinBoxSunCenterY->value();
	int angleStep = ui->spinBoxAngleStep->value();
	int radius = ui->spinBoxSunRadius->value();

	manager->DrawSun(x, y, angleStep, radius);
	ShowCanvas();
}

void MainWindow::on_pushButtonChangeColorLine_clicked()
{
	manager->SetColorLine(GetColor(this));
}

void MainWindow::on_pushButtonChangeColorBackGround_clicked()
{
	manager->SetColorBackGround(GetColor(this));
}

void  MainWindow::on_pushButtonSwapColor_clicked()
{
	manager->SwapColor();
}

void  MainWindow::on_pushButtonClear_clicked()
{
	manager->ClearCanvas();
	ShowCanvas();
}

void MainWindow::on_comboBoxPainters_currentIndexChanged()
{
	AlgorithmEnum index = (AlgorithmEnum)ui->comboBoxPainters->currentIndex();
	IPainter* newPainter = nullptr;
	switch (index)
	{
	case DDA_algorithm:
		newPainter = new DDA_Painter();
		break;
	case Breshenham_float_algorithm:
		newPainter = new BreshenhamFloat();
		break;
	case Breshenham_int_algorithm:
		newPainter = new BreshenhamInt();
		break;
	case Breshenham_smoothing_algorithm:
		newPainter = new BreshenhamSmoothing();
		break;
	case Woo_algorithm:
		newPainter = new WooPainter();
		break;
	case Qt_algorithm:
		newPainter = new QtPainter();
		break;
	}

	manager->ChangePainter(newPainter);
}

QColor GetColor(QWidget* parent)
{
	QColorDialog dialog(parent);
	return dialog.getColor();
}