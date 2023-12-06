#pragma once
#include <memory>
#include "Modifications.h"

class IDrawer;
using IDrawerPtr = std::shared_ptr<IDrawer>;


using Indices = std::vector<unsigned int>;
class IFigure{
public:
    virtual void SetPosition(Position&&) = 0;
    virtual void SetRotation(Rotate&&) = 0;
    virtual void Draw(IDrawerPtr) = 0;
    virtual ~IFigure() = default;
};

using FigurePtr = std::shared_ptr<IFigure>;
