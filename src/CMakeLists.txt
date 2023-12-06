cmake_minimum_required(VERSION 3.26)
project(MainProject)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(SpecialConstructures)
add_subdirectory(Scene)
add_subdirectory(SceneModels)
add_subdirectory(WindowRendering)
add_subdirectory(Drawer)
add_executable(${PROJECT_NAME} main.cpp
)
target_link_libraries(${PROJECT_NAME}  PUBLIC ObserverLibrary SceneLibrary SceneModels WindowRenderLibrary glfw glm)
