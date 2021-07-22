#include "resourcestore.h
void ResourceStore::ResourceStore(ResourceStore *this, GraphicsManager *rm)
{
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TagDocumentText>> > *v3; // ecx
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v4; // eax

  this->__vftable = (ResourceStore_vtbl *)&ResourceStore::`vftable';
  v3 = (std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TagDocumentText>> > *)&this->store;
  v3->_Myhead = 0;
  this->store._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<CarAvatar * const,Lap>>>::_Buyheadnode(v3);
  this->store._Myhead = v4;
  this->graphics = rm;
}
void ResourceStore::~ResourceStore(ResourceStore *this)
{
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v1; // edi
  std::map<std::wstring,Texture> *v2; // ebx
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v3; // esi
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v4; // eax
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *j; // eax
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *i; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > *v7; // [esp-4h] [ebp-24h]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > result; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)this;
  this->__vftable = (ResourceStore_vtbl *)&ResourceStore::`vftable';
  v1 = this->store._Myhead;
  v2 = &this->store;
  v9 = 0;
  v3 = v1->_Left;
  while ( v3 != v1 )
  {
    Texture::release(&v3->_Myval.second);
    if ( !v3->_Isnil )
    {
      v4 = v3->_Right;
      if ( v4->_Isnil )
      {
        for ( i = v3->_Parent; !i->_Isnil; i = i->_Parent )
        {
          if ( v3 != i->_Right )
            break;
          v3 = i;
        }
        v3 = i;
      }
      else
      {
        v3 = v3->_Right;
        for ( j = v4->_Left; !j->_Isnil; j = j->_Left )
          v3 = j;
      }
    }
  }
  v7 = (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > *)v2->_Myhead;
  v9 = -1;
  std::_Tree<std::_Tmap_traits<std::wstring,Texture,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,Texture>>,0>>::erase(
    v2,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > >)v7->_Ptr,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > >)v7);
  operator delete(v2->_Myhead);
}
ResourceStore *ResourceStore::`scalar deleting destructor'(ResourceStore *this, unsigned int a2)
{
  ResourceStore::~ResourceStore(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
Texture *ResourceStore::getTexture(ResourceStore *this, Texture *result, const std::wstring *filename, bool onlyExisting)
{
  std::map<std::wstring,Texture> *v4; // ebp
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v5; // eax
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v6; // esi
  const wchar_t *v7; // eax
  Texture *v8; // eax
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v10; // [esp+14h] [ebp-34h]
  Texture nt; // [esp+1Ch] [ebp-2Ch] BYREF
  int v12; // [esp+44h] [ebp-4h]

  v4 = &this->store;
  v5 = std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
         (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->store,
         filename);
  v6 = v5;
  if ( v5 == (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)v4->_Myhead )
    goto LABEL_6;
  v7 = v5->_Myval.first._Bx._Buf;
  if ( v6->_Myval.first._Myres >= 8 )
    v7 = *(const wchar_t **)v7;
  if ( std::wstring::compare((std::wstring *)filename, 0, filename->_Mysize, v7, v6->_Myval.first._Mysize) < 0 )
LABEL_6:
    v10 = v4->_Myhead;
  else
    v10 = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v6;
  if ( v10 == v4->_Myhead )
  {
    if ( !Path::fileExists((unsigned int)filename, filename, 0) || onlyExisting )
    {
      result->kid = 0;
      result->fileName._Myres = 7;
      result->fileName._Mysize = 0;
      result->fileName._Bx._Buf[0] = 0;
    }
    else
    {
      Texture::Texture(&nt, filename);
      v12 = 0;
      v8 = std::map<std::wstring,Texture>::operator[](v4, filename);
      v8->kid = nt.kid;
      if ( &v8->fileName != &nt.fileName )
        std::wstring::assign(&v8->fileName, &nt.fileName, 0, 0xFFFFFFFF);
      result->kid = nt.kid;
      result->fileName._Myres = 7;
      result->fileName._Mysize = 0;
      result->fileName._Bx._Buf[0] = 0;
      std::wstring::assign(&result->fileName, &nt.fileName, 0, 0xFFFFFFFF);
      v12 = -1;
      OnSetupAppCreated::~OnSetupAppCreated(&nt);
    }
  }
  else
  {
    result->kid = v10->_Myval.second.kid;
    result->fileName._Myres = 7;
    result->fileName._Mysize = 0;
    result->fileName._Bx._Buf[0] = 0;
    std::wstring::assign(&result->fileName, &v10->_Myval.second.fileName, 0, 0xFFFFFFFF);
  }
  return result;
}
Texture *ResourceStore::getTextureFromBuffer(ResourceStore *this, Texture *result, const std::wstring *name, unsigned __int8 *buffer, int size)
{
  std::map<std::wstring,Texture> *v5; // ebp
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v6; // eax
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v7; // esi
  const wchar_t *v8; // eax
  Texture *v9; // eax
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v11; // [esp+14h] [ebp-3Ch]
  Texture nt; // [esp+24h] [ebp-2Ch] BYREF
  int v13; // [esp+4Ch] [ebp-4h]

  v5 = &this->store;
  v6 = std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
         (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->store,
         name);
  v7 = v6;
  if ( v6 == (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)v5->_Myhead )
    goto LABEL_6;
  v8 = v6->_Myval.first._Bx._Buf;
  if ( v7->_Myval.first._Myres >= 8 )
    v8 = *(const wchar_t **)v8;
  if ( std::wstring::compare((std::wstring *)name, 0, name->_Mysize, v8, v7->_Myval.first._Mysize) < 0 )
LABEL_6:
    v11 = v5->_Myhead;
  else
    v11 = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v7;
  if ( v11 == v5->_Myhead )
  {
    Texture::Texture(&nt, buffer, size);
    v13 = 0;
    if ( &nt.fileName != name )
      std::wstring::assign(&nt.fileName, name, 0, 0xFFFFFFFF);
    v9 = std::map<std::wstring,Texture>::operator[](v5, name);
    v9->kid = nt.kid;
    if ( &v9->fileName != &nt.fileName )
      std::wstring::assign(&v9->fileName, &nt.fileName, 0, 0xFFFFFFFF);
    result->kid = nt.kid;
    result->fileName._Myres = 7;
    result->fileName._Mysize = 0;
    result->fileName._Bx._Buf[0] = 0;
    std::wstring::assign(&result->fileName, &nt.fileName, 0, 0xFFFFFFFF);
    v13 = -1;
    OnSetupAppCreated::~OnSetupAppCreated(&nt);
  }
  else
  {
    result->kid = v11->_Myval.second.kid;
    result->fileName._Myres = 7;
    result->fileName._Mysize = 0;
    result->fileName._Bx._Buf[0] = 0;
    std::wstring::assign(&result->fileName, &v11->_Myval.second.fileName, 0, 0xFFFFFFFF);
  }
  return result;
}
BOOL ResourceStore::hasTexture(ResourceStore *this, const std::wstring *name)
{
  std::map<std::wstring,Texture> *v2; // ebx
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v3; // edi
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v4; // eax
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v5; // esi
  const wchar_t *v6; // eax
  BOOL result; // eax

  v2 = &this->store;
  v3 = this->store._Myhead;
  v4 = std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
         (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->store,
         name);
  v5 = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v4;
  if ( v4 == (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)v2->_Myhead )
    goto LABEL_6;
  v6 = v4->_Myval.first._Bx._Buf;
  if ( v5->_Myval.first._Myres >= 8 )
    v6 = *(const wchar_t **)v6;
  if ( std::wstring::compare((std::wstring *)name, 0, name->_Mysize, v6, v5->_Myval.first._Mysize) < 0 )
LABEL_6:
    result = v2->_Myhead != v3;
  else
    result = v5 != v3;
  return result;
}
