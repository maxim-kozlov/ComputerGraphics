#include "Logic.h"
#include <QFile>

void AppendPointToTable(QStandardItemModel* table, Vector2D& point)
{
	QList<QStandardItem*> row;
	row.append(new QStandardItem(QString::number(point.GetX())));
	row.append(new QStandardItem(QString::number(point.GetY())));
	table->appendRow(row);
}

bool DeletePointFromTable(QStandardItemModel* table, int indexRow)
{
	bool ok = indexRow >= 0 && indexRow < table->rowCount();
	if (ok)
		table->removeRow(indexRow);
	return ok;
}

bool DeleteAllPointFromTable(QStandardItemModel* table)
{
	int n = table->rowCount();
	bool ok = n > 0;

	for (int i = n - 1; i >= 0; i--)
		table->removeRow(i);

	return ok;
}

QString GetInfoAboutProgram()
{
	QString help = "Lab_01";

	QFile file(":/MainWindow/Resources/About.txt");
	if (file.open(QIODevice::ReadOnly))
		help = file.readAll();
	file.close();

	return help;
}

std::vector<Vector2D> GetPointsFromTable(QStandardItemModel* table, int& codeError)
{
	std::vector<Vector2D> points(table->rowCount());
	QVariant buf;
	float x, y;
	bool ok;
	for (size_t i = 0; !codeError && i < table->rowCount(); i++)
	{
		buf = table->data(table->index(i, 0));
		x = buf.toFloat(&ok);
		if (!ok)
			codeError = INCORRECT_INPUT;

		buf = table->data(table->index(i, 1));
		y = buf.toFloat(&ok);
		if (!ok)
			codeError = INCORRECT_INPUT;

		points[i] = Vector2D(x, y);
	}
	return points;
}

int GetAnswer(std::vector<Vector2D>& points, Vector2D& A, Vector2D& B, Vector2D& C, Vector2D& M, Vector2D& P)
{
	int codeError = FindTriangleMinLenghtMedian(points, A, B, C);
	if (!codeError)
		GetMinMedian(A, B, C, M, P);
	return codeError;
}