cmake_minimum_required(VERSION 3.30)
project(Truck_Pallet)

set(CMAKE_CXX_STANDARD 20)

add_executable(Truck_Pallet main.cpp CommandLineMenu.cpp
        DataLoader.cpp  ExhaustiveBF.cpp )
