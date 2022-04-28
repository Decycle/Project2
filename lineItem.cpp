#include "lineitem.h"
#include "appcontroller.h"

/***********************************************************
* LineItem(VertexItem* a, VertexItem* b, float distance)
*_________________________________________________________
* This function is set the postion for the line
*_________________________________________________________
* PRE-CONDITIONS
* none
* POST-CONDITIONS
*     initializes heapArray to array of set SIZE
* and count to 0
***********************************************************/
LineItem::LineItem(VertexItem* a, VertexItem* b, float distance)
    :QGraphicsLineItem(a->posX + 11, a->posY + 11, b->posX + 11, b->posY + 11)
{
    setAcceptHoverEvents(true);
    this->a = a;
    this->b = b;
    this->distance = distance;
    this->p = 0;
}

double LineItem::length()
{
    double x1 = a->posX;
    double x2 = b->posX;
    double y1 = a->posY;
    double y2 = b->posY;

    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void LineItem::setDistance(double p)
{
    this->p = p;
}

void LineItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    double x1 = a->posX + 11;
    double x2 = b->posX + 11;
    double y1 = a->posY + 11;
    double y2 = b->posY + 11;

    double percent;
    if(distance == 0)
    {
        percent = p;
    }
    else
    {
        percent = p / distance;
    }


    if (percent < 0.) percent = 0.;
    if (percent > 1.) percent = 1.;

    float point_x = x1 * (1. - percent) + x2 * percent;
    float point_y = y1 * (1. - percent) + y2 * percent;

    painter->setPen(QPen(Qt::black, width));
    painter->drawLine(point_x, point_y, x2, y2);
    painter->setPen(QPen(Qt::red, width));
    painter->drawLine(x1, y1, point_x, point_y);
}

void LineItem::hoverEnterEvent(QGraphicsSceneHoverEvent*)
{
//    width = 3;
//    this->update();
}
void LineItem::hoverLeaveEvent(QGraphicsSceneHoverEvent*)
{
//    width = 2;
//    this->update();
}

void LineItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        AppController::Console->setText("Distance: " + QString::number(distance));
    }

    if(event->buttons() & Qt::RightButton)
    {

    }
}
