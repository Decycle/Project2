#include "stadium.h"

Stadium::Stadium()
{
    capacity = 0;
    location = "";
    isAmerican = false;
    hasGrass = false;
    team = "";
    opened = 0;
}

Stadium::Stadium(QString name, int capacity, QString location, bool isAmerican, bool hasGrass, QString team, int opened, VertexItem *vertex)
{
    this->name = name;
    this->capacity = capacity;
    this->location = location;
    this->isAmerican = isAmerican;
    this->hasGrass = hasGrass;
    this->team = team;
    this->opened = opened;
    this->vertex = vertex;
}

ostream& operator<<(ostream& os, const Stadium& stadium)
{
    os << "Stadium: " << stadium.name.toStdString() << endl;
    os << "Capacity: " << stadium.capacity << endl;
    os << "Location: " << stadium.location.toStdString() << endl;
    os << "American: " << stadium.isAmerican << endl;
    os << "Grass: " << stadium.hasGrass << endl;
    os << "Team: " << stadium.team.toStdString() << endl;
    os << "Opened: " << stadium.opened << endl;
    return os;
}
