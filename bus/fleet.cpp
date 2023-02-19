#include "fleet.h"
#include "bus.h"


using namespace std;


Fleet::Fleet(string name, const vector<Bus> &busses): name{name}, busses{busses}
{
    if(name.empty())
    throw runtime_error("Invalid name");
}

void Fleet::add_line(const Bus & z)
{
    busses.push_back(z);
}

vector<Bus> Fleet::stops_at(Station s) const{
    vector<Bus> temp{};
    for(size_t i{0}; i < busses.size(); i++)
    {
        if(busses.at(i).stops_at(s))
        temp.push_back(busses.at(i));
    }
    return temp;
}

// [Besitzername {Liste der Busse}], z.B.:
// [Dr. Ritchart {[42Y 7 cent/station {Main, Church}], [15A 20 cent/station{}]}]
ostream &operator<<(ostream &o, const Fleet &f){
    
    o << "[" << f.name << " {";
    bool first{true};
    for(const auto& b: f.busses)
    {
        if(first)
        first = false;
        else
        o << ", ";
        o << b;
    }
    o << "}]";
    return o;
}

