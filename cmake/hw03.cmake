otus_add_hw(
    NAME hw03_alloc
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw03_alloc
        ${CMAKE_SOURCE_DIR}/src/hw03_alloc
    CLI_NAME hw_allocator_cli
    CLI_SOURCE src/hw03_alloc/main.cpp
    TESTS
        tests/test_hw03_custom_allocator.cpp
        tests/test_hw03_custom_vector.cpp
)
