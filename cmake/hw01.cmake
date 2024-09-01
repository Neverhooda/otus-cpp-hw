otus_add_hw(
    NAME hw01_version
    SOURCES src/hw01_version/lib_version.cpp
    INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/hw01_version
    CLI_NAME helloworld_cli
    CLI_SOURCE src/hw01_version/main.cpp
    TESTS tests/test_hw01_version.cpp
)
