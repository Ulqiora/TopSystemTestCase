#include "BufferGeneratorGL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Buffer.h"

Buffers BufferGeneratorGL::Generate(
        const std::vector<glm::vec3>& vertices,
        const std::vector<unsigned int>& indices) const {
    Buffers buffers{};
    glGenVertexArrays(1, &buffers.vao);
    glGenBuffers(1, &buffers.vbo);
    glGenBuffers(1, &buffers.ebo);

    glBindVertexArray(buffers.vao);

    glBindBuffer(GL_ARRAY_BUFFER, buffers.vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 vertices.size() * sizeof(glm::vec3),
                 vertices.data(),
                 GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)nullptr);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(std::vector<unsigned int>::value_type), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return buffers;
}
