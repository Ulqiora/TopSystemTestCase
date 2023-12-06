#pragma once
#include <vector>
#include "glm/vec3.hpp"
#include "IFigure.h"
#include <glad/glad.h>
#include <Observable.h>
#include <Buffer.h>
class BufferGeneratorGL;

using TrianglePoints = std::vector<glm::vec3>;

class Triangle : public IFigure, public Observable{
public:
    Triangle(const BufferGeneratorGL&, TrianglePoints&&);
    void Draw(IDrawerPtr) override;
    void SetPosition(Position&&) override;
    void SetRotation(Rotate&&) override;
    ~Triangle() override = default;
private:
    TrianglePoints points_;
    Indices indices_{0, 1, 2, 0};
    Buffers buffers_;
};