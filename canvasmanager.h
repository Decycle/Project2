#ifndef CANVASMANAGER_H
#define CANVASMANAGER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "line.h"
#include "stadium.h"
#include "vertexItem.h"

class CanvasManager: public QObject
{
public:
    CanvasManager(QGraphicsView *graphicsView, QTextBrowser *console, Stadium **stadiums, bool *selectStadiumIndex);
    ~CanvasManager();
    void startAnimation(int* points, int pointCount);
    void clearCanvas();
    VertexItem **vertices;
private slots:
    void advance();
private:
    int** edgeList;
    int* selectedLines;
    QGraphicsScene *scene;
    QTimer *timer;
    Line **lines;
    int step;
};

#endif // CANVASMANAGER_H
