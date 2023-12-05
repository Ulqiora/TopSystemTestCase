#include <iostream>
#include "Camera.h"
#include <WindowRendering.h>

class Temp : public Observer{
public:
    void update() override;
};

void Temp::update() {
    std::cout<<"Updated\n";
}

int main() {
    WindowRendering tep(800,800);
    tep.Execute();
    auto camera = std::make_shared<Camera>(Position{0.0,0.0,3.0});
    auto temp = std::make_shared<Temp>();
    camera->AddSubscriber(temp,[temp](int i){
        std::cout<<"Subscriber Call!"+std::to_string(i)+"\n";
        temp->update();
    },1);
    camera->UpdateVectors();
    std::cout << "Hello, World!" << std::endl;
    camera->RemoveSubscriber(temp);
    camera->UpdateVectors();
    return 0;
}
