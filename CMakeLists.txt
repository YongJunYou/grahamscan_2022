cmake_minimum_required(VERSION 3.0.0)
project(cmaketest VERSION 0.1.0)

include(CTest)
enable_testing()

get_filename_component(src_path src ABSOLUTE)
file(GLOB src_file ${src_path}/*.cpp)
add_executable(Proj ${src_file})

include_directories(include)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)