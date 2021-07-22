#include "gearshiftshake.h"
void __userpurge GearShiftShake::GearShiftShake(GearShiftShake *this@<ecx>, __m128 a2@<xmm0>, CarAvatar *icar)
{
  CarAvatar *v4; // eax
  Node *v5; // eax
  bool v6; // cf
  Node *v7; // eax
  std::wstring v8; // [esp-1Ch] [ebp-5Ch] BYREF
  unsigned int v9; // [esp-4h] [ebp-44h]
  GearShiftShake *v10; // [esp+14h] [ebp-2Ch]
  std::wstring v11; // [esp+18h] [ebp-28h] BYREF
  int v12; // [esp+3Ch] [ebp-4h]

  v10 = this;
  v9 = (unsigned int)icar->game;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"GEAR_SHAKE", 0xAu);
  GameObject::GameObject(this, v8, (Game *)v9);
  v12 = 0;
  this->__vftable = (GearShiftShake_vtbl *)&GearShiftShake::`vftable';
  this->car = icar;
  SignalGenerator3D<SinSignalGenerator>::SignalGenerator3D<SinSignalGenerator>(&this->shakeGenerator, a2);
  mat44f::mat44f(&this->baseMatrix);
  this->gearRotations._Myfirst = 0;
  this->gearRotations._Mylast = 0;
  this->gearRotations._Myend = 0;
  v9 = 8;
  LOBYTE(v12) = 2;
  v8._Myres = (unsigned int)L"SHIFT_HD";
  this->currentShiftRot.x = 0.0;
  this->currentShiftRot.y = 0.0;
  this->currentShiftRot.z = 0.0;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, (const wchar_t *)v8._Myres, v9);
  v4 = this->car;
  LOBYTE(v12) = 3;
  v5 = v4->carNode->findChildByName(v4->carNode, &v11, 1);
  v6 = v11._Myres < 8;
  this->target = v5;
  LOBYTE(v12) = 2;
  if ( !v6 )
    operator delete(v11._Bx._Ptr);
  if ( this->target )
  {
    _printf("GearShiftShake: SHIFT_HD found\n");
    v7 = this->target;
    *(__m128i *)&this->baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v7->matrix);
    *(__m128i *)&this->baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v7->matrix.M21);
    *(__m128i *)&this->baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v7->matrix.M31);
    *(__m128i *)&this->baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v7->matrix.M41);
  }
  *(_QWORD *)&this->shakeGenerator.freqScale.x = _mm_unpacklo_ps(
                                                   (__m128)LODWORD(FLOAT_100_0),
                                                   (__m128)LODWORD(FLOAT_100_0)).m128_u64[0];
  this->shakeGenerator.freqScale.z = 100.0;
  *(_QWORD *)&this->shakeGenerator.scale.x = _mm_unpacklo_ps(
                                               (__m128)LODWORD(FLOAT_0_0099999998),
                                               (__m128)LODWORD(FLOAT_0_0099999998)).m128_u64[0];
  this->shakeGenerator.scale.z = 0.0099999998;
  v9 = (unsigned int)&v11;
  this->shakeGenerator.randomBlend = 0.0;
  *(_QWORD *)v11._Bx._Buf = 3245342720i64;
  *(_DWORD *)&v11._Bx._Alias[8] = 1106247680;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)v9);
  *(_QWORD *)v11._Bx._Buf = 0i64;
  *(_DWORD *)&v11._Bx._Alias[8] = 0;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  *(_QWORD *)v11._Bx._Buf = 1097859072i64;
  *(_DWORD *)&v11._Bx._Alias[8] = -1049624576;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  *(_QWORD *)v11._Bx._Buf = 3245342720i64;
  *(_DWORD *)&v11._Bx._Alias[8] = -1049624576;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  *(_QWORD *)v11._Bx._Buf = 1097859072i64;
  *(_DWORD *)&v11._Bx._Alias[8] = 0;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  *(_QWORD *)v11._Bx._Buf = 3245342720i64;
  *(_DWORD *)&v11._Bx._Alias[8] = 0;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  *(_QWORD *)v11._Bx._Buf = 1097859072i64;
  *(_DWORD *)&v11._Bx._Alias[8] = 1097859072;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  *(_QWORD *)v11._Bx._Buf = 3245342720i64;
  *(_DWORD *)&v11._Bx._Alias[8] = 1097859072;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  *(_QWORD *)v11._Bx._Buf = 1097859072i64;
  *(_DWORD *)&v11._Bx._Alias[8] = 1106247680;
  std::vector<DRSZone>::push_back(&this->gearRotations, (const vec3f *)&v11);
  this->currentBlend = 0.80000001;
}
void GearShiftShake::~GearShiftShake(GearShiftShake *this)
{
  std::vector<vec3f> *v2; // esi

  this->__vftable = (GearShiftShake_vtbl *)&GearShiftShake::`vftable';
  v2 = &this->gearRotations;
  if ( this->gearRotations._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->gearRotations);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  this->shakeGenerator.__vftable = (SignalGenerator3D<SinSignalGenerator>_vtbl *)&SignalGenerator3D<SinSignalGenerator>::`vftable';
  `eh vector destructor iterator'(
    this->shakeGenerator.sins,
    0xCu,
    3,
    (void (*)(void *))SinSignalGenerator::~SinSignalGenerator);
  GameObject::~GameObject(this);
}
GearShiftShake *GearShiftShake::`vector deleting destructor'(GearShiftShake *this, unsigned int a2)
{
  GearShiftShake::~GearShiftShake(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void GearShiftShake::update(GearShiftShake *this, float deltaT)
{
  CarAvatar *v3; // ecx
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm2_4
  __m128 v7; // xmm0
  float v8; // xmm0_4
  float v9; // xmm0_4
  __m128 v10; // xmm5
  float v11; // xmm3_4
  int v12; // ecx
  float v13; // eax
  __m128 v14; // xmm6
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm5_4
  Node *v19; // esi
  float v20; // xmm2_4
  float v21; // xmm4_4
  __int128 v22; // xmm3
  __int128 v23; // xmm2
  __int128 v24; // xmm1
  Node *v25; // esi
  __int128 v26; // xmm1
  __int128 v27; // xmm2
  __int128 v28; // xmm3
  __m128 v29; // xmm0
  __int128 v30; // xmm1
  __int128 v31; // xmm2
  __int128 v32; // xmm3
  int v33; // [esp+4h] [ebp-E0h]
  int v34; // [esp+4h] [ebp-E0h]
  int v35; // [esp+8h] [ebp-DCh]
  int v36; // [esp+8h] [ebp-DCh]
  float v37; // [esp+18h] [ebp-CCh]
  float v38; // [esp+18h] [ebp-CCh]
  float v39; // [esp+1Ch] [ebp-C8h]
  float v40; // [esp+1Ch] [ebp-C8h]
  __int64 v41; // [esp+28h] [ebp-BCh]
  unsigned __int64 v42; // [esp+28h] [ebp-BCh]
  float v43; // [esp+34h] [ebp-B0h]
  float v44; // [esp+38h] [ebp-ACh]
  float v45; // [esp+3Ch] [ebp-A8h]
  float v46; // [esp+40h] [ebp-A4h]
  float v47; // [esp+44h] [ebp-A0h]
  float v48; // [esp+48h] [ebp-9Ch] BYREF
  mat44f v49; // [esp+4Ch] [ebp-98h] BYREF
  int v50; // [esp+90h] [ebp-54h]
  mat44f v51; // [esp+94h] [ebp-50h] BYREF
  float v52; // [esp+E0h] [ebp-4h]

  if ( this->target )
  {
    ((void (*)(SignalGenerator3D<SinSignalGenerator> *, _DWORD))this->shakeGenerator.step)(
      &this->shakeGenerator,
      LODWORD(deltaT));
    this->shakeGenerator.getValue(&this->shakeGenerator, (vec3f *)&v48);
    v3 = this->car;
    v4 = v48;
    v5 = v49.M11;
    v6 = v49.M12;
    v7 = (__m128)LODWORD(v3->physicsState.engineRPM);
    v7.m128_f32[0] = v7.m128_f32[0] * 0.1;
    *(_QWORD *)&this->shakeGenerator.freqScale.x = _mm_unpacklo_ps(v7, v7).m128_u64[0];
    LODWORD(this->shakeGenerator.freqScale.z) = v7.m128_i32[0];
    v47 = v4;
    v37 = v6;
    v8 = fsqrt((float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6));
    if ( v8 != 0.0 )
    {
      v47 = (float)(1.0 / v8) * v4;
      v9 = 1.0 / v8;
      v48 = v47;
      v37 = v9 * v6;
      v49.M12 = v9 * v6;
      v49.M11 = v9 * v5;
    }
    v14 = (__m128)LODWORD(this->currentShiftRot.x);
    v10 = (__m128)LODWORD(this->currentShiftRot.y);
    v11 = this->currentBlend;
    v12 = v3->physicsState.gear;
    v13 = this->gearRotations._Myfirst[v12].z;
    v41 = *(_QWORD *)&this->gearRotations._Myfirst[v12].x;
    v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] - *(float *)&v41) * v11) + *(float *)&v41;
    v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] - *((float *)&v41 + 1)) * v11) + *((float *)&v41 + 1);
    v42 = _mm_unpacklo_ps(v14, v10).m128_u64[0];
    v52 = (float)((float)(this->currentShiftRot.z - v13) * v11) + v13;
    v15 = fsqrt(
            (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v14.m128_f32[0] * v14.m128_f32[0]))
          + (float)(v52 * v52));
    if ( v15 == 0.0 )
    {
      v16 = v52;
      v44 = *((float *)&v42 + 1);
      v45 = *(float *)&v42;
    }
    else
    {
      v45 = (float)(1.0 / v15) * v14.m128_f32[0];
      v16 = (float)(1.0 / v15) * v52;
      v44 = (float)(1.0 / v15) * *((float *)&v42 + 1);
    }
    v46 = v16;
    v39 = __libm_sse2_cosf(v33, v35).m128_f32[0];
    v43 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f((mat44f *)&v49.M13);
    v50 = 1065353216;
    v49.M24 = (float)((float)(v49.M11 * v49.M11) * (float)(1.0 - v39)) + v39;
    v49.M13 = (float)((float)(v47 * v47) * (float)(1.0 - v39)) + v39;
    v49.M41 = (float)((float)(v37 * v37) * (float)(1.0 - v39)) + v39;
    v17 = (float)(v49.M11 * v47) * (float)(1.0 - v39);
    v49.M14 = (float)(v37 * v43) + v17;
    v49.M23 = v17 - (float)(v37 * v43);
    v18 = (float)(v37 * v49.M11) * (float)(1.0 - v39);
    v49.M21 = (float)((float)(v37 * v47) * (float)(1.0 - v39)) - (float)(v49.M11 * v43);
    v49.M33 = (float)(v49.M11 * v43) + (float)((float)(v37 * v47) * (float)(1.0 - v39));
    v49.M31 = (float)(v47 * v43) + v18;
    v49.M34 = v18 - (float)(v47 * v43);
    v38 = __libm_sse2_cosf(v34, v36).m128_f32[0];
    v40 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f(&v51);
    v19 = this->target;
    v51.M11 = (float)((float)(v45 * v45) * (float)(1.0 - v38)) + v38;
    v51.M44 = 1.0;
    v51.M22 = (float)((float)(v44 * v44) * (float)(1.0 - v38)) + v38;
    v51.M33 = (float)((float)(v46 * v46) * (float)(1.0 - v38)) + v38;
    v20 = (float)(v44 * v45) * (float)(1.0 - v38);
    v51.M12 = (float)(v46 * v40) + v20;
    v51.M21 = v20 - (float)(v46 * v40);
    v21 = (float)(v46 * v44) * (float)(1.0 - v38);
    v22 = *(_OWORD *)&v51.M41;
    v51.M13 = (float)((float)(v46 * v45) * (float)(1.0 - v38)) - (float)(v44 * v40);
    v51.M31 = (float)(v44 * v40) + (float)((float)(v46 * v45) * (float)(1.0 - v38));
    v51.M23 = (float)(v45 * v40) + v21;
    v51.M32 = v21 - (float)(v45 * v40);
    v23 = *(_OWORD *)&v51.M31;
    v24 = *(_OWORD *)&v51.M21;
    *(__m128 *)&v19->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&v49.M13, *(__m128 *)&v51.M11);
    *(_OWORD *)&v19->matrix.M21 = v24;
    *(_OWORD *)&v19->matrix.M31 = v23;
    *(_OWORD *)&v19->matrix.M41 = v22;
    v25 = this->target;
    v26 = *(_OWORD *)&this->baseMatrix.M21;
    v27 = *(_OWORD *)&this->baseMatrix.M31;
    v28 = *(_OWORD *)&this->baseMatrix.M41;
    *(_OWORD *)&v51.M11 = *(_OWORD *)&this->baseMatrix.M11;
    v29 = *(__m128 *)&v25->matrix.M11;
    *(_OWORD *)&v51.M21 = v26;
    v30 = *(_OWORD *)&v25->matrix.M21;
    *(_OWORD *)&v51.M31 = v27;
    v31 = *(_OWORD *)&v25->matrix.M31;
    *(_OWORD *)&v51.M41 = v28;
    v32 = *(_OWORD *)&v25->matrix.M41;
    *(__m128 *)&v25->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&v51, v29);
    *(_OWORD *)&v25->matrix.M21 = v30;
    *(_OWORD *)&v25->matrix.M31 = v31;
    *(_OWORD *)&v25->matrix.M41 = v32;
  }
}
