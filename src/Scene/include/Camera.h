#pragma once
#include <memory>
#include "Modifications.h"
#include "Observable.h"
#include "glm/vec3.hpp"
#include "glm/gtc/matrix_transform.hpp"


using YawEalerAngle = float;
using PitchEalerAngle = float;


class RecipientObjectInfo;
using WorldPosition = Position;
using WorldUpDirection = glm::vec3;
namespace CameraConsts{
    constexpr YawEalerAngle kYaw       = -90.0f;
    constexpr PitchEalerAngle kPitch   =  0.0f;
};
class Camera : public Observable{
public:
    explicit Camera(Position&&,
                    WorldUpDirection&& = WorldUpDirection{},
                    YawEalerAngle&& = YawEalerAngle{CameraConsts::kYaw},
                    PitchEalerAngle&& = PitchEalerAngle{CameraConsts::kPitch});
    void SetPosition(Position&&) ;
    glm::mat4 GetViewMatrix();
    void UpdateVectors();
private:
    glm::vec3 cameraPosition;
//    glm::vec3 worldPoint;
    WorldUpDirection worldUp;
    YawEalerAngle yaw;
    PitchEalerAngle pitch;
    // vector's of Camera Directions
    glm::vec3 FrontDirection{};
    glm::vec3 RightDirection{};
    glm::vec3 UpDirection{};
};
using CameraPtr = std::shared_ptr<Camera>;
