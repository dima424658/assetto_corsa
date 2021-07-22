#include "acgl.h
void ACGL::ACGL(ACGL *this, GLRenderer *glRenderer)
{
  this->gl = glRenderer;
  this->__vftable = (ACGL_vtbl *)&ACGL::`vftable';
  this->formOffset.x = 0.0;
  this->formOffset.y = 0.0;
  this->formOffset.z = 0.0;
}
void ACGL::~ACGL(ACGL *this)
{
  this->__vftable = (ACGL_vtbl *)&ACGL::`vftable';
}
ACGL *ACGL::`scalar deleting destructor'(ACGL *this, unsigned int a2)
{
  this->__vftable = (ACGL_vtbl *)&ACGL::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACGL::begin(ACGL *this, acPrimitiveType primitiveType)
{
  GLRenderer::begin(this->gl, (eGLPrimitiveType)primitiveType, 0);
}
void ACGL::color4f(ACGL *this, float r, float g, float b, float a)
{
  GLRenderer::color4f(this->gl, r, g, b, a);
}
void ACGL::drawTexturedQuad(ACGL *this, float x, float y, float width, float height, IACTexture *texture)
{
  bool textured; // [esp+20h] [ebp-4h]

  textured = 0;
  if ( texture )
  {
    texture->apply(texture, 0);
    textured = 1;
  }
  GLRenderer::quad(this->gl, this->formOffset.x + x, this->formOffset.y + y, width, height, textured, 0);
}
void ACGL::end(ACGL *this)
{
  GLRenderer::end(this->gl);
}
void ACGL::setOffset(ACGL *this, vec2f *off)
{
  *(_QWORD *)&this->formOffset.x = _mm_unpacklo_ps((__m128)LODWORD(off->x), (__m128)LODWORD(off->y)).m128_u64[0];
  this->formOffset.z = 0.0;
}
void ACGL::texCoord2f(ACGL *this, float u, float v)
{
  GLRenderer::texCoord2f(this->gl, u, v);
}
void ACGL::vertex2f(ACGL *this, float x, float y)
{
  GLRenderer::vertex3f(this->gl, this->formOffset.x + x, this->formOffset.y + y, 0.0);
}
