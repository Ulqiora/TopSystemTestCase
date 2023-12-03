//
// Created by ccnc on 12/3/23.
//

#ifndef TOPSYSTEMTESTCASE_SCENEOBJECT_H
#define TOPSYSTEMTESTCASE_SCENEOBJECT_H
#include <memory>
struct Position;
struct Rotate;
struct Scale;
class IDrawer;

class SceneObject {
public:
    virtual void SetPositions(Position&&) = 0;
    virtual void SetRotation(Rotate&&) = 0;
    virtual void Draw(IDrawer&) = 0;
};


#endif //TOPSYSTEMTESTCASE_SCENEOBJECT_H
