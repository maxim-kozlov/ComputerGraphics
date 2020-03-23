#include "pch.h"
#include "Memento.h"

Memento::Memento(int maxSize) : maxSize(maxSize)
{
	
}

Memento::~Memento()
{
	while (!IsEmpty())
	{
		Matrix3x3* a = Pop();
		delete a;
	}
}

// глубокое копирование
void Memento::Push(Matrix3x3& matrix)
{
	Matrix3x3* buf = new Matrix3x3();
	matrix.CopyTo(*buf);

	if (deque.size() == maxSize)
	{
		Matrix3x3* first = deque.front();
		deque.pop_front();
		delete first;
	}

	deque.push_back(buf);
}

bool Memento::IsEmpty()
{
	return deque.empty();
}

// если нет значений в хранителе - UB
Matrix3x3* Memento::Pop()
{
	Matrix3x3* last = deque.back();
	deque.pop_back();
	return last;
}

