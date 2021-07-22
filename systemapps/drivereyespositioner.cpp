#include "drivereyespositioner.h
void __userpurge DriverEyesPositioner::DriverEyesPositioner(DriverEyesPositioner *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *aCar)
{
  Sim *v4; // eax
  const std::wstring *v5; // eax
  Font *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // edx
  int v9; // ecx
  Texture *v10; // eax
  Texture *v11; // eax
  ksgui::CustomSpinner *v12; // edi
  int v13; // eax
  int v14; // edi
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  std::wstring *v20; // eax
  int v21; // ecx
  std::wstring *v22; // ecx
  int v23; // ecx
  std::wstring *v24; // ecx
  std::wstring *v25; // eax
  CarAvatar *v26; // ecx
  vec3f *v27; // eax
  bool v28; // cf
  ksgui::CustomSpinner *v29; // edi
  int v30; // eax
  int v31; // edi
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  int v37; // ecx
  std::wstring *v38; // ecx
  int v39; // ecx
  std::wstring *v40; // ecx
  ksgui::CustomSpinner *v41; // edi
  int v42; // eax
  int v43; // edi
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  int v49; // ecx
  std::wstring *v50; // ecx
  int v51; // ecx
  std::wstring *v52; // ecx
  double v53; // st7
  double v54; // st7
  ksgui::Control *v55; // eax
  Texture *v56; // eax
  ksgui::Control *v57; // ecx
  std::wstring *v58; // ecx
  ksgui::Control *v59; // eax
  DriverEyesPositioner::{ctor}::__l19::<lambda_a7e28a60ea49c137682d9c8f30f9b8f2> *v60; // eax
  ksgui::Control *v61; // eax
  ResourceStore *v62; // eax
  const Texture *v63; // eax
  ksgui::Control *v64; // eax
  DriverEyesPositioner::{ctor}::__l20::<lambda_dbb35f46a481099f6458cc9b74b8f965> *v65; // eax
  ksgui::Control *v66; // eax
  ResourceStore *v67; // eax
  const Texture *v68; // eax
  ksgui::Control *v69; // eax
  DriverEyesPositioner::{ctor}::__l21::<lambda_9324bc2ed0d392755afe9f919de0f8ce> *v70; // eax
  ksgui::Control *v71; // eax
  ResourceStore *v72; // eax
  const Texture *v73; // eax
  ksgui::Control *v74; // eax
  DriverEyesPositioner::{ctor}::__l22::<lambda_66ac6c49d101590063f7a8543e2b33ef> *v75; // eax
  ksgui::Control *v76; // eax
  double v77; // st7
  int v78; // ecx
  ksgui::Form *v79; // ecx
  DriverEyesPositioner::{ctor}::__l23::<lambda_b53615026d993601ceadff32f20ea2aa> *v80; // eax
  const std::wstring *v81; // eax
  ksgui::Control *v82; // eax
  double v83; // st7
  int v84; // ecx
  ksgui::Form *v85; // ecx
  DriverEyesPositioner::{ctor}::__l24::<lambda_17b18095ccb9674f1652abfab99daa23> *v86; // eax
  const std::wstring *v87; // eax
  ksgui::CustomSpinner *v88; // eax
  float v89; // ecx
  ksgui::Control *v90; // ecx
  DriverEyesPositioner::{ctor}::__l25::<lambda_33790941e6efa79c882cc807a739386f> *v91; // eax
  const std::wstring *v92; // eax
  std::wstring *v93; // eax
  ksgui::Control *v94; // eax
  float v95; // ecx
  ksgui::Control *v96; // ecx
  int v97; // ecx
  DriverEyesPositioner::{ctor}::__l29::<lambda_ae9ff785cc949acf215055d2bb97b522> *v98; // eax
  const std::wstring *v99; // eax
  ksgui::Control *v100; // edi
  ksgui::Control *v101; // eax
  bool v102; // zf
  float v103; // ecx
  ksgui::Control *v104; // ecx
  int v105; // ecx
  DriverEyesPositioner::{ctor}::__l30::<lambda_d9aa85e9ef7eabc6ae791ef583e23a97> *v106; // eax
  const std::wstring *v107; // eax
  _BYTE v108[28]; // [esp+58h] [ebp-1D0h] BYREF
  float h; // [esp+74h] [ebp-1B4h]
  DriverEyesPositioner *v110; // [esp+A0h] [ebp-188h]
  int _Val; // [esp+A4h] [ebp-184h] BYREF
  ksgui::CustomSpinner *v112; // [esp+A8h] [ebp-180h] BYREF
  int v113; // [esp+ACh] [ebp-17Ch]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v114; // [esp+B0h] [ebp-178h] BYREF
  INIReader v115; // [esp+B4h] [ebp-174h] BYREF
  INIReader v116; // [esp+F8h] [ebp-130h] BYREF
  std::wstring filename; // [esp+13Ch] [ebp-ECh] BYREF
  std::wstring path; // [esp+154h] [ebp-D4h] BYREF
  std::wstring v119; // [esp+16Ch] [ebp-BCh] BYREF
  std::wstring _Left; // [esp+184h] [ebp-A4h] BYREF
  Texture v121; // [esp+19Ch] [ebp-8Ch] BYREF
  std::wstring iname; // [esp+1B8h] [ebp-70h] BYREF
  std::wstring key; // [esp+1D0h] [ebp-58h] BYREF
  std::wstring result; // [esp+1E8h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement text; // [esp+200h] [ebp-28h] BYREF
  int v126; // [esp+224h] [ebp-4h]

  v112 = 0;
  v113 = 0;
  LODWORD(h) = 1;
  v4 = aCar->sim;
  v110 = this;
  *(_DWORD *)&v108[24] = v4->game->gui;
  *(_DWORD *)&v108[20] = 7;
  *(_DWORD *)&v108[16] = 0;
  *(_WORD *)v108 = 0;
  std::wstring::assign((std::wstring *)v108, L"DRIVER_EYES_POSITIONER", 0x16u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v108, *(ksgui::GUI **)&v108[24], SLOBYTE(h));
  v126 = 0;
  this->__vftable = (DriverEyesPositioner_vtbl *)&DriverEyesPositioner::`vftable';
  this->bSaveCarINI = 0;
  this->bSaveDashINI = 0;
  this->regs._Myfirst = 0;
  this->regs._Mylast = 0;
  this->regs._Myend = 0;
  this->defaultEyesPosition.x = 0.0;
  this->defaultEyesPosition.y = 0.0;
  this->defaultEyesPosition.z = 0.0;
  this->textLeft.kid = 0;
  this->textLeft.fileName._Myres = 7;
  this->textLeft.fileName._Mysize = 0;
  this->textLeft.fileName._Bx._Buf[0] = 0;
  this->textRight.kid = 0;
  this->textRight.fileName._Myres = 7;
  this->textRight.fileName._Mysize = 0;
  this->textRight.fileName._Bx._Buf[0] = 0;
  h = *(float *)&this;
  this->needToSave = 0;
  *(_DWORD *)&v108[4] = &std::_Func_impl<std::_Callable_obj<_lambda_e5802f3d00876f053c8cc91e8eef3c1e_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v108[8] = this;
  *(_DWORD *)&v108[20] = &v108[4];
  LOBYTE(v126) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&aCar->sim->renderFinishedNodeEvent->evOnRender,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v108[4],
    (void *)LODWORD(h));
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"Onboard settings", 0x10u);
  LOBYTE(v126) = 5;
  v5 = acTranslate(&result, &text.name);
  LOBYTE(v126) = 6;
  this->formTitle->setText(this->formTitle, v5);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v126) = 3;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  *(float *)&v6 = COERCE_FLOAT(operator new(0x18u));
  v114.__this = (CarAudioFMOD *)v6;
  LOBYTE(v126) = 7;
  if ( *(float *)&v6 == 0.0 )
    v7 = 0;
  else
    Font::Font(v6, eFontMonospaced, 20.0, 0, 0);
  LOBYTE(v126) = 3;
  key._Mysize = 0;
  key._Myres = 0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&key._Mysize, v7);
  v8 = this->font._Rep;
  this->font._Rep = (std::_Ref_count_base *)key._Myres;
  _Val = (int)v8;
  this->font._Ptr = (Font *)key._Mysize;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      v9 = _Val;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(_Val + 8), 0xFFFFFFFF) )
        (*(void (**)(int))(*(_DWORD *)v9 + 4))(v9);
    }
  }
  this->devApp = 0;
  ksgui::Form::setSize(this, 400.0, 315.0);
  this->car = aCar;
  LODWORD(h) = 42;
  *(_DWORD *)&v108[24] = L"content/gui/controls/spinner/leftMinus.png";
  this->increment = 0.0;
  this->speed = 0.050000001;
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, *(const wchar_t **)&v108[24], LODWORD(h));
  LOBYTE(v126) = 8;
  v10 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &v121, &text.name, 0);
  LOBYTE(v126) = 9;
  this->textLeft.kid = v10->kid;
  if ( &this->textLeft.fileName != &v10->fileName )
    std::wstring::assign(&this->textLeft.fileName, &v10->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v126) = 8;
  OnSetupAppCreated::~OnSetupAppCreated(&v121);
  LOBYTE(v126) = 3;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  std::wstring::assign(&text.name, L"content/gui/controls/spinner/rightPlus.png", 0x2Au);
  LOBYTE(v126) = 10;
  v11 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &v121, &text.name, 0);
  LOBYTE(v126) = 11;
  this->textRight.kid = v11->kid;
  if ( &this->textRight.fileName != &v11->fileName )
    std::wstring::assign(&this->textRight.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v126) = 10;
  OnSetupAppCreated::~OnSetupAppCreated(&v121);
  LOBYTE(v126) = 3;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  *(float *)&v12 = COERCE_FLOAT(operator new(0x154u));
  v114.__this = (CarAudioFMOD *)v12;
  LOBYTE(v126) = 12;
  if ( *(float *)&v12 == 0.0 )
  {
    v14 = 0;
  }
  else
  {
    h = 0.0;
    *(_DWORD *)&v108[24] = this->gui;
    *(_DWORD *)&v108[20] = 7;
    *(_DWORD *)&v108[16] = 0;
    *(_WORD *)v108 = 0;
    std::wstring::assign((std::wstring *)v108, L"DISTANCE_SPINNER", 0x10u);
    ksgui::CustomSpinner::CustomSpinner(v12, *(std::wstring *)v108, *(ksgui::GUI **)&v108[24], SLODWORD(h));
    v14 = v13;
  }
  LOBYTE(v126) = 3;
  v112 = (ksgui::CustomSpinner *)v14;
  _Val = v14;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(float *)(_Val + 148) = *(float *)&this;
  v15 = *(float *)(v14 + 264);
  v16 = *(float *)(v14 + 32) - *(float *)(v14 + 28);
  v17 = *(float *)(v14 + 40) - *(float *)(v14 + 36);
  *(_DWORD *)(v14 + 36) = 1124532224;
  *(_DWORD *)(v14 + 28) = 1128792064;
  v18 = v16 + 200.0;
  v19 = v17 + 135.0;
  *(float *)(v14 + 32) = v18;
  *(float *)(v14 + 40) = v19;
  if ( v15 == 0.0 && *(float *)(v14 + 272) == 0.0 )
  {
    *(_DWORD *)(v14 + 264) = 1128792064;
    *(_DWORD *)(v14 + 272) = 1124532224;
    *(float *)(v14 + 268) = v18;
    *(float *)(v14 + 276) = v19;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v14 + 28))(v14, 1125515264, 1101529088);
  LODWORD(h) = 9;
  text.name._Myres = 7;
  text.name._Mysize = 0;
  *(_DWORD *)&v108[24] = L"SEAT POS.";
  text.name._Bx._Buf[0] = 0;
  *(_OWORD *)(v14 + 76) = 0i64;
  std::wstring::assign(&text.name, *(const wchar_t **)&v108[24], LODWORD(h));
  LOBYTE(v126) = 13;
  v20 = acTranslate(&result, &text.name);
  LOBYTE(v126) = 14;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v14 + 68))(v14, v20);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v126) = 3;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  v21 = *(_DWORD *)(v14 + 284);
  *(_DWORD *)(v21 + 172) = this->textLeft.kid;
  v22 = (std::wstring *)(v21 + 176);
  if ( v22 != &this->textLeft.fileName )
    std::wstring::assign(v22, &this->textLeft.fileName, 0, 0xFFFFFFFF);
  v23 = *(_DWORD *)(v14 + 288);
  *(_DWORD *)(v23 + 172) = this->textRight.kid;
  v24 = (std::wstring *)(v23 + 176);
  if ( v24 != &this->textRight.fileName )
    std::wstring::assign(v24, &this->textRight.fileName, 0, 0xFFFFFFFF);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  LOBYTE(v126) = 15;
  v25 = std::operator+<wchar_t>(&v119, &_Left, &this->car->unixName);
  LOBYTE(v126) = 16;
  std::operator+<wchar_t>(&filename, v25, L"/data/car.ini");
  if ( v119._Myres >= 8 )
    operator delete(v119._Bx._Ptr);
  v119._Myres = 7;
  v119._Mysize = 0;
  v119._Bx._Buf[0] = 0;
  LOBYTE(v126) = 19;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v26 = this->car;
  _Left._Bx._Buf[0] = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  CarAvatar::openINI(v26, &v116, &filename);
  LOBYTE(v126) = 20;
  if ( v116.ready )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"DRIVEREYES", 0xAu);
    LOBYTE(v126) = 21;
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    std::wstring::assign(&text.name, L"GRAPHICS", 8u);
    LOBYTE(v126) = 22;
    v27 = INIReader::getFloat3(&v116, (vec3f *)&key._Bx._Alias[12], &text.name, &result);
    v28 = text.name._Myres < 8;
    this->defaultEyesPosition = *v27;
    if ( !v28 )
      operator delete(text.name._Bx._Ptr);
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  *(_DWORD *)&v108[4] = &std::_Func_impl<std::_Callable_obj<_lambda_07349beeae4824298c40afa3804bcbb9_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v108[8] = this;
  *(_DWORD *)&v108[20] = &v108[4];
  LOBYTE(v126) = 20;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)(v14 + 284) + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    this);
  *(_DWORD *)&v108[4] = &std::_Func_impl<std::_Callable_obj<_lambda_8ad855ed5de67caa43dfb73bd85b03bc_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v108[8] = this;
  *(_DWORD *)&v108[20] = &v108[4];
  LOBYTE(v126) = 20;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)(v14 + 288) + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    this);
  std::vector<IDWriteFontFile *>::push_back(&this->regs, &v112);
  *(float *)&v29 = COERCE_FLOAT(operator new(0x154u));
  v114.__this = (CarAudioFMOD *)v29;
  LOBYTE(v126) = 25;
  if ( *(float *)&v29 == 0.0 )
  {
    v31 = 0;
  }
  else
  {
    h = 0.0;
    *(_DWORD *)&v108[24] = this->gui;
    std::wstring::wstring((std::wstring *)v108, L"FOV_SPINNER");
    ksgui::CustomSpinner::CustomSpinner(v29, *(std::wstring *)v108, *(ksgui::GUI **)&v108[24], SLODWORD(h));
    v31 = v30;
  }
  LOBYTE(v126) = 20;
  v112 = (ksgui::CustomSpinner *)v31;
  _Val = v31;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(float *)(_Val + 148) = *(float *)&this;
  v32 = *(float *)(v31 + 264);
  v33 = *(float *)(v31 + 32) - *(float *)(v31 + 28);
  v34 = *(float *)(v31 + 40) - *(float *)(v31 + 36);
  *(_DWORD *)(v31 + 36) = 1115815936;
  *(_DWORD *)(v31 + 28) = 1128792064;
  v35 = v33 + 200.0;
  v36 = v34 + 65.0;
  *(float *)(v31 + 32) = v35;
  *(float *)(v31 + 40) = v36;
  if ( v32 == 0.0 && *(float *)(v31 + 272) == 0.0 )
  {
    *(_DWORD *)(v31 + 264) = 1128792064;
    *(_DWORD *)(v31 + 272) = 1115815936;
    *(float *)(v31 + 268) = v35;
    *(float *)(v31 + 276) = v36;
  }
  *(_OWORD *)(v31 + 76) = 0i64;
  (*(void (**)(int, int, int))(*(_DWORD *)v31 + 28))(v31, 1125515264, 1101529088);
  v37 = *(_DWORD *)(v31 + 284);
  *(_DWORD *)(v37 + 172) = this->textLeft.kid;
  v38 = (std::wstring *)(v37 + 176);
  if ( v38 != &this->textLeft.fileName )
    std::wstring::assign(v38, &this->textLeft.fileName, 0, 0xFFFFFFFF);
  v39 = *(_DWORD *)(v31 + 288);
  *(_DWORD *)(v39 + 172) = this->textRight.kid;
  v40 = (std::wstring *)(v39 + 176);
  if ( v40 != &this->textRight.fileName )
    std::wstring::assign(v40, &this->textRight.fileName, 0, 0xFFFFFFFF);
  *(_DWORD *)&v108[4] = &std::_Func_impl<std::_Callable_obj<_lambda_9f52db2735766499c12c0ea0deb6f652_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v108[8] = this;
  *(_DWORD *)&v108[20] = &v108[4];
  LOBYTE(v126) = 20;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)(v31 + 284) + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    this);
  *(_DWORD *)&v108[4] = &std::_Func_impl<std::_Callable_obj<_lambda_af5ebad1dc4b8ca34de45101bbf71e69_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v108[8] = this;
  *(_DWORD *)&v108[20] = &v108[4];
  LOBYTE(v126) = 20;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)(v31 + 288) + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    this);
  std::vector<IDWriteFontFile *>::push_back(&this->regs, &v112);
  LODWORD(h) = 340;
  this->currentFov = 0.0;
  *(float *)&v41 = COERCE_FLOAT(operator new(LODWORD(h)));
  v114.__this = (CarAudioFMOD *)v41;
  LOBYTE(v126) = 28;
  if ( *(float *)&v41 == 0.0 )
  {
    v43 = 0;
  }
  else
  {
    h = 0.0;
    *(_DWORD *)&v108[24] = this->gui;
    std::wstring::wstring((std::wstring *)v108, L"PITCH_SPINNER");
    ksgui::CustomSpinner::CustomSpinner(v41, *(std::wstring *)v108, *(ksgui::GUI **)&v108[24], SLODWORD(h));
    v43 = v42;
  }
  LOBYTE(v126) = 20;
  _Val = v43;
  v112 = (ksgui::CustomSpinner *)v43;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v112);
  v112->parent = this;
  v44 = *(float *)(v43 + 264);
  v45 = *(float *)(v43 + 32) - *(float *)(v43 + 28);
  v46 = *(float *)(v43 + 40) - *(float *)(v43 + 36);
  *(_DWORD *)(v43 + 36) = 1126825984;
  *(_DWORD *)(v43 + 28) = 1128792064;
  v47 = v45 + 200.0;
  v48 = v46 + 170.0;
  *(float *)(v43 + 32) = v47;
  *(float *)(v43 + 40) = v48;
  if ( v44 == 0.0 && *(float *)(v43 + 272) == 0.0 )
  {
    *(_DWORD *)(v43 + 264) = 1128792064;
    *(_DWORD *)(v43 + 272) = 1126825984;
    *(float *)(v43 + 268) = v47;
    *(float *)(v43 + 276) = v48;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v43 + 28))(v43, 1125515264, 1101529088);
  *(_OWORD *)(v43 + 76) = 0i64;
  v49 = *(_DWORD *)(v43 + 284);
  *(_DWORD *)(v49 + 172) = this->textLeft.kid;
  v50 = (std::wstring *)(v49 + 176);
  if ( v50 != &this->textLeft.fileName )
    std::wstring::assign(v50, &this->textLeft.fileName, 0, 0xFFFFFFFF);
  v51 = *(_DWORD *)(v43 + 288);
  *(_DWORD *)(v51 + 172) = this->textRight.kid;
  v52 = (std::wstring *)(v51 + 176);
  if ( v52 != &this->textRight.fileName )
    std::wstring::assign(v52, &this->textRight.fileName, 0, 0xFFFFFFFF);
  *(_DWORD *)&v108[4] = &std::_Func_impl<std::_Callable_obj<_lambda_82d0ff800d36e7527155b8df918bf7c3_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v108[8] = this;
  *(_DWORD *)&v108[20] = &v108[4];
  LOBYTE(v126) = 20;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)(v43 + 284) + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    this);
  *(_DWORD *)&v108[4] = &std::_Func_impl<std::_Callable_obj<_lambda_bb6f84c8e4525073ad102766ac6d261b_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v108[8] = this;
  *(_DWORD *)&v108[20] = &v108[4];
  LOBYTE(v126) = 20;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)(v43 + 288) + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    this);
  std::vector<IDWriteFontFile *>::push_back(&this->regs, (ksgui::CustomSpinner *const *)&_Val);
  std::wstring::wstring(&result, L"cfg/camera_onboard.ini");
  LOBYTE(v126) = 31;
  INIReader::INIReader(&v115, &result);
  LOBYTE(v126) = 33;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v115.ready )
  {
    std::wstring::wstring(&key, L"FOV");
    LOBYTE(v126) = 34;
    std::wstring::wstring(&text.name, L"MODE");
    LOBYTE(v126) = 35;
    v53 = INIReader::getFloat(&v115, &text.name, &key);
    v28 = text.name._Myres < 8;
    this->defaultFOV = v53;
    if ( !v28 )
      operator delete(text.name._Bx._Ptr);
    LOBYTE(v126) = 33;
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( v116.ready )
  {
    std::wstring::wstring(&key, L"ON_BOARD_PITCH_ANGLE");
    LOBYTE(v126) = 36;
    std::wstring::wstring(&text.name, L"GRAPHICS");
    LOBYTE(v126) = 37;
    v54 = INIReader::getFloat(&v116, &text.name, &key);
    v28 = text.name._Myres < 8;
    this->defaultPitch = v54 * 0.017453;
    if ( !v28 )
      operator delete(text.name._Bx._Ptr);
    LOBYTE(v126) = 33;
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
  LOBYTE(v126) = 38;
  if ( *(float *)&v114.__this == 0.0 )
  {
    v55 = 0;
  }
  else
  {
    std::wstring::wstring(&text.name, L"ButtonUp");
    LOBYTE(v126) = 39;
    h = *(float *)&this->gui;
    v113 = 1;
    v112 = (ksgui::CustomSpinner *)1;
    ksgui::Control::Control((ksgui::Control *)v114.__this, &text.name, (ksgui::GUI *)LODWORD(h));
  }
  this->bUp = v55;
  v126 = 33;
  if ( (v113 & 1) != 0 )
  {
    v113 &= 0xFFFFFFFE;
    if ( text.name._Myres >= 8 )
      operator delete(text.name._Bx._Ptr);
  }
  v112 = (ksgui::CustomSpinner *)this->bUp;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v112);
  v112->parent = this;
  ksgui::Form::setPosition((ksgui::Form *)this->bUp, 75.0, 65.0);
  ((void (*)(ksgui::Control *, int, int))this->bUp->setSize)(this->bUp, 1106247680, 1106247680);
  std::wstring::wstring(&text.name, L"content/gui/driverEyesPositioner/arrowUp.png");
  LOBYTE(v126) = 41;
  v56 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &v121, &text.name, 0);
  LOBYTE(v126) = 42;
  v57 = this->bUp;
  v57->backTexture.kid = v56->kid;
  v58 = &v57->backTexture.fileName;
  if ( v58 != &v56->fileName )
    std::wstring::assign(v58, &v56->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v126) = 41;
  OnSetupAppCreated::~OnSetupAppCreated(&v121);
  LOBYTE(v126) = 33;
  std::wstring::~wstring(&text);
  v59 = this->bUp;
  h = *(float *)&this;
  *(_DWORD *)&v108[24] = this;
  v59->drawBackground = 0;
  this->bUp->drawBorder = 0;
  CommandItem::CommandItem(&v114, *(CarAudioFMOD **)&v108[24]);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
    v60);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bUp->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    (void *)LODWORD(h));
  *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
  LOBYTE(v126) = 43;
  if ( *(float *)&v114.__this == 0.0 )
  {
    v61 = 0;
  }
  else
  {
    std::wstring::wstring(&text.name, L"ButtonDown");
    LOBYTE(v126) = 44;
    h = *(float *)&this->gui;
    v113 |= 2u;
    v112 = (ksgui::CustomSpinner *)v113;
    ksgui::Control::Control((ksgui::Control *)v114.__this, &text.name, (ksgui::GUI *)LODWORD(h));
  }
  this->bDown = v61;
  v126 = 33;
  if ( (v113 & 2) != 0 )
  {
    v113 &= 0xFFFFFFFD;
    std::wstring::~wstring(&text);
  }
  ksgui::Control::addControl(this, this->bDown);
  ksgui::Form::setPosition((ksgui::Form *)this->bDown, 75.0, 165.0);
  ((void (*)(ksgui::Control *, int, int))this->bDown->setSize)(this->bDown, 1106247680, 1106247680);
  std::wstring::wstring(&text.name, L"content/gui/driverEyesPositioner/arrowDown.png");
  h = 0.0;
  LOBYTE(v126) = 46;
  *(_DWORD *)&v108[24] = &text;
  *(_DWORD *)&v108[20] = &v121;
  v62 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v63 = ResourceStore::getTexture(v62, *(Texture **)&v108[20], *(const std::wstring **)&v108[24], SLOBYTE(h));
  LOBYTE(v126) = 47;
  Texture::operator=(&this->bDown->backTexture, v63);
  LOBYTE(v126) = 46;
  OnSetupAppCreated::~OnSetupAppCreated(&v121);
  LOBYTE(v126) = 33;
  std::wstring::~wstring(&text);
  v64 = this->bDown;
  h = *(float *)&this;
  *(_DWORD *)&v108[24] = this;
  v64->drawBackground = 0;
  this->bDown->drawBorder = 0;
  CommandItem::CommandItem(&v114, *(CarAudioFMOD **)&v108[24]);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
    v65);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bDown->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    (void *)LODWORD(h));
  *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
  LOBYTE(v126) = 48;
  if ( *(float *)&v114.__this == 0.0 )
  {
    v66 = 0;
  }
  else
  {
    std::wstring::wstring(&text.name, L"ButtonLeft");
    LOBYTE(v126) = 49;
    h = *(float *)&this->gui;
    v113 |= 4u;
    v112 = (ksgui::CustomSpinner *)v113;
    ksgui::Control::Control((ksgui::Control *)v114.__this, &text.name, (ksgui::GUI *)LODWORD(h));
  }
  this->bLeft = v66;
  v126 = 33;
  if ( (v113 & 4) != 0 )
  {
    v113 &= 0xFFFFFFFB;
    std::wstring::~wstring(&text);
  }
  ksgui::Control::addControl(this, this->bLeft);
  ksgui::Form::setPosition((ksgui::Form *)this->bLeft, 25.0, 115.0);
  ((void (*)(ksgui::Control *, int, int))this->bLeft->setSize)(this->bLeft, 1106247680, 1106247680);
  std::wstring::wstring(&text.name, L"content/gui/driverEyesPositioner/arrowLeft.png");
  h = 0.0;
  LOBYTE(v126) = 51;
  *(_DWORD *)&v108[24] = &text;
  *(_DWORD *)&v108[20] = &v121;
  v67 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v68 = ResourceStore::getTexture(v67, *(Texture **)&v108[20], *(const std::wstring **)&v108[24], SLOBYTE(h));
  LOBYTE(v126) = 52;
  Texture::operator=(&this->bLeft->backTexture, v68);
  LOBYTE(v126) = 51;
  OnSetupAppCreated::~OnSetupAppCreated(&v121);
  LOBYTE(v126) = 33;
  std::wstring::~wstring(&text);
  v69 = this->bLeft;
  h = *(float *)&this;
  *(_DWORD *)&v108[24] = this;
  v69->drawBackground = 0;
  this->bLeft->drawBorder = 0;
  CommandItem::CommandItem(&v114, *(CarAudioFMOD **)&v108[24]);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
    v70);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bLeft->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    (void *)LODWORD(h));
  *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
  LOBYTE(v126) = 53;
  if ( *(float *)&v114.__this == 0.0 )
  {
    v71 = 0;
  }
  else
  {
    std::wstring::wstring(&text.name, L"ButtonRight");
    LOBYTE(v126) = 54;
    h = *(float *)&this->gui;
    v113 |= 8u;
    v112 = (ksgui::CustomSpinner *)v113;
    ksgui::Control::Control((ksgui::Control *)v114.__this, &text.name, (ksgui::GUI *)LODWORD(h));
  }
  this->bRight = v71;
  v126 = 33;
  if ( (v113 & 8) != 0 )
  {
    v113 &= 0xFFFFFFF7;
    std::wstring::~wstring(&text);
  }
  ksgui::Control::addControl(this, this->bRight);
  ksgui::Form::setPosition((ksgui::Form *)this->bRight, 125.0, 115.0);
  ((void (*)(ksgui::Control *, int, int))this->bRight->setSize)(this->bRight, 1106247680, 1106247680);
  std::wstring::wstring(&text.name, L"content/gui/driverEyesPositioner/arrowRight.png");
  h = 0.0;
  LOBYTE(v126) = 56;
  *(_DWORD *)&v108[24] = &text;
  *(_DWORD *)&v108[20] = &v121;
  v72 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v73 = ResourceStore::getTexture(v72, *(Texture **)&v108[20], *(const std::wstring **)&v108[24], SLOBYTE(h));
  LOBYTE(v126) = 57;
  Texture::operator=(&this->bRight->backTexture, v73);
  LOBYTE(v126) = 56;
  OnSetupAppCreated::~OnSetupAppCreated(&v121);
  LOBYTE(v126) = 33;
  std::wstring::~wstring(&text);
  v74 = this->bRight;
  h = *(float *)&this;
  *(_DWORD *)&v108[24] = this;
  v74->drawBackground = 0;
  this->bRight->drawBorder = 0;
  CommandItem::CommandItem(&v114, *(CarAudioFMOD **)&v108[24]);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
    v75);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bRight->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    (void *)LODWORD(h));
  *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
  LOBYTE(v126) = 58;
  if ( *(float *)&v114.__this == 0.0 )
  {
    v76 = 0;
  }
  else
  {
    std::wstring::wstring(&text.name, L"ButtonReset");
    LOBYTE(v126) = 59;
    h = *(float *)&this->gui;
    v113 |= 0x10u;
    v112 = (ksgui::CustomSpinner *)v113;
    ksgui::Control::Control((ksgui::Control *)v114.__this, &text.name, (ksgui::GUI *)LODWORD(h));
  }
  this->bReset = v76;
  v126 = 33;
  if ( (v113 & 0x10) != 0 )
  {
    v113 &= 0xFFFFFFEF;
    std::wstring::~wstring(&text);
  }
  ksgui::Control::addControl(this, this->bReset);
  h = 250.0;
  v77 = ksgui::Control::getWidth((ksgui::Control *)*(_DWORD *)(_Val + 288));
  *(_DWORD *)&v108[24] = v78;
  v79 = (ksgui::Form *)this->bReset;
  *(float *)&v108[24] = v77 + 200.0;
  ksgui::Form::setPosition(v79, *(float *)&v108[24], h);
  ((void (*)(ksgui::Control *, int, int))this->bReset->setSize)(this->bReset, 1121452032, 1101529088);
  h = *(float *)&this;
  CommandItem::CommandItem(&v114, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
    v80);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bReset->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    (void *)LODWORD(h));
  std::wstring::wstring(&text.name, L"Reset");
  LOBYTE(v126) = 61;
  v81 = acTranslate(&iname, &text.name);
  LOBYTE(v126) = 62;
  this->bReset->setText(this->bReset, v81);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  LOBYTE(v126) = 33;
  std::wstring::~wstring(&text);
  *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
  LOBYTE(v126) = 63;
  if ( *(float *)&v114.__this == 0.0 )
  {
    v82 = 0;
  }
  else
  {
    std::wstring::wstring(&text.name, L"ButtonSave");
    LOBYTE(v126) = 64;
    h = *(float *)&this->gui;
    v113 |= 0x20u;
    v112 = (ksgui::CustomSpinner *)v113;
    ksgui::Control::Control((ksgui::Control *)v114.__this, &text.name, (ksgui::GUI *)LODWORD(h));
  }
  this->bSave = v82;
  v126 = 33;
  if ( (v113 & 0x20) != 0 )
  {
    v113 &= 0xFFFFFFDF;
    std::wstring::~wstring(&text);
  }
  ksgui::Control::addControl(this, this->bSave);
  h = 250.0;
  v83 = ksgui::Control::getWidth((ksgui::Control *)*(_DWORD *)(_Val + 288));
  *(_DWORD *)&v108[24] = v84;
  v85 = (ksgui::Form *)this->bSave;
  *(float *)&v108[24] = v83 + 50.0;
  ksgui::Form::setPosition(v85, *(float *)&v108[24], h);
  ((void (*)(ksgui::Control *, int, int))this->bSave->setSize)(this->bSave, 1121452032, 1101529088);
  h = *(float *)&this;
  CommandItem::CommandItem(&v114, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
    v86);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->bSave->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    (void *)LODWORD(h));
  std::wstring::wstring(&text.name, L"Save");
  LOBYTE(v126) = 66;
  v87 = acTranslate(&iname, &text.name);
  LOBYTE(v126) = 67;
  this->bSave->setText(this->bSave, v87);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  LOBYTE(v126) = 33;
  std::wstring::~wstring(&text);
  *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
  LOBYTE(v126) = 68;
  if ( *(float *)&v114.__this == 0.0 )
  {
    v112 = 0;
  }
  else
  {
    std::wstring::wstring(&text.name, L"Auto pos");
    LOBYTE(v126) = 69;
    h = *(float *)&this->gui;
    v113 |= 0x40u;
    v112 = (ksgui::CustomSpinner *)v113;
    ksgui::Control::Control((ksgui::Control *)v114.__this, &text.name, (ksgui::GUI *)LODWORD(h));
    v112 = v88;
  }
  v126 = 33;
  if ( (v113 & 0x40) != 0 )
  {
    v113 &= 0xFFFFFFBF;
    std::wstring::~wstring(&text);
  }
  ksgui::Control::addControl(this, v112);
  *(float *)&v114.__this = ksgui::Control::getHeight(this->bSave);
  h = v89;
  v90 = *(ksgui::Control **)(_Val + 288);
  h = (float)(*(float *)&v114.__this + 250.0) + 10.0;
  *(float *)&v108[24] = ksgui::Control::getWidth(v90) + 200.0;
  ksgui::Form::setPosition((ksgui::Form *)v112, *(float *)&v108[24], h);
  ((void (*)(ksgui::CustomSpinner *, int, int))v112->setSize)(v112, 1121452032, 1101529088);
  h = *(float *)&this;
  CommandItem::CommandItem(&v114, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
    v91);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v112->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
    (void *)LODWORD(h));
  std::wstring::wstring(&iname, L"Auto Pos");
  LOBYTE(v126) = 71;
  v92 = acTranslate(&key, &iname);
  LOBYTE(v126) = 72;
  v112->setText(v112, v92);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  LOBYTE(v126) = 33;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  v93 = std::operator+<wchar_t>(&v121.fileName, L"content/cars/", &this->car->unixName);
  LOBYTE(v126) = 73;
  std::operator+<wchar_t>(&path, v93, L"/data/car.ini");
  LOBYTE(v126) = 75;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v121.fileName);
  if ( Path::fileExists(a2, &path, 1) )
  {
    *(float *)&v114.__this = COERCE_FLOAT(operator new(0x118u));
    LOBYTE(v126) = 76;
    if ( *(float *)&v114.__this == 0.0 )
    {
      v94 = 0;
    }
    else
    {
      std::wstring::wstring(&iname, L"ButtonSaveINI");
      LOBYTE(v126) = 77;
      h = *(float *)&this->gui;
      v113 |= 0x80u;
      v112 = (ksgui::CustomSpinner *)v113;
      ksgui::Control::Control((ksgui::Control *)v114.__this, &iname, (ksgui::GUI *)LODWORD(h));
    }
    this->bSaveCarINI = v94;
    v126 = 75;
    if ( (v113 & 0x80u) != 0 )
    {
      v113 &= 0xFFFFFF7F;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    }
    ksgui::Control::addControl(this, this->bSaveCarINI);
    *(float *)&v114.__this = ksgui::Control::getHeight(this->bSave);
    h = v95;
    v96 = *(ksgui::Control **)(_Val + 288);
    h = (float)((float)(*(float *)&v114.__this + 250.0) + 10.0) - 70.0;
    *(float *)&v114.__this = ksgui::Control::getWidth(v96);
    *(_DWORD *)&v108[24] = v97;
    ksgui::Form::setPosition((ksgui::Form *)this->bSaveCarINI, (float)(*(float *)&v114.__this + 100.0) - 70.0, h);
    ((void (*)(ksgui::Control *, int, int))this->bSaveCarINI->setSize)(
      this->bSaveCarINI,
      1121452032,
      1101529088);
    h = *(float *)&this;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&key._Myres,
      (CarAudioFMOD *)this);
    std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
      (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
      v98);
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)&this->bSaveCarINI->evClicked,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
      (void *)LODWORD(h));
    std::wstring::wstring(&iname, L"Save car.ini");
    LOBYTE(v126) = 79;
    v99 = acTranslate(&result, &iname);
    LOBYTE(v126) = 80;
    this->bSaveCarINI->setText(this->bSaveCarINI, v99);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v126) = 75;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    v100 = (ksgui::Control *)operator new(0x118u);
    key._Myres = (unsigned int)v100;
    LOBYTE(v126) = 81;
    if ( v100 )
    {
      std::wstring::wstring(&iname, L"ButtonSaveINI");
      LOBYTE(v126) = 82;
      h = *(float *)&this->gui;
      v113 |= 0x100u;
      v112 = (ksgui::CustomSpinner *)v113;
      ksgui::Control::Control(v100, &iname, (ksgui::GUI *)LODWORD(h));
    }
    else
    {
      v101 = 0;
    }
    v126 = 75;
    v102 = (v113 & 0x100) == 0;
    this->bSaveDashINI = v101;
    if ( !v102 )
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    ksgui::Control::addControl(this, this->bSaveDashINI);
    *(float *)&v114.__this = ksgui::Control::getHeight(this->bSave);
    h = v103;
    v104 = *(ksgui::Control **)(_Val + 288);
    h = (float)((float)(*(float *)&v114.__this + 250.0) + 10.0) - 70.0;
    *(float *)&v114.__this = ksgui::Control::getWidth(v104);
    *(_DWORD *)&v108[24] = v105;
    ksgui::Form::setPosition((ksgui::Form *)this->bSaveDashINI, (float)(*(float *)&v114.__this + 300.0) - 70.0, h);
    ((void (*)(ksgui::Control *, int, int))this->bSaveDashINI->setSize)(
      this->bSaveDashINI,
      1121452032,
      1101529088);
    h = *(float *)&this;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&key._Myres,
      (CarAudioFMOD *)this);
    std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
      (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v108[4],
      v106);
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)&this->bSaveDashINI->evClicked,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v108[4],
      (void *)LODWORD(h));
    std::wstring::wstring(&iname, L"Save Dash");
    LOBYTE(v126) = 84;
    v107 = acTranslate(&result, &iname);
    LOBYTE(v126) = 85;
    this->bSaveDashINI->setText(this->bSaveDashINI, v107);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v126) = 75;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  }
  ksgui::Control::scaleByMult(this);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
  LOBYTE(v126) = 20;
  INIReader::~INIReader(&v115);
  LOBYTE(v126) = 19;
  INIReader::~INIReader(&v116);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
}
DriverEyesPositioner *DriverEyesPositioner::`scalar deleting destructor'(DriverEyesPositioner *this, unsigned int a2)
{
  DriverEyesPositioner::~DriverEyesPositioner(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DriverEyesPositioner::saveToDashINI(DriverEyesPositioner *this)
{
  std::wstring *v2; // eax
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  std::wostream *v8; // eax
  std::wostream *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // ecx
  std::wstring *v12; // eax
  char *_Val; // [esp+0h] [ebp-19Ch]
  const char *v14; // [esp+18h] [ebp-184h]
  int v15; // [esp+28h] [ebp-174h]
  int v16; // [esp+2Ch] [ebp-170h]
  int v17; // [esp+30h] [ebp-16Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v18; // [esp+34h] [ebp-168h] BYREF
  std::wstring _Left; // [esp+E4h] [ebp-B8h] BYREF
  std::wstring filename; // [esp+FCh] [ebp-A0h] BYREF
  std::wstring v21; // [esp+114h] [ebp-88h] BYREF
  std::wstring v22; // [esp+12Ch] [ebp-70h] BYREF
  std::wstring inifile; // [esp+144h] [ebp-58h] BYREF
  std::wstring result; // [esp+15Ch] [ebp-40h] BYREF
  std::wstring v25; // [esp+174h] [ebp-28h] BYREF
  int v26; // [esp+190h] [ebp-Ch]
  int v27; // [esp+198h] [ebp-4h]

  v17 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v27 = 0;
  v2 = std::operator+<wchar_t>(&result, &_Left, &this->car->unixName);
  LOBYTE(v27) = 1;
  std::operator+<wchar_t>(&inifile, v2, L"/data/dash_cam.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v27) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  _Left._Mysize = 0;
  v3 = Path::getDocumentPath(&v21);
  LOBYTE(v27) = 5;
  v4 = std::operator+<wchar_t>(&v25, v3, L"/Assetto Corsa/cfg/cars/");
  LOBYTE(v27) = 6;
  v5 = std::operator+<wchar_t>(&v22, v4, &this->car->unixName);
  LOBYTE(v27) = 7;
  std::operator+<wchar_t>(&filename, v5, L"/view.ini");
  if ( v22._Myres >= 8 )
    operator delete(v22._Bx._Ptr);
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  if ( v25._Myres >= 8 )
    operator delete(v25._Bx._Ptr);
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  LOBYTE(v27) = 11;
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  *(_DWORD *)v18.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v18.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v18.gap68);
  LOBYTE(v27) = 12;
  v17 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v18, &v18.gap10[8], 0);
  v26 = 13;
  *(int *)((char *)&v16 + *(_DWORD *)(v16 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v15 + *(_DWORD *)(v16 + 4)) = *(_DWORD *)(v16 + 4) - 104;
  std::wstreambuf::wstreambuf(v18.gap10);
  *(_DWORD *)v18.gap10 = &std::wstringbuf::`vftable';
  *(_DWORD *)&v18.gap10[56] = 0;
  *(_DWORD *)&v18.gap10[60] = 0;
  LOBYTE(v26) = 15;
  _Val = (char *)LODWORD(this->car->driverEyesPosition.x);
  v6 = (std::wostream *)std::wostream::operator<<(&v18._Chcount);
  v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, _Val);
  v8 = (std::wostream *)std::wostream::operator<<(v7);
  v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v8, v14);
  std::wostream::operator<<(v9);
  v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v18, &v21);
  v11 = &inifile;
  if ( inifile._Myres >= 8 )
    v11 = (std::wstring *)inifile._Bx._Ptr;
  if ( v10->_Myres >= 8 )
    v10 = (std::wstring *)v10->_Bx._Ptr;
  WritePrivateProfileStringW(L"DASH_CAM", L"POS", v10->_Bx._Buf, v11->_Bx._Buf);
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v12 = &filename;
  if ( filename._Myres >= 8 )
    v12 = (std::wstring *)filename._Bx._Ptr;
  DeleteFileW(v12->_Bx._Buf);
  *(_DWORD *)&v18.gap0[*(_DWORD *)(*(_DWORD *)v18.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v17 + *(_DWORD *)(*(_DWORD *)v18.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v18.gap0 + 4) - 104;
  *(_DWORD *)&v18.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v18.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v18.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v18.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v18.gap68);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( inifile._Myres >= 8 )
    operator delete(inifile._Bx._Ptr);
}
void DriverEyesPositioner::saveToINI(DriverEyesPositioner *this)
{
  std::wstring *v2; // eax
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  std::wostream *v8; // eax
  std::wostream *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // ecx
  std::wstring *v12; // eax
  std::wstring *v13; // ecx
  std::wstring *v14; // eax
  char *_Val; // [esp+0h] [ebp-19Ch]
  const char *v16; // [esp+18h] [ebp-184h]
  int v17; // [esp+28h] [ebp-174h]
  int v18; // [esp+2Ch] [ebp-170h]
  int v19; // [esp+30h] [ebp-16Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v20; // [esp+34h] [ebp-168h] BYREF
  std::wstring v21; // [esp+E4h] [ebp-B8h] BYREF
  std::wstring _Left; // [esp+FCh] [ebp-A0h] BYREF
  std::wstring filename; // [esp+114h] [ebp-88h] BYREF
  std::wstring inifile; // [esp+12Ch] [ebp-70h] BYREF
  std::wstring result; // [esp+144h] [ebp-58h] BYREF
  std::wstring v26; // [esp+15Ch] [ebp-40h] BYREF
  std::wstring v27; // [esp+174h] [ebp-28h] BYREF
  int v28; // [esp+190h] [ebp-Ch]
  int v29; // [esp+198h] [ebp-4h]

  v19 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v29 = 0;
  v2 = std::operator+<wchar_t>(&result, &_Left, &this->car->unixName);
  LOBYTE(v29) = 1;
  std::operator+<wchar_t>(&inifile, v2, L"/data/car.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v29) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  _Left._Mysize = 0;
  v3 = Path::getDocumentPath(&v21);
  LOBYTE(v29) = 5;
  v4 = std::operator+<wchar_t>(&v27, v3, L"/Assetto Corsa/cfg/cars/");
  LOBYTE(v29) = 6;
  v5 = std::operator+<wchar_t>(&v26, v4, &this->car->unixName);
  LOBYTE(v29) = 7;
  std::operator+<wchar_t>(&filename, v5, L"/view.ini");
  if ( v26._Myres >= 8 )
    operator delete(v26._Bx._Ptr);
  v26._Myres = 7;
  v26._Mysize = 0;
  v26._Bx._Buf[0] = 0;
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  LOBYTE(v29) = 11;
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  *(_DWORD *)v20.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v20.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v20.gap68);
  LOBYTE(v29) = 12;
  v19 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v20, &v20.gap10[8], 0);
  v28 = 13;
  *(int *)((char *)&v18 + *(_DWORD *)(v18 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v17 + *(_DWORD *)(v18 + 4)) = *(_DWORD *)(v18 + 4) - 104;
  std::wstreambuf::wstreambuf(v20.gap10);
  *(_DWORD *)v20.gap10 = &std::wstringbuf::`vftable';
  *(_DWORD *)&v20.gap10[56] = 0;
  *(_DWORD *)&v20.gap10[60] = 0;
  LOBYTE(v28) = 15;
  _Val = (char *)LODWORD(this->car->driverEyesPosition.x);
  v6 = (std::wostream *)std::wostream::operator<<(&v20._Chcount);
  v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, _Val);
  v8 = (std::wostream *)std::wostream::operator<<(v7);
  v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v8, v16);
  std::wostream::operator<<(v9);
  v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v20, &v21);
  v11 = &inifile;
  if ( inifile._Myres >= 8 )
    v11 = (std::wstring *)inifile._Bx._Ptr;
  if ( v10->_Myres >= 8 )
    v10 = (std::wstring *)v10->_Bx._Ptr;
  WritePrivateProfileStringW(L"GRAPHICS", L"DRIVEREYES", v10->_Bx._Buf, v11->_Bx._Buf);
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v12 = std::to_wstring(
          &v21,
          this->car->sim->cameraManager->cameraOnBoard->customCameraSettings._Myfirst->pitch * 57.29578);
  v13 = &inifile;
  if ( inifile._Myres >= 8 )
    v13 = (std::wstring *)inifile._Bx._Ptr;
  if ( v12->_Myres >= 8 )
    v12 = (std::wstring *)v12->_Bx._Ptr;
  WritePrivateProfileStringW(L"GRAPHICS", L"ON_BOARD_PITCH_ANGLE", v12->_Bx._Buf, v13->_Bx._Buf);
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v14 = &filename;
  if ( filename._Myres >= 8 )
    v14 = (std::wstring *)filename._Bx._Ptr;
  DeleteFileW(v14->_Bx._Buf);
  *(_DWORD *)&v20.gap0[*(_DWORD *)(*(_DWORD *)v20.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v19 + *(_DWORD *)(*(_DWORD *)v20.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v20.gap0 + 4) - 104;
  *(_DWORD *)&v20.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v20.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v20.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v20.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v20.gap68);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( inifile._Myres >= 8 )
    operator delete(inifile._Bx._Ptr);
}
void DriverEyesPositioner::saveSettings(DriverEyesPositioner *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  std::wstring *v4; // ecx
  std::wstring *v5; // edx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  std::wstring *v10; // ecx
  std::wstring *v11; // edx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::ostream *v16; // eax
  CarAvatar *v17; // eax
  std::ostream *v18; // eax
  std::ostream *v19; // eax
  std::ostream *v20; // eax
  std::ostream *v21; // eax
  std::ostream *v22; // eax
  int v23; // eax
  int v24; // eax
  std::ostream *v25; // eax
  std::ostream *v26; // eax
  int v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // edi
  std::wstring *v30; // eax
  char *_Val; // [esp+24h] [ebp-200h]
  int v32; // [esp+30h] [ebp-1F4h]
  int v33; // [esp+30h] [ebp-1F4h]
  std::forward_iterator_tag __formal[4]; // [esp+40h] [ebp-1E4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v35; // [esp+44h] [ebp-1E0h] BYREF
  std::ofstream out; // [esp+F4h] [ebp-130h] BYREF
  std::wstring _Right; // [esp+19Ch] [ebp-88h] BYREF
  std::wstring result; // [esp+1B4h] [ebp-70h] BYREF
  std::wstring v39; // [esp+1CCh] [ebp-58h] BYREF
  std::wstring v40; // [esp+1E4h] [ebp-40h] BYREF
  std::wstring filename; // [esp+1FCh] [ebp-28h] BYREF
  int v42; // [esp+220h] [ebp-4h]

  *(_DWORD *)&__formal[0].gap0 = 0;
  v2 = Path::getDocumentPath(&result);
  v42 = 0;
  v3 = std::operator+<wchar_t>(&_Right, v2, L"/Assetto Corsa/cfg/cars/");
  LOBYTE(v42) = 1;
  Path::createFolder(v3);
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  v42 = -1;
  _Right._Myres = 7;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v4 = &this->car->unixName;
  if ( this->car->unixName._Myres < 8 )
    v5 = &this->car->unixName;
  else
    v5 = (std::wstring *)v4->_Bx._Ptr;
  v6._Ptr = &v5->_Bx._Buf[this->car->unixName._Mysize];
  if ( this->car->unixName._Myres >= 8 )
    v4 = (std::wstring *)v4->_Bx._Ptr;
  _Right._Myres = 7;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
    &_Right,
    (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v4,
    v6,
    __formal[0]);
  v42 = 2;
  v7 = Path::getDocumentPath(&result);
  LOBYTE(v42) = 3;
  v8 = std::operator+<wchar_t>(&v39, v7, L"/Assetto Corsa/cfg/cars/");
  LOBYTE(v42) = 4;
  v9 = std::operator+<wchar_t>(&v40, v8, &_Right);
  LOBYTE(v42) = 5;
  Path::createFolder(v9);
  if ( v40._Myres >= 8 )
    operator delete(v40._Bx._Ptr);
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  if ( v39._Myres >= 8 )
    operator delete(v39._Bx._Ptr);
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v42 = -1;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  v10 = &this->car->unixName;
  if ( this->car->unixName._Myres < 8 )
    v11 = &this->car->unixName;
  else
    v11 = (std::wstring *)v10->_Bx._Ptr;
  v12._Ptr = &v11->_Bx._Buf[this->car->unixName._Mysize];
  if ( this->car->unixName._Myres >= 8 )
    v10 = (std::wstring *)v10->_Bx._Ptr;
  _Right._Myres = 7;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
    &_Right,
    (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v10,
    v12,
    __formal[0]);
  v42 = 6;
  v13 = Path::getDocumentPath(&v40);
  LOBYTE(v42) = 7;
  v14 = std::operator+<wchar_t>(&v39, v13, L"/Assetto Corsa/cfg/cars/");
  LOBYTE(v42) = 8;
  v15 = std::operator+<wchar_t>(&result, v14, &_Right);
  LOBYTE(v42) = 9;
  std::operator+<wchar_t>(&filename, v15, L"/view.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v39._Myres >= 8 )
    operator delete(v39._Bx._Ptr);
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  if ( v40._Myres >= 8 )
    operator delete(v40._Bx._Ptr);
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  LOBYTE(v42) = 14;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  _Right._Myres = 7;
  _Right._Bx._Buf[0] = 0;
  _Right._Mysize = 0;
  std::ofstream::ofstream(&out, &filename, 2, 64, 1);
  LOBYTE(v42) = 15;
  v16 = std::operator<<<std::char_traits<char>>(&out, "[DRIVER_EYES_POSITION]");
  std::ostream::operator<<(v16, std::endl<char,std::char_traits<char>>);
  v17 = this->car;
  *(_DWORD *)&__formal[0].gap0 = std::endl<char,std::char_traits<char>>;
  _Val = (char *)LODWORD(v17->driverEyesPosition.x);
  v18 = std::operator<<<std::char_traits<char>>((std::ostream *)&out.gap0[20], "DRIVEREYES=");
  v19 = (std::ostream *)std::ostream::operator<<(v18);
  v20 = std::operator<<<std::char_traits<char>>(v19, _Val);
  v21 = (std::ostream *)std::ostream::operator<<(v20);
  v22 = std::operator<<<std::char_traits<char>>(v21, ",");
  v23 = std::ostream::operator<<(v22);
  v24 = std::ostream::operator<<(v23, ",");
  std::ostream::operator<<(v24, v32);
  v25 = std::operator<<<std::char_traits<char>>(&out, "[CAMERA]");
  std::ostream::operator<<(v25, std::endl<char,std::char_traits<char>>);
  v26 = std::operator<<<std::char_traits<char>>(&out, "ON_BOARD_PITCH_ANGLE=");
  v27 = std::ostream::operator<<(v26);
  std::ostream::operator<<(v27, v33);
  std::ofstream::close(&out);
  *(_DWORD *)v35.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v35.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v35.gap68);
  LOBYTE(v42) = 16;
  *(_DWORD *)&__formal[0].gap0 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v35, &v35.gap10[8], 0);
  v42 = 17;
  *(_DWORD *)&v35.gap0[*(_DWORD *)(*(_DWORD *)v35.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&__formal[*(_DWORD *)(*(_DWORD *)v35.gap0 + 4)].gap0 = *(_DWORD *)(*(_DWORD *)v35.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v35.gap10[8]);
  *(_DWORD *)&v35.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v35.gap10[64] = 0;
  *(_DWORD *)&v35.gap10[68] = 0;
  LOBYTE(v42) = 19;
  std::wostream::operator<<(v35.gap10, LODWORD(this->car->sim->cameraManager->cameraOnBoard->onBoardFov));
  v28 = Path::getDocumentPath(&v40);
  LOBYTE(v42) = 20;
  v29 = std::operator+<wchar_t>(&v39, v28, L"/Assetto Corsa/cfg/camera_onboard.ini");
  LOBYTE(v42) = 21;
  v30 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v35, &result);
  if ( v29->_Myres >= 8 )
    v29 = (std::wstring *)v29->_Bx._Ptr;
  if ( v30->_Myres >= 8 )
    v30 = (std::wstring *)v30->_Bx._Ptr;
  WritePrivateProfileStringW(L"MODE", L"FOV", v30->_Bx._Buf, v29->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v39._Myres >= 8 )
    operator delete(v39._Bx._Ptr);
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  if ( v40._Myres >= 8 )
    operator delete(v40._Bx._Ptr);
  *(_DWORD *)&v35.gap0[*(_DWORD *)(*(_DWORD *)v35.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&__formal[*(_DWORD *)(*(_DWORD *)v35.gap0 + 4)].gap0 = *(_DWORD *)(*(_DWORD *)v35.gap0 + 4) - 104;
  *(_DWORD *)&v35.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v35.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v35.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v35.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v35.gap68);
  std::ofstream::~ofstream<char,std::char_traits<char>>((std::ofstream *)&out.gap58[8]);
  std::ios::~ios<char,std::char_traits<char>>(&out.gap58[8]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void __userpurge DriverEyesPositioner::render(DriverEyesPositioner *this@<ecx>, int a2@<esi>, float dt)
{
  DriverEyesPositioner_vtbl *v4; // eax
  const std::wstring *v5; // eax
  void (__cdecl *v6)(void *); // eax
  std::wstring *v7; // esi
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  int v10; // edi
  std::wstring *v11; // esi
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  const wchar_t *v16; // eax
  int v17; // edi
  std::wstring *v18; // esi
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  float v23; // edi
  unsigned int v24; // esi
  int v25; // ecx
  int v26; // ecx
  Font *v27; // esi
  int v28; // ecx
  const std::wstring *v29; // eax
  int v30; // ecx
  int v31; // esi
  _DWORD *v32; // eax
  int v33; // esi
  _DWORD *v34; // eax
  int v35; // esi
  char *v36; // eax
  GLRenderer_vtbl *v37; // esi
  GLRenderer_vtbl *v38; // eax
  bool v39; // zf
  Font *v40; // ecx
  const std::wstring *v41; // eax
  void (__cdecl *v42)(void *); // esi
  void *v43; // eax
  float v44; // [esp+Ch] [ebp-1DCh]
  int y; // [esp+10h] [ebp-1D8h]
  float ascale; // [esp+1Ch] [ebp-1CCh]
  GLRenderer_vtbl *x; // [esp+2Ch] [ebp-1BCh]
  std::wstring *r; // [esp+30h] [ebp-1B8h]
  GLRenderer_vtbl *ra; // [esp+30h] [ebp-1B8h]
  GLRenderer *g; // [esp+34h] [ebp-1B4h]
  int *b; // [esp+38h] [ebp-1B0h]
  float a; // [esp+3Ch] [ebp-1ACh]
  __int64 v53; // [esp+40h] [ebp-1A8h]
  float v54; // [esp+40h] [ebp-1A8h]
  GLRenderer *v55; // [esp+48h] [ebp-1A0h]
  GLRenderer *v56; // [esp+48h] [ebp-1A0h]
  char v57[4]; // [esp+50h] [ebp-198h] BYREF
  int v58; // [esp+54h] [ebp-194h] BYREF
  int v59; // [esp+58h] [ebp-190h] BYREF
  int v60; // [esp+5Ch] [ebp-18Ch] BYREF
  GLRenderer *v61; // [esp+60h] [ebp-188h]
  float v62; // [esp+64h] [ebp-184h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v63; // [esp+68h] [ebp-180h] BYREF
  int v64; // [esp+118h] [ebp-D0h]
  __m128i v65; // [esp+11Ch] [ebp-CCh] BYREF
  std::wstring v66; // [esp+12Ch] [ebp-BCh] BYREF
  std::wstring text; // [esp+144h] [ebp-A4h] BYREF
  std::wstring result; // [esp+15Ch] [ebp-8Ch] BYREF
  std::wstring v69; // [esp+174h] [ebp-74h] BYREF
  std::wstring v70; // [esp+18Ch] [ebp-5Ch] BYREF
  std::wstring v71; // [esp+1A4h] [ebp-44h] BYREF
  unsigned int v72; // [esp+1BCh] [ebp-2Ch]
  int v73; // [esp+1C8h] [ebp-20h]
  unsigned int v74; // [esp+1CCh] [ebp-1Ch]
  char v75; // [esp+1D0h] [ebp-18h]
  int v76; // [esp+1D4h] [ebp-14h]
  int v77; // [esp+1D8h] [ebp-10h]
  int v78; // [esp+1E0h] [ebp-8h]

  v60 = (int)this;
  v61 = 0;
  v4 = this->__vftable;
  LODWORD(v53) = &v63;
  *(__m128i *)v63.gap0 = _mm_loadu_si128((const __m128i *)&this->rect);
  ((void (*)(DriverEyesPositioner *))v4->getWorldRect)(this);
  if ( this->currentFov == 0.0 )
    this->currentFov = this->car->sim->cameraManager->cameraOnBoard->onBoardFov;
  ksgui::Control::render(this, (int)this, a2, dt, v53, *(float *)&v55);
  Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
  result._Mysize = 7;
  *(_DWORD *)&result._Bx._Alias[12] = 0;
  LOWORD(text._Myres) = 0;
  std::wstring::assign((std::wstring *)&text._Myres, L"global settings", 0xFu);
  v78 = 0;
  v5 = acTranslate((std::wstring *)&result._Myres, (const std::wstring *)&text._Myres);
  LOBYTE(v78) = 1;
  Font::blitString(
    this->font._Ptr,
    (float)(this->scaleMult * 200.0) + v62,
    (float)(this->scaleMult * 45.0) + *(float *)&v63.gap0[4],
    v5,
    this->scaleMult,
    eAlignLeft);
  v6 = operator delete;
  if ( v69._Mysize >= 8 )
  {
    operator delete((void *)result._Myres);
    v6 = operator delete;
  }
  v78 = -1;
  v69._Mysize = 7;
  *(_DWORD *)&v69._Bx._Alias[12] = 0;
  LOWORD(result._Myres) = 0;
  if ( result._Mysize >= 8 )
    v6((void *)text._Myres);
  result._Mysize = 7;
  *(_DWORD *)&result._Bx._Alias[12] = 0;
  LOWORD(text._Myres) = 0;
  std::wstring::assign((std::wstring *)&text._Myres, L"settings", 8u);
  v78 = 2;
  v7 = acTranslate((std::wstring *)&v69._Myres, (const std::wstring *)&text._Myres);
  LOBYTE(v78) = 3;
  v8 = std::operator+<wchar_t>((std::wstring *)&v71._Myres, &this->car->unixName, L" ");
  LOBYTE(v78) = 4;
  v9 = std::operator+<wchar_t>((std::wstring *)&result._Myres, v8, v7);
  LOBYTE(v78) = 5;
  Font::blitString(
    this->font._Ptr,
    (float)(this->scaleMult * 200.0) + v62,
    (float)(this->scaleMult * 110.0) + *(float *)&v63.gap0[4],
    v9,
    this->scaleMult,
    eAlignLeft);
  if ( v69._Mysize >= 8 )
    operator delete((void *)result._Myres);
  v69._Mysize = 7;
  *(_DWORD *)&v69._Bx._Alias[12] = 0;
  LOWORD(result._Myres) = 0;
  if ( v74 >= 8 )
    operator delete((void *)v71._Myres);
  v74 = 7;
  v73 = 0;
  LOWORD(v71._Myres) = 0;
  if ( v70._Mysize >= 8 )
    operator delete((void *)v69._Myres);
  v78 = -1;
  v70._Mysize = 7;
  *(_DWORD *)&v70._Bx._Alias[12] = 0;
  LOWORD(v69._Myres) = 0;
  if ( result._Mysize >= 8 )
    operator delete((void *)text._Myres);
  std::shared_ptr<Font>::operator=(&this->font, &this->gui->ksgui::Form::ksgui::Control::font);
  v61 = this->gui->graphics->gl;
  *(_DWORD *)&v63.gap10[12] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)&v63.gap10[28] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(&v63.gap68[28]);
  v78 = 6;
  v60 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v63.gap10[12], &v63.gap10[36], 0);
  v77 = 7;
  *(_DWORD *)&v63.gap10[*(_DWORD *)(*(_DWORD *)&v63.gap10[4] + 4) + 4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v63.gap10[*(_DWORD *)(*(_DWORD *)&v63.gap10[4] + 4)] = *(_DWORD *)(*(_DWORD *)&v63.gap10[4] + 4) - 104;
  std::wstreambuf::wstreambuf(&v63.gap10[28]);
  *(_DWORD *)&v63.gap10[28] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v63.gap60[4] = 0;
  *(_DWORD *)v63.gap68 = 0;
  v77 = 9;
  std::wostream::operator<<(&v63.gap10[20], (int)this->car->sim->cameraManager->cameraOnBoard->onBoardFov);
  *(_QWORD *)result._Bx._Buf = 0x700000000i64;
  text._Bx._Buf[4] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[8], L"FOV", 3u);
  LOBYTE(v76) = 10;
  v10 = *((_DWORD *)this->regs._Myfirst + 1);
  v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)v63.gap10,
          (std::wstring *)&v70._Bx._Alias[8]);
  LOBYTE(v76) = 11;
  v12 = acTranslate((std::wstring *)((char *)&v65.m128i_u64[1] + 4), (const std::wstring *)&text._Bx._Alias[8]);
  LOBYTE(v76) = 12;
  v13 = std::operator+<wchar_t>((std::wstring *)&result._Bx._Alias[8], v12, L" (");
  LOBYTE(v76) = 13;
  v14 = std::operator+<wchar_t>((std::wstring *)&v71._Bx._Alias[8], v13, v11);
  LOBYTE(v76) = 14;
  v15 = std::operator+<wchar_t>((std::wstring *)&v69._Bx._Alias[8], v14, L")");
  LOBYTE(v76) = 15;
  r = v15;
  (*(void (**)(int))(*(_DWORD *)v10 + 68))(v10);
  if ( v70._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&v69._Bx._Alias[4]);
  v70._Bx._Ptr = (wchar_t *)7;
  v69._Myres = 0;
  v69._Bx._Buf[2] = 0;
  if ( v72 >= 8 )
    operator delete(*(void **)&v71._Bx._Alias[4]);
  v72 = 7;
  v71._Myres = 0;
  v71._Bx._Buf[2] = 0;
  if ( v69._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  v69._Bx._Ptr = (wchar_t *)7;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  if ( *(_DWORD *)&v66._Bx._Alias[12] >= 8u )
    operator delete((void *)v65.m128i_i32[2]);
  *(_QWORD *)&v66._Bx._Alias[8] = 0x700000000i64;
  v65.m128i_i16[4] = 0;
  if ( v71._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&v70._Bx._Alias[4]);
  v75 = 9;
  v71._Bx._Ptr = (wchar_t *)7;
  v70._Myres = 0;
  v70._Bx._Buf[2] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  *(_QWORD *)&v66._Bx._Alias[8] = 0x700000000i64;
  v65.m128i_i16[4] = 0;
  std::wstring::assign((std::wstring *)&v65.m128i_u64[1], word_17BE9D8, 0);
  v75 = 16;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v63.gap10[20]);
  v16 = &v65.m128i_u16[4];
  if ( *(_DWORD *)&v66._Bx._Alias[12] >= 8u )
    v16 = (const wchar_t *)v65.m128i_i32[2];
  std::wstringbuf::_Init((std::wstringbuf *)&v63.gap10[20], v16, *(unsigned int *)&v66._Bx._Alias[8], *(int *)v63.gap60);
  v75 = 9;
  if ( *(_DWORD *)&v66._Bx._Alias[12] >= 8u )
    operator delete((void *)v65.m128i_i32[2]);
  std::wostream::operator<<(
    &v63.gap10[12],
    (int)(float)(**(float **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v56[1].tempVertices[1].normal.z) + 172) + 208)
                                        + 76)
                            + 132)
               * 57.29578));
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"PITCH", 5u);
  LOBYTE(v74) = 17;
  v17 = *(_DWORD *)(LODWORD(v56[1].tempVertices[1].pos.z) + 8);
  v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&v63._Chcount,
          (std::wstring *)((char *)v65.m128i_i64 + 4));
  LOBYTE(v74) = 18;
  v19 = acTranslate(&result, &text);
  LOBYTE(v74) = 19;
  v20 = std::operator+<wchar_t>(&v71, v19, L" (");
  LOBYTE(v74) = 20;
  v21 = std::operator+<wchar_t>(&v69, v20, v18);
  LOBYTE(v74) = 21;
  v22 = std::operator+<wchar_t>(&v70, v21, L")");
  LOBYTE(v74) = 22;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v17 + 68))(v17, v22);
  if ( v70._Mysize >= 8 )
    operator delete((void *)v69._Myres);
  v70._Mysize = 7;
  *(_DWORD *)&v70._Bx._Alias[12] = 0;
  LOWORD(v69._Myres) = 0;
  if ( v69._Mysize >= 8 )
    operator delete((void *)result._Myres);
  v69._Mysize = 7;
  *(_DWORD *)&v69._Bx._Alias[12] = 0;
  LOWORD(result._Myres) = 0;
  if ( v71._Mysize >= 8 )
    operator delete((void *)v70._Myres);
  v71._Mysize = 7;
  *(_DWORD *)&v71._Bx._Alias[12] = 0;
  LOWORD(v70._Myres) = 0;
  if ( result._Mysize >= 8 )
    operator delete((void *)text._Myres);
  result._Mysize = 7;
  *(_DWORD *)&result._Bx._Alias[12] = 0;
  LOWORD(text._Myres) = 0;
  if ( *(_DWORD *)&v66._Bx._Alias[4] >= 8u )
    operator delete((void *)v65.m128i_i32[0]);
  LOBYTE(v73) = 9;
  *(_QWORD *)v66._Bx._Buf = 0x700000000i64;
  v65.m128i_i16[0] = 0;
  if ( text._Mysize >= 8 )
    operator delete((void *)v66._Myres);
  v23 = v54;
  *(float *)&v24 = 0.0;
  if ( (*(_DWORD *)(LODWORD(v54) + 356) - *(_DWORD *)(LODWORD(v54) + 352)) >> 2 )
  {
    do
    {
      GLRenderer::color4f(v56, 1.0, 1.0, 1.0, 1.0);
      v25 = *(_DWORD *)(LODWORD(v23) + 352);
      v65 = _mm_loadu_si128((const __m128i *)(*(_DWORD *)(*(_DWORD *)(v25 + 4 * v24) + 284) + 28));
      v26 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * v24) + 284);
      (*(void (**)(int, __m128i *))(*(_DWORD *)v26 + 24))(v26, &v65);
      a = *(float *)(LODWORD(v23) + 256) * 108.0;
      GLRenderer::quad(
        0,
        *(float *)(LODWORD(v23) + 256) + *(float *)v65.m128i_i32,
        *(float *)&v65.m128i_i32[1],
        a - (float)(*(float *)(LODWORD(v23) + 256) * 2.0),
        *(float *)(LODWORD(v23) + 256) * 21.0,
        0,
        0);
      Font::setColor(*(Font **)(LODWORD(v23) + 128), 0.0, 0.0, 0.0, 1.0);
      v27 = *(Font **)(LODWORD(v23) + 128);
      v28 = *(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 352) + 4 * LODWORD(v54));
      ascale = *(float *)(LODWORD(v23) + 256) * 0.85000002;
      v29 = (const std::wstring *)(*(int (**)(int))(*(_DWORD *)v28 + 72))(v28);
      Font::blitString(
        v27,
        (float)(a * 0.5) + *(float *)v65.m128i_i32,
        *(float *)&v65.m128i_i32[1],
        v29,
        ascale,
        eAlignCenter);
      v24 = LODWORD(v54) + 1;
      v54 = *(float *)&v24;
    }
    while ( v24 < (*(_DWORD *)(LODWORD(v23) + 356) - *(_DWORD *)(LODWORD(v23) + 352)) >> 2 );
  }
  v30 = *(_DWORD *)(LODWORD(v23) + 320);
  *(float *)(LODWORD(v23) + 368) = *(float *)(LODWORD(v23) + 372) * dt;
  if ( (*(unsigned __int8 (**)(int))(*(_DWORD *)v30 + 36))(v30) )
  {
    LODWORD(v54) = *(_DWORD *)(LODWORD(v23) + 320) + 156;
    v31 = *(_DWORD *)LODWORD(v54);
    if ( *(_DWORD *)LODWORD(v54) != *(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 320) + 160) )
    {
      v32 = (_DWORD *)(v31 + 24);
      LODWORD(a) = v31 + 24;
      while ( *v32 )
      {
        (*(void (**)(_DWORD, int *))(*(_DWORD *)*v32 + 8))(*v32, &v60);
        v31 += 32;
        v32 = b + 8;
        b += 8;
        if ( v31 == *(_DWORD *)(LODWORD(a) + 4) )
          goto LABEL_50;
      }
      goto LABEL_70;
    }
  }
LABEL_50:
  if ( (*(unsigned __int8 (**)(_DWORD))(**(_DWORD **)(LODWORD(v23) + 324) + 36))(*(_DWORD *)(LODWORD(v23) + 324)) )
  {
    LODWORD(a) = *(_DWORD *)(LODWORD(v23) + 324) + 156;
    v33 = *(_DWORD *)LODWORD(a);
    if ( *(_DWORD *)LODWORD(a) != *(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 324) + 160) )
    {
      v34 = (_DWORD *)(v33 + 24);
      b = (int *)(v33 + 24);
      while ( *v34 )
      {
        (*(void (**)(_DWORD, int *))(*(_DWORD *)*v34 + 8))(*v34, &v59);
        v33 += 32;
        v34 = (_DWORD *)&g->color.y;
        g = (GLRenderer *)((char *)g + 32);
        if ( v33 == b[1] )
          goto LABEL_55;
      }
      goto LABEL_70;
    }
  }
LABEL_55:
  if ( (*(unsigned __int8 (**)(_DWORD))(**(_DWORD **)(LODWORD(v23) + 328) + 36))(*(_DWORD *)(LODWORD(v23) + 328)) )
  {
    b = (int *)(*(_DWORD *)(LODWORD(v23) + 328) + 156);
    v35 = *b;
    if ( *b != *(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 328) + 160) )
    {
      v36 = (char *)(v35 + 24);
      g = (GLRenderer *)(v35 + 24);
      while ( *(_DWORD *)v36 )
      {
        (*(void (**)(_DWORD, int *))(**(_DWORD **)v36 + 8))(*(_DWORD *)v36, &v58);
        v35 += 32;
        v36 = &r[1]._Bx._Alias[8];
        r = (std::wstring *)((char *)r + 32);
        if ( (std::pair<int,void *> *)v35 == g->buffers._Myfirst )
          goto LABEL_60;
      }
      goto LABEL_70;
    }
  }
LABEL_60:
  if ( (*(unsigned __int8 (**)(_DWORD))(**(_DWORD **)(LODWORD(v23) + 332) + 36))(*(_DWORD *)(LODWORD(v23) + 332)) )
  {
    g = (GLRenderer *)(*(_DWORD *)(LODWORD(v23) + 332) + 156);
    v37 = g->__vftable;
    if ( g->__vftable != *(GLRenderer_vtbl **)(*(_DWORD *)(LODWORD(v23) + 332) + 160) )
    {
      v38 = v37 + 6;
      ra = v37 + 6;
      while ( v38->~GLRenderer )
      {
        (*(void (**)(void (*)(GLRenderer *), char *))(*(_DWORD *)v38->~GLRenderer + 8))(
          v38->~GLRenderer,
          v57);
        v37 += 8;
        v38 = x + 8;
        x += 8;
        if ( v37 == (GLRenderer_vtbl *)ra[1].~GLRenderer )
          goto LABEL_65;
      }
LABEL_70:
      std::_Xbad_function_call();
      goto $LN1456;
    }
  }
LABEL_65:
  v39 = *(_BYTE *)(LODWORD(v23) + 456) == 0;
  v40 = *(Font **)(LODWORD(v23) + 128);
  y = 1065353216;
  v44 = 0.0;
  *(_DWORD *)(LODWORD(v23) + 452) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 364) + 172)
                                                                      + 208)
                                                          + 76)
                                              + 92);
  if ( !v39 )
  {
    Font::setColor(v40, 1.0, 0.0, 0.0, 1.0);
    v66._Myres = 7;
    v66._Mysize = 0;
    v66._Bx._Buf[0] = 0;
    std::wstring::assign(&v66, L"Save Needed", 0xBu);
    LOBYTE(v71._Mysize) = 23;
    v41 = acTranslate(&v69, &v66);
    LOBYTE(v71._Mysize) = 24;
    Font::blitString(
      *(Font **)(LODWORD(v23) + 128),
      (float)((float)(a - *(float *)&b) * 0.5) + *(float *)&b,
      (float)((float)(0.0 - v54) + v54) - (float)(*(float *)(LODWORD(v23) + 256) * 50.0),
      v41,
      *(float *)(LODWORD(v23) + 256),
      eAlignCenter);
    v42 = operator delete;
    if ( v69._Myres >= 8 )
      operator delete(v69._Bx._Ptr);
    LOBYTE(v71._Mysize) = 9;
    v69._Myres = 7;
    v69._Mysize = 0;
    v69._Bx._Buf[0] = 0;
    if ( v66._Myres >= 8 )
      operator delete(v66._Bx._Ptr);
    goto LABEL_74;
  }
$LN1456:
  Font::setColor(v40, 0.0, 1.0, v44, *(float *)&y);
  v65.m128i_i32[0] = 7;
  v64 = 0;
  *(_WORD *)&v63.gap68[56] = 0;
  std::wstring::assign((std::wstring *)&v63.gap68[56], word_17BE9D8, 0);
  LOBYTE(v71._Mysize) = 25;
  Font::blitString(
    *(Font **)(LODWORD(v23) + 128),
    (float)((float)(a - *(float *)&b) * 0.5) + *(float *)&b,
    (float)((float)(0.0 - v54) + v54) - (float)(*(float *)(LODWORD(v23) + 256) * 50.0),
    (const std::wstring *)&v63.gap68[56],
    *(float *)(LODWORD(v23) + 256),
    eAlignCenter);
  LOBYTE(v71._Mysize) = 9;
  v42 = operator delete;
  if ( v65.m128i_i32[0] >= 8u )
    operator delete(*(void **)&v63.gap68[56]);
  v65.m128i_i32[0] = 7;
  v64 = 0;
  *(_WORD *)&v63.gap68[56] = 0;
LABEL_74:
  if ( GetAsyncKeyState(17) )
  {
    GLRenderer::begin(g, eLines, 0);
    GLRenderer::color3f(g, 1.0, 0.0, 1.0);
    GLRenderer::vertex3f(g, (float)*(int *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 240) + 8) + 20) * 0.5, 0.0, 0.0);
    GLRenderer::vertex3f(
      g,
      (float)*(int *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 240) + 8) + 20) * 0.5,
      (float)*(int *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v23) + 240) + 8) + 24),
      0.0);
    GLRenderer::end(g);
  }
  v71._Mysize = -1;
  *(int *)((char *)&v59 + *(_DWORD *)(v59 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v58 + *(_DWORD *)(v59 + 4)) = *(_DWORD *)(v59 + 4) - 104;
  LODWORD(v63._Chcount) = &std::wstringbuf::`vftable';
  if ( (v63.gap10[52] & 1) != 0 )
  {
    if ( **(_DWORD **)&v63.gap10[24] )
      std::wstreambuf::epptr(&v63._Chcount);
    else
      std::wstreambuf::egptr(&v63._Chcount);
    std::wstreambuf::eback(&v63._Chcount);
    v43 = (void *)std::wstreambuf::eback(&v63._Chcount);
    v42(v43);
  }
  std::wstreambuf::setg(&v63._Chcount, 0, 0, 0);
  std::wstreambuf::setp(&v62, 0, 0);
  *(_DWORD *)&v63.gap10[32] &= 0xFFFFFFFE;
  *(_DWORD *)&v63.gap10[28] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v60);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v62);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&v63.gap10[52]);
}
void DriverEyesPositioner::onRenderFinished(DriverEyesPositioner *this, const OnNodeRenderEvent *ev)
{
  GraphicsManager *v3; // ecx
  GLRenderer *v4; // esi
  const mat44f *v5; // eax
  float v6; // xmm1_4
  vec3f wp; // [esp+1Ch] [ebp-58h] BYREF
  vec3f v; // [esp+28h] [ebp-4Ch] BYREF
  mat44f result; // [esp+34h] [ebp-40h] BYREF

  if ( this->visible
    && ev->renderContext->meshFilter->passID == Opaque
    && !ACCameraManager::isCameraOnBoard(this->car->sim->cameraManager, this->car) )
  {
    DriverModel::getEyesPosition(this->car->driverModel_HR, &wp);
    v3 = this->gui->graphics;
    v4 = v3->gl;
    GraphicsManager::setDepthMode(v3, eDepthOff);
    v5 = mat44f::createIdentity(&result);
    GraphicsManager::setWorldMatrix(this->gui->graphics, v5);
    GLRenderer::begin(v4, eLines, 0);
    GLRenderer::color3f(v4, 0.0, 2.0, 2.0);
    v6 = this->scaleMult * 0.050000001;
    v.x = wp.x;
    v.y = wp.y + v6;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    v.x = wp.x;
    v.y = wp.y - v6;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    v.x = wp.x + v6;
    v.y = wp.y;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    v.x = wp.x - v6;
    v.y = wp.y;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    *(_QWORD *)&v.x = *(_QWORD *)&wp.x;
    v.z = wp.z + v6;
    GLRenderer::vertex3fv(v4, &v.x);
    *(_QWORD *)&v.x = *(_QWORD *)&wp.x;
    v.z = wp.z - v6;
    GLRenderer::vertex3fv(v4, &v.x);
    wp = *Node::localToWorld(this->car->bodyTransform, &v, &this->car->driverEyesPosition);
    GLRenderer::color3f(v4, 2.0, 1.0, 0.0);
    v.x = wp.x;
    v.y = wp.y + v6;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    v.x = wp.x;
    v.y = wp.y - v6;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    v.x = wp.x + v6;
    v.y = wp.y;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    v.x = wp.x - v6;
    v.y = wp.y;
    v.z = wp.z;
    GLRenderer::vertex3fv(v4, &v.x);
    *(_QWORD *)&v.x = *(_QWORD *)&wp.x;
    v.z = wp.z + v6;
    GLRenderer::vertex3fv(v4, &v.x);
    *(_QWORD *)&v.x = *(_QWORD *)&wp.x;
    v.z = wp.z - v6;
    GLRenderer::vertex3fv(v4, &v.x);
    GLRenderer::end(v4);
    GraphicsManager::setDepthMode(this->gui->graphics, eDepthNormal);
  }
}
void DriverEyesPositioner::~DriverEyesPositioner(DriverEyesPositioner *this)
{
  this->__vftable = (DriverEyesPositioner_vtbl *)&DriverEyesPositioner::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->textRight);
  OnSetupAppCreated::~OnSetupAppCreated(&this->textLeft);
  if ( this->regs._Myfirst )
  {
    operator delete(this->regs._Myfirst);
    this->regs._Myfirst = 0;
    this->regs._Mylast = 0;
    this->regs._Myend = 0;
  }
  this->__vftable = (DriverEyesPositioner_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
