otus_add_hw(
    NAME hw04_sfinae
    INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/hw04_sfinae
    CLI_NAME hw_sfinae_cli
    CLI_SOURCE src/hw04_sfinae/main.cpp
    TESTS tests/test_hw04_sfinae.cpp
)
