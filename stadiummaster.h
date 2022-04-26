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
    inline static int stadiumCount = 30;
    StadiumMaster(bool *selectStadiumIndex);
    void addStadium();
    Stadium **stadiums;
    bool *selectStadiumIndex;
//private:
    Graph stadiumGraph;
};

#endif // STADIUMMASTER_H
