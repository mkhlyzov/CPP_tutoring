#include "complex.h"

Complex::Complex(int x) {
	data = x;
}

int Complex::getData() const{
	return data;
}

// bool Complex::operator==(const Complex& other){
// 	return (other.data == data);
// }

bool operator==(const Complex& lhs, const Complex& rhs){
	return (lhs.data == rhs.data);
	// return (lhs.getData() == rhs.getData());
}