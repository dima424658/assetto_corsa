#include "triplescreenmanager.h
void TripleScreenManager::TripleScreenManager(TripleScreenManager *this, Sim *sim)
{
  int v3; // ebx
  Game *v4; // eax
  const std::wstring *v5; // eax
  ksgui::Spinner *v6; // eax
  const std::wstring *v7; // eax
  ksgui::Spinner *v8; // eax
  ksgui::Label *v9; // eax
  const std::wstring *v10; // eax
  ksgui::Label *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  ksgui::Spinner *v17; // eax
  const std::wstring *v18; // eax
  ksgui::Label *v19; // eax
  const std::wstring *v20; // eax
  ksgui::Label *v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  ksgui::Spinner *v27; // eax
  const std::wstring *v28; // eax
  ksgui::Label *v29; // eax
  const std::wstring *v30; // eax
  ksgui::Label *v31; // ecx
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm4_4
  float v38; // xmm3_4
  ksgui::Spinner *v39; // eax
  const std::wstring *v40; // eax
  ksgui::Spinner *v41; // ebp
  ksgui::Label *v42; // eax
  const std::wstring *v43; // eax
  ksgui::Label *v44; // edx
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  Sim *v52; // ecx
  CameraForward *v53; // eax
  CameraTripleScreen *v54; // eax
  ksgui::Spinner *v55; // ecx
  float *v56; // esi
  float v57; // xmm0_4
  _BYTE v58[28]; // [esp+34h] [ebp-94h] BYREF
  float h; // [esp+50h] [ebp-78h]
  int _Val; // [esp+78h] [ebp-50h] BYREF
  ksgui::Spinner *v61; // [esp+7Ch] [ebp-4Ch]
  Sim *v62; // [esp+80h] [ebp-48h]
  TripleScreenManager *v63; // [esp+84h] [ebp-44h]
  std::wstring text; // [esp+88h] [ebp-40h] BYREF
  std::wstring result; // [esp+A0h] [ebp-28h] BYREF
  int v66; // [esp+C4h] [ebp-4h]

  v3 = 0;
  _Val = 0;
  h = 0.0;
  v63 = this;
  v4 = sim->game;
  v62 = sim;
  *(_DWORD *)&v58[24] = v4->gui;
  *(_DWORD *)&v58[20] = 7;
  *(_DWORD *)&v58[16] = 0;
  *(_WORD *)v58 = 0;
  std::wstring::assign((std::wstring *)v58, L"TRIPLE_SCREEN", 0xDu);
  ksgui::Form::Form(this, 0, *(std::wstring *)v58, *(ksgui::GUI **)&v58[24], SLOBYTE(h));
  v66 = 0;
  this->__vftable = (TripleScreenManager_vtbl *)&TripleScreenManager::`vftable';
  this->mainDisplayCenter.x = 0.0;
  this->mainDisplayCenter.y = 0.0;
  this->driverCenter.x = 0.0;
  this->driverCenter.y = 0.0;
  VirtualDisplay::VirtualDisplay(&this->centralDisplay);
  LOBYTE(v66) = 1;
  v61 = (ksgui::Spinner *)&this->leftVirtualDisplay;
  VirtualDisplay::VirtualDisplay(&this->leftVirtualDisplay);
  LOBYTE(v66) = 2;
  std::wstring::assign(&this->leftVirtualDisplay.type, L"LateralDisplay", 0xEu);
  LOBYTE(v66) = 3;
  v61 = (ksgui::Spinner *)&this->rightVirtualDisplay;
  VirtualDisplay::VirtualDisplay(&this->rightVirtualDisplay);
  LOBYTE(v66) = 4;
  std::wstring::assign(&this->rightVirtualDisplay.type, L"LateralDisplay", 0xEu);
  this->driverHead.kid = 0;
  this->driverHead.fileName._Myres = 7;
  this->driverHead.fileName._Mysize = 0;
  this->driverHead.fileName._Bx._Buf[0] = 0;
  LOBYTE(v66) = 6;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Triple screen", 0xDu);
  LOBYTE(v66) = 7;
  v5 = acTranslate(&result, &text);
  LOBYTE(v66) = 8;
  this->formTitle->setText(this->formTitle, v5);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->devApp = 0;
  ksgui::Form::setSize(this, 600.0, 700.0);
  std::shared_ptr<Font>::operator=(&this->font, &this->gui->ksgui::Form::ksgui::Control::font);
  this->sim = sim;
  v61 = (ksgui::Spinner *)operator new(0x1BCu);
  LOBYTE(v66) = 9;
  if ( v61 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"ROTATION_SPINNER", 0x10u);
    h = 0.0;
    LOBYTE(v66) = 10;
    v3 = 1;
    *(_DWORD *)&v58[24] = 0;
    *(_DWORD *)&v58[20] = this->gui;
    _Val = 1;
    ksgui::Spinner::Spinner(v61, &text, *(ksgui::GUI **)&v58[20], 0, 0);
  }
  else
  {
    v6 = 0;
  }
  this->spRotation = v6;
  v66 = 6;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"ANGLE", 5u);
  LOBYTE(v66) = 12;
  v7 = acTranslate(&result, &text);
  LOBYTE(v66) = 13;
  this->spRotation->setText(this->spRotation, v7);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Spinner::setPosition(this->spRotation, 30.0, 420.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spRotation->setSize)(this->spRotation, 1128792064, 1106247680);
  v8 = this->spRotation;
  LODWORD(h) = &_Val;
  v8->minValue = 0;
  this->spRotation->maxValue = 90;
  _Val = (int)this->spRotation;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)LODWORD(h));
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v61 = (ksgui::Spinner *)operator new(LODWORD(h));
  LOBYTE(v66) = 14;
  if ( v61 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v58[24] = 7;
    *(_DWORD *)&v58[20] = 0;
    *(_WORD *)&v58[4] = 0;
    std::wstring::assign((std::wstring *)&v58[4], L"HELP_ROTATION", 0xDu);
    ksgui::Label::Label((ksgui::Label *)v61, *(std::wstring *)&v58[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v9 = 0;
  }
  LOBYTE(v66) = 6;
  this->helpRotation = v9;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Angle between central \n and lateral displays (deg)", 0x32u);
  LOBYTE(v66) = 15;
  v10 = acTranslate(&result, &text);
  LOBYTE(v66) = 16;
  this->helpRotation->setText(this->helpRotation, v10);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->helpRotation->fontAlign = eAlignCenter;
  v11 = this->helpRotation;
  v12 = v11->rectBase.left;
  v13 = v11->rect.right - v11->rect.left;
  v14 = v11->rect.bottom - v11->rect.top;
  v11->rect.top = 460.0;
  v11->rect.left = 30.0;
  v15 = v13 + 30.0;
  v16 = v14 + 460.0;
  v11->rect.right = v15;
  v11->rect.bottom = v16;
  if ( v12 == 0.0 && v11->rectBase.top == 0.0 )
  {
    v11->rectBase.left = 30.0;
    v11->rectBase.top = 460.0;
    v11->rectBase.right = v15;
    v11->rectBase.bottom = v16;
  }
  _Val = (int)this->helpRotation;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 444;
  *(_DWORD *)(_Val + 148) = this;
  v61 = (ksgui::Spinner *)operator new(LODWORD(h));
  LOBYTE(v66) = 17;
  if ( v61 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"SPINNER_SCREEN_WIDTH", 0x14u);
    h = 0.0;
    LOBYTE(v66) = 18;
    v3 |= 2u;
    *(_DWORD *)&v58[24] = 0;
    *(_DWORD *)&v58[20] = this->gui;
    _Val = v3;
    ksgui::Spinner::Spinner(v61, &text, *(ksgui::GUI **)&v58[20], 0, 0);
  }
  else
  {
    v17 = 0;
  }
  this->spScreenWidth = v17;
  v66 = 6;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"SCREEN WIDTH", 0xCu);
  LOBYTE(v66) = 20;
  v18 = acTranslate(&result, &text);
  LOBYTE(v66) = 21;
  this->spScreenWidth->setText(this->spScreenWidth, v18);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Spinner::setPosition(this->spScreenWidth, 30.0, 570.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spScreenWidth->setSize)(
    this->spScreenWidth,
    1128792064,
    1106247680);
  this->spScreenWidth->minValue = 0;
  this->spScreenWidth->maxValue = 3000;
  _Val = (int)this->spScreenWidth;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v61 = (ksgui::Spinner *)operator new(LODWORD(h));
  LOBYTE(v66) = 22;
  if ( v61 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v58[24] = 7;
    *(_DWORD *)&v58[20] = 0;
    *(_WORD *)&v58[4] = 0;
    std::wstring::assign((std::wstring *)&v58[4], L"HELP_WIDTH", 0xAu);
    ksgui::Label::Label((ksgui::Label *)v61, *(std::wstring *)&v58[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v19 = 0;
  }
  LOBYTE(v66) = 6;
  this->helpWidth = v19;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Width of each screen \n (mm)", 0x1Bu);
  LOBYTE(v66) = 23;
  v20 = acTranslate(&result, &text);
  LOBYTE(v66) = 24;
  this->helpWidth->setText(this->helpWidth, v20);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->helpWidth->fontAlign = eAlignCenter;
  v21 = this->helpWidth;
  v22 = v21->rectBase.left;
  v23 = v21->rect.right - v21->rect.left;
  v24 = v21->rect.bottom - v21->rect.top;
  v21->rect.top = 610.0;
  v21->rect.left = 30.0;
  v25 = v23 + 30.0;
  v26 = v24 + 610.0;
  v21->rect.right = v25;
  v21->rect.bottom = v26;
  if ( v22 == 0.0 && v21->rectBase.top == 0.0 )
  {
    v21->rectBase.left = 30.0;
    v21->rectBase.top = 610.0;
    v21->rectBase.right = v25;
    v21->rectBase.bottom = v26;
  }
  _Val = (int)this->helpWidth;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 444;
  *(_DWORD *)(_Val + 148) = this;
  v61 = (ksgui::Spinner *)operator new(LODWORD(h));
  LOBYTE(v66) = 25;
  if ( v61 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DISTANCE_SPINNER", 0x10u);
    h = 0.0;
    LOBYTE(v66) = 26;
    v3 |= 4u;
    *(_DWORD *)&v58[24] = 0;
    *(_DWORD *)&v58[20] = this->gui;
    _Val = v3;
    ksgui::Spinner::Spinner(v61, &text, *(ksgui::GUI **)&v58[20], 0, 0);
  }
  else
  {
    v27 = 0;
  }
  this->spDistance = v27;
  v66 = 6;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"DISTANCE", 8u);
  LOBYTE(v66) = 28;
  v28 = acTranslate(&result, &text);
  LOBYTE(v66) = 29;
  this->spDistance->setText(this->spDistance, v28);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ksgui::Spinner *, int, int))this->spDistance->setSize)(this->spDistance, 1128792064, 1106247680);
  ksgui::Spinner::setPosition(
    this->spDistance,
    (float)((float)(this->rect.right - this->rect.left)
          - (float)(this->spDistance->rect.right - this->spDistance->rect.left))
  - 30.0,
    420.0);
  this->spDistance->minValue = 0;
  this->spDistance->maxValue = 3000;
  _Val = (int)this->spDistance;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v61 = (ksgui::Spinner *)operator new(LODWORD(h));
  LOBYTE(v66) = 30;
  if ( v61 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v58[24] = 7;
    *(_DWORD *)&v58[20] = 0;
    *(_WORD *)&v58[4] = 0;
    std::wstring::assign((std::wstring *)&v58[4], L"HELP_DISTANCE", 0xDu);
    ksgui::Label::Label((ksgui::Label *)v61, *(std::wstring *)&v58[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v29 = 0;
  }
  LOBYTE(v66) = 6;
  this->helpDistance = v29;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Distance between central \n display and the player (mm)", 0x36u);
  LOBYTE(v66) = 31;
  v30 = acTranslate(&result, &text);
  LOBYTE(v66) = 32;
  this->helpDistance->setText(this->helpDistance, v30);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->helpDistance->fontAlign = eAlignCenter;
  v31 = this->helpDistance;
  v32 = v31->rect.right - v31->rect.left;
  v33 = v31->rect.bottom - v31->rect.top;
  v34 = (float)(this->rect.right - this->rect.left)
      - (float)(this->spDistance->rect.right - this->spDistance->rect.left);
  v31->rect.top = 460.0;
  v35 = v31->rectBase.left;
  v36 = v34 - 30.0;
  v37 = v33 + 460.0;
  v31->rect.left = v36;
  v38 = v32 + v36;
  v31->rect.bottom = v37;
  v31->rect.right = v38;
  if ( v35 == 0.0 && v31->rectBase.top == 0.0 )
  {
    v31->rectBase.left = v36;
    v31->rectBase.top = 460.0;
    v31->rectBase.right = v38;
    v31->rectBase.bottom = v37;
  }
  _Val = (int)this->helpDistance;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 444;
  *(_DWORD *)(_Val + 148) = this;
  v61 = (ksgui::Spinner *)operator new(LODWORD(h));
  LOBYTE(v66) = 33;
  if ( v61 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"MARGIN_SPINNER", 0xEu);
    h = 0.0;
    LOBYTE(v66) = 34;
    v3 |= 8u;
    *(_DWORD *)&v58[24] = 0;
    *(_DWORD *)&v58[20] = this->gui;
    _Val = v3;
    ksgui::Spinner::Spinner(v61, &text, *(ksgui::GUI **)&v58[20], 0, 0);
  }
  else
  {
    v39 = 0;
  }
  this->spMargins = v39;
  v66 = 6;
  if ( (v3 & 8) != 0 && text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  std::wstring::wstring(&text, L"MARGINS");
  LOBYTE(v66) = 36;
  v40 = acTranslate(&result, &text);
  LOBYTE(v66) = 37;
  this->spMargins->setText(this->spMargins, v40);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ksgui::Spinner *, int, int))this->spMargins->setSize)(this->spMargins, 1128792064, 1106247680);
  ksgui::Spinner::setPosition(
    this->spMargins,
    (float)((float)(this->rect.right - this->rect.left)
          - (float)(this->spMargins->rect.right - this->spMargins->rect.left))
  - 30.0,
    570.0);
  this->spMargins->minValue = -1000;
  this->spMargins->maxValue = 1000;
  _Val = (int)this->spMargins;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v41 = (ksgui::Spinner *)operator new(LODWORD(h));
  v61 = v41;
  LOBYTE(v66) = 38;
  if ( v41 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v58[4], L"HELP_MARGINS");
    ksgui::Label::Label((ksgui::Label *)v41, *(std::wstring *)&v58[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v42 = 0;
  }
  LOBYTE(v66) = 6;
  LODWORD(h) = L"Margin of each \n display/Bezel (mm)";
  this->helpMargins = v42;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(h));
  LOBYTE(v66) = 39;
  v43 = acTranslate(&result, &text);
  LOBYTE(v66) = 40;
  this->helpMargins->setText(this->helpMargins, v43);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v66) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->helpMargins->fontAlign = eAlignCenter;
  v44 = this->helpMargins;
  v45 = v44->rect.right - v44->rect.left;
  v46 = v44->rect.bottom - v44->rect.top;
  v47 = (float)(this->rect.right - this->rect.left)
      - (float)(this->spDistance->rect.right - this->spDistance->rect.left);
  v44->rect.top = 610.0;
  v48 = v44->rectBase.left;
  v49 = v47 - 30.0;
  v50 = v46 + 610.0;
  v44->rect.left = v49;
  v51 = v45 + v49;
  v44->rect.bottom = v50;
  v44->rect.right = v51;
  if ( v48 == 0.0 && v44->rectBase.top == 0.0 )
  {
    v44->rectBase.left = v49;
    v44->rectBase.top = 610.0;
    v44->rectBase.right = v51;
    v44->rectBase.bottom = v50;
  }
  _Val = (int)this->helpMargins;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  v52 = v62;
  h = 0.0;
  *(_DWORD *)&v58[24] = &CameraTripleScreen `RTTI Type Descriptor';
  *(_DWORD *)&v58[20] = &Camera `RTTI Type Descriptor';
  *(_DWORD *)&v58[16] = 0;
  *(_DWORD *)(_Val + 148) = this;
  v53 = Sim::getSceneCamera(v52);
  v54 = (CameraTripleScreen *)__RTDynamicCast(
                                v53,
                                *(_DWORD *)&v58[16],
                                *(_DWORD *)&v58[20],
                                *(_DWORD *)&v58[24],
                                LODWORD(h));
  v55 = this->spDistance;
  v56 = (float *)v54;
  this->tsCamera = v54;
  ksgui::Spinner::setValue(v55, (int)(float)(v54->tripleScreen.screens[1].left.y * 1000.0));
  v57 = v56[852] - v56[854];
  ksgui::Spinner::setValue(
    this->spScreenWidth,
    (int)(float)(fsqrt((float)((float)(v56[851] - v56[853]) * (float)(v56[851] - v56[853])) + (float)(v57 * v57))
               * 1000.0));
  ksgui::Spinner::setValue(this->spRotation, 0);
  ksgui::Spinner::setValue(this->spMargins, 0);
  *(_DWORD *)&v58[4] = &std::_Func_impl<std::_Callable_obj<_lambda_23e776f362589beac0a905822178c0c1_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v58[8] = this;
  *(_DWORD *)&v58[20] = &v58[4];
  LOBYTE(v66) = 6;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spRotation->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v58[4],
    this);
  *(_DWORD *)&v58[4] = &std::_Func_impl<std::_Callable_obj<_lambda_e4259459b8b90148ff700e9e5b5051f5_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v58[8] = this;
  *(_DWORD *)&v58[20] = &v58[4];
  LOBYTE(v66) = 6;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spScreenWidth->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v58[4],
    this);
  *(_DWORD *)&v58[4] = &std::_Func_impl<std::_Callable_obj<_lambda_fc76229021f6c517e9c24007c8695db8_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v58[8] = this;
  *(_DWORD *)&v58[20] = &v58[4];
  LOBYTE(v66) = 6;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spDistance->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v58[4],
    this);
  *(_DWORD *)&v58[4] = &std::_Func_impl<std::_Callable_obj<_lambda_e64a5c5f931b39b099847573e8d90873_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v58[8] = this;
  *(_DWORD *)&v58[20] = &v58[4];
  LOBYTE(v66) = 6;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spMargins->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v58[4],
    this);
  ((void (*)(ksgui::Spinner *, int))this->spRotation->setRepeatInterval)(this->spRotation, 1036831949);
  ((void (*)(ksgui::Spinner *, int))this->spScreenWidth->setRepeatInterval)(this->spScreenWidth, 1008981770);
  ((void (*)(ksgui::Spinner *, int))this->spDistance->setRepeatInterval)(this->spDistance, 1008981770);
  ((void (*)(ksgui::Spinner *, int))this->spMargins->setRepeatInterval)(this->spMargins, 1028443341);
  TripleScreenManager::initGraphicalComponents(this);
  TripleScreenManager::updateGraphicalInterfaceData(this);
}
TripleScreenManager *TripleScreenManager::`vector deleting destructor'(TripleScreenManager *this, unsigned int a2)
{
  TripleScreenManager::~TripleScreenManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TripleScreenManager::initGraphicalComponents(TripleScreenManager *this)
{
  char v2; // bl
  bool v3; // al
  int v4; // ebx
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  Texture *v8; // eax
  void *v9; // ecx
  const std::wstring *v10; // eax
  std::wstring v11; // [esp-1Ch] [ebp-D0h] BYREF
  BOOL v12; // [esp-4h] [ebp-B8h]
  char v13; // [esp+17h] [ebp-9Dh]
  int v14; // [esp+18h] [ebp-9Ch]
  int v15; // [esp+1Ch] [ebp-98h]
  std::wstring section; // [esp+20h] [ebp-94h] BYREF
  Texture key; // [esp+38h] [ebp-7Ch] BYREF
  INIReaderDocuments r; // [esp+54h] [ebp-60h] BYREF
  int v19; // [esp+B0h] [ebp-4h]

  v2 = 0;
  v12 = 0;
  v14 = 0;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"cfg/triple_screen.ini", 0x15u);
  INIReaderDocuments::INIReaderDocuments(&r, 0, v11, v12);
  v19 = 0;
  if ( !r.ready )
    goto LABEL_3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SPINNERS", 8u);
  LOBYTE(v19) = 1;
  v2 = 1;
  v14 = 1;
  v3 = INIReader::hasSection(&r, &section);
  v13 = 1;
  if ( !v3 )
LABEL_3:
    v13 = 0;
  v19 = 0;
  if ( (v2 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v13 )
  {
    key.fileName._Mysize = 7;
    *(_DWORD *)&key.fileName._Bx._Alias[12] = 0;
    LOWORD(key.kid) = 0;
    std::wstring::assign((std::wstring *)&key, L"SP_DISTANCE", 0xBu);
    LOBYTE(v19) = 2;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SPINNERS", 8u);
    LOBYTE(v19) = 3;
    v4 = INIReader::getInt(&r, &section, (const std::wstring *)&key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    LOBYTE(v19) = 0;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key.fileName._Mysize >= 8 )
      operator delete(key.kid);
    if ( v4 > 0 )
      ksgui::Spinner::setValue(this->spDistance, v4);
    key.fileName._Mysize = 7;
    *(_DWORD *)&key.fileName._Bx._Alias[12] = 0;
    LOWORD(key.kid) = 0;
    std::wstring::assign((std::wstring *)&key, L"SP_WIDTH", 8u);
    LOBYTE(v19) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SPINNERS", 8u);
    LOBYTE(v19) = 5;
    v5 = INIReader::getInt(&r, &section, (const std::wstring *)&key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    LOBYTE(v19) = 0;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key.fileName._Mysize >= 8 )
      operator delete(key.kid);
    if ( v5 > 0 )
      ksgui::Spinner::setValue(this->spScreenWidth, v5);
    key.fileName._Mysize = 7;
    *(_DWORD *)&key.fileName._Bx._Alias[12] = 0;
    LOWORD(key.kid) = 0;
    std::wstring::assign((std::wstring *)&key, L"SP_MARGINS", 0xAu);
    LOBYTE(v19) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SPINNERS", 8u);
    LOBYTE(v19) = 7;
    v6 = INIReader::getInt(&r, &section, (const std::wstring *)&key);
    ksgui::Spinner::setValue(this->spMargins, v6);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    LOBYTE(v19) = 0;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key.fileName._Mysize >= 8 )
      operator delete(key.kid);
    key.fileName._Mysize = 7;
    *(_DWORD *)&key.fileName._Bx._Alias[12] = 0;
    LOWORD(key.kid) = 0;
    std::wstring::assign((std::wstring *)&key, L"SP_ROTATION", 0xBu);
    LOBYTE(v19) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SPINNERS", 8u);
    LOBYTE(v19) = 9;
    v7 = INIReader::getInt(&r, &section, (const std::wstring *)&key);
    ksgui::Spinner::setValue(this->spRotation, v7);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    LOBYTE(v19) = 0;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key.fileName._Mysize >= 8 )
      operator delete(key.kid);
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"content/gui/triplescreenManager/headHelmet.png", 0x2Eu);
  LOBYTE(v19) = 10;
  v8 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &key, &section, 0);
  LOBYTE(v19) = 11;
  v9 = v8->kid;
  v10 = &v8->fileName;
  this->driverHead.kid = v9;
  if ( &this->driverHead.fileName != v10 )
    std::wstring::assign(&this->driverHead.fileName, v10, 0, 0xFFFFFFFF);
  LOBYTE(v19) = 10;
  OnSetupAppCreated::~OnSetupAppCreated(&key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v14 = 1133576192;
  section._Bx._Buf[0] = 0;
  this->mainDisplayCenter.x = 290.0;
  v15 = 1125515264;
  section._Myres = 7;
  section._Mysize = 0;
  this->mainDisplayCenter.y = 150.0;
  this->isModified = 0;
  v19 = -1;
  INIReaderDocuments::~INIReaderDocuments(&r);
}
void TripleScreenManager::~TripleScreenManager(TripleScreenManager *this)
{
  TripleScreenData *v2; // edi
  std::wstring *v3; // eax
  std::ostream *v4; // eax
  std::ostream *v5; // eax
  int v6; // eax
  std::ostream *v7; // eax
  std::ostream *v8; // eax
  std::ostream *v9; // eax
  std::ostream *v10; // eax
  int v11; // eax
  std::ostream *v12; // eax
  std::ostream *v13; // eax
  std::ostream *v14; // eax
  int v15; // eax
  std::ostream *v16; // eax
  std::ostream *v17; // eax
  std::ostream *v18; // eax
  std::ostream *v19; // eax
  int v20; // eax
  std::ostream *v21; // eax
  std::ostream *v22; // eax
  std::ostream *v23; // eax
  int v24; // eax
  std::ostream *v25; // eax
  std::ostream *v26; // eax
  std::ostream *v27; // eax
  std::ostream *v28; // eax
  int v29; // eax
  std::ostream *v30; // eax
  std::ostream *v31; // eax
  std::ostream *v32; // eax
  int v33; // eax
  std::ostream *v34; // eax
  ksgui::Spinner *v35; // eax
  std::ostream *v36; // eax
  int v37; // eax
  ksgui::Spinner *v38; // eax
  std::ostream *v39; // eax
  int v40; // eax
  ksgui::Spinner *v41; // eax
  std::ostream *v42; // eax
  int v43; // eax
  ksgui::Spinner *v44; // eax
  std::ostream *v45; // eax
  int v46; // eax
  char *_Val; // [esp+68h] [ebp-110h]
  const char *v48; // [esp+6Ch] [ebp-10Ch]
  char *v49; // [esp+70h] [ebp-108h]
  char *v50; // [esp+70h] [ebp-108h]
  const char *v51; // [esp+74h] [ebp-104h]
  int v52; // [esp+78h] [ebp-100h]
  int v53; // [esp+78h] [ebp-100h]
  const char *v54; // [esp+78h] [ebp-100h]
  int v55; // [esp+78h] [ebp-100h]
  int v56; // [esp+78h] [ebp-100h]
  int v57; // [esp+78h] [ebp-100h]
  int v58; // [esp+78h] [ebp-100h]
  std::ostream _Ostr; // [esp+7Ch] [ebp-FCh] BYREF
  char v60[72]; // [esp+F0h] [ebp-88h] BYREF
  std::wstring filename; // [esp+138h] [ebp-40h] BYREF
  std::wstring result; // [esp+150h] [ebp-28h] BYREF
  int v63; // [esp+174h] [ebp-4h]

  *(_DWORD *)&_Ostr.gap0[16] = this;
  this->__vftable = (TripleScreenManager_vtbl *)&TripleScreenManager::`vftable';
  v63 = 4;
  v2 = &this->tsCamera->tripleScreen;
  if ( this->isModified )
  {
    v3 = Path::getDocumentPath(&result);
    LOBYTE(v63) = 5;
    std::operator+<wchar_t>(&filename, v3, L"/Assetto Corsa/cfg/triple_screen.ini");
    LOBYTE(v63) = 7;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    std::ofstream::ofstream((std::ofstream *)&_Ostr.gap0[20], &filename, 2, 64, 1);
    LOBYTE(v63) = 8;
    v4 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[20], "[TRIPLE_SCREEN]");
    std::ostream::operator<<(v4, std::endl<char,std::char_traits<char>>);
    *(_DWORD *)_Ostr.gap0 = std::endl<char,std::char_traits<char>>;
    v5 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[20], "ACTIVE=1");
    v6 = std::ostream::operator<<(v5, std::endl<char,std::char_traits<char>>);
    std::ostream::operator<<(v6, v52);
    v7 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[12], "[LEFT_SCREEN]");
    std::ostream::operator<<(v7, std::endl<char,std::char_traits<char>>);
    v49 = (char *)LODWORD(v2->screens[0].left.y);
    _Val = (char *)LODWORD(v2->screens[0].left.x);
    v8 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[12], "LEFT_POINT=");
    v9 = (std::ostream *)std::ostream::operator<<(v8);
    v10 = std::operator<<<std::char_traits<char>>(v9, _Val);
    v11 = std::ostream::operator<<(v10);
    std::ostream::operator<<(v11, ",");
    v12 = std::operator<<<std::char_traits<char>>(&_Ostr, "RIGHT_POINT=");
    v13 = (std::ostream *)std::ostream::operator<<(v12);
    v14 = std::operator<<<std::char_traits<char>>(v13, v48);
    v15 = std::ostream::operator<<(v14);
    std::ostream::operator<<(v15, v49);
    std::ostream::operator<<(&_Ostr.gap0[4], std::endl<char,std::char_traits<char>>);
    v16 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "[CENTER_SCREEN]");
    std::ostream::operator<<(v16, std::endl<char,std::char_traits<char>>);
    v17 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "LEFT_POINT=");
    v18 = (std::ostream *)std::ostream::operator<<(v17);
    v19 = std::operator<<<std::char_traits<char>>(v18, v50);
    v20 = std::ostream::operator<<(v19);
    std::ostream::operator<<(v20, std::endl<char,std::char_traits<char>>);
    v21 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[8], "RIGHT_POINT=");
    v22 = (std::ostream *)std::ostream::operator<<(v21);
    v23 = std::operator<<<std::char_traits<char>>(v22, v51);
    v24 = std::ostream::operator<<(v23);
    std::ostream::operator<<(v24, v53);
    std::ostream::operator<<(&_Ostr.gap0[12], std::endl<char,std::char_traits<char>>);
    v25 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[12], "[RIGHT_SCREEN]");
    std::ostream::operator<<(v25, std::endl<char,std::char_traits<char>>);
    v26 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[12], "LEFT_POINT=");
    v27 = (std::ostream *)std::ostream::operator<<(v26);
    v28 = std::operator<<<std::char_traits<char>>(v27, v54);
    v29 = std::ostream::operator<<(v28);
    std::ostream::operator<<(v29, *(_DWORD *)_Ostr.gap0);
    v30 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[16], "RIGHT_POINT=");
    v31 = (std::ostream *)std::ostream::operator<<(v30);
    v32 = std::operator<<<std::char_traits<char>>(v31, *(const char **)_Ostr.gap0);
    v33 = std::ostream::operator<<(v32);
    std::ostream::operator<<(v33, *(_DWORD *)&_Ostr.gap0[4]);
    std::ostream::operator<<(&_Ostr.gap0[20], std::endl<char,std::char_traits<char>>);
    *(_DWORD *)_Ostr.gap0 = std::endl<char,std::char_traits<char>>;
    v34 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[20], "[SPINNERS]");
    std::ostream::operator<<(v34, *(_DWORD *)_Ostr.gap0);
    v35 = this->spMargins;
    *(_DWORD *)_Ostr.gap0 = std::endl<char,std::char_traits<char>>;
    v55 = v35->value;
    v36 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[20], "SP_MARGINS=");
    v37 = std::ostream::operator<<(v36, v55, *(_DWORD *)_Ostr.gap0);
    std::ostream::operator<<(v37, *(_DWORD *)&_Ostr.gap0[4]);
    v38 = this->spRotation;
    *(_DWORD *)_Ostr.gap0 = std::endl<char,std::char_traits<char>>;
    v56 = v38->value;
    v39 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[20], "SP_ROTATION=");
    v40 = std::ostream::operator<<(v39, v56, *(_DWORD *)_Ostr.gap0);
    std::ostream::operator<<(v40, *(_DWORD *)&_Ostr.gap0[4]);
    v41 = this->spDistance;
    *(_DWORD *)_Ostr.gap0 = std::endl<char,std::char_traits<char>>;
    v57 = v41->value;
    v42 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[20], "SP_DISTANCE=");
    v43 = std::ostream::operator<<(v42, v57, *(_DWORD *)_Ostr.gap0);
    std::ostream::operator<<(v43, *(_DWORD *)&_Ostr.gap0[4]);
    v44 = this->spScreenWidth;
    *(_DWORD *)_Ostr.gap0 = std::endl<char,std::char_traits<char>>;
    v58 = v44->value;
    v45 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[20], "SP_WIDTH=");
    v46 = std::ostream::operator<<(v45, v58, *(_DWORD *)_Ostr.gap0);
    std::ostream::operator<<(v46, *(_DWORD *)&_Ostr.gap0[4]);
    std::ofstream::close((std::ofstream *)&_Ostr.gap0[20]);
    std::ofstream::~ofstream<char,std::char_traits<char>>((std::ofstream *)v60);
    std::ios::~ios<char,std::char_traits<char>>(v60);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
  }
  LOBYTE(v63) = 3;
  OnSetupAppCreated::~OnSetupAppCreated(&this->driverHead);
  VirtualDisplay::~VirtualDisplay(&this->rightVirtualDisplay);
  VirtualDisplay::~VirtualDisplay(&this->leftVirtualDisplay);
  VirtualDisplay::~VirtualDisplay(&this->centralDisplay);
  v63 = -1;
  this->__vftable = (TripleScreenManager_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void TripleScreenManager::onSpinnerValueChanged(TripleScreenManager *this, const ksgui::OnSpinnerValueChanged *ev)
{
  float *v3; // esi
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // [esp+Ch] [ebp-74h]
  float v14; // [esp+Ch] [ebp-74h]
  float v15; // [esp+10h] [ebp-70h]
  float v16; // [esp+10h] [ebp-70h]
  float v17; // [esp+1Ch] [ebp-64h]
  float v18; // [esp+28h] [ebp-58h]
  float v19; // [esp+28h] [ebp-58h]
  float v20; // [esp+2Ch] [ebp-54h]
  float v21; // [esp+30h] [ebp-50h]
  float v22; // [esp+34h] [ebp-4Ch]
  float v23; // [esp+38h] [ebp-48h]
  float v24; // [esp+3Ch] [ebp-44h]
  mat44f v25; // [esp+40h] [ebp-40h] BYREF

  v3 = (float *)&this->tsCamera->tripleScreen;
  v4 = (float)this->spScreenWidth->value * 0.001;
  v5 = (float)((float)this->gui->graphics->videoSettings.height
             / (float)((float)this->gui->graphics->videoSettings.width * 0.33333334))
     * v4;
  v13 = (float)this->spMargins->value * 0.001;
  v20 = (float)this->spDistance->value * 0.001;
  v3[5] = v4 * -0.5;
  v3[6] = v20;
  v23 = v4 * 0.5;
  v3[7] = v4 * 0.5;
  v17 = v4;
  v3[8] = v20;
  v3[9] = v5;
  v15 = __libm_sse2_cosf().m128_f32[0];
  v18 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&v25);
  v6 = (float)(1.0 - v15) * 0.0;
  v7 = (float)((float)((float)((float)((float)(v18 * 0.0) + v6) * 0.0) + (float)((float)(v6 - v18) * -1.0))
             + (float)((float)(v6 + v15) * 0.0))
     + v25.M43;
  v8 = (float)(v4 * -0.5) - (float)(v13 * 0.5);
  v14 = v13 * 0.5;
  v9 = (float)((float)((float)((float)(v6 - (float)(v18 * 0.0)) * 0.0) + (float)((float)(v6 + v15) * -1.0))
             + (float)((float)(v18 + v6) * 0.0))
     + v25.M41;
  v3[2] = (float)(v9 * v14) + v8;
  v3[3] = (float)(v7 * v14) + v20;
  v22 = v3[3] + (float)(v7 * v4);
  *v3 = (float)(v9 * v4) + v3[2];
  v3[4] = v5;
  v3[1] = v22;
  v16 = __libm_sse2_cosf().m128_f32[0];
  v19 = __libm_sse2_sinf().m128_f32[0];
  v21 = 1.0 - v16;
  mat44f::mat44f(&v25);
  v10 = (float)((float)(1.0 - v16) * 0.0) + v16;
  v11 = (float)((float)((float)((float)((float)(v19 * 0.0) + (float)(v21 * 0.0)) * 0.0)
                      + (float)((float)(v21 * 0.0) - v19))
              + (float)(v10 * 0.0))
      + v25.M43;
  v12 = (float)((float)((float)((float)((float)(v21 * 0.0) - (float)(v19 * 0.0)) * 0.0) + v10)
              + (float)((float)(v19 + (float)(v21 * 0.0)) * 0.0))
      + v25.M41;
  v3[10] = (float)(v12 * v14) + (float)(v14 + v23);
  v3[11] = (float)(v11 * v14) + v20;
  v24 = v3[11] + (float)(v11 * v17);
  v3[12] = (float)(v12 * v17) + v3[10];
  v3[13] = v24;
  v3[14] = v5;
  this->isModified = 1;
  TripleScreenManager::updateGraphicalInterfaceData(this);
}
void __userpurge TripleScreenManager::render(TripleScreenManager *this@<ecx>, int a2@<edi>, float dt)
{
  __int64 v4; // [esp+4h] [ebp-8h]
  float savedregs; // [esp+Ch] [ebp+0h]

  if ( Sim::isInTripleScreenMode(this->sim) )
  {
    ksgui::Control::render(this, a2, (int)this, dt, v4, savedregs);
    TripleScreenManager::drawVirtualDisplay(this, &this->centralDisplay);
    TripleScreenManager::drawVirtualDisplay(this, &this->leftVirtualDisplay);
    TripleScreenManager::drawVirtualDisplay(this, &this->rightVirtualDisplay);
    TripleScreenManager::drawDriverHead(
      this,
      (float)((float)((float)this->spDistance->value * 0.00033333333) * 200.0) * 2.0);
  }
}
void TripleScreenManager::updateGraphicalInterfaceData(TripleScreenManager *this)
{
  float v2; // xmm7_4
  float v3; // xmm2_4
  vec2f v4; // [esp-8h] [ebp-20h]
  int v5; // [esp+0h] [ebp-18h]
  int v6; // [esp+0h] [ebp-18h]

  v2 = (float)((float)this->spMargins->value * 0.00033333333) * 200.0;
  v3 = (float)((float)this->spScreenWidth->value * 0.00033333333) * 200.0;
  VirtualDisplay::updateData(&this->centralDisplay, v2, v3, this->mainDisplayCenter);
  VirtualDisplay::updateData(
    &this->leftVirtualDisplay,
    v2,
    v3,
    (vec2f)(COERCE_UNSIGNED_INT((float)(this->mainDisplayCenter.x - v3) - (float)(v2 * 2.0)) | 0x4316000000000000i64));
  v4.y = 150.0;
  v4.x = (float)((float)(v2 * 2.0) + this->mainDisplayCenter.x) + v3;
  VirtualDisplay::updateData(&this->rightVirtualDisplay, v2, v3, v4);
  TripleScreenManager::rotateLateralScreen((TripleScreenManager *)&this->leftVirtualDisplay, (VirtualDisplay *)2, v5);
  TripleScreenManager::rotateLateralScreen((TripleScreenManager *)&this->rightVirtualDisplay, (VirtualDisplay *)3, v6);
}
void __usercall TripleScreenManager::drawDriverHead(TripleScreenManager *this@<ecx>, float a2@<xmm1>)
{
  GraphicsManager *v4; // ecx
  GLRenderer *v5; // edi
  float v6; // xmm1_4
  float v7; // xmm0_4

  v4 = this->gui->graphics;
  v5 = v4->gl;
  GraphicsManager::setTexture(v4, 0, &this->driverHead);
  v6 = this->centralDisplay.screenDepth;
  v7 = this->rect.top + 150.0;
  this->driverCenter.x = this->rect.left + 290.0;
  this->driverCenter.y = (float)((float)(v6 * 0.5) + v7) + a2;
  GLRenderer::quad(v5, this->driverCenter.x - 25.0, this->driverCenter.y, 50.0, 50.0, 1, 0);
  GLRenderer::color4f(v5, 1.0, 1.0, 0.0, 0.80000001);
  GLRenderer::begin(v5, eTriangles, 0);
  GLRenderer::vertex3f(v5, this->driverCenter.x, this->driverCenter.y, 0.0);
  GLRenderer::vertex3f(
    v5,
    this->rect.left + this->leftVirtualDisplay.visibleVertices._Myfirst[3].x,
    this->rect.top + this->leftVirtualDisplay.visibleVertices._Myfirst[3].y,
    0.0);
  GLRenderer::vertex3f(
    v5,
    this->rect.left + this->rightVirtualDisplay.visibleVertices._Myfirst[2].x,
    this->rect.top + this->rightVirtualDisplay.visibleVertices._Myfirst[2].y,
    0.0);
  GLRenderer::end(v5);
  GLRenderer::begin(v5, eQuads, 0);
  GLRenderer::vertex3f(
    v5,
    this->rect.left + this->leftVirtualDisplay.visibleVertices._Myfirst[3].x,
    this->rect.top + this->leftVirtualDisplay.visibleVertices._Myfirst[3].y,
    0.0);
  GLRenderer::vertex3f(
    v5,
    this->rect.left + this->leftVirtualDisplay.displayVertices._Myfirst[2].x,
    this->rect.top + this->leftVirtualDisplay.displayVertices._Myfirst[2].y,
    0.0);
  GLRenderer::vertex3f(
    v5,
    this->rect.left + this->centralDisplay.displayVertices._Myfirst[2].x,
    this->rect.top + this->centralDisplay.displayVertices._Myfirst[2].y,
    0.0);
  GLRenderer::vertex3f(
    v5,
    this->rect.left + this->rightVirtualDisplay.visibleVertices._Myfirst[2].x,
    this->rect.top + this->rightVirtualDisplay.visibleVertices._Myfirst[2].y,
    0.0);
  GLRenderer::end(v5);
}
void TripleScreenManager::drawVirtualDisplay(TripleScreenManager *this, VirtualDisplay *vd)
{
  GLRenderer *v3; // esi
  std::wstring *v4; // eax
  int v5; // eax
  bool v6; // al
  bool v7; // [esp+2Fh] [ebp-2Dh]
  std::wstring result; // [esp+30h] [ebp-2Ch] BYREF
  int v9; // [esp+58h] [ebp-4h]

  v3 = this->gui->graphics->gl;
  GLRenderer::color3f(v3, 0.0, 0.0, 0.0);
  GLRenderer::begin(v3, eQuads, 0);
  GLRenderer::vertex3f(
    v3,
    vd->displayVertices._Myfirst->x + this->rect.left,
    vd->displayVertices._Myfirst->y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->displayVertices._Myfirst[1].x + this->rect.left,
    vd->displayVertices._Myfirst[1].y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->displayVertices._Myfirst[2].x + this->rect.left,
    vd->displayVertices._Myfirst[2].y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->displayVertices._Myfirst[3].x + this->rect.left,
    vd->displayVertices._Myfirst[3].y + this->rect.top,
    0.0);
  GLRenderer::end(v3);
  GLRenderer::begin(v3, eQuads, 0);
  GLRenderer::vertex3f(
    v3,
    vd->backDisplayVertex._Myfirst->x + this->rect.left,
    vd->backDisplayVertex._Myfirst->y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->backDisplayVertex._Myfirst[1].x + this->rect.left,
    vd->backDisplayVertex._Myfirst[1].y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->backDisplayVertex._Myfirst[2].x + this->rect.left,
    vd->backDisplayVertex._Myfirst[2].y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->backDisplayVertex._Myfirst[3].x + this->rect.left,
    vd->backDisplayVertex._Myfirst[3].y + this->rect.top,
    0.0);
  GLRenderer::end(v3);
  v4 = VirtualDisplay::getType(vd, &result);
  v9 = 0;
  v5 = std::wstring::compare(v4, 0, v4->_Mysize, L"LateralDisplay", 0xEu);
  v9 = -1;
  v6 = v5 == 0;
  v7 = v6;
  if ( result._Myres >= 8 )
  {
    operator delete(result._Bx._Ptr);
    v6 = v7;
  }
  if ( v6 )
    GLRenderer::color3f(v3, 1.0, 0.0, 0.0);
  else
    GLRenderer::color3f(v3, 0.0, 1.0, 0.0);
  GLRenderer::begin(v3, eQuads, 0);
  GLRenderer::vertex3f(
    v3,
    vd->visibleVertices._Myfirst->x + this->rect.left,
    vd->visibleVertices._Myfirst->y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->visibleVertices._Myfirst[1].x + this->rect.left,
    vd->visibleVertices._Myfirst[1].y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->visibleVertices._Myfirst[2].x + this->rect.left,
    vd->visibleVertices._Myfirst[2].y + this->rect.top,
    0.0);
  GLRenderer::vertex3f(
    v3,
    vd->visibleVertices._Myfirst[3].x + this->rect.left,
    vd->visibleVertices._Myfirst[3].y + this->rect.top,
    0.0);
  GLRenderer::end(v3);
}
void __userpurge TripleScreenManager::rotateLateralScreen(TripleScreenManager *this, VirtualDisplay *vd, int rotationVertex)
{
  unsigned int v4; // ebx
  int v5; // ebp
  int v6; // ecx
  TripleScreenManager_vtbl *v7; // esi
  float v8; // xmm0_4
  int v9; // esi
  float v10; // xmm0_4
  unsigned int v11; // ecx
  float v12; // [esp+14h] [ebp-58h]
  float v13; // [esp+14h] [ebp-58h]
  float v14; // [esp+18h] [ebp-54h]
  float v15; // [esp+18h] [ebp-54h]
  float v16; // [esp+1Ch] [ebp-50h]
  float v17; // [esp+20h] [ebp-4Ch]
  float v18; // [esp+24h] [ebp-48h]
  float v19; // [esp+28h] [ebp-44h]
  float v20; // [esp+2Ch] [ebp-40h]
  float v21; // [esp+30h] [ebp-3Ch]
  float v22; // [esp+54h] [ebp-18h]
  float v23; // [esp+58h] [ebp-14h]
  float v24; // [esp+5Ch] [ebp-10h]
  float v25; // [esp+60h] [ebp-Ch]
  float rotationVertexa; // [esp+74h] [ebp+8h]
  float rotationVertexb; // [esp+74h] [ebp+8h]

  v4 = 0;
  if ( ((char *)this->name._Bx._Ptr - (char *)this->__vftable) >> 3 )
  {
    v5 = 8 * (_DWORD)vd;
    LODWORD(v16) = __libm_sse2_cosf().m128_u32[0];
    LODWORD(v17) = __libm_sse2_sinf().m128_u32[0];
    do
    {
      v6 = *(_DWORD *)&this->name._Bx._Alias[8];
      v7 = this->__vftable;
      v18 = *(float *)(v6 + v5);
      v19 = *(float *)(v6 + v5 + 4);
      v14 = *((float *)&this->~Control + 2 * v4) - v18;
      rotationVertexa = *((float *)&this->hitTest + 2 * v4) - v19;
      v12 = __libm_sse2_sinf().m128_f32[0];
      v8 = __libm_sse2_cosf().m128_f32[0];
      *((float *)&v7->~Control + 2 * v4) = v18 + (float)((float)(v8 * v14) - (float)(v12 * rotationVertexa));
      *((float *)&v7->hitTest + 2 * v4) = v19 + (float)((float)(v8 * rotationVertexa) + (float)(v12 * v14));
      v9 = *(_DWORD *)&this->name._Bx._Alias[8];
      v20 = *(float *)(v9 + v5);
      v21 = *(float *)(v9 + v5 + 4);
      v13 = *(float *)(v9 + 8 * v4) - v20;
      rotationVertexb = *(float *)(v9 + 8 * v4 + 4) - v21;
      v15 = __libm_sse2_sinf().m128_f32[0];
      v10 = __libm_sse2_cosf().m128_f32[0];
      *(float *)(v9 + 8 * v4) = v20 + (float)((float)(v10 * v13) - (float)(v15 * rotationVertexb));
      *(float *)(v9 + 8 * v4 + 4) = v21 + (float)((float)(v10 * rotationVertexb) + (float)(v15 * v13));
      v11 = this->name._Myres;
      v24 = *(float *)(v11 + v5);
      v25 = *(float *)(v11 + v5 + 4);
      v22 = *(float *)(v11 + 8 * v4);
      v23 = *(float *)(v11 + 8 * v4 + 4);
      *(float *)(v11 + 8 * v4) = v24 + (float)((float)(v16 * (float)(v22 - v24)) - (float)(v17 * (float)(v23 - v25)));
      *(float *)(v11 + 8 * v4++ + 4) = v25
                                     + (float)((float)(v16 * (float)(v23 - v25)) + (float)(v17 * (float)(v22 - v24)));
    }
    while ( v4 < ((char *)this->name._Bx._Ptr - (char *)this->__vftable) >> 3 );
  }
}
