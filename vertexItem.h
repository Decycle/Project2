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
    VertexItem(qreal x, qreal y, qreal width,
               qreal height, QTextBrowser *console,
               int index, bool *selectStadiumIndex)
        :QGraphicsEllipseItem(x, y, width, height)
    {
        this->x = x;
        this->y = y;
        this->posX = x;
        this->posY = y;
        this->console = console;
        this->index = index;
        this->selectStadiumIndex = selectStadiumIndex;

        this->setAcceptDrops(true);
//        this->setFlag(QGraphicsItem::ItemIsSelectable);
        this->setFlag(QGraphicsItem::ItemIsMovable);
//        this->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    }

    void setStadium(Stadium *stadium)
    {
        this->stadium = stadium;
    }

    void setAlternativeStadium(Stadium *stadium)
    {
        this->alternativeStadium = stadium;
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
    {
        if(selectStadiumIndex[index])
        {
            QGraphicsEllipseItem::paint(painter, option, widget);
        }
        painter->setBrush(Qt::white);
        painter->drawEllipse(x + 3, y + 3, 16, 16);
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
            if(!selectStadiumIndex[index])
            {
                selectStadiumIndex[index] = true;
                this->update();
            }
            else
            {
                selectStadiumIndex[index] = false;
                this->update();
            }

        }
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        this->setPos(event->scenePos().x() - x - 11, event->scenePos().y() - y - 11);
        this->posX = event->scenePos().x() - 5;
        this->posY = event->scenePos().y() - 5;
        this->update();
    }
public:
    int posX;
    int posY;
private:
    int x;
    int y;
    int index;
    bool *selectStadiumIndex;
    QTextBrowser *console;
    Stadium *stadium;
    Stadium *alternativeStadium = nullptr;
};


#endif // VERTEXITEM_H
