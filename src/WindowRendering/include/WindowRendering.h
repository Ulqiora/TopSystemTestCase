//
// Created by ccnc on 12/4/23.
//

#ifndef TOPSYSTEMTESTCASE_WINDOWRENDERING_H
#define TOPSYSTEMTESTCASE_WINDOWRENDERING_H
#include <cstdint>
#include <memory>
#include <iostream>
#include <GLFW/glfw3.h>
struct glfwDeleter
{
    void operator()(GLFWwindow *wnd)
    {
        std::cout << "Destroying GLFW Window Context" << std::endl;
        glfwDestroyWindow(wnd);
    }
};
class WindowRendering {
public:
    WindowRendering(std::size_t height,std::size_t width);
    bool Execute();
private:
    void ResetAllColor();
    struct glfwDeleter {
        void operator()(GLFWwindow *wnd) {
            std::cout << "Destroying GLFW Window Context" << std::endl;
            glfwDestroyWindow(wnd);
        }
    };
    std::size_t height_;
    std::size_t width_;
    std::unique_ptr<GLFWwindow, glfwDeleter> window;
};


#endif //TOPSYSTEMTESTCASE_WINDOWRENDERING_H
