cmake_minimum_required(VERSION 4.0)
project(Parcial3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parcial3 main.cpp
        FunctionBFS.cpp
)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")