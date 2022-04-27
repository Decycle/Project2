#ifndef CANVASMANAGER_H
#define CANVASMANAGER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "stadium.h"
#include "vertexItem.h"
#include "lineitem.h"

class CanvasManager: public QObject
{
public:
    CanvasManager(QGraphicsView *graphicsView);
    ~CanvasManager();
    void startAnimation(int* points, int pointCount);
    void clearCanvas();
    void addVertex(int x, int y, Stadium *stadium);
    int addLine(int i, int j);
private slots:
    void advance();
private:
    int** edgeList;
    int** vertexList;
    int* selectedLines;
    QGraphicsScene *scene;
    QTimer *timer;
    int step;
};

#endif // CANVASMANAGER_H
