#include "bus.h"

using namespace std;

Bus::Bus(string bus_name, int segment_cost, const vector<Station> &stations) : bus_name{bus_name}, segment_cost{segment_cost}, stations{stations}
{
    if (bus_name.empty())
        throw runtime_error("Invalid name");
    if (segment_cost <= 0 || segment_cost > 20)
        throw runtime_error("Invalid cost");
    if (stations.empty())
        throw runtime_error("Invalid belag");
}

bool Bus::stops_at(Station s) const
{
    for (const auto &v : stations)
    {
        if (v == s)
            return true;
    }
    return false;
}

int Bus::cost(Station from, Station to) const
{
    
    //если станции плохие - вернуть 0
    if (!(stops_at(from) && stops_at(to)))
        return 0; 
    // код выше сделал проверку и убедился, что обе станции являются доступными
    // пожалуйста не редактируй код сверху!


    // Bus b2("404", 10, {Station::A, Station::B, Station::D, Station::L});
    // b2.cost(Station:: L, Station:: A)
    int i{0};
    for (i = 0; i < stations.size(); i++)
    {
        if (stations.at(i) == from)
            break;
    }
    int j{0};
    for (j = 0; j < stations.size(); j++)
    {
        if (stations.at(j) == to)
            break;
    }
    // i =   3  - индекс  L   (для примера L->A) 
    // j =   0  - индекс  A   (для примера L->A) 
    if (j - i < 0)
        return  0;
    else
        return (j - i) * segment_cost;
}

//  [42Y 7 cent/station {Main, Church}].
ostream &operator<<(ostream &o, const Bus &b)
{
    o << "[" << b.bus_name << " " << b.segment_cost << " cent/station {";
    bool first{true};
    for (const auto &v : b.stations)
    {
        if (first)
            first = false;
        else
            o << ", ";
        o <<  names.at(static_cast<size_t>(v));
    }
    o << "}]";
    return o;
}
