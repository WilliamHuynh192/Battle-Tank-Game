cmake_minimum_required(VERSION 3.23)

project(battle_tank)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(battle_tank ${PROJECT_SOURCE_DIR}/src/battle_tank.cpp)

# Set the subsystem to Windowse
set_target_properties(battle_tank PROPERTIES
    WIN32_EXECUTABLE YES
    LINK_FLAGS "/SUBSYSTEM:WINDOWS"
)

install(TARGETS battle_tank RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
