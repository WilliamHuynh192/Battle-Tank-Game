cmake_minimum_required(VERSION 3.23)

project(battle_tank)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

message(STATUS "sdl2 image: ${SDL2_image_INCLUDE_DIR}")

include(${PROJECT_SOURCE_DIR}/src/sources.cmake)

add_executable(battle_tank ${PROJECT_SOURCE_DIR}/src/battle_tank.cpp ${BATTLE_TANK_SOURCES})

target_include_directories(battle_tank PRIVATE ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/textures)

target_link_libraries(battle_tank
    SDL2::SDL2main
    SDL2_image::SDL2_image
)

install(TARGETS battle_tank RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
