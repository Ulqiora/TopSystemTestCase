#include "IDrawer.h"
#include <Scene.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertexShader = "#version 330 core\n"
                           "layout (location = 0) in vec3 position;\n"
                           "void main()\n"
                           "{\n"
                           "    gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                           "}\n";

const char* fragmentShader = "#version 330 core\n"
                             "out vec4 color;\n"
                             "void main()\n"
                             "{\n"
                             "    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                             "}\n";

void IDrawer::DrawScene(ScenePtr scene){
    scene->Draw(getPtrFromThis());
}
void IDrawer::SetCamera(CameraPtr camera){}

IDrawerPtr IDrawer::getPtrFromThis() {
    return shared_from_this();
}

const BufferGeneratorGL &IDrawer::GetGeneratorBuffer() {
    return generator;
}

void IDrawer::DrawPoints(const Buffers& buffers,size_t size) {
    glUseProgram(program_.getID());
    glBindVertexArray(buffers.vao);
    glDrawElements(GL_LINE_STRIP, size, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

IDrawer::IDrawer()= default;

void IDrawer::SetShaderProgram(ShaderProgramType type) {
    if(type == ShaderProgramType::kDefault) program_ = ShaderProgram{vertexShader,fragmentShader};
}
//        camera.
