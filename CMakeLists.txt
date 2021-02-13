cmake_minimum_required(VERSION 3.17)
project(EditExec C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(DataStructureLibs)

add_executable(EditExec main.c)
target_link_libraries(EditExec DataStructureLibs/libs/libdoublylinkedlists.a)

add_subdirectory(test)