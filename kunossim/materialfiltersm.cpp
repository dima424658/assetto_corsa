#include "materialfiltersm.h
void __userpurge MaterialFilterSM::MaterialFilterSM(MaterialFilterSM *this@<ecx>, unsigned int a2@<ebx>, GraphicsManager *graphics)
{
  Shader *v4; // eax
  bool v5; // cf
  Shader *v6; // eax
  Shader *v7; // eax
  Shader *v8; // eax
  Shader *v9; // eax
  std::wstring name; // [esp+10h] [ebp-28h] BYREF
  int v11; // [esp+34h] [ebp-4h]

  MaterialFilter::MaterialFilter(this);
  v11 = 0;
  this->__vftable = (MaterialFilterSM_vtbl *)&MaterialFilterSM::`vftable';
  this->graphics = graphics;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksShadowGen", 0xBu);
  LOBYTE(v11) = 1;
  v4 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->smNormal = v4;
  LOBYTE(v11) = 0;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  v6 = this->smNormal;
  name._Myres = 7;
  v6->useNullPS = 1;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksShadowGenAT", 0xDu);
  LOBYTE(v11) = 2;
  v7 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->smAlphaTested = v7;
  LOBYTE(v11) = 0;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksShadowGenSKIN", 0xFu);
  LOBYTE(v11) = 3;
  v8 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->smSkinned = v8;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  v9 = this->smSkinned;
  if ( v9 )
    v9->useNullPS = 1;
}
void MaterialFilterSM::~MaterialFilterSM(MaterialFilterSM *this)
{
  this->__vftable = (MaterialFilterSM_vtbl *)&MaterialFilterSM::`vftable';
  MaterialFilter::~MaterialFilter(this);
}
MaterialFilterSM *MaterialFilterSM::`scalar deleting destructor'(MaterialFilterSM *this, unsigned int a2)
{
  this->__vftable = (MaterialFilterSM_vtbl *)&MaterialFilterSM::`vftable';
  MaterialFilter::~MaterialFilter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void MaterialFilterSM::apply(MaterialFilterSM *this, const std::shared_ptr<Material> *material, RenderContext *rc)
{
  Material *v4; // ecx
  MaterialResource *v5; // eax
  MaterialResource *v6; // ecx
  Material *v7; // esi
  CBuffer *v8; // edi
  CBuffer *i; // esi
  GraphicsManager *v10; // ecx

  v4 = material->_Ptr;
  if ( material->_Ptr->shader->ilType == Skinned )
  {
    GraphicsManager::setShader(this->graphics, this->smSkinned);
  }
  else if ( v4->blendMode )
  {
    v5 = v4->resources._Myfirst;
    v6 = v4->resources._Mylast;
    if ( v5 != v6 )
    {
      while ( v5->slot )
      {
        if ( ++v5 == v6 )
          goto LABEL_7;
      }
      GraphicsManager::setTexture(this->graphics, v5->slot, &v5->texture);
    }
LABEL_7:
    GraphicsManager::setShader(this->graphics, this->smAlphaTested);
  }
  else
  {
    GraphicsManager::setShader(this->graphics, this->smNormal);
  }
  GraphicsManager::setBlendMode(this->graphics, eOpaque);
  v7 = material->_Ptr;
  if ( material->_Ptr->blendMode )
  {
    v8 = v7->cBuffers._Mylast;
    for ( i = v7->cBuffers._Myfirst; i != v8; ++i )
    {
      if ( i->slot == 4 )
        CBuffer::commit(i);
    }
  }
  v10 = this->graphics;
  if ( material->_Ptr->doubleFaceShadow )
    GraphicsManager::setCullMode(v10, eCullNone);
  else
    GraphicsManager::setCullMode(v10, eCullBack);
}
