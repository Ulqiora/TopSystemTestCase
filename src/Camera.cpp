#include "Camera.h"
#include "SceneModels/Modifications.h"

void Camera::SetPosition(Position &&position) {

}

Camera::Camera(Position&& position,
               WorldUpDirection&& up,
               YawEalerAngle&& yaw,
               PitchEalerAngle&& pitch) :
        cameraPosition(glm::vec3(position.x, position.y, position.z)),
        worldUp(up),
        yaw(yaw),
        pitch(pitch)
{
    UpdateVectors();
}

void Camera::UpdateVectors() {
    FrontDirection = glm::vec3{
        cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
        sin(glm::radians(pitch)),
        sin(glm::radians(yaw)) * cos(glm::radians(pitch))
    };
    RightDirection = glm::normalize(glm::cross(FrontDirection,worldUp));
    UpDirection = glm::normalize(glm::cross(RightDirection, FrontDirection));;
    Notify();
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(cameraPosition, cameraPosition + FrontDirection, UpDirection);
}


