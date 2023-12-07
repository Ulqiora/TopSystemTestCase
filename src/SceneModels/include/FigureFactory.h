#pragma once
#include "IFigure.h"
#include "Circle.h"
#include "Triangle.h"
enum class ModelType{
    kCircle = 0,
    kTriangle = 1
};
namespace Model {
    class FigureFactory{
    public:
    template<class FigureType,class ...Args>
    static FigurePtr create(const BufferGeneratorGL &generatorGl, Args... args) {
        return std::make_shared<FigureType>(generatorGl, std::forward<Args&&>(args)...);
    }
    };
}