cmake_minimum_required(VERSION 3.26)
project(MainProject)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Figures/Circle)
add_executable(${PROJECT_NAME} main.cpp Figure.h Scene.h Modifications/Modifications.h Scene.cpp
        Camera.h
        Camera.cpp
        SceneObject.cpp
        SceneObject.h
        Observer/Observable.h
        Observer/Observer.h
        Observer/Observable.cpp)

#target_link_libraries(${PROJECT_NAME} glm)
