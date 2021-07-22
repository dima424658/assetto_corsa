#include "formdrszones.h
void FormDRSZones::FormDRSZones(FormDRSZones *this, CarAvatar *car)
{
  int v3; // ebx
  const std::wstring *v4; // eax
  ksgui::ConnectedLabel *v5; // ebp
  ksgui::ConnectedLabel *v6; // eax
  ksgui::ConnectedLabel *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  ksgui::ConnectedLabel *v13; // eax
  ksgui::Control *v14; // ebp
  ksgui::Control *v15; // eax
  ksgui::Control *v16; // ecx
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  ksgui::Label *v22; // ebp
  int v23; // eax
  int v24; // ecx
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  ksgui::Control *v30; // ebp
  ksgui::Control *v31; // eax
  ksgui::Control *v32; // ecx
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  _BYTE v38[28]; // [esp+14h] [ebp-88h] BYREF
  float h; // [esp+30h] [ebp-6Ch]
  int _Val; // [esp+50h] [ebp-4Ch] BYREF
  void *v41; // [esp+54h] [ebp-48h]
  FormDRSZones *v42; // [esp+58h] [ebp-44h]
  std::wstring text; // [esp+5Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+74h] [ebp-28h] BYREF
  int v45; // [esp+98h] [ebp-4h]

  v3 = 0;
  _Val = 0;
  h = 0.0;
  v42 = this;
  *(_DWORD *)&v38[24] = car->game->gui;
  *(_DWORD *)&v38[20] = 7;
  *(_DWORD *)&v38[16] = 0;
  *(_WORD *)v38 = 0;
  std::wstring::assign((std::wstring *)v38, L"DRS_ZONES", 9u);
  ksgui::Form::Form(this, 0, *(std::wstring *)v38, *(ksgui::GUI **)&v38[24], SLOBYTE(h));
  v45 = 0;
  this->__vftable = (FormDRSZones_vtbl *)&FormDRSZones::`vftable';
  this->car = car;
  this->currentZone.detection = 0.0;
  this->currentZone.start = 0.0;
  this->currentZone.end = 0.0;
  this->zones._Myfirst = 0;
  this->zones._Mylast = 0;
  this->zones._Myend = 0;
  LOBYTE(v45) = 1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"DRS Zones", 9u);
  LOBYTE(v45) = 2;
  v4 = acTranslate(&result, &text);
  LOBYTE(v45) = 3;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v45) = 1;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v5 = (ksgui::ConnectedLabel *)operator new(0x158u);
  v41 = v5;
  v6 = 0;
  LOBYTE(v45) = 4;
  if ( v5 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"NSP", 3u);
    v3 = 1;
    LOBYTE(v45) = 5;
    LODWORD(h) = &car->physicsState.normalizedSplinePosition;
    *(_DWORD *)&v38[24] = this->gui;
    _Val = 1;
    ksgui::ConnectedLabel::ConnectedLabel(
      v5,
      &text,
      *(ksgui::GUI **)&v38[24],
      &car->physicsState.normalizedSplinePosition);
  }
  this->lblNSP = v6;
  v45 = 1;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v7 = this->lblNSP;
  v8 = v7->rectBase.left;
  v9 = v7->rect.right - v7->rect.left;
  v10 = v7->rect.bottom - v7->rect.top;
  v7->rect.top = 40.0;
  v7->rect.left = 5.0;
  v11 = v9 + 5.0;
  v12 = v10 + 40.0;
  v7->rect.right = v11;
  v7->rect.bottom = v12;
  if ( v8 == 0.0 && v7->rectBase.top == 0.0 )
  {
    v7->rectBase.left = 5.0;
    v7->rectBase.top = 40.0;
    v7->rectBase.right = v11;
    v7->rectBase.bottom = v12;
  }
  ((void (*)(ksgui::ConnectedLabel *, int, int))this->lblNSP->setSize)(this->lblNSP, 1120403456, 1106247680);
  v13 = this->lblNSP;
  LODWORD(h) = &_Val;
  v13->fontScale = 2.0;
  _Val = (int)this->lblNSP;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)LODWORD(h));
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v14 = (ksgui::Control *)operator new(LODWORD(h));
  v41 = v14;
  v15 = 0;
  LOBYTE(v45) = 7;
  if ( v14 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"START_STOP", 0xAu);
    LOBYTE(v45) = 8;
    h = *(float *)&this->gui;
    v3 |= 2u;
    _Val = v3;
    ksgui::Control::Control(v14, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->butStartStopZone = v15;
  v45 = 1;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v16 = this->butStartStopZone;
  v17 = v16->rectBase.left;
  v18 = v16->rect.right - v16->rect.left;
  v19 = v16->rect.bottom - v16->rect.top;
  v16->rect.top = 100.0;
  v16->rect.left = 5.0;
  v20 = v18 + 5.0;
  v21 = v19 + 100.0;
  v16->rect.right = v20;
  v16->rect.bottom = v21;
  if ( v17 == 0.0 && v16->rectBase.top == 0.0 )
  {
    v16->rectBase.left = 5.0;
    v16->rectBase.top = 100.0;
    v16->rectBase.right = v20;
    v16->rectBase.bottom = v21;
  }
  ((void (*)(ksgui::Control *, int, int))this->butStartStopZone->setSize)(
    this->butStartStopZone,
    1127481344,
    1106247680);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Set Detection", 0xDu);
  LOBYTE(v45) = 10;
  this->butStartStopZone->setText(this->butStartStopZone, &text);
  LOBYTE(v45) = 1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  _Val = (int)this->butStartStopZone;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = this;
  *(_DWORD *)(_Val + 148) = this;
  this->recordingStatus = WaitEnd;
  *(_DWORD *)&v38[4] = &std::_Func_impl<std::_Callable_obj<_lambda_8eebe7c165de5fc64b7c94d40d00ef91_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v38[12] = car;
  *(_DWORD *)&v38[8] = this;
  *(_DWORD *)&v38[20] = &v38[4];
  LOBYTE(v45) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butStartStopZone->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v38[4],
    (void *)LODWORD(h));
  v22 = (ksgui::Label *)operator new(0x11Cu);
  v41 = v22;
  LOBYTE(v45) = 12;
  if ( v22 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v38[24] = 7;
    *(_DWORD *)&v38[20] = 0;
    *(_WORD *)&v38[4] = 0;
    std::wstring::assign((std::wstring *)&v38[4], L"ZONES", 5u);
    ksgui::Label::Label(v22, *(std::wstring *)&v38[4], (ksgui::GUI *)LODWORD(h));
    v24 = v23;
  }
  else
  {
    v24 = 0;
  }
  LOBYTE(v45) = 1;
  this->lblZones = (ksgui::Label *)v24;
  v25 = *(float *)(v24 + 264);
  v26 = *(float *)(v24 + 32) - *(float *)(v24 + 28);
  v27 = *(float *)(v24 + 40) - *(float *)(v24 + 36);
  *(_DWORD *)(v24 + 36) = 1124859904;
  *(_DWORD *)(v24 + 28) = 1128792064;
  v28 = v26 + 200.0;
  v29 = v27 + 140.0;
  *(float *)(v24 + 32) = v28;
  *(float *)(v24 + 40) = v29;
  if ( v25 == 0.0 && *(float *)(v24 + 272) == 0.0 )
  {
    *(_DWORD *)(v24 + 264) = 1128792064;
    *(_DWORD *)(v24 + 272) = 1124859904;
    *(float *)(v24 + 268) = v28;
    *(float *)(v24 + 276) = v29;
  }
  ((void (*)(ksgui::Label *, int, int))this->lblZones->setSize)(this->lblZones, 1120403456, 1133903872);
  this->lblZones->fontScale = 1.5;
  _Val = (int)this->lblZones;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v30 = (ksgui::Control *)operator new(LODWORD(h));
  v41 = v30;
  v31 = 0;
  LOBYTE(v45) = 13;
  if ( v30 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"SAVE", 4u);
    LOBYTE(v45) = 14;
    h = *(float *)&this->gui;
    v3 |= 4u;
    _Val = v3;
    ksgui::Control::Control(v30, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->butSave = v31;
  v45 = 1;
  if ( (v3 & 4) != 0 && text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v32 = this->butSave;
  v33 = v32->rectBase.left;
  v34 = v32->rect.right - v32->rect.left;
  v35 = v32->rect.bottom - v32->rect.top;
  v32->rect.top = 350.0;
  v32->rect.left = 5.0;
  v36 = v34 + 5.0;
  v37 = v35 + 350.0;
  v32->rect.right = v36;
  v32->rect.bottom = v37;
  if ( v33 == 0.0 && v32->rectBase.top == 0.0 )
  {
    v32->rectBase.left = 5.0;
    v32->rectBase.top = 350.0;
    v32->rectBase.right = v36;
    v32->rectBase.bottom = v37;
  }
  ((void (*)(ksgui::Control *, int, int))this->butSave->setSize)(this->butSave, 1120403456, 1106247680);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Save", 4u);
  LOBYTE(v45) = 16;
  this->butSave->setText(this->butSave, &text);
  LOBYTE(v45) = 1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  _Val = (int)this->butSave;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = this;
  *(_DWORD *)(_Val + 148) = this;
  *(_DWORD *)&v38[4] = &std::_Func_impl<std::_Callable_obj<_lambda_36b96abbd1bbe9f0ee8b621eafae0e15_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v38[12] = car;
  *(_DWORD *)&v38[8] = this;
  *(_DWORD *)&v38[20] = &v38[4];
  LOBYTE(v45) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSave->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v38[4],
    (void *)LODWORD(h));
  ksgui::Form::setSize(this, 400.0, 400.0);
}
FormDRSZones *FormDRSZones::`scalar deleting destructor'(FormDRSZones *this, unsigned int a2)
{
  this->__vftable = (FormDRSZones_vtbl *)&FormDRSZones::`vftable';
  if ( this->zones._Myfirst )
  {
    operator delete(this->zones._Myfirst);
    this->zones._Myfirst = 0;
    this->zones._Mylast = 0;
    this->zones._Myend = 0;
  }
  this->__vftable = (FormDRSZones_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FormDRSZones::render(FormDRSZones *this, float dt)
{
  FormDRSZones *v2; // esi
  int v3; // edi
  int v4; // edx
  int v5; // ecx
  const char *v6; // ecx
  DRSZone *v7; // edi
  DRSZone *v8; // esi
  int i; // ebx
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  const std::wstring *v18; // eax
  const char *v19; // [esp+4h] [ebp-124h]
  char *_Val; // [esp+1Ch] [ebp-10Ch]
  const char *v21; // [esp+24h] [ebp-104h]
  __int64 v22; // [esp+2Ch] [ebp-FCh]
  float v23; // [esp+34h] [ebp-F4h]
  int v25; // [esp+44h] [ebp-E4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v26; // [esp+48h] [ebp-E0h] BYREF
  std::wstring result; // [esp+F8h] [ebp-30h] BYREF
  int v28; // [esp+124h] [ebp-4h]

  v2 = this;
  *(_DWORD *)v26.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v26.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v26.gap68);
  v28 = 0;
  v25 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v26, &v26.gap10[8], 0);
  v28 = 1;
  *(_DWORD *)&v26.gap0[*(_DWORD *)(*(_DWORD *)v26.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v25 + *(_DWORD *)(*(_DWORD *)v26.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v26.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v26.gap10[8]);
  *(_DWORD *)&v26.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v26.gap10[64] = 0;
  *(_DWORD *)&v26.gap10[68] = 0;
  v28 = 3;
  v3 = std::setprecision(&result, 3, 0);
  v4 = std::wostream::operator<<(v26.gap10, std::fixed);
  if ( v4 )
    v5 = v4 + *(_DWORD *)(*(_DWORD *)v4 + 4);
  else
    v5 = 0;
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v3)(v5, *(_DWORD *)(v3 + 8), *(_DWORD *)(v3 + 12));
  v7 = v2->zones._Mylast;
  v8 = v2->zones._Myfirst;
  for ( i = 0; v8 != v7; ++i )
  {
    v21 = v6;
    _Val = (char *)LODWORD(v8->end);
    v10 = (std::wostream *)std::wostream::operator<<(v26.gap10, i);
    v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v10, v19);
    v12 = (std::wostream *)std::wostream::operator<<(v11);
    v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v12, _Val);
    v14 = (std::wostream *)std::wostream::operator<<(v13);
    v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v14, ")");
    v16 = (std::wostream *)std::wostream::operator<<(v15);
    v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v16, v21);
    std::wostream::operator<<(v17);
    ++v8;
  }
  v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v26, &result);
  LOBYTE(v28) = 4;
  this->lblZones->setText(this->lblZones, v18);
  LOBYTE(v28) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  ksgui::Control::render(this, (int)this, (int)operator delete, dt, v22, v23);
  v28 = -1;
  *(_DWORD *)&v26.gap0[*(_DWORD *)(*(_DWORD *)v26.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v25 + *(_DWORD *)(*(_DWORD *)v26.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v26.gap0 + 4) - 104;
  *(_DWORD *)&v26.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v26.gap10[68] & 1) != 0 )
    operator delete(**(void ***)&v26.gap10[20]);
  std::wstreambuf::setg(&v26.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v26.gap10[8], 0, 0);
  *(_DWORD *)&v26.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v26.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v26.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v26.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v26.gap68);
}
