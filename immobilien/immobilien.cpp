#include <iostream>
#include <vector>

enum class Type {Kitchen, Bedroom, Livingroom, Bathroom};
std::vector<std::string> TYPE_NAMES = {"Kitchen", "Bedroom", "Living room", "Bathroom"};
// TYPE_NAEMS[static_cast<size_t>(my_type)]
// .at()

std::ostream& operator<< (std::ostream& os, const Type my_type){
	switch(my_type){
		case Type::Kitchen		: os << "Kitchen"; 		break;
		case Type::Bedroom		: os << "Bedroom"; 		break;
		case Type::Livingroom	: os << "Living Room"; 	break;
		case Type::Bathroom		: os << "Bathroom"; 	break;
		default					: os.setstate(std::ios_base::failbit);
	}
	return os;
}

class Room {
private:
	int area;
	Type type;
public:
	Room(int my_area, Type my_type = Type::Livingroom){
		area = my_area;
		type = my_type;
	}
	int getArea() const{
		return area;
	}
	Type getType() const{
		return type;
	}
	int usable_as (const std::vector<Type>& my_types) const{
		for (int i = 0; i < my_types.size(); i++){
			if (my_types[i] == type){
				return 1;
			}
		}
		return 0;
	}
	bool operator==(const Room &other) const{
		return (area == other.area) && (type == other.type);
	}
	// [areasqm,type]
	friend std::ostream& operator<<(std::ostream& os, const Room& my_room){
		os << "[" << my_room.area << "sqm, " << my_room.type << "]";
		return os;
	}
};


class Property{
public:
	std::string address;
	std::vector<Room> rooms;
public:
	Property(std::string my_address, std::vector<Room> my_rooms = { Room(60) }){
		address = my_address;
		rooms = my_rooms;
	}
	// [address:{listofrooms}],e.g.:
	// [Hugogasse12:{[54sqm living room], [13 sqm kitchen], [10 sqm bathroom]}]
	friend std::ostream& operator<<(std::ostream& o, const Property& p);

	double pct_area(const std::vector<Type> &types){
		int valid_area{0};
		int total_area{0};

		for (auto& room: rooms){
			total_area += room.getArea();
			if (room.usable_as(types)) valid_area += room.getArea();
		}

		return (static_cast<double>(valid_area) / total_area);
	}

	bool is_luxurious() const{
		// check if all room types are represented
		std::vector<Type> all_types = {Type::Kitchen, Type::Bedroom, Type::Livingroom, Type::Bathroom};
		for (auto my_type: all_types){
			if (std::none_of(
				rooms.begin(), 
				rooms.end(),
				[&](auto room){   return room.usable_as({my_type});   }
			)) return false;
		}

		// finding duplicates in this->rooms
		// my_room1 == my_room2

		int duplicates{0};
		for(int i{0}; i < 4; i++){
			for(int j{i+1}; j < 4; j++){
				if (rooms[i] == rooms[j]) duplicates++;
			}
		}
		if (duplicates == 0) return false;

		return true;
	}

	void reorder (const std::vector<Type> &my_types){
		// my_types = {Bathroom, Kitchen}
		// all_types = {Kitchen, Bedroom, Livingroom, Bathroom}

		std::stable_sort(
			rooms.begin(),
			rooms.end(),
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

};

std::ostream& operator<<(std::ostream& o, const Property& p){
	o << "[" << p.address << ":{";
	for (size_t i = 0; i < p.rooms.size(); i++){
		o << p.rooms.at(i);
		if (i != (p.rooms.size() - 1)) o << ", ";
	}
	o << "}]";
	return o;
}


int main() {
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








