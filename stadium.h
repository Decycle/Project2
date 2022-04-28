#ifndef STADIUM_H
#define STADIUM_H

#include "souvenir.h"

#include <QString>
#include <iostream>
#include <sstream>

class VertexItem;

using namespace std;

class Stadium
{
public:
    // Constructor
    Stadium();
    Stadium(QString name, int capacity, QString location, bool isAmerican,
            bool hasGrass, QString team, int opened);
    //overload << operator
    friend ostream& operator<<(ostream& os, const Stadium& stadium);
    //accessor
    string str();

    QString name;
    int capacity;
    QString location;
    bool isAmerican;
    bool hasGrass;
    QString team;
    int opened;

    Souvenir souvenir;

};

#endif // STADIUM_H
