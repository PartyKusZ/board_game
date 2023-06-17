cmake_minimum_required(VERSION 3.0)

project(game)

include_directories(inc)

 
file(GLOB SRC src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..) 

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
#target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics)


