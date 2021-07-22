#include "systemmessage.h"
void SystemMessage::SystemMessage(SystemMessage *this, Sim *aSim)
{
  std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *v3; // eax
  Sim *v4; // eax
  ksgui::Taskbar *v5; // eax
  DefaultSystemMessage *v6; // ecx
  DefaultSystemMessage *v7; // eax
  DriverStatusSystemMessage *v8; // eax
  DriverStatusSystemMessage *v9; // eax
  SessionStatusSystemMessage *v10; // eax
  SessionStatusSystemMessage *v11; // eax
  std::wstring v12; // [esp-34h] [ebp-B8h] BYREF
  std::wstring v13; // [esp-1Ch] [ebp-A0h] BYREF
  SystemMessageType v14; // [esp-4h] [ebp-88h]
  std::wstring *v15; // [esp+Ch] [ebp-78h]
  std::wstring *v16; // [esp+10h] [ebp-74h]
  SystemMessage *v17; // [esp+14h] [ebp-70h]
  std::wstring ifilename; // [esp+18h] [ebp-6Ch] BYREF
  INIReader acIni; // [esp+30h] [ebp-54h] BYREF
  int v20; // [esp+80h] [ebp-4h]

  v17 = this;
  v14 = (SystemMessageType)aSim->game;
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  std::wstring::assign(&v13, L"SYSTEM_MESSAGE", 0xEu);
  GameObject::GameObject(this, v13, (Game *)v14);
  this->__vftable = (SystemMessage_vtbl *)&SystemMessage::`vftable';
  this->currentStatus = eDefaultSystemMessage;
  this->sim = aSim;
  v20 = 0;
  this->messageMask._Myhead = 0;
  this->messageMask._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<ID3D11View * const,PPFX::IGPUSurface *>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<unsigned int const ,bool>> > *)&this->messageMask);
  this->messageMask._Myhead = v3;
  v4 = this->sim;
  this->timer = 0.0;
  LOBYTE(v20) = 1;
  v5 = v4->game->gui->taskbar;
  if ( v5 )
    this->taskbar = v5;
  v6 = (DefaultSystemMessage *)operator new(316);
  v15 = (std::wstring *)v6;
  LOBYTE(v20) = 2;
  if ( v6 )
    DefaultSystemMessage::DefaultSystemMessage(v6, this->game->gui);
  else
    v7 = 0;
  v14 = 376;
  LOBYTE(v20) = 1;
  this->defaultSystemMessage = v7;
  v8 = (DriverStatusSystemMessage *)operator new(v14);
  v15 = (std::wstring *)v8;
  LOBYTE(v20) = 3;
  if ( v8 )
    DriverStatusSystemMessage::DriverStatusSystemMessage(v8, this->sim);
  else
    v9 = 0;
  v14 = 68;
  LOBYTE(v20) = 1;
  this->driverStatusSystemMessage = v9;
  v10 = (SessionStatusSystemMessage *)operator new(v14);
  v15 = (std::wstring *)v10;
  LOBYTE(v20) = 4;
  if ( v10 )
    SessionStatusSystemMessage::SessionStatusSystemMessage(v10, this->sim);
  else
    v11 = 0;
  this->sessionStatusSystemMessage = v11;
  LOBYTE(v20) = 1;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/messages.ini", 0x17u);
  LOBYTE(v20) = 5;
  INIReader::INIReader(&acIni, &ifilename);
  LOBYTE(v20) = 7;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( acIni.ready )
  {
    v14 = eNewGhostCar;
    v15 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"NEW_GHOST", 9u);
    LOBYTE(v20) = 8;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eServerPlayerJoined;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"SERVER_PLAYER_JOINED", 0x14u);
    LOBYTE(v20) = 9;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eServerPlayerDisconnected;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"SERVER_PLAYER_DISCONNECTED", 0x1Au);
    LOBYTE(v20) = 10;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eServerKickedMsg;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"SERVER_KICKED_MSG", 0x11u);
    LOBYTE(v20) = 11;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eServerSessionVoting;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"SERVER_SESSION_VOTING", 0x15u);
    LOBYTE(v20) = 12;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eServerKickVoting;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"SERVER_KICK_VOTING", 0x12u);
    LOBYTE(v20) = 13;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eServerVote;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"SERVER_VOTE", 0xBu);
    LOBYTE(v20) = 14;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eABS;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"ABS", 3u);
    LOBYTE(v20) = 15;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eTC;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"TC", 2u);
    LOBYTE(v20) = 16;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eTurbo;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"TURBO", 5u);
    LOBYTE(v20) = 17;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eBrakeBias;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"BRAKE_BIAS", 0xAu);
    LOBYTE(v20) = 18;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eBrakeEngine;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"BRAKE_ENGINE", 0xCu);
    LOBYTE(v20) = 19;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
    v14 = eMGU;
    v16 = &v13;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, L"MGU", 3u);
    LOBYTE(v20) = 20;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"SYSTEM", 6u);
    LOBYTE(v20) = 7;
    SystemMessage::setMask(this, &acIni, v12, v13, v14);
  }
  LOBYTE(v20) = 1;
  INIReader::~INIReader(&acIni);
}
void SystemMessage::~SystemMessage(SystemMessage *this)
{
  DefaultSystemMessage *v2; // ecx
  DriverStatusSystemMessage *v3; // ecx
  SessionStatusSystemMessage *v4; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > > result; // [esp+Ch] [ebp-10h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  result._Ptr = (std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *)this;
  this->__vftable = (SystemMessage_vtbl *)&SystemMessage::`vftable';
  v2 = this->defaultSystemMessage;
  v6 = 1;
  if ( v2 )
    ((void (*)(DefaultSystemMessage *, int))v2->~Control)(v2, 1);
  v3 = this->driverStatusSystemMessage;
  if ( v3 )
    ((void (*)(DriverStatusSystemMessage *, int))v3->~Control)(v3, 1);
  v4 = this->sessionStatusSystemMessage;
  if ( v4 )
  {
    SessionStatusSystemMessage::~SessionStatusSystemMessage(this->sessionStatusSystemMessage);
    operator delete(v4);
  }
  std::_Tree<std::_Tmap_traits<unsigned int,bool,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,bool>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<unsigned int,bool,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,bool> >,0> > *)&this->messageMask,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)this->messageMask._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)this->messageMask._Myhead);
  operator delete(this->messageMask._Myhead);
  v6 = -1;
  GameObject::~GameObject(this);
}
SystemMessage *SystemMessage::`vector deleting destructor'(SystemMessage *this, unsigned int a2)
{
  SystemMessage::~SystemMessage(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SystemMessage::addCarMessage(SystemMessage *this, unsigned int carIndex, const SystemMessageType type)
{
  std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *v4; // eax
  std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *v5; // esi
  std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *v6; // edx
  DriverStatusSystemMessage *v7; // ecx
  std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *v8; // [esp+10h] [ebp-4h]

  v4 = this->messageMask._Myhead;
  v5 = v4;
  v6 = v4->_Parent;
  while ( !v6->_Isnil )
  {
    if ( v6->_Myval.first >= type )
    {
      v5 = v6;
      v6 = v6->_Left;
    }
    else
    {
      v6 = v6->_Right;
    }
  }
  if ( v5 == v4 || (v8 = v5, type < v5->_Myval.first) )
    v8 = v4;
  if ( v8 == v4 || *(_BYTE *)std::map<enum SystemMessageType,bool>::operator[](&this->messageMask, &type) )
  {
    v7 = this->driverStatusSystemMessage;
    this->currentStatus = eDriverStatusSystemMessage;
    v7->currentCarIndex = carIndex;
    this->timer = 5.0;
  }
}
void SystemMessage::addMessage(SystemMessage *this, const std::wstring *imessage, const std::wstring *description, const SystemMessageType type)
{
  std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *v5; // edx
  int v6; // edi
  std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *v7; // esi
  const std::wstring *v8; // eax
  const std::wstring *v9; // ecx
  std::wstring v10; // [esp-30h] [ebp-54h] BYREF
  std::wstring v11; // [esp-18h] [ebp-3Ch] BYREF
  std::wstring *v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+20h] [ebp-4h]

  v5 = this->messageMask._Myhead;
  v6 = (int)v5;
  v7 = v5->_Parent;
  while ( !v7->_Isnil )
  {
    if ( v7->_Myval.first >= type )
    {
      v6 = (int)v7;
      v7 = v7->_Left;
    }
    else
    {
      v7 = v7->_Right;
    }
  }
  if ( (std::_Tree_node<std::pair<enum SystemMessageType const ,bool>,void *> *)v6 == v5
    || (v12 = (std::wstring *)v6, type < *(_DWORD *)(v6 + 16)) )
  {
    v12 = (std::wstring *)v5;
  }
  if ( v12 == (std::wstring *)v5
    || *(_BYTE *)std::map<enum SystemMessageType,bool>::operator[](&this->messageMask, &type) )
  {
    this->currentStatus = eDefaultSystemMessage;
    v12 = &v11;
    v11._Myres = 7;
    v11._Mysize = 0;
    v11._Bx._Buf[0] = 0;
    std::wstring::assign(&v11, description, 0, 0xFFFFFFFF);
    v13 = 0;
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
    std::wstring::assign(&v10, imessage, 0, 0xFFFFFFFF);
    v13 = -1;
    DefaultSystemMessage::setMessage(this->defaultSystemMessage, v10, v11);
    this->timer = 5.0;
  }
  else
  {
    v8 = description;
    if ( description->_Myres >= 8 )
      v8 = (const std::wstring *)description->_Bx._Ptr;
    v9 = imessage;
    if ( imessage->_Myres >= 8 )
      v9 = (const std::wstring *)imessage->_Bx._Ptr;
    _printf("System hidden message\n - %ls\n - %ls\n", v9->_Bx._Buf, v8->_Bx._Buf);
  }
}
void SystemMessage::clearMessage(SystemMessage *this)
{
  this->timer = -1.0;
}
void SystemMessage::loadDriversInfo(SystemMessage *this)
{
  DriverStatusSystemMessage::loadDriversInfo(this->driverStatusSystemMessage);
  this->timer = -1.0;
}
void SystemMessage::renderHUD(SystemMessage *this, float dt)
{
  SystemMessageMode v3; // eax
  void *v4; // ecx

  if ( this->sim->escMenu->visible )
    this->timer = -1.0;
  if ( this->timer <= 0.0 )
  {
    SessionStatusSystemMessage::render(this->sessionStatusSystemMessage, dt);
    return;
  }
  GraphicsManager::setBlendMode(this->game->gui->graphics, eAlphaBlend);
  v3 = this->currentStatus;
  if ( v3 )
  {
    if ( v3 != eDriverStatusSystemMessage )
    {
      SessionStatusSystemMessage::render(this->sessionStatusSystemMessage, dt);
      this->timer = this->timer - dt;
      return;
    }
    v4 = this->driverStatusSystemMessage;
  }
  else
  {
    v4 = this->defaultSystemMessage;
  }
  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 12))(LODWORD(dt));
  this->timer = this->timer - dt;
}
void SystemMessage::setMask(SystemMessage *this, INIReader *acIni, const std::wstring section, const std::wstring key, const SystemMessageType type)
{
  std::map<enum SystemMessageType,bool> *v5; // edi
  bool v6; // bl

  v5 = &this->messageMask;
  *(_BYTE *)std::map<enum SystemMessageType,bool>::operator[](&this->messageMask, &type) = 1;
  if ( INIReader::hasKey(acIni, &section, &key) )
  {
    v6 = INIReader::getInt(acIni, &section, &key) == 1;
    *(_BYTE *)std::map<enum SystemMessageType,bool>::operator[](v5, &type) = v6;
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
}
void SystemMessage::update(SystemMessage *this, float deltaT)
{
  Sim *v3; // eax
  ksgui::Form *v4; // ecx
  ESCMenu *v5; // eax
  DefaultSystemMessage_vtbl *v6; // edx
  GraphicsManager *v7; // eax
  __m128i v8; // xmm1
  float *v9; // eax
  DriverStatusSystemMessage_vtbl *v10; // edx
  GraphicsManager *v11; // eax
  __m128i v12; // xmm0
  float *v13; // eax
  float v14; // [esp+1Ch] [ebp-8h] BYREF
  float v15; // [esp+20h] [ebp-4h] BYREF

  v3 = this->sim;
  v4 = (ksgui::Form *)this->defaultSystemMessage;
  v5 = v3->escMenu;
  if ( v5->visible )
  {
    ksgui::Form::setPosition(v4, v5->rect.right - v5->rect.left, 0.0);
    ksgui::Form::setPosition(
      (ksgui::Form *)this->driverStatusSystemMessage,
      this->sim->escMenu->rect.right - this->sim->escMenu->rect.left,
      0.0);
    ((void (*)(DefaultSystemMessage *, _DWORD, int))this->defaultSystemMessage->setSize)(
      this->defaultSystemMessage,
      (float)this->game->graphics->videoSettings.width
    - (float)(this->sim->escMenu->rect.right - this->sim->escMenu->rect.left),
      1117782016);
    ((void (*)(DriverStatusSystemMessage *, _DWORD, int))this->driverStatusSystemMessage->setSize)(
      this->driverStatusSystemMessage,
      (float)this->game->graphics->videoSettings.width
    - (float)(this->sim->escMenu->rect.right - this->sim->escMenu->rect.left),
      1117782016);
  }
  else
  {
    ksgui::Form::setPosition(v4, 0.0, 0.0);
    ksgui::Form::setPosition((ksgui::Form *)this->driverStatusSystemMessage, 0.0, 0.0);
    v6 = this->defaultSystemMessage->__vftable;
    v7 = this->game->graphics;
    v14 = this->taskbar->rect.left - 1.0;
    v8 = _mm_cvtsi32_si128(v7->videoSettings.width);
    v9 = &v14;
    v15 = _mm_cvtepi32_ps(v8).m128_f32[0];
    if ( v15 <= v14 )
      v9 = &v15;
    ((void (__stdcall *)(_DWORD, int))v6->setSize)(*(_DWORD *)v9, 1117782016);
    v10 = this->driverStatusSystemMessage->__vftable;
    v11 = this->game->graphics;
    v15 = this->taskbar->rect.left - 1.0;
    v12 = _mm_cvtsi32_si128(v11->videoSettings.width);
    v13 = &v15;
    v14 = _mm_cvtepi32_ps(v12).m128_f32[0];
    if ( v14 <= v15 )
      v13 = &v14;
    ((void (__stdcall *)(_DWORD, int))v10->setSize)(*(_DWORD *)v13, 1117782016);
  }
  SessionStatusSystemMessage::update(this->sessionStatusSystemMessage, deltaT);
}
