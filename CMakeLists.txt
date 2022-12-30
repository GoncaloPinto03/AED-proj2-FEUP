cmake_minimum_required(VERSION 3.23.2)
project(proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(proj Tests/Airport.cpp Tests/Airport.h Tests/Airline.cpp Tests/Airline.h Tests/Flight.cpp Tests/Flight.h Tests/Main.cpp Tests/Main.h Tests/Graph.h Tests/Graph.cpp)
