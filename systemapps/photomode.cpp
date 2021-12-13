#include "photomode.h"
void PhotoMode::PhotoMode(PhotoMode *this, Sim *aSim)
{
  Game *v3; // eax
  const std::wstring *v4; // eax
  Sim *v5; // ecx
  CameraForward *v6; // eax
  Texture *v7; // eax
  Font *v8; // edi
  ksgui::Control *v9; // eax
  ksgui::Control *v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  const std::wstring *v18; // eax
  Font *v19; // eax
  Font *v20; // eax
  std::_Ref_count_base *v21; // esi
  Font *v22; // esi
  ksgui::Spinner *v23; // eax
  int i; // ebp
  ksgui::Spinner *v25; // edi
  int v26; // ecx
  ksgui::Spinner *v27; // ecx
  std::vector<ksgui::Control *> *v28; // edi
  ksgui::Control **v29; // eax
  int v30; // ebp
  ksgui::Control **v31; // edx
  ksgui::Control **v32; // eax
  ksgui::CustomSpinner *v33; // eax
  Texture *v34; // eax
  ksgui::Control *v35; // ecx
  std::wstring *v36; // ecx
  Texture *v37; // eax
  ksgui::Control *v38; // ecx
  std::wstring *v39; // ecx
  ksgui::CustomSpinner *v40; // ecx
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  ksgui::CustomSpinner *v46; // eax
  Texture *v47; // eax
  ksgui::Control *v48; // ecx
  std::wstring *v49; // ecx
  Texture *v50; // eax
  ksgui::Control *v51; // ecx
  std::wstring *v52; // ecx
  ksgui::CustomSpinner *v53; // ecx
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  ksgui::CustomSpinner *v59; // eax
  Texture *v60; // eax
  ksgui::Control *v61; // ecx
  std::wstring *v62; // ecx
  Texture *v63; // eax
  ksgui::Control *v64; // ecx
  std::wstring *v65; // ecx
  ksgui::CustomSpinner *v66; // ecx
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm1_4
  float v71; // xmm2_4
  Font *v72; // esi
  ksgui::CustomSpinner *v73; // eax
  ResourceStore *v74; // eax
  const Texture *v75; // eax
  ResourceStore *v76; // eax
  const Texture *v77; // eax
  PhotoMode::{ctor}::__l20::<lambda_b77ccd4e3e9508a9cd389ca17e0af2d5> *v78; // eax
  PhotoMode::{ctor}::__l21::<lambda_224aac95dd10d440658a5a5597d5a682> *v79; // eax
  Font *v80; // esi
  ksgui::CustomSpinner *v81; // eax
  ResourceStore *v82; // eax
  const Texture *v83; // eax
  ResourceStore *v84; // eax
  const Texture *v85; // eax
  PhotoMode::{ctor}::__l22::<lambda_58f2cfb783c46db37b5e71f4833d033e> *v86; // eax
  PhotoMode::{ctor}::__l23::<lambda_17c8a280ea512bb44dc36c1d857399b0> *v87; // eax
  Font *v88; // esi
  ksgui::CustomSpinner *v89; // eax
  ResourceStore *v90; // eax
  const Texture *v91; // eax
  ResourceStore *v92; // eax
  const Texture *v93; // eax
  PhotoMode::{ctor}::__l24::<lambda_38281e3cd09ddb6094da750f8bc62b9a> *v94; // eax
  PhotoMode::{ctor}::__l25::<lambda_59900e1a24bc294cc201d779764b60ee> *v95; // eax
  Font *v96; // esi
  ksgui::CustomSpinner *v97; // eax
  ResourceStore *v98; // eax
  const Texture *v99; // eax
  ResourceStore *v100; // eax
  const Texture *v101; // eax
  PhotoMode::{ctor}::__l26::<lambda_3a149be7f1eca55709e851c5bfe061b2> *v102; // eax
  PhotoMode::{ctor}::__l27::<lambda_fae0a4f4dd717169c690cc86b0fb2f34> *v103; // eax
  _BYTE v104[28]; // [esp+38h] [ebp-D4h] BYREF
  float h; // [esp+54h] [ebp-B8h]
  ksgui::CustomSpinner *v106; // [esp+8Ch] [ebp-80h]
  int _Val; // [esp+90h] [ebp-7Ch] BYREF
  std::shared_ptr<Font> v108; // [esp+94h] [ebp-78h] BYREF
  int v109; // [esp+9Ch] [ebp-70h]
  int v110[2]; // [esp+A0h] [ebp-6Ch] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement text; // [esp+A8h] [ebp-64h] BYREF
  int result_16; // [esp+D4h] [ebp-38h]
  unsigned int result_20; // [esp+D8h] [ebp-34h]
  Texture v114; // [esp+E0h] [ebp-2Ch] BYREF
  int v115; // [esp+108h] [ebp-4h]

  _Val = 0;
  h = 0.0;
  v109 = 0;
  v3 = aSim->game;
  v110[1] = (int)this;
  v106 = (ksgui::CustomSpinner *)aSim;
  *(_DWORD *)&v104[24] = v3->gui;
  *(_DWORD *)&v104[20] = 7;
  *(_DWORD *)&v104[16] = 0;
  *(_WORD *)v104 = 0;
  std::wstring::assign((std::wstring *)v104, L"CAMERA_PICTURE_MODE", 0x13u);
  ksgui::Form::Form(this, (unsigned int)this, *(std::wstring *)v104, *(ksgui::GUI **)&v104[24], SLOBYTE(h));
  v115 = 0;
  this->__vftable = (PhotoMode_vtbl *)&PhotoMode::`vftable';
  this->sim = aSim;
  this->currentAzimuth = 0.0;
  this->currentZenith = 0.0;
  this->multipler = 1.0;
  this->viewFinder.kid = 0;
  this->viewFinder.fileName._Myres = 7;
  this->viewFinder.fileName._Mysize = 0;
  this->viewFinder.fileName._Bx._Buf[0] = 0;
  LOBYTE(v115) = 1;
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"Photo mode", 0xAu);
  LOBYTE(v115) = 2;
  v4 = acTranslate((std::wstring *)&text.isPlayer, &text.name);
  LOBYTE(v115) = 3;
  this->formTitle->setText(this->formTitle, v4);
  if ( result_20 >= 8 )
    operator delete(*(void **)&text.isPlayer);
  LOBYTE(v115) = 1;
  result_20 = 7;
  result_16 = 0;
  *(_WORD *)&text.isPlayer = 0;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  v5 = this->sim;
  h = 0.0;
  *(_DWORD *)&v104[24] = &CameraForward `RTTI Type Descriptor';
  *(_DWORD *)&v104[20] = &Camera `RTTI Type Descriptor';
  *(_DWORD *)&v104[16] = 0;
  this->devApp = 1;
  v6 = Sim::getSceneCamera(v5);
  this->camera = (CameraForward *)__RTDynamicCast(
                                    v6,
                                    *(_DWORD *)&v104[16],
                                    *(_DWORD *)&v104[20],
                                    *(_DWORD *)&v104[24],
                                    LODWORD(h));
  this->photoModeActive = 0;
  ksgui::Form::setSize(this, 280.0, 450.0);
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"content//gui//photoMode//viewFinder.png", 0x27u);
  LOBYTE(v115) = 4;
  v7 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&text.isPlayer, &text.name, 0);
  LOBYTE(v115) = 5;
  this->viewFinder.kid = v7->kid;
  if ( &this->viewFinder.fileName != &v7->fileName )
    std::wstring::assign(&this->viewFinder.fileName, &v7->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v115) = 4;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text.isPlayer);
  LOBYTE(v115) = 1;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  v8 = (Font *)operator new(0x118u);
  v108._Ptr = v8;
  v9 = 0;
  LOBYTE(v115) = 6;
  if ( v8 )
  {
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    std::wstring::assign(&text.name, L"ACTIVATE_CONTROL", 0x10u);
    LOBYTE(v115) = 7;
    v109 = 1;
    _Val = 1;
    ksgui::Control::Control((ksgui::Control *)v8, &text.name, *((ksgui::GUI **)v106->name._Bx._Ptr + 63));
  }
  this->btnActivatePhotoMode = v9;
  v115 = 1;
  if ( (v109 & 1) != 0 )
  {
    v109 &= 0xFFFFFFFE;
    if ( text.name._Myres >= 8 )
      operator delete(text.name._Bx._Ptr);
  }
  _Val = (int)this->btnActivatePhotoMode;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ((void (*)(ksgui::Control *, int, int))this->btnActivatePhotoMode->setSize)(
    this->btnActivatePhotoMode,
    1120403456,
    1103626240);
  v10 = this->btnActivatePhotoMode;
  v11 = v10->rect.right - v10->rect.left;
  v12 = v10->rect.bottom - v10->rect.top;
  v13 = (float)(this->rect.right - this->rect.left) - v11;
  v10->rect.top = 50.0;
  v14 = v10->rectBase.left;
  v15 = v13 * 0.5;
  v16 = v12 + 50.0;
  v10->rect.left = v15;
  v17 = v11 + v15;
  v10->rect.bottom = v16;
  v10->rect.right = v17;
  if ( v14 == 0.0 && v10->rectBase.top == 0.0 )
  {
    v10->rectBase.left = v15;
    v10->rectBase.top = 50.0;
    v10->rectBase.right = v17;
    v10->rectBase.bottom = v16;
  }
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_d95bf0dd7f50592fc1cd23cfa4fcdc46_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->btnActivatePhotoMode->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    this);
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"Start", 5u);
  LOBYTE(v115) = 10;
  v18 = acTranslate((std::wstring *)&text.isPlayer, &text.name);
  LOBYTE(v115) = 11;
  this->btnActivatePhotoMode->setText(this->btnActivatePhotoMode, v18);
  if ( result_20 >= 8 )
    operator delete(*(void **)&text.isPlayer);
  LOBYTE(v115) = 1;
  result_20 = 7;
  result_16 = 0;
  *(_WORD *)&text.isPlayer = 0;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  v19 = (Font *)operator new(0x18u);
  v108._Ptr = v19;
  LOBYTE(v115) = 12;
  if ( v19 )
    Font::Font(v19, eFontMonospaced, 20.0, 0, 0);
  else
    v20 = 0;
  LOBYTE(v115) = 1;
  v108 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v108, v20);
  v21 = this->font._Rep;
  this->font = v108;
  if ( v21 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v21->_Uses, 0xFFFFFFFF) )
    {
      v21->_Destroy(v21);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v21->_Weaks) )
        v21->_Delete_this(v21);
    }
  }
  Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  v22 = (Font *)operator new(0x1BCu);
  v108._Ptr = v22;
  v23 = 0;
  LOBYTE(v115) = 13;
  if ( v22 )
  {
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    std::wstring::assign(&text.name, L"PRECISION EXP", 0xDu);
    LOBYTE(v115) = 14;
    h = 0.0;
    *(_DWORD *)&v104[24] = 1;
    *(_DWORD *)&v104[20] = this->gui;
    v109 |= 2u;
    _Val = v109;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v22, &text.name, *(ksgui::GUI **)&v104[20], 1, 0);
  }
  this->spiPrecision = v23;
  v115 = 1;
  if ( (v109 & 2) != 0 && text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  ((void (*)(ksgui::Spinner *, int, int))this->spiPrecision->setSize)(
    this->spiPrecision,
    1128792064,
    1106247680);
  ksgui::Spinner::setPosition(
    this->spiPrecision,
    (float)((float)(this->rect.right - this->rect.left)
          - (float)(this->spiPrecision->rect.right - this->spiPrecision->rect.left))
  * 0.5,
    110.0);
  for ( i = 0; i < 7; ++i )
  {
    std::to_wstring((std::wstring *)&text.isPlayer, i - 3);
    v25 = this->spiPrecision;
    LOBYTE(v115) = 16;
    std::vector<std::wstring>::push_back(&v25->items, (const std::wstring *)&text.isPlayer);
    v25->minValue = 0;
    v26 = (char *)v25->items._Mylast - (char *)v25->items._Myfirst;
    LOBYTE(v115) = 1;
    v25->maxValue = ((int)((unsigned __int64)(715827883i64 * v26) >> 32) >> 2)
                  + ((unsigned int)((unsigned __int64)(715827883i64 * v26) >> 32) >> 31)
                  - 1;
    if ( result_20 >= 8 )
      operator delete(*(void **)&text.isPlayer);
  }
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_b153d7ac7522b694d7363c1d40dd8371_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spiPrecision->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v104[4],
    this);
  ksgui::Spinner::setValue(this->spiPrecision, 3);
  v27 = this->spiPrecision;
  v28 = &this->controls;
  v29 = this->controls._Mylast;
  _Val = (int)v27;
  v110[0] = (int)v27;
  if ( v110 >= (int *)v29 || v28->_Myfirst > (ksgui::Control **)v110 )
  {
    if ( v29 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v27 = (ksgui::Spinner *)_Val;
    }
    v32 = this->controls._Mylast;
    if ( v32 )
      *v32 = v27;
  }
  else
  {
    v30 = ((char *)v110 - (char *)v28->_Myfirst) >> 2;
    if ( v29 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v27 = (ksgui::Spinner *)_Val;
    }
    v31 = this->controls._Mylast;
    if ( v31 )
      *v31 = v28->_Myfirst[v30];
  }
  ++this->controls._Mylast;
  LODWORD(h) = 340;
  v27->parent = this;
  v106 = (ksgui::CustomSpinner *)operator new(LODWORD(h));
  LOBYTE(v115) = 18;
  if ( v106 )
  {
    h = 0.0;
    *(_DWORD *)&v104[24] = this->gui;
    *(_DWORD *)&v104[20] = 7;
    *(_DWORD *)&v104[16] = 0;
    *(_WORD *)v104 = 0;
    std::wstring::assign((std::wstring *)v104, L"EXPO", 4u);
    ksgui::CustomSpinner::CustomSpinner(v106, *(std::wstring *)v104, *(ksgui::GUI **)&v104[24], SLODWORD(h));
  }
  else
  {
    v33 = 0;
  }
  LOBYTE(v115) = 1;
  this->spiExpo = v33;
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"content/gui/controls/spinner/leftMinus.png", 0x2Au);
  LOBYTE(v115) = 19;
  v34 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&text.isPlayer, &text.name, 0);
  LOBYTE(v115) = 20;
  v35 = this->spiExpo->leftButton;
  v35->backTexture.kid = v34->kid;
  v36 = &v35->backTexture.fileName;
  if ( v36 != &v34->fileName )
    std::wstring::assign(v36, &v34->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v115) = 19;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text.isPlayer);
  LOBYTE(v115) = 1;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"content/gui/controls/spinner/rightPlus.png", 0x2Au);
  LOBYTE(v115) = 21;
  v37 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&text.isPlayer, &text.name, 0);
  LOBYTE(v115) = 22;
  v38 = this->spiExpo->rightButton;
  v38->backTexture.kid = v37->kid;
  v39 = &v38->backTexture.fileName;
  if ( v39 != &v37->fileName )
    std::wstring::assign(v39, &v37->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v115) = 21;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text.isPlayer);
  LOBYTE(v115) = 1;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiExpo->setSize)(this->spiExpo, 1111752704, 1102577664);
  v40 = this->spiExpo;
  v41 = v40->rectBase.left;
  v42 = v40->rect.right - v40->rect.left;
  v43 = v40->rect.bottom - v40->rect.top;
  v40->rect.top = 150.0;
  v40->rect.left = 10.0;
  v44 = v42 + 10.0;
  v45 = v43 + 150.0;
  v40->rect.right = v44;
  v40->rect.bottom = v45;
  if ( v41 == 0.0 && v40->rectBase.top == 0.0 )
  {
    v40->rectBase.left = 10.0;
    v40->rectBase.top = 150.0;
    v40->rectBase.right = v44;
    v40->rectBase.bottom = v45;
  }
  _Val = (int)this->spiExpo;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = this;
  *(_DWORD *)(_Val + 148) = this;
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_ad77994dfc8a6f57307d540f8e68a3ef_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiExpo->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_dfebd4b51ab9a56e80442c11d8b8cbe2_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiExpo->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    this);
  v106 = (ksgui::CustomSpinner *)operator new(0x154u);
  LOBYTE(v115) = 25;
  if ( v106 )
  {
    h = 0.0;
    *(_DWORD *)&v104[24] = this->gui;
    std::wstring::wstring((std::wstring *)v104, L"EXPO");
    ksgui::CustomSpinner::CustomSpinner(v106, *(std::wstring *)v104, *(ksgui::GUI **)&v104[24], SLODWORD(h));
  }
  else
  {
    v46 = 0;
  }
  LOBYTE(v115) = 1;
  this->spiFov = v46;
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"content/gui/controls/spinner/leftMinus.png", 0x2Au);
  LOBYTE(v115) = 26;
  v47 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&text.isPlayer, &text.name, 0);
  LOBYTE(v115) = 27;
  v48 = this->spiFov->leftButton;
  v48->backTexture.kid = v47->kid;
  v49 = &v48->backTexture.fileName;
  if ( v49 != &v47->fileName )
    std::wstring::assign(v49, &v47->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v115) = 26;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text.isPlayer);
  LOBYTE(v115) = 1;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"content/gui/controls/spinner/rightPlus.png", 0x2Au);
  LOBYTE(v115) = 28;
  v50 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&text.isPlayer, &text.name, 0);
  LOBYTE(v115) = 29;
  v51 = this->spiFov->rightButton;
  v51->backTexture.kid = v50->kid;
  v52 = &v51->backTexture.fileName;
  if ( v52 != &v50->fileName )
    std::wstring::assign(v52, &v50->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v115) = 28;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text.isPlayer);
  LOBYTE(v115) = 1;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiFov->setSize)(this->spiFov, 1111752704, 1102577664);
  v53 = this->spiFov;
  v54 = v53->rectBase.left;
  v55 = v53->rect.right - v53->rect.left;
  v56 = v53->rect.bottom - v53->rect.top;
  v53->rect.top = 190.0;
  v53->rect.left = 10.0;
  v57 = v55 + 10.0;
  v58 = v56 + 190.0;
  v53->rect.right = v57;
  v53->rect.bottom = v58;
  if ( v54 == 0.0 && v53->rectBase.top == 0.0 )
  {
    v53->rectBase.left = 10.0;
    v53->rectBase.top = 190.0;
    v53->rectBase.right = v57;
    v53->rectBase.bottom = v58;
  }
  _Val = (int)this->spiFov;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = this;
  *(_DWORD *)(_Val + 148) = this;
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_9391e0b978300af3f794bece46ddc832_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiFov->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_3f6c45a970da4332f4e69b3f7d943ec7_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiFov->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    this);
  v106 = (ksgui::CustomSpinner *)operator new(0x154u);
  LOBYTE(v115) = 32;
  if ( v106 )
  {
    h = 0.0;
    *(_DWORD *)&v104[24] = this->gui;
    std::wstring::wstring((std::wstring *)v104, L"EXPO");
    ksgui::CustomSpinner::CustomSpinner(v106, *(std::wstring *)v104, *(ksgui::GUI **)&v104[24], SLODWORD(h));
  }
  else
  {
    v59 = 0;
  }
  LOBYTE(v115) = 1;
  LODWORD(h) = L"content/gui/controls/spinner/leftMinus.png";
  this->spiDofFactor = v59;
  std::wstring::wstring((std::wstring *)&text.isPlayer, (const wchar_t *)LODWORD(h));
  LOBYTE(v115) = 33;
  v60 = ResourceStore::getTexture(
          this->gui->graphics->resourceStore._Myptr,
          (Texture *)&text,
          (const std::wstring *)&text.isPlayer,
          0);
  LOBYTE(v115) = 34;
  v61 = this->spiDofFactor->leftButton;
  v61->backTexture.kid = v60->kid;
  v62 = &v61->backTexture.fileName;
  if ( v62 != &v60->fileName )
    std::wstring::assign(v62, &v60->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v115) = 33;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text);
  LOBYTE(v115) = 1;
  if ( result_20 >= 8 )
    operator delete(*(void **)&text.isPlayer);
  std::wstring::wstring((std::wstring *)&text.isPlayer, L"content/gui/controls/spinner/rightPlus.png");
  LOBYTE(v115) = 35;
  v63 = ResourceStore::getTexture(
          this->gui->graphics->resourceStore._Myptr,
          (Texture *)&text,
          (const std::wstring *)&text.isPlayer,
          0);
  LOBYTE(v115) = 36;
  v64 = this->spiDofFactor->rightButton;
  v64->backTexture.kid = v63->kid;
  v65 = &v64->backTexture.fileName;
  if ( v65 != &v63->fileName )
    std::wstring::assign(v65, &v63->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v115) = 35;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text);
  LOBYTE(v115) = 1;
  if ( result_20 >= 8 )
    operator delete(*(void **)&text.isPlayer);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiDofFactor->setSize)(
    this->spiDofFactor,
    1111752704,
    1102577664);
  v66 = this->spiDofFactor;
  v67 = v66->rectBase.left;
  v68 = v66->rect.right - v66->rect.left;
  v69 = v66->rect.bottom - v66->rect.top;
  v66->rect.top = 230.0;
  v66->rect.left = 10.0;
  v70 = v68 + 10.0;
  v71 = v69 + 230.0;
  v66->rect.right = v70;
  v66->rect.bottom = v71;
  if ( v67 == 0.0 && v66->rectBase.top == 0.0 )
  {
    v66->rectBase.left = 10.0;
    v66->rectBase.top = 230.0;
    v66->rectBase.right = v70;
    v66->rectBase.bottom = v71;
  }
  _Val = (int)this->spiDofFactor;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = this;
  *(_DWORD *)(_Val + 148) = this;
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_83b33431ecd54d2189d665f1211daa3e_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiDofFactor->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_41cf28f9ab5794b669dc79d6761a3dac_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v104[8] = this;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v115) = 1;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiDofFactor->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    this);
  v72 = (Font *)operator new(0x154u);
  v108._Ptr = v72;
  LOBYTE(v115) = 39;
  if ( v72 )
  {
    h = 0.0;
    *(_DWORD *)&v104[24] = this->gui;
    std::wstring::wstring((std::wstring *)v104, L"EXPO");
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v72,
      *(std::wstring *)v104,
      *(ksgui::GUI **)&v104[24],
      SLODWORD(h));
  }
  else
  {
    v73 = 0;
  }
  LOBYTE(v115) = 1;
  LODWORD(h) = L"content/gui/controls/spinner/leftMinus.png";
  this->spiDofFocus = v73;
  std::wstring::wstring((std::wstring *)&text.isPlayer, (const wchar_t *)LODWORD(h));
  h = 0.0;
  LOBYTE(v115) = 40;
  *(_DWORD *)&v104[24] = &text.isPlayer;
  *(_DWORD *)&v104[20] = &text;
  v74 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v75 = ResourceStore::getTexture(v74, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 41;
  Texture::operator=(&this->spiDofFocus->leftButton->backTexture, v75);
  LOBYTE(v115) = 40;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text);
  LOBYTE(v115) = 1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text.isPlayer);
  std::wstring::wstring((std::wstring *)&text.isPlayer, L"content/gui/controls/spinner/rightPlus.png");
  h = 0.0;
  LOBYTE(v115) = 42;
  *(_DWORD *)&v104[24] = &text.isPlayer;
  *(_DWORD *)&v104[20] = &text;
  v76 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v77 = ResourceStore::getTexture(v76, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 43;
  Texture::operator=(&this->spiDofFocus->rightButton->backTexture, v77);
  LOBYTE(v115) = 42;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text);
  LOBYTE(v115) = 1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text.isPlayer);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiDofFocus->setSize)(
    this->spiDofFocus,
    1111752704,
    1102577664);
  ksgui::Form::setPosition((ksgui::Form *)this->spiDofFocus, 10.0, 270.0);
  ksgui::Control::addControl(this, this->spiDofFocus);
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v78);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiDofFocus->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v79);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiDofFocus->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  v80 = (Font *)operator new(0x154u);
  v108._Ptr = v80;
  LOBYTE(v115) = 44;
  if ( v80 )
  {
    h = 0.0;
    *(_DWORD *)&v104[24] = this->gui;
    std::wstring::wstring((std::wstring *)v104, L"EXPO");
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v80,
      *(std::wstring *)v104,
      *(ksgui::GUI **)&v104[24],
      SLODWORD(h));
  }
  else
  {
    v81 = 0;
  }
  LOBYTE(v115) = 1;
  LODWORD(h) = L"content/gui/controls/spinner/leftMinus.png";
  this->spiCameraRoll = v81;
  std::wstring::wstring((std::wstring *)&text.isPlayer, (const wchar_t *)LODWORD(h));
  h = 0.0;
  LOBYTE(v115) = 45;
  *(_DWORD *)&v104[24] = &text.isPlayer;
  *(_DWORD *)&v104[20] = &text;
  v82 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v83 = ResourceStore::getTexture(v82, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 46;
  Texture::operator=(&this->spiCameraRoll->leftButton->backTexture, v83);
  LOBYTE(v115) = 45;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text);
  LOBYTE(v115) = 1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text.isPlayer);
  std::wstring::wstring((std::wstring *)&text.isPlayer, L"content/gui/controls/spinner/rightPlus.png");
  h = 0.0;
  LOBYTE(v115) = 47;
  *(_DWORD *)&v104[24] = &text.isPlayer;
  *(_DWORD *)&v104[20] = &text;
  v84 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v85 = ResourceStore::getTexture(v84, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 48;
  Texture::operator=(&this->spiCameraRoll->rightButton->backTexture, v85);
  LOBYTE(v115) = 47;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&text);
  LOBYTE(v115) = 1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text.isPlayer);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiCameraRoll->setSize)(
    this->spiCameraRoll,
    1111752704,
    1102577664);
  ksgui::Form::setPosition((ksgui::Form *)this->spiCameraRoll, 10.0, 310.0);
  ksgui::Control::addControl(this, this->spiCameraRoll);
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v86);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiCameraRoll->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v87);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiCameraRoll->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  v88 = (Font *)operator new(0x154u);
  v108._Ptr = v88;
  LOBYTE(v115) = 49;
  if ( v88 )
  {
    h = 0.0;
    *(_DWORD *)&v104[24] = this->gui;
    std::wstring::wstring((std::wstring *)v104, L"AZIMUTH");
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v88,
      *(std::wstring *)v104,
      *(ksgui::GUI **)&v104[24],
      SLODWORD(h));
  }
  else
  {
    v89 = 0;
  }
  LOBYTE(v115) = 1;
  LODWORD(h) = L"content/gui/controls/spinner/leftMinus.png";
  this->spiSunAzimuth = v89;
  std::wstring::wstring((std::wstring *)&text.isPlayer, (const wchar_t *)LODWORD(h));
  h = 0.0;
  LOBYTE(v115) = 50;
  *(_DWORD *)&v104[24] = &text.isPlayer;
  *(_DWORD *)&v104[20] = &v114;
  v90 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v91 = ResourceStore::getTexture(v90, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 51;
  Texture::operator=(&this->spiSunAzimuth->leftButton->backTexture, v91);
  LOBYTE(v115) = 50;
  OnSetupAppCreated::~OnSetupAppCreated(&v114);
  LOBYTE(v115) = 1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text.isPlayer);
  std::wstring::wstring(&text.name, L"content/gui/controls/spinner/rightPlus.png");
  h = 0.0;
  LOBYTE(v115) = 52;
  *(_DWORD *)&v104[24] = &text;
  *(_DWORD *)&v104[20] = &v114;
  v92 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v93 = ResourceStore::getTexture(v92, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 53;
  Texture::operator=(&this->spiSunAzimuth->rightButton->backTexture, v93);
  LOBYTE(v115) = 52;
  OnSetupAppCreated::~OnSetupAppCreated(&v114);
  LOBYTE(v115) = 1;
  std::wstring::~wstring(&text);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiSunAzimuth->setSize)(
    this->spiSunAzimuth,
    1111752704,
    1102577664);
  ksgui::Form::setPosition((ksgui::Form *)this->spiSunAzimuth, 10.0, 350.0);
  ksgui::Control::addControl(this, this->spiSunAzimuth);
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v94);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunAzimuth->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v95);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunAzimuth->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  v96 = (Font *)operator new(0x154u);
  v108._Ptr = v96;
  LOBYTE(v115) = 54;
  if ( v96 )
  {
    h = 0.0;
    *(_DWORD *)&v104[24] = this->gui;
    std::wstring::wstring((std::wstring *)v104, L"EXPO");
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v96,
      *(std::wstring *)v104,
      *(ksgui::GUI **)&v104[24],
      SLODWORD(h));
  }
  else
  {
    v97 = 0;
  }
  LOBYTE(v115) = 1;
  LODWORD(h) = L"content/gui/controls/spinner/leftMinus.png";
  this->spiSunZenith = v97;
  std::wstring::wstring((std::wstring *)&text.isPlayer, (const wchar_t *)LODWORD(h));
  h = 0.0;
  LOBYTE(v115) = 55;
  *(_DWORD *)&v104[24] = &text.isPlayer;
  *(_DWORD *)&v104[20] = &v114;
  v98 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v99 = ResourceStore::getTexture(v98, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 56;
  Texture::operator=(&this->spiSunZenith->leftButton->backTexture, v99);
  LOBYTE(v115) = 55;
  OnSetupAppCreated::~OnSetupAppCreated(&v114);
  LOBYTE(v115) = 1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text.isPlayer);
  std::wstring::wstring(&text.name, L"content/gui/controls/spinner/rightPlus.png");
  h = 0.0;
  LOBYTE(v115) = 57;
  *(_DWORD *)&v104[24] = &text;
  *(_DWORD *)&v104[20] = &v114;
  v100 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v101 = ResourceStore::getTexture(v100, *(Texture **)&v104[20], *(const std::wstring **)&v104[24], SLOBYTE(h));
  LOBYTE(v115) = 58;
  Texture::operator=(&this->spiSunZenith->rightButton->backTexture, v101);
  LOBYTE(v115) = 57;
  OnSetupAppCreated::~OnSetupAppCreated(&v114);
  LOBYTE(v115) = 1;
  std::wstring::~wstring(&text);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiSunZenith->setSize)(
    this->spiSunZenith,
    1111752704,
    1102577664);
  ksgui::Form::setPosition((ksgui::Form *)this->spiSunZenith, 10.0, 390.0);
  ksgui::Control::addControl(this, this->spiSunZenith);
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v102);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunZenith->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
  LODWORD(h) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v108,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v104[4],
    v103);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunZenith->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v104[4],
    (void *)LODWORD(h));
}
PhotoMode *PhotoMode::`scalar deleting destructor'(PhotoMode *this, unsigned int a2)
{
  this->__vftable = (PhotoMode_vtbl *)&PhotoMode::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->viewFinder);
  this->__vftable = (PhotoMode_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PhotoMode::onMouseWheelMovedEvent(PhotoMode *this, const OnMouseWheelMovedEvent *message)
{
  bool v3; // zf
  float v4; // xmm0_4
  CameraForward *v5; // eax
  float v6; // xmm1_4
  CameraForward *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( this->visible )
  {
    v3 = GetAsyncKeyState(2) == 0;
    v4 = message->delta;
    if ( v3 )
    {
      v5 = this->camera;
      v6 = v5->fov;
      if ( v4 <= 0.0 )
      {
        if ( v6 < 120.0 )
          v5->fov = (float)(this->multipler * 0.5) + v6;
      }
      else if ( v6 > 0.5 )
      {
        v5->fov = v6 - (float)(this->multipler * 0.5);
      }
    }
    else
    {
      this->camera->dofFocus = (float)(v4 * 0.00050000002) + this->camera->dofFocus;
      v7 = this->camera;
      v8 = FLOAT_1000_0;
      v9 = v7->dofFocus;
      if ( v9 <= 1000.0 )
      {
        v8 = 0.0;
        if ( v9 >= 0.0 )
          v8 = v7->dofFocus;
      }
      v7->dofFocus = v8;
    }
  }
}
void PhotoMode::render(PhotoMode *this, float dt)
{
  PhotoMode *v2; // ebx
  int v3; // esi
  GLRenderer *v4; // esi
  bool v5; // bl
  bool v6; // al
  bool v7; // zf
  GraphicsManager *v8; // eax
  __m128 v9; // xmm0
  Sim *v10; // ecx
  GraphicsManager *v11; // esi
  CameraForward *v12; // eax
  const std::wstring *v13; // eax
  int v14; // esi
  const std::wstring *v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  const std::wstring *v20; // eax
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  const std::wstring *v25; // eax
  std::wostream *v26; // eax
  std::wostream *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  const std::wstring *v30; // eax
  std::wostream *v31; // eax
  std::wostream *v32; // eax
  std::wstring *v33; // eax
  std::wstring *v34; // eax
  const std::wstring *v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // eax
  const std::wstring *v38; // eax
  std::wstring *v39; // eax
  std::wstring *v40; // eax
  const std::wstring *v41; // eax
  std::wstring *v42; // eax
  Node *a; // [esp+34h] [ebp-210h]
  __int64 v44; // [esp+38h] [ebp-20Ch]
  float v45; // [esp+40h] [ebp-204h]
  bool v46; // [esp+53h] [ebp-1F1h]
  PhotoMode *v47; // [esp+58h] [ebp-1ECh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > data; // [esp+5Ch] [ebp-1E8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v49; // [esp+10Ch] [ebp-138h] BYREF
  RayPicker rayPicker; // [esp+1BCh] [ebp-88h] BYREF
  std::wstring text; // [esp+200h] [ebp-44h] BYREF
  std::wstring result; // [esp+218h] [ebp-2Ch] BYREF
  int v53; // [esp+240h] [ebp-4h]

  v2 = this;
  v47 = this;
  v3 = 0;
  if ( this->photoModeActive )
  {
    v4 = this->gui->graphics->gl;
    GLRenderer::color4f(v4, 1.0, 1.0, 1.0, 1.0);
    GraphicsManager::setTexture(v2->gui->graphics, 0, &v2->viewFinder);
    GLRenderer::quad(
      v4,
      0.0,
      0.0,
      (float)v2->gui->graphics->videoSettings.width,
      (float)v2->gui->graphics->videoSettings.height,
      1,
      0);
    v5 = GetAsyncKeyState(35) != 0;
    v6 = GetAsyncKeyState(4) != 0;
    v7 = !v5;
    v2 = v47;
    v46 = v6;
    if ( v7 )
    {
      v3 = 0;
    }
    else
    {
      v8 = v47->gui->graphics;
      v9 = (__m128)COERCE_UNSIGNED_INT((float)v8->videoSettings.width);
      RayPicker::RayPicker(&rayPicker, (float)v8->videoSettings.width, (float)v8->videoSettings.height);
      v53 = 0;
      v10 = v47->sim;
      a = v10->rootNode;
      v11 = v47->gui->graphics;
      v12 = Sim::getSceneCamera(v10);
      RayPicker::pick(&rayPicker, v9, v11->videoSettings.width / 2, v11->videoSettings.height / 2, v12, a);
      *(_DWORD *)v49.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v49.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v49.gap68);
      LOBYTE(v53) = 1;
      v3 = 1;
      std::wiostream::basic_iostream<wchar_t>(&v49, &v49.gap10[8], 0);
      v53 = 2;
      *(_DWORD *)&v49.gap0[*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&data.gap68[*(_DWORD *)(*(_DWORD *)v49.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v49.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v49.gap10[8]);
      *(_DWORD *)&v49.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v49.gap10[64] = 0;
      *(_DWORD *)&v49.gap10[68] = 0;
      LOBYTE(v53) = 4;
      std::wostream::operator<<(v49.gap10);
      v2->camera->dofFocus = rayPicker.pickedDistance;
      Font::setColor(v2->font._Ptr, 1.0, 0.0, 0.0, 1.0);
      v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v49, &result);
      LOBYTE(v53) = 5;
      Font::blitString(v2->font._Ptr, 0.0, 0.0, v13, 1.0, eAlignLeft);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v49);
      v53 = -1;
      RayPicker::~RayPicker(&rayPicker);
      v6 = v46;
    }
    if ( v6 )
    {
      std::wstring::wstring(&result, word_17BE9D8);
      v53 = 6;
      ScreenCapturer::takeScreen(v2->sim->screenCapturer, &result);
      v53 = -1;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  *(_DWORD *)data.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)data.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(data.gap68);
  v53 = 7;
  v14 = v3 | 2;
  std::wiostream::basic_iostream<wchar_t>(&data, &data.gap10[8], 0);
  v53 = 8;
  *(_DWORD *)&data.gap0[*(_DWORD *)(*(_DWORD *)data.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(PhotoMode **)((char *)&v47 + *(_DWORD *)(*(_DWORD *)data.gap0 + 4)) = (PhotoMode *)(*(_DWORD *)(*(_DWORD *)data.gap0
                                                                                                  + 4)
                                                                                      - 104);
  std::wstreambuf::wstreambuf(&data.gap10[8]);
  *(_DWORD *)&data.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&data.gap10[64] = 0;
  *(_DWORD *)&data.gap10[68] = 0;
  v53 = 10;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"DOF factor", 0xAu);
  LOBYTE(v53) = 11;
  v15 = acTranslate(&result, &text);
  LOBYTE(v53) = 12;
  v16 = std::operator<<<wchar_t>((std::wostream *)data.gap10, v15);
  v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v16, " : ");
  std::wostream::operator<<(v17);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v53) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &result);
  LOBYTE(v53) = 13;
  v2->spiDofFactor->title->setText(v2->spiDofFactor->title, v18);
  LOBYTE(v53) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v53) = 14;
  std::wstringbuf::_Tidy((std::wstringbuf *)&data.gap10[8]);
  v19 = &text;
  if ( text._Myres >= 8 )
    v19 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&data.gap10[8], v19->_Bx._Buf, text._Mysize, *(int *)&data.gap10[68]);
  LOBYTE(v53) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"DOF focus", 9u);
  LOBYTE(v53) = 15;
  v20 = acTranslate(&result, &text);
  LOBYTE(v53) = 16;
  v21 = std::operator<<<wchar_t>((std::wostream *)data.gap10, v20);
  v22 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v21, " : ");
  std::wostream::operator<<(v22);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v53) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &result);
  LOBYTE(v53) = 17;
  v2->spiDofFocus->title->setText(v2->spiDofFocus->title, v23);
  LOBYTE(v53) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v53) = 18;
  std::wstringbuf::_Tidy((std::wstringbuf *)&data.gap10[8]);
  v24 = &text;
  if ( text._Myres >= 8 )
    v24 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&data.gap10[8], v24->_Bx._Buf, text._Mysize, *(int *)&data.gap10[68]);
  LOBYTE(v53) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"EXP. Mult", 9u);
  LOBYTE(v53) = 19;
  v25 = acTranslate(&result, &text);
  LOBYTE(v53) = 20;
  v26 = std::operator<<<wchar_t>((std::wostream *)data.gap10, v25);
  v27 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v26, " : ");
  std::wostream::operator<<(v27);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v53) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &result);
  LOBYTE(v53) = 21;
  v2->spiExpo->title->setText(v2->spiExpo->title, v28);
  LOBYTE(v53) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v53) = 22;
  std::wstringbuf::_Tidy((std::wstringbuf *)&data.gap10[8]);
  v29 = &text;
  if ( text._Myres >= 8 )
    v29 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&data.gap10[8], v29->_Bx._Buf, text._Mysize, *(int *)&data.gap10[68]);
  LOBYTE(v53) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"FOV", 3u);
  LOBYTE(v53) = 23;
  v30 = acTranslate(&result, &text);
  LOBYTE(v53) = 24;
  v31 = std::operator<<<wchar_t>((std::wostream *)data.gap10, v30);
  v32 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v31, " : ");
  std::wostream::operator<<(v32);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v53) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v33 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &result);
  LOBYTE(v53) = 25;
  v2->spiFov->title->setText(v2->spiFov->title, v33);
  LOBYTE(v53) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v53) = 26;
  std::wstringbuf::_Tidy((std::wstringbuf *)&data.gap10[8]);
  v34 = &text;
  if ( text._Myres >= 8 )
    v34 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&data.gap10[8], v34->_Bx._Buf, text._Mysize, *(int *)&data.gap10[68]);
  LOBYTE(v53) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Roll", 4u);
  LOBYTE(v53) = 27;
  v35 = acTranslate(&result, &text);
  LOBYTE(v53) = 28;
  std::operator<<<wchar_t>((std::wostream *)data.gap10, v35);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v53) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &result);
  LOBYTE(v53) = 29;
  v2->spiCameraRoll->title->setText(v2->spiCameraRoll->title, v36);
  LOBYTE(v53) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v53) = 30;
  std::wstringbuf::_Tidy((std::wstringbuf *)&data.gap10[8]);
  v37 = &text;
  if ( text._Myres >= 8 )
    v37 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&data.gap10[8], v37->_Bx._Buf, text._Mysize, *(int *)&data.gap10[68]);
  LOBYTE(v53) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Azimuth", 7u);
  LOBYTE(v53) = 31;
  v38 = acTranslate(&result, &text);
  LOBYTE(v53) = 32;
  std::operator<<<wchar_t>((std::wostream *)data.gap10, v38);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v53) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v39 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &result);
  LOBYTE(v53) = 33;
  v2->spiSunAzimuth->title->setText(v2->spiSunAzimuth->title, v39);
  LOBYTE(v53) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wstring::wstring(&text, word_17BE9D8);
  LOBYTE(v53) = 34;
  std::wstringbuf::_Tidy((std::wstringbuf *)&data.gap10[8]);
  v40 = &text;
  if ( text._Myres >= 8 )
    v40 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&data.gap10[8], v40->_Bx._Buf, text._Mysize, *(int *)&data.gap10[68]);
  LOBYTE(v53) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  std::wstring::wstring(&text, L"Zenith");
  LOBYTE(v53) = 35;
  v41 = acTranslate(&result, &text);
  LOBYTE(v53) = 36;
  std::operator<<<wchar_t>((std::wostream *)data.gap10, v41);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v53) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v42 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &text);
  LOBYTE(v53) = 37;
  v2->spiSunZenith->title->setText(v2->spiSunZenith->title, v42);
  LOBYTE(v53) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::render(v2, (int)operator delete, v14, dt, v44, v45);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&data);
}
