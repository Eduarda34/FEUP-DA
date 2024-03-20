cmake_minimum_required(VERSION 3.27)
project(DA_project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA_project1 main.cpp
        cities.cpp
        cities.h
        menu.cpp
        menu.h
        pipes.cpp
        pipes.h
        reservoirs.cpp
        reservoirs.h
        stations.cpp
        stations.h
        main.cpp
        Data.cpp
        Data.h
)
