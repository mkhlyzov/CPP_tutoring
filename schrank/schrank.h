#ifndef SCHRANK_H
#define SCHRANK_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "garment.h"

using namespace std;

class Schrank
{
    size_t max_engine;
    vector<Garment> garments;

public:
    Schrank(size_t, const vector<Garment> &garments = {});
    bool add(vector<Garment>);
    double mean_price() const;
    friend ostream &operator<<(ostream &o, const Schrank &s);
};

#endif
