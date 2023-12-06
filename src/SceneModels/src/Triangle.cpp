//
// Created by ccnc on 12/1/23.
//
#include "Triangle.h"
#include <cmath>
#include <BufferGeneratorGL.h>
#include <IDrawer.h>
static float Pi2Const = 2.0f * M_PI;

void Triangle::Draw(IDrawerPtr drawer) {
    drawer->DrawPoints(buffers_,indices_.size());
}

Triangle::Triangle( const BufferGeneratorGL & generator, TrianglePoints&& points):
    points_(std::move(points))
{
    if(points_.size() != 3)
        throw std::invalid_argument("Size is not correct");
    buffers_ = generator.Generate(points_,indices_);

}

void Triangle::SetPosition(Position && position) {

}

void Triangle::SetRotation(Rotate &&) {

}
