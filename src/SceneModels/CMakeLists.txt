cmake_minimum_required(VERSION 3.22)
project("SceneModels")
set(CMAKE_CXX_STANDARD 20)

#find_package(Boost REQUIRED)
#INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
#message("Boost library place : ${Boost_INCLUDE_DIR}")
file(GLOB SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
file(GLOB HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries( ${PROJECT_NAME} PUBLIC ObserverLibrary glm)