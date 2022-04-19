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

Stadium::Stadium(QString name, int capacity, QString location, bool isAmerican, bool hasGrass, QString team, int opened)
{
    this->name = name;
    this->capacity = capacity;
    this->location = location;
    this->isAmerican = isAmerican;
    this->hasGrass = hasGrass;
    this->team = team;
    this->opened = opened;
}

string Stadium::str()
{
    stringstream strstream;
    strstream << *this;
    return strstream.str();
}

ostream& operator<<(ostream& os, const Stadium& stadium)
{
    os << "Stadium: " << stadium.name.toStdString() << endl;
    os << "Capacity: " << stadium.capacity << endl;
    os << "Location: " << stadium.location.toStdString() << endl;
    os << (stadium.isAmerican ? "American" : "National")<< endl;
    os << (stadium.hasGrass ? "Grass" : "Artificial turf") << endl;
    os << "Team: " << stadium.team.toStdString() << endl;
    os << "Opened: " << stadium.opened << endl;
    return os;
}
