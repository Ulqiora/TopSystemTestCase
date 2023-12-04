#pragma once
#include <memory>
#include "SceneObject.h"
class IDrawer;

namespace Model{

struct Position;
struct Rotate;
struct Scale;

class [[maybe_unused]] IFigures:public SceneObject, public Observable{
public:
};

using FigurePtr = std::shared_ptr<IFigures>;

template<class FigureParameters>
FigurePtr create(FigureParameters);


}