#include "BufferGeneratorGL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
Buffers BufferGeneratorGL::Generate(const std::vector<glm::vec3>& vertices) const {
    Buffers buffers{};
    glGenVertexArrays(1,&buffers.vao);
    glGenBuffers(1,&buffers.vbo);
//    glGenBuffers(1, &buffers.ebo);
    glBindVertexArray(buffers.vao);

    glBindBuffer(GL_ARRAY_BUFFER,buffers.vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<long>(vertices.size() * sizeof(std::decay_t<decltype(vertices)>::value_type)),
                 vertices.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)nullptr);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    return buffers;
}
