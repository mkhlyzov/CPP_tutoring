#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"spieler.h"
#include"mannschaft.h"
using namespace std;

//Implementierung der Klasse Mannschaft


Mannschaft:: Mannschaft(string name, vector<Spieler> spielers): name{name}, spielers{spielers}
{
  int  count{0};
  if(name.empty())
    throw runtime_error("Invalid name");
  for(size_t i{0}; i < spielers.size(); i++)
  {
    for(size_t j{i+1}; j < spielers.size(); j++)
    {
      if(spielers.at(i) == spielers.at(j))
        count++;
    }
  
  }
  if(count >= 1)
    throw runtime_error("Belag voll");
}

vector<Spieler> Mannschaft:: engagieren(const vector<Spieler>& spieler_neu)
{
  vector<Spieler> erg{};
  
  int count{0};
  vector<Spieler> temp;
  for(size_t i{0}; i < spieler_neu.size();i++)
  {
    count = 0;
    for(size_t j{0}; j < spielers.size(); j++)
    {
      if(spielers.at(j) == spieler_neu.at(i))
      {
        count++;
      }
    }
    if(count < 1)
      spielers.push_back(spieler_neu.at(i));
    else
      erg.push_back(spieler_neu.at(i));
  }
  
  return erg;
}


//string Mannschaft:: aufstellung() const;
//vector<Spieler> Mannschaft:: entlassen(vector<Position>);
ostream& Mannschaft:: print(ostream& o)const
{
  o << "[" << name << ", {";
  for(size_t i{0}; i < spielers.size(); i++)
  {
    o << spielers.at(i);
    if(i < spielers.size()-1)
      o << ", ";
  }
  o << "}]";
  return o;
}

ostream& operator<<(ostream& o,const Mannschaft&m)
{
  
  return m.print(o);

}