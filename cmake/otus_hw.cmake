function(otus_set_target_options target)
    set_target_properties(${target} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -pedantic -Werror)
    endif()
endfunction()

function(otus_add_hw)
    cmake_parse_arguments(HW
        ""
        "NAME;CLI_NAME;CLI_SOURCE"
        "SOURCES;INCLUDE_DIRS;TESTS;LINK_LIBS"
        ${ARGN})

    if(NOT HW_NAME)
        message(FATAL_ERROR "otus_add_hw: NAME is required")
    endif()

    set(common_dirs
        ${CMAKE_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
        ${HW_INCLUDE_DIRS})

    if(HW_SOURCES)
        set(hw_lib ${HW_NAME}_lib)
        add_library(${hw_lib} STATIC ${HW_SOURCES})
        target_include_directories(${hw_lib} PUBLIC ${common_dirs})
        otus_set_target_options(${hw_lib})
        if(HW_LINK_LIBS)
            target_link_libraries(${hw_lib} PUBLIC ${HW_LINK_LIBS})
        endif()
    else()
        set(hw_lib ${HW_NAME}_headers)
        add_library(${hw_lib} INTERFACE)
        target_include_directories(${hw_lib} INTERFACE ${common_dirs})
        if(HW_LINK_LIBS)
            target_link_libraries(${hw_lib} INTERFACE ${HW_LINK_LIBS})
        endif()
    endif()

    if(HW_CLI_SOURCE)
        if(NOT HW_CLI_NAME)
            message(FATAL_ERROR "otus_add_hw: CLI_SOURCE given without CLI_NAME")
        endif()
        add_executable(${HW_CLI_NAME} ${HW_CLI_SOURCE})
        target_link_libraries(${HW_CLI_NAME} PRIVATE ${hw_lib})
        otus_set_target_options(${HW_CLI_NAME})
        install(TARGETS ${HW_CLI_NAME} RUNTIME DESTINATION bin)
    endif()

    if(WITH_BOOST_TEST)
        foreach(test_src IN LISTS HW_TESTS)
            get_filename_component(test_name ${test_src} NAME_WE)
            add_executable(${test_name} ${test_src})
            target_link_libraries(${test_name} PRIVATE
                ${hw_lib}
                Boost::unit_test_framework)
            target_compile_definitions(${test_name} PRIVATE BOOST_TEST_DYN_LINK)
            otus_set_target_options(${test_name})
            add_test(NAME ${test_name} COMMAND ${test_name})
        endforeach()
    endif()
endfunction()
