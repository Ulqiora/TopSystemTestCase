//
// Created by ccnc on 12/1/23.
//
#include "Circle.h"
#include <cmath>
#include <BufferGeneratorGL.h>
#include <IDrawer.h>
static float Pi2Const = 2.0f * M_PI;

void Circle::Draw(IDrawerPtr drawer) {
    drawer->DrawPoints(VAO,VBO);
}

Circle::Circle( const BufferGeneratorGL & generator, Radius radius, CirclePoints points) {
    points_.reserve(points);
    for(CirclePoints pointIndex = 0;pointIndex<points;pointIndex++){
        points_.emplace_back(
                radius * cosf(static_cast<float>(pointIndex) * Pi2Const/static_cast<float>(points)),
                radius * cosf(static_cast<float>(pointIndex) * Pi2Const/static_cast<float>(points)),
                0
        );
    }
    auto buffers = generator.Generate(points_);
    VAO = buffers.vao;
    VBO = buffers.vbo;
}

void Circle::SetPosition(Position && position) {

}

void Circle::SetRotation(Rotate &&) {

}
