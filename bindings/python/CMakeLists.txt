cmake_minimum_required(VERSION 3.15)

project(calculator_py)

# First build the base C++ library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../ ${CMAKE_CURRENT_BINARY_DIR}/base_lib)

# Then build the python bindings and link against the base lib
add_subdirectory(extern/pybind11)
file(GLOB bindings_sources "src/*.cpp")
pybind11_add_module(calculatorpy ${bindings_sources})
target_include_directories(calculatorpy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_compile_definitions(calculatorpy PRIVATE VERSION_INFO=${VERSION_INFO})
target_compile_definitions(calculatorpy PRIVATE PYBIND11_USE_SMART_HOLDER_AS_DEFAULT)
target_link_libraries(calculatorpy PRIVATE calculator)