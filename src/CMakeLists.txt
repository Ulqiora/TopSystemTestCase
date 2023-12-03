cmake_minimum_required(VERSION 3.26)
project(MainProject)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Figures/Circle)
add_executable(MainProject main.cpp Figure.h Scene.h Modifications/Modifications.h Scene.cpp
        Camera.h
        Camera.cpp
        SceneObject.cpp
        SceneObject.h)
