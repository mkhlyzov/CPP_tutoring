#include <iostream>
#include <vector>

#include "room.h"


std::vector<std::string> TYPE_NAMES = {"Kitchen", "Bedroom", "Living room", "Bathroom"};
// TYPE_NAEMS[static_cast<size_t>(my_type)]
// .at()

std::ostream& operator<< (std::ostream& os, const Type &my_type){
	switch(my_type){
		case Type::Kitchen		: os << "Kitchen"; 		break;
		case Type::Bedroom		: os << "Bedroom"; 		break;
		case Type::Livingroom	: os << "Living Room"; 	break;
		case Type::Bathroom		: os << "Bathroom"; 	break;
		default					: os.setstate(std::ios_base::failbit);
	}
	return os;
}


Room::Room(const int &my_area, const Type &my_type){
	this->area = my_area;
	this->type = my_type;
}

int Room::getArea() const{
	return this->area;
}

Type Room::getType() const{
	return this->type;
}

int Room::usable_as(const std::vector<Type>& my_types) const{
	for (int i = 0; i < my_types.size(); i++){
		if (my_types[i] == this->type){
			return 1;
		}
	}
	return 0;
}

bool Room::operator==(const Room &rhs) const{
	return (this->area == rhs.area) && (this->type == rhs.type);
}

// [areasqm,type]
std::ostream& operator<<(std::ostream& os, const Room& my_room){
	os << "[" << my_room.area << "sqm, " << my_room.type << "]";
	return os;
}
