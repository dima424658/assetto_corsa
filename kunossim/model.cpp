#include "model.h"
void Model::Model(Model *this, std::wstring name)
{
  Node::Node(this, &name);
  this->__vftable = (Model_vtbl *)&Model::`vftable';
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
Model *Model::`vector deleting destructor'(Model *this, unsigned int a2)
{
  this->__vftable = (Model_vtbl *)&Model::`vftable';
  if ( this->fileName._Myres >= 8 )
    operator delete(this->fileName._Bx._Ptr);
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Model::load(Model *this, const std::wstring *filename, GraphicsManager *graphics, IModelImporter *importer)
{
  const std::wstring *v5; // esi
  std::wstring *v6; // ecx
  std::wstring *v7; // eax
  IModelImporter_vtbl *v8; // edx
  unsigned int v9; // ecx
  IModelImporter_vtbl *v10; // eax
  Node *v11; // esi
  std::wstring result; // [esp+10h] [ebp-40h] BYREF
  std::wstring path; // [esp+28h] [ebp-28h] BYREF
  int v14; // [esp+4Ch] [ebp-4h]

  v5 = filename;
  v6 = &this->fileName;
  if ( v6 != filename )
    std::wstring::assign(v6, filename, 0, 0xFFFFFFFF);
  Path::getPath(&path, filename);
  v14 = 0;
  v7 = std::operator+<wchar_t>(&result, &path, L"/texture");
  v8 = importer->__vftable;
  LOBYTE(v14) = 1;
  v8->addTextureFolder(importer, v7);
  LOBYTE(v14) = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( filename->_Myres >= 8 )
    v5 = (const std::wstring *)filename->_Bx._Ptr;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v5->_Bx._Buf[0] )
    v9 = wcslen(v5->_Bx._Buf);
  else
    v9 = 0;
  std::wstring::assign(&result, v5->_Bx._Buf, v9);
  v10 = importer->__vftable;
  LOBYTE(v14) = 2;
  v11 = v10->load(importer, &result);
  LOBYTE(v14) = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v11 )
    this->addChild(this, v11);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
}
