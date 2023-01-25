#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"spieler.h"

using namespace std;

//Implementierung der Klasse Spieler


string Spieler:: get_name()
{
  return name;
}
Spieler::Spieler(string name,int transfer, Position position): name{name}, transfer{transfer},position{position}
{
  if(name.empty())
    throw runtime_error("Invalid name");
  if(transfer < 10 || transfer > 500)
    throw runtime_error("Invalid transfer");
}

bool Spieler:: operator==(const Spieler& other) const
{
  return name == other.name;
}  

ostream& Spieler:: print(ostream& o)const
{
  o << "[" << name << ", " << transfer << " " << "Mio Euro, " << positionsnamen.at(static_cast<size_t>(position)) << "]";
  return o;
}

ostream& operator<<(ostream& o,const Spieler& s)
{
  return s.print(o);
}