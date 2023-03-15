cmake_minimum_required(VERSION 3.25)
project(asteroids)

find_package(SDL2 REQUIRED)


include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

add_executable(asteroids
        main.cpp drawer/Drawer.h asteroid/asteroid.cpp ship/ship.cpp drawer/Drawer.cpp drawer/Color.h drawer/Color.cpp physics/Physics.h physics/Physics.cpp)

target_link_libraries(asteroids ${SDL2_LIBRARIES})