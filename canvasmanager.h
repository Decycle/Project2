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

    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    CanvasManager(QGraphicsView *graphicsView);
    ~CanvasManager();

    /**************
     ** MUTATORS **
     **************/
    void startAnimation(int* points, int pointCount);
    void clearCanvas();
    void addVertex(int x, int y, Stadium *stadium);


    /***************
    ** ACCESSORS **
    ***************/
    int addLine(int i, int j);

private slots:

    /**************
     ** MUTATORS **
     **************/
    void advance();

private:
    int** edgeList;             // IN/OUT - edges list
    int** vertexList;           // IN/OUT - vertex list
    int* selectedLines;         // IN/OUT - selected lien
    QGraphicsScene *scene;      // IN/OUT - scene to print vertex and line
    QTimer *timer;              // IN/OUT - timer
    int step;                   // IN/OUT - step to print line
};

#endif // CANVASMANAGER_H
