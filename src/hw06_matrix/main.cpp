/**
 *  OTUS homework module
 *  #6 N matrix
 *  (c) 2024
 */

#include "hw06_matrix/custom_matrix.hpp"

#include <iostream>
#include <tuple>

int main(int, char **) {
	using namespace otus_cpp;

	custom_matrix<int, 2> matrix(0);
	const int size = 10;
	for (int i = 0; i < size; ++i) {
		matrix[i][i] = i;
	}

	for (int i = 0; i < size; ++i) {
		matrix[i][size - 1 - i] = 9 - i;
	}

	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Total size " << matrix.size() << std::endl;

	for (auto [key_x, key_y, value] : matrix) {
		std::cout << "key_x: " << key_x << ", key_y: " << key_y
		          << ", value: " << value << std::endl;
	}

	((matrix[100][100] = 314) = 0) = 217;
	std::cout << "((matrix[100][100] = 314) = 0) = 217; result: "
	          << matrix[100][100] << std::endl;

	custom_matrix<int, 3> matrixn(0);
	matrixn[0][0][0] = 0;
	matrixn[1][1][1] = 1;
	matrixn[2][2][2] = 2;
	std::cout << "n-matrix: matrixn[x][y][z]" << std::endl;
	for (auto c : matrixn) {
		int x;
		int y;
		int z;
		int v;
		std::tie(x, y, z, v) = c;
		std::cout << "x: " << x << ", y: " << y << ", z: " << z << ", v: " << v
		          << std::endl;
	}

	return 0;
}
