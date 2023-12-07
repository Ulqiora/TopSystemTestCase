#include "DrawerOpenGl.h"
#include "IDrawer.h"
#include <Scene.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Buffer.h"
#include "ShaderProgram.h"
#include "BufferGeneratorGL.h"

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

void DrawerOpenGl::SetCamera(CameraPtr camera){}


const BufferGeneratorGL &DrawerOpenGl::GetGeneratorBuffer() {
    return *generator;
}

void DrawerOpenGl::DrawPoints(Buffers buffers,size_t size) {
    glUseProgram(program_->getID());
    glBindVertexArray(buffers.vao);
    glDrawElements(GL_LINE_STRIP, size, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

DrawerOpenGl::DrawerOpenGl()= default;

void DrawerOpenGl::SetShaderProgram(ShaderProgramType type) {
    if(type == ShaderProgramType::kDefault) program_ = std::make_shared<ShaderProgram>(vertexShader,fragmentShader);
}

unsigned int DrawerOpenGl::GetIdShaderId(){return program_->getID();}
//        camera.
