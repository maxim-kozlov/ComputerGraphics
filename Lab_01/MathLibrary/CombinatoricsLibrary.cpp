#include "pch.h"
#include "CombinatoricsLibrary.h"

// array_index - массив индексов от нуля до n - 1
// первые k элементов - это индексы элементов нового сочетания
bool NextCombination(int* array_index, int n, int k)
{
	for (int i = k - 1; i >= 0; i--)
	{
		// n - k + i наибольшее значение, которое может достигнуть array_index[i]
		// найдем самый правый элемент, не достигший ещё своего наибольшего значения;
		if (array_index[i] < n - k + i)
		{
			// увеличим его на единицу
			array_index[i]++;
			// всем последующим элементам присвоим наименьшие значения.
			for (int j = i + 1; j < k; ++j)
				array_index[j] = array_index[j - 1] + 1;
			return true;
		}
	}
	return false;
}
