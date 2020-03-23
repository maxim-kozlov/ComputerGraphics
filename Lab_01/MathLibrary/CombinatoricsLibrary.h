#ifndef CombinatoricsLibrary_H
#define CombinatoricsLibrary_H

#include "pch.h"

// array_index - массив индексов от нуля до n - 1
// первые k элементов - это индексы элементов нового сочетания
// return получено новое сочетание
extern "C++" MATHLIBRARY_API bool NextCombination(int* array_index, int n, int k);

#endif // !CombinatoricsLibrary_H
