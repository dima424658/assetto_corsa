#include "endsessioncommongui.h
void __userpurge EndSessionCommonGui::EndSessionCommonGui(EndSessionCommonGui *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  Game *v4; // eax
  const __m128i *v5; // eax
  bool v6; // cf
  ksgui::GUI *v7; // eax
  Texture *v8; // eax
  ksgui::ActiveButton *v9; // edi
  ksgui::ActiveButton *v10; // eax
  Event<OnMouseWheelMovedEvent> *v11; // ecx
  std::wstring *v12; // eax
  ksgui::ActiveButton *v13; // ecx
  ksgui::ActiveButton *v14; // ecx
  ksgui::ActiveButton *v15; // edi
  ksgui::ActiveButton *v16; // eax
  Event<OnMouseWheelMovedEvent> *v17; // ecx
  std::wstring *v18; // eax
  ksgui::ActiveButton *v19; // ecx
  ksgui::ActiveButton *v20; // ecx
  ksgui::ActiveButton *v21; // edi
  ksgui::ActiveButton *v22; // eax
  Event<OnMouseWheelMovedEvent> *v23; // ecx
  std::wstring *v24; // eax
  ksgui::ActiveButton *v25; // ecx
  ksgui::ActiveButton *v26; // ecx
  Font *v27; // eax
  Font *v28; // eax
  volatile signed __int32 *v29; // edi
  _BYTE v30[56]; // [esp+14h] [ebp-F0h] BYREF
  vec4f result; // [esp+4Ch] [ebp-B8h] BYREF
  ksgui::ActiveButton *v32; // [esp+5Ch] [ebp-A8h]
  EndSessionCommonGui *v33; // [esp+60h] [ebp-A4h]
  std::wstring key; // [esp+64h] [ebp-A0h] BYREF
  Texture iname; // [esp+7Ch] [ebp-88h] BYREF
  std::wstring ifilename; // [esp+98h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+B0h] [ebp-54h] BYREF
  int v38; // [esp+100h] [ebp-4h]

  v33 = this;
  iname.fileName._Mysize = 7;
  *(_DWORD *)&iname.fileName._Bx._Alias[12] = 0;
  LOWORD(iname.kid) = 0;
  std::wstring::assign((std::wstring *)&iname, L"END_SESSION_COMMON_GUI", 0x16u);
  v4 = aSim->game;
  v38 = 0;
  ksgui::Control::Control(this, (const std::wstring *)&iname, v4->gui);
  if ( iname.fileName._Mysize >= 8 )
    operator delete(iname.kid);
  this->__vftable = (EndSessionCommonGui_vtbl *)&EndSessionCommonGui::`vftable';
  this->btExit = 0;
  this->btRestart = 0;
  this->btReplay = 0;
  this->texLogo.kid = 0;
  this->texLogo.fileName._Myres = 7;
  this->texLogo.fileName._Mysize = 0;
  this->texLogo.fileName._Bx._Buf[0] = 0;
  *(_DWORD *)&v30[24] = 34;
  *(_DWORD *)&v30[20] = L"system/cfg/endSessionDisplayer.ini";
  LOBYTE(v38) = 3;
  this->sim = aSim;
  *(_WORD *)&this->drawBorder = 0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, *(const wchar_t **)&v30[20], *(unsigned int *)&v30[24]);
  LOBYTE(v38) = 4;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v38) = 6;
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
    std::wstring::assign(&key, L"COLOR", 5u);
    LOBYTE(v38) = 7;
    iname.fileName._Mysize = 7;
    *(_DWORD *)&iname.fileName._Bx._Alias[12] = 0;
    LOWORD(iname.kid) = 0;
    std::wstring::assign((std::wstring *)&iname, L"BACKGROUND", 0xAu);
    LOBYTE(v38) = 8;
    v5 = (const __m128i *)INIReader::getFloat4(&ini, &result, (const std::wstring *)&iname, &key);
    v6 = iname.fileName._Mysize < 8;
    this->backColor = (vec4f)_mm_loadu_si128(v5);
    if ( !v6 )
      operator delete(iname.kid);
    iname.fileName._Mysize = 7;
    *(_DWORD *)&iname.fileName._Bx._Alias[12] = 0;
    LOWORD(iname.kid) = 0;
    LOBYTE(v38) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/endRace/logo.png", 0x1Cu);
  v7 = this->gui;
  LOBYTE(v38) = 9;
  v8 = ResourceStore::getTexture(v7->graphics->resourceStore._Myptr, &iname, &key, 0);
  this->texLogo.kid = v8->kid;
  LOBYTE(v38) = 10;
  if ( &this->texLogo.fileName != &v8->fileName )
    std::wstring::assign(&this->texLogo.fileName, &v8->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v38) = 9;
  OnSetupAppCreated::~OnSetupAppCreated(&iname);
  LOBYTE(v38) = 6;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v9 = (ksgui::ActiveButton *)operator new(448);
  v32 = v9;
  v10 = 0;
  LOBYTE(v38) = 11;
  if ( v9 )
  {
    *(_DWORD *)&v30[24] = this->gui;
    *(_DWORD *)&v30[20] = 7;
    *(_DWORD *)&v30[16] = 0;
    *(_WORD *)v30 = 0;
    std::wstring::assign((std::wstring *)v30, L"BUTTON_DISMISS", 0xEu);
    ksgui::ActiveButton::ActiveButton(v9, *(std::wstring *)v30, *(ksgui::GUI **)&v30[24]);
  }
  *(_DWORD *)&v30[24] = this;
  this->btExit = v10;
  *(_DWORD *)v30 = &std::_Func_impl<std::_Callable_obj<_lambda_9216b871f6ebe026d154ffac66e6a9b6_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v30[4] = this;
  *(_DWORD *)&v30[16] = v30;
  v11 = (Event<OnMouseWheelMovedEvent> *)&this->btExit->evClicked;
  LOBYTE(v38) = 6;
  Event<ksgui::OnControlClicked>::addHandler(
    v11,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v30,
    *(void **)&v30[24]);
  this->btExit->backColor = (vec4f)_xmm;
  *(_DWORD *)&v30[24] = 7;
  *(_DWORD *)&v30[20] = 0;
  *(_WORD *)&v30[4] = 0;
  std::wstring::assign((std::wstring *)&v30[4], L"content/gui/endRace/exit_icon", 0x1Du);
  ksgui::ActiveButton::setMultipleTexture(this->btExit, a2, *(std::wstring *)&v30[4]);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btExit->setSize)(this->btExit, 1114636288, 1114636288);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"Exit", 4u);
  LOBYTE(v38) = 13;
  v12 = acTranslate((std::wstring *)&iname, &key);
  v13 = this->btExit;
  LOBYTE(v38) = 14;
  v13->setText(v13, v12);
  if ( iname.fileName._Mysize >= 8 )
    operator delete(iname.kid);
  iname.fileName._Mysize = 7;
  *(_DWORD *)&iname.fileName._Bx._Alias[12] = 0;
  LOWORD(iname.kid) = 0;
  LOBYTE(v38) = 6;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v14 = this->btExit;
  result.x = 0.0;
  result.y = 54.0;
  v14->textCoord.x = 0.0;
  v14->textCoord.y = result.y;
  this->btExit->font._Ptr->scale = this->fontScale;
  ksgui::Control::addControl(this, this->btExit);
  v15 = (ksgui::ActiveButton *)operator new(448);
  LODWORD(result.x) = v15;
  v16 = 0;
  LOBYTE(v38) = 15;
  if ( v15 )
  {
    *(_DWORD *)&v30[24] = this->gui;
    *(_DWORD *)&v30[20] = 7;
    *(_DWORD *)&v30[16] = 0;
    *(_WORD *)v30 = 0;
    std::wstring::assign((std::wstring *)v30, L"BUTTON_RESTART", 0xEu);
    ksgui::ActiveButton::ActiveButton(v15, *(std::wstring *)v30, *(ksgui::GUI **)&v30[24]);
  }
  *(_DWORD *)&v30[24] = this;
  this->btRestart = v16;
  *(_DWORD *)v30 = &std::_Func_impl<std::_Callable_obj<_lambda_9fa069ca4c935e03ed90bd0e5106169c_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v30[4] = this;
  *(_DWORD *)&v30[16] = v30;
  v17 = (Event<OnMouseWheelMovedEvent> *)&this->btRestart->evClicked;
  LOBYTE(v38) = 6;
  Event<ksgui::OnControlClicked>::addHandler(
    v17,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v30,
    *(void **)&v30[24]);
  this->btRestart->backColor = (vec4f)_xmm;
  *(_DWORD *)&v30[24] = 7;
  *(_DWORD *)&v30[20] = 0;
  *(_WORD *)&v30[4] = 0;
  std::wstring::assign((std::wstring *)&v30[4], L"content/gui/endRace/restart_icon", 0x20u);
  ksgui::ActiveButton::setMultipleTexture(this->btRestart, a2, *(std::wstring *)&v30[4]);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btRestart->setSize)(
    this->btRestart,
    1114636288,
    1114636288);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"Restart", 7u);
  LOBYTE(v38) = 17;
  v18 = acTranslate((std::wstring *)&iname, &key);
  v19 = this->btRestart;
  LOBYTE(v38) = 18;
  v19->setText(v19, v18);
  if ( iname.fileName._Mysize >= 8 )
    operator delete(iname.kid);
  iname.fileName._Mysize = 7;
  *(_DWORD *)&iname.fileName._Bx._Alias[12] = 0;
  LOWORD(iname.kid) = 0;
  LOBYTE(v38) = 6;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v20 = this->btRestart;
  result.x = 0.0;
  result.y = 54.0;
  v20->textCoord.x = 0.0;
  v20->textCoord.y = result.y;
  this->btRestart->font._Ptr->scale = this->fontScale;
  ksgui::Control::addControl(this, this->btRestart);
  v21 = (ksgui::ActiveButton *)operator new(448);
  LODWORD(result.x) = v21;
  v22 = 0;
  LOBYTE(v38) = 19;
  if ( v21 )
  {
    *(_DWORD *)&v30[24] = this->gui;
    *(_DWORD *)&v30[20] = 7;
    *(_DWORD *)&v30[16] = 0;
    *(_WORD *)v30 = 0;
    std::wstring::assign((std::wstring *)v30, L"BUTTON_REPLAY", 0xDu);
    ksgui::ActiveButton::ActiveButton(v21, *(std::wstring *)v30, *(ksgui::GUI **)&v30[24]);
  }
  *(_DWORD *)&v30[24] = this;
  this->btReplay = v22;
  *(_DWORD *)v30 = &std::_Func_impl<std::_Callable_obj<_lambda_00832c31ead37c65a63507055cb66a4c_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v30[4] = this;
  *(_DWORD *)&v30[16] = v30;
  v23 = (Event<OnMouseWheelMovedEvent> *)&this->btReplay->evClicked;
  LOBYTE(v38) = 6;
  Event<ksgui::OnControlClicked>::addHandler(
    v23,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v30,
    *(void **)&v30[24]);
  this->btReplay->backColor = (vec4f)_xmm;
  *(_DWORD *)&v30[24] = 7;
  *(_DWORD *)&v30[20] = 0;
  *(_WORD *)&v30[4] = 0;
  std::wstring::assign((std::wstring *)&v30[4], L"content/gui/endRace/replay", 0x1Au);
  ksgui::ActiveButton::setMultipleTexture(this->btReplay, a2, *(std::wstring *)&v30[4]);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btReplay->setSize)(
    this->btReplay,
    1114636288,
    1114636288);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"Replay", 6u);
  LOBYTE(v38) = 21;
  v24 = acTranslate((std::wstring *)&iname, &key);
  v25 = this->btReplay;
  LOBYTE(v38) = 22;
  v25->setText(v25, v24);
  if ( iname.fileName._Mysize >= 8 )
    operator delete(iname.kid);
  iname.fileName._Mysize = 7;
  *(_DWORD *)&iname.fileName._Bx._Alias[12] = 0;
  LOWORD(iname.kid) = 0;
  LOBYTE(v38) = 6;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v26 = this->btReplay;
  result.x = 0.0;
  result.y = 54.0;
  v26->textCoord.x = 0.0;
  v26->textCoord.y = result.y;
  this->btReplay->font._Ptr->scale = this->fontScale;
  ksgui::Control::addControl(this, this->btReplay);
  v27 = (Font *)operator new(24);
  LODWORD(result.x) = v27;
  LOBYTE(v38) = 23;
  if ( v27 )
    Font::Font(v27, eFontMonospaced, 14.0, 1, 1);
  else
    v28 = 0;
  LOBYTE(v38) = 6;
  result.x = 0.0;
  result.y = 0.0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&result, v28);
  std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&result);
  v29 = (volatile signed __int32 *)LODWORD(result.y);
  if ( LODWORD(result.y) )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(result.y) + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v29)(v29);
      if ( !_InterlockedDecrement(v29 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v29 + 4))(v29);
    }
  }
  LOBYTE(v38) = 3;
  INIReader::~INIReader(&ini);
}
EndSessionCommonGui *EndSessionCommonGui::`vector deleting destructor'(EndSessionCommonGui *this, unsigned int a2)
{
  this->__vftable = (EndSessionCommonGui_vtbl *)&EndSessionCommonGui::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->texLogo);
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void EndSessionCommonGui::render(EndSessionCommonGui *this, float dt)
{
  GLRenderer *v3; // ebx
  Texture *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // ecx
  float v8; // xmm0_4
  float width; // xmm0_4
  Font *v10; // ecx
  float x; // [esp+0h] [ebp-68h]
  float height; // [esp+Ch] [ebp-5Ch]
  __int64 v13; // [esp+18h] [ebp-50h]
  float v14; // [esp+20h] [ebp-48h]
  unsigned int top; // [esp+2Ch] [ebp-3Ch]
  float topa; // [esp+2Ch] [ebp-3Ch]
  float topb; // [esp+2Ch] [ebp-3Ch]
  vec4f cc; // [esp+30h] [ebp-38h] BYREF
  std::wstring s; // [esp+40h] [ebp-28h] BYREF
  int v20; // [esp+64h] [ebp-4h]

  GraphicsManager::setDepthMode(this->gui->graphics, eDepthOff);
  v3 = this->gui->graphics->gl;
  GLRenderer::color4f(v3, &this->backColor);
  GLRenderer::quad(
    v3,
    0.0,
    0.0,
    (float)this->gui->graphics->videoSettings.width,
    (float)this->gui->graphics->videoSettings.height,
    0,
    0);
  GLRenderer::color4f(v3, 1.0, 1.0, 1.0, 1.0);
  v4 = &this->texLogo;
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->texLogo);
  if ( this->texLogo.kid )
    v5 = kglTextureGetHeight(v4->kid);
  else
    v5 = 0;
  top = v5;
  if ( v4->kid )
    v6 = kglTextureGetWidth(v4->kid);
  else
    v6 = 0;
  if ( v4->kid )
    v7 = kglTextureGetWidth(v4->kid);
  else
    v7 = 0;
  v8 = (float)top;
  height = v8;
  width = (float)v6;
  x = (float)(this->gui->graphics->videoSettings.width / 2 - (v7 >> 1));
  GLRenderer::quad(v3, x, 50.0, width, height, 1, 0);
  topa = (float)(this->gui->graphics->videoSettings.height - 150);
  GLRenderer::color4f(v3, &colTitleBar_2);
  GLRenderer::quad(v3, (float)(this->gui->graphics->videoSettings.width / 2) - 250.0, topa, 500.0, 20.0, 0, 0);
  v10 = this->font._Ptr;
  cc = (vec4f)_xmm;
  Font::setColor(v10, &cc);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  std::wstring::assign(&s, L"SELECT", 6u);
  v20 = 0;
  Font::blitString(
    this->font._Ptr,
    (float)(this->gui->graphics->videoSettings.width / 2 + 10) - 250.0,
    topa,
    &s,
    1.0,
    eAlignLeft);
  v20 = -1;
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  GLRenderer::color4f(v3, &colDarkTransp_1);
  GLRenderer::quad(v3, (float)(this->gui->graphics->videoSettings.width / 2) - 250.0, topa + 20.0, 500.0, 80.0, 0, 0);
  topb = (float)(topa + 5.0) + 20.0;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->btRestart,
    (float)((float)(this->gui->graphics->videoSettings.width / 2) - 250.0) + 50.0,
    topb);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->btReplay,
    (float)(this->gui->graphics->videoSettings.width / 2)
  - (float)((float)(this->btReplay->rect.right - this->btReplay->rect.left) * 0.5),
    topb);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->btExit,
    (float)((float)((float)(this->gui->graphics->videoSettings.width / 2) + 250.0) - 50.0) - 60.0,
    topb);
  ksgui::Control::render(this, (int)v4, (int)this, dt, v13, v14);
}
