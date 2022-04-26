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
    inline static int lineCount = 54;
    CanvasManager(QGraphicsView *graphicsView, QTextBrowser *console, Stadium **stadiums, bool *selectStadiumIndex);
    ~CanvasManager();
    void startAnimation(int* points, int pointCount);
    void clearCanvas();
    void addVertex(int x, int y, Stadium *stadium);
    void addLine(int i, int j, int length);
    VertexItem **vertices;
private slots:
    void advance();
private:
    QTextBrowser *console;
    bool *selectStadiumIndex;
    int** edgeList;
    int** vertexList;
    int* selectedLines;
    QGraphicsScene *scene;
    QTimer *timer;
    Line **lines;
    int step;
};

#endif // CANVASMANAGER_H
