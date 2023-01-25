#include <iostream>


class Matrix{
private:
	int arr[2][2];
public:
	Matrix(){}
	Matrix(int my_arr[2][2]){
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				arr[i][j] = my_arr[i][j];
			}
		}
	}
	Matrix(std::initializer_list<int[2]> l){
		int i = 0;
		for (auto ptr = l.begin(); ptr < l.end(); ptr++, i++){
			for (int j = 0; j < 2; j++){
				arr[i][j] = (*ptr)[j];
			}
		}
	}
	friend std::ostream& operator<<(std::ostream& o, const Matrix& m);
};

std::ostream& operator<<(std::ostream& o, const Matrix& m){
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			o << m.arr[i][j] << " ";
		}
		o << std::endl;
	}
	return o;
}


int main(int argc, char const *argv[])
{
	int arr_a[2][2] = {{0, 0}, {0, 0}};
	Matrix A( arr_a );
	Matrix B({{1, 0}, {0, 1}});
	// Matrix B = {{0, 0}, {0, 0}};
	// Matrix B = {0, 0, 0, 0};
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	return 0;
}