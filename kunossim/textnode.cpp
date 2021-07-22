#include "textnode.h
void TextNode::TextNode(TextNode *this, std::wstring a_name, StringBlitter3D *a_blitter)
{
  bool v4; // cf

  Node::Node(this, &a_name);
  this->__vftable = (TextNode_vtbl *)&TextNode::`vftable';
  this->text._Myres = 7;
  this->text._Mysize = 0;
  this->text._Bx._Buf[0] = 0;
  v4 = a_name._Myres < 8;
  this->blitter = a_blitter;
  this->scale = 1.0;
  this->color = (vec4f)_xmm;
  this->align = eAlignLeft;
  this->version = 1;
  if ( !v4 )
    operator delete(a_name._Bx._Ptr);
}
TextNode *TextNode::`vector deleting destructor'(TextNode *this, unsigned int a2)
{
  this->__vftable = (TextNode_vtbl *)&TextNode::`vftable';
  if ( this->text._Myres >= 8 )
    operator delete(this->text._Bx._Ptr);
  this->text._Myres = 7;
  this->text._Mysize = 0;
  this->text._Bx._Buf[0] = 0;
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TextNode::render(TextNode *this, RenderContext *rc)
{
  vec3f v3; // [esp+8h] [ebp-20h]
  vec3f v4; // [esp+8h] [ebp-20h]

  if ( rc->meshFilter->passID == Transparent )
  {
    GraphicsManager::setWorldMatrix(rc->graphics, &this->matrixWS);
    StringBlitter3D::setColor(this->blitter, &this->color);
    this->blitter->scale = this->scale;
    if ( this->version == 1 )
    {
      *(_QWORD *)&v4.x = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64).m128_u64[0];
      v4.z = 0.0;
      StringBlitter3D::blitString(this->blitter, &this->text, this->scale, this->align, v4);
    }
    else if ( this->version == 2 )
    {
      StringBlitter3D::setScaleConst(this->blitter, 1.0);
      *(_QWORD *)&v3.x = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64).m128_u64[0];
      v3.z = 0.0;
      StringBlitter3D::blitStringV2(this->blitter, &this->text, this->scale, this->align, v3);
    }
  }
  MaterialFilter::resetMaterialCache((Turbo *)rc->materialFilter);
  Node::render(this, rc);
}
