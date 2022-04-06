#ifndef VERTEXITEM_H
#define VERTEXITEM_H

#include "stadium.h"

#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QTextBrowser>
#include <QGraphicsSceneMouseEvent>

using namespace std;

class VertexItem: public QGraphicsEllipseItem
{
public:
    VertexItem(qreal x, qreal y, qreal width, qreal height, QTextBrowser *console)
        :QGraphicsEllipseItem(x, y, width, height)
    {
        this->console = console;
    }

    void setStadium(Stadium *stadium)
    {
        this->stadium = stadium;
    }

    void mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
        if (event->buttons() & Qt::LeftButton)
        {
            console->setText(QString::fromStdString(stadium->str()));
        }
        else if (event->buttons() & Qt::RightButton)
        {
            //TODO: select stadium
        }
    }

private:
    QTextBrowser *console;
    Stadium *stadium;
};


#endif // VERTEXITEM_H
