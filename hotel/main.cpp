#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

#include "room.h"
#include "hotel.h"

using namespace std;
int main()
{

  const vector<string> names{"ANNA", "MARIE", "THERESIE"};
  Room r1(4, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE", "THERESIE"});
  // Room r2(2, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE","THERESIE"});
  Room r3(5, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE", "THERESIE"});
  // Room r4(1, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE","THERESIE"});

  // cout << r1 << endl;
  // cout << r2 << endl;

  // Test 5
  try
  {
    Room r1(4, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE", "THERESIE"});
    std::cout << "Test 5 passed" << std::endl;
    cout << r1 << endl;
  }
  catch (const std::runtime_error &e)
  {
    std::cout << "Test 5 failed" << std::endl; // error
  }

  try
  {
    Room r2(2, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE", "THERESIE"});
    std::cout << "Test 5 passed" << std::endl;
    cout << r2;
  }

  catch (const std::runtime_error &e)
  {
    std::cout << "Test 5 failed" << std::endl; // error
  }

  try
  {
    Room r3(5, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE", "THERESIE"});
    std::cout << "Test 5 passed" << std::endl;
    cout << r3 << endl;
  }

  catch (const std::runtime_error &e)
  {
    std::cout << "Test 5 failed" << std::endl; // error
  }

  try
  {
    Room r4(1, {Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE", "THERESIE"});
    std::cout << "Test 5 passed" << std::endl;
    cout << r4;
  }
  catch (const std::runtime_error &e)
  {
    std::cout << "Test 5 failed" << std::endl; // error
  }

  Hotel h1("Mama Maria", {r1, r3});

  // Testing accomodate
  std::cout << "============Testing accomodate==============" << std::endl;
  Hotel h2("New Moon", {
    Room(4, {Extra::WLAN, Extra::TV, Extra::BAR}, {"A", "B", "C"}),
    Room(4, {Extra::WLAN, Extra::TV, Extra::GYM}, {"A", "B", "C"}),
    Room(4, {Extra::WLAN, Extra::TV, Extra::BAR}, {"A", "B", "C"})
  });
  std::cout << h2 << std::endl;
  // bool accommodate(const vector<string> &persons, const vector<Extra> &demands);
  // const vector<string> extra_names {"WLAN","TV","BAR","VR","LARGE","GYM","SAUNA","ALLER"};
  assert(false == h2.accommodate({"Gabriel", "Daniel", "Francis"}, {Extra::WLAN, Extra::TV, Extra::BAR}));
  std::cout << "Test 10 passed\n";
  assert(true == h2.accommodate({"Gabriel"}, {Extra::WLAN, Extra::TV, Extra::BAR}));
  std::cout << "Test 11 passed\n";
  assert(true == h2.accommodate({"Billy"}, {Extra::GYM}));
  std::cout << "Test 12 passed\n";
  assert(true == h2.accommodate({}, {Extra::GYM}));
  std::cout << "Test 13 passed\n";
  assert(true == h2.accommodate({"Kirill"}, {}));
  std::cout << "Test 14 passed\n";
  
  std::cout << h2 << std::endl;
}
