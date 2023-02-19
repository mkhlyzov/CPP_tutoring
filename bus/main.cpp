#include <iostream>
#include "bus.h"


// const vector<string> names{"A", "B", "C", "D", "E", "F", "G", "K", "L"};

int main()
{
    
    
    Bus b1("404", 20, {Station::A, Station::B});
    std::cout << b1 << std::endl;
    // Tests for "stops_at"
    std::cout << "Testing 'stops_at'================\n"; 
    assert(b1.stops_at(Station:: A) == true);
    cout << "Test 1 passed" << endl;
    assert(false == b1.stops_at(Station:: E));
    cout << "Test 2 passed" << endl;
    
    // int Bus::cost(Station from, Station to) const
    cout << "Testing Bus::cost ===================\n";
    assert(b1.cost(Station:: A, Station:: E) == 0);
    cout << "Test 3 passed\n";
    assert(b1.cost(Station:: A, Station:: B) == 20);
    cout << "Test 4 passed\n";
    assert(b1.cost(Station:: E, Station:: A) == 0);
    cout << "Test 5 passed\n";
    assert(b1.cost(Station:: E, Station:: D) == 0);
    cout << "Test 6 passed\n";

    Bus b2("404", 10, {Station::A, Station::B, Station::D, Station::L});
    assert(b2.cost(Station:: A, Station:: L) == 30);
    cout << "Test 7 passed\n";
    assert(b2.cost(Station:: L, Station:: A) == 0);
    cout << "Test 8 passed\n";

    Bus b3("404", 10, {Station::B, Station::D, Station::L, Station::A});
    assert(b3.cost(Station:: B, Station:: A) == 30);
    cout << "Test 9 passed\n";

    return 0;
}
