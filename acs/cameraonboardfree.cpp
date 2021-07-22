#include "cameraonboardfree.h
void __userpurge CameraOnBoardFree::CameraOnBoardFree(CameraOnBoardFree *this@<ecx>, unsigned int a2@<ebx>, std::wstring name, Camera *a_camera, Sim *a_sim)
{
  Sim *v6; // edi
  Console *v7; // eax
  Console *v8; // eax
  Console *v9; // eax
  Console *v10; // eax
  double v11; // st7
  bool v12; // cf
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  int v18; // eax
  int v19; // eax
  int v20; // eax
  Event<OnMouseWheelMovedEvent> *v21; // ecx
  Sim *v22; // ecx
  Console *v23; // eax
  _BYTE v24[52]; // [esp-34h] [ebp-FCh] BYREF
  float multiplier; // [esp+0h] [ebp-C8h]
  _BYTE *v26; // [esp+20h] [ebp-A8h]
  _BYTE *v27; // [esp+24h] [ebp-A4h]
  CameraOnBoardFree *v28; // [esp+28h] [ebp-A0h]
  std::wstring section; // [esp+2Ch] [ebp-9Ch] BYREF
  std::wstring key; // [esp+44h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+5Ch] [ebp-6Ch] BYREF
  INIReader rr; // [esp+74h] [ebp-54h] BYREF
  int v33; // [esp+C4h] [ebp-4h]

  v6 = a_sim;
  v28 = this;
  multiplier = *(float *)&a_sim->game;
  v33 = 0;
  *(_DWORD *)&v24[48] = a_camera;
  *(_DWORD *)&v24[44] = 7;
  *(_DWORD *)&v24[40] = 0;
  *(_WORD *)&v24[24] = 0;
  std::wstring::assign((std::wstring *)&v24[24], &name, 0, 0xFFFFFFFF);
  CinematicFreeCamera::CinematicFreeCamera(
    this,
    a2,
    *(std::wstring *)&v24[24],
    *(Camera **)&v24[48],
    (Game *)LODWORD(multiplier));
  LOBYTE(v33) = 1;
  this->__vftable = (CameraOnBoardFree_vtbl *)&CameraOnBoardFree::`vftable';
  this->lockCamera = 0;
  this->useSphericalCoords = 1;
  mat44f::mat44f(&this->matrix);
  this->rotationSpeed = 0.1;
  this->isEscMode = 1;
  mat44f::loadIdentity(&this->matrix);
  multiplier = 1.0;
  *(_DWORD *)&v24[48] = 0;
  *(_DWORD *)&v24[44] = 0;
  *(_DWORD *)&v24[40] = &this->fov;
  this->fov = 60.0;
  v26 = &v24[16];
  this->escModeDOFFactor = 1.0;
  this->dofFocus = 0.1;
  this->dofFactor = 0.0;
  this->sim = v6;
  *(_DWORD *)&v24[36] = 7;
  *(_DWORD *)&v24[32] = 0;
  *(_WORD *)&v24[16] = 0;
  std::wstring::assign((std::wstring *)&v24[16], L"freeCamFov", 0xAu);
  LOBYTE(v33) = 2;
  v7 = Console::singleton();
  LOBYTE(v33) = 1;
  Console::addVar(v7, *(std::wstring *)&v24[16], *(float **)&v24[40], *(IVarCallback **)&v24[44], v24[48], multiplier);
  multiplier = 1.0;
  *(_DWORD *)&v24[48] = 0;
  *(_DWORD *)&v24[44] = 0;
  *(_DWORD *)&v24[40] = &this->dofFactor;
  v26 = &v24[16];
  *(_DWORD *)&v24[36] = 7;
  *(_DWORD *)&v24[32] = 0;
  *(_WORD *)&v24[16] = 0;
  std::wstring::assign((std::wstring *)&v24[16], L"freeCamDof", 0xAu);
  LOBYTE(v33) = 3;
  v8 = Console::singleton();
  LOBYTE(v33) = 1;
  Console::addVar(v8, *(std::wstring *)&v24[16], *(float **)&v24[40], *(IVarCallback **)&v24[44], v24[48], multiplier);
  multiplier = 1.0;
  *(_DWORD *)&v24[48] = 0;
  *(_DWORD *)&v24[44] = 0;
  *(_DWORD *)&v24[40] = &this->dofFocus;
  v26 = &v24[16];
  *(_DWORD *)&v24[36] = 7;
  *(_DWORD *)&v24[32] = 0;
  *(_WORD *)&v24[16] = 0;
  std::wstring::assign((std::wstring *)&v24[16], L"freeCamDofFocus", 0xFu);
  LOBYTE(v33) = 4;
  v9 = Console::singleton();
  LOBYTE(v33) = 1;
  Console::addVar(v9, *(std::wstring *)&v24[16], *(float **)&v24[40], *(IVarCallback **)&v24[44], v24[48], multiplier);
  multiplier = 1.0;
  *(_DWORD *)&v24[48] = 0;
  *(_DWORD *)&v24[44] = 0;
  *(_DWORD *)&v24[40] = &this->exposure;
  v26 = &v24[16];
  *(_DWORD *)&v24[36] = 7;
  *(_DWORD *)&v24[32] = 0;
  *(_WORD *)&v24[16] = 0;
  std::wstring::assign((std::wstring *)&v24[16], L"freeCamExp", 0xAu);
  LOBYTE(v33) = 5;
  v10 = Console::singleton();
  LOBYTE(v33) = 1;
  Console::addVar(v10, *(std::wstring *)&v24[16], *(float **)&v24[40], *(IVarCallback **)&v24[44], v24[48], multiplier);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/camera_onboard_free.ini", 0x22u);
  LOBYTE(v33) = 6;
  INIReader::INIReader(&rr, &ifilename);
  LOBYTE(v33) = 8;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( rr.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ROTATION_SPEED", 0xEu);
    LOBYTE(v33) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v33) = 10;
    v11 = INIReader::getFloat(&rr, &section, &key);
    v12 = section._Myres < 8;
    this->rotationSpeed = v11;
    if ( !v12 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ESC_DOF_FACTOR", 0xEu);
    LOBYTE(v33) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v33) = 12;
    v13 = INIReader::getFloat(&rr, &section, &key);
    v12 = section._Myres < 8;
    this->escModeDOFFactor = v13;
    if ( !v12 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_MULT", 8u);
    LOBYTE(v33) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v33) = 14;
    v14 = INIReader::getFloat(&rr, &section, &key);
    v12 = section._Myres < 8;
    this->minMult = v14;
    if ( !v12 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_MULT", 8u);
    LOBYTE(v33) = 15;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v33) = 16;
    v15 = INIReader::getFloat(&rr, &section, &key);
    v12 = section._Myres < 8;
    this->maxMult = v15;
    if ( !v12 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FOV", 3u);
    LOBYTE(v33) = 17;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v33) = 18;
    v16 = INIReader::getFloat(&rr, &section, &key);
    v12 = section._Myres < 8;
    this->fov = v16;
    if ( !v12 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"EXPOSURE", 8u);
    LOBYTE(v33) = 19;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v33) = 20;
    v17 = INIReader::getFloat(&rr, &section, &key);
    v12 = section._Myres < 8;
    this->exposure = v17;
    if ( !v12 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SPHERICAL_COORDS", 0x10u);
    LOBYTE(v33) = 21;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v33) = 22;
    v18 = INIReader::getInt(&rr, &section, &key);
    v12 = section._Myres < 8;
    this->useSphericalCoords = v18 > 0;
    if ( !v12 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  LODWORD(multiplier) = 12;
  this->lastMouseDown = 0;
  v19 = operator new(LODWORD(multiplier));
  if ( v19 )
  {
    *(_DWORD *)v19 = 1117126656;
    *(_DWORD *)(v19 + 4) = 1084227584;
    *(_DWORD *)(v19 + 8) = 1118437376;
  }
  else
  {
    v19 = 0;
  }
  LODWORD(multiplier) = 12;
  this->theta = (CameraValue *)v19;
  v20 = operator new(LODWORD(multiplier));
  if ( v20 )
  {
    *(_DWORD *)v20 = -1036779520;
    *(_DWORD *)(v20 + 4) = 0;
    *(_DWORD *)(v20 + 8) = 1135869952;
  }
  else
  {
    v20 = 0;
  }
  LODWORD(multiplier) = this;
  this->phi = (CameraValue *)v20;
  this->minimumRadius = 2.5;
  this->maximumRadius = 10.0;
  this->radius = 5.0;
  *(_DWORD *)&v24[28] = &std::_Func_impl<std::_Callable_obj<_lambda_f7e0e81750c0508656cd6169ba82ecd5_,0>,std::allocator<std::_Func_class<void,OnMouseWheelMovedEvent const &>>,void,OnMouseWheelMovedEvent const &>::`vftable';
  *(_DWORD *)&v24[32] = this;
  *(_DWORD *)&v24[44] = &v24[28];
  v21 = &this->game->window.evOnMouseWheelMoved;
  LOBYTE(v33) = 8;
  Event<ksgui::OnControlClicked>::addHandler(
    v21,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v24[28],
    (void *)LODWORD(multiplier));
  multiplier = 1.0;
  *(_DWORD *)&v24[48] = 0;
  v26 = &v24[24];
  *(_DWORD *)&v24[24] = &std::_Func_impl<std::_Callable_obj<_lambda_cdb34aae9163c371db9cc79de400855f_,0>,std::allocator<std::_Func_class<void,SVar *,float>>,void,SVar *,float>::`vftable';
  *(_DWORD *)&v24[28] = this;
  *(_DWORD *)&v24[40] = &v24[24];
  LOBYTE(v33) = 25;
  v27 = v24;
  std::wstring::wstring((std::wstring *)v24, L"freeF5");
  v22 = this->sim;
  LOBYTE(v33) = 26;
  v23 = Sim::getConsole(v22);
  LOBYTE(v33) = 8;
  Console::addVarLambda(
    v23,
    *(std::wstring *)v24,
    *(std::function<void __cdecl(SVar *,float)> *)&v24[24],
    v24[48],
    multiplier);
  LOBYTE(v33) = 1;
  INIReader::~INIReader(&rr);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
CameraOnBoardFree *CameraOnBoardFree::`vector deleting destructor'(CameraOnBoardFree *this, unsigned int a2)
{
  this->__vftable = (CameraOnBoardFree_vtbl *)&CameraOnBoardFree::`vftable';
  CinematicFreeCamera::~CinematicFreeCamera(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraOnBoardFree::forceThetaPhi(CameraOnBoardFree *this, float aTheta, float aPhi, float aRadius)
{
  this->theta->value = aTheta;
  this->phi->value = aPhi;
  this->radius = aRadius;
}
void CameraOnBoardFree::setIntroMode(CameraOnBoardFree *this, bool value)
{
  this->isEscMode = value;
}
void CameraOnBoardFree::update(CameraOnBoardFree *this, float dt)
{
  CameraShadowMapped *v3; // eax
  unsigned int v4; // eax
  CarAvatar *v5; // eax
  float *v6; // eax
  Camera *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  mat44f *v11; // esi
  unsigned int v12; // eax
  int *v13; // eax
  int v14; // xmm1_4
  int v15; // xmm2_4
  const __m128i *v16; // eax
  Sim *v17; // ecx
  unsigned int v18; // eax
  CarAvatar *v19; // eax
  Camera *v20; // esi
  Node *v21; // eax
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __int128 v24; // xmm3
  __m128i v25; // xmm1
  __m128i v26; // xmm2
  __m128i v27; // xmm3
  unsigned int v28; // eax
  CarAvatar *v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  CarAvatar *v32; // eax
  unsigned int v33; // eax
  CarAvatar *v34; // eax
  float deltaT; // [esp+20h] [ebp-80h]
  __m128 deltaT_8; // [esp+28h] [ebp-78h] BYREF
  __m128i v37; // [esp+38h] [ebp-68h] BYREF
  __m128i v38; // [esp+48h] [ebp-58h]
  __m128i v39; // [esp+58h] [ebp-48h]
  __m128 result_8[3]; // [esp+68h] [ebp-38h] BYREF
  _BYTE result_56[12]; // [esp+98h] [ebp-8h] OVERLAPPED

  if ( this->sim->replayManager->hasLoadedReplay )
    this->isEscMode = 0;
  std::wstring::assign(&this->camera->name, L"ONBOARD FREE", 0xCu);
  this->camera->CinematicFreeCamera::fov = this->fov;
  this->camera->exposure = this->exposure;
  this->camera->minExposure = this->sim->hdrLevels.minExposure;
  this->camera->maxExposure = this->sim->hdrLevels.maxExposure;
  this->camera->nearPlane = 0.1;
  v3 = (CameraShadowMapped *)__RTDynamicCast(
                               this->camera,
                               0,
                               &Camera `RTTI Type Descriptor',
                               &CameraShadowMapped `RTTI Type Descriptor',
                               0);
  CameraShadowMapped::setShadowMapsSplits(v3, 10.0, 80.0, 300.0, 1500.0);
  if ( this->isEscMode && !this->sim->replayManager->isActive )
  {
    this->camera->dofFactor = this->escModeDOFFactor;
    this->camera->dofRange = 250.0;
    v4 = Sim::getFocusedCarIndex(this->sim);
    v5 = Sim::getCar(this->sim, v4);
    v6 = (float *)v5->bodyTransform->getWorldMatrix(v5->bodyTransform, (mat44f *)result_8);
    v7 = this->camera;
    v8 = v7->matrix.M43 - v6[14];
    v9 = (float)((float)((float)(v7->matrix.M42 - v6[13]) * (float)(v7->matrix.M42 - v6[13]))
               + (float)((float)(v7->matrix.M41 - v6[12]) * (float)(v7->matrix.M41 - v6[12])))
       + (float)(v8 * v8);
    v10 = 0.0;
    if ( v9 != 0.0 )
      v10 = fsqrt(v9);
    v7->dofFactor = 1.0;
    v11 = &this->matrix;
    this->camera->dofRange = 3.0;
    this->camera->dofFocus = v10;
    v12 = Sim::getFocusedCarIndex(this->sim);
    Sim::getCar(this->sim, v12);
    updateOrbitStatic((int)&this->matrix, &this->matrix);
    goto LABEL_14;
  }
  GetAsyncKeyState(16);
  GetAsyncKeyState(9);
  if ( !this->useSphericalCoords )
  {
    CinematicFreeCamera::setMatrixMovementFromUserInput(this, &this->matrix, deltaT);
    CinematicFreeCamera::setCameraParameterFromUserInput(this, &this->fov, &this->dofFactor, deltaT);
    if ( GetAsyncKeyState(2) )
    {
      v30 = Sim::getFocusedCarIndex(this->sim);
      v11 = &this->matrix;
      Sim::getCar(this->sim, v30);
      updateOrbit((int)this, (int)&this->matrix, &this->matrix);
    }
    else
    {
      v11 = &this->matrix;
    }
LABEL_14:
    v31 = Sim::getFocusedCarIndex(this->sim);
    v32 = Sim::getCar(this->sim, v31);
    mul(&this->camera->CinematicFreeCamera::matrix, v11, &v32->bodyTransform->matrix);
    v33 = Sim::getFocusedCarIndex(this->sim);
    v34 = Sim::getCar(this->sim, v33);
    AudioEngine::setListener(
      this->game->audioEngine,
      &this->camera->CinematicFreeCamera::matrix,
      &v34->physicsState.velocity);
    return;
  }
  this->camera->dofFactor = 0.0;
  v13 = (int *)CameraOnBoardFree::updateSphericalCoord(this, (vec3f *)&deltaT_8, deltaT);
  v37.m128i_i64[0] = 0x3F00000000000000i64;
  v37.m128i_i32[2] = 0;
  v14 = v13[1];
  v15 = v13[2];
  deltaT_8.m128_i32[0] = *v13;
  *(unsigned __int64 *)((char *)deltaT_8.m128_u64 + 4) = __PAIR64__(v15, v14);
  v16 = (const __m128i *)mat44f::createTarget((mat44f *)result_8, (const vec3f *)&deltaT_8, (const vec3f *)&v37);
  v17 = this->sim;
  deltaT_8 = (__m128)_mm_loadu_si128(v16);
  v37 = _mm_loadu_si128(v16 + 1);
  v38 = _mm_loadu_si128(v16 + 2);
  v39 = _mm_loadu_si128(v16 + 3);
  v18 = Sim::getFocusedCarIndex(v17);
  v19 = Sim::getCar(this->sim, v18);
  v20 = this->camera;
  v21 = v19->bodyTransform;
  v22 = *(__m128 *)&v21->matrix.M21;
  v23 = *(__m128 *)&v21->matrix.M31;
  v24 = *(_OWORD *)&v21->matrix.M41;
  result_8[0] = *(__m128 *)&v21->matrix.M11;
  result_8[1] = v22;
  v25 = v37;
  result_8[2] = v23;
  v26 = v38;
  *(_OWORD *)result_56 = v24;
  v27 = v39;
  *(__m128 *)&v20->matrix.M11 = DirectX::XMMatrixMultiply(result_8, deltaT_8);
  *(__m128i *)&v20->matrix.M21 = v25;
  *(__m128i *)&v20->matrix.M31 = v26;
  *(__m128i *)&v20->matrix.M41 = v27;
  v28 = Sim::getFocusedCarIndex(this->sim);
  v29 = Sim::getCar(this->sim, v28);
  AudioEngine::setListener(
    this->game->audioEngine,
    &this->camera->CinematicFreeCamera::matrix,
    &v29->physicsState.velocity);
  if ( GetAsyncKeyState(2) )
    this->phi->value = (float)(deltaT * 10.0) + this->phi->value;
}
vec3f *CameraOnBoardFree::updateSphericalCoord(CameraOnBoardFree *this, vec3f *result, float deltaT)
{
  SHORT v4; // ax
  CameraValue *v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  CameraValue *v9; // esi
  float v10; // xmm0_4
  vec3f *v11; // eax
  tagPOINT Point; // [esp+0h] [ebp-Ch] BYREF
  float v13; // [esp+8h] [ebp-4h]
  float deltaTa; // [esp+14h] [ebp+8h]
  float deltaTb; // [esp+14h] [ebp+8h]

  deltaTa = deltaT * 20.0;
  if ( !this->lockCamera )
  {
    GetCursorPos(&Point);
    v4 = GetAsyncKeyState(1);
    if ( v4 && this->lastMouseDown )
    {
      v5 = this->theta;
      v6 = (float)(Point.x - this->lastMousePoint.x);
      v7 = v5->value - (float)((float)((float)(Point.y - this->lastMousePoint.y) * deltaTa) * 0.30000001);
      v8 = v5->maxD;
      if ( v7 <= v8 )
      {
        if ( v5->minD <= v7 )
          v8 = v5->value - (float)((float)((float)(Point.y - this->lastMousePoint.y) * deltaTa) * 0.30000001);
        else
          v8 = v5->minD;
      }
      v5->value = v8;
      this->phi->value = this->phi->value - (float)((float)(v6 * deltaTa) * 0.30000001);
    }
    this->lastMousePoint = Point;
    this->lastMouseDown = v4 != 0;
  }
  v9 = this->phi;
  v13 = (float)(this->theta->value * 3.1415927) * 0.0055555557;
  deltaTb = __libm_sse2_sinf().m128_f32[0] * this->radius;
  *(float *)&Point.y = (float)(v9->value * 3.1415927) * 0.0055555557;
  result->x = __libm_sse2_cosf().m128_f32[0] * deltaTb;
  result->y = __libm_sse2_cosf().m128_f32[0] * this->radius;
  v10 = __libm_sse2_sinf().m128_f32[0];
  v11 = result;
  LODWORD(result->z) = COERCE_UNSIGNED_INT(v10 * deltaTb) ^ _xmm;
  return v11;
}
void CameraOnBoardFree::setPosition(CameraOnBoardFree *this, const vec3f *pos)
{
  *(vec3f *)&this->matrix.M41 = *pos;
}
