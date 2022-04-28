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
    /**************
     ** CONSTRUCTOR
     **************/
    Stadium();
    Stadium(QString name, int capacity, QString location, bool isAmerican,
            bool hasGrass, QString team, int opened);

    /***************
    ** ACCESSORS **
    ***************/
    friend ostream& operator<<(ostream& os, const Stadium& stadium);
    string str();


    QString name;                   // IN/OUT - stadium name
    int capacity;                   // IN/OUT - stadium capacity
    QString location;               // IN/OUT - stadium location
    bool isAmerican;                // IN/OUT - is American league or not
    bool hasGrass;                  // IN/OUT - has grass or not
    QString team;                   // IN/OUT - stadium team name
    int opened;                     // IN/OUT - stadium open time
    Souvenir souvenir;              // IN/OUT - stadium souvenir list

};

#endif // STADIUM_H
