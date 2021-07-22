#include "hotlapmode.h
void HotlapMode::HotlapMode(HotlapMode *this, Sim *aSim)
{
  CarAvatar *v3; // eax
  Event<OnLapCompletedEvent> *v4; // ecx
  std::wstring v5; // [esp-1Ch] [ebp-3Ch] BYREF
  Game *v6; // [esp-4h] [ebp-24h]
  HotlapMode *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = this;
  v6 = aSim->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"HOTLAP_MODE", 0xBu);
  GameMode::GameMode(this, v5, v6);
  v6 = 0;
  v8 = 0;
  this->__vftable = (HotlapMode_vtbl *)&HotlapMode::`vftable';
  v3 = Sim::getCar(aSim, (unsigned int)v6);
  v6 = (Game *)this;
  this->car = v3;
  this->sim = aSim;
  v5._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_667fe4fd1d29f79adbc68a2309d7b2a7_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  *(_DWORD *)&v5._Bx._Alias[4] = this;
  v5._Mysize = (unsigned int)&v5;
  v4 = &this->car->evOnLapCompleted;
  LOBYTE(v8) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v4,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v5,
    v6);
}
HotlapMode *HotlapMode::`vector deleting destructor'(HotlapMode *this, unsigned int a2)
{
  this->__vftable = (HotlapMode_vtbl *)&HotlapMode::`vftable';
  GameMode::~GameMode(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
