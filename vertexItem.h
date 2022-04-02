#ifndef VERTEXITEM_H
#define VERTEXITEM_H

#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QPen>
#include <QBrush>

class VertexItem: public QGraphicsEllipseItem
{
public:
    VertexItem(qreal x, qreal y, qreal width, qreal height)
        :QGraphicsEllipseItem(x, y, width, height)
    {

    }

    void mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
        qDebug() << "Show stadium info";
    }

private:

};


#endif // VERTEXITEM_H
