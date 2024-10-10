/**
 *  OTUS homework module
 *  #3 custom allocator
 *  (c) 2024
 */

#include "hw03_alloc/custom_allocator.hpp"
#include "hw03_alloc/custom_vector.hpp"
#include "hw03_alloc/number_sequence.hpp"

#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <utility>

int main(int, char **) {
	using namespace otus_cpp;

	static constexpr std::array numbers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// Creating an instance of std::map<int, int>
	auto map_std_allocator = std::map<int, int>();
	// Filling it with 10 elements, where the key is a number from 0 to 9,
	// and the value is the factorial of the key
	for (const auto &x : numbers) {
		map_std_allocator.emplace(x, factorial(x));
	}

	// Creating an instance of std::map<int, int> with a new allocator
	// limited to 10 elements
	auto map_custom_allocator =
	    std::map<int, int, std::less<>,
	             custom_allocator<std::pair<const int, int>, 10>>{};
	// Filling it with 10 elements, where the key is a number from 0 to 9,
	// and the value is the factorial of the key
	for (const auto &x : numbers) {
		map_custom_allocator.emplace(x, factorial(x));
	}
	// Displaying all values (key and value separated by a space) stored in
	// the container
	for (const auto &[key, val] : map_custom_allocator) {
		std::cout << key << " " << val << std::endl;
	}

	// Creating an instance of a custom container for storing values of type
	// int
	auto vector_std_allocator = custom_vector<int>();
	// Filling it with 10 elements from 0 to 9
	for (const auto &x : numbers) {
		vector_std_allocator.push_back(x);
	}

	// Creating an instance of a custom container for storing values of type
	// int with a new allocator limited to 10 elements
	auto vector_custom_allocator =
	    custom_vector<int, custom_allocator<int, 10>>();
	// Filling it with 10 elements from 0 to 9
	for (const auto &x : numbers) {
		vector_custom_allocator.push_back(x);
	}
	// Displaying all values stored in the container
	for (const auto &val : vector_custom_allocator) {
		std::cout << val << std::endl;
	}

	return 0;
}
