cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 1.2.${PATCH_VERSION})

project(otus_cpp_hw VERSION ${PROJECT_VESRION})

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

configure_file(version.h.in version.h)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include(${CMAKE_SOURCE_DIR}/cmake/otus_hw.cmake)

if(WITH_BOOST_TEST)
    enable_testing()
endif()


include(${CMAKE_SOURCE_DIR}/cmake/hw01.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/hw02.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/hw03.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/hw04.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/hw05.cmake)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME "otus-cpp-hw")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT neverhooda@gmail.com)
include(CPack)
