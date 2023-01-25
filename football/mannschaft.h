#ifndef MANNSCHAFT_H
#define MANNSCHAFT_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"spieler.h"
using namespace std;

//Definition der Klasse Mannschaft

class Mannschaft
{
  string name;
  vector<Spieler> spielers;
  public:
  Mannschaft(string, vector<Spieler> spielers = {});
  vector<Spieler> engagieren(const vector<Spieler>& spieler_neu);
  ostream& print(ostream&)const;
  //string aufstellung() const;
  //vector<Spieler> entlassen(vector<Position>);
};

ostream& operator<<(ostream&,const Mannschaft&);
#endif