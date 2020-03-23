#pragma once

#include "HelperMath.h"
#include "Vector2D.h"
#include <vector>
#include <QStandardItemModel.h>
#include <QString>

#define INCORRECT_INPUT 1

void AppendPointToTable(QStandardItemModel* table, Vector2D& point);

bool DeletePointFromTable(QStandardItemModel* table, int indexRow);

bool DeleteAllPointFromTable(QStandardItemModel* table);

QString GetInfoAboutProgram();

std::vector<Vector2D> GetPointsFromTable(QStandardItemModel* table, int& codeError);

// получить искомый треугольник и его минимальную медиану
int GetAnswer(std::vector<Vector2D>& points, Vector2D& A, Vector2D& B, Vector2D& C, Vector2D& M, Vector2D& P);