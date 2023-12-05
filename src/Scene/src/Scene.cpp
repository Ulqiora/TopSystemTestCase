#include "../include/Scene.h"
#include "Camera.h"
#include "IDrawer.h"
void Scene::AddFigure(Model::FigurePtr &&) {

}

void Scene::RemoveFigure(FigureIndex id) {

}

void Scene::Draw(IDrawer & drawer) {
    drawer.SetCamera(camera_);
    for(const auto& model:models_){
        model->Draw(drawer);
    }
}
