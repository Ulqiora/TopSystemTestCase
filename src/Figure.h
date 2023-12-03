#pragma once
#include <memory>
#include "SceneObject.h"
class IDrawer;

namespace Model{

struct Position;
struct Rotate;
struct Scale;

class [[maybe_unused]] IFigures:public SceneObject{
public:
//    virtual void SetPositions(Position&&) = 0;
//    virtual void SetRotation(Rotate&&) = 0;
//    virtual void SetScale(Scale&&) = 0;
//    virtual void Draw(IDrawer&) = 0;
};

using FigurePtr = std::shared_ptr<IFigures>;

template<class FigureParameters>
FigurePtr create(FigureParameters);


}