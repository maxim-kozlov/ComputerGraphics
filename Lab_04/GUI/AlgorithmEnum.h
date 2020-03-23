#pragma once
#include <string>

enum AlgorithmEnum
{
	Canonical_algorithm,
	Parametric_algorithm,
	Breshenham_algorithm,
	Middle_Dot_algorithm,
	Qt_algorithm
};

std::string GetName(AlgorithmEnum algorithm);