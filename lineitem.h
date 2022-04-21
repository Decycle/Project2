#ifndef LINEITEM_H
#define LINEITEM_H

#include <QGraphicsLineItem>
#include <QTextBrowser>
#include <QDebug>
#include <QPen>

class LineItem: public QGraphicsLineItem
{
public:
    LineItem(qreal x1, qreal y1, qreal x2, qreal y2, QPen pen, QTextBrowser *console, float distance)
        :QGraphicsLineItem(x1, y1, x2, y2)
    {
        setAcceptHoverEvents(true);
        this->pen = pen;
        this->console = console;
        setPen(pen);
        this->distance = distance;
    }

    void hoverEnterEvent(QGraphicsSceneHoverEvent*)
    {
        pen.setWidth(3);
        setPen(pen);
    }
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*)
    {
        pen.setWidth(2);
        setPen(pen);
    }

    void mousePressEvent(QGraphicsSceneMouseEvent*)
    {
        console->setText("Distance: " + QString::number(distance));
    }

private:
    QTextBrowser *console;
    QPen pen;
    float distance;
};

#endif // LINEITEM_H
