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
    VertexItem(qreal x, qreal y, qreal width,
               qreal height, QTextBrowser *console,
               int index, bool *selectStadiumIndex)
        :QGraphicsEllipseItem(x, y, width, height)
    {
        this->console = console;
        this->index = index;
        this->selectStadiumIndex = selectStadiumIndex;
    }

    void setStadium(Stadium *stadium)
    {
        this->stadium = stadium;
    }

    void setAlternativeStadium(Stadium *stadium)
    {
        this->alternativeStadium = stadium;
    }

    void mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
        if (event->buttons() & Qt::LeftButton)
        {
            if(alternativeStadium != nullptr)
            {
                console->setText(QString::fromStdString(stadium->str() + '\n' + alternativeStadium->str()));
            }
            else
            {
                console->setText(QString::fromStdString(stadium->str()));
            }
        }
        else if (event->buttons() & Qt::RightButton)
        {
            //TODO: select stadium
            if(!selectStadiumIndex[index])
            {
                selectStadiumIndex[index] = true;
                this->setOpacity(0.5);
            }
            else
            {
                selectStadiumIndex[index] = false;
                this->setOpacity(0.0);
            }

        }
    }

private:
    int index;
    bool *selectStadiumIndex;
    QTextBrowser *console;
    Stadium *stadium;
    Stadium *alternativeStadium = nullptr;
};


#endif // VERTEXITEM_H
