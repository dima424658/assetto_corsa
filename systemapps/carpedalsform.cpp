#include "carpedalsform.h
void __userpurge CarPedalsForm::CarPedalsForm(CarPedalsForm *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *icar)
{
  Game *v4; // eax
  const std::wstring *v5; // eax
  std::wstring *v6; // eax
  double v7; // st7
  bool v8; // cf
  ksgui::Control *v9; // edi
  int v10; // eax
  int v11; // edi
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  ksgui::ProgressBar *v17; // edi
  ksgui::ProgressBar *v18; // eax
  ksgui::ProgressBar *v19; // ecx
  ksgui::ProgressBar *v20; // ecx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  ksgui::Control *v26; // edi
  ksgui::Control *v27; // eax
  ksgui::Control *v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  ksgui::ProgressBar *v34; // edi
  ksgui::ProgressBar *v35; // eax
  ksgui::ProgressBar *v36; // ecx
  ksgui::ProgressBar *v37; // ecx
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  ksgui::ProgressBar *v43; // edi
  ksgui::ProgressBar *v44; // eax
  ksgui::ProgressBar *v45; // ecx
  ksgui::ProgressBar *v46; // ecx
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  ksgui::ProgressBar *v52; // edi
  ksgui::ProgressBar *v53; // eax
  ksgui::ProgressBar *v54; // ecx
  ksgui::ProgressBar *v55; // ecx
  float v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // ecx
  _BYTE v62[28]; // [esp+18h] [ebp-E4h] BYREF
  float h; // [esp+34h] [ebp-C8h]
  int _Val; // [esp+4Ch] [ebp-B0h] BYREF
  int v65; // [esp+50h] [ebp-ACh]
  int v66; // [esp+54h] [ebp-A8h]
  ksgui::ProgressBar *v67; // [esp+58h] [ebp-A4h]
  CarPedalsForm *v68; // [esp+5Ch] [ebp-A0h]
  std::wstring result; // [esp+60h] [ebp-9Ch] BYREF
  std::wstring text; // [esp+78h] [ebp-84h] BYREF
  std::wstring key; // [esp+90h] [ebp-6Ch] BYREF
  INIReaderDocuments iniControls; // [esp+A8h] [ebp-54h] BYREF
  int v73; // [esp+F8h] [ebp-4h]

  _Val = 0;
  v66 = 0;
  LODWORD(h) = 1;
  v4 = icar->game;
  v68 = this;
  *(_DWORD *)&v62[24] = v4->gui;
  *(_DWORD *)&v62[20] = 7;
  *(_DWORD *)&v62[16] = 0;
  *(_WORD *)v62 = 0;
  std::wstring::assign((std::wstring *)v62, L"PEDALS", 6u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v62, *(ksgui::GUI **)&v62[24], SLOBYTE(h));
  v73 = 0;
  LODWORD(h) = 6;
  this->__vftable = (CarPedalsForm_vtbl *)&CarPedalsForm::`vftable';
  *(_DWORD *)&v62[24] = L"Pedals";
  this->isGasOk = 0;
  this->ffMult = 1.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v62[24], LODWORD(h));
  LOBYTE(v73) = 1;
  v5 = acTranslate(&result, &text);
  LOBYTE(v73) = 2;
  this->formTitle->setText(this->formTitle, v5);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v73) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  h = 0.0;
  this->devApp = 0;
  this->car = icar;
  *(_DWORD *)&v62[24] = 7;
  *(_DWORD *)&v62[20] = 0;
  *(_WORD *)&v62[4] = 0;
  std::wstring::assign((std::wstring *)&v62[4], L"cfg/controls.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(
    &iniControls,
    (unsigned int)operator delete,
    *(std::wstring *)&v62[4],
    SLOBYTE(h));
  LOBYTE(v73) = 3;
  if ( iniControls.ready )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"INPUT_METHOD", 0xCu);
    LOBYTE(v73) = 4;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"HEADER", 6u);
    LOBYTE(v73) = 5;
    v6 = INIReader::getString(&iniControls, &key, &text, &result);
    LOBYTE(v73) = 6;
    HIBYTE(v65) = std::wstring::compare(v6, 0, v6->_Mysize, L"WHEEL", 5u) == 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    LOBYTE(v73) = 3;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( HIBYTE(v65) )
    {
      std::wstring::wstring(&key, L"FF_GAIN");
      LOBYTE(v73) = 7;
      std::wstring::wstring(&result, L"STEER");
      LOBYTE(v73) = 8;
      v7 = INIReader::getFloat(&iniControls, &result, &key);
      v8 = result._Myres < 8;
      this->ffMult = v7;
      if ( !v8 )
        operator delete(result._Bx._Ptr);
      LOBYTE(v73) = 3;
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  ksgui::Form::setSize(this, 130.0, 100.0);
  v9 = (ksgui::Control *)operator new(0x118u);
  v67 = (ksgui::ProgressBar *)v9;
  LOBYTE(v73) = 9;
  if ( v9 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"BACK", 4u);
    LOBYTE(v73) = 10;
    h = *(float *)&this->gui;
    v66 = 1;
    _Val = 1;
    ksgui::Control::Control(v9, &text, (ksgui::GUI *)LODWORD(h));
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  v73 = 3;
  if ( (v66 & 1) != 0 )
  {
    v66 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v11 + 28))(v11, 1117782016, 1114636288);
  v12 = *(float *)(v11 + 264);
  v13 = *(float *)(v11 + 32) - *(float *)(v11 + 28);
  v14 = *(float *)(v11 + 40) - *(float *)(v11 + 36);
  *(_DWORD *)(v11 + 36) = 1107296256;
  *(_DWORD *)(v11 + 28) = 1103626240;
  v15 = v13 + 25.0;
  v16 = v14 + 32.0;
  *(float *)(v11 + 32) = v15;
  *(float *)(v11 + 40) = v16;
  if ( v12 == 0.0 && *(float *)(v11 + 272) == 0.0 )
  {
    *(_DWORD *)(v11 + 264) = 1103626240;
    *(_DWORD *)(v11 + 272) = 1107296256;
    *(float *)(v11 + 268) = v15;
    *(float *)(v11 + 276) = v16;
  }
  *(_OWORD *)(v11 + 44) = _xmm;
  LODWORD(h) = &_Val;
  *(_OWORD *)(v11 + 60) = _xmm;
  _Val = v11;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)LODWORD(h));
  LODWORD(h) = 1;
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setAutoHideMode(this, SLODWORD(h));
  v17 = (ksgui::ProgressBar *)operator new(0x128u);
  v67 = v17;
  LOBYTE(v73) = 12;
  if ( v17 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v62[24] = 7;
    *(_DWORD *)&v62[20] = 0;
    *(_WORD *)&v62[4] = 0;
    std::wstring::assign((std::wstring *)&v62[4], L"GAS", 3u);
    ksgui::ProgressBar::ProgressBar(v17, *(std::wstring *)&v62[4], (ksgui::GUI *)LODWORD(h));
    v19 = v18;
  }
  else
  {
    v19 = 0;
  }
  LOBYTE(v73) = 3;
  this->prgGas = v19;
  ((void (*)(ksgui::ProgressBar *, int, int))v19->setSize)(v19, 1092616192, 1112014848);
  v20 = this->prgGas;
  v21 = v20->rectBase.left;
  v22 = v20->rect.right - v20->rect.left;
  v23 = v20->rect.bottom - v20->rect.top;
  v20->rect.top = 40.0;
  v20->rect.left = 65.0;
  v24 = v22 + 65.0;
  v25 = v23 + 40.0;
  v20->rect.right = v24;
  v20->rect.bottom = v25;
  if ( v21 == 0.0 && v20->rectBase.top == 0.0 )
  {
    v20->rectBase.left = 65.0;
    v20->rectBase.top = 40.0;
    v20->rectBase.right = v24;
    v20->rectBase.bottom = v25;
  }
  this->prgGas->foreColor = (vec4f)_xmm;
  this->prgGas->borderColor = (vec4f)_xmm;
  _Val = (int)this->prgGas;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v26 = (ksgui::Control *)operator new(LODWORD(h));
  v67 = (ksgui::ProgressBar *)v26;
  v27 = 0;
  LOBYTE(v73) = 13;
  if ( v26 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"GAS", 3u);
    LOBYTE(v73) = 14;
    h = *(float *)&this->gui;
    v66 |= 2u;
    _Val = v66;
    ksgui::Control::Control(v26, &result, (ksgui::GUI *)LODWORD(h));
  }
  this->gasLed = v27;
  v73 = 3;
  if ( (v66 & 2) != 0 && result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, int))this->gasLed->setSize)(this->gasLed, 1092616192, 1084227584);
  v28 = this->gasLed;
  v29 = v28->rectBase.left;
  v30 = v28->rect.right - v28->rect.left;
  v31 = v28->rect.bottom - v28->rect.top;
  v28->rect.top = 33.0;
  v28->rect.left = 65.0;
  v32 = v30 + 65.0;
  v33 = v31 + 33.0;
  v28->rect.right = v32;
  v28->rect.bottom = v33;
  if ( v29 == 0.0 && v28->rectBase.top == 0.0 )
  {
    v28->rectBase.left = 65.0;
    v28->rectBase.top = 33.0;
    v28->rectBase.right = v32;
    v28->rectBase.bottom = v33;
  }
  this->gasLed->borderColor = (vec4f)_xmm;
  this->gasLed->backColor = (vec4f)_xmm;
  _Val = (int)this->gasLed;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 296;
  *(_DWORD *)(_Val + 148) = this;
  v34 = (ksgui::ProgressBar *)operator new(LODWORD(h));
  v67 = v34;
  LOBYTE(v73) = 16;
  if ( v34 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v62[24] = 7;
    *(_DWORD *)&v62[20] = 0;
    *(_WORD *)&v62[4] = 0;
    std::wstring::assign((std::wstring *)&v62[4], L"BRAKE", 5u);
    ksgui::ProgressBar::ProgressBar(v34, *(std::wstring *)&v62[4], (ksgui::GUI *)LODWORD(h));
    v36 = v35;
  }
  else
  {
    v36 = 0;
  }
  LOBYTE(v73) = 3;
  this->prgBrake = v36;
  ((void (*)(ksgui::ProgressBar *, int, int))v36->setSize)(v36, 1092616192, 1112014848);
  v37 = this->prgBrake;
  v38 = v37->rectBase.left;
  v39 = v37->rect.right - v37->rect.left;
  v40 = v37->rect.bottom - v37->rect.top;
  v37->rect.top = 40.0;
  v37->rect.left = 50.0;
  v41 = v39 + 50.0;
  v42 = v40 + 40.0;
  v37->rect.right = v41;
  v37->rect.bottom = v42;
  if ( v38 == 0.0 && v37->rectBase.top == 0.0 )
  {
    v37->rectBase.left = 50.0;
    v37->rectBase.top = 40.0;
    v37->rectBase.right = v41;
    v37->rectBase.bottom = v42;
  }
  this->prgBrake->foreColor = (vec4f)_xmm;
  _Val = (int)this->prgBrake;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 296;
  *(_DWORD *)(_Val + 148) = this;
  v43 = (ksgui::ProgressBar *)operator new(LODWORD(h));
  v67 = v43;
  LOBYTE(v73) = 17;
  if ( v43 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v62[24] = 7;
    *(_DWORD *)&v62[20] = 0;
    *(_WORD *)&v62[4] = 0;
    std::wstring::assign((std::wstring *)&v62[4], L"CLUTCH", 6u);
    ksgui::ProgressBar::ProgressBar(v43, *(std::wstring *)&v62[4], (ksgui::GUI *)LODWORD(h));
    v45 = v44;
  }
  else
  {
    v45 = 0;
  }
  LOBYTE(v73) = 3;
  this->prgClutch = v45;
  ((void (*)(ksgui::ProgressBar *, int, int))v45->setSize)(v45, 1092616192, 1112014848);
  v46 = this->prgClutch;
  v47 = v46->rectBase.left;
  v48 = v46->rect.right - v46->rect.left;
  v49 = v46->rect.bottom - v46->rect.top;
  v46->rect.top = 40.0;
  v46->rect.left = 35.0;
  v50 = v48 + 35.0;
  v51 = v49 + 40.0;
  v46->rect.right = v50;
  v46->rect.bottom = v51;
  if ( v47 == 0.0 && v46->rectBase.top == 0.0 )
  {
    v46->rectBase.left = 35.0;
    v46->rectBase.top = 40.0;
    v46->rectBase.right = v50;
    v46->rectBase.bottom = v51;
  }
  this->prgClutch->foreColor = (vec4f)_xmm;
  _Val = (int)this->prgClutch;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 296;
  *(_DWORD *)(_Val + 148) = this;
  v52 = (ksgui::ProgressBar *)operator new(LODWORD(h));
  v67 = v52;
  LOBYTE(v73) = 18;
  if ( v52 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v62[24] = 7;
    *(_DWORD *)&v62[20] = 0;
    *(_WORD *)&v62[4] = 0;
    std::wstring::assign((std::wstring *)&v62[4], L"FF", 2u);
    ksgui::ProgressBar::ProgressBar(v52, *(std::wstring *)&v62[4], (ksgui::GUI *)LODWORD(h));
    v54 = v53;
  }
  else
  {
    v54 = 0;
  }
  LOBYTE(v73) = 3;
  this->prgFF = v54;
  ((void (*)(ksgui::ProgressBar *, int, int))v54->setSize)(v54, 1092616192, 1112014848);
  v55 = this->prgFF;
  v56 = v55->rectBase.left;
  v57 = v55->rect.right - v55->rect.left;
  v58 = v55->rect.bottom - v55->rect.top;
  v55->rect.top = 40.0;
  v55->rect.left = 80.0;
  v59 = v57 + 80.0;
  v60 = v58 + 40.0;
  v55->rect.right = v59;
  v55->rect.bottom = v60;
  if ( v56 == 0.0 && v55->rectBase.top == 0.0 )
  {
    v55->rectBase.left = 80.0;
    v55->rectBase.top = 40.0;
    v55->rectBase.right = v59;
    v55->rectBase.bottom = v60;
  }
  this->prgFF->isVertical = 1;
  this->prgFF->minValue = 0.0;
  this->prgFF->maxValue = 1.0;
  _Val = (int)this->prgFF;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  h = v61;
  *(_DWORD *)(_Val + 148) = this;
  ((void (*)(CarPedalsForm *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
  LOBYTE(v73) = 0;
  INIReaderDocuments::~INIReaderDocuments(&iniControls);
}
void CarPedalsForm::render(CarPedalsForm *this, float dt)
{
  unsigned int v3; // eax
  CarAvatar *v4; // eax
  ksgui::ProgressBar *v5; // ecx
  float v6; // xmm1_4
  RaceEngineer *v7; // ecx
  ICarControlsProvider *v8; // eax
  int v9; // edi
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  ksgui::ProgressBar *v13; // eax
  __int128 v14; // xmm0
  vec4f v15; // xmm0
  vec4f v16; // xmm0
  vec4f v17; // xmm0
  vec4f v18; // xmm0
  __int64 v19; // [esp+4h] [ebp-10h]
  float v20; // [esp+Ch] [ebp-8h]
  float v21; // [esp+10h] [ebp-4h]
  float v22; // [esp+10h] [ebp-4h]

  v3 = Sim::getFocusedCarIndex(this->car->sim);
  v4 = Sim::getCar(this->car->sim, v3);
  v5 = this->prgGas;
  this->car = v4;
  v5->value = v4->physicsState.gas;
  this->prgBrake->value = this->car->physicsState.brake;
  v6 = 1.0 - this->car->physicsState.clutch;
  if ( v6 <= 1.0 )
  {
    if ( v6 < 0.0 )
      v6 = 0.0;
  }
  else
  {
    v6 = FLOAT_1_0;
  }
  v20 = FLOAT_1_0;
  this->prgClutch->value = v6;
  v7 = this->car->raceEngineer._Myptr;
  if ( v7 && RaceEngineer::getCar(v7) )
    v20 = RaceEngineer::getCar(this->car->raceEngineer._Myptr)->userFFGain;
  v8 = CarAvatar::getControlsProvider(this->car);
  v9 = (int)v8;
  if ( v8 )
  {
    LODWORD(v21) = LODWORD(this->car->physicsState.lastFF_Pure) & _xmm;
    v10 = FLOAT_1_0;
    v22 = ((double (*)(ICarControlsProvider *))v8->getFFGlobalGain)(v8) * (float)(v21 * v20);
    v11 = v22;
    if ( v22 <= 1.0 )
    {
      v12 = 0.0;
      if ( v22 >= 0.0 )
        v12 = v22;
      this->prgFF->value = v12;
    }
    else
    {
      this->prgFF->value = FLOAT_1_0;
    }
  }
  else
  {
    v10 = FLOAT_1_0;
    v11 = 0.0;
  }
  v13 = this->prgGas;
  if ( this->car->physicsState.gas < v10 )
  {
    v14 = _xmm;
  }
  else
  {
    v14 = _xmm;
    this->isGasOk = 1;
  }
  v13->borderColor = (vec4f)v14;
  if ( this->isGasOk )
    v15 = (vec4f)_xmm;
  else
    v15 = (vec4f)_xmm;
  this->gasLed->backColor = v15;
  if ( this->car->physicsState.brake <= 0.0 )
    v16 = (vec4f)_xmm;
  else
    v16 = (vec4f)_xmm;
  this->prgBrake->borderColor = v16;
  if ( this->car->physicsState.clutch <= 0.0 )
    v17 = (vec4f)_xmm;
  else
    v17 = (vec4f)_xmm;
  this->prgClutch->borderColor = v17;
  if ( v9 && v11 > v10 )
    v18 = (vec4f)_xmm;
  else
    v18 = (vec4f)_xmm;
  this->prgFF->foreColor = v18;
  ksgui::Control::render(this, v9, (int)this, dt, v19, v20);
}
