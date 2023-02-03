#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <vector>

#include "room.h"


class Property{
public:
	std::string address;
	std::vector<Room> rooms;
public:
	Property(const std::string& my_address, const std::vector<Room> &my_rooms = { Room(60) });
	
	friend std::ostream& operator<<(std::ostream&, const Property&);

	double pct_area(const std::vector<Type> &types) const;
	bool is_luxurious() const;
	void reorder (const std::vector<Type> &my_types);
	void reorder1(const std::vector<Type> &my_types);
};

#endif