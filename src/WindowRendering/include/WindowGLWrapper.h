#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
struct glfwDeleter
{
    void operator()(GLFWwindow *wnd)
    {
        std::cout << "Destroying GLFW Window Context" << std::endl;
        glfwDestroyWindow(wnd);
    }
};
using WindowPtr = std::unique_ptr<GLFWwindow, glfwDeleter>;