#include "splinelocator.h
void SplineLocator::getSides(SplineLocator *this, float *sides, float nsplinepos)
{
  AISpline *v4; // esi
  float *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // eax
  char v14[4]; // [esp+Ch] [ebp-74h] BYREF
  float v15; // [esp+10h] [ebp-70h]
  float v16; // [esp+14h] [ebp-6Ch]
  vec3f result; // [esp+18h] [ebp-68h] BYREF
  float *v18; // [esp+24h] [ebp-5Ch]
  AISplinePayload v19; // [esp+28h] [ebp-58h] BYREF

  v18 = sides;
  v4 = AISplineRecorder::getBestLapSpline(this->track->aiSplineRecorder._Myptr);
  InterpolatingSpline::splineToWorld(&v4->spline, &result, nsplinepos);
  AISpline::payloadAtPosition(v4, &v19, nsplinepos);
  v5 = (float *)((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getPosition)(
                  this->car->body,
                  v14,
                  0);
  v6 = v15 - *v5;
  v7 = result.x - v5[2];
  v8 = (float)(v19.forwardVector.x * v6) - (float)(v19.normal.y * v7);
  v9 = (float)((float)((float)(v16 - v5[1]) * (float)(v16 - v5[1])) + (float)(v6 * v6)) + (float)(v7 * v7);
  if ( v9 == 0.0 )
    v10 = 0.0;
  else
    v10 = fsqrt(v9);
  v11 = FLOAT_1_0;
  if ( v8 <= 0.0 )
  {
    if ( v8 >= 0.0 )
      v12 = 0.0;
    else
      v12 = FLOAT_N1_0;
  }
  else
  {
    v12 = FLOAT_1_0;
  }
  v13 = result.y;
  *(_DWORD *)LODWORD(result.y) = COERCE_UNSIGNED_INT((float)(v12 * v10) + v19.speedMS) & _xmm;
  if ( v8 <= 0.0 )
  {
    if ( v8 >= 0.0 )
      v11 = 0.0;
    else
      v11 = FLOAT_N1_0;
  }
  *(_DWORD *)(LODWORD(v13) + 4) = COERCE_UNSIGNED_INT(v19.radius - (float)(v11 * v10)) & _xmm;
}
void SplineLocator::init(SplineLocator *this, Car *car)
{
  Track *v2; // eax

  this->car = car;
  v2 = car->ksPhysics->track;
  this->track = v2;
  this->currentIndex = -1;
  this->normalizedPos = -1.0;
  this->offset = 0.0;
  this->currentSpline = AISplineRecorder::getBestLapSpline(v2->aiSplineRecorder._Myptr);
}
double __cdecl SplineLocator::locateOnSpline(AISpline *spline, const vec3f *pos, int *index)
{
  InterpolatingSpline *v3; // ebx
  const vec3f *v4; // edi
  vec3f *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm0_4
  int v8; // ebp
  vec3f *v9; // eax
  float v10; // xmm0_4
  vec3f result; // [esp+Ch] [ebp-Ch] BYREF
  float splinea; // [esp+1Ch] [ebp+4h]

  v3 = &spline->spline;
  if ( *index == -1 )
  {
    v4 = pos;
LABEL_6:
    *index = (int)InterpolatingSpline::closestPointIndex(v3, v4, 0);
    return InterpolatingSpline::worldToSpline(v3, v4, *index);
  }
  v5 = Spline::pointAt(&spline->spline, &result, *index);
  v4 = pos;
  v6 = pos->y - v5->y;
  v7 = pos->z - v5->z;
  splinea = (float)((float)(v6 * v6) + (float)((float)(pos->x - v5->x) * (float)(pos->x - v5->x))) + (float)(v7 * v7);
  v8 = Spline::wrapIndex(v3, *index + 1);
  v9 = Spline::pointAt(v3, &result, v8);
  v10 = pos->z - v9->z;
  if ( splinea > (float)((float)((float)((float)(v4->y - v9->y) * (float)(v4->y - v9->y))
                               + (float)((float)(v4->x - v9->x) * (float)(v4->x - v9->x)))
                       + (float)(v10 * v10)) )
    *index = v8;
  if ( splinea > 2500.0 )
    goto LABEL_6;
  return InterpolatingSpline::worldToSpline(v3, v4, *index);
}
double __cdecl SplineLocator::locateOnSplineWithBounds(AISpline *spline, const vec3f *pos, const std::vector<SplineIndexBound> *bounds, int *index)
{
  InterpolatingSpline *v4; // ebx
  int v5; // eax
  double v6; // st7
  vec3f *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm0_4
  int v10; // ebp
  vec3f *v11; // eax
  float v12; // xmm0_4
  vec3f result; // [esp+Ch] [ebp-Ch] BYREF
  float splinea; // [esp+1Ch] [ebp+4h]

  v4 = &spline->spline;
  if ( *index == -1 )
  {
    v5 = Spline::closestPointIndexWithBounds(&spline->spline, pos, bounds, 0);
    *index = v5;
    v6 = InterpolatingSpline::worldToSpline(v4, pos, v5);
  }
  else
  {
    v7 = Spline::pointAt(&spline->spline, &result, *index);
    v8 = pos->y - v7->y;
    v9 = pos->z - v7->z;
    splinea = (float)((float)(v8 * v8) + (float)((float)(pos->x - v7->x) * (float)(pos->x - v7->x))) + (float)(v9 * v9);
    v10 = Spline::wrapIndex(v4, *index + 1);
    v11 = Spline::pointAt(v4, &result, v10);
    v12 = pos->z - v11->z;
    if ( splinea > (float)((float)((float)((float)(pos->y - v11->y) * (float)(pos->y - v11->y))
                                 + (float)((float)(pos->x - v11->x) * (float)(pos->x - v11->x)))
                         + (float)(v12 * v12)) )
      *index = v10;
    if ( splinea > 2500.0 )
      *index = (int)InterpolatingSpline::closestPointIndex(v4, pos, 0);
    v6 = InterpolatingSpline::worldToSpline(v4, pos, *index);
  }
  return v6;
}
void SplineLocator::reset(SplineLocator *this)
{
  this->normalizedPos = -1.0;
  this->currentIndex = -1;
}
void SplineLocator::resetToClosestPoint(SplineLocator *this)
{
  const vec3f *v2; // eax
  double v3; // st7
  Car *v4; // eax
  AISpline *v5; // esi
  const vec3f *v6; // eax
  int *splinePosition; // [esp+Ch] [ebp-1Ch]
  float v8; // [esp+18h] [ebp-10h]
  char v9[12]; // [esp+1Ch] [ebp-Ch] BYREF

  this->currentIndex = -1;
  splinePosition = &this->currentIndex;
  v2 = (const vec3f *)((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getPosition)(
                        this->car->body,
                        v9,
                        0);
  v3 = SplineLocator::locateOnSpline(this->currentSpline, v2, splinePosition);
  v4 = this->car;
  v5 = this->currentSpline;
  v8 = v3;
  this->normalizedPos = v8;
  v6 = (const vec3f *)((int (*)(IRigidBody *, char *, _DWORD))v4->body->getPosition)(v4->body, v9, 0);
  this->offset = InterpolatingSpline::getSignedDistanceFromSpline(&v5->spline, v6, v8);
}
void SplineLocator::step(SplineLocator *this, float dt)
{
  vec3f *(*v3)(IRigidBody *, vec3f *, float); // eax
  const vec3f *v4; // eax
  double v5; // st7
  const vec3f *v6; // eax
  Car *v7; // eax
  AISpline *v8; // esi
  const vec3f *v9; // eax
  double v10; // st7
  AISpline *v11; // ecx
  float v12; // xmm2_4
  float v13; // xmm3_4
  std::vector<SplineIndexBound> *splinePosition; // [esp+10h] [ebp-70h]
  float splinePositiona; // [esp+10h] [ebp-70h]
  float splinePositionb; // [esp+10h] [ebp-70h]
  int *v17; // [esp+14h] [ebp-6Ch]
  char v18[12]; // [esp+1Ch] [ebp-64h] BYREF
  AISplinePayload result; // [esp+28h] [ebp-58h] BYREF

  if ( this->normalizedPos >= 0.0 )
  {
    v17 = &this->currentIndex;
    v3 = this->car->body->getPosition;
    goto LABEL_5;
  }
  v17 = &this->currentIndex;
  v3 = this->car->body->getPosition;
  if ( (((char *)this->track->startingBounds._Mylast - (char *)this->track->startingBounds._Myfirst) & 0xFFFFFFF8) == 0 )
  {
LABEL_5:
    v6 = (const vec3f *)((int (__stdcall *)(char *, _DWORD))v3)(v18, 0);
    v5 = SplineLocator::locateOnSpline(this->currentSpline, v6, v17);
    goto LABEL_6;
  }
  splinePosition = &this->track->startingBounds;
  v4 = (const vec3f *)((int (__stdcall *)(char *, _DWORD))v3)(v18, 0);
  v5 = SplineLocator::locateOnSplineWithBounds(this->currentSpline, v4, splinePosition, v17);
LABEL_6:
  v7 = this->car;
  this->normalizedPos = v5;
  v8 = this->currentSpline;
  splinePositiona = this->normalizedPos;
  v9 = (const vec3f *)((int (*)(IRigidBody *, char *, _DWORD))v7->body->getPosition)(v7->body, v18, 0);
  v10 = InterpolatingSpline::getSignedDistanceFromSpline(&v8->spline, v9, splinePositiona);
  v11 = this->currentSpline;
  splinePositionb = this->normalizedPos;
  this->offset = v10;
  AISpline::payloadAtPosition(v11, &result, splinePositionb);
  v12 = this->offset;
  v13 = this->car->carHalfWidth * 2.0;
  this->isOutsideLimits = COERCE_FLOAT(LODWORD(result.sides[0]) ^ _xmm) > (float)(v13 - v12)
                       || (float)(COERCE_FLOAT(LODWORD(v12) ^ _xmm) - v13) > result.sides[1];
}
