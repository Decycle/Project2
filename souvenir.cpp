#include "souvenir.h"

#include <iomanip>
#include <sstream>
#include <QDebug>

/**********************************************************
* Method Souvenir(): Class Souvenir
*_________________________________________________________
* This method is a default constructor
*_________________________________________________________
* PRE-CONDITIONS
*
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
Souvenir::Souvenir()
{
    count = 0;

    this->addItem("Baseball cap", 25.99);
    this->addItem("Baseball bat", 35.35);
    this->addItem("Team pennant", 12.99);
    this->addItem("Autographed baseball", 19.99);
}

/**********************************************************
* Method totalPrice(): Class Souvenir
*_________________________________________________________
* This method return total price
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*      int
***********************************************************/
double Souvenir::totalPrice()
{
    int total = 0;

    for(int i = 0; i < count; i ++)
    {
        total += prices[i];
    }

    return total;
}

/**********************************************************
* Method addItem(): Class Souvenir
*_________________________________________________________
* This method add new souvenir to list
*_________________________________________________________
* PRE-CONDITIONS
*      string double
*
* POST-CONDITIONS
*      none
***********************************************************/
void Souvenir::addItem(string name, double price)
{
    this->names[count] = name;
    this->prices[count] = price;
    count++;
}

/**********************************************************
* Method to_str(): Class Souvenir
*_________________________________________________________
* This method print out souvenir list
*_________________________________________________________
* PRE-CONDITIONS
*
*   none
* POST-CONDITIONS
*      string
***********************************************************/
string Souvenir::to_str() const
{
    stringstream output;

    for(int i = 0; i < count; i ++)
    {
        output << names[i] << ": $";
        output << std::fixed << std::setprecision(2) << prices[i] << "\n";
    }

    return output.str();
}
