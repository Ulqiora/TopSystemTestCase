cmake_minimum_required(VERSION 3.26)
project(MainProject)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(SpecialConstructures)
add_subdirectory(SceneModels/Circle)
add_executable(${PROJECT_NAME} main.cpp SceneModels/Figure.h Scene.h Modifications/Modifications.h Scene.cpp
        Camera.h
        Camera.cpp
        SceneModels/SceneObject.h)

#target_link_libraries(${PROJECT_NAME} glm)
