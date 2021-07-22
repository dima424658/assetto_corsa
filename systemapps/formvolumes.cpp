#include "formvolumes.h
void FormVolumes::FormVolumes(FormVolumes *this, Sim *aSim)
{
  int v3; // ebx
  Font *v4; // eax
  Font *v5; // eax
  ksgui::Spinner *v6; // eax
  ksgui::Spinner *v7; // eax
  ksgui::Spinner *v8; // eax
  ksgui::Spinner *v9; // eax
  ksgui::Label *v10; // esi
  float v11; // eax
  float v12; // esi
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v13; // edx
  CarAudioFMOD *v14; // ecx
  int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  wchar_t *v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  ksgui::Control *v22; // esi
  ksgui::Control *v23; // eax
  ksgui::Control *v24; // esi
  float v25; // ecx
  volatile signed __int32 *v26; // esi
  ksgui::Control *v27; // ecx
  CarAudioFMOD *v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  ksgui::Control *v34; // eax
  ksgui::Control *v35; // ecx
  CarAudioFMOD *v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  ksgui::Spinner *v42; // eax
  ksgui::Spinner *v43; // eax
  ksgui::Spinner *v44; // eax
  ksgui::Spinner *v45; // esi
  ksgui::Spinner *v46; // eax
  ksgui::Spinner *v47; // ecx
  float v48; // xmm1_4
  ksgui::Spinner_vtbl *v49; // eax
  int i; // esi
  ksgui::Label *v51; // esi
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v52; // eax
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v53; // esi
  CarAudioFMOD_vtbl *v54; // eax
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  ksgui::Control *v61; // eax
  ksgui::Control *v62; // ecx
  float v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  float v67; // xmm2_4
  float v68; // xmm3_4
  ksgui::Control *v69; // eax
  ksgui::Control *v70; // ecx
  float v71; // xmm1_4
  float v72; // xmm0_4
  float v73; // xmm2_4
  float v74; // xmm3_4
  float v75; // xmm2_4
  float v76; // xmm3_4
  ksgui::ListBox *v77; // ebp
  ksgui::ListBox *v78; // eax
  ksgui::ListBox *v79; // eax
  ksgui::ListBox *v80; // ecx
  const __m128i *v81; // eax
  __m128i v82; // xmm0
  ksgui::ListBox *v83; // ecx
  const __m128i *v84; // eax
  ksgui::Control *v85; // ebp
  ksgui::Control *v86; // eax
  FormVolumes::{ctor}::__l35::<lambda_37ca92c32f5bc7550908e8b6e9cf423e> *v87; // eax
  ksgui::Label *v88; // esi
  ksgui::Label *v89; // eax
  ksgui::Label *v90; // eax
  const std::wstring *v91; // eax
  _BYTE v92[80]; // [esp+68h] [ebp-DCh] BYREF
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v93; // [esp+D4h] [ebp-70h] BYREF
  float top; // [esp+D8h] [ebp-6Ch] BYREF
  int v95; // [esp+DCh] [ebp-68h]
  std::shared_ptr<Font> small_font; // [esp+E0h] [ebp-64h] BYREF
  FormVolumes *v97; // [esp+E8h] [ebp-5Ch]
  std::wstring iname; // [esp+ECh] [ebp-58h] BYREF
  std::wstring v99; // [esp+104h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement result; // [esp+11Ch] [ebp-28h] BYREF
  int v101; // [esp+140h] [ebp-4h]

  v3 = 0;
  v99._Bx._Ptr = 0;
  *(_DWORD *)&v92[36] = 0;
  v97 = this;
  *(_DWORD *)&v92[32] = aSim->game->gui;
  *(_DWORD *)&v92[28] = 7;
  *(_DWORD *)&v92[24] = 0;
  *(_WORD *)&v92[8] = 0;
  std::wstring::assign((std::wstring *)&v92[8], (const wchar_t *)&stru_17C4688.parent, 0xCu);
  ksgui::Form::Form(this, 0, *(std::wstring *)&v92[8], *(ksgui::GUI **)&v92[32], v92[36]);
  v101 = 0;
  this->sim = aSim;
  *(_DWORD *)&v92[36] = 24;
  this->__vftable = (FormVolumes_vtbl *)&stru_17C4688.backColor.w;
  this->master = 0;
  this->engine = 0;
  this->wind = 0;
  this->tyres = 0;
  this->opponents = 0;
  this->dirt_bottom = 0;
  this->brakes = 0;
  this->transmission = 0;
  this->surfaces = 0;
  this->bumperInt = 0;
  this->bumperExt = 0;
  this->bonnetInt = 0;
  this->bonnetExt = 0;
  this->driverListBox = 0;
  this->driverButton = 0;
  this->driverButtonTimeAccum = 5.0;
  this->height = 23.0;
  this->space = 35.0;
  this->lastDriverNumber = 0;
  this->devApp = 0;
  this->loaded = 0;
  *(float *)&v4 = COERCE_FLOAT(operator new(*(unsigned int *)&v92[36]));
  v93.__this = (CarAudioFMOD *)v4;
  LOBYTE(v101) = 1;
  if ( *(float *)&v4 == 0.0 )
    v5 = 0;
  else
    Font::Font(v4, eFontMonospaced, 15.0, 0, 0);
  LOBYTE(v101) = 0;
  small_font._Ptr = 0;
  small_font._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&small_font, v5);
  LOBYTE(v101) = 2;
  v99._Myres = 7;
  v99._Mysize = 0;
  v99._Bx._Buf[0] = 0;
  std::wstring::assign(&v99, (const wchar_t *)&stru_17C4688.repeatInterval, 5u);
  LOBYTE(v101) = 3;
  this->formTitle->setText(this->formTitle, &v99);
  LOBYTE(v101) = 2;
  if ( v99._Myres >= 8 )
    operator delete(v99._Bx._Ptr);
  top = 0.0;
  *(float *)&v93.__this = COERCE_FLOAT(operator new(0x1BCu));
  LOBYTE(v101) = 4;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v6 = 0;
  }
  else
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, &stru_17C4688.text._Bx._Buf[2], 6u);
    *(_DWORD *)&v92[36] = 0;
    v3 = 1;
    LOBYTE(v101) = 5;
    *(_DWORD *)&v92[32] = 1;
    *(_DWORD *)&v92[28] = this->gui;
    v99._Bx._Ptr = (wchar_t *)1;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v93.__this, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->master = v6;
  v101 = 2;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  FormVolumes::setSpinner(this, 0.0, this->master, &top);
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_269cfee337444c30de51bb60d71ce489_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->master->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    this);
  *(float *)&v93.__this = COERCE_FLOAT(operator new(0x1BCu));
  LOBYTE(v101) = 8;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v7 = 0;
  }
  else
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, stru_17C4688.backTexture.fileName._Bx._Buf, 6u);
    *(_DWORD *)&v92[36] = 0;
    LOBYTE(v101) = 9;
    v3 |= 2u;
    *(_DWORD *)&v92[32] = 1;
    *(_DWORD *)&v92[28] = this->gui;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v93.__this, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->engine = v7;
  v101 = 2;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  FormVolumes::setSpinner(this, 0.0, this->engine, &top);
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_1167fcd8a3ce318cbf64ff92180676b7_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->engine->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    this);
  *(float *)&v93.__this = COERCE_FLOAT(operator new(0x1BCu));
  LOBYTE(v101) = 12;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v8 = 0;
  }
  else
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, (const wchar_t *)&stru_17C4688.backTexture.fileName._Mysize, 4u);
    *(_DWORD *)&v92[36] = 0;
    LOBYTE(v101) = 13;
    v3 |= 4u;
    *(_DWORD *)&v92[32] = 1;
    *(_DWORD *)&v92[28] = this->gui;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v93.__this, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->wind = v8;
  v101 = 2;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  FormVolumes::setSpinner(this, 0.0, this->wind, &top);
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_d928727def25673e967ea5ca81896de5_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->wind->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    this);
  *(float *)&v93.__this = COERCE_FLOAT(operator new(0x1BCu));
  LOBYTE(v101) = 16;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v9 = 0;
  }
  else
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, (const wchar_t *)&stru_17C4688.rectBase.right, 5u);
    *(_DWORD *)&v92[36] = 0;
    LOBYTE(v101) = 17;
    v3 |= 8u;
    *(_DWORD *)&v92[32] = 1;
    *(_DWORD *)&v92[28] = this->gui;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v93.__this, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->tyres = v9;
  v101 = 2;
  if ( (v3 & 8) != 0 )
  {
    v3 &= 0xFFFFFFF7;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  FormVolumes::setSpinner(this, 0.0, this->tyres, &top);
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_e3b4a43304ae62f776c15ce3d92f6084_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->tyres->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    this);
  *(float *)&v99._Bx._Ptr = this->space + top;
  *(float *)&v10 = COERCE_FLOAT(operator new(0x11Cu));
  v93.__this = (CarAudioFMOD *)v10;
  LOBYTE(v101) = 20;
  if ( *(float *)&v10 == 0.0 )
  {
    v12 = 0.0;
  }
  else
  {
    *(_DWORD *)&v92[36] = this->gui;
    *(_DWORD *)&v92[32] = 7;
    *(_DWORD *)&v92[28] = 0;
    *(_WORD *)&v92[12] = 0;
    std::wstring::assign((std::wstring *)&v92[12], (const wchar_t *)&stru_17C4688.formTitle, 0xAu);
    ksgui::Label::Label(v10, *(std::wstring *)&v92[12], *(ksgui::GUI **)&v92[36]);
    v12 = v11;
  }
  LOBYTE(v101) = 2;
  top = 0.0;
  v95 = 0;
  std::_Ptr_base<Font>::_Reset((std::_Ptr_base<Material> *)&top, (Material *)small_font._Ptr, small_font._Rep);
  v13.__this = *(CarAudioFMOD **)(LODWORD(v12) + 132);
  *(_DWORD *)(LODWORD(v12) + 132) = v95;
  v93.__this = v13.__this;
  *(float *)(LODWORD(v12) + 128) = top;
  if ( *(float *)&v13.__this != 0.0
    && !_InterlockedExchangeAdd((volatile signed __int32 *)&v13.__this->game, 0xFFFFFFFF) )
  {
    ((void (*)(CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>))v13.__this->~GameObject)(v13);
    v14 = v93.__this;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v93.__this->name, 0xFFFFFFFF) )
      ((void (*)(CarAudioFMOD *))v14->update)(v14);
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, (const wchar_t *)&stru_17C4688.text._Myres, 6u);
  LOBYTE(v101) = 21;
  (*(void (**)(float, std::wstring *))(*(_DWORD *)LODWORD(v12) + 68))(COERCE_FLOAT(LODWORD(v12)), &iname);
  LOBYTE(v101) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v15 = *(_DWORD *)LODWORD(v12);
  *(_DWORD *)(LODWORD(v12) + 152) = 2;
  *(_OWORD *)(LODWORD(v12) + 44) = _xmm;
  (*(void (**)(float, int, _DWORD))(v15 + 28))(COERCE_FLOAT(LODWORD(v12)), 1125515264, LODWORD(this->height));
  v16 = *(float *)(LODWORD(v12) + 264);
  v17 = *(float *)(LODWORD(v12) + 32) - *(float *)(LODWORD(v12) + 28);
  v18 = *(float *)(LODWORD(v12) + 40) - *(float *)(LODWORD(v12) + 36);
  v19 = v99._Bx._Ptr;
  *(_DWORD *)(LODWORD(v12) + 28) = 1117126656;
  v20 = v17 + 75.0;
  v21 = v18 + *(float *)&v19;
  *(float *)(LODWORD(v12) + 36) = *(float *)&v19;
  *(float *)(LODWORD(v12) + 32) = v20;
  *(float *)(LODWORD(v12) + 40) = v21;
  if ( v16 == 0.0 && *(float *)(LODWORD(v12) + 272) == 0.0 )
  {
    *(_DWORD *)(LODWORD(v12) + 264) = 1117126656;
    *(float *)(LODWORD(v12) + 272) = *(float *)&v19;
    *(float *)(LODWORD(v12) + 268) = v20;
    *(float *)(LODWORD(v12) + 276) = v21;
  }
  top = v12;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&top);
  *(_DWORD *)&v92[36] = 280;
  *(_DWORD *)(LODWORD(top) + 148) = this;
  *(float *)&v93.__this = this->height + *(float *)&v99._Bx._Ptr;
  *(float *)&v22 = COERCE_FLOAT(operator new(*(unsigned int *)&v92[36]));
  top = *(float *)&v22;
  v23 = 0;
  LOBYTE(v101) = 22;
  if ( *(float *)&v22 != 0.0 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, (const wchar_t *)&stru_17C4688.intervalCounter, 9u);
    LOBYTE(v101) = 23;
    *(_DWORD *)&v92[36] = this->gui;
    v3 |= 0x10u;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Control::Control(v22, &iname, *(ksgui::GUI **)&v92[36]);
  }
  this->bonnetInt = v23;
  v101 = 2;
  if ( (v3 & 0x10) != 0 )
  {
    v3 &= 0xFFFFFFEF;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  *(_DWORD *)&v92[36] = small_font._Rep;
  v24 = this->bonnetInt;
  *(_QWORD *)v99._Bx._Buf = 0i64;
  std::_Ptr_base<Font>::_Reset((std::_Ptr_base<Material> *)&v99, (Material *)small_font._Ptr, small_font._Rep);
  v25 = *(float *)&v24->font._Rep;
  v24->font = *(std::shared_ptr<Font> *)v99._Bx._Buf;
  v26 = (volatile signed __int32 *)LODWORD(v25);
  top = v25;
  if ( v25 != 0.0 && !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v25) + 4), 0xFFFFFFFF) )
  {
    (**(void (***)(float))LODWORD(v25))(COERCE_FLOAT(LODWORD(v25)));
    if ( !_InterlockedExchangeAdd(v26 + 2, 0xFFFFFFFF) )
      (*(void (**)(volatile signed __int32 *))(*v26 + 4))(v26);
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Internal", 8u);
  LOBYTE(v101) = 25;
  this->bonnetInt->setText(this->bonnetInt, &iname);
  LOBYTE(v101) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, _DWORD))this->bonnetInt->setSize)(
    this->bonnetInt,
    1120403456,
    LODWORD(this->height));
  ((void (*)(ksgui::Control *, int))this->bonnetInt->setRepeatInterval)(this->bonnetInt, 1028443341);
  v27 = this->bonnetInt;
  v28 = v93.__this;
  v29 = v27->rectBase.left;
  v30 = v27->rect.right - v27->rect.left;
  v31 = v27->rect.bottom - v27->rect.top;
  v27->rect.left = 50.0;
  v32 = v30 + 50.0;
  v33 = v31 + *(float *)&v28;
  v27->rect.top = *(float *)&v28;
  v27->rect.right = v32;
  v27->rect.bottom = v33;
  if ( v29 == 0.0 && v27->rectBase.top == 0.0 )
  {
    v27->rectBase.left = 50.0;
    v27->rectBase.top = *(float *)&v28;
    v27->rectBase.right = v32;
    v27->rectBase.bottom = v33;
  }
  *(_DWORD *)&v92[36] = this->bonnetInt;
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_236d102ec253d2d28d5308f6e250f236_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bonnetInt->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v92[12],
    *(void **)&v92[36]);
  top = *(float *)&this->bonnetInt;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&top);
  *(_DWORD *)&v92[36] = 280;
  *(_DWORD *)(LODWORD(top) + 148) = this;
  top = COERCE_FLOAT(operator new(*(unsigned int *)&v92[36]));
  LOBYTE(v101) = 27;
  if ( top == 0.0 )
  {
    v34 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, (const wchar_t *)&stru_17C4688.tyres);
    LOBYTE(v101) = 28;
    *(_DWORD *)&v92[36] = this->gui;
    v3 |= 0x20u;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Control::Control((ksgui::Control *)LODWORD(top), &iname, *(ksgui::GUI **)&v92[36]);
  }
  this->bonnetExt = v34;
  v101 = 2;
  if ( (v3 & 0x20) != 0 )
  {
    v3 &= 0xFFFFFFDF;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  std::shared_ptr<Font>::operator=(&this->bonnetExt->font, &small_font);
  std::wstring::wstring(&iname, L"External");
  LOBYTE(v101) = 30;
  this->bonnetExt->setText(this->bonnetExt, &iname);
  LOBYTE(v101) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, _DWORD))this->bonnetExt->setSize)(
    this->bonnetExt,
    1120403456,
    LODWORD(this->height));
  ((void (*)(ksgui::Control *, int))this->bonnetExt->setRepeatInterval)(this->bonnetExt, 1028443341);
  v35 = this->bonnetExt;
  v36 = v93.__this;
  v37 = v35->rectBase.left;
  v38 = v35->rect.right - v35->rect.left;
  v39 = v35->rect.bottom - v35->rect.top;
  v35->rect.left = 150.0;
  v40 = v38 + 150.0;
  v41 = v39 + *(float *)&v36;
  v35->rect.top = *(float *)&v36;
  v35->rect.right = v40;
  v35->rect.bottom = v41;
  if ( v37 == 0.0 && v35->rectBase.top == 0.0 )
  {
    v35->rectBase.left = 150.0;
    v35->rectBase.top = *(float *)&v36;
    v35->rectBase.right = v40;
    v35->rectBase.bottom = v41;
  }
  *(_DWORD *)&v92[36] = this->bonnetExt;
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_43d561cfea8059b7c944e67b2b7319db_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bonnetExt->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v92[12],
    *(void **)&v92[36]);
  v93.__this = (CarAudioFMOD *)this->bonnetExt;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v93);
  *(_DWORD *)&v92[36] = 444;
  top = 0.0;
  v93.__this->bank.path._Bx._Ptr = (wchar_t *)this;
  *(float *)&v93.__this = COERCE_FLOAT(operator new(*(unsigned int *)&v92[36]));
  LOBYTE(v101) = 32;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v42 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, (const wchar_t *)&stru_17C4688.surfaces);
    *(_DWORD *)&v92[36] = 0;
    LOBYTE(v101) = 33;
    v3 |= 0x40u;
    *(_DWORD *)&v92[32] = 1;
    *(_DWORD *)&v92[28] = this->gui;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v93.__this, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->opponents = v42;
  v101 = 2;
  if ( (v3 & 0x40) != 0 )
  {
    v3 &= 0xFFFFFFBF;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  FormVolumes::setSpinner(this, 220.0, this->opponents, &top);
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_5339deedebb689cbdb0b84abd7fea3a9_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->opponents->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    this);
  *(float *)&v93.__this = COERCE_FLOAT(operator new(0x1BCu));
  LOBYTE(v101) = 36;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v43 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, (const wchar_t *)&stru_17C4688.zoomInIcon);
    *(_DWORD *)&v92[36] = 0;
    LOBYTE(v101) = 37;
    v3 |= 0x80u;
    *(_DWORD *)&v92[32] = 1;
    *(_DWORD *)&v92[28] = this->gui;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v93.__this, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->dirt_bottom = v43;
  v101 = 2;
  if ( (v3 & 0x80u) != 0 )
  {
    v3 &= 0xFFFFFF7F;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  FormVolumes::setSpinner(this, 220.0, this->dirt_bottom, &top);
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_c07d0d62db6be702b2beb84a9b8e869f_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->dirt_bottom->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    this);
  *(float *)&v93.__this = COERCE_FLOAT(operator new(0x1BCu));
  LOBYTE(v101) = 40;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v44 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, (const wchar_t *)&stru_17C4688.scaleStep);
    *(_DWORD *)&v92[36] = 0;
    LOBYTE(v101) = 41;
    v3 |= 0x100u;
    *(_DWORD *)&v92[32] = 1;
    *(_DWORD *)&v92[28] = this->gui;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v93.__this, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->surfaces = v44;
  v101 = 2;
  if ( (v3 & 0x100) != 0 )
  {
    v3 &= 0xFFFFFEFF;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  FormVolumes::setSpinner(this, 220.0, this->surfaces, &top);
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_34428c05a9e2953885126d278fa89500_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->surfaces->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    this);
  *(float *)&v45 = COERCE_FLOAT(operator new(0x1BCu));
  v93.__this = (CarAudioFMOD *)v45;
  LOBYTE(v101) = 44;
  if ( *(float *)&v45 == 0.0 )
  {
    v46 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, L"Transmission");
    *(_DWORD *)&v92[36] = 0;
    *(_DWORD *)&v92[32] = 1;
    LOBYTE(v101) = 45;
    *(_DWORD *)&v92[28] = this->gui;
    v3 |= 0x200u;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Spinner::Spinner(v45, &iname, *(ksgui::GUI **)&v92[28], 1, 0);
  }
  this->transmission = v46;
  v101 = 2;
  if ( (v3 & 0x200) != 0 )
  {
    v3 &= 0xFFFFFDFF;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v47 = this->transmission;
  v48 = this->height + this->space;
  *(float *)&v92[36] = this->height;
  v49 = v47->__vftable;
  *(_DWORD *)&v92[32] = 1128792064;
  top = v48 + top;
  ((void (*)(ksgui::Spinner *, int, _DWORD))v49->setSize)(v47, 1128792064, *(_DWORD *)&v92[36]);
  ksgui::Spinner::setPosition(this->transmission, 270.0, top);
  std::wstring::wstring((std::wstring *)&v92[16], L"ENGINE");
  ksgui::Spinner::addItem(this->transmission, *(std::wstring *)&v92[16]);
  for ( i = 0; i < 11; ++i )
  {
    std::to_wstring((std::wstring *)&v92[16], i);
    ksgui::Spinner::addItem(this->transmission, *(std::wstring *)&v92[16]);
  }
  v93.__this = (CarAudioFMOD *)this->transmission;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v93);
  *(_DWORD *)&v92[36] = this;
  v93.__this->bank.path._Bx._Ptr = (wchar_t *)this;
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_da483fcc2c702b95288e0ddc7106f034_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->transmission->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v92[12],
    *(void **)&v92[36]);
  top = this->space + top;
  *(float *)&v51 = COERCE_FLOAT(operator new(0x11Cu));
  v93.__this = (CarAudioFMOD *)v51;
  LOBYTE(v101) = 48;
  if ( *(float *)&v51 == 0.0 )
  {
    *(float *)&v53.__this = 0.0;
  }
  else
  {
    *(_DWORD *)&v92[36] = this->gui;
    std::wstring::wstring((std::wstring *)&v92[12], L"bumper_LBL");
    ksgui::Label::Label(v51, *(std::wstring *)&v92[12], *(ksgui::GUI **)&v92[36]);
    v53.__this = v52.__this;
  }
  LOBYTE(v101) = 2;
  std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)&v53.__this->dirtEvent.path._Bx._Alias[12], &small_font);
  std::wstring::wstring(&iname, (const wchar_t *)&stru_17C4688.labWarning);
  LOBYTE(v101) = 49;
  ((void (*)(CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>, std::wstring *))v53.__this->__vftable[2].shutdown)(
    v53,
    &iname);
  LOBYTE(v101) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v54 = v53.__this->__vftable;
  *(_DWORD *)&v53.__this->bank.path._Bx._Alias[4] = 2;
  *(_OWORD *)&v53.__this->gameObjects._Mylast = _xmm;
  ((void (*)(CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>, int, _DWORD))v54[1].update)(
    v53,
    1125515264,
    LODWORD(this->height));
  v55 = *(float *)&v53.__this->engineIntEvent.instance;
  v56 = *(float *)&v53.__this->isActive - *(float *)&v53.__this->name._Myres;
  v57 = *(float *)&v53.__this->gameObjects._Myfirst - *(float *)&v53.__this->parent;
  v58 = top;
  v53.__this->name._Myres = 1133740032;
  v59 = v56 + 295.0;
  v60 = v57 + v58;
  *(float *)&v53.__this->parent = v58;
  *(float *)&v53.__this->isActive = v59;
  *(float *)&v53.__this->gameObjects._Myfirst = v60;
  if ( v55 == 0.0 && v53.__this->engineIntEvent.basePitch == 0.0 )
  {
    v53.__this->engineIntEvent.instance = (FMOD::Studio::EventInstance *)1133740032;
    v53.__this->engineIntEvent.basePitch = v58;
    v53.__this->engineIntEvent.baseVolume = v59;
    *(float *)&v53.__this->engineIntEvent.path._Bx._Ptr = v60;
  }
  v93.__this = v53.__this;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v93);
  *(_DWORD *)&v92[36] = 280;
  v93.__this->bank.path._Bx._Ptr = (wchar_t *)this;
  top = this->height + top;
  *(float *)&v93.__this = COERCE_FLOAT(operator new(*(unsigned int *)&v92[36]));
  LOBYTE(v101) = 50;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v61 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, (const wchar_t *)&stru_17C4688.height);
    LOBYTE(v101) = 51;
    *(_DWORD *)&v92[36] = this->gui;
    v3 |= 0x400u;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Control::Control((ksgui::Control *)v93.__this, &iname, *(ksgui::GUI **)&v92[36]);
  }
  this->bumperInt = v61;
  v101 = 2;
  if ( (v3 & 0x400) != 0 )
  {
    v3 &= 0xFFFFFBFF;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  std::shared_ptr<Font>::operator=(&this->bumperInt->font, &small_font);
  std::wstring::wstring(&iname, L"Internal");
  LOBYTE(v101) = 53;
  this->bumperInt->setText(this->bumperInt, &iname);
  LOBYTE(v101) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, _DWORD))this->bumperInt->setSize)(
    this->bumperInt,
    1120403456,
    LODWORD(this->height));
  ((void (*)(ksgui::Control *, int))this->bumperInt->setRepeatInterval)(this->bumperInt, 1028443341);
  v62 = this->bumperInt;
  v63 = top;
  v64 = v62->rectBase.left;
  v65 = v62->rect.right - v62->rect.left;
  v66 = v62->rect.bottom - v62->rect.top;
  v62->rect.left = 270.0;
  v67 = v65 + 270.0;
  v68 = v66 + v63;
  v62->rect.top = v63;
  v62->rect.right = v67;
  v62->rect.bottom = v68;
  if ( v64 == 0.0 && v62->rectBase.top == 0.0 )
  {
    v62->rectBase.left = 270.0;
    v62->rectBase.top = v63;
    v62->rectBase.right = v67;
    v62->rectBase.bottom = v68;
  }
  *(_DWORD *)&v92[36] = this->bumperInt;
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_387e47ba7bcb57d24164ccc58d1fdee4_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bumperInt->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v92[12],
    *(void **)&v92[36]);
  v93.__this = (CarAudioFMOD *)this->bumperInt;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v93);
  *(_DWORD *)&v92[36] = 280;
  v93.__this->bank.path._Bx._Ptr = (wchar_t *)this;
  *(float *)&v93.__this = COERCE_FLOAT(operator new(*(unsigned int *)&v92[36]));
  LOBYTE(v101) = 55;
  if ( *(float *)&v93.__this == 0.0 )
  {
    v69 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, L"bumperExt");
    LOBYTE(v101) = 56;
    *(_DWORD *)&v92[36] = this->gui;
    v3 |= 0x800u;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Control::Control((ksgui::Control *)v93.__this, &iname, *(ksgui::GUI **)&v92[36]);
  }
  this->bumperExt = v69;
  v101 = 2;
  if ( (v3 & 0x800) != 0 )
  {
    v3 &= 0xFFFFF7FF;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  std::shared_ptr<Font>::operator=(&this->bumperExt->font, &small_font);
  std::wstring::wstring(&iname, L"External");
  LOBYTE(v101) = 58;
  this->bumperExt->setText(this->bumperExt, &iname);
  LOBYTE(v101) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, _DWORD))this->bumperExt->setSize)(
    this->bumperExt,
    1120403456,
    LODWORD(this->height));
  ((void (*)(ksgui::Control *, int))this->bumperExt->setRepeatInterval)(this->bumperExt, 1028443341);
  v70 = this->bumperExt;
  v71 = top;
  v72 = v70->rectBase.left;
  v73 = v70->rect.right - v70->rect.left;
  v74 = v70->rect.bottom - v70->rect.top;
  v70->rect.left = 370.0;
  v75 = v73 + 370.0;
  v76 = v74 + v71;
  v70->rect.top = v71;
  v70->rect.right = v75;
  v70->rect.bottom = v76;
  if ( v72 == 0.0 && v70->rectBase.top == 0.0 )
  {
    v70->rectBase.left = 370.0;
    v70->rectBase.top = v71;
    v70->rectBase.right = v75;
    v70->rectBase.bottom = v76;
  }
  *(_DWORD *)&v92[36] = this->bumperExt;
  *(_DWORD *)&v92[12] = &std::_Func_impl<std::_Callable_obj<_lambda_1384aab6323566c0e9e919b7fe48495e_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v92[16] = this;
  *(_DWORD *)&v92[28] = &v92[12];
  LOBYTE(v101) = 2;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bumperExt->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v92[12],
    *(void **)&v92[36]);
  ksgui::Control::addControl(this, this->bumperExt);
  top = (float)(this->space + this->height) + top;
  *(float *)&v77 = COERCE_FLOAT(operator new(0x170u));
  v93.__this = (CarAudioFMOD *)v77;
  LOBYTE(v101) = 60;
  if ( *(float *)&v77 == 0.0 )
  {
    v78 = 0;
  }
  else
  {
    *(_DWORD *)&v92[36] = 1;
    *(_DWORD *)&v92[32] = this->gui;
    *(_DWORD *)&v92[28] = 1;
    *(_DWORD *)&v92[24] = 6;
    std::wstring::wstring((std::wstring *)v92, L"DRIVER_LIST_BOX");
    ksgui::ListBox::ListBox(
      v77,
      *(std::wstring *)v92,
      *(unsigned int *)&v92[24],
      *(unsigned int *)&v92[28],
      *(ksgui::GUI **)&v92[32],
      v92[36]);
  }
  LOBYTE(v101) = 2;
  this->driverListBox = v78;
  ksgui::Control::resetBaseRect(v78);
  ((void (*)(ksgui::ListBox *, int, int))this->driverListBox->setSize)(
    this->driverListBox,
    1137836032,
    1120403456);
  ksgui::Form::setPosition((ksgui::Form *)this->driverListBox, 50.0, top);
  this->driverListBox->fontScale = 0.80000001;
  v79 = this->driverListBox;
  *(_DWORD *)&v92[36] = 1061997773;
  *(_DWORD *)&v92[32] = 1041865114;
  *(_DWORD *)&v92[28] = 1041865114;
  v79->allowDeselection = 0;
  vec4f::vec4f((vec4f *)&v99, 0.15000001, *(float *)&v92[28], *(float *)&v92[32], *(float *)&v92[36]);
  v80 = this->driverListBox;
  v82 = _mm_loadu_si128(v81);
  *(_DWORD *)&v92[36] = 1061997773;
  *(_DWORD *)&v92[32] = 1045220557;
  v80->backColor = (vec4f)v82;
  vec4f::vec4f((vec4f *)&v99, 0.2, 0.2, *(float *)&v92[32], *(float *)&v92[36]);
  v83 = this->driverListBox;
  *(_DWORD *)&v92[36] = 0;
  v83->borderColor = (vec4f)_mm_loadu_si128(v84);
  ksgui::ListBox::drawCellsBackgrounds(this->driverListBox, v92[36]);
  ksgui::Control::setVisible(this->driverListBox->titleRow, 0);
  ksgui::Control::addControl(this, this->driverListBox);
  top = top + 100.0;
  *(float *)&v85 = COERCE_FLOAT(operator new(0x118u));
  v93.__this = (CarAudioFMOD *)v85;
  LOBYTE(v101) = 61;
  if ( *(float *)&v85 == 0.0 )
  {
    v86 = 0;
  }
  else
  {
    std::wstring::wstring(&iname, L"DRIVER_BUTTON");
    LOBYTE(v101) = 62;
    *(_DWORD *)&v92[36] = this->gui;
    v3 |= 0x1000u;
    v99._Bx._Ptr = (wchar_t *)v3;
    ksgui::Control::Control(v85, &iname, *(ksgui::GUI **)&v92[36]);
  }
  this->driverButton = v86;
  v101 = 2;
  if ( (v3 & 0x1000) != 0 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  std::shared_ptr<Font>::operator=(&this->driverButton->font, &small_font);
  std::wstring::wstring(&iname, L"SET DRIVER");
  LOBYTE(v101) = 64;
  this->driverButton->setText(this->driverButton, &iname);
  LOBYTE(v101) = 2;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  ((void (*)(ksgui::Control *, int, _DWORD))this->driverButton->setSize)(
    this->driverButton,
    1120403456,
    LODWORD(this->height));
  ((void (*)(ksgui::Control *, int))this->driverButton->setRepeatInterval)(this->driverButton, 1028443341);
  ksgui::Form::setPosition((ksgui::Form *)this->driverButton, 370.0, top + 5.0);
  *(_DWORD *)&v92[36] = this->driverButton;
  CommandItem::CommandItem(&v93, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v92[12],
    v87);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->driverButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v92[12],
    *(void **)&v92[36]);
  ksgui::Control::addControl(this, this->driverButton);
  top = top + 25.0;
  *(float *)&v88 = COERCE_FLOAT(operator new(0x11Cu));
  v93.__this = (CarAudioFMOD *)v88;
  LOBYTE(v101) = 65;
  if ( *(float *)&v88 == 0.0 )
  {
    v89 = 0;
  }
  else
  {
    *(_DWORD *)&v92[36] = this->gui;
    std::wstring::wstring((std::wstring *)&v92[12], L"LAB_WARNING");
    ksgui::Label::Label(v88, *(std::wstring *)&v92[12], *(ksgui::GUI **)&v92[36]);
  }
  LOBYTE(v101) = 2;
  *(_DWORD *)&v92[36] = &small_font;
  this->labWarning = v89;
  std::shared_ptr<Font>::operator=(&v89->font, *(const std::shared_ptr<Font> **)&v92[36]);
  v90 = this->labWarning;
  *(_DWORD *)&v92[36] = L"* driver changes will only be effective after restart";
  v90->fontAlign = eAlignLeft;
  std::wstring::wstring(&iname, *(const wchar_t **)&v92[36]);
  LOBYTE(v101) = 66;
  v91 = acTranslate(&result.name, &iname);
  LOBYTE(v101) = 67;
  this->labWarning->setText(this->labWarning, v91);
  std::wstring::~wstring(&result);
  LOBYTE(v101) = 2;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  ((void (*)(ksgui::Label *, int, _DWORD))this->labWarning->setSize)(
    this->labWarning,
    1120403456,
    LODWORD(this->height));
  ksgui::Form::setPosition((ksgui::Form *)this->labWarning, 10.0, top + 5.0);
  ksgui::Control::setVisible(this->labWarning, 0);
  ksgui::Control::addControl(this, this->labWarning);
  ksgui::Form::setSize(this, 520.0, 500.0);
  std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&small_font);
}
void FormVolumes::refreshDrivers(FormVolumes *this)
{
  int i; // ebx
  const std::wstring *v3; // eax
  const std::wstring *v4; // esi
  ksgui::ListBox *v5; // edi
  unsigned int v6; // edx
  signed int v7; // esi
  signed int v8; // eax
  std::wstring v9; // [esp-18h] [ebp-D4h] BYREF
  ksgui::ListBoxRowData x; // [esp+1Ch] [ebp-A0h] BYREF
  ksgui::ListBoxRowData v11; // [esp+64h] [ebp-58h] BYREF
  int v12; // [esp+B8h] [ebp-4h]

  ksgui::ListBox::clear(this->driverListBox);
  for ( i = 0; i < AudioEngine::getDriverNum(this->sim->game->audioEngine); ++i )
  {
    AudioEngine::getDriverInfo(this->sim->game->audioEngine, &v9, i);
    ksgui::ListBoxRowData::ListBoxRowData(&v11, v9);
    v4 = v3;
    v12 = 0;
    x.name._Myres = 7;
    x.name._Mysize = 0;
    x.name._Bx._Buf[0] = 0;
    std::wstring::assign(&x.name, v3, 0, 0xFFFFFFFF);
    LOBYTE(v12) = 1;
    x.category = (unsigned int)v4[1]._Bx._Ptr;
    x.backColor = (vec4f)_mm_loadu_si128((const __m128i *)&v4[1]._Bx._Buf[2]);
    std::vector<vec4f>::vector<vec4f>(&x.forecolors, (const std::vector<vec4f> *)&v4[1]._Myres);
    LOBYTE(v12) = 2;
    std::vector<std::wstring>::vector<std::wstring>(&x.columns, (const std::vector<std::wstring> *)&v4[2]._Bx._Alias[8]);
    LOBYTE(v12) = 4;
    ksgui::ListBoxRowData::~ListBoxRowData(&v11);
    v5 = this->driverListBox;
    std::vector<ksgui::ListBoxRowData>::push_back(&v5->items, &x);
    v5->scrollBar->maxValue = v5->items._Mylast - v5->items._Myfirst;
    v6 = (int)((unsigned __int64)(2021161081i64 * ((char *)v5->items._Mylast - (char *)v5->items._Myfirst)) >> 32) >> 5;
    if ( v5->selectedItemIndex >= 0 )
    {
      v7 = v6 + (v6 >> 31);
      v8 = v5->selectedItemIndex + ((unsigned int)(v5->rows._Mylast - v5->rows._Myfirst) >> 1);
      if ( v8 <= v7 )
      {
        v7 = v5->selectedItemIndex + ((unsigned int)(v5->rows._Mylast - v5->rows._Myfirst) >> 1);
        if ( v8 < 0 )
          v7 = 0;
      }
      ksgui::ScrollBar::setValue(v5->scrollBar, v7);
      v9._Myres = v7;
    }
    else
    {
      ksgui::ScrollBar::setValue(v5->scrollBar, v6 + (v6 >> 31));
      v9._Myres = v5->items._Mylast - v5->items._Myfirst;
    }
    ksgui::ListBox::scrollListBoxToItem(v5, v9._Myres);
    v12 = -1;
    ksgui::ListBoxRowData::~ListBoxRowData(&x);
  }
}
void __userpurge FormVolumes::setSpinner(FormVolumes *this@<ecx>, float a2@<xmm3>, ksgui::Spinner *obj, float *lasttop)
{
  int i; // esi
  int v6; // ecx
  bool v7; // cf
  std::wstring result; // [esp+2Ch] [ebp-24h] BYREF
  int v10; // [esp+4Ch] [ebp-4h]

  *lasttop = (float)(this->space + this->height) + *lasttop;
  ((void (*)(ksgui::Spinner *, int, _DWORD))obj->setSize)(obj, 1128792064, LODWORD(this->height));
  ksgui::Spinner::setPosition(obj, a2 + 50.0, *lasttop);
  for ( i = 0; i < 11; ++i )
  {
    std::to_wstring(&result, i);
    v10 = 0;
    std::vector<std::wstring>::push_back(&obj->items, &result);
    obj->minValue = 0;
    v6 = (char *)obj->items._Mylast - (char *)obj->items._Myfirst;
    v10 = -1;
    v7 = result._Myres < 8;
    obj->maxValue = ((int)((unsigned __int64)(715827883i64 * v6) >> 32) >> 2)
                  + ((unsigned int)((unsigned __int64)(715827883i64 * v6) >> 32) >> 31)
                  - 1;
    if ( !v7 )
      operator delete(result._Bx._Ptr);
  }
  this->addControl(this, obj);
}
void __userpurge FormVolumes::saveVolume(float _Val@<xmm1>, FormVolumes *this, const std::wstring key)
{
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // edx
  const wchar_t *v7; // ecx
  const wchar_t *v8; // eax
  std::wstring path; // [esp+10h] [ebp-58h] BYREF
  std::wstring result; // [esp+28h] [ebp-40h] BYREF
  std::wstring v11; // [esp+40h] [ebp-28h] BYREF
  int v12; // [esp+64h] [ebp-4h]

  v12 = 0;
  v4 = Path::getDocumentPath(&result);
  LOBYTE(v12) = 1;
  std::operator+<wchar_t>(&path, v4, L"\\Assetto Corsa\\cfg\\audio.ini");
  LOBYTE(v12) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  v5 = std::to_wstring(&v11, _Val);
  v6 = &path;
  v7 = (const wchar_t *)v5;
  if ( path._Myres >= 8 )
    v6 = (std::wstring *)path._Bx._Ptr;
  if ( v5->_Myres >= 8 )
    v7 = v5->_Bx._Ptr;
  v8 = (const wchar_t *)&this;
  if ( key._Mysize >= 8 )
    v8 = (const wchar_t *)this;
  WritePrivateProfileStringW(L"LEVELS", v8, v7, v6->_Bx._Buf);
  if ( v11._Myres >= 8 )
    operator delete(v11._Bx._Ptr);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  if ( key._Mysize >= 8 )
    operator delete(this);
}
void FormVolumes::render(FormVolumes *this, float dt)
{
  float v3; // xmm0_4
  const std::wstring *v4; // eax
  const std::wstring *v5; // eax
  Sim *v6; // ecx
  CameraDrivableManager *v7; // esi
  unsigned int v8; // eax
  Sim *v9; // ecx
  int v10; // esi
  unsigned int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  bool v14; // cc
  const std::wstring *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  const std::wstring *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  const std::wstring *v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  const std::wstring *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  const std::wstring *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  const std::wstring *v30; // eax
  float v31; // xmm0_4
  const std::wstring *v32; // eax
  const std::wstring *v33; // eax
  std::wstring v34; // [esp-18h] [ebp-F8h] BYREF
  float v35; // [esp+0h] [ebp-E0h]
  __int64 v36; // [esp+4h] [ebp-DCh]
  float v37; // [esp+Ch] [ebp-D4h]
  float v38; // [esp+14h] [ebp-CCh]
  char v39; // [esp+1Bh] [ebp-C5h]
  float v40; // [esp+1Ch] [ebp-C4h]
  std::wstring section; // [esp+20h] [ebp-C0h] BYREF
  std::wstring result; // [esp+38h] [ebp-A8h] BYREF
  std::wstring text; // [esp+50h] [ebp-90h] BYREF
  std::wstring v44; // [esp+68h] [ebp-78h] BYREF
  INIReaderDocuments reader; // [esp+80h] [ebp-60h] BYREF
  int v46; // [esp+DCh] [ebp-4h]

  v3 = this->driverButtonTimeAccum;
  if ( v3 >= 0.0 )
  {
    if ( v3 <= 5.0 )
    {
      this->driverButtonTimeAccum = v3 + dt;
    }
    else
    {
      std::wstring::wstring(&text, L"SET DRIVER");
      v46 = 0;
      v4 = acTranslate(&result, &text);
      LOBYTE(v46) = 1;
      v5 = acTranslate(&section, v4);
      LOBYTE(v46) = 2;
      this->driverButton->setText(this->driverButton, v5);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v46 = -1;
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      this->driverButtonTimeAccum = -1.0;
    }
  }
  v6 = this->sim;
  v7 = v6->cameraManager->cameraDrivable;
  v8 = Sim::getFocusedCarIndex(v6);
  FormVolumes::setSound(this, 0, v7->drivableCameraPositions._Myfirst[v8].bonnetExternalSound, 0);
  v9 = this->sim;
  v10 = (int)v9->cameraManager->cameraDrivable;
  v11 = Sim::getFocusedCarIndex(v9);
  FormVolumes::setSound(this, 1, *(_BYTE *)(*(_DWORD *)(v10 + 88) + 56 * v11 + 52), 0);
  if ( this->lastDriverNumber != AudioEngine::getDriverNum(this->sim->game->audioEngine) )
  {
    this->lastDriverNumber = AudioEngine::getDriverNum(this->sim->game->audioEngine);
    FormVolumes::refreshDrivers(this);
  }
  ksgui::Control::render(this, (int)operator delete, v10, dt, v36, v37);
  if ( !this->loaded )
  {
    v35 = 0.0;
    v34._Myres = 7;
    v34._Mysize = 0;
    v34._Bx._Buf[0] = 0;
    std::wstring::assign(&v34, L"cfg/audio.ini", 0xDu);
    INIReaderDocuments::INIReaderDocuments(&reader, (unsigned int)this, v34, SLOBYTE(v35));
    v46 = 3;
    if ( reader.ready )
    {
      std::wstring::wstring(&text, L"MASTER");
      LOBYTE(v46) = 4;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 5;
      v12 = FLOAT_1_0;
      v40 = INIReader::getFloat(&reader, &section, &text);
      v13 = v40;
      v14 = v40 <= 1.0;
      v40 = FLOAT_1_0;
      if ( !v14 || (v12 = 0.0, v13 < 0.0) )
        v13 = v12;
      v15 = std::to_wstring(&result, (int)(float)(v13 * 10.0));
      LOBYTE(v46) = 6;
      ksgui::Spinner::setValue(this->master, v15);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"WIND");
      LOBYTE(v46) = 7;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 8;
      v16 = FLOAT_1_0;
      v38 = INIReader::getFloat(&reader, &section, &text);
      v17 = v38;
      if ( v38 > 1.0 || (v16 = 0.0, v38 < 0.0) )
        v17 = v16;
      v18 = std::to_wstring(&result, (int)(float)(v17 * 10.0));
      LOBYTE(v46) = 9;
      ksgui::Spinner::setValue(this->wind, v18);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"TYRES");
      LOBYTE(v46) = 10;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 11;
      v19 = FLOAT_1_0;
      v38 = INIReader::getFloat(&reader, &section, &text);
      v20 = v38;
      if ( v38 > 1.0 || (v19 = 0.0, v38 < 0.0) )
        v20 = v19;
      v21 = std::to_wstring(&result, (int)(float)(v20 * 10.0));
      LOBYTE(v46) = 12;
      ksgui::Spinner::setValue(this->tyres, v21);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"SURFACES");
      LOBYTE(v46) = 13;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 14;
      v22 = FLOAT_1_0;
      v38 = INIReader::getFloat(&reader, &section, &text);
      v23 = v38;
      if ( v38 > 1.0 || (v22 = 0.0, v38 < 0.0) )
        v23 = v22;
      v24 = std::to_wstring(&result, (int)(float)(v23 * 10.0));
      LOBYTE(v46) = 15;
      ksgui::Spinner::setValue(this->surfaces, v24);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"DIRT_BOTTOM");
      LOBYTE(v46) = 16;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 17;
      v25 = FLOAT_1_0;
      v38 = INIReader::getFloat(&reader, &section, &text);
      v26 = v38;
      if ( v38 > 1.0 || (v25 = 0.0, v38 < 0.0) )
        v26 = v25;
      v27 = std::to_wstring(&result, (int)(float)(v26 * 10.0));
      LOBYTE(v46) = 18;
      ksgui::Spinner::setValue(this->dirt_bottom, v27);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"OPPONENTS");
      LOBYTE(v46) = 19;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 20;
      v28 = FLOAT_1_0;
      v38 = INIReader::getFloat(&reader, &section, &text);
      v29 = v38;
      if ( v38 > 1.0 || (v28 = 0.0, v38 < 0.0) )
        v29 = v28;
      v30 = std::to_wstring(&result, (int)(float)(v29 * 10.0));
      LOBYTE(v46) = 21;
      ksgui::Spinner::setValue(this->opponents, v30);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"ENGINE");
      LOBYTE(v46) = 22;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 23;
      v31 = FLOAT_1_0;
      v38 = INIReader::getFloat(&reader, &section, &text);
      if ( v38 <= 1.0 )
      {
        v31 = 0.0;
        if ( v38 >= 0.0 )
          v31 = v38;
      }
      v32 = std::to_wstring(&result, (int)(float)(v31 * 10.0));
      LOBYTE(v46) = 24;
      ksgui::Spinner::setValue(this->engine, v32);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"TRANSMISSION");
      LOBYTE(v46) = 25;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 26;
      v39 = INIReader::hasKey(&reader, &section, &text);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      if ( !v39 )
        goto LABEL_95;
      std::wstring::wstring(&text, L"TRANSMISSION");
      LOBYTE(v46) = 27;
      std::wstring::wstring(&section, L"LEVELS");
      LOBYTE(v46) = 28;
      v38 = INIReader::getFloat(&reader, &section, &text);
      if ( v38 <= 1.0 )
      {
        if ( v38 >= -1.0 )
          v40 = v38;
        else
          v40 = FLOAT_N1_0;
      }
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v46) = 3;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      if ( v40 == -1.0 )
      {
LABEL_95:
        std::wstring::wstring(&text, L"ENGINE");
        LOBYTE(v46) = 29;
        ksgui::Spinner::setValue(this->transmission, &text);
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
      }
      else
      {
        v33 = std::to_wstring(&v44, (int)(float)(v40 * 10.0));
        LOBYTE(v46) = 30;
        ksgui::Spinner::setValue(this->transmission, v33);
        if ( v44._Myres >= 8 )
          operator delete(v44._Bx._Ptr);
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
      }
      this->loaded = 1;
    }
    v46 = -1;
    INIReaderDocuments::~INIReaderDocuments(&reader);
  }
}
void FormVolumes::setSound(FormVolumes *this, __int16 camera, bool value, bool save)
{
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  void (__cdecl *v7)(void *); // eax
  Sim *v8; // ecx
  CameraDrivableManager *v9; // esi
  unsigned int v10; // ecx
  DrivableCameraDef *v11; // eax
  ksgui::Control *v12; // eax
  vec4f v13; // xmm0
  std::wstring *v14; // eax
  std::wstring *v15; // ecx
  void (__cdecl *v16)(void *); // esi
  ksgui::Control *v17; // eax
  vec4f v18; // xmm0
  std::wstring *v19; // eax
  std::wstring *v20; // ecx
  int v21; // eax
  DrivableCameraDef v22; // [esp-38h] [ebp-13Ch]
  __m128i v23; // [esp+14h] [ebp-F0h] BYREF
  __m128i v24; // [esp+24h] [ebp-E0h] BYREF
  __m128i v25[4]; // [esp+34h] [ebp-D0h] BYREF
  __int64 v26; // [esp+74h] [ebp-90h]
  std::wstring v27; // [esp+90h] [ebp-74h] BYREF
  std::wstring v28; // [esp+A8h] [ebp-5Ch] BYREF
  std::wstring result; // [esp+C0h] [ebp-44h] BYREF
  std::wstring v30; // [esp+D8h] [ebp-2Ch] BYREF
  int v31; // [esp+100h] [ebp-4h]

  v5 = Path::getDocumentPath(&result);
  v31 = 0;
  v6 = std::operator+<wchar_t>(&v30, v5, L"/Assetto Corsa/cfg/camera_manager.ini");
  std::wstring::wstring(&v27, v6);
  v7 = operator delete;
  if ( v30._Myres >= 8 )
  {
    operator delete(v30._Bx._Ptr);
    v7 = operator delete;
  }
  v30._Myres = 7;
  v30._Mysize = 0;
  v30._Bx._Buf[0] = 0;
  LOBYTE(v31) = 2;
  if ( result._Myres >= 8 )
    v7(result._Bx._Ptr);
  v8 = this->sim;
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  v9 = v8->cameraManager->cameraDrivable;
  v10 = Sim::getFocusedCarIndex(v8);
  v11 = v9->drivableCameraPositions._Myfirst;
  v25[0] = _mm_loadu_si128((const __m128i *)&v11[v10]);
  v23 = _mm_loadu_si128((const __m128i *)&v11[v10].bonnetCameraPos);
  v24 = _mm_loadu_si128((const __m128i *)&v11[v10].chaseCameraPitch);
  v26 = *(_QWORD *)&v11[v10].rotationOffset;
  if ( camera )
  {
    v17 = this->bumperInt;
    BYTE4(v26) = value;
    if ( value )
    {
      v17->backColor = 0i64;
      v18 = (vec4f)_xmm;
    }
    else
    {
      v17->backColor = (vec4f)_xmm;
      v18 = 0i64;
    }
    this->bumperExt->backColor = v18;
    if ( save )
    {
      v19 = std::to_wstring(&v28, value);
      v20 = &v27;
      if ( v27._Myres >= 8 )
        v20 = (std::wstring *)v27._Bx._Ptr;
      if ( v19->_Myres >= 8 )
        v19 = (std::wstring *)v19->_Bx._Ptr;
      WritePrivateProfileStringW(L"AUDIO", L"BUMPER_EXTERNAL", v19->_Bx._Buf, v20->_Bx._Buf);
      goto LABEL_15;
    }
LABEL_26:
    v16 = operator delete;
    goto LABEL_27;
  }
  v12 = this->bonnetInt;
  BYTE5(v26) = value;
  if ( value )
  {
    v12->backColor = 0i64;
    v13 = (vec4f)_xmm;
  }
  else
  {
    v12->backColor = (vec4f)_xmm;
    v13 = 0i64;
  }
  this->bonnetExt->backColor = v13;
  if ( !save )
    goto LABEL_26;
  v14 = std::to_wstring(&v28, value);
  v15 = &v27;
  if ( v27._Myres >= 8 )
    v15 = (std::wstring *)v27._Bx._Ptr;
  if ( v14->_Myres >= 8 )
    v14 = (std::wstring *)v14->_Bx._Ptr;
  WritePrivateProfileStringW(L"AUDIO", L"BONNET_EXTERNAL", v14->_Bx._Buf, v15->_Bx._Buf);
LABEL_15:
  v16 = operator delete;
  if ( v28._Myres >= 8 )
    operator delete(v28._Bx._Ptr);
LABEL_27:
  *(__m128i *)&v22.bumperCameraPos.x = _mm_load_si128(v25);
  *(__m128i *)&v22.bonnetCameraPos.x = _mm_load_si128(&v23);
  *(__m128i *)&v22.chaseCameraPitch = _mm_load_si128(&v24);
  *(_QWORD *)&v22.rotationOffset = v26;
  v21 = Sim::getFocusedCarIndex(this->sim);
  CameraDrivableManager::setDrivableCameraDefAt(this->sim->cameraManager->cameraDrivable, v21, v22);
  if ( v27._Myres >= 8 )
    v16(v27._Bx._Ptr);
}
