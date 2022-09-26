cmake_minimum_required(VERSION 3.15)

project(Calculator)


# First build the base C++ library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../ ${CMAKE_CURRENT_BINARY_DIR}/base_lib)

# Then we make our C subset adapter library of the original C++ library
# and link it to a seperate library
file(GLOB calculator_c_sources "src/*.cpp")
add_library(calculator_c ${calculator_c_sources})
target_include_directories(calculator_c PUBLIC include/)
target_include_directories(calculator_c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_link_libraries(calculator_c PUBLIC calculator)
set_property(
    TARGET calculator_c PROPERTY PUBLIC_HEADER
    "include/calc_c.h"
)
install(TARGETS calculator_c
        RUNTIME DESTINATION bin COMPONENT Runtime
        LIBRARY DESTINATION lib COMPONENT Runtime
        PUBLIC_HEADER DESTINATION include/calc COMPONENT Development)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

if(BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    include(CTest)
    # Now we can go and use the c adapter lib in a c file
    add_executable(test_calc_c test/test_calc.c)
    target_include_directories(test_calc_c PUBLIC include/)
    target_link_libraries(test_calc_c PUBLIC calculator_c)
    add_test(NAME all_tests COMMAND test_calc_c)
endif()


