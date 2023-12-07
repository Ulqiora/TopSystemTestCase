#pragma once
#include <string_view>

class ShaderProgram{
public:
    ShaderProgram();
    ShaderProgram(const char *vertex, const char *fragment);
    [[nodiscard]] unsigned int getID()const ;
private:

    unsigned int shaderProgram{};
};
