cmake_minimum_required(VERSION 3.27)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(test src/main.cpp
        src/NearestNeighbours.cpp
        include/NearestNeighbours.h
        src/FileReader.cpp
        include/FileReader.h
        src/ConfigReader.cpp
        include/ConfigReader.h
        src/MatrixGenerator.cpp
        include/MatrixGenerator.h)
