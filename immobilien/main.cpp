#include <iostream>

#include "room.h"
#include "property.h"


int main() {
	Property prop = Property("Lenina st.", {
		{10, Type::Bathroom},
		{15, Type::Livingroom},
		{20, Type::Kitchen},
		{25, Type::Bedroom},
		{30, Type::Bathroom},
		{35, Type::Livingroom},
		{40, Type::Kitchen},
		{45, Type::Bedroom},
	});
	std::cout << prop << std::endl << std::endl;
	prop.reorder1({Type::Livingroom});
	std::cout << prop << std::endl << std::endl;

	return 0;
}