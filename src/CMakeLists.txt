cmake_minimum_required(VERSION 3.26)
project(MainProject)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(SpecialConstructures)
add_subdirectory(SceneModels/Circle)
add_executable(${PROJECT_NAME} main.cpp Scene/include/Scene.h Scene/src/Scene.cpp
        Camera.h
        Camera.cpp
)


target_link_libraries(${PROJECT_NAME} ObserverLibrary SceneLibrary glm)
