#include "Camera.h"
#include "Modifications/Modifications.h"

void Camera::SetPosition(Position &&position) {

}

void Camera::SetRotation(Rotate &&) {

}

void Camera::Draw(IDrawer &) {

}

Camera::Camera(Position&& position,
//               WorldPosition&& wPosition,
               WorldUpDirection&& up,
               YawEalerAngle&& yaw,
               PitchEalerAngle&& pitch) :
        cameraPosition(glm::vec3(position.x, position.y, position.z)),
//        worldPoint(glm::vec3(wPosition.x, wPosition.y, wPosition.z)),
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
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(cameraPosition, cameraPosition + FrontDirection, UpDirection);
}


