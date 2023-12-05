#pragma once
#include <memory>
#include "Modifications.h"
class IDrawer;

class SceneObject{
public:
    virtual void SetPosition(Position&&) = 0;
    virtual void SetRotation(Rotate&&) = 0;
    virtual void Draw(IDrawer&) = 0;
};


