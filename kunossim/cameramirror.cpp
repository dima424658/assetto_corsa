#include "cameramirror.h"
void CameraMirror::CameraMirror(CameraMirror *this, const std::wstring *name, GraphicsManager *graphics)
{
  Camera::Camera(this, name, graphics);
  this->__vftable = (CameraMirror_vtbl *)&CameraMirror::`vftable';
  this->tyreSmoke = 0;
}
CameraMirror *CameraMirror::`vector deleting destructor'(CameraMirror *this, unsigned int a2)
{
  this->__vftable = (CameraMirror_vtbl *)&CameraMirror::`vftable';
  Camera::~Camera(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraMirror::renderOpaque(CameraMirror *this, Node *node, float dt)
{
  GraphicsManager *v4; // eax
  MaterialFilter materialFilter; // [esp+Ch] [ebp-74h] BYREF
  RenderContext rc; // [esp+14h] [ebp-6Ch] BYREF
  CameraMeshFilter filter; // [esp+24h] [ebp-5Ch] BYREF
  mat44f id; // [esp+34h] [ebp-4Ch] BYREF
  int v9; // [esp+7Ch] [ebp-4h]

  CameraMeshFilter::CameraMeshFilter(&filter, this, Opaque, (int)this->maxLayer);
  v9 = 0;
  MaterialFilter::MaterialFilter(&materialFilter);
  v4 = this->graphics;
  rc.materialFilter = &materialFilter;
  rc.meshFilter = &filter;
  LOBYTE(v9) = 1;
  rc.graphics = v4;
  rc.camera = this;
  Camera::renderCamera(this);
  Camera::clearBuffers(this);
  if ( this->skyBox )
  {
    mat44f::mat44f(&id);
    mat44f::loadIdentity(&id);
    GraphicsManager::setWorldMatrix(this->graphics, &id);
    PvsProcessor::begin(this->graphics->pvsProcessor, &rc, Default, 0, 0);
    SkyBox::render(this->skyBox, &rc);
    PvsProcessor::end(this->graphics->pvsProcessor);
    GraphicsManager::clearRenderTargetDepth(this->graphics, this->clearDepth);
  }
  PvsProcessor::begin(this->graphics->pvsProcessor, &rc, Default, 0, 0);
  node->render(node, &rc);
  PvsProcessor::end(this->graphics->pvsProcessor);
  LOBYTE(v9) = 0;
  MaterialFilter::~MaterialFilter(&materialFilter);
  v9 = -1;
  CameraMeshFilter::~CameraMeshFilter(&filter);
}
void CameraMirror::renderTransparent(CameraMirror *this, Node *node, float dt)
{
  GraphicsManager *v4; // ecx
  MaterialFilter materialFilter; // [esp+8h] [ebp-34h] BYREF
  RenderContext rcTR; // [esp+10h] [ebp-2Ch] BYREF
  CameraMeshFilter filterTR; // [esp+20h] [ebp-1Ch] BYREF
  int v8; // [esp+38h] [ebp-4h]

  CameraMeshFilter::CameraMeshFilter(&filterTR, this, Transparent, (int)this->maxLayer);
  v8 = 0;
  MaterialFilter::MaterialFilter(&materialFilter);
  v4 = this->graphics;
  rcTR.materialFilter = &materialFilter;
  LOBYTE(v8) = 1;
  rcTR.meshFilter = &filterTR;
  rcTR.graphics = v4;
  rcTR.camera = this;
  GraphicsManager::setDepthMode(v4, eDepthNoWrite);
  PvsProcessor::begin(this->graphics->pvsProcessor, &rcTR, Default, 0, 0);
  node->render(node, &rcTR);
  PvsProcessor::end(this->graphics->pvsProcessor);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  LOBYTE(v8) = 0;
  MaterialFilter::~MaterialFilter(&materialFilter);
  v8 = -1;
  CameraMeshFilter::~CameraMeshFilter(&filterTR);
}
