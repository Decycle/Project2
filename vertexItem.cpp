#include "vertexItem.h"
#include "appcontroller.h"

VertexItem::VertexItem(qreal x, qreal y, qreal width,
           qreal height, int index, bool isMovable)
    :QGraphicsEllipseItem(x, y, width, height)
{
    this->x = x;
    this->y = y;
    this->posX = x;
    this->posY = y;
    this->index = index;
    this->isMovable = isMovable;

    this->setAcceptDrops(true);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

void VertexItem::setStadium(Stadium *stadium)
{
    this->stadium = stadium;
}

void VertexItem::setAlternativeStadium(Stadium *stadium)
{
    this->alternativeStadium = stadium;
}

void VertexItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if(AppController::SelectStadiumIndex[index])
    {
        QGraphicsEllipseItem::paint(painter, option, widget);
    }
    painter->setPen(Qt::NoPen);

    if(isMovable)
    {
        painter->setBrush(QColor(201, 255, 203));
    }
    else
    {
        painter->setBrush(Qt::white);
    }
    painter->drawEllipse(x + 3, y + 3, 16, 16);
}

void VertexItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        if(alternativeStadium != nullptr)
        {
            AppController::Console->setText(QString::fromStdString(stadium->str() + '\n' + alternativeStadium->str()));
        }
        else
        {
            AppController::Console->setText(QString::fromStdString(stadium->str()));
        }
    }
    else if (event->buttons() & Qt::RightButton)
    {
        if(!AppController::SelectStadiumIndex[index])
        {
            AppController::SelectStadiumIndex[index] = true;
            this->update();
        }
        else
        {
            AppController::SelectStadiumIndex[index] = false;
            this->update();
        }

    }
}

void VertexItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!isMovable)
    {
        return;
    }

    this->setPos(event->scenePos().x() - x - 11, event->scenePos().y() - y - 11);
    this->posX = event->scenePos().x() - 5;
    this->posY = event->scenePos().y() - 5;
    this->update();
    for(int i = 0; i < AppController::LineCount; i ++)
    {
        AppController::Lines[i]->update();
    }
}
