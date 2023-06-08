cmake_minimum_required(VERSION 3.23)
project(Batalla_Naval)

set(CMAKE_CXX_STANDARD 14)

include_directories(libs)

add_executable(Batalla_Naval
        libs/barco.cpp
        libs/barco.h
        libs/jugador.cpp
        libs/jugador.h
        libs/jugador_cpu.cpp
        libs/jugador_cpu.h
        libs/jugador_humano.cpp
        libs/jugador_humano.h
        libs/tablero.cpp
        libs/tablero.h
        main.cpp)
