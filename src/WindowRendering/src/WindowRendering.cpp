#include "WindowRendering.h"
#include <GLFW/glfw3.h>
#include <FigureFactory.h>
//#include <gl
WindowRendering::WindowRendering(std::size_t height, std::size_t width):
    height_(height),
    width_(width),
    scene(std::make_shared<Scene>()),
    drawer(std::make_shared<IDrawer>())
{
    if (!glfwInit())
    {
        throw std::runtime_error("GLFW failed to initialize.");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

//    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
//    window = (glfwCreateWindow(
//            static_cast<int>(width_),
//            static_cast<int>(height_),
//            "TestCase",
//            nullptr,
//            nullptr
//    ));
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
//    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0,0,800,800);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    drawer->SetShaderProgram(ShaderProgramType::kDefault);
}

bool WindowRendering::Execute() {
    while (!glfwWindowShouldClose(window.get())){
        ResetAllColor();
//        drawer->DrawScene(scene);

        glfwSwapBuffers(window.get());
        glfwPollEvents();
    }
//    while (!glfwWindowShouldClose(window)){
//        ResetAllColor();
////        drawer->DrawScene(scene);
//
//        Update();
//    }
    return false;
}

void WindowRendering::ResetAllColor() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
}

void WindowRendering::AddCircle() {
    scene->AddFigure(
        Model::FigureFactory::create(
                ModelType::kCircle,
                drawer->GetGeneratorBuffer(),
                0.5
        )
    );
}

void WindowRendering::Update() {
    int width, height;

    glfwGetFramebufferSize(window.get(), &width, &height);

    glViewport(0, 0, width, height);

    glfwSwapBuffers(window.get());
    glfwPollEvents();
}
