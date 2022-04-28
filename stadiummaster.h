#ifndef STADIUMMASTER_H
#define STADIUMMASTER_H

#include "graph.h"
#include "stadium.h"
#include "vertexItem.h"

#include <QDebug>

class StadiumMaster
{
public:
    /*****************
     ** CONSTRUCTOR **
     *****************/
    StadiumMaster();
    /**************
     ** MUTATOR **
     **************/
    void addStadium();
    void addPath(int i, int j, int length);
//private:
    Graph stadiumGraph;
};

#endif // STADIUMMASTER_H
