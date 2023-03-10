#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cassert>

#include "garment.h"
#include "schrank.h"

using namespace std;

int main()
{
    Garment g1(12, Color::Red, Type::Pants);
    Garment g2(22, Color::Gray, Type::Blouse);
    Garment g3(20, Color::Blue, Type::Shirt);
    Garment g4(30, Color::Yellow, Type::Skirt);
    Garment g5(12, Color::Red, Type::Pants);
    Garment g6(22, Color::Gray, Type::Blouse);
    Garment g7(20, Color::Blue, Type::Shirt);
    Garment g8(30, Color::Yellow, Type::Skirt);
    Garment g9(12, Color::Red, Type::Pants);
    Garment g10(22, Color::Gray, Type::Blouse);
    Garment g11(20, Color::Blue, Type::Shirt);
    Garment g12(30, Color::Yellow, Type::Skirt);


    // Test 1
    Schrank s1(100, {g1, g2, g3});
    std::cout << "Test 1 passed" << std::endl;
    // Test 2
    try {
        Schrank s2(1, {g1, g2}); // error
        std::cout << "Test 2 failed-----------" << std::endl;
    }
    catch (const std::runtime_error& e){
        std::cout << "Test 2 passed" << std::endl;
    }
    // Test 3
    try {
        Schrank s3(500, {g2, g2}); // error
        std::cout << "Test 3 failed-----------" << std::endl;
    }
    catch (const std::runtime_error& e){
        std::cout << "Test 3 passed" << std::endl;
    }

    // Test 4
    try {
        Schrank s4(100, {}); // error
        std::cout << "Test 4 failed-----------" << std::endl;
    }
    catch (const std::runtime_error& e){
        std::cout << "Test 4 passed" << std::endl;
    }

    // Test 5
    try {
        Schrank s4(100, {g1, g1, g1, g1, g1}); // error
        std::cout << "Test 5 failed-----------" << std::endl;
    }
    catch (const std::runtime_error& e){
        std::cout << "Test 5 passed" << std::endl;
    }

    // Test 6
    Schrank s4(100, {g1, g1, g2, g2, g2});
    std::cout << "Test 6 passed" << std::endl;

    // Test 7
    try {
        Schrank s4(100, {g2, g2, g2}); // error
        std::cout << "Test 7 failed-----------" << std::endl;
    }
    catch (const std::runtime_error& e){
        std::cout << "Test 7 passed" << std::endl;
    }

    std::cout << "We passed constructor tests!" << std::endl;
    std::cout << "Starting 'add' tests!" << std::endl;

    // Test 8
    Schrank s5(100, {g1, g1, g2});
    std::cout << s5 << std::endl; // g1 g1 g2 g2 g2
    assert (s5.add({g3, g3}) == true);
    std::cout << s5 << std::endl; // g3 g3 g1 g1 g2 g2 g2
    std::cout << "Test 8 passed" << std::endl;

    // Test 9
    Schrank s6(10, {g1, g1, g2, g2, g2});
    assert (s6.add({g3, g3, g3, g4, g6, g2, g3}) == false);
    std::cout << "Test 9 passed" << std::endl;

    // Test 10
    Schrank s7(10, {g1, g1, g2, g2, g2, g1, g2});
    assert (s7.add({g3, g3, g3, g4, g6, g2}) == false);
    std::cout << "Test 10 passed" << std::endl;

    // cout << s1.add({g4});
    // cout << s1 << endl;
}
