cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Calculator)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")


if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

set(calculator_sources
    src/calc.cpp
)
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
    set(calculator_test_sources
        tests/main.cpp
        tests/test_calculator.cpp 
    )
    add_executable(calculator_test ${calculator_test_sources})
    target_include_directories(calculator_test PUBLIC include)
    target_include_directories(calculator_test PRIVATE extern/catch2/include)
    target_link_libraries(calculator_test PRIVATE calculator)
    add_test(NAME all_tests COMMAND calculator_test)
    if(CODE_COVERAGE)
        include(CodeCoverage)
        append_coverage_compiler_flags()
        target_compile_options(calculator PUBLIC -O0)

        setup_target_for_coverage_gcovr_xml(
            NAME calculator_test_coverage
            EXECUTABLE calculator_test
            DEPENDENCIES calculator_test calculator
            BASE_DIRECTORY "src/"
        )
    endif()
endif()
