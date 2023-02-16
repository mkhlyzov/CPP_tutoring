#include "garment.h"

using namespace std;

Garment::Garment(int preis, Color farbe, Type type) : preis{preis}, farbe{farbe}, type{type}
{
    if (preis < 0)
        throw runtime_error("Invalid preis");
}
int Garment::get_price() const
{
    return preis;
}

Type Garment::get_type() const
{
    return type;
}

bool Garment::has_color(Color f) const
{
    return this->farbe == f;
}

void Garment::deteriorate(int w)
{

    preis -= w;
    if (preis < 0)
        preis = 0;
    if (w < 0)
        throw runtime_error("Invalid error");
}

ostream &operator<<(ostream &o, const Garment &g)
{
    o << "[" << g.preis << " Cent, " << color_names.at(static_cast<int>(g.farbe)) << " " << type_names.at(static_cast<int>(g.type)) << "]";
    return o;
}
