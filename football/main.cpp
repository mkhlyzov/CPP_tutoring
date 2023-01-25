// #include <iostream>
// #include <vector>

// #include "mannschaft.h"


// int main(){
// 	Mannschaft team1("ABC");
// 	std::cout << team1 << std::endl;

// 	Mannschaft team2("ABC", {
// 		Spieler("Bob", 100, Position::Sturm),
// 		Spieler("Carl", 91, Position::Mitte),
// 		Spieler("Arnold", 120, Position::Sturm)
// 	});
// 	std::cout << team2 << std::endl;

// 	Mannschaft team3("ABC", {
// 		Spieler("Bob", 100, Position::Sturm),
// 		Spieler("Carl", 91, Position::Mitte),
// 		Spieler("Arnold", 120, Position::Sturm),
// 		Spieler("NotCarl", 220, Position::Mitte),
// 	});
// 	std::cout << team3 << std::endl;

// 	return 0;
// }


#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"spieler.h"
#include"mannschaft.h"

using namespace std;

int main() {
  const Spieler stegen{"Stegen",60,Position::Tor};
  const Spieler cillessen{"Cillessen",10};
  const Spieler umtiti{"Umtiti",60,Position::Abwehr};
  const Spieler alba{"Alba",60,Position::Abwehr};
  const Spieler digne{"Digne",15,Position::Abwehr};
  const Spieler roberto{"Roberto",55,Position::Abwehr};
  const Spieler paulinho{"Paulinho",40,Position::Mitte};
  const Spieler gomes{"Gomes",15,Position::Mitte};
  const Spieler rakitic{"Rakitic",50,Position::Mitte};
  const Spieler coutinho{"Coutinho",100,Position::Mitte};
  const Spieler messi{"Messi",180,Position::Sturm};
  const Spieler suarez{"Suarez",70,Position::Sturm};
  const Spieler elhaddadi{"El Haddadi",12,Position::Sturm};

  cout << "SPIELER\n";
  cout << messi << '\n';
  cerr << messi << '\n';
  cout << cillessen << '\n';

  try {
    Spieler s{"",60};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 1\n";
  }
  try {
    Spieler s{"Mesis",9};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 2\n";
  }
  try {
    Spieler s{"Mesis",500};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 3\n";
  }
  try {
    Spieler s{"Mesis",501};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 4\n";
  }
  cout << (messi==messi) << (messi==alba) << (messi==Spieler{"Test",180,Position::Sturm});
  cout << (messi==Spieler{"Messi",18}) << (messi==Spieler{"Messis",180,Position::Sturm});
  cout << '\n';

  cout << "\nMANNSCHAFT\n";
  try {
    cout << Mannschaft{"Kapfenberg"} << '\n';
    cerr << Mannschaft{"Kapfenberg"} << '\n';
    cout << Mannschaft{"Simmering"} << '\n';
    cout << Mannschaft{"Brutal",{coutinho}} << '\n';
    cerr << Mannschaft{"Brutal", {coutinho}} << '\n';
    cerr << Mannschaft{"Sturm", {messi,cillessen}} << '\n';
    Mannschaft m{""};
    cout << m << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 5\n";
  }
  try {
    Mannschaft m{"Liga Nord",{messi,coutinho,cillessen,coutinho,elhaddadi}};
    cout << m << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 6\n";
  }
  Mannschaft barcelona{"Barcelona",{coutinho,cillessen,suarez}};
  const Mannschaft h{"Hoppala",barcelona.engagieren({messi,messi})};
  cout << h << '\n';
  cerr << h << '\n';
  barcelona.engagieren({});
  cout << barcelona << '\n';

  //Dekommentieren fuer Zusatz aufstellung
  /*
  cout << "\nZusatz 10 Punkte\n";
  try {
    cout << barcelona.aufstellung() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 7\n";
  }
  try {
    barcelona.engagieren({umtiti,alba,digne,gomes,paulinho});
    cout << barcelona.aufstellung() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 8\n";
  }
  try {
    Mannschaft cpy{barcelona};
    cpy.engagieren({});
    cpy.engagieren({roberto});
    cout << cpy.aufstellung() << '\n';
    cpy = barcelona;
    cpy.engagieren({stegen});
    cout << cpy.aufstellung() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 9\n";
  }
  try {
    Mannschaft cpy{barcelona};
    cpy.engagieren({rakitic,roberto});
    cout << cpy.aufstellung() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 10\n";
  }
  */

  //Dekommentieren fuer Zusatz entlassen
  /*
  cout << "\nZusatz 15 Punkte\n";
  vector<Spieler> result;
  barcelona.engagieren({umtiti,alba,digne,gomes,paulinho,roberto,stegen});
  result = barcelona.entlassen({});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';
  result = barcelona.entlassen({Position::Tor});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';
  result = barcelona.entlassen({Position::Tor,Position::Sturm,Position::Sturm,Position::Tor});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';
  result = barcelona.entlassen({Position::Sturm,Position::Abwehr});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';
  result = barcelona.entlassen({Position::Sturm,Position::Abwehr,Position::Mitte});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';
  */

  return 0;
}