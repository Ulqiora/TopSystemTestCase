cmake_minimum_required(VERSION 3.26)
project(TopSystemTestCase)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party)
add_subdirectory(src)
#find_package(glm REQUIRED)


target_link_libraries(MainProject PUBLIC glm)