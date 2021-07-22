#include "splinestripbuilder.h
void SplineStripBuilder::SplineStripBuilder(SplineStripBuilder *this, GraphicsManager *graphics)
{
  this->lastPoint.x = 0.0;
  this->lastPoint.y = 0.0;
  this->lastPoint.z = 0.0;
  this->vertices._Myfirst = 0;
  this->vertices._Mylast = 0;
  this->vertices._Myend = 0;
  this->indices._Myfirst = 0;
  this->indices._Mylast = 0;
  this->indices._Myend = 0;
  this->points[0].x = 0.0;
  this->points[0].y = 0.0;
  this->points[0].z = 0.0;
  this->points[1].x = 0.0;
  this->points[1].y = 0.0;
  this->points[1].z = 0.0;
  this->points[2].x = 0.0;
  this->points[2].y = 0.0;
  this->points[2].z = 0.0;
  this->points[3].x = 0.0;
  this->points[3].y = 0.0;
  this->points[3].z = 0.0;
  this->width = 1.0;
  this->textureStep = 0.1;
  *(_WORD *)&this->firstPoint = 0;
  this->currentTexU = 0.0;
}
void SplineStripBuilder::~SplineStripBuilder(SplineStripBuilder *this)
{
  if ( this->indices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->indices);
    operator delete(this->indices._Myfirst);
    this->indices._Myfirst = 0;
    this->indices._Mylast = 0;
    this->indices._Myend = 0;
  }
  if ( this->vertices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->vertices);
    operator delete(this->vertices._Myfirst);
    this->vertices._Myfirst = 0;
    this->vertices._Mylast = 0;
    this->vertices._Myend = 0;
  }
}
void SplineStripBuilder::addPoint(SplineStripBuilder *this, const vec3f *p, const vec3f *normal, const vec3f *color, float alpha)
{
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  vec3f *v13; // ecx
  __m128 v14; // xmm5
  float v15; // xmm1_4
  float v16; // eax
  __m128 v17; // xmm4
  float v18; // xmm0_4
  __m128 v19; // xmm7
  float v20; // xmm6_4
  __int64 v21; // xmm0_8
  float v22; // eax
  __m128 v23; // xmm2
  float v24; // xmm1_4
  unsigned __int64 v25; // xmm7_8
  float v26; // eax
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  float v29; // xmm0_4
  unsigned __int64 v30; // xmm2_8
  vec2f tex; // [esp+14h] [ebp-Ch] BYREF
  float v32; // [esp+1Ch] [ebp-4h]
  float pa; // [esp+24h] [ebp+4h]

  if ( this->hasFirstVertex )
  {
    v7 = p->x - this->lastPoint.x;
    v8 = p->y - this->lastPoint.y;
    v9 = p->z - this->lastPoint.z;
    v10 = (float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9);
    if ( v10 == 0.0 )
      v11 = 0.0;
    else
      v11 = fsqrt(v10);
    pa = (float)(v11 / this->textureStep) + this->currentTexU;
    v12 = fsqrt(v10);
    if ( v12 != 0.0 )
    {
      v7 = (float)(1.0 / v12) * v7;
      v8 = (float)(1.0 / v12) * v8;
      v9 = (float)(1.0 / v12) * v9;
    }
    v13 = this->points;
    v14 = (__m128)LODWORD(normal->z);
    v15 = normal->z * v7;
    v14.m128_f32[0] = (float)(v14.m128_f32[0] * v8) - (float)(normal->y * v9);
    v16 = this->points[2].z;
    v17 = (__m128)LODWORD(normal->x);
    v18 = v17.m128_f32[0] * v8;
    v17.m128_f32[0] = v17.m128_f32[0] * v9;
    v19 = v14;
    v20 = (float)(normal->y * v7) - v18;
    *(_QWORD *)&this->points[0].x = *(_QWORD *)&this->points[2].x;
    v21 = *(_QWORD *)&this->points[3].x;
    v17.m128_f32[0] = v17.m128_f32[0] - v15;
    this->points[0].z = v16;
    v22 = this->points[3].z;
    *(_QWORD *)&this->points[1].x = v21;
    this->points[1].z = v22;
    v23 = v17;
    v23.m128_f32[0] = (float)((float)(v17.m128_f32[0] * this->width) * 0.5) + p->y;
    v19.m128_f32[0] = (float)((float)(v14.m128_f32[0] * this->width) * 0.5) + p->x;
    v24 = (float)((float)(v20 * this->width) * 0.5) + p->z;
    v25 = _mm_unpacklo_ps(v19, v23).m128_u64[0];
    *(_QWORD *)&this->points[2].x = v25;
    v32 = v24;
    v26 = v24;
    this->points[2].z = v24;
    v27 = (__m128)LODWORD(p->x);
    v28 = (__m128)LODWORD(p->y);
    v27.m128_f32[0] = v27.m128_f32[0] - (float)((float)(v14.m128_f32[0] * this->width) * 0.5);
    v28.m128_f32[0] = v28.m128_f32[0] - (float)((float)(v17.m128_f32[0] * this->width) * 0.5);
    v29 = p->z - (float)((float)(v20 * this->width) * 0.5);
    v30 = _mm_unpacklo_ps(v27, v28).m128_u64[0];
    *(_QWORD *)&this->points[3].x = v30;
    v32 = v29;
    this->points[3].z = v29;
    if ( this->firstPoint )
    {
      *(_QWORD *)&v13->x = v25;
      *(_QWORD *)&this->points[1].x = v30;
      this->points[0].z = v26;
      this->points[1].z = v29;
      this->firstPoint = 0;
    }
    tex.y = this->currentTexU;
    tex.x = 0.0;
    SplineStripBuilder::addVertex(this, this->points, color, &tex, alpha);
    tex.y = pa;
    tex.x = 0.0;
    SplineStripBuilder::addVertex(this, &this->points[2], color, &tex, alpha);
    tex.y = this->currentTexU;
    tex.x = 1.0;
    SplineStripBuilder::addVertex(this, &this->points[1], color, &tex, alpha);
    tex.y = this->currentTexU;
    tex.x = 1.0;
    SplineStripBuilder::addVertex(this, &this->points[1], color, &tex, alpha);
    tex.y = pa;
    tex.x = 0.0;
    SplineStripBuilder::addVertex(this, &this->points[2], color, &tex, alpha);
    tex.y = pa;
    tex.x = 1.0;
    SplineStripBuilder::addVertex(this, &this->points[3], color, &tex, alpha);
    this->currentTexU = pa;
  }
  else
  {
    *(_WORD *)&this->firstPoint = 257;
  }
  *(_QWORD *)&this->lastPoint.x = *(_QWORD *)&p->x;
  this->lastPoint.z = p->z;
}
void SplineStripBuilder::addVertex(SplineStripBuilder *this, const vec3f *v1, const vec3f *normal, const vec2f *tex, float alpha)
{
  __int64 v6; // xmm0_8
  __int64 v7; // xmm0_8
  MeshVertex mv; // [esp+8h] [ebp-2Ch] BYREF

  mv.tangent.y = 0.0;
  v6 = *(_QWORD *)&v1->x;
  mv.pos.z = v1->z;
  *(_QWORD *)&mv.pos.x = v6;
  mv.tangent.z = 0.0;
  v7 = *(_QWORD *)&normal->x;
  mv.normal.z = normal->z;
  mv.texCoord = *tex;
  *(_QWORD *)&mv.normal.x = v7;
  mv.tangent.x = alpha;
  std::vector<MeshVertex>::push_back(&this->vertices, &mv);
  v1 = (const vec3f *)(unsigned __int16)(((int)((unsigned __int64)(780903145i64
                                                                 * ((char *)this->vertices._Mylast
                                                                  - (char *)this->vertices._Myfirst)) >> 32) >> 3)
                                       + ((unsigned int)((unsigned __int64)(780903145i64
                                                                          * ((char *)this->vertices._Mylast
                                                                           - (char *)this->vertices._Myfirst)) >> 32) >> 31)
                                       - 1);
  std::vector<unsigned short>::push_back(&this->indices, (const unsigned __int16 *)&v1);
}
Mesh *SplineStripBuilder::buildMesh(SplineStripBuilder *this)
{
  Mesh *v2; // esi
  int v3; // eax
  int v4; // esi
  std::wstring v6; // [esp-18h] [ebp-38h] BYREF
  Mesh *v7; // [esp+Ch] [ebp-14h]
  int v8; // [esp+1Ch] [ebp-4h]

  v2 = (Mesh *)operator new(276);
  v7 = v2;
  v8 = 0;
  if ( v2 )
  {
    v6._Myres = 7;
    v6._Mysize = 0;
    v6._Bx._Buf[0] = 0;
    std::wstring::assign(&v6, L"NONAME", 6u);
    Mesh::Mesh(v2, v6);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  v8 = -1;
  std::vector<MeshVertex>::operator=((std::vector<MeshVertex> *)(v4 + 224), &this->vertices);
  std::vector<unsigned short>::operator=((std::vector<unsigned short> *)(v4 + 236), &this->indices);
  return (Mesh *)v4;
}
