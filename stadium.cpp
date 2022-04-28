#include "stadium.h"
/***********************************************************
* Stadium()
*_________________________________________________________
* This function initializes variable data
*_________________________________________________________
* PRE-CONDITIONS
*  capacity: capacity
*  location: location
*  isAmerican: is american stadium
*  hasGrass: has grass;
*  team: team name;
*  opened: open time
*
* POST-CONDITIONS
*   return: none.
***********************************************************/
Stadium::Stadium()
{
    capacity = 0;
    location = "";
    isAmerican = false;
    hasGrass = false;
    team = "";
    opened = 0;
}

/***********************************************************
* Stadium(QString name, int capacity, QString location,
* bool isAmerican, bool hasGrass, QString team, int opened)
*_________________________________________________________
* This function initializes variable data
*_________________________________________________________
* PRE-CONDITIONS
*  capacity: capacity
*  location: location
*  isAmerican: is american stadium
*  hasGrass: has grass;
*  team: team name;
*  opened: open time
*
* POST-CONDITIONS
*   This function will create a new stadium with the
 *  given information..
***********************************************************/
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

/***********************************************************
* str()
*_________________________________________________________
* This function will change it to string
*_________________________________________________________
* PRE-CONDITIONS
* none
*
* POST-CONDITIONS
*   This function will change it to string
***********************************************************/
string Stadium::str()
{
    stringstream strstream;
    strstream << *this;
    return strstream.str();
}

/***********************************************************
* ostream& operator<<(ostream& os, const Stadium& stadium)
*_________________________________________________________
* This function will output all the information
*_________________________________________________________
* PRE-CONDITIONS
* capacity: capacity
*  location: location
*  isAmerican: is american stadium
*  hasGrass: has grass;
*  team: team name;
*  opened: open time
*
* POST-CONDITIONS
*   This function output all the information.
***********************************************************/
ostream& operator<<(ostream& os, const Stadium& stadium)
{
    os << "Stadium: " << stadium.name.toStdString() << endl;
    os << "Capacity: " << stadium.capacity << endl;
    os << "Location: " << stadium.location.toStdString() << endl;
    os << (stadium.isAmerican ? "American" : "National")<< endl;
    os << (stadium.hasGrass ? "Grass" : "Artificial turf") << endl;
    os << "Team: " << stadium.team.toStdString() << endl;
    os << "Opened: " << stadium.opened << endl;
    os << "Souvenir: \n" << stadium.souvenir.to_str() << endl;
    return os;
}
