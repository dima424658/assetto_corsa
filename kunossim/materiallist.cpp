#include "materiallist.h
void MaterialList::MaterialList(MaterialList *this)
{
  this->__vftable = (MaterialList_vtbl *)&MaterialList::`vftable';
  this->materials._Myfirst = 0;
  this->materials._Mylast = 0;
  this->materials._Myend = 0;
  this->textures._Myfirst = 0;
  this->textures._Mylast = 0;
  this->textures._Myend = 0;
}
void MaterialList::~MaterialList(MaterialList *this)
{
  this->__vftable = (MaterialList_vtbl *)&MaterialList::`vftable';
  std::vector<Texture>::_Tidy(&this->textures);
  if ( this->materials._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->materials);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::shared_ptr<Material>>>>(
      this->materials._Myfirst,
      this->materials._Mylast);
    operator delete(this->materials._Myfirst);
    this->materials._Myfirst = 0;
    this->materials._Mylast = 0;
    this->materials._Myend = 0;
  }
}
MaterialList *MaterialList::`vector deleting destructor'(MaterialList *this, unsigned int a2)
{
  this->__vftable = (MaterialList_vtbl *)&MaterialList::`vftable';
  std::vector<Texture>::_Tidy(&this->textures);
  if ( this->materials._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->materials);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::shared_ptr<Material>>>>(
      this->materials._Myfirst,
      this->materials._Mylast);
    operator delete(this->materials._Myfirst);
    this->materials._Myfirst = 0;
    this->materials._Mylast = 0;
    this->materials._Myend = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
Texture *MaterialList::getTextureFromName(MaterialList *this, Texture *result, const std::wstring *name)
{
  Texture *v4; // eax
  Texture *v5; // eax

  v4 = std::_Find_if<Texture *,_lambda_14a9fb379b2fcf61985a07182e02a074_>(
         this->textures._Myfirst,
         this->textures._Mylast,
         (MaterialList::getTextureFromName::__l3::<lambda_14a9fb379b2fcf61985a07182e02a074>)name);
  if ( v4 == this->textures._Mylast )
  {
    v5 = result;
    result->kid = 0;
    result->fileName._Myres = 7;
    result->fileName._Mysize = 0;
    result->fileName._Bx._Buf[0] = 0;
  }
  else
  {
    result->kid = v4->kid;
    result->fileName._Myres = 7;
    result->fileName._Mysize = 0;
    result->fileName._Bx._Buf[0] = 0;
    std::wstring::assign(&result->fileName, &v4->fileName, 0, 0xFFFFFFFF);
    v5 = result;
  }
  return v5;
}
