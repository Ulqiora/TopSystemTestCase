#include "IDrawer.h"
#include <Scene.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertexShader = R"(~
#version 330 core

layout(location = 0) in vec4 position;

void main(){
    gl_Position = position;
}
~)";

const char* fragmentShader = R"(~
#version 330 core

layout(location = 0) out vec4 color;

void main(){
    color = vec4(1.0,0.0,0.0,1.0);
}
~)";

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

void IDrawer::DrawPoints(VAOBuffer vao,VBOBuffer vbo) {
    glUseProgram(program_.getID());
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, 0);
//    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    glUseProgram(0);
}

IDrawer::IDrawer()= default;

void IDrawer::SetShaderProgram(ShaderProgramType type) {
    if(type == ShaderProgramType::kDefault) program_ = ShaderProgram{vertexShader,fragmentShader};
}
//        camera.
