#ifndef STADIUMMASTER_H
#define STADIUMMASTER_H

#include "graph.h"
#include "line.h"
#include "stadium.h"
#include "vertexItem.h"

#include <QDebug>

class StadiumMaster
{
public:
    StadiumMaster();
    void addStadium();
    void addPath(int i, int j, int length);
//private:
    Graph stadiumGraph;
};

#endif // STADIUMMASTER_H
