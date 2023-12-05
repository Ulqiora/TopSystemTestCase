#pragma once
#include <vector>
#include <glm/vec3.hpp>
#include "Figure.h"

using Radius = float;

namespace CircleConsts{
    size_t PointsOnCircle = 30;
};
using CirclePoints = size_t;

class Circle : public Model::IFigures{
public:
    Circle(Radius, CirclePoints = CircleConsts::PointsOnCircle);
private:
    std::vector<glm::vec3> points_;
};