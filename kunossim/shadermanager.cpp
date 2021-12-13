#include "shadermanager.h"
void ShaderManager::ShaderManager(ShaderManager *this, GraphicsManager *graphics)
{
  this->graphics = graphics;
  this->__vftable = (ShaderManager_vtbl *)&ShaderManager::`vftable';
  this->shaders._Myfirst = 0;
  this->shaders._Mylast = 0;
  this->shaders._Myend = 0;
}
void ShaderManager::~ShaderManager(ShaderManager *this)
{
  std::vector<Shader *> *v1; // esi

  v1 = &this->shaders;
  this->__vftable = (ShaderManager_vtbl *)&ShaderManager::`vftable';
  if ( this->shaders._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->shaders);
    operator delete(v1->_Myfirst);
    v1->_Myfirst = 0;
    v1->_Mylast = 0;
    v1->_Myend = 0;
  }
}
ShaderManager *ShaderManager::`vector deleting destructor'(ShaderManager *this, unsigned int a2)
{
  this->__vftable = (ShaderManager_vtbl *)&ShaderManager::`vftable';
  if ( this->shaders._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->shaders);
    operator delete(this->shaders._Myfirst);
    this->shaders._Myfirst = 0;
    this->shaders._Mylast = 0;
    this->shaders._Myend = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ShaderManager::cleanup(ShaderManager *this)
{
  Shader **v1; // esi
  unsigned int v2; // ebx
  int v3; // edi

  v1 = this->shaders._Myfirst;
  v2 = (unsigned int)((char *)this->shaders._Mylast - (char *)v1 + 3) >> 2;
  v3 = 0;
  if ( v1 > this->shaders._Mylast )
    v2 = 0;
  if ( v2 )
  {
    do
    {
      if ( *v1 )
        ((void (*)(Shader *, int))(*v1)->~Shader)(*v1, 1);
      ++v3;
      ++v1;
    }
    while ( v3 != v2 );
  }
}
Shader *__userpurge ShaderManager::getShader@<eax>(ShaderManager *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *name)
{
  const std::wstring *v4; // esi
  Shader **v5; // eax
  Shader *v7; // eax
  Shader *v8; // eax
  Shader *v9; // esi
  Shader *sh; // [esp+10h] [ebp-5Ch] BYREF
  std::wstring vertexShader; // [esp+14h] [ebp-58h] BYREF
  std::wstring pixelShader; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring s; // [esp+44h] [ebp-28h] BYREF
  int v14; // [esp+68h] [ebp-4h]

  v4 = name;
  v5 = std::_Find_if<Shader * *,_lambda_c088d720ac5d7f25c7517eee00002c73_>(
         this->shaders._Myfirst,
         this->shaders._Mylast,
         (ShaderManager::getShader::__l3::<lambda_c088d720ac5d7f25c7517eee00002c73>)name);
  if ( v5 != this->shaders._Mylast )
    return *v5;
  std::operator+<wchar_t>(&s, L"system/shaders/win/", name);
  v14 = 0;
  std::operator+<wchar_t>(&pixelShader, &s, L"_ps.fxo");
  LOBYTE(v14) = 1;
  std::operator+<wchar_t>(&vertexShader, &s, L"_vs.fxo");
  LOBYTE(v14) = 2;
  if ( Path::fileExists(a2, &pixelShader, 0) && Path::fileExists(a2, &vertexShader, 0) )
  {
    v7 = (Shader *)operator new(124);
    sh = v7;
    LOBYTE(v14) = 3;
    if ( v7 )
      Shader::Shader(v7, this->graphics, &s);
    else
      v8 = 0;
    sh = v8;
    LOBYTE(v14) = 2;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&this->shaders,
      (ICollisionObject *const *)&sh);
    v9 = sh;
  }
  else
  {
    if ( name->_Myres >= 8 )
      v4 = (const std::wstring *)name->_Bx._Ptr;
    _printf("ERROR: Shader %S NOT FOUND, RETURNING NULL\n", v4->_Bx._Buf);
    _fflush(0);
    v9 = 0;
  }
  if ( vertexShader._Myres >= 8 )
    operator delete(vertexShader._Bx._Ptr);
  vertexShader._Myres = 7;
  vertexShader._Mysize = 0;
  vertexShader._Bx._Buf[0] = 0;
  if ( pixelShader._Myres >= 8 )
    operator delete(pixelShader._Bx._Ptr);
  pixelShader._Myres = 7;
  pixelShader._Mysize = 0;
  pixelShader._Bx._Buf[0] = 0;
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  return v9;
}
