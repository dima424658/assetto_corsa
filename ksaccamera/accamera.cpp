#include "accamera.h
void ACCamera::ACCamera(ACCamera *this)
{
  this->__vftable = (ACCamera_vtbl *)&ACCamera::`vftable';
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  mat44f::mat44f(&this->matrix);
  this->splineFileName._Myres = 7;
  this->splineFileName._Mysize = 0;
  this->splineFileName._Bx._Buf[0] = 0;
  mat44f::loadIdentity(&this->matrix);
  this->minFov = 30.0;
  this->maxFov = 30.0;
  this->inPoint = -1.0;
  this->outPoint = -1.0;
  std::wstring::assign(&this->name, L"UNNAMED", 7u);
  this->humanizer = 1.0;
  this->shadowSplits[3] = 0.0;
  this->shadowSplits[0] = 1.8;
  this->shadowSplits[1] = 100.0;
  this->shadowSplits[2] = 180.0;
  this->nearPlane = 0.1;
  this->farPlane = 35000.0;
  this->minExposure = 0.0;
  this->maxExposure = 10000.0;
  this->dofFactor = 10.0;
  this->dofRange = 10000.0;
  this->dofFocus = 0.0;
  this->maxDistance = 0.0;
  this->minDistance = 0.0;
  this->splineRotationY = 0.0;
  this->spline = 0;
  this->fovGamma = 0.0;
  this->wasTriggered = 0;
  this->splineAnimationLength = 15.0;
  this->isFixed = 0;
  this->dofManual = 0;
}
ACCamera *ACCamera::`vector deleting destructor'(ACCamera *this, unsigned int a2)
{
  ACCamera::~ACCamera(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACCamera::~ACCamera(ACCamera *this)
{
  this->__vftable = (ACCamera_vtbl *)&ACCamera::`vftable';
  if ( this->splineFileName._Myres >= 8 )
    operator delete(this->splineFileName._Bx._Ptr);
  this->splineFileName._Myres = 7;
  this->splineFileName._Mysize = 0;
  this->splineFileName._Bx._Buf[0] = 0;
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
void ACCamera::ACCamera(ACCamera *this, const ACCamera *__that)
{
  ACCamera *v2; // edi
  std::wstring *v3; // ecx

  v2 = this;
  v3 = &this->name;
  this->__vftable = (ACCamera_vtbl *)&ACCamera::`vftable';
  v3->_Myres = 7;
  v3->_Mysize = 0;
  v3->_Bx._Buf[0] = 0;
  std::wstring::assign(v3, &__that->name, 0, 0xFFFFFFFF);
  *(__m128i *)&v2->matrix.M11 = _mm_loadu_si128((const __m128i *)&__that->matrix);
  *(__m128i *)&v2->matrix.M21 = _mm_loadu_si128((const __m128i *)&__that->matrix.M21);
  *(__m128i *)&v2->matrix.M31 = _mm_loadu_si128((const __m128i *)&__that->matrix.M31);
  *(__m128i *)&v2->matrix.M41 = _mm_loadu_si128((const __m128i *)&__that->matrix.M41);
  v2->maxFov = __that->maxFov;
  v2->minFov = __that->minFov;
  v2->inPoint = __that->inPoint;
  v2->outPoint = __that->outPoint;
  v2->humanizer = __that->humanizer;
  *(__m128i *)v2->shadowSplits = _mm_loadu_si128((const __m128i *)__that->shadowSplits);
  v2->nearPlane = __that->nearPlane;
  v2->farPlane = __that->farPlane;
  v2->minExposure = __that->minExposure;
  v2->maxExposure = __that->maxExposure;
  v2->dofFactor = __that->dofFactor;
  v2->dofFocus = __that->dofFocus;
  v2->dofRange = __that->dofRange;
  v2->dofManual = __that->dofManual;
  v2->maxDistance = __that->maxDistance;
  v2->minDistance = __that->minDistance;
  v2->splineFileName._Myres = 7;
  v2->splineFileName._Mysize = 0;
  v2->splineFileName._Bx._Buf[0] = 0;
  std::wstring::assign(&v2->splineFileName, &__that->splineFileName, 0, 0xFFFFFFFF);
  v2->splineRotationY = __that->splineRotationY;
  v2->spline = __that->spline;
  v2->fovGamma = __that->fovGamma;
  v2->wasTriggered = __that->wasTriggered;
  v2->isCameraStretch = __that->isCameraStretch;
  v2->splineAnimationLength = __that->splineAnimationLength;
  v2->isFixed = __that->isFixed;
}
