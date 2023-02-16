#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

enum class Extra{WLAN,TV,BAR,VR,LARGE,GYM,SAUNA,ALLER};
const vector<string> extra_names {"WLAN","TV","BAR","VR","LARGE","GYM","SAUNA","ALLER"};
class Room
{
 int size;
 vector<Extra> extras;
 vector<string> guests;
 friend ostream& operator<<(ostream& o,const Room& r);
};

#endif
