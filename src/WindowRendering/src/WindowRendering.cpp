#include "WindowRendering.h"

#include <GLFW/glfw3.h>
//#include <gl
WindowRendering::WindowRendering(std::size_t height, std::size_t width):
    height_(height),
    width_(width)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    window.reset(glfwCreateWindow(
            static_cast<int>(width_),
            static_cast<int>(height_),
            "TestCase",
            nullptr,
            nullptr
    ));
    if (this->window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window.get());
}

bool WindowRendering::Execute() {
    while (!glfwWindowShouldClose(window.get())){
        glfwPollEvents();
    }
    return false;
}

void WindowRendering::ResetAllColor() {
//    glfwInit();
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glfwSwapBuffers(this->window.get());
}
