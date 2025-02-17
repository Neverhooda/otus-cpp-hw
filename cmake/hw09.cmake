find_package(Threads REQUIRED)

otus_add_hw(
    NAME hw09_async_terminal
    SOURCES
        src/hw09_async_terminal/async.cpp
        src/hw09_async_terminal/async_process.cpp
        src/hw09_async_terminal/async_terminal.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw09_async_terminal
        ${CMAKE_SOURCE_DIR}/src/hw09_async_terminal
    LINK_LIBS Threads::Threads hw07_terminal_lib
    CLI_NAME async_cli
    CLI_SOURCE src/hw09_async_terminal/main.cpp
    TESTS tests/test_hw09_async.cpp
)
