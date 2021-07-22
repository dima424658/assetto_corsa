#include "pushtopassmanager.h
void PushToPassManager::PushToPassManager(PushToPassManager *this, Sim *isim)
{
  Event<OnNewSessionEvent> *v3; // ecx
  const Session *v4; // eax
  std::wstring v5; // [esp-1Ch] [ebp-A4h] BYREF
  Game *v6; // [esp-4h] [ebp-8Ch]
  PushToPassManager *v7; // [esp+14h] [ebp-74h]
  Session result; // [esp+18h] [ebp-70h] BYREF
  int v9; // [esp+84h] [ebp-4h]

  v7 = this;
  v6 = isim->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"PUSHTOPASS_MANAGER", 0x12u);
  GameObject::GameObject(this, v5, v6);
  v6 = (Game *)this;
  v9 = 0;
  this->__vftable = (PushToPassManager_vtbl *)&PushToPassManager::`vftable';
  this->baseActivations = 0;
  this->activationCoeff = 0.0;
  this->sim = isim;
  v5._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_337d89af823d3631c4dcafdd24119694_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v5._Bx._Alias[4] = this;
  v5._Mysize = (unsigned int)&v5;
  v3 = &this->sim->evOnNewSession;
  LOBYTE(v9) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v3,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v5,
    v6);
  v4 = RaceManager::getCurrentSession(this->sim->raceManager, &result);
  LOBYTE(v9) = 2;
  PushToPassManager::assignActivations(this, v4);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
}
PushToPassManager *PushToPassManager::`scalar deleting destructor'(PushToPassManager *this, unsigned int a2)
{
  this->__vftable = (PushToPassManager_vtbl *)&PushToPassManager::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PushToPassManager::assignActivations(PushToPassManager *this, const Session *ses)
{
  Sim *v3; // ecx
  unsigned int v4; // edi
  CarAvatar *v5; // eax
  CarAvatar *v6; // esi
  std::wstring v7; // [esp-18h] [ebp-28h] BYREF

  v3 = this->sim;
  v4 = 0;
  if ( v3->cars._Mylast - v3->cars._Myfirst )
  {
    while ( 1 )
    {
      v5 = Sim::getCar(v3, v4);
      v6 = v5;
      if ( ses->sessionType == Pratice )
        break;
      if ( ses->sessionType == Race )
      {
        v7._Myres = 7;
        v7._Mysize = 0;
        v7._Bx._Buf[0] = 0;
        std::wstring::assign(&v7, L"START", 5u);
        v7._Myres = CarAvatar::getSpawnPositionIndex(v6, v7);
LABEL_7:
        CarAvatar::setP2PStartingActivations(v6, v7._Myres);
        goto LABEL_8;
      }
      CarAvatar::setP2PActivations(v5, 0);
LABEL_8:
      v3 = this->sim;
      if ( ++v4 >= v3->cars._Mylast - v3->cars._Myfirst )
        return;
    }
    v7._Myres = 0;
    goto LABEL_7;
  }
}
