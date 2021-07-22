#include "aidriverdrag.h
bool AIDriverDrag::isDeviceConnected(AIDriver *this)
{
  return 0;
}
void AIDriverDrag::AIDriverDrag(AIDriverDrag *this, Car *icar)
{
  Event<vec3f> *v3; // ecx
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  int v6; // eax
  bool v7; // cf
  int v8; // eax
  bool v9; // bl
  double v10; // st7
  bool v11; // bl
  double v12; // st7
  double v13; // st7
  bool v14; // bl
  double v15; // st7
  std::function<void __cdecl(vec3f const &)> v16; // [esp-10h] [ebp-108h] BYREF
  AIDriverDrag *i_4; // [esp+8h] [ebp-F0h]
  AIDriverDrag *v18; // [esp+24h] [ebp-D4h]
  std::wstring key; // [esp+2Ch] [ebp-CCh] BYREF
  std::wstring section; // [esp+44h] [ebp-B4h] BYREF
  std::wstring result; // [esp+5Ch] [ebp-9Ch] BYREF
  std::wstring v22; // [esp+74h] [ebp-84h] BYREF
  INIReader r; // [esp+8Ch] [ebp-6Ch] BYREF
  std::wstring aifilename; // [esp+D0h] [ebp-28h] BYREF
  int v25; // [esp+F4h] [ebp-4h]

  v18 = this;
  *(_WORD *)&this->isAutoclutchNeeded = 0;
  this->keyboardEnabled = 1;
  this->ffEnabled = 1;
  this->ffFilter = 0.0;
  this->suppressPenalties = 0;
  v25 = 0;
  this->__vftable = (AIDriverDrag_vtbl *)&AIDriverDrag::`vftable';
  this->push = 0.0;
  InterpolatingSpline::InterpolatingSpline(&this->spline);
  this->car = icar;
  PIDController::PIDController(&this->pidSteer);
  PIDController::PIDController(&this->pidBrake);
  LOBYTE(v25) = 3;
  PIDController::PIDController(&this->pidGas);
  i_4 = this;
  this->steerSignal = 0.0;
  this->gasSignal = 0.0;
  this->brakeSignal = 0.0;
  this->changeUpRPM = 8000;
  this->changeDnRPM = 4000;
  this->steerGain = 0.050000001;
  this->steerMinLookahead = 12.0;
  this->gasBrakeLookahead = 3.0;
  this->startTime = DOUBLE_1_797693134862316e308;
  this->normalizedSplinePosition = 0.0;
  this->targetOffset = 0.0;
  this->oldSteer = 0.0;
  this->understeerSteerCorrection = 0.0;
  this->maxPush = 100.0;
  this->slipRatioLimit = 10.0;
  v16._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_54699e72027b16b9484512c8c28fa944_,0>,std::allocator<std::_Func_class<void,vec3f const &>>,void,vec3f const &>::`vftable';
  v16._Space._Pfn[1] = (void (__cdecl *)())this;
  v16._Impl = (std::_Func_base<void,vec3f const &> *)&v16;
  v3 = &this->car->evOnForcedPositionCompleted;
  LOBYTE(v25) = 4;
  Event<vec3f>::addHandler(v3, v16, i_4);
  this->changeDnRPM = (int)Engine::getMaxTorqueRPM(&this->car->drivetrain.acEngine);
  v4 = std::operator+<wchar_t>(&result, L"content/cars/", &icar->unixName);
  LOBYTE(v25) = 6;
  v5 = std::operator+<wchar_t>(&v22, v4, L"/data/ai.ini");
  std::wstring::wstring(&aifilename, v5);
  if ( v22._Myres >= 8 )
    operator delete(v22._Bx._Ptr);
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  LOBYTE(v25) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&r, &aifilename);
  LOBYTE(v25) = 9;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"UP", 2u);
    LOBYTE(v25) = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GEARS", 5u);
    LOBYTE(v25) = 11;
    v6 = INIReader::getInt(&r, &section, &key);
    v7 = section._Myres < 8;
    this->changeUpRPM = v6;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 9;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DOWN", 4u);
    LOBYTE(v25) = 12;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GEARS", 5u);
    LOBYTE(v25) = 13;
    v8 = INIReader::getInt(&r, &section, &key);
    v7 = section._Myres < 8;
    this->changeDnRPM = v8;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 9;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEER", 5u);
    LOBYTE(v25) = 14;
    v9 = INIReader::hasSection(&r, &key);
    LOBYTE(v25) = 9;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v9 )
    {
      std::wstring::wstring(&section, L"STEER_GAIN");
      LOBYTE(v25) = 15;
      std::wstring::wstring(&key, L"STEER");
      LOBYTE(v25) = 16;
      v10 = INIReader::getFloat(&r, &key, &section);
      v7 = key._Myres < 8;
      this->steerGain = v10;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 9;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LOOKAHEAD", 9u);
    LOBYTE(v25) = 17;
    v11 = INIReader::hasSection(&r, &key);
    LOBYTE(v25) = 9;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v11 )
    {
      std::wstring::wstring(&section, L"BASE");
      LOBYTE(v25) = 18;
      std::wstring::wstring(&key, L"LOOKAHEAD");
      LOBYTE(v25) = 19;
      v12 = INIReader::getFloat(&r, &key, &section);
      v7 = key._Myres < 8;
      this->steerMinLookahead = v12;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 9;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      std::wstring::wstring(&section, L"GAS_BRAKE_LOOKAHEAD");
      LOBYTE(v25) = 20;
      std::wstring::wstring(&key, L"LOOKAHEAD");
      LOBYTE(v25) = 21;
      v13 = INIReader::getFloat(&r, &key, &section);
      v7 = key._Myres < 8;
      this->gasBrakeLookahead = v13;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 9;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DRAG", 4u);
    LOBYTE(v25) = 22;
    v14 = INIReader::hasSection(&r, &key);
    LOBYTE(v25) = 9;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v14 )
    {
      std::wstring::wstring(&section, L"SLIP_RATIO_LIMIT");
      LOBYTE(v25) = 23;
      std::wstring::wstring(&key, L"DRAG");
      LOBYTE(v25) = 24;
      v15 = INIReader::getFloat(&r, &key, &section);
      v7 = key._Myres < 8;
      this->slipRatioLimit = v15;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 9;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
  }
  this->car->tractionControl.isActive = 0;
  PIDController::setPID(&this->pidSteer, 0.30000001, 0.0, 0.0);
  PIDController::setPID(&this->pidBrake, 1.0, 0.0099999998, 0.0);
  PIDController::setPID(&this->pidGas, 0.30000001, 0.0, 0.001);
  if ( this->slipRatioLimit == 0.0 )
    this->slipRatioLimit = 10.0;
  _printf("DRAG : SLIP RATIO LIMIT %.2f\n", this->slipRatioLimit);
  LOBYTE(v25) = 8;
  INIReader::~INIReader(&r);
  if ( aifilename._Myres >= 8 )
    operator delete(aifilename._Bx._Ptr);
}
AIDriverDrag *AIDriverDrag::`scalar deleting destructor'(AIDriverDrag *this, unsigned int a2)
{
  this->__vftable = (AIDriverDrag_vtbl *)&AIDriverDrag::`vftable';
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->pidGas);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->pidBrake);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->pidSteer);
  InterpolatingSpline::~InterpolatingSpline(&this->spline);
  this->__vftable = (AIDriverDrag_vtbl *)&ICarControlsProvider::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void AIDriverDrag::acquireControls(AIDriverDrag *this, CarControls *controls, float dt, CarControlsInput *input)
{
  int v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  vec3f pos; // [esp+18h] [ebp-4Ch] BYREF
  char v13[64]; // [esp+24h] [ebp-40h] BYREF

  v5 = ((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getWorldMatrix)(this->car->body, v13, 0);
  v6 = *(float *)(v5 + 52);
  v7 = *(float *)(v5 + 56);
  pos.x = *(float *)(v5 + 48);
  pos.y = v6;
  pos.z = v7;
  this->normalizedSplinePosition = InterpolatingSpline::worldToSpline(&this->spline, &pos, -1);
  AIDriverDrag::stepSteer(this, dt);
  AIDriverDrag::stepGasBrake(this, dt);
  AIDriverDrag::stepGears(this, dt, controls);
  v8 = this->steerSignal;
  if ( v8 <= 1.0 )
  {
    v9 = FLOAT_N1_0;
    if ( v8 >= -1.0 )
      v9 = this->steerSignal;
  }
  else
  {
    v9 = FLOAT_1_0;
  }
  controls->steer = v9;
  v10 = this->gasSignal;
  if ( v10 <= 1.0 )
  {
    if ( v10 < 0.0 )
      v10 = 0.0;
  }
  else
  {
    v10 = FLOAT_1_0;
  }
  controls->gas = v10;
  v11 = this->brakeSignal;
  if ( v11 <= 1.0 )
  {
    if ( v11 >= 0.0 )
      controls->brake = v11;
    else
      controls->brake = 0.0;
  }
  else
  {
    controls->brake = FLOAT_1_0;
  }
}
const char *AIDriverDrag::getName(AIDriverDrag *this)
{
  return "KS AI DRAG DRIVER";
}
void AIDriverDrag::setStartTime(AIDriverDrag *this, long double startTime)
{
  this->startTime = (float)((float)((float)this->maxPush - this->push)
                          * (float)((float)((float)_rand() * 0.000030518509) * 50.0))
                  + startTime;
}
void AIDriverDrag::stepGasBrake(AIDriverDrag *this, float dt)
{
  Car *v3; // edx
  double v4; // xmm0_8
  float *v5; // ecx
  bool v6; // cc
  float v7; // xmm1_4
  float *v8; // ecx
  float *v9; // eax
  Car *v10; // [esp-4h] [ebp-2Ch]
  float mslipRear; // [esp+8h] [ebp-20h] BYREF
  float mslipFront; // [esp+Ch] [ebp-1Ch] BYREF
  RaceEngineer eng; // [esp+10h] [ebp-18h] BYREF
  int v14; // [esp+24h] [ebp-4h]

  v10 = this->car;
  this->brakeSignal = 0.0;
  this->gasSignal = 0.0;
  RaceEngineer::RaceEngineer(&eng, v10);
  v3 = this->car;
  v4 = this->startTime;
  v14 = 0;
  if ( (float)(v4 - v3->ksPhysics->physicsTime) <= 0.0 )
  {
    this->gasSignal = 1.0;
    v5 = &v3->tyres[2].status.ndSlip;
    if ( v3->tyres[3].status.ndSlip > v3->tyres[2].status.ndSlip )
      v5 = &v3->tyres[3].status.ndSlip;
    v6 = v3->tyres[1].status.ndSlip <= v3->tyres[0].status.ndSlip;
    v7 = *v5;
    v8 = &v3->tyres[0].status.ndSlip;
    mslipRear = v7;
    if ( !v6 )
      v8 = &v3->tyres[1].status.ndSlip;
    v9 = &mslipRear;
    mslipFront = *v8;
    if ( v7 <= mslipFront )
      v9 = &mslipFront;
    if ( *v9 > this->slipRatioLimit )
      this->gasSignal = 0.5;
  }
  else
  {
    AIDriverDrag::stepGasBrakeStart(this);
  }
  v14 = -1;
  RaceEngineer::~RaceEngineer(&eng);
}
void AIDriverDrag::stepGasBrakeStart(AIDriverDrag *this)
{
  Car *v2; // ecx
  double v3; // xmm0_8
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float diff; // [esp+4h] [ebp-4h]
  float diffa; // [esp+4h] [ebp-4h]

  v2 = this->car;
  v3 = this->startTime;
  this->gasSignal = 0.0;
  v4 = v3 - v2->ksPhysics->physicsTime;
  if ( v4 < 1000.0 )
  {
    diff = (float)this->changeUpRPM;
    v5 = FLOAT_1_0;
    diffa = (diff - Drivetrain::getEngineRPM(&v2->drivetrain)) * 0.001;
    v6 = diffa + this->gasSignal;
    this->gasSignal = v6;
    if ( v6 <= 1.0 )
    {
      v5 = 0.0;
      if ( v6 >= 0.0 )
        v5 = v6;
    }
    this->gasSignal = v5;
  }
  this->brakeSignal = 0.050000001;
}
void AIDriverDrag::stepGears(AIDriverDrag *this, float dt, CarControls *controls)
{
  char v5; // cl
  Car *v6; // edx
  Drivetrain *v7; // ebx
  Speed *v8; // eax
  Car *v9; // eax
  float v10; // xmm0_4
  float *v11; // ecx
  float *v12; // eax
  Car *v13; // eax
  Speed result; // [esp+10h] [ebp-4h] BYREF
  char controlsa; // [esp+1Ch] [ebp+8h]
  float controlsb; // [esp+1Ch] [ebp+8h]

  v5 = 0;
  v6 = this->car;
  v7 = &v6->drivetrain;
  if ( (int)(v6->drivetrain.engine.velocity * 0.1591550715257987 * 60.0) > this->changeUpRPM
    && !controls->gearUp
    && v6->drivetrain.cutOff <= 0.0 )
  {
    if ( Drivetrain::isChangingGear(&v6->drivetrain) )
    {
      v5 = 0;
    }
    else
    {
      v8 = Car::getSpeed(this->car, &result);
      v5 = 1;
      if ( (v8->value < 1.0 || this->car->tyres[2].status.ndSlip < 1.1)
        && (this->car->controls.clutch > 0.99000001 || v7->currentGear == 1) )
      {
        controlsa = 1;
        goto LABEL_12;
      }
    }
  }
  controlsa = 0;
LABEL_12:
  if ( (v5 & 1) != 0 )
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( controlsa )
  {
    *(_WORD *)&controls->gearUp = 1;
  }
  else
  {
    controls->gearUp = 0;
    v9 = this->car;
    v10 = v9->tyres[3].status.ndSlip;
    v11 = &v9->tyres[3].status.ndSlip;
    v12 = &v9->tyres[2].status.ndSlip;
    if ( v10 > *v12 )
      v12 = v11;
    controlsb = *v12;
    controls->gearDn = !Drivetrain::isChangingGear(v7)
                    && (v13 = this->car, v13->controls.clutch > 0.98000002)
                    && v13->controls.gas < 0.1
                    && (double)this->changeDnRPM > v13->drivetrain.engine.velocity * 0.1591550715257987 * 60.0
                    && v7->currentGear > 2
                    && controlsb < 1.1;
  }
}
void AIDriverDrag::stepSteer(AIDriverDrag *this, float dt)
{
  Car *v3; // eax
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float Px; // [esp+Ch] [ebp-20h] BYREF
  float v9; // [esp+10h] [ebp-1Ch]
  vec3f result; // [esp+14h] [ebp-18h] BYREF
  vec3f v11; // [esp+20h] [ebp-Ch] BYREF

  Px = 25.0 / Spline::length(&this->spline) + this->normalizedSplinePosition;
  InterpolatingSpline::splineToWorld(&this->spline, &result, Px);
  v3 = this->car;
  Px = this->targetOffset;
  v3->body->worldToLocal(v3->body, &v11, &result);
  v9 = (float)((float)((float)(v11.x - Px) * -0.050000001) - this->oldSteer) + this->oldSteer;
  Px = v9;
  v4 = FLOAT_0_89999998;
  if ( __fdtest(&Px) <= 0 )
  {
    v5 = v9;
    if ( v9 <= 0.89999998 )
    {
      if ( v9 < -0.89999998 )
        v5 = FLOAT_N0_89999998;
    }
    else
    {
      v5 = FLOAT_0_89999998;
    }
  }
  else
  {
    v5 = 0.0;
  }
  v6 = this->understeerSteerCorrection;
  if ( v6 > 0.0 )
  {
    v7 = this->oldSteer;
    this->understeerSteerCorrection = v6 - 1.0;
    v5 = (float)((float)(v5 - v7) * 0.1) + v7;
  }
  if ( v5 <= 0.89999998 )
  {
    if ( v5 >= -0.89999998 )
      v4 = v5;
    else
      v4 = FLOAT_N0_89999998;
  }
  this->steerSignal = v4;
  this->oldSteer = v4;
}
