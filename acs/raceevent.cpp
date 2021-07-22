#include "raceevent.h
void __userpurge RaceEvent::RaceEvent(RaceEvent *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  CarAvatar *v4; // eax
  Event<OnLapCompletedEvent> *v5; // ecx
  float v6; // xmm1_4
  unsigned int v7; // esi
  int *v8; // ebx
  std::wstring v9; // [esp-1Ch] [ebp-BCh] BYREF
  Game *v10; // [esp-4h] [ebp-A4h]
  float globalAiLevel; // [esp+14h] [ebp-8Ch]
  RaceEvent *v12; // [esp+18h] [ebp-88h]
  std::wstring section; // [esp+1Ch] [ebp-84h] BYREF
  std::wstring key; // [esp+34h] [ebp-6Ch] BYREF
  INIReaderDocuments r; // [esp+4Ch] [ebp-54h] BYREF
  int v16; // [esp+9Ch] [ebp-4h]

  v12 = this;
  v10 = aSim->game;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"HOTLAP_MODE", 0xBu);
  GameMode::GameMode(this, v9, v10);
  v10 = 0;
  v16 = 0;
  this->__vftable = (RaceEvent_vtbl *)&RaceEvent::`vftable';
  v4 = Sim::getCar(aSim, (unsigned int)v10);
  v10 = (Game *)this;
  this->car = v4;
  this->sim = aSim;
  this->objectiveTier = -1;
  v9._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_76ca4c382ab4389b129882793988837a_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  *(_DWORD *)&v9._Bx._Alias[4] = this;
  v9._Mysize = (unsigned int)&v9;
  v5 = &this->car->evOnLapCompleted;
  LOBYTE(v16) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v5,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v9,
    v10);
  v10 = 0;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&r, a2, v9, (bool)v10);
  v6 = 0.0;
  LOBYTE(v16) = 2;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"AI_LEVEL", 8u);
    LOBYTE(v16) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"RACE", 4u);
    LOBYTE(v16) = 4;
    globalAiLevel = INIReader::getFloat(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v6 = globalAiLevel;
  }
  v7 = 0;
  if ( this->conditions._Mylast - this->conditions._Myfirst )
  {
    v8 = &this->conditions._Myfirst->objective;
    do
    {
      if ( v6 >= (float)*v8 )
        this->objectiveTier = v7;
      ++v7;
      v8 += 14;
    }
    while ( v7 < this->conditions._Mylast - this->conditions._Myfirst );
  }
  LOBYTE(v16) = 0;
  INIReaderDocuments::~INIReaderDocuments(&r);
}
RaceEvent *RaceEvent::`scalar deleting destructor'(RaceEvent *this, unsigned int a2)
{
  this->__vftable = (RaceEvent_vtbl *)&RaceEvent::`vftable';
  GameMode::~GameMode(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void RaceEvent::update(RaceEvent *this, float dt)
{
  if ( RaceManager::isRaceOver(this->sim->raceManager, 0) )
    this->verifyConditions(this);
}
void RaceEvent::verifyConditions(RaceEvent *this)
{
  CarAvatar *v2; // eax
  unsigned int v3; // edi
  int v4; // ebx
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  Sim *v7; // ecx
  GameMode::ConditionDef *v8; // eax
  std::wstring imessage; // [esp+10h] [ebp-40h] BYREF
  std::wstring result; // [esp+28h] [ebp-28h] BYREF
  int v11; // [esp+4Ch] [ebp-4h]

  v2 = Sim::getCar(this->sim, 0);
  if ( RaceManager::getCarLeaderboardPosition(this->sim->raceManager, v2) == 1
    && RaceManager::isRaceOver(this->sim->raceManager, 0)
    && this->objectiveTier >= 0
    && !Sim::getCar(this->sim, 0)->isBlackFlagged
    && !this->conditions._Myfirst[this->objectiveTier].achieved )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      std::wstring::wstring(&imessage, L"Race challenge");
      v5 = &this->conditions._Myfirst->name;
      v11 = 0;
      v6 = std::operator+<wchar_t>(&result, (std::wstring *)((char *)v5 + v4 * 56), L" Achieved");
      v7 = this->sim;
      LOBYTE(v11) = 1;
      SystemMessage::addMessage(v7->systemMessage, &imessage, v6, eDefault);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      v11 = -1;
      if ( imessage._Myres >= 8 )
        operator delete(imessage._Bx._Ptr);
      imessage._Myres = 7;
      imessage._Bx._Buf[0] = 0;
      v8 = this->conditions._Myfirst;
      imessage._Mysize = 0;
      v8[v4].achieved = 1;
      GameMode::setTier(this, v3++);
      ++v4;
    }
    while ( v3 <= this->objectiveTier );
  }
}
