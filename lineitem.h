#ifndef LINEITEM_H
#define LINEITEM_H

#include <QGraphicsLineItem>
#include <QTextBrowser>
#include <QDebug>
#include <QPen>

class LineItem: public QGraphicsLineItem
{
public:
    LineItem(qreal x1, qreal y1, qreal x2, qreal y2, QPen pen, QTextBrowser *console)
        :QGraphicsLineItem(x1, y1, x2, y2)
    {
        setAcceptHoverEvents(true);
        this->pen = pen;
        this->console = console;
        setPen(pen);
    }

    void hoverEnterEvent(QGraphicsSceneHoverEvent* event)
    {
        pen.setWidth(3);
        setPen(pen);

    }
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
    {
        pen.setWidth(2);
        setPen(pen);
    }

    void mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
//        console->setText("Show Line");
    }

private:
    QTextBrowser *console;
    QPen pen;
};

#endif // LINEITEM_H
