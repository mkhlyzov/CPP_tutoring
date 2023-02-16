#ifndef GARMENT_H
#define GARMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// int -23423423423 +23423423423 // 2^32 = 4 294 967 296
// char 'a' 'b' 'c' '+' 'R' '2'    // 256 различных значений 0-255    0 1 2 3   /  4...255
// double 2134.2354235
// bool true false   // 2 варианта
// // создать переменную которая может принимать только 5 значений

// class MyCustomDataType{
//     int x;
//     int y;
//     char c;
// };


enum class Color
{
    Red,
    Blue,
    Gray,
    Yellow
};
enum class Type
{
    Pants,
    Blouse,
    Shirt,
    Skirt
};

const vector<string> type_names{"Pants", "Blouse", "Shirt", "Skirt"};
const vector<string> color_names{"Red", "Blue", "Gray", "Yellow"};

class Garment
{
    int preis;
    Color farbe;
    Type type;

public:
    Garment(int, Color farbe = Color::Gray, Type type = Type::Pants);
    int get_price() const;
    Type get_type() const;
    bool has_color(Color f) const;
    void deteriorate(int w);
    friend ostream &operator<<(ostream &o, const Garment &g);
};

#endif
