#ifndef SPIELER_H
#define SPIELER_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

enum class Position {Tor, Abwehr, Mitte, Sturm};
const vector<string> positionsnamen{"Tor","Abwehr","Mitte","Sturm"};

//Definition der Klasse Spieler
class Spieler
{
  string name;
  int transfer;
  Position position;
  public:
  Spieler(string,int, Position = Position:: Tor);
  bool operator==(const Spieler&) const;
  ostream& print(ostream&)const;
  string get_name();
};

ostream& operator<<(ostream&,const Spieler&);
#endif