cmake_minimum_required(VERSION 3.17)
project(DA_project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(main.cpp cities.cpp cities.h reservoirs.cpp reservoirs.h pipes.cpp pipes.h stations.cpp stations.h)