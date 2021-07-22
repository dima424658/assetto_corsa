#include "dicontrolinput.h"
void DIControlInput::DIControlInput(DIControlInput *this, std::wstring iname, DirectInput *di)
{
  DIControlInput *v3; // esi
  std::wstring *v4; // ecx
  bool v5; // cf

  v3 = this;
  v4 = &this->name;
  this->__vftable = (DIControlInput_vtbl *)&DIControlInput::`vftable';
  v4->_Myres = 7;
  v4->_Mysize = 0;
  v4->_Bx._Buf[0] = 0;
  v3->axis.minv = 0.0;
  v3->axis.joy = -1;
  v3->axis.index = -1;
  v3->axis.maxv = 1.0;
  if ( v4 != &iname )
    std::wstring::assign(v4, &iname, 0, 0xFFFFFFFF);
  v5 = iname._Myres < 8;
  v3->directInput = di;
  v3->device = 0;
  if ( !v5 )
    operator delete(iname._Bx._Ptr);
}
void DIControlInput::~DIControlInput(DIControlInput *this)
{
  this->__vftable = (DIControlInput_vtbl *)&DIControlInput::`vftable';
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
DIControlInput *DIControlInput::`vector deleting destructor'(DIControlInput *this, unsigned int a2)
{
  this->__vftable = (DIControlInput_vtbl *)&DIControlInput::`vftable';
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
