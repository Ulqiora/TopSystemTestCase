#include "WindowRendering.h"
#include <GLFW/glfw3.h>
#include <FigureFactory.h>
WindowRendering::WindowRendering(std::size_t height, std::size_t width):
    height_(static_cast<int>(height)),
    width_(static_cast<int>(width)),
    scene(std::make_shared<Scene>()),
    drawer(std::make_shared<IDrawer>())
{
    if (!glfwInit())
    {
        throw std::runtime_error("GLFW failed to initialize.");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window.reset(glfwCreateWindow(
            static_cast<int>(width_),
            static_cast<int>(height_),
            "TestCase",
            nullptr,
            nullptr
    ));
    if (this->window == nullptr) {
        glfwTerminate();
        throw std::logic_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window.get());

    gladLoadGL();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        throw std::logic_error("Failed to initialize GLAD");
    }

    glfwGetFramebufferSize(window.get(), &width_, &height_);
    glViewport(0, 0, width_, height_);
    drawer->SetShaderProgram(ShaderProgramType::kDefault);
}

bool WindowRendering::Execute() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    while (!glfwWindowShouldClose(window.get())){
        ResetAllColor();
        scene->Draw(drawer);
        Update();
    }
    return false;
}

void WindowRendering::ResetAllColor() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
}

void WindowRendering::AddCircle() {
    scene->AddFigure(
        Model::FigureFactory::create<Circle>(
                drawer->GetGeneratorBuffer(),
                0.5
        )
    );
}

void WindowRendering::Update() {
    glfwSwapBuffers(window.get());
    glfwPollEvents();
}

void WindowRendering::AddTriangle() {
    std::vector<glm::vec3> points = {
            glm::vec3(0.5f,  0.5f, 0.0f),
            glm::vec3(0.5f, -0.5f, 0.0f),
            glm::vec3(-0.5f,  0.5f, 0.0f)
    };
    scene->AddFigure(
            Model::FigureFactory::create<Triangle>(
                    drawer->GetGeneratorBuffer(),
                    points
            )
    );
}
