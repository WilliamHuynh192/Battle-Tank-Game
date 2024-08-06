cmake_minimum_required(VERSION 3.23)

project(battle_tank)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)

add_executable(battle_tank ${PROJECT_SOURCE_DIR}/src/battle_tank.cpp)

target_link_libraries(battle_tank
    SDL2::SDL2main
)

install(TARGETS battle_tank RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
