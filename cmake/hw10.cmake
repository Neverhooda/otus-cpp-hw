find_package(Threads REQUIRED)

otus_add_hw(
    NAME hw10_network_terminal
    SOURCES
        src/hw10_network_terminal/bulk_session.cpp
        src/hw10_network_terminal/decorator_async.cpp
        src/hw10_network_terminal/network_terminal.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw10_network_terminal
        ${CMAKE_SOURCE_DIR}/src/hw10_network_terminal
    LINK_LIBS Threads::Threads hw09_async_terminal_lib
    CLI_NAME bulk_server
    CLI_SOURCE src/hw10_network_terminal/main.cpp
    TESTS tests/test_hw10_network_terminal.cpp
)
