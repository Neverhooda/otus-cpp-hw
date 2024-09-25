/**
 *  OTUS homework module
 *  #2 ip filter
 *  (c) 2024
 */

#include "hw02_filter/ip_filter.hpp"
#include "hw02_filter/split.hpp"

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int, char **) {
	using namespace otus_cpp;

	std::vector<uint32_t> ip_pool;
	for (std::string line; std::getline(std::cin, line);) {
		std::vector<std::string> out;
		split(std::begin(line), std::end(line), std::back_inserter(out), '\t',
		      [](auto it_a, auto it_b) { return std::string(it_a, it_b); });
		ip_pool.push_back(ip_filter::cast_ip_to_int(out[0]));
	}

	std::sort(ip_pool.begin(), ip_pool.end(), std::greater<uint32_t>());
	ip_filter::print(ip_pool);

	auto pool_filtred_by_firts = ip_filter::filter(ip_pool, 1);
	ip_filter::print(pool_filtred_by_firts);

	auto pool_filtred_by_firts_second = ip_filter::filter(ip_pool, 46, 70);
	ip_filter::print(pool_filtred_by_firts_second);

	auto pool_filtred_by_any = ip_filter::filter_any(ip_pool, 46);
	ip_filter::print(pool_filtred_by_any);

	return 0;
}
