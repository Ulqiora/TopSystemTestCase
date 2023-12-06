#include "Buffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Buffers::~Buffers() {
    if(vao == 0)
        glDeleteVertexArrays(1,&vao);
    if(vbo == 0)
        glDeleteVertexArrays(1,&vbo);
    if(ebo == 0)
        glDeleteVertexArrays(1,&ebo);
}
