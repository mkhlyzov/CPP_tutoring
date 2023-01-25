#include <iostream>
#include <vector>
#include <string>

#include "property.h"


Property::Property(const std::string &my_address, const std::vector<Room> &my_rooms){
	this->address = my_address;
	this->rooms = my_rooms;
}

double Property::pct_area(const std::vector<Type> &types) const{
	int valid_area{0};
	int total_area{0};

	for (auto& room: this->rooms){
		total_area += room.getArea();
		if (room.usable_as(types)) valid_area += room.getArea();
	}

	return (static_cast<double>(valid_area) / total_area);
}

bool Property::is_luxurious() const{
	// check if all room types are represented
	std::vector<Type> all_types = {Type::Kitchen, Type::Bedroom, Type::Livingroom, Type::Bathroom};
	for (auto my_type: all_types){
		if (std::none_of(
			this->rooms.begin(), 
			this->rooms.end(),
			[&](auto room){ return room.usable_as({my_type}); }
		)) return false;
	}

	// finding duplicates in this->rooms
	// my_room1 == my_room2

	int number_of_duplicates{0};
	for(int i{0}; i < 4; i++){
		for(int j{i+1}; j < 4; j++){
			if (this->rooms[i] == this->rooms[j])
				number_of_duplicates++;
		}
	}
	if (number_of_duplicates == 0) return false;

	return true;
}

void Property::reorder(const std::vector<Type> &my_types){
	// my_types = {Bathroom, Kitchen}
	// all_types = {Kitchen, Bedroom, Livingroom, Bathroom}

	std::stable_sort(
		this->rooms.begin(),
		this->rooms.end(),
		[&my_types](const Room& lhs, const Room& rhs){
			int lhs_priority{100};
			int rhs_priority{100};

			for (int i{0}; i < my_types.size(); i++){
				if (my_types[i] == lhs.getType()) lhs_priority = i;
				if (my_types[i] == rhs.getType()) rhs_priority = i;
			}

			return (lhs_priority < rhs_priority);
		}
	);
}

// [address:{listofrooms}],e.g.:
// [Hugogasse12:{[54sqm living room], [13 sqm kitchen], [10 sqm bathroom]}]
std::ostream& operator<<(std::ostream& o, const Property& p){
	o << "[" << p.address << ":{";
	for (size_t i = 0; i < p.rooms.size(); i++){
		o << p.rooms.at(i);
		if (i != (p.rooms.size() - 1)) o << ", ";
	}
	o << "}]";
	return o;
}