/**
 *  OTUS homework module
 *  #4 SFINAE
 *  (c) 2024
 */

#include "hw04_sfinae/ip_print.hpp"

#include <cstdint>
#include <list>
#include <string>
#include <tuple>
#include <vector>

int main(int, char **) {
	// 255
	otus_cpp::sfinae::print_ip(int8_t{-1});

	// 0.0
	otus_cpp::sfinae::print_ip(int16_t{0});

	// 127.0.0.1
	otus_cpp::sfinae::print_ip(int32_t{2130706433});

	// 123.45.67.89.101.112.131.41
	otus_cpp::sfinae::print_ip(int64_t{8875824491850138409});

	// Hello, World!
	otus_cpp::sfinae::print_ip(std::string{"Hello, World!"});

	// 100.200.300.400
	otus_cpp::sfinae::print_ip(std::vector<int>{100, 200, 300, 400});

	// 400.300.200.100
	otus_cpp::sfinae::print_ip(std::list<short>{400, 300, 200, 100});

	// 123.456.789.0
	otus_cpp::sfinae::print_ip(std::make_tuple(123, 456, 789, 0));

	return 0;
}
