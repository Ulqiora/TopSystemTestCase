//
// Created by ccnc on 12/7/23.
//

#ifndef TOPSYSTEMTESTCASE_DRAWEROPENGL_H
#define TOPSYSTEMTESTCASE_DRAWEROPENGL_H
#include "IDrawer.h"
#include "BufferGeneratorGL.h"
//#include
class DrawerOpenGl{
    public:
        DrawerOpenGl();
        void SetShaderProgram(ShaderProgramType) ;
        void SetCamera(CameraPtr camera) ;
        void DrawPoints(Buffers, size_t) ;
        const BufferGeneratorGL& GetGeneratorBuffer() ;
        unsigned int GetIdShaderId() ;
    private:
        ShaderProgramPtr program_;
        BufferGeneratorGLPtr generator;
};


#endif //TOPSYSTEMTESTCASE_DRAWEROPENGL_H
