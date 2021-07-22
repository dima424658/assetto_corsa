#include "displaynode.h"
void DisplayNode::DisplayNode(DisplayNode *this, std::wstring a_name)
{
  bool v3; // cf

  Node::Node(this, &a_name);
  this->__vftable = (DisplayNode_vtbl *)&DisplayNode::`vftable';
  this->txBase.kid = 0;
  this->txBase.fileName._Myres = 7;
  this->txBase.fileName._Mysize = 0;
  this->txBase.fileName._Bx._Buf[0] = 0;
  this->txTop.kid = 0;
  this->txTop.fileName._Myres = 7;
  this->txTop.fileName._Mysize = 0;
  this->txTop.fileName._Bx._Buf[0] = 0;
  v3 = a_name._Myres < 8;
  this->size.x = 0.0;
  this->size.y = 0.0;
  this->blendX = 0.5;
  this->color = (vec4f)_xmm;
  this->type = UnknownItem;
  this->trigger = 0.0;
  this->digit = 0;
  this->valueInt = 0;
  this->valueFloat = 0;
  if ( !v3 )
    operator delete(a_name._Bx._Ptr);
}
void DisplayNode::DisplayNode(DisplayNode *this, std::wstring a_name, DigitalItemType a_type)
{
  bool v4; // cf
  DigitalItemType v5; // eax

  Node::Node(this, &a_name);
  this->__vftable = (DisplayNode_vtbl *)&DisplayNode::`vftable';
  this->txBase.kid = 0;
  this->txBase.fileName._Myres = 7;
  this->txBase.fileName._Mysize = 0;
  this->txBase.fileName._Bx._Buf[0] = 0;
  this->txTop.kid = 0;
  this->txTop.fileName._Mysize = 0;
  this->txTop.fileName._Myres = 7;
  this->txTop.fileName._Bx._Buf[0] = 0;
  v4 = a_name._Myres < 8;
  this->size.x = 0.0;
  this->size.y = 0.0;
  v5 = a_type;
  this->blendX = 0.5;
  this->color = (vec4f)_xmm;
  this->type = v5;
  this->trigger = 0.0;
  this->digit = 0;
  this->valueInt = 0;
  this->valueFloat = 0;
  if ( !v4 )
    operator delete(a_name._Bx._Ptr);
}
DisplayNode *DisplayNode::`vector deleting destructor'(DisplayNode *this, unsigned int a2)
{
  this->__vftable = (DisplayNode_vtbl *)&DisplayNode::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->txTop);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txBase);
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DisplayNode::drawBase(DisplayNode *this, RenderContext *rc, GLRenderer *gl)
{
  if ( this->txBase.kid )
  {
    GraphicsManager::setTexture(rc->graphics, 0, &this->txBase);
    GLRenderer::color4f(gl, this->color.x, this->color.y, this->color.z, this->color.w);
    GLRenderer::begin(gl, eQuads, 0);
    GLRenderer::texCoord2f(gl, 0.0, 1.0);
    GLRenderer::vertex3f(gl, 0.0, 0.0, 0.0);
    GLRenderer::texCoord2f(gl, 1.0, 1.0);
    GLRenderer::vertex3f(gl, COERCE_FLOAT(LODWORD(this->size.x) ^ _xmm), 0.0, 0.0);
    GLRenderer::texCoord2f(gl, 1.0, 0.0);
    GLRenderer::vertex3f(gl, COERCE_FLOAT(LODWORD(this->size.x) ^ _xmm), this->size.y, 0.0);
    GLRenderer::texCoord2f(gl, 0.0, 0.0);
    GLRenderer::vertex3f(gl, 0.0, this->size.y, 0.0);
    GLRenderer::end(gl);
  }
}
void DisplayNode::drawBaseInverted(DisplayNode *this, RenderContext *rc, GLRenderer *gl)
{
  if ( this->txBase.kid )
  {
    GraphicsManager::setTexture(rc->graphics, 0, &this->txBase);
    GLRenderer::color4f(gl, this->color.x, this->color.y, this->color.z, this->color.w);
    GLRenderer::begin(gl, eQuads, 0);
    GLRenderer::texCoord2f(gl, 1.0, 1.0);
    GLRenderer::vertex3f(gl, this->size.x, 0.0, 0.0);
    GLRenderer::texCoord2f(gl, 0.0, 1.0);
    GLRenderer::vertex3f(gl, 0.0, 0.0, 0.0);
    GLRenderer::texCoord2f(gl, 0.0, 0.0);
    GLRenderer::vertex3f(gl, 0.0, this->size.y, 0.0);
    GLRenderer::texCoord2f(gl, 1.0, 0.0);
    GLRenderer::vertex3f(gl, this->size.x, this->size.y, 0.0);
    GLRenderer::end(gl);
  }
}
void DisplayNode::drawTop(DisplayNode *this, RenderContext *rc, GLRenderer *gl)
{
  if ( this->txTop.kid )
  {
    GraphicsManager::setTexture(rc->graphics, 0, &this->txTop);
    GLRenderer::color4f(gl, this->color.x, this->color.y, this->color.z, this->color.w);
    GLRenderer::begin(gl, eQuads, 0);
    GLRenderer::texCoord2f(gl, 0.0, 1.0);
    GLRenderer::vertex3f(gl, 0.0, 0.0, 0.0);
    GLRenderer::texCoord2f(gl, this->blendX, 1.0);
    GLRenderer::vertex3f(gl, COERCE_FLOAT(COERCE_UNSIGNED_INT(this->blendX * this->size.x) ^ _xmm), 0.0, 0.0);
    GLRenderer::texCoord2f(gl, this->blendX, 0.0);
    GLRenderer::vertex3f(gl, COERCE_FLOAT(COERCE_UNSIGNED_INT(this->blendX * this->size.x) ^ _xmm), this->size.y, 0.0);
    GLRenderer::texCoord2f(gl, 0.0, 0.0);
    GLRenderer::vertex3f(gl, 0.0, this->size.y, 0.0);
    GLRenderer::end(gl);
  }
}
void DisplayNode::drawTopInverted(DisplayNode *this, RenderContext *rc, GLRenderer *gl)
{
  if ( this->txTop.kid )
  {
    GraphicsManager::setTexture(rc->graphics, 0, &this->txTop);
    GLRenderer::color4f(gl, this->color.x, this->color.y, this->color.z, this->color.w);
    GLRenderer::begin(gl, eQuads, 0);
    GLRenderer::texCoord2f(gl, this->blendX, 1.0);
    GLRenderer::vertex3f(gl, this->blendX * this->size.x, 0.0, 0.0);
    GLRenderer::texCoord2f(gl, 0.0, 1.0);
    GLRenderer::vertex3f(gl, 0.0, 0.0, 0.0);
    GLRenderer::texCoord2f(gl, 0.0, 0.0);
    GLRenderer::vertex3f(gl, 0.0, this->size.y, 0.0);
    GLRenderer::texCoord2f(gl, this->blendX, 0.0);
    GLRenderer::vertex3f(gl, this->blendX * this->size.x, this->size.y, 0.0);
    GLRenderer::end(gl);
  }
}
void DisplayNode::render(DisplayNode *this, RenderContext *rc)
{
  GLRenderer *v3; // ebx
  DigitalItemType v4; // eax
  int *v5; // eax
  __m128i v6; // xmm1
  int *v7; // eax
  GLRenderer *v8; // [esp-8h] [ebp-10h]

  if ( rc->meshFilter->passID != Transparent )
    goto LABEL_14;
  GraphicsManager::setWorldMatrix(rc->graphics, &this->matrixWS);
  v3 = rc->graphics->gl;
  v4 = this->type;
  if ( v4 == 25 )
  {
    v7 = this->valueInt;
    if ( v7 )
    {
      v6 = _mm_cvtsi32_si128(*v7);
LABEL_12:
      if ( this->trigger == _mm_cvtepi32_ps(v6).m128_f32[0] )
        DisplayNode::drawBase(this, rc, rc->graphics->gl);
    }
LABEL_14:
    Node::render(this, rc);
    return;
  }
  if ( v4 == 30 )
  {
    v5 = this->valueInt;
    if ( v5 )
    {
      v6 = _mm_cvtsi32_si128(*v5 / this->digit % 10);
      goto LABEL_12;
    }
    goto LABEL_14;
  }
  v8 = rc->graphics->gl;
  if ( v4 != 33 || this->trigger == 0.0 )
  {
    DisplayNode::drawBase(this, rc, v8);
    DisplayNode::drawTop(this, rc, v3);
    Node::render(this, rc);
  }
  else
  {
    DisplayNode::drawBaseInverted(this, rc, v8);
    DisplayNode::drawTopInverted(this, rc, v3);
    Node::render(this, rc);
  }
}
