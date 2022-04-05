#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
#include <string>
using namespace std;

using namespace std;

class stadium {
public:

    stadium();
    stadium(string stadium_name, string team, string phone, string date,string cap);

    void set_address(string street, string zip);
    void set_capacity(string cap);
    void info();
private:
    string stadium_name;
    string team_name;
    string address;
    string phone;

    string capacity;
    string date_open;

public:
    const string &getStadiumName() const;
    const string &getTeamName() const;
    const string &getAddress() const;
    const string &getCapacity() const;
    const string &getPhone() const;
    const string &getDateOpen() const;


};
#endif // STADIUM_H
