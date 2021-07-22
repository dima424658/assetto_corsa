#include "accontrol.h
void ACControl::ACControl(ACControl *this, ksgui::GUI *igui)
{
  std::wstring iname; // [esp+Ch] [ebp-28h] BYREF
  int v4; // [esp+30h] [ebp-4h]

  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"AC_CONTROL", 0xAu);
  v4 = 0;
  ksgui::Control::Control(this, &iname, igui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->IACControl::__vftable = (IACControl_vtbl *)&IACControl::`vftable';
  this->ksgui::Control::__vftable = (ACControl_vtbl *)&ACControl::`vftable'{for `ksgui::Control'};
  this->IACControl::__vftable = (IACControl_vtbl *)&ACControl::`vftable'{for `IACControl'};
}
ACControl *ACControl::`scalar deleting destructor'(ACControl *this, unsigned int a2)
{
  this->ksgui::Control::__vftable = (ACControl_vtbl *)&ACControl::`vftable'{for `ksgui::Control'};
  this->IACControl::__vftable = (IACControl_vtbl *)&ACControl::`vftable'{for `IACControl'};
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void *ACControl::getTag(ACControl *this)
{
  return this[-1].backTexture.kid;
}
std::wstring *ACControl::getText(char *this)
{
  return ksgui::Control::getText((ACControl *)(this - 280));
}
void ACControl::setControlPosition(ACControl *this, float x, float y)
{
  ksgui::Form::setPosition((ksgui::Form *)&this[-1].name, x, y);
}
void ACControl::setControlSize(ACControl *this, float x, float y)
{
  ksgui::Control::setSize((ACControl *)((char *)this - 280), x, y);
}
void ACControl::setTag(ACControl *this, void *atag)
{
  this[-1].backTexture.kid = atag;
}
void ACControl::setText(char *this, const std::wstring *a2)
{
  ksgui::Control::setText((ACControl *)(this - 280), a2);
}
