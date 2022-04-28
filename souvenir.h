#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <iostream>
using namespace std;

class Souvenir
{
public:
    Souvenir();
    void addItem(string name, double price);
    string to_str() const;
    double totalPrice();
    string names[20];
    double prices[20];
    int count;
};

#endif // SOUVENIR_H
