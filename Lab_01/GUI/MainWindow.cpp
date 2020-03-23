#include "MainWindow.h"
#include <qmessagebox.h>
#include "HelperDraw.h"
#include "HelperScale.h"
#include "Logic.h"

void ShowAnswer(QWidget* parent, QString A, QString B, QString C, float lenMedian);

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow), ViewPort(3, 3)
{
	ui->setupUi(this);

	table = new QStandardItemModel(0, 2, this);
	ui->tableView->setModel(table);
	table->setHeaderData(0, Qt::Horizontal, "X");
	table->setHeaderData(1, Qt::Horizontal, "Y");
	
	SetMaximumPossibleValuesSpinBox(ui->doubleSpinBoxX);
	SetMaximumPossibleValuesSpinBox(ui->doubleSpinBoxY);

	QAction* help = new QAction(tr("help"), this);
	help->setShortcut(tr("F1"));
	connect(help, SIGNAL(triggered()), this, SLOT(on_helpmenu_triggered()));
	ui->menuhelp->addAction(help);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButtonAddPoint_clicked()
{
	Vector2D newPoint;
	newPoint.SetX(ui->doubleSpinBoxX->value());
	newPoint.SetY(ui->doubleSpinBoxY->value());
	AppendPointToTable(table, newPoint);
}

void MainWindow::on_pushButtonDeletePoint_clicked()
{
	int indexRow = ui->spinBoxId->value() - 1;
	if (!DeletePointFromTable(table, indexRow))
		QMessageBox::critical(this, "Error", "Point with given id doesn`t exist");
}

void MainWindow::on_pushButtonDeleteAll_clicked()
{
	if  (!DeleteAllPointFromTable(table))
		QMessageBox::warning(this, "Warning", "Points have already been deleted");
}

void MainWindow::on_helpmenu_triggered()
{
	QMessageBox::information(this, "Inforamation", GetInfoAboutProgram());
}

void MainWindow::on_pushButtonSearch_clicked()
{
	int code_error = 0;
	
	std::vector<Vector2D> points = GetPointsFromTable(table, code_error);

	Vector2D A, B, C, M, P;
	if (!code_error)
		code_error = GetAnswer(points, A, B, C, M, P);
	QGraphicsScene* scene = CreateScene(ui->graphicsView);

	if (!code_error)
	{	
		Vector2D Pmin = GetMinPoint(A, B, C);
		Vector2D Pmax = GetMaxPoint(A, B, C);

		float h = GetHeightScene(scene) - 2*MARGIN;
		float w = GetWidthScene(scene) - 2*MARGIN;

		float kx = GetScaleX(Pmax.GetX(), Pmin.GetX(), w);
		float ky = GetScaleX(Pmax.GetY(), Pmin.GetY(), h);

		SetViewPort(ViewPort, Pmin, kx, ky, h);

		Vector2D Ascreen = Scaling(ViewPort, A);
		Vector2D Bscreen = Scaling(ViewPort, B);
		Vector2D Cscreen = Scaling(ViewPort, C);

		DrawTriangle(scene, Ascreen, Bscreen, Cscreen, 0x00FF00);
		WritePoint(scene, A, Ascreen, w);
		WritePoint(scene, B, Bscreen, w);
		WritePoint(scene, C, Cscreen, w);


		Vector2D Pscreen = Scaling(ViewPort, P);
		Vector2D Mscreen = Scaling(ViewPort, M);
		DrawLine(scene, Pscreen, Mscreen, 0xFF0000);
		WritePoint(scene, M, Mscreen, w);	
	}

	SetScene(ui->graphicsView, scene);

	if (!code_error)
	{
		ShowAnswer(this, ConvertStringToQString(A.ToString()),
						 ConvertStringToQString(B.ToString()),
						 ConvertStringToQString(C.ToString()),
						 (M - P).GetLenght());
	}
	if (code_error == INCORRECT_INPUT)
		QMessageBox::critical(this, "Error", "Incorrect points");
	if (code_error == FIND_DEGENERATE_TRIANGLE)
		QMessageBox::warning(this, "Error", "The answer is a degenerate triangle");
	if (code_error == NOT_ENOUGH_POINT)
		QMessageBox::critical(this, "Error", "Not enough points");
}

void ShowAnswer(QWidget* parent, QString A, QString B, QString C, float lenMedian)
{
	QMessageBox::information(parent, "Answer", "The desired triangle is built on points " + \
		A + " " + B + " " + C + ".\n" + \
		"It has a minimal lenght median = " + QString::number(lenMedian, 'g', 3) + \
		" among all possible triangles with vertices at the points of the set.");
}
