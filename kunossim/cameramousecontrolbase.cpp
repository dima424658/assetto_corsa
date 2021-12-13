#include "cameramousecontrolbase.h"
void CameraMouseControlBase::CameraMouseControlBase(CameraMouseControlBase *this, Camera *camera)
{
  this->target = camera;
  this->MOVE_SPEED = 5.0;
  this->MOVE_SPEED_SHIFT = 0.050000001;
  this->MOVE_SPEED_CTRL = 50.0;
  this->__vftable = (CameraMouseControlBase_vtbl *)&CameraMouseControlBase::`vftable';
  *(_WORD *)&this->isVertialStrafeActive = 256;
  this->lastMousePoint.first = 0;
  this->lastMousePoint.second = 0;
  this->moveSpeed = this->MOVE_SPEED;
  this->moveSpeedShift = this->MOVE_SPEED_SHIFT;
  this->moveSpeedCtrl = this->MOVE_SPEED_CTRL;
  this->mouseRotationSpeed = 0.0099999998;
  this->lastMouseDown = 0;
}
void CameraMouseControlBase::~CameraMouseControlBase(CameraMouseControlBase *this)
{
  this->__vftable = (CameraMouseControlBase_vtbl *)&CameraMouseControlBase::`vftable';
}
CameraMouseControlBase *CameraMouseControlBase::`scalar deleting destructor'(CameraMouseControlBase *this, unsigned int a2)
{
  this->__vftable = (CameraMouseControlBase_vtbl *)&CameraMouseControlBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge CameraMouseControlBase::mouseLook(CameraMouseControlBase *this@<ecx>, int a2@<esi>, float dt, float speed)
{
  SHORT v5; // ax
  Camera *v6; // esi
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  Camera *v10; // ecx
  bool v11; // [esp+17h] [ebp-5Dh]
  tagPOINT Point; // [esp+18h] [ebp-5Ch] BYREF
  float rads; // [esp+20h] [ebp-54h]
  __m128 pDeterminant; // [esp+24h] [ebp-50h] BYREF
  mat44f v15; // [esp+34h] [ebp-40h] BYREF

  GetCursorPos(&Point);
  if ( this->useRightButtonForMouseLook )
    v5 = GetAsyncKeyState(2);
  else
    v5 = GetAsyncKeyState(1);
  v11 = v5 != 0;
  if ( v5 && this->lastMouseDown )
  {
    Camera::rotatePitch(
      this->target,
      a2,
      COERCE_FLOAT(COERCE_UNSIGNED_INT(
                     (float)((float)((float)(Point.y - this->lastMousePoint.second) * this->mouseRotationSpeed)
                           * this->target->fov)
                   * 0.016666668) ^ _xmm));
    v6 = this->target;
    rads = (float)((float)((float)(this->lastMousePoint.first - Point.x) * this->mouseRotationSpeed) * v6->fov)
         * 0.016666668;
    mat44f::mat44f(&v15);
    v7 = *(__m128 *)&v6->matrix.M21;
    v8 = *(__m128 *)&v6->matrix.M31;
    v9 = *(__m128 *)&v6->matrix.M41;
    *(__m128 *)&v15.M11 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)&v6->matrix.M11, v7, v8, v9);
    pDeterminant.m128_i32[0] = v7.m128_i32[0];
    v10 = this->target;
    pDeterminant.m128_i32[1] = _mm_shuffle_ps(v7, v7, 85).m128_u32[0];
    *(__m128 *)&v15.M31 = v8;
    *(__m128 *)&v15.M41 = v9;
    pDeterminant.m128_i32[2] = _mm_shuffle_ps(v7, v7, 170).m128_u32[0];
    Camera::rotateOnAxis(v10, (int)this, (int)v6, (const vec3f *)&pDeterminant, rads);
  }
  this->lastMousePoint = (std::pair<long,long>)Point;
  this->lastMouseDown = v11;
}
void CameraMouseControlBase::stepKeyboard(CameraMouseControlBase *this, float dt, float msp)
{
  float v4; // xmm0_4
  float mspa; // [esp+14h] [ebp+8h]

  if ( GetAsyncKeyState(16) )
    v4 = this->moveSpeedShift * msp;
  else
    v4 = msp;
  mspa = v4;
  if ( GetAsyncKeyState(17) )
    mspa = this->moveSpeedCtrl * v4;
  if ( this->isVertialStrafeActive )
  {
    if ( GetAsyncKeyState(34) )
      Camera::moveUpWorld(this->target, COERCE_FLOAT(COERCE_UNSIGNED_INT(dt * mspa) ^ _xmm));
    if ( GetAsyncKeyState(33) )
      Camera::moveUpWorld(this->target, dt * mspa);
  }
  if ( GetAsyncKeyState(38) )
    Camera::moveForward(this->target, dt * mspa);
  if ( GetAsyncKeyState(40) )
    Camera::moveForward(this->target, COERCE_FLOAT(COERCE_UNSIGNED_INT(dt * mspa) ^ _xmm));
  if ( GetAsyncKeyState(37) )
    Camera::moveRight(this->target, COERCE_FLOAT(COERCE_UNSIGNED_INT(dt * mspa) ^ _xmm));
  if ( GetAsyncKeyState(39) )
    Camera::moveRight(this->target, dt * mspa);
}
void CameraMouseControlBase::update(CameraMouseControlBase *this, float deltaT)
{
  CameraMouseControlBase::stepKeyboard(this, deltaT, this->moveSpeed);
  CameraMouseControlBase::mouseLook(this, (int)this, deltaT, 0.0);
}
