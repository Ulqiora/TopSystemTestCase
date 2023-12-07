//
// Created by ccnc on 12/5/23.
//

#ifndef TOPSYSTEMTESTCASE_BUFFERGENERATORGL_H
#define TOPSYSTEMTESTCASE_BUFFERGENERATORGL_H
#include "glm/vec3.hpp"
#include <vector>
#include <memory>
struct Buffers;
class BufferGeneratorGL {
public:
    [[nodiscard("if the buffer has not been saved, then they will not be cleaned up")]]
    Buffers Generate(const std::vector<glm::vec3>&, const std::vector<unsigned int>&)const;
};
using BufferGeneratorGLPtr = std::shared_ptr<BufferGeneratorGL>;


#endif //TOPSYSTEMTESTCASE_BUFFERGENERATORGL_H
