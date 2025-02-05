find_package(Eigen3 3.4 QUIET NO_MODULE)

if(NOT Eigen3_FOUND)
    if(CMAKE_VERSION VERSION_LESS 3.14)
        message(FATAL_ERROR
            "hw13 requires Eigen 3.4. No system Eigen was found, and the download "
            "fallback needs CMake 3.14 or newer (running ${CMAKE_VERSION}). "
            "Install libeigen3-dev, or upgrade CMake.")
    endif()
    include(FetchContent)
    FetchContent_Declare(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.4.0
    )
    set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(eigen)
endif()

otus_add_hw(
    NAME hw13_ml
    SOURCES src/hw13_ml_computer_vision/ml_classifier.cpp
    INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/include/hw13_ml_computer_vision
        ${CMAKE_SOURCE_DIR}/src/hw13_ml_computer_vision
    LINK_LIBS Eigen3::Eigen
    CLI_NAME ml_computer_vision
    CLI_SOURCE src/hw13_ml_computer_vision/main.cpp
    TESTS tests/test_hw13_ml_computer_vision.cpp
)

if(WITH_BOOST_TEST)
    set_tests_properties(test_hw13_ml_computer_vision PROPERTIES
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/ml)
endif()
