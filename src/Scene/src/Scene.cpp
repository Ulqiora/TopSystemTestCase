#include "Scene.h"
#include "Camera.h"
#include "../../Drawer/include/IDrawer.h"
//#include <
void Scene::AddFigure(FigurePtr && model) {
    models_.push_back(model);
}

void Scene::RemoveFigure(FigureIndex id) {
    models_.erase(models_.cbegin()+id);
}

void Scene::Draw(IDrawerPtr drawer) {
//    drawer->SetCamera(camera_);
    for(const auto& model:models_){
        model->Draw(drawer);
    }
}

