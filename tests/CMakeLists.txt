cmake_minimum_required(VERSION 3.0)

project(game_tests)

enable_testing()


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(../inc)

 
file(GLOB SRC *.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..) 

add_executable(test_test ${SRC} 
                        ../src/Archer.cpp
                        ../src/Base.cpp
                        ../src/Catapult.cpp
                        ../src/Commander.cpp
                        ../src/File_parser.cpp
                        ../src/Floodfill.cpp
                        ../src/Game_state.cpp
                        ../src/Knight.cpp
                        ../src/Pikeman.cpp
                        ../src/Ram.cpp
                        ../src/Swordsman.cpp
                        ../src/Unit.cpp
                        ../src/Worker.cpp
                        ../src/Enemie_forces_analysis.cpp)
target_link_libraries(test_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)




