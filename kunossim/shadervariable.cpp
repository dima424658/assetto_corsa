#include "shadervariable.h
void ShaderVariable::ShaderVariable(ShaderVariable *this, std::wstring iname, CBuffer *cbuffer, int ioffset, int isize)
{
  std::wstring *v6; // edi
  int v7; // eax

  v6 = &this->name;
  this->__vftable = (ShaderVariable_vtbl *)&ShaderVariable::`vftable';
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  this->buffer = cbuffer;
  if ( &this->name != &iname )
    std::wstring::assign(&this->name, &iname, 0, 0xFFFFFFFF);
  this->offset = ioffset;
  v7 = isize;
  this->size = isize;
  switch ( v7 )
  {
    case 4:
      this->type = eBoolean;
      break;
    case 8:
      this->type = eInteger;
      break;
    case 12:
      this->type = eFloat;
      break;
    case 16:
      this->type = eDouble;
      break;
    case 64:
      this->type = 4;
      break;
    default:
      this->type = 5;
      if ( std::wstring::compare(v6, 0, v6->_Mysize, L"bones", 5u) )
        _printf("ERROR: Variable type cannot be found\n");
      break;
  }
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
}
ShaderVariable *ShaderVariable::`vector deleting destructor'(ShaderVariable *this, unsigned int a2)
{
  this->__vftable = (ShaderVariable_vtbl *)&ShaderVariable::`vftable';
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ShaderVariable::set(ShaderVariable *this, float *value)
{
  CBuffer::set(this->buffer, value, this->offset, this->size);
}
