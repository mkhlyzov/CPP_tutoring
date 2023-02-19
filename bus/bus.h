#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

enum class Station
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    K,
    L
};

const vector<string> names{"A", "B", "C", "D", "E", "F", "G", "K", "L"};

class Bus
{
    string bus_name;
    int segment_cost;
    vector<Station> stations;

public:
    Bus(string, int cost = 7, const vector<Station> &stations = {});
    bool stops_at(Station s) const;
    int cost(Station from, Station to) const;
    friend ostream &operator<<(ostream &o, const Bus &b);
};

#endif
