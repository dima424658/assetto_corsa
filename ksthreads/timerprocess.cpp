#include "timerprocess.h
void TimerProcess::TimerProcess(TimerProcess *this, int interval, std::function<void __cdecl(void)> callback)
{
  std::function<void __cdecl(void)> *v4; // esi
  std::_Func_base<void>_vtbl *v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  std::_Func_base<void> *v8; // ecx

  v4 = &this->callback;
  this->__vftable = (TimerProcess_vtbl *)&TimerProcess::`vftable';
  this->interval = interval;
  this->callback._Impl = 0;
  if ( callback._Impl )
  {
    v5 = callback._Impl->__vftable;
    if ( (std::function<void __cdecl(void)> *)callback._Impl == &callback )
      v6 = ((int (__stdcall *)(std::function<void __cdecl(void)> *))v5->_Copy)(v4);
    else
      v6 = ((int (__stdcall *)(_DWORD))v5->_Copy)(0);
    v4->_Impl = (std::_Func_base<void> *)v6;
  }
  else
  {
    this->callback._Impl = 0;
  }
  v7 = timeSetEvent(interval, 0, timer2_callback, (DWORD_PTR)this, 1u);
  v8 = callback._Impl;
  this->hTimer2 = v7;
  if ( v8 )
    ((void (__stdcall *)(bool))v8->_Delete_this)(v8 != (std::_Func_base<void> *)&callback);
}
void TimerProcess::~TimerProcess(TimerProcess *this)
{
  std::_Func_base<void> *v2; // ecx
  std::function<void __cdecl(void)> *v3; // esi
  std::_Func_base<void> *v4; // ecx
  unsigned int v5; // [esp-4h] [ebp-8h]

  v5 = this->hTimer2;
  this->__vftable = (TimerProcess_vtbl *)&TimerProcess::`vftable';
  timeKillEvent(v5);
  v2 = this->callback._Impl;
  v3 = &this->callback;
  if ( v2 )
  {
    ((void (__stdcall *)(bool))v2->_Delete_this)(v2 != (std::_Func_base<void> *)v3);
    v3->_Impl = 0;
  }
  v4 = v3->_Impl;
  if ( v4 )
  {
    ((void (__stdcall *)(bool))v4->_Delete_this)(v4 != (std::_Func_base<void> *)v3);
    v3->_Impl = 0;
  }
}
void TimerProcess::step(TimerProcess *this)
{
  std::_Func_base<void> *v1; // ecx

  v1 = this->callback._Impl;
  if ( v1 )
    v1->_Do_call(v1);
  else
    std::_Xbad_function_call();
}
