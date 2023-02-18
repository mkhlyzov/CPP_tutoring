#include "room.h"

using namespace std;

Room::Room(int size, const vector<Extra> &extras, const vector<string> &guests) : size{size}, extras{extras}, guests{guests}
{
  if (size <= 0)
    throw runtime_error("Invalid size of appartment");

  int count{0};
  for (size_t i{0}; i < extras.size(); i++)
  {
    for (size_t j{i + 1}; j < extras.size(); j++)
    {
      if (extras.at(i) == extras.at(j))
        count++;
    }
  }
  if (count > 1)
    throw runtime_error("Invalid Error");
  size_t count1{guests.size()};

  if (count1 > size)
    throw runtime_error("Invalid Error1");
}

bool Room::complies(const vector<Extra> &demands) const
{
  for (size_t i{0}; i < demands.size(); i++)
  {
    int count{0};
    for (size_t j{0}; j < extras.size(); j++)
    {
      if (extras.at(j) == demands.at(j))
        count++;
    }
    if (count < 1)
      return false;
  }
  return true;
}

bool Room::check_in(const vector<string> &persons)
{
  size_t count{persons.size()};
  size_t count1{guests.size()};
  if (count + count1 > size)
  {
    return false;
  }
  for (size_t i{0}; i < persons.size(); i++)
  {
    guests.push_back(persons.at(i));
  }
  return true;
}

ostream &operator<<(ostream &o, const Room &r)
{
  o << "[" << r.size << " {";
  bool first{true};
  for (const auto &elem : r.extras)
  {
    if (first)
      first = false;
    else
      o << ", ";
    o << extra_names.at(static_cast<size_t>(elem));
  }
  o << "} {";
  bool first1{true};
  for (const auto &elem1 : r.guests)
  {
    if (first1)
      first1 = false;
    else
      o << ", ";
    o << elem1;
  }
  o << "}]";
  return o;
}
