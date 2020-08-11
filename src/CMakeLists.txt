cmake_minimum_required (VERSION 3.17)

add_executable (Pong "main.cpp" "Engine.h" "Coord.h" "Engine.cpp" "GameBoard.h" "Ball.h" "GameBoard.cpp")

find_package(SDL2 REQUIRED)

target_include_directories(Pong PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(Pong PRIVATE ${SDL2_LIBRARY})