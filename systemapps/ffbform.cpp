#include "ffbform.h"
void __userpurge FFBForm::FFBForm(FFBForm *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *aCar)
{
  Sim *v4; // eax
  Texture *v5; // eax
  Texture *v6; // eax
  std::_Ref_count_base *v7; // eax
  Font *v8; // eax
  int v9; // eax
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  ksgui::CustomSpinner *v16; // eax
  const std::wstring *v17; // eax
  std::_Ptr_base<Material> *v18; // esi
  volatile signed __int32 *v19; // ecx
  volatile signed __int32 *v20; // esi
  ksgui::Control *v21; // ecx
  std::wstring *v22; // ecx
  ksgui::Control *v23; // ecx
  std::wstring *v24; // ecx
  std::_Ref_count_base *v25; // esi
  CarAudioFMOD *v26; // eax
  ksgui::Label *v27; // esi
  volatile signed __int32 *v28; // esi
  ksgui::Label *v29; // ecx
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  std::_Ref_count_base *v35; // esi
  CarAudioFMOD *v36; // eax
  CarAudioFMOD *v37; // esi
  unsigned int v38; // edx
  CarAudioFMOD *v39; // ecx
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  CarAvatar *v45; // eax
  std::wstring *v46; // eax
  void (__cdecl *v47)(void *); // esi
  CarAudioFMOD *v48; // ecx
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  ksgui::Control *v54; // eax
  ksgui::Control *v55; // eax
  ksgui::Control *v56; // ecx
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  ksgui::Control *v62; // eax
  ksgui::Control *v63; // eax
  ksgui::Control *v64; // ecx
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm2_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  ksgui::Form *v70; // eax
  ksgui::Form *v71; // eax
  float v72; // xmm0_4
  CarAvatar *v73; // ecx
  ICarControlsProvider *v74; // eax
  ksgui::Form *v75; // eax
  ksgui::Spinner *v76; // ecx
  float v77; // xmm0_4
  ksgui::Form *v78; // eax
  ksgui::Spinner *v79; // ecx
  float v80; // xmm0_4
  ksgui::Form *v81; // eax
  ksgui::Spinner *v82; // ecx
  float v83; // xmm0_4
  ksgui::Form *v84; // eax
  ksgui::Form *v85; // esi
  ksgui::Spinner *v86; // ecx
  FSWinCmdWheelConfig *v87; // ecx
  int v88; // ecx
  FFBForm::{ctor}::__l51::<lambda_0e8c66a4b0ccd493a3b9ef491b78a026> *v89; // eax
  int v90; // eax
  std::_Ref_count_base *v91; // esi
  int v92; // eax
  int v93; // esi
  std::wstring *v94; // eax
  FFBForm::{ctor}::__l55::<lambda_753bb7bea2d1fa579acc626be2eae045> *v95; // eax
  _BYTE v96[64]; // [esp+40h] [ebp-E8h] BYREF
  FFBForm *v97; // [esp+90h] [ebp-98h]
  std::shared_ptr<Font> v98; // [esp+94h] [ebp-94h] BYREF
  float y; // [esp+9Ch] [ebp-8Ch]
  std::_Ptr_base<Material> v100; // [esp+A0h] [ebp-88h] BYREF
  int v101; // [esp+A8h] [ebp-80h]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v102; // [esp+ACh] [ebp-7Ch] BYREF
  ksgui::Form *v103; // [esp+B0h] [ebp-78h] BYREF
  std::wstring v104; // [esp+B4h] [ebp-74h] BYREF
  Texture result; // [esp+CCh] [ebp-5Ch] BYREF
  std::wstring filename; // [esp+E8h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement iname; // [esp+100h] [ebp-28h] BYREF
  int v108; // [esp+124h] [ebp-4h]

  v103 = 0;
  v101 = 0;
  *(_DWORD *)&v96[28] = 1;
  v4 = aCar->sim;
  v97 = this;
  *(_DWORD *)&v96[24] = v4->game->gui;
  *(_DWORD *)&v96[20] = 7;
  *(_DWORD *)&v96[16] = 0;
  *(_WORD *)v96 = 0;
  std::wstring::assign((std::wstring *)v96, L"FFB_FORM", 8u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v96, *(ksgui::GUI **)&v96[24], v96[28]);
  v108 = 0;
  this->__vftable = (FFBForm_vtbl *)&FFBForm::`vftable';
  this->textLeft.kid = 0;
  this->textLeft.fileName._Myres = 7;
  this->textLeft.fileName._Mysize = 0;
  this->textLeft.fileName._Bx._Buf[0] = 0;
  this->textRight.kid = 0;
  this->textRight.fileName._Myres = 7;
  this->textRight.fileName._Mysize = 0;
  this->textRight.fileName._Bx._Buf[0] = 0;
  this->isAutoAdjustingFF = 0;
  this->ffAvg = 0.0;
  this->ffAvtPercentage = 0.0;
  this->suggestedFFMult = 1.0;
  this->isSaveNeeded = 0;
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  LOBYTE(v108) = 3;
  *(_DWORD *)&v96[28] = 42;
  this->devApp = 0;
  filename._Mysize = 0;
  *(_DWORD *)&v96[24] = L"content/gui/controls/spinner/leftMinus.png";
  this->car = aCar;
  filename._Myres = 7;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, *(const wchar_t **)&v96[24], *(unsigned int *)&v96[28]);
  LOBYTE(v108) = 4;
  v5 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &filename, 0);
  LOBYTE(v108) = 5;
  this->textLeft.kid = v5->kid;
  if ( &this->textLeft.fileName != &v5->fileName )
    std::wstring::assign(&this->textLeft.fileName, &v5->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v108) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v108) = 3;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/controls/spinner/rightPlus.png", 0x2Au);
  LOBYTE(v108) = 6;
  v6 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &filename, 0);
  LOBYTE(v108) = 7;
  this->textRight.kid = v6->kid;
  if ( &this->textRight.fileName != &v6->fileName )
    std::wstring::assign(&this->textRight.fileName, &v6->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v108) = 6;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v108) = 3;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"Force Feedback Controller", 0x19u);
  LOBYTE(v108) = 8;
  this->formTitle->setText(this->formTitle, &filename);
  LOBYTE(v108) = 3;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v7 = (std::_Ref_count_base *)operator new(0x18u);
  v100._Rep = v7;
  LOBYTE(v108) = 9;
  if ( v7 )
    Font::Font((Font *)v7, eFontMonospaced, 16.0, 0, 0);
  else
    v8 = 0;
  LOBYTE(v108) = 3;
  v98._Ptr = 0;
  v98._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&v98, v8);
  LOBYTE(v108) = 10;
  v102.__this = (CarAudioFMOD *)operator new(0x154u);
  LOBYTE(v108) = 11;
  if ( v102.__this )
  {
    *(_DWORD *)&v96[28] = 0;
    *(_DWORD *)&v96[24] = this->gui;
    *(_DWORD *)&v96[20] = 7;
    *(_DWORD *)&v96[16] = 0;
    *(_WORD *)v96 = 0;
    std::wstring::assign((std::wstring *)v96, L"FFB_SPINNER", 0xBu);
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v102.__this,
      *(std::wstring *)v96,
      *(ksgui::GUI **)&v96[24],
      *(CustomSpinnerMode *)&v96[28]);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  LOBYTE(v108) = 10;
  this->ffb = (ksgui::CustomSpinner *)v10;
  v11 = *(float *)(v10 + 264);
  v12 = *(float *)(v10 + 32) - *(float *)(v10 + 28);
  v13 = *(float *)(v10 + 40) - *(float *)(v10 + 36);
  *(_DWORD *)(v10 + 36) = 1117126656;
  *(_DWORD *)(v10 + 28) = 1103626240;
  v14 = v12 + 25.0;
  v15 = v13 + 75.0;
  *(float *)(v10 + 32) = v14;
  *(float *)(v10 + 40) = v15;
  if ( v11 == 0.0 && *(float *)(v10 + 272) == 0.0 )
  {
    *(_DWORD *)(v10 + 264) = 1103626240;
    *(_DWORD *)(v10 + 272) = 1117126656;
    *(float *)(v10 + 268) = v14;
    *(float *)(v10 + 276) = v15;
  }
  v16 = this->ffb;
  filename._Myres = 7;
  *(_DWORD *)&v96[28] = 3;
  *(_DWORD *)&v96[24] = L"FFB";
  v16->foreColor = 0i64;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, *(const wchar_t **)&v96[24], *(unsigned int *)&v96[28]);
  LOBYTE(v108) = 12;
  v17 = acTranslate(&v104, &filename);
  LOBYTE(v108) = 13;
  this->ffb->setText(this->ffb, v17);
  if ( v104._Myres >= 8 )
    operator delete(v104._Bx._Ptr);
  LOBYTE(v108) = 10;
  v104._Myres = 7;
  v104._Mysize = 0;
  v104._Bx._Buf[0] = 0;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  *(_DWORD *)&v96[28] = v98._Rep;
  v18 = (std::_Ptr_base<Material> *)this->ffb;
  v100 = 0i64;
  std::_Ptr_base<Font>::_Reset(&v100, (Material *)v98._Ptr, v98._Rep);
  v19 = (volatile signed __int32 *)v18[16]._Rep;
  v18[16] = v100;
  v20 = v19;
  v102.__this = (CarAudioFMOD *)v19;
  if ( v19 )
  {
    if ( !_InterlockedExchangeAdd(v19 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v19)(v19);
      if ( !_InterlockedExchangeAdd(v20 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v20 + 4))(v20);
    }
  }
  ((void (*)(ksgui::CustomSpinner *, int, int))this->ffb->setSize)(this->ffb, 1133903872, 1101529088);
  v21 = this->ffb->leftButton;
  v21->backTexture.kid = this->textLeft.kid;
  v22 = &v21->backTexture.fileName;
  if ( v22 != &this->textLeft.fileName )
    std::wstring::assign(v22, &this->textLeft.fileName, 0, 0xFFFFFFFF);
  v23 = this->ffb->rightButton;
  v23->backTexture.kid = this->textRight.kid;
  v24 = &v23->backTexture.fileName;
  if ( v24 != &this->textRight.fileName )
    std::wstring::assign(v24, &this->textRight.fileName, 0, 0xFFFFFFFF);
  *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_d2df1809daeed8a92c8365fcf118b116_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v96[8] = this;
  *(_DWORD *)&v96[20] = &v96[4];
  LOBYTE(v108) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->ffb->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v96[4],
    this);
  *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_d91802a48d0e7f53b67b620818c2ad43_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v96[8] = this;
  *(_DWORD *)&v96[20] = &v96[4];
  LOBYTE(v108) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->ffb->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v96[4],
    this);
  v102.__this = (CarAudioFMOD *)this->ffb;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v102);
  *(_DWORD *)&v96[28] = 284;
  v102.__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v25 = (std::_Ref_count_base *)operator new(*(unsigned int *)&v96[28]);
  v100._Rep = v25;
  LOBYTE(v108) = 16;
  if ( v25 )
  {
    *(_DWORD *)&v96[28] = this->gui;
    *(_DWORD *)&v96[24] = 7;
    *(_DWORD *)&v96[20] = 0;
    *(_WORD *)&v96[4] = 0;
    std::wstring::assign((std::wstring *)&v96[4], L"FFB_VALUE", 9u);
    ksgui::Label::Label((ksgui::Label *)v25, *(std::wstring *)&v96[4], *(ksgui::GUI **)&v96[28]);
    v27 = (ksgui::Label *)v26;
    v102.__this = v26;
  }
  else
  {
    v27 = 0;
    v102.__this = 0;
  }
  LOBYTE(v108) = 10;
  *(_DWORD *)&v96[28] = v98._Rep;
  this->ffbValue = v27;
  v100 = 0i64;
  std::_Ptr_base<Font>::_Reset(&v100, (Material *)v98._Ptr, *(std::_Ref_count_base **)&v96[28]);
  v28 = (volatile signed __int32 *)v27->font._Rep;
  *(std::_Ptr_base<Material> *)&v102.__this->dirtEvent.path._Bx._Alias[12] = v100;
  if ( v28 )
  {
    if ( !_InterlockedExchangeAdd(v28 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v28)(v28);
      if ( !_InterlockedExchangeAdd(v28 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v28 + 4))(v28);
    }
  }
  this->ffbValue->setText(this->ffbValue, &this->car->guiShortName);
  ((void (*)(ksgui::Label *, int, int))this->ffbValue->setSize)(this->ffbValue, 1133903872, 1101529088);
  v29 = this->ffbValue;
  v30 = v29->rectBase.left;
  v31 = v29->rect.right - v29->rect.left;
  v32 = v29->rect.bottom - v29->rect.top;
  v29->rect.top = 40.0;
  v29->rect.left = 250.0;
  v33 = v31 + 250.0;
  v34 = v32 + 40.0;
  v29->rect.right = v33;
  v29->rect.bottom = v34;
  if ( v30 == 0.0 && v29->rectBase.top == 0.0 )
  {
    v29->rectBase.left = 250.0;
    v29->rectBase.top = 40.0;
    v29->rectBase.right = v33;
    v29->rectBase.bottom = v34;
  }
  v102.__this = (CarAudioFMOD *)this->ffbValue;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v102);
  *(_DWORD *)&v96[28] = 284;
  v102.__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v35 = (std::_Ref_count_base *)operator new(*(unsigned int *)&v96[28]);
  v100._Rep = v35;
  LOBYTE(v108) = 17;
  if ( v35 )
  {
    *(_DWORD *)&v96[28] = this->gui;
    *(_DWORD *)&v96[24] = 7;
    *(_DWORD *)&v96[20] = 0;
    *(_WORD *)&v96[4] = 0;
    std::wstring::assign((std::wstring *)&v96[4], L"NAME", 4u);
    ksgui::Label::Label((ksgui::Label *)v35, *(std::wstring *)&v96[4], *(ksgui::GUI **)&v96[28]);
    v37 = v36;
  }
  else
  {
    v37 = 0;
  }
  LOBYTE(v108) = 10;
  v100._Ptr = 0;
  v100._Rep = 0;
  std::_Ptr_base<Font>::_Reset(&v100, (Material *)v98._Ptr, v98._Rep);
  v38 = v37->dirtEvent.path._Mysize;
  v37->dirtEvent.path._Mysize = (unsigned int)v100._Rep;
  v102.__this = (CarAudioFMOD *)v38;
  *(_DWORD *)&v37->dirtEvent.path._Bx._Alias[12] = v100._Ptr;
  if ( v38 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v38 + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(unsigned int))v38)(v38);
      v39 = v102.__this;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v102.__this->name, 0xFFFFFFFF) )
        ((void (*)(CarAudioFMOD *))v39->update)(v39);
    }
  }
  ((void (*)(CarAudioFMOD *, std::wstring *))v37->__vftable[2].shutdown)(v37, &this->car->guiShortName);
  ((void (*)(CarAudioFMOD *, int, int))v37->__vftable[1].update)(v37, 1133903872, 1101529088);
  v40 = *(float *)&v37->engineIntEvent.instance;
  v41 = *(float *)&v37->isActive - *(float *)&v37->name._Myres;
  v42 = *(float *)&v37->gameObjects._Myfirst - *(float *)&v37->parent;
  v37->parent = (GameObject *)1109393408;
  v37->name._Myres = 1103626240;
  v43 = v41 + 25.0;
  v44 = v42 + 40.0;
  *(float *)&v37->isActive = v43;
  *(float *)&v37->gameObjects._Myfirst = v44;
  if ( v40 == 0.0 && v37->engineIntEvent.basePitch == 0.0 )
  {
    v37->engineIntEvent.instance = (FMOD::Studio::EventInstance *)1103626240;
    v37->engineIntEvent.basePitch = 40.0;
    v37->engineIntEvent.baseVolume = v43;
    *(float *)&v37->engineIntEvent.path._Bx._Ptr = v44;
  }
  v102.__this = v37;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v102);
  v102.__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v45 = this->car;
  if ( v45->configName._Mysize )
  {
    v50 = std::operator+<wchar_t>(&result.fileName, L"content/cars/", &v45->unixName);
    LOBYTE(v108) = 19;
    v51 = std::operator+<wchar_t>(&iname.name, v50, L"/data_");
    LOBYTE(v108) = 20;
    v52 = std::operator+<wchar_t>(&filename, v51, &this->car->configName);
    LOBYTE(v108) = 21;
    v53 = std::operator+<wchar_t>(&v104, v52, L"/car.ini");
    std::wstring::operator=(&this->filename, v53);
    v47 = operator delete;
    if ( v104._Myres >= 8 )
      operator delete(v104._Bx._Ptr);
    v104._Myres = 7;
    v104._Mysize = 0;
    v104._Bx._Buf[0] = 0;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    if ( iname.name._Myres >= 8 )
      operator delete(iname.name._Bx._Ptr);
    LOBYTE(v108) = 10;
    iname.name._Myres = 7;
    iname.name._Mysize = 0;
    iname.name._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
    {
      *(_DWORD *)&v96[28] = result.fileName._Bx._Ptr;
      goto LABEL_69;
    }
  }
  else
  {
    v46 = std::operator+<wchar_t>(&iname.name, L"content/cars/", &v45->unixName);
    LOBYTE(v108) = 18;
    v47 = operator delete;
    v48 = (CarAudioFMOD *)std::operator+<wchar_t>(&v104, v46, L"/data/car.ini");
    v49 = &this->filename;
    v102.__this = v48;
    if ( &this->filename != (std::wstring *)v48 )
    {
      if ( this->filename._Myres >= 8 )
      {
        operator delete(v49->_Bx._Ptr);
        v48 = v102.__this;
        v49 = &this->filename;
      }
      v49->_Myres = 7;
      *(_DWORD *)&v96[28] = v48;
      v49->_Mysize = 0;
      v49->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(v49, *(std::wstring **)&v96[28]);
    }
    if ( v104._Myres >= 8 )
      operator delete(v104._Bx._Ptr);
    LOBYTE(v108) = 10;
    v104._Myres = 7;
    v104._Mysize = 0;
    v104._Bx._Buf[0] = 0;
    if ( iname.name._Myres >= 8 )
    {
      *(_DWORD *)&v96[28] = iname.name._Bx._Ptr;
LABEL_69:
      v47(*(void **)&v96[28]);
      goto LABEL_70;
    }
  }
LABEL_70:
  if ( Path::fileExists(a2, &this->filename, 1) )
  {
    v102.__this = (CarAudioFMOD *)operator new(0x118u);
    LOBYTE(v108) = 22;
    if ( v102.__this )
    {
      std::wstring::wstring(&iname.name, L"FFB_RESET");
      LOBYTE(v108) = 23;
      *(_DWORD *)&v96[28] = this->gui;
      v101 = 1;
      v103 = (ksgui::Form *)1;
      ksgui::Control::Control((ksgui::Control *)v102.__this, &iname.name, *(ksgui::GUI **)&v96[28]);
    }
    else
    {
      v54 = 0;
    }
    this->ffbAutoAdjust = v54;
    v108 = 10;
    if ( (v101 & 1) != 0 )
    {
      v101 &= 0xFFFFFFFE;
      if ( iname.name._Myres >= 8 )
        v47(iname.name._Bx._Ptr);
    }
    v55 = this->ffbAutoAdjust;
    *(_DWORD *)&v96[28] = L"Auto FFB OFF";
    v55->fontScale = 0.69999999;
    std::wstring::wstring(&iname.name, *(const wchar_t **)&v96[28]);
    LOBYTE(v108) = 25;
    this->ffbAutoAdjust->setText(this->ffbAutoAdjust, (const std::wstring *)&iname);
    LOBYTE(v108) = 10;
    if ( iname.name._Myres >= 8 )
      v47(iname.name._Bx._Ptr);
    ((void (*)(ksgui::Control *, int, int))this->ffbAutoAdjust->setSize)(
      this->ffbAutoAdjust,
      1126825984,
      1101529088);
    ((void (*)(ksgui::Control *, _DWORD))this->ffbAutoAdjust->setRepeatInterval)(this->ffbAutoAdjust, 0);
    v56 = this->ffbAutoAdjust;
    v57 = v56->rectBase.left;
    v58 = v56->rect.right - v56->rect.left;
    v59 = v56->rect.bottom - v56->rect.top;
    v56->rect.top = 115.0;
    v56->rect.left = 155.0;
    v60 = v58 + 155.0;
    v61 = v59 + 115.0;
    v56->rect.right = v60;
    v56->rect.bottom = v61;
    if ( v57 == 0.0 && v56->rectBase.top == 0.0 )
    {
      v56->rectBase.left = 155.0;
      v56->rectBase.top = 115.0;
      v56->rectBase.right = v60;
      v56->rectBase.bottom = v61;
    }
    *(_DWORD *)&v96[28] = this->ffbAutoAdjust;
    *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_7fdde5224257478b9f42537cd9101c59_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
    *(_DWORD *)&v96[8] = this;
    *(_DWORD *)&v96[20] = &v96[4];
    LOBYTE(v108) = 10;
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)&this->ffbAutoAdjust->evClicked,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v96[4],
      *(void **)&v96[28]);
    v102.__this = (CarAudioFMOD *)this->ffbAutoAdjust;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v102);
    *(_DWORD *)&v96[28] = 280;
    v102.__this->bank.path._Bx._Ptr = (wchar_t *)this;
    v102.__this = (CarAudioFMOD *)operator new(*(unsigned int *)&v96[28]);
    LOBYTE(v108) = 27;
    if ( v102.__this )
    {
      std::wstring::wstring(&iname.name, L"FFB_QUICK");
      LOBYTE(v108) = 28;
      *(_DWORD *)&v96[28] = this->gui;
      v101 |= 2u;
      v103 = (ksgui::Form *)v101;
      ksgui::Control::Control((ksgui::Control *)v102.__this, &iname.name, *(ksgui::GUI **)&v96[28]);
    }
    else
    {
      v62 = 0;
    }
    this->quickAdjust = v62;
    v108 = 10;
    if ( (v101 & 2) != 0 )
    {
      v101 &= 0xFFFFFFFD;
      if ( iname.name._Myres >= 8 )
        v47(iname.name._Bx._Ptr);
    }
    v63 = this->quickAdjust;
    *(_DWORD *)&v96[28] = L"Quick Adjust";
    v63->fontScale = 0.69999999;
    std::wstring::wstring(&iname.name, *(const wchar_t **)&v96[28]);
    LOBYTE(v108) = 30;
    this->quickAdjust->setText(this->quickAdjust, (const std::wstring *)&iname);
    LOBYTE(v108) = 10;
    if ( iname.name._Myres >= 8 )
      v47(iname.name._Bx._Ptr);
    ((void (*)(ksgui::Control *, int, int))this->quickAdjust->setSize)(
      this->quickAdjust,
      1126825984,
      1101529088);
    ((void (*)(ksgui::Control *, _DWORD))this->quickAdjust->setRepeatInterval)(this->quickAdjust, 0);
    v64 = this->quickAdjust;
    v65 = v64->rectBase.left;
    v66 = v64->rect.right - v64->rect.left;
    v67 = v64->rect.bottom - v64->rect.top;
    v64->rect.top = 145.0;
    v64->rect.left = 155.0;
    v68 = v66 + 155.0;
    v69 = v67 + 145.0;
    v64->rect.right = v68;
    v64->rect.bottom = v69;
    if ( v65 == 0.0 && v64->rectBase.top == 0.0 )
    {
      v64->rectBase.left = 155.0;
      v64->rectBase.top = 145.0;
      v64->rectBase.right = v68;
      v64->rectBase.bottom = v69;
    }
    *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_5cdc6dbe0ccd312e9dfa5d835cf47ed3_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
    *(_DWORD *)&v96[8] = this;
    *(_DWORD *)&v96[20] = &v96[4];
    LOBYTE(v108) = 10;
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)&this->quickAdjust->evClicked,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v96[4],
      this);
    v102.__this = (CarAudioFMOD *)this->quickAdjust;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v102);
    *(_DWORD *)&v96[28] = this;
    v102.__this->bank.path._Bx._Ptr = (wchar_t *)this;
    *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_5ce3c9a008ef626a8ac295554bddaa75_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
    *(_DWORD *)&v96[8] = this;
    *(_DWORD *)&v96[20] = &v96[4];
    LOBYTE(v108) = 10;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->car->sim->raceManager->evOnLapCompleted,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v96[4],
      *(void **)&v96[28]);
    v102.__this = (CarAudioFMOD *)operator new(0x158u);
    LOBYTE(v108) = 33;
    if ( v102.__this )
    {
      std::wstring::wstring(&result.fileName, L"FFAVG");
      LOBYTE(v108) = 34;
      v101 |= 4u;
      v103 = (ksgui::Form *)v101;
      ksgui::ConnectedLabel::ConnectedLabel(
        (ksgui::ConnectedLabel *)v102.__this,
        &result.fileName,
        this->gui,
        &this->ffAvtPercentage);
      v103 = v70;
    }
    else
    {
      v103 = 0;
    }
    v108 = 10;
    if ( (v101 & 4) != 0 )
    {
      v101 &= 0xFFFFFFFB;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result.fileName);
    }
    ksgui::Form::setPosition(v103, 25.0, 115.0);
    ((void (*)(ksgui::Form *, int, int))v103->setSize)(v103, 1112014848, 1103626240);
    v102.__this = (CarAudioFMOD *)v103;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v102);
    *(_DWORD *)&v96[28] = 344;
    v102.__this->bank.path._Bx._Ptr = (wchar_t *)this;
    v102.__this = (CarAudioFMOD *)operator new(*(unsigned int *)&v96[28]);
    LOBYTE(v108) = 36;
    if ( v102.__this )
    {
      std::wstring::wstring(&result.fileName, L"OPT_FF");
      LOBYTE(v108) = 37;
      v101 |= 8u;
      v103 = (ksgui::Form *)v101;
      ksgui::ConnectedLabel::ConnectedLabel(
        (ksgui::ConnectedLabel *)v102.__this,
        &result.fileName,
        this->gui,
        &this->suggestedFFMult);
      v103 = v71;
    }
    else
    {
      v103 = 0;
    }
    v108 = 10;
    if ( (v101 & 8) != 0 )
    {
      v101 &= 0xFFFFFFF7;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result.fileName);
    }
    ksgui::Form::setPosition(v103, 25.0, 145.0);
    ((void (*)(ksgui::Form *, int, int))v103->setSize)(v103, 1112014848, 1103626240);
    v102.__this = (CarAudioFMOD *)v103;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v102);
    *(_DWORD *)&v96[28] = 1138163712;
    v102.__this->bank.path._Bx._Ptr = (wchar_t *)this;
    ksgui::Form::setSize(this, 350.0, *(float *)&v96[28]);
    v72 = FLOAT_200_0;
  }
  else
  {
    ksgui::Form::setSize(this, 350.0, 350.0);
    v72 = FLOAT_120_0;
  }
  v73 = this->car;
  *(_DWORD *)&v96[28] = 0;
  *(_DWORD *)&v96[24] = &DICarControl `RTTI Type Descriptor';
  *(_DWORD *)&v96[20] = &ICarControlsProvider `RTTI Type Descriptor';
  *(_DWORD *)&v96[16] = 0;
  y = v72;
  v74 = CarAvatar::getControlsProvider(v73);
  v102.__this = (CarAudioFMOD *)__RTDynamicCast(
                                  v74,
                                  *(_DWORD *)&v96[16],
                                  *(_DWORD *)&v96[20],
                                  *(_DWORD *)&v96[24],
                                  *(_DWORD *)&v96[28]);
  if ( v102.__this )
  {
    v100._Rep = (std::_Ref_count_base *)operator new(0x1BCu);
    LOBYTE(v108) = 39;
    if ( v100._Rep )
    {
      std::wstring::wstring(&result.fileName, L"SP_SLIPS");
      LOBYTE(v108) = 40;
      *(_DWORD *)&v96[28] = 0;
      *(_DWORD *)&v96[24] = 1;
      *(_DWORD *)&v96[20] = this->gui;
      v101 |= 0x10u;
      v103 = (ksgui::Form *)v101;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v100._Rep, &result.fileName, *(ksgui::GUI **)&v96[20], 1, 0);
      v103 = v75;
    }
    else
    {
      v103 = 0;
    }
    v108 = 10;
    if ( (v101 & 0x10) != 0 )
    {
      v101 &= 0xFFFFFFEF;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result.fileName);
    }
    std::wstring::wstring(&iname.name, L"Slips");
    LOBYTE(v108) = 42;
    acTranslate((std::wstring *)&v96[8], &iname.name);
    ksgui::Spinner::setLabelText((ksgui::Spinner *)v103, *(std::wstring *)&v96[8]);
    LOBYTE(v108) = 10;
    if ( iname.name._Myres >= 8 )
      v47(iname.name._Bx._Ptr);
    v76 = (ksgui::Spinner *)v103;
    *(float *)&v96[28] = y;
    v103->scaleToBeSaved = 0.0;
    v76->maxValue = 100;
    v76->step = 1;
    ksgui::Spinner::setPosition(v76, 25.0, *(float *)&v96[28]);
    ((void (*)(ksgui::Form *, int, int))v103->setSize)(v103, 1133903872, 1101004800);
    ksgui::Spinner::setValue(
      (ksgui::Spinner *)v103,
      (int)(float)(*(float *)&v102.__this[2].gearIntEvent.engine * 100.0));
    LOBYTE(v108) = 10;
    *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_308aaf104fba68aa0bf5f8b69dfaf8be_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v96[8] = this;
    *(_DWORD *)&v96[20] = &v96[4];
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v103->pinIcon,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v96[4],
      this);
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v103);
    v77 = y;
    *(_DWORD *)&v96[28] = 444;
    v103->parent = this;
    y = v77 + 60.0;
    v100._Rep = (std::_Ref_count_base *)operator new(*(unsigned int *)&v96[28]);
    LOBYTE(v108) = 44;
    if ( v100._Rep )
    {
      std::wstring::wstring(&result.fileName, L"SP_ROAD");
      LOBYTE(v108) = 45;
      *(_DWORD *)&v96[28] = 0;
      *(_DWORD *)&v96[24] = 1;
      *(_DWORD *)&v96[20] = this->gui;
      v101 |= 0x20u;
      v103 = (ksgui::Form *)v101;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v100._Rep, &result.fileName, *(ksgui::GUI **)&v96[20], 1, 0);
      v103 = v78;
    }
    else
    {
      v103 = 0;
    }
    v108 = 10;
    if ( (v101 & 0x20) != 0 )
    {
      v101 &= 0xFFFFFFDF;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result.fileName);
    }
    std::wstring::wstring(&iname.name, L"Road");
    LOBYTE(v108) = 47;
    acTranslate((std::wstring *)&v96[8], &iname.name);
    ksgui::Spinner::setLabelText((ksgui::Spinner *)v103, *(std::wstring *)&v96[8]);
    LOBYTE(v108) = 10;
    if ( iname.name._Myres >= 8 )
      v47(iname.name._Bx._Ptr);
    v79 = (ksgui::Spinner *)v103;
    *(float *)&v96[28] = y;
    v103->scaleToBeSaved = 0.0;
    v79->maxValue = 100;
    v79->step = 1;
    ksgui::Spinner::setPosition(v79, 20.0, *(float *)&v96[28]);
    ((void (*)(ksgui::Form *, int, int))v103->setSize)(v103, 1133903872, 1103626240);
    ksgui::Spinner::setValue(
      (ksgui::Spinner *)v103,
      (int)(float)(*(float *)&v102.__this[2].gearExtEvent.reverbResponse * 100.0));
    LOBYTE(v108) = 10;
    *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_185e42ccf2dd3b0a13185cb8ee5ec2b7_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v96[8] = this;
    *(_DWORD *)&v96[20] = &v96[4];
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v103->pinIcon,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v96[4],
      this);
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v103);
    v80 = y;
    *(_DWORD *)&v96[28] = 444;
    v103->parent = this;
    y = v80 + 60.0;
    v100._Rep = (std::_Ref_count_base *)operator new(*(unsigned int *)&v96[28]);
    LOBYTE(v108) = 49;
    if ( v100._Rep )
    {
      std::wstring::wstring(&result.fileName, L"SP_CURB");
      LOBYTE(v108) = 50;
      *(_DWORD *)&v96[28] = 0;
      *(_DWORD *)&v96[24] = 1;
      *(_DWORD *)&v96[20] = this->gui;
      v101 |= 0x40u;
      v103 = (ksgui::Form *)v101;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v100._Rep, &result.fileName, *(ksgui::GUI **)&v96[20], 1, 0);
      v103 = v81;
    }
    else
    {
      v103 = 0;
    }
    v108 = 10;
    if ( (v101 & 0x40) != 0 )
    {
      v101 &= 0xFFFFFFBF;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result.fileName);
    }
    std::wstring::wstring(&iname.name, L"Curbs");
    LOBYTE(v108) = 52;
    acTranslate((std::wstring *)&v96[8], &iname.name);
    ksgui::Spinner::setLabelText((ksgui::Spinner *)v103, *(std::wstring *)&v96[8]);
    LOBYTE(v108) = 10;
    if ( iname.name._Myres >= 8 )
      v47(iname.name._Bx._Ptr);
    v82 = (ksgui::Spinner *)v103;
    *(float *)&v96[28] = y;
    v103->scaleToBeSaved = 0.0;
    v82->maxValue = 100;
    v82->step = 1;
    ksgui::Spinner::setPosition(v82, 20.0, *(float *)&v96[28]);
    ((void (*)(ksgui::Form *, int, int))v103->setSize)(v103, 1133903872, 1103626240);
    ksgui::Spinner::setValue(
      (ksgui::Spinner *)v103,
      (int)(float)(*(float *)&v102.__this[2].gearExtEvent.path._Myres * 100.0));
    LOBYTE(v108) = 10;
    *(_DWORD *)&v96[4] = &std::_Func_impl<std::_Callable_obj<_lambda_1595c1b2612b51953ab806a0bf2fcfef_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v96[8] = this;
    *(_DWORD *)&v96[20] = &v96[4];
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v103->pinIcon,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v96[4],
      this);
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v103);
    v83 = y;
    *(_DWORD *)&v96[28] = 444;
    v103->parent = this;
    y = v83 + 60.0;
    v100._Rep = (std::_Ref_count_base *)operator new(*(unsigned int *)&v96[28]);
    LOBYTE(v108) = 54;
    if ( v100._Rep )
    {
      std::wstring::wstring(&result.fileName, L"SP_ABS");
      LOBYTE(v108) = 55;
      *(_DWORD *)&v96[28] = 0;
      *(_DWORD *)&v96[24] = 1;
      *(_DWORD *)&v96[20] = this->gui;
      v101 |= 0x80u;
      v103 = (ksgui::Form *)v101;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v100._Rep, &result.fileName, *(ksgui::GUI **)&v96[20], 1, 0);
      v103 = v84;
    }
    else
    {
      v103 = 0;
    }
    v108 = 10;
    if ( (v101 & 0x80u) != 0 )
    {
      v101 &= 0xFFFFFF7F;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result.fileName);
    }
    std::wstring::wstring(&iname.name, L"ABS");
    LOBYTE(v108) = 57;
    acTranslate((std::wstring *)&v96[8], &iname.name);
    ksgui::Spinner::setLabelText((ksgui::Spinner *)v103, *(std::wstring *)&v96[8]);
    LOBYTE(v108) = 10;
    if ( iname.name._Myres >= 8 )
      v47(iname.name._Bx._Ptr);
    v85 = v103;
    v86 = (ksgui::Spinner *)v103;
    *(float *)&v96[28] = y;
    v103->scaleToBeSaved = 0.0;
    v86->maxValue = 100;
    v86->step = 1;
    ksgui::Spinner::setPosition(v86, 20.0, *(float *)&v96[28]);
    ((void (*)(ksgui::Form *, int, int))v85->setSize)(v85, 1133903872, 1103626240);
    ksgui::Spinner::setValue(
      (ksgui::Spinner *)v85,
      (int)(float)(*(float *)&v102.__this[2].gearIntEvent.description * 100.0));
    *(_DWORD *)&v96[28] = this;
    v100._Rep = (std::_Ref_count_base *)this;
    v102.__this = (CarAudioFMOD *)&v96[4];
    *(_DWORD *)&v96[20] = 0;
    if ( std::_Test_callable<_lambda_0e8c66a4b0ccd493a3b9ef491b78a026_>(v87) )
    {
      v103 = (ksgui::Form *)operator new(0xCu, v102.__this);
      if ( v103 )
      {
        *(_DWORD *)v96 = v88;
        FolderEncrypter::FolderEncrypter((std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *)&v100._Rep);
        std::_Func_impl<std::_Callable_obj<_lambda_0e8c66a4b0ccd493a3b9ef491b78a026_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::_Func_impl<std::_Callable_obj<_lambda_0e8c66a4b0ccd493a3b9ef491b78a026_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>(
          (std::_Func_impl<std::_Callable_obj<<lambda_0e8c66a4b0ccd493a3b9ef491b78a026>,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &> >,void,ksgui::OnSpinnerValueChanged const &> *)v103,
          v89,
          *(const std::allocator<std::_Func_impl<std::_Callable_obj<<lambda_0e8c66a4b0ccd493a3b9ef491b78a026>,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &> >,void,ksgui::OnSpinnerValueChanged const &> > **)v96);
      }
      else
      {
        v90 = 0;
      }
      *(_DWORD *)v96 = v90;
    }
    else
    {
      *(_DWORD *)v96 = 0;
    }
    std::_Func_class<void,OnPhysicsStepCompleted const &>::_Set(
      (std::_Func_class<void,OnPhysicsStepCompleted const &> *)v102.__this,
      *(std::_Func_base<void,OnPhysicsStepCompleted const &> **)v96);
    LOBYTE(v108) = 10;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v85->pinIcon,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v96[4],
      *(void **)&v96[28]);
    ksgui::Control::addControl(this, v85);
    y = y + 60.0;
    v91 = (std::_Ref_count_base *)operator new(0x118u);
    v100._Rep = v91;
    LOBYTE(v108) = 59;
    if ( v91 )
    {
      std::wstring::wstring(&result.fileName, L"SAVE_FF");
      LOBYTE(v108) = 60;
      *(_DWORD *)&v96[28] = this->gui;
      v101 |= 0x100u;
      v103 = (ksgui::Form *)v101;
      ksgui::Control::Control((ksgui::Control *)v91, &result.fileName, *(ksgui::GUI **)&v96[28]);
      v93 = v92;
    }
    else
    {
      v93 = 0;
    }
    v108 = 10;
    if ( (v101 & 0x100) != 0 )
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result.fileName);
    ksgui::Form::setPosition((ksgui::Form *)v93, 20.0, y);
    (*(void (**)(int, int, int))(*(_DWORD *)v93 + 28))(v93, 1133903872, 1103626240);
    std::wstring::wstring(&iname.name, L"Save");
    LOBYTE(v108) = 62;
    v94 = acTranslate(&v104, &iname.name);
    LOBYTE(v108) = 63;
    (*(void (**)(int, std::wstring *))(*(_DWORD *)v93 + 68))(v93, v94);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v104);
    LOBYTE(v108) = 10;
    std::wstring::~wstring(&iname);
    *(_DWORD *)&v96[28] = this;
    CommandItem::CommandItem(&v102, (CarAudioFMOD *)this);
    std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
      (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v96[4],
      v95);
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)(v93 + 156),
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v96[4],
      *(void **)&v96[28]);
    ksgui::Control::addControl(this, (ksgui::Control *)v93);
  }
  ksgui::Control::scaleByMult(this);
  std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&v98);
}
FFBForm *FFBForm::`vector deleting destructor'(FFBForm *this, unsigned int a2)
{
  FFBForm::~FFBForm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FFBForm::saveFFB(FFBForm *this)
{
  int v2; // edi
  int v3; // esi
  int v4; // ecx
  std::wstring *v5; // eax
  std::wstring *v6; // esi
  std::wstring *v7; // ecx
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  float v10; // [esp+2Ch] [ebp-E4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v11; // [esp+30h] [ebp-E0h] BYREF
  std::wstring result; // [esp+E0h] [ebp-30h] BYREF
  int v13; // [esp+10Ch] [ebp-4h]

  v10 = 0.0;
  v10 = CarAvatar::getUserFFGain(this->car);
  if ( v10 != 1.0 )
    CarAvatar::setUserFFGain(this->car, 1.0);
  *(_DWORD *)v11.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v11.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v11.gap68);
  v13 = 0;
  LODWORD(v10) = 1;
  std::wiostream::basic_iostream<wchar_t>(&v11, &v11.gap10[8], 0);
  v13 = 1;
  *(_DWORD *)&v11.gap0[*(_DWORD *)(*(_DWORD *)v11.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v10 + *(_DWORD *)(*(_DWORD *)v11.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v11.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v11.gap10[8]);
  *(_DWORD *)&v11.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v11.gap10[64] = 0;
  *(_DWORD *)&v11.gap10[68] = 0;
  v13 = 3;
  v2 = std::setprecision(&result, 3, 0);
  v3 = std::wostream::operator<<(v11.gap10, std::fixed);
  if ( v3 )
    v4 = v3 + *(_DWORD *)(*(_DWORD *)v3 + 4);
  else
    v4 = 0;
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v2)(v4, *(_DWORD *)(v2 + 8), *(_DWORD *)(v2 + 12));
  CarAvatar::getFFMult(this->car);
  std::wostream::operator<<(v3);
  v5 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v11, &result);
  v6 = &this->filename;
  if ( this->filename._Myres < 8 )
    v7 = &this->filename;
  else
    v7 = (std::wstring *)v6->_Bx._Ptr;
  if ( v5->_Myres >= 8 )
    v5 = (std::wstring *)v5->_Bx._Ptr;
  WritePrivateProfileStringW(L"CONTROLS", L"FFMULT", v5->_Bx._Buf, v7->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, word_17BE9D8, 0);
  LOBYTE(v13) = 4;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v11.gap10[8]);
  v8 = &result;
  if ( result._Myres >= 8 )
    v8 = (std::wstring *)result._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v11.gap10[8], v8->_Bx._Buf, result._Mysize, *(int *)&v11.gap10[68]);
  LOBYTE(v13) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wostream::operator<<(v11.gap10);
  v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v11, &result);
  if ( this->filename._Myres >= 8 )
    v6 = (std::wstring *)v6->_Bx._Ptr;
  if ( v9->_Myres >= 8 )
    v9 = (std::wstring *)v9->_Bx._Ptr;
  WritePrivateProfileStringW(L"CONTROLS", L"STEER_ASSIST", v9->_Bx._Buf, v6->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  *(_DWORD *)&v11.gap0[*(_DWORD *)(*(_DWORD *)v11.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v10 + *(_DWORD *)(*(_DWORD *)v11.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v11.gap0 + 4) - 104;
  *(_DWORD *)&v11.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v11.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v11.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v11.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v11.gap68);
}
void FFBForm::render(FFBForm *this, float dt)
{
  std::wstring *v3; // esi
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  GLRenderer *v8; // esi
  ksgui::CustomSpinner *v9; // ecx
  float v10; // xmm0_4
  CarAvatar *v11; // ecx
  float v12; // xmm1_4
  __int64 v13; // [esp+2Ch] [ebp-184h]
  float v14; // [esp+34h] [ebp-17Ch]
  float v15; // [esp+3Ch] [ebp-174h]
  float v16; // [esp+3Ch] [ebp-174h]
  __m128i y; // [esp+40h] [ebp-170h] BYREF
  int v18; // [esp+54h] [ebp-15Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v19; // [esp+58h] [ebp-158h] BYREF
  std::wstring text; // [esp+10Ch] [ebp-A4h] BYREF
  std::wstring v21; // [esp+124h] [ebp-8Ch] BYREF
  std::wstring v22; // [esp+13Ch] [ebp-74h] BYREF
  std::wstring result; // [esp+154h] [ebp-5Ch] BYREF
  std::wstring v24; // [esp+16Ch] [ebp-44h] BYREF
  std::wstring v25; // [esp+184h] [ebp-2Ch] BYREF
  int v26; // [esp+1ACh] [ebp-4h]

  *(_DWORD *)v19.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v19.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v19.gap68);
  v26 = 0;
  std::wiostream::basic_iostream<wchar_t>(&v19, &v19.gap10[8], 0);
  v26 = 1;
  *(_DWORD *)&v19.gap0[*(_DWORD *)(*(_DWORD *)v19.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v18 + *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v19.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v19.gap10[8]);
  *(_DWORD *)&v19.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v19.gap10[64] = 0;
  *(_DWORD *)&v19.gap10[68] = 0;
  v26 = 3;
  v15 = CarAvatar::getUserFFGain(this->car) * 100.0;
  std::wostream::operator<<(v19.gap10, (int)v15);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"FFB ", 4u);
  LOBYTE(v26) = 4;
  v3 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v19, &result);
  LOBYTE(v26) = 5;
  v4 = acTranslate(&v22, &text);
  LOBYTE(v26) = 6;
  v5 = std::operator+<wchar_t>(&v24, v4, L" (");
  LOBYTE(v26) = 7;
  v6 = std::operator+<wchar_t>(&v21, v5, v3);
  LOBYTE(v26) = 8;
  v7 = std::operator+<wchar_t>(&v25, v6, L")");
  LOBYTE(v26) = 9;
  this->ffbValue->setText(this->ffbValue, v7);
  if ( v25._Myres >= 8 )
    operator delete(v25._Bx._Ptr);
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  if ( v22._Myres >= 8 )
    operator delete(v22._Bx._Ptr);
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v26) = 3;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  std::shared_ptr<Font>::operator=(&this->font, &this->gui->ksgui::Form::ksgui::Control::font);
  v8 = this->gui->graphics->gl;
  GLRenderer::color4f(v8, 1.0, 1.0, 1.0, 1.0);
  v9 = this->ffb;
  y = _mm_loadu_si128((const __m128i *)&v9->leftButton->rect);
  v9->leftButton->getWorldRect(v9->leftButton, (ksgui::ksRect *)&y);
  GLRenderer::quad(
    v8,
    this->scaleMult + *(float *)&y.m128i_i32[1],
    *(float *)&y.m128i_i32[2],
    (float)((float)(this->scaleMult * 300.0) - (float)(this->scaleMult * 42.0)) - (float)(this->scaleMult * 2.0),
    this->scaleMult * 21.0,
    0,
    0);
  if ( this->isAutoAdjustingFF )
  {
    v10 = FLOAT_1_0;
    if ( dt <= 1.0 )
    {
      v10 = 0.0;
      if ( dt >= 0.0 )
        v10 = dt;
    }
    v11 = this->car;
    v12 = (float)((float)(v11->physicsState.lastFF_Pure - this->ffAvg) * v10) + this->ffAvg;
    this->ffAvg = v12;
    if ( (float)(COERCE_FLOAT(LODWORD(v12) & _xmm) * 100.0) > this->ffAvtPercentage )
    {
      LODWORD(this->ffAvtPercentage) = COERCE_UNSIGNED_INT(v12 * 100.0) & _xmm;
      v16 = CarAvatar::getFFMult(v11);
      this->suggestedFFMult = (float)((float)(0.89999998 / COERCE_FLOAT(LODWORD(this->ffAvg) & _xmm)) * v16) * 1000.0;
    }
  }
  ksgui::Control::render(this, (int)this, (int)v8, dt, v13, v14);
  *(_DWORD *)&v19.gap0[*(_DWORD *)(*(_DWORD *)v19.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v18 + *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v19.gap0 + 4) - 104;
  *(_DWORD *)&v19.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v19.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v19.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v19.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v19.gap68);
}
void FFBForm::shutdown(FFBForm *this)
{
  if ( this->isSaveNeeded )
    FFBForm::saveFFB(this);
}
void FFBForm::~FFBForm(FFBForm *this)
{
  this->__vftable = (FFBForm_vtbl *)&FFBForm::`vftable';
  if ( this->filename._Myres >= 8 )
    operator delete(this->filename._Bx._Ptr);
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&this->textRight);
  OnSetupAppCreated::~OnSetupAppCreated(&this->textLeft);
  this->__vftable = (FFBForm_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
