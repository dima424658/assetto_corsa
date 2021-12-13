#include "debugtimer.h"
void DebugTimer::DebugTimer(DebugTimer *this, const std::wstring *iname)
{
  std::wstring *v3; // ecx

  this->__vftable = (DebugTimer_vtbl *)&DebugTimer::`vftable';
  v3 = &this->name;
  v3->_Myres = 7;
  v3->_Mysize = 0;
  v3->_Bx._Buf[0] = 0;
  std::wstring::assign(v3, iname, 0, 0xFFFFFFFF);
  this->startTime = ksGetQPTTime();
}
void DebugTimer::~DebugTimer(DebugTimer *this)
{
  std::wstring *v2; // ebx
  double v3; // st7

  this->__vftable = (DebugTimer_vtbl *)&DebugTimer::`vftable';
  if ( this->name._Myres < 8 )
    v2 = &this->name;
  else
    v2 = (std::wstring *)this->name._Bx._Ptr;
  v3 = ksGetQPTTime();
  _printf("DEBUG TIMER: %S:%f\n", v2->_Bx._Buf, v3 - (double)this->startTime);
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
DebugTimer *DebugTimer::`vector deleting destructor'(DebugTimer *this, unsigned int a2)
{
  DebugTimer::~DebugTimer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
