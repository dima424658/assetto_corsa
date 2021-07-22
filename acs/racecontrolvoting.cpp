#include "racecontrolvoting.h
void RaceControlVoting::RaceControlVoting(RaceControlVoting *this, Sim *aSim)
{
  Game *v3; // eax
  Font *v4; // eax
  Font *v5; // eax
  volatile signed __int32 *v6; // edi
  unsigned int v7; // ebx
  Font *v8; // eax
  Font *v9; // eax
  volatile signed __int32 *v10; // edi
  Font *v11; // ecx
  ksgui::ActiveButton *v12; // edi
  ksgui::ActiveButton *v13; // eax
  ksgui::ActiveButton *v14; // ecx
  ksgui::ActiveButton *v15; // ecx
  float v16; // xmm1_4
  Event<OnMouseWheelMovedEvent> *v17; // ecx
  wchar_t *v18; // edi
  ksgui::ActiveButton *v19; // eax
  ksgui::ActiveButton *v20; // ecx
  ksgui::ActiveButton *v21; // ecx
  float v22; // xmm0_4
  Event<OnMouseWheelMovedEvent> *v23; // ecx
  wchar_t *v24; // edi
  ksgui::ActiveButton *v25; // eax
  ksgui::ActiveButton *v26; // ecx
  ksgui::ActiveButton *v27; // ecx
  float v28; // xmm0_4
  Event<OnMouseWheelMovedEvent> *v29; // ecx
  wchar_t *v30; // edi
  ksgui::ActiveButton *v31; // eax
  ksgui::ActiveButton *v32; // ecx
  ksgui::ActiveButton *v33; // ecx
  float v34; // xmm0_4
  Event<OnMouseWheelMovedEvent> *v35; // ecx
  Event<OnNewSessionEvent> *v36; // ecx
  _BYTE h[56]; // [esp+1Ch] [ebp-74h] BYREF
  void *v38; // [esp+60h] [ebp-30h]
  RaceControlVoting *v39; // [esp+64h] [ebp-2Ch]
  std::wstring iname; // [esp+68h] [ebp-28h] BYREF
  int v41; // [esp+8Ch] [ebp-4h]

  v39 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"RACE_CONTROL_VOTING", 0x13u);
  v3 = aSim->game;
  v41 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (RaceControlVoting_vtbl *)&RaceControlVoting::`vftable';
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  LOBYTE(v41) = 3;
  this->butVoteNextSession = 0;
  this->butVoteRestart = 0;
  this->butVoteYes = 0;
  *(_DWORD *)&h[24] = 1128792064;
  this->butVoteNo = 0;
  this->sim = aSim;
  this->timeToNextRequest = 0.0;
  this->sessionRequestCount = 0;
  ksgui::Control::setSize(this, 620.0, *(float *)&h[24]);
  v4 = (Font *)operator new(24);
  v38 = v4;
  LOBYTE(v41) = 4;
  if ( v4 )
    Font::Font(v4, eFontProportional, 14.0, 1, 1);
  else
    v5 = 0;
  LOBYTE(v41) = 3;
  *(_QWORD *)iname._Bx._Buf = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&iname, v5);
  std::shared_ptr<Font>::operator=(&this->titleFont, (std::shared_ptr<Font> *)&iname);
  v6 = *(volatile signed __int32 **)&iname._Bx._Alias[4];
  v7 = -1;
  if ( *(_DWORD *)&iname._Bx._Alias[4] )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)&iname._Bx._Alias[4] + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v6)(v6);
      if ( !_InterlockedExchangeAdd(v6 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v6 + 4))(v6);
    }
  }
  v8 = (Font *)operator new(24);
  v38 = v8;
  LOBYTE(v41) = 5;
  if ( v8 )
    Font::Font(v8, eFontMonospaced, 20.0, 0, 0);
  else
    v9 = 0;
  LOBYTE(v41) = 3;
  *(_QWORD *)iname._Bx._Buf = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&iname, v9);
  std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&iname);
  v10 = *(volatile signed __int32 **)&iname._Bx._Alias[4];
  if ( *(_DWORD *)&iname._Bx._Alias[4] )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)&iname._Bx._Alias[4] + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v10)(v10);
      v7 = _InterlockedDecrement(v10 + 2);
      if ( !v7 )
        (*(void (**)(volatile signed __int32 *))(*v10 + 4))(v10);
    }
  }
  v11 = this->font._Ptr;
  iname._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
  Font::setColor(v11, (const vec4f *)&iname);
  v12 = (ksgui::ActiveButton *)operator new(448);
  v38 = v12;
  LOBYTE(v41) = 6;
  if ( v12 )
  {
    *(_DWORD *)&h[24] = this->sim->game->gui;
    *(_DWORD *)&h[20] = 7;
    *(_DWORD *)&h[16] = 0;
    *(_WORD *)h = 0;
    std::wstring::assign((std::wstring *)h, L"BUT_VOTE_NEXT_SESSION", 0x15u);
    ksgui::ActiveButton::ActiveButton(v12, *(std::wstring *)h, *(ksgui::GUI **)&h[24]);
  }
  else
  {
    v13 = 0;
  }
  this->butVoteNextSession = v13;
  LOBYTE(v41) = 3;
  *(_DWORD *)&h[24] = 7;
  *(_DWORD *)&h[20] = 0;
  *(_WORD *)&h[4] = 0;
  std::wstring::assign((std::wstring *)&h[4], L"content/gui/raceControl/skip_icon", 0x21u);
  ksgui::ActiveButton::setMultipleTexture(this->butVoteNextSession, v7, *(std::wstring *)&h[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Next Session", 0xCu);
  v14 = this->butVoteNextSession;
  LOBYTE(v41) = 7;
  v14->setText(v14, &iname);
  LOBYTE(v41) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)this->butVoteNextSession, 45.0, 20.0);
  ((void (*)(ksgui::ActiveButton *, int, int))this->butVoteNextSession->setSize)(
    this->butVoteNextSession,
    1109393408,
    1109393408);
  v15 = this->butVoteNextSession;
  iname._Bx._Ptr = 0;
  *(_DWORD *)&h[24] = this;
  v16 = v15->rect.bottom - v15->rect.top;
  v15->textCoord.x = 0.0;
  *(float *)&iname._Bx._Alias[4] = v16;
  v15->textCoord.y = v16;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_f68f5318e090cd77d25b97858f77cfca_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v17 = (Event<OnMouseWheelMovedEvent> *)&this->butVoteNextSession->evClicked;
  LOBYTE(v41) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v17,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)h,
    *(void **)&h[24]);
  ksgui::Control::addControl(this, this->butVoteNextSession);
  v18 = (wchar_t *)operator new(448);
  iname._Bx._Ptr = v18;
  LOBYTE(v41) = 9;
  if ( v18 )
  {
    *(_DWORD *)&h[24] = this->sim->game->gui;
    *(_DWORD *)&h[20] = 7;
    *(_DWORD *)&h[16] = 0;
    *(_WORD *)h = 0;
    std::wstring::assign((std::wstring *)h, L"BUT_VOTE_RESTART_SESSION", 0x18u);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v18, *(std::wstring *)h, *(ksgui::GUI **)&h[24]);
  }
  else
  {
    v19 = 0;
  }
  this->butVoteRestart = v19;
  LOBYTE(v41) = 3;
  *(_DWORD *)&h[24] = 7;
  *(_DWORD *)&h[20] = 0;
  *(_WORD *)&h[4] = 0;
  std::wstring::assign((std::wstring *)&h[4], L"content/gui/raceControl/restart_icon", 0x24u);
  ksgui::ActiveButton::setMultipleTexture(this->butVoteRestart, v7, *(std::wstring *)&h[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Restart Session", 0xFu);
  v20 = this->butVoteRestart;
  LOBYTE(v41) = 10;
  v20->setText(v20, &iname);
  LOBYTE(v41) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)this->butVoteRestart, 185.0, 20.0);
  ((void (*)(ksgui::ActiveButton *, int, int))this->butVoteRestart->setSize)(
    this->butVoteRestart,
    1109393408,
    1109393408);
  v21 = this->butVoteRestart;
  iname._Bx._Ptr = 0;
  *(_DWORD *)&h[24] = this;
  v22 = v21->rect.bottom - v21->rect.top;
  v21->textCoord.x = 0.0;
  *(float *)&iname._Bx._Alias[4] = v22;
  v21->textCoord.y = v22;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_3ad8f7ad81e2d6392327fb1efbf08b42_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v23 = (Event<OnMouseWheelMovedEvent> *)&this->butVoteRestart->evClicked;
  LOBYTE(v41) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v23,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)h,
    *(void **)&h[24]);
  ksgui::Control::addControl(this, this->butVoteRestart);
  v24 = (wchar_t *)operator new(448);
  iname._Bx._Ptr = v24;
  LOBYTE(v41) = 12;
  if ( v24 )
  {
    *(_DWORD *)&h[24] = this->sim->game->gui;
    *(_DWORD *)&h[20] = 7;
    *(_DWORD *)&h[16] = 0;
    *(_WORD *)h = 0;
    std::wstring::assign((std::wstring *)h, L"BUT_VOTE_YES", 0xCu);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v24, *(std::wstring *)h, *(ksgui::GUI **)&h[24]);
  }
  else
  {
    v25 = 0;
  }
  this->butVoteYes = v25;
  LOBYTE(v41) = 3;
  *(_DWORD *)&h[24] = 7;
  *(_DWORD *)&h[20] = 0;
  *(_WORD *)&h[4] = 0;
  std::wstring::assign((std::wstring *)&h[4], L"content/gui/raceControl/vote_yes", 0x20u);
  ksgui::ActiveButton::setMultipleTexture(this->butVoteYes, v7, *(std::wstring *)&h[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Yes", 3u);
  v26 = this->butVoteYes;
  LOBYTE(v41) = 13;
  v26->setText(v26, &iname);
  LOBYTE(v41) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)this->butVoteYes, 45.0, 100.0);
  ((void (*)(ksgui::ActiveButton *, int, int))this->butVoteYes->setSize)(
    this->butVoteYes,
    1109393408,
    1109393408);
  v27 = this->butVoteYes;
  iname._Bx._Ptr = 0;
  *(_DWORD *)&h[24] = this;
  v28 = v27->rect.bottom - v27->rect.top;
  v27->textCoord.x = 0.0;
  *(float *)&iname._Bx._Alias[4] = v28;
  v27->textCoord.y = v28;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_c69f380736deb837b60bdbd51b0c49e3_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v29 = (Event<OnMouseWheelMovedEvent> *)&this->butVoteYes->evClicked;
  LOBYTE(v41) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v29,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)h,
    *(void **)&h[24]);
  ksgui::Control::addControl(this, this->butVoteYes);
  ksgui::Control::setVisible(this->butVoteYes, 0);
  v30 = (wchar_t *)operator new(448);
  iname._Bx._Ptr = v30;
  LOBYTE(v41) = 15;
  if ( v30 )
  {
    *(_DWORD *)&h[24] = this->sim->game->gui;
    *(_DWORD *)&h[20] = 7;
    *(_DWORD *)&h[16] = 0;
    *(_WORD *)h = 0;
    std::wstring::assign((std::wstring *)h, L"BUT_VOTE_NO", 0xBu);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v30, *(std::wstring *)h, *(ksgui::GUI **)&h[24]);
  }
  else
  {
    v31 = 0;
  }
  this->butVoteNo = v31;
  LOBYTE(v41) = 3;
  *(_DWORD *)&h[24] = 7;
  *(_DWORD *)&h[20] = 0;
  *(_WORD *)&h[4] = 0;
  std::wstring::assign((std::wstring *)&h[4], L"content/gui/raceControl/vote_no", 0x1Fu);
  ksgui::ActiveButton::setMultipleTexture(this->butVoteNo, v7, *(std::wstring *)&h[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"No", 2u);
  v32 = this->butVoteNo;
  LOBYTE(v41) = 16;
  v32->setText(v32, &iname);
  LOBYTE(v41) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->butVoteNo->setSize)(
    this->butVoteNo,
    1109393408,
    1109393408);
  ksgui::Form::setPosition((ksgui::Form *)this->butVoteNo, 185.0, 100.0);
  v33 = this->butVoteNo;
  iname._Bx._Ptr = 0;
  *(_DWORD *)&h[24] = this;
  v34 = v33->rect.bottom - v33->rect.top;
  v33->textCoord.x = 0.0;
  *(float *)&iname._Bx._Alias[4] = v34;
  v33->textCoord.y = v34;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_c32c24a05543357f470375f158ec58d6_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v35 = (Event<OnMouseWheelMovedEvent> *)&this->butVoteNo->evClicked;
  LOBYTE(v41) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v35,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)h,
    *(void **)&h[24]);
  ksgui::Control::addControl(this, this->butVoteNo);
  ksgui::Control::setVisible(this->butVoteNo, 0);
  *(_DWORD *)&h[24] = this;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_b18e1197a292d2440579ac87d6f8afb1_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v36 = &this->sim->evOnNewSession;
  LOBYTE(v41) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v36,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)h,
    this);
}
RaceControlVoting *RaceControlVoting::`scalar deleting destructor'(RaceControlVoting *this, unsigned int a2)
{
  std::_Ref_count_base *v3; // edi

  this->__vftable = (RaceControlVoting_vtbl *)&RaceControlVoting::`vftable';
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
void __userpurge RaceControlVoting::render(RaceControlVoting *this@<ecx>, int a2@<esi>, float dt)
{
  RaceControlVoting_vtbl *v4; // eax
  Sim *v5; // eax
  GLRenderer *v6; // esi
  const std::wstring *v7; // eax
  Font *v8; // ecx
  Sim *v9; // ecx
  float v10; // xmm0_4
  const std::wstring *v11; // eax
  Font *v12; // ecx
  const std::wstring *v13; // eax
  Font *v14; // ecx
  bool v15; // al
  bool v16; // al
  GLRenderer *v17; // esi
  double v18; // st7
  Sim *v19; // ecx
  double v20; // st7
  const std::wstring *v21; // eax
  float v22; // xmm0_4
  Font *v23; // ecx
  bool v24; // al
  ACClient *v25; // ecx
  VoteType v26; // eax
  __int32 v27; // eax
  const std::wstring *v28; // eax
  float v29; // xmm0_4
  Font *v30; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v31; // ecx
  std::wstring *v32; // eax
  std::wstring *v33; // esi
  Sim *v34; // ecx
  CarAvatar *v35; // eax
  std::wstring *v36; // eax
  const std::wstring *v37; // eax
  float v38; // xmm0_4
  Font *v39; // ecx
  const std::wstring *v40; // eax
  float v41; // xmm0_4
  Font *v42; // ecx
  const std::wstring *v43; // eax
  float v44; // xmm0_4
  Font *v45; // ecx
  VoteType v46; // eax
  __int32 v47; // eax
  const std::wstring *v48; // eax
  float v49; // xmm0_4
  Font *v50; // ecx
  std::wstring *v51; // eax
  std::wstring *v52; // esi
  Sim *v53; // ecx
  CarAvatar *v54; // eax
  const std::wstring *v55; // eax
  float v56; // xmm0_4
  Font *v57; // ecx
  const std::wstring *v58; // eax
  float v59; // xmm0_4
  Font *v60; // ecx
  const std::wstring *v61; // eax
  float v62; // xmm0_4
  Font *v63; // ecx
  float r_4; // [esp+Ch] [ebp-240h]
  __int64 v65; // [esp+1Ch] [ebp-230h]
  float v66; // [esp+24h] [ebp-228h]
  float maxWidth; // [esp+2Ch] [ebp-220h]
  float maxWidtha; // [esp+2Ch] [ebp-220h]
  ksgui::ksRect wrect; // [esp+30h] [ebp-21Ch] BYREF
  float v70; // [esp+40h] [ebp-20Ch]
  std::wstring result; // [esp+44h] [ebp-208h] BYREF
  std::wstring text; // [esp+5Ch] [ebp-1F0h] BYREF
  std::wstring v73; // [esp+74h] [ebp-1D8h] BYREF
  std::wstring v74; // [esp+8Ch] [ebp-1C0h] BYREF
  std::wstring v75; // [esp+A4h] [ebp-1A8h] BYREF
  std::wstring v76; // [esp+BCh] [ebp-190h] BYREF
  std::wstring v77; // [esp+D4h] [ebp-178h] BYREF
  std::wstring v78; // [esp+ECh] [ebp-160h] BYREF
  std::wstring v79; // [esp+104h] [ebp-148h] BYREF
  std::wstring v80; // [esp+11Ch] [ebp-130h] BYREF
  std::wstring v81; // [esp+134h] [ebp-118h] BYREF
  std::wstring v82; // [esp+14Ch] [ebp-100h] BYREF
  std::wstring v83; // [esp+164h] [ebp-E8h] BYREF
  std::wstring v84; // [esp+17Ch] [ebp-D0h] BYREF
  std::wstring v85; // [esp+194h] [ebp-B8h] BYREF
  std::wstring v86; // [esp+1ACh] [ebp-A0h] BYREF
  std::wstring v87; // [esp+1C4h] [ebp-88h] BYREF
  std::wstring v88; // [esp+1DCh] [ebp-70h] BYREF
  std::wstring v89; // [esp+1F4h] [ebp-58h] BYREF
  std::wstring v90; // [esp+20Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v91; // [esp+224h] [ebp-28h] BYREF
  int v92; // [esp+248h] [ebp-4h]

  ksgui::Control::render(this, (int)this, a2, dt, v65, v66);
  v4 = this->__vftable;
  wrect.left = 0.0;
  wrect.top = 0.0;
  wrect.right = 1.0;
  wrect.bottom = 1.0;
  v4->getWorldRect(this, &wrect);
  v5 = this->sim;
  wrect.left = this->rect.left + wrect.left;
  wrect.top = this->rect.top + wrect.top;
  v6 = v5->game->graphics->gl;
  GLRenderer::color4f(v6, colTitleBar_9.x, colTitleBar_9.y, colTitleBar_9.z, colTitleBar_9.w);
  GLRenderer::quad(v6, wrect.left, wrect.top, this->rect.right - this->rect.left, 20.0, 0, 0);
  Font::setColor(this->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"VOTING", 6u);
  v92 = 0;
  v7 = acTranslate(&result, &text);
  v8 = this->titleFont._Ptr;
  LOBYTE(v92) = 1;
  Font::blitString(v8, wrect.left + 10.0, wrect.top + 1.0, v7, 1.0, eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v92 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v9 = this->sim;
  wrect.top = wrect.top + 20.0;
  maxWidth = ACClient::getVotingTimeLeft(v9->client);
  ksgui::Control::setVisible(this->butVoteRestart, maxWidth <= 0.0);
  ksgui::Control::setVisible(this->butVoteNextSession, maxWidth <= 0.0);
  v10 = maxWidth;
  if ( this->timeToNextRequest > this->sim->game->gameTime.now && maxWidth <= 0.0 )
  {
    ksgui::Control::setVisible(this->butVoteRestart, 0);
    ksgui::Control::setVisible(this->butVoteNextSession, 0);
    std::wstring::wstring(&text, L"Voting request is locked for");
    v92 = 2;
    v11 = acTranslate(&result, &text);
    v12 = this->font._Ptr;
    LOBYTE(v92) = 3;
    Font::blitString(
      v12,
      (float)((float)(this->rect.right - this->rect.left) * 0.5) + wrect.left,
      wrect.top,
      v11,
      0.89999998,
      eAlignCenter);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v92 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v13 = timeToWString(&result, (int)(this->timeToNextRequest - this->sim->game->gameTime.now), 0, 0);
    v14 = this->font._Ptr;
    v92 = 4;
    Font::blitString(
      v14,
      (float)((float)(this->rect.right - this->rect.left) * 0.5) + wrect.left,
      wrect.top + 20.0,
      v13,
      1.0,
      eAlignCenter);
    v92 = -1;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v10 = maxWidth;
  }
  v15 = v10 > 0.0 && !ACClient::hasVoted(this->sim->client);
  ksgui::Control::setVisible(this->butVoteNo, v15);
  v16 = maxWidth > 0.0 && !ACClient::hasVoted(this->sim->client);
  ksgui::Control::setVisible(this->butVoteYes, v16);
  if ( maxWidth > 0.0 )
  {
    v17 = this->gui->graphics->gl;
    GLRenderer::color4f(v17, colTitleBar_9.x, colTitleBar_9.y, colTitleBar_9.z, colTitleBar_9.w);
    maxWidtha = this->rect.right - this->rect.left;
    v18 = ACClient::getVotingTimeLeft(this->sim->client);
    v19 = this->sim;
    v70 = v18 * maxWidtha;
    v20 = ACClient::getVotingMaxTime(v19->client);
    r_4 = v70 / v20;
    GLRenderer::quad(
      v17,
      (float)((float)((float)(maxWidtha * 0.5) + this->rect.left) + 100.0) - (float)(maxWidtha * 0.5),
      this->rect.top + 75.0,
      r_4,
      15.0,
      0,
      0);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"in progress", 0xBu);
    v92 = 5;
    v21 = acTranslate(&result, &text);
    v22 = this->rect.top + 50.0;
    v23 = this->font._Ptr;
    LOBYTE(v92) = 6;
    Font::blitString(
      v23,
      (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
      v22,
      v21,
      0.89999998,
      eAlignCenter);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v92 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v24 = ACClient::hasVoted(this->sim->client);
    v25 = this->sim->client;
    if ( v24 )
    {
      v46 = ACClient::getCurrentVoteType(v25);
      if ( v46 )
      {
        v47 = v46 - 1;
        if ( v47 )
        {
          if ( v47 == 1 )
          {
            std::wstring::wstring(&v74, L"Voted on kicking");
            v92 = 22;
            v51 = acTranslate(&v87, &v74);
            LOBYTE(v92) = 23;
            v52 = std::operator+<wchar_t>(&v85, v51, L" ");
            v53 = this->sim;
            LOBYTE(v92) = 24;
            v54 = ACClient::getCurrentVotingTarget(v53->client);
            v55 = std::operator+<wchar_t>(&v83, v52, &v54->driverInfo.name);
            v56 = this->rect.top + 20.0;
            v57 = this->font._Ptr;
            LOBYTE(v92) = 25;
            Font::blitString(
              v57,
              (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
              v56,
              v55,
              0.89999998,
              eAlignCenter);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v85);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v87);
            v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74;
          }
          else
          {
            std::wstring::wstring(&v77, L"Vote Submitted");
            v92 = 26;
            v48 = acTranslate(&v81, &v77);
            v49 = this->rect.top + 20.0;
            v50 = this->font._Ptr;
            LOBYTE(v92) = 27;
            Font::blitString(
              v50,
              (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
              v49,
              v48,
              0.89999998,
              eAlignCenter);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v81);
            v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77;
          }
        }
        else
        {
          std::wstring::wstring(&v76, L"Voted on restarting session");
          v92 = 20;
          v58 = acTranslate(&v89, &v76);
          v59 = this->rect.top + 20.0;
          v60 = this->font._Ptr;
          LOBYTE(v92) = 21;
          Font::blitString(
            v60,
            (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
            v59,
            v58,
            0.89999998,
            eAlignCenter);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v89);
          v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76;
        }
      }
      else
      {
        std::wstring::wstring(&v78, L"Voted on skipping session");
        v92 = 18;
        v61 = acTranslate(&v91.name, &v78);
        v62 = this->rect.top + 20.0;
        v63 = this->font._Ptr;
        LOBYTE(v92) = 19;
        Font::blitString(
          v63,
          (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
          v62,
          v61,
          0.89999998,
          eAlignCenter);
        std::wstring::~wstring(&v91);
        v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78;
      }
    }
    else
    {
      v26 = ACClient::getCurrentVoteType(v25);
      if ( v26 )
      {
        v27 = v26 - 1;
        if ( v27 )
        {
          if ( v27 == 1 )
          {
            std::wstring::wstring(&text, L"Kick");
            v92 = 11;
            v32 = acTranslate(&v84, &text);
            LOBYTE(v92) = 12;
            v33 = std::operator+<wchar_t>(&v90, v32, L" ");
            v34 = this->sim;
            LOBYTE(v92) = 13;
            v35 = ACClient::getCurrentVotingTarget(v34->client);
            v36 = std::operator+<wchar_t>(&v82, v33, &v35->driverInfo.name);
            LOBYTE(v92) = 14;
            v37 = std::operator+<wchar_t>(&v86, v36, L" ?");
            v38 = this->rect.top + 20.0;
            v39 = this->font._Ptr;
            LOBYTE(v92) = 15;
            Font::blitString(
              v39,
              (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
              v38,
              v37,
              0.89999998,
              eAlignCenter);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v86);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v82);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v90);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v84);
            v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
          }
          else
          {
            std::wstring::wstring(&result, L"Choose your vote");
            v92 = 16;
            v28 = acTranslate(&v79, &result);
            v29 = this->rect.top + 20.0;
            v30 = this->font._Ptr;
            LOBYTE(v92) = 17;
            Font::blitString(
              v30,
              (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
              v29,
              v28,
              0.89999998,
              eAlignCenter);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
            v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
          }
        }
        else
        {
          std::wstring::wstring(&v73, L"Restart session?");
          v92 = 9;
          v40 = acTranslate(&v88, &v73);
          v41 = this->rect.top + 20.0;
          v42 = this->font._Ptr;
          LOBYTE(v92) = 10;
          Font::blitString(
            v42,
            (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
            v41,
            v40,
            0.89999998,
            eAlignCenter);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v88);
          v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73;
        }
      }
      else
      {
        std::wstring::wstring(&v75, L"Skip session?");
        v92 = 7;
        v43 = acTranslate(&v80, &v75);
        v44 = this->rect.top + 20.0;
        v45 = this->font._Ptr;
        LOBYTE(v92) = 8;
        Font::blitString(
          v45,
          (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left) + 100.0,
          v44,
          v43,
          0.89999998,
          eAlignCenter);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v80);
        v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75;
      }
    }
    std::wstring::~wstring(v31);
  }
}
bool RaceControlVoting::voteSpamCheck(RaceControlVoting *this)
{
  Sim *v1; // ebx
  bool result; // al
  double v3; // xmm1_8
  unsigned int v4; // edi
  unsigned int v5; // esi
  int v6; // edx
  double v7; // xmm0_8
  unsigned int v8; // eax

  v1 = this->sim;
  if ( this->timeToNextRequest > v1->game->gameTime.now )
    return 0;
  ++this->sessionRequestCount;
  v3 = 0.0;
  v4 = this->sessionRequestCount;
  v5 = 1;
  this->timeToNextRequest = 0.0;
  if ( v4 )
  {
    v6 = 60000;
    do
    {
      v7 = (double)v6;
      v8 = (unsigned int)v6 >> 31;
      ++v5;
      v6 += 60000;
      v3 = v3 + v7 + _xmm[v8];
    }
    while ( v5 <= v4 );
    this->timeToNextRequest = v3;
  }
  result = 1;
  this->timeToNextRequest = v1->game->gameTime.now + this->timeToNextRequest;
  return result;
}
