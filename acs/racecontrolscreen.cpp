#include "racecontrolscreen.h"
void RaceControlScreen::RaceControlScreen(RaceControlScreen *this, Sim *aSim)
{
  Game *v3; // eax
  RaceControlSessionInfo *v4; // eax
  RaceControlSessionInfo *v5; // eax
  RaceControlSessionServer *v6; // eax
  RaceControlSessionServer *v7; // eax
  RaceControlSessionServer *v8; // ecx
  RaceControlSessionInfo *v9; // eax
  RaceControlVoting *v10; // eax
  RaceControlVoting *v11; // eax
  RaceControlVoting *v12; // ecx
  RaceControlSessionServer *v13; // eax
  ACChat *v14; // eax
  ACChat *v15; // eax
  ACStandardLeaderboard *v16; // eax
  ACStandardLeaderboard *v17; // eax
  RaceControlSPSession *v18; // eax
  int v19; // eax
  int v20; // edi
  RaceControlSessionInfo *v21; // eax
  int *v22; // eax
  float v23; // xmm0_4
  int v24; // edi
  ACStandardLeaderboard *v25; // eax
  ACStandardLeaderboard *v26; // eax
  Font *v27; // eax
  Font *v28; // eax
  volatile signed __int32 *v29; // edi
  int numberOfRows; // [esp+38h] [ebp-38h] BYREF
  volatile signed __int32 *v31; // [esp+3Ch] [ebp-34h]
  int v32[2]; // [esp+40h] [ebp-30h] BYREF
  std::wstring iname; // [esp+48h] [ebp-28h] BYREF
  int v34; // [esp+6Ch] [ebp-4h]

  v32[1] = (int)this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"RACE_CONTROL_SCREEN", 0x13u);
  v3 = aSim->game;
  v34 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (RaceControlScreen_vtbl *)&RaceControlScreen::`vftable';
  this->chat = 0;
  this->sim = aSim;
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  LOBYTE(v34) = 3;
  this->voting = 0;
  this->leaderboard = 0;
  this->sessionInfo = 0;
  this->serverInfo = 0;
  v4 = (RaceControlSessionInfo *)operator new(496);
  numberOfRows = (int)v4;
  LOBYTE(v34) = 4;
  if ( v4 )
    RaceControlSessionInfo::RaceControlSessionInfo(v4, this->sim);
  else
    v5 = 0;
  LOBYTE(v34) = 3;
  this->sessionInfo = v5;
  ksgui::Form::setPosition((ksgui::Form *)v5, 20.0, 55.0);
  ((void (*)(RaceControlSessionInfo *, int, int))this->sessionInfo->setSize)(
    this->sessionInfo,
    1133576192,
    1128988672);
  this->sessionInfo->drawBackground = 0;
  this->sessionInfo->drawBorder = 0;
  ksgui::Control::addControl(this, this->sessionInfo);
  if ( this->sim->client )
  {
    v6 = (RaceControlSessionServer *)operator new(300);
    numberOfRows = (int)v6;
    LOBYTE(v34) = 5;
    if ( v6 )
    {
      RaceControlSessionServer::RaceControlSessionServer(v6, this->sim);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    v9 = this->sessionInfo;
    this->serverInfo = v8;
    LOBYTE(v34) = 3;
    ksgui::Form::setPosition((ksgui::Form *)v8, 20.0, v9->rect.bottom + 15.0);
    ((void (*)(RaceControlSessionServer *, int, int))this->serverInfo->setSize)(
      this->serverInfo,
      1133576192,
      1134723072);
    this->serverInfo->drawBackground = 0;
    this->serverInfo->drawBorder = 0;
    ksgui::Control::addControl(this, this->serverInfo);
    v10 = (RaceControlVoting *)operator new(328);
    numberOfRows = (int)v10;
    LOBYTE(v34) = 6;
    if ( v10 )
    {
      RaceControlVoting::RaceControlVoting(v10, this->sim);
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    v13 = this->serverInfo;
    this->voting = v12;
    LOBYTE(v34) = 3;
    ksgui::Form::setPosition((ksgui::Form *)v12, 20.0, v13->rect.bottom + 15.0);
    ((void (*)(RaceControlVoting *, int, int))this->voting->setSize)(this->voting, 1133576192, 1127153664);
    this->voting->backColor = (vec4f)_xmm;
    this->voting->drawBorder = 0;
    ksgui::Control::addControl(this, this->voting);
    v14 = (ACChat *)operator new(364);
    numberOfRows = (int)v14;
    LOBYTE(v34) = 7;
    if ( v14 )
      ACChat::ACChat(v14, this->sim);
    else
      v15 = 0;
    LOBYTE(v34) = 3;
    this->chat = v15;
    ksgui::Form::setPosition((ksgui::Form *)v15, 325.0, 425.0);
    ((void (*)(ACChat *, int, _DWORD))this->chat->setSize)(
      this->chat,
      1145241600,
      this->voting->rect.bottom - this->chat->rect.top);
    this->chat->backColor = (vec4f)_xmm;
    this->chat->drawBorder = 0;
    ksgui::Control::addControl(this, this->chat);
    v16 = (ACStandardLeaderboard *)operator new(536);
    numberOfRows = (int)v16;
    LOBYTE(v34) = 8;
    if ( v16 )
      ACStandardLeaderboard::ACStandardLeaderboard(v16, this->sim, 10, 0);
    else
      v17 = 0;
    LOBYTE(v34) = 3;
    this->leaderboard = v17;
    ksgui::Form::setPosition((ksgui::Form *)v17, 325.0, 55.0);
    ((void (*)(ACStandardLeaderboard *, int, int))this->leaderboard->setSize)(
      this->leaderboard,
      1145241600,
      1134723072);
  }
  else
  {
    v18 = (RaceControlSPSession *)operator new(304);
    numberOfRows = (int)v18;
    LOBYTE(v34) = 9;
    if ( v18 )
    {
      RaceControlSPSession::RaceControlSPSession(v18, this->sim);
      v20 = v19;
    }
    else
    {
      v20 = 0;
    }
    v21 = this->sessionInfo;
    LOBYTE(v34) = 3;
    ksgui::Form::setPosition((ksgui::Form *)v20, 20.0, v21->rect.bottom + 15.0);
    (*(void (**)(int, int, int))(*(_DWORD *)v20 + 28))(v20, 1133576192, 1120403456);
    *(_OWORD *)(v20 + 44) = _xmm;
    *(_BYTE *)(v20 + 200) = 0;
    ksgui::Control::addControl(this, (ksgui::Control *)v20);
    v22 = v32;
    v23 = (float)(this->gui->graphics->videoSettings.height - 200) * 0.032786883;
    v32[0] = this->sim->cars._Mylast - this->sim->cars._Myfirst;
    numberOfRows = (int)v23;
    if ( v32[0] >= (int)v23 )
      v22 = &numberOfRows;
    v24 = *v22;
    v25 = (ACStandardLeaderboard *)operator new(536);
    numberOfRows = (int)v25;
    LOBYTE(v34) = 10;
    if ( v25 )
      ACStandardLeaderboard::ACStandardLeaderboard(v25, this->sim, v24, 0);
    else
      v26 = 0;
    LOBYTE(v34) = 3;
    this->leaderboard = v26;
    ksgui::Form::setPosition((ksgui::Form *)v26, 325.0, 55.0);
    ((void (*)(ACStandardLeaderboard *, int, _DWORD))this->leaderboard->setSize)(
      this->leaderboard,
      1145241600,
      (float)((float)v24 * 30.5) + 20.0);
  }
  this->leaderboard->showModeButtons = 1;
  ksgui::Control::addControl(this, this->leaderboard);
  v27 = (Font *)operator new(24);
  numberOfRows = (int)v27;
  LOBYTE(v34) = 11;
  if ( v27 )
    Font::Font(v27, eFontMonospaced, 25.0, 1, 1);
  else
    v28 = 0;
  LOBYTE(v34) = 3;
  numberOfRows = 0;
  v31 = 0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&numberOfRows, v28);
  std::shared_ptr<Font>::operator=(&this->titleFont, (std::shared_ptr<Font> *)&numberOfRows);
  v29 = v31;
  if ( v31 && !_InterlockedExchangeAdd(v31 + 1, 0xFFFFFFFF) )
  {
    (**(void (***)(volatile signed __int32 *))v29)(v29);
    if ( !_InterlockedDecrement(v29 + 2) )
      (*(void (**)(void))(*v29 + 4))();
  }
}
RaceControlScreen *RaceControlScreen::`scalar deleting destructor'(RaceControlScreen *this, unsigned int a2)
{
  std::_Ref_count_base *v3; // edi

  this->__vftable = (RaceControlScreen_vtbl *)&RaceControlScreen::`vftable';
  v3 = this->titleFont._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v3->_Weaks) )
        v3->_Delete_this(v3);
    }
  }
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
int RaceControlScreen::getShownSessionID(RaceControlScreen *this)
{
  return this->leaderboard->sessionID;
}
void __userpurge RaceControlScreen::render(RaceControlScreen *this@<ecx>, int a2@<esi>, float dt)
{
  RaceControlScreen_vtbl *v4; // eax
  unsigned int v5; // ebx
  float v6; // xmm0_4
  Sim *v7; // ecx
  Game *v8; // eax
  RaceManager *v9; // ecx
  GLRenderer *v10; // esi
  Sim *v11; // ecx
  int v12; // ebp
  vec4f r; // xmm0
  std::wstring *v14; // ecx
  std::wstring *v15; // ebx
  wchar_t *v16; // eax
  std::wstring *v17; // ecx
  const std::wstring *v18; // eax
  std::wostream *v19; // eax
  const std::wstring *v20; // eax
  ACClient *v21; // eax
  unsigned __int16 v22; // ax
  int v23; // ebx
  vec4f v24; // xmm0
  RaceManager *v25; // ecx
  unsigned __int16 v26; // ax
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  const std::wstring *v29; // eax
  Font *v30; // ecx
  unsigned __int16 v31; // ax
  std::wstring *v32; // eax
  std::wstring *v33; // eax
  const std::wstring *v34; // eax
  Font *v35; // ecx
  unsigned __int16 v36; // ax
  std::wstring *v37; // eax
  const std::wstring *v38; // eax
  Font *v39; // ecx
  unsigned __int16 v40; // ax
  std::wstring *v41; // eax
  const std::wstring *v42; // eax
  Font *v43; // ecx
  const std::wstring *v44; // eax
  Font *v45; // ecx
  int v46; // eax
  Sim *v47; // ecx
  unsigned int v48; // eax
  Sim *v49; // ecx
  __int64 v50; // [esp+24h] [ebp-1BCh]
  float v51; // [esp+2Ch] [ebp-1B4h]
  ksgui::ksRect wrect; // [esp+3Ch] [ebp-1A4h] BYREF
  int v53; // [esp+4Ch] [ebp-194h]
  GLRenderer *v54; // [esp+50h] [ebp-190h]
  int v55; // [esp+54h] [ebp-18Ch]
  double result; // [esp+58h] [ebp-188h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v57; // [esp+60h] [ebp-180h] BYREF
  Session sessionInfo; // [esp+110h] [ebp-D0h] BYREF
  std::wstring v59; // [esp+170h] [ebp-70h] BYREF
  std::wstring sessionInfoName; // [esp+188h] [ebp-58h] BYREF
  std::wstring v61; // [esp+1A0h] [ebp-40h] BYREF
  std::wstring v62; // [esp+1B8h] [ebp-28h] BYREF
  int v63; // [esp+1DCh] [ebp-4h]

  v55 = 0;
  ksgui::Control::render(this, (int)this, a2, dt, v50, v51);
  v4 = this->__vftable;
  wrect.left = 0.0;
  wrect.top = 0.0;
  wrect.right = 1.0;
  wrect.bottom = 1.0;
  v4->getWorldRect(this, &wrect);
  v5 = 0;
  v6 = this->rect.left + 20.0;
  v7 = this->sim;
  v53 = 0;
  wrect.left = v6 + wrect.left;
  wrect.top = (float)(this->rect.top + 8.0) + wrect.top;
  v8 = v7->game;
  v9 = v7->raceManager;
  v10 = v8->graphics->gl;
  v54 = v10;
  if ( RaceManager::getSessionCount(v9) )
  {
    do
    {
      RaceManager::getSessionInfo(this->sim->raceManager, &sessionInfo, v5);
      v11 = this->sim;
      v63 = 0;
      v12 = RaceManager::getCurrentSessionIndex(v11->raceManager);
      if ( v5 == v12 )
        r = colTitleBar_5;
      else
        r = colDarkBar_5;
      GLRenderer::color4f(v10, r.x, r.y, r.z, r.w);
      GLRenderer::quad(v10, wrect.left, wrect.top, 290.0, 32.0, 0, 0);
      sessionInfoName._Myres = 7;
      sessionInfoName._Bx._Buf[0] = 0;
      sessionInfoName._Mysize = 0;
      std::wstring::assign(&sessionInfoName, &sessionInfo.name, 0, 0xFFFFFFFF);
      v14 = &sessionInfoName;
      v15 = &sessionInfoName;
      LOBYTE(v63) = 1;
      if ( sessionInfoName._Myres >= 8 )
        v14 = (std::wstring *)sessionInfoName._Bx._Ptr;
      if ( sessionInfoName._Myres >= 8 )
        v15 = (std::wstring *)sessionInfoName._Bx._Ptr;
      v16 = &v14->_Bx._Buf[sessionInfoName._Mysize];
      v17 = &sessionInfoName;
      if ( sessionInfoName._Myres >= 8 )
        v17 = (std::wstring *)sessionInfoName._Bx._Ptr;
      if ( v17 == (std::wstring *)v16 )
        LODWORD(result) = v15;
      else
        std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
          (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&result,
          v17->_Bx._Buf,
          v16,
          (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v15,
          _toupper);
      *(_DWORD *)v57.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v57.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v57.gap68);
      v55 |= 1u;
      LOBYTE(v63) = 2;
      std::wiostream::basic_iostream<wchar_t>(&v57, &v57.gap10[8], 0);
      v63 = 3;
      *(_DWORD *)&v57.gap0[*(_DWORD *)(*(_DWORD *)v57.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&result + *(_DWORD *)(*(_DWORD *)v57.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v57.gap0 + 4)
                                                                              - 104;
      std::wstreambuf::wstreambuf(&v57.gap10[8]);
      *(_DWORD *)&v57.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v57.gap10[64] = 0;
      *(_DWORD *)&v57.gap10[68] = 0;
      LOBYTE(v63) = 5;
      v18 = acTranslate(&v59, &sessionInfoName);
      LOBYTE(v63) = 6;
      std::operator<<<wchar_t>((std::wostream *)v57.gap10, v18);
      LOBYTE(v63) = 5;
      if ( v59._Myres >= 8 )
        operator delete(v59._Bx._Ptr);
      if ( sessionInfo.sessionType == Race && RaceManager::getInvertedGridPositions(this->sim->raceManager) )
        std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v57.gap10, "x2");
      std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v57.gap10, " ");
      if ( sessionInfo.sessionType != Race || sessionInfo.isTimedRace )
      {
        v20 = timeToWString(&v59, (int)(float)(sessionInfo.durationMinutes * 60000.0), 1, 0);
        LOBYTE(v63) = 7;
        std::operator<<<wchar_t>((std::wostream *)v57.gap10, v20);
        LOBYTE(v63) = 5;
        if ( v59._Myres >= 8 )
          operator delete(v59._Bx._Ptr);
        v21 = this->sim->client;
        if ( v21 )
        {
          if ( sessionInfo.sessionType != Race )
            goto LABEL_54;
          if ( !v21->hasExtraLap )
            goto LABEL_29;
          std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v57.gap10, "+");
        }
      }
      else
      {
        v19 = (std::wostream *)std::wostream::operator<<(v57.gap10, sessionInfo.laps);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v19, "L");
      }
      if ( sessionInfo.sessionType == Race )
      {
LABEL_29:
        v22 = RaceManager::getPitWindowEnd(this->sim->raceManager);
        v23 = v53;
        if ( v22 )
        {
          if ( v53 == v12 )
            v24 = colTitleBar_5;
          else
            v24 = colDarkBar_5;
          GLRenderer::color4f(v54, v24.x, v24.y, v24.z, v24.w);
          GLRenderer::quad(v54, wrect.left + 290.0, wrect.top, 152.0, 32.0, 0, 0);
          v25 = this->sim->raceManager;
          if ( sessionInfo.isTimedRace )
          {
            v26 = RaceManager::getPitWindowStart(v25);
            v27 = std::to_wstring(&v61, (int)(float)(sessionInfo.durationMinutes - (float)v26));
            LOBYTE(v63) = 8;
            v28 = std::operator+<wchar_t>(&v59, L"PIT OPEN: ", v27);
            LOBYTE(v63) = 9;
            v29 = std::operator+<wchar_t>(&v62, v28, L" minutes left");
            v30 = this->titleFont._Ptr;
            LOBYTE(v63) = 10;
            Font::blitString(v30, wrect.left + 440.0, wrect.top, v29, 0.5, eAlignRight);
            if ( v62._Myres >= 8 )
              operator delete(v62._Bx._Ptr);
            v62._Myres = 7;
            v62._Mysize = 0;
            v62._Bx._Buf[0] = 0;
            if ( v59._Myres >= 8 )
              operator delete(v59._Bx._Ptr);
            v59._Myres = 7;
            v59._Mysize = 0;
            v59._Bx._Buf[0] = 0;
            LOBYTE(v63) = 5;
            if ( v61._Myres >= 8 )
              operator delete(v61._Bx._Ptr);
            v31 = RaceManager::getPitWindowEnd(this->sim->raceManager);
            v32 = std::to_wstring(&v61, (int)(float)(sessionInfo.durationMinutes - (float)v31));
            LOBYTE(v63) = 11;
            v33 = std::operator+<wchar_t>(&v62, L"PIT CLOSE: ", v32);
            LOBYTE(v63) = 12;
            v34 = std::operator+<wchar_t>(&v59, v33, L" minutes left");
            v35 = this->titleFont._Ptr;
            LOBYTE(v63) = 13;
            Font::blitString(v35, wrect.left + 440.0, wrect.top + 16.0, v34, 0.5, eAlignRight);
            if ( v59._Myres >= 8 )
              operator delete(v59._Bx._Ptr);
            v59._Myres = 7;
            v59._Mysize = 0;
            v59._Bx._Buf[0] = 0;
            if ( v62._Myres >= 8 )
              operator delete(v62._Bx._Ptr);
            v62._Myres = 7;
            v62._Mysize = 0;
            v62._Bx._Buf[0] = 0;
          }
          else
          {
            v36 = RaceManager::getPitWindowStart(v25);
            v37 = std::to_wstring(&v61, v36);
            LOBYTE(v63) = 14;
            v38 = std::operator+<wchar_t>(&v59, L"PIT OPEN: lap ", v37);
            v39 = this->titleFont._Ptr;
            LOBYTE(v63) = 15;
            Font::blitString(v39, wrect.left + 440.0, wrect.top, v38, 0.5, eAlignRight);
            if ( v59._Myres >= 8 )
              operator delete(v59._Bx._Ptr);
            v59._Myres = 7;
            v59._Mysize = 0;
            v59._Bx._Buf[0] = 0;
            LOBYTE(v63) = 5;
            if ( v61._Myres >= 8 )
              operator delete(v61._Bx._Ptr);
            v40 = RaceManager::getPitWindowEnd(this->sim->raceManager);
            v41 = std::to_wstring(&v61, v40);
            LOBYTE(v63) = 16;
            v42 = std::operator+<wchar_t>(&v59, L"PIT CLOSE: lap ", v41);
            v43 = this->titleFont._Ptr;
            LOBYTE(v63) = 17;
            Font::blitString(v43, wrect.left + 440.0, wrect.top + 16.0, v42, 0.5, eAlignRight);
            if ( v59._Myres >= 8 )
              operator delete(v59._Bx._Ptr);
            v59._Myres = 7;
            v59._Mysize = 0;
            v59._Bx._Buf[0] = 0;
          }
          LOBYTE(v63) = 5;
          if ( v61._Myres >= 8 )
            operator delete(v61._Bx._Ptr);
        }
        goto LABEL_55;
      }
LABEL_54:
      v23 = v53;
LABEL_55:
      v44 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v57, &v61);
      v45 = this->titleFont._Ptr;
      LOBYTE(v63) = 18;
      Font::blitString(v45, wrect.left + 145.0, wrect.top, v44, 1.0, eAlignCenter);
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      LOBYTE(v63) = 1;
      wrect.left = wrect.left + 308.0;
      *(_DWORD *)&v57.gap0[*(_DWORD *)(*(_DWORD *)v57.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&result + *(_DWORD *)(*(_DWORD *)v57.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v57.gap0 + 4)
                                                                              - 104;
      *(_DWORD *)&v57.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v57.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v57.gap10[8]) )
          std::wstreambuf::epptr(&v57.gap10[8]);
        else
          std::wstreambuf::egptr(&v57.gap10[8]);
        std::wstreambuf::eback(&v57.gap10[8]);
        v46 = std::wstreambuf::eback(&v57.gap10[8]);
        operator delete(v46);
      }
      std::wstreambuf::setg(&v57.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v57.gap10[8], 0, 0);
      *(_DWORD *)&v57.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v57.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v57.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v57.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v57.gap68);
      if ( sessionInfoName._Myres >= 8 )
        operator delete(sessionInfoName._Bx._Ptr);
      sessionInfoName._Myres = 7;
      sessionInfoName._Mysize = 0;
      sessionInfoName._Bx._Buf[0] = 0;
      v63 = -1;
      if ( sessionInfo.name._Myres >= 8 )
        operator delete(sessionInfo.name._Bx._Ptr);
      sessionInfo.name._Myres = 7;
      sessionInfo.name._Mysize = 0;
      sessionInfo.name._Bx._Buf[0] = 0;
      if ( sessionInfo.spawSet._Myres >= 8 )
        operator delete(sessionInfo.spawSet._Bx._Ptr);
      v47 = this->sim;
      v5 = v23 + 1;
      v53 = v5;
      v48 = RaceManager::getSessionCount(v47->raceManager);
      v10 = v54;
    }
    while ( v5 < v48 );
  }
  v49 = this->sim;
  if ( v49->client )
  {
    if ( RaceManager::getCurrentSessionType(v49->raceManager) == Race )
    {
      ksgui::Control::setVisible(this->voting, 1);
    }
    else
    {
      result = RaceManager::getSessionTimeLeft(this->sim->raceManager);
      ksgui::Control::setVisible(this->voting, result > 30000.0);
    }
  }
}
