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
 public:
 Room(int,const vector<Extra>& extras = {}, const vector<string>& guests = {});
 bool complies(const vector<Extra>& demands)const;
 bool check_in(const vector<string>& persons);
 friend ostream& operator<<(ostream& o,const Room& r);
};

#endif
