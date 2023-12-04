//
// Created by ccnc on 12/3/23.
//

#ifndef TOPSYSTEMTESTCASE_SCENEOBJECT_H
#define TOPSYSTEMTESTCASE_SCENEOBJECT_H
#include <memory>
#include "Modifications/Modifications.h"
#include "Observer/Observable.h"
class IDrawer;

class SceneObject : public Observable{
public:
    virtual void SetPosition(Position&&) = 0;
    virtual void SetRotation(Rotate&&) = 0;
    virtual void Draw(IDrawer&) = 0;
};


#endif //TOPSYSTEMTESTCASE_SCENEOBJECT_H
