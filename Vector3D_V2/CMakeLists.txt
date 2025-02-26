cmake_minimum_required(VERSION 3.14)

project(Vector3DProject
    VERSION 1.0.0
    DESCRIPTION "Vector3D"
    LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)


# language features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Vector3DProject)

set(sources 
   ./src/Vector3D.h
   ./src/Vector3D.cpp
   ./src/main.cpp
)

target_sources(Vector3DProject PRIVATE ${sources})
