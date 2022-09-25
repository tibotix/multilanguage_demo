cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Calculator)



file(GLOB calculator_sources "src/*.cpp")
# Note: To build a shared library, use -DBUILD_SHARED_LIBS=ON when configuring.
add_library(calculator ${calculator_sources})
target_include_directories(calculator PUBLIC include)
set_property(
    TARGET calculator PROPERTY PUBLIC_HEADER
    "include/calc.h"
    "include/errors.h"    
)
install(TARGETS calculator 
        RUNTIME DESTINATION bin COMPONENT Runtime
        LIBRARY DESTINATION lib COMPONENT Runtime
        PUBLIC_HEADER DESTINATION include/calc COMPONENT Development)


if(BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    include(CTest)
    file(GLOB test_sources "tests/test_*.cpp")
    add_executable(calculator_test tests/main.cpp ${test_sources})
    target_include_directories(calculator_test PUBLIC include)
    target_include_directories(calculator_test PRIVATE extern/catch2/include)
    target_link_libraries(calculator_test PRIVATE calculator)
    add_test(NAME all_tests COMMAND calculator_test)
endif()
