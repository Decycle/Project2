#ifndef LINEITEM_H
#define LINEITEM_H

#include "vertexItem.h"

#include <QGraphicsLineItem>
#include <QTextBrowser>
#include <QDebug>
#include <QPen>
#include <QPainter>

class LineItem: public QGraphicsLineItem
{
public:
    LineItem(VertexItem* a, VertexItem* b, float distance);
    void setDistance(double p);
    double length();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void hoverEnterEvent(QGraphicsSceneHoverEvent*);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
    void mousePressEvent(QGraphicsSceneMouseEvent*);

private:
    VertexItem *a;
    VertexItem *b;
    int width = 2;
    double p;
    float distance;
};

#endif // LINEITEM_H
