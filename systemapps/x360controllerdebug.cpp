#include "x360controllerdebug.h
void X360ControllerDebug::X360ControllerDebug(X360ControllerDebug *this, Sim *aSim)
{
  char v3; // bl
  const std::wstring *v4; // eax
  Sim *v5; // ecx
  CarAvatar *v6; // eax
  ICarControlsProvider *v7; // eax
  Event<OnMouseWheelMovedEvent> **v8; // eax
  Event<OnMouseWheelMovedEvent> *v9; // ebp
  Event<OnMouseWheelMovedEvent> **v10; // eax
  Event<OnMouseWheelMovedEvent> *v11; // ebp
  Event<OnMouseWheelMovedEvent> **v12; // eax
  Event<OnMouseWheelMovedEvent> *v13; // ebp
  Event<OnMouseWheelMovedEvent> **v14; // eax
  Event<OnMouseWheelMovedEvent> *v15; // ebp
  Event<OnMouseWheelMovedEvent> **v16; // eax
  Event<OnMouseWheelMovedEvent> *v17; // ebp
  ksgui::Control *v18; // ebp
  ksgui::Control *v19; // eax
  ksgui::Control *v20; // ecx
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  const std::wstring *v27; // eax
  _BYTE v28[72]; // [esp-14h] [ebp-B4h] BYREF
  int _Val[2]; // [esp+4Ch] [ebp-54h] BYREF
  LRControl v30; // [esp+54h] [ebp-4Ch] BYREF
  X360ControllerDebug *v31; // [esp+5Ch] [ebp-44h]
  std::wstring text; // [esp+60h] [ebp-40h] BYREF
  std::wstring result; // [esp+78h] [ebp-28h] BYREF
  int v34; // [esp+9Ch] [ebp-4h]

  v3 = 0;
  _Val[0] = 0;
  *(_DWORD *)&v28[28] = 0;
  v31 = this;
  *(_DWORD *)&v28[24] = aSim->game->gui;
  *(_DWORD *)&v28[20] = 7;
  *(_DWORD *)&v28[16] = 0;
  *(_WORD *)v28 = 0;
  std::wstring::assign((std::wstring *)v28, L"X360_CONTROL_DEBUG", 0x12u);
  ksgui::Form::Form(this, 0, *(std::wstring *)v28, *(ksgui::GUI **)&v28[24], v28[28]);
  v34 = 0;
  *(_DWORD *)&v28[28] = 21;
  this->__vftable = (X360ControllerDebug_vtbl *)&X360ControllerDebug::`vftable';
  *(_DWORD *)&v28[24] = L"X360 Controller debug";
  this->btSave = 0;
  this->sim = aSim;
  this->y = 0.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v28[24], *(unsigned int *)&v28[28]);
  LOBYTE(v34) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v34) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v34) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v5 = this->sim;
  *(_DWORD *)&v28[28] = 0;
  *(_DWORD *)&v28[24] = &JoypadCarControl `RTTI Type Descriptor';
  *(_DWORD *)&v28[20] = &ICarControlsProvider `RTTI Type Descriptor';
  *(_DWORD *)&v28[16] = 0;
  v6 = Sim::getCar(v5, 0);
  v7 = CarAvatar::getControlsProvider(v6);
  this->control = (JoypadCarControl *)__RTDynamicCast(
                                        v7,
                                        *(_DWORD *)&v28[16],
                                        *(_DWORD *)&v28[20],
                                        *(_DWORD *)&v28[24],
                                        *(_DWORD *)&v28[28]);
  ksgui::Form::setSize(this, 400.0, 300.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Speed Sens", 0xAu);
  LOBYTE(v34) = 3;
  acTranslate((std::wstring *)&v28[8], &text);
  LRControl::LRControl(
    &v30,
    50.0,
    *(float *)&this,
    (ksgui::Form *)this->gui,
    *(ksgui::GUI **)&v28[8],
    *(std::wstring *)&v28[12]);
  v9 = *v8;
  _Val[0] = (int)v8[1];
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Bx._Buf[0] = 0;
  text._Mysize = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_98220cafbee913606fc4bde590cfa739_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  LOBYTE(v34) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    v9 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  LOBYTE(v34) = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_a84bcb22ee10e9bbce22242679299d57_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(_Val[0] + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Steer Gamma", 0xBu);
  LOBYTE(v34) = 6;
  acTranslate((std::wstring *)&v28[8], &text);
  LRControl::LRControl(
    &v30,
    100.0,
    *(float *)&this,
    (ksgui::Form *)this->gui,
    *(ksgui::GUI **)&v28[8],
    *(std::wstring *)&v28[12]);
  v11 = *v10;
  _Val[0] = (int)v10[1];
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Bx._Buf[0] = 0;
  text._Mysize = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_52055b6f4e241360b657225286273105_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  LOBYTE(v34) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    v11 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  LOBYTE(v34) = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_8ebbb66c72c7ac4920a8586e73162044_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(_Val[0] + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Steer Filter", 0xCu);
  LOBYTE(v34) = 9;
  acTranslate((std::wstring *)&v28[8], &text);
  LRControl::LRControl(
    &v30,
    150.0,
    *(float *)&this,
    (ksgui::Form *)this->gui,
    *(ksgui::GUI **)&v28[8],
    *(std::wstring *)&v28[12]);
  v13 = *v12;
  _Val[0] = (int)v12[1];
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Bx._Buf[0] = 0;
  text._Mysize = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_6528f4e37745e0aee3de60926cde79d1_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  LOBYTE(v34) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    v13 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  LOBYTE(v34) = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_5968cb409d3d62bddbe9dac2128ff060_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(_Val[0] + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Deadzone", 8u);
  LOBYTE(v34) = 12;
  acTranslate((std::wstring *)&v28[8], &text);
  LRControl::LRControl(
    &v30,
    200.0,
    *(float *)&this,
    (ksgui::Form *)this->gui,
    *(ksgui::GUI **)&v28[8],
    *(std::wstring *)&v28[12]);
  v15 = *v14;
  _Val[0] = (int)v14[1];
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Bx._Buf[0] = 0;
  text._Mysize = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_3abf7af9598375885462e215404b46cd_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  LOBYTE(v34) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    v15 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  LOBYTE(v34) = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_e1d5dd795cb6585517a0fa44915a6e4b_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(_Val[0] + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Speed", 5u);
  LOBYTE(v34) = 15;
  acTranslate((std::wstring *)&v28[8], &text);
  LRControl::LRControl(
    &v30,
    250.0,
    *(float *)&this,
    (ksgui::Form *)this->gui,
    *(ksgui::GUI **)&v28[8],
    *(std::wstring *)&v28[12]);
  v17 = *v16;
  _Val[0] = (int)v16[1];
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Bx._Buf[0] = 0;
  text._Mysize = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_e410a5bc041dca31110f839e4a8bbc01_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  LOBYTE(v34) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    v17 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  LOBYTE(v34) = 0;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_e380350773b66068748caadca2c767c0_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(_Val[0] + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    this);
  v18 = (ksgui::Control *)operator new(0x118u);
  _Val[1] = (int)v18;
  LOBYTE(v34) = 18;
  if ( v18 )
  {
    std::wstring::wstring(&result, L"SAVE_CFG");
    LOBYTE(v34) = 19;
    *(_DWORD *)&v28[28] = this->gui;
    v3 = 1;
    _Val[0] = 1;
    ksgui::Control::Control(v18, &result, *(ksgui::GUI **)&v28[28]);
  }
  else
  {
    v19 = 0;
  }
  this->btSave = v19;
  v34 = 0;
  if ( (v3 & 1) != 0 && result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, int))this->btSave->setSize)(this->btSave, 1120403456, 1112014848);
  v20 = this->btSave;
  v21 = v20->rect.right - v20->rect.left;
  v22 = v20->rect.bottom - v20->rect.top;
  v23 = (float)(this->rect.bottom - this->rect.top) - v22;
  v20->rect.left = 20.0;
  v24 = v20->rectBase.left;
  v25 = v21 + 20.0;
  v26 = v22 + v23;
  v20->rect.top = v23;
  v20->rect.right = v25;
  v20->rect.bottom = v26;
  if ( v24 == 0.0 && v20->rectBase.top == 0.0 )
  {
    v20->rectBase.left = 20.0;
    v20->rectBase.top = v23;
    v20->rectBase.right = v25;
    v20->rectBase.bottom = v26;
  }
  _Val[0] = (int)this->btSave;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, _Val);
  *(_DWORD *)&v28[28] = this;
  *(_DWORD *)(_Val[0] + 148) = this;
  *(_DWORD *)&v28[4] = &std::_Func_impl<std::_Callable_obj<_lambda_8671f82e2ada3d6acae5515f607dea29_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v28[8] = this;
  *(_DWORD *)&v28[20] = &v28[4];
  LOBYTE(v34) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->btSave->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v28[4],
    *(void **)&v28[28]);
  std::wstring::wstring(&text, L"Save");
  LOBYTE(v34) = 22;
  v27 = acTranslate(&result, &text);
  LOBYTE(v34) = 23;
  this->btSave->setText(this->btSave, v27);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
}
void __userpurge X360ControllerDebug::printStringList(X360ControllerDebug *this@<ecx>, int a2@<xmm1>, int a3@<xmm2>, std::wstring name, vec4f color)
{
  int v8; // ecx
  X360ControllerDebug_vtbl *v9; // eax
  float v10; // xmm0_4
  std::wstring *v11; // esi
  std::wstring *v12; // eax
  const std::wstring *v13; // eax
  int v14; // eax
  int v15[4]; // [esp+3Ch] [ebp-120h] BYREF
  vec2f pos; // [esp+4Ch] [ebp-110h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v17; // [esp+54h] [ebp-108h] BYREF
  std::wstring v18; // [esp+104h] [ebp-58h] BYREF
  std::wstring v19; // [esp+11Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+134h] [ebp-28h] BYREF
  int v21; // [esp+158h] [ebp-4h]

  v15[2] = a3;
  v15[0] = a2;
  v21 = 0;
  *(_DWORD *)v17.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v17.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v17.gap68);
  LOBYTE(v21) = 1;
  v15[3] = 1;
  std::wiostream::basic_iostream<wchar_t>(&v17, &v17.gap10[8], 0);
  v21 = 2;
  *(_DWORD *)&v17.gap0[*(_DWORD *)(*(_DWORD *)v17.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.y + *(_DWORD *)(*(_DWORD *)v17.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v17.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v17.gap10[8]);
  *(_DWORD *)&v17.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v17.gap10[64] = 0;
  *(_DWORD *)&v17.gap10[68] = 0;
  LOBYTE(v21) = 4;
  __libm_sse2_powf(v8);
  std::wostream::operator<<(v17.gap10);
  v9 = this->__vftable;
  v10 = this->y;
  v15[0] = 0;
  *(float *)&v15[1] = v10;
  v9->localToWorld(this, &pos, (const vec2f *)v15);
  Font::setColor(this->gui->ksgui::Form::ksgui::Control::font._Ptr, &color);
  v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v17, &result);
  LOBYTE(v21) = 5;
  v12 = std::operator+<wchar_t>(&v18, &name, L" : ");
  LOBYTE(v21) = 6;
  v13 = std::operator+<wchar_t>(&v19, v12, v11);
  LOBYTE(v21) = 7;
  Font::blitString(this->gui->ksgui::Form::ksgui::Control::font._Ptr, pos.x, pos.y, v13, 1.0, eAlignLeft);
  if ( v19._Myres >= 8 )
    operator delete(v19._Bx._Ptr);
  v19._Myres = 7;
  v19._Mysize = 0;
  v19._Bx._Buf[0] = 0;
  if ( v18._Myres >= 8 )
    operator delete(v18._Bx._Ptr);
  v18._Myres = 7;
  v18._Mysize = 0;
  v18._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v14 = *(_DWORD *)v17.gap0;
  this->y = this->y + 20.0;
  *(_DWORD *)&v17.gap0[*(_DWORD *)(v14 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.y + *(_DWORD *)(*(_DWORD *)v17.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v17.gap0 + 4) - 104;
  *(_DWORD *)&v17.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v17.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v17.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v17.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v17.gap68);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void __userpurge X360ControllerDebug::render(X360ControllerDebug *this@<ecx>, int a2@<esi>, float dt)
{
  bool v4; // zf
  std::wstring v5; // [esp-24h] [ebp-7Ch] BYREF
  vec4f v6; // [esp-Ch] [ebp-64h]
  __int64 v7; // [esp+4h] [ebp-54h]
  float v8; // [esp+Ch] [ebp-4Ch]
  std::wstring text; // [esp+14h] [ebp-44h] BYREF
  std::wstring v10; // [esp+2Ch] [ebp-2Ch] BYREF
  int v11; // [esp+54h] [ebp-4h]

  ksgui::Control::render(this, (int)this, a2, dt, v7, v8);
  v4 = this->control == 0;
  this->y = 35.0;
  if ( !v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"RAW", 3u);
    v11 = 0;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &text);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->lastRaw), SLODWORD(FLOAT_4_0), v5, v6);
    v11 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Filtered", 8u);
    v11 = 1;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &text);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->lastNormalized), SLODWORD(FLOAT_4_0), v5, v6);
    v11 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"% of steer", 0xAu);
    v11 = 2;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &text);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->lastMaxSteer), SLODWORD(FLOAT_4_0), v5, v6);
    v11 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Steering Speed", 0xEu);
    v11 = 3;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &text);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->steerSpeed), SLODWORD(FLOAT_4_0), v5, v6);
    v11 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DeadZone", 8u);
    v11 = 4;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &text);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->deadZone), SLODWORD(FLOAT_4_0), v5, v6);
    v11 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Steer Filter", 0xCu);
    v11 = 5;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &text);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->steerFilter), SLODWORD(FLOAT_4_0), v5, v6);
    v11 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Steer Gamma", 0xBu);
    v11 = 6;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &text);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->steerGamma), SLODWORD(FLOAT_4_0), v5, v6);
    v11 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
    std::wstring::assign(&v10, L"Speed Sens.", 0xBu);
    v11 = 7;
    v6 = (vec4f)_xmm;
    acTranslate(&v5, &v10);
    X360ControllerDebug::printStringList(this, LODWORD(this->control->speedSensitivity), SLODWORD(FLOAT_4_0), v5, v6);
    if ( v10._Myres >= 8 )
      operator delete(v10._Bx._Ptr);
  }
}
