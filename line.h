#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPen>
#include <QTextBrowser>
#include <lineitem.h>


class Line
{
public:
    Line();
    Line(float x1, float y1, float x2, float y2, QTextBrowser *console, float distance);
    void addToScene(QGraphicsScene *scene);
    float length();
    void setDistance(float p);
private:
    float x1;
    float y1;
    float x2;
    float y2;
    float distance;
    LineItem *blackLine;
    LineItem *redLine;
    QTextBrowser *console;

};

#endif // LINE_H
