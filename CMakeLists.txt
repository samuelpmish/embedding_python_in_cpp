cmake_minimum_required(VERSION 3.8)
project(embedding_python LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(pybind11)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(mylib ${sources})
target_include_directories(mylib PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_precompile_headers(mylib PRIVATE ${PROJECT_SOURCE_DIR}/src/pch.hpp)
target_link_libraries(mylib PRIVATE pybind11::embed)

add_executable(driver driver.cpp)
target_link_libraries(driver PRIVATE mylib)

if (ENABLE_ASAN)
  add_link_options(-fsanitize=address)
  add_compile_options(-fsanitize=address)
endif()

if (ENABLE_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
