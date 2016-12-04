cmake_minimum_required(VERSION 3.6)
project(try)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TaxiCenter.cpp Node.cpp Point.cpp Coordinate.cpp
        Grid.cpp BFS.cpp Trip.cpp Passenger.cpp Driver.cpp Taxi.cpp
        TestTaxiCenter.cpp TestNode.cpp TestPoint.cpp TestGrid.cpp TestTrip.cpp TestPassenger.cpp TestDriver.cpp
        TestTaxi.cpp)
add_library(ex2 ${SOURCE_FILES} main.cpp TaxiCenter.cpp Node.cpp Point.cpp Coordinate.cpp
        Grid.cpp BFS.cpp Trip.cpp Passenger.cpp Driver.cpp Taxi.cpp TestTaxiCenter.cpp TestNode.cpp TestPoint.cpp TestGrid.cpp TestTrip.cpp TestPassenger.cpp TestDriver.cpp
        TestTaxi.cpp)
include_directories(googletest-master/googletest/include)
include_directories(googletest-master/googlemock/include)
add_subdirectory(googletest-master)
add_executable(try ${SOURCE_FILES} main.cpp TaxiCenter.cpp Node.cpp Point.cpp Coordinate.cpp
        Grid.cpp BFS.cpp Trip.cpp Passenger.cpp Driver.cpp Taxi.cpp
        TestTaxiCenter.cpp TestNode.cpp TestPoint.cpp TestGrid.cpp TestTrip.cpp TestPassenger.cpp TestDriver.cpp
        TestTaxi.cpp)
target_link_libraries(try gtest gtest_main)