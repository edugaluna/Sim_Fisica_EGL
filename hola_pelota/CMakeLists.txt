cmake_minimum_required(VERSION 3.26)
project(hola_pelota)

set(CMAKE_CXX_STANDARD 17)

add_executable(hola_pelota main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(hola_pelota PRIVATE box2d::box2d)