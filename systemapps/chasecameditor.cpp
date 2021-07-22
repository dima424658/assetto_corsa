#include "chasecameditor.h
void ChaseCamEditor::ChaseCamEditor(ChaseCamEditor *this, Sim *sim)
{
  int v3; // ebx
  ksgui::Spinner *v4; // ebp
  ksgui::Spinner *v5; // eax
  ksgui::Spinner *v6; // eax
  ksgui::Spinner *v7; // eax
  ksgui::Control *v8; // eax
  ksgui::Control *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  ksgui::Spinner *v15; // ebp
  ksgui::Control *v16; // eax
  ksgui::Control *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  ksgui::Spinner *v23; // ebx
  ksgui::Label *v24; // eax
  ksgui::Label *v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  _BYTE v31[28]; // [esp+10h] [ebp-7Ch] BYREF
  float h; // [esp+2Ch] [ebp-60h]
  int _Val; // [esp+58h] [ebp-34h] BYREF
  ksgui::Spinner *v34; // [esp+5Ch] [ebp-30h]
  ChaseCamEditor *v35; // [esp+60h] [ebp-2Ch]
  std::wstring iname; // [esp+64h] [ebp-28h] BYREF
  int v37; // [esp+88h] [ebp-4h]

  v3 = 0;
  _Val = 0;
  h = 0.0;
  v35 = this;
  *(_DWORD *)&v31[24] = sim->game->gui;
  *(_DWORD *)&v31[20] = 7;
  *(_DWORD *)&v31[16] = 0;
  *(_WORD *)v31 = 0;
  std::wstring::assign((std::wstring *)v31, L"CHASE_CAM_EDITOR", 0x10u);
  ksgui::Form::Form(this, 0, *(std::wstring *)v31, *(ksgui::GUI **)&v31[24], SLOBYTE(h));
  v37 = 0;
  LODWORD(h) = 15;
  this->__vftable = (ChaseCamEditor_vtbl *)&ChaseCamEditor::`vftable';
  *(_DWORD *)&v31[24] = L"ChaseCam Editor";
  this->sim = sim;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, *(const wchar_t **)&v31[24], LODWORD(h));
  LOBYTE(v37) = 1;
  this->formTitle->setText(this->formTitle, &iname);
  LOBYTE(v37) = 0;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Form::setSize(this, 400.0, 400.0);
  v4 = (ksgui::Spinner *)operator new(0x1BCu);
  v34 = v4;
  v5 = 0;
  LOBYTE(v37) = 2;
  if ( v4 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Distance", 8u);
    h = 0.0;
    *(_DWORD *)&v31[24] = 0;
    LOBYTE(v37) = 3;
    *(_DWORD *)&v31[20] = this->gui;
    v3 = 1;
    _Val = 1;
    ksgui::Spinner::Spinner(v4, &iname, *(ksgui::GUI **)&v31[20], 0, 0);
  }
  this->spDistance = v5;
  v37 = 0;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  _Val = (int)this->spDistance;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Spinner::setPosition(this->spDistance, 10.0, 40.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spDistance->setSize)(this->spDistance, 1125515264, 1101004800);
  this->spDistance->minValue = 0;
  this->spDistance->maxValue = 1000;
  ksgui::Spinner::setValue(
    this->spDistance,
    (int)(float)(sim->cameraManager->cameraDrivable->chaseCamData[0].distance * 10.0));
  *(_DWORD *)&v31[4] = &std::_Func_impl<std::_Callable_obj<_lambda_cb48ad9147d9ce8fc011e44c5655f084_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v31[8] = this;
  *(_DWORD *)&v31[20] = &v31[4];
  LOBYTE(v37) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spDistance->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v31[4],
    this);
  v34 = (ksgui::Spinner *)operator new(0x1BCu);
  LOBYTE(v37) = 6;
  if ( v34 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Height", 6u);
    h = 0.0;
    LOBYTE(v37) = 7;
    v3 |= 2u;
    *(_DWORD *)&v31[24] = 0;
    *(_DWORD *)&v31[20] = this->gui;
    _Val = v3;
    ksgui::Spinner::Spinner(v34, &iname, *(ksgui::GUI **)&v31[20], 0, 0);
  }
  else
  {
    v6 = 0;
  }
  this->spHeight = v6;
  v37 = 0;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  _Val = (int)this->spHeight;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Spinner::setPosition(this->spHeight, 10.0, 80.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spHeight->setSize)(this->spHeight, 1125515264, 1101004800);
  this->spHeight->minValue = 0;
  this->spHeight->maxValue = 1000;
  ksgui::Spinner::setValue(
    this->spHeight,
    (int)(float)(sim->cameraManager->cameraDrivable->chaseCamData[0].height * 10.0));
  *(_DWORD *)&v31[4] = &std::_Func_impl<std::_Callable_obj<_lambda_377cdf5e12515769267954fd2b1d6349_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v31[8] = this;
  *(_DWORD *)&v31[20] = &v31[4];
  LOBYTE(v37) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spHeight->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v31[4],
    this);
  v34 = (ksgui::Spinner *)operator new(0x1BCu);
  LOBYTE(v37) = 10;
  if ( v34 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Pitch", 5u);
    h = 0.0;
    LOBYTE(v37) = 11;
    v3 |= 4u;
    *(_DWORD *)&v31[24] = 0;
    *(_DWORD *)&v31[20] = this->gui;
    _Val = v3;
    ksgui::Spinner::Spinner(v34, &iname, *(ksgui::GUI **)&v31[20], 0, 0);
  }
  else
  {
    v7 = 0;
  }
  this->spPitch = v7;
  v37 = 0;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  _Val = (int)this->spPitch;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Spinner::setPosition(this->spPitch, 10.0, 120.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spPitch->setSize)(this->spPitch, 1125515264, 1101004800);
  this->spPitch->minValue = -45;
  this->spPitch->maxValue = 45;
  ksgui::Spinner::setValue(
    this->spPitch,
    (int)(float)(sim->cameraManager->cameraDrivable->chaseCamData[0].pitchRAD * 57.29578));
  *(_DWORD *)&v31[4] = &std::_Func_impl<std::_Callable_obj<_lambda_099004683791e5e78b79ba2aa827763b_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v31[8] = this;
  *(_DWORD *)&v31[20] = &v31[4];
  LOBYTE(v37) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spPitch->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v31[4],
    this);
  v34 = (ksgui::Spinner *)operator new(0x118u);
  LOBYTE(v37) = 14;
  if ( v34 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Save chase 0", 0xCu);
    LOBYTE(v37) = 15;
    h = *(float *)&this->gui;
    v3 |= 8u;
    _Val = v3;
    ksgui::Control::Control(v34, &iname, (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v8 = 0;
  }
  this->butSaveGlobal0 = v8;
  v37 = 0;
  if ( (v3 & 8) != 0 )
  {
    v3 &= 0xFFFFFFF7;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  _Val = (int)this->butSaveGlobal0;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ((void (*)(ksgui::Control *, int, int))this->butSaveGlobal0->setSize)(
    this->butSaveGlobal0,
    1125515264,
    1106247680);
  v9 = this->butSaveGlobal0;
  v10 = v9->rectBase.left;
  v11 = v9->rect.right - v9->rect.left;
  v12 = v9->rect.bottom - v9->rect.top;
  v9->rect.top = 350.0;
  v9->rect.left = 10.0;
  v13 = v11 + 10.0;
  v14 = v12 + 350.0;
  v9->rect.right = v13;
  v9->rect.bottom = v14;
  if ( v10 == 0.0 && v9->rectBase.top == 0.0 )
  {
    v9->rectBase.left = 10.0;
    v9->rectBase.top = 350.0;
    v9->rectBase.right = v13;
    v9->rectBase.bottom = v14;
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Save CHASE_0", 0xCu);
  LOBYTE(v37) = 17;
  this->butSaveGlobal0->setText(this->butSaveGlobal0, &iname);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  *(_DWORD *)&v31[4] = &std::_Func_impl<std::_Callable_obj<_lambda_5d4300ca4f51594cb9ca8b3c898e5602_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v31[8] = this;
  *(_DWORD *)&v31[20] = &v31[4];
  LOBYTE(v37) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSaveGlobal0->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v31[4],
    this);
  v15 = (ksgui::Spinner *)operator new(0x118u);
  v34 = v15;
  v16 = 0;
  LOBYTE(v37) = 19;
  if ( v15 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Save chase 1", 0xCu);
    LOBYTE(v37) = 20;
    h = *(float *)&this->gui;
    v3 |= 0x10u;
    _Val = v3;
    ksgui::Control::Control(v15, &iname, (ksgui::GUI *)LODWORD(h));
  }
  this->butSaveGlobal1 = v16;
  v37 = 0;
  if ( (v3 & 0x10) != 0 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  _Val = (int)this->butSaveGlobal1;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ((void (*)(ksgui::Control *, int, int))this->butSaveGlobal1->setSize)(
    this->butSaveGlobal1,
    1125515264,
    1106247680);
  v17 = this->butSaveGlobal1;
  v18 = v17->rectBase.left;
  v19 = v17->rect.right - v17->rect.left;
  v20 = v17->rect.bottom - v17->rect.top;
  v17->rect.top = 350.0;
  v17->rect.left = 200.0;
  v21 = v19 + 200.0;
  v22 = v20 + 350.0;
  v17->rect.right = v21;
  v17->rect.bottom = v22;
  if ( v18 == 0.0 && v17->rectBase.top == 0.0 )
  {
    v17->rectBase.left = 200.0;
    v17->rectBase.top = 350.0;
    v17->rectBase.right = v21;
    v17->rectBase.bottom = v22;
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Save CHASE_1", 0xCu);
  LOBYTE(v37) = 22;
  this->butSaveGlobal1->setText(this->butSaveGlobal1, &iname);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  *(_DWORD *)&v31[4] = &std::_Func_impl<std::_Callable_obj<_lambda_cbbbee75040862a861784e2053a8fd34_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v31[8] = this;
  *(_DWORD *)&v31[20] = &v31[4];
  LOBYTE(v37) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSaveGlobal1->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v31[4],
    this);
  v23 = (ksgui::Spinner *)operator new(0x11Cu);
  v34 = v23;
  v24 = 0;
  LOBYTE(v37) = 24;
  if ( v23 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v31[24] = 7;
    *(_DWORD *)&v31[20] = 0;
    *(_WORD *)&v31[4] = 0;
    std::wstring::assign((std::wstring *)&v31[4], L"INACTIVE", 8u);
    ksgui::Label::Label((ksgui::Label *)v23, *(std::wstring *)&v31[4], (ksgui::GUI *)LODWORD(h));
  }
  LOBYTE(v37) = 0;
  this->labInactive = v24;
  _Val = (int)v24;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  v25 = this->labInactive;
  v26 = v25->rectBase.left;
  v27 = v25->rect.right - v25->rect.left;
  v28 = v25->rect.bottom - v25->rect.top;
  v25->rect.top = 200.0;
  v25->rect.left = 50.0;
  v29 = v27 + 50.0;
  v30 = v28 + 200.0;
  v25->rect.right = v29;
  v25->rect.bottom = v30;
  if ( v26 == 0.0 && v25->rectBase.top == 0.0 )
  {
    v25->rectBase.left = 50.0;
    v25->rectBase.top = 200.0;
    v25->rectBase.right = v29;
    v25->rectBase.bottom = v30;
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Select Chase Cam 0 to activate", 0x1Eu);
  LOBYTE(v37) = 25;
  this->labInactive->setText(this->labInactive, &iname);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
}
void ChaseCamEditor::render(ChaseCamEditor *this, float dt)
{
  ACCameraManager *v3; // eax
  CameraDrivableManager *v4; // eax
  bool v5; // bl
  ksgui::Control *v6; // ecx
  int v7; // edi
  ksgui::Control_vtbl *v8; // eax
  ksgui::Control *v9; // ecx
  ksgui::Control_vtbl *v10; // eax
  ksgui::Spinner *v11; // ecx
  ksgui::Spinner_vtbl *v12; // eax
  ksgui::Spinner *v13; // ecx
  ksgui::Spinner_vtbl *v14; // eax
  ksgui::Spinner *v15; // ecx
  ksgui::Spinner_vtbl *v16; // eax
  ksgui::Label *v17; // ecx
  __int64 v18; // [esp+1Ch] [ebp-10h]
  float v19; // [esp+24h] [ebp-8h]
  int is_visible; // [esp+28h] [ebp-4h]
  bool is_visiblea; // [esp+28h] [ebp-4h]

  v3 = this->sim->cameraManager;
  v5 = 0;
  if ( v3->mode == eDrivable )
  {
    v4 = v3->cameraDrivable;
    if ( v4->currentMode == eChase && !v4->chaseIndex )
      v5 = 1;
  }
  v6 = this->butSaveGlobal1;
  LOBYTE(is_visible) = v5;
  v7 = is_visible;
  if ( v6->visible != v5 )
  {
    v8 = v6->__vftable;
    v6->visible = v5;
    ((void (__stdcall *)(int))v8->onVisibleChanged)(is_visible);
  }
  v9 = this->butSaveGlobal0;
  if ( v9->visible != v5 )
  {
    v10 = v9->__vftable;
    v9->visible = v5;
    ((void (__stdcall *)(int))v10->onVisibleChanged)(is_visible);
  }
  v11 = this->spDistance;
  if ( v11->visible != v5 )
  {
    v12 = v11->__vftable;
    v11->visible = v5;
    ((void (__stdcall *)(int))v12->onVisibleChanged)(is_visible);
  }
  v13 = this->spPitch;
  if ( v13->visible != v5 )
  {
    v14 = v13->__vftable;
    v13->visible = v5;
    ((void (__stdcall *)(int))v14->onVisibleChanged)(is_visible);
  }
  v15 = this->spHeight;
  if ( v15->visible != v5 )
  {
    v16 = v15->__vftable;
    v15->visible = v5;
    ((void (__stdcall *)(int))v16->onVisibleChanged)(is_visible);
  }
  v17 = this->labInactive;
  if ( v17->visible != !v5 )
  {
    v17->visible = !v5;
    is_visiblea = !v5;
    v17->onVisibleChanged(v17, is_visiblea);
  }
  ksgui::Control::render(this, v7, (int)this, dt, v18, v19);
}
