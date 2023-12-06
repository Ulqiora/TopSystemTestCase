#pragma once
#include <vector>
#include "glm/vec3.hpp"
#include "IFigure.h"
#include <Observable.h>

class BufferGeneratorGL;
using Radius = float;


using CirclePoints = size_t;

class Circle : public IFigure, public Observable{
public:
    Circle(const BufferGeneratorGL&, Radius, CirclePoints = PointsOnCircle);
    void Draw(IDrawerPtr) override;
    void SetPosition(Position&&) override;
    void SetRotation(Rotate&&) override;
    ~Circle() override = default;
private:
    static const size_t PointsOnCircle = 30;
    std::vector<glm::vec3> points_;
    unsigned int VAO{};
    unsigned int VBO{};
};