#include "bus.h"

using namespace std;


Bus:: Bus(string name, int cost, const vector<Station>& names): name{name}, cost{cost}, names{names}
{
 if(name.empty())
 throw runtime_error("Invalid name");
 if(cost <= 0 || cost > 20)
 throw runtime_error("Invalid cost");
 if(names.empty())
 throw runtime_error("Invalid belag");
}

bool stops_at(Station s) const
{
 for(const auto& v: names)
 {
  if(names == s)
  return true;
 }
 return false;
}

int cost(Station from, Station to) const
{
 int i{0};
 for(i = 0; i < names.size(); i++)
 {
  if(names.at(i) == from)
  break;
 }
 int j{0};
 for(j = 0; j < names.size(); j++)
 {
  if(names.at(j) == to)
  break;
 }
 if(j - i < 0)
 return (j - i) * cost * (-1);
 else
 return (j - i) * cost;
}
 friend ostream& operator<<(ostream& o,const Bus& b)
 {
  o << "[" << b.name << " " << b.cost << " cent/station {";
  bool first{true};
  for(const auto& v: b.names)
  {
   if(first)
   first = false;
   else
   o << ", ";
   o << v;
  } 
  o << "}]";
 }
