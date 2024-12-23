/**
 *  OTUS homework module
 *  #7 bulk terminal
 *  (c) 2024
 */

#include "hw07_terminal/terminal.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	// #7 HomeWork: terminal
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <block_size>" << std::endl;
		return 1;
	}

	size_t block_size = std::stoi(argv[1]);
	otus_cpp::terminal terminal_(block_size, std::cin, std::cout);
	terminal_.run();
	return 0;
}
