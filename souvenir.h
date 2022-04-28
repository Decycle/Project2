#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <iostream>
using namespace std;

class Souvenir
{
public:

    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    Souvenir();

    /**************
     ** MUTATORS **
     **************/
    void addItem(string name, double price);

    /***************
    ** ACCESSORS **
    ***************/
    string to_str() const;
    double totalPrice();


    string names[20];           //IN/OUT----sourvenir list
    double prices[20];          //IN/OUT----sourvenir price list
    int count;                  //IN/OUT----sourvenir count
};

#endif // SOUVENIR_H
