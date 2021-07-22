#include "spline.h
void Spline::Spline(Spline *this)
{
  this->__vftable = (Spline_vtbl *)&Spline::`vftable';
  this->points._Myfirst = 0;
  this->points._Mylast = 0;
  this->points._Myend = 0;
  this->m_closed = 0;
  this->m_length = 0.0;
}
void Spline::~Spline(Spline *this)
{
  SplinePoint *v2; // eax

  this->__vftable = (Spline_vtbl *)&Spline::`vftable';
  v2 = this->points._Myfirst;
  this->points._Mylast = v2;
  if ( v2 )
  {
    operator delete(v2);
    this->points._Myfirst = 0;
    this->points._Mylast = 0;
    this->points._Myend = 0;
  }
}
Spline *Spline::`scalar deleting destructor'(Spline *this, unsigned int a2)
{
  SplinePoint *v3; // eax

  this->__vftable = (Spline_vtbl *)&Spline::`vftable';
  v3 = this->points._Myfirst;
  this->points._Mylast = v3;
  if ( v3 )
  {
    operator delete(v3);
    this->points._Myfirst = 0;
    this->points._Mylast = 0;
    this->points._Myend = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Spline::addPoint(Spline *this, const vec3f *p, int tag)
{
  SplinePoint *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  std::vector<SplinePoint> *v7; // ecx
  __int64 v8; // xmm0_8
  SplinePoint _Val; // [esp+4h] [ebp-14h] BYREF

  if ( this->points._Mylast - this->points._Myfirst )
  {
    v3 = this->points._Mylast;
    v4 = p->z - v3[-1].point.z;
    v5 = (float)((float)((float)(p->y - v3[-1].point.y) * (float)(p->y - v3[-1].point.y))
               + (float)((float)(p->x - v3[-1].point.x) * (float)(p->x - v3[-1].point.x)))
       + (float)(v4 * v4);
    v6 = 0.0;
    if ( v5 != 0.0 )
      v6 = fsqrt(v5);
    this->m_length = v6 + this->m_length;
  }
  else
  {
    this->m_length = 0.0;
  }
  v7 = &this->points;
  v8 = *(_QWORD *)&p->x;
  _Val.point.z = p->z;
  _Val.tag = tag;
  *(_QWORD *)&_Val.point.x = v8;
  LODWORD(_Val.pointLength) = v7[1]._Myfirst;
  std::vector<SplinePoint>::push_back(v7, &_Val);
}
void Spline::addSplinePoint(Spline *this, const SplinePoint *p)
{
  std::vector<SplinePoint>::push_back(&this->points, p);
}
void Spline::applyMatrix(Spline *this, const mat44f *m)
{
  unsigned int v3; // ebp
  int v4; // ebx
  SplinePoint *v5; // ecx
  __m128 v6; // xmm3
  float v7; // xmm5_4
  __m128 v8; // xmm6
  float v9; // xmm4_4
  float v10; // xmm1_4

  v3 = 0;
  if ( this->points._Mylast - this->points._Myfirst )
  {
    v4 = 0;
    do
    {
      v5 = this->points._Myfirst;
      ++v3;
      v6 = (__m128)LODWORD(m->M22);
      v7 = v5[v4].point.y;
      v8 = (__m128)LODWORD(v5[v4].point.x);
      v9 = v5[v4].point.z;
      v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] * m->M11) + (float)(m->M21 * v7)) + (float)(m->M31 * v9))
                     + m->M41;
      v6.m128_f32[0] = (float)((float)((float)(v6.m128_f32[0] * v7) + (float)(v5[v4].point.x * m->M12))
                             + (float)(m->M32 * v9))
                     + m->M42;
      v10 = (float)((float)((float)(m->M13 * v5[v4].point.x) + (float)(m->M23 * v7)) + (float)(m->M33 * v9)) + m->M43;
      *(_QWORD *)&v5[v4].point.x = _mm_unpacklo_ps(v8, v6).m128_u64[0];
      v5[v4++].point.z = v10;
    }
    while ( v3 < this->points._Mylast - this->points._Myfirst );
  }
}
double Spline::boundInsideSpline(Spline *this, float value)
{
  int v4; // ecx
  int v5; // ecx

  if ( value < 0.0 )
    return 0.0;
  v4 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
  if ( value > (float)(((int)((unsigned __int64)(1717986919i64 * v4) >> 32) >> 3)
                     + ((unsigned int)((unsigned __int64)(1717986919i64 * v4) >> 32) >> 31)
                     - 1) )
  {
    v5 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
    value = (float)(((int)((unsigned __int64)(1717986919i64 * v5) >> 32) >> 3)
                  + ((unsigned int)((unsigned __int64)(1717986919i64 * v5) >> 32) >> 31)
                  - 1);
  }
  return value;
}
void Spline::clear(Spline *this)
{
  this->points._Mylast = this->points._Myfirst;
  this->m_length = 0.0;
}
unsigned int Spline::closestPointIndex(Spline *this, const vec3f *point, float *distance)
{
  const vec3f *v4; // esi
  Spline::closestPointIndex::__l9::<lambda_161ed80abd734302ca18e728b7dd1192> v5; // xmm0
  SplinePoint *v7; // [esp-14h] [ebp-44h]
  unsigned int foundIndex; // [esp+Ch] [ebp-24h] BYREF
  float Px; // [esp+10h] [ebp-20h] BYREF
  float v10; // [esp+14h] [ebp-1Ch] BYREF
  float v11; // [esp+18h] [ebp-18h] BYREF
  unsigned int c; // [esp+1Ch] [ebp-14h] BYREF
  Spline::closestPointIndex::__l9::<lambda_161ed80abd734302ca18e728b7dd1192> result; // [esp+20h] [ebp-10h] BYREF

  if ( !(this->points._Mylast - this->points._Myfirst) )
    return 0;
  v4 = point;
  Px = point->x;
  if ( __fdtest(&Px) > 0 )
    return 0;
  v10 = v4->y;
  if ( __fdtest(&v10) > 0 )
    return 0;
  v11 = v4->z;
  if ( __fdtest(&v11) > 0 )
    return 0;
  result.point = v4;
  result.bestDist = (float *)&point;
  point = (const vec3f *)1259902591;
  result.foundIndex = &foundIndex;
  result.c = &c;
  v5 = (Spline::closestPointIndex::__l9::<lambda_161ed80abd734302ca18e728b7dd1192>)_mm_loadu_si128((const __m128i *)&result);
  foundIndex = 0;
  v7 = this->points._Mylast;
  c = 0;
  std::for_each<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<SplinePoint>>>,_lambda_161ed80abd734302ca18e728b7dd1192_>(
    &result,
    (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<SplinePoint> > >)this->points._Myfirst,
    (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<SplinePoint> > >)v7,
    v5);
  if ( distance )
    *distance = fsqrt(*(float *)&point);
  return foundIndex;
}
unsigned int Spline::closestPointIndexWithBounds(Spline *this, const vec3f *point, const std::vector<SplineIndexBound> *bounds, float *distance)
{
  const vec3f *v5; // esi
  __m128i v6; // xmm0
  SplinePoint *v8; // [esp-Ch] [ebp-60h]
  SplinePoint *v9; // [esp-8h] [ebp-5Ch]
  float bestDist; // [esp+Ch] [ebp-48h] BYREF
  unsigned int foundIndex; // [esp+10h] [ebp-44h] BYREF
  float Px; // [esp+14h] [ebp-40h] BYREF
  float v13; // [esp+18h] [ebp-3Ch] BYREF
  float v14; // [esp+1Ch] [ebp-38h] BYREF
  unsigned int c; // [esp+20h] [ebp-34h] BYREF
  __m128i v16; // [esp+24h] [ebp-30h] BYREF
  __int64 v17; // [esp+34h] [ebp-20h]
  Spline::closestPointIndexWithBounds::__l19::<lambda_b7c327d54d0345e9ac0b908de0735019> _Func; // [esp+3Ch] [ebp-18h] BYREF

  if ( !(this->points._Mylast - this->points._Myfirst) )
    return 0;
  v5 = point;
  Px = point->x;
  if ( __fdtest(&Px) > 0 )
    return 0;
  v13 = v5->y;
  if ( __fdtest(&v13) > 0 )
    return 0;
  v14 = v5->z;
  if ( __fdtest(&v14) > 0 )
    return 0;
  v16.m128i_i32[3] = (int)v5;
  v16.m128i_i32[0] = (int)&point;
  *(__int64 *)((char *)v16.m128i_i64 + 4) = __PAIR64__(&c, (unsigned int)bounds);
  v6 = _mm_loadu_si128(&v16);
  LODWORD(v17) = &bestDist;
  HIDWORD(v17) = &foundIndex;
  v9 = this->points._Mylast;
  *(__m128i *)&_Func.is_in_bounds = v6;
  bestDist = 9999999.0;
  v8 = this->points._Myfirst;
  foundIndex = 0;
  c = 0;
  *(_QWORD *)&_Func.bestDist = v17;
  std::_For_each<SplinePoint const *,_lambda_b7c327d54d0345e9ac0b908de0735019_>(v8, v9, &_Func);
  if ( distance )
    *distance = fsqrt(bestDist);
  return foundIndex;
}
std::vector<unsigned int> *Spline::closestPointIndicesFlat(Spline *this, std::vector<unsigned int> *result, const vec3f *point, unsigned int numberOfNeigbours, float *distance)
{
  ComparablePoint *v5; // ebp
  ComparablePoint *v6; // esi
  ComparablePoint *v7; // ebx
  float v8; // eax
  int v9; // ecx
  unsigned int v10; // edi
  const vec3f *v11; // ecx
  Spline *v12; // edx
  __m128 v13; // xmm1
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  int v17; // edi
  int v18; // eax
  unsigned int v19; // edx
  unsigned int *v20; // edi
  unsigned int *v21; // ecx
  unsigned int *v22; // edx
  signed int v23; // ebx
  signed int v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // edx
  unsigned int *v27; // ecx
  unsigned int v28; // eax
  unsigned int *v29; // edx
  signed int v30; // ecx
  unsigned int v31; // edx
  unsigned int v32; // edx
  unsigned int _Count; // [esp+18h] [ebp-48h]
  unsigned int v36; // [esp+20h] [ebp-40h] BYREF
  int v37; // [esp+24h] [ebp-3Ch]
  std::vector<ComparablePoint> closestPoints; // [esp+28h] [ebp-38h] BYREF
  vec3f myPoint; // [esp+34h] [ebp-2Ch]
  SplinePoint p; // [esp+40h] [ebp-20h]
  int v41; // [esp+5Ch] [ebp-4h]
  const vec3f *pointa; // [esp+68h] [ebp+8h]
  const vec3f *pointb; // [esp+68h] [ebp+8h]

  v5 = 0;
  v6 = 0;
  v7 = 0;
  closestPoints._Myfirst = 0;
  closestPoints._Mylast = 0;
  closestPoints._Myend = 0;
  v8 = point->z;
  *(_QWORD *)&myPoint.x = *(_QWORD *)&point->x;
  myPoint.z = v8;
  v9 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
  v10 = 0;
  v41 = 1;
  _Count = 0;
  if ( v9 / 20 )
  {
    v11 = 0;
    pointa = 0;
    do
    {
      v12 = this;
      v13 = (__m128)_mm_loadu_si128((const __m128i *)((char *)this->points._Myfirst + (unsigned int)v11));
      p.tag = *(int *)((char *)&this->points._Myfirst->tag + (unsigned int)v11);
      v14 = myPoint.x - v13.m128_f32[0];
      v13.m128_f32[0] = _mm_shuffle_ps(v13, v13, 170).m128_f32[0];
      v15 = (float)(v14 * v14) + (float)((float)(myPoint.z - v13.m128_f32[0]) * (float)(myPoint.z - v13.m128_f32[0]));
      if ( v15 == 0.0 )
        v16 = 0.0;
      else
        v16 = fsqrt(v15);
      v36 = v10;
      v37 = LODWORD(v16);
      if ( &v36 >= (unsigned int *)v6 || v5 > (ComparablePoint *)&v36 )
      {
        if ( v6 == v7 )
        {
          std::vector<ComparablePoint>::_Reserve(&closestPoints, 1u);
          v7 = closestPoints._Myend;
          v6 = closestPoints._Mylast;
          v5 = closestPoints._Myfirst;
          v12 = this;
          v11 = pointa;
        }
        if ( v6 )
        {
          v18 = v37;
          v6->index = v10;
          LODWORD(v6->distance) = v18;
        }
      }
      else
      {
        v17 = ((char *)&v36 - (char *)v5) >> 3;
        if ( v6 == v7 )
        {
          std::vector<ComparablePoint>::_Reserve(&closestPoints, 1u);
          v7 = closestPoints._Myend;
          v6 = closestPoints._Mylast;
          v5 = closestPoints._Myfirst;
          v12 = this;
          v11 = pointa;
        }
        if ( v6 )
        {
          v6->index = v5[v17].index;
          v6->distance = v5[v17].distance;
        }
        v10 = _Count;
      }
      pointa = (const vec3f *)((char *)v11 + 20);
      ++v10;
      ++v6;
      v11 = (const vec3f *)((char *)v11 + 20);
      v19 = (int)((unsigned __int64)(1717986919i64 * ((char *)v12->points._Mylast - (char *)v12->points._Myfirst)) >> 32) >> 3;
      closestPoints._Mylast = v6;
      _Count = v10;
    }
    while ( v10 < v19 + (v19 >> 31) );
  }
  std::_Sort<ComparablePoint *,int,std::less<void>>(v5, v6, v6 - v5, 0);
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  pointb = 0;
  if ( numberOfNeigbours )
  {
    v20 = &v5->index;
    do
    {
      v21 = result->_Mylast;
      if ( v20 >= v21 || result->_Myfirst > v20 )
      {
        v29 = result->_Myend;
        if ( v21 == v29 && !(v29 - v21) )
        {
          v30 = v21 - result->_Myfirst;
          if ( v30 == 0x3FFFFFFF )
LABEL_49:
            std::_Xlength_error("vector<T> too long");
          v31 = v29 - result->_Myfirst;
          if ( 0x3FFFFFFF - (v31 >> 1) >= v31 )
            v32 = (v31 >> 1) + v31;
          else
            v32 = 0;
          if ( v32 < v30 + 1 )
            v32 = v30 + 1;
          std::vector<ID3D11ShaderResourceView *>::_Reallocate((std::vector<TyreThermalPatch *> *)result, v32);
        }
        v27 = result->_Mylast;
        if ( !v27 )
          goto LABEL_45;
        v28 = *v20;
      }
      else
      {
        v22 = result->_Myend;
        v23 = v20 - result->_Myfirst;
        if ( v21 == v22 && !(v22 - v21) )
        {
          v24 = v21 - result->_Myfirst;
          if ( v24 == 0x3FFFFFFF )
            goto LABEL_49;
          v25 = v22 - result->_Myfirst;
          if ( 0x3FFFFFFF - (v25 >> 1) >= v25 )
            v26 = (v25 >> 1) + v25;
          else
            v26 = 0;
          if ( v26 < v24 + 1 )
            v26 = v24 + 1;
          std::vector<ID3D11ShaderResourceView *>::_Reallocate((std::vector<TyreThermalPatch *> *)result, v26);
        }
        v27 = result->_Mylast;
        if ( !v27 )
          goto LABEL_45;
        v28 = result->_Myfirst[v23];
      }
      *v27 = v28;
LABEL_45:
      v20 += 2;
      ++result->_Mylast;
      pointb = (const vec3f *)((char *)pointb + 1);
    }
    while ( (unsigned int)pointb < numberOfNeigbours );
  }
  if ( v5 )
    operator delete(v5);
  return result;
}
vec3f *Spline::getPointSmooth(Spline *this, vec3f *result, float v)
{
  float v3; // xmm2_4
  float v4; // xmm2_4
  SplinePoint *v5; // esi
  float v6; // xmm0_4
  int v7; // edi
  float v8; // xmm0_4
  int v9; // eax
  int v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  vec3f *v14; // eax
  float v15; // xmm2_4
  float va; // [esp+8h] [ebp+8h]

  if ( v <= 1.0 )
  {
    v3 = 0.0;
    if ( v >= 0.0 )
      v3 = v;
  }
  else
  {
    v3 = FLOAT_1_0;
  }
  v4 = v3 * 0.99900001;
  v5 = this->points._Myfirst;
  v6 = (float)(((int)((unsigned __int64)(1717986919i64 * ((char *)this->points._Mylast - (char *)v5)) >> 32) >> 3)
             - 1
             + ((unsigned int)((unsigned __int64)(1717986919i64 * ((char *)this->points._Mylast - (char *)v5)) >> 32) >> 31));
  v7 = (int)(float)(v6 * v4);
  v8 = (float)(unsigned int)(this->points._Mylast - v5);
  va = (float)(v4 - (float)((float)v7 / v8)) / (float)(1.0 / v8);
  v9 = Spline::wrapIndex(this, v7 + 1);
  v10 = v9;
  v11 = v5[v7].point.z;
  v12 = v5[v9].point.z;
  v13 = (float)((float)(v5[v9].point.x - v5[v7].point.x) * va) + v5[v7].point.x;
  v14 = result;
  v15 = (float)((float)(v5[v10].point.y - v5[v7].point.y) * va) + v5[v7].point.y;
  result->x = v13;
  result->y = v15;
  result->z = (float)((float)(v12 - v11) * va) + v11;
  return v14;
}
vec3f *Spline::getSplineDirection(Spline *this, vec3f *result, const vec3f *point)
{
  vec3f *v4; // eax
  unsigned int v5; // esi
  int v6; // eax
  SplinePoint *v7; // edx
  int v8; // eax
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  vec3f dir; // [esp+4h] [ebp-Ch]

  if ( (unsigned int)(this->points._Mylast - this->points._Myfirst) >= 2 )
  {
    v5 = Spline::closestPointIndex(this, point, 0);
    v6 = Spline::wrapIndex(this, v5 + 1);
    if ( v6 == v5 )
      --v5;
    v7 = this->points._Myfirst;
    v8 = v6;
    v9 = v7[v8].point.x - v7[v5].point.x;
    v10 = v7[v8].point.y - v7[v5].point.y;
    v11 = v7[v8].point.z - v7[v5].point.z;
    *(_QWORD *)&dir.x = __PAIR64__(LODWORD(v10), LODWORD(v9));
    dir.z = v11;
    v12 = fsqrt((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11));
    if ( v12 != 0.0 )
    {
      dir.x = (float)(1.0 / v12) * v9;
      dir.y = (float)(1.0 / v12) * v10;
      dir.z = (float)(1.0 / v12) * v11;
    }
    v4 = result;
    *result = dir;
  }
  else
  {
    v4 = result;
    result->x = 0.0;
    result->y = 0.0;
    result->z = 0.0;
  }
  return v4;
}
bool Spline::isClosed(Spline *this)
{
  bool result; // al
  SplinePoint *v3; // ecx
  SplinePoint *v4; // eax
  float v5; // xmm2_4

  result = 0;
  if ( (unsigned int)(this->points._Mylast - this->points._Myfirst) >= 2 )
  {
    v3 = this->points._Myfirst;
    v4 = this->points._Mylast - 1;
    v5 = (float)((float)((float)(v4->point.y - v3->point.y) * (float)(v4->point.y - v3->point.y))
               + (float)((float)(v4->point.x - v3->point.x) * (float)(v4->point.x - v3->point.x)))
       + (float)((float)(v4->point.z - v3->point.z) * (float)(v4->point.z - v3->point.z));
    if ( v5 == 0.0 || fsqrt(v5) <= 75.0 )
      result = 1;
  }
  return result;
}
double Spline::length(Spline *this)
{
  double result; // st7

  if ( this->points._Myfirst == this->points._Mylast )
    result = 0.0;
  else
    result = this->m_length;
  return result;
}
void Spline::loadFromCSV(Spline *this, std::wstring filename)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  _DWORD *v5; // ecx
  bool i; // bl
  char *v7; // ecx
  wchar_t v8; // ax
  int v9; // eax
  std::wstring *v10; // eax
  int v11; // ecx
  SplinePoint *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  int v15; // xmm1_4
  const wchar_t *v16; // [esp-10h] [ebp-134h]
  wchar_t _Ptr[2]; // [esp+14h] [ebp-110h] BYREF
  float z; // [esp+18h] [ebp-10Ch] BYREF
  float y; // [esp+1Ch] [ebp-108h] BYREF
  unsigned int x; // [esp+20h] [ebp-104h] BYREF
  unsigned __int64 x_4; // [esp+24h] [ebp-100h]
  SplinePoint _Val; // [esp+2Ch] [ebp-F8h] BYREF
  int v23; // [esp+40h] [ebp-E4h]
  std::wifstream file; // [esp+44h] [ebp-E0h] BYREF
  std::wstring line; // [esp+FCh] [ebp-28h] BYREF
  int v26; // [esp+120h] [ebp-4h]

  v3 = &filename;
  v26 = 0;
  if ( filename._Myres >= 8 )
    v3 = (std::wstring *)filename._Bx._Ptr;
  _printf("LOADING CSV: %S\n", v3->_Bx._Buf);
  v4 = Path::getPlatformSpecificPath(&line, &filename);
  LOBYTE(v26) = 1;
  std::wifstream::wifstream(&file, v4, 1, 64, 1);
  LOBYTE(v26) = 3;
  if ( line._Myres >= 8 )
    operator delete(line._Bx._Ptr);
  v5 = (_DWORD *)(*(_DWORD *)file.gap0 + 4);
  *(_DWORD *)_Ptr = 0;
  for ( i = 0;
        (*((_BYTE *)&file._Chcount + *(_DWORD *)(*(_DWORD *)file.gap0 + 4) + 4) & 1) == 0;
        v5 = (_DWORD *)(*(_DWORD *)file.gap0 + 4) )
  {
    line._Myres = 7;
    line._Mysize = 0;
    line._Bx._Buf[0] = 0;
    v7 = &file.gap0[*v5];
    LOBYTE(v26) = 4;
    v8 = std::wios::widen(v7, 10);
    std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&file, &line, v8);
    if ( !*(_DWORD *)_Ptr )
    {
      *(_DWORD *)_Ptr = 44;
      v9 = std::wstring::find(&line, _Ptr, 0, 1u);
      *(_DWORD *)_Ptr = 1;
      i = v9 == -1;
    }
    v10 = &line;
    if ( i )
      v16 = L"%f %f %f\n";
    else
      v16 = L"%f,%f,%f\n";
    if ( line._Myres >= 8 )
      v10 = (std::wstring *)line._Bx._Ptr;
    _swscanf_s(v10->_Bx._Buf, v16, &x, &y, &z);
    v11 = (char *)this->points._Mylast - (char *)this->points._Myfirst;
    x_4 = __PAIR64__(LODWORD(y), x);
    _Val.point.x = z;
    if ( v11 / 20 )
    {
      v12 = this->points._Mylast;
      v13 = 0.0;
      v14 = (float)((float)((float)(y - v12[-1].point.y) * (float)(y - v12[-1].point.y))
                  + (float)((float)(*(float *)&x - v12[-1].point.x) * (float)(*(float *)&x - v12[-1].point.x)))
          + (float)((float)(z - v12[-1].point.z) * (float)(z - v12[-1].point.z));
      if ( v14 != 0.0 )
        v13 = fsqrt(v14);
      this->m_length = this->m_length + v13;
    }
    else
    {
      this->m_length = 0.0;
    }
    v15 = LODWORD(this->m_length);
    _Val.pointLength = _Val.point.x;
    *(_QWORD *)&_Val.point.y = x_4;
    _Val.tag = v15;
    v23 = 0;
    std::vector<SplinePoint>::push_back(&this->points, (SplinePoint *)&_Val.point.y);
    LOBYTE(v26) = 3;
    if ( line._Myres >= 8 )
      operator delete(line._Bx._Ptr);
  }
  std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&file.gap64[12]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file.gap64[12]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
vec3f *Spline::pointAt(Spline *this, vec3f *result, unsigned int index)
{
  vec3f *v4; // eax
  float v5; // ecx

  v4 = result;
  if ( index >= this->points._Mylast - this->points._Myfirst )
  {
    result->x = 0.0;
    result->y = 0.0;
    result->z = 0.0;
  }
  else
  {
    v5 = this->points._Myfirst[index].point.z;
    *(_QWORD *)&result->x = *(_QWORD *)&this->points._Myfirst[index].point.x;
    result->z = v5;
  }
  return v4;
}
int Spline::pointsCount(Spline *this)
{
  return this->points._Mylast - this->points._Myfirst;
}
void Spline::reverse(Spline *this)
{
  std::_Reverse<SplinePoint *>(this->points._Myfirst, this->points._Mylast);
}
void Spline::setPointAt(Spline *this, unsigned int index, vec3f point)
{
  if ( index < this->points._Mylast - this->points._Myfirst )
    this->points._Myfirst[index].point = point;
}
SplinePoint *Spline::splinePointAt(Spline *this, SplinePoint *result, unsigned int index)
{
  SplinePoint *v4; // eax
  int v5; // ecx

  v4 = result;
  if ( index >= this->points._Mylast - this->points._Myfirst )
  {
    *(_QWORD *)&result->point.x = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64).m128_u64[0];
    result->point.z = 0.0;
    result->pointLength = 0.0;
    result->tag = 0;
  }
  else
  {
    v5 = this->points._Myfirst[index].tag;
    *(__m128i *)&result->point.x = _mm_loadu_si128((const __m128i *)&this->points._Myfirst[index]);
    result->tag = v5;
  }
  return v4;
}
int Spline::tagAt(Spline *this, unsigned int index)
{
  int result; // eax

  if ( index >= this->points._Mylast - this->points._Myfirst )
    result = 0;
  else
    result = this->points._Myfirst[index].tag;
  return result;
}
int Spline::wrapIndex(Spline *this, int index)
{
  SplinePoint *v3; // eax
  SplinePoint *v4; // ecx
  float v5; // xmm2_4
  int v6; // edi
  int v7; // eax
  int result; // eax
  float indexa; // [esp+Ch] [ebp+4h]

  if ( (unsigned int)(this->points._Mylast - this->points._Myfirst) >= 2
    && ((v3 = this->points._Mylast,
         v4 = this->points._Myfirst,
         v5 = (float)((float)((float)(v3[-1].point.y - v4->point.y) * (float)(v3[-1].point.y - v4->point.y))
                    + (float)((float)(v3[-1].point.x - v4->point.x) * (float)(v3[-1].point.x - v4->point.x)))
            + (float)((float)(v3[-1].point.z - v4->point.z) * (float)(v3[-1].point.z - v4->point.z)),
         v5 == 0.0)
     || fsqrt(v5) <= 75.0) )
  {
    v6 = index;
    v7 = this->points._Mylast - this->points._Myfirst;
    if ( index >= 0 )
    {
      if ( index >= v7 )
        v6 = index - (this->points._Mylast - this->points._Myfirst);
      result = v6;
    }
    else
    {
      result = index + v7;
    }
  }
  else
  {
    indexa = Spline::boundInsideSpline(this, (float)index);
    result = (int)indexa;
  }
  return result;
}
