#include "triangle.h
void Triangle::Triangle(Triangle *this)
{
  this->points[0].x = 0.0;
  this->points[0].y = 0.0;
  this->points[0].z = 0.0;
  this->points[1].x = 0.0;
  this->points[1].y = 0.0;
  this->points[1].z = 0.0;
  this->points[2].x = 0.0;
  this->points[2].y = 0.0;
  this->points[2].z = 0.0;
  this->plane.normal.x = 0.0;
  this->plane.normal.y = 0.0;
  this->plane.normal.z = 0.0;
  this->__vftable = (Triangle_vtbl *)&Triangle::`vftable';
  this->plane.d = 0.0;
}
Triangle *Triangle::`vector deleting destructor'(Triangle *this, unsigned int a2)
{
  Triangle::~Triangle(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Triangle::Triangle(Triangle *this, const vec3f *p1, const vec3f *p2, const vec3f *p3)
{
  float v6; // xmm3_4
  float v7; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  __m128 v10; // xmm6
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm7_4
  __m128 v14; // xmm5
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  float v21; // xmm0_4
  float v22; // xmm4_4
  __m128 v23; // xmm3
  float v24; // xmm2_4
  __m128 v25; // xmm0
  float v26; // [esp+10h] [ebp-8h]
  float p1a; // [esp+1Ch] [ebp+4h]
  float p2a; // [esp+20h] [ebp+8h]
  float p3a; // [esp+24h] [ebp+Ch]

  this->__vftable = (Triangle_vtbl *)&Triangle::`vftable';
  this->points[0].x = 0.0;
  this->points[0].y = 0.0;
  this->points[0].z = 0.0;
  this->points[1].x = 0.0;
  this->points[1].y = 0.0;
  this->points[1].z = 0.0;
  this->points[2].x = 0.0;
  this->points[2].y = 0.0;
  this->points[2].z = 0.0;
  this->plane.normal.x = 0.0;
  this->plane.normal.y = 0.0;
  this->plane.normal.z = 0.0;
  this->plane.d = 0.0;
  this->points[0] = *p1;
  this->points[1] = *p2;
  this->points[2] = *p3;
  v10 = (__m128)LODWORD(p1->x);
  v6 = p1->x - p2->x;
  v7 = p1->z;
  v8 = p1->y - p2->y;
  v9 = v7 - p2->z;
  p3a = v6;
  p2a = v8;
  v10.m128_f32[0] = v10.m128_f32[0] - p3->x;
  v11 = p1->y - p3->y;
  p1a = v9;
  v12 = v9 * v9;
  v13 = v7 - p3->z;
  v14 = (__m128)LODWORD(FLOAT_1_0);
  v15 = fsqrt((float)((float)(v8 * v8) + (float)(v6 * v6)) + v12);
  if ( v15 == 0.0 )
  {
    v17 = p1a;
  }
  else
  {
    v16 = (float)(1.0 / v15) * v6;
    v17 = p1a * (float)(1.0 / v15);
    p3a = v16;
    p1a = v17;
    p2a = (float)(1.0 / v15) * v8;
  }
  v18 = fsqrt((float)((float)(v11 * v11) + (float)(v10.m128_f32[0] * v10.m128_f32[0])) + (float)(v13 * v13));
  if ( v18 != 0.0 )
  {
    v19 = (__m128)LODWORD(FLOAT_1_0);
    v19.m128_f32[0] = 1.0 / v18;
    v20 = v19;
    v20.m128_f32[0] = v19.m128_f32[0] * v10.m128_f32[0];
    v10 = v20;
    v11 = v19.m128_f32[0] * v11;
    v13 = v19.m128_f32[0] * v13;
  }
  v21 = v11 * v17;
  v23 = v10;
  v22 = (float)(v13 * p2a) - v21;
  v23.m128_f32[0] = (float)(v10.m128_f32[0] * p1a) - (float)(v13 * p3a);
  v24 = (float)(v11 * p3a) - (float)(v10.m128_f32[0] * p2a);
  v26 = v24;
  v25 = 0i64;
  v25.m128_f32[0] = fsqrt((float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22)) + (float)(v24 * v24));
  if ( v25.m128_f32[0] != 0.0 )
  {
    v14.m128_f32[0] = 1.0 / v25.m128_f32[0];
    v25 = v14;
    v22 = v22 * v14.m128_f32[0];
    v25.m128_f32[0] = v14.m128_f32[0] * v23.m128_f32[0];
    v24 = v14.m128_f32[0] * v24;
    v26 = v24;
    v23 = v25;
  }
  v25.m128_f32[0] = v22;
  *(_QWORD *)&this->plane.normal.x = _mm_unpacklo_ps(v25, v23).m128_u64[0];
  this->plane.normal.z = v26;
  LODWORD(this->plane.d) = COERCE_UNSIGNED_INT((float)((float)(p1->x * v22) + (float)(v23.m128_f32[0] * p1->y)) + (float)(p1->z * v24)) ^ _xmm;
}
void Triangle::~Triangle(Triangle *this)
{
  this->__vftable = (Triangle_vtbl *)&Triangle::`vftable';
}
double Triangle::computeArea(Triangle *this)
{
  float v1; // xmm7_4
  float v2; // xmm1_4
  float v3; // xmm4_4
  float v4; // xmm3_4
  float v5; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  double result; // st7

  v1 = this->points[2].z - this->points[0].z;
  v2 = this->points[2].y - this->points[0].y;
  v3 = this->points[2].y - this->points[1].y;
  v4 = this->points[2].z - this->points[1].z;
  v5 = this->points[2].x - this->points[1].x;
  v6 = this->points[2].x - this->points[0].x;
  v7 = (float)((float)((float)((float)(v1 * v5) - (float)(v6 * v4)) * (float)((float)(v1 * v5) - (float)(v6 * v4)))
             + (float)((float)((float)(v2 * v4) - (float)(v1 * v3)) * (float)((float)(v2 * v4) - (float)(v1 * v3))))
     + (float)((float)((float)(v6 * v3) - (float)(v2 * v5)) * (float)((float)(v6 * v3) - (float)(v2 * v5)));
  if ( v7 == 0.0 )
    result = 0.0 * 0.5;
  else
    result = fsqrt(v7) * 0.5;
  return result;
}
