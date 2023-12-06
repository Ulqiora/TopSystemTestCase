#include "../include/ShaderProgram.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
ShaderProgram::ShaderProgram(const char* vertex, const char* fragment) {
    GLuint vertexcontext = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexcontext,1,&vertex,nullptr);
    glCompileShader(vertexcontext);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexcontext,1,&vertex,nullptr);
    glCompileShader(vertexcontext);
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram,vertexcontext);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexcontext);
    glDeleteShader(fragmentShader);
}

unsigned int ShaderProgram::getID() const {
    return shaderProgram;
}

ShaderProgram::ShaderProgram() = default;
