//
// Created by ccnc on 12/7/23.
//

#ifndef TOPSYSTEMTESTCASE_BUFFER_H
#define TOPSYSTEMTESTCASE_BUFFER_H
using VAOBuffer = unsigned int;
using VBOBuffer = unsigned int;
using EBOBuffer = unsigned int;
struct Buffers{
    VAOBuffer vao{};
    VBOBuffer vbo{};
    EBOBuffer ebo{};
    ~Buffers();
};
#endif //TOPSYSTEMTESTCASE_BUFFER_H
