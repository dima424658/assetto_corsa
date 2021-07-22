#include "lockcontrolstimeavatar.h
void LockControlsTimeAvatar::LockControlsTimeAvatar(LockControlsTimeAvatar *this, Sim *sim)
{
  char v3; // bl
  Font *v4; // eax
  Font *v5; // eax
  Font *v6; // esi
  char v7; // al
  int v8; // eax
  bool v9; // cf
  std::wstring v10; // [esp-10h] [ebp-D4h] BYREF
  unsigned int v11; // [esp+8h] [ebp-BCh]
  char v12; // [esp+1Fh] [ebp-A5h]
  int v13; // [esp+20h] [ebp-A4h]
  LockControlsTimeAvatar *v14; // [esp+24h] [ebp-A0h]
  std::wstring section; // [esp+28h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+40h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+58h] [ebp-6Ch] BYREF
  INIReader acMsg; // [esp+70h] [ebp-54h] BYREF
  int v19; // [esp+C0h] [ebp-4h]

  v3 = 0;
  v13 = 0;
  v14 = this;
  v11 = (unsigned int)sim->game;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"LAP_INVALIDATOR_AVATAR", 0x16u);
  GameObject::GameObject(this, v10, (Game *)v11);
  this->__vftable = (LockControlsTimeAvatar_vtbl *)&LockControlsTimeAvatar::`vftable';
  this->sim = sim;
  v19 = 0;
  this->font._Myptr = 0;
  this->backColor.x = 0.0;
  this->backColor.y = 0.0;
  this->backColor.z = 0.0;
  this->backColor.w = 0.0;
  v11 = 24;
  LOBYTE(v19) = 1;
  this->borderColor.x = 0.0;
  this->borderColor.y = 0.0;
  this->borderColor.z = 0.0;
  this->borderColor.w = 0.0;
  v4 = (Font *)operator new(v11);
  v13 = (int)v4;
  LOBYTE(v19) = 2;
  if ( v4 )
    Font::Font(v4, eFontProportional, 15.0, 0, 0);
  else
    v5 = 0;
  v6 = this->font._Myptr;
  LOBYTE(v19) = 1;
  this->font._Myptr = v5;
  if ( v6 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v6);
    operator delete(v6);
  }
  this->backColor = (vec4f)_xmm;
  this->showMessage = 1;
  v11 = 23;
  v10._Myres = (unsigned int)L"system/cfg/messages.ini";
  this->borderColor = (vec4f)_xmm;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v10._Myres, v11);
  LOBYTE(v19) = 3;
  INIReader::INIReader(&acMsg, &ifilename);
  LOBYTE(v19) = 5;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( !acMsg.ready )
    goto LABEL_10;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"LOCK_CONTROL", 0xCu);
  LOBYTE(v19) = 6;
  v13 = 1;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"PENALTY", 7u);
  v19 = 7;
  v3 = 3;
  v13 = 3;
  v7 = INIReader::hasKey(&acMsg, &section, &key);
  v12 = 1;
  if ( !v7 )
LABEL_10:
    v12 = 0;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
  }
  v19 = 5;
  if ( (v3 & 1) != 0 && key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v12 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LOCK_CONTROL", 0xCu);
    LOBYTE(v19) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PENALTY", 7u);
    LOBYTE(v19) = 9;
    v8 = INIReader::getInt(&acMsg, &section, &key);
    v9 = section._Myres < 8;
    this->showMessage = v8 == 1;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  LOBYTE(v19) = 1;
  INIReader::~INIReader(&acMsg);
}
LockControlsTimeAvatar *LockControlsTimeAvatar::`vector deleting destructor'(LockControlsTimeAvatar *this, unsigned int a2)
{
  Font *v3; // edi

  this->__vftable = (LockControlsTimeAvatar_vtbl *)&LockControlsTimeAvatar::`vftable';
  v3 = this->font._Myptr;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v3);
    operator delete(v3);
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void LockControlsTimeAvatar::renderHUD(LockControlsTimeAvatar *this, float deltaT)
{
  Sim *v3; // ecx
  float *v4; // esi
  GraphicsManager *v5; // eax
  CarAvatar *v6; // eax
  GLRenderer *v7; // edi
  const std::wstring *v8; // eax
  float v9; // xmm1_4
  Font *v10; // ecx
  std::wstring *v11; // edi
  Sim *v12; // ecx
  CarAvatar *v13; // eax
  std::wstring *v14; // esi
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  bool v17; // cf
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  const std::wstring *v20; // eax
  const std::wstring *v21; // eax
  Font *v22; // ecx
  float v23; // [esp+30h] [ebp-1A0h] BYREF
  float v24; // [esp+34h] [ebp-19Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > line; // [esp+38h] [ebp-198h] BYREF
  std::wstring text; // [esp+E8h] [ebp-E8h] BYREF
  std::wstring result; // [esp+100h] [ebp-D0h] BYREF
  std::wstring v28; // [esp+118h] [ebp-B8h] BYREF
  std::wstring v29; // [esp+130h] [ebp-A0h] BYREF
  std::wstring v30; // [esp+148h] [ebp-88h] BYREF
  std::wstring v31; // [esp+160h] [ebp-70h] BYREF
  std::wstring v32; // [esp+178h] [ebp-58h] BYREF
  std::wstring v33; // [esp+190h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v34; // [esp+1A8h] [ebp-28h] BYREF
  int v35; // [esp+1CCh] [ebp-4h]

  v23 = 0.0;
  if ( this->showMessage
    && Sim::getCar(this->sim, 0)->physicsState.lockControlsTime > 0.0
    && !ReplayManager::isInReplaymode(this->sim->replayManager) )
  {
    v3 = this->sim;
    if ( !v3->pauseMenu->visible && !v3->escMenu->visible )
    {
      v4 = &v24;
      v5 = this->game->graphics;
      v24 = v3->game->gui->taskbar->rect.left - 1.0;
      v23 = (float)v5->videoSettings.width;
      if ( v23 <= v24 )
        v4 = &v23;
      v6 = Sim::getCar(v3, 0);
      SystemMessage::clearMessage(v6->sim->systemMessage);
      v7 = Sim::getCar(this->sim, 0)->sim->game->graphics->gl;
      GLRenderer::color4f(v7, &this->backColor);
      GLRenderer::quad(v7, 0.0, 0.0, *v4, 79.0, 0, 0);
      GLRenderer::color4f(v7, &this->borderColor);
      GLRenderer::begin(v7, eLines, 0);
      GLRenderer::vertex3f(v7, 0.0, 80.0, 0.0);
      GLRenderer::vertex3f(v7, *v4, 80.0, 0.0);
      GLRenderer::end(v7);
      GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
      Font::setColor(this->font._Myptr, 1.0, 0.0, 0.0, 1.0);
      this->font._Myptr->shadowed = 1;
      std::wstring::wstring(&text, L"PENALTY");
      v35 = 0;
      v8 = acTranslate(&result, &text);
      v9 = *v4 * 0.5;
      v10 = this->font._Myptr;
      LOBYTE(v35) = 1;
      v24 = v9;
      Font::blitString(v10, v9, 5.0, v8, 2.0, eAlignCenter);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      v35 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      *(_DWORD *)line.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)line.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(line.gap68);
      v35 = 2;
      LODWORD(v23) = 1;
      std::wiostream::basic_iostream<wchar_t>(&line, &line.gap10[8], 0);
      v35 = 3;
      *(_DWORD *)&line.gap0[*(_DWORD *)(*(_DWORD *)line.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&v24 + *(_DWORD *)(*(_DWORD *)line.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)line.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&line.gap10[8]);
      *(_DWORD *)&line.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&line.gap10[64] = 0;
      *(_DWORD *)&line.gap10[68] = 0;
      v35 = 5;
      std::wstring::wstring(&result, L"SECONDS");
      LOBYTE(v35) = 6;
      std::wstring::wstring(&text, L"CONTROLS ARE LOCKED FOR");
      LOBYTE(v35) = 7;
      v11 = acTranslate(&v28, &result);
      v12 = this->sim;
      LOBYTE(v35) = 8;
      v13 = Sim::getCar(v12, 0);
      v14 = std::to_wstring(&v30, (int)(float)(v13->physicsState.lockControlsTime * 0.001));
      LOBYTE(v35) = 9;
      v15 = acTranslate(&v33, &text);
      LOBYTE(v35) = 10;
      v16 = std::operator+<wchar_t>(&v31, v15, L" ");
      v17 = v14->_Myres < 8;
      LOBYTE(v35) = 11;
      if ( !v17 )
        v14 = (std::wstring *)v14->_Bx._Ptr;
      v18 = std::operator+<wchar_t>(&v34.name, v16, v14->_Bx._Buf);
      LOBYTE(v35) = 12;
      v19 = std::operator+<wchar_t>(&v29, v18, L" ");
      LOBYTE(v35) = 13;
      v20 = std::operator+<wchar_t>(&v32, v19, v11);
      LOBYTE(v35) = 14;
      std::operator<<<wchar_t>((std::wostream *)line.gap10, v20);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v32);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v29);
      std::wstring::~wstring(&v34);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v31);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v33);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v30);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v28);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      LOBYTE(v35) = 5;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&line, &v28);
      v22 = this->font._Myptr;
      LOBYTE(v35) = 15;
      Font::blitString(v22, v24, 40.0, v21, 2.0, eAlignCenter);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v28);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&line);
    }
  }
}
