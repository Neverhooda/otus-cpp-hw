find_package(Threads REQUIRED)

otus_add_hw(
    NAME hw12_map_reduce
    SOURCES
        src/hw12_map_reduce/map_reduce.cpp
        src/hw12_map_reduce/utility.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw12_map_reduce
        ${CMAKE_SOURCE_DIR}/src/hw12_map_reduce
    LINK_LIBS Threads::Threads
    CLI_NAME mapreduce
    CLI_SOURCE src/hw12_map_reduce/main.cpp
    TESTS tests/test_hw12_map_reduce.cpp
)
