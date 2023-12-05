#pragma once
#include <vector>
#include <Figure.h>

class Camera;
using CameraPtr = std::shared_ptr<Camera>;

using FigureIndex = size_t;
class Scene{
public:
    void AddFigure(Model::FigurePtr&&);
    void RemoveFigure(FigureIndex);
    void Draw(IDrawer&);
private:
    std::vector<Model::FigurePtr> models_;
    CameraPtr camera_;
};
