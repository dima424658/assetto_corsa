#include "racecontrolspsession.h"
void RaceControlSPSession::RaceControlSPSession(RaceControlSPSession *this, Sim *aSim)
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
  _BYTE h[56]; // [esp+8h] [ebp-84h] BYREF
  void *v31; // [esp+44h] [ebp-48h]
  RaceControlSPSession *v32; // [esp+48h] [ebp-44h]
  std::wstring iname; // [esp+4Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+64h] [ebp-28h] BYREF
  int v35; // [esp+88h] [ebp-4h]

  v32 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"RACE_CONTROL_SESSION", 0x14u);
  v3 = aSim->game;
  v35 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (RaceControlSPSession_vtbl *)&RaceControlSPSession::`vftable';
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  LOBYTE(v35) = 3;
  this->butRestart = 0;
  this->butSkip = 0;
  this->butExit = 0;
  *(_DWORD *)&h[24] = 1128792064;
  this->sim = aSim;
  ksgui::Control::setSize(this, 620.0, *(float *)&h[24]);
  v4 = (Font *)operator new(24);
  v31 = v4;
  LOBYTE(v35) = 4;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 14.0, 1, 1);
  else
    v5 = 0;
  LOBYTE(v35) = 3;
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
  v31 = v8;
  LOBYTE(v35) = 5;
  if ( v8 )
    Font::Font(v8, eFontProportional, 20.0, 0, 0);
  else
    v9 = 0;
  LOBYTE(v35) = 3;
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
  v31 = v12;
  LOBYTE(v35) = 6;
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
  this->butRestart = v13;
  LOBYTE(v35) = 3;
  *(_DWORD *)&h[24] = 7;
  *(_DWORD *)&h[20] = 0;
  *(_WORD *)&h[4] = 0;
  std::wstring::assign((std::wstring *)&h[4], L"content/gui/raceControl/restart_icon", 0x24u);
  ksgui::ActiveButton::setMultipleTexture(this->butRestart, v7, *(std::wstring *)&h[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Restart Session", 0xFu);
  LOBYTE(v35) = 7;
  *(_DWORD *)&h[24] = acTranslate(&result, &iname);
  v14 = this->butRestart;
  LOBYTE(v35) = 8;
  v14->setText(v14, *(const std::wstring **)&h[24]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v35) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)this->butRestart, 45.0, 30.0);
  ((void (*)(ksgui::ActiveButton *, int, int))this->butRestart->setSize)(
    this->butRestart,
    1109393408,
    1109393408);
  v15 = this->butRestart;
  iname._Bx._Ptr = 0;
  *(_DWORD *)&h[24] = this;
  v16 = v15->rect.bottom - v15->rect.top;
  v15->textCoord.x = 0.0;
  *(float *)&iname._Bx._Alias[4] = v16;
  v15->textCoord.y = v16;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_2dd610ddbe668e210caf3ebb461e4f31_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v17 = (Event<OnMouseWheelMovedEvent> *)&this->butRestart->evClicked;
  LOBYTE(v35) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v17,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)h,
    *(void **)&h[24]);
  ksgui::Control::addControl(this, this->butRestart);
  v18 = (wchar_t *)operator new(448);
  iname._Bx._Ptr = v18;
  LOBYTE(v35) = 10;
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
  this->butSkip = v19;
  LOBYTE(v35) = 3;
  *(_DWORD *)&h[24] = 7;
  *(_DWORD *)&h[20] = 0;
  *(_WORD *)&h[4] = 0;
  std::wstring::assign((std::wstring *)&h[4], L"content/gui/raceControl/skip_icon", 0x21u);
  ksgui::ActiveButton::setMultipleTexture(this->butSkip, v7, *(std::wstring *)&h[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Skip Session", 0xCu);
  LOBYTE(v35) = 11;
  *(_DWORD *)&h[24] = acTranslate(&result, &iname);
  v20 = this->butSkip;
  LOBYTE(v35) = 12;
  v20->setText(v20, *(const std::wstring **)&h[24]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v35) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)this->butSkip, 130.0, 30.0);
  ((void (*)(ksgui::ActiveButton *, int, int))this->butSkip->setSize)(this->butSkip, 1109393408, 1109393408);
  v21 = this->butSkip;
  iname._Bx._Ptr = 0;
  *(_DWORD *)&h[24] = this;
  v22 = v21->rect.bottom - v21->rect.top;
  v21->textCoord.x = 0.0;
  *(float *)&iname._Bx._Alias[4] = v22;
  v21->textCoord.y = v22;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_bb64a4f5a6593c2e373304c99feec67e_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v23 = (Event<OnMouseWheelMovedEvent> *)&this->butSkip->evClicked;
  LOBYTE(v35) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v23,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)h,
    *(void **)&h[24]);
  ksgui::Control::addControl(this, this->butSkip);
  v24 = (wchar_t *)operator new(448);
  iname._Bx._Ptr = v24;
  LOBYTE(v35) = 14;
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
  this->butExit = v25;
  LOBYTE(v35) = 3;
  *(_DWORD *)&h[24] = 7;
  *(_DWORD *)&h[20] = 0;
  *(_WORD *)&h[4] = 0;
  std::wstring::assign((std::wstring *)&h[4], L"content/gui/raceControl/vote_no", 0x1Fu);
  ksgui::ActiveButton::setMultipleTexture(this->butExit, v7, *(std::wstring *)&h[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Exit", 4u);
  LOBYTE(v35) = 15;
  *(_DWORD *)&h[24] = acTranslate(&result, &iname);
  v26 = this->butExit;
  LOBYTE(v35) = 16;
  v26->setText(v26, *(const std::wstring **)&h[24]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v35) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)this->butExit, 215.0, 30.0);
  ((void (*)(ksgui::ActiveButton *, int, int))this->butExit->setSize)(this->butExit, 1109393408, 1109393408);
  v27 = this->butExit;
  iname._Bx._Ptr = 0;
  *(_DWORD *)&h[24] = this;
  v28 = v27->rect.bottom - v27->rect.top;
  v27->textCoord.x = 0.0;
  *(float *)&iname._Bx._Alias[4] = v28;
  v27->textCoord.y = v28;
  *(_DWORD *)h = &std::_Func_impl<std::_Callable_obj<_lambda_5db828d598263dcd7ad40b376cc6c615_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[4] = this;
  *(_DWORD *)&h[16] = h;
  v29 = (Event<OnMouseWheelMovedEvent> *)&this->butExit->evClicked;
  LOBYTE(v35) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v29,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)h,
    *(void **)&h[24]);
  ksgui::Control::addControl(this, this->butExit);
}
RaceControlSPSession *RaceControlSPSession::`vector deleting destructor'(RaceControlSPSession *this, unsigned int a2)
{
  std::_Ref_count_base *v3; // edi

  this->__vftable = (RaceControlSPSession_vtbl *)&RaceControlSPSession::`vftable';
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
void __userpurge RaceControlSPSession::render(RaceControlSPSession *this@<ecx>, int a2@<esi>, float dt)
{
  RaceControlSPSession_vtbl *v4; // eax
  Sim *v5; // eax
  GLRenderer *v6; // esi
  const std::wstring *v7; // eax
  Font *v8; // ecx
  __int64 v9; // [esp+1Ch] [ebp-5Ch]
  float v10; // [esp+24h] [ebp-54h]
  ksgui::ksRect wrect; // [esp+28h] [ebp-50h] BYREF
  std::wstring text; // [esp+38h] [ebp-40h] BYREF
  std::wstring result; // [esp+50h] [ebp-28h] BYREF
  int v14; // [esp+74h] [ebp-4h]

  ksgui::Control::render(this, (int)this, a2, dt, v9, v10);
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
  GLRenderer::color4f(v6, colTitleBar_8.x, colTitleBar_8.y, colTitleBar_8.z, colTitleBar_8.w);
  GLRenderer::quad(v6, wrect.left, wrect.top, this->rect.right - this->rect.left, 20.0, 0, 0);
  Font::setColor(this->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"SESSION CONTROL", 0xFu);
  v14 = 0;
  v7 = acTranslate(&result, &text);
  v8 = this->titleFont._Ptr;
  LOBYTE(v14) = 1;
  Font::blitString(v8, wrect.left + 10.0, wrect.top + 1.0, v7, 1.0, eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
}
