#include "boundingfrustum.h
void BoundingFrustum::BoundingFrustum(BoundingFrustum *this, const mat44f *iviewProj)
{
  this->__vftable = (BoundingFrustum_vtbl *)&BoundingFrustum::`vftable';
  mat44f::mat44f(&this->matViewProj);
  this->planes[0].normal.x = 0.0;
  this->planes[0].normal.y = 0.0;
  this->planes[0].normal.z = 0.0;
  this->planes[0].d = 0.0;
  this->planes[1].normal.x = 0.0;
  this->planes[1].normal.y = 0.0;
  this->planes[1].normal.z = 0.0;
  this->planes[1].d = 0.0;
  this->planes[2].normal.x = 0.0;
  this->planes[2].normal.y = 0.0;
  this->planes[2].normal.z = 0.0;
  this->planes[2].d = 0.0;
  this->planes[3].normal.x = 0.0;
  this->planes[3].normal.y = 0.0;
  this->planes[3].normal.z = 0.0;
  this->planes[3].d = 0.0;
  this->planes[4].normal.x = 0.0;
  this->planes[4].normal.y = 0.0;
  this->planes[4].normal.z = 0.0;
  this->planes[4].d = 0.0;
  this->planes[5].normal.x = 0.0;
  this->planes[5].normal.y = 0.0;
  this->planes[5].normal.z = 0.0;
  this->planes[5].d = 0.0;
  mat44f::mat44f(&this->invViewProj);
  BoundingFrustum::setMatrix(this, iviewProj);
}
void BoundingFrustum::~BoundingFrustum(BoundingFrustum *this)
{
  this->__vftable = (BoundingFrustum_vtbl *)&BoundingFrustum::`vftable';
}
BoundingFrustum *BoundingFrustum::`vector deleting destructor'(BoundingFrustum *this, unsigned int a2)
{
  this->__vftable = (BoundingFrustum_vtbl *)&BoundingFrustum::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void BoundingFrustum::getCorners(BoundingFrustum *this, std::vector<vec3f> *corners)
{
  float v3; // xmm4_4
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  vec3f _Val; // [esp+0h] [ebp-Ch] BYREF

  v3 = (float)((float)((float)(this->invViewProj.M22 * -1.0) + (float)(this->invViewProj.M12 * -1.0))
             + (float)(this->invViewProj.M32 * 0.0))
     + this->invViewProj.M42;
  v4 = (float)((float)((float)(this->invViewProj.M23 * -1.0) + (float)(this->invViewProj.M13 * -1.0))
             + (float)(this->invViewProj.M33 * 0.0))
     + this->invViewProj.M43;
  v5 = (float)((float)((float)(this->invViewProj.M24 * -1.0) + (float)(this->invViewProj.M14 * -1.0))
             + (float)(this->invViewProj.M34 * 0.0))
     + this->invViewProj.M44;
  _Val.x = (float)(1.0 / v5)
         * (float)((float)((float)((float)(this->invViewProj.M21 * -1.0) + (float)(this->invViewProj.M11 * -1.0))
                         + (float)(this->invViewProj.M31 * 0.0))
                 + this->invViewProj.M41);
  _Val.y = (float)(1.0 / v5) * v3;
  _Val.z = (float)(1.0 / v5) * v4;
  std::vector<DRSZone>::push_back(corners, &_Val);
  v6 = (float)((float)((float)(this->invViewProj.M22 * -1.0) + this->invViewProj.M12)
             + (float)(this->invViewProj.M32 * 0.0))
     + this->invViewProj.M42;
  v7 = (float)((float)((float)(this->invViewProj.M23 * -1.0) + this->invViewProj.M13)
             + (float)(this->invViewProj.M33 * 0.0))
     + this->invViewProj.M43;
  v8 = (float)((float)((float)(this->invViewProj.M24 * -1.0) + this->invViewProj.M14)
             + (float)(this->invViewProj.M34 * 0.0))
     + this->invViewProj.M44;
  _Val.x = (float)(1.0 / v8)
         * (float)((float)((float)((float)(this->invViewProj.M21 * -1.0) + this->invViewProj.M11)
                         + (float)(this->invViewProj.M31 * 0.0))
                 + this->invViewProj.M41);
  _Val.y = (float)(1.0 / v8) * v6;
  _Val.z = (float)(1.0 / v8) * v7;
  std::vector<DRSZone>::push_back(corners, &_Val);
  v9 = (float)((float)(this->invViewProj.M22 + this->invViewProj.M12) + (float)(this->invViewProj.M32 * 0.0))
     + this->invViewProj.M42;
  v10 = (float)((float)(this->invViewProj.M23 + this->invViewProj.M13) + (float)(this->invViewProj.M33 * 0.0))
      + this->invViewProj.M43;
  v11 = (float)((float)(this->invViewProj.M24 + this->invViewProj.M14) + (float)(this->invViewProj.M34 * 0.0))
      + this->invViewProj.M44;
  _Val.x = (float)(1.0 / v11)
         * (float)((float)((float)(this->invViewProj.M21 + this->invViewProj.M11) + (float)(this->invViewProj.M31 * 0.0))
                 + this->invViewProj.M41);
  _Val.y = (float)(1.0 / v11) * v9;
  _Val.z = (float)(1.0 / v11) * v10;
  std::vector<DRSZone>::push_back(corners, &_Val);
  v12 = (float)((float)((float)(this->invViewProj.M12 * -1.0) + this->invViewProj.M22)
              + (float)(this->invViewProj.M32 * 0.0))
      + this->invViewProj.M42;
  v13 = (float)((float)((float)(this->invViewProj.M13 * -1.0) + this->invViewProj.M23)
              + (float)(this->invViewProj.M33 * 0.0))
      + this->invViewProj.M43;
  v14 = (float)((float)((float)(this->invViewProj.M14 * -1.0) + this->invViewProj.M24)
              + (float)(this->invViewProj.M34 * 0.0))
      + this->invViewProj.M44;
  _Val.x = (float)(1.0 / v14)
         * (float)((float)((float)((float)(this->invViewProj.M11 * -1.0) + this->invViewProj.M21)
                         + (float)(this->invViewProj.M31 * 0.0))
                 + this->invViewProj.M41);
  _Val.y = (float)(1.0 / v14) * v12;
  _Val.z = (float)(1.0 / v14) * v13;
  std::vector<DRSZone>::push_back(corners, &_Val);
  v15 = (float)((float)((float)(this->invViewProj.M22 * -1.0) + (float)(this->invViewProj.M12 * -1.0))
              + this->invViewProj.M32)
      + this->invViewProj.M42;
  v16 = (float)((float)((float)(this->invViewProj.M23 * -1.0) + (float)(this->invViewProj.M13 * -1.0))
              + this->invViewProj.M33)
      + this->invViewProj.M43;
  v17 = (float)((float)((float)(this->invViewProj.M24 * -1.0) + (float)(this->invViewProj.M14 * -1.0))
              + this->invViewProj.M34)
      + this->invViewProj.M44;
  _Val.x = (float)(1.0 / v17)
         * (float)((float)((float)((float)(this->invViewProj.M21 * -1.0) + (float)(this->invViewProj.M11 * -1.0))
                         + this->invViewProj.M31)
                 + this->invViewProj.M41);
  _Val.y = (float)(1.0 / v17) * v15;
  _Val.z = (float)(1.0 / v17) * v16;
  std::vector<DRSZone>::push_back(corners, &_Val);
  v18 = (float)((float)((float)(this->invViewProj.M22 * -1.0) + this->invViewProj.M12) + this->invViewProj.M32)
      + this->invViewProj.M42;
  v19 = (float)((float)((float)(this->invViewProj.M23 * -1.0) + this->invViewProj.M13) + this->invViewProj.M33)
      + this->invViewProj.M43;
  v20 = 1.0
      / (float)((float)((float)((float)(this->invViewProj.M24 * -1.0) + this->invViewProj.M14) + this->invViewProj.M34)
              + this->invViewProj.M44);
  _Val.x = v20
         * (float)((float)((float)((float)(this->invViewProj.M21 * -1.0) + this->invViewProj.M11) + this->invViewProj.M31)
                 + this->invViewProj.M41);
  _Val.y = v20 * v18;
  _Val.z = v20 * v19;
  std::vector<DRSZone>::push_back(corners, &_Val);
  v21 = 1.0
      / (float)((float)((float)(this->invViewProj.M24 + this->invViewProj.M14) + this->invViewProj.M34)
              + this->invViewProj.M44);
  v22 = (float)((float)(this->invViewProj.M22 + this->invViewProj.M12) + this->invViewProj.M32) + this->invViewProj.M42;
  v23 = (float)((float)(this->invViewProj.M23 + this->invViewProj.M13) + this->invViewProj.M33) + this->invViewProj.M43;
  _Val.x = v21
         * (float)((float)((float)(this->invViewProj.M21 + this->invViewProj.M11) + this->invViewProj.M31)
                 + this->invViewProj.M41);
  _Val.y = v21 * v22;
  _Val.z = v21 * v23;
  std::vector<DRSZone>::push_back(corners, &_Val);
  v24 = (float)((float)((float)(this->invViewProj.M12 * -1.0) + this->invViewProj.M22) + this->invViewProj.M32)
      + this->invViewProj.M42;
  v25 = (float)((float)((float)(this->invViewProj.M13 * -1.0) + this->invViewProj.M23) + this->invViewProj.M33)
      + this->invViewProj.M43;
  v26 = 1.0
      / (float)((float)((float)((float)(this->invViewProj.M14 * -1.0) + this->invViewProj.M24) + this->invViewProj.M34)
              + this->invViewProj.M44);
  _Val.x = v26
         * (float)((float)((float)(this->invViewProj.M21 + (float)(this->invViewProj.M11 * -1.0)) + this->invViewProj.M31)
                 + this->invViewProj.M41);
  _Val.y = v26 * v24;
  _Val.z = v26 * v25;
  std::vector<DRSZone>::push_back(corners, &_Val);
}
char BoundingFrustum::intersect(BoundingFrustum *this, const sphere *s)
{
  int v2; // edx
  float *i; // ecx

  v2 = 0;
  for ( i = &this->planes[0].normal.y;
        (float)((float)((float)((float)(*(i - 1) * s->center.x) + (float)(s->center.y * *i))
                      + (float)(i[1] * s->center.z))
              + i[2]) <= s->radius;
        i += 4 )
  {
    if ( ++v2 >= 6 )
      return 1;
  }
  return 0;
}
void BoundingFrustum::setMatrix(BoundingFrustum *this, const mat44f *value)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  plane4f *v6; // ecx
  int v7; // edx
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // eax
  __m128 pDeterminant; // [esp+10h] [ebp-60h] BYREF
  float v17; // [esp+2Ch] [ebp-44h]
  mat44f v18; // [esp+30h] [ebp-40h] BYREF

  *(__m128i *)&this->matViewProj.M11 = _mm_loadu_si128((const __m128i *)value);
  *(__m128i *)&this->matViewProj.M21 = _mm_loadu_si128((const __m128i *)&value->M21);
  *(__m128i *)&this->matViewProj.M31 = _mm_loadu_si128((const __m128i *)&value->M31);
  *(__m128i *)&this->matViewProj.M41 = _mm_loadu_si128((const __m128i *)&value->M41);
  mat44f::mat44f(&v18);
  v3 = *(__m128 *)&value->M21;
  v4 = *(__m128 *)&value->M31;
  v5 = *(__m128 *)&value->M41;
  *(__m128 *)&this->invViewProj.M11 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)&value->M11, v3, v4, v5);
  *(__m128 *)&this->invViewProj.M21 = v3;
  *(__m128 *)&this->invViewProj.M31 = v4;
  *(__m128 *)&this->invViewProj.M41 = v5;
  this->planes[2].normal.x = COERCE_FLOAT(LODWORD(value->M14) ^ _xmm) - value->M11;
  this->planes[2].normal.y = COERCE_FLOAT(LODWORD(value->M24) ^ _xmm) - value->M21;
  this->planes[2].normal.z = COERCE_FLOAT(LODWORD(value->M34) ^ _xmm) - value->M31;
  this->planes[2].d = COERCE_FLOAT(LODWORD(value->M44) ^ _xmm) - value->M41;
  this->planes[3].normal.x = value->M11 - value->M14;
  this->planes[3].normal.y = value->M21 - value->M24;
  this->planes[3].normal.z = value->M31 - value->M34;
  this->planes[3].d = value->M41 - value->M44;
  this->planes[4].normal.x = value->M12 - value->M14;
  this->planes[4].normal.y = value->M22 - value->M24;
  this->planes[4].normal.z = value->M32 - value->M34;
  this->planes[4].d = value->M42 - value->M44;
  this->planes[5].normal.x = COERCE_FLOAT(LODWORD(value->M14) ^ _xmm) - value->M12;
  this->planes[5].normal.y = COERCE_FLOAT(LODWORD(value->M24) ^ _xmm) - value->M22;
  this->planes[5].normal.z = COERCE_FLOAT(LODWORD(value->M34) ^ _xmm) - value->M32;
  this->planes[5].d = COERCE_FLOAT(LODWORD(value->M44) ^ _xmm) - value->M42;
  v6 = this->planes;
  v7 = 6;
  LODWORD(this->planes[0].normal.x) = LODWORD(value->M13) ^ _xmm;
  LODWORD(this->planes[0].normal.y) = LODWORD(value->M23) ^ _xmm;
  LODWORD(this->planes[0].normal.z) = LODWORD(value->M33) ^ _xmm;
  LODWORD(this->planes[0].d) = LODWORD(value->M43) ^ _xmm;
  this->planes[1].normal.x = value->M13 - value->M14;
  this->planes[1].normal.y = value->M23 - value->M24;
  this->planes[1].normal.z = value->M33 - value->M34;
  this->planes[1].d = value->M43 - value->M44;
  do
  {
    v8 = (__m128)LODWORD(v6->normal.y);
    v9 = (__m128)LODWORD(v6->normal.x);
    v10 = (__m128)LODWORD(v6->normal.z);
    v11 = v10;
    v12 = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9.m128_f32[0] * v9.m128_f32[0]))
        + (float)(v10.m128_f32[0] * v10.m128_f32[0]);
    if ( v12 == 0.0 || (v13 = fsqrt(v12), v13 == 0.0) )
    {
      v11.m128_f32[0] = 0.0;
      pDeterminant.m128_i32[2] = 0;
      v15 = 0.0;
      *(_QWORD *)&v6->normal.x = _mm_unpacklo_ps(v11, (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
      v6->d = 0.0;
    }
    else
    {
      v9.m128_f32[0] = v9.m128_f32[0] * (float)(1.0 / v13);
      v8.m128_f32[0] = v8.m128_f32[0] * (float)(1.0 / v13);
      v14 = (float)(1.0 / v13) * v6->d;
      v17 = v10.m128_f32[0] * (float)(1.0 / v13);
      v15 = v17;
      *(_QWORD *)&v6->normal.x = _mm_unpacklo_ps(v9, v8).m128_u64[0];
      v6->d = v14;
    }
    v6->normal.z = v15;
    ++v6;
    --v7;
  }
  while ( v7 );
}
