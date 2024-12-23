otus_add_hw(
    NAME hw07_terminal
    SOURCES
        src/hw07_terminal/command_handler.cpp
        src/hw07_terminal/command_parser.cpp
        src/hw07_terminal/terminal.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw07_terminal
        ${CMAKE_SOURCE_DIR}/src/hw07_terminal
    CLI_NAME bulk
    CLI_SOURCE src/hw07_terminal/main.cpp
    TESTS tests/test_hw07_terminal.cpp
)
