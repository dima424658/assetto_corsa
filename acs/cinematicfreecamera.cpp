#include "cinematicfreecamera.h
void __userpurge CinematicFreeCamera::CinematicFreeCamera(CinematicFreeCamera *this@<ecx>, unsigned int a2@<ebx>, std::wstring name, Camera *aCamera, Game *aGame)
{
  Camera *v6; // esi
  std::wstring v7; // [esp-1Ch] [ebp-3Ch] BYREF
  Game *v8; // [esp-4h] [ebp-24h]
  CinematicFreeCamera *v9; // [esp+Ch] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-4h]

  v6 = aCamera;
  v9 = this;
  v8 = aGame;
  v10 = 0;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, &name, 0, 0xFFFFFFFF);
  GameObject::GameObject(this, v7, v8);
  this->__vftable = (CinematicFreeCamera_vtbl *)&CinematicFreeCamera::`vftable';
  this->exposure = 30.0;
  LOBYTE(v10) = 1;
  this->delay.delayRight = 0.0;
  this->delay.delayLeft = 0.0;
  this->delay.delayForward = 0.0;
  this->delay.delayBack = 0.0;
  this->delay.mouseDelayX = 0.5;
  this->delay.mouseDelayY = 0.5;
  this->delay.delayPitch = 0.0;
  this->delay.delayYaw = 0.0;
  Trigger::Trigger(&this->lockTrigger);
  LOBYTE(v10) = 2;
  Trigger::Trigger(&this->cinematicFeatureTrigger);
  LOBYTE(v10) = 3;
  Trigger::Trigger(&this->blurSwitch);
  LOBYTE(v10) = 4;
  CameraMouseControlBase::CameraMouseControlBase(&this->base, v6);
  LOBYTE(v10) = 5;
  *(_WORD *)&this->useCinematicFeatures = 1;
  this->moveSpeed = 7.0;
  this->minMult = 0.1;
  this->maxMult = 3.0;
  this->movementDelay = 0.2;
  this->dofFactor = 0.0;
  this->dofFocus = 100.0;
  this->ctrlLock = 0;
  this->oldDeltaX = 0.0;
  this->oldDeltaY = 0.0;
  this->mouseSpeed = 1.0;
  this->mouseDelay = 0.07;
  this->camera = v6;
  CinematicFreeCamera::loadSettingsFromINI(this, a2);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void CinematicFreeCamera::~CinematicFreeCamera(CinematicFreeCamera *this)
{
  this->__vftable = (CinematicFreeCamera_vtbl *)&CinematicFreeCamera::`vftable';
  CameraMouseControlBase::~CameraMouseControlBase(&this->base);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->blurSwitch);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->cinematicFeatureTrigger);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->lockTrigger);
  GameObject::~GameObject(this);
}
CinematicFreeCamera *CinematicFreeCamera::`vector deleting destructor'(CinematicFreeCamera *this, unsigned int a2)
{
  this->__vftable = (CinematicFreeCamera_vtbl *)&CinematicFreeCamera::`vftable';
  CameraMouseControlBase::~CameraMouseControlBase(&this->base);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->blurSwitch);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->cinematicFeatureTrigger);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->lockTrigger);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CinematicFreeCamera::getKeyboardMovement(CinematicFreeCamera *this, mat44f *matrix, float dt, float msp)
{
  int v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm3_4

  if ( GetAsyncKeyState(38) )
    matrix->M42 = matrix->M42 - (float)(dt * msp);
  if ( GetAsyncKeyState(40) )
    matrix->M42 = (float)(dt * msp) + matrix->M42;
  v5 = _xmm;
  if ( !GetAsyncKeyState(87) )
  {
    if ( !GetAsyncKeyState(38) )
    {
      v6 = this->delay.delayForward - (float)(dt / this->movementDelay);
      v7 = FLOAT_1_0;
      if ( v6 > 1.0 || (v7 = 0.0, v6 < 0.0) )
        v6 = v7;
      this->delay.delayForward = v6;
      goto LABEL_16;
    }
    v5 = _xmm;
  }
  v8 = FLOAT_1_0;
  v9 = (float)(dt / this->movementDelay) + this->delay.delayForward;
  if ( v9 > 1.0 || (v8 = 0.0, v9 < 0.0) )
    v9 = v8;
  this->delay.delayForward = v9;
  v10 = (float)(v9 * msp) * dt;
  v11 = (float)(COERCE_FLOAT(LODWORD(matrix->M32) ^ v5) * v10) + matrix->M42;
  v12 = (float)(COERCE_FLOAT(LODWORD(matrix->M33) ^ v5) * v10) + matrix->M43;
  matrix->M41 = (float)(COERCE_FLOAT(LODWORD(matrix->M31) ^ v5) * v10) + matrix->M41;
  matrix->M42 = v11;
  matrix->M43 = v12;
LABEL_16:
  if ( GetAsyncKeyState(83) || GetAsyncKeyState(40) )
  {
    v15 = FLOAT_1_0;
    v16 = (float)(dt / this->movementDelay) + this->delay.delayBack;
    if ( v16 > 1.0 || (v15 = 0.0, v16 < 0.0) )
      v16 = v15;
    this->delay.delayBack = v16;
    LODWORD(v17) = COERCE_UNSIGNED_INT((float)(v16 * msp) * dt) ^ _xmm;
    v18 = (float)(COERCE_FLOAT(LODWORD(matrix->M32) ^ _xmm) * v17) + matrix->M42;
    v19 = (float)(COERCE_FLOAT(LODWORD(matrix->M33) ^ _xmm) * v17) + matrix->M43;
    matrix->M41 = (float)(COERCE_FLOAT(LODWORD(matrix->M31) ^ _xmm) * v17) + matrix->M41;
    matrix->M42 = v18;
    matrix->M43 = v19;
  }
  else
  {
    v13 = this->delay.delayBack - (float)(dt / this->movementDelay);
    v14 = FLOAT_1_0;
    if ( v13 > 1.0 || (v14 = 0.0, v13 < 0.0) )
      v13 = v14;
    this->delay.delayBack = v13;
  }
  if ( GetAsyncKeyState(65) || GetAsyncKeyState(37) )
  {
    v22 = FLOAT_1_0;
    v23 = (float)(dt / this->movementDelay) + this->delay.delayLeft;
    if ( v23 > 1.0 || (v22 = 0.0, v23 < 0.0) )
      v23 = v22;
    this->delay.delayLeft = v23;
    LODWORD(v24) = COERCE_UNSIGNED_INT((float)(dt * msp) * v23) ^ _xmm;
    v25 = (float)(matrix->M12 * v24) + matrix->M42;
    v26 = (float)(matrix->M13 * v24) + matrix->M43;
    matrix->M41 = (float)(matrix->M11 * v24) + matrix->M41;
    matrix->M42 = v25;
    matrix->M43 = v26;
  }
  else
  {
    v20 = this->delay.delayLeft - (float)(dt / this->movementDelay);
    v21 = FLOAT_1_0;
    if ( v20 > 1.0 || (v21 = 0.0, v20 < 0.0) )
      v20 = v21;
    this->delay.delayLeft = v20;
  }
  if ( GetAsyncKeyState(68) || GetAsyncKeyState(39) )
  {
    v29 = FLOAT_1_0;
    v30 = (float)(dt / this->movementDelay) + this->delay.delayRight;
    if ( v30 <= 1.0 )
    {
      v29 = 0.0;
      if ( v30 >= 0.0 )
        v29 = (float)(dt / this->movementDelay) + this->delay.delayRight;
    }
    this->delay.delayRight = v29;
    v31 = (float)(dt * msp) * v29;
    v32 = (float)(matrix->M12 * v31) + matrix->M42;
    v33 = (float)(matrix->M13 * v31) + matrix->M43;
    matrix->M41 = (float)(matrix->M11 * v31) + matrix->M41;
    matrix->M42 = v32;
    matrix->M43 = v33;
  }
  else
  {
    v27 = this->delay.delayRight - (float)(dt / this->movementDelay);
    v28 = FLOAT_1_0;
    if ( v27 <= 1.0 )
    {
      v28 = 0.0;
      if ( v27 >= 0.0 )
        v28 = this->delay.delayRight - (float)(dt / this->movementDelay);
    }
    this->delay.delayRight = v28;
  }
  if ( GetAsyncKeyState(67) )
    matrix->M42 = (float)(dt * msp) + matrix->M42;
  if ( GetAsyncKeyState(90) )
    matrix->M42 = matrix->M42 - (float)(dt * msp);
  if ( GetAsyncKeyState(70) )
    rotateRoll((int)GetAsyncKeyState, matrix, (float)(dt * msp) * 0.2);
  if ( GetAsyncKeyState(71) )
    rotateRoll((int)GetAsyncKeyState, matrix, (float)(dt * msp) * -0.2);
  if ( GetAsyncKeyState(66) )
    rotatePitch((int)GetAsyncKeyState, matrix, dt * msp);
  if ( GetAsyncKeyState(86) )
    rotatePitch((int)GetAsyncKeyState, matrix, COERCE_FLOAT(COERCE_UNSIGNED_INT(dt * msp) ^ _xmm));
}
void CinematicFreeCamera::getMouseLook(CinematicFreeCamera *this, mat44f *matrix, float dt, float speed)
{
  SHORT v5; // ax
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  Camera *v18; // eax
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  mat44f *v23; // edi
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  HWND v34; // eax
  int v35; // eax
  int v36; // ecx
  vec3f v37; // [esp-Ch] [ebp-B0h]
  char v38; // [esp+1Ah] [ebp-8Ah]
  bool v39; // [esp+1Bh] [ebp-89h]
  tagPOINT Point; // [esp+1Ch] [ebp-88h] BYREF
  float v41; // [esp+24h] [ebp-80h]
  float v42; // [esp+28h] [ebp-7Ch]
  float v43; // [esp+2Ch] [ebp-78h]
  mat44f *v44; // [esp+30h] [ebp-74h]
  __m128 pDeterminant; // [esp+34h] [ebp-70h] BYREF
  mat44f v46; // [esp+50h] [ebp-54h] BYREF
  tagRECT Rect; // [esp+90h] [ebp-14h] BYREF

  v44 = matrix;
  GetCursorPos(&Point);
  v5 = GetAsyncKeyState(1);
  v39 = v5 != 0;
  if ( !v5 || !this->lastMouseDown )
  {
    v36 = Point.y;
    goto LABEL_56;
  }
  v38 = 0;
  if ( GetAsyncKeyState(88) )
  {
    v6 = this->oldDeltaX;
    v7 = this->oldDeltaY;
  }
  else
  {
    v6 = (float)(Point.x - this->lastMousePoint.x);
    v7 = (float)(Point.y - this->lastMousePoint.y);
  }
  v8 = this->mouseDelay;
  v41 = v7;
  v9 = COERCE_FLOAT(LODWORD(v6) & _xmm) * v8;
  v10 = COERCE_FLOAT(LODWORD(v7) & _xmm) * v8;
  v11 = 0.0;
  v42 = v6;
  this->delay.mouseDelayX = v9;
  this->delay.mouseDelayY = v10;
  if ( v6 <= 0.0 )
  {
    if ( v6 >= 0.0 )
      v12 = 0.0;
    else
      v12 = FLOAT_N1_0;
  }
  else
  {
    v12 = FLOAT_1_0;
  }
  v13 = this->delay.delayYaw;
  if ( v13 <= 0.0 )
  {
    if ( v13 >= 0.0 )
      v14 = 0.0;
    else
      v14 = FLOAT_N1_0;
  }
  else
  {
    v14 = FLOAT_1_0;
  }
  if ( v12 != v14 )
    this->delay.delayYaw = 0.0;
  v15 = this->delay.delayYaw + v6;
  this->delay.delayYaw = v15;
  if ( COERCE_FLOAT(LODWORD(v15) & _xmm) > 3.0 )
  {
    v16 = this->delay.delayYaw;
    if ( v16 <= 0.0 )
    {
      if ( v16 < 0.0 )
        v11 = FLOAT_N1_0;
    }
    else
    {
      v11 = FLOAT_1_0;
    }
    this->delay.delayYaw = v11 * 3.0;
  }
  v17 = this->delay.delayYaw
      - (float)((float)((float)((float)(this->delay.delayYaw * v9) * this->mouseSpeed) * dt) * 0.5);
  v43 = (float)((float)((float)(this->delay.delayYaw * v9) * this->mouseSpeed) * dt) * 0.5;
  this->delay.delayYaw = v17;
  mat44f::mat44f(&v46);
  v18 = this->camera;
  v19 = *(__m128 *)&v18->matrix.M21;
  v20 = *(__m128 *)&v18->matrix.M31;
  v21 = *(__m128 *)&v18->matrix.M41;
  v22 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)&v18->matrix.M11, v19, v20, v21);
  v23 = v44;
  *(__m128 *)&v46.M11 = v22;
  *(__m128 *)&v46.M31 = v20;
  pDeterminant.m128_i32[2] = _mm_shuffle_ps(v19, v19, 170).m128_u32[0];
  *(_QWORD *)&v37.x = _mm_unpacklo_ps(v19, _mm_shuffle_ps(v19, v19, 85)).m128_u64[0];
  *(__m128 *)&v46.M41 = v21;
  LODWORD(v37.z) = pDeterminant.m128_i32[2];
  rotateOnAxis((int)this, v44, v37, COERCE_FLOAT(LODWORD(v43) ^ _xmm));
  v24 = v41;
  v25 = FLOAT_1_0;
  if ( v41 <= 0.0 )
  {
    if ( v41 < 0.0 )
    {
      v27 = FLOAT_N1_0;
      v26 = FLOAT_N1_0;
      goto LABEL_30;
    }
    v26 = 0.0;
  }
  else
  {
    v26 = FLOAT_1_0;
  }
  v27 = FLOAT_N1_0;
LABEL_30:
  v28 = this->delay.delayPitch;
  if ( v28 <= 0.0 )
  {
    if ( v28 >= 0.0 )
      v29 = 0.0;
    else
      v29 = v27;
  }
  else
  {
    v29 = FLOAT_1_0;
  }
  if ( v26 != v29 )
    this->delay.delayPitch = 0.0;
  v30 = this->delay.delayPitch + v24;
  this->delay.delayPitch = v30;
  if ( COERCE_FLOAT(LODWORD(v30) & _xmm) > 3.0 )
  {
    v31 = this->delay.delayPitch;
    if ( v31 <= 0.0 )
    {
      if ( v31 >= 0.0 )
        v25 = 0.0;
      else
        v25 = v27;
    }
    this->delay.delayPitch = v25 * 3.0;
  }
  v32 = this->delay.delayPitch;
  v33 = (float)((float)((float)(this->delay.mouseDelayY * v32) * this->mouseSpeed) * dt) * 0.5;
  this->delay.delayPitch = v32 - v33;
  rotatePitch((int)this, v23, COERCE_FLOAT(LODWORD(v33) ^ _xmm));
  v34 = GetDesktopWindow();
  GetWindowRect(v34, &Rect);
  if ( Point.x < Rect.right - 10 )
  {
    if ( Point.x > 10 )
      goto LABEL_48;
    Point.x = Rect.right - 15;
  }
  else
  {
    Point.x = 15;
  }
  v38 = 1;
LABEL_48:
  v35 = GetSystemMetrics(79);
  v36 = Point.y;
  if ( Point.y == v35 - 1 )
  {
    v36 = 0;
    Point.y = 0;
LABEL_53:
    SetCursorPos(Point.x, v36);
    v36 = Point.y;
    goto LABEL_54;
  }
  if ( !Point.y )
  {
    v36 = GetSystemMetrics(79) - 1;
    Point.y = v36;
    goto LABEL_53;
  }
  if ( v38 )
    goto LABEL_53;
LABEL_54:
  this->oldDeltaX = v42;
  this->oldDeltaY = v41;
LABEL_56:
  this->lastMousePoint.x = Point.x;
  this->lastMousePoint.y = v36;
  this->lastMouseDown = v39;
}
void __usercall CinematicFreeCamera::loadSettingsFromINI(CinematicFreeCamera *this@<ecx>, unsigned int a2@<ebx>)
{
  double v3; // st7
  bool v4; // cf
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  std::wstring v10; // [esp-1Ch] [ebp-108h] BYREF
  BOOL v11; // [esp-4h] [ebp-F0h]
  float userDistanceScale; // [esp+8h] [ebp-E4h]
  std::wstring section; // [esp+Ch] [ebp-E0h] BYREF
  std::wstring key; // [esp+24h] [ebp-C8h] BYREF
  std::wstring v15; // [esp+3Ch] [ebp-B0h] BYREF
  INIReaderDocuments rr; // [esp+54h] [ebp-98h] BYREF
  INIReader ini; // [esp+98h] [ebp-54h] BYREF
  int v18; // [esp+E8h] [ebp-4h]

  v11 = 0;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"cfg/video_editing.ini", 0x15u);
  INIReaderDocuments::INIReaderDocuments(&rr, a2, v10, v11);
  v18 = 0;
  if ( rr.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MOVE_SPEED", 0xAu);
    LOBYTE(v18) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v18) = 2;
    v3 = INIReader::getFloat(&rr, &section, &key);
    v4 = section._Myres < 8;
    this->moveSpeed = v3;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_MULT", 8u);
    LOBYTE(v18) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v18) = 4;
    v5 = INIReader::getFloat(&rr, &section, &key);
    v4 = section._Myres < 8;
    this->minMult = v5;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_MULT", 8u);
    LOBYTE(v18) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v18) = 6;
    v6 = INIReader::getFloat(&rr, &section, &key);
    v4 = section._Myres < 8;
    this->maxMult = v6;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FOV", 3u);
    LOBYTE(v18) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v18) = 8;
    v7 = INIReader::getFloat(&rr, &section, &key);
    v4 = section._Myres < 8;
    this->fov = v7;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MOVEMENT_DELAY", 0xEu);
    LOBYTE(v18) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v18) = 10;
    v8 = INIReader::getFloat(&rr, &section, &key);
    v4 = section._Myres < 8;
    this->movementDelay = v8;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MOUSE_LOOK_SPEED", 0x10u);
    LOBYTE(v18) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v18) = 12;
    v9 = INIReader::getFloat(&rr, &section, &key);
    v4 = section._Myres < 8;
    this->mouseSpeed = v9;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"system/cfg/camera_track.ini", 0x1Bu);
  LOBYTE(v18) = 13;
  INIReader::INIReader(&ini, &section);
  LOBYTE(v18) = 15;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISTANCE_SCALE", 0xEu);
    LOBYTE(v18) = 16;
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    std::wstring::assign(&v15, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v18) = 17;
    userDistanceScale = INIReader::getFloat(&ini, &v15, &key);
    if ( v15._Myres >= 8 )
      operator delete(v15._Bx._Ptr);
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    this->distanceScale = 1.0 / userDistanceScale;
  }
  LOBYTE(v18) = 0;
  INIReader::~INIReader(&ini);
  v18 = -1;
  INIReaderDocuments::~INIReaderDocuments(&rr);
}
void CinematicFreeCamera::setAudioDistanceScale(CinematicFreeCamera *this)
{
  AudioEngine::setDistanceScale(this->game->audioEngine, this->distanceScale);
}
void CinematicFreeCamera::setCameraParameterFromUserInput(CinematicFreeCamera *this, float *aFov, float *aDofFactor, float deltaT)
{
  float v5; // [esp+8h] [ebp-4h]

  v5 = this->moveSpeed;
  if ( GetAsyncKeyState(9) )
    v5 = this->maxMult * v5;
  if ( GetAsyncKeyState(16) )
    v5 = this->minMult * v5;
  if ( GetAsyncKeyState(107) && *aFov < 125.0 )
    *aFov = (float)(v5 * deltaT) + *aFov;
  if ( GetAsyncKeyState(109) )
  {
    if ( *aFov > 1.0 )
      *aFov = *aFov - (float)(v5 * deltaT);
  }
}
void CinematicFreeCamera::setMatrixMovementFromUserInput(CinematicFreeCamera *this, mat44f *inputMatrix, float dt)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  float speed; // [esp+10h] [ebp-8h]
  float msp; // [esp+14h] [ebp-4h]

  msp = this->moveSpeed;
  speed = this->mouseSpeed;
  if ( GetAsyncKeyState(16) )
  {
    v4 = this->minMult;
    speed = v4 * speed;
    msp = v4 * msp;
  }
  if ( GetAsyncKeyState(9) )
  {
    v5 = this->maxMult;
    speed = v5 * speed;
    msp = v5 * msp;
  }
  CinematicFreeCamera::getKeyboardMovement(this, inputMatrix, dt, msp);
  if ( this->useCinematicFeatures )
    CinematicFreeCamera::getMouseLook(this, inputMatrix, dt, speed);
  else
    CinematicFreeCamera::standardMouseLook(this, (int)this, dt, speed);
}
void __userpurge CinematicFreeCamera::standardMouseLook(CinematicFreeCamera *this@<ecx>, int a2@<esi>, float dt, float speed)
{
  SHORT v5; // ax
  Camera *v6; // esi
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  Camera *v10; // ecx
  bool v11; // [esp+17h] [ebp-5Dh]
  tagPOINT Point; // [esp+18h] [ebp-5Ch] BYREF
  float rads; // [esp+20h] [ebp-54h]
  __m128 pDeterminant; // [esp+24h] [ebp-50h] BYREF
  mat44f v15; // [esp+34h] [ebp-40h] BYREF

  GetCursorPos(&Point);
  v5 = GetAsyncKeyState(1);
  v11 = v5 != 0;
  if ( v5 && this->lastMouseDown )
  {
    Camera::rotatePitch(
      this->camera,
      a2,
      COERCE_FLOAT(COERCE_UNSIGNED_INT(
                     (float)((float)((float)(Point.y - this->lastMousePoint.y) * speed) * this->camera->fov)
                   * 0.016666668) ^ _xmm));
    v6 = this->camera;
    rads = (float)((float)((float)(this->lastMousePoint.x - Point.x) * speed) * v6->fov) * 0.016666668;
    mat44f::mat44f(&v15);
    v7 = *(__m128 *)&v6->matrix.M21;
    v8 = *(__m128 *)&v6->matrix.M31;
    v9 = *(__m128 *)&v6->matrix.M41;
    *(__m128 *)&v15.M11 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)&v6->matrix.M11, v7, v8, v9);
    pDeterminant.m128_i32[0] = v7.m128_i32[0];
    v10 = this->camera;
    pDeterminant.m128_i32[1] = _mm_shuffle_ps(v7, v7, 85).m128_u32[0];
    *(__m128 *)&v15.M31 = v8;
    *(__m128 *)&v15.M41 = v9;
    pDeterminant.m128_i32[2] = _mm_shuffle_ps(v7, v7, 170).m128_u32[0];
    Camera::rotateOnAxis(v10, (int)this, (int)v6, (const vec3f *)&pDeterminant, rads);
  }
  this->lastMousePoint = Point;
  this->lastMouseDown = v11;
}
void __userpurge CinematicFreeCamera::update(CinematicFreeCamera *this@<ecx>, unsigned int a2@<ebx>, float deltaT)
{
  SHORT v4; // ax
  bool v5; // al
  Sim *v6; // eax
  SHORT v7; // ax
  int v8; // eax
  float v9; // xmm1_4
  float v10; // xmm1_4
  Camera *v11; // ecx
  float v12; // eax
  Game *v13; // ecx
  mat44f *v14; // eax
  float v15; // [esp+10h] [ebp-50h]
  vec3f velocity; // [esp+14h] [ebp-4Ch] BYREF
  std::wstring imessage; // [esp+20h] [ebp-40h] BYREF
  std::wstring description; // [esp+38h] [ebp-28h] BYREF
  int v19; // [esp+5Ch] [ebp-4h]

  if ( GetAsyncKeyState(45) )
    CinematicFreeCamera::loadSettingsFromINI(this, a2);
  v4 = GetAsyncKeyState(8);
  if ( Trigger::ignoreSubsequentTrue(&this->cinematicFeatureTrigger, v4 != 0) )
  {
    v5 = !this->useCinematicFeatures;
    this->useCinematicFeatures = v5;
    if ( v5 )
    {
      std::wstring::wstring(&description, word_17BE9D8);
      v19 = 0;
      std::wstring::wstring(&imessage, L"Cinematic Camera LOOK ON");
      LOBYTE(v19) = 1;
    }
    else
    {
      std::wstring::wstring(&description, word_17BE9D8);
      v19 = 2;
      std::wstring::wstring(&imessage, L"Cinematic Camera LOOK OFF");
      LOBYTE(v19) = 3;
    }
    v6 = GameObject::getGameObject<Sim>(this->game->root);
    SystemMessage::addMessage(v6->systemMessage, &imessage, &description, eDefault);
    if ( imessage._Myres >= 8 )
      operator delete(imessage._Bx._Ptr);
    v19 = -1;
    imessage._Bx._Buf[0] = 0;
    imessage._Mysize = 0;
    imessage._Myres = 7;
    if ( description._Myres >= 8 )
      operator delete(description._Bx._Ptr);
  }
  v7 = GetAsyncKeyState(46);
  if ( Trigger::ignoreSubsequentTrue(&this->blurSwitch, v7 != 0) )
  {
    v8 = __RTDynamicCast(this->camera, 0, &Camera `RTTI Type Descriptor', &CameraForwardYebis `RTTI Type Descriptor', 0);
    if ( v8 )
      *(_BYTE *)(v8 + 1684) = *(_BYTE *)(v8 + 1684) == 0;
  }
  CinematicFreeCamera::setMatrixMovementFromUserInput(this, &this->camera->matrix, deltaT);
  v15 = this->moveSpeed;
  if ( GetAsyncKeyState(9) )
    v15 = this->maxMult * v15;
  if ( GetAsyncKeyState(16) )
    v15 = this->minMult * v15;
  if ( GetAsyncKeyState(107) )
  {
    v9 = this->fov;
    if ( v9 < 125.0 )
      this->fov = (float)(v15 * deltaT) + v9;
  }
  if ( GetAsyncKeyState(109) )
  {
    v10 = this->fov;
    if ( v10 > 1.0 )
      this->fov = v10 - (float)(v15 * deltaT);
  }
  v11 = this->camera;
  v12 = this->fov;
  velocity.x = 0.0;
  velocity.y = 0.0;
  v11->fov = v12;
  v13 = this->game;
  v14 = &this->camera->matrix;
  velocity.z = 0.0;
  AudioEngine::setListener(v13->audioEngine, v14, &velocity);
}
