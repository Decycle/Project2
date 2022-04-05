#include "stadium.h"

stadium::stadium(){}

stadium::stadium(string stadium_name, string team_name, string phone, string date, string cap):
                 stadium_name(stadium_name), team_name(team_name),phone(phone){
    date_open = "Opened - " +date;
    capacity = "Capacity - " + cap;
}

void stadium::info(){
    cout << getStadiumName() << endl;
    cout << getTeamName() << endl;
    cout << getAddress() << endl;
    cout << getPhone() << endl;
    cout << getDateOpen() << endl;
    cout << getCapacity() << endl;
}
void stadium::set_address(string street, string zip){
    address = street + "\n"+zip;
}

void stadium::set_capacity(string cap){
    capacity = "Capacity - " + cap;
}



const string &stadium::getStadiumName() const {
    return stadium_name;
}

const string &stadium::getTeamName() const {
    return team_name;
}

const string &stadium::getAddress() const {
    return address;
}

const string &stadium::getCapacity() const {
    return capacity;
}

const string &stadium::getPhone() const {
    return phone;
}

const string &stadium::getDateOpen() const {
//    string temp = "Opened - " +date_open;
//    return temp;
    return date_open;
}
