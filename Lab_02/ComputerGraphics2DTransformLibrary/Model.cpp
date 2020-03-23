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
	// ��������� ���������
	memento.Push(MatrixModel);

	// ������� � ������ ���������
	BufferTransform.SetMove(-xc, -yc);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	// ������� ������������ ����� (0, 0)
	BufferTransform.SetRotate(GetRadians(angleDegree));
	MatrixModel.GetProduct(Buffer, BufferTransform);

	// ������� � �������� �����
	BufferTransform.SetMove(xc, yc);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	Buffer.CopyTo(MatrixModel);
}

void Model::Scale(float kx, float ky, float xm, float ym)
{
	// ��������� ���������
	memento.Push(MatrixModel);

	// ������� � ������ ���������
	BufferTransform.SetMove(-xm, -ym);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	// ��������������� ������������ ����� (0, 0)
	BufferTransform.SetScale(kx, ky);
	MatrixModel.GetProduct(Buffer, BufferTransform);

	// ������� � �������� �����
	BufferTransform.SetMove(xm, ym);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	Buffer.CopyTo(MatrixModel);
}

void Model::Move(float dx, float dy)
{
	// ��������� ���������
	memento.Push(MatrixModel);

	// �������
	BufferTransform.SetMove(dx, dy);
	Buffer.GetProduct(MatrixModel, BufferTransform);

	Buffer.CopyTo(MatrixModel);
}

bool Model::Cancel()
{
	// ���� ���������� ��������
	bool noEmpty = !memento.IsEmpty();
	if (noEmpty)
	{
		// �������� ��������� ���������� ��������
		Matrix3x3* last = memento.Pop();
		last->CopyTo(MatrixModel);
		delete last;
	}
	return noEmpty;
}