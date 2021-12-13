#include "tyretester.h"
IRayCaster *TyreTester::createRayCaster(TyreTester *this, float length)
{
  return 0;
}
bool TyreTester::rayCastWithRayCaster(TyreTester *this, const vec3f *org, const vec3f *dir, RayCastResult *result, float length, IRayCaster *rayCaster)
{
  return 0;
}
double TyreTester::getK(TyreTester *this)
{
  return 0.0;
}
void TyreTester::TyreTester(TyreTester *this, const std::wstring *dataPath, int index)
{
  IRayTrackCollisionProvider *v4; // edi
  Tyre *v5; // eax
  Tyre *v6; // eax
  std::wstring v7; // [esp-24h] [ebp-44h] BYREF
  int v8; // [esp-Ch] [ebp-2Ch]
  int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp-4h] [ebp-24h]
  TyreTester *v11; // [esp+Ch] [ebp-14h]
  Tyre *v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-4h]

  v11 = this;
  this->bumpStopProgressive = 0.0;
  this->baseCFM = 0.0000001;
  v4 = &this->IRayTrackCollisionProvider;
  v13 = 0;
  this->IRayTrackCollisionProvider::__vftable = (IRayTrackCollisionProvider_vtbl *)&IRayTrackCollisionProvider::`vftable';
  this->ISuspension::__vftable = (TyreTester_vtbl *)&TyreTester::`vftable'{for `ISuspension'};
  this->IRayTrackCollisionProvider::__vftable = (IRayTrackCollisionProvider_vtbl *)&TyreTester::`vftable'{for `IRayTrackCollisionProvider'};
  SurfaceDef::SurfaceDef(&this->surf);
  this->status.travel = 0.0;
  this->status.damperSpeedMS = 0.0;
  v10 = 1632;
  this->slipAngle = 0.0;
  this->velocity = 20.0;
  this->load = 0.0;
  v5 = (Tyre *)operator new(v10);
  v12 = v5;
  LOBYTE(v13) = 2;
  if ( v5 )
    Tyre::Tyre(v5);
  else
    v6 = 0;
  v10 = 0;
  v9 = 0;
  v8 = index;
  this->tyre = v6;
  LOBYTE(v13) = 1;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, dataPath, 0, 0xFFFFFFFF);
  Tyre::init(this->tyre, this, v4, v7, v8, v9, (Car *)v10);
  this->surf.dirtAdditiveK = 0.0;
  this->surf.gripMod = 1.0;
}
TyreTester *TyreTester::`vector deleting destructor'(char *this, unsigned int a2)
{
  return TyreTester::`vector deleting destructor'((TyreTester *)(this - 48), a2);
}
TyreTester *TyreTester::`vector deleting destructor'(TyreTester *this, unsigned int a2)
{
  Tyre *v3; // edi

  this->ISuspension::__vftable = (TyreTester_vtbl *)&TyreTester::`vftable'{for `ISuspension'};
  this->IRayTrackCollisionProvider::__vftable = (IRayTrackCollisionProvider_vtbl *)&TyreTester::`vftable'{for `IRayTrackCollisionProvider'};
  v3 = this->tyre;
  if ( v3 )
  {
    Tyre::~Tyre(v3);
    operator delete(v3);
  }
  this->IRayTrackCollisionProvider::__vftable = (IRayTrackCollisionProvider_vtbl *)&IRayTrackCollisionProvider::`vftable';
  this->ISuspension::__vftable = (TyreTester_vtbl *)&ISuspension::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
vec3f *TyreTester::getBasePosition(TyreTester *this, vec3f *result)
{
  vec3f *v2; // eax

  v2 = result;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  return v2;
}
std::vector<DebugLine> *TyreTester::getDebugLines(TyreTester *this, std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix)
{
  std::vector<DebugLine> *v4; // eax

  v4 = result;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  return v4;
}
mat44f *TyreTester::getHubWorldMatrix(TyreTester *this, mat44f *result)
{
  int v2; // ecx
  __int128 v3; // xmm3
  __int128 v4; // xmm1
  __int128 v5; // xmm2
  mat44f *v6; // eax
  int v7; // [esp+0h] [ebp-60h]
  int v8; // [esp+4h] [ebp-5Ch]
  float v9; // [esp+18h] [ebp-48h]
  float v10; // [esp+1Ch] [ebp-44h]
  mat44f v11; // [esp+20h] [ebp-40h] BYREF

  mat44f::mat44f(result);
  mat44f::loadIdentity(result);
  v9 = __libm_sse2_cosf(v7, v8).m128_f32[0];
  v10 = __libm_sse2_sinf(v2).m128_f32[0];
  mat44f::mat44f(&v11);
  v11.M44 = 1.0;
  v11.M22 = (float)(1.0 - v9) + v9;
  v11.M33 = (float)((float)(1.0 - v9) * 0.0) + v9;
  v11.M11 = v11.M33;
  v11.M12 = (float)(v10 * 0.0) + (float)((float)(1.0 - v9) * 0.0);
  v11.M21 = (float)((float)(1.0 - v9) * 0.0) - (float)(v10 * 0.0);
  v11.M13 = (float)((float)(1.0 - v9) * 0.0) - v10;
  v11.M31 = v10 + (float)((float)(1.0 - v9) * 0.0);
  v3 = *(_OWORD *)&result->M41;
  v11.M23 = v11.M12;
  v11.M32 = v11.M21;
  v4 = *(_OWORD *)&result->M21;
  v5 = *(_OWORD *)&result->M31;
  *(__m128 *)&result->M11 = DirectX::XMMatrixMultiply((__m128 *)&v11, *(__m128 *)&result->M11);
  v6 = result;
  *(_OWORD *)&result->M21 = v4;
  *(_OWORD *)&result->M31 = v5;
  *(_OWORD *)&result->M41 = v3;
  return v6;
}
double TyreTester::getLoad(TyreTester *this)
{
  return this->load;
}
vec3f *TyreTester::getPointVelocity(TyreTester *this, vec3f *result, const vec3f *p)
{
  vec3f *v3; // eax
  float v4; // ecx

  v3 = result;
  v4 = this->velocity;
  result->x = 0.0;
  result->y = 0.0;
  result->z = v4;
  return v3;
}
SuspensionStatus *TyreTester::getStatus(TyreTester *this)
{
  return &this->status;
}
char TyreTester::rayCast(TyreTester *this, const vec3f *org, const vec3f *dir, RayCastResult *result, float length)
{
  __m128 v5; // xmm3
  float v6; // xmm0_4

  v5 = (__m128)LODWORD(this->bumpStopProgressive);
  v6 = (float)((float)(*(float *)(LODWORD(this->k) + 624) - *(float *)(LODWORD(this->k) + 160))
             * *(float *)(LODWORD(this->k) + 144))
     + *(float *)(LODWORD(this->k) + 20);
  result->hasHit = 1;
  *(_QWORD *)&result->normal.x = _mm_unpacklo_ps((__m128)0i64, (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
  result->normal.z = 0.0;
  v5.m128_f32[0] = (float)(v5.m128_f32[0] / v6) - *(float *)(LODWORD(this->k) + 16);
  *(_QWORD *)&result->pos.x = _mm_unpacklo_ps((__m128)0i64, v5).m128_u64[0];
  result->pos.z = 0.0;
  result->surfaceDef = (SurfaceDef *)&this->staticCamber;
  return 1;
}
std::vector<TyreTestFrame> *TyreTester::slipAngleSweep(TyreTester *this, std::vector<TyreTestFrame> *result, float minSA, float maxSA, float aload, int steps)
{
  std::vector<TyreTestFrame> *v7; // esi
  Tyre *v8; // ecx
  int v9; // ecx
  float v10; // xmm1_4
  Tyre *v11; // eax
  float v12; // xmm0_4
  Tyre *v13; // esi
  Tyre *v14; // eax
  int v16; // [esp+4h] [ebp-40h]
  int v17; // [esp+8h] [ebp-3Ch]
  int v18; // [esp+1Ch] [ebp-28h]
  TyreTestFrame _Val; // [esp+20h] [ebp-24h] BYREF
  int v20; // [esp+40h] [ebp-4h]
  float maxSAa; // [esp+50h] [ebp+Ch]

  v7 = result;
  this->tyre->debugOutput = 1;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v8 = this->tyre;
  v20 = 0;
  maxSAa = (float)(maxSA - minSA) / (float)steps;
  this->load = aload;
  Tyre::reset(v8);
  this->tyre->externalInputs.isActive = 1;
  this->tyre->externalInputs.load = this->load;
  v9 = 0;
  v18 = 0;
  this->tyre->externalInputs.slipRatio = 0.0;
  if ( steps > 0 )
  {
    v10 = FLOAT_0_017453;
    do
    {
      this->tyre->status.blister = 0.0;
      this->tyre->status.grain = 0.0;
      v11 = this->tyre;
      v12 = (float)((float)v9 * maxSAa) + minSA;
      this->slipAngle = v12;
      v11->externalInputs.slipAngle = v12 * v10;
      v13 = this->tyre;
      v13->status.angularVelocity = COERCE_FLOAT(__libm_sse2_cosf(v16, v17).m128_u32[0] & _xmm)
                                  * (float)(this->velocity / v13->data.radius);
      Tyre::step(this->tyre, *(float *)&this, 0.003);
      v14 = this->tyre;
      v7 = result;
      _Val.Fx = v14->status.Fx;
      _Val.Fy = v14->status.Fy;
      _Val.Mz = v14->status.Mz;
      _Val.slipAngle = v14->status.slipAngleRAD * 57.29578;
      _Val.slipRatio = v14->status.slipRatio;
      std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element>>::push_back(
        result,
        &_Val);
      v10 = FLOAT_0_017453;
      v9 = v18 + 1;
      v18 = v9;
    }
    while ( v9 < steps );
  }
  return v7;
}
std::vector<TyreTestFrame> *TyreTester::slipRatioSweep(TyreTester *this, std::vector<TyreTestFrame> *result, float minSR, float maxSR, float aload, int steps)
{
  Tyre *v7; // ecx
  int v8; // eax
  float v9; // xmm1_4
  float v10; // xmm3_4
  __m128i v11; // xmm2
  Tyre *v12; // eax
  Tyre *v13; // eax
  int v15; // [esp+1Ch] [ebp-28h]
  TyreTestFrame _Val; // [esp+20h] [ebp-24h] BYREF
  int v17; // [esp+40h] [ebp-4h]
  float maxSRa; // [esp+50h] [ebp+Ch]

  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v7 = this->tyre;
  v17 = 0;
  maxSRa = (float)(maxSR - minSR) / (float)steps;
  this->load = aload;
  Tyre::reset(v7);
  this->tyre->externalInputs.isActive = 1;
  this->tyre->externalInputs.load = this->load;
  this->tyre->externalInputs.slipAngle = 0.0;
  v8 = 0;
  v15 = 0;
  if ( steps > 0 )
  {
    v9 = minSR;
    v10 = minSR + 1.0;
    do
    {
      v11 = _mm_cvtsi32_si128(v8);
      v12 = this->tyre;
      this->slipAngle = 0.0;
      *(float *)v11.m128i_i32 = _mm_cvtepi32_ps(v11).m128_f32[0] * maxSRa;
      v12->externalInputs.slipRatio = *(float *)v11.m128i_i32 + v9;
      this->tyre->status.angularVelocity = (float)(this->velocity / this->tyre->data.radius)
                                         * (float)(v10 + *(float *)v11.m128i_i32);
      Tyre::step(this->tyre, *(float *)&result, 0.003);
      v13 = this->tyre;
      LODWORD(_Val.Fx) = LODWORD(v13->status.Fx) ^ _xmm;
      _Val.Fy = v13->status.Fy;
      _Val.Mz = v13->status.Mz;
      _Val.slipAngle = v13->status.slipAngleRAD * 57.29578;
      _Val.slipRatio = v13->status.slipRatio;
      std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element>>::push_back(
        result,
        &_Val);
      v10 = minSR + 1.0;
      v8 = v15 + 1;
      v9 = minSR;
      v15 = v8;
    }
    while ( v8 < steps );
  }
  return result;
}
std::vector<TyreTestFrame> *TyreTester::srSASweep(TyreTester *this, std::vector<TyreTestFrame> *result, float sa, float minsr, float maxsr, float load, int steps)
{
  std::vector<TyreTestFrame> *v8; // esi
  Tyre *v9; // ecx
  int v10; // ecx
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  Tyre *v14; // eax
  Tyre *v15; // esi
  Tyre *v16; // eax
  int v18; // [esp+4h] [ebp-4Ch]
  int v19; // [esp+8h] [ebp-48h]
  float v20; // [esp+24h] [ebp-2Ch]
  int v21; // [esp+28h] [ebp-28h]
  TyreTestFrame _Val; // [esp+2Ch] [ebp-24h] BYREF
  int v23; // [esp+4Ch] [ebp-4h]
  float maxsra; // [esp+60h] [ebp+10h]

  v8 = result;
  this->tyre->debugOutput = 1;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v9 = this->tyre;
  v23 = 0;
  maxsra = (float)(maxsr - minsr) / (float)steps;
  this->load = load;
  Tyre::reset(v9);
  v10 = 0;
  v21 = 0;
  this->tyre->externalInputs.isActive = 1;
  this->tyre->externalInputs.load = load;
  if ( steps > 0 )
  {
    v11 = minsr;
    v12 = sa;
    v13 = sa * 0.017453;
    do
    {
      v14 = this->tyre;
      this->slipAngle = v12;
      v14->externalInputs.slipAngle = v13;
      v20 = (float)v10 * maxsra;
      this->tyre->externalInputs.slipRatio = v20 + v11;
      v15 = this->tyre;
      v15->status.angularVelocity = COERCE_FLOAT(__libm_sse2_cosf(v18, v19).m128_u32[0] & _xmm)
                                  * (float)((float)(this->velocity / v15->data.radius)
                                          * (float)((float)(minsr + 1.0) + v20));
      Tyre::step(this->tyre, *(float *)&this, 0.003);
      v16 = this->tyre;
      v8 = result;
      _Val.Fx = v16->status.Fx;
      _Val.Fy = v16->status.Fy;
      _Val.Mz = v16->status.Mz;
      _Val.slipAngle = v16->status.slipAngleRAD * 57.29578;
      _Val.slipRatio = v16->status.slipRatio;
      std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element>>::push_back(
        result,
        &_Val);
      v13 = sa * 0.017453;
      v10 = v21 + 1;
      v11 = minsr;
      v12 = sa;
      v21 = v10;
    }
    while ( v10 < steps );
  }
  return v8;
}
