#include "jsonoutputfile.h"
void JsonOutputFile::JsonOutputFile(JsonOutputFile *this, Sim *aSim)
{
  RaceManager *v3; // ecx
  int v4; // eax
  char v5; // al
  Sim *v6; // ecx
  std::wstring *v7; // esi
  Sim *v8; // ecx
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  Sim *v11; // eax
  Sim *v12; // ecx
  int v13; // eax
  Sim *v14; // ecx
  jsonwriter::Value v15; // [esp-20h] [ebp-B4h] BYREF
  char v16; // [esp+1Bh] [ebp-79h]
  int _Val[2]; // [esp+1Ch] [ebp-78h] BYREF
  std::wstring name; // [esp+24h] [ebp-70h] BYREF
  std::wstring result; // [esp+3Ch] [ebp-58h] BYREF
  std::wstring v20; // [esp+54h] [ebp-40h] BYREF
  std::wstring v21; // [esp+6Ch] [ebp-28h] BYREF
  int v22; // [esp+90h] [ebp-4h]

  _Val[1] = (int)this;
  v15.type = (jsonwriter::Value::ValueType)aSim->game;
  v15.valueStr._Myres = 7;
  v15.valueStr._Mysize = 0;
  v15.valueStr._Bx._Buf[0] = 0;
  std::wstring::assign(&v15.valueStr, L"JSON_OUTPUT_FILE", 0x10u);
  GameObject::GameObject(this, v15.valueStr, (Game *)v15.type);
  v22 = 0;
  this->__vftable = (JsonOutputFile_vtbl *)&JsonOutputFile::`vftable';
  this->currentSessionType = Undefined;
  jsonwriter::Object::Object(&this->root);
  LOBYTE(v22) = 1;
  jsonwriter::Array::Array(&this->sessions);
  this->sessionCounter._Myfirst = 0;
  this->sessionCounter._Mylast = 0;
  this->sessionCounter._Myend = 0;
  this->sim = aSim;
  v3 = aSim->raceManager;
  v15.type = (jsonwriter::Value::ValueType)_Val;
  LOBYTE(v22) = 3;
  _Val[0] = 0;
  v4 = RaceManager::getSessionCount(v3);
  std::vector<int>::resize(&this->sessionCounter, v4, (const int *)v15.type);
  v5 = TrackAvatar::getConfig(this->sim->track, &result)->_Mysize != 0;
  v16 = v5;
  if ( result._Myres >= 8 )
  {
    operator delete(result._Bx._Ptr);
    v5 = v16;
  }
  name._Myres = 7;
  name._Mysize = 0;
  v15.type = VT_R8;
  v15.valueStr._Myres = (unsigned int)L"track";
  if ( v5 )
  {
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, (const wchar_t *)v15.valueStr._Myres, v15.type);
    v6 = this->sim;
    LOBYTE(v22) = 4;
    v7 = TrackAvatar::getConfig(v6->track, &result);
    v8 = this->sim;
    LOBYTE(v22) = 5;
    v9 = std::operator+<wchar_t>(&v20, &v8->track->name, L"-");
    LOBYTE(v22) = 6;
    v10 = std::operator+<wchar_t>(&v21, v9, v7);
    LOBYTE(v22) = 7;
    jsonwriter::Value::Value(&v15, v10);
    jsonwriter::Object::Add(&this->root, &name, v15);
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    if ( v20._Myres >= 8 )
      operator delete(v20._Bx._Ptr);
    v20._Myres = 7;
    v20._Mysize = 0;
    v20._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  else
  {
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, (const wchar_t *)v15.valueStr._Myres, v15.type);
    v11 = this->sim;
    LOBYTE(v22) = 8;
    jsonwriter::Value::Value(&v15, &v11->track->name);
    jsonwriter::Object::Add(&this->root, &name, v15);
  }
  LOBYTE(v22) = 3;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"number_of_sessions", 0x12u);
  v12 = this->sim;
  LOBYTE(v22) = 9;
  v13 = RaceManager::getSessionCount(v12->raceManager);
  jsonwriter::Value::Value(&v15, v13);
  jsonwriter::Object::Add(&this->root, &name, v15);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  v15.type = (jsonwriter::Value::ValueType)this;
  v15.valueStr._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_97c571bad91b726f976ee61884ac1b43_,0>,std::allocator<std::_Func_class<void,OnSessionEndEvent const &>>,void,OnSessionEndEvent const &>::`vftable';
  *(_DWORD *)&v15.valueStr._Bx._Alias[4] = this;
  v15.valueStr._Mysize = (unsigned int)&v15.valueStr;
  v14 = this->sim;
  LOBYTE(v22) = 3;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v14->raceManager->evOnSessionEnd,
    (std::function<void __cdecl(SessionInfo const &)>)v15.valueStr,
    this);
}
void JsonOutputFile::~JsonOutputFile(JsonOutputFile *this)
{
  this->__vftable = (JsonOutputFile_vtbl *)&JsonOutputFile::`vftable';
  if ( this->sessionCounter._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->sessionCounter);
    operator delete(this->sessionCounter._Myfirst);
    this->sessionCounter._Myfirst = 0;
    this->sessionCounter._Mylast = 0;
    this->sessionCounter._Myend = 0;
  }
  jsonwriter::Array::~Array(&this->sessions);
  jsonwriter::Object::~Object(&this->root);
  GameObject::~GameObject(this);
}
JsonOutputFile *JsonOutputFile::`vector deleting destructor'(JsonOutputFile *this, unsigned int a2)
{
  JsonOutputFile::~JsonOutputFile(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void JsonOutputFile::addExtraSessionInfo(JsonOutputFile *this)
{
  Sim *v2; // ecx
  __int32 v3; // eax
  __int32 v4; // eax
  DragMode *v5; // esi
  int v6; // eax
  int value; // eax
  int v8; // eax
  int v9; // edx
  float v10; // xmm0_4
  int v11; // eax
  int v12; // eax
  DriftMode *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  TimeAttack *v17; // esi
  int v18; // eax
  Sim *v19; // ebx
  GameObject **v20; // esi
  int v21; // eax
  GameMode *v22; // edi
  const std::wstring *v23; // eax
  const std::wstring *v24; // eax
  int v25; // ecx
  Sim *v26; // ecx
  CarAvatar *v27; // eax
  CarAvatar *v28; // eax
  jsonwriter::Value v29; // [esp+4h] [ebp-1A4h] BYREF
  int v30; // [esp+38h] [ebp-170h]
  float v31; // [esp+3Ch] [ebp-16Ch]
  jsonwriter::Array extraInfo; // [esp+40h] [ebp-168h] BYREF
  jsonwriter::Object bestTime; // [esp+50h] [ebp-158h] BYREF
  std::wstring v34; // [esp+60h] [ebp-148h] BYREF
  jsonwriter::Object gameModeInfo; // [esp+78h] [ebp-130h] BYREF
  int v36; // [esp+88h] [ebp-120h]
  unsigned int v37; // [esp+8Ch] [ebp-11Ch]
  std::wstring result; // [esp+90h] [ebp-118h] BYREF
  std::wstring v39; // [esp+A8h] [ebp-100h] BYREF
  std::wstring v40; // [esp+C0h] [ebp-E8h] BYREF
  std::wstring v41; // [esp+D8h] [ebp-D0h] BYREF
  std::wstring v42; // [esp+F0h] [ebp-B8h] BYREF
  std::wstring v43; // [esp+108h] [ebp-A0h] BYREF
  std::wstring v44; // [esp+120h] [ebp-88h] BYREF
  std::wstring v45; // [esp+138h] [ebp-70h] BYREF
  std::wstring v46; // [esp+150h] [ebp-58h] BYREF
  std::wstring v47; // [esp+168h] [ebp-40h] BYREF
  std::wstring name; // [esp+180h] [ebp-28h] BYREF
  int v49; // [esp+1A4h] [ebp-4h]

  jsonwriter::Array::Array(&extraInfo);
  v2 = this->sim;
  v49 = 0;
  v3 = RaceManager::getCurrentSessionType(v2->raceManager) - 5;
  if ( !v3 )
  {
    v17 = GameObject::getGameObject<TimeAttack>(this->sim);
    if ( !v17 )
      goto LABEL_49;
    jsonwriter::Object::Object(&gameModeInfo);
    LOBYTE(v49) = 13;
    std::wstring::wstring(&result, L"name");
    LOBYTE(v49) = 14;
    jsonwriter::Value::Value(&v29, L"timeattack");
    jsonwriter::Object::Add(&gameModeInfo, &result, v29);
    LOBYTE(v49) = 13;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::wstring(&v34, L"points");
    v18 = (int)v17->status.points;
    LOBYTE(v49) = 15;
    jsonwriter::Value::Value(&v29, v18);
    jsonwriter::Object::Add(&gameModeInfo, &v34, v29);
    LOBYTE(v49) = 13;
    if ( v34._Myres >= 8 )
      operator delete(v34._Bx._Ptr);
    v34._Myres = 7;
    v34._Mysize = 0;
    v34._Bx._Buf[0] = 0;
    goto LABEL_48;
  }
  v4 = v3 - 1;
  if ( !v4 )
  {
    v13 = GameObject::getGameObject<DriftMode>(this->sim);
    if ( !v13 )
      goto LABEL_49;
    jsonwriter::Object::Object(&gameModeInfo);
    LOBYTE(v49) = 1;
    std::wstring::wstring(&v47, L"name");
    LOBYTE(v49) = 2;
    jsonwriter::Value::Value(&v29, L"drift");
    jsonwriter::Object::Add(&gameModeInfo, &v47, v29);
    LOBYTE(v49) = 1;
    if ( v47._Myres >= 8 )
      operator delete(v47._Bx._Ptr);
    v47._Myres = 7;
    v47._Mysize = 0;
    v47._Bx._Buf[0] = 0;
    std::wstring::wstring(&v41, L"points");
    v14 = (int)v13->sessionPoints;
    LOBYTE(v49) = 3;
    jsonwriter::Value::Value(&v29, v14);
    jsonwriter::Object::Add(&gameModeInfo, &v41, v29);
    LOBYTE(v49) = 1;
    if ( v41._Myres >= 8 )
      operator delete(v41._Bx._Ptr);
    v41._Myres = 7;
    v41._Mysize = 0;
    v41._Bx._Buf[0] = 0;
    std::wstring::wstring(&v42, L"combos");
    v15 = (int)v13->maxSessionComboCount;
    LOBYTE(v49) = 4;
    jsonwriter::Value::Value(&v29, v15);
    jsonwriter::Object::Add(&gameModeInfo, &v42, v29);
    LOBYTE(v49) = 1;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    std::wstring::wstring(&v39, L"levels");
    v16 = v13->currentLevel + 1;
    LOBYTE(v49) = 5;
    jsonwriter::Value::Value(&v29, v16);
    jsonwriter::Object::Add(&gameModeInfo, &v39, v29);
    LOBYTE(v49) = 1;
    if ( v39._Myres >= 8 )
      operator delete(v39._Bx._Ptr);
    v39._Myres = 7;
    v39._Mysize = 0;
    v39._Bx._Buf[0] = 0;
    goto LABEL_48;
  }
  if ( v4 == 1 )
  {
    v5 = GameObject::getGameObject<DragMode>(this->sim);
    if ( v5 )
    {
      jsonwriter::Object::Object(&gameModeInfo);
      LOBYTE(v49) = 6;
      std::wstring::wstring(&name, L"name");
      LOBYTE(v49) = 7;
      jsonwriter::Value::Value(&v29, L"drag");
      jsonwriter::Object::Add(&gameModeInfo, &name, v29);
      LOBYTE(v49) = 6;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::wstring(&v44, L"total");
      LOBYTE(v49) = 8;
      jsonwriter::Value::Value(&v29, v5->matchNumber);
      jsonwriter::Object::Add(&gameModeInfo, &v44, v29);
      LOBYTE(v49) = 6;
      if ( v44._Myres >= 8 )
        operator delete(v44._Bx._Ptr);
      v44._Myres = 7;
      v44._Mysize = 0;
      v44._Bx._Buf[0] = 0;
      std::wstring::wstring(&v46, L"wins");
      v6 = (char *)v5->carStatus._Mylast - (char *)v5->carStatus._Myfirst;
      LOBYTE(v49) = 9;
      if ( (v6 & 0xFFFFFFC0) != 0 )
        value = v5->carStatus._Myfirst->numberOfWins;
      else
        value = 0;
      jsonwriter::Value::Value(&v29, value);
      jsonwriter::Object::Add(&gameModeInfo, &v46, v29);
      LOBYTE(v49) = 6;
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      std::wstring::wstring(&v40, L"runs");
      v8 = (char *)v5->carStatus._Mylast - (char *)v5->carStatus._Myfirst;
      LOBYTE(v49) = 10;
      if ( (v8 & 0xFFFFFFC0) != 0 )
        v9 = v5->carStatus._Myfirst->numberOfWins + v5->carStatus._Myfirst[1].numberOfWins;
      else
        v9 = 0;
      jsonwriter::Value::Value(&v29, v9);
      jsonwriter::Object::Add(&gameModeInfo, &v40, v29);
      LOBYTE(v49) = 6;
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      v40._Myres = 7;
      v40._Mysize = 0;
      v40._Bx._Buf[0] = 0;
      if ( (((char *)v5->carStatus._Mylast - (char *)v5->carStatus._Myfirst) & 0xFFFFFFC0) != 0 )
        v10 = v5->carStatus._Myfirst->lowestReactionTime;
      else
        v10 = v31;
      v31 = v10 * 1000.0;
      if ( (float)(v10 * 1000.0) > 100000.0 )
        v31 = FLOAT_N1_0;
      std::wstring::wstring(&v45, L"reaction_time");
      LOBYTE(v49) = 11;
      jsonwriter::Value::Value(&v29, v31);
      jsonwriter::Object::Add(&gameModeInfo, &v45, v29);
      LOBYTE(v49) = 6;
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
      v45._Myres = 7;
      v45._Mysize = 0;
      v45._Bx._Buf[0] = 0;
      std::wstring::wstring(&v43, L"max_speed");
      v11 = (char *)v5->carStatus._Mylast - (char *)v5->carStatus._Myfirst;
      LOBYTE(v49) = 12;
      if ( (v11 & 0xFFFFFFC0) != 0 )
        v12 = v5->carStatus._Myfirst->maxSpeed;
      else
        v12 = v30;
      jsonwriter::Value::Value(&v29, v12);
      jsonwriter::Object::Add(&gameModeInfo, &v43, v29);
      LOBYTE(v49) = 6;
      if ( v43._Myres >= 8 )
        operator delete(v43._Bx._Ptr);
      v43._Myres = 7;
      v43._Mysize = 0;
      v43._Bx._Buf[0] = 0;
LABEL_48:
      jsonwriter::Array::Add(&extraInfo, &gameModeInfo);
      LOBYTE(v49) = 0;
      jsonwriter::Object::~Object(&gameModeInfo);
      goto LABEL_49;
    }
  }
LABEL_49:
  v19 = this->sim;
  v20 = v19->gameObjects._Myfirst;
  if ( v20 != v19->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v21 = __RTDynamicCast(*v20, 0, &GameObject `RTTI Type Descriptor', &GameMode `RTTI Type Descriptor', 0);
      v22 = (GameMode *)v21;
      if ( v21 )
        break;
      if ( ++v20 == v19->gameObjects._Mylast )
        goto LABEL_67;
    }
    if ( (*(_DWORD *)(v21 + 104) - *(_DWORD *)(v21 + 100)) / 56 >= 0 )
    {
      jsonwriter::Object::Object(&gameModeInfo);
      LOBYTE(v49) = 16;
      std::wstring::wstring(&v34, L"name");
      LOBYTE(v49) = 17;
      jsonwriter::Value::Value(&v29, L"special_event");
      jsonwriter::Object::Add(&gameModeInfo, &v34, v29);
      LOBYTE(v49) = 16;
      if ( v34._Myres >= 8 )
        operator delete(v34._Bx._Ptr);
      std::wstring::wstring(&v39, L"guid");
      LOBYTE(v49) = 18;
      v23 = GameMode::getGUID(v22, &result);
      LOBYTE(v49) = 19;
      v24 = ksEscapeJsonDoubleQuotesAndBackslash(&v34, v23);
      LOBYTE(v49) = 20;
      jsonwriter::Value::Value(&v29, v24);
      jsonwriter::Object::Add(&gameModeInfo, &v39, v29);
      if ( v34._Myres >= 8 )
        operator delete(v34._Bx._Ptr);
      v34._Myres = 7;
      v34._Mysize = 0;
      v34._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v49) = 16;
      if ( v39._Myres >= 8 )
        operator delete(v39._Bx._Ptr);
      std::wstring::wstring(&v34, L"max");
      v25 = (char *)v22->conditions._Mylast - (char *)v22->conditions._Myfirst;
      LOBYTE(v49) = 21;
      jsonwriter::Value::Value(&v29, v25 / 56);
      jsonwriter::Object::Add(&gameModeInfo, &v34, v29);
      LOBYTE(v49) = 16;
      if ( v34._Myres >= 8 )
        operator delete(v34._Bx._Ptr);
      std::wstring::wstring(&v34, L"tier");
      LOBYTE(v49) = 22;
      jsonwriter::Value::Value(&v29, v22->currentTier);
      jsonwriter::Object::Add(&gameModeInfo, &v34, v29);
      LOBYTE(v49) = 16;
      if ( v34._Myres >= 8 )
        operator delete(v34._Bx._Ptr);
      jsonwriter::Array::Add(&extraInfo, &gameModeInfo);
      LOBYTE(v49) = 0;
      jsonwriter::Object::~Object(&gameModeInfo);
    }
  }
LABEL_67:
  jsonwriter::Object::Object(&bestTime);
  LOBYTE(v49) = 23;
  v34._Myres = 7;
  v34._Mysize = 0;
  v34._Bx._Buf[0] = 0;
  std::wstring::assign(&v34, L"name", 4u);
  LOBYTE(v49) = 24;
  jsonwriter::Value::Value(&v29, L"bestlap");
  jsonwriter::Object::Add(&bestTime, &v34, v29);
  LOBYTE(v49) = 23;
  if ( v34._Myres >= 8 )
    operator delete(v34._Bx._Ptr);
  v34._Myres = 7;
  v34._Mysize = 0;
  v34._Bx._Buf[0] = 0;
  std::wstring::assign(&v34, L"time", 4u);
  v26 = this->sim;
  LOBYTE(v49) = 25;
  v27 = Sim::getCar(v26, 0);
  v28 = RaceManager::getInstanceBestLap(this->sim->raceManager, v27);
  jsonwriter::Value::Value(&v29, (const int)v28);
  jsonwriter::Object::Add(&bestTime, &v34, v29);
  LOBYTE(v49) = 23;
  if ( v34._Myres >= 8 )
    operator delete(v34._Bx._Ptr);
  jsonwriter::Array::Add(&extraInfo, &bestTime);
  v37 = 7;
  v36 = 0;
  LOWORD(gameModeInfo.__vftable) = 0;
  std::wstring::assign((std::wstring *)&gameModeInfo, L"extras", 6u);
  LOBYTE(v49) = 26;
  jsonwriter::Object::Add(&this->root, (const std::wstring *)&gameModeInfo, &extraInfo);
  if ( v37 >= 8 )
    operator delete(gameModeInfo.__vftable);
  v37 = 7;
  v36 = 0;
  LOWORD(gameModeInfo.__vftable) = 0;
  LOBYTE(v49) = 0;
  jsonwriter::Object::~Object(&bestTime);
  v49 = -1;
  jsonwriter::Array::~Array(&extraInfo);
}
void JsonOutputFile::endSession(JsonOutputFile *this, const OnSessionEndEvent *message)
{
  Sim *v3; // ecx
  int v4; // eax
  Sim *v5; // ecx
  Session *v6; // eax
  const std::wstring *value; // eax
  Sim *v8; // ecx
  int v9; // eax
  Sim *v10; // ecx
  Session *v11; // eax
  Sim *v12; // ecx
  float v13; // xmm0_4
  Sim *v14; // eax
  bool v15; // zf
  int v16; // eax
  jsonwriter::Value v17; // [esp+4h] [ebp-E0h] BYREF
  jsonwriter::Object currentSession; // [esp+34h] [ebp-B0h] BYREF
  std::wstring name; // [esp+44h] [ebp-A0h] BYREF
  Session result; // [esp+5Ch] [ebp-88h] BYREF
  std::wstring v21; // [esp+BCh] [ebp-28h] BYREF
  int v22; // [esp+E0h] [ebp-4h]

  jsonwriter::Object::Object(&currentSession);
  v22 = 0;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"event", 5u);
  v3 = this->sim;
  LOBYTE(v22) = 1;
  v4 = RaceManager::getCurrentSessionIndex(v3->raceManager);
  jsonwriter::Value::Value(&v17, this->sessionCounter._Myfirst[v4]);
  jsonwriter::Object::Add(&currentSession, &name, v17);
  LOBYTE(v22) = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"name", 4u);
  v5 = this->sim;
  LOBYTE(v22) = 2;
  v6 = RaceManager::getCurrentSession(v5->raceManager, &result);
  LOBYTE(v22) = 3;
  value = ksEscapeJsonDoubleQuotesAndBackslash(&v21, &v6->name);
  LOBYTE(v22) = 4;
  jsonwriter::Value::Value(&v17, value);
  jsonwriter::Object::Add(&currentSession, &name, v17);
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  result.spawSet._Myres = 7;
  result.spawSet._Mysize = 0;
  result.spawSet._Bx._Buf[0] = 0;
  LOBYTE(v22) = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"type", 4u);
  v8 = this->sim;
  LOBYTE(v22) = 5;
  v9 = RaceManager::getCurrentSessionType(v8->raceManager);
  jsonwriter::Value::Value(&v17, v9);
  jsonwriter::Object::Add(&currentSession, &name, v17);
  LOBYTE(v22) = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"lapsCount", 9u);
  v10 = this->sim;
  LOBYTE(v22) = 6;
  v11 = RaceManager::getCurrentSession(v10->raceManager, &result);
  LOBYTE(v22) = 7;
  jsonwriter::Value::Value(&v17, v11->laps);
  jsonwriter::Object::Add(&currentSession, &name, v17);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  result.spawSet._Myres = 7;
  result.spawSet._Mysize = 0;
  result.spawSet._Bx._Buf[0] = 0;
  LOBYTE(v22) = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"duration", 8u);
  v12 = this->sim;
  LOBYTE(v22) = 8;
  v13 = RaceManager::getCurrentSession(v12->raceManager, &result)->durationMinutes;
  LOBYTE(v22) = 9;
  jsonwriter::Value::Value(&v17, v13);
  jsonwriter::Object::Add(&currentSession, &name, v17);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  result.spawSet._Myres = 7;
  result.spawSet._Mysize = 0;
  result.spawSet._Bx._Buf[0] = 0;
  LOBYTE(v22) = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Bx._Buf[0] = 0;
  v14 = this->sim;
  v17.type = (jsonwriter::Value::ValueType)message;
  name._Mysize = 0;
  v15 = v14->client == 0;
  v17.valueStr._Myres = (unsigned int)&currentSession;
  if ( v15 )
    JsonOutputFile::offlineEndSession(
      this,
      (jsonwriter::Object *)v17.valueStr._Myres,
      (const OnSessionEndEvent *)v17.type);
  else
    JsonOutputFile::onlineEndSession(
      this,
      (jsonwriter::Object *)v17.valueStr._Myres,
      (const OnSessionEndEvent *)v17.type);
  v16 = RaceManager::getCurrentSessionIndex(this->sim->raceManager);
  ++this->sessionCounter._Myfirst[v16];
  jsonwriter::Array::Add(&this->sessions, &currentSession);
  v22 = -1;
  jsonwriter::Object::~Object(&currentSession);
}
void JsonOutputFile::offlineEndSession(JsonOutputFile *this, jsonwriter::Object *currentSession, const OnSessionEndEvent *message)
{
  JsonOutputFile *v3; // ebp
  jsonwriter::Object *v4; // edi
  const OnSessionEndEvent *v5; // ebx
  Sim *v6; // ecx
  Sim *v7; // ecx
  unsigned int v8; // edx
  int v9; // esi
  CarAvatar *v10; // eax
  std::vector<Lap> *v11; // ecx
  CarAvatar *v12; // ebp
  Lap *v13; // edi
  int *v14; // ecx
  bool v15; // cc
  int v16; // eax
  unsigned int v17; // ebx
  int v18; // esi
  int v19; // eax
  Lap *v20; // ecx
  unsigned int v21; // edi
  const std::wstring *v22; // eax
  int v23; // eax
  unsigned int v24; // edx
  int v25; // eax
  Lap *v26; // edi
  int v27; // eax
  int v28; // eax
  unsigned int v29; // esi
  int *v30; // edx
  Sim *v31; // ecx
  unsigned int v32; // esi
  Sim *v33; // ecx
  CarAvatar *v34; // eax
  int v35; // eax
  Sim *v36; // ecx
  CarAvatar *v37; // eax
  int v38; // eax
  CarAvatar *v39; // eax
  int v40; // eax
  const int *v41; // esi
  int *v42; // eax
  int v43; // edi
  unsigned int v44; // ebx
  jsonwriter::Value v45; // [esp-20h] [ebp-108h] BYREF
  jsonwriter::Value::ValueType v46; // [esp+14h] [ebp-D4h]
  std::vector<Lap> carLaps; // [esp+18h] [ebp-D0h] BYREF
  std::vector<JSONLap> currentSessionBestLaps; // [esp+24h] [ebp-C4h] BYREF
  std::vector<int> currentSessionTotalLaps; // [esp+30h] [ebp-B8h] BYREF
  int _Val; // [esp+3Ch] [ebp-ACh] BYREF
  jsonwriter::Object lap; // [esp+40h] [ebp-A8h] BYREF
  unsigned int v52; // [esp+50h] [ebp-98h] BYREF
  char v53; // [esp+57h] [ebp-91h] BYREF
  int v54; // [esp+58h] [ebp-90h]
  const OnSessionEndEvent *v55; // [esp+5Ch] [ebp-8Ch]
  jsonwriter::Object *v56; // [esp+60h] [ebp-88h]
  jsonwriter::Array result; // [esp+64h] [ebp-84h] BYREF
  JsonOutputFile *v58; // [esp+74h] [ebp-74h]
  jsonwriter::Array lapsTotal; // [esp+78h] [ebp-70h] BYREF
  jsonwriter::Array currentSessionLaps; // [esp+88h] [ebp-60h] BYREF
  jsonwriter::Array bestLaps; // [esp+98h] [ebp-50h] BYREF
  std::wstring name; // [esp+A8h] [ebp-40h] BYREF
  std::wstring v63; // [esp+C0h] [ebp-28h] BYREF
  int v64; // [esp+E4h] [ebp-4h]

  v3 = this;
  v58 = this;
  v4 = currentSession;
  v5 = message;
  v56 = currentSession;
  v55 = message;
  jsonwriter::Array::Array(&currentSessionLaps);
  v64 = 0;
  currentSessionTotalLaps._Myfirst = 0;
  currentSessionTotalLaps._Mylast = 0;
  currentSessionTotalLaps._Myend = 0;
  currentSessionBestLaps._Myfirst = 0;
  currentSessionBestLaps._Mylast = 0;
  currentSessionBestLaps._Myend = 0;
  v6 = v3->sim;
  LOBYTE(v64) = 2;
  _Val = 0;
  std::vector<int>::resize(&currentSessionTotalLaps, v6->cars._Mylast - v6->cars._Myfirst, &_Val);
  std::vector<JSONLap>::resize(&currentSessionBestLaps, v3->sim->cars._Mylast - v3->sim->cars._Myfirst);
  v7 = v3->sim;
  v8 = 0;
  _Val = 0;
  if ( v7->cars._Mylast - v7->cars._Myfirst )
  {
    v9 = 0;
    v54 = 0;
    do
    {
      v10 = Sim::getCar(v7, v8);
      v11 = v5->result.laps._Myfirst;
      v12 = v10;
      if ( v11 != v5->result.laps._Mylast )
      {
        std::vector<Lap>::vector<Lap>(&carLaps, (std::vector<Lap> *)((char *)v11 + v9));
        v13 = carLaps._Myfirst;
        LOBYTE(v64) = 3;
        v14 = (int *)&v52;
        v15 = carLaps._Mylast - carLaps._Myfirst < v5->currentSession.laps;
        v52 = carLaps._Mylast - carLaps._Myfirst;
        if ( !v15 )
          v14 = &v5->currentSession.laps;
        v16 = *v14;
        if ( !*v14 )
          v16 = carLaps._Mylast - carLaps._Myfirst;
        v17 = 0;
        v52 = v16;
        if ( v16 )
        {
          v18 = 0;
          do
          {
            jsonwriter::Object::Object(&lap);
            LOBYTE(v64) = 4;
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"lap", 3u);
            LOBYTE(v64) = 5;
            jsonwriter::Value::Value(&v45, v17);
            jsonwriter::Object::Add(&lap, &name, v45);
            LOBYTE(v64) = 4;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"car", 3u);
            LOBYTE(v64) = 6;
            v19 = CarAvatar::getGuid(v12);
            jsonwriter::Value::Value(&v45, v19);
            jsonwriter::Object::Add(&lap, &name, v45);
            LOBYTE(v64) = 4;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            jsonwriter::Array::Array(&result);
            v20 = carLaps._Myfirst;
            v21 = 0;
            for ( LOBYTE(v64) = 7; v21 < carLaps._Myfirst[v18].splits._Mylast - carLaps._Myfirst[v18].splits._Myfirst; ++v21 )
            {
              jsonwriter::Value::Value(&v45, v20[v18].splits._Myfirst[v21]);
              jsonwriter::Array::Add(&result, v45);
              v20 = carLaps._Myfirst;
            }
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"sectors", 7u);
            LOBYTE(v64) = 8;
            jsonwriter::Object::Add(&lap, &name, &result);
            LOBYTE(v64) = 7;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            if ( carLaps._Myfirst[v18].isValid || v55->currentSession.sessionType == Race )
            {
              name._Myres = 7;
              name._Mysize = 0;
              name._Bx._Buf[0] = 0;
              std::wstring::assign(&name, L"time", 4u);
              LOBYTE(v64) = 9;
              jsonwriter::Value::Value(&v45, carLaps._Myfirst[v18].time);
            }
            else
            {
              name._Myres = 7;
              name._Mysize = 0;
              name._Bx._Buf[0] = 0;
              std::wstring::assign(&name, L"time", 4u);
              LOBYTE(v64) = 10;
              jsonwriter::Value::Value(&v45, -1);
            }
            jsonwriter::Object::Add(&lap, &name, v45);
            LOBYTE(v64) = 7;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"cuts", 4u);
            LOBYTE(v64) = 11;
            jsonwriter::Value::Value(&v45, carLaps._Myfirst[v18].cuts);
            jsonwriter::Object::Add(&lap, &name, v45);
            LOBYTE(v64) = 7;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"tyre", 4u);
            LOBYTE(v64) = 12;
            v22 = ksEscapeJsonDoubleQuotesAndBackslash(&v63, &carLaps._Myfirst[v18].compound);
            LOBYTE(v64) = 13;
            jsonwriter::Value::Value(&v45, v22);
            jsonwriter::Object::Add(&lap, &name, v45);
            if ( v63._Myres >= 8 )
              operator delete(v63._Bx._Ptr);
            v63._Myres = 7;
            v63._Mysize = 0;
            v63._Bx._Buf[0] = 0;
            LOBYTE(v64) = 7;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            jsonwriter::Array::Add(&currentSessionLaps, &lap);
            v23 = CarAvatar::getGuid(v12);
            v24 = carLaps._Myfirst[v18].time;
            if ( currentSessionBestLaps._Myfirst[v23].lapTime > v24 && v24 && carLaps._Myfirst[v18].isValid )
            {
              v25 = CarAvatar::getGuid(v12);
              currentSessionBestLaps._Myfirst[v25].lapCount = v17;
              v26 = carLaps._Myfirst;
              v27 = CarAvatar::getGuid(v12);
              currentSessionBestLaps._Myfirst[v27].lapTime = v26[v18].time;
            }
            v28 = CarAvatar::getGuid(v12);
            LOBYTE(v64) = 4;
            ++currentSessionTotalLaps._Myfirst[v28];
            jsonwriter::Array::~Array(&result);
            LOBYTE(v64) = 3;
            jsonwriter::Object::~Object(&lap);
            ++v17;
            ++v18;
          }
          while ( v17 < v52 );
          v13 = carLaps._Myfirst;
        }
        LOBYTE(v64) = 2;
        if ( v13 )
        {
          std::_Container_base0::_Orphan_all(&carLaps);
          v45.type = v46;
          v45.valueStr._Myres = (unsigned int)&v53;
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(carLaps._Myfirst, carLaps._Mylast);
          operator delete(carLaps._Myfirst);
          carLaps._Myfirst = 0;
          carLaps._Mylast = 0;
          carLaps._Myend = 0;
        }
        v9 = v54;
        v5 = v55;
      }
      v3 = v58;
      v9 += 12;
      v8 = _Val + 1;
      v54 = v9;
      _Val = v8;
      v7 = v58->sim;
    }
    while ( v8 < v7->cars._Mylast - v7->cars._Myfirst );
    v4 = v56;
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"laps", 4u);
  LOBYTE(v64) = 14;
  jsonwriter::Object::Add(v4, &name, &currentSessionLaps);
  LOBYTE(v64) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  jsonwriter::Array::Array(&lapsTotal);
  v29 = 0;
  v30 = currentSessionTotalLaps._Myfirst;
  for ( LOBYTE(v64) = 15;
        v29 < currentSessionTotalLaps._Mylast - currentSessionTotalLaps._Myfirst;
        v30 = currentSessionTotalLaps._Myfirst )
  {
    jsonwriter::Value::Value(&v45, v30[v29]);
    jsonwriter::Array::Add(&lapsTotal, v45);
    ++v29;
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"lapstotal", 9u);
  LOBYTE(v64) = 16;
  jsonwriter::Object::Add(v4, &name, &lapsTotal);
  LOBYTE(v64) = 15;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  jsonwriter::Array::Array(&bestLaps);
  v31 = v3->sim;
  v32 = 0;
  LOBYTE(v64) = 17;
  if ( v31->cars._Mylast - v31->cars._Myfirst )
  {
    do
    {
      jsonwriter::Object::Object(&lap);
      LOBYTE(v64) = 18;
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"car", 3u);
      LOBYTE(v64) = 19;
      jsonwriter::Value::Value(&v45, v32);
      jsonwriter::Object::Add(&lap, &name, v45);
      LOBYTE(v64) = 18;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"time", 4u);
      v33 = v3->sim;
      LOBYTE(v64) = 20;
      v34 = Sim::getCar(v33, v32);
      v35 = CarAvatar::getGuid(v34);
      jsonwriter::Value::Value(&v45, currentSessionBestLaps._Myfirst[v35].lapTime);
      jsonwriter::Object::Add(&lap, &name, v45);
      LOBYTE(v64) = 18;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"lap", 3u);
      v36 = v3->sim;
      LOBYTE(v64) = 21;
      v37 = Sim::getCar(v36, v32);
      v38 = CarAvatar::getGuid(v37);
      jsonwriter::Value::Value(&v45, currentSessionBestLaps._Myfirst[v38].lapCount);
      jsonwriter::Object::Add(&lap, &name, v45);
      LOBYTE(v64) = 18;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      v39 = Sim::getCar(v3->sim, v32);
      v40 = CarAvatar::getGuid(v39);
      if ( currentSessionBestLaps._Myfirst[v40].lapTime != -1 )
        jsonwriter::Array::Add(&bestLaps, &lap);
      LOBYTE(v64) = 17;
      jsonwriter::Object::~Object(&lap);
      ++v32;
    }
    while ( v32 < v3->sim->cars._Mylast - v3->sim->cars._Myfirst );
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"bestLaps", 8u);
  LOBYTE(v64) = 22;
  jsonwriter::Object::Add(v4, &name, &bestLaps);
  LOBYTE(v64) = 17;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  if ( v5->currentSession.sessionType == Race )
  {
    jsonwriter::Array::Array(&result);
    v41 = v5->result.positions._Myfirst;
    v43 = 0;
    v42 = v5->result.positions._Mylast;
    LOBYTE(v64) = 23;
    v44 = (unsigned int)((char *)v42 - (char *)v41 + 3) >> 2;
    if ( v41 > v42 )
      v44 = 0;
    if ( v44 )
    {
      do
      {
        jsonwriter::Value::Value(&v45, *v41);
        jsonwriter::Array::Add(&result, v45);
        ++v43;
        ++v41;
      }
      while ( v43 != v44 );
    }
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"raceResult", 0xAu);
    LOBYTE(v64) = 24;
    jsonwriter::Object::Add(v56, &name, &result);
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    LOBYTE(v64) = 17;
    jsonwriter::Array::~Array(&result);
  }
  LOBYTE(v64) = 15;
  jsonwriter::Array::~Array(&bestLaps);
  LOBYTE(v64) = 2;
  jsonwriter::Array::~Array(&lapsTotal);
  LOBYTE(v64) = 1;
  if ( currentSessionBestLaps._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&currentSessionBestLaps);
    operator delete(currentSessionBestLaps._Myfirst);
    currentSessionBestLaps._Myfirst = 0;
    currentSessionBestLaps._Mylast = 0;
    currentSessionBestLaps._Myend = 0;
  }
  LOBYTE(v64) = 0;
  if ( currentSessionTotalLaps._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&currentSessionTotalLaps);
    operator delete(currentSessionTotalLaps._Myfirst);
    currentSessionTotalLaps._Myfirst = 0;
    currentSessionTotalLaps._Mylast = 0;
    currentSessionTotalLaps._Myend = 0;
  }
  v64 = -1;
  jsonwriter::Array::~Array(&currentSessionLaps);
}
void JsonOutputFile::onlineEndSession(JsonOutputFile *this, jsonwriter::Object *currentSession, const OnSessionEndEvent *message)
{
  JsonOutputFile *v3; // ebp
  jsonwriter::Object *v4; // edi
  const OnSessionEndEvent *v5; // ebx
  Sim *v6; // ecx
  Sim *v7; // ecx
  unsigned int v8; // edx
  int v9; // ecx
  std::vector<Lap> *v10; // eax
  Lap *v11; // edi
  int *v12; // ecx
  bool v13; // cc
  int v14; // eax
  unsigned int v15; // ebx
  int v16; // esi
  Sim *v17; // ecx
  CarAvatar *v18; // ebp
  int v19; // eax
  Lap *v20; // ecx
  unsigned int v21; // edi
  const std::wstring *v22; // eax
  int v23; // eax
  unsigned int v24; // edx
  int v25; // eax
  Lap *v26; // edi
  int v27; // eax
  Sim *v28; // ecx
  int v29; // eax
  Sim *v30; // ecx
  unsigned int v31; // esi
  CarAvatar *v32; // eax
  int v33; // eax
  Sim *v34; // ecx
  unsigned int v35; // esi
  CarAvatar *v36; // eax
  int v37; // eax
  signed int v38; // edi
  const int *v39; // esi
  int *v40; // eax
  int v41; // edi
  unsigned int v42; // ebx
  jsonwriter::Value v43; // [esp-20h] [ebp-FCh] BYREF
  jsonwriter::Value::ValueType v44; // [esp+14h] [ebp-C8h]
  std::vector<Lap> carLaps; // [esp+18h] [ebp-C4h] BYREF
  std::vector<JSONLap> currentSessionBestLaps; // [esp+24h] [ebp-B8h] BYREF
  int v47; // [esp+30h] [ebp-ACh]
  unsigned int index; // [esp+34h] [ebp-A8h]
  jsonwriter::Object lap; // [esp+38h] [ebp-A4h] BYREF
  char v50; // [esp+4Bh] [ebp-91h] BYREF
  unsigned int v51; // [esp+4Ch] [ebp-90h] BYREF
  const OnSessionEndEvent *v52; // [esp+50h] [ebp-8Ch]
  jsonwriter::Object *v53; // [esp+54h] [ebp-88h]
  JsonOutputFile *v54; // [esp+58h] [ebp-84h]
  jsonwriter::Array result; // [esp+5Ch] [ebp-80h] BYREF
  jsonwriter::Array currentSessionLaps; // [esp+6Ch] [ebp-70h] BYREF
  jsonwriter::Array bestLaps; // [esp+7Ch] [ebp-60h] BYREF
  jsonwriter::Array lapsTotal; // [esp+8Ch] [ebp-50h] BYREF
  std::wstring name; // [esp+9Ch] [ebp-40h] BYREF
  std::wstring v60; // [esp+B4h] [ebp-28h] BYREF
  int v61; // [esp+D8h] [ebp-4h]

  v3 = this;
  v54 = this;
  v4 = currentSession;
  v5 = message;
  v53 = currentSession;
  v52 = message;
  jsonwriter::Array::Array(&currentSessionLaps);
  v61 = 0;
  currentSessionBestLaps._Myfirst = 0;
  currentSessionBestLaps._Mylast = 0;
  currentSessionBestLaps._Myend = 0;
  v6 = v3->sim;
  LOBYTE(v61) = 1;
  std::vector<JSONLap>::resize(&currentSessionBestLaps, v6->cars._Mylast - v6->cars._Myfirst);
  v7 = v3->sim;
  v8 = 0;
  index = 0;
  if ( v7->cars._Mylast - v7->cars._Myfirst )
  {
    v9 = 0;
    v47 = 0;
    do
    {
      v10 = v5->result.laps._Myfirst;
      if ( v10 != v5->result.laps._Mylast )
      {
        std::vector<Lap>::vector<Lap>(&carLaps, (std::vector<Lap> *)((char *)v10 + v9));
        v11 = carLaps._Myfirst;
        LOBYTE(v61) = 2;
        v12 = (int *)&v51;
        v13 = carLaps._Mylast - carLaps._Myfirst < v5->currentSession.laps;
        v51 = carLaps._Mylast - carLaps._Myfirst;
        if ( !v13 )
          v12 = &v5->currentSession.laps;
        v14 = *v12;
        if ( !*v12 )
          v14 = carLaps._Mylast - carLaps._Myfirst;
        v15 = 0;
        v51 = v14;
        if ( v14 )
        {
          v16 = 0;
          do
          {
            jsonwriter::Object::Object(&lap);
            v43.type = index;
            v17 = v3->sim;
            LOBYTE(v61) = 3;
            v18 = Sim::getCar(v17, index);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"lap", 3u);
            LOBYTE(v61) = 4;
            jsonwriter::Value::Value(&v43, v15);
            jsonwriter::Object::Add(&lap, &name, v43);
            LOBYTE(v61) = 3;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"car", 3u);
            LOBYTE(v61) = 5;
            v19 = CarAvatar::getGuid(v18);
            jsonwriter::Value::Value(&v43, v19);
            jsonwriter::Object::Add(&lap, &name, v43);
            LOBYTE(v61) = 3;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            jsonwriter::Array::Array(&result);
            v20 = carLaps._Myfirst;
            v21 = 0;
            for ( LOBYTE(v61) = 6; v21 < carLaps._Myfirst[v16].splits._Mylast - carLaps._Myfirst[v16].splits._Myfirst; ++v21 )
            {
              jsonwriter::Value::Value(&v43, v20[v16].splits._Myfirst[v21]);
              jsonwriter::Array::Add(&result, v43);
              v20 = carLaps._Myfirst;
            }
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"sectors", 7u);
            LOBYTE(v61) = 7;
            jsonwriter::Object::Add(&lap, &name, &result);
            LOBYTE(v61) = 6;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            if ( carLaps._Myfirst[v16].isValid || v52->currentSession.sessionType == Race )
            {
              name._Myres = 7;
              name._Mysize = 0;
              name._Bx._Buf[0] = 0;
              std::wstring::assign(&name, L"time", 4u);
              LOBYTE(v61) = 8;
              jsonwriter::Value::Value(&v43, carLaps._Myfirst[v16].time);
            }
            else
            {
              name._Myres = 7;
              name._Mysize = 0;
              name._Bx._Buf[0] = 0;
              std::wstring::assign(&name, L"time", 4u);
              LOBYTE(v61) = 9;
              jsonwriter::Value::Value(&v43, -1);
            }
            jsonwriter::Object::Add(&lap, &name, v43);
            LOBYTE(v61) = 6;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"cuts", 4u);
            LOBYTE(v61) = 10;
            jsonwriter::Value::Value(&v43, carLaps._Myfirst[v16].cuts);
            jsonwriter::Object::Add(&lap, &name, v43);
            LOBYTE(v61) = 6;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"tyre", 4u);
            LOBYTE(v61) = 11;
            v22 = ksEscapeJsonDoubleQuotesAndBackslash(&v60, &carLaps._Myfirst[v16].compound);
            LOBYTE(v61) = 12;
            jsonwriter::Value::Value(&v43, v22);
            jsonwriter::Object::Add(&lap, &name, v43);
            if ( v60._Myres >= 8 )
              operator delete(v60._Bx._Ptr);
            v60._Myres = 7;
            v60._Mysize = 0;
            v60._Bx._Buf[0] = 0;
            LOBYTE(v61) = 6;
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            jsonwriter::Array::Add(&currentSessionLaps, &lap);
            v23 = CarAvatar::getGuid(v18);
            v24 = carLaps._Myfirst[v16].time;
            if ( currentSessionBestLaps._Myfirst[v23].lapTime > v24 && v24 && carLaps._Myfirst[v16].isValid )
            {
              v25 = CarAvatar::getGuid(v18);
              currentSessionBestLaps._Myfirst[v25].lapCount = v15;
              v26 = carLaps._Myfirst;
              v27 = CarAvatar::getGuid(v18);
              currentSessionBestLaps._Myfirst[v27].lapTime = v26[v16].time;
            }
            LOBYTE(v61) = 3;
            jsonwriter::Array::~Array(&result);
            LOBYTE(v61) = 2;
            jsonwriter::Object::~Object(&lap);
            v3 = v54;
            ++v15;
            ++v16;
          }
          while ( v15 < v51 );
          v11 = carLaps._Myfirst;
        }
        LOBYTE(v61) = 1;
        if ( v11 )
        {
          std::_Container_base0::_Orphan_all(&carLaps);
          v43.type = v44;
          v43.valueStr._Myres = (unsigned int)&v50;
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(carLaps._Myfirst, carLaps._Mylast);
          operator delete(carLaps._Myfirst);
          carLaps._Myfirst = 0;
          carLaps._Mylast = 0;
          carLaps._Myend = 0;
        }
        v9 = v47;
        v8 = index;
        v5 = v52;
      }
      ++v8;
      v47 = v9 + 12;
      v28 = v3->sim;
      index = v8;
      v29 = (char *)v28->cars._Mylast - (char *)v28->cars._Myfirst;
      v9 = v47;
    }
    while ( v8 < v29 >> 2 );
    v4 = v53;
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"laps", 4u);
  LOBYTE(v61) = 13;
  jsonwriter::Object::Add(v4, &name, &currentSessionLaps);
  LOBYTE(v61) = 1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  jsonwriter::Array::Array(&lapsTotal);
  v30 = v3->sim;
  v31 = 0;
  for ( LOBYTE(v61) = 14; v31 < v30->cars._Mylast - v30->cars._Myfirst; ++v31 )
  {
    v32 = Sim::getCar(v30, v31);
    v33 = RaceManager::getLapCount(v3->sim->raceManager, v32);
    jsonwriter::Value::Value(&v43, v33);
    jsonwriter::Array::Add(&lapsTotal, v43);
    v30 = v3->sim;
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"lapstotal", 9u);
  LOBYTE(v61) = 15;
  jsonwriter::Object::Add(v4, &name, &lapsTotal);
  LOBYTE(v61) = 14;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  jsonwriter::Array::Array(&bestLaps);
  v34 = v3->sim;
  v35 = 0;
  LOBYTE(v61) = 16;
  if ( v34->cars._Mylast - v34->cars._Myfirst )
  {
    do
    {
      v36 = Sim::getCar(v34, v35);
      v37 = CarAvatar::getGuid(v36);
      v38 = currentSessionBestLaps._Myfirst[v37].lapTime;
      jsonwriter::Object::Object(&lap);
      LOBYTE(v61) = 17;
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"car", 3u);
      LOBYTE(v61) = 18;
      jsonwriter::Value::Value(&v43, v35);
      jsonwriter::Object::Add(&lap, &name, v43);
      LOBYTE(v61) = 17;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"time", 4u);
      LOBYTE(v61) = 19;
      jsonwriter::Value::Value(&v43, v38);
      jsonwriter::Object::Add(&lap, &name, v43);
      LOBYTE(v61) = 17;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      v43.type = VT_I4;
      v43.valueStr._Myres = (unsigned int)L"lap";
      name._Bx._Buf[0] = 0;
      if ( v35 >= currentSessionBestLaps._Mylast - currentSessionBestLaps._Myfirst )
      {
        std::wstring::assign(&name, (const wchar_t *)v43.valueStr._Myres, v43.type);
        LOBYTE(v61) = 21;
        jsonwriter::Value::Value(&v43, -1);
      }
      else
      {
        std::wstring::assign(&name, (const wchar_t *)v43.valueStr._Myres, v43.type);
        LOBYTE(v61) = 20;
        jsonwriter::Value::Value(&v43, currentSessionBestLaps._Myfirst[v35].lapCount);
      }
      jsonwriter::Object::Add(&lap, &name, v43);
      LOBYTE(v61) = 17;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      if ( v38 > 0 )
        jsonwriter::Array::Add(&bestLaps, &lap);
      LOBYTE(v61) = 16;
      jsonwriter::Object::~Object(&lap);
      v34 = v3->sim;
      ++v35;
    }
    while ( v35 < v34->cars._Mylast - v34->cars._Myfirst );
    v4 = v53;
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"bestLaps", 8u);
  LOBYTE(v61) = 22;
  jsonwriter::Object::Add(v4, &name, &bestLaps);
  LOBYTE(v61) = 16;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  if ( v5->currentSession.sessionType == Race )
  {
    jsonwriter::Array::Array(&result);
    v39 = v5->result.positions._Myfirst;
    v41 = 0;
    v40 = v5->result.positions._Mylast;
    LOBYTE(v61) = 23;
    v42 = (unsigned int)((char *)v40 - (char *)v39 + 3) >> 2;
    if ( v39 > v40 )
      v42 = 0;
    if ( v42 )
    {
      do
      {
        jsonwriter::Value::Value(&v43, *v39);
        jsonwriter::Array::Add(&result, v43);
        ++v41;
        ++v39;
      }
      while ( v41 != v42 );
    }
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"raceResult", 0xAu);
    LOBYTE(v61) = 24;
    jsonwriter::Object::Add(v53, &name, &result);
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    LOBYTE(v61) = 16;
    jsonwriter::Array::~Array(&result);
  }
  LOBYTE(v61) = 14;
  jsonwriter::Array::~Array(&bestLaps);
  LOBYTE(v61) = 1;
  jsonwriter::Array::~Array(&lapsTotal);
  LOBYTE(v61) = 0;
  if ( currentSessionBestLaps._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&currentSessionBestLaps);
    operator delete(currentSessionBestLaps._Myfirst);
    currentSessionBestLaps._Myfirst = 0;
    currentSessionBestLaps._Mylast = 0;
    currentSessionBestLaps._Myend = 0;
  }
  v61 = -1;
  jsonwriter::Array::~Array(&currentSessionLaps);
}
void JsonOutputFile::writeOutputFile(JsonOutputFile *this)
{
  std::wstring name; // [esp+Ch] [ebp-40h] BYREF
  std::wstring documentPath; // [esp+24h] [ebp-28h] BYREF
  int v4; // [esp+48h] [ebp-4h]

  JsonOutputFile::writePlayers(this);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"sessions", 8u);
  v4 = 0;
  jsonwriter::Object::Add(&this->root, &name, &this->sessions);
  v4 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  JsonOutputFile::addExtraSessionInfo(this);
  Path::getDocumentPath(&documentPath);
  v4 = 1;
  std::wstring::append(&documentPath, L"\\Assetto Corsa\\out\\race_out.json", 0x20u);
  jsonwriter::FileWriter::WriteFile(&documentPath, &this->root);
  if ( documentPath._Myres >= 8 )
    operator delete(documentPath._Bx._Ptr);
}
void JsonOutputFile::writePlayers(JsonOutputFile *this)
{
  Sim *v2; // ecx
  unsigned int v3; // esi
  Sim *v4; // ecx
  CarAvatar *v5; // eax
  const std::wstring *v6; // eax
  Sim *v7; // ecx
  CarAvatar *v8; // eax
  const std::wstring *v9; // eax
  Sim *v10; // ecx
  CarAvatar *v11; // eax
  const std::wstring *v12; // eax
  const std::wstring *v13; // eax
  const std::wstring *v14; // eax
  jsonwriter::Value v15; // [esp-20h] [ebp-C8h] BYREF
  jsonwriter::Array players; // [esp+10h] [ebp-98h] BYREF
  std::wstring name; // [esp+20h] [ebp-88h] BYREF
  std::wstring result; // [esp+38h] [ebp-70h] BYREF
  jsonwriter::Object p; // [esp+50h] [ebp-58h] BYREF
  int v20; // [esp+60h] [ebp-48h]
  unsigned int v21; // [esp+64h] [ebp-44h]
  std::wstring v22; // [esp+68h] [ebp-40h] BYREF
  std::wstring v23; // [esp+80h] [ebp-28h] BYREF
  int v24; // [esp+A4h] [ebp-4h]

  jsonwriter::Array::Array(&players);
  v2 = this->sim;
  v3 = 0;
  v24 = 0;
  if ( v2->cars._Mylast - v2->cars._Myfirst )
  {
    do
    {
      jsonwriter::Object::Object(&p);
      LOBYTE(v24) = 1;
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"name", 4u);
      v4 = this->sim;
      LOBYTE(v24) = 2;
      v5 = Sim::getCar(v4, v3);
      v6 = ksEscapeJsonDoubleQuotesAndBackslash(&result, &v5->driverInfo.name);
      LOBYTE(v24) = 3;
      jsonwriter::Value::Value(&v15, v6);
      jsonwriter::Object::Add(&p, &name, v15);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v24) = 1;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"car", 3u);
      v7 = this->sim;
      LOBYTE(v24) = 4;
      v8 = Sim::getCar(v7, v3);
      v9 = ksEscapeJsonDoubleQuotesAndBackslash(&result, &v8->unixName);
      LOBYTE(v24) = 5;
      jsonwriter::Value::Value(&v15, v9);
      jsonwriter::Object::Add(&p, &name, v15);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v24) = 1;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"skin", 4u);
      v10 = this->sim;
      v15.type = (jsonwriter::Value::ValueType)&v23;
      LOBYTE(v24) = 6;
      v11 = Sim::getCar(v10, v3);
      v12 = CarAvatar::getCurrentSkin(v11, (std::wstring *)v15.type);
      LOBYTE(v24) = 7;
      v13 = Path::getFileName(&v22, v12);
      LOBYTE(v24) = 8;
      v14 = ksEscapeJsonDoubleQuotesAndBackslash(&result, v13);
      LOBYTE(v24) = 9;
      jsonwriter::Value::Value(&v15, v14);
      jsonwriter::Object::Add(&p, &name, v15);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( v22._Myres >= 8 )
        operator delete(v22._Bx._Ptr);
      v22._Myres = 7;
      v22._Mysize = 0;
      v22._Bx._Buf[0] = 0;
      if ( v23._Myres >= 8 )
        operator delete(v23._Bx._Ptr);
      v23._Myres = 7;
      v23._Mysize = 0;
      v23._Bx._Buf[0] = 0;
      LOBYTE(v24) = 1;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      jsonwriter::Array::Add(&players, &p);
      LOBYTE(v24) = 0;
      jsonwriter::Object::~Object(&p);
      ++v3;
    }
    while ( v3 < this->sim->cars._Mylast - this->sim->cars._Myfirst );
  }
  v21 = 7;
  v20 = 0;
  LOWORD(p.__vftable) = 0;
  std::wstring::assign((std::wstring *)&p, L"players", 7u);
  LOBYTE(v24) = 10;
  jsonwriter::Object::Add(&this->root, (const std::wstring *)&p, &players);
  if ( v21 >= 8 )
    operator delete(p.__vftable);
  v21 = 7;
  v20 = 0;
  LOWORD(p.__vftable) = 0;
  v24 = -1;
  jsonwriter::Array::~Array(&players);
}
