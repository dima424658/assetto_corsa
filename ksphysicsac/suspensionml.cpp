#include "suspensionml.h
SuspensionStatus *SuspensionML::getStatus(SuspensionML *this)
{
  return &this->status;
}
void SuspensionML::SuspensionML(SuspensionML *this, Car *car, int index)
{
  float v4; // xmm1_4
  MLJoint *v5; // eax

  this->bumpStopProgressive = 0.0;
  this->baseCFM = 0.0000001;
  this->__vftable = (SuspensionML_vtbl *)&SuspensionML::`vftable';
  this->status.travel = 0.0;
  this->status.damperSpeedMS = 0.0;
  Damper::Damper(&this->damper);
  this->car = car;
  this->index = index;
  this->joints._Myfirst = 0;
  this->joints._Mylast = 0;
  this->joints._Myend = 0;
  this->basePosition.x = 0.0;
  this->basePosition.y = 0.0;
  this->basePosition.z = 0.0;
  this->steerTorque = 0.0;
  this->damageData.damageAmount = 0.0;
  this->damageData.minVelocity = 15.0;
  this->damageData.damageGain = 0.0;
  this->damageData.maxDamage = 0.0;
  this->damageData.isDebug = 0;
  this->damageData.lastAmount = 0.0;
  this->baseCarSteerPosition.x = 0.0;
  this->baseCarSteerPosition.y = 0.0;
  this->baseCarSteerPosition.z = 0.0;
  this->staticCamber = 0.0;
  this->rodLength = 0.0;
  v4 = (float)((float)_rand() * 0.000030518509) * 100.0;
  this->damageData.damageDirection = v4;
  if ( v4 >= 50.0 )
    this->damageData.damageDirection = 1.0;
  else
    this->damageData.damageDirection = -1.0;
  SuspensionML::loadINI(this, (__m128)LODWORD(FLOAT_50_0), index);
  v5 = this->joints._Myfirst;
  *(_QWORD *)&this->baseCarSteerPosition.x = *(_QWORD *)&v5[4].ballCar.relToCar.x;
  this->baseCarSteerPosition.z = v5[4].ballCar.relToCar.z;
}
SuspensionML *SuspensionML::`vector deleting destructor'(SuspensionML *this, unsigned int a2)
{
  this->__vftable = (SuspensionML_vtbl *)&SuspensionML::`vftable';
  if ( this->joints._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->joints);
    operator delete(this->joints._Myfirst);
    this->joints._Myfirst = 0;
    this->joints._Mylast = 0;
    this->joints._Myend = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->damper);
  this->__vftable = (SuspensionML_vtbl *)&ISuspension::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SuspensionML::addForceAtPos(SuspensionML *this, const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque)
{
  SuspensionML_vtbl *v6; // eax
  vec3f steercentre; // [esp+10h] [ebp-18h] BYREF
  vec3f steeraxis; // [esp+1Ch] [ebp-Ch] BYREF

  this->hub->addForceAtPos(this->hub, force, pos);
  if ( addToSteerTorque )
  {
    v6 = this->__vftable;
    steeraxis.x = 0.0;
    steeraxis.y = 0.0;
    steeraxis.z = 0.0;
    steercentre.x = 0.0;
    steercentre.y = 0.0;
    steercentre.z = 0.0;
    v6->getSteerBasis(this, &steercentre, &steeraxis);
    this->steerTorque = (float)((float)((float)((float)((float)(force->x * (float)(pos->z - steercentre.z))
                                                      - (float)(force->z * (float)(pos->x - steercentre.x)))
                                              * steeraxis.y)
                                      + (float)((float)((float)(force->z * (float)(pos->y - steercentre.y))
                                                      - (float)(force->y * (float)(pos->z - steercentre.z)))
                                              * steeraxis.x))
                              + (float)((float)((float)(force->y * (float)(pos->x - steercentre.x))
                                              - (float)(force->x * (float)(pos->y - steercentre.y)))
                                      * steeraxis.z))
                      + this->steerTorque;
  }
}
void SuspensionML::addLocalForceAndTorque(SuspensionML *this, const vec3f *force, const vec3f *torque, const vec3f *driveTorque)
{
  int v5[3]; // [esp+4h] [ebp-Ch] BYREF

  v5[0] = 0;
  v5[1] = 0;
  v5[2] = 0;
  this->hub->addForceAtLocalPos(this->hub, force, (const vec3f *)v5);
  this->hub->addTorque(this->hub, torque);
  if ( driveTorque->x != 0.0 || driveTorque->y != 0.0 || driveTorque->z != 0.0 )
    this->car->body->addTorque(this->car->body, driveTorque);
}
void SuspensionML::addTorque(SuspensionML *this, const vec3f *torque)
{
  SuspensionML_vtbl *v3; // eax
  vec3f steeraxis; // [esp+Ch] [ebp-18h] BYREF
  vec3f steercentre; // [esp+18h] [ebp-Ch] BYREF

  this->hub->addTorque(this->hub, torque);
  v3 = this->__vftable;
  steeraxis.x = 0.0;
  steeraxis.y = 0.0;
  steeraxis.z = 0.0;
  steercentre.x = 0.0;
  steercentre.y = 0.0;
  steercentre.z = 0.0;
  v3->getSteerBasis(this, &steercentre, &steeraxis);
  this->steerTorque = (float)((float)((float)(torque->y * steeraxis.y) + (float)(torque->x * steeraxis.x))
                            + (float)(torque->z * steeraxis.z))
                    + this->steerTorque;
}
vec3f *SuspensionML::getBasePosition(SuspensionML *this, vec3f *result)
{
  vec3f *v2; // eax
  __int64 v3; // xmm0_8
  float v4; // ecx

  v2 = result;
  v3 = *(_QWORD *)&this->basePosition.x;
  v4 = this->basePosition.z;
  *(_QWORD *)&result->x = v3;
  result->z = v4;
  return v2;
}
double SuspensionML::getDamage(SuspensionML *this)
{
  double result; // st7

  if ( this->damageData.maxDamage == 0.0 )
    result = 0.0;
  else
    result = this->damageData.damageAmount / this->damageData.maxDamage;
  return result;
}
Damper *SuspensionML::getDamper(SuspensionML *this)
{
  return &this->damper;
}
std::vector<DebugLine> *SuspensionML::getDebugLines(SuspensionML *this, std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix)
{
  MLJoint *v4; // edi
  MLJoint *v5; // esi
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  __int64 v10; // xmm4_8
  float v11; // xmm3_4
  float v12; // xmm0_4
  __m128 v13; // xmm7
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  __m128i v26; // [esp+18h] [ebp-58h] BYREF
  float v27; // [esp+28h] [ebp-48h]
  float v28; // [esp+34h] [ebp-3Ch]
  DebugLine _Val; // [esp+38h] [ebp-38h] BYREF
  int v30; // [esp+6Ch] [ebp-4h]
  const mat44f *hubMatrixa; // [esp+7Ch] [ebp+Ch]

  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v4 = this->joints._Mylast;
  v5 = this->joints._Myfirst;
  v30 = 0;
  if ( v5 != v4 )
  {
    v7 = &v5->ballTyre.relToTyre.z;
    hubMatrixa = (const mat44f *)&v5->ballTyre.relToTyre.z;
    do
    {
      v8 = *(v7 - 1);
      v9 = *(v7 - 2);
      v10 = LODWORD(hubMatrix->M21);
      v11 = *v7;
      v12 = hubMatrix->M11 * v9;
      _Val.seconds = 0.0;
      v13 = (__m128)LODWORD(hubMatrix->M12);
      v14 = *(v7 - 4);
      *(float *)&v10 = (float)((float)(*(float *)&v10 * v8) + v12) + (float)(v11 * hubMatrix->M31);
      v15 = v11 * hubMatrix->M32;
      v16 = v11 * hubMatrix->M33;
      *(float *)&v10 = *(float *)&v10 + hubMatrix->M41;
      v13.m128_f32[0] = (float)((float)((float)(v13.m128_f32[0] * v9) + (float)(v8 * hubMatrix->M22)) + v15)
                      + hubMatrix->M42;
      v17 = (float)(hubMatrix->M23 * v8) + (float)(v9 * hubMatrix->M13);
      v26.m128i_i64[0] = v10;
      v18 = *(v7 - 5);
      *(float *)&v10 = *(v7 - 3);
      v19 = v17 + v16;
      v20 = (__m128)LODWORD(bodyMatrix->M21);
      v21 = (__m128)LODWORD(bodyMatrix->M22);
      v22 = bodyMatrix->M13;
      v28 = v19 + hubMatrix->M43;
      v20.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] * v14) + (float)(bodyMatrix->M11 * v18))
                              + (float)(bodyMatrix->M31 * *(float *)&v10))
                      + bodyMatrix->M41;
      v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] * v14) + (float)(v18 * bodyMatrix->M12))
                              + (float)(bodyMatrix->M32 * *(float *)&v10))
                      + bodyMatrix->M42;
      v23 = (float)((float)(v22 * v18) + (float)(bodyMatrix->M23 * v14)) + (float)(bodyMatrix->M33 * *(float *)&v10);
      *(_QWORD *)&_Val.p0.x = _mm_unpacklo_ps(v20, v21).m128_u64[0];
      *(_QWORD *)&_Val.p1.x = _mm_unpacklo_ps((__m128)_mm_loadl_epi64(&v26), v13).m128_u64[0];
      v24 = v23 + bodyMatrix->M43;
      _Val.color = (vec4f)_xmm;
      v27 = v24;
      _Val.p0.z = v24;
      _Val.p1.z = v28;
      std::vector<DebugLine>::push_back(result, &_Val);
      ++v5;
      v7 = &hubMatrixa->M42;
      hubMatrixa = (const mat44f *)((char *)hubMatrixa + 52);
    }
    while ( v5 != v4 );
  }
  return result;
}
vec3f *SuspensionML::getHubAngularVelocity(SuspensionML *this, vec3f *result)
{
  this->hub->getAngularVelocity(this->hub, result);
  return result;
}
mat44f *SuspensionML::getHubWorldMatrix(SuspensionML *this, mat44f *result)
{
  int v3; // ecx
  IRigidBody *v4; // ecx
  IRigidBody_vtbl *v5; // eax
  mat44f *(*v6)(IRigidBody *, mat44f *, float); // eax
  int v7; // eax
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __int128 v11; // xmm1
  __int128 v12; // xmm2
  __int128 v13; // xmm3
  mat44f *v14; // eax
  int v15; // [esp+4h] [ebp-A0h]
  int v16; // [esp+8h] [ebp-9Ch]
  float v17; // [esp+18h] [ebp-8Ch]
  float v18; // [esp+1Ch] [ebp-88h]
  __m128 v19; // [esp+24h] [ebp-80h] BYREF
  __int128 v20; // [esp+34h] [ebp-70h]
  __int128 v21; // [esp+44h] [ebp-60h]
  __int128 v22; // [esp+54h] [ebp-50h]
  DirectX::XMMATRIX M2_8; // [esp+64h] [ebp-40h] BYREF

  mat44f::mat44f(result);
  v17 = __libm_sse2_cosf(v15, v16).m128_f32[0];
  v18 = __libm_sse2_sinf(v3).m128_f32[0];
  mat44f::mat44f((mat44f *)&v19);
  v4 = this->hub;
  HIDWORD(v22) = 1065353216;
  v5 = v4->__vftable;
  *((float *)&v21 + 2) = (float)(1.0 - v17) + v17;
  v6 = v5->getWorldMatrix;
  v19.m128_f32[0] = (float)((float)(1.0 - v17) * 0.0) + v17;
  *((float *)&v20 + 1) = v19.m128_f32[0];
  v19.m128_f32[1] = v18 + (float)((float)(1.0 - v17) * 0.0);
  *(float *)&v20 = (float)((float)(1.0 - v17) * 0.0) - v18;
  v19.m128_f32[2] = (float)((float)(1.0 - v17) * 0.0) - (float)(v18 * 0.0);
  *(float *)&v21 = (float)(v18 * 0.0) + (float)((float)(1.0 - v17) * 0.0);
  *((float *)&v20 + 2) = *(float *)&v21;
  *((float *)&v21 + 1) = v19.m128_f32[2];
  v7 = ((int (__stdcall *)(DirectX::XMMATRIX *, _DWORD))v6)(&M2_8, 0);
  v8 = *(__m128 *)(v7 + 16);
  v9 = *(__m128 *)(v7 + 32);
  v10 = *(__m128 *)(v7 + 48);
  M2_8.r[0] = *(__m128 *)v7;
  M2_8.r[1] = v8;
  v11 = v20;
  M2_8.r[2] = v9;
  v12 = v21;
  M2_8.r[3] = v10;
  v13 = v22;
  *(__m128 *)&result->M11 = DirectX::XMMatrixMultiply(M2_8.r, v19);
  v14 = result;
  *(_OWORD *)&result->M21 = v11;
  *(_OWORD *)&result->M31 = v12;
  *(_OWORD *)&result->M41 = v13;
  return v14;
}
void SuspensionML::getMass(SuspensionML *this)
{
  this->hub->getMass(this->hub);
}
vec3f *SuspensionML::getPointVelocity(SuspensionML *this, vec3f *result, const vec3f *p)
{
  this->hub->getPointVelocity(this->hub, result, p);
  return result;
}
void __userpurge SuspensionML::getSteerBasis(SuspensionML *this@<ecx>, __m128 a2@<xmm6>, vec3f *center, vec3f *axis)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm5
  float v7; // xmm4_4
  __m128 v8; // xmm2
  unsigned __int64 v9; // xmm6_8
  float v10; // ecx
  float v11; // xmm0_4
  float *v12; // eax
  float v13; // xmm4_4
  float *v14; // ecx
  MLBall *v15; // [esp+0h] [ebp-34h]
  unsigned __int64 v16; // [esp+0h] [ebp-34h]
  MLBall *v17; // [esp+8h] [ebp-2Ch]
  float v18; // [esp+8h] [ebp-2Ch]
  float v19; // [esp+Ch] [ebp-28h]
  vec3f p1; // [esp+10h] [ebp-24h] BYREF
  vec3f p2; // [esp+1Ch] [ebp-18h]
  float *v22; // [esp+28h] [ebp-Ch]
  unsigned __int64 *v23; // [esp+2Ch] [ebp-8h]

  v17 = &this->joints._Myfirst->ballTyre;
  ((void (*)(IRigidBody *))this->hub->localToWorld)(this->hub);
  v15 = &this->joints._Myfirst[2].ballTyre;
  ((void (*)(IRigidBody *, float *))this->hub->localToWorld)(this->hub, &p1.y);
  v5 = (__m128)(unsigned int)v15;
  v6 = (__m128)(unsigned int)&p1;
  v7 = *(float *)&v17;
  v8 = (__m128)(unsigned int)&p1;
  v8.m128_f32[0] = COERCE_FLOAT(&p1) - p1.x;
  a2.m128_f32[0] = *(float *)&v15 - v19;
  v9 = _mm_unpacklo_ps(a2, v8).m128_u64[0];
  v10 = *(float *)&v17 - p1.y;
  v18 = *(float *)&v17 - p1.y;
  p2.y = v18;
  v11 = fsqrt(
          (float)((float)(v8.m128_f32[0] * v8.m128_f32[0])
                + (float)((float)(*(float *)&v15 - v19) * (float)(*(float *)&v15 - v19)))
        + (float)(p2.y * p2.y));
  if ( v11 != 0.0 )
  {
    *(float *)&v16 = (float)(1.0 / v11) * (float)(*(float *)&v15 - v19);
    *((float *)&v16 + 1) = (float)(1.0 / v11) * *((float *)&v9 + 1);
    v9 = v16;
    v10 = (float)(1.0 / v11) * v18;
  }
  v12 = (float *)v23;
  v6.m128_f32[0] = COERCE_FLOAT(&p1) + p1.x;
  v13 = v7 + p1.y;
  *v23 = v9;
  v12[2] = v10;
  v14 = v22;
  v5.m128_f32[0] = (float)(v5.m128_f32[0] + v19) * 0.5;
  v6.m128_f32[0] = v6.m128_f32[0] * 0.5;
  *(_QWORD *)v22 = _mm_unpacklo_ps(v5, v6).m128_u64[0];
  v14[2] = v13 * 0.5;
}
double SuspensionML::getSteerTorque(SuspensionML *this)
{
  return this->steerTorque;
}
vec3f *SuspensionML::getVelocity(SuspensionML *this, vec3f *result)
{
  this->hub->getVelocity(this->hub, result);
  return result;
}
void __userpurge SuspensionML::loadINI(SuspensionML *this@<ecx>, __m128 a2@<xmm0>, int index)
{
  Car *v4; // eax
  const std::wstring *v5; // eax
  Car *v6; // ecx
  const std::wstring *v7; // eax
  __m128 v8; // xmm0
  float v9; // eax
  double v10; // st7
  bool v11; // cf
  IPhysicsCore *v12; // eax
  IRigidBody *v13; // eax
  float v14; // xmm0_4
  int v15; // esi
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // esi
  vec3f *v21; // eax
  float v22; // xmm0_4
  IRigidBody *v23; // esi
  IRigidBody *v24; // ecx
  Car *v25; // eax
  IRigidBody *v26; // esi
  Car *v27; // eax
  IPhysicsCore *v28; // eax
  std::wstring *v29; // esi
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  double v40; // st7
  int v41; // xmm1_4
  vec3f v42; // [esp+74h] [ebp-254h] BYREF
  vec3f v43; // [esp+80h] [ebp-248h] BYREF
  vec3f v44; // [esp+8Ch] [ebp-23Ch] BYREF
  vec3f v45; // [esp+98h] [ebp-230h] BYREF
  __int64 v46; // [esp+A4h] [ebp-224h] BYREF
  float v47; // [esp+ACh] [ebp-21Ch]
  MLJoint _Val; // [esp+B0h] [ebp-218h] BYREF
  int v49; // [esp+E4h] [ebp-1E4h]
  float v50; // [esp+E8h] [ebp-1E0h]
  float v51; // [esp+ECh] [ebp-1DCh]
  unsigned int v52; // [esp+F0h] [ebp-1D8h]
  __int64 v53; // [esp+F4h] [ebp-1D4h] BYREF
  float v54; // [esp+FCh] [ebp-1CCh]
  unsigned int v55; // [esp+100h] [ebp-1C8h]
  unsigned int v56; // [esp+104h] [ebp-1C4h]
  std::wstring *v57; // [esp+108h] [ebp-1C0h]
  std::wstring v58; // [esp+10Ch] [ebp-1BCh] BYREF
  std::wstring v59; // [esp+124h] [ebp-1A4h] BYREF
  std::wstring v60; // [esp+13Ch] [ebp-18Ch] BYREF
  std::wstring v61; // [esp+154h] [ebp-174h] BYREF
  std::wstring result; // [esp+16Ch] [ebp-15Ch] BYREF
  std::wstring v63; // [esp+184h] [ebp-144h] BYREF
  INIReader v64; // [esp+19Ch] [ebp-12Ch] BYREF
  std::wstring v65; // [esp+1E0h] [ebp-E8h] BYREF
  std::wstring key; // [esp+1F8h] [ebp-D0h] BYREF
  std::wstring section; // [esp+210h] [ebp-B8h] BYREF
  std::wstring ptr; // [esp+228h] [ebp-A0h] BYREF
  std::wstring v69; // [esp+240h] [ebp-88h] BYREF
  std::wstring v70; // [esp+258h] [ebp-70h] BYREF
  std::wstring v71; // [esp+270h] [ebp-58h] BYREF
  unsigned __int64 v72; // [esp+288h] [ebp-40h]
  float v73; // [esp+290h] [ebp-38h]
  unsigned __int64 v74; // [esp+294h] [ebp-34h]
  float v75; // [esp+29Ch] [ebp-2Ch]
  std::wstring v76; // [esp+2A0h] [ebp-28h] BYREF
  int v77; // [esp+2C4h] [ebp-4h]

  v4 = this->car;
  v49 = index;
  v5 = std::operator+<wchar_t>(&result, &v4->carDataPath, L"suspensions.ini");
  v6 = this->car;
  v77 = 0;
  v7 = Car::getConfigPath(v6, &v63, v5);
  LOBYTE(v77) = 1;
  INIReader::INIReader(&v64, v7);
  if ( v63._Myres >= 8 )
    operator delete(v63._Bx._Ptr);
  v63._Myres = 7;
  v63._Mysize = 0;
  v63._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"VERSION", 7u);
  LOBYTE(v77) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v77) = 6;
  INIReader::getInt(&v64, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"WHEELBASE", 9u);
  LOBYTE(v77) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v77) = 8;
  v50 = INIReader::getFloat(&v64, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CG_LOCATION", 0xBu);
  LOBYTE(v77) = 9;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v77) = 10;
  v51 = INIReader::getFloat(&v64, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v77) = 11;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v77) = 12;
  *(float *)&v56 = INIReader::getFloat(&v64, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v77) = 13;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v77) = 14;
  *(float *)&v57 = INIReader::getFloat(&v64, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v77) = 15;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v77) = 16;
  *(float *)&v55 = INIReader::getFloat(&v64, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v77) = 17;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v77) = 18;
  *(float *)&v52 = INIReader::getFloat(&v64, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  a2.m128_f32[0] = *(float *)&v57;
  v8 = _mm_unpacklo_ps(a2, (__m128)v56);
  v73 = (float)(1.0 - v51) * v50;
  v75 = v73;
  v72 = v8.m128_u64[0];
  v8.m128_f32[0] = *(float *)&v52;
  *(_DWORD *)&v76._Bx._Alias[8] = COERCE_UNSIGNED_INT(v51 * v50) ^ _xmm;
  v54 = *(float *)&v76._Bx._Alias[8];
  v76._Myres = *(_DWORD *)&v76._Bx._Alias[8];
  v74 = _mm_unpacklo_ps(_mm_xor_ps((__m128)(unsigned int)v57, (__m128)(unsigned int)_xmm), (__m128)v56).m128_u64[0];
  *(_QWORD *)v76._Bx._Buf = _mm_unpacklo_ps(v8, (__m128)v55).m128_u64[0];
  *(_QWORD *)&v76._Bx._Alias[12] = _mm_unpacklo_ps(_mm_xor_ps((__m128)v52, (__m128)(unsigned int)_xmm), (__m128)v55).m128_u64[0];
  v9 = *(&v73 + 3 * index);
  *(_QWORD *)&this->basePosition.x = *(unsigned __int64 *)((char *)&v72 + 12 * index);
  this->basePosition.z = v9;
  ptr._Myres = 7;
  ptr._Mysize = 0;
  ptr._Bx._Buf[0] = 0;
  std::wstring::assign(&ptr, L"FRONT", 5u);
  LOBYTE(v77) = 19;
  v69._Myres = 7;
  v69._Mysize = 0;
  v69._Bx._Buf[0] = 0;
  std::wstring::assign(&v69, L"FRONT", 5u);
  LOBYTE(v77) = 20;
  v70._Myres = 7;
  v70._Mysize = 0;
  v70._Bx._Buf[0] = 0;
  std::wstring::assign(&v70, L"REAR", 4u);
  LOBYTE(v77) = 21;
  v71._Myres = 7;
  v71._Mysize = 0;
  v71._Bx._Buf[0] = 0;
  std::wstring::assign(&v71, L"REAR", 4u);
  LOBYTE(v77) = 22;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HUB_MASS", 8u);
  LOBYTE(v77) = 23;
  v57 = &ptr + index;
  v10 = INIReader::getFloat(&v64, v57, &section);
  v11 = section._Myres < 8;
  this->hubMass = v10;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(section._Bx._Ptr);
  v12 = PhysicsEngine::getCore(this->car->ksPhysics);
  v13 = v12->createRigidBody(v12);
  v14 = this->hubMass;
  this->hub = v13;
  ((void (*)(IRigidBody *, float, int, int, int))v13->setMassBox)(
    v13,
    COERCE_FLOAT(LODWORD(v14)),
    1045220557,
    1058642330,
    1058642330);
  SuspensionML::attach(this);
  *(float *)&v15 = 0.0;
  *(float *)&v56 = 0.0;
  do
  {
    v16 = std::to_wstring(&v59, v15);
    LOBYTE(v77) = 24;
    v17 = std::operator+<wchar_t>(&v58, L"JOINT", v16);
    LOBYTE(v77) = 25;
    std::operator+<wchar_t>(&v76, v17, L"_CAR");
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    LOBYTE(v77) = 28;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    v59._Myres = 7;
    v59._Bx._Buf[0] = 0;
    v59._Mysize = 0;
    v18 = std::to_wstring(&v60, v15);
    LOBYTE(v77) = 29;
    v19 = std::operator+<wchar_t>(&v61, L"JOINT", v18);
    LOBYTE(v77) = 30;
    std::operator+<wchar_t>(&v65, v19, L"_TYRE");
    if ( v61._Myres >= 8 )
      operator delete(v61._Bx._Ptr);
    v61._Myres = 7;
    v61._Mysize = 0;
    v61._Bx._Buf[0] = 0;
    LOBYTE(v77) = 33;
    if ( v60._Myres >= 8 )
      operator delete(v60._Bx._Ptr);
    v60._Myres = 7;
    v60._Mysize = 0;
    v60._Bx._Buf[0] = 0;
    MLJoint::MLJoint(&_Val);
    v20 = v57;
    _Val.ballCar.relToTyre = *INIReader::getFloat3(&v64, (vec3f *)&key._Bx._Alias[12], v57, &v76);
    v21 = INIReader::getFloat3(&v64, (vec3f *)&section._Bx._Alias[12], v20, &v65);
    *(_QWORD *)&_Val.ballTyre.relToTyre.x = *(_QWORD *)&v21->x;
    v22 = this->basePosition.x;
    _Val.ballTyre.relToTyre.z = v21->z;
    if ( v22 > 0.0 )
    {
      LODWORD(_Val.ballCar.relToTyre.x) ^= _xmm;
      LODWORD(_Val.ballTyre.relToTyre.x) ^= _xmm;
    }
    v23 = this->car->body;
    this->hub->localToWorld(this->hub, &v44, (const vec3f *)&_Val);
    v23->worldToLocal(v23, (vec3f *)&v46, &v44);
    v24 = this->hub;
    _Val.ballCar.relToCar.z = v47;
    v25 = this->car;
    *(_QWORD *)&_Val.ballCar.relToCar.x = v46;
    v26 = v25->body;
    v24->localToWorld(v24, &v42, &_Val.ballTyre.relToTyre);
    v26->worldToLocal(v26, (vec3f *)&v53, &v42);
    _Val.ballTyre.relToCar.z = v54;
    v27 = this->car;
    *(_QWORD *)&_Val.ballTyre.relToCar.x = v53;
    v27->body->localToWorld(v27->body, &v45, &_Val.ballCar.relToCar);
    this->car->body->localToWorld(this->car->body, &v43, &_Val.ballTyre.relToCar);
    v28 = PhysicsEngine::getCore(this->car->ksPhysics);
    _Val.joint = v28->createDistanceJoint(v28, this->car->body, this->hub, &v45, &v43);
    _printf("creating joint\n");
    _printf(
      "%s: (%f , %f , %f)\n",
      "ballCar",
      _Val.ballCar.relToCar.x,
      _Val.ballCar.relToCar.y,
      _Val.ballCar.relToCar.z);
    _printf(
      "%s: (%f , %f , %f)\n",
      "axle",
      _Val.ballTyre.relToCar.x,
      _Val.ballTyre.relToCar.y,
      _Val.ballTyre.relToCar.z);
    std::vector<MLJoint>::push_back(&this->joints, &_Val);
    if ( v65._Myres >= 8 )
      operator delete(v65._Bx._Ptr);
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    LOBYTE(v77) = 22;
    if ( v76._Myres >= 8 )
      operator delete(v76._Bx._Ptr);
    v15 = v56 + 1;
    v56 = v15;
  }
  while ( v15 < 5 );
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  std::wstring::assign(&v65, L"ROD_LENGTH", 0xAu);
  v29 = v57;
  LOBYTE(v77) = 34;
  v30 = INIReader::getFloat(&v64, v57, &v65);
  v11 = v65._Myres < 8;
  this->rodLength = v30;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v65._Bx._Ptr);
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  std::wstring::assign(&v65, L"TOE_OUT", 7u);
  LOBYTE(v77) = 35;
  v31 = INIReader::getFloat(&v64, v29, &v65);
  v11 = v65._Myres < 8;
  this->toeOUT_Linear = v31;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v65._Bx._Ptr);
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  std::wstring::assign(&v65, L"SPRING_RATE", 0xBu);
  LOBYTE(v77) = 36;
  v32 = INIReader::getFloat(&v64, v29, &v65);
  v11 = v65._Myres < 8;
  this->k = v32;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v65._Bx._Ptr);
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  std::wstring::assign(&v65, L"PROGRESSIVE_SPRING_RATE", 0x17u);
  LOBYTE(v77) = 37;
  v33 = INIReader::getFloat(&v64, v29, &v65);
  v11 = v65._Myres < 8;
  this->progressiveK = v33;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v65._Bx._Ptr);
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  std::wstring::assign(&v65, L"DAMP_BUMP", 9u);
  LOBYTE(v77) = 38;
  v34 = INIReader::getFloat(&v64, v29, &v65);
  v11 = v65._Myres < 8;
  this->damper.bumpSlow = v34;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v65._Bx._Ptr);
  std::wstring::wstring(&v76, L"DAMP_REBOUND");
  LOBYTE(v77) = 39;
  v35 = INIReader::getFloat(&v64, v29, &v76);
  v11 = v76._Myres < 8;
  this->damper.reboundSlow = v35;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v76._Bx._Ptr);
  std::wstring::wstring(&v76, L"DAMP_FAST_BUMP");
  LOBYTE(v77) = 40;
  v36 = INIReader::getFloat(&v64, v29, &v76);
  v11 = v76._Myres < 8;
  this->damper.bumpFast = v36;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v76._Bx._Ptr);
  std::wstring::wstring(&v76, L"DAMP_FAST_REBOUND");
  LOBYTE(v77) = 41;
  v37 = INIReader::getFloat(&v64, v29, &v76);
  v11 = v76._Myres < 8;
  this->damper.reboundFast = v37;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v76._Bx._Ptr);
  std::wstring::wstring(&v76, L"DAMP_FAST_BUMPTHRESHOLD");
  LOBYTE(v77) = 42;
  v38 = INIReader::getFloat(&v64, v29, &v76);
  v11 = v76._Myres < 8;
  this->damper.fastThresholdBump = v38;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v76._Bx._Ptr);
  std::wstring::wstring(&v76, L"DAMP_FAST_REBOUNDTHRESHOLD");
  LOBYTE(v77) = 43;
  v39 = INIReader::getFloat(&v64, v29, &v76);
  v11 = v76._Myres < 8;
  this->damper.fastThresholdRebound = v39;
  LOBYTE(v77) = 22;
  if ( !v11 )
    operator delete(v76._Bx._Ptr);
  std::wstring::wstring(&v65, L"STATIC_CAMBER");
  LOBYTE(v77) = 44;
  v40 = INIReader::getFloat(&v64, v29, &v65);
  v11 = v65._Myres < 8;
  v41 = _xmm;
  *(float *)&v55 = v40 * 0.017453;
  LODWORD(this->staticCamber) = v55 ^ _xmm;
  if ( !v11 )
  {
    operator delete(v65._Bx._Ptr);
    v41 = _xmm;
  }
  v65._Myres = 7;
  v65._Bx._Buf[0] = 0;
  v65._Mysize = 0;
  if ( v49 % 2 )
    LODWORD(this->staticCamber) ^= v41;
  LOBYTE(v77) = 4;
  `eh vector destructor iterator'(&ptr, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
  v77 = -1;
  INIReader::~INIReader(&v64);
}
void SuspensionML::resetDamage(SuspensionML *this)
{
  this->damageData.damageAmount = 0.0;
}
void SuspensionML::setDamage(SuspensionML *this, float amount)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4

  v2 = this->damageData.minVelocity;
  if ( amount > v2 )
  {
    v3 = amount - v2;
    v4 = this->damageData.maxDamage;
    v5 = v3 * this->damageData.damageGain;
    if ( v5 <= v4 )
      v4 = v5;
    this->damageData.damageAmount = v4;
  }
  if ( this->damageData.isDebug && amount != this->damageData.lastAmount )
    this->damageData.lastAmount = amount;
}
void SuspensionML::attach(SuspensionML *this)
{
  vec3f hubPos; // [esp+14h] [ebp-4Ch] BYREF
  mat44f bodyMatrix; // [esp+20h] [ebp-40h] BYREF

  ((void (*)(IRigidBody *, mat44f *, _DWORD))this->car->body->getWorldMatrix)(
    this->car->body,
    &bodyMatrix,
    0);
  this->car->body->localToWorld(this->car->body, &hubPos, &this->basePosition);
  this->hub->setRotation(this->hub, &bodyMatrix);
  this->hub->setPosition(this->hub, &hubPos);
}
void SuspensionML::setSteerLengthOffset(SuspensionML *this, float o)
{
  float v2; // xmm2_4
  float v4; // xmm0_4
  MLJoint *v5; // ecx
  float v6; // xmm0_4
  __m128 v7; // xmm2
  float v8; // eax
  IPhysicsCore *v9; // eax

  v2 = 0.0;
  v4 = this->basePosition.x;
  if ( v4 <= 0.0 )
  {
    if ( v4 < 0.0 )
      v2 = FLOAT_N1_0;
  }
  else
  {
    v2 = FLOAT_1_0;
  }
  v5 = this->joints._Myfirst;
  v6 = this->toeOUT_Linear * v2;
  v7 = (__m128)LODWORD(this->baseCarSteerPosition.x);
  v8 = this->baseCarSteerPosition.z;
  v7.m128_f32[0] = v7.m128_f32[0]
                 + (float)((float)((float)(this->damageData.damageDirection * this->damageData.damageAmount) + o) + v6);
  *(_QWORD *)&v5[4].ballCar.relToCar.x = _mm_unpacklo_ps(v7, (__m128)LODWORD(this->baseCarSteerPosition.y)).m128_u64[0];
  v5[4].ballCar.relToCar.z = v8;
  v9 = PhysicsEngine::getCore(this->car->ksPhysics);
  v9->reseatDistanceJointLocal(
    v9,
    this->joints._Myfirst[4].joint,
    &this->joints._Myfirst[4].ballCar.relToCar,
    &this->joints._Myfirst[4].ballTyre.relToTyre);
}
void SuspensionML::step(SuspensionML *this, float dt)
{
  IRigidBody *v3; // ecx
  IRigidBody *v4; // ebx
  float *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  SuspensionML_vtbl *v15; // eax
  IRigidBody_vtbl *v16; // eax
  double v17; // st7
  float v18; // xmm1_4
  SuspensionML_vtbl *v19; // eax
  IRigidBody_vtbl *v20; // eax
  float v21; // [esp+4Ch] [ebp-9Ch]
  float v; // [esp+4Ch] [ebp-9Ch]
  float v23; // [esp+50h] [ebp-98h] BYREF
  float v24; // [esp+54h] [ebp-94h]
  float v25; // [esp+58h] [ebp-90h]
  float v26; // [esp+5Ch] [ebp-8Ch]
  float v27; // [esp+60h] [ebp-88h]
  float v28; // [esp+64h] [ebp-84h]
  float v29; // [esp+68h] [ebp-80h] BYREF
  float v30; // [esp+6Ch] [ebp-7Ch]
  float v31; // [esp+70h] [ebp-78h]
  float v32; // [esp+74h] [ebp-74h]
  int v33[3]; // [esp+78h] [ebp-70h] BYREF
  vec3f v34; // [esp+84h] [ebp-64h] BYREF
  int v35[3]; // [esp+90h] [ebp-58h] BYREF
  char v36; // [esp+9Ch] [ebp-4Ch] BYREF
  float v37; // [esp+A0h] [ebp-48h]
  char v38[64]; // [esp+A8h] [ebp-40h] BYREF

  v3 = this->hub;
  this->steerTorque = 0.0;
  ((void (*)(IRigidBody *, vec3f *, _DWORD))v3->getPosition)(v3, &v34, 0);
  v4 = this->car->body;
  v4->worldToLocal(v4, (vec3f *)&v36, &v34);
  v5 = (float *)((int (*)(IRigidBody *, char *, _DWORD))v4->getWorldMatrix)(v4, v38, 0);
  v6 = this->progressiveK;
  v7 = this->packerRange;
  v8 = this->k;
  v9 = v5[4];
  v10 = (float)(v37 - this->basePosition.y) + this->rodLength;
  v11 = v5[5];
  v12 = v5[6];
  v28 = v9;
  v26 = v11;
  v27 = v12;
  this->status.travel = v10;
  v13 = (float)((float)(v6 * v10) + v8) * v10;
  v21 = v13;
  if ( v7 != 0.0 && v10 > v7 && v8 != 0.0 )
  {
    v13 = (float)((float)(v10 - v7) * this->bumpStopRate) + v13;
    v21 = v13;
  }
  LODWORD(v14) = LODWORD(v13) ^ _xmm;
  v15 = this->__vftable;
  v23 = v9 * v14;
  v24 = v11 * v14;
  v25 = v12 * v14;
  v15->addForceAtPos(this, (const vec3f *)&v23, &v34, 0, 0);
  v16 = v4->__vftable;
  v23 = 0.0;
  v24 = v21;
  v25 = 0.0;
  v16->addLocalForceAtLocalPos(v4, (const vec3f *)&v23, &this->basePosition);
  this->hub->getVelocity(this->hub, (vec3f *)v35);
  v4->getLocalPointVelocity(v4, (vec3f *)v33, &this->basePosition);
  v = (float)((float)((float)(*(float *)v35 - *(float *)v33) * v28)
            + (float)((float)(*(float *)&v35[1] - *(float *)&v33[1]) * v26))
    + (float)((float)(*(float *)&v35[2] - *(float *)&v33[2]) * v27);
  v17 = Damper::getForce(&this->damper, v);
  v18 = v28;
  v19 = this->__vftable;
  v32 = v17;
  this->status.damperSpeedMS = v;
  v29 = v18 * v32;
  v30 = v26 * v32;
  v31 = v27 * v32;
  v19->addForceAtPos(this, (const vec3f *)&v29, &v34, 0, 0);
  v20 = v4->__vftable;
  LODWORD(v23) = LODWORD(v29) ^ _xmm;
  LODWORD(v24) = LODWORD(v30) ^ _xmm;
  LODWORD(v25) = LODWORD(v31) ^ _xmm;
  v20->addForceAtLocalPos(v4, (const vec3f *)&v23, &this->basePosition);
}
void SuspensionML::stop(SuspensionML *this)
{
  ((void (*)(IRigidBody *, int))this->hub->stop)(this->hub, 1065353216);
}
