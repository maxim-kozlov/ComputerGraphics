#pragma once
#include "pch.h"
#include <deque>
#include "Matrix3x3.h"

// хранитель
// основан на деке
class Memento
{
public:
	Memento(int maxSize);
	~Memento();

	// push с глубоким копированием данных
	// и вытеснением первого элемента, если
	// недостаточно места в деке
	void Push(Matrix3x3& matrix);
	
	// проверка на пустоту
	bool IsEmpty();

	// если нет значений в хранителе - null
	// освобждение памяти на вызывающей стороне 
	Matrix3x3* Pop();

private:
	// максимальное количество хранимых commit-ов
	const int maxSize;
	std::deque<Matrix3x3*> deque;
};

