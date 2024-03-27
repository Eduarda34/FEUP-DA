cmake_minimum_required(VERSION 3.27)
project(DA_project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA_project1 src/.cpp/main.cpp
        src/.cpp/cities.cpp
        src/.h/cities.h
        src/.cpp/Data.cpp
        src/.h/Data.h
        src/.cpp/menu.cpp
        src/.h/menu.h
        src/.cpp/pipes.cpp
        src/.h/pipes.h
        src/.cpp/reservoirs.cpp
        src/.h/reservoirs.h
        src/.cpp/stations.cpp
        src/.h/stations.h)
