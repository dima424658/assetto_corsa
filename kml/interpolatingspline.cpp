#include "interpolatingspline.h"
void InterpolatingSpline::InterpolatingSpline(InterpolatingSpline *this)
{
  Spline::Spline(this);
  this->__vftable = (InterpolatingSpline_vtbl *)&InterpolatingSpline::`vftable';
  this->grid._Myfirst = 0;
  this->grid._Mylast = 0;
  this->grid._Myend = 0;
  this->cubicSpline.__vftable = (CubicSpline<float,vec3f>_vtbl *)&CubicSpline<float,vec3f>::`vftable';
  this->cubicSpline.mElements._Myfirst = 0;
  this->cubicSpline.mElements._Mylast = 0;
  this->cubicSpline.mElements._Myend = 0;
  this->isSplineReady = 0;
  this->interpolationMode = eCatmulRom;
  this->gridData = 0;
}
void InterpolatingSpline::~InterpolatingSpline(InterpolatingSpline *this)
{
  std::vector<GridElement> *v2; // eax

  this->__vftable = (InterpolatingSpline_vtbl *)&InterpolatingSpline::`vftable';
  this->points._Mylast = this->points._Myfirst;
  if ( this->gridData )
  {
    operator delete(this->gridData);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<GridElement>>>>(
      this->grid._Myfirst,
      this->grid._Mylast);
    this->grid._Mylast = this->grid._Myfirst;
  }
  this->cubicSpline.__vftable = (CubicSpline<float,vec3f>_vtbl *)&CubicSpline<float,vec3f>::`vftable';
  if ( this->cubicSpline.mElements._Myfirst )
  {
    operator delete(this->cubicSpline.mElements._Myfirst);
    this->cubicSpline.mElements._Myfirst = 0;
    this->cubicSpline.mElements._Mylast = 0;
    this->cubicSpline.mElements._Myend = 0;
  }
  v2 = this->grid._Myfirst;
  if ( v2 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<GridElement>>>>(v2, this->grid._Mylast);
    operator delete(this->grid._Myfirst);
    this->grid._Myfirst = 0;
    this->grid._Mylast = 0;
    this->grid._Myend = 0;
  }
  Spline::~Spline(this);
}
InterpolatingSpline *InterpolatingSpline::`scalar deleting destructor'(InterpolatingSpline *this, unsigned int a2)
{
  InterpolatingSpline::~InterpolatingSpline(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void InterpolatingSpline::addPoint(InterpolatingSpline *this, const vec3f *p, int tag)
{
  this->isSplineReady = 0;
  Spline::addPoint(this, p, tag);
}
void InterpolatingSpline::addSplinePoint(InterpolatingSpline *this, const SplinePoint *p)
{
  this->isSplineReady = 0;
  Spline::addSplinePoint(this, p);
}
void InterpolatingSpline::bezierEndopoint(InterpolatingSpline *this)
{
  __int64 v2; // rax
  int i; // esi
  int v4; // edx
  float t; // xmm0_4
  __int64 v6; // rax
  int j; // ebp
  SplinePoint *v8; // esi
  float v9; // xmm0_4
  float v10; // [esp+1Ch] [ebp-5Ch]
  vec3f result; // [esp+20h] [ebp-58h] BYREF
  InterpolatingSpline support; // [esp+2Ch] [ebp-4Ch] BYREF
  int v13; // [esp+74h] [ebp-4h]

  if ( (unsigned int)(this->points._Mylast - this->points._Myfirst) >= 0x32 )
  {
    InterpolatingSpline::InterpolatingSpline(&support);
    v2 = 1717986919i64 * ((char *)this->points._Mylast - (char *)this->points._Myfirst);
    v13 = 0;
    for ( i = (SHIDWORD(v2) >> 3) + (HIDWORD(v2) >> 31) - 25; i != 25; ++i )
    {
      v4 = (unsigned __int64)(1717986919i64 * ((char *)this->points._Mylast - (char *)this->points._Myfirst)) >> 32;
      support.isSplineReady = 0;
      if ( i == (v4 >> 3) + ((unsigned int)v4 >> 31) )
        i = 0;
      Spline::addPoint(&support, &this->points._Myfirst[i].point, 0);
    }
    t = 0.0;
    v6 = 1717986919i64 * ((char *)this->points._Mylast - (char *)this->points._Myfirst);
    v10 = 0.0;
    for ( j = (SHIDWORD(v6) >> 3) + (HIDWORD(v6) >> 31) - 25; j != 25; v10 = t )
    {
      v8 = this->points._Myfirst;
      if ( j == this->points._Mylast - v8 )
        j = 0;
      v8[j++].point = *InterpolatingSpline::calculateNthBezier(&support, &result, t);
      v9 = (float)(unsigned int)Spline::pointsCount(&support);
      t = (float)(1.0 / v9) + v10;
    }
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<GridElement>>>>(
      support.grid._Myfirst,
      support.grid._Mylast);
    support.grid._Mylast = support.grid._Myfirst;
    Spline::clear(&support);
    InterpolatingSpline::computeSplineLength(this);
    v13 = -1;
    InterpolatingSpline::~InterpolatingSpline(&support);
  }
}
void InterpolatingSpline::buildGrid(InterpolatingSpline *this)
{
  GridData *v2; // eax
  GridData *v3; // eax
  std::vector<std::vector<GridElement>> *v4; // edi
  unsigned int v5; // ebx
  int v6; // esi
  GridData *v7; // ecx
  float v8; // xmm1_4
  GridData *v9; // ecx
  float v10; // xmm1_4
  GridData *v11; // ecx
  float v12; // xmm0_4
  GridData *v13; // ecx
  float v14; // xmm0_4
  GridData *v15; // esi
  int v16; // esi
  GridElement *v17; // ebx
  GridElement *v18; // edi
  GridElement *i; // esi
  unsigned int v20; // ebx
  std::vector<GridElement> *v21; // ecx
  GridData *v22; // ecx
  float v23; // xmm3_4
  float v24; // xmm2_4
  double v25; // xmm0_8
  std::vector<unsigned int> *v26; // edi
  GridElement *v27; // esi
  int v28; // [esp+18h] [ebp-58h]
  int v29; // [esp+1Ch] [ebp-54h]
  unsigned int v30; // [esp+20h] [ebp-50h]
  float v31; // [esp+24h] [ebp-4Ch]
  unsigned int v32; // [esp+24h] [ebp-4Ch]
  unsigned int v33; // [esp+28h] [ebp-48h]
  std::vector<GridElement> _Val; // [esp+34h] [ebp-3Ch] BYREF
  GridElement v35; // [esp+40h] [ebp-30h] BYREF
  std::vector<unsigned int> result; // [esp+4Ch] [ebp-24h] BYREF
  vec3f coords; // [esp+58h] [ebp-18h] BYREF
  int v38; // [esp+6Ch] [ebp-4h]

  if ( this->gridData )
  {
    operator delete(this->gridData);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<GridElement>>>>(
      this->grid._Myfirst,
      this->grid._Mylast);
    this->grid._Mylast = this->grid._Myfirst;
  }
  v2 = (GridData *)operator new(32);
  if ( v2 )
    GridData::GridData(v2);
  else
    v3 = 0;
  this->gridData = v3;
  v4 = &this->grid;
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<GridElement>>>>(
    this->grid._Myfirst,
    this->grid._Mylast);
  this->grid._Mylast = this->grid._Myfirst;
  _printf("BUILDING GRID FOR PERFORMANCE\n");
  v5 = 0;
  if ( this->points._Mylast - this->points._Myfirst )
  {
    v6 = 0;
    do
    {
      v7 = this->gridData;
      v8 = this->points._Myfirst[v6].point.x;
      if ( v7->minExtreme.x > v8 )
        v7->minExtreme.x = v8;
      v9 = this->gridData;
      v10 = this->points._Myfirst[v6].point.z;
      if ( v9->minExtreme.z > v10 )
        v9->minExtreme.z = v10;
      v11 = this->gridData;
      v12 = this->points._Myfirst[v6].point.x;
      if ( v12 > v11->maxExtreme.x )
        v11->maxExtreme.x = v12;
      v13 = this->gridData;
      v14 = this->points._Myfirst[v6].point.z;
      if ( v14 > v13->maxExtreme.z )
        v13->maxExtreme.z = v14;
      ++v5;
      ++v6;
    }
    while ( v5 < this->points._Mylast - this->points._Myfirst );
  }
  this->gridData->minExtreme.x = this->gridData->minExtreme.x - 350.0;
  this->gridData->minExtreme.z = this->gridData->minExtreme.z - 350.0;
  this->gridData->maxExtreme.x = this->gridData->maxExtreme.x + 350.0;
  this->gridData->maxExtreme.z = this->gridData->maxExtreme.z + 350.0;
  v15 = this->gridData;
  v31 = 1.0 / v15->samplingDensity;
  v33 = (unsigned int)(float)((float)(v15->maxExtreme.x - v15->minExtreme.x) * v31);
  v32 = (unsigned int)(float)((float)(v15->maxExtreme.z - v15->minExtreme.z) * v31);
  v30 = 0;
  if ( v33 )
  {
    v16 = 0;
    v28 = 0;
    do
    {
      _Val._Myfirst = 0;
      _Val._Mylast = 0;
      _Val._Myend = 0;
      v38 = 0;
      std::vector<std::vector<GridElement>>::push_back(v4, &_Val);
      v17 = _Val._Myfirst;
      v38 = -1;
      if ( _Val._Myfirst )
      {
        v18 = _Val._Mylast;
        for ( i = _Val._Myfirst; i != v18; ++i )
        {
          if ( i->closestIndices._Myfirst )
          {
            operator delete(i->closestIndices._Myfirst);
            i->closestIndices._Myfirst = 0;
            i->closestIndices._Mylast = 0;
            i->closestIndices._Myend = 0;
          }
        }
        operator delete(v17);
        v16 = v28;
        v4 = &this->grid;
        _Val._Myfirst = 0;
        _Val._Mylast = 0;
        _Val._Myend = 0;
      }
      v20 = 0;
      if ( v32 )
      {
        v29 = 0;
        do
        {
          v35.closestIndices._Myfirst = 0;
          v35.closestIndices._Mylast = 0;
          v35.closestIndices._Myend = 0;
          v21 = (std::vector<GridElement> *)((char *)v4->_Myfirst + v16);
          v38 = 1;
          std::vector<GridElement>::push_back(v21, &v35);
          v38 = -1;
          if ( v35.closestIndices._Myfirst )
          {
            operator delete(v35.closestIndices._Myfirst);
            v35.closestIndices._Myfirst = 0;
            v35.closestIndices._Mylast = 0;
            v35.closestIndices._Myend = 0;
          }
          v22 = this->gridData;
          v23 = v22->samplingDensity;
          v24 = v23 * ((double)v30 + 0.5) + v22->minExtreme.x;
          v25 = v22->minExtreme.z;
          coords.y = 0.0;
          coords.x = v24;
          coords.z = ((double)v20 + 0.5) * v23 + v25;
          v26 = Spline::closestPointIndicesFlat(this, &result, &coords, v22->neighborsConsideredNumber, 0);
          v27 = &(*(GridElement **)((char *)&this->grid._Myfirst->_Myfirst + v16))[v29];
          if ( v27 != (GridElement *)v26 )
          {
            if ( v27->closestIndices._Myfirst )
            {
              operator delete(v27->closestIndices._Myfirst);
              v27->closestIndices._Myfirst = 0;
              v27->closestIndices._Mylast = 0;
              v27->closestIndices._Myend = 0;
            }
            v27->closestIndices._Myfirst = v26->_Myfirst;
            v27->closestIndices._Mylast = v26->_Mylast;
            v27->closestIndices._Myend = v26->_Myend;
            v26->_Myfirst = 0;
            v26->_Mylast = 0;
            v26->_Myend = 0;
          }
          v38 = -1;
          if ( result._Myfirst )
          {
            operator delete(result._Myfirst);
            result._Myfirst = 0;
            result._Mylast = 0;
            result._Myend = 0;
          }
          ++v29;
          v4 = &this->grid;
          v16 = v28;
          ++v20;
        }
        while ( v20 < v32 );
      }
      v4 = &this->grid;
      v16 += 12;
      ++v30;
      v28 = v16;
    }
    while ( v30 < v33 );
  }
}
vec3f *InterpolatingSpline::calculateCatmullRom(InterpolatingSpline *this, vec3f *result, const float t)
{
  float v4; // eax
  vec3f *v5; // eax
  unsigned int v6; // ebp
  int v7; // esi
  int v8; // edi
  SplinePoint *v9; // esi
  float v10; // xmm4_4
  SplinePoint *v11; // esi
  double v12; // st7
  float v13; // xmm3_4
  float v14; // xmm0_4
  unsigned int v15; // eax
  float v16; // xmm1_4
  float v17; // xmm5_4
  float i; // xmm2_4
  float v19; // xmm4_4
  unsigned int v20; // eax
  float v21; // xmm2_4
  SplinePoint *v22; // ecx
  float v23; // xmm1_4
  float v24; // xmm2_4
  __int64 v25; // xmm0_8
  unsigned int v26; // eax
  float v27; // xmm7_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm4_4
  unsigned int v31; // eax
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  unsigned int v35; // eax
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  float v41; // xmm4_4
  unsigned int v42; // eax
  float v43; // xmm2_4
  unsigned int v44; // eax
  float v45; // xmm1_4
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm7_4
  float v49; // xmm1_4
  float v50; // xmm4_4
  float v51; // xmm1_4
  unsigned int v52; // eax
  float v53; // xmm3_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  float v58; // xmm0_4
  SplinePoint *v59; // ecx
  __int64 v60; // xmm0_8
  float v61; // ecx
  float d1; // [esp+18h] [ebp-28h]
  float d1b; // [esp+18h] [ebp-28h]
  float d1a; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  float v66; // [esp+1Ch] [ebp-24h]
  float d2a; // [esp+20h] [ebp-20h]
  float d2b; // [esp+20h] [ebp-20h]
  float d2; // [esp+20h] [ebp-20h]
  int v70; // [esp+24h] [ebp-1Ch]
  float v71; // [esp+24h] [ebp-1Ch]
  int v72; // [esp+28h] [ebp-18h]
  float v73; // [esp+2Ch] [ebp-14h]
  float b; // [esp+30h] [ebp-10h] BYREF
  vec3f resulta; // [esp+34h] [ebp-Ch] BYREF

  resulta.x = 0.0;
  resulta.y = 0.0;
  resulta.z = 0.0;
  if ( (unsigned int)(this->points._Mylast - this->points._Myfirst) >= 4 )
  {
    v6 = InterpolatingSpline::getLastIndexFromNorm(this, t, &b);
    v72 = Spline::wrapIndex(this, v6 - 1);
    v7 = Spline::wrapIndex(this, v6 + 1);
    v65 = v7;
    v70 = Spline::wrapIndex(this, v6 + 2);
    if ( this->points._Myfirst == this->points._Mylast || (d1b = Spline::length(this), d1b == 0.0) )
    {
      d1 = 0.0;
    }
    else
    {
      v11 = this->points._Myfirst;
      v12 = v11[v6].pointLength / Spline::length(this);
      v7 = v65;
      d1 = v12;
    }
    if ( this->points._Myfirst == this->points._Mylast || (d2a = Spline::length(this), d2a == 0.0) )
    {
      v10 = 0.0;
    }
    else
    {
      v8 = v7;
      v9 = this->points._Myfirst;
      d2b = v9[v8].pointLength / Spline::length(this);
      v10 = d2b;
    }
    v13 = FLOAT_1_0;
    v14 = v10 - d1;
    if ( (float)(v10 - d1) < 0.0 )
      v14 = (float)(v10 + 1.0) - d1;
    if ( v14 <= 0.0 )
    {
      v59 = this->points._Myfirst;
      v5 = result;
      v60 = *(_QWORD *)&v59[this->points._Mylast - v59 - 1].point.x;
      v61 = v59[this->points._Mylast - v59 - 1].point.z;
      *(_QWORD *)&result->x = v60;
      result->z = v61;
    }
    else
    {
      v15 = 3;
      v16 = FLOAT_1_0;
      v17 = (float)(t - d1) / v14;
      for ( i = v17; ; i = i * i )
      {
        if ( (v15 & 1) != 0 )
          v16 = v16 * i;
        v15 >>= 1;
        if ( !v15 )
          break;
      }
      v19 = (float)(t - d1) / v14;
      v20 = 2;
      v21 = FLOAT_1_0;
      while ( 1 )
      {
        if ( (v20 & 1) != 0 )
          v21 = v21 * v19;
        v20 >>= 1;
        if ( !v20 )
          break;
        v19 = v19 * v19;
      }
      v22 = this->points._Myfirst;
      v23 = v16 - v21;
      v24 = FLOAT_1_0;
      v25 = LODWORD(v22[v70].point.x);
      v26 = 3;
      *(float *)&v25 = (float)(*(float *)&v25 * 0.5) * v23;
      v27 = (float)(v22[v70].point.y * 0.5) * v23;
      v28 = (float)(v22[v70].point.z * 0.5) * v23;
      v29 = v17;
      *(_QWORD *)&resulta.x = v25;
      v73 = v27;
      b = v28;
      while ( 1 )
      {
        if ( (v26 & 1) != 0 )
          v24 = v24 * v29;
        v26 >>= 1;
        if ( !v26 )
          break;
        v29 = v29 * v29;
      }
      v30 = v17;
      v31 = 2;
      v32 = FLOAT_1_0;
      while ( 1 )
      {
        if ( (v31 & 1) != 0 )
          v32 = v32 * v30;
        v31 >>= 1;
        if ( !v31 )
          break;
        v30 = v30 * v30;
      }
      v33 = (float)(v32 * 4.0) - (float)(v24 * 3.0);
      v34 = v17;
      v35 = 3;
      v36 = v33 + v17;
      v37 = (float)(v22[v65].point.x * 0.5) * v36;
      v38 = (float)(v22[v65].point.y * 0.5) * v36;
      v39 = (float)(v22[v65].point.z * 0.5) * v36;
      v40 = FLOAT_1_0;
      d2 = v37;
      v66 = v38;
      d1a = v39;
      while ( 1 )
      {
        if ( (v35 & 1) != 0 )
          v40 = v40 * v34;
        v35 >>= 1;
        if ( !v35 )
          break;
        v34 = v34 * v34;
      }
      v41 = v17;
      v42 = 2;
      v43 = FLOAT_1_0;
      while ( 1 )
      {
        if ( (v42 & 1) != 0 )
          v43 = v43 * v41;
        v42 >>= 1;
        if ( !v42 )
          break;
        v41 = v41 * v41;
      }
      v44 = 3;
      v45 = (float)((float)(v40 * 3.0) - (float)(v43 * 5.0)) + 2.0;
      v46 = (float)(v22[v6].point.z * 0.5) * v45;
      v47 = (float)(v22[v6].point.y * 0.5) * v45;
      v48 = (float)(v22[v6].point.x * 0.5) * v45;
      v49 = v17;
      v71 = v46;
      v50 = FLOAT_1_0;
      while ( 1 )
      {
        if ( (v44 & 1) != 0 )
          v50 = v50 * v49;
        v44 >>= 1;
        if ( !v44 )
          break;
        v49 = v49 * v49;
      }
      v51 = v17;
      v52 = 2;
      while ( 1 )
      {
        if ( (v52 & 1) != 0 )
          v13 = v13 * v51;
        v52 >>= 1;
        if ( !v52 )
          break;
        v51 = v51 * v51;
      }
      v53 = (float)((float)(v13 * 2.0) - v50) - v17;
      v54 = v66 + (float)((float)((float)(v22[v72].point.y * 0.5) * v53) + v47);
      v55 = d1a + (float)((float)((float)(v22[v72].point.z * 0.5) * v53) + v71);
      v56 = (__m128)_mm_loadl_epi64((const __m128i *)&resulta);
      v56.m128_f32[0] = v56.m128_f32[0] + (float)(d2 + (float)((float)((float)(v22[v72].point.x * 0.5) * v53) + v48));
      v57 = (__m128)LODWORD(v73);
      v57.m128_f32[0] = v73 + v54;
      v58 = b + v55;
      *(_QWORD *)&result->x = _mm_unpacklo_ps(v56, v57).m128_u64[0];
      resulta.z = v58;
      result->z = v58;
      v5 = result;
    }
  }
  else
  {
    v4 = resulta.z;
    *(_QWORD *)&result->x = *(_QWORD *)&resulta.x;
    result->z = v4;
    v5 = result;
  }
  return v5;
}
vec3f *InterpolatingSpline::calculateCubicBezier(InterpolatingSpline *this, vec3f *result, const float t)
{
  unsigned int v4; // edi
  int v5; // edx
  float *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  float *v10; // ecx
  int v11; // edx
  float *v12; // ecx
  SplinePoint *v13; // eax
  float v14; // esi
  int v15; // edi
  SplinePoint *v16; // esi
  float v17; // xmm3_4
  SplinePoint *v18; // esi
  double v19; // st7
  float v20; // xmm1_4
  signed int v21; // esi
  int v22; // edi
  double v23; // st7
  float v24; // xmm2_4
  unsigned int v25; // eax
  float v26; // xmm1_4
  float v27; // xmm3_4
  __int128 v28; // xmm2
  unsigned int v29; // eax
  float v30; // xmm1_4
  __int128 v31; // xmm0
  float v32; // xmm0_4
  int v33; // eax
  float v34; // xmm3_4
  float bin; // [esp+18h] [ebp-20h] BYREF
  unsigned int v37; // [esp+1Ch] [ebp-1Ch] BYREF
  float d2; // [esp+20h] [ebp-18h] BYREF
  int indices[4]; // [esp+24h] [ebp-14h]

  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  if ( (unsigned int)(this->points._Mylast - this->points._Myfirst) >= 4 )
  {
    v4 = 4 * (unsigned int)(float)((float)(int)InterpolatingSpline::getLastIndexFromNorm(this, t, &d2) * 0.25);
    v5 = (unsigned __int64)(1717986919i64 * ((char *)this->points._Mylast - (char *)this->points._Myfirst)) >> 32;
    indices[0] = v4;
    v6 = (float *)&v37;
    v37 = v4 + 1;
    LODWORD(bin) = (v5 >> 3) - 1 + ((unsigned int)v5 >> 31);
    if ( v4 + 1 >= LODWORD(bin) )
      v6 = &bin;
    v7 = *(_DWORD *)v6;
    v8 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
    indices[1] = v7;
    v9 = (unsigned __int64)(1717986919i64 * v8) >> 32;
    v10 = &bin;
    LODWORD(bin) = v4 + 2;
    v37 = (v9 >> 3) - 1 + ((unsigned int)v9 >> 31);
    if ( v4 + 2 >= v37 )
      v10 = (float *)&v37;
    indices[2] = *(int *)v10;
    v11 = (unsigned __int64)(1717986919i64 * ((char *)this->points._Mylast - (char *)this->points._Myfirst)) >> 32;
    v12 = &bin;
    LODWORD(bin) = v4 + 3;
    v37 = (v11 >> 3) - 1 + ((unsigned int)v11 >> 31);
    v13 = this->points._Myfirst;
    if ( v4 + 3 >= v37 )
      v12 = (float *)&v37;
    v14 = *v12;
    d2 = v14;
    *(float *)&indices[3] = v14;
    if ( v13 == this->points._Mylast || (bin = Spline::length(this), bin == 0.0) )
    {
      *(float *)&v37 = 0.0;
    }
    else
    {
      v18 = this->points._Myfirst;
      v19 = v18[v4].pointLength / Spline::length(this);
      v14 = d2;
      bin = v19;
      *(float *)&v37 = bin;
    }
    if ( this->points._Myfirst == this->points._Mylast || (d2 = Spline::length(this), d2 == 0.0) )
    {
      v17 = 0.0;
    }
    else
    {
      v15 = LODWORD(v14);
      v16 = this->points._Myfirst;
      d2 = v16[v15].pointLength / Spline::length(this);
      v17 = d2;
    }
    v20 = v17 - *(float *)&v37;
    if ( (float)(v17 - *(float *)&v37) < 0.0 )
      v20 = (float)(v17 + 1.0) - *(float *)&v37;
    if ( v20 > 0.0 )
    {
      v21 = 0;
      d2 = 1.0 - t;
      v22 = 3;
      do
      {
        v23 = BinomialCoefficient_DoublePrecision(3u, v21);
        v24 = d2;
        v25 = v22;
        bin = v23;
        v26 = FLOAT_1_0;
        while ( 1 )
        {
          if ( (v25 & 1) != 0 )
            v26 = v26 * v24;
          v25 >>= 1;
          if ( !v25 )
            break;
          v24 = v24 * v24;
        }
        v27 = v26;
        v28 = LODWORD(t);
        v29 = v21;
        if ( v21 < 0 )
          v29 = -v21;
        v30 = FLOAT_1_0;
        while ( 1 )
        {
          if ( (v29 & 1) != 0 )
            v30 = v30 * *(float *)&v28;
          v29 >>= 1;
          if ( !v29 )
            break;
          v31 = v28;
          *(float *)&v31 = *(float *)&v28 * *(float *)&v28;
          v28 = v31;
        }
        if ( v21 >= 0 )
          v32 = v30;
        else
          v32 = 1.0 / v30;
        v33 = indices[v21++];
        --v22;
        v34 = (float)(v27 * bin) * v32;
        result->x = (float)(this->points._Myfirst[v33].point.x * v34) + result->x;
        result->y = (float)(this->points._Myfirst[v33].point.y * v34) + result->y;
        result->z = (float)(this->points._Myfirst[v33].point.z * v34) + result->z;
      }
      while ( v22 >= 0 );
    }
  }
  return result;
}
vec3f *__userpurge InterpolatingSpline::calculateCubicSpline@<eax>(InterpolatingSpline *this@<ecx>, __m128 a2@<xmm0>, vec3f *result, const float pos)
{
  if ( !this->isSplineReady )
    InterpolatingSpline::computeSplineCoefficients(this, a2);
  CubicSpline<float,vec3f>::valueAt(&this->cubicSpline, result, &pos);
  return result;
}
vec3f *InterpolatingSpline::calculateLinear(InterpolatingSpline *this, vec3f *result, const float pos)
{
  unsigned int v4; // ebp
  int v5; // esi
  float v6; // xmm1_4
  SplinePoint *v7; // esi
  double v8; // st7
  int v9; // edi
  SplinePoint *v10; // esi
  SplinePoint *v11; // edx
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  vec3f *v15; // eax
  float v16; // xmm2_4
  float d1; // [esp+18h] [ebp-Ch]
  float d1a; // [esp+18h] [ebp-Ch]
  int v19; // [esp+1Ch] [ebp-8h]
  float d2; // [esp+20h] [ebp-4h] BYREF

  v4 = InterpolatingSpline::getLastIndexFromNorm(this, pos, &d2);
  v5 = Spline::wrapIndex(this, v4 + 1);
  v19 = v5;
  if ( this->points._Myfirst == this->points._Mylast || (d1a = Spline::length(this), d1a == 0.0) )
  {
    d1 = 0.0;
  }
  else
  {
    v7 = this->points._Myfirst;
    v8 = v7[v4].pointLength / Spline::length(this);
    v5 = v19;
    d1 = v8;
  }
  if ( this->points._Myfirst == this->points._Mylast )
  {
    v6 = 0.0;
  }
  else
  {
    d2 = Spline::length(this);
    v6 = 0.0;
    if ( d2 != 0.0 )
    {
      v9 = v5;
      v10 = this->points._Myfirst;
      d2 = v10[v9].pointLength / Spline::length(this);
      v6 = d2;
    }
  }
  v11 = this->points._Myfirst;
  v12 = (float)(pos - d1) / (float)(v6 - d1);
  v13 = v11[v4].point.z;
  v14 = v11[v19].point.z;
  v15 = result;
  v16 = (float)((float)(v11[v19].point.y - v11[v4].point.y) * v12) + v11[v4].point.y;
  result->x = (float)((float)(v11[v19].point.x - v11[v4].point.x) * v12) + v11[v4].point.x;
  result->y = v16;
  result->z = (float)((float)(v14 - v13) * v12) + v13;
  return v15;
}
vec3f *InterpolatingSpline::calculateNthBezier(InterpolatingSpline *this, vec3f *result, const float t)
{
  unsigned int v5; // ebx
  int v6; // ecx
  double v7; // xmm3_8
  double v8; // xmm4_8
  int v9; // ebp
  int v10; // ecx
  double v11; // xmm1_8
  double v12; // xmm7_8
  double v13; // xmm5_8
  double v14; // xmm2_8
  double v15; // xmm6_8
  double v16; // xmm2_8
  double v17; // xmm1_8
  double v18; // xmm2_8
  double v19; // xmm0_8
  SplinePoint *v20; // eax
  double v21; // xmm1_8
  int v22; // ecx
  float v23; // xmm2_4
  double v24; // xmm0_8
  float v25; // xmm5_4
  float v27; // [esp+Ch] [ebp-18h]
  double v28; // [esp+14h] [ebp-10h]
  double v29; // [esp+14h] [ebp-10h]
  float resulta; // [esp+28h] [ebp+4h]

  v5 = 0;
  v27 = 0.0;
  v6 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  if ( v6 / 20 )
  {
    v7 = DOUBLE_1_0;
    v8 = DOUBLE_2_0;
    resulta = 0.0;
    v9 = 0;
    do
    {
      v10 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
      v11 = (double)(((int)((unsigned __int64)(1717986919i64 * v10) >> 32) >> 3)
                   + ((unsigned int)((unsigned __int64)(1717986919i64 * v10) >> 32) >> 31)
                   - 1);
      v28 = v11;
      v12 = (double)v5;
      if ( (double)v5 != v7 )
      {
        if ( v11 == 0.0 )
        {
          v13 = v7;
        }
        else if ( v11 == v7 )
        {
          v13 = v7;
        }
        else if ( v11 == v8 )
        {
          v13 = v8;
        }
        else
        {
          v13 = (double)(((int)((unsigned __int64)(1717986919i64 * v10) >> 32) >> 3)
                       + ((unsigned int)((unsigned __int64)(1717986919i64 * v10) >> 32) >> 31)
                       - 1);
          v14 = v13;
          do
          {
            v14 = v14 - v7;
            v13 = v13 * v14;
          }
          while ( v14 > v8 );
        }
        if ( v12 == 0.0 )
        {
          v15 = v7;
        }
        else if ( v12 == v8 )
        {
          v15 = v8;
        }
        else
        {
          v15 = (double)v5;
          v16 = (double)v5;
          do
          {
            v16 = v16 - v7;
            v15 = v15 * v16;
          }
          while ( v16 > v8 );
        }
        v17 = v11 - v12;
        if ( v17 == 0.0 )
        {
          v17 = v7;
        }
        else if ( v17 == v7 )
        {
          v17 = v7;
        }
        else if ( v17 == v8 )
        {
          v17 = v8;
        }
        else
        {
          v18 = v17;
          do
          {
            v18 = v18 - v7;
            v17 = v17 * v18;
          }
          while ( v18 > v8 );
        }
        v28 = v13 / (v17 * v15);
      }
      v29 = *(double *)__libm_sse2_pow().m128_u64 * v28;
      v19 = *(double *)__libm_sse2_pow().m128_u64;
      v20 = this->points._Myfirst;
      ++v5;
      v21 = v29 * v19;
      v22 = (char *)this->points._Mylast - (char *)v20;
      v7 = DOUBLE_1_0;
      v8 = DOUBLE_2_0;
      *(float *)&v19 = v20[v9].point.x * (v29 * v19);
      result->x = *(float *)&v19 + result->x;
      *(float *)&v19 = v20[v9].point.y * v21;
      v23 = *(float *)&v19 + v27;
      v24 = v20[v9++].point.z;
      v27 = v23;
      *(float *)&v24 = v24 * v21;
      v25 = *(float *)&v24 + resulta;
      resulta = *(float *)&v24 + resulta;
    }
    while ( v5 < v22 / 20 );
    result->y = v23;
    result->z = v25;
  }
  return result;
}
vec3f *InterpolatingSpline::calculateUniformBSpline(InterpolatingSpline *this, vec3f *result, const float t)
{
  __int64 v4; // rax
  unsigned int v6; // ebp
  int v7; // esi
  int v8; // edi
  SplinePoint *v9; // esi
  float v10; // xmm2_4
  SplinePoint *v11; // esi
  double v12; // st7
  float v13; // xmm0_4
  unsigned int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float i; // xmm3_4
  SplinePoint *v18; // ecx
  unsigned int v19; // eax
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  unsigned int v26; // eax
  float v27; // xmm1_4
  __int64 v28; // xmm0_8
  float v29; // xmm1_4
  float v30; // xmm3_4
  unsigned int v31; // eax
  float v32; // xmm1_4
  float v33; // xmm7_4
  float v34; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm4_4
  unsigned int v37; // eax
  float v38; // xmm3_4
  unsigned int v39; // eax
  float v40; // xmm1_4
  float v41; // xmm4_4
  float v42; // xmm0_4
  float v43; // xmm7_4
  float v44; // xmm1_4
  float v45; // xmm4_4
  unsigned int v46; // eax
  float v47; // xmm3_4
  float v48; // xmm3_4
  __m128 v49; // xmm4
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  __m128 v54; // xmm3
  float v55; // xmm0_4
  float d1; // [esp+18h] [ebp-2Ch]
  float d1b; // [esp+18h] [ebp-2Ch]
  float d1a; // [esp+18h] [ebp-2Ch]
  int v59; // [esp+1Ch] [ebp-28h]
  float v60; // [esp+1Ch] [ebp-28h]
  float d2a; // [esp+20h] [ebp-24h]
  float d2b; // [esp+20h] [ebp-24h]
  float d2; // [esp+20h] [ebp-24h]
  int v64; // [esp+24h] [ebp-20h]
  float v65; // [esp+24h] [ebp-20h]
  int v66; // [esp+28h] [ebp-1Ch]
  float v67; // [esp+2Ch] [ebp-18h]
  float v68; // [esp+30h] [ebp-14h]
  float b; // [esp+34h] [ebp-10h] BYREF
  _BYTE v70[12]; // [esp+38h] [ebp-Ch] BYREF
  float ta; // [esp+4Ch] [ebp+8h]

  v4 = 1717986919i64 * ((char *)this->points._Mylast - (char *)this->points._Myfirst);
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  if ( (unsigned int)((SHIDWORD(v4) >> 3) + (HIDWORD(v4) >> 31)) < 4 )
    return result;
  v6 = InterpolatingSpline::getLastIndexFromNorm(this, t, &b);
  v66 = Spline::wrapIndex(this, v6 - 1);
  v7 = Spline::wrapIndex(this, v6 + 1);
  v59 = v7;
  v64 = Spline::wrapIndex(this, v6 + 2);
  if ( this->points._Myfirst == this->points._Mylast || (d1b = Spline::length(this), d1b == 0.0) )
  {
    d1 = 0.0;
  }
  else
  {
    v11 = this->points._Myfirst;
    v12 = v11[v6].pointLength / Spline::length(this);
    v7 = v59;
    d1 = v12;
  }
  if ( this->points._Myfirst == this->points._Mylast || (d2a = Spline::length(this), d2a == 0.0) )
  {
    v10 = 0.0;
  }
  else
  {
    v8 = v7;
    v9 = this->points._Myfirst;
    d2b = v9[v8].pointLength / Spline::length(this);
    v10 = d2b;
  }
  v13 = v10 - d1;
  if ( (float)(v10 - d1) < 0.0 )
    v13 = (float)(v10 + 1.0) - d1;
  if ( v13 <= 0.0 )
    return result;
  v14 = 3;
  v15 = FLOAT_1_0;
  v16 = (float)(t - d1) / v13;
  for ( i = v16; ; i = i * i )
  {
    if ( (v14 & 1) != 0 )
      v15 = v15 * i;
    v14 >>= 1;
    if ( !v14 )
      break;
  }
  v18 = this->points._Myfirst;
  v19 = 3;
  v20 = (float)(v18[v64].point.y * 0.16666667) * v15;
  v21 = (float)(v18[v64].point.x * 0.16666667) * v15;
  v22 = (float)(v18[v64].point.z * 0.16666667) * v15;
  v23 = v16;
  v68 = v20;
  v24 = FLOAT_1_0;
  v67 = v21;
  b = v22;
  while ( 1 )
  {
    if ( (v19 & 1) != 0 )
      v24 = v24 * v23;
    v19 >>= 1;
    if ( !v19 )
      break;
    v23 = v23 * v23;
  }
  v25 = v16;
  v26 = 2;
  v27 = FLOAT_1_0;
  while ( 1 )
  {
    if ( (v26 & 1) != 0 )
      v27 = v27 * v25;
    v26 >>= 1;
    if ( !v26 )
      break;
    v25 = v25 * v25;
  }
  v28 = LODWORD(v18[v59].point.x);
  v29 = (float)(v27 * 3.0) - (float)(v24 * 3.0);
  v30 = v16;
  v31 = 3;
  ta = v16 * 3.0;
  v32 = (float)(v29 + (float)(v16 * 3.0)) + 1.0;
  *(float *)&v28 = (float)(*(float *)&v28 * 0.16666667) * v32;
  v33 = (float)(v18[v59].point.y * 0.16666667) * v32;
  v34 = (float)(v18[v59].point.z * 0.16666667) * v32;
  v35 = FLOAT_1_0;
  *(_QWORD *)v70 = v28;
  v60 = v33;
  d1a = v34;
  while ( 1 )
  {
    if ( (v31 & 1) != 0 )
      v35 = v35 * v30;
    v31 >>= 1;
    if ( !v31 )
      break;
    v30 = v30 * v30;
  }
  v36 = v16;
  v37 = 2;
  v38 = FLOAT_1_0;
  while ( 1 )
  {
    if ( (v37 & 1) != 0 )
      v38 = v38 * v36;
    v37 >>= 1;
    if ( !v37 )
      break;
    v36 = v36 * v36;
  }
  v39 = 3;
  v40 = (float)((float)(v35 * 3.0) - (float)(v38 * 6.0)) + 4.0;
  v41 = (float)(v18[v6].point.z * 0.16666667) * v40;
  v42 = (float)(v18[v6].point.y * 0.16666667) * v40;
  v43 = (float)(v18[v6].point.x * 0.16666667) * v40;
  v44 = v16;
  d2 = v41;
  v45 = FLOAT_1_0;
  v65 = v42;
  while ( 1 )
  {
    if ( (v39 & 1) != 0 )
      v45 = v45 * v44;
    v39 >>= 1;
    if ( !v39 )
      break;
    v44 = v44 * v44;
  }
  v46 = 2;
  v47 = FLOAT_1_0;
  while ( 1 )
  {
    if ( (v46 & 1) != 0 )
      v47 = v47 * v16;
    v46 >>= 1;
    if ( !v46 )
      break;
    v16 = v16 * v16;
  }
  v48 = (float)(v47 * 3.0) - v45;
  v49 = (__m128)LODWORD(v60);
  v50 = (float)(v48 - ta) + 1.0;
  v51 = (float)(v18[v66].point.z * 0.16666667) * v50;
  v52 = (float)((float)(v18[v66].point.x * 0.16666667) * v50) + v43;
  v53 = (float)((float)(v18[v66].point.y * 0.16666667) * v50) + v65;
  v54 = (__m128)_mm_loadl_epi64((const __m128i *)v70);
  v54.m128_f32[0] = (float)(v54.m128_f32[0] + v52) + v67;
  v49.m128_f32[0] = (float)(v60 + v53) + v68;
  v55 = (float)(d1a + (float)(v51 + d2)) + b;
  *(_QWORD *)&result->x = _mm_unpacklo_ps(v54, v49).m128_u64[0];
  *(float *)&v70[8] = v55;
  result->z = v55;
  return result;
}
void InterpolatingSpline::clear(InterpolatingSpline *this)
{
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<GridElement>>>>(
    this->grid._Myfirst,
    this->grid._Mylast);
  this->grid._Mylast = this->grid._Myfirst;
  Spline::clear(this);
}
const vec3f *InterpolatingSpline::closestPointIndex(InterpolatingSpline *this, const vec3f *point, float *distance)
{
  if ( this->points._Myfirst == this->points._Mylast )
    return 0;
  if ( this->gridData )
    return InterpolatingSpline::closestPointIndexGrid(this, point, 0);
  return (const vec3f *)Spline::closestPointIndex(this, point, 0);
}
const vec3f *InterpolatingSpline::closestPointIndexGrid(InterpolatingSpline *this, const vec3f *position, float *distance)
{
  GridData *v4; // esi
  unsigned int v5; // edi
  int v7; // esi
  std::vector<GridElement> *v8; // edi
  GridElement *v9; // eax
  float v10; // xmm3_4
  const vec3f *v11; // ebp
  int v12; // esi
  unsigned int *v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // edi
  SplinePoint *v16; // edx
  SplinePoint *v17; // ebx
  float v18; // xmm4_4
  unsigned int v19; // edx
  const vec3f *v20; // eax
  const vec3f *v21; // edx
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // [esp+0h] [ebp-Ch]
  unsigned int v26; // [esp+0h] [ebp-Ch]
  float v27; // [esp+4h] [ebp-8h]
  float v28; // [esp+8h] [ebp-4h]
  const vec3f *positiona; // [esp+10h] [ebp+4h]

  v4 = this->gridData;
  v25 = 1.0 / v4->samplingDensity;
  v5 = (unsigned int)(float)((float)(position->x - v4->minExtreme.x) * v25);
  v28 = position->z;
  v26 = (unsigned int)(float)((float)(v28 - v4->minExtreme.z) * v25);
  if ( v5 >= this->grid._Mylast - this->grid._Myfirst )
    return (const vec3f *)Spline::closestPointIndex(this, position, distance);
  v7 = v5;
  v8 = this->grid._Myfirst;
  if ( v26 >= v8[v7]._Mylast - v8[v7]._Myfirst )
    return (const vec3f *)Spline::closestPointIndex(this, position, distance);
  v9 = v8[v7]._Myfirst;
  v10 = FLOAT_9999999_0;
  v11 = 0;
  v12 = 0;
  v13 = v9[v26].closestIndices._Myfirst;
  v14 = (unsigned int)v9[v26].closestIndices._Mylast;
  v15 = (v14 - (unsigned int)v13 + 3) >> 2;
  if ( (unsigned int)v13 > v14 )
    v15 = 0;
  if ( v15 )
  {
    v16 = this->points._Mylast;
    v17 = this->points._Myfirst;
    v27 = position->x;
    v18 = position->y;
    v19 = (int)((unsigned __int64)(1717986919i64 * ((char *)v16 - (char *)v17)) >> 32) >> 3;
    v20 = (const vec3f *)(v19 + (v19 >> 31) - 1);
    positiona = v20;
    do
    {
      v21 = (const vec3f *)*v13;
      if ( *v13 > (unsigned int)v20 )
        v21 = v20;
      v22 = v18 - v17[(_DWORD)v21].point.y;
      v23 = v28 - v17[(_DWORD)v21].point.z;
      v24 = (float)((float)(v22 * v22)
                  + (float)((float)(v27 - v17[(_DWORD)v21].point.x) * (float)(v27 - v17[(_DWORD)v21].point.x)))
          + (float)(v23 * v23);
      if ( v10 > v24 )
      {
        v10 = v24;
        v11 = v21;
      }
      v20 = positiona;
      ++v12;
      ++v13;
    }
    while ( v12 != v15 );
  }
  if ( distance )
    *distance = fsqrt(v10);
  return v11;
}
void __usercall InterpolatingSpline::computeSplineCoefficients(InterpolatingSpline *this@<ecx>, __m128 a2@<xmm0>)
{
  InterpolatingSpline *v2; // edi
  float *v3; // ebx
  float *v4; // esi
  float *v5; // ebp
  int v6; // ecx
  int v7; // edi
  const vec3f *v8; // eax
  int v9; // ecx
  int v10; // edx
  vec3f *v11; // eax
  int v12; // [esp+14h] [ebp-38h]
  float d; // [esp+18h] [ebp-34h] BYREF
  unsigned int v14; // [esp+1Ch] [ebp-30h]
  InterpolatingSpline *v15; // [esp+20h] [ebp-2Ch]
  unsigned int v16; // [esp+24h] [ebp-28h]
  std::vector<float> indices; // [esp+28h] [ebp-24h] BYREF
  std::vector<vec3f> ps; // [esp+34h] [ebp-18h] BYREF
  int v19; // [esp+48h] [ebp-4h]

  v2 = this;
  v15 = this;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  indices._Myfirst = 0;
  indices._Mylast = 0;
  indices._Myend = 0;
  v19 = 1;
  ps._Myfirst = 0;
  ps._Mylast = 0;
  ps._Myend = 0;
  v14 = 0;
  if ( this->points._Mylast - this->points._Myfirst )
  {
    v6 = 0;
    v12 = 0;
    do
    {
      a2 = (__m128)*(unsigned int *)((char *)&v2->points._Myfirst->pointLength + v6);
      a2.m128_f32[0] = a2.m128_f32[0] / v2->m_length;
      v16 = a2.m128_i32[0];
      d = a2.m128_f32[0];
      if ( &d >= v4 || v3 > &d )
      {
        if ( v4 == v5 )
        {
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&indices, 1u);
          v5 = indices._Myend;
          v4 = indices._Mylast;
          v3 = indices._Myfirst;
          a2 = (__m128)v16;
          v6 = v12;
        }
        if ( v4 )
          *v4 = a2.m128_f32[0];
      }
      else
      {
        v7 = &d - v3;
        if ( v4 == v5 )
        {
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&indices, 1u);
          v5 = indices._Myend;
          v4 = indices._Mylast;
          v3 = indices._Myfirst;
          v6 = v12;
        }
        if ( v4 )
          *v4 = v3[v7];
        v2 = v15;
      }
      ++v4;
      v8 = (vec3f *)((char *)&v2->points._Myfirst->point + v6);
      indices._Mylast = v4;
      std::vector<DRSZone>::push_back(&ps, v8);
      v9 = (char *)v2->points._Mylast - (char *)v2->points._Myfirst;
      ++v14;
      v12 += 20;
      v10 = (unsigned __int64)(1717986919i64 * v9) >> 32;
      v6 = v12;
    }
    while ( v14 < (v10 >> 3) + ((unsigned int)v10 >> 31) );
  }
  CubicSpline<float,vec3f>::computeCoefficients(&v2->cubicSpline, a2, &indices, &ps);
  v11 = ps._Myfirst;
  v2->isSplineReady = 1;
  if ( v11 )
    operator delete(v11);
  if ( v3 )
    operator delete(v3);
}
void InterpolatingSpline::computeSplineLength(InterpolatingSpline *this)
{
  InterpolatingSpline *v1; // esi
  SplinePoint *v2; // eax
  int v3; // ebx
  int v4; // ebp
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  float v9; // xmm4_4
  float v10; // xmm5_4
  SplinePoint *v11; // edx
  int v12; // eax
  float v13; // xmm0_4
  int v14; // ecx
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm2_4
  unsigned int v18; // eax
  float v19; // xmm1_4
  float v20; // xmm3_4
  unsigned int v21; // eax
  float v22; // xmm2_4
  float v23; // xmm1_4
  unsigned int v24; // eax
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  unsigned int v29; // eax
  float v30; // xmm1_4
  unsigned int v31; // eax
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm3_4
  unsigned int v38; // eax
  float v39; // xmm2_4
  unsigned int v40; // eax
  float v41; // xmm3_4
  float v42; // xmm1_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm7_4
  float i; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  unsigned int v49; // eax
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  unsigned int v54; // edx
  bool v55; // al
  unsigned int v56; // esi
  int v57; // esi
  int v58; // ebx
  int v59; // edi
  int v60; // eax
  int v61; // edx
  SplinePoint *v62; // esi
  float v63; // xmm4_4
  float v64; // xmm5_4
  float v65; // xmm6_4
  float v66; // xmm7_4
  float v67; // xmm0_4
  float v68; // xmm2_4
  unsigned int v69; // eax
  float v70; // xmm1_4
  float v71; // xmm2_4
  float v72; // xmm3_4
  unsigned int v73; // eax
  float v74; // xmm1_4
  float v75; // xmm2_4
  unsigned int v76; // eax
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm1_4
  float v80; // xmm3_4
  unsigned int v81; // eax
  unsigned int v82; // eax
  float v83; // xmm1_4
  float v84; // xmm2_4
  float v85; // xmm1_4
  float v86; // xmm0_4
  float v87; // xmm1_4
  float v88; // xmm2_4
  float v89; // xmm3_4
  unsigned int v90; // eax
  unsigned int v91; // eax
  float v92; // xmm1_4
  float v93; // xmm2_4
  float v94; // xmm1_4
  float v95; // xmm5_4
  float v96; // xmm6_4
  float v97; // xmm7_4
  float j; // xmm1_4
  float v99; // xmm3_4
  float v100; // xmm1_4
  unsigned int v101; // eax
  float v102; // xmm3_4
  float v103; // xmm0_4
  float v104; // xmm0_4
  float v105; // xmm1_4
  float v107; // [esp+18h] [ebp-68h]
  float v108; // [esp+1Ch] [ebp-64h]
  float v109; // [esp+20h] [ebp-60h]
  float v110; // [esp+24h] [ebp-5Ch]
  float v111; // [esp+24h] [ebp-5Ch]
  float v112; // [esp+28h] [ebp-58h]
  float v113; // [esp+2Ch] [ebp-54h]
  float v114; // [esp+30h] [ebp-50h]
  float v115; // [esp+34h] [ebp-4Ch]
  float v116; // [esp+3Ch] [ebp-44h]
  float v117; // [esp+4Ch] [ebp-34h]
  float v118; // [esp+54h] [ebp-2Ch]
  float v119; // [esp+58h] [ebp-28h]
  float v120; // [esp+5Ch] [ebp-24h]
  float v121; // [esp+60h] [ebp-20h]
  float v122; // [esp+60h] [ebp-20h]
  float v123; // [esp+64h] [ebp-1Ch]
  float v124; // [esp+64h] [ebp-1Ch]
  __int64 oldVector; // [esp+68h] [ebp-18h]
  __int64 oldVectora; // [esp+68h] [ebp-18h]
  float oldVector_8; // [esp+70h] [ebp-10h]
  float oldVector_8a; // [esp+70h] [ebp-10h]
  __int64 newVector; // [esp+74h] [ebp-Ch]
  __int64 newVectora; // [esp+74h] [ebp-Ch]
  float newVector_8; // [esp+7Ch] [ebp-4h]
  float newVector_8a; // [esp+7Ch] [ebp-4h]

  v1 = this;
  v2 = this->points._Myfirst;
  if ( v2 != this->points._Mylast )
  {
    v107 = 0.0;
    if ( ((int)((unsigned __int64)(1717986919i64 * ((char *)this->points._Mylast - (char *)v2)) >> 32) >> 3)
       + ((unsigned int)((unsigned __int64)(1717986919i64 * ((char *)this->points._Mylast - (char *)v2)) >> 32) >> 31)
       - 1 )
    {
      v3 = 0;
      v4 = 1;
      do
      {
        v5 = Spline::wrapIndex(v1, v4 - 2);
        v6 = Spline::wrapIndex(v1, v4++);
        v7 = v6;
        v8 = Spline::wrapIndex(this, v4);
        v9 = 0.0;
        v10 = FLOAT_1_0;
        v11 = this->points._Myfirst;
        oldVector = *(_QWORD *)&v11[v3].point.x;
        v108 = 0.0;
        oldVector_8 = v11[v3].point.z;
        v12 = v8;
        v13 = v11[v8].point.x;
        v14 = v7;
        v110 = v13 * 0.5;
        v15 = v11[v12].point.y * 0.5;
        v16 = v11[v12].point.z * 0.5;
        v121 = v15;
        v123 = v16;
        do
        {
          v17 = v9;
          v18 = 3;
          v19 = v10;
          while ( 1 )
          {
            if ( (v18 & 1) != 0 )
              v19 = v19 * v17;
            v18 >>= 1;
            if ( !v18 )
              break;
            v17 = v17 * v17;
          }
          v20 = v9;
          v21 = 2;
          v22 = v10;
          while ( 1 )
          {
            if ( (v21 & 1) != 0 )
              v22 = v22 * v20;
            v21 >>= 1;
            if ( !v21 )
              break;
            v20 = v20 * v20;
          }
          v23 = v19 - v22;
          v24 = 3;
          v25 = v10;
          v118 = v110 * v23;
          v119 = v15 * v23;
          v26 = v16 * v23;
          v27 = v9;
          v120 = v26;
          while ( 1 )
          {
            if ( (v24 & 1) != 0 )
              v25 = v25 * v27;
            v24 >>= 1;
            if ( !v24 )
              break;
            v27 = v27 * v27;
          }
          v28 = v9;
          v29 = 2;
          v30 = v10;
          while ( 1 )
          {
            if ( (v29 & 1) != 0 )
              v30 = v30 * v28;
            v29 >>= 1;
            if ( !v29 )
              break;
            v28 = v28 * v28;
          }
          v31 = 3;
          v32 = (float)(v30 * 4.0) - (float)(v25 * 3.0);
          v33 = v9;
          v34 = v32 + v9;
          v109 = (float)(v11[v7].point.x * 0.5) * v34;
          v117 = (float)(v11[v7].point.y * 0.5) * v34;
          v35 = (float)(v11[v7].point.z * 0.5) * v34;
          v36 = v10;
          while ( 1 )
          {
            if ( (v31 & 1) != 0 )
              v36 = v36 * v33;
            v31 >>= 1;
            if ( !v31 )
              break;
            v33 = v33 * v33;
          }
          v37 = v9;
          v38 = 2;
          v39 = v10;
          while ( 1 )
          {
            if ( (v38 & 1) != 0 )
              v39 = v39 * v37;
            v38 >>= 1;
            if ( !v38 )
              break;
            v37 = v37 * v37;
          }
          v40 = 3;
          v41 = FLOAT_1_0;
          v42 = (float)((float)(v36 * 3.0) - (float)(v39 * 5.0)) + 2.0;
          v43 = (float)(v11[v3].point.x * 0.5) * v42;
          v44 = (float)(v11[v3].point.y * 0.5) * v42;
          v45 = (float)(v11[v3].point.z * 0.5) * v42;
          for ( i = v9; ; i = i * i )
          {
            if ( (v40 & 1) != 0 )
              v41 = v41 * i;
            v40 >>= 1;
            if ( !v40 )
              break;
          }
          v47 = FLOAT_1_0;
          v48 = v9;
          v49 = 2;
          while ( 1 )
          {
            if ( (v49 & 1) != 0 )
              v47 = v47 * v48;
            v49 >>= 1;
            if ( !v49 )
              break;
            v48 = v48 * v48;
          }
          v50 = (float)((float)(v47 * 2.0) - v41) - v9;
          *((float *)&newVector + 1) = (float)((float)((float)((float)(v11[v5].point.y * 0.5) * v50) + v44) + v117)
                                     + v119;
          *(float *)&newVector = (float)((float)((float)((float)(v11[v5].point.x * 0.5) * v50) + v43) + v109) + v118;
          newVector_8 = (float)((float)((float)((float)(v11[v5].point.z * 0.5) * v50) + v45) + v35) + v120;
          v51 = (float)((float)((float)(*((float *)&newVector + 1) - *((float *)&oldVector + 1))
                              * (float)(*((float *)&newVector + 1) - *((float *)&oldVector + 1)))
                      + (float)((float)(*(float *)&newVector - *(float *)&oldVector)
                              * (float)(*(float *)&newVector - *(float *)&oldVector)))
              + (float)((float)(newVector_8 - oldVector_8) * (float)(newVector_8 - oldVector_8));
          v52 = 0.0;
          if ( v51 != 0.0 )
            v52 = fsqrt(v51);
          v53 = v52 + v108;
          v9 = v9 + 0.001;
          v10 = FLOAT_1_0;
          v15 = v121;
          v16 = v123;
          oldVector_8 = newVector_8;
          v108 = v53;
          oldVector = newVector;
        }
        while ( v9 <= 1.0 );
        v1 = this;
        ++v3;
        v11[v14].pointLength = v53 + v107;
        v107 = v53 + v107;
        v54 = (int)((unsigned __int64)(1717986919i64 * ((char *)v1->points._Mylast - (char *)v1->points._Myfirst)) >> 32) >> 3;
      }
      while ( v4 - 1 < v54 + (v54 >> 31) - 1 );
    }
    v55 = Spline::isClosed(v1);
    v1->m_closed = v55;
    if ( v55 )
    {
      v56 = (int)((unsigned __int64)(1717986919i64 * ((char *)v1->points._Mylast - (char *)v1->points._Myfirst)) >> 32) >> 3;
      v57 = v56 - 1 + (v56 >> 31);
      v58 = Spline::wrapIndex(this, v57 - 1);
      v59 = Spline::wrapIndex(this, v57 + 1);
      v60 = Spline::wrapIndex(this, v57 + 2);
      v61 = v57;
      v62 = this->points._Myfirst;
      v63 = 0.0;
      oldVectora = *(_QWORD *)&v62[v61].point.x;
      oldVector_8a = v62[v61].point.z;
      v64 = v62[v60].point.y * 0.5;
      v122 = v62[v60].point.x * 0.5;
      v65 = v62[v60].point.z * 0.5;
      v66 = v62[v59].point.x * 0.5;
      v112 = v64;
      v111 = v65;
      v67 = FLOAT_1_0;
      do
      {
        v68 = v63;
        v69 = 3;
        v70 = v67;
        while ( 1 )
        {
          if ( (v69 & 1) != 0 )
            v70 = v70 * v68;
          v69 >>= 1;
          if ( !v69 )
            break;
          v68 = v68 * v68;
        }
        v71 = FLOAT_1_0;
        v72 = v63;
        v73 = 2;
        while ( 1 )
        {
          if ( (v73 & 1) != 0 )
            v71 = v71 * v72;
          v73 >>= 1;
          if ( !v73 )
            break;
          v72 = v72 * v72;
        }
        v74 = v70 - v71;
        v75 = FLOAT_1_0;
        v76 = 3;
        v115 = v122 * v74;
        v114 = v64 * v74;
        v77 = v65 * v74;
        v78 = v63;
        v113 = v77;
        while ( 1 )
        {
          if ( (v76 & 1) != 0 )
            v75 = v75 * v78;
          v76 >>= 1;
          if ( !v76 )
            break;
          v78 = v78 * v78;
        }
        v79 = FLOAT_1_0;
        v80 = v63;
        v81 = 2;
        while ( 1 )
        {
          if ( (v81 & 1) != 0 )
            v79 = v79 * v80;
          v81 >>= 1;
          if ( !v81 )
            break;
          v80 = v80 * v80;
        }
        v82 = 3;
        v83 = (float)(v79 * 4.0) - (float)(v75 * 3.0);
        v84 = v63;
        v85 = v83 + v63;
        v124 = v66 * v85;
        v116 = (float)(v62[v59].point.y * 0.5) * v85;
        v86 = (float)(v62[v59].point.z * 0.5) * v85;
        v87 = FLOAT_1_0;
        while ( 1 )
        {
          if ( (v82 & 1) != 0 )
            v87 = v87 * v84;
          v82 >>= 1;
          if ( !v82 )
            break;
          v84 = v84 * v84;
        }
        v88 = FLOAT_1_0;
        v89 = v63;
        v90 = 2;
        while ( 1 )
        {
          if ( (v90 & 1) != 0 )
            v88 = v88 * v89;
          v90 >>= 1;
          if ( !v90 )
            break;
          v89 = v89 * v89;
        }
        v91 = 3;
        v92 = (float)(v87 * 3.0) - (float)(v88 * 5.0);
        v93 = FLOAT_1_0;
        v94 = v92 + 2.0;
        v95 = (float)(v62[v61].point.x * 0.5) * v94;
        v96 = (float)(v62[v61].point.y * 0.5) * v94;
        v97 = (float)(v62[v61].point.z * 0.5) * v94;
        for ( j = v63; ; j = j * j )
        {
          if ( (v91 & 1) != 0 )
            v93 = v93 * j;
          v91 >>= 1;
          if ( !v91 )
            break;
        }
        v99 = FLOAT_1_0;
        v100 = v63;
        v101 = 2;
        while ( 1 )
        {
          if ( (v101 & 1) != 0 )
            v99 = v99 * v100;
          v101 >>= 1;
          if ( !v101 )
            break;
          v100 = v100 * v100;
        }
        v102 = (float)((float)(v99 * 2.0) - v93) - v63;
        *(float *)&newVectora = v115 + (float)(v124 + (float)((float)((float)(v62[v58].point.x * 0.5) * v102) + v95));
        *((float *)&newVectora + 1) = v114
                                    + (float)(v116 + (float)((float)((float)(v62[v58].point.y * 0.5) * v102) + v96));
        newVector_8a = v113 + (float)(v86 + (float)((float)((float)(v62[v58].point.z * 0.5) * v102) + v97));
        v103 = (float)((float)((float)(*((float *)&newVectora + 1) - *((float *)&oldVectora + 1))
                             * (float)(*((float *)&newVectora + 1) - *((float *)&oldVectora + 1)))
                     + (float)((float)(*(float *)&newVectora - *(float *)&oldVectora)
                             * (float)(*(float *)&newVectora - *(float *)&oldVectora)))
             + (float)((float)(newVector_8a - oldVector_8a) * (float)(newVector_8a - oldVector_8a));
        if ( v103 == 0.0 )
          v104 = 0.0;
        else
          v104 = fsqrt(v103);
        v63 = v63 + 0.001;
        v64 = v112;
        v65 = v111;
        v66 = v62[v59].point.x * 0.5;
        v105 = v104 + v107;
        oldVectora = newVectora;
        v67 = FLOAT_1_0;
        oldVector_8a = newVector_8a;
        v107 = v105;
      }
      while ( v63 <= 1.0 );
      this->m_length = v105;
    }
    else
    {
      v1->m_length = v107;
    }
  }
}
void InterpolatingSpline::filterPointsTooClose(InterpolatingSpline *this, float minDistance)
{
  unsigned int v3; // ebx
  int v4; // ebp
  int i; // esi
  int v6; // eax
  SplinePoint *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  int v12; // eax
  SplinePoint *v13; // [esp-4h] [ebp-30h]
  std::vector<SplinePoint> newPoints; // [esp+14h] [ebp-18h] BYREF
  int v15; // [esp+28h] [ebp-4h]

  newPoints._Myfirst = 0;
  newPoints._Mylast = 0;
  newPoints._Myend = 0;
  v13 = this->points._Myfirst;
  v15 = 0;
  std::vector<SplinePoint>::push_back(&newPoints, v13);
  v3 = 1;
  if ( (unsigned int)(this->points._Mylast - this->points._Myfirst) > 1 )
  {
    v4 = 1;
    do
    {
      for ( i = 1; ; ++i )
      {
        v6 = Spline::wrapIndex(this, i + v3);
        v7 = this->points._Myfirst;
        v6 *= 5;
        v8 = v7[v4].point.y - *(&v7->point.y + v6);
        v9 = v7[v4].point.z - *(&v7->point.z + v6);
        v10 = (float)((float)((float)(v7[v4].point.x - *(&v7->point.x + v6))
                            * (float)(v7[v4].point.x - *(&v7->point.x + v6)))
                    + (float)(v8 * v8))
            + (float)(v9 * v9);
        v11 = 0.0;
        if ( v10 != 0.0 )
          v11 = fsqrt(v10);
        if ( minDistance <= v11 )
          break;
      }
      if ( i )
      {
        v12 = Spline::wrapIndex(this, i + v3);
        std::vector<SplinePoint>::push_back(&newPoints, &this->points._Myfirst[v12]);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->points._Mylast - this->points._Myfirst );
  }
  InterpolatingSpline::computeSplineLength(this);
  if ( newPoints._Myfirst )
    operator delete(newPoints._Myfirst);
}
unsigned int InterpolatingSpline::getLastIndexFromNorm(InterpolatingSpline *this, float t, float *blendToNext)
{
  unsigned int result; // eax
  double v5; // st7
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // edx
  int i; // eax
  SplinePoint *v10; // ecx
  float v11; // xmm1_4
  SplinePoint *v12; // eax
  float v13; // xmm2_4
  float v14; // xmm0_4
  SplinePoint *v15; // ebx
  int v16; // ecx
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float distance; // [esp+4h] [ebp-4h]

  if ( this->points._Myfirst == this->points._Mylast )
    return 0;
  v5 = Spline::length(this);
  v6 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
  distance = v5 * t;
  v7 = (unsigned int)(float)((float)(((int)((unsigned __int64)(1717986919i64 * v6) >> 32) >> 3)
                                   - 1
                                   + ((unsigned int)((unsigned __int64)(1717986919i64 * v6) >> 32) >> 31))
                           * t);
  v8 = ((unsigned int)((unsigned __int64)(1717986919i64 * v6) >> 32) >> 31)
     + ((int)((unsigned __int64)(1717986919i64 * v6) >> 32) >> 3)
     - 1;
  for ( i = v7; ; ++i )
  {
    while ( 1 )
    {
      if ( v7 >= v8 )
      {
        if ( Spline::isClosed(this) )
        {
          v15 = this->points._Myfirst;
          v16 = (char *)this->points._Mylast - (char *)v15;
          v17 = v15->point.x - v15[v16 / 20 - 1].point.x;
          v18 = v15->point.y - v15[v16 / 20 - 1].point.y;
          v19 = v15->point.z - v15[v16 / 20 - 1].point.z;
          v20 = (float)((float)(v17 * v17) + (float)(v18 * v18)) + (float)(v19 * v19);
          v21 = 0.0;
          if ( v20 != 0.0 )
            v21 = fsqrt(v20);
          if ( blendToNext )
            *blendToNext = (float)(distance - v15[this->points._Mylast - v15 - 1].pointLength) / v21;
        }
        return v7;
      }
      v10 = this->points._Myfirst;
      v11 = v10[i].pointLength;
      if ( distance >= v11 )
        break;
LABEL_9:
      --v7;
      --i;
    }
    if ( v10[i + 1].pointLength > distance )
      break;
    if ( distance <= v11 )
      goto LABEL_9;
    ++v7;
  }
  if ( blendToNext )
  {
    v12 = this->points._Myfirst;
    v13 = distance - v12[v7].pointLength;
    v14 = v12[v7 + 1].pointLength - v12[v7].pointLength;
    result = v7;
    *blendToNext = v13 / v14;
    return result;
  }
  return v7;
}
double InterpolatingSpline::getNormalizedPosition(InterpolatingSpline *this, const unsigned int index)
{
  SplinePoint *v3; // esi
  float v5; // [esp+4h] [ebp-4h]

  if ( this->points._Myfirst == this->points._Mylast )
    return 0.0;
  v5 = Spline::length(this);
  if ( v5 == 0.0 )
    return 0.0;
  v3 = this->points._Myfirst;
  return v3[index].pointLength / Spline::length(this);
}
double InterpolatingSpline::getSignedDistanceFromSpline(InterpolatingSpline *this, const vec3f *p, float splinePosition)
{
  float pos; // xmm0_4
  vec3f *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  double v17; // st7
  float v18; // [esp+8h] [ebp-20h]
  vec3f projection; // [esp+10h] [ebp-18h] BYREF
  vec3f result; // [esp+1Ch] [ebp-Ch] BYREF
  float sign; // [esp+2Ch] [ebp+4h]
  float signa; // [esp+2Ch] [ebp+4h]
  float splinePositiona; // [esp+30h] [ebp+8h]
  float splinePositionc; // [esp+30h] [ebp+8h]
  float splinePositionb; // [esp+30h] [ebp+8h]

  InterpolatingSpline::splineToWorld(this, &projection, splinePosition);
  splinePositiona = 0.5 / Spline::length(this) + splinePosition;
  pos = splinePositiona;
  if ( Spline::isClosed(this) )
  {
    if ( splinePositiona < 0.0 )
      pos = splinePositiona + 1.0;
    if ( pos > 1.0 )
      pos = pos - 1.0;
  }
  else
  {
    splinePositionc = Spline::boundInsideSpline(this, splinePositiona);
    pos = splinePositionc;
  }
  v5 = InterpolatingSpline::splineToWorld(this, &result, pos);
  v6 = v5->x - projection.x;
  v7 = v5->y - projection.y;
  v8 = v5->z - projection.z;
  v9 = fsqrt((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8));
  if ( v9 != 0.0 )
  {
    v8 = v8 * (float)(1.0 / v9);
    v6 = (float)(1.0 / v9) * v6;
    v7 = (float)(1.0 / v9) * v7;
  }
  v10 = p->z - projection.z;
  v11 = p->y - projection.y;
  v18 = p->x - projection.x;
  sign = v18;
  splinePositionb = v10;
  v12 = v11;
  v13 = fsqrt((float)((float)(v11 * v11) + (float)(v18 * v18)) + (float)(splinePositionb * splinePositionb));
  if ( v13 == 0.0 )
  {
    v15 = v10;
  }
  else
  {
    sign = (float)(1.0 / v13) * v18;
    v14 = 1.0 / v13;
    v12 = v14 * v11;
    v15 = v14 * v10;
    splinePositionb = v15;
  }
  v16 = (float)((float)(v11 * v11) + (float)(v18 * v18)) + (float)(v10 * v10);
  signa = (float)((float)((float)((float)(v15 * v7) - (float)(v12 * v8)) * 0.0)
                + (float)((float)(sign * v8) - (float)(splinePositionb * v6)))
        + (float)((float)((float)(v12 * v6) - (float)(sign * v7)) * 0.0);
  if ( v16 == 0.0 )
    v17 = 0.0 * signa;
  else
    v17 = fsqrt(v16) * signa;
  return v17;
}
bool InterpolatingSpline::isGridOn(InterpolatingSpline *this)
{
  return this->gridData != 0;
}
vec3f *InterpolatingSpline::linearProjection(InterpolatingSpline *this, vec3f *result, const vec3f *point, int closestIndex)
{
  int v4; // edx
  const vec3f *v6; // eax
  float v7; // xmm6_4
  float v8; // xmm4_4
  int v9; // ecx
  SplinePoint *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  vec3f *v14; // eax
  float v15; // xmm1_4
  __int64 closestPoint; // [esp+8h] [ebp-Ch]
  float closestPoint_8; // [esp+10h] [ebp-4h]
  float pointa; // [esp+1Ch] [ebp+8h]
  int closestIndexa; // [esp+20h] [ebp+Ch]

  v4 = closestIndex;
  if ( closestIndex < 0 )
  {
    if ( this->points._Myfirst == this->points._Mylast )
    {
      v4 = 0;
    }
    else
    {
      if ( this->gridData )
        v6 = InterpolatingSpline::closestPointIndexGrid(this, point, 0);
      else
        v6 = (const vec3f *)Spline::closestPointIndex(this, point, 0);
      v4 = (int)v6;
    }
  }
  closestPoint = *(_QWORD *)&this->points._Myfirst[v4].point.x;
  closestPoint_8 = this->points._Myfirst[v4].point.z;
  *(float *)&closestIndexa = point->x - *(float *)&closestPoint;
  pointa = point->z - closestPoint_8;
  v7 = this->points._Myfirst[v4].point.x;
  v8 = 0.0;
  v9 = Spline::wrapIndex(this, v4 + 1);
  v10 = this->points._Myfirst;
  v11 = v10[v9].point.x - *(float *)&closestPoint;
  v12 = v10[v9].point.z - closestPoint_8;
  v13 = fsqrt((float)(v12 * v12) + (float)(v11 * v11));
  if ( v13 != 0.0 )
  {
    v11 = (float)(1.0 / v13) * v11;
    v8 = (float)(1.0 / v13) * 0.0;
    v12 = (float)(1.0 / v13) * v12;
  }
  v14 = result;
  v15 = (float)((float)(v11 * *(float *)&closestIndexa) + (float)(v8 * 0.0)) + (float)(v12 * pointa);
  result->x = (float)(v11 * v15) + v7;
  result->y = (float)(v15 * v8) + *((float *)&closestPoint + 1);
  result->z = (float)(v12 * v15) + closestPoint_8;
  return v14;
}
void InterpolatingSpline::loadGrid(InterpolatingSpline *this, std::ifstream *in)
{
  std::ifstream *v3; // esi
  GridData *v4; // eax
  GridData *v5; // eax
  std::vector<std::vector<GridElement>> *v6; // ebp
  int v7; // ebx
  GridElement *v8; // edi
  int v9; // edi
  std::vector<GridElement> *v10; // ecx
  int i; // esi
  bool v12; // cc
  int closestIndices; // [esp+6Ch] [ebp-40h] BYREF
  int gridSize2; // [esp+70h] [ebp-3Ch] BYREF
  int gridSize; // [esp+74h] [ebp-38h] BYREF
  int gridDataAvailable; // [esp+78h] [ebp-34h] BYREF
  int index; // [esp+7Ch] [ebp-30h] BYREF
  int v18; // [esp+80h] [ebp-2Ch]
  int v19; // [esp+84h] [ebp-28h]
  std::vector<GridElement> _Val; // [esp+88h] [ebp-24h] BYREF
  GridElement v21; // [esp+94h] [ebp-18h] BYREF
  int v22; // [esp+A8h] [ebp-4h]

  v3 = in;
  gridDataAvailable = 0;
  std::istream::read(in, &gridDataAvailable);
  if ( gridDataAvailable <= 0 )
  {
    InterpolatingSpline::buildGrid(this);
  }
  else
  {
    _printf("LOADING GRID DATA\n");
    v4 = (GridData *)operator new(32);
    if ( v4 )
      GridData::GridData(v4);
    else
      v5 = 0;
    this->gridData = v5;
    std::istream::read(in, v5);
    std::istream::read(in, &this->gridData->minExtreme);
    std::istream::read(in, &this->gridData->neighborsConsideredNumber);
    std::istream::read(in, &this->gridData->samplingDensity);
    gridSize = 0;
    std::istream::read(in, &gridSize);
    v19 = 0;
    if ( gridSize > 0 )
    {
      v6 = &this->grid;
      v7 = 0;
      do
      {
        _Val._Myfirst = 0;
        _Val._Mylast = 0;
        _Val._Myend = 0;
        v22 = 0;
        std::vector<std::vector<GridElement>>::push_back(v6, &_Val);
        v8 = _Val._Myfirst;
        v22 = -1;
        if ( _Val._Myfirst )
        {
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<GridElement>>>(_Val._Myfirst, _Val._Mylast);
          operator delete(v8);
          _Val._Myfirst = 0;
          _Val._Mylast = 0;
          _Val._Myend = 0;
        }
        gridSize2 = 0;
        std::istream::read(v3, &gridSize2);
        v18 = 0;
        if ( gridSize2 > 0 )
        {
          v9 = 0;
          do
          {
            v21.closestIndices._Myfirst = 0;
            v21.closestIndices._Mylast = 0;
            v21.closestIndices._Myend = 0;
            v10 = &v6->_Myfirst[v7];
            v22 = 1;
            std::vector<GridElement>::push_back(v10, &v21);
            v22 = -1;
            if ( v21.closestIndices._Myfirst )
            {
              operator delete(v21.closestIndices._Myfirst);
              v21.closestIndices._Myfirst = 0;
              v21.closestIndices._Mylast = 0;
              v21.closestIndices._Myend = 0;
            }
            closestIndices = 0;
            std::istream::read(v3, &closestIndices);
            std::vector<RenderTarget *>::resize(
              (std::vector<RenderTarget *> *)&v6->_Myfirst[v7]._Myfirst[v9],
              closestIndices);
            for ( i = 0; i < closestIndices; ++i )
            {
              index = 0;
              std::istream::read(in, &index);
              v6->_Myfirst[v7]._Myfirst[v9].closestIndices._Myfirst[i] = index;
            }
            ++v9;
            v12 = ++v18 < gridSize2;
            v3 = in;
          }
          while ( v12 );
        }
        ++v7;
        ++v19;
      }
      while ( v19 < gridSize );
    }
  }
}
void InterpolatingSpline::popBack(InterpolatingSpline *this)
{
  --this->points._Mylast;
}
void InterpolatingSpline::saveGrid(InterpolatingSpline *this, std::ofstream *out)
{
  std::ofstream *v2; // ebx
  int v3; // eax
  int v5; // esi
  std::vector<GridElement> *v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // edi
  unsigned int v10; // esi
  _DWORD *v11; // eax
  int v12; // [esp+6Ch] [ebp-24h]
  unsigned int v13; // [esp+70h] [ebp-20h]
  unsigned int v14; // [esp+74h] [ebp-1Ch]
  int gridDataAvailable; // [esp+78h] [ebp-18h] BYREF
  int gridSize; // [esp+7Ch] [ebp-14h] BYREF
  int gridSize2; // [esp+80h] [ebp-10h] BYREF
  int *v18; // [esp+84h] [ebp-Ch]
  int closestIndices; // [esp+88h] [ebp-8h] BYREF
  int index; // [esp+8Ch] [ebp-4h] BYREF

  v2 = out;
  v3 = 0;
  if ( this->gridData )
    v3 = 1;
  gridDataAvailable = v3;
  std::ostream::write(out, &gridDataAvailable, 4, 0);
  if ( this->gridData )
  {
    _printf("SAVING GRID DATA\n");
    std::ostream::write(out, this->gridData, 12, 0);
    std::ostream::write(out, &this->gridData->minExtreme, 12, 0);
    std::ostream::write(out, &this->gridData->neighborsConsideredNumber, 4, 0);
    std::ostream::write(out, &this->gridData->samplingDensity, 4, 0);
    gridSize = this->grid._Mylast - this->grid._Myfirst;
    std::ostream::write(out, &gridSize, 4, 0);
    v14 = 0;
    if ( this->grid._Mylast - this->grid._Myfirst )
    {
      v5 = 0;
      v6 = this->grid._Myfirst;
      v12 = 0;
      do
      {
        gridSize2 = *(GridElement **)((char *)&v6->_Mylast + v5) - *(GridElement **)((char *)&v6->_Myfirst + v5);
        std::ostream::write(v2, &gridSize2, 4, 0);
        v6 = this->grid._Myfirst;
        v13 = 0;
        v7 = *(char **)((char *)&v6->_Mylast + v5) - *(char **)((char *)&v6->_Myfirst + v5);
        v18 = (int *)((char *)v6 + v5);
        if ( v7 / 12 )
        {
          v8 = 0;
          v9 = *v18;
          do
          {
            closestIndices = (*(_DWORD *)(v9 + v8 + 4) - *(_DWORD *)(v9 + v8)) >> 2;
            std::ostream::write(out, &closestIndices, 4, 0);
            v10 = 0;
            v9 = *(int *)((char *)&this->grid._Myfirst->_Myfirst + v12);
            v11 = (_DWORD *)(v9 + v8);
            if ( (*(_DWORD *)(v9 + v8 + 4) - *(_DWORD *)(v9 + v8)) >> 2 )
            {
              do
              {
                index = *(_DWORD *)(*v11 + 4 * v10);
                std::ostream::write(out, &index, 4, 0);
                ++v10;
                v9 = *(int *)((char *)&this->grid._Myfirst->_Myfirst + v12);
                v11 = (_DWORD *)(v9 + v8);
              }
              while ( v10 < (*(_DWORD *)(v9 + v8 + 4) - *(_DWORD *)(v9 + v8)) >> 2 );
            }
            v8 += 12;
            v5 = v12;
            ++v13;
          }
          while ( v13 < *(GridElement **)((char *)&this->grid._Myfirst->_Mylast + v12)
                      - *(GridElement **)((char *)&this->grid._Myfirst->_Myfirst + v12) );
          v2 = out;
          v6 = this->grid._Myfirst;
        }
        v5 += 12;
        ++v14;
        v12 = v5;
      }
      while ( v14 < this->grid._Mylast - this->grid._Myfirst );
    }
  }
}
vec3f *InterpolatingSpline::splineToWorld(InterpolatingSpline *this, vec3f *result, float pos)
{
  __m128 t; // xmm0
  vec3f *v4; // eax

  t = (__m128)LODWORD(pos);
  if ( pos > 1.0 )
  {
    t = (__m128)LODWORD(FLOAT_1_0);
    goto LABEL_3;
  }
  if ( pos >= 0.0 )
  {
    if ( pos != 0.0 )
      goto LABEL_3;
  }
  else
  {
    t = 0i64;
  }
  if ( this->points._Myfirst != this->points._Mylast )
  {
    v4 = result;
    *result = this->points._Myfirst->point;
    return v4;
  }
LABEL_3:
  switch ( this->interpolationMode )
  {
    case eLinear:
      InterpolatingSpline::calculateLinear(this, result, t.m128_f32[0]);
      v4 = result;
      break;
    case eBezier:
      InterpolatingSpline::calculateCubicBezier(this, result, t.m128_f32[0]);
      v4 = result;
      break;
    case eCatmulRom:
      InterpolatingSpline::calculateCatmullRom(this, result, t.m128_f32[0]);
      v4 = result;
      break;
    case eBSpline:
      InterpolatingSpline::calculateUniformBSpline(this, result, t.m128_f32[0]);
      v4 = result;
      break;
    case eNThBezier:
      InterpolatingSpline::calculateNthBezier(this, result, t.m128_f32[0]);
      v4 = result;
      break;
    case eCubicSpline:
      InterpolatingSpline::calculateCubicSpline(this, t, result, t.m128_f32[0]);
      v4 = result;
      break;
    default:
      v4 = result;
      result->x = 0.0;
      result->y = 0.0;
      result->z = 0.0;
      break;
  }
  return v4;
}
double InterpolatingSpline::worldToSpline(InterpolatingSpline *this, const vec3f *pos, int closestIndex)
{
  const vec3f *v3; // eax
  InterpolatingSpline *v4; // esi
  int v5; // edi
  int v6; // edi
  SplinePoint *v7; // esi
  double v8; // st7
  SplinePoint *v9; // esi
  double v10; // st7
  int v11; // edi
  SplinePoint *v12; // esi
  double v13; // st7
  vec3f *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  vec3f *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  int v26; // edi
  bool v27; // al
  float v28; // xmm0_4
  vec3f *v29; // eax
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  bool v33; // al
  float v34; // xmm0_4
  vec3f *v35; // eax
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  int v40; // edi
  bool v41; // al
  float v42; // xmm0_4
  vec3f *v43; // eax
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm0_4
  bool v48; // al
  float v49; // xmm0_4
  vec3f *v50; // eax
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  bool v54; // al
  float v55; // xmm1_4
  vec3f v57; // [esp+Ch] [ebp-34h] BYREF
  vec3f result; // [esp+18h] [ebp-28h] BYREF
  float v59; // [esp+24h] [ebp-1Ch]
  float v60; // [esp+28h] [ebp-18h]
  float value; // [esp+2Ch] [ebp-14h]
  float v62; // [esp+30h] [ebp-10h]
  Spline *v63; // [esp+34h] [ebp-Ch]
  float v64; // [esp+38h] [ebp-8h]
  float v65; // [esp+3Ch] [ebp-4h]
  float closestIndexb; // [esp+48h] [ebp+8h]
  float closestIndexc; // [esp+48h] [ebp+8h]
  float closestIndexa; // [esp+48h] [ebp+8h]

  v3 = (const vec3f *)closestIndex;
  v4 = this;
  v63 = this;
  if ( closestIndex == -1 )
  {
    if ( this->points._Myfirst == this->points._Mylast )
    {
      v3 = 0;
    }
    else if ( this->gridData )
    {
      v3 = InterpolatingSpline::closestPointIndexGrid(this, pos, 0);
    }
    else
    {
      v3 = (const vec3f *)Spline::closestPointIndex(this, pos, 0);
    }
    closestIndex = (int)v3;
  }
  v5 = Spline::wrapIndex(v4, (int)&v3[-1].z + 3);
  if ( v4->points._Myfirst == v4->points._Mylast || (value = Spline::length(v4), value == 0.0) )
  {
    v65 = 0.0;
  }
  else
  {
    v7 = v4->points._Myfirst;
    v8 = v7[v5].pointLength / Spline::length(v63);
    v4 = (InterpolatingSpline *)v63;
    value = v8;
    v65 = value;
  }
  v6 = Spline::wrapIndex(v4, closestIndex);
  if ( v4->points._Myfirst == v4->points._Mylast )
  {
    v64 = 0.0;
  }
  else
  {
    value = Spline::length(v4);
    if ( value == 0.0 )
    {
      v64 = 0.0;
    }
    else
    {
      v9 = v4->points._Myfirst;
      v10 = v9[v6].pointLength / Spline::length(v63);
      v4 = (InterpolatingSpline *)v63;
      value = v10;
      v64 = value;
    }
  }
  v11 = Spline::wrapIndex(v4, closestIndex + 1);
  if ( v4->points._Myfirst == v4->points._Mylast )
  {
    v62 = 0.0;
  }
  else
  {
    closestIndexb = Spline::length(v4);
    if ( closestIndexb == 0.0 )
    {
      v62 = 0.0;
    }
    else
    {
      v12 = v4->points._Myfirst;
      v13 = v12[v11].pointLength / Spline::length(v63);
      v4 = (InterpolatingSpline *)v63;
      closestIndexc = v13;
      v62 = closestIndexc;
    }
  }
  v14 = InterpolatingSpline::splineToWorld(v4, &result, v65);
  v15 = v14->z - pos->z;
  v16 = (float)((float)((float)(v14->y - pos->y) * (float)(v14->y - pos->y))
              + (float)((float)(v14->x - pos->x) * (float)(v14->x - pos->x)))
      + (float)(v15 * v15);
  v17 = 0.0;
  if ( v16 != 0.0 )
    v17 = fsqrt(v16);
  value = v17;
  v18 = InterpolatingSpline::splineToWorld(v4, &result, v62);
  v19 = v18->z - pos->z;
  v20 = (float)((float)((float)(v18->y - pos->y) * (float)(v18->y - pos->y))
              + (float)((float)(v18->x - pos->x) * (float)(v18->x - pos->x)))
      + (float)(v19 * v19);
  if ( v20 == 0.0 )
    v21 = 0.0;
  else
    v21 = fsqrt(v20);
  v22 = FLOAT_0_5;
  v23 = FLOAT_0_25;
  v24 = v64;
  closestIndexa = FLOAT_0_5;
  *(float *)&v63 = FLOAT_0_25;
  if ( v21 <= value )
  {
    v39 = v62 - v64;
    v65 = v62 - v64;
    if ( (float)(v62 - v64) < 0.0 )
    {
      v39 = v39 + 1.0;
      v65 = v39;
    }
    v40 = 10;
    while ( 1 )
    {
      v59 = v22 - v23;
      value = (float)((float)(v22 - v23) * v39) + v24;
      v41 = Spline::isClosed(v4);
      v42 = value;
      if ( v41 )
      {
        if ( value < 0.0 )
          v42 = value + 1.0;
        if ( v42 > 1.0 )
          v42 = v42 - 1.0;
      }
      else
      {
        v60 = Spline::boundInsideSpline(v4, value);
        v42 = v60;
      }
      v43 = InterpolatingSpline::splineToWorld(v4, &v57, v42);
      v44 = v43->z - pos->z;
      v45 = (float)((float)((float)(v43->y - pos->y) * (float)(v43->y - pos->y))
                  + (float)((float)(v43->x - pos->x) * (float)(v43->x - pos->x)))
          + (float)(v44 * v44);
      v46 = 0.0;
      if ( v45 != 0.0 )
        v46 = fsqrt(v45);
      v62 = v46;
      v47 = (float)(*(float *)&v63 + closestIndexa) * v65;
      closestIndexa = *(float *)&v63 + closestIndexa;
      value = v47 + v64;
      v48 = Spline::isClosed(v4);
      v49 = value;
      if ( v48 )
      {
        if ( value < 0.0 )
          v49 = value + 1.0;
        if ( v49 > 1.0 )
          v49 = v49 - 1.0;
      }
      else
      {
        v60 = Spline::boundInsideSpline(v4, value);
        v49 = v60;
      }
      v50 = InterpolatingSpline::splineToWorld(v4, &result, v49);
      v51 = v50->z - pos->z;
      v52 = (float)((float)((float)(v50->y - pos->y) * (float)(v50->y - pos->y))
                  + (float)((float)(v50->x - pos->x) * (float)(v50->x - pos->x)))
          + (float)(v51 * v51);
      v53 = 0.0;
      if ( v52 != 0.0 )
        v53 = fsqrt(v52);
      if ( v53 <= v62 )
      {
        v22 = closestIndexa;
      }
      else
      {
        v22 = v59;
        closestIndexa = v59;
      }
      v23 = *(float *)&v63 * 0.5;
      *(float *)&v63 = *(float *)&v63 * 0.5;
      if ( !--v40 )
        break;
      v39 = v65;
      v24 = v64;
    }
  }
  else
  {
    v25 = v65 - v64;
    v65 = v65 - v64;
    if ( v65 > 0.0 )
    {
      LODWORD(v25) = COERCE_UNSIGNED_INT(1.0 - v25) ^ _xmm;
      v65 = v25;
    }
    v26 = 10;
    while ( 1 )
    {
      v60 = v23 + v22;
      value = (float)((float)(v23 + v22) * v25) + v24;
      v27 = Spline::isClosed(v4);
      v28 = value;
      if ( v27 )
      {
        if ( value < 0.0 )
          v28 = value + 1.0;
        if ( v28 > 1.0 )
          v28 = v28 - 1.0;
      }
      else
      {
        value = Spline::boundInsideSpline(v4, value);
        v28 = value;
      }
      v29 = InterpolatingSpline::splineToWorld(v4, &result, v28);
      v30 = v29->z - pos->z;
      v31 = (float)((float)((float)(v29->y - pos->y) * (float)(v29->y - pos->y))
                  + (float)((float)(v29->x - pos->x) * (float)(v29->x - pos->x)))
          + (float)(v30 * v30);
      v32 = 0.0;
      if ( v31 != 0.0 )
        v32 = fsqrt(v31);
      v62 = v32;
      closestIndexa = closestIndexa - *(float *)&v63;
      value = (float)(closestIndexa * v65) + v64;
      v33 = Spline::isClosed(v4);
      v34 = value;
      if ( v33 )
      {
        if ( value < 0.0 )
          v34 = value + 1.0;
        if ( v34 > 1.0 )
          v34 = v34 - 1.0;
      }
      else
      {
        value = Spline::boundInsideSpline(v4, value);
        v34 = value;
      }
      v35 = InterpolatingSpline::splineToWorld(v4, &v57, v34);
      v36 = v35->z - pos->z;
      v37 = (float)((float)((float)(v35->y - pos->y) * (float)(v35->y - pos->y))
                  + (float)((float)(v35->x - pos->x) * (float)(v35->x - pos->x)))
          + (float)(v36 * v36);
      v38 = 0.0;
      if ( v37 != 0.0 )
        v38 = fsqrt(v37);
      if ( v38 <= v62 )
      {
        v22 = closestIndexa;
      }
      else
      {
        v22 = v60;
        closestIndexa = v60;
      }
      v23 = *(float *)&v63 * 0.5;
      *(float *)&v63 = *(float *)&v63 * 0.5;
      if ( !--v26 )
        break;
      v25 = v65;
      v24 = v64;
    }
  }
  v65 = (float)(v65 * v22) + v64;
  v54 = Spline::isClosed(v4);
  v55 = v65;
  if ( !v54 )
    return Spline::boundInsideSpline(v4, v65);
  if ( v65 < 0.0 )
    v55 = v65 + 1.0;
  if ( v55 > 1.0 )
    v55 = v55 - 1.0;
  return v55;
}
double InterpolatingSpline::wrapPosition(InterpolatingSpline *this, float pos)
{
  float v4; // xmm1_4

  if ( !Spline::isClosed(this) )
    return Spline::boundInsideSpline(this, pos);
  v4 = pos;
  if ( pos < 0.0 )
  {
    v4 = pos + 1.0;
    pos = pos + 1.0;
  }
  if ( v4 > 1.0 )
    pos = v4 - 1.0;
  return pos;
}
