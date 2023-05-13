cmake_minimum_required(VERSION 3.25)
project(asteroids)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_gfx REQUIRED)



include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

add_executable(asteroids
        main.cpp drawer/Drawer.h object/Ship.cpp drawer/Drawer.cpp drawer/Color.h drawer/Color.cpp physics/Physics.h physics/Physics.cpp physics/Vec2d.h physics/Vec2d.cpp physics/Matrix2d.h physics/Matrix2d.cpp object/Object.h object/Object.cpp object/Asteroid.h object/Asteroid.cpp physics/CollisionBox.h physics/CollisionBox.cpp drawer/DrawLoop.h drawer/DrawLoop.cpp physics/util.h object/Dummy.h object/Dummy.cpp object/projectiles/Rocket.h object/projectiles/Rocket.cpp drawer/text/Font.h drawer/text/Font.cpp world/World.h world/World.cpp object/effects/Smoke.h object/effects/Smoke.cpp physics/util.cpp object/projectiles/Projectile.h object/projectiles/Projectile.cpp object/projectiles/Bullet.h object/projectiles/Bullet.cpp object/Text.h object/Text.cpp object/effects/Shockwave.h object/effects/Shockwave.cpp object/projectiles/Laser.h object/projectiles/Laser.cpp)

target_link_libraries(${PROJECT_NAME} SDL2::Main  SDL2::GFX SDL2::TTF)
