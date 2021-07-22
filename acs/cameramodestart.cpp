#include "cameramodestart.h"
void CameraModeStart::CameraModeStart(CameraModeStart *this, Sim *sim, CameraTrack *cameraTrack, CameraForward *camera, const std::wstring *trackName, const std::wstring *trackConfig)
{
  std::wstring *v7; // eax
  std::wstring *v8; // edi
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // edi
  double v13; // st7
  bool v14; // cf
  Font *v15; // eax
  Font *v16; // eax
  Font *v17; // edi
  std::wstring v18; // [esp-10h] [ebp-100h] BYREF
  Game *v19; // [esp+8h] [ebp-E8h]
  CameraModeStart *v20; // [esp+18h] [ebp-D8h]
  Font *v21; // [esp+1Ch] [ebp-D4h]
  std::wstring *_Right; // [esp+20h] [ebp-D0h]
  INIReader v23; // [esp+24h] [ebp-CCh] BYREF
  std::wstring v24; // [esp+68h] [ebp-88h] BYREF
  std::wstring result; // [esp+80h] [ebp-70h] BYREF
  std::wstring section; // [esp+98h] [ebp-58h] BYREF
  std::wstring key; // [esp+B0h] [ebp-40h] BYREF
  std::wstring ifilename; // [esp+C8h] [ebp-28h] BYREF
  int v29; // [esp+ECh] [ebp-4h]

  _Right = (std::wstring *)trackConfig;
  v19 = cameraTrack->game;
  v20 = this;
  v18._Myres = 7;
  v18._Mysize = 0;
  v18._Bx._Buf[0] = 0;
  std::wstring::assign(&v18, L"CAMERA_MODE_START", 0x11u);
  GameObject::GameObject(this, v18, v19);
  this->__vftable = (CameraModeStart_vtbl *)&CameraModeStart::`vftable';
  v29 = 0;
  this->cameras._Myfirst = 0;
  this->cameras._Mylast = 0;
  this->cameras._Myend = 0;
  this->camera = camera;
  this->currentIndex = 0;
  this->positionOffset.x = 0.0;
  this->positionOffset.y = 0.0;
  this->positionOffset.z = 0.0;
  this->timePerCamera = 7.0;
  this->font._Myptr = 0;
  this->sim = sim;
  this->isCameraIndexShowing = 0.0;
  this->offsetLength = 1.0;
  this->offsetRotation = 0.5;
  this->targetCarPos.x = 0.0;
  this->targetCarPos.y = 0.0;
  this->targetCarPos.z = 0.0;
  this->currentTarget.x = 0.0;
  this->currentTarget.y = 0.0;
  this->currentTarget.z = 0.0;
  this->targetCarPosBlend = 2.0;
  this->panVel = 0.40000001;
  this->targetPos.x = 0.0;
  this->targetPos.y = 0.0;
  this->targetPos.z = 0.0;
  this->currentPos.x = 0.0;
  this->currentPos.y = 0.0;
  this->currentPos.z = 0.0;
  section._Myres = 1065353216;
  *(_QWORD *)&this->positionOffset.x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_1_0), (__m128)LODWORD(FLOAT_5_0)).m128_u64[0];
  this->positionOffset.z = 1.0;
  this->currentVel = 0.1;
  this->posBlend = -2.0;
  this->trackCameraCounter = 0;
  this->isFirstFrameCounter = 0;
  this->crewSide = -1.0;
  this->phase = 1000.0;
  this->isShowingCar = 0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  v19 = (Game *)trackName;
  LOBYTE(v29) = 3;
  v18._Myres = (unsigned int)L"content/tracks/";
  if ( _Right->_Mysize )
  {
    v9 = std::operator+<wchar_t>(&v24, (const wchar_t *)v18._Myres, (const std::wstring *)v19);
    LOBYTE(v29) = 5;
    v10 = std::operator+<wchar_t>(&result, v9, L"/");
    LOBYTE(v29) = 6;
    v11 = std::operator+<wchar_t>(&section, v10, _Right);
    LOBYTE(v29) = 7;
    v12 = std::operator+<wchar_t>(&key, v11, L"/data/crew.ini");
    if ( &ifilename != v12 )
    {
      if ( ifilename._Myres >= 8 )
        operator delete(ifilename._Bx._Ptr);
      ifilename._Myres = 7;
      ifilename._Mysize = 0;
      ifilename._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&ifilename, v12);
    }
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v29) = 3;
    if ( v24._Myres >= 8 )
    {
      v19 = (Game *)v24._Bx._Ptr;
      goto LABEL_22;
    }
  }
  else
  {
    v7 = std::operator+<wchar_t>(&result, (const wchar_t *)v18._Myres, (const std::wstring *)v19);
    LOBYTE(v29) = 4;
    v8 = std::operator+<wchar_t>(&key, v7, L"/data/crew.ini");
    if ( &ifilename != v8 )
    {
      if ( ifilename._Myres >= 8 )
        operator delete(ifilename._Bx._Ptr);
      ifilename._Myres = 7;
      ifilename._Mysize = 0;
      ifilename._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&ifilename, v8);
    }
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v29) = 3;
    if ( result._Myres >= 8 )
    {
      v19 = (Game *)result._Bx._Ptr;
LABEL_22:
      operator delete(v19);
      goto LABEL_23;
    }
  }
LABEL_23:
  INIReader::INIReader(&v23, &ifilename);
  LOBYTE(v29) = 8;
  if ( v23.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SIDE", 4u);
    LOBYTE(v29) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v29) = 10;
    v13 = INIReader::getFloat(&v23, &section, &key);
    v14 = section._Myres < 8;
    *(float *)&_Right = v13;
    LODWORD(this->crewSide) = (unsigned int)_Right ^ _xmm;
    if ( !v14 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v29) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v15 = (Font *)operator new(24);
  v21 = v15;
  LOBYTE(v29) = 11;
  if ( v15 )
    Font::Font(v15, eFontProportional, 32.0, 0, 0);
  else
    v16 = 0;
  v17 = this->font._Myptr;
  LOBYTE(v29) = 8;
  this->font._Myptr = v16;
  if ( v17 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v17);
    operator delete(v17);
  }
  LOBYTE(v29) = 3;
  INIReader::~INIReader(&v23);
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
}
CameraModeStart *CameraModeStart::`scalar deleting destructor'(CameraModeStart *this, unsigned int a2)
{
  Font *v3; // edi

  this->__vftable = (CameraModeStart_vtbl *)&CameraModeStart::`vftable';
  v3 = this->font._Myptr;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v3);
    operator delete(v3);
  }
  std::vector<ACCamera>::_Tidy(&this->cameras);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraModeStart::renderHUD(CameraModeStart *this, float deltaT)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Font *v5; // ecx
  std::wstring v6; // [esp+1Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+34h] [ebp-28h] BYREF
  int v8; // [esp+58h] [ebp-4h]

  if ( this->isCameraIndexShowing != 0.0 )
  {
    v3 = std::to_wstring(&result, this->currentIndex);
    v8 = 0;
    v4 = std::operator+<wchar_t>(&v6, L"CAMERA INDEX:", v3);
    v5 = this->font._Myptr;
    LOBYTE(v8) = 1;
    Font::blitString(v5, 150.0, 150.0, v4, 1.0, eAlignLeft);
    if ( v6._Myres >= 8 )
      operator delete(v6._Bx._Ptr);
    v6._Myres = 7;
    v6._Mysize = 0;
    v6._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
}
void CameraModeStart::update(CameraModeStart *this, float deltaT)
{
  Game *v3; // ecx
  mat44f *v4; // eax
  vec3f velocity; // [esp+8h] [ebp-Ch] BYREF

  CameraModeStart::updateCar(this, deltaT);
  v3 = this->game;
  v4 = &this->camera->matrix;
  velocity.x = 0.0;
  velocity.y = 0.0;
  velocity.z = 0.0;
  AudioEngine::setListener(v3->audioEngine, v4, &velocity);
}
void CameraModeStart::updateCar(CameraModeStart *this, float dt)
{
  CarAvatar *v3; // edx
  float v4; // xmm0_4
  float v5; // xmm3_4
  vec3f *v6; // ecx
  float v7; // xmm1_4
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  float v10; // xmm0_4
  bool v11; // cc
  __m128 v12; // xmm0
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  __m128 v17; // xmm2
  float v18; // xmm3_4
  float v19; // edi
  __m128 v20; // xmm0
  float v21; // eax
  unsigned __int64 v22; // xmm0_8
  float v23; // xmm1_4
  int (__cdecl *v24)(); // ecx
  float v25; // eax
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  float v28; // eax
  int v29; // eax
  __int64 v30; // xmm0_8
  int v31; // eax
  float v32; // eax
  __m128 v33; // xmm0
  float v34; // eax
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  const __m128i *v39; // eax
  __m128i *v40; // ecx
  Game *v41; // ecx
  mat44f *v42; // eax
  float v43; // [esp+24h] [ebp-9Ch]
  unsigned int v44; // [esp+24h] [ebp-9Ch]
  float v45; // [esp+24h] [ebp-9Ch]
  vec3f cameraTarget; // [esp+28h] [ebp-98h] BYREF
  float v47; // [esp+34h] [ebp-8Ch]
  vec3f cameraPosition; // [esp+38h] [ebp-88h] BYREF
  float v49; // [esp+44h] [ebp-7Ch]
  float v50; // [esp+48h] [ebp-78h]
  float v51; // [esp+4Ch] [ebp-74h]
  __m128 v52; // [esp+50h] [ebp-70h]
  __m128 v53; // [esp+60h] [ebp-60h]
  __m128 v54; // [esp+70h] [ebp-50h]
  mat44f result; // [esp+80h] [ebp-40h] BYREF

  this->camera->chromaticAberrationEnabled = 1;
  this->camera->lensFlare = 1;
  this->camera->dofFocus = 20.0;
  this->camera->dofFactor = 1.0;
  this->camera->tripleScreenAvailable = 0;
  v3 = Sim::getCar(this->sim, 0);
  v4 = 0.0;
  v5 = 0.0;
  v6 = v3->physicsState.tyreContactPoint;
  v49 = v3->physicsState.tyreContactPoint[0].y;
  v7 = 0.0;
  if ( v3->physicsState.tyreContactPoint != v3->physicsState.tyreContactNormal )
  {
    while ( 1 )
    {
      v8 = (__m128)LODWORD(v6->x);
      v8.m128_f32[0] = v8.m128_f32[0] + v7;
      v9 = (__m128)LODWORD(v6->y);
      v9.m128_f32[0] = v9.m128_f32[0] + v4;
      v10 = v6->z + v5;
      ++v6;
      cameraPosition.z = v10;
      *(_QWORD *)&cameraTarget.x = _mm_unpacklo_ps(v8, v9).m128_u64[0];
      v7 = cameraTarget.x;
      cameraTarget.z = v10;
      v5 = v10;
      if ( v6 == v3->physicsState.tyreContactNormal )
        break;
      v4 = cameraTarget.y;
    }
  }
  v11 = v3->driverEyesPosition.x >= 0.0;
  *(__m128i *)&result.M11 = _mm_loadu_si128((const __m128i *)&v3->physicsState.worldMatrix);
  v50 = v7 * 0.25;
  *(__m128i *)&result.M21 = _mm_loadu_si128((const __m128i *)&v3->physicsState.worldMatrix.M21);
  v43 = v5 * 0.25;
  *(__m128i *)&result.M31 = _mm_loadu_si128((const __m128i *)&v3->physicsState.worldMatrix.M31);
  v12 = (__m128)_mm_loadu_si128((const __m128i *)&v3->physicsState.worldMatrix.M41);
  LODWORD(cameraTarget.x) = v12.m128_i32[0];
  v54 = _mm_shuffle_ps(v12, v12, 85);
  LODWORD(cameraTarget.y) = v54.m128_i32[0];
  v52 = v12;
  v53 = _mm_shuffle_ps(v12, v12, 170);
  LODWORD(cameraTarget.z) = v53.m128_i32[0];
  if ( v11 )
    v13 = FLOAT_1_0;
  else
    v13 = FLOAT_N1_0;
  v47 = v13;
  if ( CarAvatar::isInPit(v3) )
    v14 = this->crewSide;
  else
    v14 = v47;
  v15 = (float)(result.M13 * 3.0) * v14;
  v16 = (float)((float)(result.M11 * 3.0) * v14) + v50;
  v17 = (__m128)LODWORD(v49);
  v17.m128_f32[0] = v49 + 1.75;
  v18 = (float)(COERCE_FLOAT(LODWORD(result.M31) ^ _xmm) * 2.0) + v16;
  v47 = v18;
  cameraPosition.x = v18;
  v51 = (float)(COERCE_FLOAT(LODWORD(result.M33) ^ _xmm) * 2.0) + (float)(v15 + v43);
  cameraPosition.z = v51;
  v49 = v17.m128_f32[0];
  LODWORD(cameraPosition.y) = v17.m128_i32[0];
  if ( dt > 0.5 )
    dt = FLOAT_0_5;
  v19 = cameraTarget.z;
  v20 = 0i64;
  if ( this->posBlend < 0.0 )
  {
    v21 = cameraPosition.z;
    v20.m128_f32[0] = v18;
    v22 = _mm_unpacklo_ps(v20, v17).m128_u64[0];
    *(_QWORD *)&this->targetPos.x = v22;
    *(_QWORD *)&cameraPosition.x = v22;
    *(_QWORD *)&this->targetCarPos.x = *(_QWORD *)&cameraTarget.x;
    this->targetPos.z = v21;
    this->posBlend = 2.0;
    this->targetCarPos.z = v19;
  }
  v23 = FLOAT_1_0;
  v24 = _rand;
  if ( this->targetCarPosBlend > 1.0 || this->isFirstFrameCounter < 100 )
  {
    v25 = this->targetCarPos.z;
    *(_QWORD *)&this->currentTarget.x = *(_QWORD *)&this->targetCarPos.x;
    this->currentTarget.z = v25;
    v50 = (float)((float)((float)_rand() * 0.000030518509) * 0.2) - 0.1;
    *(float *)&v44 = (float)((float)((float)_rand() * 0.000030518509) * 0.0) - 0.1;
    v26 = (__m128)v44;
    v26.m128_f32[0] = *(float *)&v44 + v54.m128_f32[0];
    v27 = (__m128)COERCE_UNSIGNED_INT((float)_rand());
    v52.m128_f32[2] = v50 + v53.m128_f32[0];
    v28 = v50 + v53.m128_f32[0];
    v27.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] * 0.000030518509) * 0.2) - 0.1) + v52.m128_f32[0];
    *(_QWORD *)&this->targetCarPos.x = _mm_unpacklo_ps(v27, v26).m128_u64[0];
    this->targetCarPos.z = v28;
    v29 = this->isFirstFrameCounter;
    if ( v29 < 100 )
    {
      v30 = *(_QWORD *)&cameraTarget.x;
      *(_QWORD *)&this->targetCarPos.x = *(_QWORD *)&cameraTarget.x;
      *(_QWORD *)&this->currentTarget.x = v30;
      this->targetCarPos.z = v19;
      this->currentTarget.z = v19;
      this->isFirstFrameCounter = v29 + 1;
    }
    this->targetCarPosBlend = 0.0;
    v31 = _rand();
    v23 = FLOAT_1_0;
    v24 = _rand;
    this->panVel = (float)((float)((float)v31 * 0.000030518509) * 0.20000002) + 0.1;
  }
  if ( this->posBlend > v23 )
  {
    v32 = this->targetPos.z;
    *(_QWORD *)&this->currentPos.x = *(_QWORD *)&this->targetPos.x;
    this->currentPos.z = v32;
    this->posBlend = 0.0;
    v45 = (float)((float)((float)v24() * 0.000030518509) * 0.60000002) - 0.30000001;
    v33 = (__m128)COERCE_UNSIGNED_INT((float)_rand());
    v52.m128_f32[2] = v45 + v51;
    v34 = v45 + v51;
    v33.m128_f32[0] = (float)((float)((float)(v33.m128_f32[0] * 0.000030518509) * 0.60000002) - 0.30000001) + v47;
    *(_QWORD *)&this->targetPos.x = _mm_unpacklo_ps(v33, (__m128)LODWORD(v49)).m128_u64[0];
    this->targetPos.z = v34;
  }
  v35 = this->targetCarPosBlend;
  v36 = (float)(3.0 - (float)(v35 * 2.0)) * (float)(v35 * v35);
  v37 = (float)((float)(this->targetCarPos.y - this->currentTarget.y) * v36) + this->currentTarget.y;
  v38 = (float)((float)(this->targetCarPos.z - this->currentTarget.z) * v36) + this->currentTarget.z;
  cameraTarget.x = (float)((float)(this->targetCarPos.x - this->currentTarget.x) * v36) + this->currentTarget.x;
  cameraTarget.y = v37;
  cameraTarget.z = v38;
  if ( dt < 0.5 )
    this->targetCarPosBlend = (float)(this->panVel * dt) + v35;
  this->posBlend = (float)(dt * 0.039999999) + this->posBlend;
  v39 = (const __m128i *)mat44f::createTarget(&result, &cameraPosition, &cameraTarget);
  v40 = (__m128i *)&this->camera->matrix;
  *v40 = _mm_loadu_si128(v39);
  v40[1] = _mm_loadu_si128(v39 + 1);
  v40[2] = _mm_loadu_si128(v39 + 2);
  v40[3] = _mm_loadu_si128(v39 + 3);
  this->camera->fov = 40.0;
  this->camera->maxExposure = 2000.0;
  this->camera->minExposure = 0.0;
  this->camera->dofFactor = 0.0;
  this->camera->nearPlane = 0.1;
  this->camera->farPlane = 15000.0;
  this->camera->exposure = 30.0;
  CameraShadowMapped::setShadowMapsSplits(this->camera, 5.0, 25.0, 250.0, 500.0);
  this->camera->dofFocus = 0.0;
  this->camera->dofRange = 0.0;
  this->camera->dofFactor = 0.0;
  if ( dt < 1.0 )
    this->phase = this->phase + dt;
  v41 = this->game;
  v42 = &this->camera->matrix;
  cameraPosition.x = 0.0;
  cameraPosition.y = 0.0;
  cameraPosition.z = 0.0;
  AudioEngine::setListener(v41->audioEngine, v42, &cameraPosition);
}
