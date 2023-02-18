#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "room.h"

using namespace std;

class Hotel
{
    string name;
    vector<Room> rooms;

public:
    Hotel(string, const vector<Room> &rooms = {});
    bool accommodate(const vector<string> &persons, const vector<Extra> &demands);
    vector<size_t> find(const vector<Extra> &demands) const;
    friend ostream &operator<<(ostream &o, const Hotel &h);
};
#endif
