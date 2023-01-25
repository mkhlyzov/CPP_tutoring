#ifndef ROOM_H
#define ROOM_H


enum class Type {Kitchen, Bedroom, Livingroom, Bathroom};
std::ostream& operator<< (std::ostream& os, const Type &my_type);


class Room {
private:
	int area;
	Type type;
public:
	Room(const int &my_area, const Type &my_type = Type::Livingroom);

	int getArea() const;
	Type getType() const;

	int usable_as (const std::vector<Type>& my_types) const;
	bool operator==(const Room &rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const Room& my_room);
};

#endif