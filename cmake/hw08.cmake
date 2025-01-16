find_package(Boost REQUIRED COMPONENTS filesystem program_options)

otus_add_hw(
    NAME hw08_boost
    SOURCES
        src/hw08_boost/file_parser.cpp
        src/hw08_boost/hash.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw08_boost
        ${CMAKE_SOURCE_DIR}/src/hw08_boost
    LINK_LIBS Boost::filesystem Boost::program_options
    CLI_NAME bayan
    CLI_SOURCE src/hw08_boost/main.cpp
    TESTS tests/test_hw08_boost.cpp
)
