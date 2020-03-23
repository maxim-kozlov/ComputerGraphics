#pragma once
#include "pch.h"
#include <deque>
#include "Matrix3x3.h"

// ���������
// ������� �� ����
class Memento
{
public:
	Memento(int maxSize);
	~Memento();

	// push � �������� ������������ ������
	// � ����������� ������� ��������, ����
	// ������������ ����� � ����
	void Push(Matrix3x3& matrix);
	
	// �������� �� �������
	bool IsEmpty();

	// ���� ��� �������� � ��������� - null
	// ����������� ������ �� ���������� ������� 
	Matrix3x3* Pop();

private:
	// ������������ ���������� �������� commit-��
	const int maxSize;
	std::deque<Matrix3x3*> deque;
};

