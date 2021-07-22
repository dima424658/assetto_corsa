#include "formhdr.h
void FormHDR::FormHDR(FormHDR *this, ksgui::GUI *gui, CameraForwardYebis *cameraYebis, Sim *sim)
{
  int v5; // ebx
  const std::wstring *v6; // eax
  ksgui::Graph *v7; // eax
  ksgui::Graph *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  ksgui::Graph *v17; // eax
  ksgui::ConnectedLabel *v18; // eax
  ksgui::ConnectedLabel *v19; // ecx
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  ksgui::Control *v25; // eax
  ksgui::Control *v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  ksgui::Spinner *v32; // eax
  ksgui::Spinner *v33; // eax
  ksgui::Spinner *v34; // eax
  Sim *v35; // ecx
  CarAvatar *v36; // eax
  ksgui::Spinner *v37; // eax
  ksgui::Spinner *v38; // eax
  ksgui::Spinner *v39; // eax
  Sim *v40; // ecx
  CarAvatar *v41; // eax
  ksgui::Control *v42; // eax
  ksgui::Control *v43; // ecx
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  ksgui::Spinner *v49; // eax
  ksgui::Spinner *v50; // eax
  ksgui::Spinner *v51; // eax
  ksgui::Control *v52; // eax
  ksgui::Control *v53; // ecx
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm4_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  unsigned int v61; // ebx
  CarAvatar *v62; // eax
  std::wstring *v63; // eax
  const std::wstring *v64; // eax
  ksgui::Control *v65; // ecx
  ksgui::Control_vtbl *v66; // eax
  _BYTE v67[72]; // [esp+30h] [ebp-A0h] BYREF
  ksgui::Graph *v68; // [esp+78h] [ebp-58h] BYREF
  __m128i v69; // [esp+7Ch] [ebp-54h] BYREF
  FormHDR *v70; // [esp+8Ch] [ebp-44h]
  std::wstring text; // [esp+90h] [ebp-40h] BYREF
  std::wstring result; // [esp+A8h] [ebp-28h] BYREF
  int v73; // [esp+CCh] [ebp-4h]

  v5 = 0;
  *(_DWORD *)&v67[28] = 0;
  *(_DWORD *)&v67[24] = gui;
  v68 = 0;
  v70 = this;
  v69.m128i_i32[3] = (int)sim;
  *(_DWORD *)&v67[20] = 7;
  *(_DWORD *)&v67[16] = 0;
  *(_WORD *)v67 = 0;
  std::wstring::assign((std::wstring *)v67, L"FORM_HDR", 8u);
  ksgui::Form::Form(this, 0, *(std::wstring *)v67, *(ksgui::GUI **)&v67[24], v67[28]);
  v73 = 0;
  this->camera = cameraYebis;
  *(_DWORD *)&v67[28] = 12;
  *(_DWORD *)&v67[24] = L"HDR Settings";
  this->__vftable = (FormHDR_vtbl *)&FormHDR::`vftable';
  this->sim = sim;
  this->currentAutoExposure = 0.0;
  this->savedTimeStamp = 0.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v67[24], *(unsigned int *)&v67[28]);
  LOBYTE(v73) = 1;
  v6 = acTranslate(&result, &text);
  LOBYTE(v73) = 2;
  this->formTitle->setText(this->formTitle, v6);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v73) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->devApp = 1;
  ksgui::Form::setSize(this, 400.0, 600.0);
  v68 = (ksgui::Graph *)operator new(0x140u);
  LOBYTE(v73) = 3;
  if ( v68 )
  {
    *(_DWORD *)&v67[28] = gui;
    *(_DWORD *)&v67[24] = 7;
    *(_DWORD *)&v67[20] = 0;
    *(_WORD *)&v67[4] = 0;
    std::wstring::assign((std::wstring *)&v67[4], L"AutoExposure", 0xCu);
    ksgui::Graph::Graph(v68, *(std::wstring *)&v67[4], *(ksgui::GUI **)&v67[28]);
  }
  else
  {
    v7 = 0;
  }
  LOBYTE(v73) = 0;
  *(_DWORD *)&v67[28] = &v68;
  this->autoExposureGraph = v7;
  v68 = v7;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, *(int **)&v67[28]);
  v68->parent = this;
  ((void (*)(ksgui::Graph *, int, int))this->autoExposureGraph->setSize)(
    this->autoExposureGraph,
    1135542272,
    1133903872);
  v8 = this->autoExposureGraph;
  v9 = v8->rectBase.left;
  v10 = v8->rect.right - v8->rect.left;
  v11 = v8->rect.bottom - v8->rect.top;
  v8->rect.top = 30.0;
  v8->rect.left = 25.0;
  v12 = v10 + 25.0;
  v13 = v11 + 30.0;
  v8->rect.right = v12;
  v8->rect.bottom = v13;
  if ( v9 == 0.0 && v8->rectBase.top == 0.0 )
  {
    v8->rectBase.left = 25.0;
    v8->rectBase.top = 30.0;
    v8->rectBase.right = v12;
    v8->rectBase.bottom = v13;
  }
  *(_DWORD *)&text._Bx._Alias[8] = 1065353216;
  v14 = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_1_0), (__m128)LODWORD(FLOAT_1_0));
  v69.m128i_i64[0] = LODWORD(FLOAT_1_0);
  *(_QWORD *)&v67[20] = v14.m128_u64[0];
  *(_DWORD *)&v67[28] = 1065353216;
  ksgui::Graph::addSerie(this->autoExposureGraph, *(__int128 *)&v67[20]);
  v15 = (__m128)_mm_loadl_epi64(&v69);
  *(_DWORD *)&text._Bx._Alias[8] = 0;
  v14.m128_f32[0] = v15.m128_f32[0];
  *(_QWORD *)&v67[20] = _mm_unpacklo_ps(v14, v15).m128_u64[0];
  *(_DWORD *)&v67[28] = 0;
  ksgui::Graph::addSerie(this->autoExposureGraph, *(__int128 *)&v67[20]);
  v16 = (__m128)_mm_loadl_epi64(&v69);
  *(_DWORD *)&text._Bx._Alias[8] = 0;
  *(_QWORD *)&v67[20] = _mm_unpacklo_ps(v16, (__m128)0i64).m128_u64[0];
  *(_DWORD *)&v67[28] = 0;
  ksgui::Graph::addSerie(this->autoExposureGraph, *(__int128 *)&v67[20]);
  v17 = this->autoExposureGraph;
  *(_DWORD *)&v67[28] = 344;
  v17->maxY = 10.0;
  v69.m128i_i32[0] = (int)operator new(*(unsigned int *)&v67[28]);
  LOBYTE(v73) = 4;
  if ( v69.m128i_i32[0] )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"AutoExposure", 0xCu);
    LOBYTE(v73) = 5;
    v5 = 1;
    v68 = (ksgui::Graph *)1;
    ksgui::ConnectedLabel::ConnectedLabel(
      (ksgui::ConnectedLabel *)v69.m128i_i32[0],
      &text,
      gui,
      &this->currentAutoExposure);
  }
  else
  {
    v18 = 0;
  }
  this->labAutoExposure = v18;
  v73 = 0;
  if ( (v5 & 1) != 0 )
  {
    v5 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v19 = this->labAutoExposure;
  v20 = v19->rectBase.left;
  v21 = v19->rect.right - v19->rect.left;
  v22 = v19->rect.bottom - v19->rect.top;
  v19->rect.top = 350.0;
  v19->rect.left = 25.0;
  v23 = v21 + 25.0;
  v24 = v22 + 350.0;
  v19->rect.right = v23;
  v19->rect.bottom = v24;
  if ( v20 == 0.0 && v19->rectBase.top == 0.0 )
  {
    v19->rectBase.left = 25.0;
    v19->rectBase.top = 350.0;
    v19->rectBase.right = v23;
    v19->rectBase.bottom = v24;
  }
  v68 = (ksgui::Graph *)this->labAutoExposure;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v68);
  *(_DWORD *)&v67[28] = 280;
  v68->parent = this;
  v69.m128i_i32[0] = (int)operator new(*(unsigned int *)&v67[28]);
  LOBYTE(v73) = 7;
  if ( v69.m128i_i32[0] )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Disable Limits", 0xEu);
    LOBYTE(v73) = 8;
    v5 |= 2u;
    v68 = (ksgui::Graph *)v5;
    ksgui::Control::Control((ksgui::Control *)v69.m128i_i32[0], &text, gui);
  }
  else
  {
    v25 = 0;
  }
  this->butDisableLimits = v25;
  v73 = 0;
  if ( (v5 & 2) != 0 )
  {
    v5 &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Disable Limits", 0xEu);
  LOBYTE(v73) = 10;
  this->butDisableLimits->setText(this->butDisableLimits, &text);
  LOBYTE(v73) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v68 = (ksgui::Graph *)this->butDisableLimits;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v68);
  v68->parent = this;
  v26 = this->butDisableLimits;
  v27 = v26->rectBase.left;
  v28 = v26->rect.right - v26->rect.left;
  v29 = v26->rect.bottom - v26->rect.top;
  v26->rect.top = 350.0;
  v26->rect.left = 250.0;
  v30 = v28 + 250.0;
  v31 = v29 + 350.0;
  v26->rect.right = v30;
  v26->rect.bottom = v31;
  if ( v27 == 0.0 && v26->rectBase.top == 0.0 )
  {
    v26->rectBase.left = 250.0;
    v26->rectBase.top = 350.0;
    v26->rectBase.right = v30;
    v26->rectBase.bottom = v31;
  }
  ((void (*)(ksgui::Control *, int, int))this->butDisableLimits->setSize)(
    this->butDisableLimits,
    1120403456,
    1101004800);
  *(_DWORD *)&v67[4] = &std::_Func_impl<std::_Callable_obj<_lambda_7d01fca3e9ee52c3031d566313262bc1_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v67[8] = this;
  *(_DWORD *)&v67[20] = &v67[4];
  LOBYTE(v73) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butDisableLimits->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v67[4],
    this);
  v69.m128i_i32[0] = (int)operator new(0x1BCu);
  LOBYTE(v73) = 12;
  if ( v69.m128i_i32[0] )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"spOnBoardExp", 0xCu);
    LOBYTE(v73) = 13;
    v5 |= 4u;
    v68 = (ksgui::Graph *)v5;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v69.m128i_i32[0], &text, gui, 0, 0);
  }
  else
  {
    v32 = 0;
  }
  this->spOnBoardExposure = v32;
  v73 = 0;
  if ( (v5 & 4) != 0 )
  {
    v5 &= 0xFFFFFFFB;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v68 = (ksgui::Graph *)this->spOnBoardExposure;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v68);
  v68->parent = this;
  ksgui::Spinner::setPosition(this->spOnBoardExposure, 25.0, 400.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spOnBoardExposure->setSize)(
    this->spOnBoardExposure,
    1125515264,
    1106247680);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"OnBoard EXP", 0xBu);
  v33 = this->spOnBoardExposure;
  LOBYTE(v73) = 15;
  v33->label->setText(v33->label, &text);
  LOBYTE(v73) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v34 = this->spOnBoardExposure;
  v35 = (Sim *)v69.m128i_i32[3];
  *(_DWORD *)&v67[28] = 0;
  v34->minValue = 0;
  this->spOnBoardExposure->maxValue = 100;
  v36 = Sim::getCar(v35, *(unsigned int *)&v67[28]);
  ksgui::Spinner::setValue(this->spOnBoardExposure, (int)v36->onBoardExposure);
  *(_DWORD *)&v67[28] = this;
  *(_DWORD *)&v67[4] = &std::_Func_impl<std::_Callable_obj<_lambda_cbc7ac63e352068be527d19c59908c1f_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v67[8] = v69.m128i_i32[3];
  *(_DWORD *)&v67[20] = &v67[4];
  LOBYTE(v73) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spOnBoardExposure->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v67[4],
    this);
  v69.m128i_i32[0] = (int)operator new(0x1BCu);
  LOBYTE(v73) = 17;
  if ( v69.m128i_i32[0] )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"spOutBoardExp", 0xDu);
    LOBYTE(v73) = 18;
    v5 |= 8u;
    v68 = (ksgui::Graph *)v5;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v69.m128i_i32[0], &text, gui, 0, 0);
  }
  else
  {
    v37 = 0;
  }
  this->spOutBoardExposure = v37;
  v73 = 0;
  if ( (v5 & 8) != 0 )
  {
    v5 &= 0xFFFFFFF7;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v68 = (ksgui::Graph *)this->spOutBoardExposure;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v68);
  v68->parent = this;
  ksgui::Spinner::setPosition(this->spOutBoardExposure, 225.0, 400.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spOutBoardExposure->setSize)(
    this->spOutBoardExposure,
    1125515264,
    1106247680);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"OutBoard EXP", 0xCu);
  v38 = this->spOutBoardExposure;
  LOBYTE(v73) = 20;
  v38->label->setText(v38->label, &text);
  LOBYTE(v73) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v39 = this->spOutBoardExposure;
  v40 = (Sim *)v69.m128i_i32[3];
  *(_DWORD *)&v67[28] = 0;
  v39->minValue = 0;
  this->spOutBoardExposure->maxValue = 100;
  v41 = Sim::getCar(v40, *(unsigned int *)&v67[28]);
  ksgui::Spinner::setValue(this->spOutBoardExposure, (int)v41->outBoardExposure);
  *(_DWORD *)&v67[28] = this;
  *(_DWORD *)&v67[4] = &std::_Func_impl<std::_Callable_obj<_lambda_70b0f94afc090b8ac830ff20ba5fa984_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v67[8] = v69.m128i_i32[3];
  *(_DWORD *)&v67[20] = &v67[4];
  LOBYTE(v73) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spOutBoardExposure->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v67[4],
    this);
  v69.m128i_i32[0] = (int)operator new(0x118u);
  LOBYTE(v73) = 22;
  if ( v69.m128i_i32[0] )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"labExpMult", 0xAu);
    LOBYTE(v73) = 23;
    v5 |= 0x10u;
    v68 = (ksgui::Graph *)v5;
    ksgui::Control::Control((ksgui::Control *)v69.m128i_i32[0], &text, gui);
  }
  else
  {
    v42 = 0;
  }
  this->labExpMult = v42;
  v73 = 0;
  if ( (v5 & 0x10) != 0 )
  {
    v5 &= 0xFFFFFFEF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v68 = (ksgui::Graph *)this->labExpMult;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v68);
  v68->parent = this;
  v43 = this->labExpMult;
  v44 = v43->rectBase.left;
  v45 = v43->rect.right - v43->rect.left;
  v46 = v43->rect.bottom - v43->rect.top;
  v43->rect.top = 480.0;
  v43->rect.left = 25.0;
  v47 = v45 + 25.0;
  v48 = v46 + 480.0;
  v43->rect.right = v47;
  v43->rect.bottom = v48;
  if ( v44 == 0.0 && v43->rectBase.top == 0.0 )
  {
    v43->rectBase.left = 25.0;
    v43->rectBase.top = 480.0;
    v43->rectBase.right = v47;
    v43->rectBase.bottom = v48;
  }
  ((void (*)(ksgui::Control *, int, int))this->labExpMult->setSize)(this->labExpMult, 1125515264, 1106247680);
  v69.m128i_i32[0] = (int)operator new(0x1BCu);
  LOBYTE(v73) = 25;
  if ( v69.m128i_i32[0] )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"target", 6u);
    LOBYTE(v73) = 26;
    v5 |= 0x20u;
    v68 = (ksgui::Graph *)v5;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v69.m128i_i32[0], &text, gui, 0, 0);
  }
  else
  {
    v49 = 0;
  }
  this->spTarget = v49;
  v73 = 0;
  if ( (v5 & 0x20) != 0 )
  {
    v5 &= 0xFFFFFFDF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v68 = (ksgui::Graph *)this->spTarget;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v68);
  v68->parent = this;
  ksgui::Spinner::setPosition(this->spTarget, 225.0, 480.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spTarget->setSize)(this->spTarget, 1125515264, 1106247680);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"PP Target (not saved)", 0x15u);
  v50 = this->spTarget;
  LOBYTE(v73) = 28;
  v50->label->setText(v50->label, &text);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v51 = this->spTarget;
  *(_DWORD *)&v67[28] = this;
  v51->minValue = 0;
  this->spTarget->maxValue = 100;
  this->spTarget->displayValueMult = 0.0099999998;
  *(_DWORD *)&v67[4] = &std::_Func_impl<std::_Callable_obj<_lambda_f2b220d28947b5c0207a80176cf7ac1f_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v67[8] = this;
  *(_DWORD *)&v67[20] = &v67[4];
  LOBYTE(v73) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spTarget->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v67[4],
    *(void **)&v67[28]);
  ksgui::Spinner::setValue(this->spTarget, (int)(float)(this->camera->pp.autoExposureTarget * 100.0));
  v69.m128i_i32[0] = (int)operator new(0x118u);
  LOBYTE(v73) = 30;
  if ( v69.m128i_i32[0] )
  {
    std::wstring::wstring(&result, L"Save");
    LOBYTE(v73) = 31;
    v5 |= 0x40u;
    v68 = (ksgui::Graph *)v5;
    ksgui::Control::Control((ksgui::Control *)v69.m128i_i32[0], &result, gui);
  }
  else
  {
    v52 = 0;
  }
  this->butSave = v52;
  v73 = 0;
  if ( (v5 & 0x40) != 0 && result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wstring::wstring(&result, L"Save in car.ini");
  LOBYTE(v73) = 33;
  this->butSave->setText(this->butSave, &result);
  LOBYTE(v73) = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v68 = (ksgui::Graph *)this->butSave;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v68);
  v68->parent = this;
  ((void (*)(ksgui::Control *, int, int))this->butSave->setSize)(this->butSave, 1135542272, 1101004800);
  v53 = this->butSave;
  v54 = v53->rect.bottom - v53->rect.top;
  v55 = v53->rect.right - v53->rect.left;
  v53->rect.left = 25.0;
  v56 = 600.0 - v54;
  v57 = v53->rect.bottom - v53->rect.top;
  v58 = v55 + 25.0;
  v53->rect.top = v56;
  v59 = v56 + v57;
  v60 = v53->rectBase.left;
  v53->rect.right = v58;
  v53->rect.bottom = v59;
  if ( v60 == 0.0 && v53->rectBase.top == 0.0 )
  {
    v53->rectBase.left = 25.0;
    v53->rectBase.top = v56;
    v53->rectBase.right = v58;
    v53->rectBase.bottom = v59;
  }
  v61 = v69.m128i_u32[3];
  v62 = Sim::getCar((Sim *)v69.m128i_i32[3], 0);
  v63 = std::operator+<wchar_t>(&text, L"content/cars/", &v62->unixName);
  LOBYTE(v73) = 34;
  v64 = std::operator+<wchar_t>(&result, v63, L"/data.acd");
  LOBYTE(v73) = 35;
  v69.m128i_i8[11] = Path::fileExists(v61, v64, 0);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v73) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  if ( v69.m128i_i8[11] )
  {
    v65 = this->butSave;
    if ( v65->visible )
    {
      v66 = v65->__vftable;
      *(_DWORD *)&v67[28] = 0;
      v65->visible = 0;
      ((void (__stdcall *)(_DWORD))v66->onVisibleChanged)(*(_DWORD *)&v67[28]);
    }
  }
  *(_DWORD *)&v67[4] = &std::_Func_impl<std::_Callable_obj<_lambda_46a7be93e17a22b77cc31e06c1e036d8_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v67[8] = v61;
  *(_DWORD *)&v67[12] = this;
  *(_DWORD *)&v67[20] = &v67[4];
  LOBYTE(v73) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSave->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v67[4],
    this);
  ksgui::Form::setAutoHideMode(this, 0);
}
void __userpurge FormHDR::render(FormHDR *this@<ecx>, int a2@<edi>, float dt)
{
  CameraForwardYebis *v4; // eax
  ksgui::Graph *v5; // ecx
  float v6; // xmm0_4
  int v7; // eax
  CameraForwardYebis *v8; // eax
  ksgui::Graph *v9; // ecx
  float v10; // xmm1_4
  float v11; // xmm0_4
  unsigned int v12; // eax
  ksgui::Graph *v13; // ecx
  std::wostream *v14; // eax
  int v15; // ebx
  int v16; // ecx
  const std::wstring *v17; // eax
  __int64 v18; // [esp+1Ch] [ebp-114h]
  float v19; // [esp+24h] [ebp-10Ch]
  int _Val; // [esp+2Ch] [ebp-104h] BYREF
  float limit_max; // [esp+30h] [ebp-100h]
  float limit_min; // [esp+34h] [ebp-FCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v23; // [esp+38h] [ebp-F8h] BYREF
  std::wstring v24; // [esp+E8h] [ebp-48h] BYREF
  std::wstring result; // [esp+104h] [ebp-2Ch] BYREF
  int v26; // [esp+12Ch] [ebp-4h]

  _Val = 0;
  v4 = this->camera;
  v5 = this->autoExposureGraph;
  v6 = v4->currentAutoExposure;
  this->currentAutoExposure = v6;
  v7 = v5->series._Mylast - v5->series._Myfirst;
  _Val = LODWORD(v6);
  if ( v7 )
  {
    if ( v5->autoAdjustMaxValue && v6 > v5->maxY )
      v5->maxY = v6;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&(*v5->series._Myfirst)->values, &_Val);
  }
  v8 = this->camera;
  v9 = this->autoExposureGraph;
  v10 = v8->pp.autoExposureMin;
  v11 = v8->pp.autoExposureMax;
  limit_min = v10;
  limit_max = v11;
  v12 = v9->series._Mylast - v9->series._Myfirst;
  _Val = LODWORD(v10);
  if ( v12 > 1 )
  {
    if ( v9->autoAdjustMaxValue && v10 > v9->maxY )
      v9->maxY = v10;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)(*((_DWORD *)v9->series._Myfirst + 1) + 12), &_Val);
    v11 = limit_max;
  }
  v13 = this->autoExposureGraph;
  _Val = LODWORD(v11);
  if ( (unsigned int)(v13->series._Mylast - v13->series._Myfirst) > 2 )
  {
    if ( v13->autoAdjustMaxValue && v11 > v13->maxY )
      v13->maxY = v11;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)(*((_DWORD *)v13->series._Myfirst + 2) + 12), &_Val);
  }
  if ( this->sim->game->gameTime.now > this->savedTimeStamp )
  {
    v24._Myres = 7;
    v24._Mysize = 0;
    v24._Bx._Buf[0] = 0;
    std::wstring::assign(&v24, L"Save in car.ini", 0xFu);
    v26 = 0;
    this->butSave->setText(this->butSave, &v24);
    v26 = -1;
    if ( v24._Myres >= 8 )
      operator delete(v24._Bx._Ptr);
  }
  *(_DWORD *)v23.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v23.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v23.gap68);
  v26 = 1;
  _Val = 1;
  std::wiostream::basic_iostream<wchar_t>(&v23, &v23.gap10[8], 0);
  v26 = 2;
  *(_DWORD *)&v23.gap0[*(_DWORD *)(*(_DWORD *)v23.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&limit_min + *(_DWORD *)(*(_DWORD *)v23.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v23.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v23.gap10[8]);
  *(_DWORD *)&v23.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v23.gap10[64] = 0;
  *(_DWORD *)&v23.gap10[68] = 0;
  v26 = 4;
  _Val = std::setprecision(&v24, 2, 0);
  v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v23.gap10, "Exp multiplier: ");
  v15 = std::wostream::operator<<(v14, std::fixed);
  if ( v15 )
    v16 = v15 + *(_DWORD *)(*(_DWORD *)v15 + 4);
  else
    v16 = 0;
  (*(void (__cdecl **)(int, _DWORD))_Val)(v16, *(_DWORD *)(_Val + 8));
  std::wostream::operator<<(v15);
  v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v23, &result);
  LOBYTE(v26) = 5;
  this->labExpMult->setText(this->labExpMult, v17);
  LOBYTE(v26) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  ksgui::Control::render(this, a2, (int)this, dt, v18, v19);
  *(_DWORD *)&v23.gap0[*(_DWORD *)(*(_DWORD *)v23.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&limit_min + *(_DWORD *)(*(_DWORD *)v23.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v23.gap0 + 4) - 104;
  *(_DWORD *)&v23.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v23.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v23.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v23.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v23.gap68);
}
