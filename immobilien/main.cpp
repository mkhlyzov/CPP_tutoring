#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"room.h"
#include"property.h"
using namespace std;

int main()
{
  try {
    //Room
    cout << "Room\n";
    try {
      cout << Room{2} << '\n';
      cout << Room{1} << '\n';
      cout << "Test 1\n";
    }
    catch (runtime_error&) {
      cout << "Error 1\n";
    }
    try {
      cout << Room{120} << '\n';
      cout << Room{121} << '\n';
      cout << "Test 2\n";
    }
    catch (runtime_error&) {
      cout << "Error 2\n";
    }
    try {
      cout << Room{65, Type::Bathroom} << '\n';
      cout << Room{-4, Type::Bathroom} << '\n';
      cout << "Test 3\n";
    }
    catch (runtime_error&) {
      cout << "Error 3\n";
    }
    try {
      cout << Room{42, Type::Bedroom} << '\n';
      cout << Room{212, Type::Livingroom} << '\n';
      cout << "Test 4\n";
    }
    catch (runtime_error&) {
      cout << "Error 4\n";
    }
    try {
      cout << Room{91, Type::Livingroom} << '\n';
      cout << Room{4, Type::Kitchen} << '\n';
      cout << "Test 5\n";
    }
    catch (runtime_error&) {
      cout << "Error 5\n";
    }

    const Room theRoom{72};
    cout << theRoom << " " << theRoom.usable_as({}) << " " << theRoom.usable_as({Type::Bathroom, Type::Kitchen}) 
         << " " << theRoom.usable_as({Type::Bedroom, Type::Livingroom}) << " "
         << theRoom.usable_as({Type::Livingroom}) << '\n';
    cerr << theRoom << '\n';
    const vector<Room> myRooms{{80},{20,Type::Kitchen},{40,Type::Bedroom},{12,Type::Bathroom},
                               {79},{20,Type::Bedroom},{40,Type::Bedroom},{10,Type::Bathroom}};
    for (const auto& r : myRooms) {
      cout << static_cast<int>(r.getType()) << ' ';
      for (const auto& r1 : myRooms)
        cout << (r==r1);
      cout << '\n';
    }

    //Property
    cout << "\nProperty\n";
    try {
      cout << Property{""} << '\n';
      cout << "Test 6\n";
    }
    catch (runtime_error&) {
      cout << "Error 6\n";
    }
    try {
      cout << Property{"Herrengasse 5"} << '\n';
      cout << Property{"Herrengasse 3",{}} << '\n';
      cout << "Test 7\n";
    }
    catch (runtime_error&) {
      cout << "Error 7\n";
    }
    try {
      cout << Property{"Stubenring 2",myRooms} << '\n';
      cout << Property{"Stubenbastei 1",{{20,Type::Kitchen},{40,Type::Bedroom},{12,Type::Bathroom},
                               {79,Type::Kitchen},{20,Type::Bedroom},{40,Type::Bedroom},{10,Type::Bathroom}}};
      cout << "Test 8\n";
    }
    catch (runtime_error&) {
      cout << "Error 8\n";
    }

    const Property myProperty{"Heldenplatz 5",myRooms};
    Property yourProperty{"Stephansplatz 1",{{20,Type::Livingroom},{40,Type::Bedroom},
                            {12,Type::Bathroom},{79,Type::Livingroom,},{20,Type::Bedroom},{40,Type::Bedroom},
                            {10,Type::Bathroom}}};
    cout << myProperty << '\n' << yourProperty << '\n';
    cerr << myProperty << '\n';
    cout << myProperty.pct_area({}) << " " << myProperty.pct_area({Type::Kitchen}) << " "
         << myProperty.pct_area({Type::Livingroom, Type::Bedroom}) << " "
         << myProperty.pct_area({Type::Bedroom, Type::Kitchen, Type::Bathroom, Type::Livingroom}) << '\n';
    cout << yourProperty.pct_area({}) << " " << yourProperty.pct_area({Type::Kitchen}) << " "
         << yourProperty.pct_area({Type::Livingroom, Type::Bedroom}) << " "
         << yourProperty.pct_area({Type::Bedroom, Type::Kitchen, Type::Bathroom, Type::Livingroom}) << '\n';
    cout << myProperty.is_luxurious() << yourProperty.is_luxurious() << '\n';
    Property noLuxury{"Elm Street 10",{{80},{80},{20,Type::Kitchen},{40,Type::Bedroom},{20,Type::Kitchen},
                              {40,Type::Bedroom},{20,Type::Kitchen},{40,Type::Bedroom},{80}}};
    Property almostLuxury{"Elm Street 11",{{80},{20,Type::Bathroom},{80},{20,Type::Kitchen},{40,Type::Bedroom},
                              {20,Type::Kitchen},{40,Type::Bedroom},{20,Type::Kitchen},
                              {20,Type::Bathroom},{40,Type::Bedroom},{80}}};
    Property stillNoLuxury{"Elm Street 12",{{80},{20,Type::Bathroom},{20,Type::Kitchen},{40,Type::Bedroom},
                              {20,Type::Kitchen},{40,Type::Bedroom},{20,Type::Kitchen},
                              {20,Type::Bathroom},{40,Type::Bedroom},{80},{20,Type::Bathroom}}};
    Property pureLuxury{"Broadway 7",{{80},{20,Type::Bathroom},{20,Type::Kitchen},{40,Type::Bedroom},
                              {20,Type::Kitchen},{80,Type::Livingroom},{40,Type::Bedroom},{20,Type::Kitchen},
                              {20,Type::Bathroom},{40,Type::Bedroom},{80},{20,Type::Bathroom},{80},{80}}};
    Property noMoreLuxury{"Broadway 70",{{80},{21,Type::Bathroom},{20,Type::Kitchen},{40,Type::Bedroom},
                              {20,Type::Kitchen},{80,Type::Livingroom},{40,Type::Bedroom},{20,Type::Kitchen},
                              {20,Type::Bathroom},{40,Type::Bedroom},{80},{20,Type::Bathroom},{80},{80}}};
    Property anotherOne{"No Way",{{89},{20,Type::Bathroom},{21,Type::Kitchen},{41,Type::Bedroom},
                              {22,Type::Kitchen},{88,Type::Livingroom},{42,Type::Bedroom},{23,Type::Kitchen},
                              {24,Type::Bathroom},{43,Type::Bedroom},{87},{25,Type::Bathroom},{86},{85}}};
    cout << noLuxury.is_luxurious() << almostLuxury.is_luxurious() << stillNoLuxury.is_luxurious()
         << pureLuxury.is_luxurious() << noMoreLuxury.is_luxurious() << '\n';

    //Dekommentieren für Zusatz 10 Punkte
    /*
    cout << "\nZusatz reorder 10 Punkte\n";
    noLuxury.reorder({});
    cout << noLuxury << '\n';
    noLuxury.reorder({Type::Kitchen,Type::Bathroom});
    cout << noLuxury << '\n';
    almostLuxury.reorder({Type::Kitchen,Type::Bathroom});
    cout << almostLuxury << '\n';
    noMoreLuxury.reorder({Type::Kitchen,Type::Bathroom});
    cout << noMoreLuxury << '\n';
    stillNoLuxury.reorder({Type::Livingroom});
    cout << stillNoLuxury << '\n';
    pureLuxury.reorder({Type::Bathroom,Type::Kitchen,Type::Livingroom,Type::Bedroom});
    cout << pureLuxury << '\n';
    Property myOtherOne{anotherOne};
    myOtherOne.reorder({Type::Bedroom,Type::Livingroom});
    cout << myOtherOne << '\n';
    myOtherOne.reorder({Type::Kitchen,Type::Bathroom,Type::Bedroom,Type::Livingroom});
    cout << myOtherOne << '\n';
    */

    //Dekommentieren für Zusatz 15 Punkte
    /*
    cout << "\nZusatz exchange 15 Punkte\n";
    cout << anotherOne.exchange(noLuxury) << " ";
    cout << anotherOne << '\n' << noLuxury << '\n';
    cout << noLuxury.exchange(anotherOne) << " ";
    cout << anotherOne << '\n' << noLuxury << '\n';
    Property myCpy{myProperty};
    cout << anotherOne.exchange(myCpy) << "";
    cout << anotherOne << '\n' << myCpy << '\n';
    cout << anotherOne.exchange(myCpy) << "";
    cout << anotherOne << '\n' << myCpy << '\n';
    cout << anotherOne.exchange(yourProperty) << "";
    cout << anotherOne << '\n' << yourProperty << '\n';
    cout << anotherOne.exchange(myCpy) << "";
    cout << anotherOne << '\n' << myCpy << '\n';
    */
  }
  catch (exception& e) {
    cout << "Unerwartete Exception: " << e.what() << '\n';
  }

  return 0;
}