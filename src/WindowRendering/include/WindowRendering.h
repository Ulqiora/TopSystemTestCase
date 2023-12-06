//
// Created by ccnc on 12/4/23.
//

#ifndef TOPSYSTEMTESTCASE_WINDOWRENDERING_H
#define TOPSYSTEMTESTCASE_WINDOWRENDERING_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "WindowGLWrapper.h"
#include <IDrawer.h>
#include <Scene.h>
#include <cstdint>
#include <memory>
#include <iostream>

class WindowRendering {
public:
    WindowRendering(std::size_t height,std::size_t width);
    bool Execute();
    void AddCircle();
private:
    void ResetAllColor();
    void Update();
private:
    std::size_t height_;
    std::size_t width_;
    ScenePtr scene;
    IDrawerPtr drawer;
//    GLFWwindow* window;
    WindowPtr window;
};


#endif //TOPSYSTEMTESTCASE_WINDOWRENDERING_H
