cmake_minimum_required(VERSION 3.24)
project(proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(proj Tests/main.cpp Tests/Airport.cpp Tests/Airport.h Tests/Airline.cpp Tests/Airline.h Tests/Flight.cpp Tests/Flight.h)
