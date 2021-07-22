#include "slipstream.h
double SlipStream::getSlipEffect(SlipStream *this, const vec3f *p)
{
  __m128 v2; // xmm3
  float v3; // xmm5_4
  __m128 v4; // xmm0
  float v5; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  double result; // st7
  unsigned __int64 dt; // [esp+0h] [ebp-18h]
  float dt_8; // [esp+8h] [ebp-10h]

  v2 = (__m128)LODWORD(p->y);
  v3 = p->z;
  v4 = (__m128)LODWORD(v3);
  v5 = (float)((float)((float)(p->y - this->triangle.points[0].y) * (float)(p->y - this->triangle.points[0].y))
             + (float)((float)(p->x - this->triangle.points[0].x) * (float)(p->x - this->triangle.points[0].x)))
     + (float)((float)(v4.m128_f32[0] - this->triangle.points[0].z)
             * (float)(v4.m128_f32[0] - this->triangle.points[0].z));
  if ( v5 == 0.0 )
    v6 = 0.0;
  else
    v6 = fsqrt(v5);
  v7 = this->length;
  if ( v7 <= v6 )
    goto LABEL_10;
  v8 = p->x - this->triangle.points[0].x;
  v2.m128_f32[0] = v2.m128_f32[0] - this->triangle.points[0].y;
  v4.m128_f32[0] = v8;
  dt = _mm_unpacklo_ps(v4, v2).m128_u64[0];
  dt_8 = v3 - this->triangle.points[0].z;
  v9 = fsqrt((float)((float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v8 * v8)) + (float)(dt_8 * dt_8));
  if ( v9 == 0.0 )
  {
    v12 = v3 - this->triangle.points[0].z;
    v11 = *((float *)&dt + 1);
    v13 = *(float *)&dt;
  }
  else
  {
    v10 = 1.0 / v9;
    v11 = (float)(1.0 / v9) * *((float *)&dt + 1);
    v12 = v10 * dt_8;
    v13 = v10 * v8;
  }
  v14 = (float)((float)(this->dir.y * v11) + (float)(this->dir.x * v13)) + (float)(this->dir.z * v12);
  if ( v14 <= 0.69999999 )
LABEL_10:
    result = 0.0;
  else
    result = (float)((float)((float)((float)(1.0 - (float)(v6 / v7)) * (float)(v14 - 0.69999999)) * 3.3333333)
                   * this->effectGainMult);
  return result;
}
void SlipStream::init(SlipStream *this, PhysicsEngine *pe)
{
  PhysicsEngine *v3; // ecx

  v3 = pe;
  pe = (PhysicsEngine *)this;
  this->physicsEngine = v3;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&v3->slipStreams,
    (ICollisionObject *const *)&pe);
  this->length = 0.0;
  this->speedFactor = 0.5;
}
void SlipStream::setPosition(SlipStream *this, const vec3f *pos, const vec3f *vel)
{
  float v5; // xmm5_4
  __m128 v6; // xmm7
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  __m128 v14; // xmm2
  __m128 v15; // xmm5
  float v16; // edx
  __m128 v17; // xmm5
  float v18; // xmm0_4
  float v19; // xmm3_4
  unsigned __int64 v20; // xmm0_8
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  float v25; // eax
  float v26; // eax
  unsigned __int64 v27; // [esp+Ch] [ebp-24h]
  unsigned __int64 v28; // [esp+18h] [ebp-18h]
  float v29; // [esp+20h] [ebp-10h]
  float v30; // [esp+24h] [ebp-Ch]
  float v31; // [esp+28h] [ebp-8h]
  float v32; // [esp+2Ch] [ebp-4h]
  float v33; // [esp+2Ch] [ebp-4h]
  float posa; // [esp+34h] [ebp+4h]
  float vela; // [esp+38h] [ebp+8h]

  this->triangle.points[0] = *pos;
  v5 = vel->z;
  v6 = (__m128)LODWORD(vel->x);
  v31 = 0.0;
  v7 = v5;
  v8 = fsqrt((float)(v5 * v5) + (float)(v6.m128_f32[0] * v6.m128_f32[0]));
  if ( v8 != 0.0 )
  {
    v7 = v5 * (float)(1.0 / v8);
    v6.m128_f32[0] = v6.m128_f32[0] * (float)(1.0 / v8);
    v31 = (float)(1.0 / v8) * 0.0;
  }
  v9 = (float)((float)(vel->y * vel->y) + (float)(vel->x * vel->x)) + (float)(v5 * v5);
  if ( v9 == 0.0 )
    v10 = 0.0;
  else
    v10 = fsqrt(v9);
  v11 = (float)(this->speedFactor * v10) * this->speedFactorMult;
  this->length = v11;
  v29 = v11;
  v32 = (float)(v6.m128_f32[0] - (float)(v31 * 0.0)) * v11;
  v12 = (float)((float)((float)(v7 * 0.0) - (float)(v6.m128_f32[0] * 0.0)) * v11) * 0.25;
  v13 = (float)((float)(v31 * 0.0) - v7) * v11;
  v14 = (__m128)LODWORD(vel->y);
  posa = v12;
  v14.m128_f32[0] = v14.m128_f32[0] * -1.0;
  vela = v13 * 0.25;
  v15 = (__m128)LODWORD(vel->x);
  v15.m128_f32[0] = v15.m128_f32[0] * -1.0;
  v33 = v32 * 0.25;
  v28 = _mm_unpacklo_ps(v15, v14).m128_u64[0];
  v16 = vel->z * -1.0;
  v14.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v15.m128_f32[0] * v15.m128_f32[0]);
  v30 = v15.m128_f32[0];
  v17 = (__m128)LODWORD(v31);
  v18 = fsqrt(v14.m128_f32[0] + (float)(v16 * v16));
  if ( v18 == 0.0 )
  {
    v20 = v28;
  }
  else
  {
    v19 = 1.0 / v18;
    *(float *)&v27 = (float)(1.0 / v18) * v30;
    *((float *)&v27 + 1) = (float)(1.0 / v18) * *((float *)&v28 + 1);
    v20 = v27;
    v16 = v19 * v16;
  }
  v21 = (__m128)LODWORD(v31);
  v22 = _mm_xor_ps((__m128)LODWORD(v29), (__m128)_xmm);
  v23 = v6;
  *(_QWORD *)&this->dir.x = v20;
  this->dir.z = v16;
  v23.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v22.m128_f32[0]) + pos->x) + vela;
  v21.m128_f32[0] = (float)((float)(v31 * v22.m128_f32[0]) + pos->y) + posa;
  v24 = v22;
  v25 = (float)((float)(v7 * v22.m128_f32[0]) + pos->z) + v33;
  *(_QWORD *)&this->triangle.points[1].x = _mm_unpacklo_ps(v23, v21).m128_u64[0];
  this->triangle.points[1].z = v25;
  v24.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v6.m128_f32[0]) + pos->x) - vela;
  v17.m128_f32[0] = (float)((float)(v31 * v22.m128_f32[0]) + pos->y) - posa;
  v26 = (float)((float)(v7 * v22.m128_f32[0]) + pos->z) - v33;
  *(_QWORD *)&this->triangle.points[2].x = _mm_unpacklo_ps(v24, v17).m128_u64[0];
  this->triangle.points[2].z = v26;
}
