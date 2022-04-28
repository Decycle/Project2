#include "souvenir.h"

#include <iomanip>
#include <sstream>
#include <QDebug>

Souvenir::Souvenir()
{
    this->addItem("Baseball cap", 25.99);
    this->addItem("Baseball bat", 35.35);
    this->addItem("Team pennant", 12.99);
    this->addItem("Autographed baseball", 19.99);
}

double Souvenir::totalPrice()
{
    int total = 0;

    for(int i = 0; i < count; i ++)
    {
        total += prices[i];
    }

    return total;
}

void Souvenir::addItem(string name, double price)
{
    this->names[count] = name;
    this->prices[count] = price;
    count++;
}

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
