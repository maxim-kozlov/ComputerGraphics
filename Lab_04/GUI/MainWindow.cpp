#include "MainWindow.h"
#include <QColorDialog>
#include "QtPainter.h"
#include "Canonical.h"
#include "Parametric.h"
#include "Breshenham.h"
#include "MiddleDot.h"

#include "ManagerTime.h"

QColor GetColor(QWidget* parent);

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	InitManagerDraw();

	InitPainters();
	InitComboBoxPainters();

	chartViewTimeCircle = new QChartView();
	chartViewTimeCircle->setRenderHint(QPainter::Antialiasing);
	ui->horizontalLayoutTabTimeCircle->addWidget(chartViewTimeCircle);

	chartViewTimeEllipse = new QChartView();
	chartViewTimeEllipse->setRenderHint(QPainter::Antialiasing);
	ui->horizontalLayoutTimeEllipse->addWidget(chartViewTimeEllipse);

	ManagerTime managerTimeCircle(chartViewTimeCircle);
	managerTimeCircle.ShowTimeCircle(10, 1000, 50, 10);

	ManagerTime managerTimeEllipse(chartViewTimeEllipse);
	managerTimeEllipse.ShowTimeEllipse(10, 5, 1000, 50, 10);

	manager->ClearCanvas();
	ShowCanvas();
}

MainWindow::~MainWindow()
{
	delete ui->graphicsView->scene();
	delete manager;
	for (size_t i = 0; i < COUNT_PAINTERS; i++)
		delete painters[i];
}

void MainWindow::InitManagerDraw()
{
	auto qsene = new QGraphicsScene(ui->graphicsView);
	ui->graphicsView->setScene(qsene);

	int w = ui->graphicsView->width() - 2;
	int h = ui->graphicsView->height() - 2;
	manager = new ManagerDraw(w, h, ui->labelMainColor, ui->labelColorBackGround);
}

void MainWindow::InitPainters()
{
	painters[0] = new Canonical();
	painters[1] = new Parametric();
	painters[2] = new Breshenham();
	painters[3] = new MiddleDot();
	painters[4] = new QtPainter();
}

void MainWindow::InitComboBoxPainters()
{
	ui->comboBoxPainters->clear();
	for (size_t i = 0; i < COUNT_PAINTERS; i++)
		ui->comboBoxPainters->addItem(painters[i]->GetName());
	ui->comboBoxPainters->setCurrentIndex(0);
}

void MainWindow::ShowCanvas()
{
	auto qscene = ui->graphicsView->scene();
	qscene->clear();
	qscene->addPixmap(QPixmap::fromImage(manager->GetCanvas()));
}

void MainWindow::on_pushButtonDrawEllipse_clicked()
{
	int x = ui->spinBoxCenterX->value();
	int y = ui->spinBoxCenterY->value();
	int a = ui->spinBoxEllipseA->value();
	int b = ui->spinBoxEllipseB->value();

	manager->DrawEllipse(x, y, a, b);
	ShowCanvas();
}

void MainWindow::on_pushButtonDrawSpectrum_clicked()
{
	float dr = ui->spinBoxSpectrumDR->value();
	int n = ui->spinBoxSpectrumN->value();
	float a = ui->spinBoxSpectrumA->value();
	float b = ui->spinBoxSpectrumB->value();

	float x = ui->graphicsView->width() / 2. - 1;
	float y = ui->graphicsView->height() / 2. - 1;

	manager->DrawSpectrum(x, y, a, b, dr, n);
	ShowCanvas();
}

void MainWindow::on_pushButtonChangeMainColor_clicked()
{
	manager->SetMainColor(GetColor(this));
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
	int i = ui->comboBoxPainters->currentIndex();
	manager->SetPainter(painters[i]);
}

void MainWindow::on_tabWidget_currentChanged()
{
	/*int i = ui->tabWidget->currentIndex();
	if (i == 1)
	{
		ManagerTime managerTime(chartViewTimeCircle);
		managerTime.ShowTimeCircle(1, 500, 10, 100);
	}
	else if (i == 2)
	{
		ManagerTime managerTime(chartViewTimeEllipse);
		managerTime.ShowTimeEllipse();
	}*/
}

QColor GetColor(QWidget* parent)
{
	QColorDialog dialog(parent);
	return dialog.getColor();
}