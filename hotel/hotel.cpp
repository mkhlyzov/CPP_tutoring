#include "hotel.h"
#include "room.h"
using namespace std;

Hotel::Hotel(string name, const vector<Room> &rooms) : name{name}, rooms{rooms}
{
    if (name.empty())
        throw runtime_error("Invalid name");
    if (rooms.empty())
        throw runtime_error("belag ist leer");
}

bool Hotel:: accommodate(const vector<string>& persons, const vector<Extra>& demands)
{
    size_t count{rooms.size()};
    size_t count1{persons.size()};
    if(count < count1)
    return false;
    else
    rooms.push_back(persons);
    return true;
    if()
}
vector<size_t> Hotel:: find(const vector<Extra>& demands) const
{
    return {};
}
ostream &operator<<(ostream &o, const Hotel &h)
{
    o << "[" << h.name << " {";
    bool first{true};
    for (const auto &v : h.rooms)
    {
        if (first)
            first = false;
        else
            o << ", ";
        o << v;
    }
    o << "}]";
    return o;
}
