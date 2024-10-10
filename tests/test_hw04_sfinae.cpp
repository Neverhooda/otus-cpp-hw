/**
 *  OTUS homework test module
 *  (c) 2024
 */

#define BOOST_TEST_MODULE test_hw04_sfinae

#include "hw04_sfinae/container_trait.hpp"
#include "hw04_sfinae/ip_print.hpp"

#include <boost/test/unit_test.hpp>

#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

namespace {

std::string capture_print_ip(const std::function<void()> &action) {
	std::ostringstream buffer;
	auto *old = std::cout.rdbuf(buffer.rdbuf());
	action();
	std::cout.rdbuf(old);
	return buffer.str();
}

} // namespace

BOOST_AUTO_TEST_SUITE(test_hw04_sfinae)

BOOST_AUTO_TEST_CASE(test_is_container) {
	BOOST_CHECK(otus_cpp::sfinae::is_container<std::vector<int>>::value);
	BOOST_CHECK(otus_cpp::sfinae::is_container<std::list<short>>::value);
	BOOST_CHECK(!otus_cpp::sfinae::is_container<int>::value);
	BOOST_CHECK(!otus_cpp::sfinae::is_container<std::string>::value);
}

BOOST_AUTO_TEST_CASE(test_is_tuple) {
	BOOST_CHECK((otus_cpp::sfinae::is_tuple<std::tuple<int, int>>::value));
	BOOST_CHECK(!otus_cpp::sfinae::is_tuple<std::vector<int>>::value);
}

BOOST_AUTO_TEST_CASE(test_is_equale_types) {
	BOOST_CHECK((otus_cpp::sfinae::is_equale_types_v<int, int, int>));
	BOOST_CHECK((!otus_cpp::sfinae::is_equale_types_v<int, char, int>));
}

BOOST_AUTO_TEST_CASE(test_print_ip_integral) {
	BOOST_CHECK_EQUAL(
	    capture_print_ip([] { otus_cpp::sfinae::print_ip(int8_t{-1}); }),
	    "255\n");
	BOOST_CHECK_EQUAL(
	    capture_print_ip([] { otus_cpp::sfinae::print_ip(int16_t{0}); }),
	    "0.0\n");
	BOOST_CHECK_EQUAL(
	    capture_print_ip(
	        [] { otus_cpp::sfinae::print_ip(int32_t{2130706433}); }),
	    "127.0.0.1\n");
}

BOOST_AUTO_TEST_CASE(test_print_ip_string) {
	BOOST_CHECK_EQUAL(capture_print_ip([] {
		                  otus_cpp::sfinae::print_ip(
		                      std::string{"Hello, World!"});
	                  }),
	                  "Hello, World!\n");
}

BOOST_AUTO_TEST_CASE(test_print_ip_container) {
	BOOST_CHECK_EQUAL(capture_print_ip([] {
		                  otus_cpp::sfinae::print_ip(
		                      std::vector<int>{100, 200, 300, 400});
	                  }),
	                  "100.200.300.400\n");
	BOOST_CHECK_EQUAL(capture_print_ip([] {
		                  otus_cpp::sfinae::print_ip(
		                      std::list<short>{400, 300, 200, 100});
	                  }),
	                  "400.300.200.100\n");
}

BOOST_AUTO_TEST_CASE(test_print_ip_tuple) {
	BOOST_CHECK_EQUAL(capture_print_ip([] {
		                  otus_cpp::sfinae::print_ip(
		                      std::make_tuple(123, 456, 789, 0));
	                  }),
	                  "123.456.789.0\n");
}

BOOST_AUTO_TEST_SUITE_END()
