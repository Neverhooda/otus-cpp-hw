otus_add_hw(
    NAME hw06_matrix
    INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/hw06_matrix
    CLI_NAME hw_n_matrix_cli
    CLI_SOURCE src/hw06_matrix/main.cpp
    TESTS tests/test_hw06_matrix.cpp
)
