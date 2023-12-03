cmake_minimum_required(VERSION 3.22)
project("Circle")
set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
message("Boost library place : ${Boost_INCLUDE_DIR}")

add_library(AgentCPU SHARED src/Circle.cpp include/Circle.h)

target_include_directories( AgentCPU
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)