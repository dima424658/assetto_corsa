#include "nodeboundingsphere.h
void NodeBoundingSphere::NodeBoundingSphere(NodeBoundingSphere *this, std::wstring name, float radius)
{
  bool v4; // cf
  float v5; // xmm0_4
  std::wstring v6; // [esp-18h] [ebp-30h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  v7 = 0;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, &name, 0, 0xFFFFFFFF);
  Renderable::Renderable(this, v6);
  v4 = name._Myres < 8;
  v5 = radius;
  this->__vftable = (NodeBoundingSphere_vtbl *)&NodeBoundingSphere::`vftable';
  this->delegateNode = 0;
  *(_DWORD *)&this->castShadows = 65793;
  this->boundingSphere.radius = v5;
  if ( !v4 )
    operator delete(name._Bx._Ptr);
}
NodeBoundingSphere *NodeBoundingSphere::`vector deleting destructor'(NodeBoundingSphere *this, unsigned int a2)
{
  this->__vftable = (NodeBoundingSphere_vtbl *)&NodeBoundingSphere::`vftable';
  Renderable::~Renderable(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void NodeBoundingSphere::applyNoCull(NodeBoundingSphere *this, Node *n)
{
  NodeBoundingSphere *v2; // eax
  bool v3; // zf

  v2 = (NodeBoundingSphere *)n;
  v3 = n == 0;
  n = this;
  if ( v3 )
    v2 = this;
  std::_For_each<Node * *,_lambda_3270fa600fff0b7b11de11848bf89cb4_>(
    v2->nodes._Myfirst,
    v2->nodes._Mylast,
    (NodeBoundingSphere::applyNoCull::__l9::<lambda_3270fa600fff0b7b11de11848bf89cb4> *)&n);
}
void NodeBoundingSphere::render(NodeBoundingSphere *this, RenderContext *rc)
{
  Node *v3; // eax
  sphere trSphere; // [esp+8h] [ebp-10h] BYREF

  v3 = this->delegateNode;
  if ( v3 )
  {
    *(__m128i *)&this->matrixWS.M11 = _mm_loadu_si128((const __m128i *)&v3->matrixWS);
    *(__m128i *)&this->matrixWS.M21 = _mm_loadu_si128((const __m128i *)&v3->matrixWS.M21);
    *(__m128i *)&this->matrixWS.M31 = _mm_loadu_si128((const __m128i *)&v3->matrixWS.M31);
    *(__m128i *)&this->matrixWS.M41 = _mm_loadu_si128((const __m128i *)&v3->matrixWS.M41);
  }
  sphere::transform(&this->boundingSphere, &trSphere, &this->matrixWS);
  if ( BoundingFrustum::intersect(&rc->camera->frustum, &trSphere) )
    Node::render(this, rc);
}
