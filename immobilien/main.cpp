#include <iostream>

#include "room.h"
#include "property.h"


int main() {
	// ROOM RELATED MANIPULATIONS

	// Room my_room1(5, Type::Kitchen);
	// Room my_room2(15);
	// Room my_room3(5, Type::Kitchen);

	// // std::cout << "my_room1 type: " << static_cast<int>(my_room1.getType()) << std::endl;
	// // std::cout << "my_room2 type: " << static_cast<int>(my_room2.getType()) << std::endl;
	// std::cout << "my_room1 type: " << my_room1.getType() << std::endl;
	// std::cout << "my_room2 type: " << my_room2.getType() << std::endl;

	// std::vector<Type> my_types = {Type::Kitchen, Type::Bedroom};
	// std::cout << my_room1.usable_as(my_types) << std::endl;
	// std::cout << my_room2.usable_as(my_types) << std::endl;

	// std::cout << "my_room1 == my_room2 is " << (my_room1 == my_room2) << std::endl;
	// std::cout << "my_room1 == my_room3 is " << (my_room1 == my_room3) << std::endl;

	// std::cout << my_room1 << std::endl;
	// std::cout << my_room2 << std::endl;
	// std::cout << my_room3 << std::endl;

	// PROPERTY RELATED MANIPULATIONS

	Property prop1 = Property("Anya's house", {Room(5, Type::Bedroom), Room(20, Type::Kitchen)});
	Property prop2 = Property("Anya's house 2");
	Property prop3 = Property("Lux", 
		{Room(10, Type::Kitchen), Room(10, Type::Kitchen),
		Room(24, Type::Bedroom), Room(15, Type::Livingroom), Room(14, Type::Bathroom)});

	std::cout << "prop1: " << prop1 << std::endl;
	std::cout << "prop2: " << prop2 << std::endl;
	std::cout << "prop3: " << prop3 << std::endl;

	std::cout << "prop1.pct_area: " << prop1.pct_area({Type::Bedroom}) << std::endl;

	std::cout << prop1.is_luxurious() << std::endl;
	std::cout << prop3.is_luxurious() << std::endl;


	prop3.reorder({Type::Bathroom, Type::Livingroom});
	std::cout << "prop3: " << prop3 << std::endl;


	return 0;
}