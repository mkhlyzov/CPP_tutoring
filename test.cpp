#include <iostream>
#include <cassert>
#include <vector>
#include <string>

void countdown(int n){
	if (n == 0){
		std::cout << "We are finished!" << std::endl;
		return;
	}
	std::cout << n << std::endl;
	return countdown(n - 1);
}


int main(){

	// // Question 1
	// char x = 'abc';
	// std::cout << x << std::endl;

	// // Question 2
	// {
	// 	int x = 1;
	// }
	// std::cout << x << std::endl;

	// // Question 3
	// int arr[10];
	// arr[21] = 5;
	// std::cout << arr[21] << std::endl;

	// // Question 4
	// int arr2[] = {0, 2, 4, 6, 14, 15};
	// for (auto& i: arr2){
	// 	std::cout << i << std::endl;
	// }

	// // Question 5

	// countdown(1000000);

	// // Question 6

	// char a = 'a';
	// char b = 'b';
	// char c = 'c';
	// std::cout << &a << std::endl;
	// std::cout << &b << std::endl;
	// std::cout << &c << std::endl;

	// // Question 7

	// int x = 11;
	// int& y = x;
	// y = 7;

	// std::cout << "x value is  : " << x << std::endl;
	// std::cout << "x address is: " << &x << std::endl;
	// std::cout << "y value is  : " << y << std::endl;
	// std::cout << "y address is: " << &y << std::endl;
	
	// Question 8

	// std::cout << sizeof(char) << std::endl; // 1
	// std::cout << sizeof(int) << std::endl;	// 4
	// std::cout << sizeof(double) << std::endl; // 8
	// std::cout << std::endl;
	// std::cout << sizeof(char*) << std::endl; // 16
	// std::cout << sizeof(int*) << std::endl; // 64
	// std::cout << sizeof(double*) << std::endl; // 128

	// // Below is a code that helps us understand the nature of
	// // pointer data type. Pointers store addresses so they needs enough
	// // memory to write address down. sizeof(pointer) is "length"
	// // of address in our OS.
	// char c;
	// int i;
	// double d;
	// std::cout << static_cast<void*>(&c) << std::endl;
	// std::cout << &i << std::endl;
	// std::cout << &d << std::endl;	

	// // Question 9

	// int arr[] = {2, 4, 6, 8, 10};
	// std::cout << *(arr + 2) << std::endl;
	// std::cout << 2[arr] << std::endl;

	// // Question 10

	// int n;
	// std::cin >> n;
	// int arr[n];
	// for (int i = 0; i < n; i++){
	// 	arr[i] = i;
	// }

	// // Question 11

	// std::string s1 = "this is a string!";
	// std::string s2;
	// std::cout << "s1 = " << s1 << std::endl;
	// std::cout << "s2 = " << s2 << std::endl;

	// s2 = static_cast<std::string&&>(s1);
	// std::cout << "s1 = " << s1 << std::endl;
	// std::cout << "s2 = " << s2 << std::endl;

	// Question 12



	return 0;
}
