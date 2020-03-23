#include "pch.h"
#include "Model.h"
#include "HelperMath.h"

Model::Model() : memento(6)
{
	MatrixModel.IdentityMatrix();
}

Matrix3x3& Model::GetMatrixModel()
{
	return MatrixModel;
}

void Model::Rotate(float angleDegree, float xc, float yc)
{
	// запомнить состояние
	memento.Push(MatrixModel);

	// перенос в начало координат
	BufferTransform.SetMove(-xc, -yc);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	// поворот относительно точки (0, 0)
	BufferTransform.SetRotate(GetRadians(angleDegree));
	MatrixModel.GetProduct(Buffer, BufferTransform);

	// перенос в исходную точку
	BufferTransform.SetMove(xc, yc);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	Buffer.CopyTo(MatrixModel);
}

void Model::Scale(float kx, float ky, float xm, float ym)
{
	// запомнить состояние
	memento.Push(MatrixModel);

	// перенос в начало координат
	BufferTransform.SetMove(-xm, -ym);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	// масштабирование относительно точки (0, 0)
	BufferTransform.SetScale(kx, ky);
	MatrixModel.GetProduct(Buffer, BufferTransform);

	// перенос в исходную точку
	BufferTransform.SetMove(xm, ym);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	Buffer.CopyTo(MatrixModel);
}

void Model::Move(float dx, float dy)
{
	// запомнить состояние
	memento.Push(MatrixModel);

	// перенос
	BufferTransform.SetMove(dx, dy);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	Buffer.CopyTo(MatrixModel);
}

bool Model::Cancel()
{
	// есть сохранённые значения
	bool noEmpty = !memento.IsEmpty();
	if (noEmpty)
	{
		// получить последнее сохранённое значение
		Matrix3x3* last = memento.Pop();
		last->CopyTo(MatrixModel);
		delete last;
	}
	return noEmpty;
}