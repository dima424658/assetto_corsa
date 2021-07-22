#include "formai.h
void FormAI::FormAI(FormAI *this, Sim *isim)
{
  int v3; // ebx
  Sim *v4; // ecx
  unsigned int v5; // eax
  CarAvatar *v6; // eax
  ICarControlsProvider *v7; // eax
  AIDriver *v8; // eax
  Sim *v9; // ecx
  TrackAvatar *v10; // eax
  AISpline *v11; // eax
  void *(__cdecl *v12)(unsigned int); // ebp
  ksgui::Graph *v13; // eax
  ksgui::Graph *v14; // ecx
  ksgui::Graph *v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  ksgui::Graph *v21; // ecx
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  ksgui::Graph *v25; // eax
  bool v26; // cf
  ksgui::Control *v27; // eax
  ksgui::Control *v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  ksgui::Control *v34; // eax
  const std::wstring *v35; // eax
  ksgui::Control *v36; // eax
  ksgui::Control *v37; // ecx
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  const std::wstring *v43; // eax
  ksgui::Control *v44; // eax
  ksgui::Control *v45; // ecx
  float v46; // xmm0_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  const std::wstring *v51; // eax
  CarAvatar **v52; // eax
  CarAvatar *v53; // eax
  CarAudioFMOD *v54; // ebp
  CarAvatar *v55; // eax
  CarAudioFMOD *v56; // eax
  CarAudioFMOD *v57; // ebp
  float v58; // xmm0_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  ksgui::Label *v63; // eax
  ksgui::Label *v64; // ecx
  ksgui::Label *v65; // ecx
  float v66; // xmm0_4
  float v67; // xmm2_4
  float v68; // xmm3_4
  float v69; // xmm2_4
  float v70; // xmm3_4
  ksgui::Label *v71; // eax
  ksgui::Label *v72; // ecx
  ksgui::Label *v73; // ecx
  float v74; // xmm0_4
  float v75; // xmm2_4
  float v76; // xmm3_4
  float v77; // xmm2_4
  float v78; // xmm3_4
  CarAudioFMOD *v79; // ebp
  int v80; // eax
  int v81; // ebp
  float v82; // xmm0_4
  float v83; // xmm2_4
  float v84; // xmm3_4
  float v85; // xmm2_4
  float v86; // xmm3_4
  int v87; // ebx
  const std::wstring *v88; // eax
  ksgui::Spinner *v89; // eax
  ksgui::Spinner *v90; // eax
  int v91; // ebx
  const std::wstring *v92; // eax
  ksgui::Spinner *v93; // eax
  ksgui::Spinner *v94; // eax
  int v95; // ebx
  const std::wstring *v96; // eax
  ksgui::Spinner *v97; // eax
  ksgui::Spinner *v98; // eax
  int v99; // ebx
  const std::wstring *v100; // eax
  ksgui::Spinner *v101; // eax
  ksgui::Spinner *v102; // eax
  int v103; // ebx
  const std::wstring *v104; // eax
  ksgui::Spinner *v105; // eax
  ksgui::Spinner *v106; // eax
  ksgui::Spinner *v107; // eax
  CarAudioFMOD *v108; // esi
  int v109; // ebx
  const std::wstring *v110; // eax
  ksgui::Spinner *v111; // eax
  ksgui::Spinner *v112; // eax
  FormAI::{ctor}::__l61::<lambda_5694703b5c7ac5d2cbb6c09c8b7f593d> *v113; // eax
  CarAudioFMOD *v114; // esi
  int v115; // ebx
  const std::wstring *v116; // eax
  ksgui::Spinner *v117; // eax
  ksgui::Spinner *v118; // eax
  FormAI::{ctor}::__l65::<lambda_4c36825b83bed81dee180c9bd5e633af> *v119; // eax
  CarAudioFMOD *v120; // esi
  ksgui::Control *v121; // eax
  const std::wstring *v122; // eax
  FormAI::{ctor}::__l75::<lambda_08d5c279d5c624a1985c56ed4fe77111> *v123; // eax
  CarAudioFMOD *v124; // esi
  int v125; // ebx
  const std::wstring *v126; // eax
  ksgui::Spinner *v127; // eax
  ksgui::Spinner *v128; // eax
  FormAI::{ctor}::__l79::<lambda_cf515479f4f9b277bee4a18202bc4130> *v129; // eax
  CarAudioFMOD *v130; // esi
  ksgui::Control *v131; // eax
  FormAI::{ctor}::__l83::<lambda_30161f25a4bf4c58baa13fc3444faf5f> *v132; // eax
  Console *v133; // eax
  FormAI::{ctor}::__l87::<lambda_5032e6488a505c02ac6e91fadc12f8ff> *v134; // eax
  Console *v135; // eax
  FormAI::{ctor}::__l91::<lambda_f15c06616ae14ad5acca2d6b7d54f0dd> *v136; // eax
  Console *v137; // eax
  FormAI::{ctor}::__l95::<lambda_c504270dae932f09fa6cbc52e2deb9b3> *v138; // eax
  Console *v139; // eax
  FormAI::{ctor}::__l99::<lambda_b4fde1976c00f1ba3517b7430015925a> *v140; // eax
  Console *v141; // eax
  std::wstring v142; // [esp+94h] [ebp-134h] BYREF
  _BYTE h[72]; // [esp+ACh] [ebp-11Ch] BYREF
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v144[2]; // [esp+108h] [ebp-C0h] BYREF
  int v145; // [esp+110h] [ebp-B8h]
  __int64 v146; // [esp+114h] [ebp-B4h] BYREF
  std::vector<CarAvatar *> cars; // [esp+11Ch] [ebp-ACh] BYREF
  FormAI *v148; // [esp+128h] [ebp-A0h]
  std::wstring key; // [esp+12Ch] [ebp-9Ch] BYREF
  std::wstring section; // [esp+144h] [ebp-84h] BYREF
  std::wstring inifile; // [esp+15Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+174h] [ebp-54h] BYREF
  int v153; // [esp+1C4h] [ebp-4h]

  v3 = 0;
  v144[0].__this = 0;
  *(_DWORD *)&h[28] = 0;
  v148 = this;
  *(_DWORD *)&h[24] = isim->game->gui;
  *(_DWORD *)&h[20] = 7;
  *(_DWORD *)&h[16] = 0;
  *(_WORD *)h = 0;
  std::wstring::assign((std::wstring *)h, L"FORM_AI", 7u);
  ksgui::Form::Form(this, 0, *(std::wstring *)h, *(ksgui::GUI **)&h[24], h[28]);
  v153 = 0;
  this->__vftable = (FormAI_vtbl *)&FormAI::`vftable';
  this->sim = isim;
  this->currentTargetOffset = 0.0;
  this->currentOffset = 0.0;
  this->smallFont._Myptr = 0;
  LOBYTE(v153) = 1;
  *(_DWORD *)&h[28] = 2;
  this->maxOutsideOffset = 0.0;
  *(_DWORD *)&h[24] = L"AI";
  *(_WORD *)&this->autoFuelSaveCons = 0;
  this->autoFuelTime = 0.0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, *(const wchar_t **)&h[24], *(unsigned int *)&h[28]);
  LOBYTE(v153) = 2;
  this->formTitle->setText(this->formTitle, &section);
  LOBYTE(v153) = 1;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v4 = this->sim;
  *(_DWORD *)&h[28] = 0;
  *(_DWORD *)&h[24] = &AIDriver `RTTI Type Descriptor';
  *(_DWORD *)&h[20] = &ICarControlsProvider `RTTI Type Descriptor';
  *(_DWORD *)&h[16] = 0;
  v5 = Sim::getFocusedCarIndex(v4);
  v6 = Sim::getCar(this->sim, v5);
  v7 = CarAvatar::getControlsProvider(v6);
  v8 = (AIDriver *)__RTDynamicCast(v7, *(_DWORD *)&h[16], *(_DWORD *)&h[20], *(_DWORD *)&h[24], *(_DWORD *)&h[28]);
  v9 = this->sim;
  this->aiDriver = v8;
  this->interpolationDensity = 5000.0;
  this->previousCP = 0;
  this->aiActive = 0;
  v10 = GameObject::getGameObject<TrackAvatar>(v9);
  v11 = TrackAvatar::getAISpline(v10);
  v12 = operator new;
  *(_DWORD *)&h[28] = 320;
  this->aiSpline = v11;
  v144[0].__this = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v153) = 3;
  if ( v144[0].__this )
  {
    *(_DWORD *)&h[28] = this->gui;
    *(_DWORD *)&h[24] = 7;
    *(_DWORD *)&h[20] = 0;
    *(_WORD *)&h[4] = 0;
    std::wstring::assign((std::wstring *)&h[4], L"SPEED_GRAPH", 0xBu);
    ksgui::Graph::Graph((ksgui::Graph *)v144[0].__this, *(std::wstring *)&h[4], *(ksgui::GUI **)&h[28]);
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  LOBYTE(v153) = 1;
  this->speedGraph = v14;
  ((void (*)(ksgui::Graph *, int, int))v14->setSize)(v14, 1133576192, 1120403456);
  v15 = this->speedGraph;
  v16 = v15->rectBase.left;
  v17 = v15->rect.right - v15->rect.left;
  v18 = v15->rect.bottom - v15->rect.top;
  v15->rect.top = 30.0;
  v15->rect.left = 5.0;
  v19 = v17 + 5.0;
  v20 = v18 + 30.0;
  v15->rect.right = v19;
  v15->rect.bottom = v20;
  if ( v16 == 0.0 && v15->rectBase.top == 0.0 )
  {
    v15->rectBase.left = 5.0;
    v15->rectBase.top = 30.0;
    v15->rectBase.right = v19;
    v15->rectBase.bottom = v20;
  }
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->speedGraph;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&section._Bx._Alias[8] = 0;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  *(_QWORD *)&h[20] = _mm_unpacklo_ps((__m128)0i64, (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
  *(_DWORD *)&h[28] = *(_DWORD *)&section._Bx._Alias[8];
  v21 = this->speedGraph;
  v146 = LODWORD(FLOAT_1_0);
  ksgui::Graph::addSerie(v21, *(__int128 *)&h[20]);
  *(_DWORD *)&section._Bx._Alias[8] = 0;
  *(_QWORD *)&h[20] = _mm_unpacklo_ps((__m128)(unsigned int)v146, (__m128)0i64).m128_u64[0];
  *(_DWORD *)&h[28] = 0;
  ksgui::Graph::addSerie(this->speedGraph, *(__int128 *)&h[20]);
  *(_DWORD *)&section._Bx._Alias[8] = 1065353216;
  v22 = _mm_unpacklo_ps((__m128)(unsigned int)v146, (__m128)0i64);
  *(_QWORD *)&h[20] = v22.m128_u64[0];
  *(_DWORD *)&h[28] = 1065353216;
  ksgui::Graph::addSerie(this->speedGraph, *(__int128 *)&h[20]);
  v23 = (__m128)_mm_loadl_epi64((const __m128i *)&v146);
  *(_DWORD *)&section._Bx._Alias[8] = 0;
  v22.m128_f32[0] = v23.m128_f32[0];
  *(_QWORD *)&h[20] = _mm_unpacklo_ps(v22, v23).m128_u64[0];
  *(_DWORD *)&h[28] = 0;
  ksgui::Graph::addSerie(this->speedGraph, *(__int128 *)&h[20]);
  v24 = (__m128)_mm_loadl_epi64((const __m128i *)&v146);
  *(_DWORD *)&section._Bx._Alias[8] = 1065353216;
  *(_QWORD *)&h[20] = _mm_unpacklo_ps(v24, v24).m128_u64[0];
  *(_DWORD *)&h[28] = 1065353216;
  ksgui::Graph::addSerie(this->speedGraph, *(__int128 *)&h[20]);
  v25 = this->speedGraph;
  *(_DWORD *)&h[28] = 28;
  *(_DWORD *)&h[24] = L"system/cfg/assetto_corsa.ini";
  v25->minY = 0.0;
  this->speedGraph->maxY = 60.0;
  this->speedGraph->maxValuesCount = 300;
  inifile._Myres = 7;
  inifile._Mysize = 0;
  inifile._Bx._Buf[0] = 0;
  std::wstring::assign(&inifile, *(const wchar_t **)&h[24], *(unsigned int *)&h[28]);
  LOBYTE(v153) = 4;
  INIReader::INIReader(&ini, &inifile);
  LOBYTE(v153) = 5;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"AUTO_FUEL_CONS", 0xEu);
    LOBYTE(v153) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AC_APPS", 7u);
    LOBYTE(v153) = 7;
    HIBYTE(v145) = INIReader::hasKey(&ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v153) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( HIBYTE(v145) )
    {
      std::wstring::wstring(&section, L"AUTO_FUEL_CONS");
      LOBYTE(v153) = 8;
      std::wstring::wstring(&key, L"AC_APPS");
      LOBYTE(v153) = 9;
      *(float *)&v144[0].__this = INIReader::getFloat(&ini, &key, &section);
      v26 = key._Myres < 8;
      this->autoFuelSaveCons = *(float *)&v144[0].__this > 0.0;
      if ( !v26 )
        operator delete(key._Bx._Ptr);
      LOBYTE(v153) = 5;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
  }
  v144[1].__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v153) = 10;
  if ( v144[1].__this )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BEGIN_FAST", 0xAu);
    LOBYTE(v153) = 11;
    *(_DWORD *)&h[28] = this->gui;
    v3 = 1;
    v144[0].__this = (CarAudioFMOD *)1;
    ksgui::Control::Control((ksgui::Control *)v144[1].__this, &key, *(ksgui::GUI **)&h[28]);
  }
  else
  {
    v27 = 0;
  }
  this->butStartRecording = v27;
  v153 = 5;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  ((void (*)(ksgui::Control *, int, int))this->butStartRecording->setSize)(
    this->butStartRecording,
    1128792064,
    1103626240);
  v28 = this->butStartRecording;
  v29 = v28->rectBase.left;
  v30 = v28->rect.right - v28->rect.left;
  v31 = v28->rect.bottom - v28->rect.top;
  v28->rect.top = 140.0;
  v28->rect.left = 50.0;
  v32 = v30 + 50.0;
  v33 = v31 + 140.0;
  v28->rect.right = v32;
  v28->rect.bottom = v33;
  if ( v29 == 0.0 && v28->rectBase.top == 0.0 )
  {
    v28->rectBase.left = 50.0;
    v28->rectBase.top = 140.0;
    v28->rectBase.right = v32;
    v28->rectBase.bottom = v33;
  }
  v34 = this->butStartRecording;
  *(_DWORD *)&h[28] = 15;
  *(_DWORD *)&h[24] = L"start recording";
  key._Myres = 7;
  v34->tag = 0;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, *(const wchar_t **)&h[24], *(unsigned int *)&h[28]);
  LOBYTE(v153) = 13;
  v35 = acTranslate(&section, &key);
  LOBYTE(v153) = 14;
  this->butStartRecording->setText(this->butStartRecording, v35);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  LOBYTE(v153) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->butStartRecording;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = this;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_adeba99c56f52cf1e5384ee95e8b8735_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butStartRecording->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&h[4],
    *(void **)&h[28]);
  v144[1].__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v153) = 16;
  if ( v144[1].__this )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BEGIN_PITS", 0xAu);
    LOBYTE(v153) = 17;
    *(_DWORD *)&h[28] = this->gui;
    v3 |= 2u;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Control::Control((ksgui::Control *)v144[1].__this, &key, *(ksgui::GUI **)&h[28]);
  }
  else
  {
    v36 = 0;
  }
  this->butStartPitLane = v36;
  v153 = 5;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  ((void (*)(ksgui::Control *, int, int))this->butStartPitLane->setSize)(
    this->butStartPitLane,
    1128792064,
    1103626240);
  v37 = this->butStartPitLane;
  v38 = v37->rectBase.left;
  v39 = v37->rect.right - v37->rect.left;
  v40 = v37->rect.bottom - v37->rect.top;
  v37->rect.top = 170.0;
  v37->rect.left = 50.0;
  v41 = v39 + 50.0;
  v42 = v40 + 170.0;
  v37->rect.right = v41;
  v37->rect.bottom = v42;
  if ( v38 == 0.0 && v37->rectBase.top == 0.0 )
  {
    v37->rectBase.left = 50.0;
    v37->rectBase.top = 170.0;
    v37->rectBase.right = v41;
    v37->rectBase.bottom = v42;
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_7c6bf41c2a5678b461414b6b53929a12_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butStartPitLane->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&h[4],
    this);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"start pits", 0xAu);
  LOBYTE(v153) = 20;
  v43 = acTranslate(&section, &key);
  LOBYTE(v153) = 21;
  this->butStartPitLane->setText(this->butStartPitLane, v43);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  LOBYTE(v153) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->butStartPitLane;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = 280;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v144[1].__this = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v153) = 22;
  if ( v144[1].__this )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SAVE_CONS", 9u);
    LOBYTE(v153) = 23;
    *(_DWORD *)&h[28] = this->gui;
    v3 |= 4u;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Control::Control((ksgui::Control *)v144[1].__this, &key, *(ksgui::GUI **)&h[28]);
  }
  else
  {
    v44 = 0;
  }
  this->butSaveCons = v44;
  v153 = 5;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  ((void (*)(ksgui::Control *, int, int))this->butSaveCons->setSize)(
    this->butSaveCons,
    1128792064,
    1103626240);
  v45 = this->butSaveCons;
  v46 = v45->rectBase.left;
  v47 = v45->rect.right - v45->rect.left;
  v48 = v45->rect.bottom - v45->rect.top;
  v45->rect.top = 200.0;
  v45->rect.left = 50.0;
  v49 = v47 + 50.0;
  v50 = v48 + 200.0;
  v45->rect.right = v49;
  v45->rect.bottom = v50;
  if ( v46 == 0.0 && v45->rectBase.top == 0.0 )
  {
    v45->rectBase.left = 50.0;
    v45->rectBase.top = 200.0;
    v45->rectBase.right = v49;
    v45->rectBase.bottom = v50;
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_c78bc8669a69e8a8e9fccb19fcacfe36_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSaveCons->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&h[4],
    this);
  std::wstring::wstring(&section, L"save cons");
  LOBYTE(v153) = 26;
  v51 = acTranslate(&key, &section);
  LOBYTE(v153) = 27;
  this->butSaveCons->setText(this->butSaveCons, v51);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LOBYTE(v153) = 5;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->butSaveCons;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = 1144586240;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  ksgui::Form::setSize(this, 400.0, *(float *)&h[28]);
  GameObject::getGameObjects<CarAvatar>(this->sim, &cars);
  LOBYTE(v153) = 28;
  v52 = cars._Myfirst;
  this->car = 0;
  if ( v52 != cars._Mylast )
  {
    v53 = *v52;
    *(_DWORD *)&h[28] = 344;
    this->car = v53;
    v54 = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
    v144[1].__this = v54;
    LOBYTE(v153) = 29;
    if ( v54 )
    {
      std::wstring::wstring(&key, L"LAT_OFF");
      LOBYTE(v153) = 30;
      v3 |= 8u;
      v55 = this->car;
      v144[0].__this = (CarAudioFMOD *)v3;
      ksgui::ConnectedLabel::ConnectedLabel(
        (ksgui::ConnectedLabel *)v54,
        &key,
        this->gui,
        &v55->aiState.targetLateralOffset);
      v57 = v56;
    }
    else
    {
      v57 = 0;
    }
    v153 = 28;
    if ( (v3 & 8) != 0 )
    {
      v3 &= 0xFFFFFFF7;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
    }
    ((void (*)(CarAudioFMOD *, int, int))v57->__vftable[1].update)(v57, 1128792064, 1103626240);
    v58 = *(float *)&v57->engineIntEvent.instance;
    v59 = *(float *)&v57->isActive - *(float *)&v57->name._Myres;
    v60 = *(float *)&v57->gameObjects._Myfirst - *(float *)&v57->parent;
    v57->parent = (GameObject *)1131413504;
    v57->name._Myres = 1112014848;
    v61 = v59 + 50.0;
    v62 = v60 + 240.0;
    *(float *)&v57->isActive = v61;
    *(float *)&v57->gameObjects._Myfirst = v62;
    if ( v58 == 0.0 && v57->engineIntEvent.basePitch == 0.0 )
    {
      v57->engineIntEvent.instance = (FMOD::Studio::EventInstance *)1112014848;
      v57->engineIntEvent.basePitch = 240.0;
      v57->engineIntEvent.baseVolume = v61;
      *(float *)&v57->engineIntEvent.path._Bx._Ptr = v62;
    }
    v144[0].__this = v57;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
    v12 = operator new;
    *(_DWORD *)&h[28] = 284;
    v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
    v144[1].__this = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
    LOBYTE(v153) = 32;
    if ( v144[1].__this )
    {
      *(_DWORD *)&h[28] = this->gui;
      std::wstring::wstring((std::wstring *)&h[4], L"BR_TARGET");
      ksgui::Label::Label((ksgui::Label *)v144[1].__this, *(std::wstring *)&h[4], *(ksgui::GUI **)&h[28]);
      v64 = v63;
    }
    else
    {
      v64 = 0;
    }
    LOBYTE(v153) = 28;
    this->lblBrakeTarget = v64;
    ((void (*)(ksgui::Label *, int, int))v64->setSize)(v64, 1128792064, 1103626240);
    v65 = this->lblBrakeTarget;
    v66 = v65->rectBase.left;
    v67 = v65->rect.right - v65->rect.left;
    v68 = v65->rect.bottom - v65->rect.top;
    v65->rect.top = 265.0;
    v65->rect.left = 50.0;
    v69 = v67 + 50.0;
    v70 = v68 + 265.0;
    v65->rect.right = v69;
    v65->rect.bottom = v70;
    if ( v66 == 0.0 && v65->rectBase.top == 0.0 )
    {
      v65->rectBase.left = 50.0;
      v65->rectBase.top = 265.0;
      v65->rectBase.right = v69;
      v65->rectBase.bottom = v70;
    }
    v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->lblBrakeTarget;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
    v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  }
  v144[1].__this = (CarAudioFMOD *)v12(0x11Cu);
  LOBYTE(v153) = 33;
  if ( v144[1].__this )
  {
    *(_DWORD *)&h[28] = this->gui;
    std::wstring::wstring((std::wstring *)&h[4], L"LABEL_NSP");
    ksgui::Label::Label((ksgui::Label *)v144[1].__this, *(std::wstring *)&h[4], *(ksgui::GUI **)&h[28]);
    v72 = v71;
  }
  else
  {
    v72 = 0;
  }
  LOBYTE(v153) = 28;
  this->lblNSP = v72;
  ((void (*)(ksgui::Label *, int, int))v72->setSize)(v72, 1128792064, 1103626240);
  v73 = this->lblNSP;
  v74 = v73->rectBase.left;
  v75 = v73->rect.right - v73->rect.left;
  v76 = v73->rect.bottom - v73->rect.top;
  v73->rect.top = 295.0;
  v73->rect.left = 300.0;
  v77 = v75 + 300.0;
  v78 = v76 + 295.0;
  v73->rect.right = v77;
  v73->rect.bottom = v78;
  if ( v74 == 0.0 && v73->rectBase.top == 0.0 )
  {
    v73->rectBase.left = 300.0;
    v73->rectBase.top = 295.0;
    v73->rectBase.right = v77;
    v73->rectBase.bottom = v78;
  }
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->lblNSP;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = this;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_8af09c7faabdfe802f8b8af6f7fe171d_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 28;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->sim->renderFinishedNodeEvent->evOnRender,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v79 = (CarAudioFMOD *)v12(0x118u);
  v144[1].__this = v79;
  LOBYTE(v153) = 35;
  if ( v79 )
  {
    std::wstring::wstring(&key, L"magic");
    LOBYTE(v153) = 36;
    *(_DWORD *)&h[28] = this->gui;
    v3 |= 0x10u;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Control::Control((ksgui::Control *)v79, &key, *(ksgui::GUI **)&h[28]);
    v81 = v80;
  }
  else
  {
    v81 = 0;
  }
  v153 = 28;
  if ( (v3 & 0x10) != 0 )
  {
    v3 &= 0xFFFFFFEF;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v81 + 28))(v81, 1120403456, 1103626240);
  v82 = *(float *)(v81 + 264);
  v83 = *(float *)(v81 + 32) - *(float *)(v81 + 28);
  v84 = *(float *)(v81 + 40) - *(float *)(v81 + 36);
  *(_DWORD *)(v81 + 36) = 1134886912;
  *(_DWORD *)(v81 + 28) = 1084227584;
  v85 = v83 + 5.0;
  v86 = v84 + 330.0;
  *(float *)(v81 + 32) = v85;
  *(float *)(v81 + 40) = v86;
  if ( v82 == 0.0 && *(float *)(v81 + 272) == 0.0 )
  {
    *(_DWORD *)(v81 + 264) = 1084227584;
    *(_DWORD *)(v81 + 272) = 1134886912;
    *(float *)(v81 + 268) = v85;
    *(float *)(v81 + 276) = v86;
  }
  std::wstring::wstring(&section, L"Magic: ON");
  LOBYTE(v153) = 38;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v81 + 68))(v81, &section);
  LOBYTE(v153) = 28;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v144[0].__this = (CarAudioFMOD *)v81;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = this;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_3705af672113d081d64d08d10a3f0497_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 28;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(v81 + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&h[4],
    *(void **)&h[28]);
  v144[1].__this = (CarAudioFMOD *)operator new(0x1BCu);
  LOBYTE(v153) = 40;
  if ( v144[1].__this )
  {
    std::wstring::wstring(&section, L"Steer LA");
    LOBYTE(v153) = 41;
    v87 = v3 | 0x20;
    v144[0].__this = (CarAudioFMOD *)v87;
    v88 = acTranslate(&key, &section);
    *(_DWORD *)&h[28] = 0;
    v153 = 42;
    v3 = v87 | 0x40;
    *(_DWORD *)&h[24] = 0;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v144[1].__this, v88, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v89 = 0;
  }
  this->spSteerLookAhead = v89;
  if ( (v3 & 0x40) != 0 )
  {
    v3 &= 0xFFFFFFBF;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v153 = 28;
  if ( (v3 & 0x20) != 0 )
  {
    v3 &= 0xFFFFFFDF;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spSteerLookAhead->setSize)(
    this->spSteerLookAhead,
    1127153664,
    1103626240);
  ksgui::Spinner::setPosition(this->spSteerLookAhead, 5.0, 440.0);
  ((void (*)(ksgui::Spinner *, int))this->spSteerLookAhead->setRepeatInterval)(
    this->spSteerLookAhead,
    1015222895);
  ksgui::Spinner::setValue(this->spSteerLookAhead, 0);
  v90 = this->spSteerLookAhead;
  *(_DWORD *)&h[28] = this;
  v90->step = 1;
  this->spSteerLookAhead->minValue = 0;
  this->spSteerLookAhead->maxValue = 500;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_6f65ee15b8d811198c7b194ed11e2671_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 28;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spSteerLookAhead->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->spSteerLookAhead;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = 444;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v144[1].__this = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v153) = 46;
  if ( v144[1].__this )
  {
    std::wstring::wstring(&section, L"Steer gain");
    LOBYTE(v153) = 47;
    v91 = v3 | 0x80;
    v144[0].__this = (CarAudioFMOD *)v91;
    v92 = acTranslate(&key, &section);
    *(_DWORD *)&h[28] = 0;
    v153 = 48;
    v3 = v91 | 0x100;
    *(_DWORD *)&h[24] = 0;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v144[1].__this, v92, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v93 = 0;
  }
  this->spSteerGain = v93;
  if ( (v3 & 0x100) != 0 )
  {
    v3 &= 0xFFFFFEFF;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v153 = 28;
  if ( (v3 & 0x80u) != 0 )
  {
    v3 &= 0xFFFFFF7F;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spSteerGain->setSize)(
    this->spSteerGain,
    1127153664,
    1103626240);
  ksgui::Spinner::setPosition(this->spSteerGain, 5.0, 500.0);
  ((void (*)(ksgui::Spinner *, int))this->spSteerGain->setRepeatInterval)(this->spSteerGain, 1015222895);
  ksgui::Spinner::setValue(this->spSteerGain, 0);
  v94 = this->spSteerGain;
  *(_DWORD *)&h[28] = this;
  v94->step = 1;
  this->spSteerGain->minValue = 0;
  this->spSteerGain->maxValue = 400;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_36a866cd242be5e73afa782ea0d7dc4d_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 28;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spSteerGain->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->spSteerGain;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = 444;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v144[1].__this = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v153) = 52;
  if ( v144[1].__this )
  {
    std::wstring::wstring(&section, L"rpm gear up");
    LOBYTE(v153) = 53;
    v95 = v3 | 0x200;
    v144[0].__this = (CarAudioFMOD *)v95;
    v96 = acTranslate(&key, &section);
    *(_DWORD *)&h[28] = 0;
    v153 = 54;
    v3 = v95 | 0x400;
    *(_DWORD *)&h[24] = 0;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v144[1].__this, v96, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v97 = 0;
  }
  this->spGearUp = v97;
  if ( (v3 & 0x400) != 0 )
  {
    v3 &= 0xFFFFFBFF;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v153 = 28;
  if ( (v3 & 0x200) != 0 )
  {
    v3 &= 0xFFFFFDFF;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spGearUp->setSize)(this->spGearUp, 1127153664, 1103626240);
  ksgui::Spinner::setPosition(this->spGearUp, 5.0, 560.0);
  ((void (*)(ksgui::Spinner *, int))this->spGearUp->setRepeatInterval)(this->spGearUp, 1015222895);
  ksgui::Spinner::setValue(this->spGearUp, 0);
  v98 = this->spGearUp;
  *(_DWORD *)&h[28] = this;
  v98->step = 50;
  this->spGearUp->minValue = 0;
  this->spGearUp->maxValue = 50000;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_6ac8d2293cb98e75d086f3ea21f63a1f_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 28;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spGearUp->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->spGearUp;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = 444;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v144[1].__this = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v153) = 58;
  if ( v144[1].__this )
  {
    std::wstring::wstring(&section, L"gear down %");
    LOBYTE(v153) = 59;
    v99 = v3 | 0x800;
    v144[0].__this = (CarAudioFMOD *)v99;
    v100 = acTranslate(&key, &section);
    *(_DWORD *)&h[28] = 0;
    v153 = 60;
    v3 = v99 | 0x1000;
    *(_DWORD *)&h[24] = 0;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v144[1].__this, v100, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v101 = 0;
  }
  this->spGearDown = v101;
  if ( (v3 & 0x1000) != 0 )
  {
    v3 &= 0xFFFFEFFF;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v153 = 28;
  if ( (v3 & 0x800) != 0 )
  {
    v3 &= 0xFFFFF7FF;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spGearDown->setSize)(this->spGearDown, 1127153664, 1103626240);
  ksgui::Spinner::setPosition(this->spGearDown, 200.0, 560.0);
  ((void (*)(ksgui::Spinner *, int))this->spGearDown->setRepeatInterval)(this->spGearDown, 1015222895);
  ksgui::Spinner::setValue(this->spGearDown, 0);
  v102 = this->spGearDown;
  *(_DWORD *)&h[28] = this;
  v102->step = 1;
  this->spGearDown->minValue = 50;
  this->spGearDown->maxValue = 100;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_45b4aa29b4536354e3fda6954864fed8_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v153) = 28;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spGearDown->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v144[0] = (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee>)this->spGearDown;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v144);
  *(_DWORD *)&h[28] = 444;
  v144[0].__this->bank.path._Bx._Ptr = (wchar_t *)this;
  v144[1].__this = (CarAudioFMOD *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v153) = 64;
  if ( v144[1].__this )
  {
    std::wstring::wstring(&section, L"brake hint");
    LOBYTE(v153) = 65;
    v103 = v3 | 0x2000;
    v144[0].__this = (CarAudioFMOD *)v103;
    v104 = acTranslate(&key, &section);
    *(_DWORD *)&h[28] = 0;
    v153 = 66;
    v3 = v103 | 0x4000;
    *(_DWORD *)&h[24] = 0;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v144[1].__this, v104, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v105 = 0;
  }
  this->spBrakeGain = v105;
  if ( (v3 & 0x4000) != 0 )
  {
    v3 &= 0xFFFFBFFF;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v153 = 28;
  if ( (v3 & 0x2000) != 0 )
  {
    v3 &= 0xFFFFDFFF;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spBrakeGain->setSize)(
    this->spBrakeGain,
    1127153664,
    1103626240);
  ksgui::Spinner::setPosition(this->spBrakeGain, 5.0, 620.0);
  ((void (*)(ksgui::Spinner *, int))this->spBrakeGain->setRepeatInterval)(this->spBrakeGain, 1015222895);
  v106 = this->spBrakeGain;
  *(_DWORD *)&h[28] = 90;
  v106->minValue = 0;
  this->spBrakeGain->maxValue = 130;
  ksgui::Spinner::setValue(this->spBrakeGain, *(int *)&h[28]);
  v107 = this->spBrakeGain;
  *(_DWORD *)&h[28] = this;
  v107->step = 1;
  *(_DWORD *)&h[20] = 0;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_bc39b7f8fcfa1baf5c37ee9cdfc4878a_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  std::_Func_class<void,OnPhysicsStepCompleted const &>::_Set(
    (std::_Func_class<void,OnPhysicsStepCompleted const &> *)&h[4],
    (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&h[4]);
  LOBYTE(v153) = 28;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spBrakeGain->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  ksgui::Control::addControl(this, this->spBrakeGain);
  v108 = (CarAudioFMOD *)operator new(0x1BCu);
  v144[1].__this = v108;
  LOBYTE(v153) = 70;
  if ( v108 )
  {
    std::wstring::wstring(&key, L"tyre hint");
    LOBYTE(v153) = 71;
    v109 = v3 | 0x8000;
    v144[0].__this = (CarAudioFMOD *)v109;
    v110 = acTranslate(&section, &key);
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 0;
    v153 = 72;
    v3 = v109 | 0x10000;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v108, v110, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v111 = 0;
  }
  this->spTyresHint = v111;
  if ( (v3 & 0x10000) != 0 )
  {
    v3 &= 0xFFFEFFFF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
  }
  v153 = 28;
  if ( (v3 & 0x8000) != 0 )
  {
    v3 &= 0xFFFF7FFF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spTyresHint->setSize)(
    this->spTyresHint,
    1127153664,
    1103626240);
  ksgui::Spinner::setPosition(this->spTyresHint, 200.0, 620.0);
  ((void (*)(ksgui::Spinner *, int))this->spTyresHint->setRepeatInterval)(this->spTyresHint, 1015222895);
  v112 = this->spTyresHint;
  *(_DWORD *)&h[28] = 120;
  v112->minValue = 0;
  this->spTyresHint->maxValue = 150;
  ksgui::Spinner::setValue(this->spTyresHint, *(int *)&h[28]);
  this->spTyresHint->step = 1;
  ksgui::Control::addControl(this, this->spTyresHint);
  *(_DWORD *)&h[28] = this;
  CommandItem::CommandItem(&v144[1], (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&h[4],
    v113);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spTyresHint->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v114 = (CarAudioFMOD *)operator new(0x1BCu);
  v144[1].__this = v114;
  LOBYTE(v153) = 75;
  if ( v114 )
  {
    std::wstring::wstring(&key, L"aero hint");
    LOBYTE(v153) = 76;
    v115 = v3 | 0x20000;
    v144[0].__this = (CarAudioFMOD *)v115;
    v116 = acTranslate(&section, &key);
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 0;
    v153 = 77;
    v3 = v115 | 0x40000;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v114, v116, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v117 = 0;
  }
  this->spAeroHint = v117;
  if ( (v3 & 0x40000) != 0 )
  {
    v3 &= 0xFFFBFFFF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
  }
  v153 = 28;
  if ( (v3 & 0x20000) != 0 )
  {
    v3 &= 0xFFFDFFFF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spAeroHint->setSize)(this->spAeroHint, 1127153664, 1103626240);
  ksgui::Spinner::setPosition(this->spAeroHint, 200.0, 500.0);
  ((void (*)(ksgui::Spinner *, int))this->spAeroHint->setRepeatInterval)(this->spAeroHint, 1015222895);
  v118 = this->spAeroHint;
  *(_DWORD *)&h[28] = 100;
  v118->minValue = 0;
  this->spAeroHint->maxValue = 150;
  ksgui::Spinner::setValue(this->spAeroHint, *(int *)&h[28]);
  this->spAeroHint->step = 1;
  ksgui::Control::addControl(this, this->spAeroHint);
  *(_DWORD *)&h[28] = this;
  CommandItem::CommandItem(&v144[1], (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&h[4],
    v119);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spAeroHint->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v120 = (CarAudioFMOD *)operator new(0x118u);
  v144[1].__this = v120;
  LOBYTE(v153) = 80;
  if ( v120 )
  {
    std::wstring::wstring(&key, L"SAVE AI");
    LOBYTE(v153) = 81;
    *(_DWORD *)&h[28] = this->gui;
    v3 |= 0x80000u;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Control::Control((ksgui::Control *)v120, &key, *(ksgui::GUI **)&h[28]);
  }
  else
  {
    v121 = 0;
  }
  this->butSaveAi = v121;
  v153 = 28;
  if ( (v3 & 0x80000) != 0 )
  {
    v3 &= 0xFFF7FFFF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  }
  ((void (*)(ksgui::Control *, int, int))this->butSaveAi->setSize)(this->butSaveAi, 1127153664, 1103626240);
  ksgui::Form::setPosition((ksgui::Form *)this->butSaveAi, 200.0, 680.0);
  std::wstring::wstring(&key, L"SAVE ai");
  LOBYTE(v153) = 83;
  v122 = acTranslate(&section, &key);
  LOBYTE(v153) = 84;
  this->butSaveAi->setText(this->butSaveAi, v122);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
  LOBYTE(v153) = 28;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  *(_DWORD *)&h[28] = this;
  CommandItem::CommandItem(&v144[1], (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&h[4],
    v123);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSaveAi->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&h[4],
    *(void **)&h[28]);
  ksgui::Control::addControl(this, this->butSaveAi);
  v124 = (CarAudioFMOD *)operator new(0x1BCu);
  v144[1].__this = v124;
  LOBYTE(v153) = 85;
  if ( v124 )
  {
    std::wstring::wstring(&key, L"aiPush");
    LOBYTE(v153) = 86;
    v125 = v3 | 0x100000;
    v144[0].__this = (CarAudioFMOD *)v125;
    v126 = acTranslate(&section, &key);
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 0;
    v153 = 87;
    v3 = v125 | 0x200000;
    *(_DWORD *)&h[20] = this->gui;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v124, v126, *(ksgui::GUI **)&h[20], 0, 0);
  }
  else
  {
    v127 = 0;
  }
  this->spAIpush = v127;
  if ( (v3 & 0x200000) != 0 )
  {
    v3 &= 0xFFDFFFFF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
  }
  v153 = 28;
  if ( (v3 & 0x100000) != 0 )
  {
    v3 &= 0xFFEFFFFF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->spAIpush->setSize)(this->spAIpush, 1120403456, 1103626240);
  ksgui::Spinner::setPosition(this->spAIpush, 200.0, 380.0);
  v128 = this->spAIpush;
  *(_DWORD *)&h[28] = 100;
  v128->minValue = 1;
  this->spAIpush->maxValue = 120;
  this->spAIpush->step = 1;
  ksgui::Spinner::setValue(this->spAIpush, *(int *)&h[28]);
  ksgui::Control::addControl(this, this->spAIpush);
  *(_DWORD *)&h[28] = this;
  CommandItem::CommandItem(&v144[1], (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&h[4],
    v129);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spAIpush->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    *(void **)&h[28]);
  v130 = (CarAudioFMOD *)operator new(0x118u);
  v144[1].__this = v130;
  LOBYTE(v153) = 90;
  if ( v130 )
  {
    std::wstring::wstring(&key, L"RADIUS");
    LOBYTE(v153) = 91;
    *(_DWORD *)&h[28] = this->gui;
    v3 |= (unsigned int)&_ImageBase;
    v144[0].__this = (CarAudioFMOD *)v3;
    ksgui::Control::Control((ksgui::Control *)v130, &key, *(ksgui::GUI **)&h[28]);
  }
  else
  {
    v131 = 0;
  }
  this->labCurrentRadius = v131;
  v153 = 28;
  if ( ((unsigned int)&_ImageBase & v3) != 0 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  ((void (*)(ksgui::Control *, int, int))this->labCurrentRadius->setSize)(
    this->labCurrentRadius,
    1120403456,
    1103626240);
  ksgui::Form::setPosition((ksgui::Form *)this->labCurrentRadius, 5.0, 360.0);
  ksgui::Control::addControl(this, this->labCurrentRadius);
  *(_DWORD *)&h[28] = 1065353216;
  *(_DWORD *)&h[24] = 0;
  CommandItem::CommandItem(&v144[1], (CarAudioFMOD *)this);
  v144[0].__this = (CarAudioFMOD *)h;
  std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
    (std::function<void __cdecl(SVar *,float)> *)h,
    v132);
  LOBYTE(v153) = 93;
  LODWORD(v146) = &v142;
  std::wstring::wstring(&v142, L"aiSteerGain");
  LOBYTE(v153) = 94;
  v133 = Sim::getConsole(this->sim);
  LOBYTE(v153) = 28;
  Console::addVarLambda(v133, v142, *(std::function<void __cdecl(SVar *,float)> *)h, h[24], *(float *)&h[28]);
  *(_DWORD *)&h[28] = 1065353216;
  *(_DWORD *)&h[24] = 0;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v146,
    (CarAudioFMOD *)this);
  v144[1].__this = (CarAudioFMOD *)h;
  std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
    (std::function<void __cdecl(SVar *,float)> *)h,
    v134);
  LOBYTE(v153) = 95;
  v144[0].__this = (CarAudioFMOD *)&v142;
  std::wstring::wstring(&v142, L"aiPush");
  LOBYTE(v153) = 96;
  v135 = Sim::getConsole(this->sim);
  LOBYTE(v153) = 28;
  Console::addVarLambda(v135, v142, *(std::function<void __cdecl(SVar *,float)> *)h, h[24], *(float *)&h[28]);
  *(_DWORD *)&h[28] = 1065353216;
  *(_DWORD *)&h[24] = 0;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v146,
    (CarAudioFMOD *)this);
  v144[1].__this = (CarAudioFMOD *)h;
  std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
    (std::function<void __cdecl(SVar *,float)> *)h,
    v136);
  LOBYTE(v153) = 97;
  v144[0].__this = (CarAudioFMOD *)&v142;
  std::wstring::wstring(&v142, L"aiLookAhead");
  LOBYTE(v153) = 98;
  v137 = Sim::getConsole(this->sim);
  LOBYTE(v153) = 28;
  Console::addVarLambda(v137, v142, *(std::function<void __cdecl(SVar *,float)> *)h, h[24], *(float *)&h[28]);
  *(_DWORD *)&h[28] = 1065353216;
  *(_DWORD *)&h[24] = 0;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v146,
    (CarAudioFMOD *)this);
  v144[1].__this = (CarAudioFMOD *)h;
  std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
    (std::function<void __cdecl(SVar *,float)> *)h,
    v138);
  LOBYTE(v153) = 99;
  v144[0].__this = (CarAudioFMOD *)&v142;
  std::wstring::wstring(&v142, L"aiLookAheadSpeed");
  LOBYTE(v153) = 100;
  v139 = Sim::getConsole(this->sim);
  LOBYTE(v153) = 28;
  Console::addVarLambda(v139, v142, *(std::function<void __cdecl(SVar *,float)> *)h, h[24], *(float *)&h[28]);
  *(_DWORD *)&h[28] = 1065353216;
  *(_DWORD *)&h[24] = 0;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v146,
    (CarAudioFMOD *)this);
  v144[1].__this = (CarAudioFMOD *)h;
  std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
    (std::function<void __cdecl(SVar *,float)> *)h,
    v140);
  LOBYTE(v153) = 101;
  v144[0].__this = (CarAudioFMOD *)&v142;
  std::wstring::wstring(&v142, L"aiSteerGain");
  LOBYTE(v153) = 102;
  v141 = Sim::getConsole(this->sim);
  LOBYTE(v153) = 28;
  Console::addVarLambda(v141, v142, *(std::function<void __cdecl(SVar *,float)> *)h, h[24], *(float *)&h[28]);
  std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&cars);
  LOBYTE(v153) = 4;
  INIReader::~INIReader(&ini);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&inifile);
}
FormAI *FormAI::`scalar deleting destructor'(FormAI *this, unsigned int a2)
{
  Font *v3; // edi

  this->__vftable = (FormAI_vtbl *)&FormAI::`vftable';
  v3 = this->smallFont._Myptr;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)this->smallFont._Myptr);
    operator delete(v3);
  }
  this->__vftable = (FormAI_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FormAI::render(FormAI *this, float dt)
{
  ICarControlsProvider *v3; // eax
  AIDriver *v4; // eax
  unsigned int v5; // eax
  CarAvatar *v6; // eax
  ksgui::Graph *v7; // ecx
  float v8; // xmm0_4
  ksgui::Graph *v9; // ecx
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // eax
  ksgui::Graph *v13; // ecx
  float v14; // xmm0_4
  unsigned int v15; // eax
  ksgui::Graph *v16; // ecx
  float v17; // xmm0_4
  unsigned int v18; // eax
  ksgui::Graph *v19; // ecx
  float v20; // xmm0_4
  unsigned int v21; // eax
  std::_Func_base<void> *v22; // ecx
  std::wostream *v23; // eax
  const std::wstring *v24; // eax
  std::wstring *v25; // eax
  CarAvatar *v26; // eax
  float v27; // xmm1_4
  int v28; // ecx
  float v29; // xmm1_4
  std::wostream *v30; // eax
  std::wostream *v31; // eax
  std::wostream *v32; // eax
  std::wostream *v33; // eax
  std::wostream *v34; // eax
  std::wostream *v35; // eax
  const std::wstring *v36; // eax
  std::wstring *v37; // eax
  std::wstring *v38; // edx
  char *v39; // ecx
  const std::wstring *v40; // eax
  Game *v41; // eax
  GraphicsManager *v42; // eax
  int v43; // edx
  int v44; // ecx
  const std::wstring *v45; // eax
  std::wostream *v46; // eax
  std::wostream *v47; // eax
  const std::wstring *v48; // eax
  std::wstring *v49; // eax
  AISpline *v50; // eax
  CarAvatar *v51; // esi
  std::_Func_base<void> *v52; // ecx
  vec3f *v53; // eax
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float v57; // xmm2_4
  std::wostream *v58; // eax
  std::wostream *v59; // eax
  const std::wstring *v60; // eax
  std::wstring *v61; // eax
  const std::wstring *v62; // esi
  AISpline *v63; // eax
  std::_Func_base<void> *v64; // ecx
  std::wostream *v65; // eax
  std::wostream *v66; // eax
  const std::wstring *v67; // eax
  std::wstring *v68; // eax
  const std::wstring *v69; // esi
  std::wostream *v70; // eax
  std::wostream *v71; // eax
  const std::wstring *v72; // eax
  Sim *v73; // eax
  float v74; // xmm0_4
  Game *v75; // eax
  Font *v76; // ecx
  std::wstring *v77; // eax
  CarAvatar *v78; // eax
  std::_Func_base<void> **v79; // esi
  float v80; // xmm0_4
  float v81; // xmm1_4
  std::wstring **v82; // eax
  const std::wstring *v83; // eax
  std::_Func_base<void> *v84; // ecx
  CarAvatar *v85; // ecx
  std::wostream *v86; // eax
  std::wostream *v87; // eax
  std::wostream *v88; // eax
  std::wostream *v89; // eax
  std::wostream *v90; // eax
  const std::wstring *v91; // eax
  std::wstring *v92; // eax
  const std::wstring *v93; // eax
  CarAvatar *v94; // ecx
  std::wostream *v95; // eax
  std::wostream *v96; // eax
  int v97; // eax
  const std::wstring *v98; // eax
  std::wstring *v99; // eax
  const std::wstring *v100; // esi
  AISpline *v101; // eax
  std::wostream *v102; // eax
  std::wostream *v103; // eax
  int v104; // eax
  const std::wstring *v105; // eax
  std::wstring *v106; // eax
  const std::wstring *v107; // eax
  CarAvatar *v108; // ecx
  std::wostream *v109; // eax
  std::wostream *v110; // eax
  int v111; // eax
  const std::wstring *v112; // eax
  std::wstring *v113; // eax
  const std::wstring *v114; // edx
  AIDriver *v115; // eax
  float v116; // xmm2_4
  float v117; // xmm0_4
  float v118; // xmm1_4
  float v119; // xmm2_4
  float v120; // xmm0_4
  float v121; // xmm2_4
  std::wostream *v122; // eax
  std::wostream *v123; // eax
  int v124; // eax
  const std::wstring *v125; // eax
  std::wstring *v126; // eax
  const std::wstring *v127; // eax
  AIDriver *v128; // ecx
  std::wostream *v129; // eax
  std::wostream *v130; // eax
  int v131; // eax
  const std::wstring *v132; // eax
  std::wstring *v133; // eax
  std::_Func_base<void> *v134; // ecx
  AIDriver *v135; // eax
  std::wostream *v136; // eax
  int v137; // eax
  const std::wstring *v138; // eax
  std::wstring *v139; // eax
  std::_Func_base<void> *v140; // ecx
  AIDriver *v141; // eax
  std::wostream *v142; // eax
  int v143; // eax
  const std::wstring *v144; // eax
  std::wstring *v145; // eax
  const std::wstring *v146; // esi
  CarAvatar *v147; // eax
  Sim *v148; // ecx
  float v149; // xmm1_4
  float v150; // xmm2_4
  AISplineRecorder *v151; // eax
  std::wostream *v152; // eax
  std::wostream *v153; // eax
  int v154; // eax
  const std::wstring *v155; // eax
  std::wstring *v156; // eax
  const std::wstring *v157; // esi
  CarAvatar *v158; // ecx
  float v159; // xmm0_4
  float v160; // xmm1_4
  float v161; // xmm2_4
  Sim *v162; // ecx
  AISpline *v163; // eax
  double v164; // st7
  std::_Func_base<void> *v165; // ecx
  Sim *v166; // ecx
  AISpline *v167; // eax
  AISplinePayload *v168; // eax
  std::_Func_base<void> *v169; // ecx
  std::wostream *v170; // eax
  std::wostream *v171; // eax
  int v172; // eax
  const std::wstring *v173; // eax
  std::wstring *v174; // eax
  std::allocator<wchar_t> *v175; // eax
  const std::wstring *v176; // esi
  CarAvatar *v177; // eax
  vec3f *v178; // eax
  Sim *v179; // ecx
  AISplineRecorder *v180; // eax
  InterpolatingSpline *v181; // eax
  std::wostream *v182; // eax
  std::wostream *v183; // eax
  int v184; // eax
  std::wstring *v185; // eax
  Game *v186; // eax
  Font *v187; // eax
  Sim *v188; // eax
  Font *v189; // eax
  const std::wstring *v190; // esi
  CarAvatar *v191; // ecx
  vec3f *v192; // eax
  Sim *v193; // ecx
  AISpline *v194; // eax
  InterpolatingSpline *v195; // eax
  double v196; // st7
  std::_Func_base<void> *v197; // ecx
  Sim *v198; // ecx
  AISpline *v199; // eax
  AISplinePayload *v200; // eax
  std::_Func_base<void> *v201; // ecx
  std::wostream *v202; // eax
  std::wostream *v203; // eax
  int v204; // eax
  std::wstring *v205; // eax
  Game *v206; // eax
  Font *v207; // eax
  ksgui::Control *v208; // esi
  long double v209; // xmm0_8
  const __m128i *v210; // eax
  float v211; // xmm0_4
  FormAI::render::__l45::<lambda_64f7ab9f8d033263388e9f2dac61cb4b> *v212; // eax
  CarAvatar *v213; // eax
  CarAvatar *v214; // eax
  CarAvatar *v215; // eax
  FormAI::render::__l53::<lambda_903528dd93b8b4fc96dfa664148dcc1c> *v216; // eax
  const char *v217; // [esp+7Ch] [ebp-2BCh]
  std::function<void __cdecl(void)> r; // [esp+84h] [ebp-2B4h] BYREF
  __int64 v219; // [esp+9Ch] [ebp-29Ch]
  float v220; // [esp+A4h] [ebp-294h]
  int _Val; // [esp+B0h] [ebp-288h] BYREF
  std::wstring *_Str; // [esp+B4h] [ebp-284h] BYREF
  GLRenderer *v223; // [esp+B8h] [ebp-280h]
  int v224; // [esp+BCh] [ebp-27Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v225; // [esp+C0h] [ebp-278h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v226; // [esp+170h] [ebp-1C8h] BYREF
  std::wstring _Newstr; // [esp+220h] [ebp-118h] BYREF
  std::wstring result; // [esp+238h] [ebp-100h] BYREF
  std::wstring text; // [esp+250h] [ebp-E8h] BYREF
  std::wstring imessage; // [esp+268h] [ebp-D0h] BYREF
  std::wstring v231; // [esp+280h] [ebp-B8h] BYREF
  std::wstring v232; // [esp+298h] [ebp-A0h] BYREF
  std::wstring v233; // [esp+2B0h] [ebp-88h] BYREF
  AISplinePayload v234; // [esp+2C8h] [ebp-70h] BYREF
  int v235; // [esp+334h] [ebp-4h]

  *(float *)&_Val = 0.0;
  if ( !this->aiDriver )
  {
    v3 = CarAvatar::getControlsProvider(this->car);
    v4 = (AIDriver *)__RTDynamicCast(
                       v3,
                       0,
                       &ICarControlsProvider `RTTI Type Descriptor',
                       &AIDriver `RTTI Type Descriptor',
                       0);
    this->aiDriver = v4;
    if ( v4 )
    {
      ksgui::Spinner::setValue(this->spSteerLookAhead, (int)(float)(v4->steerMinLookahead * 10.0));
      ksgui::Spinner::setValue(this->spSteerGain, (int)(float)(this->aiDriver->steerGain * 100.0));
      ksgui::Spinner::setValue(this->spGearUp, (int)this->aiDriver->changeUpRPM);
      ksgui::Spinner::setValue(this->spGearDown, (int)(float)((float)(this->aiDriver->changeDnPerc * 100.0) + 0.5));
      ksgui::Spinner::setValue(this->spBrakeGain, (int)(float)(this->aiDriver->brakeHintBase * 100.0));
      ksgui::Spinner::setValue(this->spTyresHint, (int)(float)(this->aiDriver->tyresHint * 100.0));
      ksgui::Spinner::setValue(this->spAeroHint, (int)(float)(this->aiDriver->aeroHint * 100.0));
    }
  }
  v5 = Sim::getFocusedCarIndex(this->sim);
  v6 = Sim::getCar(this->sim, v5);
  this->car = v6;
  if ( v6 && v6->aiState.isActive )
  {
    v7 = this->speedGraph;
    v8 = v6->physicsState.speed.value;
    *(float *)&_Val = v8;
    if ( (unsigned int)(v7->series._Mylast - v7->series._Myfirst) > 1 )
    {
      if ( v7->autoAdjustMaxValue && v8 > v7->maxY )
        v7->maxY = v8;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)(*((_DWORD *)v7->series._Myfirst + 1) + 12), &_Val);
    }
    v9 = this->speedGraph;
    v10 = FLOAT_50_0;
    v11 = this->car->physicsState.gas * 50.0;
    v12 = v9->series._Mylast - v9->series._Myfirst;
    *(float *)&_Val = v11;
    if ( v12 )
    {
      if ( v9->autoAdjustMaxValue && v11 > v9->maxY )
        v9->maxY = v11;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&(*v9->series._Myfirst)->values, &_Val);
      v10 = FLOAT_50_0;
    }
    v13 = this->speedGraph;
    v14 = this->car->physicsState.brake * v10;
    v15 = v13->series._Mylast - v13->series._Myfirst;
    *(float *)&_Val = v14;
    if ( v15 > 2 )
    {
      if ( v13->autoAdjustMaxValue && v14 > v13->maxY )
        v13->maxY = v14;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)(*((_DWORD *)v13->series._Myfirst + 2) + 12), &_Val);
    }
    v16 = this->speedGraph;
    v17 = this->car->aiState.targetSpeed;
    v18 = v16->series._Mylast - v16->series._Myfirst;
    *(float *)&_Val = v17;
    if ( v18 > 3 )
    {
      if ( v16->autoAdjustMaxValue && v17 > v16->maxY )
        v16->maxY = v17;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)(*((_DWORD *)v16->series._Myfirst + 3) + 12), &_Val);
    }
    v19 = this->speedGraph;
    v20 = this->car->aiState.understeerFactor * 50.0;
    v21 = v19->series._Mylast - v19->series._Myfirst;
    *(float *)&_Val = v20;
    if ( v21 > 4 )
    {
      if ( v19->autoAdjustMaxValue && v20 > v19->maxY )
        v19->maxY = v20;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)(*((_DWORD *)v19->series._Myfirst + 4) + 12), &_Val);
    }
    *(_DWORD *)v226.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v226.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v226.gap68);
    v235 = 0;
    _Val = 1;
    std::wiostream::basic_iostream<wchar_t>(&v226, &v226.gap10[8], 0);
    v235 = 1;
    *(_DWORD *)&v226.gap0[*(_DWORD *)(*(_DWORD *)v226.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v225.gap68[*(_DWORD *)(*(_DWORD *)v226.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v226.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v226.gap10[8]);
    *(_DWORD *)&v226.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v226.gap10[64] = 0;
    *(_DWORD *)&v226.gap10[68] = 0;
    v235 = 3;
    (&r._Impl)[1] = (std::_Func_base<void> *)(int)(float)(this->car->aiState.currentPush * 100.0);
    r._Impl = v22;
    v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v226.gap10, "CP:");
    std::wostream::operator<<(v23, (&r._Impl)[1]);
    v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v226, &result);
    LOBYTE(v235) = 4;
    this->labCurrentRadius->setText(this->labCurrentRadius, v24);
    LOBYTE(v235) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&text, word_17BE9D8);
    LOBYTE(v235) = 5;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v226.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v226.gap10[68];
    v25 = &text;
    r._Impl = (std::_Func_base<void> *)text._Mysize;
    if ( text._Myres >= 8 )
      v25 = (std::wstring *)text._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v226.gap10[8], v25->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 3;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v26 = this->car;
    v27 = v26->aiState.brakeTargetSpeed;
    if ( v27 > 0.0 )
    {
      v28 = (int)(float)(v27 * 3.5999999);
      v29 = v26->physicsState.speed.value * 3.5999999;
      r._Space._Pfn[1] = (void (__cdecl *)())" ";
      r._Space._Pfn[0] = (void (__cdecl *)())(int)v29;
      v30 = (std::wostream *)std::wostream::operator<<(v226.gap10, v28);
      v31 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v30, v217);
      v32 = (std::wostream *)std::wostream::operator<<(v31, " ");
      v33 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v32, " D:");
      v34 = (std::wostream *)std::wostream::operator<<(v33, r._Impl);
      v35 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v34, (const char *)r._Impl);
      std::wostream::operator<<(v35, v219);
      v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v226, &result);
      LOBYTE(v235) = 6;
      this->lblBrakeTarget->setText(this->lblBrakeTarget, v36);
      LOBYTE(v235) = 3;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    std::wstring::wstring(&text, word_17BE9D8);
    LOBYTE(v235) = 7;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v226.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v226.gap10[68];
    v37 = &text;
    r._Impl = (std::_Func_base<void> *)text._Mysize;
    if ( text._Myres >= 8 )
      v37 = (std::wstring *)text._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v226.gap10[8], v37->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 3;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v223 = (GLRenderer *)std::setprecision(&text, 3, 0);
    v38 = (std::wstring *)std::wostream::operator<<(v226.gap10, std::fixed);
    _Str = v38;
    if ( v38 )
      v39 = (char *)v38 + *((_DWORD *)v38->_Bx._Ptr + 1);
    else
      v39 = 0;
    (&r._Impl)[1] = (std::_Func_base<void> *)v223->buffers._Myend;
    ((void (__cdecl *)(char *, std::pair<int,void *> *))v223->__vftable)(v39, v223->buffers._Mylast);
    std::wostream::operator<<(_Str, LODWORD(this->car->physicsState.normalizedSplinePosition));
    v40 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v226, &result);
    LOBYTE(v235) = 8;
    this->lblNSP->setText(this->lblNSP, v40);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v235 = -1;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v226);
  }
  ksgui::Control::render(this, (int)this, (int)operator delete, dt, v219, v220);
  v41 = this->sim->game;
  (&r._Impl)[1] = (std::_Func_base<void> *)1065353216;
  r._Impl = 0;
  v42 = v41->graphics;
  *(_QWORD *)&r._Space._Alias[8] = 1065353216i64;
  v223 = v42->gl;
  GLRenderer::color4f(v223, 1.0, 0.0, 0.0, 1.0);
  Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  *(_DWORD *)v225.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v225.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v225.gap68);
  v235 = 9;
  _Val |= 2u;
  std::wiostream::basic_iostream<wchar_t>(&v225, &v225.gap10[8], 0);
  v235 = 10;
  *(_DWORD *)&v225.gap0[*(_DWORD *)(*(_DWORD *)v225.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v224 + *(_DWORD *)(*(_DWORD *)v225.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v225.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v225.gap10[8]);
  *(_DWORD *)&v225.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v225.gap10[64] = 0;
  *(_DWORD *)&v225.gap10[68] = 0;
  v235 = 12;
  _Str = (std::wstring *)std::setprecision(&text, 2, 0);
  v43 = std::wostream::operator<<(v225.gap10, std::fixed);
  if ( v43 )
    v44 = v43 + *(_DWORD *)(*(_DWORD *)v43 + 4);
  else
    v44 = 0;
  ((void (__cdecl *)(int, _DWORD, _DWORD))_Str->_Bx._Ptr)(
    v44,
    *(_DWORD *)&_Str->_Bx._Alias[8],
    *(_DWORD *)&_Str->_Bx._Alias[12]);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Normalized Pos", 0xEu);
  LOBYTE(v235) = 13;
  v45 = acTranslate(&_Newstr, &text);
  LOBYTE(v235) = 14;
  (&r._Impl)[1] = (std::_Func_base<void> *)LODWORD(this->car->physicsState.normalizedSplinePosition);
  v46 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v45);
  v47 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v46, L" : ");
  std::wostream::operator<<(v47, (&r._Impl)[1]);
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  LOBYTE(v235) = 12;
  _Newstr._Myres = 7;
  _Newstr._Mysize = 0;
  _Newstr._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v48 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
  LOBYTE(v235) = 15;
  Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 20.0, v48, 1.0, eAlignLeft);
  LOBYTE(v235) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  GLRenderer::color4f(v223, 1.0, 0.0, 0.0, 1.0);
  Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v235) = 16;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
  (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
  v49 = &text;
  r._Impl = (std::_Func_base<void> *)text._Mysize;
  if ( text._Myres >= 8 )
    v49 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v49->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
  LOBYTE(v235) = 12;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  _Newstr._Myres = 7;
  _Newstr._Mysize = 0;
  _Newstr._Bx._Buf[0] = 0;
  std::wstring::assign(&_Newstr, L"Target Steer Distance", 0x15u);
  LOBYTE(v235) = 17;
  _Str = acTranslate(&result, &_Newstr);
  LOBYTE(v235) = 18;
  v50 = TrackAvatar::getAISpline(this->sim->track);
  v51 = this->car;
  (&r._Impl)[1] = v52;
  v53 = InterpolatingSpline::splineToWorld(&v50->spline, (vec3f *)&text, v51->aiState.currentNormalizedSplinePosition);
  v54 = v53->y - v51->aiState.steerTarget.y;
  v55 = (float)((float)(v53->x - v51->aiState.steerTarget.x) * (float)(v53->x - v51->aiState.steerTarget.x))
      + (float)(v54 * v54);
  v56 = 0.0;
  v57 = v55 + (float)((float)(v53->z - v51->aiState.steerTarget.z) * (float)(v53->z - v51->aiState.steerTarget.z));
  if ( v57 != 0.0 )
    v56 = fsqrt(v57);
  v58 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, _Str);
  v59 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v58, L" : ");
  std::wostream::operator<<(v59, LODWORD(v56));
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v235) = 12;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  v60 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
  LOBYTE(v235) = 19;
  Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 50.0, v60, 1.0, eAlignLeft);
  LOBYTE(v235) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v235) = 20;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
  (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
  v61 = &text;
  r._Impl = (std::_Func_base<void> *)text._Mysize;
  if ( text._Myres >= 8 )
    v61 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v61->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
  LOBYTE(v235) = 12;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  _Newstr._Myres = 7;
  _Newstr._Mysize = 0;
  _Newstr._Bx._Buf[0] = 0;
  std::wstring::assign(&_Newstr, L"Points count", 0xCu);
  LOBYTE(v235) = 21;
  v62 = acTranslate(&result, &_Newstr);
  LOBYTE(v235) = 22;
  v63 = TrackAvatar::getAISpline(this->sim->track);
  (&r._Impl)[1] = (std::_Func_base<void> *)Spline::pointsCount(&v63->spline);
  r._Impl = v64;
  v65 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v62);
  v66 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v65, L" : ");
  std::wostream::operator<<(v66, (&r._Impl)[1]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v235) = 12;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  v67 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
  LOBYTE(v235) = 23;
  Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 80.0, v67, 1.0, eAlignLeft);
  LOBYTE(v235) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v235) = 24;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
  (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
  v68 = &text;
  r._Impl = (std::_Func_base<void> *)text._Mysize;
  if ( text._Myres >= 8 )
    v68 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v68->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
  LOBYTE(v235) = 12;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  _Newstr._Myres = 7;
  _Newstr._Mysize = 0;
  _Newstr._Bx._Buf[0] = 0;
  std::wstring::assign(&_Newstr, L"Interpolation Mode", 0x12u);
  LOBYTE(v235) = 25;
  v69 = acTranslate(&result, &_Newstr);
  LOBYTE(v235) = 26;
  (&r._Impl)[1] = (std::_Func_base<void> *)&interpolationModeName_166[TrackAvatar::getAISpline(this->sim->track)->spline.interpolationMode];
  v70 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v69);
  v71 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v70, L" : ");
  std::operator<<<wchar_t>(v71, (const std::wstring *)(&r._Impl)[1]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v235) = 12;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  v72 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
  LOBYTE(v235) = 27;
  Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 110.0, v72, 1.0, eAlignLeft);
  LOBYTE(v235) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v73 = this->sim;
  LODWORD(v74) = LODWORD(this->car->aiState.outsideOffset) & _xmm;
  (&r._Impl)[1] = (std::_Func_base<void> *)1065353216;
  v75 = v73->game;
  r._Impl = 0;
  v76 = v75->gui->font._Ptr;
  if ( v74 >= 2.0 )
    *(_QWORD *)&r._Space._Alias[8] = 1065353216i64;
  else
    *(_QWORD *)&r._Space._Alias[8] = 0x3F80000000000000i64;
  Font::setColor(
    v76,
    *(float *)&r._Space._Pfn[2],
    *(float *)&r._Space._Alias[12],
    *(float *)&r._Impl,
    *(float *)&(&r._Impl)[1]);
  std::wstring::wstring(&_Newstr, word_17BE9D8);
  LOBYTE(v235) = 28;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
  (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
  v77 = &_Newstr;
  r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
  if ( _Newstr._Myres >= 8 )
    v77 = (std::wstring *)_Newstr._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v77->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
  LOBYTE(v235) = 12;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  if ( GetAsyncKeyState(17) )
    this->maxOutsideOffset = 0.0;
  v78 = this->car;
  v79 = (std::_Func_base<void> **)&this->maxOutsideOffset;
  v80 = this->maxOutsideOffset;
  (&r._Impl)[1] = (std::_Func_base<void> *)L"Outside offset";
  v81 = v78->aiState.outsideOffset;
  v82 = &_Str;
  _Str = (std::wstring *)(LODWORD(v81) & _xmm);
  if ( v80 > COERCE_FLOAT(LODWORD(v81) & _xmm) )
    v82 = (std::wstring **)&this->maxOutsideOffset;
  *v79 = (std::_Func_base<void> *)*v82;
  std::wstring::wstring(&_Newstr, (const wchar_t *)(&r._Impl)[1]);
  LOBYTE(v235) = 29;
  v83 = acTranslate(&result, &_Newstr);
  (&r._Impl)[1] = (std::_Func_base<void> *)")";
  r._Impl = v84;
  LOBYTE(v235) = 30;
  v85 = this->car;
  r._Impl = *v79;
  *(_DWORD *)&r._Space._Alias[12] = "(";
  r._Space._Pfn[2] = (void (__cdecl *)())LODWORD(v85->aiState.outsideOffset);
  v86 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v83);
  v87 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v86, L" : ");
  v88 = (std::wostream *)std::wostream::operator<<(v87, r._Space._Pfn[2]);
  v89 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v88, (const char *)r._Space._Pfn[2]);
  v90 = (std::wostream *)std::wostream::operator<<(v89, "(");
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v90, ")");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v235) = 12;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  v91 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
  LOBYTE(v235) = 31;
  Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 140.0, v91, 2.0, eAlignLeft);
  LOBYTE(v235) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  std::wstring::wstring(&_Newstr, word_17BE9D8);
  LOBYTE(v235) = 32;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
  (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
  v92 = &_Newstr;
  r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
  if ( _Newstr._Myres >= 8 )
    v92 = (std::wstring *)_Newstr._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v92->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
  LOBYTE(v235) = 12;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  std::wstring::wstring(&_Newstr, L"Gas Brake Target");
  LOBYTE(v235) = 33;
  v93 = acTranslate(&result, &_Newstr);
  LOBYTE(v235) = 34;
  v94 = this->car;
  (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
  r._Impl = (std::_Func_base<void> *)v94;
  r._Impl = (std::_Func_base<void> *)LODWORD(v94->aiState.gasBrakeTarget);
  v95 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v93);
  v96 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v95, L" : ");
  v97 = std::wostream::operator<<(v96, r._Impl);
  std::wostream::operator<<(v97);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v235) = 12;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  v98 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
  LOBYTE(v235) = 35;
  Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 170.0, v98, 1.0, eAlignLeft);
  LOBYTE(v235) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  std::wstring::wstring(&_Newstr, word_17BE9D8);
  LOBYTE(v235) = 36;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
  (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
  v99 = &_Newstr;
  r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
  if ( _Newstr._Myres >= 8 )
    v99 = (std::wstring *)_Newstr._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v99->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
  LOBYTE(v235) = 12;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  std::wstring::wstring(&_Newstr, L"IS grid on");
  LOBYTE(v235) = 37;
  v100 = acTranslate(&result, &_Newstr);
  LOBYTE(v235) = 38;
  v101 = TrackAvatar::getAISpline(this->sim->track);
  r._Impl = (std::_Func_base<void> *)InterpolatingSpline::isGridOn(&v101->spline);
  v102 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v100);
  v103 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v102, L" : ");
  v104 = std::wostream::operator<<(v103, r._Impl, std::endl<wchar_t,std::char_traits<wchar_t>>);
  std::wostream::operator<<(v104);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v235) = 12;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Newstr._Myres >= 8 )
    operator delete(_Newstr._Bx._Ptr);
  v105 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
  LOBYTE(v235) = 39;
  Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 200.0, v105, 1.0, eAlignLeft);
  LOBYTE(v235) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( this->aiDriver )
  {
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 40;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v106 = &_Newstr;
    r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
    if ( _Newstr._Myres >= 8 )
      v106 = (std::wstring *)_Newstr._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v106->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    std::wstring::wstring(&_Newstr, L"Prj RPM");
    LOBYTE(v235) = 41;
    v107 = acTranslate(&result, &_Newstr);
    LOBYTE(v235) = 42;
    v108 = this->car;
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    r._Impl = (std::_Func_base<void> *)v108;
    r._Impl = (std::_Func_base<void> *)LODWORD(v108->aiState.projDNRPM);
    v109 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v107);
    v110 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v109, L" : ");
    v111 = std::wostream::operator<<(v110, r._Impl);
    std::wostream::operator<<(v111);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v235) = 12;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    v112 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
    LOBYTE(v235) = 43;
    Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 230.0, v112, 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 44;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v113 = &_Newstr;
    r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
    if ( _Newstr._Myres >= 8 )
      v113 = (std::wstring *)_Newstr._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v113->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    std::wstring::wstring(&_Newstr, L"Distance From target");
    LOBYTE(v235) = 45;
    v114 = acTranslate(&result, &_Newstr);
    LOBYTE(v235) = 46;
    v115 = this->aiDriver;
    v116 = v115->steerTarget.x - this->car->bodyTransform->matrix.M41;
    v117 = v115->steerTarget.y - this->car->bodyTransform->matrix.M42;
    v118 = v115->steerTarget.z - this->car->bodyTransform->matrix.M43;
    v119 = (float)(v116 * v116) + (float)(v117 * v117);
    v120 = 0.0;
    v121 = v119 + (float)(v118 * v118);
    if ( v121 != 0.0 )
      v120 = fsqrt(v121);
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    v122 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v114);
    v123 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v122, L" : ");
    v124 = std::wostream::operator<<(v123, LODWORD(v120));
    std::wostream::operator<<(v124);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v235) = 12;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    v125 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
    LOBYTE(v235) = 47;
    Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 260.0, v125, 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 48;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v126 = &_Newstr;
    r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
    if ( _Newstr._Myres >= 8 )
      v126 = (std::wstring *)_Newstr._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v126->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    std::wstring::wstring(&_Newstr, L"BASE");
    LOBYTE(v235) = 49;
    v127 = acTranslate(&result, &_Newstr);
    LOBYTE(v235) = 50;
    v128 = this->aiDriver;
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    r._Impl = (std::_Func_base<void> *)v128;
    r._Impl = (std::_Func_base<void> *)LODWORD(v128->steerMinLookahead);
    v129 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v127);
    v130 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v129, L" : ");
    v131 = std::wostream::operator<<(v130, r._Impl);
    std::wostream::operator<<(v131);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v235) = 12;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    v132 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
    LOBYTE(v235) = 51;
    Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 290.0, v132, 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 52;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v133 = &_Newstr;
    r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
    if ( _Newstr._Myres >= 8 )
      v133 = (std::wstring *)_Newstr._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v133->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    v135 = this->aiDriver;
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    r._Impl = v134;
    r._Impl = (std::_Func_base<void> *)LODWORD(v135->nextCarModifier);
    v136 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v225.gap10, "NCM : ");
    v137 = std::wostream::operator<<(v136, r._Impl);
    std::wostream::operator<<(v137);
    v138 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
    LOBYTE(v235) = 53;
    Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 350.0, v138, 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 54;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v139 = &_Newstr;
    r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
    if ( _Newstr._Myres >= 8 )
      v139 = (std::wstring *)_Newstr._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v139->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    v141 = this->aiDriver;
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    r._Impl = v140;
    r._Impl = (std::_Func_base<void> *)LODWORD(v141->distToNextCorner);
    v142 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v225.gap10, "DTNC : ");
    v143 = std::wostream::operator<<(v142, r._Impl);
    std::wostream::operator<<(v143);
    v144 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
    LOBYTE(v235) = 55;
    Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 380.0, v144, 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  else
  {
    Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 56;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v145 = &_Newstr;
    r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
    if ( _Newstr._Myres >= 8 )
      v145 = (std::wstring *)_Newstr._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v145->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    std::wstring::wstring(&_Newstr, L"RIGHT INDEX");
    LOBYTE(v235) = 57;
    v146 = acTranslate(&result, &_Newstr);
    LOBYTE(v235) = 58;
    v147 = Sim::getCar(this->sim, 0);
    v148 = this->sim;
    v149 = v147->physicsState.worldMatrix.M42;
    v150 = v147->physicsState.worldMatrix.M43;
    text._Bx._Ptr = (wchar_t *)LODWORD(v147->physicsState.worldMatrix.M41);
    *(_QWORD *)&text._Bx._Alias[4] = __PAIR64__(LODWORD(v150), LODWORD(v149));
    v151 = TrackAvatar::getSplineRecorder(v148->track);
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    r._Impl = (std::_Func_base<void> *)InterpolatingSpline::closestPointIndex(
                                         &v151->rightSpline,
                                         (const vec3f *)&text,
                                         0);
    v152 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v146);
    v153 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v152, L" : ");
    v154 = std::wostream::operator<<(v153, r._Impl);
    std::wostream::operator<<(v154);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v235) = 12;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    v155 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
    LOBYTE(v235) = 59;
    Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 230.0, v155, 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 60;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v156 = &_Newstr;
    r._Impl = (std::_Func_base<void> *)_Newstr._Mysize;
    if ( _Newstr._Myres >= 8 )
      v156 = (std::wstring *)_Newstr._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v156->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    std::wstring::wstring(&_Newstr, L"RIGHT DISTANCE");
    LOBYTE(v235) = 61;
    v157 = acTranslate(&result, &_Newstr);
    LOBYTE(v235) = 62;
    v158 = this->car;
    v159 = v158->physicsState.worldMatrix.M41;
    v160 = v158->physicsState.worldMatrix.M42;
    v161 = v158->physicsState.worldMatrix.M43;
    v162 = this->sim;
    *(_QWORD *)text._Bx._Buf = __PAIR64__(LODWORD(v160), LODWORD(v159));
    *(float *)&text._Bx._Alias[8] = v161;
    v163 = TrackAvatar::getAISpline(v162->track);
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    v164 = InterpolatingSpline::worldToSpline(&v163->spline, (const vec3f *)&text, -1);
    r._Impl = v165;
    v166 = this->sim;
    *(float *)&r._Impl = v164;
    *(_DWORD *)&r._Space._Alias[12] = &v234;
    v167 = TrackAvatar::getAISpline(v166->track);
    v168 = AISpline::payloadAtPosition(v167, &v234, *(float *)&r._Impl);
    r._Impl = v169;
    r._Impl = (std::_Func_base<void> *)LODWORD(v168->sides[1]);
    v170 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v157);
    v171 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v170, L" : ");
    v172 = std::wostream::operator<<(v171, r._Impl);
    std::wostream::operator<<(v172);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v235) = 12;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( _Newstr._Myres >= 8 )
      operator delete(_Newstr._Bx._Ptr);
    v173 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &result);
    LOBYTE(v235) = 63;
    Font::blitString(this->sim->game->gui->font._Ptr, 20.0, 260.0, v173, 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    Font::setColor(this->sim->game->gui->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    std::wstring::wstring(&text, word_17BE9D8);
    LOBYTE(v235) = 64;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v225.gap10[8]);
    (&r._Impl)[1] = *(std::_Func_base<void> **)&v225.gap10[68];
    v174 = &text;
    r._Impl = (std::_Func_base<void> *)text._Mysize;
    if ( text._Myres >= 8 )
      v174 = (std::wstring *)text._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v225.gap10[8], v174->_Bx._Buf, (unsigned int)r._Impl, (int)(&r._Impl)[1]);
    LOBYTE(v235) = 12;
    if ( text._Myres >= 8 )
    {
      (&r._Impl)[1] = (std::_Func_base<void> *)(text._Myres + 1);
      r._Impl = (std::_Func_base<void> *)text._Bx._Ptr;
      v175 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                          (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&text,
                                          (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&v224 + 3);
      std::allocator<wchar_t>::deallocate(v175, (wchar_t *)r._Impl, (unsigned int)(&r._Impl)[1]);
    }
    text._Myres = 7;
    std::wstring::_Eos(&text, 0);
    std::wstring::wstring(&result, L"LEFT  INDEX");
    LOBYTE(v235) = 65;
    v176 = acTranslate(&v233, &result);
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    r._Impl = 0;
    LOBYTE(v235) = 66;
    v177 = Sim::getCar(this->sim, 0);
    v178 = mat44f::getTranslation(&v177->physicsState.worldMatrix, (vec3f *)&text);
    v179 = this->sim;
    *(_DWORD *)&r._Space._Alias[12] = v178;
    v180 = TrackAvatar::getSplineRecorder(v179->track);
    v181 = AISplineRecorder::getLeftSpline(v180);
    r._Impl = (std::_Func_base<void> *)InterpolatingSpline::closestPointIndex(
                                         v181,
                                         *(const vec3f **)&r._Space._Alias[12],
                                         0);
    v182 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v176);
    v183 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v182, L" : ");
    v184 = std::wostream::operator<<(v183, r._Impl);
    std::wostream::operator<<(v184);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v233);
    LOBYTE(v235) = 12;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    v185 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &v231);
    LOBYTE(v235) = 67;
    (&r._Impl)[1] = 0;
    r._Impl = (std::_Func_base<void> *)1065353216;
    *(_DWORD *)&r._Space._Alias[12] = v185;
    v186 = this->sim->game;
    *(_QWORD *)&r._Space._Alias[4] = 0x4391000041A00000i64;
    v187 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v186->gui->font);
    Font::blitString(v187, 20.0, 290.0, *(const std::wstring **)&r._Space._Alias[12], 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v231);
    (&r._Impl)[1] = (std::_Func_base<void> *)1065353216;
    r._Impl = 0;
    v188 = this->sim;
    *(_QWORD *)&r._Space._Alias[8] = 1065353216i64;
    v189 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v188->game->gui->font);
    Font::setColor(v189, 1.0, 0.0, 0.0, 1.0);
    std::wstring::wstring(&_Newstr, word_17BE9D8);
    LOBYTE(v235) = 68;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &_Newstr);
    LOBYTE(v235) = 12;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Newstr);
    std::wstring::wstring(&imessage, L"LEFT DISTANCE");
    LOBYTE(v235) = 69;
    v190 = acTranslate(&v231, &imessage);
    (&r._Impl)[1] = (std::_Func_base<void> *)std::endl<wchar_t,std::char_traits<wchar_t>>;
    LOBYTE(v235) = 70;
    v191 = this->car;
    r._Impl = (std::_Func_base<void> *)-1;
    v192 = mat44f::getTranslation(&v191->physicsState.worldMatrix, (vec3f *)&text);
    v193 = this->sim;
    *(_DWORD *)&r._Space._Alias[12] = v192;
    v194 = TrackAvatar::getAISpline(v193->track);
    v195 = AISpline::getBaseSpline(v194);
    v196 = InterpolatingSpline::worldToSpline(v195, *(const vec3f **)&r._Space._Alias[12], -1);
    r._Impl = v197;
    v198 = this->sim;
    *(float *)&r._Impl = v196;
    *(_DWORD *)&r._Space._Alias[12] = &v234;
    v199 = TrackAvatar::getAISpline(v198->track);
    v200 = AISpline::payloadAtPosition(v199, &v234, *(float *)&r._Impl);
    r._Impl = v201;
    r._Impl = (std::_Func_base<void> *)LODWORD(v200->sides[0]);
    v202 = std::operator<<<wchar_t>((std::wostream *)v225.gap10, v190);
    v203 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v202, L" : ");
    v204 = std::wostream::operator<<(v203, r._Impl);
    std::wostream::operator<<(v204);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v231);
    LOBYTE(v235) = 12;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&imessage);
    v205 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v225, &v232);
    LOBYTE(v235) = 71;
    (&r._Impl)[1] = 0;
    r._Impl = (std::_Func_base<void> *)1065353216;
    *(_DWORD *)&r._Space._Alias[12] = v205;
    v206 = this->sim->game;
    *(_QWORD *)&r._Space._Alias[4] = 0x43A0000041A00000i64;
    v207 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v206->gui->font);
    Font::blitString(v207, 20.0, 320.0, *(const std::wstring **)&r._Space._Alias[12], 1.0, eAlignLeft);
    LOBYTE(v235) = 12;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v232);
  }
  v208 = this->butStartRecording;
  if ( v208->tag )
  {
    v209 = this->car->game->gameTime.now * 0.002;
    (&r._Impl)[1] = (std::_Func_base<void> *)1065353216;
    if ( (int)v209 % 2 )
    {
      r._Impl = 0;
      *(_QWORD *)&r._Space._Alias[8] = 1065353216i64;
    }
    else
    {
      r._Impl = (std::_Func_base<void> *)1053609165;
      *(_QWORD *)&r._Space._Alias[8] = 0x3ECCCCCD3ECCCCCDi64;
    }
    vec4f::vec4f(
      (vec4f *)&text,
      *(float *)&r._Space._Pfn[2],
      *(float *)&r._Space._Alias[12],
      *(float *)&r._Impl,
      *(float *)&(&r._Impl)[1]);
    v208->backColor = (vec4f)_mm_loadu_si128(v210);
  }
  if ( this->autoFuelSaveCons )
  {
    if ( !this->autoFuelSaveConsActive )
    {
      v211 = this->autoFuelTime + dt;
      this->autoFuelTime = v211;
      if ( v211 > 2.0 )
      {
        std::wstring::wstring(&result, L"Enabled");
        LOBYTE(v235) = 72;
        std::wstring::wstring(&imessage, L"AUTO FUEL CONS");
        LOBYTE(v235) = 73;
        SystemMessage::addMessage(this->sim->systemMessage, &imessage, &result, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&imessage);
        LOBYTE(v235) = 12;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        (&r._Impl)[1] = (std::_Func_base<void> *)this;
        this->autoFuelSaveConsActive = 1;
        CommandItem::CommandItem(
          (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Str,
          (CarAudioFMOD *)(&r._Impl)[1]);
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(&r, v212);
        PhysicsAvatar::executeOnPhysicsThread(this->sim->physicsAvatar, r);
      }
    }
    v213 = Sim::getCar(this->sim, 0);
    if ( (unsigned int)RaceManager::getLapCount(this->sim->raceManager, v213) >= 3
      || (v214 = Sim::getCar(this->sim, 0), (unsigned int)RaceManager::getLapCount(this->sim->raceManager, v214) > 1)
      && (v215 = Sim::getCar(this->sim, 0), CarAvatar::isInPitlane(v215)) )
    {
      CommandItem::CommandItem(
        (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Str,
        (CarAudioFMOD *)this);
      std::function<void __cdecl (void)>::function<void __cdecl (void)>(&r, v216);
      PhysicsAvatar::executeOnPhysicsThread(this->car->sim->physicsAvatar, r);
    }
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v225);
}
void FormAI::onBeginPitlaneClicked(FormAI *this, const ksgui::OnControlClicked *message)
{
  const std::wstring *v3; // eax
  AISplineRecorder *v4; // eax
  const std::wstring *v5; // eax
  CarAvatar *v6; // eax
  AISplineRecorder *v7; // eax
  std::wstring v8; // [esp+10h] [ebp-74h] BYREF
  std::wstring text; // [esp+28h] [ebp-5Ch] BYREF
  std::wstring result; // [esp+40h] [ebp-44h] BYREF
  std::wstring v11; // [esp+58h] [ebp-2Ch] BYREF
  int v12; // [esp+80h] [ebp-4h]

  if ( this->butStartPitLane->tag )
  {
    v8._Myres = 7;
    v8._Mysize = 0;
    v8._Bx._Buf[0] = 0;
    std::wstring::assign(&v8, L"start recording", 0xFu);
    v12 = 2;
    v5 = acTranslate(&v11, &v8);
    LOBYTE(v12) = 3;
    this->butStartPitLane->setText(this->butStartPitLane, v5);
    if ( v11._Myres >= 8 )
      operator delete(v11._Bx._Ptr);
    v12 = -1;
    v11._Myres = 7;
    v11._Mysize = 0;
    v11._Bx._Buf[0] = 0;
    if ( v8._Myres >= 8 )
      operator delete(v8._Bx._Ptr);
    v8._Myres = 7;
    v8._Bx._Buf[0] = 0;
    v6 = this->car;
    v8._Mysize = 0;
    v7 = TrackAvatar::getSplineRecorder(v6->sim->track);
    AISplineRecorder::endPitLaneSpline(v7);
    this->butStartPitLane->tag = 0;
  }
  else
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"recording", 9u);
    v12 = 0;
    v3 = acTranslate(&result, &text);
    LOBYTE(v12) = 1;
    this->butStartPitLane->setText(this->butStartPitLane, v3);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v12 = -1;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    this->butStartPitLane->tag = (void *)1;
    v4 = TrackAvatar::getSplineRecorder(this->car->sim->track);
    AISplineRecorder::beginPitLaneSpline(v4);
  }
}
void FormAI::renderSplines(FormAI *this)
{
  unsigned int v2; // eax
  Game *v3; // esi
  const mat44f *v4; // eax
  GLRenderer *v5; // esi
  float pos; // xmm0_4
  const vec3f *v7; // eax
  AISplineRecorder *v8; // eax
  InterpolatingSpline *v9; // esi
  float v10; // xmm0_4
  const vec3f *v11; // eax
  unsigned int v12; // esi
  int v13; // eax
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  AISplineRecorder *v22; // eax
  AISplineRecorder *v23; // eax
  CarAvatar *v24; // eax
  SplinePoint *v25; // xmm1_4
  float v26; // xmm2_4
  CarAvatar *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // [esp+20h] [ebp-F4h]
  float v31; // [esp+20h] [ebp-F4h]
  InterpolatingSpline *v32; // [esp+20h] [ebp-F4h]
  GLRenderer *v33; // [esp+24h] [ebp-F0h]
  Spline spline; // [esp+28h] [ebp-ECh] BYREF
  vec3f p; // [esp+40h] [ebp-D4h] BYREF
  vec3f v36; // [esp+4Ch] [ebp-C8h] BYREF
  float v37; // [esp+58h] [ebp-BCh]
  float v38; // [esp+5Ch] [ebp-B8h]
  float v39; // [esp+60h] [ebp-B4h]
  unsigned int v40; // [esp+64h] [ebp-B0h]
  vec3f v41; // [esp+68h] [ebp-ACh] BYREF
  Spline v42; // [esp+74h] [ebp-A0h] BYREF
  Spline v43; // [esp+8Ch] [ebp-88h] BYREF
  AISplinePayload result; // [esp+A4h] [ebp-70h] BYREF
  int v45; // [esp+110h] [ebp-4h]

  v2 = Sim::getFocusedCarIndex(this->sim);
  this->car = Sim::getCar(this->sim, v2);
  v3 = this->sim->game;
  v4 = mat44f::createIdentity((mat44f *)&result);
  GraphicsManager::setWorldMatrix(v3->graphics, v4);
  v5 = v3->graphics->gl;
  v33 = v5;
  this->interpolationDensity = Spline::length(&this->aiSpline->spline) * 0.2;
  GLRenderer::color3f(v5, 0.0, 3.0, 3.0);
  if ( Spline::pointsCount(&this->aiSpline->spline) )
  {
    Spline::Spline(&spline);
    v45 = 0;
    v30 = 0.0;
    GLRenderer::color3f(v5, 3.0, 0.0, 3.0);
    pos = 0.0;
    do
    {
      v7 = AISpline::getPointWithOffset(this->aiSpline, &v41, pos, 0.0, 0.69999999);
      Spline::addPoint(&spline, v7, 0);
      v30 = (float)(1.0 / this->interpolationDensity) + v30;
      pos = v30;
    }
    while ( v30 <= 1.0 );
    GLRenderer::spline(v5, &spline);
    v45 = -1;
    Spline::~Spline(&spline);
  }
  v8 = TrackAvatar::getSplineRecorder(this->car->sim->track);
  v9 = &AISplineRecorder::getPitLaneSpline(v8)->spline;
  if ( Spline::pointsCount(v9) )
  {
    Spline::Spline(&spline);
    v45 = 1;
    v31 = 0.0;
    GLRenderer::color3f(v33, 0.0, 3.0, 3.0);
    v10 = 0.0;
    do
    {
      v11 = InterpolatingSpline::splineToWorld(v9, &v41, v10);
      Spline::addPoint(&spline, v11, 0);
      v31 = (float)(1.0 / this->interpolationDensity) + v31;
      v10 = v31;
    }
    while ( v31 <= 1.0 );
    GLRenderer::spline(v33, &spline);
    v45 = -1;
    Spline::~Spline(&spline);
  }
  v32 = &this->aiSpline->spline;
  GLRenderer::color3f(v33, 3.0, 0.0, 0.0);
  Spline::Spline(&v42);
  v45 = 2;
  Spline::Spline(&v43);
  v12 = 0;
  for ( LOBYTE(v45) = 3; v12 < Spline::pointsCount(v32); v12 = v40 )
  {
    Spline::pointAt(v32, &v36, v12);
    v40 = v12 + 1;
    v13 = Spline::wrapIndex(v32, v12 + 1);
    Spline::pointAt(v32, &v41, v13);
    AISpline::payloadAtSplineIndex(this->aiSpline, &result, v12);
    v14 = 0.0;
    v15 = v41.x - v36.x;
    v16 = v41.z - v36.z;
    v17 = fsqrt((float)(v15 * v15) + (float)(v16 * v16));
    if ( v17 != 0.0 )
    {
      v15 = (float)(1.0 / v17) * v15;
      v14 = (float)(1.0 / v17) * 0.0;
      v16 = (float)(1.0 / v17) * v16;
    }
    v18 = v15 * 0.0;
    v19 = v15 - (float)(v14 * 0.0);
    v20 = (float)(v14 * 0.0) - v16;
    v39 = v20;
    v37 = v19;
    v21 = (float)(v16 * 0.0) - v18;
    v38 = v21;
    if ( result.sides[0] != 0.0 )
    {
      p.x = v36.x + (float)(v20 * COERCE_FLOAT(LODWORD(result.sides[0]) ^ _xmm));
      p.y = v36.y + (float)(v21 * COERCE_FLOAT(LODWORD(result.sides[0]) ^ _xmm));
      p.z = v36.z + (float)(v19 * COERCE_FLOAT(LODWORD(result.sides[0]) ^ _xmm));
      Spline::addPoint(&v42, &p, 0);
      *(float *)&spline.__vftable = v36.x + (float)(result.sides[1] * v39);
      *(float *)&spline.points._Myfirst = v36.y + (float)(result.sides[1] * v38);
      *(float *)&spline.points._Mylast = v36.z + (float)(result.sides[1] * v37);
      Spline::addPoint(&v43, (const vec3f *)&spline, 0);
    }
  }
  GLRenderer::spline(v33, &v42);
  GLRenderer::spline(v33, &v43);
  LOBYTE(v45) = 2;
  Spline::~Spline(&v43);
  v45 = -1;
  Spline::~Spline(&v42);
  GLRenderer::color4f(v33, 3.0, 3.0, 0.0, 1.0);
  v22 = TrackAvatar::getSplineRecorder(this->car->sim->track);
  GLRenderer::spline(v33, &v22->leftSpline);
  v23 = TrackAvatar::getSplineRecorder(this->car->sim->track);
  GLRenderer::spline(v33, &v23->rightSpline);
  GLRenderer::begin(v33, eLines, 0);
  GLRenderer::color3f(v33, 3.0, 3.0, 0.0);
  v24 = this->car;
  v25 = (SplinePoint *)LODWORD(v24->aiState.steerTarget.z);
  v26 = v24->aiState.steerTarget.y - -10.0;
  spline.__vftable = (Spline_vtbl *)LODWORD(v24->aiState.steerTarget.x);
  spline.points._Mylast = v25;
  *(float *)&spline.points._Myfirst = v26;
  GLRenderer::vertex3fv(v33, (const float *)&spline);
  v27 = this->car;
  v28 = v27->aiState.steerTarget.z;
  v29 = v27->aiState.steerTarget.y - 50.0;
  p.x = v27->aiState.steerTarget.x;
  p.z = v28;
  p.y = v29;
  GLRenderer::vertex3fv(v33, &p.x);
  GLRenderer::end(v33);
}
