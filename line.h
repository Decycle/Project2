#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPen>
#include <lineitem.h>


class Line
{
public:
    Line();
    Line(float x1, float y1, float x2, float y2);
    void addToScene(QGraphicsScene *scene);
    float length();
    void setDistance(float p);
//private:
    float x1;
    float y1;
    float x2;
    float y2;
    LineItem *blackLine;
    LineItem *redLine;
};

#endif // LINE_H
