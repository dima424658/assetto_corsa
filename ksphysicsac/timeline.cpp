#include "timeline.h"
TimeLine *TimeLine::`vector deleting destructor'(TimeLine *this, unsigned int a2)
{
  TimeLine::~TimeLine(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TimeLine::TimeLine(TimeLine *this, const vec3f *p1, const vec3f *p2, int iid, TimeLineType type)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm3_4
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  float v11; // xmm0_4
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm1

  this->type = type;
  this->__vftable = (TimeLine_vtbl *)&TimeLine::`vftable';
  this->points[0].x = 0.0;
  this->points[0].y = 0.0;
  this->points[0].z = 0.0;
  this->points[1].x = 0.0;
  this->points[1].y = 0.0;
  this->points[1].z = 0.0;
  this->planeNormal.x = 0.0;
  this->planeNormal.y = 0.0;
  this->planeNormal.z = 0.0;
  this->points[0] = *p1;
  this->points[1] = *p2;
  this->points[0].y = 0.0;
  this->points[1].y = 0.0;
  this->id = iid;
  v5 = this->points[0].x - this->points[1].x;
  v6 = this->points[0].y - this->points[1].y;
  v7 = this->points[0].z - this->points[1].z;
  this->length = (float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v7 * v7);
  v9 = (__m128)LODWORD(this->points[0].y);
  v8 = this->points[0].x - this->points[1].x;
  v9.m128_f32[0] = v9.m128_f32[0] - this->points[1].y;
  v10 = (__m128)LODWORD(this->points[0].z);
  v10.m128_f32[0] = v10.m128_f32[0] - this->points[1].z;
  v11 = fsqrt(
          (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8))
        + (float)(v10.m128_f32[0] * v10.m128_f32[0]));
  if ( v11 != 0.0 )
  {
    v12 = (__m128)LODWORD(FLOAT_1_0);
    v12.m128_f32[0] = 1.0 / v11;
    v8 = (float)(1.0 / v11) * v8;
    v13 = v12;
    v13.m128_f32[0] = v12.m128_f32[0] * v9.m128_f32[0];
    v12.m128_f32[0] = v12.m128_f32[0] * v10.m128_f32[0];
    v9 = v13;
    v10 = v12;
  }
  v9.m128_f32[0] = v9.m128_f32[0] * 0.0;
  v14 = v9;
  v14.m128_f32[0] = v9.m128_f32[0] - v10.m128_f32[0];
  v10.m128_f32[0] = (float)(v10.m128_f32[0] * 0.0) - (float)(v8 * 0.0);
  *(_QWORD *)&this->planeNormal.x = _mm_unpacklo_ps(v14, v10).m128_u64[0];
  this->planeNormal.z = v8 - v9.m128_f32[0];
}
void TimeLine::~TimeLine(TimeLine *this)
{
  this->__vftable = (TimeLine_vtbl *)&TimeLine::`vftable';
}
int TimeLine::check(TimeLine *this, const vec3f *p)
{
  float v2; // eax
  float v3; // xmm0_4
  int result; // eax

  v2 = p->z;
  v3 = this->length;
  if ( (float)((float)((float)(COERCE_FLOAT(LODWORD(this->points[0].y) ^ _xmm)
                             * COERCE_FLOAT(LODWORD(this->points[0].y) ^ _xmm))
                     + (float)((float)(p->x - this->points[0].x) * (float)(p->x - this->points[0].x)))
             + (float)((float)(v2 - this->points[0].z) * (float)(v2 - this->points[0].z))) > v3
    || (float)((float)((float)(COERCE_FLOAT(LODWORD(this->points[1].y) ^ _xmm)
                             * COERCE_FLOAT(LODWORD(this->points[1].y) ^ _xmm))
                     + (float)((float)(p->x - this->points[1].x) * (float)(p->x - this->points[1].x)))
             + (float)((float)(v2 - this->points[1].z) * (float)(v2 - this->points[1].z))) > v3 )
  {
    result = 0;
  }
  else
  {
    result = ((float)((float)((float)(this->planeNormal.y * COERCE_FLOAT(LODWORD(this->points[0].y) ^ _xmm))
                            + (float)(this->planeNormal.x * (float)(p->x - this->points[0].x)))
                    + (float)(this->planeNormal.z * (float)(p->z - this->points[0].z))) > 0.0)
           + 1;
  }
  return result;
}
