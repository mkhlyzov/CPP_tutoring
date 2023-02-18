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

// Hotel h2("New Moon", {
//     Room(4, {Extra::WLAN, Extra::TV, Extra::BAR}, {"A", "B", "C"}),
//     Room(4, {Extra::WLAN, Extra::TV, Extra::GYM}, {"A", "B", "C"}),
//     Room(4, {Extra::WLAN, Extra::TV, Extra::BAR}, {"A", "B", "C"})
//   });
// h2.accommodate({"Billy"}, {Extra::GYM})
bool Hotel::accommodate(const vector<string> &persons, const vector<Extra> &demands)
{
    // пытается заселить людей в каждую комнату
   
    for (size_t i{0}; i < rooms.size(); i++)
    {
        // метод complies проверяет достаточно ли удобной является комната
        // метод check_in пытается заселить людей
        if (rooms.at(i).complies(demands) && rooms.at(i).check_in(persons))
            return true;
    }
    return false;
    
    //==========================
    // пытается заселить тольк ов первую комнату
    /*
    for (size_t i{0}; i < rooms.size(); i++)
    {
        // метод complies проверяет достаточно ли удобной является комната
        // метод check_in пытается заселить людей
        if (rooms.at(i).complies(demands) && rooms.at(i).check_in(persons))
            return true;
        else
            return false;
    }
    return true;
    */
}
vector<size_t> Hotel::find(const vector<Extra> &demands) const
{
    vector<size_t> temp{};
    for(size_t i{0}; i < rooms.size(); i++)
    {
      if(rooms.at(i).complies(demands))
      temp.push_back(static_cast<size_t>(i));
    } 
    return temp;
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
