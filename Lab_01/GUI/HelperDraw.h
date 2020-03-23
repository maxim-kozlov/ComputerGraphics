#pragma once

#include <QString>
#include <QGraphicsTextItem>
#include <QtWidgets/QGraphicsView>
#include "Vector2D.h"
#include <qspinbox.h>
#define MARGIN 20
#define E_MARGIN 2

void SetMaximumPossibleValuesSpinBox(QDoubleSpinBox* spinBox);

QGraphicsScene* CreateScene(QGraphicsView* view);
void SetScene(QGraphicsView* view, QGraphicsScene* scene);

float GetHeightScene(QGraphicsScene* scene);
float GetWidthScene(QGraphicsScene* scene);


void WriteText(QGraphicsScene* scene, QString text, QPoint pos);
void WritePoint(QGraphicsScene* scene, Vector2D& point, Vector2D& pos, float w);
QString ConvertStringToQString(std::string str);

void DrawLine(QGraphicsScene* scene, Vector2D& A, Vector2D& B, unsigned int color);
void DrawTriangle(QGraphicsScene* scene, Vector2D& A, Vector2D& B, Vector2D& C, unsigned int color);