#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPen>
#include <QBrush>
#include <QList>
#include <QPointF>
#include <QGraphicsEllipseItem>
#include "ui_mainwindow.h"

class Draw
{
public:
    static void initializeGraphicsScene(Ui::MainWindow *ui, QGraphicsScene *&scene, QGraphicsPixmapItem *&gridPixmapItem);
    static void clearPathHistory(QGraphicsScene *scene, QList<QPointF> &pathPoints, QList<QGraphicsEllipseItem *> &pathItems, QGraphicsPixmapItem *gridPixmapItem);
    static void updatePath(Ui::MainWindow *ui, QGraphicsScene *scene, QList<QPointF> &pathPoints, QList<QGraphicsEllipseItem *> &pathItems, float posX, float posY);
};

#endif // DRAW_H
