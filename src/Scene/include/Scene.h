#pragma once
#include <vector>
#include <IFigure.h>
#include <IDrawer.h>
class Camera;
using CameraPtr = std::shared_ptr<Camera>;

using FigureIndex = size_t;
class Scene{
public:
    void AddFigure(FigurePtr&&);
    void RemoveFigure(FigureIndex);
    void Draw(IDrawerPtr);
private:
    std::vector<FigurePtr> models_;
    CameraPtr camera_;
};
using ScenePtr = std::shared_ptr<Scene>;
