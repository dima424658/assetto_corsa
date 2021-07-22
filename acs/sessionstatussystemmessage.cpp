#include "sessionstatussystemmessage.h"
void SessionStatusSystemMessage::SessionStatusSystemMessage(SessionStatusSystemMessage *this, Sim *aSim)
{
  int *v3; // ebp
  std::wstring *v4; // ecx
  Font *v5; // eax
  TyreTester *v6; // eax
  TyreTester *v7; // esi
  TyreTester *v8; // ebx
  const __m128i *v9; // eax
  bool v10; // cf
  int v11; // eax
  int v12; // eax
  int v13; // eax
  Font *v14; // esi
  const vec4f *v15; // eax
  Font *v16; // ecx
  int v17[2]; // [esp+24h] [ebp-B4h] BYREF
  vec4f result; // [esp+2Ch] [ebp-ACh] BYREF
  std::wstring section; // [esp+3Ch] [ebp-9Ch] BYREF
  std::wstring key; // [esp+54h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+6Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+84h] [ebp-54h] BYREF
  int v23; // [esp+D4h] [ebp-4h]

  v3 = (int *)&this->font;
  this->sim = aSim;
  v17[1] = (int)this;
  this->font._Myptr = 0;
  v4 = &this->textToRender;
  v4->_Myres = 7;
  v4->_Mysize = 0;
  v23 = 0;
  v4->_Bx._Buf[0] = 0;
  this->lastCurrentLapValid = 0;
  this->invalidLapMessageTime = 0.0;
  this->position.x = 0.0;
  this->position.y = 0.0;
  this->backgroundColor.x = 0.0;
  this->backgroundColor.y = 0.0;
  this->backgroundColor.z = 0.0;
  this->backgroundColor.w = 0.0;
  *(_WORD *)&this->praticeVisible = 257;
  this->raceVisible = 1;
  std::wstring::assign(v4, word_17BE9D8, 0);
  v5 = (Font *)operator new(24);
  v17[0] = (int)v5;
  LOBYTE(v23) = 2;
  if ( v5 )
  {
    Font::Font(v5, eFontProportional, 16.0, 0, 1);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  LOBYTE(v23) = 1;
  if ( v3 == v17 )
  {
    if ( v7 )
    {
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart(v7);
      operator delete(v7);
    }
  }
  else
  {
    v8 = (TyreTester *)*v3;
    *v3 = (int)v7;
    if ( v8 )
    {
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart(v8);
      operator delete(v8);
    }
  }
  this->position.y = 0.0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/session_info.ini", 0x1Bu);
  LOBYTE(v23) = 3;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v23) = 5;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BACKGROUND_COLOR", 0x10u);
    LOBYTE(v23) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"OPTIONS", 7u);
    LOBYTE(v23) = 7;
    v9 = (const __m128i *)INIReader::getFloat4(&ini, &result, &section, &key);
    v10 = section._Myres < 8;
    this->backgroundColor = (vec4f)_mm_loadu_si128(v9);
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v23) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PRATICE_VISIBLE", 0xFu);
    LOBYTE(v23) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"OPTIONS", 7u);
    LOBYTE(v23) = 9;
    v11 = INIReader::getInt(&ini, &section, &key);
    v10 = section._Myres < 8;
    this->praticeVisible = v11 != 0;
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v23) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"QUALIFY_VISIBLE", 0xFu);
    LOBYTE(v23) = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"OPTIONS", 7u);
    LOBYTE(v23) = 11;
    v12 = INIReader::getInt(&ini, &section, &key);
    v10 = section._Myres < 8;
    this->qualifyVisible = v12 != 0;
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v23) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"RACE_VISIBLE", 0xCu);
    LOBYTE(v23) = 12;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"OPTIONS", 7u);
    LOBYTE(v23) = 13;
    v13 = INIReader::getInt(&ini, &section, &key);
    v10 = section._Myres < 8;
    this->raceVisible = v13 != 0;
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v23) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FONT_COLOR", 0xAu);
    LOBYTE(v23) = 14;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"OPTIONS", 7u);
    v14 = (Font *)*v3;
    LOBYTE(v23) = 15;
    v15 = INIReader::getFloat4(&ini, &result, &section, &key);
    Font::setColor(v14, v15);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  else
  {
    v16 = (Font *)*v3;
    this->backgroundColor = (vec4f)_xmm;
    Font::setColor(v16, 1.0, 1.0, 1.0, 1.0);
    *(_WORD *)&this->praticeVisible = 257;
    this->raceVisible = 1;
  }
  LOBYTE(v23) = 1;
  INIReader::~INIReader(&ini);
}
void SessionStatusSystemMessage::~SessionStatusSystemMessage(SessionStatusSystemMessage *this)
{
  Font *v2; // esi

  if ( this->textToRender._Myres >= 8 )
    operator delete(this->textToRender._Bx._Ptr);
  this->textToRender._Myres = 7;
  this->textToRender._Mysize = 0;
  this->textToRender._Bx._Buf[0] = 0;
  v2 = this->font._Myptr;
  if ( v2 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v2);
    operator delete(v2);
  }
}
void SessionStatusSystemMessage::render(SessionStatusSystemMessage *this, float dt)
{
  GLRenderer *v3; // esi
  float v4; // xmm0_4

  if ( this->textToRender._Mysize )
  {
    v3 = this->sim->game->graphics->gl;
    GLRenderer::color4f(v3, &this->backgroundColor);
    v4 = (float)this->textToRender._Mysize;
    GLRenderer::quad(
      v3,
      (float)((float)this->sim->game->graphics->videoSettings.width * 0.5) - (float)(v4 * 5.0),
      this->position.y,
      v4 * 10.0,
      24.0,
      0,
      0);
    Font::blitString(
      this->font._Myptr,
      (float)this->sim->game->graphics->videoSettings.width * 0.5,
      0.0,
      &this->textToRender,
      1.0,
      eAlignCenter);
  }
}
void SessionStatusSystemMessage::update(SessionStatusSystemMessage *this, float dt)
{
  CarAvatar *v3; // eax
  Sim *v4; // ecx
  EndSessionDisplayer *v5; // eax
  CarAvatar *v6; // eax
  bool v7; // al
  float v8; // xmm0_4
  SessionType v9; // edi
  __int32 v10; // edi
  __int32 v11; // edi
  std::wstring *v12; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v13; // ecx
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring v16; // [esp+10h] [ebp-ACh] BYREF
  std::wstring v17; // [esp+28h] [ebp-94h] BYREF
  std::wstring v18; // [esp+40h] [ebp-7Ch] BYREF
  Session result; // [esp+58h] [ebp-64h] BYREF

  std::wstring::assign(&this->textToRender, word_17BE9D8, 0);
  v3 = Sim::getCar(this->sim, 0);
  if ( CarAvatar::hasPenalty(v3) == 0.0 && Sim::getCar(this->sim, 0)->physicsState.lockControlsTime <= 0.0 )
  {
    v4 = this->sim;
    if ( !this->sim->escMenu->visible && !v4->pauseMenu->visible && !ReplayManager::isInReplaymode(v4->replayManager) )
    {
      v5 = this->sim->endSessionDisplayer;
      if ( !v5 || !v5->isActive )
      {
        v6 = Sim::getCar(this->sim, 0);
        v7 = CarAvatar::isCurrentLapValid(v6);
        if ( !v7 && this->lastCurrentLapValid )
          this->invalidLapMessageTime = 5.0;
        v8 = this->invalidLapMessageTime;
        this->lastCurrentLapValid = v7;
        if ( v8 > 0.0 )
        {
          this->invalidLapMessageTime = v8 - dt;
          return;
        }
        v9 = RaceManager::getCurrentSession(this->sim->raceManager, &result)->sessionType;
        Session::~Session(&result);
        v10 = v9 - 1;
        if ( !v10 )
        {
          if ( !this->praticeVisible )
            return;
          v15 = RaceManager::getPracticeQualifyText(this->sim->raceManager, &v17);
          std::wstring::operator=(&this->textToRender, v15);
          v13 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v17;
          goto LABEL_23;
        }
        v11 = v10 - 1;
        if ( !v11 )
        {
          if ( !this->qualifyVisible )
            return;
          v14 = RaceManager::getPracticeQualifyText(this->sim->raceManager, &v16);
          std::wstring::operator=(&this->textToRender, v14);
          v13 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v16;
          goto LABEL_23;
        }
        if ( v11 != 1 )
        {
          std::wstring::assign(&this->textToRender, word_17BE9D8);
          return;
        }
        if ( this->raceVisible )
        {
          v12 = RaceManager::getRaceText(this->sim->raceManager, &v18);
          std::wstring::operator=(&this->textToRender, v12);
          v13 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v18;
LABEL_23:
          std::wstring::~wstring(v13);
          return;
        }
      }
    }
  }
}
