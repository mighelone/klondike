set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# extra path
#include_directories ("/Users/vascella/.local/include")
include_directories("./src")
#link_directories ("/Users/vascella/.local/lib")

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)

#get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#string(REPLACE " " "_" ProjectId ${ProjectId})
#project(${ProjectId})
set(ProjectId "klondike")
project(${ProjectId} VERSION 0.1 LANGUAGES CXX)

file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

add_library(${ProjectId} SHARED ${project_sources})


# testCard
add_executable(testCard.x tests/testCard.cpp)
target_link_libraries(testCard.x ${ProjectId} gtest)

# testStack
add_executable(testStack.x tests/testStack.cpp)
target_link_libraries(testStack.x ${ProjectId} gtest)

# testFoundations
add_executable(testFoundation.x tests/testFoundation.cpp)
target_link_libraries(testFoundation.x ${ProjectId} gtest)

#testGame
add_executable(testGame.x tests/testGame.cpp)
target_link_libraries(testGame.x ${ProjectId} gtest)

add_executable(klondike.x klondike.cpp)
target_link_libraries(klondike.x ${ProjectId})




add_executable(testRun.x tests/test.cpp)
target_link_libraries(testRun.x ${ProjectId})
