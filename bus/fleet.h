#ifndef FLEET_H
#define FLEET_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "bus.h"

using namespace std;

class Fleet
{
    string name;
    vector<Bus> busses;

public:
    Fleet(string, const vector<Bus> &busses = {});
    void add_line(const Bus &);
    vector<Bus> stops_at(Station) const;
    friend ostream &operator<<(ostream &o, const Fleet &f);
};

#endif