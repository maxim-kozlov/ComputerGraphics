#include "pch.h"
#include "CombinatoricsLibrary.h"

// array_index - ������ �������� �� ���� �� n - 1
// ������ k ��������� - ��� ������� ��������� ������ ���������
bool NextCombination(int* array_index, int n, int k)
{
	for (int i = k - 1; i >= 0; i--)
	{
		// n - k + i ���������� ��������, ������� ����� ���������� array_index[i]
		// ������ ����� ������ �������, �� ��������� ��� ������ ����������� ��������;
		if (array_index[i] < n - k + i)
		{
			// �������� ��� �� �������
			array_index[i]++;
			// ���� ����������� ��������� �������� ���������� ��������.
			for (int j = i + 1; j < k; ++j)
				array_index[j] = array_index[j - 1] + 1;
			return true;
		}
	}
	return false;
}
