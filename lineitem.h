#ifndef LINEITEM_H
#define LINEITEM_H

#include "vertexItem.h"

#include <QGraphicsLineItem>
#include <QTextBrowser>
#include <QDebug>
#include <QPen>
#include <QPainter>

/***********************************************************
* Class LineItem
*_________________________________________________________
* this class is set the line on the map
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
* this class is set the line on the map
***********************************************************/
class LineItem: public QGraphicsLineItem
{
public:

    LineItem(VertexItem* a, VertexItem* b, float distance);
    void setDistance(double p); // this function the distance
    double length(); // set length for the line
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void hoverEnterEvent(QGraphicsSceneHoverEvent*); // hover enter
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*); // hover Leave
    void mousePressEvent(QGraphicsSceneMouseEvent*); // mouse press

private:
    VertexItem *a;
    VertexItem *b;
    int width = 2;
    double p;
    float distance; // distance
};

#endif // LINEITEM_H
