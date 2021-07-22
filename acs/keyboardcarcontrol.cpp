#include "keyboardcarcontrol.h"
void __userpurge KeyboardCarControl::KeyboardCarControl(KeyboardCarControl *this@<ecx>, unsigned int a2@<ebx>, Car *carPointer)
{
  std::wstring v4; // [esp-1Ch] [ebp-48h] BYREF
  int v5; // [esp-4h] [ebp-30h]
  KeyboardCarControl *v6; // [esp+Ch] [ebp-20h]
  ksSecurity v7; // [esp+10h] [ebp-1Ch] BYREF
  int v8; // [esp+28h] [ebp-4h]

  v6 = this;
  *(_WORD *)&this->isAutoclutchNeeded = 0;
  this->keyboardEnabled = 1;
  this->ffEnabled = 1;
  this->ffFilter = 0.0;
  this->suppressPenalties = 0;
  v5 = (int)carPointer;
  v8 = 0;
  this->__vftable = (KeyboardCarControl_vtbl *)&KeyboardCarControl::`vftable';
  RaceEngineer::RaceEngineer(&this->eng, (Car *)v5);
  LOBYTE(v8) = 1;
  *(_WORD *)&this->mouseSteering = 0;
  this->oldMouseValue = 0.0;
  this->mouseSpeed = 1000.0;
  this->activeWindow = GetActiveWindow();
  this->isAutoclutchNeeded = 1;
  this->validated = 0;
  ksSecurity::ksSecurity(&v7);
  v5 = 2;
  LOBYTE(v8) = 2;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"base", 4u);
  this->validated = ksSecurity::validate(&v7, v4, v5);
  LOBYTE(v8) = 1;
  ksSecurity::~ksSecurity(&v7);
  this->aiSpline = carPointer->ksPhysics->track->aiSplineRecorder._Myptr;
  *(_WORD *)&carPointer->autoClutch.useAutoOnStart = 257;
  this->intSteer = 0.0;
  this->intGas = 0.0;
  this->car = carPointer;
  this->steerSpeed = 1.1;
  this->gasPedalSpeed = 4.0;
  this->steerDecelerator = 1.0;
  this->steerResetFactor = 1.5;
  this->lookAhead = 8.0;
  this->steerOppositeDirectionFactor = 2.0;
  this->currentSplinePos = -1;
  this->targetSpeed = 0.0;
  this->oldSteer = 0.0;
  this->steerGain = 0.18000001;
  this->speedDeceleringFactor = 1.0;
  this->turnDeceleringFactor = 0.0;
  this->understeerSteerCorrection = 0.0;
  this->minSteering = 0.0;
  this->keyGas = 0;
  this->keyRight = 0;
  this->keyLeft = 0;
  this->keyBrake = 0;
  this->keyGearDown = 0;
  this->keyGearUp = 0;
  this->keyGlanceLeft = 0;
  this->keyGlanceRight = 0;
  this->keyGlanceBack = 0;
  this->keyBrakeBalanceUp = 0;
  this->keyBrakeBalanceDn = 0;
  this->keyAbsUp = 0;
  this->keyAbsDn = 0;
  this->keyTcUp = 0;
  this->keyTcDn = 0;
  this->keyTurboUp = 0;
  this->keyTurboDn = 0;
  this->keyKers = 0;
  this->keyDrs = 0;
  this->keyEngineBrakeUp = 0;
  this->keyEngineBrakeDn = 0;
  this->keyMGUKDeliveryUp = 0;
  this->keyMGUKDeliveryDn = 0;
  this->keyMGUKRecoveryUp = 0;
  this->keyMGUKRecoveryDn = 0;
  this->keyMGUHMode = 0;
  this->keyTurnOnHeadlights = 8;
  this->keyHorn = 9;
  this->keyHandbrake = 120;
  KeyboardCarControl::readFromIni(this, a2);
  GetCursorPos(&this->mouseCoordinates);
}
KeyboardCarControl *KeyboardCarControl::`scalar deleting destructor'(KeyboardCarControl *this, unsigned int a2)
{
  this->__vftable = (KeyboardCarControl_vtbl *)&KeyboardCarControl::`vftable';
  RaceEngineer::~RaceEngineer(&this->eng);
  this->__vftable = (KeyboardCarControl_vtbl *)&ICarControlsProvider::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void KeyboardCarControl::acquireControls(KeyboardCarControl *this, CarControls *controls, float dt, CarControlsInput *input)
{
  bool v5; // zf
  double v7; // st7
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  bool v12; // al
  bool v13; // al
  BOOL v14; // eax
  bool v15; // al
  bool v16; // al
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  bool v24; // al
  bool v25; // al
  bool v26; // al
  bool v27; // al
  bool v28; // al
  bool v29; // al
  bool v30; // al
  float dta; // [esp+20h] [ebp+8h]
  float dtb; // [esp+20h] [ebp+8h]
  float inputa; // [esp+24h] [ebp+Ch]

  if ( this->validated )
  {
    v5 = !this->mouseSteering;
    this->oldSteer = controls->steer;
    if ( v5 )
      v7 = KeyboardCarControl::getKeyboardSteering(this, dt, input);
    else
      v7 = KeyboardCarControl::getMouseSteering(this, dt, input);
    v8 = FLOAT_1_0;
    inputa = v7;
    if ( inputa <= 1.0 )
    {
      v8 = FLOAT_N1_0;
      if ( inputa >= -1.0 )
        v8 = v7;
    }
    controls->steer = v8;
    if ( GetAsyncKeyState(this->keyGas) && this->keyboardEnabled
      || this->mouseSteering && this->mouseAcceleratorBrake && GetAsyncKeyState(1) )
    {
      v9 = FLOAT_1_0;
      dta = KeyboardCarControl::computeGasCoefficient(this, input, dt);
      v10 = dta;
      if ( dta > 1.0 || (v9 = 0.0, dta < 0.0) )
        v10 = v9;
      controls->gas = v10;
    }
    else
    {
      controls->gas = 0.0;
      this->intGas = 0.0;
    }
    if ( GetAsyncKeyState(this->keyBrake) && this->keyboardEnabled
      || this->mouseSteering && this->mouseAcceleratorBrake && GetAsyncKeyState(2) )
    {
      v11 = FLOAT_1_0;
      dtb = RaceEngineer::getOptimalBrake(&this->eng);
      if ( dtb <= 1.0 )
      {
        v11 = 0.0;
        if ( dtb >= 0.0 )
          v11 = dtb;
      }
      controls->brake = v11;
    }
    else
    {
      controls->brake = 0.0;
    }
    v12 = GetAsyncKeyState(this->keyKers) && this->keyboardEnabled;
    controls->kers = v12;
    v13 = GetAsyncKeyState(this->keyDrs) && this->keyboardEnabled;
    controls->drs = v13;
    v14 = GetAsyncKeyState(this->keyHandbrake) && this->keyboardEnabled;
    controls->handBrake = (float)v14;
    v15 = GetAsyncKeyState(this->keyGearUp) && this->keyboardEnabled;
    controls->gearUp = v15;
    v16 = GetAsyncKeyState(this->keyGearDown) && this->keyboardEnabled;
    controls->gearDn = v16;
    v17 = GetAsyncKeyState(this->keyBrakeBalanceUp) && this->keyboardEnabled;
    controls->brakeBalanceUp = v17;
    v18 = GetAsyncKeyState(this->keyBrakeBalanceDn) && this->keyboardEnabled;
    controls->brakeBalanceDn = v18;
    v19 = GetAsyncKeyState(this->keyAbsDn) && this->keyboardEnabled;
    controls->absDn = v19;
    v20 = GetAsyncKeyState(this->keyAbsUp) && this->keyboardEnabled;
    controls->absUp = v20;
    v21 = GetAsyncKeyState(this->keyTcDn) && this->keyboardEnabled;
    controls->tcDn = v21;
    v22 = GetAsyncKeyState(this->keyTcUp) && this->keyboardEnabled;
    controls->tcUp = v22;
    v23 = GetAsyncKeyState(this->keyTurboDn) && this->keyboardEnabled;
    controls->turboDn = v23;
    v24 = GetAsyncKeyState(this->keyTurboUp) && this->keyboardEnabled;
    controls->turboUp = v24;
    v25 = GetAsyncKeyState(this->keyEngineBrakeDn) && this->keyboardEnabled;
    controls->engineBrakeDn = v25;
    v26 = GetAsyncKeyState(this->keyEngineBrakeUp) && this->keyboardEnabled;
    controls->engineBrakeUp = v26;
    v27 = GetAsyncKeyState(this->keyMGUKRecoveryDn) && this->keyboardEnabled;
    controls->MGUKRecoveryDn = v27;
    v28 = GetAsyncKeyState(this->keyMGUKRecoveryUp) && this->keyboardEnabled;
    controls->MGUKRecoveryUp = v28;
    v29 = GetAsyncKeyState(this->keyMGUKDeliveryDn) && this->keyboardEnabled;
    controls->MGUKDeliveryDn = v29;
    v30 = GetAsyncKeyState(this->keyMGUKDeliveryUp) && this->keyboardEnabled;
    controls->MGUKDeliveryUp = v30;
    controls->MGUHMode = GetAsyncKeyState(this->keyMGUHMode) && this->keyboardEnabled;
  }
}
double KeyboardCarControl::computeGasCoefficient(KeyboardCarControl *this, CarControlsInput *input, float dt)
{
  float *v4; // edi
  float *v5; // eax
  bool v6; // bl
  float v7; // xmm1_4
  bool v8; // cc
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v14; // [esp+10h] [ebp-8h]
  Speed result; // [esp+14h] [ebp-4h] BYREF
  float dta; // [esp+20h] [ebp+8h]

  dta = this->gasPedalSpeed * dt;
  v4 = (float *)&RaceEngineer::getRightDrivenTyre(&this->eng)->drivetrain.outShaftL.inertia + 1;
  v5 = (float *)&RaceEngineer::getLeftDrivenTyre(&this->eng)->drivetrain.outShaftL.inertia + 1;
  if ( *v4 > *v5 )
    v5 = v4;
  v14 = *v5;
  v6 = (float)(Car::getSpeed(this->car, &result)->value * 3.5999999) < 100.0;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v7 = this->intGas;
  if ( v6 )
    v8 = v14 <= 0.99;
  else
    v8 = v14 <= 2.0;
  if ( v8 )
  {
    v11 = v7 + dta;
    if ( v11 <= 1.0 )
    {
      if ( v11 < 0.0 )
        v11 = 0.0;
    }
    else
    {
      v11 = FLOAT_1_0;
    }
    this->intGas = v11;
  }
  else
  {
    v9 = v7 - dta;
    if ( v9 <= 1.0 )
    {
      v10 = FLOAT_0_64999998;
      if ( v9 >= 0.64999998 )
        v10 = v9;
      this->intGas = v10;
    }
    else
    {
      this->intGas = FLOAT_1_0;
    }
  }
  v12 = this->intGas;
  if ( v12 > 1.0 )
    return 1.0;
  if ( v12 >= 0.0 )
    return v12;
  return 0.0;
}
bool KeyboardCarControl::getAction(KeyboardCarControl *this, DriverActions anAction)
{
  SHORT v3; // ax
  bool result; // al

  switch ( anAction )
  {
    case eLookingLeft:
      v3 = GetAsyncKeyState(this->keyGlanceLeft);
      goto LABEL_3;
    case eLookingRight:
      v3 = GetAsyncKeyState(this->keyGlanceRight);
      goto LABEL_3;
    case eHeadlightsSwitch:
      v3 = GetAsyncKeyState(this->keyTurnOnHeadlights);
      goto LABEL_3;
    case eChangingCamera:
      v3 = GetAsyncKeyState(this->keyChangeCamera);
      goto LABEL_3;
    case eHorn:
      v3 = GetAsyncKeyState(this->keyHorn);
      goto LABEL_3;
    case eLookingBack:
      v3 = GetAsyncKeyState(this->keyGlanceBack);
      goto LABEL_3;
    case eHeadlightsFlash:
      v3 = GetAsyncKeyState(this->keyFlashHeadlights);
LABEL_3:
      result = v3 && this->keyboardEnabled;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
vec3f *KeyboardCarControl::getCarPositionOnSpline(KeyboardCarControl *this, vec3f *result)
{
  AISpline *v3; // eax
  vec3f *v4; // eax
  AISpline *v5; // eax
  int v6; // esi
  AISpline *v7; // eax
  int v8; // edi
  AISpline *v9; // eax
  AISpline *v10; // eax
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  vec3f p1; // [esp+10h] [ebp-24h] BYREF
  vec3f p2; // [esp+1Ch] [ebp-18h] BYREF
  vec3f carpos; // [esp+28h] [ebp-Ch] BYREF

  v3 = AISplineRecorder::getBestLapSpline(this->aiSpline);
  if ( Spline::pointsCount(&v3->spline) )
  {
    v5 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    v6 = Spline::wrapIndex(&v5->spline, this->currentSplinePos - 1);
    v7 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    v8 = Spline::wrapIndex(&v7->spline, this->currentSplinePos);
    ((void (*)(IRigidBody *, vec3f *, _DWORD))this->car->body->getPosition)(this->car->body, &carpos, 0);
    v9 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    Spline::pointAt(&v9->spline, &p1, v6);
    v10 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    Spline::pointAt(&v10->spline, &p2, v8);
    v11 = 0.0;
    v12 = p2.x - p1.x;
    v13 = p2.z - p1.z;
    v14 = fsqrt((float)(v13 * v13) + (float)(v12 * v12));
    if ( v14 != 0.0 )
    {
      v12 = (float)(1.0 / v14) * v12;
      v11 = (float)(1.0 / v14) * 0.0;
      v13 = (float)(1.0 / v14) * v13;
    }
    v4 = result;
    v15 = (float)((float)((float)(carpos.x - p1.x) * v12) + (float)(v11 * 0.0))
        + (float)((float)(carpos.z - p1.z) * v13);
    v16 = (float)(v15 * v11) + p1.y;
    v17 = (float)(v13 * v15) + p1.z;
    result->x = (float)(v12 * v15) + p1.x;
    result->y = v16;
    result->z = v17;
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
double KeyboardCarControl::getKeyboardSteering(KeyboardCarControl *this, float dt, CarControlsInput *input)
{
  float v5; // [esp+10h] [ebp-4h]
  float targetSteer; // [esp+10h] [ebp-4h]

  this->minSteering = (float)(1.0 / (float)((float)(input->speed.value * 0.5) + 1.0)) * 3.1415927;
  v5 = KeyboardCarControl::stepSteer(this, dt);
  LODWORD(targetSteer) = LODWORD(v5) & _xmm;
  if ( this->minSteering > targetSteer )
    targetSteer = this->minSteering;
  if ( GetAsyncKeyState(this->keyLeft) && this->keyboardEnabled )
    return KeyboardCarControl::steeringMovement(this, targetSteer * -1.0, dt, input);
  if ( GetAsyncKeyState(this->keyRight) && this->keyboardEnabled )
    return KeyboardCarControl::steeringMovement(this, targetSteer, dt, input);
  return KeyboardCarControl::steeringMovement(this, 0.0, dt, input);
}
double KeyboardCarControl::getMouseSteering(KeyboardCarControl *this, float dt, CarControlsInput *input)
{
  tagPOINT *v4; // esi
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  int v8; // eax
  tagRECT activeWindowRect; // [esp+8h] [ebp-14h] BYREF

  v4 = &this->mouseCoordinates;
  GetCursorPos(&this->mouseCoordinates);
  GetWindowRect(this->activeWindow, &activeWindowRect);
  v5 = FLOAT_1_0;
  v6 = (float)(activeWindowRect.left + (activeWindowRect.right - activeWindowRect.left) / 2);
  v7 = (float)((float)((float)v4->x - v6) / this->mouseSpeed) + this->oldMouseValue;
  this->oldMouseValue = v7;
  if ( v7 <= 1.0 )
  {
    v5 = FLOAT_N1_0;
    if ( v7 >= -1.0 )
      v5 = v7;
  }
  v8 = activeWindowRect.bottom - 100;
  this->oldMouseValue = v5;
  SetCursorPos((int)v6, v8);
  return this->oldMouseValue;
}
const char *KeyboardCarControl::getName(KeyboardCarControl *this)
{
  return "Kunos Simulazioni Keyboard controls provider";
}
vec3f *KeyboardCarControl::getPointAtDistance(KeyboardCarControl *this, vec3f *result, float distance, int *pointIndex)
{
  AISpline *v5; // eax
  vec3f *v6; // eax
  AISpline *v7; // eax
  int v8; // ebx
  AISpline *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  AISpline *v12; // eax
  AISpline *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm1_4
  AISpline *v16; // eax
  int v17; // esi
  AISpline *v18; // eax
  AISpline *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm6_4
  __int64 v22; // xmm3_8
  float v23; // xmm7_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm2_4
  AISplineRecorder *v27; // ecx
  float v28; // xmm0_4
  AISpline *v29; // eax
  int v30; // esi
  AISpline *v31; // eax
  float v32; // ecx
  float v33; // [esp+Ch] [ebp-54h]
  vec3f np1; // [esp+10h] [ebp-50h] BYREF
  vec3f np; // [esp+24h] [ebp-3Ch] BYREF
  vec3f nextpos; // [esp+30h] [ebp-30h] BYREF
  vec3f blend1; // [esp+3Ch] [ebp-24h] BYREF
  vec3f blend0; // [esp+48h] [ebp-18h] BYREF
  vec3f nextposMinusOne; // [esp+54h] [ebp-Ch] BYREF

  v5 = AISplineRecorder::getBestLapSpline(this->aiSpline);
  if ( Spline::pointsCount(&v5->spline) )
  {
    v7 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    v8 = Spline::wrapIndex(&v7->spline, this->currentSplinePos + 1);
    KeyboardCarControl::getCarPositionOnSpline(this, &nextpos);
    v9 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    Spline::pointAt(&v9->spline, &np, v8);
    np.y = 0.0;
    v10 = (float)((float)(nextpos.z - np.z) * (float)(nextpos.z - np.z))
        + (float)((float)(nextpos.x - np.x) * (float)(nextpos.x - np.x));
    if ( v10 == 0.0 )
    {
      v11 = 0.0;
      v33 = 0.0;
    }
    else
    {
      v11 = fsqrt(v10);
      v33 = v11;
    }
    if ( distance > v11 )
    {
      do
      {
        v12 = AISplineRecorder::getBestLapSpline(this->aiSpline);
        v8 = Spline::wrapIndex(&v12->spline, v8 + 1);
        v13 = AISplineRecorder::getBestLapSpline(this->aiSpline);
        Spline::pointAt(&v13->spline, &np1, v8);
        np1.y = 0.0;
        v14 = (float)((float)(np1.z - nextpos.z) * (float)(np1.z - nextpos.z))
            + (float)((float)(np1.x - nextpos.x) * (float)(np1.x - nextpos.x));
        if ( v14 == 0.0 )
        {
          v15 = 0.0;
          v33 = 0.0;
        }
        else
        {
          v15 = fsqrt(v14);
          v33 = v15;
        }
        np = np1;
      }
      while ( distance > v15 );
    }
    v16 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    v17 = Spline::wrapIndex(&v16->spline, v8 - 1);
    v18 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    Spline::pointAt(&v18->spline, &blend0, v17);
    v19 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    Spline::pointAt(&v19->spline, &blend1, v8);
    v22 = LODWORD(blend0.x);
    v20 = 0.0;
    v21 = blend1.x;
    *(float *)&v22 = blend0.x - blend1.x;
    v23 = blend1.y;
    v24 = blend0.y - blend1.y;
    v25 = blend0.z - blend1.z;
    *pointIndex = v8;
    v26 = (float)((float)(v24 * v24) + (float)(*(float *)&v22 * *(float *)&v22)) + (float)(v25 * v25);
    if ( v26 != 0.0 )
      v20 = fsqrt(v26);
    v27 = this->aiSpline;
    v28 = (float)(v33 - distance) / v20;
    *(float *)&v22 = (float)(*(float *)&v22 * v28) + v21;
    *(_QWORD *)&np1.x = v22;
    nextpos.z = (float)(v25 * v28) + blend1.z;
    v29 = AISplineRecorder::getBestLapSpline(v27);
    v30 = Spline::wrapIndex(&v29->spline, *pointIndex - 1);
    v31 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    Spline::pointAt(&v31->spline, &nextposMinusOne, v30);
    v6 = result;
    v32 = nextpos.z;
    *(_QWORD *)&result->x = _mm_unpacklo_ps(
                              (__m128)_mm_loadl_epi64((const __m128i *)&np1),
                              (__m128)COERCE_UNSIGNED_INT((float)(v24 * v28) + v23)).m128_u64[0];
    result->z = v32;
  }
  else
  {
    v6 = result;
    result->x = 0.0;
    result->y = 0.0;
    result->z = 0.0;
  }
  return v6;
}
void __usercall KeyboardCarControl::readFromIni(KeyboardCarControl *this@<ecx>, unsigned int a2@<ebx>)
{
  double v3; // st7
  bool v4; // cf
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  int v9; // eax
  double v10; // st7
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  bool v18; // bl
  int v19; // eax
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // edi
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  int v37; // edi
  int v38; // edi
  int v39; // edi
  int v40; // edi
  int v41; // edi
  int v42; // edi
  int v43; // edi
  std::wstring v44; // [esp-1Ch] [ebp-B4h] BYREF
  BOOL v45; // [esp-4h] [ebp-9Ch]
  wchar_t _Right[2]; // [esp+10h] [ebp-88h] BYREF
  std::wstring key; // [esp+14h] [ebp-84h] BYREF
  std::wstring section; // [esp+2Ch] [ebp-6Ch] BYREF
  INIReaderDocuments d; // [esp+44h] [ebp-54h] BYREF
  int v50; // [esp+94h] [ebp-4h]

  v45 = 0;
  v44._Myres = 7;
  v44._Mysize = 0;
  v44._Bx._Buf[0] = 0;
  std::wstring::assign(&v44, L"cfg/controls.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&d, a2, v44, v45);
  v50 = 0;
  if ( d.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEERING_SPEED", 0xEu);
    LOBYTE(v50) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 2;
    v3 = INIReader::getFloat(&d, &section, &key);
    v4 = section._Myres < 8;
    this->steerSpeed = v3;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEERING_OPPOSITE_DIRECTION_SPEED", 0x21u);
    LOBYTE(v50) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 4;
    v5 = INIReader::getFloat(&d, &section, &key);
    v4 = section._Myres < 8;
    this->steerOppositeDirectionFactor = v5;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEER_GAIN", 0xAu);
    LOBYTE(v50) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 6;
    v6 = INIReader::getFloat(&d, &section, &key);
    v4 = section._Myres < 8;
    this->steerGain = v6;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEER_RESET_SPEED", 0x11u);
    LOBYTE(v50) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 8;
    v7 = INIReader::getFloat(&d, &section, &key);
    v4 = section._Myres < 8;
    this->steerResetFactor = v7;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LOOKAHEAD_POINTS", 0x10u);
    LOBYTE(v50) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 10;
    v8 = INIReader::getFloat(&d, &section, &key);
    v4 = section._Myres < 8;
    this->lookAhead = v8;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MOUSE_STEER", 0xBu);
    LOBYTE(v50) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 12;
    v9 = INIReader::getInt(&d, &section, &key);
    v4 = section._Myres < 8;
    this->mouseSteering = v9 > 0;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MOUSE_SPEED", 0xBu);
    LOBYTE(v50) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 14;
    v10 = INIReader::getFloat(&d, &section, &key);
    v4 = section._Myres < 8;
    this->mouseSpeed = v10 * 10000.0;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( this->mouseSpeed == 0.0 )
      this->mouseSpeed = 1000.0;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MOUSE_ACCELERATOR_BRAKE", 0x17u);
    LOBYTE(v50) = 15;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 16;
    v11 = INIReader::getInt(&d, &section, &key);
    v4 = section._Myres < 8;
    this->mouseAcceleratorBrake = v11 > 0;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    INIReader::setVerboseMode(&d, 1);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GAS", 3u);
    LOBYTE(v50) = 17;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KEYBOARD", 8u);
    LOBYTE(v50) = 18;
    v12 = INIReader::getHex(&d, &section, &key);
    v4 = section._Myres < 8;
    this->keyGas = v12;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&section, L"BRAKE");
    LOBYTE(v50) = 19;
    std::wstring::wstring(&key, L"KEYBOARD");
    LOBYTE(v50) = 20;
    v13 = INIReader::getHex(&d, &key, &section);
    v4 = key._Myres < 8;
    this->keyBrake = v13;
    if ( !v4 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"LEFT");
    LOBYTE(v50) = 21;
    std::wstring::wstring(&key, L"KEYBOARD");
    LOBYTE(v50) = 22;
    v14 = INIReader::getHex(&d, &key, &section);
    v4 = key._Myres < 8;
    this->keyLeft = v14;
    if ( !v4 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"RIGHT");
    LOBYTE(v50) = 23;
    std::wstring::wstring(&key, L"KEYBOARD");
    LOBYTE(v50) = 24;
    v15 = INIReader::getHex(&d, &key, &section);
    v4 = key._Myres < 8;
    this->keyRight = v15;
    if ( !v4 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 25;
    std::wstring::wstring(&key, L"GEARUP");
    LOBYTE(v50) = 26;
    v16 = INIReader::getHex(&d, &key, &section);
    v4 = key._Myres < 8;
    this->keyGearUp = v16;
    if ( !v4 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 27;
    std::wstring::wstring(&key, L"GEARDN");
    LOBYTE(v50) = 28;
    v17 = INIReader::getHex(&d, &key, &section);
    v4 = key._Myres < 8;
    this->keyGearDown = v17;
    if ( !v4 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 29;
    std::wstring::wstring(&key, L"HANDBRAKE");
    LOBYTE(v50) = 30;
    v18 = INIReader::getHex(&d, &key, &section) >= 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v18 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v50) = 31;
      std::wstring::wstring(&key, L"HANDBRAKE");
      LOBYTE(v50) = 32;
      v19 = INIReader::getHex(&d, &key, &section);
      v4 = key._Myres < 8;
      this->keyHandbrake = v19;
      if ( !v4 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v50) = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 33;
    std::wstring::wstring(&key, L"KERS");
    LOBYTE(v50) = 34;
    v20 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v20 != -1 )
      this->keyKers = v20;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 35;
    std::wstring::wstring(&key, L"DRS");
    LOBYTE(v50) = 36;
    v21 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v21 != -1 )
      this->keyDrs = v21;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 37;
    std::wstring::wstring(&key, L"GLANCELEFT");
    LOBYTE(v50) = 38;
    v22 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v22 != -1 )
      this->keyGlanceLeft = v22;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 39;
    std::wstring::wstring(&key, L"GLANCERIGHT");
    LOBYTE(v50) = 40;
    v23 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v23 != -1 )
      this->keyGlanceRight = v23;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 41;
    std::wstring::wstring(&key, L"GLANCEBACK");
    LOBYTE(v50) = 42;
    v24 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v24 != -1 )
      this->keyGlanceBack = v24;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 43;
    std::wstring::wstring(&key, L"ACTION_HEADLIGHTS");
    LOBYTE(v50) = 44;
    v25 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v25 != -1 )
      this->keyTurnOnHeadlights = v25;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 45;
    std::wstring::wstring(&key, L"ACTION_HEADLIGHTS_FLASH");
    LOBYTE(v50) = 46;
    v26 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v26 != -1 )
      this->keyFlashHeadlights = v26;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 47;
    std::wstring::wstring(&key, L"ACTION_HORN");
    LOBYTE(v50) = 48;
    v27 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v27 != -1 )
      this->keyHorn = v27;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 49;
    std::wstring::wstring(&key, L"BALANCEUP");
    LOBYTE(v50) = 50;
    v28 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v28 != -1 )
      this->keyBrakeBalanceUp = v28;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 51;
    std::wstring::wstring(&key, L"BALANCEDN");
    LOBYTE(v50) = 52;
    v29 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v29 != -1 )
      this->keyBrakeBalanceDn = v29;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 53;
    std::wstring::wstring(&key, L"ACTION_CHANGE_CAMERA");
    LOBYTE(v50) = 54;
    v30 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v30 != -1 )
      this->keyChangeCamera = v30;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 55;
    std::wstring::wstring(&key, L"ABSUP");
    LOBYTE(v50) = 56;
    v31 = INIReader::getHex(&d, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v50) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    *(_DWORD *)_Right = 0;
    std::char_traits<wchar_t>::assign(section._Bx._Buf, _Right);
    if ( v31 != -1 )
      this->keyAbsUp = v31;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 57;
    std::wstring::wstring(&key, L"ABSDN");
    LOBYTE(v50) = 58;
    v32 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v32 != -1 )
      this->keyAbsDn = v32;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 59;
    std::wstring::wstring(&key, L"TCUP");
    LOBYTE(v50) = 60;
    v33 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v33 != -1 )
      this->keyTcUp = v33;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 61;
    std::wstring::wstring(&key, L"TCDN");
    LOBYTE(v50) = 62;
    v34 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v34 != -1 )
      this->keyTcDn = v34;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 63;
    std::wstring::wstring(&key, L"TURBOUP");
    LOBYTE(v50) = 64;
    v35 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v35 != -1 )
      this->keyTurboUp = v35;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 65;
    std::wstring::wstring(&key, L"TURBODN");
    LOBYTE(v50) = 66;
    v36 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v36 != -1 )
      this->keyTurboDn = v36;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 67;
    std::wstring::wstring(&key, L"ENGINE_BRAKE_UP");
    LOBYTE(v50) = 68;
    v37 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v37 != -1 )
      this->keyEngineBrakeUp = v37;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 69;
    std::wstring::wstring(&key, L"ENGINE_BRAKE_DN");
    LOBYTE(v50) = 70;
    v38 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v38 != -1 )
      this->keyEngineBrakeDn = v38;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 71;
    std::wstring::wstring(&key, L"MGUK_DELIVERY_UP");
    LOBYTE(v50) = 72;
    v39 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v39 != -1 )
      this->keyMGUKDeliveryUp = v39;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 73;
    std::wstring::wstring(&key, L"MGUK_DELIVERY_DN");
    LOBYTE(v50) = 74;
    v40 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v40 != -1 )
      this->keyMGUKDeliveryDn = v40;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 75;
    std::wstring::wstring(&key, L"MGUK_RECOVERY_UP");
    LOBYTE(v50) = 76;
    v41 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v41 != -1 )
      this->keyMGUKRecoveryUp = v41;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 77;
    std::wstring::wstring(&key, L"MGUK_RECOVERY_DN");
    LOBYTE(v50) = 78;
    v42 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v50) = 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v42 != -1 )
      this->keyMGUKRecoveryDn = v42;
    std::wstring::wstring(&section, L"KEY");
    LOBYTE(v50) = 79;
    std::wstring::wstring(&key, L"MGUH_MODE");
    LOBYTE(v50) = 80;
    v43 = INIReader::getHex(&d, &key, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    if ( v43 != -1 )
      this->keyMGUHMode = v43;
  }
  v50 = -1;
  INIReaderDocuments::~INIReaderDocuments(&d);
}
void KeyboardCarControl::setMouseSteering(KeyboardCarControl *this, bool value)
{
  this->mouseSteering = value;
}
double KeyboardCarControl::steeringMovement(KeyboardCarControl *this, const float targetSteer, float dt, CarControlsInput *input)
{
  float v4; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm7_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  double v27; // st7
  Speed result; // [esp+4h] [ebp-8h] BYREF
  float v29; // [esp+8h] [ebp-4h] BYREF

  v4 = FLOAT_1_0;
  v6 = this->intSteer;
  v7 = targetSteer - v6;
  v8 = this->steerSpeed * dt;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(targetSteer - v6) & _xmm) >= v8 )
  {
    v9 = 0.0;
    if ( targetSteer != 0.0 )
    {
      if ( v6 <= 0.0 )
      {
        if ( v6 < 0.0 )
        {
          v11 = FLOAT_N1_0;
          v10 = FLOAT_N1_0;
          goto LABEL_9;
        }
        v10 = 0.0;
      }
      else
      {
        v10 = FLOAT_1_0;
      }
      v11 = FLOAT_N1_0;
LABEL_9:
      if ( targetSteer <= 0.0 )
      {
        if ( targetSteer >= 0.0 )
          v12 = 0.0;
        else
          v12 = v11;
      }
      else
      {
        v12 = FLOAT_1_0;
      }
      if ( v10 != v12 && v6 != 0.0 )
      {
        if ( v7 <= 0.0 )
        {
          if ( v7 < 0.0 )
            v9 = v11;
        }
        else
        {
          v9 = FLOAT_1_0;
        }
        this->intSteer = (float)((float)(v9 * v8) * this->steerOppositeDirectionFactor) + v6;
        goto LABEL_58;
      }
      Car::getSpeed(this->car, &result);
      dt = 0.0;
      v13 = __libm_sse2_expf().m128_f32[0];
      v14 = &dt;
      v29 = (float)(2.0 / (float)(v13 + 1.0)) - 1.0;
      if ( v29 >= 0.0 )
        v14 = &v29;
      v15 = 1.0 - *v14;
      if ( v15 <= 1.0 )
      {
        if ( v15 < 0.1 )
          v15 = FLOAT_0_1;
      }
      else
      {
        v15 = FLOAT_1_0;
      }
      this->speedDeceleringFactor = v15;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      HIBYTE(dt) = (float)(Car::getSpeed(this->car, &result)->value * 3.5999999) > 100.0;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      v4 = FLOAT_1_0;
      if ( HIBYTE(dt) )
      {
        this->steerDecelerator = this->speedDeceleringFactor;
      }
      else
      {
        v16 = COERCE_FLOAT(LODWORD(targetSteer) & _xmm) * 0.63661975;
        if ( v16 <= 1.0 )
        {
          v17 = FLOAT_0_1;
          if ( v16 >= 0.1 )
            v17 = COERCE_FLOAT(LODWORD(targetSteer) & _xmm) * 0.63661975;
        }
        else
        {
          v17 = FLOAT_1_0;
        }
        v18 = this->speedDeceleringFactor;
        this->turnDeceleringFactor = v17;
        this->steerDecelerator = (float)(v18 + v17) * 0.5;
      }
      v19 = this->intSteer;
      v20 = 0.0;
      if ( (float)(targetSteer - v19) <= 0.0 )
      {
        if ( (float)(targetSteer - v19) < 0.0 )
        {
          v21 = FLOAT_N1_0;
          v20 = FLOAT_N1_0;
          goto LABEL_37;
        }
      }
      else
      {
        v20 = FLOAT_1_0;
      }
      v21 = FLOAT_N1_0;
LABEL_37:
      this->intSteer = (float)((float)(v20 * v8) * this->steerDecelerator) + v19;
      goto LABEL_59;
    }
    if ( v7 <= 0.0 )
    {
      if ( v7 < 0.0 )
      {
        v23 = FLOAT_N1_0;
        v22 = FLOAT_N1_0;
LABEL_46:
        this->intSteer = (float)((float)(v22 * v8) * this->steerResetFactor) + v6;
        if ( v6 <= 0.0 )
        {
          if ( v6 >= 0.0 )
            v24 = 0.0;
          else
            v24 = v23;
        }
        else
        {
          v24 = FLOAT_1_0;
        }
        v25 = this->intSteer;
        if ( v25 <= 0.0 )
        {
          if ( v25 < 0.0 )
            v9 = v23;
        }
        else
        {
          v9 = FLOAT_1_0;
        }
        if ( v24 != v9 )
          this->intSteer = 0.0;
        goto LABEL_58;
      }
      v22 = 0.0;
    }
    else
    {
      v22 = FLOAT_1_0;
    }
    v23 = FLOAT_N1_0;
    goto LABEL_46;
  }
  this->intSteer = targetSteer;
LABEL_58:
  v21 = FLOAT_N1_0;
LABEL_59:
  v26 = this->intSteer;
  if ( v26 <= v4 )
  {
    if ( v21 > v26 )
    {
      v27 = v21;
      this->intSteer = v21;
      return v27;
    }
    v4 = this->intSteer;
  }
  v27 = v4;
  this->intSteer = v4;
  return v27;
}
double KeyboardCarControl::stepSteer(KeyboardCarControl *this, float dt)
{
  IRigidBody *v3; // ecx
  AISplineRecorder *v4; // ecx
  AISpline *v5; // eax
  AISpline *v6; // eax
  Car *v7; // ecx
  int v8; // xmm1_4
  int v9; // xmm0_4
  IRigidBody *v10; // ecx
  Car *v11; // ecx
  int v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float distance; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v21; // [esp+Ch] [ebp-A0h]
  int pointIndex; // [esp+14h] [ebp-98h] BYREF
  float v23; // [esp+18h] [ebp-94h]
  float v24; // [esp+1Ch] [ebp-90h]
  float v25; // [esp+20h] [ebp-8Ch]
  float v26; // [esp+24h] [ebp-88h]
  float v27; // [esp+28h] [ebp-84h] BYREF
  vec3f v28; // [esp+2Ch] [ebp-80h] BYREF
  vec3f result; // [esp+3Ch] [ebp-70h] BYREF
  int v30; // [esp+48h] [ebp-64h] BYREF
  int v31[8]; // [esp+4Ch] [ebp-60h] BYREF
  char v32[40]; // [esp+6Ch] [ebp-40h] BYREF
  float v33; // [esp+94h] [ebp-18h]
  float v34; // [esp+98h] [ebp-14h]
  int v35; // [esp+9Ch] [ebp-10h]

  v28.x = 0.0;
  v3 = this->car->body;
  v26 = 0.0;
  v25 = COERCE_FLOAT(v32);
  ((void (*)(IRigidBody *))v3->getWorldMatrix)(v3);
  v4 = this->aiSpline;
  result.y = v33;
  result.z = v34;
  v30 = v35;
  v5 = AISplineRecorder::getBestLapSpline(v4);
  if ( !Spline::pointsCount(&v5->spline) )
  {
    v6 = AISplineRecorder::getBestLapSpline(this->aiSpline);
    this->currentSplinePos = (int)InterpolatingSpline::closestPointIndex(&v6->spline, (vec3f *)&result.y, 0);
  }
  v7 = this->car;
  v24 = COERCE_FLOAT(v31);
  v8 = LODWORD(v7->tyres[0].worldRotation.M33) ^ _xmm;
  v9 = LODWORD(v7->tyres[0].worldRotation.M31) ^ _xmm;
  v31[1] = LODWORD(v7->tyres[0].worldRotation.M32) ^ _xmm;
  v31[0] = v9;
  v31[2] = v8;
  v10 = v7->body;
  v23 = COERCE_FLOAT(&v27);
  ((void (*)(IRigidBody *))v10->worldToLocalNormal)(v10);
  v11 = this->car;
  pointIndex = (int)&result.z;
  v12 = LODWORD(v11->tyres[1].worldRotation.M33) ^ _xmm;
  LODWORD(v13) = LODWORD(v11->tyres[1].worldRotation.M31) ^ _xmm;
  v30 = LODWORD(v11->tyres[1].worldRotation.M32) ^ _xmm;
  result.z = v13;
  v31[0] = v12;
  v11->body->worldToLocalNormal(v11->body, &v28, (vec3f *)&result.z);
  v24 = 0.0;
  v27 = 0.0;
  v14 = fsqrt((float)(COERCE_FLOAT(&v27) * COERCE_FLOAT(&v27)) + (float)(v25 * v25));
  if ( v14 != 0.0 )
  {
    v23 = (float)(1.0 / v14) * COERCE_FLOAT(&v27);
    v24 = (float)(1.0 / v14) * 0.0;
    v25 = (float)(1.0 / v14) * v25;
  }
  v15 = fsqrt((float)(v26 * v26) + (float)(v28.x * v28.x));
  if ( v15 != 0.0 )
  {
    v26 = (float)(1.0 / v15) * v26;
    v27 = (float)(1.0 / v15) * 0.0;
    v28.x = (float)(1.0 / v15) * v28.x;
  }
  distance = this->lookAhead;
  pointIndex = 0;
  KeyboardCarControl::getPointAtDistance(this, &result, distance, &pointIndex);
  this->car->body->worldToLocal(this->car->body, (vec3f *)&v30, &result);
  LODWORD(v21) = COERCE_UNSIGNED_INT(this->steerGain * result.y) ^ _xmm;
  if ( __finite(v21) )
  {
    v17 = v21;
    if ( v21 <= 0.89999998 )
    {
      if ( v21 < -0.89999998 )
        v17 = FLOAT_N0_89999998;
    }
    else
    {
      v17 = FLOAT_0_89999998;
    }
  }
  else
  {
    v17 = 0.0;
  }
  v18 = this->understeerSteerCorrection;
  if ( v18 > 0.0 )
  {
    v19 = (float)(v17 - this->oldSteer) * 0.1;
    this->understeerSteerCorrection = v18 - 1.0;
    v17 = v19 + this->oldSteer;
  }
  if ( v17 > 0.89999998 )
    return 0.89999998;
  if ( v17 >= -0.89999998 )
    return v17;
  return -0.89999998;
}
double KeyboardCarControl::getFFGlobalGain(TyreTester *this)
{
  return 1.0;
}
