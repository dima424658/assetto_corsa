#include "aispline.h
InterpolatingSpline *AISpline::getBaseSpline(AISpline *this)
{
  return &this->spline;
}
AISpline *AISpline::operator=(AISpline *this, const AISpline *__that)
{
  std::wstring *v3; // ecx

  v3 = &this->filename;
  this->lapTime = __that->lapTime;
  if ( v3 != &__that->filename )
    std::wstring::assign(v3, &__that->filename, 0, 0xFFFFFFFF);
  this->version = __that->version;
  std::vector<AIStraightData>::operator=(&this->straights, &__that->straights);
  std::vector<SplinePoint>::operator=(&this->spline.points, &__that->spline.points);
  this->spline.m_length = __that->spline.m_length;
  this->spline.m_closed = __that->spline.m_closed;
  std::vector<std::vector<GridElement>>::operator=(&this->spline.grid, &__that->spline.grid);
  this->spline.gridData = __that->spline.gridData;
  std::vector<CubicSpline<float,vec3f>::Element,std::allocator<CubicSpline<float,vec3f>::Element>>::operator=(
    &this->spline.cubicSpline.mElements,
    &__that->spline.cubicSpline.mElements);
  this->spline.isSplineReady = __that->spline.isSplineReady;
  this->spline.interpolationMode = __that->spline.interpolationMode;
  std::vector<AISplinePayload>::operator=(&this->payloads, &__that->payloads);
  this->straightFactor = __that->straightFactor;
  return this;
}
void AISpline::AISpline(AISpline *this)
{
  this->__vftable = (AISpline_vtbl *)&AISpline::`vftable';
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  this->straights._Myfirst = 0;
  this->straights._Mylast = 0;
  this->straights._Myend = 0;
  InterpolatingSpline::InterpolatingSpline(&this->spline);
  this->payloads._Myfirst = 0;
  this->payloads._Mylast = 0;
  this->payloads._Myend = 0;
  this->straightFactor = -1.0;
  this->lapTime = 0;
  this->version = 0;
  this->spline.interpolationMode = eCatmulRom;
}
void AISpline::~AISpline(AISpline *this)
{
  AISplinePayload *v2; // eax

  this->__vftable = (AISpline_vtbl *)&AISpline::`vftable';
  v2 = this->payloads._Myfirst;
  if ( v2 )
  {
    operator delete(v2);
    this->payloads._Myfirst = 0;
    this->payloads._Mylast = 0;
    this->payloads._Myend = 0;
  }
  InterpolatingSpline::~InterpolatingSpline(&this->spline);
  if ( this->straights._Myfirst )
  {
    operator delete(this->straights._Myfirst);
    this->straights._Myfirst = 0;
    this->straights._Mylast = 0;
    this->straights._Myend = 0;
  }
  if ( this->filename._Myres >= 8 )
    operator delete(this->filename._Bx._Ptr);
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
}
AISpline *AISpline::`scalar deleting destructor'(AISpline *this, unsigned int a2)
{
  AISpline::~AISpline(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void AISpline::addPoint(AISpline *this, const vec3f *point, const AISplinePayload *payload)
{
  int v4; // eax

  v4 = Spline::pointsCount(&this->spline);
  InterpolatingSpline::addPoint(&this->spline, point, v4);
  std::vector<AISplinePayload>::push_back(&this->payloads, payload);
}
void AISpline::adjustPayloadEndpoint(AISpline *this, const int numberOfPoints)
{
  AISplinePayload *v3; // esi
  int v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm7_4
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  unsigned int v9; // esi
  AISplinePayload *v10; // edx
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // ecx
  __m128i v15; // xmm6
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  AISplinePayload *v21; // [esp+10h] [ebp-70h]
  int v22; // [esp+14h] [ebp-6Ch]
  float *v23; // [esp+18h] [ebp-68h]
  AISplinePayload pl; // [esp+2Ch] [ebp-54h] BYREF

  v3 = this->payloads._Myfirst;
  v4 = -numberOfPoints;
  v23 = &v3[this->payloads._Mylast - v3 - numberOfPoints].speedMS;
  v21 = &v3[numberOfPoints];
  if ( -numberOfPoints < numberOfPoints )
  {
    v22 = 0;
    v5 = 1.0 / (float)((float)numberOfPoints * 2.0);
    do
    {
      v6 = (float)v22 * v5;
      v7 = (__m128)LODWORD(v21->normal.x);
      v8 = (__m128)LODWORD(v21->normal.y);
      v9 = (v4 + this->payloads._Mylast - this->payloads._Myfirst)
         % (unsigned int)(this->payloads._Mylast - this->payloads._Myfirst);
      v10 = this->payloads._Myfirst;
      v11 = v23[6];
      v12 = v23[7];
      v13 = v23[8];
      v14 = v10[v9].compression;
      v15 = _mm_loadu_si128((const __m128i *)&v10[v9].grip);
      *(__m128i *)&pl.speedMS = _mm_loadu_si128((const __m128i *)&v10[v9]);
      *(__m128i *)&pl.camber = _mm_loadu_si128((const __m128i *)&v10[v9].camber);
      v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] - v11) * v6) + v11;
      *(__m128i *)&pl.normal.z = _mm_loadu_si128((const __m128i *)&v10[v9].normal.z);
      v8.m128_f32[0] = (float)((float)(v8.m128_f32[0] - v12) * v6) + v12;
      *(__m128i *)&pl.length = _mm_loadu_si128((const __m128i *)&v10[v9].length);
      v16 = v21->camber - v23[4];
      *(_QWORD *)&pl.normal.x = _mm_unpacklo_ps(v7, v8).m128_u64[0];
      pl.camber = (float)(v16 * v6) + v23[4];
      pl.direction = (float)((float)(v21->direction - v23[5]) * v6) + v23[5];
      pl.gas = (float)((float)(v21->gas - v23[13]) * v6) + v23[13];
      pl.length = (float)((float)(v21->length - v23[12]) * v6) + v23[12];
      v17 = v21->radius;
      pl.normal.z = (float)((float)(v21->normal.z - v13) * v6) + v13;
      v18 = (float)(v17 - v23[1]) * v6;
      ++v4;
      ++v22;
      v19 = *v23;
      pl.brake = 0.0;
      pl.radius = v18 + v23[1];
      pl.sides[0] = (float)((float)(v21->sides[0] - v23[2]) * v6) + v23[2];
      pl.sides[1] = (float)((float)(v21->sides[1] - v23[3]) * v6) + v23[3];
      v20 = (float)((float)(v21->speedMS - v19) * v6) + v19;
      v5 = 1.0 / (float)((float)numberOfPoints * 2.0);
      pl.speedMS = v20;
      *(__m128i *)&v10[v9].speedMS = _mm_loadu_si128((const __m128i *)&pl);
      *(__m128i *)&v10[v9].camber = _mm_loadu_si128((const __m128i *)&pl.camber);
      *(__m128i *)&v10[v9].normal.z = _mm_loadu_si128((const __m128i *)&pl.normal.z);
      *(__m128i *)&v10[v9].length = _mm_loadu_si128((const __m128i *)&pl.length);
      *(__m128i *)&v10[v9].grip = v15;
      v10[v9].compression = v14;
    }
    while ( v4 < numberOfPoints );
  }
}
void AISpline::buildGrid(AISpline *this)
{
  InterpolatingSpline::buildGrid(&this->spline);
}
void __userpurge AISpline::buildSides(AISpline *this@<ecx>, __m128 a2@<xmm0>, IRayTrackCollisionProvider *track)
{
  AISpline *v3; // ebx
  InterpolatingSpline *v4; // edi
  std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *v5; // eax
  unsigned int v6; // esi
  float v7; // ebx
  IRayTrackCollisionProvider_vtbl *v8; // eax
  int v9; // esi
  unsigned int v10; // ecx
  float v11; // xmm4_4
  float v12; // xmm3_4
  __m128 v13; // xmm2
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  IRayTrackCollisionProvider_vtbl *v24; // eax
  IRayTrackCollisionProvider_vtbl *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm2_4
  float *v28; // eax
  IRayTrackCollisionProvider_vtbl *v29; // eax
  IRayTrackCollisionProvider_vtbl *v30; // eax
  float v31; // xmm2_4
  float v32; // xmm3_4
  float *v33; // eax
  unsigned int v34; // eax
  float v35; // [esp+48h] [ebp-E8h]
  float v36; // [esp+48h] [ebp-E8h]
  float sider; // [esp+4Ch] [ebp-E4h] BYREF
  float v38; // [esp+50h] [ebp-E0h]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > > v39; // [esp+54h] [ebp-DCh] BYREF
  unsigned int index; // [esp+58h] [ebp-D8h]
  vec3f result; // [esp+5Ch] [ebp-D4h] BYREF
  std::map<unsigned int,bool> track_surfaces; // [esp+68h] [ebp-C8h] BYREF
  float v43; // [esp+70h] [ebp-C0h]
  float v44; // [esp+74h] [ebp-BCh]
  float v45; // [esp+78h] [ebp-B8h] BYREF
  float v46; // [esp+7Ch] [ebp-B4h]
  __int64 v47; // [esp+80h] [ebp-B0h] BYREF
  float v48; // [esp+88h] [ebp-A8h]
  float v49; // [esp+8Ch] [ebp-A4h]
  vec3f point; // [esp+90h] [ebp-A0h] BYREF
  float v51; // [esp+9Ch] [ebp-94h] BYREF
  float v52; // [esp+A0h] [ebp-90h]
  float v53; // [esp+A4h] [ebp-8Ch]
  int v54; // [esp+A8h] [ebp-88h] BYREF
  int v55; // [esp+ACh] [ebp-84h]
  int v56; // [esp+B0h] [ebp-80h]
  RayCastResult res; // [esp+B4h] [ebp-7Ch] BYREF
  float v58; // [esp+D8h] [ebp-58h]
  float v59; // [esp+DCh] [ebp-54h]
  int v60; // [esp+E0h] [ebp-50h] BYREF
  RayCastResult cast_result; // [esp+E4h] [ebp-4Ch] BYREF
  vec3f prev_point; // [esp+108h] [ebp-28h] BYREF
  float v63; // [esp+11Ch] [ebp-14h]
  int v64; // [esp+12Ch] [ebp-4h]

  v3 = this;
  v38 = *(float *)&this;
  v4 = &this->spline;
  LODWORD(sider) = &this->spline;
  if ( (unsigned int)Spline::pointsCount(&this->spline) >= 2 )
  {
    _printf("Building sides\n");
    track_surfaces._Myhead = 0;
    track_surfaces._Mysize = 0;
    std::_Tree_alloc<0,std::_Tree_base_types<std::pair<ID3D11View * const,PPFX::IGPUSurface *>>>::_Buyheadnode(&track_surfaces);
    track_surfaces._Myhead = v5;
    v64 = 0;
    v6 = 1;
    if ( (unsigned int)Spline::pointsCount(v4) > 1 )
    {
      v7 = sider;
      do
      {
        Spline::pointAt((Spline *)LODWORD(v7), &point, v6);
        v8 = track->__vftable;
        *(_OWORD *)&res.pos.x = 0i64;
        HIDWORD(v47) = LODWORD(point.x);
        res.normal.y = 0.0;
        v48 = point.y + 2.0;
        a2 = (__m128)LODWORD(point.z);
        res.normal.z = 0.0;
        res.surfaceDef = 0;
        res.hasHit = 0;
        res.collisionObject = 0;
        v45 = 0.0;
        v46 = -1.0;
        LODWORD(v47) = 0;
        v49 = point.z;
        ((void (*)(IRayTrackCollisionProvider *, char *, float *, RayCastResult *, int))v8->rayCast)(
          track,
          (char *)&v47 + 4,
          &v45,
          &res,
          1120403456);
        if ( res.hasHit )
        {
          sider = *(float *)&res.collisionObject;
          *std::map<unsigned int,bool>::operator[](&track_surfaces, (const unsigned int *)&sider) = 1;
        }
        ++v6;
      }
      while ( v6 < Spline::pointsCount((Spline *)LODWORD(v7)) );
      v3 = (AISpline *)LODWORD(v38);
    }
    index = 1;
    if ( (unsigned int)Spline::pointsCount(&v3->spline) > 1 )
    {
      v9 = 1;
      v10 = 1;
      do
      {
        Spline::pointAt(&v3->spline, &prev_point, v10 - 1);
        Spline::pointAt(&v3->spline, &result, index);
        v11 = 0.0;
        v12 = result.x - prev_point.x;
        v13 = (__m128)LODWORD(result.y);
        v13.m128_f32[0] = result.y - prev_point.y;
        a2.m128_f32[0] = result.x - prev_point.x;
        *(_QWORD *)&point.x = _mm_unpacklo_ps(a2, v13).m128_u64[0];
        v63 = result.z - prev_point.z;
        point.z = result.z - prev_point.z;
        v14 = fsqrt((float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v63 * v63));
        if ( v14 == 0.0 )
        {
          v18 = point.z;
          v17 = point.y;
          v19 = point.x;
        }
        else
        {
          v15 = 1.0 / v14;
          v16 = 1.0 / v14;
          v17 = (float)(1.0 / v14) * point.y;
          v18 = v15 * point.z;
          v19 = v16 * v12;
        }
        v20 = v17 * 0.0;
        v43 = 0.0;
        v21 = v19 - v20;
        v22 = v20 - v18;
        v38 = v21;
        v44 = v22;
        v23 = fsqrt((float)(v21 * v21) + (float)(v22 * v22));
        if ( v23 != 0.0 )
        {
          v21 = v21 * (float)(1.0 / v23);
          v22 = v22 * (float)(1.0 / v23);
          v38 = v21;
          v11 = (float)(1.0 / v23) * 0.0;
          v44 = v22;
          v43 = v11;
        }
        v24 = track->__vftable;
        *(_OWORD *)&res.pos.x = 0i64;
        v35 = FLOAT_0_050000001;
        sider = FLOAT_0_050000001;
        res.normal.y = 0.0;
        res.normal.z = 0.0;
        res.surfaceDef = 0;
        res.hasHit = 0;
        res.collisionObject = 0;
        v58 = v22 * 0.050000001;
        v59 = v11 * 0.050000001;
        *(float *)&v39._Ptr = v21 * 0.050000001;
        v54 = 0;
        v55 = -1082130432;
        v56 = 0;
        v51 = result.x - (float)(v22 * 0.050000001);
        v52 = (float)(result.y - (float)(v11 * 0.050000001)) + 20.0;
        v53 = result.z - (float)(v21 * 0.050000001);
        ((void (*)(IRayTrackCollisionProvider *, float *, int *, RayCastResult *, int))v24->rayCast)(
          track,
          &v51,
          &v54,
          &res,
          1120403456);
        if ( res.hasHit )
        {
          do
          {
            if ( !res.surfaceDef->isValidTrack )
            {
              v28 = (float *)&v60;
              v60 = 1065353216;
              if ( v35 >= 1.0 )
                v28 = &sider;
              v3->payloads._Myfirst[v9].sides[0] = *v28;
              goto LABEL_26;
            }
            if ( v35 > 100.0 )
            {
              _printf("SEARCHING LEFT OVER 100m, bailing out\n");
              goto LABEL_26;
            }
            v25 = track->__vftable;
            v26 = v44 * (float)(v35 + 0.050000001);
            v27 = v38 * (float)(v35 + 0.050000001);
            v35 = v35 + 0.050000001;
            sider = v35;
            v54 = 0;
            v55 = -1082130432;
            v56 = 0;
            v51 = result.x - v26;
            v52 = (float)(result.y - (float)(v35 * v43)) + 20.0;
            v53 = result.z - v27;
            ((void (*)(IRayTrackCollisionProvider *, float *, int *, RayCastResult *, int))v25->rayCast)(
              track,
              &v51,
              &v54,
              &res,
              1120403456);
          }
          while ( res.hasHit );
          if ( v35 <= 0.1 )
            goto LABEL_25;
          v3->payloads._Myfirst[v9].sides[0] = v35;
        }
        else
        {
LABEL_25:
          v3->payloads._Myfirst[v9].sides[0] = 4.0;
        }
LABEL_26:
        v29 = track->__vftable;
        v36 = FLOAT_0_050000001;
        sider = FLOAT_0_050000001;
        a2 = 0i64;
        cast_result.normal.y = 0.0;
        cast_result.normal.z = 0.0;
        *(_OWORD *)&cast_result.pos.x = 0i64;
        cast_result.surfaceDef = 0;
        cast_result.hasHit = 0;
        cast_result.collisionObject = 0;
        HIDWORD(v47) = 0;
        v48 = -1.0;
        v49 = 0.0;
        v45 = result.x + v58;
        v46 = (float)(result.y + v59) + 20.0;
        *(float *)&v47 = result.z + *(float *)&v39._Ptr;
        ((void (*)(IRayTrackCollisionProvider *, float *, char *, RayCastResult *, int))v29->rayCast)(
          track,
          &v45,
          (char *)&v47 + 4,
          &cast_result,
          1120403456);
        if ( cast_result.hasHit )
        {
          do
          {
            if ( !cast_result.surfaceDef->isValidTrack )
            {
              v33 = (float *)&v39;
              *(float *)&v39._Ptr = 0.2;
              if ( v36 >= 0.2 )
                v33 = &sider;
              v3->payloads._Myfirst[v9].sides[1] = *v33;
              goto LABEL_37;
            }
            a2 = (__m128)LODWORD(v36);
            if ( v36 > 100.0 )
            {
              _printf("SEARCHING RIGHT OVER 100m, bailing out\n");
              goto LABEL_37;
            }
            v30 = track->__vftable;
            v31 = (float)(v44 * (float)(v36 + 0.050000001)) + result.x;
            v32 = (float)((float)(v36 + 0.050000001) * v43) + result.y;
            v36 = v36 + 0.050000001;
            sider = v36;
            a2 = 0i64;
            cast_result.normal.y = 0.0;
            *(_OWORD *)&cast_result.pos.x = 0i64;
            cast_result.normal.z = 0.0;
            cast_result.surfaceDef = 0;
            cast_result.hasHit = 0;
            cast_result.collisionObject = 0;
            v48 = -1.0;
            v49 = 0.0;
            v45 = v31;
            v46 = v32 + 20.0;
            v47 = COERCE_UNSIGNED_INT((float)(v38 * v36) + result.z);
            ((void (*)(IRayTrackCollisionProvider *, float *, char *, RayCastResult *, int))v30->rayCast)(
              track,
              &v45,
              (char *)&v47 + 4,
              &cast_result,
              1120403456);
          }
          while ( cast_result.hasHit );
          a2 = (__m128)LODWORD(v36);
          if ( v36 <= 0.1 )
            goto LABEL_36;
          v3->payloads._Myfirst[v9].sides[1] = v36;
        }
        else
        {
LABEL_36:
          v3->payloads._Myfirst[v9].sides[1] = 4.0;
        }
LABEL_37:
        ++index;
        ++v9;
        v34 = Spline::pointsCount(&v3->spline);
        v10 = index;
      }
      while ( index < v34 );
    }
    std::_Tree<std::_Tmap_traits<unsigned int,bool,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,bool>>,0>>::erase(
      &track_surfaces,
      &v39,
      (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)track_surfaces._Myhead->_Left,
      (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)track_surfaces._Myhead);
    operator delete(track_surfaces._Myhead);
  }
}
void __userpurge AISpline::calculateNormals(AISpline *this@<ecx>, __m128 a2@<xmm0>, IRayTrackCollisionProvider *track)
{
  InterpolatingSpline *v4; // esi
  int v5; // eax
  unsigned int i; // edi
  float v7; // xmm3_4
  __m128 v8; // xmm2
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  int v18; // eax
  IRayTrackCollisionProvider_vtbl *v19; // eax
  float v20; // xmm3_4
  float v21; // xmm3_4
  IRayTrackCollisionProvider_vtbl *v22; // eax
  IRayTrackCollisionProvider_vtbl *v23; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  int v28; // eax
  int v29; // eax
  __m128i *v30; // ecx
  float v31; // eax
  AISplinePayload v32; // [esp+30h] [ebp-1ACh] BYREF
  float v33; // [esp+8Ch] [ebp-150h]
  vec3f v34; // [esp+90h] [ebp-14Ch] BYREF
  int v35; // [esp+9Ch] [ebp-140h] BYREF
  __int128 v36; // [esp+A0h] [ebp-13Ch]
  int v37; // [esp+B0h] [ebp-12Ch]
  __int128 v38[2]; // [esp+B4h] [ebp-128h] BYREF
  int v39; // [esp+D4h] [ebp-108h]
  int v40; // [esp+D8h] [ebp-104h]
  int v41; // [esp+DCh] [ebp-100h]
  int v42; // [esp+E0h] [ebp-FCh]
  int v43; // [esp+E4h] [ebp-F8h] BYREF
  __int64 v44; // [esp+E8h] [ebp-F4h]
  int v45[3]; // [esp+F0h] [ebp-ECh] BYREF
  int v46[3]; // [esp+FCh] [ebp-E0h] BYREF
  int v47; // [esp+108h] [ebp-D4h] BYREF
  _BYTE v48[24]; // [esp+10Ch] [ebp-D0h]
  int v49; // [esp+124h] [ebp-B8h]
  int v50; // [esp+128h] [ebp-B4h]
  int v51[3]; // [esp+12Ch] [ebp-B0h] BYREF
  int v52[3]; // [esp+138h] [ebp-A4h] BYREF
  int v53; // [esp+144h] [ebp-98h] BYREF
  __int64 v54; // [esp+148h] [ebp-94h]
  unsigned int v55; // [esp+150h] [ebp-8Ch]
  unsigned __int64 v56; // [esp+154h] [ebp-88h]
  float v57; // [esp+15Ch] [ebp-80h]
  vec3f result; // [esp+160h] [ebp-7Ch] BYREF
  AISpline *v59; // [esp+16Ch] [ebp-70h]
  IRayTrackCollisionProvider *v60; // [esp+170h] [ebp-6Ch]
  float v61; // [esp+174h] [ebp-68h]
  __m128i v62; // [esp+178h] [ebp-64h] BYREF
  float v63; // [esp+188h] [ebp-54h]
  DebugTimer v64; // [esp+18Ch] [ebp-50h] BYREF
  std::wstring iname; // [esp+1B4h] [ebp-28h] BYREF
  int v66; // [esp+1D8h] [ebp-4h]

  v59 = this;
  v60 = track;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"AISpline::calculateNormals", 0x1Au);
  v66 = 0;
  DebugTimer::DebugTimer(&v64, &iname);
  LOBYTE(v66) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  v4 = &this->spline;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  if ( (unsigned int)Spline::pointsCount(v4) >= 2 )
  {
    v5 = Spline::pointsCount(v4);
    Spline::pointAt(v4, &result, v5 - 1);
    for ( i = 0; i < Spline::pointsCount(v4); i = v55 )
    {
      Spline::pointAt(v4, (vec3f *)&v62, i);
      v7 = *(float *)v62.m128i_i32 - result.x;
      v8 = (__m128)v62.m128i_u32[1];
      v8.m128_f32[0] = *(float *)&v62.m128i_i32[1] - result.y;
      a2.m128_f32[0] = *(float *)v62.m128i_i32 - result.x;
      v56 = _mm_unpacklo_ps(a2, v8).m128_u64[0];
      v33 = *(float *)&v62.m128i_i32[2] - result.z;
      v57 = *(float *)&v62.m128i_i32[2] - result.z;
      v9 = *(float *)&v62.m128i_i32[2] - result.z;
      v10 = fsqrt((float)((float)(v7 * v7) + (float)(v8.m128_f32[0] * v8.m128_f32[0])) + (float)(v33 * v33));
      if ( v10 == 0.0 )
      {
        v13 = *((float *)&v56 + 1);
        v12 = *(float *)&v56;
      }
      else
      {
        v11 = 1.0 / v10;
        v12 = v7 * (float)(1.0 / v10);
        v13 = *((float *)&v56 + 1) * (float)(1.0 / v10);
        v9 = v9 * v11;
      }
      v14 = v13 * 0.0;
      v63 = 0.0;
      v15 = v12 - v14;
      v16 = v14 - v9;
      *(float *)&v62.m128i_i32[3] = v15;
      v61 = v16;
      v17 = fsqrt((float)(v16 * v16) + (float)(v15 * v15));
      if ( v17 != 0.0 )
      {
        v61 = v16 * (float)(1.0 / v17);
        v63 = (float)(1.0 / v17) * 0.0;
        *(float *)&v62.m128i_i32[3] = v15 * (float)(1.0 / v17);
      }
      *(_DWORD *)&v48[16] = 0;
      *(_DWORD *)&v48[20] = 0;
      v47 = 0;
      *(_OWORD *)v48 = 0i64;
      LOBYTE(v49) = 0;
      v50 = 0;
      v55 = i + 1;
      v18 = Spline::wrapIndex(v4, i + 1);
      Spline::pointAt(v4, &v34, v18);
      v19 = v60->__vftable;
      a2 = (__m128)v62.m128i_u32[2];
      v45[0] = 0;
      v45[1] = -1082130432;
      v45[2] = 0;
      v52[0] = v62.m128i_i32[0];
      *(float *)&v52[1] = *(float *)&v62.m128i_i32[1] + 2.0;
      v52[2] = v62.m128i_i32[2];
      ((void (__stdcall *)(int *, int *, int *, int))v19->rayCast)(v52, v45, &v47, 1120403456);
      if ( (_BYTE)v49 )
      {
        AISpline::payloadAtSplineIndex(v59, &v32, i);
        v20 = (float)((float)(v34.z - *(float *)&v62.m128i_i32[2]) * (float)(*(float *)v62.m128i_i32 - result.x))
            - (float)((float)(v34.x - *(float *)v62.m128i_i32) * (float)(*(float *)&v62.m128i_i32[2] - result.z));
        if ( v20 <= 0.0 )
        {
          if ( v20 >= 0.0 )
            v21 = 0.0;
          else
            v21 = FLOAT_N1_0;
        }
        else
        {
          v21 = FLOAT_1_0;
        }
        v38[1] = 0i64;
        v22 = v60->__vftable;
        v61 = v61 * v21;
        v63 = v21 * v63;
        *(float *)&v62.m128i_i32[3] = *(float *)&v62.m128i_i32[3] * v21;
        v39 = 0;
        v40 = 0;
        HIDWORD(v38[0]) = 0;
        LOBYTE(v41) = 0;
        v42 = 0;
        v53 = 0;
        v54 = 3212836864i64;
        *(float *)v51 = *(float *)v62.m128i_i32 + (float)(v61 * 0.60000002);
        *(float *)&v51[2] = *(float *)&v62.m128i_i32[2] + (float)(*(float *)&v62.m128i_i32[3] * 0.60000002);
        *(float *)&v51[1] = (float)(*(float *)&v62.m128i_i32[1] + 2.0) + (float)(v63 * 0.60000002);
        ((void (*)(IRayTrackCollisionProvider *, int *, int *, char *, int))v22->rayCast)(
          v60,
          v51,
          &v53,
          (char *)v38 + 12,
          1120403456);
        v36 = 0i64;
        v23 = v60->__vftable;
        v37 = 0;
        LODWORD(v38[0]) = 0;
        v35 = 0;
        BYTE4(v38[0]) = 0;
        DWORD2(v38[0]) = 0;
        v43 = 0;
        v44 = 3212836864i64;
        *(float *)v46 = *(float *)v62.m128i_i32 - (float)(v61 * 0.60000002);
        *(float *)&v46[1] = (float)(*(float *)&v62.m128i_i32[1] + 2.0) - (float)(v63 * 0.60000002);
        *(float *)&v46[2] = *(float *)&v62.m128i_i32[2] - (float)(*(float *)&v62.m128i_i32[3] * 0.60000002);
        ((void (*)(IRayTrackCollisionProvider *, int *, int *, int *, int))v23->rayCast)(
          v60,
          v46,
          &v43,
          &v35,
          1120403456);
        LODWORD(v63) = __libm_sse2_atanf().m128_u32[0];
        v24 = __libm_sse2_atanf().m128_f32[0];
        v25 = *(float *)(HIDWORD(v38[0]) + 136);
        v26 = (float)(v24 * 0.69999999) + (float)(v63 * 0.30000001);
        v27 = *(float *)(v35 + 136) - v25;
        v32.normal = *(vec3f *)&v48[12];
        v32.camber = v26;
        v32.grip = (float)(v27 * 0.89999998) + v25;
        v28 = Spline::wrapIndex(v4, i);
        v29 = Spline::tagAt(v4, v28);
        v30 = (__m128i *)&v59->payloads._Myfirst[v29];
        v31 = v32.compression;
        *v30 = _mm_loadu_si128((const __m128i *)&v32);
        v30[1] = _mm_loadu_si128((const __m128i *)&v32.camber);
        v30[2] = _mm_loadu_si128((const __m128i *)&v32.normal.z);
        v30[3] = _mm_loadu_si128((const __m128i *)&v32.length);
        v30[4] = _mm_loadu_si128((const __m128i *)&v32.grip);
        *(float *)v30[5].m128i_i32 = v31;
        a2 = (__m128)_mm_loadl_epi64(&v62);
        *(_QWORD *)&result.x = a2.m128_u64[0];
        LODWORD(result.z) = v62.m128i_i32[2];
      }
    }
  }
  v66 = -1;
  DebugTimer::~DebugTimer(&v64);
}
void AISpline::calculateRadius(AISpline *this, int range)
{
  InterpolatingSpline *v2; // esi
  unsigned int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // edi
  int v7; // eax
  vec3f *v8; // eax
  vec3f *v9; // eax
  vec3f *v10; // eax
  double v11; // xmm5_8
  double v12; // xmm4_8
  double v13; // xmm3_8
  double v14; // xmm6_8
  double v15; // xmm7_8
  double v16; // xmm1_8
  double v17; // xmm0_8
  unsigned int v18; // xmm0_4
  double v19; // xmm0_8
  double v20; // xmm0_8
  double v21; // xmm0_8
  double v22; // xmm0_8
  unsigned int v23; // edi
  float v24; // xmm6_4
  double v25; // xmm0_8
  float v26; // xmm0_4
  float v27; // xmm7_4
  double v28; // xmm1_8
  double v29; // xmm0_8
  float v30; // xmm0_4
  float v31; // xmm4_4
  double v32; // xmm3_8
  double v33; // xmm0_8
  float v34; // xmm0_4
  double v35; // xmm0_8
  float *v36; // eax
  int v37; // eax
  int v38; // eax
  __m128i v39; // xmm0
  AISplinePayload *v40; // ecx
  float v41; // eax
  bool v42; // cf
  float normalizedSplinePosition; // [esp+4h] [ebp-114h]
  float normalizedSplinePositiona; // [esp+4h] [ebp-114h]
  unsigned int resolution; // [esp+8h] [ebp-110h]
  vec3f v46; // [esp+14h] [ebp-104h] BYREF
  vec3f v47; // [esp+20h] [ebp-F8h] BYREF
  vec3f result; // [esp+2Ch] [ebp-ECh] BYREF
  AISplinePayload v49; // [esp+38h] [ebp-E0h] BYREF
  double v50; // [esp+8Ch] [ebp-8Ch]
  double v51; // [esp+94h] [ebp-84h]
  double v52; // [esp+9Ch] [ebp-7Ch]
  double v53; // [esp+A4h] [ebp-74h]
  double v54; // [esp+ACh] [ebp-6Ch]
  double v55; // [esp+B4h] [ebp-64h]
  double v56; // [esp+BCh] [ebp-5Ch]
  double v57; // [esp+C4h] [ebp-54h]
  double v58; // [esp+CCh] [ebp-4Ch]
  double v59; // [esp+D4h] [ebp-44h]
  double v60; // [esp+DCh] [ebp-3Ch]
  double v61; // [esp+E4h] [ebp-34h]
  unsigned __int64 v62; // [esp+ECh] [ebp-2Ch]
  double v63; // [esp+F4h] [ebp-24h]
  unsigned __int64 v64; // [esp+FCh] [ebp-1Ch]
  float v65; // [esp+104h] [ebp-14h]
  int v66; // [esp+108h] [ebp-10h]
  unsigned int index; // [esp+10Ch] [ebp-Ch] BYREF
  unsigned int v68; // [esp+110h] [ebp-8h] BYREF
  AISpline *v69; // [esp+114h] [ebp-4h]

  v69 = this;
  v2 = &this->spline;
  if ( Spline::pointsCount(&this->spline) )
  {
    _printf("Calculating radius\n");
    *(float *)&v3 = 0.0;
    v65 = 0.0;
    *(float *)&v68 = 0.0;
    if ( Spline::pointsCount(v2) != 1 )
    {
      v4 = -range;
      v66 = -range;
      do
      {
        v5 = Spline::wrapIndex(v2, v4);
        v6 = Spline::wrapIndex(&v69->spline, v3);
        *(float *)&v7 = COERCE_FLOAT(Spline::wrapIndex(&v69->spline, v68 + range));
        resolution = v5;
        index = v7;
        v2 = &v69->spline;
        v8 = Spline::pointAt(&v69->spline, &result, resolution);
        v60 = v8->x;
        v50 = v8->y;
        v61 = v8->z;
        v9 = Spline::pointAt(v2, &v46, v6);
        v58 = v9->x;
        v53 = v9->y;
        v54 = v9->z;
        v10 = Spline::pointAt(v2, &v47, index);
        v11 = 0.0;
        v12 = v10->z - v54;
        v13 = v10->x - v58;
        v14 = v58 - v60;
        v15 = v54 - v61;
        v52 = v54 - v61;
        v56 = v54 - v61;
        v59 = v12;
        v51 = v58 - v60;
        v55 = v58 - v60;
        v57 = v13;
        v16 = v12 * v12 + v13 * v13;
        *(double *)&v64 = 0.0;
        if ( v16 == 0.0 )
          v17 = 0.0;
        else
          v17 = sqrt(v16);
        *(float *)&v18 = v17;
        index = v18;
        v19 = sqrt(v16);
        if ( v19 != 0.0 )
        {
          v11 = 1.0 / v19 * 0.0;
          v13 = 1.0 / v19 * v13;
          v12 = 1.0 / v19 * v12;
          v57 = v13;
          v59 = v12;
        }
        v20 = sqrt(v15 * v15 + v14 * v14);
        if ( v20 == 0.0 )
        {
          v21 = *(double *)&v64;
        }
        else
        {
          v15 = v15 * (1.0 / v20);
          v14 = v14 * (1.0 / v20);
          v21 = 1.0 / v20 * 0.0;
          v56 = v15;
          v55 = v14;
        }
        v63 = v13 * v14 + v11 * v21 + v12 * v15;
        v64 = __libm_sse2_asin().m128_u64[0];
        v22 = v63;
        if ( v63 <= -1.0 || v63 >= 1.0 )
        {
          *(double *)&v62 = 0.0;
        }
        else
        {
          v62 = __libm_sse2_acos().m128_u64[0];
          v22 = v63;
        }
        if ( COERCE_DOUBLE(*(_QWORD *)&v22 & _xmm) >= 1.0 )
        {
          *(double *)&v64 = DOUBLE_1_0;
          *(double *)&v62 = 0.0;
        }
        v23 = v68;
        AISpline::payloadAtSplineIndex(v69, &v49, v68);
        v49.direction = 1.0;
        if ( v57 * v56 - v59 * v55 <= 0.0 )
          v49.direction = -1.0;
        v24 = FLOAT_99999_0;
        v25 = *(double *)__libm_sse2_tan().m128_u64 * *(float *)&index;
        if ( *(double *)&v62 != 0.0 && v63 < 1.0 )
        {
          v26 = v25 * v25;
          v24 = fsqrt(v26 + (float)(*(float *)&index * *(float *)&index));
        }
        v28 = v52 * v52 + v51 * v51;
        v29 = 0.0;
        if ( v28 != 0.0 )
          v29 = sqrt(v28);
        v30 = v29;
        if ( v30 == 0.0 )
        {
          v31 = v49.grade;
        }
        else
        {
          v27 = v53 - v50;
          v31 = (float)(1.0 / v30) * v27;
          v49.grade = v31;
          v49.compression = (float)(v31 - v65) * (float)(1.0 / v30);
        }
        v65 = v31;
        v49.radius = v24;
        v32 = v52 * v52 + v51 * v51;
        if ( v32 == 0.0 )
          v33 = 0.0;
        else
          v33 = sqrt(v32);
        v34 = v33;
        v49.length = v34;
        v35 = (v61 - v54) * (v61 - v54) + (v60 - v58) * (v60 - v58);
        if ( v35 == 0.0 || sqrt(v35) < 0.5 )
          v49.radius = 9000.0;
        normalizedSplinePosition = InterpolatingSpline::getNormalizedPosition(v2, v23);
        *(float *)&v68 = AISpline::getDistToCornerFwd(v69, 250.0, normalizedSplinePosition, 1.0);
        normalizedSplinePositiona = InterpolatingSpline::getNormalizedPosition(v2, v23);
        *(float *)&index = AISpline::getDistToCornerRev(v69, 250.0, normalizedSplinePositiona, 1.0);
        v36 = (float *)&index;
        LODWORD(v49.distFromNextCorner) = v68;
        if ( *(float *)&v68 <= *(float *)&index )
          v36 = (float *)&v68;
        v49.distFromCorner = *v36;
        v37 = Spline::wrapIndex(v2, v23);
        v38 = Spline::tagAt(v2, v37);
        v39 = _mm_loadu_si128((const __m128i *)&v49);
        v3 = v23 + 1;
        ++v66;
        v68 = v3;
        v40 = &v69->payloads._Myfirst[v38];
        v41 = v49.compression;
        *(__m128i *)&v40->speedMS = v39;
        *(__m128i *)&v40->camber = _mm_loadu_si128((const __m128i *)&v49.camber);
        *(__m128i *)&v40->normal.z = _mm_loadu_si128((const __m128i *)&v49.normal.z);
        *(__m128i *)&v40->length = _mm_loadu_si128((const __m128i *)&v49.length);
        *(__m128i *)&v40->grip = _mm_loadu_si128((const __m128i *)&v49.grip);
        v40->compression = v41;
        v42 = v3 < Spline::pointsCount(v2) - 1;
        v4 = v66;
      }
      while ( v42 );
    }
  }
  else
  {
    _printf("WARNING: calculateRadius() found no points\n");
  }
}
void AISpline::cleanSpline(AISpline *this)
{
  int v2; // eax
  float v3; // xmm2_4
  int v4; // eax
  vec3f last; // [esp+8h] [ebp-30h] BYREF
  vec3f first; // [esp+14h] [ebp-24h] BYREF
  vec3f result; // [esp+20h] [ebp-18h] BYREF
  vec3f v8; // [esp+2Ch] [ebp-Ch] BYREF

  v2 = Spline::pointsCount(&this->spline);
  Spline::pointAt(&this->spline, &last, v2 - 1);
  Spline::pointAt(&this->spline, &first, 0);
  while ( 1 )
  {
    v3 = (float)((float)((float)(last.y - first.y) * (float)(last.y - first.y))
               + (float)((float)(last.x - first.x) * (float)(last.x - first.x)))
       + (float)((float)(last.z - first.z) * (float)(last.z - first.z));
    if ( v3 != 0.0 && fsqrt(v3) >= 2.0 )
      break;
    if ( (unsigned int)Spline::pointsCount(&this->spline) <= 4 )
      break;
    InterpolatingSpline::popBack(&this->spline);
    --this->payloads._Mylast;
    v4 = Spline::pointsCount(&this->spline);
    last = *Spline::pointAt(&this->spline, &result, v4 - 1);
    first = *Spline::pointAt(&this->spline, &v8, 0);
  }
  InterpolatingSpline::computeSplineLength(&this->spline);
}
void AISpline::clear(AISpline *this)
{
  this->spline.clear(&this->spline);
  this->payloads._Mylast = this->payloads._Myfirst;
}
void AISpline::closeSmooth(AISpline *this)
{
  InterpolatingSpline::bezierEndopoint(&this->spline);
  AISpline::adjustPayloadEndpoint(this, 10);
}
double AISpline::getCornerRadiusAt(AISpline *this, float normalizedPosition, float distance, float lateralOffset, float carWidth)
{
  float v6; // xmm2_4
  float v7; // xmm2_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  int v16; // ecx
  float pos; // [esp+0h] [ebp-38h]
  float posa; // [esp+0h] [ebp-38h]
  vec3f p0; // [esp+14h] [ebp-24h] BYREF
  vec3f p2; // [esp+20h] [ebp-18h] BYREF
  vec3f p1; // [esp+2Ch] [ebp-Ch] BYREF
  float normalizedPositiona; // [esp+3Ch] [ebp+4h]
  float distanceb; // [esp+40h] [ebp+8h]
  float distancea; // [esp+40h] [ebp+8h]

  distanceb = distance / Spline::length(&this->spline);
  pos = InterpolatingSpline::wrapPosition(&this->spline, normalizedPosition - distanceb);
  AISpline::getPointWithOffset(this, &p0, pos, lateralOffset, carWidth);
  AISpline::getPointWithOffset(this, &p1, normalizedPosition, lateralOffset, carWidth);
  posa = InterpolatingSpline::wrapPosition(&this->spline, normalizedPosition + distanceb);
  AISpline::getPointWithOffset(this, &p2, posa, lateralOffset, carWidth);
  v6 = (float)((float)((float)(p2.y - p0.y) * (float)(p2.y - p0.y))
             + (float)((float)(p2.x - p0.x) * (float)(p2.x - p0.x)))
     + (float)((float)(p2.z - p0.z) * (float)(p2.z - p0.z));
  if ( v6 == 0.0 )
    normalizedPositiona = 0.0;
  else
    normalizedPositiona = fsqrt(v6);
  v7 = 0.0;
  v8 = p2.z - p1.z;
  v9 = p1.x - p0.x;
  distancea = 0.0;
  v10 = p1.z - p0.z;
  v11 = p2.x - p1.x;
  v12 = fsqrt((float)(v10 * v10) + (float)(v9 * v9));
  if ( v12 != 0.0 )
  {
    v13 = 1.0 / v12;
    v9 = v9 * v13;
    v10 = v13 * v10;
    distancea = v13 * 0.0;
  }
  v14 = fsqrt((float)(v8 * v8) + (float)(v11 * v11));
  if ( v14 != 0.0 )
  {
    v11 = (float)(1.0 / v14) * v11;
    v7 = (float)(1.0 / v14) * 0.0;
    v8 = (float)(1.0 / v14) * v8;
  }
  v15 = (float)((float)(v7 * distancea) + (float)(v11 * v9)) + (float)(v8 * v10);
  if ( v15 > 1.0 || v15 >= 0.0 && v15 >= 1.0 )
    return 10000.0;
  __libm_sse2_acosf();
  return (float)(normalizedPositiona / (float)(__libm_sse2_sinf(v16).m128_f32[0] * 2.0));
}
double AISpline::getDistToCornerFwd(AISpline *this, float thresholdRadius, float normalizedSplinePosition, float resolution)
{
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  int v15; // ecx
  float v16; // xmm1_4
  float v18; // [esp+0h] [ebp-48h]
  float v19; // [esp+0h] [ebp-48h]
  float dist; // [esp+14h] [ebp-34h]
  float v21; // [esp+18h] [ebp-30h]
  float v22; // [esp+18h] [ebp-30h]
  float v23; // [esp+1Ch] [ebp-2Ch]
  float sstep; // [esp+20h] [ebp-28h]
  vec3f result; // [esp+24h] [ebp-24h] BYREF
  vec3f v26; // [esp+30h] [ebp-18h] BYREF
  vec3f v27; // [esp+3Ch] [ebp-Ch] BYREF

  dist = 0.0;
  sstep = resolution / Spline::length(&this->spline);
  while ( 1 )
  {
    v21 = 20.0 / Spline::length(&this->spline);
    v18 = InterpolatingSpline::wrapPosition(&this->spline, normalizedSplinePosition - v21);
    AISpline::getPointWithOffset(this, &result, v18, 0.0, 0.60000002);
    AISpline::getPointWithOffset(this, &v27, normalizedSplinePosition, 0.0, 0.60000002);
    v19 = InterpolatingSpline::wrapPosition(&this->spline, v21 + normalizedSplinePosition);
    AISpline::getPointWithOffset(this, &v26, v19, 0.0, 0.60000002);
    v5 = (float)((float)((float)(v26.y - result.y) * (float)(v26.y - result.y))
               + (float)((float)(v26.x - result.x) * (float)(v26.x - result.x)))
       + (float)((float)(v26.z - result.z) * (float)(v26.z - result.z));
    if ( v5 == 0.0 )
      v23 = 0.0;
    else
      v23 = fsqrt(v5);
    v6 = 0.0;
    v7 = v26.z - v27.z;
    v8 = v27.x - result.x;
    result.y = 0.0;
    v27.y = 0.0;
    v9 = v27.z - result.z;
    v10 = v26.x - v27.x;
    v26.y = 0.0;
    v22 = 0.0;
    v11 = fsqrt((float)(v9 * v9) + (float)(v8 * v8));
    if ( v11 != 0.0 )
    {
      v12 = 1.0 / v11;
      v8 = v8 * v12;
      v9 = v12 * v9;
      v22 = v12 * 0.0;
    }
    v13 = fsqrt((float)(v7 * v7) + (float)(v10 * v10));
    if ( v13 != 0.0 )
    {
      v10 = (float)(1.0 / v13) * v10;
      v6 = (float)(1.0 / v13) * 0.0;
      v7 = (float)(1.0 / v13) * v7;
    }
    v14 = (float)((float)(v6 * v22) + (float)(v10 * v8)) + (float)(v7 * v9);
    if ( v14 > 1.0 || v14 >= 0.0 && v14 >= 1.0 )
    {
      v16 = FLOAT_10000_0;
    }
    else
    {
      __libm_sse2_acosf();
      v16 = v23 / (float)(__libm_sse2_sinf(v15).m128_f32[0] * 2.0);
    }
    if ( thresholdRadius >= v16 )
      break;
    dist = dist + resolution;
    normalizedSplinePosition = InterpolatingSpline::wrapPosition(&this->spline, sstep + normalizedSplinePosition);
    if ( dist >= 500.0 )
      return 500.0;
  }
  return dist;
}
double AISpline::getDistToCornerRev(AISpline *this, float thresholdRadius, float normalizedSplinePosition, float resolution)
{
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  int v15; // ecx
  float v16; // xmm1_4
  float v18; // [esp+0h] [ebp-48h]
  float v19; // [esp+0h] [ebp-48h]
  float dist; // [esp+14h] [ebp-34h]
  float v21; // [esp+18h] [ebp-30h]
  float v22; // [esp+18h] [ebp-30h]
  float v23; // [esp+1Ch] [ebp-2Ch]
  float sstep; // [esp+20h] [ebp-28h]
  vec3f result; // [esp+24h] [ebp-24h] BYREF
  vec3f v26; // [esp+30h] [ebp-18h] BYREF
  vec3f v27; // [esp+3Ch] [ebp-Ch] BYREF

  dist = 0.0;
  sstep = resolution / Spline::length(&this->spline);
  while ( 1 )
  {
    v21 = 20.0 / Spline::length(&this->spline);
    v18 = InterpolatingSpline::wrapPosition(&this->spline, normalizedSplinePosition - v21);
    AISpline::getPointWithOffset(this, &result, v18, 0.0, 0.60000002);
    AISpline::getPointWithOffset(this, &v27, normalizedSplinePosition, 0.0, 0.60000002);
    v19 = InterpolatingSpline::wrapPosition(&this->spline, v21 + normalizedSplinePosition);
    AISpline::getPointWithOffset(this, &v26, v19, 0.0, 0.60000002);
    v5 = (float)((float)((float)(v26.y - result.y) * (float)(v26.y - result.y))
               + (float)((float)(v26.x - result.x) * (float)(v26.x - result.x)))
       + (float)((float)(v26.z - result.z) * (float)(v26.z - result.z));
    if ( v5 == 0.0 )
      v23 = 0.0;
    else
      v23 = fsqrt(v5);
    v6 = 0.0;
    v7 = v26.z - v27.z;
    v8 = v27.x - result.x;
    result.y = 0.0;
    v27.y = 0.0;
    v9 = v27.z - result.z;
    v10 = v26.x - v27.x;
    v26.y = 0.0;
    v22 = 0.0;
    v11 = fsqrt((float)(v9 * v9) + (float)(v8 * v8));
    if ( v11 != 0.0 )
    {
      v12 = 1.0 / v11;
      v8 = v8 * v12;
      v9 = v12 * v9;
      v22 = v12 * 0.0;
    }
    v13 = fsqrt((float)(v7 * v7) + (float)(v10 * v10));
    if ( v13 != 0.0 )
    {
      v10 = (float)(1.0 / v13) * v10;
      v6 = (float)(1.0 / v13) * 0.0;
      v7 = (float)(1.0 / v13) * v7;
    }
    v14 = (float)((float)(v6 * v22) + (float)(v10 * v8)) + (float)(v7 * v9);
    if ( v14 > 1.0 || v14 >= 0.0 && v14 >= 1.0 )
    {
      v16 = FLOAT_10000_0;
    }
    else
    {
      __libm_sse2_acosf();
      v16 = v23 / (float)(__libm_sse2_sinf(v15).m128_f32[0] * 2.0);
    }
    if ( thresholdRadius >= v16 )
      break;
    dist = dist + resolution;
    normalizedSplinePosition = InterpolatingSpline::wrapPosition(&this->spline, normalizedSplinePosition - sstep);
    if ( dist >= 500.0 )
      return 500.0;
  }
  return dist;
}
vec3f *AISpline::getLastPoint(AISpline *this, vec3f *result)
{
  InterpolatingSpline *v2; // edi
  int v3; // eax

  v2 = &this->spline;
  v3 = Spline::pointsCount(&this->spline);
  Spline::pointAt(v2, result, v3 - 1);
  return result;
}
void AISpline::getPayloadIndices(AISpline *this, float pos, unsigned int *i0, unsigned int *i1, float *blend)
{
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // esi
  long double payloadIndex; // [esp+18h] [ebp-8h] BYREF
  float posa; // [esp+24h] [ebp+4h]

  if ( Spline::pointsCount(&this->spline) )
  {
    posa = InterpolatingSpline::wrapPosition(&this->spline, pos);
    v6 = InterpolatingSpline::getLastIndexFromNorm(&this->spline, posa, blend);
    v7 = Spline::tagAt(&this->spline, v6);
    payloadIndex = (float)((float)((float)((float)(v7 + 1) - (float)v7) * *blend) + (float)v7);
    *blend = _modf(payloadIndex, &payloadIndex);
    v8 = (int)payloadIndex % (unsigned int)(this->payloads._Mylast - this->payloads._Myfirst);
    *i0 = v8;
    *i1 = (v8 + 1) % (this->payloads._Mylast - this->payloads._Myfirst);
  }
  else
  {
    *i0 = 0;
    *i1 = 0;
  }
}
vec3f *AISpline::getPointWithOffset(AISpline *this, vec3f *result, float pos, float lateralOffset, float carHalfWidth)
{
  AISplinePayload *v6; // edx
  __m128 v7; // xmm5
  float v8; // xmm4_4
  __m128 v9; // xmm6
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  vec3f *v20; // eax
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // [esp+14h] [ebp-3Ch]
  unsigned int p1; // [esp+18h] [ebp-38h] BYREF
  unsigned int p0; // [esp+1Ch] [ebp-34h] BYREF
  float blend; // [esp+20h] [ebp-30h] BYREF
  float v27; // [esp+24h] [ebp-2Ch]
  float v28; // [esp+28h] [ebp-28h]
  vec3f forward_vector; // [esp+2Ch] [ebp-24h]
  vec3f nextpos; // [esp+38h] [ebp-18h] BYREF
  float v31; // [esp+4Ch] [ebp-4h]

  AISpline::getPayloadIndices(this, pos, &p0, &p1, &blend);
  v6 = this->payloads._Myfirst;
  v9 = (__m128)LODWORD(v6[p0].forwardVector.x);
  v7 = (__m128)LODWORD(v6[p0].forwardVector.y);
  v8 = v6[p0].forwardVector.z;
  v9.m128_f32[0] = v9.m128_f32[0] + (float)((float)(v6[p1].forwardVector.x - v9.m128_f32[0]) * blend);
  v10 = (float)(v6[p1].forwardVector.z - v8) * blend;
  v28 = (float)((float)(v6[p1].sides[0] - v6[p0].sides[0]) * blend) + v6[p0].sides[0];
  v11 = (float)(v6[p1].sides[1] - v6[p0].sides[1]) * blend;
  v31 = v8 + v10;
  v27 = v11 + v6[p0].sides[1];
  v12 = v6[p1].forwardVector.y - v7.m128_f32[0];
  forward_vector.z = v8 + v10;
  v7.m128_f32[0] = v7.m128_f32[0] + (float)(v12 * blend);
  *(_QWORD *)&forward_vector.x = _mm_unpacklo_ps(v9, v7).m128_u64[0];
  v13 = fsqrt(
          (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v9.m128_f32[0] * v9.m128_f32[0]))
        + (float)(v31 * v31));
  if ( v13 == 0.0 )
  {
    v14 = forward_vector.z;
    v23 = forward_vector.y;
    p0 = LODWORD(forward_vector.x);
  }
  else
  {
    *(float *)&p0 = (float)(1.0 / v13) * v9.m128_f32[0];
    v14 = (float)(1.0 / v13) * forward_vector.z;
    v23 = (float)(1.0 / v13) * forward_vector.y;
  }
  *(float *)&p1 = v14;
  InterpolatingSpline::splineToWorld(&this->spline, &nextpos, pos);
  if ( (float)(v27 + v28) <= 4.0 || carHalfWidth <= 0.0 )
  {
    v15 = lateralOffset;
  }
  else
  {
    v15 = lateralOffset;
    if ( lateralOffset <= (float)(v27 - carHalfWidth) )
    {
      if ( (float)(carHalfWidth - v28) > lateralOffset )
        v15 = carHalfWidth;
    }
    else
    {
      v15 = v27 - carHalfWidth;
    }
  }
  v16 = *(float *)&p0 - (float)(v23 * 0.0);
  v17 = (float)(v23 * 0.0) - *(float *)&p1;
  v18 = (float)(*(float *)&p1 * 0.0) - (float)(*(float *)&p0 * 0.0);
  v19 = fsqrt((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v16 * v16));
  if ( v19 != 0.0 )
  {
    v17 = v17 * (float)(1.0 / v19);
    v16 = (float)(1.0 / v19) * v16;
    v18 = (float)(1.0 / v19) * v18;
  }
  v20 = result;
  v21 = (float)(v18 * v15) + nextpos.y;
  v22 = (float)(v16 * v15) + nextpos.z;
  result->x = (float)(v17 * v15) + nextpos.x;
  result->y = v21;
  result->z = v22;
  return v20;
}
vec3f *AISpline::getPointWithOffset(AISpline *this, vec3f *result, float pos, float lateralOffset, float carHalfWidth, const AISplinePayload *pl)
{
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  __m128 v16; // xmm2
  vec3f *v17; // eax
  __m128 v18; // xmm1
  float v19; // xmm0_4

  InterpolatingSpline::splineToWorld(&this->spline, result, pos);
  v6 = pl->sides[1];
  if ( (float)(pl->sides[0] + v6) <= 4.0 )
  {
    v8 = lateralOffset;
  }
  else
  {
    v7 = v6 - carHalfWidth;
    v8 = lateralOffset;
    if ( lateralOffset <= v7 )
    {
      if ( (float)(carHalfWidth - pl->sides[0]) > lateralOffset )
        v8 = carHalfWidth - pl->sides[0];
    }
    else
    {
      v8 = v7;
    }
  }
  v9 = pl->forwardVector.z;
  v10 = pl->forwardVector.y * 0.0;
  v11 = pl->forwardVector.x - v10;
  v12 = v10 - v9;
  v13 = (float)(v9 * 0.0) - (float)(pl->forwardVector.x * 0.0);
  v14 = fsqrt((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v11 * v11));
  if ( v14 != 0.0 )
  {
    v15 = 1.0 / v14;
    v12 = v12 * v15;
    v11 = v15 * v11;
    v13 = v15 * v13;
  }
  v16 = (__m128)LODWORD(result->x);
  v17 = result;
  v18 = (__m128)LODWORD(result->y);
  v16.m128_f32[0] = v16.m128_f32[0] + (float)(v12 * v8);
  v18.m128_f32[0] = v18.m128_f32[0] + (float)(v13 * v8);
  v19 = result->z + (float)(v11 * v8);
  *(_QWORD *)&result->x = _mm_unpacklo_ps(v16, v18).m128_u64[0];
  result->z = v19;
  return v17;
}
void AISpline::getSidesAtPos(AISpline *this, float pos, float *sides, unsigned int use_blend)
{
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // eax
  unsigned int p1; // [esp+18h] [ebp-8h] BYREF
  float blend; // [esp+1Ch] [ebp-4h] BYREF

  if ( (_BYTE)use_blend )
  {
    AISpline::getPayloadIndices(this, pos, &use_blend, &p1, &blend);
    v5 = use_blend;
    v6 = p1;
    *sides = (float)((float)(this->payloads._Myfirst[p1].sides[0] - this->payloads._Myfirst[use_blend].sides[0]) * blend)
           + this->payloads._Myfirst[use_blend].sides[0];
    sides[1] = (float)((float)(this->payloads._Myfirst[v6].sides[1] - this->payloads._Myfirst[v5].sides[1]) * blend)
             + this->payloads._Myfirst[v5].sides[1];
  }
  else
  {
    v7 = InterpolatingSpline::getLastIndexFromNorm(&this->spline, pos, 0);
    *sides = this->payloads._Myfirst[v7].sides[0];
    sides[1] = this->payloads._Myfirst[v7].sides[1];
  }
}
void AISpline::getSlimPayloadAt(AISpline *this, float pos, AISplineSlimPayload *pl)
{
  unsigned int v4; // eax
  int v5; // eax
  double v6; // st7
  unsigned int v7; // esi
  unsigned int v8; // ecx
  unsigned int v9; // esi
  AISplinePayload *v10; // eax
  float blend; // [esp+14h] [ebp-Ch] BYREF
  long double payloadIndex; // [esp+18h] [ebp-8h] BYREF
  float payloadBlend; // [esp+24h] [ebp+4h]
  float payloadBlenda; // [esp+24h] [ebp+4h]

  if ( Spline::pointsCount(&this->spline) )
  {
    blend = 0.0;
    payloadBlend = InterpolatingSpline::wrapPosition(&this->spline, pos);
    v4 = InterpolatingSpline::getLastIndexFromNorm(&this->spline, payloadBlend, &blend);
    v5 = Spline::tagAt(&this->spline, v4);
    payloadIndex = (float)((float)((float)((float)(v5 + 1) - (float)v5) * blend) + (float)v5);
    v6 = _modf(payloadIndex, &payloadIndex);
    v7 = (int)payloadIndex % (unsigned int)(this->payloads._Mylast - this->payloads._Myfirst);
    payloadBlenda = v6;
    v8 = v7;
    v9 = (v7 + 1) % (this->payloads._Mylast - this->payloads._Myfirst);
    pl->camber = (float)((float)(this->payloads._Myfirst[v9].camber - this->payloads._Myfirst[v8].camber) * payloadBlenda)
               + this->payloads._Myfirst[v8].camber;
    pl->grade = (float)((float)(this->payloads._Myfirst[v9].grade - this->payloads._Myfirst[v8].grade) * payloadBlenda)
              + this->payloads._Myfirst[v8].grade;
    pl->grip = (float)((float)(this->payloads._Myfirst[v9].grip - this->payloads._Myfirst[v8].grip) * payloadBlenda)
             + this->payloads._Myfirst[v8].grip;
    v10 = this->payloads._Myfirst;
    pl->isPitlane = v10[v8].isPitlane || v10[v9].isPitlane;
  }
}
char AISpline::getStraightDataFromIndex(AISpline *this, int index, AIStraightData *data, float radiusThreshold)
{
  unsigned int v5; // esi
  int v6; // eax
  int v7; // ebx
  AISplinePayload *v8; // eax
  __m128i v9; // xmm0
  InterpolatingSpline *v10; // ecx
  float v12; // [esp+0h] [ebp-64h]
  int v13; // [esp+4h] [ebp-60h]
  AISplinePayload v14; // [esp+Ch] [ebp-58h] BYREF

  v12 = 0.0;
  v5 = 0;
  if ( !Spline::pointsCount(&this->spline) )
    return 0;
  while ( 1 )
  {
    v13 = Spline::wrapIndex(&this->spline, v5 + index);
    v6 = Spline::wrapIndex(&this->spline, v13);
    v7 = Spline::tagAt(&this->spline, v6);
    if ( v7 < 0 || v7 >= (unsigned int)(this->payloads._Mylast - this->payloads._Myfirst) )
    {
      _printf(
        "ERROR: AISpline::payloadAtSplineIndex tag (%d) out of bounds, payloads: %d\n",
        v7,
        this->payloads._Mylast - this->payloads._Myfirst);
      AISplinePayload::AISplinePayload(&v14);
    }
    else
    {
      v8 = &this->payloads._Myfirst[v7];
      *(__m128i *)&v14.speedMS = _mm_loadu_si128((const __m128i *)v8);
      *(__m128i *)&v14.camber = _mm_loadu_si128((const __m128i *)&v8->camber);
      *(__m128i *)&v14.normal.z = _mm_loadu_si128((const __m128i *)&v8->normal.z);
      *(__m128i *)&v14.length = _mm_loadu_si128((const __m128i *)&v8->length);
      v9 = _mm_loadu_si128((const __m128i *)&v8->grip);
      v14.compression = v8->compression;
      *(__m128i *)&v14.grip = v9;
    }
    v10 = &this->spline;
    if ( radiusThreshold >= v14.radius )
      break;
    ++v5;
    v12 = v14.length + v12;
    if ( v5 >= Spline::pointsCount(v10) )
      return 0;
  }
  data->end = InterpolatingSpline::getNormalizedPosition(v10, v13);
  data->length = v12;
  return 1;
}
double AISpline::getStraightFactor(AISpline *this)
{
  AISplinePayload *v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // ebx
  double result; // st7
  float cc; // [esp+4h] [ebp-60h]
  float v7; // [esp+8h] [ebp-5Ch]
  float v8; // [esp+Ch] [ebp-58h]
  float v9; // [esp+Ch] [ebp-58h]
  AISplinePayload pl; // [esp+10h] [ebp-54h] BYREF

  v7 = 0.0;
  if ( this->straightFactor > 0.0 )
    return this->straightFactor;
  v2 = this->payloads._Myfirst;
  if ( v2 == this->payloads._Mylast )
    return this->straightFactor;
  v8 = 0.0;
  cc = 0.0;
  v3 = 0;
  v4 = this->payloads._Mylast - v2;
  if ( v4 )
  {
    do
    {
      AISpline::payloadAtSplineIndex(this, &pl, v3);
      cc = pl.length + cc;
      if ( pl.radius >= 250.0 )
      {
        v7 = pl.length + v7;
        v8 = v7;
      }
      ++v3;
    }
    while ( v3 < v4 );
  }
  result = v8 / cc;
  v9 = result;
  this->straightFactor = v9;
  return result;
}
void AISpline::initPitlane(AISpline *this, IRayTrackCollisionProvider *track)
{
  unsigned int i; // esi
  IRayTrackCollisionProvider_vtbl *v4; // eax
  float v5; // xmm0_4
  int v6; // eax
  int v7; // ecx
  float v8; // eax
  __m128i *v9; // ecx
  int v10[3]; // [esp+14h] [ebp-9Ch] BYREF
  vec3f point; // [esp+20h] [ebp-90h] BYREF
  int v12[3]; // [esp+2Ch] [ebp-84h] BYREF
  RayCastResult res; // [esp+38h] [ebp-78h] BYREF
  AISplinePayload pl; // [esp+5Ch] [ebp-54h] BYREF

  for ( i = 0; i < Spline::pointsCount(&this->spline); ++i )
  {
    Spline::pointAt(&this->spline, &point, i);
    v4 = track->__vftable;
    *(_OWORD *)&res.pos.x = 0i64;
    v10[0] = LODWORD(point.x);
    res.normal.y = 0.0;
    *(float *)&v10[1] = point.y + 2.0;
    res.normal.z = 0.0;
    res.surfaceDef = 0;
    res.hasHit = 0;
    res.collisionObject = 0;
    v12[0] = 0;
    v12[1] = -1082130432;
    v12[2] = 0;
    v10[2] = LODWORD(point.z);
    ((void (*)(IRayTrackCollisionProvider *, int *, int *, RayCastResult *, int))v4->rayCast)(
      track,
      v10,
      v12,
      &res,
      1120403456);
    if ( res.hasHit )
    {
      if ( res.surfaceDef )
      {
        AISpline::payloadAtSplineIndex(this, &pl, i);
        v5 = res.surfaceDef->gripMod;
        pl.isPitlane = res.surfaceDef->isPitlane;
        pl.grip = v5;
        v6 = Spline::wrapIndex(&this->spline, i);
        v7 = Spline::tagAt(&this->spline, v6);
        v8 = pl.compression;
        v9 = (__m128i *)&this->payloads._Myfirst[v7];
        *v9 = _mm_loadu_si128((const __m128i *)&pl);
        v9[1] = _mm_loadu_si128((const __m128i *)&pl.camber);
        v9[2] = _mm_loadu_si128((const __m128i *)&pl.normal.z);
        v9[3] = _mm_loadu_si128((const __m128i *)&pl.length);
        v9[4] = _mm_loadu_si128((const __m128i *)&pl.grip);
        *(float *)v9[5].m128i_i32 = v8;
      }
    }
  }
}
void AISpline::initStraights(AISpline *this, float radiusThreshold)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v6; // esi
  bool v7; // al
  AIStraightData *v8; // edi
  int v9; // eax
  AIStraightData *v10; // esi
  int v11; // eax
  bool v12; // [esp+27h] [ebp-69h]
  bool v13; // [esp+27h] [ebp-69h]
  AISpline::initStraights::__l21::<lambda_4068cce6dab9ae348091e8b6d830e82f> v14; // [esp+28h] [ebp-68h]
  int i; // [esp+28h] [ebp-68h]
  AIStraightData currStraight; // [esp+2Ch] [ebp-64h] BYREF
  AISplinePayload pl; // [esp+38h] [ebp-58h] BYREF

  if ( Spline::pointsCount(&this->spline) )
  {
    v3 = Spline::pointsCount(&this->spline);
    currStraight.end = 0.0;
    currStraight.length = 0.0;
    v12 = AISpline::payloadAtSplineIndex(this, &pl, v3 - 1)->radius > radiusThreshold;
    v4 = Spline::pointsCount(&this->spline);
    currStraight.start = InterpolatingSpline::getNormalizedPosition(&this->spline, v4 - 1);
    v5 = Spline::pointsCount(&this->spline);
    v6 = v5 - 1;
    if ( v5 != 1 )
    {
      v7 = v12;
      do
      {
        if ( v7 )
        {
          AISpline::payloadAtSplineIndex(this, &pl, v6);
          v13 = pl.radius > radiusThreshold;
          if ( pl.radius <= radiusThreshold )
          {
            v11 = Spline::wrapIndex(&this->spline, v6 + 1);
            if ( AISpline::getStraightDataFromIndex(this, v11, &currStraight, radiusThreshold) )
              std::vector<AISplineHint>::push_back(
                (std::vector<AISplineHint> *)&this->straights,
                (const AISplineHint *)&currStraight);
          }
          else
          {
            currStraight.start = InterpolatingSpline::getNormalizedPosition(&this->spline, v6);
          }
          v7 = v13;
        }
        else
        {
          AISpline::payloadAtSplineIndex(this, &pl, v6);
          v7 = pl.radius > radiusThreshold;
        }
        --v6;
      }
      while ( v6 );
    }
    std::_Sort<AIStraightData *,int,_lambda_4068cce6dab9ae348091e8b6d830e82f_>(
      this->straights._Myfirst,
      this->straights._Mylast,
      this->straights._Mylast - this->straights._Myfirst,
      v14);
    v8 = this->straights._Mylast;
    v9 = 0;
    v10 = this->straights._Myfirst;
    for ( i = 0; v10 != v8; ++i )
    {
      _printf("Straight %d, start: %f, length: %f\n", v9, v10->start, v10->length);
      ++v10;
      v9 = i + 1;
    }
  }
}
int AISpline::isInStraight(AISpline *this, float normalizedPos)
{
  int v2; // edi
  AIStraightData *i; // esi
  float v4; // xmm1_4
  float v5; // xmm2_4

  v2 = 0;
  if ( !(this->straights._Mylast - this->straights._Myfirst) )
    return -1;
  for ( i = this->straights._Myfirst; ; ++i )
  {
    v4 = i->start;
    v5 = i->end;
    if ( v5 > i->start )
    {
      if ( normalizedPos < v4 )
        goto LABEL_9;
      goto LABEL_8;
    }
    if ( normalizedPos >= v4 && normalizedPos <= 1.0 )
      break;
LABEL_8:
    if ( v5 >= normalizedPos )
      return v2;
LABEL_9:
    if ( ++v2 >= (unsigned int)(this->straights._Mylast - this->straights._Myfirst) )
      return -1;
  }
  return v2;
}
void __userpurge AISpline::load(AISpline *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *a_filename)
{
  AISpline::loadFast(this, a2, a3, a_filename);
  AISpline::calculateRadius(this, 1);
  AISpline::initStraights(this, 250.0);
}
void __userpurge AISpline::loadFast(AISpline *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *a_filename)
{
  const std::wstring *v5; // esi
  std::wstring *v6; // ebx
  const std::wstring *v7; // eax
  int *v8; // ebx
  std::ifstream in; // [esp+14h] [ebp-E0h] BYREF
  std::wstring result; // [esp+CCh] [ebp-28h] BYREF
  int v11; // [esp+F0h] [ebp-4h]

  v5 = a_filename;
  v6 = &this->filename;
  if ( &this->filename != a_filename )
    std::wstring::assign(&this->filename, a_filename, 0, 0xFFFFFFFF);
  this->spline.clear(&this->spline);
  this->payloads._Mylast = this->payloads._Myfirst;
  v7 = Path::getPlatformSpecificPath(&result, v6);
  v11 = 0;
  std::ifstream::ifstream(&in, v7, 32, 64, 1);
  LOBYTE(v11) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( (*((_BYTE *)&in._Chcount + *(_DWORD *)(*(_DWORD *)in.gap0 + 4) + 4) & 6) == 0 )
  {
    v8 = &this->version;
    std::istream::read(&in, &this->version);
    if ( a_filename->_Myres >= 8 )
      v5 = (const std::wstring *)a_filename->_Bx._Ptr;
    _printf("Loading AI Spline: %S\n", v5->_Bx._Buf);
    _printf("AI SPLINE VERSION %d\n", *v8);
    if ( *v8 >= 7 )
      AISpline::loadVersion7(this, a2, a3, &in);
    else
      AISpline::loadVersion6(this, a2, &in);
    InterpolatingSpline::computeSplineLength(&this->spline);
    if ( !std::filebuf::close((std::filebuf *)in.gap10) )
      std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
  }
  v11 = -1;
  std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
  *(_DWORD *)&in.gap64[12] = std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor((struct std::ios_base *)&in.gap64[12]);
}
void __userpurge AISpline::loadVersion6(AISpline *this@<ecx>, __m128 a2@<xmm3>, std::ifstream *in)
{
  AISpline *v3; // esi
  int v4; // esi
  unsigned int v5; // eax
  int v6; // edi
  bool v7; // cc
  float v8; // xmm1_4
  float v9; // xmm1_4
  __m128 v10; // xmm2
  float v11; // ecx
  float v12; // xmm0_4
  int v13; // eax
  int v14; // eax
  char v15; // al
  int v16; // edx
  bool v17; // zf
  int v18; // eax
  Spline *v19; // esi
  int v20; // eax
  vec3f *v21; // edi
  vec3f *v22; // eax
  float v23; // xmm4_4
  __m128 v24; // xmm2
  unsigned __int64 v25; // xmm3_8
  float v26; // ecx
  float v27; // xmm0_4
  AISplinePayload *v28; // eax
  FILE *v29; // [esp+9Ch] [ebp-C0h]
  char v30[4]; // [esp+A8h] [ebp-B4h] BYREF
  vec3f result; // [esp+ACh] [ebp-B0h] BYREF
  unsigned int v32; // [esp+B8h] [ebp-A4h]
  vec3f v33; // [esp+BCh] [ebp-A0h] BYREF
  unsigned int v34; // [esp+C8h] [ebp-94h] BYREF
  float v35; // [esp+CCh] [ebp-90h]
  float v36; // [esp+D0h] [ebp-8Ch]
  unsigned __int64 v37; // [esp+D4h] [ebp-88h]
  vec3f p; // [esp+DCh] [ebp-80h] BYREF
  AISpline *v39; // [esp+E8h] [ebp-74h]
  unsigned int v40; // [esp+ECh] [ebp-70h]
  std::ifstream *v41; // [esp+F0h] [ebp-6Ch] BYREF
  __m128i v42; // [esp+F4h] [ebp-68h] BYREF
  AISplinePayload _Val; // [esp+104h] [ebp-58h] BYREF

  v3 = this;
  v41 = in;
  v39 = this;
  std::istream::read(in, &v34);
  _printf("LOADING AI POINTS %u\n", v34);
  v3 = (AISpline *)((char *)v3 + 4);
  std::istream::read(v41, v3);
  _printf("LAPTIME %u", v3->__vftable);
  v4 = (int)v39;
  v5 = 3;
  v6 = (int)v41;
  v40 = v34;
  v7 = v39->version < 3;
  v35 = 0.0;
  if ( !v7 )
    v5 = 0;
  v32 = v5;
  v36 = 0.0;
  v37 = 0i64;
  v42.m128i_i32[3] = 0;
  if ( v34 )
  {
    while ( 1 )
    {
      p.x = 0.0;
      p.y = 0.0;
      p.z = 0.0;
      std::istream::read(v6, &p);
      AISplinePayload::AISplinePayload(&_Val);
      if ( *(int *)(v4 + 32) < 5 )
        std::istream::read(v6, &v41);
      std::istream::read(v6, &_Val);
      std::istream::read(v6, &_Val.gas);
      if ( *(int *)(v4 + 32) >= 6 )
        std::istream::read(v6, &_Val.brake);
      std::istream::read(v6, v30);
      if ( *(int *)(v4 + 32) >= 3 )
      {
        std::istream::read(v6, &_Val.radius);
        std::istream::read(v6, _Val.sides);
        std::istream::read(v6, &_Val.sides[1]);
        std::istream::read(v6, &_Val.camber);
        std::istream::read(v6, &_Val.direction);
        std::istream::read(v6, &_Val.normal);
        std::istream::read(v6, &_Val.length);
      }
      if ( *(int *)(v4 + 32) < 6 )
      {
        v8 = (float)(_Val.speedMS - v35) / (float)(_Val.length / _Val.speedMS);
        if ( v8 >= 0.0 )
        {
          _Val.gas = 1.0;
        }
        else
        {
          LODWORD(v9) = LODWORD(v8) ^ _xmm;
          if ( v9 <= 1.0 )
          {
            if ( v9 >= 0.0 )
              _Val.brake = v9;
            else
              _Val.brake = 0.0;
          }
          else
          {
            _Val.brake = 1.0;
          }
        }
        v35 = _Val.speedMS;
      }
      v10 = (__m128)LODWORD(p.y);
      v10.m128_f32[0] = p.y - v36;
      a2.m128_f32[0] = p.x - *((float *)&v37 + 1);
      a2 = _mm_unpacklo_ps(a2, v10);
      result.z = p.z - *(float *)&v37;
      v11 = p.z - *(float *)&v37;
      v42.m128i_i64[0] = a2.m128_u64[0];
      *(float *)&v42.m128i_i32[2] = p.z - *(float *)&v37;
      v12 = fsqrt(
              (float)((float)(v10.m128_f32[0] * v10.m128_f32[0])
                    + (float)((float)(p.x - *((float *)&v37 + 1)) * (float)(p.x - *((float *)&v37 + 1))))
            + (float)(result.z * result.z));
      if ( v12 != 0.0 )
      {
        *(float *)v42.m128i_i32 = (float)(1.0 / v12) * (float)(p.x - *((float *)&v37 + 1));
        *(float *)&v42.m128i_i32[1] = (float)(1.0 / v12) * *(float *)&v42.m128i_i32[1];
        a2 = (__m128)_mm_loadl_epi64(&v42);
        *(float *)&v42.m128i_i32[2] = (float)(1.0 / v12) * *(float *)&v42.m128i_i32[2];
        v11 = *(float *)&v42.m128i_i32[2];
      }
      _Val.forwardVector.z = v11;
      *(_QWORD *)&_Val.forwardVector.x = a2.m128_u64[0];
      v33 = p;
      if ( !v32 || !(v42.m128i_i32[3] % v32) )
      {
        v13 = Spline::pointsCount((Spline *)(v4 + 48));
        InterpolatingSpline::addPoint((InterpolatingSpline *)(v4 + 48), &p, v13);
        v4 = (int)v39;
        std::vector<AISplinePayload>::push_back(&v39->payloads, &_Val);
      }
      if ( ++v42.m128i_i32[3] >= v40 )
        break;
      v37 = __PAIR64__(LODWORD(v33.x), LODWORD(v33.z));
      v36 = v33.y;
    }
  }
  v14 = v6 + 16;
  if ( *(_DWORD *)(v6 + 96) )
  {
    v15 = std::filebuf::_Endwrite((std::filebuf *)(v6 + 16));
    v29 = *(FILE **)(v6 + 96);
    v40 = 0;
    v16 = v6 + 16;
    if ( !v15 )
      v16 = v40;
    v42.m128i_i32[3] = v16;
    v17 = _fclose(v29) == 0;
    v18 = v42.m128i_i32[3];
    if ( !v17 )
      v18 = 0;
    v42.m128i_i32[3] = v18;
    v14 = v6 + 16;
  }
  else
  {
    v42.m128i_i32[3] = 0;
  }
  *(_BYTE *)(v14 + 76) = 0;
  *(_BYTE *)(v14 + 69) = 0;
  std::streambuf::_Init(v14);
  v17 = v42.m128i_i32[3] == 0;
  *(_DWORD *)(v6 + 96) = 0;
  *(_DWORD *)(v6 + 88) = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)(v6 + 80) = 0;
  if ( v17 )
    std::ios::setstate(v6 + *(_DWORD *)(*(_DWORD *)v6 + 4), 2, 0);
  if ( (unsigned int)((*(_DWORD *)(v4 + 116) - *(_DWORD *)(v4 + 112)) / 84) >= 2 )
  {
    v19 = (Spline *)(v4 + 48);
    v20 = Spline::pointsCount(v19);
    v21 = Spline::pointAt(v19, &result, v20 - 1);
    v22 = Spline::pointAt(v19, &v33, 0);
    v23 = v22->x - v21->x;
    v24 = (__m128)LODWORD(v22->y);
    v24.m128_f32[0] = v24.m128_f32[0] - v21->y;
    a2.m128_f32[0] = v23;
    v25 = _mm_unpacklo_ps(a2, v24).m128_u64[0];
    result.z = v22->z - v21->z;
    v26 = result.z;
    v42.m128i_i64[0] = v25;
    v42.m128i_i32[2] = LODWORD(result.z);
    v27 = fsqrt((float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23)) + (float)(result.z * result.z));
    if ( v27 != 0.0 )
    {
      *(float *)v42.m128i_i32 = (float)(1.0 / v27) * v23;
      *(float *)&v42.m128i_i32[1] = (float)(1.0 / v27) * *(float *)&v42.m128i_i32[1];
      v25 = v42.m128i_i64[0];
      *(float *)&v42.m128i_i32[2] = (float)(1.0 / v27) * *(float *)&v42.m128i_i32[2];
      v26 = *(float *)&v42.m128i_i32[2];
    }
    v28 = v39->payloads._Myfirst;
    *(_QWORD *)&v28->forwardVector.x = v25;
    v28->forwardVector.z = v26;
  }
}
void __userpurge AISpline::loadVersion7(AISpline *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, std::ifstream *in)
{
  InterpolatingSpline *v5; // ebx
  unsigned int i; // esi
  unsigned int v7; // esi
  vec3f *v8; // eax
  __m128 v9; // xmm1
  int v10; // ecx
  float v11; // xmm0_4
  vec3f *v12; // eax
  __int64 v13; // xmm0_8
  AISpline *v14; // edi
  int v15; // eax
  vec3f *v16; // esi
  vec3f *v17; // eax
  float v18; // xmm3_4
  __m128 v19; // xmm2
  unsigned __int64 v20; // xmm4_8
  float v21; // ecx
  float v22; // xmm0_4
  AISplinePayload *v23; // eax
  unsigned __int64 v24; // [esp+FCh] [ebp-CCh] BYREF
  float v25; // [esp+104h] [ebp-C4h]
  unsigned int npayload; // [esp+108h] [ebp-C0h] BYREF
  AISpline *v27; // [esp+10Ch] [ebp-BCh]
  unsigned int pointcount; // [esp+110h] [ebp-B8h] BYREF
  float v29; // [esp+114h] [ebp-B4h]
  __int64 v30; // [esp+118h] [ebp-B0h]
  std::vector<AISplinePayload> *v31; // [esp+120h] [ebp-A8h]
  float tag; // [esp+124h] [ebp-A4h] BYREF
  vec3f current_pos; // [esp+128h] [ebp-A0h]
  SplinePoint p; // [esp+134h] [ebp-94h] BYREF
  float v35; // [esp+150h] [ebp-78h]
  int sampleCount; // [esp+154h] [ebp-74h] BYREF
  float obsolete_latg; // [esp+158h] [ebp-70h] BYREF
  vec3f result; // [esp+15Ch] [ebp-6Ch] BYREF
  AISplinePayload pl; // [esp+168h] [ebp-60h] BYREF

  v27 = this;
  _printf("LOADING VERSION 7\n");
  v5 = &this->spline;
  pointcount = Spline::pointsCount(v5);
  _printf("Points count: %d\n", pointcount);
  std::istream::read(in, &pointcount);
  std::istream::read(in, &v27->lapTime);
  std::istream::read(in, &sampleCount);
  for ( i = 0; i < pointcount; ++i )
  {
    Spline::splinePointAt(v5, &p, i);
    std::istream::read(in, &p);
    std::istream::read(in, &p.pointLength);
    std::istream::read(in, &p.tag);
    InterpolatingSpline::addSplinePoint(v5, &p);
  }
  npayload = 0;
  std::istream::read(in, &npayload);
  v7 = 0;
  v30 = 0i64;
  v29 = 0.0;
  if ( npayload )
  {
    v31 = &v27->payloads;
    while ( 1 )
    {
      AISplinePayload::AISplinePayload(&pl);
      std::istream::read(in, &pl);
      std::istream::read(in, &pl.gas);
      std::istream::read(in, &pl.brake);
      std::istream::read(in, &obsolete_latg);
      std::istream::read(in, &pl.radius);
      std::istream::read(in, pl.sides);
      std::istream::read(in, &pl.sides[1]);
      std::istream::read(in, &pl.camber);
      std::istream::read(in, &pl.direction);
      std::istream::read(in, &pl.normal);
      std::istream::read(in, &pl.length);
      std::istream::read(in, &pl.forwardVector);
      tag = 0.0;
      std::istream::read(in, &tag);
      std::istream::read(in, &pl.grade);
      v8 = Spline::pointAt(v5, &result, v7);
      a3 = (__m128)LODWORD(v8->x);
      a3.m128_f32[0] = a3.m128_f32[0] - *(float *)&v30;
      v9 = (__m128)LODWORD(v8->y);
      v9.m128_f32[0] = v9.m128_f32[0] - *((float *)&v30 + 1);
      a2.m128_f32[0] = a3.m128_f32[0];
      a2 = _mm_unpacklo_ps(a2, v9);
      v35 = v8->z - v29;
      v10 = LODWORD(v35);
      v24 = a2.m128_u64[0];
      v25 = v35;
      v11 = fsqrt(
              (float)((float)(a3.m128_f32[0] * a3.m128_f32[0]) + (float)(v9.m128_f32[0] * v9.m128_f32[0]))
            + (float)(v35 * v35));
      if ( v11 != 0.0 )
      {
        *(float *)&v24 = (float)(1.0 / v11) * a3.m128_f32[0];
        *((float *)&v24 + 1) = (float)(1.0 / v11) * *((float *)&v24 + 1);
        a2 = (__m128)_mm_loadl_epi64((const __m128i *)&v24);
        v25 = (float)(1.0 / v11) * v25;
        v10 = LODWORD(v25);
      }
      LODWORD(pl.forwardVector.z) = v10;
      *(_QWORD *)&pl.forwardVector.x = a2.m128_u64[0];
      v12 = Spline::pointAt(v5, &p.point, v7);
      v13 = *(_QWORD *)&v12->x;
      current_pos.z = v12->z;
      *(_QWORD *)&current_pos.x = v13;
      std::vector<AISplinePayload>::push_back(v31, &pl);
      if ( ++v7 >= npayload )
        break;
      v29 = current_pos.z;
      v30 = *(_QWORD *)&current_pos.x;
    }
  }
  InterpolatingSpline::loadGrid(v5, in);
  v14 = v27;
  if ( (unsigned int)(v27->payloads._Mylast - v27->payloads._Myfirst) >= 2 )
  {
    v15 = Spline::pointsCount(v5);
    v16 = Spline::pointAt(v5, &p.point, v15 - 1);
    v17 = Spline::pointAt(v5, &result, 0);
    v18 = v17->x - v16->x;
    v19 = (__m128)LODWORD(v17->y);
    v19.m128_f32[0] = v19.m128_f32[0] - v16->y;
    a3.m128_f32[0] = v18;
    v20 = _mm_unpacklo_ps(a3, v19).m128_u64[0];
    v35 = v17->z - v16->z;
    v21 = v35;
    v24 = v20;
    v25 = v35;
    v22 = fsqrt((float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18)) + (float)(v35 * v35));
    if ( v22 != 0.0 )
    {
      *(float *)&v24 = (float)(1.0 / v22) * v18;
      *((float *)&v24 + 1) = (float)(1.0 / v22) * *((float *)&v24 + 1);
      v20 = v24;
      v25 = (float)(1.0 / v22) * v25;
      v21 = v25;
    }
    v23 = v14->payloads._Myfirst;
    *(_QWORD *)&v23->forwardVector.x = v20;
    v23->forwardVector.z = v21;
  }
}
AISplinePayload *AISpline::payloadAtPosition(AISpline *this, AISplinePayload *result, float pos)
{
  AISplinePayload *v3; // edi
  double v5; // st7
  unsigned int v6; // eax
  int v7; // eax
  double v8; // st7
  unsigned int v9; // esi
  int v10; // edx
  float v11; // xmm6_4
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // ecx
  AISplinePayload *v15; // eax
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  unsigned __int64 v18; // xmm1_8
  float v19; // edx
  float v20; // xmm0_4
  AISplinePayload *v21; // eax
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  unsigned __int64 v24; // xmm1_8
  float v25; // edx
  float v26; // xmm0_4
  AISplinePayload *v27; // eax
  long double payloadIndex; // [esp+18h] [ebp-20h] BYREF
  unsigned __int64 v30; // [esp+20h] [ebp-18h]
  float v31; // [esp+28h] [ebp-10h]
  float v32; // [esp+34h] [ebp-4h]

  v3 = result;
  AISplinePayload::AISplinePayload(result);
  if ( Spline::pointsCount(&this->spline) )
  {
    v5 = InterpolatingSpline::wrapPosition(&this->spline, pos);
    *(float *)&result = 0.0;
    pos = v5;
    v6 = InterpolatingSpline::getLastIndexFromNorm(&this->spline, pos, (float *)&result);
    v7 = Spline::tagAt(&this->spline, v6);
    payloadIndex = (float)((float)((float)((float)(v7 + 1) - (float)v7) * *(float *)&result) + (float)v7);
    v8 = _modf(payloadIndex, &payloadIndex);
    v9 = (int)payloadIndex % (unsigned int)(this->payloads._Mylast - this->payloads._Myfirst);
    v10 = (unsigned __int64)(818089009i64 * ((char *)this->payloads._Mylast - (char *)this->payloads._Myfirst)) >> 32;
    pos = v8;
    v11 = pos;
    v12 = v9 + 1;
    v13 = v9;
    v14 = v12 % ((v10 >> 4) + ((unsigned int)v10 >> 31));
    v3->camber = (float)((float)(this->payloads._Myfirst[v14].camber - this->payloads._Myfirst[v13].camber) * pos)
               + this->payloads._Myfirst[v13].camber;
    v3->direction = (float)((float)(this->payloads._Myfirst[v14].direction - this->payloads._Myfirst[v13].direction)
                          * v11)
                  + this->payloads._Myfirst[v13].direction;
    v3->gas = (float)((float)(this->payloads._Myfirst[v14].gas - this->payloads._Myfirst[v13].gas) * v11)
            + this->payloads._Myfirst[v13].gas;
    v3->length = (float)((float)(this->payloads._Myfirst[v14].length - this->payloads._Myfirst[v13].length) * v11)
               + this->payloads._Myfirst[v13].length;
    v15 = this->payloads._Myfirst;
    v17 = (__m128)LODWORD(v15[v14].normal.x);
    v16 = (__m128)LODWORD(v15[v14].normal.y);
    v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] - v15[v13].normal.x) * v11) + v15[v13].normal.x;
    v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] - v15[v13].normal.y) * v11) + v15[v13].normal.y;
    v18 = _mm_unpacklo_ps(v17, v16).m128_u64[0];
    v32 = (float)((float)(v15[v14].normal.z - v15[v13].normal.z) * v11) + v15[v13].normal.z;
    v19 = v32;
    v30 = v18;
    v31 = v32;
    v20 = fsqrt(
            (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v17.m128_f32[0] * v17.m128_f32[0]))
          + (float)(v32 * v32));
    if ( v20 != 0.0 )
    {
      *(float *)&v30 = (float)(1.0 / v20) * v17.m128_f32[0];
      v31 = (float)(1.0 / v20) * v31;
      v19 = v31;
      *((float *)&v30 + 1) = (float)(1.0 / v20) * *((float *)&v30 + 1);
      v18 = v30;
    }
    *(_QWORD *)&v3->normal.x = v18;
    v3->normal.z = v19;
    v3->radius = (float)((float)(this->payloads._Myfirst[v14].radius - this->payloads._Myfirst[v13].radius) * v11)
               + this->payloads._Myfirst[v13].radius;
    v3->sides[0] = (float)((float)(this->payloads._Myfirst[v14].sides[0] - this->payloads._Myfirst[v13].sides[0]) * v11)
                 + this->payloads._Myfirst[v13].sides[0];
    v3->sides[1] = (float)((float)(this->payloads._Myfirst[v14].sides[1] - this->payloads._Myfirst[v13].sides[1]) * v11)
                 + this->payloads._Myfirst[v13].sides[1];
    v3->speedMS = (float)((float)(this->payloads._Myfirst[v14].speedMS - this->payloads._Myfirst[v13].speedMS) * v11)
                + this->payloads._Myfirst[v13].speedMS;
    v3->brake = (float)((float)(this->payloads._Myfirst[v14].brake - this->payloads._Myfirst[v13].brake) * v11)
              + this->payloads._Myfirst[v13].brake;
    v21 = this->payloads._Myfirst;
    v23 = (__m128)LODWORD(v21[v14].forwardVector.x);
    v22 = (__m128)LODWORD(v21[v14].forwardVector.y);
    v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] - v21[v13].forwardVector.x) * v11) + v21[v13].forwardVector.x;
    v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] - v21[v13].forwardVector.y) * v11) + v21[v13].forwardVector.y;
    v24 = _mm_unpacklo_ps(v23, v22).m128_u64[0];
    v32 = (float)((float)(v21[v14].forwardVector.z - v21[v13].forwardVector.z) * v11) + v21[v13].forwardVector.z;
    v25 = v32;
    v30 = v24;
    v31 = v32;
    v26 = fsqrt(
            (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v23.m128_f32[0] * v23.m128_f32[0]))
          + (float)(v32 * v32));
    if ( v26 != 0.0 )
    {
      *((float *)&v30 + 1) = *((float *)&v30 + 1) * (float)(1.0 / v26);
      *(float *)&v30 = v23.m128_f32[0] * (float)(1.0 / v26);
      v24 = v30;
      v31 = v31 * (float)(1.0 / v26);
      v25 = v31;
    }
    *(_QWORD *)&v3->forwardVector.x = v24;
    v3->forwardVector.z = v25;
    v3->grade = (float)((float)(this->payloads._Myfirst[v14].grade - this->payloads._Myfirst[v13].grade) * v11)
              + this->payloads._Myfirst[v13].grade;
    v3->grip = (float)((float)(this->payloads._Myfirst[v14].grip - this->payloads._Myfirst[v13].grip) * v11)
             + this->payloads._Myfirst[v13].grip;
    v3->distFromCorner = (float)((float)(this->payloads._Myfirst[v14].distFromCorner
                                       - this->payloads._Myfirst[v13].distFromCorner)
                               * v11)
                       + this->payloads._Myfirst[v13].distFromCorner;
    v3->distFromNextCorner = (float)((float)(this->payloads._Myfirst[v14].distFromNextCorner
                                           - this->payloads._Myfirst[v13].distFromNextCorner)
                                   * v11)
                           + this->payloads._Myfirst[v13].distFromNextCorner;
    v27 = this->payloads._Myfirst;
    if ( !v27[v13].isPitlane && !v27[v14].isPitlane )
    {
      v3->isPitlane = 0;
      return v3;
    }
    v3->isPitlane = 1;
  }
  return v3;
}
AISplinePayload *AISpline::payloadAtSplineIndex(AISpline *this, AISplinePayload *result, const unsigned int index)
{
  int v4; // eax
  int v5; // esi
  AISplinePayload *v6; // eax
  AISplinePayload *v7; // ecx

  v4 = Spline::wrapIndex(&this->spline, index);
  v5 = Spline::tagAt(&this->spline, v4);
  if ( v5 < 0 || v5 >= (unsigned int)(this->payloads._Mylast - this->payloads._Myfirst) )
  {
    _printf(
      "ERROR: AISpline::payloadAtSplineIndex tag (%d) out of bounds, payloads: %d\n",
      v5,
      this->payloads._Mylast - this->payloads._Myfirst);
    AISplinePayload::AISplinePayload(result);
    v6 = result;
  }
  else
  {
    v6 = result;
    v7 = &this->payloads._Myfirst[v5];
    *(__m128i *)&result->speedMS = _mm_loadu_si128((const __m128i *)v7);
    *(__m128i *)&result->camber = _mm_loadu_si128((const __m128i *)&v7->camber);
    *(__m128i *)&result->normal.z = _mm_loadu_si128((const __m128i *)&v7->normal.z);
    *(__m128i *)&result->length = _mm_loadu_si128((const __m128i *)&v7->length);
    *(__m128i *)&result->grip = _mm_loadu_si128((const __m128i *)&v7->grip);
    result->compression = v7->compression;
  }
  return v6;
}
int AISpline::pointsCount(AISpline *this)
{
  return Spline::pointsCount(&this->spline);
}
void AISpline::save(AISpline *this, std::wstring filen)
{
  std::wstring *v3; // eax
  InterpolatingSpline *v4; // edi
  unsigned int i; // esi
  int v6; // ebp
  unsigned int j; // edi
  AISplinePayload *v8; // esi
  _BYTE *v9; // esi
  int v10; // ecx
  unsigned int pointcount; // [esp+104h] [ebp-E4h] BYREF
  unsigned int npayload; // [esp+108h] [ebp-E0h] BYREF
  float obsolete_latg; // [esp+10Ch] [ebp-DCh] BYREF
  float tag; // [esp+110h] [ebp-D8h] BYREF
  InterpolatingSpline *v15; // [esp+114h] [ebp-D4h]
  int version; // [esp+118h] [ebp-D0h] BYREF
  int sampleCount; // [esp+11Ch] [ebp-CCh] BYREF
  std::ofstream out; // [esp+120h] [ebp-C8h] BYREF
  SplinePoint p; // [esp+1C8h] [ebp-20h] BYREF
  int v20; // [esp+1E4h] [ebp-4h]

  v20 = 0;
  _printf("SAVING VERSION 7\n");
  v3 = &filen;
  if ( filen._Myres >= 8 )
    v3 = (std::wstring *)filen._Bx._Ptr;
  std::ofstream::ofstream(&out, v3->_Bx._Buf, 32, 64, 1);
  LOBYTE(v20) = 1;
  version = 7;
  std::ostream::write(&out, &version, 4, 0);
  v4 = &this->spline;
  v15 = &this->spline;
  pointcount = Spline::pointsCount(&this->spline);
  std::ostream::write(&out, &pointcount, 4, 0);
  std::ostream::write(&out, &this->lapTime, 4, 0);
  sampleCount = 0;
  std::ostream::write(&out, &sampleCount, 4, 0);
  for ( i = 0; i < pointcount; ++i )
  {
    Spline::splinePointAt(&this->spline, &p, i);
    std::ostream::write(&out, &p, 12, 0);
    std::ostream::write(&out, &p.pointLength, 4, 0);
    std::ostream::write(&out, &p.tag, 4, 0);
  }
  npayload = this->payloads._Mylast - this->payloads._Myfirst;
  std::ostream::write(&out, &npayload, 4, 0);
  if ( npayload )
  {
    v6 = 0;
    for ( j = 0; j < npayload; ++j )
    {
      v8 = &this->payloads._Myfirst[v6];
      std::ostream::write(&out, v8, 4, 0);
      std::ostream::write(&out, &v8->gas, 4, 0);
      std::ostream::write(&out, &v8->brake, 4, 0);
      obsolete_latg = 0.0;
      std::ostream::write(&out, &obsolete_latg, 4, 0);
      std::ostream::write(&out, &v8->radius, 4, 0);
      std::ostream::write(&out, v8->sides, 4, 0);
      std::ostream::write(&out, &v8->sides[1], 4, 0);
      std::ostream::write(&out, &v8->camber, 4, 0);
      std::ostream::write(&out, &v8->direction, 4, 0);
      std::ostream::write(&out, &v8->normal, 12, 0);
      std::ostream::write(&out, &v8->length, 4, 0);
      std::ostream::write(&out, &v8->forwardVector, 12, 0);
      tag = 0.0;
      std::ostream::write(&out, &tag, 4, 0);
      std::ostream::write(&out, &v8->grade, 4, 0);
      ++v6;
    }
    v4 = v15;
  }
  InterpolatingSpline::saveGrid(v4, &out);
  v9 = &out.gap0[4];
  if ( *(_DWORD *)&out._Filebuffer[4] )
  {
    if ( !std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]) )
      v9 = 0;
    if ( _fclose(*(FILE **)&out._Filebuffer[4]) )
      v9 = 0;
  }
  else
  {
    v9 = 0;
  }
  out._Filebuffer[0] = 0;
  out.gap0[73] = 0;
  std::streambuf::_Init(&out.gap0[4]);
  *(_DWORD *)&out._Filebuffer[4] = 0;
  *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&out.gap0[68] = 0;
  if ( !v9 )
    std::ios::setstate((char *)&out + *(_DWORD *)(*(_DWORD *)out.gap0 + 4), 2, 0);
  LOBYTE(v20) = 0;
  *(_DWORD *)&out.gap0[*(_DWORD *)(*(_DWORD *)out.gap0 + 4)] = &std::ofstream::`vftable';
  *(int *)((char *)&sampleCount + *(_DWORD *)(*(_DWORD *)out.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)out.gap0 + 4) - 96;
  v10 = *(_DWORD *)&out._Filebuffer[4];
  *(_DWORD *)&out.gap0[4] = &std::filebuf::`vftable';
  if ( *(_DWORD *)&out._Filebuffer[4] && **(std::ofstream ***)&out.gap0[16] == (std::ofstream *)&out.gap0[72] )
  {
    std::streambuf::setg(&out.gap0[4], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[64]);
    v10 = *(_DWORD *)&out._Filebuffer[4];
  }
  if ( out._Filebuffer[0] )
  {
    if ( v10 )
    {
      std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]);
      _fclose(*(FILE **)&out._Filebuffer[4]);
    }
    out._Filebuffer[0] = 0;
    out.gap0[73] = 0;
    std::streambuf::_Init(&out.gap0[4]);
    *(_DWORD *)&out._Filebuffer[4] = 0;
    *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&out.gap0[68] = 0;
  }
  std::streambuf::~streambuf<char,std::char_traits<char>>(&out.gap0[4]);
  std::ostream::~ostream<char,std::char_traits<char>>(&out.gap0[8]);
  *(_DWORD *)&out.gap58[8] = std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor((struct std::ios_base *)&out.gap58[8]);
  if ( filen._Myres >= 8 )
    operator delete(filen._Bx._Ptr);
}
void AISpline::setPayloadAtSplineIndex(AISpline *this, const unsigned int index, AISplinePayload pl)
{
  int v4; // eax
  AISplinePayload *v5; // ecx

  v4 = Spline::wrapIndex(&this->spline, index);
  v5 = &this->payloads._Myfirst[Spline::tagAt(&this->spline, v4)];
  *(__m128i *)&v5->speedMS = _mm_loadu_si128((const __m128i *)&pl);
  *(__m128i *)&v5->camber = _mm_loadu_si128((const __m128i *)&pl.camber);
  *(__m128i *)&v5->normal.z = _mm_loadu_si128((const __m128i *)&pl.normal.z);
  *(__m128i *)&v5->length = _mm_loadu_si128((const __m128i *)&pl.length);
  *(__m128i *)&v5->grip = _mm_loadu_si128((const __m128i *)&pl.grip);
  v5->compression = pl.compression;
}
