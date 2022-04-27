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
    LineItem(VertexItem* a, VertexItem* b, QTextBrowser *console, float distance)
        :QGraphicsLineItem(a->posX + 11, a->posY + 11, b->posX + 11, b->posY + 11)
    {
        setAcceptHoverEvents(true);
        this->a = a;
        this->b = b;
        this->console = console;
        this->distance = distance;
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
    {
        painter->setPen(QPen(Qt::black, width));
        painter->drawLine(a->posX + 11, a->posY + 11, b->posX + 11, b->posY + 11);

//        QGraphicsLineItem::paint(painter, option, widget);
//        if(selectStadiumIndex[index])
//        {
//            QGraphicsEllipseItem::paint(painter, option, widget);
//        }
//        painter->setBrush(Qt::white);
//        painter->drawEllipse(x + 3, y + 3, 16, 16);
    }

    void hoverEnterEvent(QGraphicsSceneHoverEvent*)
    {
        width = 3;
        this->update();
    }
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*)
    {
        width = 2;
        this->update();
    }

    void mousePressEvent(QGraphicsSceneMouseEvent*)
    {
        console->setText("Distance: " + QString::number(distance));
    }

private:
    QTextBrowser *console;
    VertexItem *a;
    VertexItem *b;
    int width = 2;
    float distance;
};

#endif // LINEITEM_H
