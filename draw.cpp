#include "draw.h"
#include <QPen>
#include <QBrush>

void Draw::initializeGraphicsScene(Ui::MainWindow *ui, QGraphicsScene *&scene, QGraphicsPixmapItem *&gridPixmapItem)
{
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-150, -150, 300, 300);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    QPixmap gridPixmap(":/images/grid.png");
    gridPixmapItem = scene->addPixmap(gridPixmap);
    gridPixmapItem->setPos(-gridPixmap.width() / 2, -gridPixmap.height() / 2);

    scene->addLine(-10, 0, 10, 0, QPen(Qt::black));
    scene->addLine(0, -10, 0, 10, QPen(Qt::black));
}

void Draw::clearPathHistory(QGraphicsScene *scene, QList<QPointF> &pathPoints, QList<QGraphicsEllipseItem *> &pathItems, QGraphicsPixmapItem *gridPixmapItem)
{
    pathPoints.clear();
    for (auto item : pathItems) {
        scene->removeItem(item);
        delete item;
    }
    pathItems.clear();

    if (!scene->items().contains(gridPixmapItem)) {
        scene->addItem(gridPixmapItem);
        gridPixmapItem->setPos(-gridPixmapItem->pixmap().width() / 2, -gridPixmapItem->pixmap().height() / 2);
    }

    scene->addLine(-10, 0, 10, 0, QPen(Qt::black));
    scene->addLine(0, -10, 0, 10, QPen(Qt::black));
}

void Draw::updatePath(Ui::MainWindow *ui, QGraphicsScene *scene, QList<QPointF> &pathPoints, QList<QGraphicsEllipseItem *> &pathItems, float posX, float posY)
{
    QPointF newPoint(posX, posY);
    pathPoints.append(newPoint);

    for (auto item : pathItems) {
        scene->removeItem(item);
        delete item;
    }
    pathItems.clear();

    QPen pen(Qt::blue);
    QBrush brush(Qt::blue);
    for (const QPointF &point : pathPoints) {
        QGraphicsEllipseItem *ellipse = scene->addEllipse((point.x()) * 12, (point.y()) * -12, 5, 5, pen, brush);
        pathItems.append(ellipse);
    }

    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}
