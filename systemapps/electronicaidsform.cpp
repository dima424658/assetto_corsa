#include "electronicaidsform.h
void ElectronicAidsForm::ElectronicAidsForm(ElectronicAidsForm *this, CarAvatar *acar)
{
  int v3; // ebx
  const std::wstring *v4; // eax
  ksgui::Control *v5; // ebp
  ksgui::Control *v6; // eax
  ksgui::Control *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  ksgui::Control *v13; // ecx
  std::wstring *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebp
  ksgui::Control *v17; // ecx
  ksgui::Control_vtbl *v18; // eax
  float v19; // xmm0_4
  ksgui::Control *v20; // eax
  ksgui::Control *v21; // ebp
  ksgui::Control *v22; // eax
  ksgui::Control *v23; // ecx
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  Texture *v30; // eax
  ksgui::Control *v31; // ecx
  std::wstring *v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebp
  ksgui::Control *v35; // ecx
  ksgui::Control_vtbl *v36; // eax
  float v37; // xmm0_4
  ksgui::Control *v38; // ebp
  ksgui::Control *v39; // eax
  ksgui::Control *v40; // ecx
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm4_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  Texture *v47; // eax
  ksgui::Control *v48; // ecx
  std::wstring *v49; // ecx
  unsigned int v50; // edx
  unsigned int v51; // ebp
  ksgui::Control *v52; // ecx
  ksgui::Control_vtbl *v53; // eax
  float v54; // xmm0_4
  ksgui::Control *v55; // ebp
  ksgui::Control *v56; // eax
  ksgui::Control *v57; // ecx
  float v58; // xmm3_4
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm4_4
  float v62; // xmm0_4
  float v63; // xmm1_4
  Texture *v64; // eax
  ksgui::Control *v65; // ecx
  std::wstring *v66; // ecx
  unsigned int v67; // edx
  unsigned int v68; // edi
  ksgui::Control *v69; // ecx
  ksgui::Control_vtbl *v70; // eax
  float v71; // xmm0_4
  std::wstring v72; // [esp+8h] [ebp-B8h] BYREF
  float w; // [esp+20h] [ebp-A0h]
  float h; // [esp+24h] [ebp-9Ch]
  int _Val; // [esp+3Ch] [ebp-84h] BYREF
  ksgui::Control *v76; // [esp+40h] [ebp-80h]
  ElectronicAidsForm *v77; // [esp+44h] [ebp-7Ch]
  std::wstring result; // [esp+48h] [ebp-78h] BYREF
  std::wstring text; // [esp+60h] [ebp-60h] BYREF
  Texture t; // [esp+78h] [ebp-48h] BYREF
  Texture v81; // [esp+94h] [ebp-2Ch] BYREF
  int v82; // [esp+BCh] [ebp-4h]

  v3 = 0;
  _Val = 0;
  LODWORD(h) = 1;
  v77 = this;
  w = *(float *)&acar->game->gui;
  v72._Myres = 7;
  v72._Mysize = 0;
  v72._Bx._Buf[0] = 0;
  std::wstring::assign(&v72, L"ELECTRONICS", 0xBu);
  ksgui::Form::Form(this, 0, v72, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v82 = 0;
  LODWORD(h) = 11;
  this->__vftable = (ElectronicAidsForm_vtbl *)&ElectronicAidsForm::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Electronics", LODWORD(h));
  LOBYTE(v82) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v82) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v82) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->devApp = 0;
  this->car = acar;
  ksgui::Form::setSize(this, 350.0, 115.0);
  v5 = (ksgui::Control *)operator new(0x118u);
  v76 = v5;
  v6 = 0;
  LOBYTE(v82) = 3;
  if ( v5 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"ABS", 3u);
    LOBYTE(v82) = 4;
    h = *(float *)&this->gui;
    v3 = 1;
    _Val = 1;
    ksgui::Control::Control(v5, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->controlABS = v6;
  v82 = 0;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v7 = this->controlABS;
  v8 = v7->rectBase.left;
  v9 = v7->rect.right - v7->rect.left;
  v10 = v7->rect.bottom - v7->rect.top;
  v7->rect.top = 30.0;
  v7->rect.left = 35.0;
  v11 = v9 + 35.0;
  v12 = v10 + 30.0;
  v7->rect.right = v11;
  v7->rect.bottom = v12;
  if ( v8 == 0.0 && v7->rectBase.top == 0.0 )
  {
    v7->rectBase.left = 35.0;
    v7->rectBase.top = 30.0;
    v7->rectBase.right = v11;
    v7->rectBase.bottom = v12;
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/electronicaids/abs.png", 0x22u);
  LOBYTE(v82) = 6;
  ResourceStore::getTexture(this->car->game->graphics->resourceStore._Myptr, &t, &text, 0);
  LOBYTE(v82) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v13 = this->controlABS;
  text._Bx._Buf[0] = 0;
  text._Myres = 7;
  v13->backTexture.kid = t.kid;
  v14 = &v13->backTexture.fileName;
  text._Mysize = 0;
  if ( v14 != &t.fileName )
    std::wstring::assign(v14, &t.fileName, 0, 0xFFFFFFFF);
  if ( t.kid )
  {
    v15 = *((_DWORD *)t.kid + 10);
    v16 = *((_DWORD *)t.kid + 9);
  }
  else
  {
    v15 = 0;
    v16 = 0;
  }
  v17 = this->controlABS;
  v18 = v17->__vftable;
  v19 = (float)v15;
  w = (float)v16;
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))v18->setSize)(v17, LODWORD(w), LODWORD(v19));
  v20 = this->controlABS;
  LODWORD(h) = &_Val;
  v20->drawBackground = 0;
  this->controlABS->drawBorder = 0;
  _Val = (int)this->controlABS;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)LODWORD(h));
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v21 = (ksgui::Control *)operator new(LODWORD(h));
  v76 = v21;
  v22 = 0;
  LOBYTE(v82) = 9;
  if ( v21 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"TC", 2u);
    LOBYTE(v82) = 10;
    h = *(float *)&this->gui;
    v3 |= 2u;
    _Val = v3;
    ksgui::Control::Control(v21, &result, (ksgui::GUI *)LODWORD(h));
  }
  this->controlTC = v22;
  v82 = 8;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v23 = this->controlTC;
  v24 = this->controlABS->rect.right + 10.0;
  v25 = v23->rect.right - v23->rect.left;
  v26 = v23->rect.bottom - v23->rect.top;
  v23->rect.top = 30.0;
  v23->rect.left = v24;
  v27 = v24 + v25;
  v28 = v23->rectBase.left;
  v29 = v26 + 30.0;
  v23->rect.right = v27;
  v23->rect.bottom = v29;
  if ( v28 == 0.0 && v23->rectBase.top == 0.0 )
  {
    v23->rectBase.left = v24;
    v23->rectBase.top = 30.0;
    v23->rectBase.right = v27;
    v23->rectBase.bottom = v29;
  }
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"content/gui/electronicaids/tc.png", 0x21u);
  LOBYTE(v82) = 12;
  v30 = ResourceStore::getTexture(this->car->game->graphics->resourceStore._Myptr, &v81, &result, 0);
  LOBYTE(v82) = 13;
  t.kid = v30->kid;
  if ( &t.fileName != &v30->fileName )
    std::wstring::assign(&t.fileName, &v30->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v82) = 12;
  OnSetupAppCreated::~OnSetupAppCreated(&v81);
  LOBYTE(v82) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v31 = this->controlTC;
  v31->backTexture.kid = t.kid;
  v32 = &v31->backTexture.fileName;
  if ( v32 != &t.fileName )
    std::wstring::assign(v32, &t.fileName, 0, 0xFFFFFFFF);
  if ( t.kid )
  {
    v33 = *((_DWORD *)t.kid + 10);
    v34 = *((_DWORD *)t.kid + 9);
  }
  else
  {
    v33 = 0;
    v34 = 0;
  }
  v35 = this->controlTC;
  v36 = v35->__vftable;
  v37 = (float)v33;
  w = (float)v34;
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))v36->setSize)(v35, LODWORD(w), LODWORD(v37));
  this->controlTC->drawBackground = 0;
  this->controlTC->drawBorder = 0;
  _Val = (int)this->controlTC;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v38 = (ksgui::Control *)operator new(LODWORD(h));
  v76 = v38;
  v39 = 0;
  LOBYTE(v82) = 14;
  if ( v38 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"EDL", 3u);
    LOBYTE(v82) = 15;
    h = *(float *)&this->gui;
    v3 |= 4u;
    _Val = v3;
    ksgui::Control::Control(v38, &result, (ksgui::GUI *)LODWORD(h));
  }
  this->controlEDL = v39;
  v82 = 8;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v40 = this->controlEDL;
  v41 = this->controlTC->rect.right + 10.0;
  v42 = v40->rect.right - v40->rect.left;
  v43 = v40->rect.bottom - v40->rect.top;
  v40->rect.top = 30.0;
  v40->rect.left = v41;
  v44 = v41 + v42;
  v45 = v40->rectBase.left;
  v46 = v43 + 30.0;
  v40->rect.right = v44;
  v40->rect.bottom = v46;
  if ( v45 == 0.0 && v40->rectBase.top == 0.0 )
  {
    v40->rectBase.left = v41;
    v40->rectBase.top = 30.0;
    v40->rectBase.right = v44;
    v40->rectBase.bottom = v46;
  }
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"content/gui/electronicaids/edl.png", 0x22u);
  LOBYTE(v82) = 17;
  v47 = ResourceStore::getTexture(this->car->game->graphics->resourceStore._Myptr, &v81, &result, 0);
  LOBYTE(v82) = 18;
  t.kid = v47->kid;
  if ( &t.fileName != &v47->fileName )
    std::wstring::assign(&t.fileName, &v47->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v82) = 17;
  OnSetupAppCreated::~OnSetupAppCreated(&v81);
  LOBYTE(v82) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v48 = this->controlEDL;
  v48->backTexture.kid = t.kid;
  v49 = &v48->backTexture.fileName;
  if ( v49 != &t.fileName )
    std::wstring::assign(v49, &t.fileName, 0, 0xFFFFFFFF);
  if ( t.kid )
  {
    v50 = *((_DWORD *)t.kid + 10);
    v51 = *((_DWORD *)t.kid + 9);
  }
  else
  {
    v50 = 0;
    v51 = 0;
  }
  v52 = this->controlEDL;
  v53 = v52->__vftable;
  v54 = (float)v50;
  w = (float)v51;
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))v53->setSize)(v52, LODWORD(w), LODWORD(v54));
  this->controlEDL->drawBackground = 0;
  this->controlEDL->drawBorder = 0;
  _Val = (int)this->controlEDL;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v55 = (ksgui::Control *)operator new(LODWORD(h));
  v76 = v55;
  v56 = 0;
  LOBYTE(v82) = 19;
  if ( v55 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"DRS", 3u);
    LOBYTE(v82) = 20;
    h = *(float *)&this->gui;
    v3 |= 8u;
    _Val = v3;
    ksgui::Control::Control(v55, &result, (ksgui::GUI *)LODWORD(h));
  }
  this->controlDRS = v56;
  v82 = 8;
  if ( (v3 & 8) != 0 && result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v57 = this->controlDRS;
  v58 = this->controlEDL->rect.right + 10.0;
  v59 = v57->rect.right - v57->rect.left;
  v60 = v57->rect.bottom - v57->rect.top;
  v57->rect.top = 30.0;
  v57->rect.left = v58;
  v61 = v58 + v59;
  v62 = v57->rectBase.left;
  v63 = v60 + 30.0;
  v57->rect.right = v61;
  v57->rect.bottom = v63;
  if ( v62 == 0.0 && v57->rectBase.top == 0.0 )
  {
    v57->rectBase.left = v58;
    v57->rectBase.top = 30.0;
    v57->rectBase.right = v61;
    v57->rectBase.bottom = v63;
  }
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"content/gui/electronicaids/drs.png", 0x22u);
  LOBYTE(v82) = 22;
  v64 = ResourceStore::getTexture(this->car->game->graphics->resourceStore._Myptr, &v81, &result, 0);
  LOBYTE(v82) = 23;
  t.kid = v64->kid;
  if ( &t.fileName != &v64->fileName )
    std::wstring::assign(&t.fileName, &v64->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v82) = 22;
  OnSetupAppCreated::~OnSetupAppCreated(&v81);
  LOBYTE(v82) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v65 = this->controlDRS;
  v65->backTexture.kid = t.kid;
  v66 = &v65->backTexture.fileName;
  if ( v66 != &t.fileName )
    std::wstring::assign(v66, &t.fileName, 0, 0xFFFFFFFF);
  if ( t.kid )
  {
    v67 = *((_DWORD *)t.kid + 10);
    v68 = *((_DWORD *)t.kid + 9);
  }
  else
  {
    v67 = 0;
    v68 = 0;
  }
  v69 = this->controlDRS;
  v70 = v69->__vftable;
  v71 = (float)v67;
  w = (float)v68;
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))v70->setSize)(v69, LODWORD(w), LODWORD(v71));
  this->controlDRS->drawBackground = 0;
  this->controlDRS->drawBorder = 0;
  _Val = (int)this->controlDRS;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 1;
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setAutoHideMode(this, SLODWORD(h));
  ((void (*)(ElectronicAidsForm *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
  LOBYTE(v82) = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&t);
}
void __userpurge ElectronicAidsForm::render(ElectronicAidsForm *this@<ecx>, int a2@<edi>, int a3@<esi>, float dt)
{
  vec4f v5; // xmm0
  ksgui::Control *v6; // ecx
  ksgui::Control *v7; // ecx
  vec4f v8; // xmm0
  ksgui::Control *v9; // ecx
  ksgui::Control *v10; // ecx
  CarAvatar *v11; // ecx
  double v12; // st7
  vec4f v13; // xmm0
  ksgui::Control *v14; // ecx
  ksgui::Control *v15; // ecx
  CarAvatar *v16; // eax
  unsigned int v17; // eax
  vec4f v18; // xmm0
  ksgui::Control *v19; // ecx
  ksgui::Control *v20; // ecx
  __int64 v21; // [esp+4h] [ebp-20h]
  int v22; // [esp+4h] [ebp-20h]
  float v23; // [esp+8h] [ebp-1Ch]
  __int128 v24; // [esp+Ch] [ebp-18h] BYREF
  int v25; // [esp+1Ch] [ebp-8h]
  int v26; // [esp+20h] [ebp-4h]

  LODWORD(v21) = a3;
  ksgui::Control::render(this, a2, (int)this, dt, v21, *(float *)&v24);
  if ( CarAvatar::isAbsEnabled(this->car) )
  {
    if ( CarAvatar::isAbsInAction(this->car) )
      v5 = (vec4f)_xmm;
    else
      v5 = (vec4f)_xmm;
    this->controlABS->backTextureColor = v5;
    v6 = this->controlABS;
    if ( !v6->visible )
    {
      v6->visible = 1;
      v6->onVisibleChanged(v6, 1);
    }
  }
  else
  {
    v7 = this->controlABS;
    if ( v7->visible )
    {
      v7->visible = 0;
      v7->onVisibleChanged(v7, 0);
    }
  }
  if ( CarAvatar::isTcEnabled(this->car) )
  {
    if ( CarAvatar::isTcInAction(this->car) )
      v8 = (vec4f)_xmm;
    else
      v8 = (vec4f)_xmm;
    this->controlTC->backTextureColor = v8;
    v9 = this->controlTC;
    if ( !v9->visible )
    {
      v9->visible = 1;
      v9->onVisibleChanged(v9, 1);
    }
  }
  else
  {
    v10 = this->controlTC;
    if ( v10->visible )
    {
      v10->visible = 0;
      v10->onVisibleChanged(v10, 0);
    }
  }
  if ( CarAvatar::isEdlEnabled(this->car) )
  {
    *(double *)&v24 = CarAvatar::getEdlOutLevel(this->car);
    if ( *(double *)&v24 <= 0.1 || (v11 = this->car, v11->physicsState.speed.value <= 1.0) )
    {
      v13 = (vec4f)_xmm;
    }
    else
    {
      v23 = CarAvatar::getEdlOutLevel(v11) * 1.3;
      v12 = CarAvatar::getEdlOutLevel(this->car);
      v25 = 0;
      v26 = 1065353216;
      *((float *)&v24 + 2) = v23 + 0.69999999;
      *(float *)&v24 = v12 * 0.3;
      *((float *)&v24 + 3) = *(float *)&v24 + 0.69999999;
      v13 = (vec4f)_mm_loadu_si128((const __m128i *)((char *)&v24 + 8));
    }
    this->controlEDL->backTextureColor = v13;
    v14 = this->controlEDL;
    if ( !v14->visible )
    {
      v14->visible = 1;
      v14->onVisibleChanged(v14, 1);
    }
  }
  else
  {
    v15 = this->controlEDL;
    if ( v15->visible )
    {
      v15->visible = 0;
      v15->onVisibleChanged(v15, 0);
    }
  }
  v16 = this->car;
  if ( v16->physicsInfo.hasDRS )
  {
    v17 = v16->physicsState.statusBytes;
    if ( (v17 & 4) != 0 )
    {
      v18 = (vec4f)_xmm;
    }
    else if ( (v17 & 2) != 0 )
    {
      v18 = (vec4f)_xmm;
    }
    else
    {
      v18 = (vec4f)_xmm;
    }
    this->controlDRS->backTextureColor = v18;
    v19 = this->controlDRS;
    if ( !v19->visible )
    {
      v19->visible = 1;
      ((void (*)(ksgui::Control *, int, int, float, _DWORD, _DWORD, _DWORD, _DWORD, int))v19->onVisibleChanged)(
        v19,
        1,
        v22,
        COERCE_FLOAT(LODWORD(v23)),
        v24,
        DWORD1(v24),
        DWORD2(v24),
        HIDWORD(v24),
        v25);
    }
  }
  else
  {
    v20 = this->controlDRS;
    if ( v20->visible )
    {
      v20->visible = 0;
      v20->onVisibleChanged(v20, 0);
    }
  }
}
