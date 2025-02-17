find_package(Threads REQUIRED)

otus_add_hw(
    NAME hw11_join_server
    SOURCES
        src/hw11_join_server/join_server.cpp
        src/hw11_join_server/join_session.cpp
        src/hw11_join_server/table_keeper.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw11_join_server
        ${CMAKE_SOURCE_DIR}/src/hw11_join_server
    LINK_LIBS Threads::Threads
    CLI_NAME join_server
    CLI_SOURCE src/hw11_join_server/main.cpp
    TESTS tests/test_hw11_join_server.cpp
)
