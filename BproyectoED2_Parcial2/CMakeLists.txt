cmake_minimum_required(VERSION 3.8)
project(BproyectoED2_Parcial2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Nodo.cpp Nodo.h arbolB.cpp arbolB.h)
add_executable(BproyectoED2_Parcial2 ${SOURCE_FILES})