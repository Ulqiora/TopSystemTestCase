#include "IDrawer.h"

#include <utility>
#include "DrawerOpenGl.h"
#include "Buffer.h"

IDrawer::IDrawer() : impl(std::make_shared<DrawerOpenGl>()){

}

void IDrawer::SetShaderProgram(ShaderProgramType type) {
    impl->SetShaderProgram(type);
}

void IDrawer::SetCamera(CameraPtr camera) {
    impl->SetCamera(std::move(camera));
}

void IDrawer::DrawPoints(Buffers buffer, size_t size) {
    impl->DrawPoints(buffer,size);
}

const BufferGeneratorGL &IDrawer::GetGeneratorBuffer() {
    return impl->GetGeneratorBuffer();
}

unsigned int IDrawer::GetIdShaderId() {
    return impl->GetIdShaderId();
}
