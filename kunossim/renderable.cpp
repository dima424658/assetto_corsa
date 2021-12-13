#include "renderable.h"
void Renderable::Renderable(Renderable *this, std::wstring iname)
{
  bool v3; // cf

  Node::Node(this, &iname);
  v3 = iname._Myres < 8;
  this->__vftable = (Renderable_vtbl *)&Renderable::`vftable';
  this->boundingSphere.center.x = 0.0;
  this->boundingSphere.center.y = 0.0;
  this->boundingSphere.center.z = 0.0;
  this->boundingSphere.radius = 0.0;
  *(_DWORD *)&this->castShadows = 257;
  this->layer = 0;
  this->lodIN = 0.0;
  this->lodOUT = 0.0;
  this->isStatic = 0;
  if ( !v3 )
    operator delete(iname._Bx._Ptr);
}
void Renderable::~Renderable(Renderable *this)
{
  this->__vftable = (Renderable_vtbl *)&Renderable::`vftable';
  Node::~Node(this);
}
Renderable *Renderable::`scalar deleting destructor'(Renderable *this, unsigned int a2)
{
  this->__vftable = (Renderable_vtbl *)&Renderable::`vftable';
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Renderable::Renderable(Renderable *this, const Renderable *__that)
{
  Node::Node(this, __that);
  this->__vftable = (Renderable_vtbl *)&Renderable::`vftable';
  this->castShadows = __that->castShadows;
  this->isVisible = __that->isVisible;
  this->isTransparent = __that->isTransparent;
  this->noCull = __that->noCull;
  this->boundingSphere.center.x = 0.0;
  this->boundingSphere.center.y = 0.0;
  this->boundingSphere.center.z = 0.0;
  this->boundingSphere = __that->boundingSphere;
  this->layer = __that->layer;
  this->lodIN = __that->lodIN;
  this->lodOUT = __that->lodOUT;
  this->isStatic = __that->isStatic;
}
