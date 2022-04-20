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
    StadiumMaster(bool *selectStadiumIndex);
    Stadium **stadiums;
    int stadiumCount;
    bool *selectStadiumIndex;
//private:
    Graph stadiumGraph;
};

#endif // STADIUMMASTER_H
