#include "cameraonboard.h
void __userpurge CameraOnBoard::CameraOnBoard(CameraOnBoard *this@<ecx>, char a2@<bl>, __m128 a3@<xmm0>, Game *igame, CameraForward *cam, Sim *aSim)
{
  Game *v7; // eax
  Event<OnReplayStatusChanged> *v8; // ecx
  Sim *v9; // ecx
  double v10; // st7
  bool v11; // cf
  double v12; // st7
  double v13; // st7
  vec3f *v14; // eax
  double v15; // st7
  int v16; // eax
  double v17; // st7
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  float v20; // xmm0_4
  float v21; // xmm0_4
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  float v24; // xmm1_4
  unsigned int v25; // esi
  std::forward_iterator_tag v26; // bp
  CarAvatar *v27; // eax
  std::wstring *v28; // eax
  const std::wstring *v29; // eax
  CarAvatar *v30; // ecx
  double v31; // st7
  vec3f *v32; // eax
  __int64 v33; // xmm0_8
  float v34; // eax
  std::wstring *v35; // ecx
  std::wstring *v36; // edx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v37; // eax
  std::wstring *v38; // eax
  std::wstring *v39; // eax
  std::wstring *v40; // eax
  const std::wstring *v41; // eax
  CarAvatar *v42; // eax
  std::wstring *v43; // eax
  CarAvatar *v44; // eax
  __m128 v45; // xmm1
  float v46; // xmm0_4
  std::wstring v47; // [esp-1Ch] [ebp-27Ch] BYREF
  Game *v48; // [esp-4h] [ebp-264h]
  vec3f shakeMul; // [esp+1Ch] [ebp-244h] OVERLAPPED
  CameraOnBoardCustomSettings ccs; // [esp+28h] [ebp-238h] BYREF
  std::forward_iterator_tag __formal[4]; // [esp+30h] [ebp-230h]
  ModelBoundariesCoordinates boundaries; // [esp+38h] [ebp-228h]
  std::wstring section; // [esp+50h] [ebp-210h] BYREF
  vec3f gForceMult; // [esp+68h] [ebp-1F8h] BYREF
  int v55; // [esp+78h] [ebp-1E8h]
  unsigned int v56; // [esp+7Ch] [ebp-1E4h]
  std::wstring _Right; // [esp+80h] [ebp-1E0h] BYREF
  std::wstring key; // [esp+98h] [ebp-1C8h] BYREF
  vec3f offsetBoundary; // [esp+B0h] [ebp-1B0h] BYREF
  int v60; // [esp+C0h] [ebp-1A0h]
  unsigned int v61; // [esp+C4h] [ebp-19Ch]
  std::wstring v62; // [esp+C8h] [ebp-198h] BYREF
  std::wstring result; // [esp+E0h] [ebp-180h] BYREF
  std::wstring v64; // [esp+F8h] [ebp-168h] BYREF
  std::wstring v65; // [esp+110h] [ebp-150h] BYREF
  std::wstring iniName; // [esp+128h] [ebp-138h] BYREF
  INIReaderDocuments r; // [esp+140h] [ebp-120h] BYREF
  INIReader carR; // [esp+184h] [ebp-DCh] BYREF
  INIReaderDocuments shakeIni; // [esp+1C8h] [ebp-98h] BYREF
  INIReaderDocuments dR; // [esp+20Ch] [ebp-54h] BYREF
  int v71; // [esp+25Ch] [ebp-4h]

  v48 = igame;
  *(_DWORD *)&__formal[0].gap0 = this;
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  std::wstring::assign(&v47, L"CAMERA_ONBOARD", 0xEu);
  GameObject::GameObject(this, v47, v48);
  this->__vftable = (CameraOnBoard_vtbl *)&CameraOnBoard::`vftable';
  this->camera = cam;
  v48 = 0;
  v71 = 0;
  this->offset.x = 0.0;
  this->offset.y = 0.0;
  this->offset.z = 0.0;
  this->car = Sim::getCar(aSim, (unsigned int)v48);
  this->gForceMix.x = 0.0;
  this->gForceMix.y = 0.0;
  this->gForceMix.z = 0.0;
  this->onBoardFov = 54.0;
  this->farPlane = 15000.0;
  this->lookBackPoints._Myfirst = 0;
  this->lookBackPoints._Mylast = 0;
  this->lookBackPoints._Myend = 0;
  this->customCameraSettings._Myfirst = 0;
  this->customCameraSettings._Mylast = 0;
  this->customCameraSettings._Myend = 0;
  this->gForceMixCurrentOffset.x = 0.0;
  this->gForceMixCurrentOffset.y = 0.0;
  this->gForceMixCurrentOffset.z = 0.0;
  this->shakeFreq.x = 0.0;
  this->shakeFreq.y = 0.0;
  this->shakeFreq.z = 0.0;
  LOBYTE(v71) = 2;
  this->shakeScale.x = 0.0;
  this->shakeScale.y = 0.0;
  this->shakeScale.z = 0.0;
  SignalGenerator3D<SinSignalGenerator>::SignalGenerator3D<SinSignalGenerator>(&this->shakeGenerator, a3);
  v7 = this->game;
  LOBYTE(v71) = 3;
  TrackIR::TrackIR(&this->trackIR, (HWND__ *)v7->window.hWnd);
  v48 = (Game *)this;
  this->sim = aSim;
  v47._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_574220c074d6cb5b1f0e3bb8d3111ead_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v47._Bx._Alias[4] = this;
  v47._Mysize = (unsigned int)&v47;
  v8 = &this->sim->evOnReplayStatusChanged;
  LOBYTE(v71) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v8,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v47,
    v48);
  v48 = (Game *)this;
  v47._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_c71de86c4bb0f8d72ecae5d8ef806e87_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v47._Bx._Alias[4] = this;
  v47._Mysize = (unsigned int)&v47;
  v9 = this->sim;
  LOBYTE(v71) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v9->evOnPauseModeChanged,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v47,
    this);
  *(_QWORD *)&this->gForceMix.x = _mm_unpacklo_ps(
                                    (__m128)LODWORD(FLOAT_N0_0020000001),
                                    (__m128)LODWORD(FLOAT_N0_0020000001)).m128_u64[0];
  v48 = 0;
  this->gForceMix.z = -0.0024999999;
  *(_QWORD *)&this->shakeScale.x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_00019999999)).m128_u64[0];
  this->shakeScale.z = 0.00015000001;
  *(_QWORD *)&this->shakeFreq.x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_100_05), (__m128)LODWORD(FLOAT_100_05)).m128_u64[0];
  this->stillCamera = 0;
  this->isWorldAligned = 1;
  this->gForceLagMix = 0.80000001;
  this->headRotationAnimation = 0.0;
  this->headRotationSpeed = 5.0;
  this->headRotationDegrees = 60.0;
  gForceMult.z = 100.05;
  this->shakeFreq.z = 100.05;
  this->shakeGenerator.randomBlend = 0.5;
  this->shakeMul = 1.0;
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  std::wstring::assign(&v47, L"cfg/camera_onboard.ini", 0x16u);
  INIReaderDocuments::INIReaderDocuments(&r, a2, v47, (bool)v48);
  LOBYTE(v71) = 7;
  if ( r.ready )
  {
    v56 = 7;
    v55 = 0;
    LOWORD(gForceMult.x) = 0;
    std::wstring::assign((std::wstring *)&gForceMult, L"LAG", 3u);
    LOBYTE(v71) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GFORCES", 7u);
    LOBYTE(v71) = 9;
    v10 = INIReader::getFloat(&r, &section, (const std::wstring *)&gForceMult);
    v11 = section._Myres < 8;
    this->gForceLagMix = v10;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 7;
    if ( v56 >= 8 )
      operator delete(LODWORD(gForceMult.x));
    v56 = 7;
    v55 = 0;
    LOWORD(gForceMult.x) = 0;
    std::wstring::assign((std::wstring *)&gForceMult, L"HEAD_MAX_DEGREES", 0x10u);
    LOBYTE(v71) = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ROTATION", 8u);
    LOBYTE(v71) = 11;
    v12 = INIReader::getFloat(&r, &section, (const std::wstring *)&gForceMult);
    v11 = section._Myres < 8;
    this->headRotationDegrees = v12;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 7;
    if ( v56 >= 8 )
      operator delete(LODWORD(gForceMult.x));
    v56 = 7;
    v55 = 0;
    LOWORD(gForceMult.x) = 0;
    std::wstring::assign((std::wstring *)&gForceMult, L"SPEED", 5u);
    LOBYTE(v71) = 12;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ROTATION", 8u);
    LOBYTE(v71) = 13;
    v13 = INIReader::getFloat(&r, &section, (const std::wstring *)&gForceMult);
    v11 = section._Myres < 8;
    this->headRotationSpeed = v13;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 7;
    if ( v56 >= 8 )
      operator delete(LODWORD(gForceMult.x));
    v61 = 7;
    v60 = 0;
    LOWORD(offsetBoundary.x) = 0;
    std::wstring::assign((std::wstring *)&offsetBoundary, L"FREQ", 4u);
    LOBYTE(v71) = 14;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHAKE", 5u);
    LOBYTE(v71) = 15;
    v14 = INIReader::getFloat3(&r, &gForceMult, &section, (const std::wstring *)&offsetBoundary);
    v11 = section._Myres < 8;
    this->shakeFreq = *v14;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 7;
    if ( v61 >= 8 )
      operator delete(LODWORD(offsetBoundary.x));
    v56 = 7;
    v55 = 0;
    LOWORD(gForceMult.x) = 0;
    std::wstring::assign((std::wstring *)&gForceMult, L"RANDOM", 6u);
    LOBYTE(v71) = 16;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHAKE", 5u);
    LOBYTE(v71) = 17;
    v15 = INIReader::getFloat(&r, &section, (const std::wstring *)&gForceMult);
    v11 = section._Myres < 8;
    this->shakeGenerator.randomBlend = v15;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 7;
    if ( v56 >= 8 )
      operator delete(LODWORD(gForceMult.x));
    v56 = 7;
    v55 = 0;
    LOWORD(gForceMult.x) = 0;
    std::wstring::assign((std::wstring *)&gForceMult, L"IS_WORLD_ALIGNED", 0x10u);
    LOBYTE(v71) = 18;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"MODE", 4u);
    LOBYTE(v71) = 19;
    v16 = INIReader::getInt(&r, &section, (const std::wstring *)&gForceMult);
    v11 = section._Myres < 8;
    this->isWorldAligned = v16 != 0;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 7;
    if ( v56 >= 8 )
      operator delete(LODWORD(gForceMult.x));
    v56 = 7;
    v55 = 0;
    LOWORD(gForceMult.x) = 0;
    std::wstring::assign((std::wstring *)&gForceMult, L"FOV", 3u);
    LOBYTE(v71) = 20;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"MODE", 4u);
    LOBYTE(v71) = 21;
    v17 = INIReader::getFloat(&r, &section, (const std::wstring *)&gForceMult);
    v11 = section._Myres < 8;
    this->onBoardFov = v17;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 7;
    if ( v56 >= 8 )
      operator delete(LODWORD(gForceMult.x));
    if ( this->onBoardFov == 0.0 )
      this->onBoardFov = 54.0;
  }
  v48 = 0;
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  std::wstring::assign(&v47, L"cfg/camera_manager.ini", 0x16u);
  INIReaderDocuments::INIReaderDocuments(&shakeIni, a2, v47, (bool)v48);
  LOBYTE(v71) = 22;
  if ( shakeIni.ready )
  {
    std::wstring::wstring(&key, L"GFORCEZ");
    LOBYTE(v71) = 23;
    std::wstring::wstring(&_Right, L"SHAKE");
    LOBYTE(v71) = 24;
    std::wstring::wstring(&v62, L"GFORCEY");
    LOBYTE(v71) = 25;
    std::wstring::wstring(&result, L"SHAKE");
    LOBYTE(v71) = 26;
    std::wstring::wstring((std::wstring *)&offsetBoundary, L"GFORCEX");
    LOBYTE(v71) = 27;
    std::wstring::wstring(&section, L"SHAKE");
    LOBYTE(v71) = 28;
    shakeMul.y = INIReader::getFloat(&shakeIni, &_Right, &key);
    shakeMul.x = INIReader::getFloat(&shakeIni, &result, &v62);
    gForceMult.x = INIReader::getFloat(&shakeIni, &section, (const std::wstring *)&offsetBoundary);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( v61 >= 8 )
      operator delete(LODWORD(offsetBoundary.x));
    v61 = 7;
    v60 = 0;
    LOWORD(offsetBoundary.x) = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v62._Myres >= 8 )
      operator delete(v62._Bx._Ptr);
    v62._Myres = 7;
    v62._Mysize = 0;
    v62._Bx._Buf[0] = 0;
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    LOBYTE(v71) = 22;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v18 = (__m128)LODWORD(this->gForceMix.y);
    v19 = (__m128)LODWORD(gForceMult.x);
    v20 = this->gForceMix.z;
    v19.m128_f32[0] = gForceMult.x * this->gForceMix.x;
    v48 = (Game *)L"SHAKEMULT";
    v18.m128_f32[0] = v18.m128_f32[0] * shakeMul.x;
    v21 = v20 * shakeMul.y;
    *(_QWORD *)&this->gForceMix.x = _mm_unpacklo_ps(v19, v18).m128_u64[0];
    gForceMult.z = v21;
    this->gForceMix.z = v21;
    std::wstring::wstring(&key, (const wchar_t *)v48);
    LOBYTE(v71) = 29;
    std::wstring::wstring(&_Right, L"SHAKE");
    LOBYTE(v71) = 30;
    shakeMul.x = INIReader::getFloat(&shakeIni, &_Right, &key);
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    LOBYTE(v71) = 22;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v22 = (__m128)LODWORD(this->shakeScale.x);
    v23 = (__m128)LODWORD(this->shakeScale.y);
    v22.m128_f32[0] = v22.m128_f32[0] * shakeMul.x;
    v23.m128_f32[0] = v23.m128_f32[0] * shakeMul.x;
    v24 = this->shakeScale.z * shakeMul.x;
    *(_QWORD *)&this->shakeScale.x = _mm_unpacklo_ps(v22, v23).m128_u64[0];
    gForceMult.z = v24;
    this->shakeScale.z = v24;
  }
  v25 = 0;
  if ( this->sim->cars._Mylast - this->sim->cars._Myfirst )
  {
    v26.gap0 = __formal[0].gap0;
    do
    {
      v27 = Sim::getCar(this->sim, v25);
      v28 = std::operator+<wchar_t>(&result, L"content/cars/", &v27->unixName);
      LOBYTE(v71) = 31;
      v29 = std::operator+<wchar_t>(&v62, v28, L"/data/car.ini");
      v30 = this->car;
      LOBYTE(v71) = 32;
      CarAvatar::openINI(v30, &carR, v29);
      if ( v62._Myres >= 8 )
        operator delete(v62._Bx._Ptr);
      v62._Myres = 7;
      v62._Mysize = 0;
      v62._Bx._Buf[0] = 0;
      LOBYTE(v71) = 35;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      ccs.pitch = 0.0;
      ccs.yaw = 0.0;
      *(_QWORD *)&shakeMul.x = 0i64;
      shakeMul.z = 0.0;
      if ( carR.ready )
      {
        std::wstring::wstring(&key, L"ON_BOARD_PITCH_ANGLE");
        LOBYTE(v71) = 36;
        std::wstring::wstring(&_Right, L"GRAPHICS");
        LOBYTE(v71) = 37;
        ccs.pitch = INIReader::getFloat(&carR, &_Right, &key) * 0.017453;
        if ( _Right._Myres >= 8 )
          operator delete(_Right._Bx._Ptr);
        _Right._Myres = 7;
        _Right._Mysize = 0;
        _Right._Bx._Buf[0] = 0;
        LOBYTE(v71) = 35;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        std::wstring::wstring(&key, L"SHAKE_MUL");
        LOBYTE(v71) = 38;
        std::wstring::wstring(&_Right, L"GRAPHICS");
        LOBYTE(v71) = 39;
        v31 = INIReader::getFloat(&carR, &_Right, &key);
        v11 = _Right._Myres < 8;
        this->shakeMul = v31;
        if ( !v11 )
          operator delete(_Right._Bx._Ptr);
        _Right._Myres = 7;
        _Right._Mysize = 0;
        _Right._Bx._Buf[0] = 0;
        LOBYTE(v71) = 35;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        if ( this->shakeMul == 0.0 )
          this->shakeMul = 1.0;
        std::wstring::wstring(&key, L"ON_BOARD_LOOKBACK_OFFSET");
        LOBYTE(v71) = 40;
        std::wstring::wstring(&_Right, L"GRAPHICS");
        LOBYTE(v71) = 41;
        a2 = INIReader::hasKey(&carR, &_Right, &key);
        if ( _Right._Myres >= 8 )
          operator delete(_Right._Bx._Ptr);
        _Right._Myres = 7;
        _Right._Mysize = 0;
        _Right._Bx._Buf[0] = 0;
        LOBYTE(v71) = 35;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        if ( a2 )
        {
          std::wstring::wstring(&key, L"ON_BOARD_LOOKBACK_OFFSET");
          LOBYTE(v71) = 42;
          std::wstring::wstring(&_Right, L"GRAPHICS");
          LOBYTE(v71) = 43;
          v32 = INIReader::getFloat3(&carR, (vec3f *)&section, &_Right, &key);
          v33 = *(_QWORD *)&v32->x;
          v34 = v32->z;
          *(_QWORD *)&offsetBoundary.x = v33;
          offsetBoundary.z = v34;
          if ( _Right._Myres >= 8 )
            operator delete(_Right._Bx._Ptr);
          _Right._Myres = 7;
          _Right._Mysize = 0;
          _Right._Bx._Buf[0] = 0;
          LOBYTE(v71) = 35;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          shakeMul = offsetBoundary;
        }
      }
      v35 = &this->car->unixName;
      if ( this->car->unixName._Myres < 8 )
        v36 = &this->car->unixName;
      else
        v36 = (std::wstring *)v35->_Bx._Ptr;
      v37._Ptr = &v36->_Bx._Buf[this->car->unixName._Mysize];
      if ( this->car->unixName._Myres >= 8 )
        v35 = (std::wstring *)v35->_Bx._Ptr;
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
        &_Right,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v35,
        v37,
        v26);
      LOBYTE(v71) = 44;
      v38 = Path::getDocumentPath(&key);
      LOBYTE(v71) = 45;
      v39 = std::operator+<wchar_t>(&v64, v38, L"/Assetto Corsa/cfg/cars/");
      LOBYTE(v71) = 46;
      v40 = std::operator+<wchar_t>(&iniName, v39, &_Right);
      LOBYTE(v71) = 47;
      v41 = std::operator+<wchar_t>(&v65, v40, L"/view.ini");
      LOBYTE(v71) = 48;
      a2 = Path::fileExists(a2, v41, 0);
      if ( v65._Myres >= 8 )
        operator delete(v65._Bx._Ptr);
      v65._Myres = 7;
      v65._Mysize = 0;
      v65._Bx._Buf[0] = 0;
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
      if ( v64._Myres >= 8 )
        operator delete(v64._Bx._Ptr);
      v64._Myres = 7;
      v64._Mysize = 0;
      v64._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v71) = 35;
      if ( _Right._Myres >= 8 )
        operator delete(_Right._Bx._Ptr);
      if ( a2 )
      {
        v42 = this->car;
        v48 = 0;
        v43 = std::operator+<wchar_t>(&key, L"cfg/cars/", &v42->unixName);
        LOBYTE(v71) = 49;
        std::operator+<wchar_t>(&v47, v43, L"/view.ini");
        INIReaderDocuments::INIReaderDocuments(&dR, a2, v47, (bool)v48);
        LOBYTE(v71) = 51;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( dR.ready )
        {
          std::wstring::wstring(&v64, L"ON_BOARD_PITCH_ANGLE");
          LOBYTE(v71) = 52;
          std::wstring::wstring(&_Right, L"CAMERA");
          LOBYTE(v71) = 53;
          ccs.pitch = INIReader::getFloat(&dR, &_Right, &v64);
          if ( _Right._Myres >= 8 )
            operator delete(_Right._Bx._Ptr);
          _Right._Myres = 7;
          _Right._Mysize = 0;
          _Right._Bx._Buf[0] = 0;
          if ( v64._Myres >= 8 )
            operator delete(v64._Bx._Ptr);
        }
        LOBYTE(v71) = 35;
        INIReaderDocuments::~INIReaderDocuments(&dR);
      }
      std::vector<DRSWingSetting>::push_back(
        (std::vector<PerformancePair> *)&this->customCameraSettings,
        (PerformancePair *)&ccs);
      v44 = Sim::getCar(this->sim, v25);
      v45 = (__m128)_mm_loadu_si128((const __m128i *)&v44->modelBoundaries);
      *(_QWORD *)&boundaries.top = *(_QWORD *)&v44->modelBoundaries.top;
      v46 = _mm_shuffle_ps(v45, v45, 255).m128_f32[0] + v44->modelBoundaries.left;
      gForceMult.y = shakeMul.y + boundaries.top;
      gForceMult.z = shakeMul.z + _mm_shuffle_ps(v45, v45, 85).m128_f32[0];
      gForceMult.x = (float)(v46 * 0.5) + shakeMul.x;
      std::vector<DRSZone>::push_back(&this->lookBackPoints, &gForceMult);
      LOBYTE(v71) = 22;
      INIReader::~INIReader(&carR);
      ++v25;
    }
    while ( v25 < this->sim->cars._Mylast - this->sim->cars._Myfirst );
  }
  LOBYTE(v71) = 7;
  INIReaderDocuments::~INIReaderDocuments(&shakeIni);
  LOBYTE(v71) = 4;
  INIReaderDocuments::~INIReaderDocuments(&r);
}
void CameraOnBoard::~CameraOnBoard(CameraOnBoard *this)
{
  std::vector<CameraOnBoardCustomSettings> *v2; // esi

  this->__vftable = (CameraOnBoard_vtbl *)&CameraOnBoard::`vftable';
  TrackIR::~TrackIR(&this->trackIR);
  this->shakeGenerator.__vftable = (SignalGenerator3D<SinSignalGenerator>_vtbl *)&SignalGenerator3D<SinSignalGenerator>::`vftable';
  `eh vector destructor iterator'(
    this->shakeGenerator.sins,
    0xCu,
    3,
    (void (*)(void *))SinSignalGenerator::~SinSignalGenerator);
  v2 = &this->customCameraSettings;
  if ( this->customCameraSettings._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->customCameraSettings);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    this->customCameraSettings._Mylast = 0;
    this->customCameraSettings._Myend = 0;
  }
  if ( this->lookBackPoints._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lookBackPoints);
    operator delete(this->lookBackPoints._Myfirst);
    this->lookBackPoints._Myfirst = 0;
    this->lookBackPoints._Mylast = 0;
    this->lookBackPoints._Myend = 0;
  }
  GameObject::~GameObject(this);
}
CameraOnBoard *CameraOnBoard::`vector deleting destructor'(CameraOnBoard *this, unsigned int a2)
{
  CameraOnBoard::~CameraOnBoard(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraOnBoard::lookBack(CameraOnBoard *this)
{
  unsigned int v2; // eax
  CarAvatar *v3; // esi
  CameraForward *v4; // ecx
  float v5; // xmm5_4
  float v6; // xmm1_4
  vec3f lookPoint; // [esp+Ch] [ebp-Ch]

  v2 = Sim::getFocusedCarIndex(this->sim);
  v3 = Sim::getCar(this->sim, v2);
  lookPoint = this->lookBackPoints._Myfirst[Sim::getFocusedCarIndex(this->sim)];
  v4 = this->camera;
  v5 = (float)((float)((float)(v3->bodyMatrix.M22 * lookPoint.y) + (float)(v3->bodyMatrix.M12 * lookPoint.x))
             + (float)(v3->bodyMatrix.M32 * lookPoint.z))
     + v3->bodyMatrix.M42;
  v6 = (float)((float)((float)(v3->bodyMatrix.M23 * lookPoint.y) + (float)(v3->bodyMatrix.M13 * lookPoint.x))
             + (float)(v3->bodyMatrix.M33 * lookPoint.z))
     + v3->bodyMatrix.M43;
  v4->matrix.M41 = (float)((float)((float)(v3->bodyMatrix.M21 * lookPoint.y) + (float)(v3->bodyMatrix.M11 * lookPoint.x))
                         + (float)(v3->bodyMatrix.M31 * lookPoint.z))
                 + v3->bodyMatrix.M41;
  v4->matrix.M42 = v5;
  v4->matrix.M43 = v6;
  Camera::rotateHeading(v4, (int)v3, 3.1415401);
}
void CameraOnBoard::lookLeftRight(CameraOnBoard *this, float dt)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  float v5; // xmm2_4
  int v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  unsigned int v18; // eax
  unsigned int v19; // eax
  float v20; // [esp+8h] [ebp-4h]

  v20 = 0.0;
  v3 = Sim::getFocusedCarIndex(this->sim);
  if ( (Sim::getCar(this->sim, v3)->physicsState.actionsState.state & 1) != 0 )
    v20 = FLOAT_1_0;
  v4 = Sim::getFocusedCarIndex(this->sim);
  if ( (Sim::getCar(this->sim, v4)->physicsState.actionsState.state & 2) != 0 )
    v5 = FLOAT_N1_0;
  else
    v5 = v20;
  v6 = _xmm;
  v7 = this->headRotationAnimation;
  v8 = this->headRotationSpeed * dt;
  v9 = COERCE_FLOAT(COERCE_UNSIGNED_INT(this->headRotationDegrees * v5) & _xmm) * 0.017453;
  if ( (float)(COERCE_FLOAT(LODWORD(v9) & _xmm) - COERCE_FLOAT(LODWORD(this->headRotationAnimation) & _xmm)) > v8 )
  {
    this->headRotationAnimation = (float)(v8 * v5) + v7;
    goto LABEL_39;
  }
  if ( v9 == 0.0 )
    goto LABEL_32;
  v10 = FLOAT_1_0;
  if ( v5 <= 0.0 )
  {
    if ( v5 >= 0.0 )
      v11 = 0.0;
    else
      v11 = FLOAT_N1_0;
  }
  else
  {
    v11 = FLOAT_1_0;
  }
  if ( v7 <= 0.0 )
  {
    if ( v7 >= 0.0 )
      v12 = 0.0;
    else
      v12 = FLOAT_N1_0;
  }
  else
  {
    v12 = FLOAT_1_0;
  }
  if ( v11 == v12 )
  {
    this->headRotationAnimation = v9 * v5;
    goto LABEL_39;
  }
  if ( v5 <= 0.0 )
  {
    if ( v5 >= 0.0 )
      v13 = 0.0;
    else
      v13 = FLOAT_N1_0;
  }
  else
  {
    v13 = FLOAT_1_0;
  }
  v14 = this->headRotationAnimation;
  if ( v14 <= 0.0 )
  {
    if ( v14 >= 0.0 )
      v10 = 0.0;
    else
      v10 = FLOAT_N1_0;
  }
  if ( v13 != v10 )
  {
    v6 = _xmm;
LABEL_32:
    v15 = this->headRotationAnimation;
    if ( v15 <= 0.0 )
    {
      if ( v15 >= 0.0 )
        v16 = 0.0;
      else
        v16 = FLOAT_N1_0;
    }
    else
    {
      v16 = FLOAT_1_0;
    }
    v17 = (float)(COERCE_FLOAT(LODWORD(this->headRotationAnimation) & v6) - v8) * v16;
    this->headRotationAnimation = v17;
    if ( v8 > (float)(COERCE_FLOAT(LODWORD(v17) & v6) - v8) )
      this->headRotationAnimation = 0.0;
  }
LABEL_39:
  v18 = Sim::getFocusedCarIndex(this->sim);
  Camera::rotateHeading(
    this->camera,
    (int)this,
    this->customCameraSettings._Myfirst[v18].yaw + this->headRotationAnimation);
  v19 = Sim::getFocusedCarIndex(this->sim);
  Camera::rotatePitch(this->camera, (int)this, this->customCameraSettings._Myfirst[v19].pitch);
}
void CameraOnBoard::update(CameraOnBoard *this, float deltaT)
{
  CameraOnBoard *v2; // edi
  float v3; // xmm0_4
  CameraForward *v4; // eax
  unsigned int v5; // eax
  CarAvatar *v6; // eax
  int v7; // esi
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  CameraForward *v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm5_4
  float v26; // xmm0_4
  float *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm4_4
  float v35; // xmm4_4
  float *v36; // eax
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm5_4
  float v41; // xmm4_4
  __m128 v42; // xmm3
  float v43; // xmm6_4
  float v44; // xmm5_4
  float v45; // xmm0_4
  __m128 v46; // xmm2
  float v47; // xmm4_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm3_4
  __m128 v51; // xmm2
  SignalGenerator3D<SinSignalGenerator> *v52; // esi
  __m128 v53; // xmm1
  float v54; // xmm0_4
  __m128 v55; // xmm2
  __m128 v56; // xmm1
  unsigned int v57; // xmm0_4
  unsigned int v58; // eax
  float v59; // xmm0_4
  float *v60; // edi
  int v61; // eax
  float v62; // xmm3_4
  float v63; // xmm4_4
  float v64; // xmm1_4
  float v65; // xmm5_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  float v68; // xmm0_4
  float *v69; // eax
  float v70; // xmm2_4
  float v71; // xmm1_4
  CameraForward *v72; // eax
  __m128 v73; // xmm5
  __m128 v74; // xmm6
  __m128 v75; // xmm7
  __m128 v76; // xmm0
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v77; // xmm0
  float v78; // xmm1_4
  float v79; // xmm2_4
  int v80; // eax
  const mat44f *v81; // eax
  char v82; // [esp+1Ch] [ebp-10Ch] BYREF
  _QWORD v83[3]; // [esp+44h] [ebp-E4h]
  CameraOnBoard *v84; // [esp+5Ch] [ebp-CCh]
  int v85; // [esp+60h] [ebp-C8h]
  float dt; // [esp+64h] [ebp-C4h]
  vec3f pos; // [esp+68h] [ebp-C0h] BYREF
  float v88; // [esp+74h] [ebp-B4h]
  float v89; // [esp+78h] [ebp-B0h]
  float v90; // [esp+7Ch] [ebp-ACh]
  bool v91; // [esp+83h] [ebp-A5h]
  float v92; // [esp+84h] [ebp-A4h]
  float v93; // [esp+88h] [ebp-A0h]
  INIReader v94; // [esp+8Ch] [ebp-9Ch] BYREF
  std::wstring ifilename; // [esp+D0h] [ebp-58h] BYREF
  std::wstring section; // [esp+E8h] [ebp-40h] BYREF
  std::wstring key; // [esp+100h] [ebp-28h] BYREF
  int v98; // [esp+124h] [ebp-4h]

  v2 = this;
  v84 = this;
  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
    v3 = v2->car->sim->replayManager->timeMult * deltaT;
  else
    v3 = deltaT;
  v4 = v2->camera;
  dt = v3;
  v4->tripleScreenAvailable = 1;
  v5 = Sim::getFocusedCarIndex(v2->sim);
  v6 = Sim::getCar(v2->sim, v5);
  v2->car = v6;
  v2->camera->blurRadialSpeed = v6->physicsState.speed.value;
  v7 = (int)v2->car;
  v85 = v7;
  v8 = *(float *)(v7 + 380);
  v9 = COERCE_FLOAT(*(_DWORD *)(v7 + 396) ^ _xmm) * -1.0;
  v10 = COERCE_FLOAT(*(_DWORD *)(v7 + 400) ^ _xmm) * -1.0;
  v11 = COERCE_FLOAT(*(_DWORD *)(v7 + 404) ^ _xmm) * -1.0;
  v92 = *(float *)(v7 + 388);
  v12 = *(float *)(v7 + 384);
  v90 = v10;
  v13 = fsqrt((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v11 * v11));
  if ( v13 != 0.0 )
  {
    v14 = 1.0 / v13;
    v9 = v9 * v14;
    v11 = v14 * v11;
    v90 = v14 * v90;
  }
  v15 = fsqrt((float)((float)(v8 * v8) + (float)(v12 * v12)) + (float)(v92 * v92));
  if ( v15 != 0.0 )
  {
    v8 = v8 * (float)(1.0 / v15);
    v12 = v12 * (float)(1.0 / v15);
    v92 = v92 * (float)(1.0 / v15);
  }
  if ( v2->isWorldAligned )
  {
    key._Myres = 0;
    *(_QWORD *)&pos.x = _mm_unpacklo_ps((__m128)0i64, (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
    pos.z = 0.0;
    v90 = 0.0;
    v16 = fsqrt((float)(v11 * v11) + (float)(v9 * v9));
    if ( v16 != 0.0 )
    {
      v9 = v9 * (float)(1.0 / v16);
      v11 = v11 * (float)(1.0 / v16);
      v90 = (float)(1.0 / v16) * 0.0;
    }
    v12 = pos.y;
    v17 = fsqrt(1.0);
    if ( v17 == 0.0 )
    {
      v19 = pos.z;
      v8 = pos.x;
      v92 = pos.z;
    }
    else
    {
      v18 = 1.0 / v17;
      v19 = pos.z * (float)(1.0 / v17);
      v8 = v18 * 0.0;
      v12 = pos.y * v18;
      v92 = pos.z * v18;
    }
  }
  else
  {
    v19 = v92;
  }
  v20 = v2->camera;
  v93 = (float)(v19 * v90) - (float)(v12 * v11);
  v88 = (float)(v8 * v11) - (float)(v19 * v9);
  v89 = (float)(v12 * v9) - (float)(v8 * v90);
  v21 = fsqrt((float)((float)(v93 * v93) + (float)(v88 * v88)) + (float)(v89 * v89));
  v22 = v88;
  if ( v21 == 0.0 )
  {
    v24 = v93;
    v25 = v89;
  }
  else
  {
    v23 = 1.0 / v21;
    v24 = v93 * (float)(1.0 / v21);
    v22 = v88 * v23;
    v25 = v89 * v23;
  }
  LODWORD(v20->matrix.M32) = LODWORD(v90) ^ _xmm;
  v26 = v92;
  LODWORD(v20->matrix.M31) = LODWORD(v9) ^ _xmm;
  LODWORD(v20->matrix.M33) = LODWORD(v11) ^ _xmm;
  v20->matrix.M21 = v8;
  v20->matrix.M22 = v12;
  v20->matrix.M23 = v26;
  v20->matrix.M11 = v24;
  v20->matrix.M12 = v22;
  v20->matrix.M13 = v25;
  v2->camera->fov = v2->onBoardFov;
  v2->camera->farPlane = v2->farPlane;
  v2->camera->nearPlane = 0.050000001;
  v2->camera->dofFactor = 0.0;
  std::wstring::assign(&v2->camera->name, L"ON_BOARD", 8u);
  v2->camera->chromaticAberrationEnabled = 0;
  v2->camera->lensFlare = 0;
  CameraShadowMapped::setShadowMapsSplits(v2->camera, 1.3, 80.0, 250.0, 500.0);
  v2->camera->exposure = v2->car->onBoardExposure;
  v2->camera->minExposure = v2->car->sim->hdrLevels.minExposure;
  v2->camera->maxExposure = v2->car->sim->hdrLevels.maxExposure;
  v27 = (float *)v2->car;
  v28 = v27[88];
  v29 = v27[89];
  v30 = v27[90];
  v31 = v27[96] * v29;
  v88 = (float)((float)((float)(v27[95] * v29) + (float)(v27[91] * v28)) + (float)(v27[99] * v30)) + v27[103];
  v32 = (float)((float)(v27[92] * v28) + v31) + (float)(v27[100] * v30);
  v33 = v27[97];
  v89 = v32 + v27[104];
  v34 = v27[93];
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  v35 = (float)((float)((float)(v34 * v28) + (float)(v33 * v29)) + (float)(v27[101] * v30)) + v27[105];
  ifilename._Bx._Buf[0] = 0;
  v93 = v35;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  v98 = 0;
  INIReader::INIReader(&v94, &ifilename);
  LOBYTE(v98) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ENABLE_CAMERA_SHAKE", 0x13u);
  LOBYTE(v98) = 3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"VR", 2u);
  LOBYTE(v98) = 4;
  v91 = INIReader::getInt(&v94, &section, &key) != 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v98) = 2;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( !v2->sim->isVrConnected || v91 )
  {
    v37 = v2->gForceMix.x * *(float *)(v7 + 1992);
    v38 = v2->gForceMix.y * *(float *)(v7 + 1996);
    v39 = v2->gForceMix.z * *(float *)(v7 + 2000);
    v40 = v2->car->bodyMatrix.M12 * v37;
    v41 = v2->car->bodyMatrix.M13 * v37;
    v42 = (__m128)LODWORD(v2->gForceMixCurrentOffset.x);
    v43 = (float)((float)(v2->car->bodyMatrix.M21 * v38)
                + (float)((float)(v2->gForceMix.x * *(float *)(v7 + 1992)) * v2->car->bodyMatrix.M11))
        + (float)(v2->car->bodyMatrix.M31 * v39);
    v44 = (float)(v40 + (float)(v2->car->bodyMatrix.M22 * v38)) + (float)(v2->car->bodyMatrix.M32 * v39);
    v45 = v2->car->bodyMatrix.M33 * v39;
    v46 = (__m128)LODWORD(v2->gForceMixCurrentOffset.y);
    v47 = (float)(v41 + (float)(v2->car->bodyMatrix.M23 * v38)) + v45;
    v48 = v2->gForceLagMix;
    v42.m128_f32[0] = (float)((float)(v42.m128_f32[0] - v43) * v48) + v43;
    v46.m128_f32[0] = (float)((float)(v46.m128_f32[0] - v44) * v48) + v44;
    v49 = (float)(v2->gForceMixCurrentOffset.z - v47) * v48;
    *(_QWORD *)&v2->gForceMixCurrentOffset.x = _mm_unpacklo_ps(v42, v46).m128_u64[0];
    *(float *)&key._Myres = v49 + v47;
    v2->gForceMixCurrentOffset.z = v49 + v47;
    v50 = *(float *)(v7 + 1056) * 0.0099999998;
    if ( v50 <= 1.0 )
    {
      if ( v50 < 0.0 )
        v50 = 0.0;
    }
    else
    {
      v50 = FLOAT_1_0;
    }
    if ( v2->stillCamera )
      v50 = 0.0;
    v51 = (__m128)LODWORD(v2->shakeFreq.x);
    v52 = &v2->shakeGenerator;
    v53 = (__m128)LODWORD(v2->shakeFreq.y);
    v54 = v2->shakeFreq.z;
    v51.m128_f32[0] = v51.m128_f32[0] * v50;
    v53.m128_f32[0] = v53.m128_f32[0] * v50;
    *(_QWORD *)&v2->shakeGenerator.freqScale.x = _mm_unpacklo_ps(v51, v53).m128_u64[0];
    *(float *)&key._Myres = v54 * v50;
    v2->shakeGenerator.freqScale.z = v54 * v50;
    v55 = (__m128)LODWORD(v2->shakeScale.x);
    v56 = (__m128)LODWORD(v2->shakeScale.y);
    v55.m128_f32[0] = v55.m128_f32[0] * v50;
    v56.m128_f32[0] = v56.m128_f32[0] * v50;
    *(float *)&v57 = v2->shakeScale.z * v50;
    *(_QWORD *)&v2->shakeGenerator.scale.x = _mm_unpacklo_ps(v55, v56).m128_u64[0];
    key._Myres = v57;
    v58 = v57;
    v59 = dt;
    LODWORD(v2->shakeGenerator.scale.z) = v58;
    v2->shakeGenerator.step(&v2->shakeGenerator, COERCE_FLOAT(LODWORD(v59)));
    v60 = &v2->car->bodyMatrix.M11;
    v61 = (int)v52->getValue(v52, (vec3f *)&key._Bx._Alias[12]);
    v62 = *(float *)(v61 + 4);
    v7 = v85;
    v55.m128_i32[0] = *(_DWORD *)(v61 + 8);
    v63 = FLOAT_1_0;
    v64 = *(float *)(v85 + 1056) * 0.30000001;
    v65 = (float)((float)(v60[4] * v62) + (float)(*(float *)v61 * *v60)) + (float)(v60[8] * v55.m128_f32[0]);
    v66 = (float)((float)(v60[1] * *(float *)v61) + (float)(v60[5] * v62)) + (float)(v60[9] * v55.m128_f32[0]);
    v67 = (float)((float)(v60[2] * *(float *)v61) + (float)(v60[6] * v62)) + (float)(v60[10] * v55.m128_f32[0]);
    if ( v64 <= 1.0 )
    {
      if ( v64 >= 0.0 )
        v63 = *(float *)(v85 + 1056) * 0.30000001;
      else
        v63 = 0.0;
    }
    v2 = v84;
    v68 = v84->shakeMul;
    v69 = (float *)v84->camera;
    v70 = (float)((float)((float)(v84->gForceMixCurrentOffset.y * v68) + v66) * v63) + v89;
    v71 = (float)((float)((float)(v84->gForceMixCurrentOffset.z * v68) + v67) * v63) + v93;
    v69[14] = (float)((float)((float)(v68 * v84->gForceMixCurrentOffset.x) + v65) * v63) + v88;
    v69[15] = v70;
    v69[16] = v71;
  }
  else
  {
    v36 = (float *)v2->camera;
    v36[14] = v88;
    v36[15] = v89;
    v36[16] = v93;
  }
  if ( v2->trackIR.isValid )
  {
    *(_DWORD *)&key._Bx._Alias[12] = 0;
    key._Mysize = 0;
    key._Myres = 0;
    pos.x = 0.0;
    pos.y = 0.0;
    pos.z = 0.0;
    TrackIR::getOffsets(&v2->trackIR, (vec3f *)&key._Bx._Alias[12], &pos);
    Camera::rotateHeading(v2->camera, v7, *(float *)&key._Mysize * 0.017453);
    Camera::rotatePitch(v2->camera, v7, *(float *)&key._Bx._Alias[12] * 0.017453);
    Camera::rotateRoll(v2->camera, v7, *(float *)&key._Myres * 0.017453);
    v72 = v2->camera;
    v73 = (__m128)_mm_loadu_si128((const __m128i *)&v72->matrix);
    v74 = (__m128)_mm_loadu_si128((const __m128i *)&v72->matrix.M31);
    v75 = (__m128)_mm_loadu_si128((const __m128i *)&v72->matrix.M21);
    *(__m128i *)&v83[1] = _mm_loadu_si128((const __m128i *)&v72->matrix.M41);
    *(__m128 *)((char *)&section._Bx + 8) = v75;
    LODWORD(pos.x) ^= _xmm;
    v76 = (__m128)_mm_loadu_si128((const __m128i *)&section._Bx._Buf[4]);
    v77 = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_shuffle_ps(v76, v76, 170);
    v78 = v72->matrix.M42
        + (float)((float)((float)(_mm_shuffle_ps(
                                    v75,
                                    (__m128)_mm_loadu_si128((const __m128i *)&section._Bx._Buf[4]),
                                    85).m128_f32[0]
                                * pos.y)
                        + (float)(_mm_shuffle_ps(v73, v73, 85).m128_f32[0] * pos.x))
                + (float)(_mm_shuffle_ps(v74, v74, 85).m128_f32[0] * pos.z));
    *(float *)&v77._Ptr = (float)((float)(*(float *)&v77._Ptr * pos.y)
                                + (float)(_mm_shuffle_ps(v73, v73, 170).m128_f32[0] * pos.x))
                        + (float)(_mm_shuffle_ps(v74, v74, 170).m128_f32[0] * pos.z);
    *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&section._Bx + 8) = v77;
    *(float *)&v77._Ptr = v72->matrix.M41
                        + (float)((float)((float)(v75.m128_f32[0] * pos.y) + (float)(v73.m128_f32[0] * pos.x))
                                + (float)(v74.m128_f32[0] * pos.z));
    v79 = *(float *)_mm_loadu_si128((const __m128i *)&section._Bx._Buf[4]).m128i_i32 + v72->matrix.M43;
    v72->matrix.M42 = v78;
    LODWORD(v72->matrix.M41) = v77._Ptr;
    v72->matrix.M43 = v79;
  }
  else
  {
    v80 = v2->car->physicsState.actionsState.state;
    if ( !v2->sim->isVrConnected )
    {
      if ( (v80 & 0x200) != 0 || (v80 & 1) != 0 && (v80 & 2) != 0 )
        CameraOnBoard::lookBack(v2);
      else
        CameraOnBoard::lookLeftRight(v2, dt);
    }
  }
  v81 = v2->camera->getFinalWorldMatrix(v2->camera, (mat44f *)&v82);
  AudioEngine::setListener(v2->game->audioEngine, v81, (const vec3f *)(v7 + 1060));
  v98 = -1;
  INIReader::~INIReader(&v94);
}
