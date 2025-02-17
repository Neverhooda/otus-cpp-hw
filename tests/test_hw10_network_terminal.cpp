/**
 *  OTUS homework test module
 *  (c) 2025
 */

#define BOOST_TEST_MODULE test_hw10_network_terminal

#include "hw10_network_terminal/network_terminal.hpp"

#include <boost/test/unit_test.hpp>

#include <chrono>
#include <thread>

namespace {

short pick_free_port() {
	boost::asio::io_context probe_context;
	boost::asio::ip::tcp::acceptor probe(
	    probe_context,
	    boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 0));
	auto port = probe.local_endpoint().port();
	probe.close();
	return static_cast<short>(port);
}

bool try_connect(short port) {
	boost::asio::io_context client_context;
	boost::asio::ip::tcp::socket socket(client_context);
	boost::system::error_code error;
	socket.connect(boost::asio::ip::tcp::endpoint(
	                   boost::asio::ip::make_address("127.0.0.1"), port),
	               error);
	return !error;
}

} // namespace

BOOST_AUTO_TEST_SUITE(test_hw10_network_terminal)

BOOST_AUTO_TEST_CASE(test_server_accepts_connection) {
	const short port = pick_free_port();
	boost::asio::io_context io_context;
	otus_cpp::nw_async::server server(io_context, port, 3);

	std::thread worker([&io_context] { io_context.run(); });

	BOOST_CHECK(try_connect(port));

	server.stop();
	io_context.stop();
	worker.join();
}

BOOST_AUTO_TEST_CASE(test_server_accepts_several_connections) {
	const short port = pick_free_port();
	boost::asio::io_context io_context;
	otus_cpp::nw_async::server server(io_context, port, 3);

	std::thread worker([&io_context] { io_context.run(); });

	BOOST_CHECK(try_connect(port));
	BOOST_CHECK(try_connect(port));

	server.stop();
	io_context.stop();
	worker.join();
}

BOOST_AUTO_TEST_SUITE_END()
