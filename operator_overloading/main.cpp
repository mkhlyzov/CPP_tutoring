#include <iostream>
#include "complex.h"

int main(){
	Complex c1(5);
	Complex c2(4);
	Complex c3(5);

	std::cout << (c1 == c3) << std::endl;
	std::cout << (c1 == Complex(5)) << std::endl;
	std::cout << (Complex(5) == c2) << std::endl;
	std::cout << (Complex(5) == Complex(3)) << std::endl;
	std::cout << (c2 == 9) << std::endl;
	
	std::cout << (9 == c2) << std::endl;


	return 0;
}