#include "setupitem.h
void SetupItem::SetupItem(SetupItem *this, const SetupItem *__that)
{
  SetupItem *v2; // edi
  std::wstring *v3; // ecx
  const SetupItem *v4; // ecx
  SetupItem_vtbl *v5; // eax
  int v6; // eax

  v2 = this;
  v3 = &this->name;
  this->__vftable = (SetupItem_vtbl *)&SetupItem::`vftable';
  v3->_Myres = 7;
  v3->_Mysize = 0;
  v3->_Bx._Buf[0] = 0;
  std::wstring::assign(v3, &__that->name, 0, 0xFFFFFFFF);
  v2->connectedFloat = __that->connectedFloat;
  v2->units._Myres = 7;
  v2->units._Mysize = 0;
  v2->units._Bx._Buf[0] = 0;
  std::wstring::assign(&v2->units, &__that->units, 0, 0xFFFFFFFF);
  v2->multiplier = __that->multiplier;
  v2->newValue = __that->newValue;
  v2->attached = __that->attached;
  v2->onValueChanged._Impl = 0;
  v4 = (const SetupItem *)__that->onValueChanged._Impl;
  if ( v4 )
  {
    v5 = v4->__vftable;
    if ( v4 == (const SetupItem *)&__that->onValueChanged )
      v6 = ((int (__stdcall *)(std::function<void __cdecl(SetupItem *)> *))v5->~SetupItem)(&v2->onValueChanged);
    else
      v6 = ((int (__stdcall *)(_DWORD))v5->~SetupItem)(0);
    v2->onValueChanged._Impl = (std::_Func_base<void,SetupItem *> *)v6;
  }
  else
  {
    v2->onValueChanged._Impl = 0;
  }
  v2->labelMultiplier = __that->labelMultiplier;
}
SetupItem *SetupItem::`scalar deleting destructor'(SetupItem *this, unsigned int a2)
{
  SetupItem::~SetupItem(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SetupItem::SetupItem(SetupItem *this, std::wstring aname, float *aconnectedFloat, std::wstring units, bool isAttached, float multiplier, float labelMult)
{
  SetupItem *v7; // esi
  std::wstring *v8; // ecx
  bool v9; // cf
  float *v10; // eax
  float v11; // xmm1_4

  v7 = this;
  v8 = &this->name;
  this->__vftable = (SetupItem_vtbl *)&SetupItem::`vftable';
  v8->_Myres = 7;
  v8->_Mysize = 0;
  v8->_Bx._Buf[0] = 0;
  std::wstring::assign(v8, &aname, 0, 0xFFFFFFFF);
  v7->connectedFloat = aconnectedFloat;
  v7->units._Myres = 7;
  v7->units._Mysize = 0;
  v7->units._Bx._Buf[0] = 0;
  v7->attached = isAttached;
  v7->onValueChanged._Impl = 0;
  v7->labelMultiplier = labelMult;
  if ( &v7->units != &units )
    std::wstring::assign(&v7->units, &units, 0, 0xFFFFFFFF);
  v9 = aname._Myres < 8;
  v10 = v7->connectedFloat;
  v11 = multiplier;
  v7->multiplier = multiplier;
  v7->newValue = *v10 / v11;
  if ( !v9 )
    operator delete(aname._Bx._Ptr);
  aname._Myres = 7;
  aname._Mysize = 0;
  aname._Bx._Buf[0] = 0;
  if ( units._Myres >= 8 )
    operator delete(units._Bx._Ptr);
}
void SetupItem::~SetupItem(SetupItem *this)
{
  std::function<void __cdecl(SetupItem *)> *v2; // edi
  std::_Func_base<void,SetupItem *> *v3; // ecx
  std::_Func_base<void,SetupItem *> *v4; // ecx

  v2 = &this->onValueChanged;
  this->__vftable = (SetupItem_vtbl *)&SetupItem::`vftable';
  v3 = this->onValueChanged._Impl;
  if ( v3 )
  {
    ((void (__stdcall *)(bool))v3->_Delete_this)(v3 != (std::_Func_base<void,SetupItem *> *)v2);
    v2->_Impl = 0;
  }
  v4 = v2->_Impl;
  if ( v4 )
  {
    ((void (__stdcall *)(bool))v4->_Delete_this)(v4 != (std::_Func_base<void,SetupItem *> *)v2);
    v2->_Impl = 0;
  }
  if ( this->units._Myres >= 8 )
    operator delete(this->units._Bx._Ptr);
  this->units._Myres = 7;
  this->units._Mysize = 0;
  this->units._Bx._Buf[0] = 0;
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
