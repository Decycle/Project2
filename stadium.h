#ifndef STADIUM_H
#define STADIUM_H

#include <QString>
#include <iostream>
#include <sstream>

class VertexItem;

using namespace std;

class Stadium
{
public:
    Stadium();
    Stadium(QString name, int capacity, QString location, bool isAmerican,
            bool hasGrass, QString team, int opened,
            VertexItem *vertex);
    friend ostream& operator<<(ostream& os, const Stadium& stadium);
    string str();
    VertexItem *vertex;

private:
    QString name;
    int capacity;
    QString location;
    bool isAmerican;
    bool hasGrass;
    QString team;
    int opened;

};

#endif // STADIUM_H