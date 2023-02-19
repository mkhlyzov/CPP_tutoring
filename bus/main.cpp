#include <iostream>
#include "bus.h"
#include "fleet.h"


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


    // Testing Fleet
    cout << "Fleet tests ========================\n";
    Bus b4("404", 10, {Station::A, Station::B, Station::C, Station::D});
    Bus b5("405", 10, {Station::B, Station::C, Station::D, Station::E});
    Bus b6("406", 10, {Station::C, Station::D, Station::E, Station::F});
    Bus b7("407", 10, {Station::D, Station::E, Station::F, Station::G});
    Bus b8("408", 10, {Station::E, Station::F, Station::G, Station::K});
    
    Fleet f1("Bob", {b4,b5, b6});
    cout << f1 << endl;
    try
    {    Fleet f2("", {b4,b5, b6});
        cout << "Test 10 failed" << endl;
    }
    catch(const std::runtime_error& e)
    {
        cout << "Test 10 passed\n";
    }
    // Test add_line
    f1.add_line(b7);
    cout << f1 << endl;
    // Test stops_at    
    for (Bus b : f1.stops_at(Station:: G)){
        cout << b << ", ";
    }
    cout << endl;
    
    for (Bus b : f1.stops_at(Station:: K)){
        cout << b << ", ";
    }
    cout << endl;

    for (Bus b : f1.stops_at(Station:: D)){
        cout << b << ", ";
    }
    cout << endl;
    return 0;
}
