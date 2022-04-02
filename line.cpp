#include "line.h"

Line::Line()
{
    x1 = 0.;
    y1 = 0.;
    x2 = 0.;
    y2 = 0.;

    redLine = new LineItem(x1, y1, x1, y1, QPen(Qt::red, 2.));
    blackLine = new LineItem(x1, y1, x2, y2, QPen(Qt::black, 2.));
}

Line::Line(float x1, float y1, float x2, float y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;

    redLine = new LineItem(x1, y1, x1, y1, QPen(Qt::red, 2.));
    redLine->setZValue(1);
    blackLine = new LineItem(x1, y1, x2, y2, QPen(Qt::black, 2.));
}

void Line::addToScene(QGraphicsScene *scene)
{
    scene->addItem(redLine);
    scene->addItem(blackLine);
}

float Line::length()
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}


void Line::setDistance(float p)
{
    p = p / length();

    if (p < 0.) p = 0.;
    if (p > 1.) p = 1.;

    float point_x = x1 * (1. - p) + x2 * p;
    float point_y = y1 * (1. - p) + y2 * p;

    redLine->setLine(x1, y1, point_x, point_y);
    blackLine->setLine(point_x, point_y, x2, y2);
}
