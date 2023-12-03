#pragma once
#include <vector>
#include "Figure.h"
using FigureIndex = size_t;
class Scene{
public:
    void AddFigure(Model::FigurePtr&&);
    void RemoveFigure(FigureIndex);
    void Draw(IDrawer&);
private:
    std::vector<Model::FigurePtr> models_;
};
