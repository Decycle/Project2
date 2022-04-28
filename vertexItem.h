#ifndef VERTEXITEM_H
#define VERTEXITEM_H

#include "stadium.h"

#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QTextBrowser>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

using namespace std;

class VertexItem: public QGraphicsEllipseItem
{
public:
    /*****************
     ** CONSTRUCTOR **
     *****************/
    VertexItem(qreal x, qreal y, qreal width,
               qreal height, int index, bool isMovable=false);
    /*************
     ** MUTATOR **
     *************/
    void setStadium(Stadium *stadium);
    void setAlternativeStadium(Stadium *stadium);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
public:
    int posX;
    int posY;
private:
    int x;
    int y;
    int index;
    bool isMovable;
    Stadium *stadium;
    Stadium *alternativeStadium = nullptr;
};

#endif // VERTEXITEM_H
