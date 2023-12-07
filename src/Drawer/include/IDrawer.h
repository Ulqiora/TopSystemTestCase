//
// Created by ccnc on 12/6/23.
//

#ifndef TOPSYSTEMTESTCASE_IDRAWER_H
#define TOPSYSTEMTESTCASE_IDRAWER_H
#include <Camera.h>

class ShaderProgram;
using ShaderProgramPtr = std::shared_ptr<ShaderProgram>;
class IDrawer;
using IDrawerPtr = std::shared_ptr<IDrawer>;

class BufferGeneratorGL;
struct Buffers;
using VAOBuffer = unsigned int;

enum class ShaderProgramType{
    kDefault
};
class DrawerOpenGl;
using DrawerOpenGlPtr = std::shared_ptr<DrawerOpenGl>;
class IDrawer{
public:
    IDrawer ();
    virtual void SetShaderProgram(ShaderProgramType);
    virtual void SetCamera(CameraPtr camera);
    virtual void DrawPoints(Buffers, size_t) ;
    virtual const BufferGeneratorGL& GetGeneratorBuffer();
    virtual unsigned int GetIdShaderId();
private:
    DrawerOpenGlPtr impl;
};
#endif //TOPSYSTEMTESTCASE_IDRAWER_H
