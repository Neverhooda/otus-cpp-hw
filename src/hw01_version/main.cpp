/**
 *  OTUS homework module
 *  #1 hello world
 *  (c) 2024
 */

#include "hw01_version/lib_version.hpp"

#include <iostream>

int main(int, char **) {
	std::cout << "Version: " << otus_cpp::version() << std::endl;
	std::cout << "Hello, world!" << std::endl;
	return 0;
}
