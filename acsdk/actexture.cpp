#include "actexture.h"
void ACTexture::ACTexture(ACTexture *this, const std::wstring *filename, GraphicsManager *graphics)
{
  ResourceStore *v4; // ecx
  Texture *v5; // eax
  Texture result; // [esp+Ch] [ebp-2Ch] BYREF
  int v7; // [esp+34h] [ebp-4h]

  this->__vftable = (ACTexture_vtbl *)&ACTexture::`vftable';
  this->texture.kid = 0;
  this->texture.fileName._Myres = 7;
  this->texture.fileName._Mysize = 0;
  v7 = 0;
  this->texture.fileName._Bx._Buf[0] = 0;
  this->graphics = graphics;
  v4 = graphics->resourceStore._Myptr;
  LOBYTE(v7) = 1;
  v5 = ResourceStore::getTexture(v4, &result, filename, 0);
  this->texture.kid = v5->kid;
  LOBYTE(v7) = 2;
  if ( &this->texture.fileName != &v5->fileName )
    std::wstring::assign(&this->texture.fileName, &v5->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v7) = 1;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
}
ACTexture *ACTexture::`scalar deleting destructor'(ACTexture *this, unsigned int a2)
{
  this->__vftable = (ACTexture_vtbl *)&ACTexture::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->texture);
  this->__vftable = (ACTexture_vtbl *)&IACTexture::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACTexture::apply(ACTexture *this, int slot)
{
  GraphicsManager::setTexture(this->graphics, slot, &this->texture);
}
