/**
 * \file draw.cpp
 * \brief Implementacja funkcji rysujących.
 */

#include "draw.h"
#include <QPen>
#include <QBrush>

/**
 * \brief Inicjalizuje scenę graficzną.
 *
 * \param ui Wskaźnik do interfejsu głównego okna.
 * \param scene Wskaźnik do wskaźnika sceny graficznej, który zostanie zainicjowany nową sceną.
 * \param gridPixmapItem Wskaźnik do wskaźnika elementu pixmapy siatki, który zostanie zainicjowany elementem pixmapy.
 */
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

/**
 * \brief Czyści historię ścieżki i przywraca siatkę.
 *
 * \param scene Wskaźnik do sceny graficznej.
 * \param pathPoints Lista punktów ścieżki, będzie opróżniona po wykonaniu funkcji.
 * \param pathItems Lista elementów graficznych reprezentujących punkty ścieżki, będzie opróżniona po wykonaniu funkcji.
 * \param gridPixmapItem Wskaźnik do elementu pixmapy siatki, który jest ponownie dodawany do sceny, jeśli nie jest obecny.
 */
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


/**
 * \brief Aktualizuje ścieżkę, dodając nowy punkt.
 *
 * \param ui Wskaźnik do interfejsu głównego okna.
 * \param scene Wskaźnik do sceny graficznej.
 * \param pathPoints Lista punktów ścieżki, do której zostanie dodany nowy punkt.
 * \param pathItems Lista elementów graficznych reprezentujących punkty ścieżki, zostanie zaktualizowana o nowy element.
 * \param posX Pozycja X nowego punktu.
 * \param posY Pozycja Y nowego punktu.
 */
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
