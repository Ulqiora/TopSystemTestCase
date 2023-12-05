//
// Created by ccnc on 12/1/23.
//
#include "Circle.h"
#include <cmath>

static float Pi2Const = 2.0f * M_PI;

Circle::Circle(Radius radius, CirclePoints points) {
    points_.reserve(points);
    for(CirclePoints pointIndex = 0;pointIndex<points;pointIndex++){
        points_.emplace_back(
           radius * cosf(static_cast<float>(pointIndex) * Pi2Const/static_cast<float>(points)),
           radius * cosf(static_cast<float>(pointIndex) * Pi2Const/static_cast<float>(points)),
           0
        );
    }
}
