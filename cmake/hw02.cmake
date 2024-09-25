otus_add_hw(
    NAME hw02_filter
    SOURCES src/hw02_filter/ip_filter.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw02_filter
        ${CMAKE_SOURCE_DIR}/src/hw02_filter
    CLI_NAME ip_filter_cli
    CLI_SOURCE src/hw02_filter/main.cpp
    TESTS tests/test_hw02_ip_filter.cpp
)
