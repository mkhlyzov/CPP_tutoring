#include "garment.h"
#include "schrank.h"

using namespace std;

Schrank::Schrank(size_t max_engine, const vector<Garment> &garments) : max_engine{max_engine}, garments{garments}
{
  if (max_engine < 5 || max_engine > 300)
    throw runtime_error("Invalid kapazitat");

  if (garments.empty())
    throw runtime_error("Invalid Belag");

  if (garments.empty())
    throw runtime_error("Belag ist leer");

  int i{0}, j{0}, k{0}, l{0};
  for (const auto &a : garments)
  {
    //     class Garment
    //
    //     int preis;
    //     Color farbe;
    //     Type type;   <-----
    switch (static_cast<int>(a.get_type())) // Garment g1(12, Color::Red, Type::Pants);    // значения из ограниченного набора (всего 4)
    //  a.type имеет тип Type, но можно сконвертировать в integer с помощью static_cast
    //  static_cast<int>(a.type)   принимает значения 0...3
    //  a.type - приватная, так что мы используем a.get_type()
    {
    case static_cast<int>(Type::Pants):
      ++i;
      break;
    case static_cast<int>(Type::Blouse):
      ++j;
      break;
    case static_cast<int>(Type::Shirt):
      ++k;
      break;
    case static_cast<int>(Type::Skirt):
      ++l;
      break;
    }
    // i j k l
    // как определить что весь шкаф (garments) состоит только лишь из штанов?
    if (i == garments.size() || j == garments.size() || k == garments.size() || l == garments.size())
      throw runtime_error("Format verdoppelt");
  }
}

bool Schrank::add(vector<Garment> new_garments)
{
  // если хватает места на все вещи - добавляем все вещи, и return true
  // не хватает места на все вещи - ничего не добавляем, и return false

  // это требует:
  // 1) умения проверять хватает ли места
  // 2) умения добавлять все вещи в шкаф
  size_t count{garments.size()};
  size_t count1{new_garments.size()};

  // if (a){
  //   return
  // }
  // else {b}
  // эквивалентно
  // if (a) return
  // b

  if (count + count1 > 300)
  {
    return false;
  }

  for (size_t i{0}; i < new_garments.size(); ++i)
  {
    garments.push_back(new_garments.at(i));
  }
  return true;
}

double Schrank::mean_price() const
{
  int res{0};
  for (const auto &v : garments)
  {
    res += (v.get_price()) / 2;
  }
  return res;
}

ostream &operator<<(ostream &o, const Schrank &s)
{
  o << "[" << s.max_engine << ", {";
  bool first{true};
  for (const auto &v : s.garments)
  {
    if (first)
      first = false;
    else
      o << ", ";
    o << v;
  }
  o << "}, " << s.mean_price() << "]";
  return o;
}
