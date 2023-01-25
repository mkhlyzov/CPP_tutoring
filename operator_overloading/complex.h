#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <iostream>

class Complex{
private:
	int data;
public:
	Complex(int x);
	int getData() const;
	std::ostream operator<<(std::ostream&);

	// bool operator== (const Complex& other);
	friend bool operator==(const Complex&, const Complex&);
};


#endif