//
// Created by ccnc on 12/1/23.
//
#include "Circle.h"
#include <cmath>
#include <BufferGeneratorGL.h>
#include <IDrawer.h>
#include <numeric>
static float Pi2Const = 2.0f * M_PI;

void Circle::Draw(IDrawerPtr drawer) {
    drawer->DrawPoints(buffers_,indices_.size());
}

Circle::Circle( const BufferGeneratorGL & generator, Radius radius, CirclePoints points) {
    points_.reserve(points);
    for(CirclePoints pointIndex = 0;pointIndex<points;pointIndex++){
        points_.emplace_back(
                radius * cosf(static_cast<float>(pointIndex) * Pi2Const/static_cast<float>(points)),
                radius * sinf(static_cast<float>(pointIndex) * Pi2Const/static_cast<float>(points)),
                0
        );
    }
    indices_.resize(points);
    std::iota(indices_.begin(),indices_.end(),0);
    indices_.push_back(0);
    buffers_ = generator.Generate(points_,indices_);

}

void Circle::SetPosition(Position && position) {

}

void Circle::SetRotation(Rotate &&) {

}
