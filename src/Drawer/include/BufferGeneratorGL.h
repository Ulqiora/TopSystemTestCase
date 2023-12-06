//
// Created by ccnc on 12/5/23.
//

#ifndef TOPSYSTEMTESTCASE_BUFFERGENERATORGL_H
#define TOPSYSTEMTESTCASE_BUFFERGENERATORGL_H
#include "glm/vec3.hpp"
#include <vector>
using VAOBuffer = unsigned int;
using VBOBuffer = unsigned int;
using EBOBuffer = unsigned int;
struct Buffers{
    VAOBuffer vao;
    VBOBuffer vbo;
    EBOBuffer ebo;
};

class BufferGeneratorGL {
public:
    [[nodiscard("if the buffer has not been saved, then they will not be cleaned up")]]
    Buffers Generate(const std::vector<glm::vec3>&)const;
};


#endif //TOPSYSTEMTESTCASE_BUFFERGENERATORGL_H
