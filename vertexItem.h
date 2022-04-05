#ifndef VERTEXITEM_H
#define VERTEXITEM_H

#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QTextBrowser>
#include <QGraphicsSceneMouseEvent>

class VertexItem: public QGraphicsEllipseItem
{
public:
    VertexItem(qreal x, qreal y, qreal width, qreal height, QTextBrowser *console)
        :QGraphicsEllipseItem(x, y, width, height)
    {
        this->console = console;
    }

    void mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
        console->setText("Show Stadium");
    }

private:
    QTextBrowser *console;
};


#endif // VERTEXITEM_H
