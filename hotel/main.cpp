#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

#include "room.h"


using namespace std;
int main()
{

const vector<string> names{"ANNA", "MARIE", "THERESIE"};
Room r1(4,{Extra::WLAN, Extra::TV, Extra::BAR}, {"ANNA", "MARIE"."THERESIE"});
Room r2(2, {"TV", "WLAN", "BAR", "VR"}, {"ANNA", "MARIE"."THERESIE"});
Room r3(5, {"TV", "WLAN", "BAR", "VR"}, {"ANNA", "MARIE"."THERESIE"});
Room r4(1, {"TV", "WLAN", "BAR", "VR"}, {"ANNA", "MARIE"."THERESIE"});

 cout << r1 << endl;
 cout << r2 << endl;
}
