#include "caravatar.h"


std::wstring CarAvatar::getCurrentSkin()
{
    return currentSkin;
}

void CarAvatar::armFirstLap()
{
    if (physics)
        sim->physicsAvatar->executeOnPhysicsThread([this]() {
        physics->transponder->armFirstLap();
            });
}

void CarAvatar::checkACD()
{
    std::wstring carFolder = std::wstring{ L"content\\cars\\" } + unixName; // eax
    std::wstring acd = carFolder + L"\\data.acd";
    std::wstring filesMask = carFolder + L"\\data\\*.*"; // eax

    std::vector<std::wstring> files = Path::getFiles(filesMask);

    if (!files.empty() && Path::fileExists(acd))
        for (auto filename : files)
        {
            FolderEncrypter encrypter;
            encrypter.check(acd, filename, carFolder + L"/data/" + filename);

            //dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull, dxFakeMutex, dxFakeAtomicsProvider>, dxtemplateJobListSelfHandler<dxSelfWakeup, dxtemplateJobListContainer<dxFakeLull, dxFakeMutex, dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester*)&v11);
        }
}

void CarAvatar::cycleAbsMode(int value)
{
    std::wstring imessage = L"ABS"; // [esp+10h] [ebp-58h] BYREF
    std::wstring text = L"Not available"; // [esp+28h] [ebp-40h] BYREF

    if (physics && physics->abs.isPresent)
    {
        sim->physicsAvatar->executeOnPhysicsThread([=]() {
            auto& abs = physics->abs;
            if (abs.isPresent)
                abs.cycleMode(value);
            });
    }
    else
    {
        sim->systemMessage->addMessage(imessage, acTranslate(text), SystemMessageType::eABS);
    }
}

bool CarAvatar::cycleERSHeatCharging()
{
    isHeatChargingBatteries = !isHeatChargingBatteries;
    if (!physics)
        sim->physicsAvatar->executeOnPhysicsThread([=]()
            {
                physics->ers.isHeatCharginBattery = isHeatChargingBatteries;
            });

    return isHeatChargingBatteries;
}

std::pair<int, std::wstring> CarAvatar::cycleERSPower(int value)
{
    std::pair<int, std::wstring> result;

    if (value <= 0)
        --currentERSPowerIndex;
    else
        ++currentERSPowerIndex;
        
    if (currentERSPowerIndex < physicsInfo.ersPowerControllerCount && currentERSPowerIndex < 0)
            currentERSPowerIndex = physicsInfo.ersPowerControllerCount - 1;
    else
        currentERSPowerIndex = 0;
    
    if (physics)
    {
        sim->physicsAvatar->executeOnPhysicsThread([this /*, currentERSPowerIndex*/](){
            physics->ers.setPowerController(currentERSPowerIndex);
        });
        
        result.second = physics->ers.ersPowerControllers[currentERSPowerIndex].name;
    }

    result.first = currentERSPowerIndex;
    return result;
}

int CarAvatar::cycleERSRecovery(int value)
{
  int v3; // eax
  int v4; // ecx
  Sim *v5; // ecx
  std::function<void __cdecl(void)> v7; // [esp-18h] [ebp-30h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  if ( value <= 0 )
    --this->currentERSRecovery;
  else
    ++this->currentERSRecovery;
  v3 = this->currentERSRecovery;
  if ( v3 <= 10 )
  {
    if ( v3 < 0 )
      this->currentERSRecovery = 10;
  }
  else
  {
    this->currentERSRecovery = 0;
  }
  if ( this->physics )
  {
    v4 = this->currentERSRecovery;
    v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_974d9a86c9871fad6d80b6bca17690e4_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v7._Space._Alias[4] = __PAIR64__((unsigned int)this, v4);
    v7._Impl = (std::_Func_base<void> *)&v7;
    v5 = this->sim;
    v8 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v5->physicsAvatar, v7);
  }
  return this->currentERSRecovery;
}

int CarAvatar::cycleEngineBrake(int value)
{
  int v3; // eax
  int v4; // ecx
  int v5; // esi
  Sim *v6; // ecx
  std::function<void __cdecl(void)> v8; // [esp-18h] [ebp-30h] BYREF
  int v9; // [esp+14h] [ebp-4h]

  if ( value <= 0 )
    --this->currentEngineBrakeSetting;
  else
    ++this->currentEngineBrakeSetting;
  v3 = this->currentEngineBrakeSetting;
  v4 = this->physicsInfo.engineBrakeSettingsCount;
  if ( v3 < v4 )
  {
    if ( v3 < 0 )
      this->currentEngineBrakeSetting = v4 - 1;
  }
  else
  {
    this->currentEngineBrakeSetting = 0;
  }
  v5 = this->currentEngineBrakeSetting;
  if ( this->physics )
  {
    v8._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_2b0204bce18fed09f12b202c88c6dd7c_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v8._Space._Alias[4] = __PAIR64__((unsigned int)this, v5);
    v8._Impl = (std::_Func_base<void> *)&v8;
    v6 = this->sim;
    v9 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v6->physicsAvatar, v8);
  }
  return v5;
}

void CarAvatar::cycleTcMode(int value)
{
  Car *v3; // eax
  Sim *v4; // ecx
  const std::wstring *v5; // eax
  Sim *v6; // ecx
  std::function<void __cdecl(void)> v7; // [esp-18h] [ebp-80h] BYREF
  std::wstring imessage; // [esp+10h] [ebp-58h] BYREF
  std::wstring text; // [esp+28h] [ebp-40h] BYREF
  std::wstring result; // [esp+40h] [ebp-28h] BYREF
  int v11; // [esp+64h] [ebp-4h]

  v3 = this->physics;
  if ( v3 && v3->tractionControl.isPresent )
  {
    v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_6828820115e812f9ce74b3229486162d_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v7._Space._Alias[4] = __PAIR64__(value, (unsigned int)this);
    v7._Impl = (std::_Func_base<void> *)&v7;
    v4 = this->sim;
    v11 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v4->physicsAvatar, v7);
  }
  else
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Not available", 0xDu);
    v11 = 0;
    imessage._Myres = 7;
    imessage._Mysize = 0;
    imessage._Bx._Buf[0] = 0;
    std::wstring::assign(&imessage, L"TC", 2u);
    LOBYTE(v11) = 1;
    v5 = acTranslate(&result, &text);
    v6 = this->sim;
    LOBYTE(v11) = 2;
    SystemMessage::addMessage(v6->systemMessage, &imessage, v5, eTC);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( imessage._Myres >= 8 )
      operator delete(imessage._Bx._Ptr);
    imessage._Myres = 7;
    imessage._Mysize = 0;
    imessage._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
}

void CarAvatar::forcePosition(const mat44f *matrix)
{
  PitStop *v3; // eax
  __m128 v4; // xmm5
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __m128 v7; // xmm2
  std::function<void __cdecl(void)> v8; // [esp-18h] [ebp-50h] BYREF
  CarAvatar::forcePosition::__l12::<lambda_4bd78b0f57e50f6ac501c7aa7346d468> _Func; // [esp+4h] [ebp-34h] BYREF
  float v10; // [esp+28h] [ebp-10h]
  float v11; // [esp+34h] [ebp-4h]

  if ( !this->guid )
  {
    v3 = this->sim->pitStop;
    if ( v3 )
      v3->state = Finishing;
  }
  if ( this->physics )
  {
    _Func.__this = this;
    v4 = (__m128)LODWORD(matrix->M41);
    v5 = _mm_xor_ps((__m128)LODWORD(matrix->M31), (__m128)(unsigned int)_xmm);
    v6 = (__m128)LODWORD(matrix->M42);
    v7 = (__m128)LODWORD(matrix->M32);
    v10 = matrix->M43;
    LODWORD(v11) = LODWORD(matrix->M33) ^ _xmm;
    _Func.hed.z = v11;
    _Func.pos.z = v10;
    *(_QWORD *)&_Func.hed.x = _mm_unpacklo_ps(v5, _mm_xor_ps(v7, (__m128)(unsigned int)_xmm)).m128_u64[0];
    *(_QWORD *)&_Func.pos.x = _mm_unpacklo_ps(v4, v6).m128_u64[0];
    std::function<void __cdecl (void)>::function<void __cdecl (void)>(&v8, &_Func);
    PhysicsAvatar::executeOnPhysicsThread(this->sim->physicsAvatar, v8);
  }
}

std::pair<unsigned int,unsigned int> *CarAvatar::getABSMode(std::pair<unsigned int,unsigned int> *result)
{
  Car *v2; // ecx
  std::pair<unsigned int,unsigned int> *v3; // eax

  v2 = this->physics;
  if ( v2 )
  {
    ABS::getCurrentMode(&v2->abs, result);
    v3 = result;
  }
  else
  {
    v3 = result;
    result->first = 0;
    result->second = 0;
  }
  return v3;
}

int CarAvatar::getAILapsToComplete()
{
  Car *v1; // eax
  int result; // eax

  v1 = this->physics;
  if ( v1 )
    result = v1->aiLapsToComplete;
  else
    result = -1;
  return result;
}

DriverModel *CarAvatar::getActiveDriverModel()
{
  DriverModel *result; // eax

  if ( this->isDriverHR )
    result = this->driverModel_HR;
  else
    result = this->driverModel_LR;
  return result;
}

bool CarAvatar::getAutoBlip()
{
  Car *v1; // eax
  bool result; // al

  v1 = this->physics;
  if ( v1 )
    result = v1->autoBlip.isActive;
  else
    result = 0;
  return result;
}

bool CarAvatar::getAutoShifter()
{
  Car *v1; // eax
  bool result; // al

  v1 = this->physics;
  if ( v1 )
    result = v1->autoShift.isActive;
  else
    result = 0;
  return result;
}

double CarAvatar::getBallastKG()
{
  Car *v1; // eax
  double result; // st7
  NetCarStateProvider *v3; // eax

  v1 = this->physics;
  if ( v1 )
    return v1->ballastKG;
  v3 = this->netCarStateProvider;
  if ( v3 )
    result = v3->ballastKG;
  else
    result = 0.0;
  return result;
}

CarColliderManager *CarAvatar::getColliderManager()
{
  Car *v1; // eax
  CarColliderManager *result; // eax

  v1 = this->physics;
  if ( v1 )
    result = &v1->colliderManager;
  else
    result = 0;
  return result;
}

ICarControlsProvider *CarAvatar::getControlsProvider()
{
  Car *v1; // ecx
  ICarControlsProvider *result; // eax

  v1 = this->physics;
  if ( v1 )
    result = Car::getControlsProvider(v1);
  else
    result = 0;
  return result;
}

int CarAvatar::getCurrentCompoundIdealPressure(uint16_t tyreIndex)
{
  Car *v2; // esi
  int v3; // edi
  int v4; // ebx
  int result; // eax

  if ( this->guid
    || (v2 = this->physics) == 0
    || (v3 = this->currentTyreCompoundIndex[tyreIndex], v3 < 0)
    || (v4 = tyreIndex, v3 >= (unsigned int)(v2->tyres[v4].compoundDefs._Mylast - v2->tyres[v4].compoundDefs._Myfirst)) )
  {
    result = 0;
  }
  else
  {
    result = (int)v2->tyres[v4].compoundDefs._Myfirst[v3].modelData.idealPressure;
  }
  return result;
}

std::wstring *CarAvatar::getCurrentCompoundShortName()
{
  Car *v2; // esi
  int v3; // ebx
  std::wstring *v4; // ecx

  v2 = this->physics;
  if ( v2
    && (v3 = this->currentTyreCompoundIndex[0], v3 >= 0)
    && v3 < (unsigned int)(v2->tyres[0].compoundDefs._Mylast - v2->tyres[0].compoundDefs._Myfirst) )
  {
    v4 = &v2->tyres[0].compoundDefs._Myfirst[v3].shortName;
  }
  else
  {
    v4 = &this->externalTyreCompoundShortName;
  }
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, v4, 0, 0xFFFFFFFF);
  return result;
}

int CarAvatar::getCurrentCompoundStaticPressure(unsigned uint16_t tyreIndex)
{
  Car *v2; // esi
  int v3; // edi
  int v4; // ebx
  int result; // eax

  if ( this->guid
    || (v2 = this->physics) == 0
    || (v3 = this->currentTyreCompoundIndex[tyreIndex], v3 < 0)
    || (v4 = tyreIndex, v3 >= (unsigned int)(v2->tyres[v4].compoundDefs._Mylast - v2->tyres[v4].compoundDefs._Myfirst)) )
  {
    result = 0;
  }
  else
  {
    result = (int)v2->tyres[v4].compoundDefs._Myfirst[v3].pressureStatic;
  }
  return result;
}

void CarAvatar::getDistancesOnSpline(CarAvatar *car, float *frontDistance, float *backDistance)
{
  AISpline *v4; // eax
  float track_length; // [esp+4h] [ebp+4h]

  *frontDistance = car->physicsState.normalizedSplinePosition - this->physicsState.normalizedSplinePosition;
  *backDistance = this->physicsState.normalizedSplinePosition - car->physicsState.normalizedSplinePosition;
  if ( *frontDistance < 0.0 )
    *frontDistance = *frontDistance + 1.0;
  if ( *backDistance < 0.0 )
    *backDistance = *backDistance + 1.0;
  v4 = TrackAvatar::getAISpline(this->sim->track);
  track_length = Spline::length(&v4->spline);
  *frontDistance = *frontDistance * track_length;
  *backDistance = *backDistance * track_length;
}

std::pair<int,std::wstring > *CarAvatar::getERSPower()
{
  std::wstring *v3; // ecx
  ERSPowerController *v4; // edx

  v3 = &result->second;
  result->first = 0;
  result->second._Myres = 7;
  result->second._Mysize = 0;
  result->second._Bx._Buf[0] = 0;
  if ( this->physics )
  {
    result->first = this->currentERSPowerIndex;
    v4 = &this->physics->ers.ersPowerControllers._Myfirst[this->currentERSPowerIndex];
    if ( v3 != (std::wstring *)v4 )
      std::wstring::assign(v3, &v4->name, 0, 0xFFFFFFFF);
  }
  return result;
}

double CarAvatar::getEdlOutLevel()
{
  Car *v1; // eax
  double result; // st7

  v1 = this->physics;
  if ( v1 )
    result = v1->edl.outLevel;
  else
    result = 0.0;
  return result;
}

double CarAvatar::getFFMult()
{
  Car *v1; // eax
  double result; // st7

  v1 = this->physics;
  if ( v1 )
    result = v1->ffMult;
  else
    result = 0.0;
  return result;
}

double CarAvatar::getGraphicSteerDeg()
{
  Car *v1; // eax
  double result; // st7

  v1 = this->physics;
  result = this->physicsState.steer;
  if ( v1 )
    result = result / v1->steerLock * this->graphicSteerLockDegrees;
  return result;
}

vec3f *CarAvatar::getGraphicsOffset()
{
  vec3f *v2; // eax
  __int64 v3; // xmm0_8
  float v4; // ecx

  v2 = result;
  v3 = *(_QWORD *)&this->graphicsOffset.x;
  v4 = this->graphicsOffset.z;
  *(_QWORD *)&result->x = v3;
  result->z = v4;
  return v2;
}

int CarAvatar::getGuid()
{
  return this->guid;
}

double CarAvatar::getKmPerLiter()
{
  Car *v1; // eax

  v1 = this->physics;
  if ( !v1 )
    return 0.0;
  return (float)(v1->fuelLapEvaluator.totalM * 0.001 / v1->fuelLapEvaluator.totalLiters);
}

double CarAvatar::getPackerRange(int index)
{
  Car *v2; // ecx
  ISuspension *v3; // ecx
  double result; // st7

  v2 = this->physics;
  if ( !v2 )
    return 0.0;
  v3 = v2->suspensions._Myfirst[index];
  v3->getPackerRange(v3);
  return result;
}

PitStopTime *CarAvatar::getPitstopTime(float fuel_requested, bool changeTyres, bool repairBody, bool repairEngine, bool repairSus, bool useRandomizer)
{
  Car *v8; // ecx
  float *v9; // eax
  PitStopTime *v10; // eax
  CarAvatar *v11; // [esp+18h] [ebp-4h] BYREF

  v11 = this;
  v8 = this->physics;
  if ( v8 )
  {
    v11 = 0;
    v9 = &fuel_requested;
    if ( fuel_requested <= 0.0 )
      v9 = (float *)&v11;
    Car::getPitstopTime(v8, result, *v9, changeTyres, repairBody, repairEngine, repairSus, useRandomizer);
    v10 = result;
  }
  else
  {
    v10 = result;
    result->total = 0.0;
    result->tyres = 0.0;
    result->repair = 0.0;
    result->fuel = 0.0;
  }
  return v10;
}

double CarAvatar::getRestrictor()
{
  double result; // st7
  NetCarStateProvider *v2; // eax

  if ( this->physics )
    return Car::getRestrictor(this->physics);
  v2 = this->netCarStateProvider;
  if ( v2 )
    result = v2->restrictor;
  else
    result = 0.0;
  return result;
}

vec3f *CarAvatar::getRoadDirection()
{
  Sim *v2; // eax
  AISpline *v3; // eax
  vec3f point; // [esp+0h] [ebp-Ch] BYREF

  v2 = this->sim;
  point = *(vec3f *)&this->physicsState.worldMatrix.M41;
  v3 = AISplineRecorder::getBestLapSpline(v2->physicsAvatar->engine.track->aiSplineRecorder._Myptr);
  Spline::getSplineDirection(&v3->spline, result, &point);
  return result;
}

std::wstring *CarAvatar::getScreenName()
{
  Car *v2; // ecx

  v2 = this->physics;
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  if ( v2 )
    std::wstring::assign(result, &v2->screenName, 0, 0xFFFFFFFF);
  else
    std::wstring::assign(result, L"REMOTE_CAR", 0xAu);
  return result;
}

SetupManager *CarAvatar::getSetupManager()
{
  Car *v1; // eax
  SetupManager *result; // eax

  v1 = this->physics;
  if ( v1 )
    result = &v1->setupManager;
  else
    result = 0;
  return result;
}

unsigned int CarAvatar::getSpawnPositionIndex(std::wstring setName)
{
  unsigned int result; // eax
  unsigned int v3; // esi

  result = CarRaceInfo::getSpawnPositionIndex(&this->raceInfo, &setName);
  v3 = result;
  if ( setName._Myres >= 8 )
  {
    operator delete(setName._Bx._Ptr);
    result = v3;
  }
  return result;
}

double CarAvatar::getStabilityControl()
{
  Car *v1; // eax
  double result; // st7

  v1 = this->physics;
  if ( v1 )
    result = v1->stabilityControl.gain;
  else
    result = 0.0;
  return result;
}

std::vector<DebugLine> *CarAvatar::getSuspensionDebugLines(std::vector<DebugLine> *result, int index)
{
  ISuspension *v4; // ecx

  v4 = this->physics->suspensions._Myfirst[index];
  v4->getDebugLines(v4, result, &this->physicsState.worldMatrix, &this->physicsState.suspensionMatrix[index]);
  return result;
}

std::pair<unsigned int,unsigned int> *CarAvatar::getTCMode()
{
  Car *v2; // ecx
  std::pair<unsigned int,unsigned int> *v3; // eax

  v2 = this->physics;
  if ( v2 )
  {
    TractionControl::getCurrentMode(&v2->tractionControl, result);
    v3 = result;
  }
  else
  {
    v3 = result;
    result->first = 0;
    result->second = 0;
  }
  return v3;
}

double CarAvatar::getTimeDifferenceOnSpline(CarAvatar *car)
{
  CarAvatar *v2; // edi
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  AISpline *v7; // eax
  float *v8; // eax
  float v9; // xmm0_4
  double result; // st7
  float v11; // xmm0_4
  float v12; // [esp+8h] [ebp-Ch] BYREF
  float v13; // [esp+Ch] [ebp-8h] BYREF
  float v14; // [esp+10h] [ebp-4h]

  v2 = car;
  v4 = this->physicsState.normalizedSplinePosition;
  v5 = car->physicsState.normalizedSplinePosition - v4;
  v6 = v4 - car->physicsState.normalizedSplinePosition;
  *(float *)&car = v5;
  v14 = v6;
  if ( v5 < 0.0 )
    *(float *)&car = v5 + 1.0;
  if ( v6 < 0.0 )
    v14 = v6 + 1.0;
  v7 = TrackAvatar::getAISpline(this->sim->track);
  v13 = Spline::length(&v7->spline);
  v8 = (float *)&car;
  v12 = v13 * *(float *)&car;
  if ( (float)(v13 * v14) <= (float)(v13 * *(float *)&car) )
  {
    v11 = v2->physicsState.speed.value;
    v12 = 0.1;
    *(float *)&car = v11;
    if ( v11 <= 0.1 )
      v8 = &v12;
    car = (CarAvatar *)(COERCE_UNSIGNED_INT((float)(v13 * v14) / *v8) ^ _xmm);
    result = *(float *)&car * 1000.0;
  }
  else
  {
    v9 = this->physicsState.speed.value;
    v13 = 0.1;
    *(float *)&car = v9;
    if ( v9 <= 0.1 )
      v8 = &v13;
    result = v12 / *v8 * 1000.0;
  }
  return result;
}

TimeTransponder *CarAvatar::getTimeTransponder()
{
  Car *v1; // eax
  TimeTransponder *result; // eax

  v1 = this->physics;
  if ( v1 )
    result = &v1->transponder;
  else
    result = 0;
  return result;
}

std::wstring *CarAvatar::getTyreCompound(unsigned int index, bool fullname)
{
  int v4; // edx
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  Car *v7; // esi

  if ( fullname )
  {
    v4 = this->currentTyreCompoundIndex[index];
    v5 = this->physicsInfo.tyreCompounds._Myfirst;
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, &v5[v4], 0, 0xFFFFFFFF);
    v6 = result;
  }
  else
  {
    v7 = this->physics;
    if ( v7 && index < v7->tyres[0].compoundDefs._Mylast - v7->tyres[0].compoundDefs._Myfirst )
    {
      std::wstring::wstring(result, &v7->tyres[0].compoundDefs._Myfirst[index].shortName);
      v6 = result;
    }
    else
    {
      result->_Myres = 7;
      result->_Mysize = 0;
      result->_Bx._Buf[0] = 0;
      std::wstring::assign(result, word_17BE9D8, 0);
      v6 = result;
    }
  }
  return v6;
}

int CarAvatar::getTyreCompoundIndex(unsigned int tyre_index)
{
  return this->currentTyreCompoundIndex[tyre_index];
}

double CarAvatar::getUserFFGain()
{
  return this->userFFGain;
}

double CarAvatar::getWingAngle(int wingIndex)
{
  Car *v2; // ecx
  int v3; // eax
  Wing *v4; // ecx
  double result; // st7

  v2 = this->physics;
  if ( !v2 )
    return 0.0;
  v3 = wingIndex;
  v4 = v2->aeroMap.wings._Myfirst;
  if ( v4[wingIndex].data.hasController )
    result = v4[v3].status.inputAngle;
  else
    result = v4[v3].status.angle;
  return result;
}

//----- (005C93D0) --------------------------------------------------------
void CarAvatar::goToSpawnPosition(const std::wstring *setName)
{
  const std::wstring *v3; // eax
  unsigned int v4; // eax
  Car *v5; // ecx
  mat44f pos; // [esp+8h] [ebp-40h] BYREF

  if ( setName->_Myres < 8 )
    v3 = setName;
  else
    v3 = (const std::wstring *)setName->_Bx._Ptr;
  _printf("goToSpawnPosition %S\n", v3->_Bx._Buf);
  v4 = CarRaceInfo::getSpawnPositionIndex(&this->raceInfo, setName);
  TrackAvatar::getSpawnPosition(this->sim->track, &pos, setName, v4);
  v5 = this->physics;
  if ( v5 )
    FuelLapEvaluator::setIgnoreLap(&v5->fuelLapEvaluator, 1);
  CarAvatar::forcePosition(this, &pos);
}

//----- (005C9450) --------------------------------------------------------
long double CarAvatar::hasPenalty()
{
  Car *v1; // ecx
  long double result; // st7

  v1 = this->physics;
  if ( v1 )
    result = Car::getPenaltyTime(v1);
  else
    result = 0.0;
  return result;
}

//----- (005C9470) --------------------------------------------------------
void CarAvatar::init3D(std::wstring skin)
{
  unsigned int v3; // ebx
  std::wstring *v4; // ecx
  ICollisionObject *v5; // esi
  NodeBoundingSphere *v6; // eax
  Sim *v7; // ecx
  CarNodeSorter *v8; // ecx
  wchar_t *v9; // esi
  Node *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  vec3f *v13; // eax
  bool v14; // cf
  wchar_t *v15; // eax
  int v16; // eax
  int v17; // esi
  wchar_t *v18; // eax
  int v19; // eax
  wchar_t *v20; // esi
  Node *v21; // eax
  wchar_t *v22; // eax
  ConstrainedObjectsManager *v23; // eax
  wchar_t *v24; // eax
  CarLodManager *v25; // eax
  CarLodManager *v26; // esi
  ICollisionObject *v27; // esi
  std::wstring *v28; // eax
  vec3f *v29; // eax
  std::wstring *v30; // eax
  std::wstring *v31; // eax
  std::wstring *v32; // eax
  const std::wstring *v33; // eax
  std::wstring *v34; // eax
  vec3f *v35; // eax
  double v36; // st7
  double v37; // st7
  NodeBoundingSphere *v38; // edx
  unsigned int v39; // esi
  Node *v40; // ecx
  NodeBoundingSphere *v41; // ecx
  Node *v42; // eax
  Node *v43; // eax
  Node *v44; // eax
  NodeBoundingSphere *v45; // ecx
  Node *v46; // eax
  Node *v47; // eax
  wchar_t *v48; // eax
  ICollisionObject *v49; // eax
  ICollisionObject *v50; // esi
  wchar_t *v51; // eax
  ICollisionObject *v52; // eax
  ICollisionObject *v53; // esi
  std::wstring v54; // [esp-18h] [ebp-1C0h] BYREF
  float radius; // [esp+0h] [ebp-1A8h]
  ICollisionObject *_Val; // [esp+18h] [ebp-190h] BYREF
  int v57; // [esp+1Ch] [ebp-18Ch]
  ICollisionObject *v58; // [esp+20h] [ebp-188h] BYREF
  std::wstring n; // [esp+24h] [ebp-184h] BYREF
  std::wstring key; // [esp+3Ch] [ebp-16Ch] BYREF
  std::wstring section; // [esp+54h] [ebp-154h] BYREF
  std::wstring result; // [esp+6Ch] [ebp-13Ch] BYREF
  std::wstring v63; // [esp+84h] [ebp-124h] BYREF
  std::wstring ini; // [esp+9Ch] [ebp-10Ch] BYREF
  std::wstring v65; // [esp+B4h] [ebp-F4h] BYREF
  INIReader r; // [esp+CCh] [ebp-DCh] BYREF
  INIReaderDocuments rCustom; // [esp+110h] [ebp-98h] BYREF
  INIReader carini; // [esp+154h] [ebp-54h] BYREF
  int v69; // [esp+1A4h] [ebp-4h]

  v3 = 0;
  _Val = 0;
  v4 = &this->currentSkin;
  v69 = 0;
  if ( v4 != &skin )
    std::wstring::assign(v4, &skin, 0, 0xFFFFFFFF);
  *(double *)v63._Bx._Buf = ksGetTime();
  v58 = (ICollisionObject *)*(double *)v63._Bx._Buf;
  v5 = (ICollisionObject *)operator new(228);
  _Val = v5;
  v6 = 0;
  LOBYTE(v69) = 1;
  if ( v5 )
  {
    radius = 4.0;
    v54._Myres = 7;
    v54._Mysize = 0;
    v54._Bx._Buf[0] = 0;
    std::wstring::assign(&v54, L"CARNODE", 7u);
    NodeBoundingSphere::NodeBoundingSphere((NodeBoundingSphere *)v5, v54, radius);
  }
  v7 = this->sim;
  LODWORD(radius) = this;
  this->carNode = v6;
  v54._Myres = (unsigned int)v6;
  v8 = v7->carsNode;
  LOBYTE(v69) = 0;
  CarNodeSorter::addCar(v8, v6, (CarAvatar *)LODWORD(radius));
  v9 = (wchar_t *)operator new(188);
  v63._Bx._Ptr = v9;
  v10 = 0;
  LOBYTE(v69) = 2;
  if ( v9 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"BODYTR", 6u);
    LOBYTE(v69) = 3;
    v3 = 1;
    _Val = (ICollisionObject *)1;
    Node::Node((Node *)v9, &n);
  }
  this->bodyTransform = v10;
  v69 = 0;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  CarAvatar::initDriver(this, v3);
  v11 = std::operator+<wchar_t>(&result, L"content/cars/", &this->unixName);
  LOBYTE(v69) = 5;
  v12 = std::operator+<wchar_t>(&key, v11, L"/data/car.ini");
  LOBYTE(v69) = 6;
  CarAvatar::openINI(this, &carini, v12);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v69) = 9;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"MIRROR_POSITION", 0xFu);
  LOBYTE(v69) = 10;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"GRAPHICS", 8u);
  LOBYTE(v69) = 11;
  v13 = INIReader::getFloat3(&carini, (vec3f *)&v63, &section, &n);
  v14 = section._Myres < 8;
  this->mirrorPosition = *v13;
  if ( !v14 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v69) = 9;
  if ( n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"USE_ANIMATED_SUSPENSIONS", 0x18u);
  LOBYTE(v69) = 12;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"GRAPHICS", 8u);
  LOBYTE(v69) = 13;
  HIBYTE(v57) = INIReader::getInt(&carini, &section, &n) != 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v69) = 9;
  if ( n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  if ( HIBYTE(v57) )
  {
    _printf("USING ANIMATED SUSPENSIONS\n");
    v15 = (wchar_t *)operator new(132);
    v63._Bx._Ptr = v15;
    LOBYTE(v69) = 14;
    if ( v15 )
    {
      SuspensionAnimator::SuspensionAnimator((SuspensionAnimator *)v15, this);
      v17 = v16;
      goto LABEL_28;
    }
  }
  else
  {
    _printf("USING PHYSICS DRIVEN SUSPENSIONS\n");
    v18 = (wchar_t *)operator new(124);
    v63._Bx._Ptr = v18;
    LOBYTE(v69) = 15;
    if ( v18 )
    {
      SuspensionAvatar::SuspensionAvatar((SuspensionAvatar *)v18, this);
      v17 = v19;
      goto LABEL_28;
    }
  }
  v17 = 0;
LABEL_28:
  LOBYTE(v69) = 9;
  _Val = (ICollisionObject *)v17;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
  *(_DWORD *)(v17 + 36) = this;
  LODWORD(radius) = 188;
  this->suspensionAvatar = (ISuspensionAvatar *)(v17 + 52);
  v20 = (wchar_t *)operator new(LODWORD(radius));
  v63._Bx._Ptr = v20;
  v21 = 0;
  LOBYTE(v69) = 16;
  if ( v20 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"STEER_TRANSFORM", 0xFu);
    LOBYTE(v69) = 17;
    v3 |= 2u;
    _Val = (ICollisionObject *)v3;
    Node::Node((Node *)v20, &n);
  }
  this->steerTransformHR = v21;
  v69 = 9;
  if ( (v3 & 2) != 0 && n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  this->bodyTransform->addChild(this->bodyTransform, this->steerTransformHR);
  this->carNode->addChild(this->carNode, this->bodyTransform);
  v22 = (wchar_t *)operator new(68);
  v63._Bx._Ptr = v22;
  LOBYTE(v69) = 19;
  if ( v22 )
    ConstrainedObjectsManager::ConstrainedObjectsManager((ConstrainedObjectsManager *)v22, this);
  else
    v23 = 0;
  LODWORD(radius) = 100;
  LOBYTE(v69) = 9;
  this->constrainedObjectManager = v23;
  v24 = (wchar_t *)operator new(LODWORD(radius));
  v63._Bx._Ptr = v24;
  LOBYTE(v69) = 20;
  if ( v24 )
  {
    CarLodManager::CarLodManager((CarLodManager *)v24, this);
    v26 = v25;
  }
  else
  {
    v26 = 0;
  }
  LOBYTE(v69) = 9;
  LODWORD(radius) = &_Val;
  this->lodManager = v26;
  _Val = (ICollisionObject *)v26;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)LODWORD(radius));
  v26->parent = this;
  _Val = (ICollisionObject *)this->constrainedObjectManager;
  v27 = _Val;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
  LODWORD(radius) = 13;
  v27[9].__vftable = (ICollisionObject_vtbl *)this;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"content/cars/", LODWORD(radius));
  LOBYTE(v69) = 21;
  v28 = std::operator+<wchar_t>(&v65, &section, &this->unixName);
  LOBYTE(v69) = 22;
  std::operator+<wchar_t>(&ini, v28, L"/data/car.ini");
  if ( v65._Myres >= 8 )
    operator delete(v65._Bx._Ptr);
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  LOBYTE(v69) = 25;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Bx._Buf[0] = 0;
  section._Mysize = 0;
  CarAvatar::openINI(this, &r, &ini);
  LOBYTE(v69) = 26;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"DRIVEREYES", 0xAu);
  LOBYTE(v69) = 27;
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"GRAPHICS", 8u);
  LOBYTE(v69) = 28;
  v29 = INIReader::getFloat3(&r, (vec3f *)&v63, &n, &key);
  v14 = n._Myres < 8;
  this->driverEyesPosition = *v29;
  if ( !v14 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  LOBYTE(v69) = 26;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  this->mirrorPosition.y = this->driverEyesPosition.y;
  this->mirrorPosition.z = this->driverEyesPosition.z;
  v30 = Path::getDocumentPath(&v63);
  LOBYTE(v69) = 29;
  v31 = std::operator+<wchar_t>(&n, v30, L"/Assetto Corsa/cfg/cars/");
  LOBYTE(v69) = 30;
  v32 = std::operator+<wchar_t>(&key, v31, &this->unixName);
  LOBYTE(v69) = 31;
  v33 = std::operator+<wchar_t>(&result, v32, L"/view.ini");
  LOBYTE(v69) = 32;
  LOBYTE(v3) = Path::fileExists(v3, v33, 0);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  LOBYTE(v69) = 26;
  if ( v63._Myres >= 8 )
    operator delete(v63._Bx._Ptr);
  if ( (_BYTE)v3 )
  {
    radius = 0.0;
    v34 = std::operator+<wchar_t>(&result, L"cfg/cars/", &this->unixName);
    LOBYTE(v69) = 33;
    std::operator+<wchar_t>(&v54, v34, L"/view.ini");
    INIReaderDocuments::INIReaderDocuments(&rCustom, v3, v54, SLOBYTE(radius));
    LOBYTE(v69) = 35;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( rCustom.ready )
    {
      std::wstring::wstring(&n, L"DRIVEREYES");
      LOBYTE(v69) = 36;
      std::wstring::wstring(&key, L"DRIVER_EYES_POSITION");
      LOBYTE(v69) = 37;
      v35 = INIReader::getFloat3(&rCustom, (vec3f *)&v63, &key, &n);
      v14 = key._Myres < 8;
      this->driverEyesPosition = *v35;
      if ( !v14 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( n._Myres >= 8 )
        operator delete(n._Bx._Ptr);
    }
    LOBYTE(v69) = 26;
    INIReaderDocuments::~INIReaderDocuments(&rCustom);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ONBOARD_EXPOSURE", 0x10u);
  LOBYTE(v69) = 38;
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"GRAPHICS", 8u);
  LOBYTE(v69) = 39;
  v36 = INIReader::getFloat(&r, &n, &key);
  v14 = n._Myres < 8;
  this->onBoardExposure = v36;
  if ( !v14 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  LOBYTE(v69) = 26;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->onBoardExposure == 0.0 )
    this->onBoardExposure = 40.0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"OUTBOARD_EXPOSURE", 0x11u);
  LOBYTE(v69) = 40;
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"GRAPHICS", 8u);
  LOBYTE(v69) = 41;
  v37 = INIReader::getFloat(&r, &n, &key);
  v14 = n._Myres < 8;
  this->outBoardExposure = v37;
  if ( !v14 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  LOBYTE(v69) = 26;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->outBoardExposure == 0.0 )
    this->outBoardExposure = 40.0;
  *(double *)v63._Bx._Buf = ksGetTime();
  v38 = this->carNode;
  v39 = (unsigned int)*(double *)v63._Bx._Buf;
  v40 = this->bodyTransform;
  radius = 0.0;
  v38->delegateNode = v40;
  NodeBoundingSphere::applyNoCull(this->carNode, (Node *)LODWORD(radius));
  CarAvatar::initMirrorMaterials(this);
  _printf("CAR LOADED IN %u\n", v39 - (_DWORD)v58);
  if ( this->sim->isRoomVR )
  {
    std::wstring::wstring(&result, L"CINTURE_ON");
    v41 = this->carNode;
    LOBYTE(v69) = 42;
    v42 = v41->findChildByName(v41, &result, 1);
    v14 = result._Myres < 8;
    this->beltOnNode = v42;
    LOBYTE(v69) = 26;
    if ( !v14 )
      operator delete(result._Bx._Ptr);
    v43 = this->beltOnNode;
    if ( v43 )
    {
      v43->isActive = 0;
      v44 = this->beltOnNode;
LABEL_85:
      v44->parent->removeChild(v44->parent, v44);
      goto LABEL_86;
    }
  }
  else
  {
    std::wstring::wstring(&result, L"CINTURE_OFF");
    v45 = this->carNode;
    LOBYTE(v69) = 43;
    v46 = v45->findChildByName(v45, &result, 1);
    v14 = result._Myres < 8;
    this->beltOffNode = v46;
    LOBYTE(v69) = 26;
    if ( !v14 )
      operator delete(result._Bx._Ptr);
    v47 = this->beltOffNode;
    if ( v47 )
    {
      v47->isActive = 0;
      v44 = this->beltOffNode;
      goto LABEL_85;
    }
  }
LABEL_86:
  v48 = (wchar_t *)operator new(128);
  v63._Bx._Ptr = v48;
  LOBYTE(v69) = 44;
  if ( v48 )
  {
    VisualDamageManager::VisualDamageManager((VisualDamageManager *)v48, this);
    v50 = v49;
  }
  else
  {
    v50 = 0;
  }
  LOBYTE(v69) = 26;
  v58 = v50;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &v58);
  LODWORD(radius) = 68;
  v50[9].__vftable = (ICollisionObject_vtbl *)this;
  v51 = (wchar_t *)operator new(LODWORD(radius));
  v63._Bx._Ptr = v51;
  LOBYTE(v69) = 45;
  if ( v51 )
  {
    RotatingObjects::RotatingObjects((RotatingObjects *)v51, this);
    v53 = v52;
  }
  else
  {
    v53 = 0;
  }
  LOBYTE(v69) = 26;
  v58 = v53;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &v58);
  v53[9].__vftable = (ICollisionObject_vtbl *)this;
  makeTyresDoubleFacedShadows(this->carNode);
  LOBYTE(v69) = 25;
  INIReader::~INIReader(&r);
  if ( ini._Myres >= 8 )
    operator delete(ini._Bx._Ptr);
  ini._Myres = 7;
  ini._Mysize = 0;
  ini._Bx._Buf[0] = 0;
  LOBYTE(v69) = 0;
  INIReader::~INIReader(&carini);
  if ( skin._Myres >= 8 )
    operator delete(skin._Bx._Ptr);
}

void __usercall CarAvatar::initCameraCar(@<ecx>, __m128 a2@<xmm0>)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  int v5; // edi
  std::wostream *v6; // eax
  const std::wstring *v7; // eax
  char v8; // al
  int v9; // eax
  std::wstring *v10; // ecx
  std::wostream *v11; // eax
  std::vector<CameraCarDefinition> *v12; // eax
  int v13; // esi
  CameraCarDefinition *v14; // eax
  std::wostream *v15; // eax
  const std::wstring *v16; // eax
  char v17; // al
  const std::wstring *v18; // eax
  const std::wstring *v19; // eax
  const std::wstring *v20; // eax
  const std::wstring *v21; // eax
  const std::wstring *v22; // eax
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm7_4
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  float v30; // xmm0_4
  __m128 v31; // xmm1
  __m128 v32; // xmm0
  float v33; // xmm7_4
  float v34; // xmm0_4
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  float v37; // xmm1_4
  __m128 v38; // xmm0
  float v39; // xmm0_4
  float v40; // xmm7_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm0_4
  CameraCarDefinition *v44; // esi
  __m128i v45; // xmm0
  __m128i v46; // xmm0
  __m128i v47; // xmm0
  const std::wstring *v48; // eax
  const std::wstring *v49; // eax
  int v50; // eax
  bool v51; // cf
  CameraCarDefinition *v52; // eax
  int v53; // eax
  CameraCarDefinition *v54; // eax
  int v55; // eax
  int v56; // [esp+4h] [ebp-314h]
  int v57; // [esp+4h] [ebp-314h]
  char v58[4]; // [esp+18h] [ebp-300h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v59; // [esp+1Ch] [ebp-2FCh] BYREF
  CameraCarDefinition v60; // [esp+CCh] [ebp-24Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v61; // [esp+118h] [ebp-200h] BYREF
  vec3f v62; // [esp+1C8h] [ebp-150h] BYREF
  std::vector<CameraCarDefinition> *v63; // [esp+1D4h] [ebp-144h]
  vec3f v64; // [esp+1D8h] [ebp-140h] BYREF
  float v65; // [esp+1E4h] [ebp-134h]
  int v66; // [esp+1E8h] [ebp-130h]
  CarAvatar *v67; // [esp+1ECh] [ebp-12Ch]
  int v68; // [esp+1F0h] [ebp-128h]
  int v69; // [esp+1F4h] [ebp-124h]
  vec3f v70; // [esp+1F8h] [ebp-120h] BYREF
  float v71; // [esp+204h] [ebp-114h]
  float v72; // [esp+208h] [ebp-110h]
  float v73; // [esp+20Ch] [ebp-10Ch]
  float v74; // [esp+210h] [ebp-108h]
  float v75; // [esp+214h] [ebp-104h]
  int v76; // [esp+218h] [ebp-100h]
  std::wstring v77; // [esp+21Ch] [ebp-FCh] BYREF
  INIReader v78; // [esp+234h] [ebp-E4h] BYREF
  std::wstring result; // [esp+278h] [ebp-A0h] BYREF
  std::wstring v80; // [esp+290h] [ebp-88h] BYREF
  std::wstring _Left; // [esp+2A8h] [ebp-70h] BYREF
  std::wstring v82; // [esp+2C0h] [ebp-58h] BYREF
  std::wstring v83; // [esp+2D8h] [ebp-40h] BYREF
  std::wstring key; // [esp+2F0h] [ebp-28h] BYREF
  int v85; // [esp+314h] [ebp-4h]

  v67 = this;
  v66 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v85 = 0;
  v3 = std::operator+<wchar_t>(&result, &_Left, &this->unixName);
  LOBYTE(v85) = 1;
  v4 = std::operator+<wchar_t>(&v80, v3, L"/data/cameras.ini");
  LOBYTE(v85) = 2;
  CarAvatar::openINI(this, &v78, v4);
  if ( v80._Myres >= 8 )
    operator delete(v80._Bx._Ptr);
  v80._Myres = 7;
  v80._Mysize = 0;
  v80._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v85) = 6;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  v5 = 0;
  *(_DWORD *)v61.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v61.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v61.gap68);
  LOBYTE(v85) = 7;
  v66 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v61, &v61.gap10[8], 0);
  v85 = 8;
  *(_DWORD *)&v61.gap0[*(_DWORD *)(*(_DWORD *)v61.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)(&v60.externalSound + *(_DWORD *)(*(_DWORD *)v61.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v61.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v61.gap10[8]);
  *(_DWORD *)&v61.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v61.gap10[64] = 0;
  *(_DWORD *)&v61.gap10[68] = 0;
  LOBYTE(v85) = 10;
  v6 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v61.gap10, "CAMERA_");
  std::wostream::operator<<(v6, 0);
  if ( v78.ready )
  {
    while ( 1 )
    {
      v7 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v61, &v83);
      LOBYTE(v85) = 11;
      v8 = INIReader::hasSection(&v78, v7);
      HIBYTE(v76) = v8;
      LOBYTE(v85) = 10;
      if ( v83._Myres >= 8 )
      {
        operator delete(v83._Bx._Ptr);
        v8 = HIBYTE(v76);
      }
      if ( !v8 )
        break;
      v82._Myres = 7;
      v82._Mysize = 0;
      ++v5;
      v82._Bx._Buf[0] = 0;
      std::wstring::assign(&v82, word_17BE9D8, 0);
      LOBYTE(v85) = 12;
      if ( (v61.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v61.gap10[8]) )
          std::wstreambuf::epptr(&v61.gap10[8]);
        else
          std::wstreambuf::egptr(&v61.gap10[8]);
        std::wstreambuf::eback(&v61.gap10[8]);
        v9 = std::wstreambuf::eback(&v61.gap10[8]);
        operator delete(v9);
      }
      std::wstreambuf::setg(&v61.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v61.gap10[8], 0, 0);
      v10 = &v82;
      *(_DWORD *)&v61.gap10[64] = 0;
      v56 = *(_DWORD *)&v61.gap10[68] & 0xFFFFFFFE;
      if ( v82._Myres >= 8 )
        v10 = (std::wstring *)v82._Bx._Ptr;
      *(_DWORD *)&v61.gap10[68] &= 0xFFFFFFFE;
      std::wstringbuf::_Init((std::wstringbuf *)&v61.gap10[8], v10->_Bx._Buf, v82._Mysize, v56);
      LOBYTE(v85) = 10;
      if ( v82._Myres >= 8 )
        operator delete(v82._Bx._Ptr);
      v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v61.gap10, "CAMERA_");
      std::wostream::operator<<(v11, v5);
    }
    if ( v5 > 6 )
      v5 = 6;
  }
  v69 = 0;
  if ( v5 > 0 )
  {
    v12 = &this->cameras;
    v13 = 0;
    v63 = v12;
    v68 = 0;
    do
    {
      CameraCarDefinition::CameraCarDefinition(&v60, a2);
      std::vector<CameraCarDefinition>::push_back(v63, v14);
      if ( v78.ready )
      {
        *(_DWORD *)v59.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v59.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v59.gap68);
        v66 |= 2u;
        LOBYTE(v85) = 13;
        std::wiostream::basic_iostream<wchar_t>(&v59, &v59.gap10[8], 0);
        v85 = 14;
        *(_DWORD *)&v59.gap0[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)&v58[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4)] = *(_DWORD *)(*(_DWORD *)v59.gap0 + 4) - 104;
        std::wstreambuf::wstreambuf(&v59.gap10[8]);
        *(_DWORD *)&v59.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v59.gap10[64] = 0;
        *(_DWORD *)&v59.gap10[68] = 0;
        v57 = v69;
        LOBYTE(v85) = 16;
        v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v59.gap10, "CAMERA_");
        std::wostream::operator<<(v15, v57);
        v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v77);
        LOBYTE(v85) = 17;
        v17 = INIReader::hasSection(&v78, v16);
        HIBYTE(v76) = v17;
        LOBYTE(v85) = 16;
        if ( v77._Myres >= 8 )
        {
          operator delete(v77._Bx._Ptr);
          v17 = HIBYTE(v76);
        }
        if ( v17 )
        {
          mat44f::mat44f((mat44f *)&v60.matrix.M14);
          mat44f::loadIdentity((mat44f *)&v60.matrix.M14);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"POSITION", 8u);
          LOBYTE(v85) = 18;
          v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v83);
          LOBYTE(v85) = 19;
          INIReader::getFloat3(&v78, &v62, v18, &key);
          if ( v83._Myres >= 8 )
            operator delete(v83._Bx._Ptr);
          v83._Myres = 7;
          v83._Mysize = 0;
          v83._Bx._Buf[0] = 0;
          LOBYTE(v85) = 16;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"FORWARD", 7u);
          LOBYTE(v85) = 20;
          v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v83);
          LOBYTE(v85) = 21;
          INIReader::getFloat3(&v78, &v64, v19, &key);
          if ( v83._Myres >= 8 )
            operator delete(v83._Bx._Ptr);
          v83._Myres = 7;
          v83._Mysize = 0;
          v83._Bx._Buf[0] = 0;
          LOBYTE(v85) = 16;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"UP", 2u);
          LOBYTE(v85) = 22;
          v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v83);
          LOBYTE(v85) = 23;
          INIReader::getFloat3(&v78, &v70, v20, &key);
          if ( v83._Myres >= 8 )
            operator delete(v83._Bx._Ptr);
          v83._Myres = 7;
          v83._Mysize = 0;
          v83._Bx._Buf[0] = 0;
          LOBYTE(v85) = 16;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"FOV", 3u);
          LOBYTE(v85) = 24;
          v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v83);
          LOBYTE(v85) = 25;
          v71 = INIReader::getFloat(&v78, v21, &key);
          if ( v83._Myres >= 8 )
            operator delete(v83._Bx._Ptr);
          v83._Myres = 7;
          v83._Mysize = 0;
          v83._Bx._Buf[0] = 0;
          LOBYTE(v85) = 16;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"EXPOSURE", 8u);
          LOBYTE(v85) = 26;
          v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v83);
          LOBYTE(v85) = 27;
          v72 = INIReader::getFloat(&v78, v22, &key);
          if ( v83._Myres >= 8 )
            operator delete(v83._Bx._Ptr);
          v83._Myres = 7;
          v83._Mysize = 0;
          v83._Bx._Buf[0] = 0;
          LOBYTE(v85) = 16;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          v65 = v71;
          if ( v71 <= 0.0 )
            v65 = FLOAT_60_0;
          v71 = v72;
          if ( v72 <= 0.0 )
            v71 = FLOAT_40_0;
          v23 = v64.x;
          v24 = v64.y;
          v25 = v64.z;
          v26 = fsqrt((float)((float)(v23 * v23) + (float)(v24 * v24)) + (float)(v25 * v25));
          if ( v26 != 0.0 )
          {
            v23 = (float)(1.0 / v26) * v64.x;
            v24 = (float)(1.0 / v26) * v64.y;
            v64.x = v23;
            v64.y = v24;
            v25 = (float)(1.0 / v26) * v64.z;
            v64.z = v25;
          }
          v27 = v70.x;
          v28 = (__m128)LODWORD(v70.y);
          v29 = (__m128)LODWORD(v70.z);
          v74 = v70.x;
          v73 = v70.z;
          v30 = fsqrt((float)((float)(v27 * v27) + (float)(v28.m128_f32[0] * v28.m128_f32[0])) + (float)(v70.z * v70.z));
          if ( v30 != 0.0 )
          {
            v31 = (__m128)LODWORD(FLOAT_1_0);
            v31.m128_f32[0] = 1.0 / v30;
            v27 = (float)(1.0 / v30) * v70.x;
            v32 = v31;
            v31.m128_f32[0] = v31.m128_f32[0] * v70.z;
            v32.m128_f32[0] = v32.m128_f32[0] * v70.y;
            v29 = v31;
            v74 = v27;
            v73 = v31.m128_f32[0];
            v28 = v32;
          }
          v29.m128_f32[0] = (float)(v29.m128_f32[0] * v24) - (float)(v28.m128_f32[0] * v25);
          v33 = (float)(v27 * v25) - (float)(v73 * v23);
          v28.m128_f32[0] = (float)(v28.m128_f32[0] * v23) - (float)(v74 * v24);
          v34 = fsqrt(
                  (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v33 * v33))
                + (float)(v28.m128_f32[0] * v28.m128_f32[0]));
          if ( v34 != 0.0 )
          {
            v35 = (__m128)LODWORD(FLOAT_1_0);
            v35.m128_f32[0] = 1.0 / v34;
            v36 = v35;
            v36.m128_f32[0] = v35.m128_f32[0] * v29.m128_f32[0];
            v29 = v36;
            v36.m128_f32[0] = v35.m128_f32[0] * v33;
            v35.m128_f32[0] = v35.m128_f32[0] * v28.m128_f32[0];
            v33 = v36.m128_f32[0];
            v28 = v35;
          }
          v37 = (float)(v33 * v25) - (float)(v28.m128_f32[0] * v24);
          v38 = v29;
          v28.m128_f32[0] = (float)(v28.m128_f32[0] * v23) - (float)(v29.m128_f32[0] * v25);
          v38.m128_f32[0] = v37;
          *(float *)&v82._Myres = (float)(v29.m128_f32[0] * v24) - (float)(v33 * v23);
          *(_QWORD *)&v70.x = _mm_unpacklo_ps(v38, v28).m128_u64[0];
          v70.z = *(float *)&v82._Myres;
          v39 = fsqrt(
                  (float)((float)(v37 * v37) + (float)(v28.m128_f32[0] * v28.m128_f32[0]))
                + (float)(*(float *)&v82._Myres * *(float *)&v82._Myres));
          if ( v39 == 0.0 )
          {
            v41 = v70.z;
            v40 = v70.y;
            v42 = v70.x;
          }
          else
          {
            v40 = (float)(1.0 / v39) * v70.y;
            v41 = (float)(1.0 / v39) * v70.z;
            v42 = (float)(1.0 / v39) * v37;
            v70.y = v40;
            v70.z = v41;
            v70.x = v42;
          }
          v72 = v41;
          v74 = (float)(v41 * v24) - (float)(v40 * v25);
          v75 = (float)(v42 * v25) - (float)(v41 * v23);
          v73 = (float)(v40 * v23) - (float)(v42 * v24);
          v43 = fsqrt((float)((float)(v74 * v74) + (float)(v75 * v75)) + (float)(v73 * v73));
          if ( v43 != 0.0 )
          {
            v74 = (float)(1.0 / v43) * v74;
            v75 = (float)(1.0 / v43) * v75;
            v73 = (float)(1.0 / v43) * v73;
          }
          v60.matrix.M24 = v42;
          v60.matrix.M31 = v40;
          v44 = v67->cameras._Mylast;
          v60.matrix.M14 = v74;
          v60.matrix.M21 = v75;
          v60.matrix.M22 = v73;
          *(vec3f *)&v60.matrix.M44 = v62;
          v45 = _mm_loadu_si128((const __m128i *)&v60.matrix.M14);
          v60.matrix.M32 = v41;
          *(__m128i *)&v44[-1].matrix.M11 = v45;
          v46 = _mm_loadu_si128((const __m128i *)&v60.matrix.M24);
          key._Myres = 7;
          LODWORD(v60.matrix.M34) = LODWORD(v23) ^ _xmm;
          *(__m128i *)&v44[-1].matrix.M21 = v46;
          key._Mysize = 0;
          LODWORD(v60.matrix.M41) = LODWORD(v24) ^ _xmm;
          LODWORD(v60.matrix.M42) = LODWORD(v25) ^ _xmm;
          v47 = _mm_loadu_si128((const __m128i *)&v60.matrix.M34);
          key._Bx._Buf[0] = 0;
          *(__m128i *)&v44[-1].matrix.M31 = v47;
          *(__m128i *)&v44[-1].matrix.M41 = _mm_loadu_si128((const __m128i *)&v60.matrix.M44);
          v44[-1].fov = v65;
          a2 = (__m128)LODWORD(v71);
          v44[-1].exposure = v71;
          std::wstring::assign(&key, L"EXTERNAL_SOUND", 0xEu);
          LOBYTE(v85) = 28;
          v48 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v83);
          LOBYTE(v85) = 29;
          HIBYTE(v76) = INIReader::hasKey(&v78, v48, &key);
          if ( v83._Myres >= 8 )
            operator delete(v83._Bx._Ptr);
          v83._Myres = 7;
          v83._Mysize = 0;
          v83._Bx._Buf[0] = 0;
          LOBYTE(v85) = 16;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          if ( HIBYTE(v76) )
          {
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
            std::wstring::assign(&key, L"EXTERNAL_SOUND", 0xEu);
            LOBYTE(v85) = 30;
            v49 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v83);
            LOBYTE(v85) = 31;
            v50 = INIReader::getInt(&v78, v49, &key);
            v51 = v83._Myres < 8;
            v44[-1].externalSound = v50 != 0;
            if ( !v51 )
              operator delete(v83._Bx._Ptr);
            v83._Myres = 7;
            v83._Mysize = 0;
            v83._Bx._Buf[0] = 0;
            if ( key._Myres >= 8 )
              operator delete(key._Bx._Ptr);
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
          }
          v13 = v68;
        }
        else
        {
          a2 = (__m128)COERCE_UNSIGNED_INT((float)v13);
          v52 = v67->cameras._Mylast;
          LODWORD(v52[-1].matrix.M41) = a2.m128_i32[0];
          v52[-1].matrix.M42 = 4.0;
          v52[-1].matrix.M43 = -4.0;
        }
        LOBYTE(v85) = 10;
        *(_DWORD *)&v59.gap0[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)&v58[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4)] = *(_DWORD *)(*(_DWORD *)v59.gap0 + 4) - 104;
        *(_DWORD *)&v59.gap10[8] = &std::wstringbuf::`vftable';
        if ( (v59.gap10[68] & 1) != 0 )
        {
          if ( std::wstreambuf::pptr(&v59.gap10[8]) )
            std::wstreambuf::epptr(&v59.gap10[8]);
          else
            std::wstreambuf::egptr(&v59.gap10[8]);
          std::wstreambuf::eback(&v59.gap10[8]);
          v53 = std::wstreambuf::eback(&v59.gap10[8]);
          operator delete(v53);
        }
        std::wstreambuf::setg(&v59.gap10[8], 0, 0, 0);
        std::wstreambuf::setp(&v59.gap10[8], 0, 0);
        *(_DWORD *)&v59.gap10[68] &= 0xFFFFFFFE;
        *(_DWORD *)&v59.gap10[64] = 0;
        std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v59.gap10[8]);
        std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v59.gap10[16]);
        std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v59.gap68);
      }
      else
      {
        a2 = (__m128)COERCE_UNSIGNED_INT((float)v13);
        v54 = v67->cameras._Mylast;
        LODWORD(v54[-1].matrix.M41) = a2.m128_i32[0];
        v54[-1].matrix.M42 = 4.0;
        v54[-1].matrix.M43 = -4.0;
      }
      v68 = --v13;
      ++v69;
    }
    while ( v69 < v5 );
  }
  LOBYTE(v85) = 6;
  *(_DWORD *)&v61.gap0[*(_DWORD *)(*(_DWORD *)v61.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)(&v60.externalSound + *(_DWORD *)(*(_DWORD *)v61.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v61.gap0 + 4) - 104;
  *(_DWORD *)&v61.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v61.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v61.gap10[8]) )
      std::wstreambuf::epptr(&v61.gap10[8]);
    else
      std::wstreambuf::egptr(&v61.gap10[8]);
    std::wstreambuf::eback(&v61.gap10[8]);
    v55 = std::wstreambuf::eback(&v61.gap10[8]);
    operator delete(v55);
  }
  std::wstreambuf::setg(&v61.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v61.gap10[8], 0, 0);
  *(_DWORD *)&v61.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v61.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v61.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v61.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v61.gap68);
  v85 = -1;
  INIReader::~INIReader(&v78);
}

void CarAvatar::initCommon()
{
  char v2; // bl
  std::wstring *v3; // ebp
  std::wstring *v4; // edi
  std::wstring *v5; // eax
  char v6; // al
  std::wstring *v7; // ebp
  std::wstring *v8; // eax
  vec3f *v9; // eax
  bool v10; // cf
  double v11; // st7
  char v12; // al
  int v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  const std::wstring *v17; // eax
  Sim *v18; // ecx
  RaceEngineer *v19; // ecx
  bool v20; // zf
  ICollisionObject *v21; // eax
  ICollisionObject *v22; // eax
  ICollisionObject *v23; // ebx
  ICollisionObject *v24; // eax
  ICollisionObject *v25; // eax
  ICollisionObject *v26; // ebx
  ICollisionObject *v27; // eax
  ICollisionObject *v28; // eax
  ICollisionObject *v29; // ebx
  ICollisionObject *v30; // eax
  ICollisionObject *v31; // eax
  ICollisionObject *v32; // ebx
  ICollisionObject *v33; // eax
  ICollisionObject *v34; // eax
  ICollisionObject *v35; // ebx
  ICollisionObject *v36; // eax
  ICollisionObject *v37; // eax
  ICollisionObject *v38; // ebx
  ICollisionObject *v39; // eax
  ICollisionObject *v40; // eax
  ICollisionObject *v41; // ebx
  ICollisionObject *v42; // eax
  ICollisionObject *v43; // eax
  ICollisionObject *v44; // ebx
  std::wstring v45; // [esp-1Ch] [ebp-160h] BYREF
  int v46; // [esp-4h] [ebp-148h]
  ICollisionObject *_Val; // [esp+14h] [ebp-130h] BYREF
  char v48; // [esp+1Bh] [ebp-129h]
  std::wstring key; // [esp+1Ch] [ebp-128h] BYREF
  std::wstring v50; // [esp+34h] [ebp-110h] BYREF
  std::wstring section; // [esp+4Ch] [ebp-F8h] BYREF
  std::wstring result; // [esp+64h] [ebp-E0h] BYREF
  std::wstring carINIPath; // [esp+7Ch] [ebp-C8h] BYREF
  INIReader carINI; // [esp+94h] [ebp-B0h] BYREF
  std::wstring v55; // [esp+D8h] [ebp-6Ch] BYREF
  INIReaderDocuments ini; // [esp+F0h] [ebp-54h] BYREF
  int v57; // [esp+140h] [ebp-4h]

  v2 = 0;
  v3 = &this->unixName;
  v4 = &this->guiName;
  _Val = 0;
  if ( &this->guiName != &this->unixName )
    std::wstring::assign(&this->guiName, &this->unixName, 0, 0xFFFFFFFF);
  v5 = std::operator+<wchar_t>(&result, L"content/cars/", v3);
  v57 = 0;
  std::operator+<wchar_t>(&carINIPath, v5, L"/data/car.ini");
  LOBYTE(v57) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  CarAvatar::openINI(this, &carINI, &carINIPath);
  LOBYTE(v57) = 3;
  _Val = (ICollisionObject *)1;
  if ( carINI.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"VERSION", 7u);
    LOBYTE(v57) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v57) = 5;
    v48 = INIReader::hasKey(&carINI, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v57) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v48 )
    {
      std::wstring::wstring(&v50, L"VERSION");
      LOBYTE(v57) = 6;
      std::wstring::wstring(&key, L"HEADER");
      LOBYTE(v57) = 7;
      _Val = (ICollisionObject *)(unsigned __int16)INIReader::getInt(&carINI, &key, &v50);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v57) = 3;
      if ( v50._Myres >= 8 )
        operator delete(v50._Bx._Ptr);
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"INFO", 4u);
    LOBYTE(v57) = 8;
    v6 = INIReader::hasSection(&carINI, &key);
    v48 = v6;
    LOBYTE(v57) = 3;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v6 = v48;
    }
    if ( v6 )
    {
      std::wstring::wstring(&section, L"SCREEN_NAME");
      LOBYTE(v57) = 9;
      std::wstring::wstring(&key, L"INFO");
      LOBYTE(v57) = 10;
      v7 = INIReader::getString(&carINI, &v50, &key, &section);
      if ( v4 != v7 )
      {
        if ( v4->_Myres >= 8 )
          operator delete(v4->_Bx._Ptr);
        v4->_Myres = 7;
        v4->_Mysize = 0;
        v46 = (int)v7;
        v4->_Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(v4, (std::wstring *)v46);
      }
      if ( v50._Myres >= 8 )
        operator delete(v50._Bx._Ptr);
      v50._Myres = 7;
      v50._Mysize = 0;
      v50._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v57) = 3;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      if ( &this->guiShortName != v4 )
        std::wstring::assign(&this->guiShortName, v4, 0, 0xFFFFFFFF);
      if ( (__int16)_Val > 1 )
      {
        std::wstring::wstring(&section, L"SHORT_NAME");
        LOBYTE(v57) = 11;
        std::wstring::wstring(&key, L"INFO");
        LOBYTE(v57) = 12;
        v8 = INIReader::getString(&carINI, &v50, &key, &section);
        std::wstring::operator=(&this->guiShortName, v8);
        if ( v50._Myres >= 8 )
          operator delete(v50._Bx._Ptr);
        v50._Myres = 7;
        v50._Mysize = 0;
        v50._Bx._Buf[0] = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        LOBYTE(v57) = 3;
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
      }
      v3 = &this->unixName;
    }
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    std::wstring::assign(&v50, L"GRAPHICS_OFFSET", 0xFu);
    LOBYTE(v57) = 13;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BASIC", 5u);
    LOBYTE(v57) = 14;
    v9 = INIReader::getFloat3(&carINI, (vec3f *)&section, &key, &v50);
    v10 = key._Myres < 8;
    this->graphicsOffset = *v9;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v57) = 3;
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    std::wstring::assign(&v50, L"GRAPHICS_PITCH_ROTATION", 0x17u);
    LOBYTE(v57) = 15;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BASIC", 5u);
    LOBYTE(v57) = 16;
    v11 = INIReader::getFloat(&carINI, &key, &v50);
    v10 = key._Myres < 8;
    this->graphicsPitchRotation = v11 * 0.017453;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v57) = 3;
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
  }
  v46 = 0;
  v45._Myres = 7;
  v45._Mysize = 0;
  v45._Bx._Buf[0] = 0;
  std::wstring::assign(&v45, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&ini, 0, v45, v46);
  LOBYTE(v57) = 17;
  if ( !ini.ready )
    goto LABEL_48;
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  std::wstring::assign(&v50, L"ACTIVE", 6u);
  LOBYTE(v57) = 18;
  _Val = (ICollisionObject *)1;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"DOWNSHIFT_PROTECTION_NOTIFICATION", 0x21u);
  v57 = 19;
  v2 = 3;
  _Val = (ICollisionObject *)3;
  v12 = INIReader::hasKey(&ini, &key, &v50);
  v48 = 1;
  if ( !v12 )
LABEL_48:
    v48 = 0;
  if ( (v2 & 2) != 0 )
  {
    v2 &= 0xFDu;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v57 = 17;
  if ( (v2 & 1) != 0 && v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  if ( v48 )
  {
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    std::wstring::assign(&v50, L"ACTIVE", 6u);
    LOBYTE(v57) = 20;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DOWNSHIFT_PROTECTION_NOTIFICATION", 0x21u);
    LOBYTE(v57) = 21;
    v13 = INIReader::getInt(&ini, &key, &v50);
    v10 = key._Myres < 8;
    this->showDownShiftProtetion = v13 == 1;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v57) = 17;
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
  }
  this->currentTyreCompoundIndex[0] = 0;
  this->currentTyreCompoundIndex[1] = 0;
  this->currentTyreCompoundIndex[2] = 0;
  this->currentTyreCompoundIndex[3] = 0;
  this->guid = CarAvatar::guidCounter++;
  v14 = std::to_wstring(&v55, this->guid + 1);
  LOBYTE(v57) = 22;
  v15 = std::operator+<wchar_t>(&section, L"Loading Car ", v14);
  LOBYTE(v57) = 23;
  v16 = std::operator+<wchar_t>(&key, v15, L": ");
  LOBYTE(v57) = 24;
  v17 = std::operator+<wchar_t>(&v50, v16, v4);
  v18 = this->sim;
  LOBYTE(v57) = 25;
  Sim::setSplashMessage(v18, v17);
  if ( v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v57) = 17;
  if ( v55._Myres >= 8 )
    operator delete(v55._Bx._Ptr);
  Sim::setSplashLoadingCar(this->sim, v3);
  this->physics = 0;
  v19 = this->raceEngineer._Myptr;
  this->raceEngineer._Myptr = 0;
  if ( v19 )
    ((void (*)(RaceEngineer *, int))v19->~RaceEngineer)(v19, 1);
  v20 = this->guid == 0;
  this->nonReplayPhysicsStateProvider = 0;
  this->isDriverHR = 1;
  if ( v20 )
  {
    v21 = (ICollisionObject *)operator new(64);
    _Val = v21;
    LOBYTE(v57) = 26;
    if ( v21 )
    {
      BrakeBiasNotifier::BrakeBiasNotifier((BrakeBiasNotifier *)v21, this);
      v23 = v22;
    }
    else
    {
      v23 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v23;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v46 = 64;
    v23[9].__vftable = (ICollisionObject_vtbl *)this;
    v24 = (ICollisionObject *)operator new(v46);
    _Val = v24;
    LOBYTE(v57) = 27;
    if ( v24 )
    {
      TractionControlNotifier::TractionControlNotifier((TractionControlNotifier *)v24, this);
      v26 = v25;
    }
    else
    {
      v26 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v26;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v46 = 64;
    v26[9].__vftable = (ICollisionObject_vtbl *)this;
    v27 = (ICollisionObject *)operator new(v46);
    _Val = v27;
    LOBYTE(v57) = 28;
    if ( v27 )
    {
      AbsNotifier::AbsNotifier((AbsNotifier *)v27, this);
      v29 = v28;
    }
    else
    {
      v29 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v29;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v46 = 64;
    v29[9].__vftable = (ICollisionObject_vtbl *)this;
    v30 = (ICollisionObject *)operator new(v46);
    _Val = v30;
    LOBYTE(v57) = 29;
    if ( v30 )
    {
      TurboBoostNotifier::TurboBoostNotifier((TurboBoostNotifier *)v30, this);
      v32 = v31;
    }
    else
    {
      v32 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v32;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v46 = 64;
    v32[9].__vftable = (ICollisionObject_vtbl *)this;
    v33 = (ICollisionObject *)operator new(v46);
    _Val = v33;
    LOBYTE(v57) = 30;
    if ( v33 )
    {
      EngineBrakeNotifier::EngineBrakeNotifier((EngineBrakeNotifier *)v33, this);
      v35 = v34;
    }
    else
    {
      v35 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v35;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v46 = 64;
    v35[9].__vftable = (ICollisionObject_vtbl *)this;
    v36 = (ICollisionObject *)operator new(v46);
    _Val = v36;
    LOBYTE(v57) = 31;
    if ( v36 )
    {
      MGUKDeliveryNotifier::MGUKDeliveryNotifier((MGUKDeliveryNotifier *)v36, this);
      v38 = v37;
    }
    else
    {
      v38 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v38;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v46 = 64;
    v38[9].__vftable = (ICollisionObject_vtbl *)this;
    v39 = (ICollisionObject *)operator new(v46);
    _Val = v39;
    LOBYTE(v57) = 32;
    if ( v39 )
    {
      MGUKRecoveryNotifier::MGUKRecoveryNotifier((MGUKRecoveryNotifier *)v39, this);
      v41 = v40;
    }
    else
    {
      v41 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v41;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v46 = 60;
    v41[9].__vftable = (ICollisionObject_vtbl *)this;
    v42 = (ICollisionObject *)operator new(v46);
    _Val = v42;
    LOBYTE(v57) = 33;
    if ( v42 )
    {
      MGUHModeNotifier::MGUHModeNotifier((MGUHModeNotifier *)v42, this);
      v44 = v43;
    }
    else
    {
      v44 = 0;
    }
    LOBYTE(v57) = 17;
    _Val = v44;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v44[9].__vftable = (ICollisionObject_vtbl *)this;
  }
  LOBYTE(v57) = 3;
  INIReaderDocuments::~INIReaderDocuments(&ini);
  LOBYTE(v57) = 2;
  INIReader::~INIReader(&carINI);
  if ( carINIPath._Myres >= 8 )
    operator delete(carINIPath._Bx._Ptr);
}

void CarAvatar::initCommonPostPhysics()
{
  float v2; // xmm1_4
  char v3; // bl
  int v4; // ebx
  SkidMarkBuffer **v5; // ebp
  __m128 v6; // xmm0
  int v7; // ecx
  unsigned int v8; // ebx
  SkidMarkBuffer *v9; // eax
  SkidMarkBuffer *v10; // eax
  SkidMarkBuffer *v11; // edx
  Sim *v12; // eax
  TyreSmoke *v13; // eax
  int v14; // eax
  int v15; // ebp
  GameObject **v16; // eax
  GameObject **v17; // ecx
  int v18; // ebx
  GameObject **v19; // ecx
  GameObject **v20; // eax
  EngineSmoke *v21; // eax
  int v22; // eax
  int v23; // ebp
  GameObject **v24; // eax
  GameObject **v25; // ecx
  int v26; // ebx
  GameObject **v27; // ecx
  GameObject **v28; // eax
  std::wstring *v29; // ebx
  std::wstring *v30; // eax
  std::wstring *v31; // eax
  std::wstring *v32; // eax
  Game *v33; // eax
  std::wstring *v34; // eax
  CarAudioFMOD *v35; // eax
  CarAudioFMOD *v36; // eax
  CarAudioFMOD *v37; // ebx
  GameObject **v38; // eax
  GameObject **v39; // ecx
  int v40; // ebp
  GameObject **v41; // ecx
  GameObject **v42; // eax
  bool v43; // cf
  CarAnimations *v44; // eax
  CarAnimations *v45; // eax
  CarAnimations *v46; // ebx
  GameObject **v47; // eax
  GameObject **v48; // ecx
  int v49; // ebp
  GameObject **v50; // ecx
  GameObject **v51; // eax
  GearShiftShake *v52; // eax
  int v53; // eax
  int v54; // ebp
  GameObject **v55; // eax
  GameObject **v56; // ecx
  int v57; // ebx
  GameObject **v58; // ecx
  GameObject **v59; // eax
  AnalogInstruments *v60; // eax
  int v61; // eax
  int v62; // ebp
  GameObject **v63; // eax
  GameObject **v64; // ecx
  int v65; // ebx
  GameObject **v66; // ecx
  GameObject **v67; // eax
  CarBrakeLights *v68; // eax
  CarBrakeLights *v69; // eax
  CarBrakeLights *v70; // ebx
  GameObject **v71; // eax
  GameObject **v72; // ecx
  int v73; // ebp
  GameObject **v74; // ecx
  GameObject **v75; // eax
  AnimatedLights *v76; // eax
  int v77; // eax
  int v78; // ebp
  GameObject **v79; // eax
  GameObject **v80; // ecx
  int v81; // ebx
  GameObject **v82; // ecx
  GameObject **v83; // eax
  unsigned int v84; // eax
  const __m128i *v85; // eax
  int *v86; // eax
  IEventTrigger **v87; // eax
  std::vector<IEventTrigger *> *v88; // ebx
  int v89; // ebp
  IEventTrigger **v90; // ecx
  IEventTrigger **v91; // eax
  ReplayRecorder *v92; // eax
  int v93; // eax
  int v94; // ebp
  GameObject **v95; // eax
  GameObject **v96; // ecx
  GameObject **v97; // ecx
  GameObject **v98; // eax
  bool v99; // bl
  int v100; // eax
  int v101; // eax
  int v102; // eax
  CarColliderRenderer *v103; // eax
  float v104; // eax
  float v105; // ebx
  TyreBlur *v106; // eax
  float v107; // eax
  float v108; // ebx
  BlurredObjects *v109; // eax
  float v110; // eax
  float v111; // ebx
  DigitalInstruments *v112; // eax
  float v113; // eax
  float v114; // ebx
  DigitalPanels *v115; // eax
  float v116; // eax
  float v117; // ebx
  Flames *v118; // eax
  float v119; // eax
  float v120; // ebx
  BrakeDiscGraphics *v121; // eax
  float v122; // eax
  float v123; // ebx
  DynamicCarEffects *v124; // eax
  float v125; // eax
  float v126; // ebx
  std::wstring v127; // [esp-10h] [ebp-228h] BYREF
  float gain; // [esp+8h] [ebp-210h]
  float uff; // [esp+20h] [ebp-1F8h] BYREF
  void *v130; // [esp+24h] [ebp-1F4h]
  float quantityMult; // [esp+28h] [ebp-1F0h]
  int v132; // [esp+2Ch] [ebp-1ECh]
  CarBrakeLights *v133; // [esp+30h] [ebp-1E8h] BYREF
  int v134; // [esp+34h] [ebp-1E4h] BYREF
  CarAnimations *v135; // [esp+38h] [ebp-1E0h] BYREF
  EventTriggerOnChange<int> *v136; // [esp+3Ch] [ebp-1DCh] BYREF
  int v137; // [esp+40h] [ebp-1D8h] BYREF
  int v138; // [esp+44h] [ebp-1D4h] BYREF
  int v139; // [esp+48h] [ebp-1D0h] BYREF
  int v140; // [esp+4Ch] [ebp-1CCh] BYREF
  CarAudioFMOD *v141; // [esp+50h] [ebp-1C8h] BYREF
  int v142; // [esp+54h] [ebp-1C4h] BYREF
  SuspensionGraphicsGenerator generator; // [esp+58h] [ebp-1C0h] BYREF
  std::wstring key; // [esp+6Ch] [ebp-1ACh] BYREF
  std::wstring guidsFilename; // [esp+84h] [ebp-194h] BYREF
  std::wstring result; // [esp+9Ch] [ebp-17Ch] BYREF
  std::wstring ifilename; // [esp+B4h] [ebp-164h] BYREF
  std::wstring bankFilename; // [esp+CCh] [ebp-14Ch] BYREF
  std::wstring v149; // [esp+E4h] [ebp-134h] BYREF
  std::wstring v150; // [esp+FCh] [ebp-11Ch] BYREF
  INIReaderDocuments vini; // [esp+114h] [ebp-104h] BYREF
  INIReaderDocuments ini; // [esp+158h] [ebp-C0h] BYREF
  DebugTimer dtAudio; // [esp+19Ch] [ebp-7Ch] BYREF
  INIReader smini; // [esp+1C4h] [ebp-54h] BYREF
  int v155; // [esp+214h] [ebp-4h]

  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/skidmarks.ini", 0x18u);
  v155 = 0;
  INIReader::INIReader(&smini, &ifilename);
  LOBYTE(v155) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  v2 = FLOAT_1_0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  quantityMult = FLOAT_1_0;
  if ( smini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"QUANTITY_MULT", 0xDu);
    LOBYTE(v155) = 3;
    guidsFilename._Myres = 7;
    guidsFilename._Mysize = 0;
    guidsFilename._Bx._Buf[0] = 0;
    std::wstring::assign(&guidsFilename, L"GRAPHICS", 8u);
    LOBYTE(v155) = 4;
    v3 = INIReader::hasKey(&smini, &guidsFilename, &key);
    if ( guidsFilename._Myres >= 8 )
      operator delete(guidsFilename._Bx._Ptr);
    guidsFilename._Myres = 7;
    guidsFilename._Mysize = 0;
    guidsFilename._Bx._Buf[0] = 0;
    LOBYTE(v155) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v3 )
    {
      std::wstring::wstring(&result, L"QUANTITY_MULT");
      LOBYTE(v155) = 5;
      std::wstring::wstring(&key, L"GRAPHICS");
      LOBYTE(v155) = 6;
      quantityMult = INIReader::getFloat(&smini, &key, &result);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v155) = 2;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v2 = quantityMult;
    }
    else
    {
      v2 = FLOAT_1_0;
    }
  }
  v4 = 0;
  v5 = this->skidMarkBuffers;
  v132 = 0;
  v6.m128_i32[0] = 0;
  LODWORD(uff) = this->skidMarkBuffers;
  do
  {
    *v5 = 0;
    v7 = this->game->graphics->videoSettings.worldDetail;
    if ( v7 > 0 && v2 != v6.m128_f32[0] )
    {
      v8 = (int)(float)(v2 * 6000.0);
      if ( v7 >= 3 )
        v8 = (int)(float)(v2 * 12000.0);
      v9 = (SkidMarkBuffer *)operator new(324);
      v130 = v9;
      LOBYTE(v155) = 7;
      if ( v9 )
      {
        SkidMarkBuffer::SkidMarkBuffer(v9, this->game->graphics, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      *v5 = v11;
      v12 = this->sim;
      LOBYTE(v155) = 2;
      v12->skidMarkNode->addChild(v12->skidMarkNode, v11);
      v4 = v132;
    }
    v13 = (TyreSmoke *)operator new(96);
    v130 = v13;
    LOBYTE(v155) = 8;
    if ( v13 )
    {
      TyreSmoke::TyreSmoke(v13, this, v4);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    v16 = this->gameObjects._Mylast;
    LOBYTE(v155) = 2;
    v140 = v15;
    if ( &v140 >= (int *)v16 || (v17 = this->gameObjects._Myfirst, v17 > (GameObject **)&v140) )
    {
      if ( v16 == this->gameObjects._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
      v20 = this->gameObjects._Mylast;
      if ( v20 )
        *v20 = (GameObject *)v15;
    }
    else
    {
      v18 = ((char *)&v140 - (char *)v17) >> 2;
      if ( v16 == this->gameObjects._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
      v19 = this->gameObjects._Mylast;
      if ( v19 )
        *v19 = this->gameObjects._Myfirst[v18];
      v4 = v132;
    }
    ++this->gameObjects._Mylast;
    ++v4;
    v2 = quantityMult;
    v6 = 0i64;
    *(_DWORD *)(v15 + 36) = this;
    v5 = (SkidMarkBuffer **)(LODWORD(uff) + 4);
    v132 = v4;
    LODWORD(uff) += 4;
  }
  while ( v4 < 4 );
  v21 = (EngineSmoke *)operator new(92);
  v130 = v21;
  LOBYTE(v155) = 9;
  if ( v21 )
  {
    EngineSmoke::EngineSmoke(v21, this);
    v23 = v22;
  }
  else
  {
    v23 = 0;
  }
  v24 = this->gameObjects._Mylast;
  LOBYTE(v155) = 2;
  v142 = v23;
  if ( &v142 >= (int *)v24 || (v25 = this->gameObjects._Myfirst, v25 > (GameObject **)&v142) )
  {
    if ( v24 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v28 = this->gameObjects._Mylast;
    if ( v28 )
      *v28 = (GameObject *)v23;
  }
  else
  {
    v26 = ((char *)&v142 - (char *)v25) >> 2;
    if ( v24 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v27 = this->gameObjects._Mylast;
    if ( v27 )
      *v27 = this->gameObjects._Myfirst[v26];
  }
  ++this->gameObjects._Mylast;
  LODWORD(gain) = 10;
  *(_DWORD *)(v23 + 36) = this;
  guidsFilename._Myres = 7;
  guidsFilename._Mysize = 0;
  guidsFilename._Bx._Buf[0] = 0;
  std::wstring::assign(&guidsFilename, L"AUDIO LOAD", LODWORD(gain));
  LOBYTE(v155) = 10;
  DebugTimer::DebugTimer(&dtAudio, &guidsFilename);
  LOBYTE(v155) = 12;
  if ( guidsFilename._Myres >= 8 )
    operator delete(guidsFilename._Bx._Ptr);
  guidsFilename._Myres = 7;
  v29 = &this->unixName;
  guidsFilename._Bx._Buf[0] = 0;
  guidsFilename._Mysize = 0;
  v30 = std::operator+<wchar_t>(&result, L"content/cars/", &this->unixName);
  LOBYTE(v155) = 13;
  v31 = std::operator+<wchar_t>(&v149, v30, L"/sfx/");
  LOBYTE(v155) = 14;
  v32 = std::operator+<wchar_t>(&v150, v31, &this->unixName);
  LOBYTE(v155) = 15;
  std::operator+<wchar_t>(&bankFilename, v32, L".bank");
  if ( v150._Myres >= 8 )
    operator delete(v150._Bx._Ptr);
  v150._Myres = 7;
  v150._Mysize = 0;
  v150._Bx._Buf[0] = 0;
  if ( v149._Myres >= 8 )
    operator delete(v149._Bx._Ptr);
  v149._Myres = 7;
  v149._Mysize = 0;
  v149._Bx._Buf[0] = 0;
  LOBYTE(v155) = 19;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  v33 = this->game;
  result._Mysize = 0;
  if ( v33->audioEngine && Path::fileExists((unsigned int)v29, &bankFilename, 0) )
  {
    v34 = std::operator+<wchar_t>(&key, L"content/cars/", &this->unixName);
    LOBYTE(v155) = 20;
    std::operator+<wchar_t>(&guidsFilename, v34, L"/sfx/GUIDs.txt");
    LOBYTE(v155) = 22;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Bx._Buf[0] = 0;
    key._Mysize = 0;
    if ( Path::fileExists((unsigned int)v29, &guidsFilename, 0) )
      AudioEngine::parseGUIDs(this->game->audioEngine, &guidsFilename);
    v35 = (CarAudioFMOD *)operator new(824);
    v130 = v35;
    LOBYTE(v155) = 23;
    if ( v35 )
    {
      CarAudioFMOD::CarAudioFMOD(v35, this);
      v37 = v36;
    }
    else
    {
      v37 = 0;
    }
    v38 = this->gameObjects._Mylast;
    LOBYTE(v155) = 22;
    v141 = v37;
    if ( &v141 >= v38 || (v39 = this->gameObjects._Myfirst, v39 > &v141) )
    {
      if ( v38 == this->gameObjects._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
      v42 = this->gameObjects._Mylast;
      if ( v42 )
        *v42 = v37;
    }
    else
    {
      v40 = &v141 - (CarAudioFMOD **)v39;
      if ( v38 == this->gameObjects._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
      v41 = this->gameObjects._Mylast;
      if ( v41 )
        *v41 = this->gameObjects._Myfirst[v40];
    }
    ++this->gameObjects._Mylast;
    v37->parent = this;
    v43 = guidsFilename._Myres < 8;
    this->carAudioFMOD = v37;
    LOBYTE(v155) = 19;
    if ( !v43 )
      operator delete(guidsFilename._Bx._Ptr);
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&dtAudio);
  v44 = (CarAnimations *)operator new(92);
  v130 = v44;
  LOBYTE(v155) = 24;
  if ( v44 )
  {
    CarAnimations::CarAnimations(v44, this);
    v46 = v45;
  }
  else
  {
    v46 = 0;
  }
  v47 = this->gameObjects._Mylast;
  LOBYTE(v155) = 19;
  v135 = v46;
  if ( &v135 >= v47 || (v48 = this->gameObjects._Myfirst, v48 > &v135) )
  {
    if ( v47 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v51 = this->gameObjects._Mylast;
    if ( v51 )
      *v51 = v46;
  }
  else
  {
    v49 = &v135 - (CarAnimations **)v48;
    if ( v47 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v50 = this->gameObjects._Mylast;
    if ( v50 )
      *v50 = this->gameObjects._Myfirst[v49];
  }
  ++this->gameObjects._Mylast;
  v46->parent = this;
  LODWORD(gain) = 220;
  this->carAnimations = v46;
  v52 = (GearShiftShake *)operator new(LODWORD(gain));
  v130 = v52;
  LOBYTE(v155) = 25;
  if ( v52 )
  {
    GearShiftShake::GearShiftShake(v52, (__m128)0i64, this);
    v54 = v53;
  }
  else
  {
    v54 = 0;
  }
  v55 = this->gameObjects._Mylast;
  LOBYTE(v155) = 19;
  v139 = v54;
  if ( &v139 >= (int *)v55 || (v56 = this->gameObjects._Myfirst, v56 > (GameObject **)&v139) )
  {
    if ( v55 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v59 = this->gameObjects._Mylast;
    if ( v59 )
      *v59 = (GameObject *)v54;
  }
  else
  {
    v57 = ((char *)&v139 - (char *)v56) >> 2;
    if ( v55 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v58 = this->gameObjects._Mylast;
    if ( v58 )
      *v58 = this->gameObjects._Myfirst[v57];
  }
  ++this->gameObjects._Mylast;
  LODWORD(gain) = 824;
  *(_DWORD *)(v54 + 36) = this;
  v60 = (AnalogInstruments *)operator new(LODWORD(gain));
  v130 = v60;
  LOBYTE(v155) = 26;
  if ( v60 )
  {
    AnalogInstruments::AnalogInstruments(v60, this);
    v62 = v61;
  }
  else
  {
    v62 = 0;
  }
  v63 = this->gameObjects._Mylast;
  LOBYTE(v155) = 19;
  v137 = v62;
  if ( &v137 >= (int *)v63 || (v64 = this->gameObjects._Myfirst, v64 > (GameObject **)&v137) )
  {
    if ( v63 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v67 = this->gameObjects._Mylast;
    if ( v67 )
      *v67 = (GameObject *)v62;
  }
  else
  {
    v65 = ((char *)&v137 - (char *)v64) >> 2;
    if ( v63 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v66 = this->gameObjects._Mylast;
    if ( v66 )
      *v66 = this->gameObjects._Myfirst[v65];
  }
  ++this->gameObjects._Mylast;
  LODWORD(gain) = 172;
  *(_DWORD *)(v62 + 36) = this;
  v68 = (CarBrakeLights *)operator new(LODWORD(gain));
  v130 = v68;
  LOBYTE(v155) = 27;
  if ( v68 )
  {
    CarBrakeLights::CarBrakeLights(v68, this);
    v70 = v69;
  }
  else
  {
    v70 = 0;
  }
  v71 = this->gameObjects._Mylast;
  LOBYTE(v155) = 19;
  v133 = v70;
  if ( &v133 >= v71 || (v72 = this->gameObjects._Myfirst, v72 > &v133) )
  {
    if ( v71 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v75 = this->gameObjects._Mylast;
    if ( v75 )
      *v75 = v70;
  }
  else
  {
    v73 = &v133 - (CarBrakeLights **)v72;
    if ( v71 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v74 = this->gameObjects._Mylast;
    if ( v74 )
      *v74 = this->gameObjects._Myfirst[v73];
  }
  ++this->gameObjects._Mylast;
  LODWORD(gain) = 84;
  v70->parent = this;
  v76 = (AnimatedLights *)operator new(LODWORD(gain));
  v130 = v76;
  LOBYTE(v155) = 28;
  if ( v76 )
  {
    AnimatedLights::AnimatedLights(v76, (unsigned int)v70, v70);
    v78 = v77;
  }
  else
  {
    v78 = 0;
  }
  v79 = this->gameObjects._Mylast;
  LOBYTE(v155) = 19;
  v134 = v78;
  if ( &v134 >= (int *)v79 || (v80 = this->gameObjects._Myfirst, v80 > (GameObject **)&v134) )
  {
    if ( v79 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v83 = this->gameObjects._Mylast;
    if ( v83 )
      *v83 = (GameObject *)v78;
  }
  else
  {
    v81 = ((char *)&v134 - (char *)v80) >> 2;
    if ( v79 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v82 = this->gameObjects._Mylast;
    if ( v82 )
      *v82 = this->gameObjects._Myfirst[v81];
  }
  ++this->gameObjects._Mylast;
  LODWORD(gain) = this;
  *(_DWORD *)(v78 + 36) = this;
  CarRaceInfo::init(&this->raceInfo, (CarAvatar *)LODWORD(gain));
  if ( this->sim->track )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PIT", 3u);
    LOBYTE(v155) = 29;
    guidsFilename._Myres = 7;
    guidsFilename._Mysize = 0;
    guidsFilename._Bx._Buf[0] = 0;
    std::wstring::assign(&guidsFilename, L"PIT", 3u);
    LOBYTE(v155) = 30;
    v84 = CarRaceInfo::getSpawnPositionIndex(&this->raceInfo, &key);
    v85 = (const __m128i *)TrackAvatar::getSpawnPosition(this->sim->track, (mat44f *)&ini, &guidsFilename, v84);
    v43 = guidsFilename._Myres < 8;
    *(__m128i *)&this->pitPosition.M11 = _mm_loadu_si128(v85);
    *(__m128i *)&this->pitPosition.M21 = _mm_loadu_si128(v85 + 1);
    *(__m128i *)&this->pitPosition.M31 = _mm_loadu_si128(v85 + 2);
    v6 = (__m128)_mm_loadu_si128(v85 + 3);
    *(__m128 *)&this->pitPosition.M41 = v6;
    if ( !v43 )
      operator delete(guidsFilename._Bx._Ptr);
    guidsFilename._Myres = 7;
    guidsFilename._Mysize = 0;
    guidsFilename._Bx._Buf[0] = 0;
    LOBYTE(v155) = 19;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( this == (CarAvatar *)-1052 )
  {
    MEMORY[0xFFFFFC28] = 0;
    MEMORY[0xFFFFFC2C] = 0;
  }
  else
  {
    v86 = this->evOnGearChanged.attachedFloat;
    if ( v86 )
      this->evOnGearChanged.oldFloatValue = *v86;
    this->evOnGearChanged.attachedFloat = &this->physicsState.gear;
  }
  v87 = this->eventTriggers._Mylast;
  v88 = &this->eventTriggers;
  v136 = &this->evOnGearChanged;
  if ( &v136 >= v87 || v88->_Myfirst > &v136 )
  {
    if ( v87 == this->eventTriggers._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->eventTriggers, 1u);
    v91 = this->eventTriggers._Mylast;
    if ( v91 )
      *v91 = &this->evOnGearChanged;
  }
  else
  {
    v89 = &v136 - (EventTriggerOnChange<int> **)v88->_Myfirst;
    if ( v87 == this->eventTriggers._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->eventTriggers, 1u);
    v90 = this->eventTriggers._Mylast;
    if ( v90 )
      *v90 = v88->_Myfirst[v89];
  }
  ++this->eventTriggers._Mylast;
  v92 = (ReplayRecorder *)operator new(164);
  v130 = v92;
  LOBYTE(v155) = 31;
  if ( v92 )
  {
    ReplayRecorder::ReplayRecorder(v92, this, this->physicsStateProvider);
    v94 = v93;
  }
  else
  {
    v94 = 0;
  }
  v95 = this->gameObjects._Mylast;
  LOBYTE(v155) = 19;
  v138 = v94;
  if ( &v138 >= (int *)v95 || (v96 = this->gameObjects._Myfirst, v96 > (GameObject **)&v138) )
  {
    if ( v95 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v98 = this->gameObjects._Mylast;
    if ( v98 )
      *v98 = (GameObject *)v94;
  }
  else
  {
    v88 = (std::vector<IEventTrigger *> *)(((char *)&v138 - (char *)v96) >> 2);
    if ( v95 == this->gameObjects._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
    v97 = this->gameObjects._Mylast;
    if ( v97 )
      *v97 = this->gameObjects._Myfirst[(_DWORD)v88];
  }
  ++this->gameObjects._Mylast;
  gain = 0.0;
  *(_DWORD *)(v94 + 36) = this;
  *(_WORD *)&this->lockVirtualSteer = 0;
  v127._Myres = 7;
  v127._Mysize = 0;
  v127._Bx._Buf[0] = 0;
  std::wstring::assign(&v127, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&vini, (unsigned int)v88, v127, SLOBYTE(gain));
  LOBYTE(v155) = 32;
  if ( vini.ready )
  {
    vini.suppressErrorReporting = 1;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ASSETTOCORSA", 0xCu);
    LOBYTE(v155) = 33;
    v99 = INIReader::hasSection(&vini, &key);
    LOBYTE(v155) = 32;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v99 )
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"LOCK_STEER", 0xAu);
      LOBYTE(v155) = 34;
      guidsFilename._Myres = 7;
      guidsFilename._Mysize = 0;
      guidsFilename._Bx._Buf[0] = 0;
      std::wstring::assign(&guidsFilename, L"ASSETTOCORSA", 0xCu);
      LOBYTE(v155) = 35;
      v100 = INIReader::getInt(&vini, &guidsFilename, &key);
      v43 = guidsFilename._Myres < 8;
      this->lockVirtualSteer = v100 != 0;
      if ( !v43 )
        operator delete(guidsFilename._Bx._Ptr);
      guidsFilename._Myres = 7;
      guidsFilename._Mysize = 0;
      guidsFilename._Bx._Buf[0] = 0;
      LOBYTE(v155) = 32;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&guidsFilename, L"HIDE_ARMS");
      LOBYTE(v155) = 36;
      std::wstring::wstring(&key, L"ASSETTOCORSA");
      LOBYTE(v155) = 37;
      v101 = INIReader::getInt(&vini, &key, &guidsFilename);
      v43 = key._Myres < 8;
      this->hideArmsInCockpit = v101 != 0;
      if ( !v43 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v155) = 32;
      if ( guidsFilename._Myres >= 8 )
        operator delete(guidsFilename._Bx._Ptr);
      std::wstring::wstring(&guidsFilename, L"HIDE_STEER");
      LOBYTE(v155) = 38;
      std::wstring::wstring(&key, L"ASSETTOCORSA");
      LOBYTE(v155) = 39;
      v102 = INIReader::getInt(&vini, &key, &guidsFilename);
      v43 = key._Myres < 8;
      this->hideSteer = v102 != 0;
      if ( !v43 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v155) = 32;
      if ( guidsFilename._Myres >= 8 )
        operator delete(guidsFilename._Bx._Ptr);
    }
  }
  v103 = (CarColliderRenderer *)operator new(56);
  v130 = v103;
  LOBYTE(v155) = 40;
  if ( v103 )
  {
    CarColliderRenderer::CarColliderRenderer(v103, this);
    v105 = v104;
  }
  else
  {
    v105 = 0.0;
  }
  LOBYTE(v155) = 32;
  uff = v105;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  LODWORD(gain) = this;
  *(_DWORD *)(LODWORD(v105) + 36) = this;
  *(_BYTE *)(LODWORD(v105) + 32) = 0;
  SuspensionGraphicsGenerator::SuspensionGraphicsGenerator(&generator, (CarAvatar *)LODWORD(gain));
  LOBYTE(v155) = 41;
  SuspensionGraphicsGenerator::generateConnections(&generator);
  v106 = (TyreBlur *)operator new(152);
  v130 = v106;
  LOBYTE(v155) = 42;
  if ( v106 )
  {
    TyreBlur::TyreBlur(v106, this);
    v108 = v107;
  }
  else
  {
    v108 = 0.0;
  }
  LOBYTE(v155) = 41;
  uff = v108;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  LODWORD(gain) = 68;
  *(_DWORD *)(LODWORD(v108) + 36) = this;
  v109 = (BlurredObjects *)operator new(LODWORD(gain));
  v130 = v109;
  LOBYTE(v155) = 43;
  if ( v109 )
  {
    BlurredObjects::BlurredObjects(v109, this);
    v111 = v110;
  }
  else
  {
    v111 = 0.0;
  }
  LOBYTE(v155) = 41;
  uff = v111;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  LODWORD(gain) = 120;
  *(_DWORD *)(LODWORD(v111) + 36) = this;
  v112 = (DigitalInstruments *)operator new(LODWORD(gain));
  v130 = v112;
  LOBYTE(v155) = 44;
  if ( v112 )
  {
    DigitalInstruments::DigitalInstruments(v112, this);
    v114 = v113;
  }
  else
  {
    v114 = 0.0;
  }
  LOBYTE(v155) = 41;
  uff = v114;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  LODWORD(gain) = 132;
  *(_DWORD *)(LODWORD(v114) + 36) = this;
  v115 = (DigitalPanels *)operator new(LODWORD(gain));
  v130 = v115;
  LOBYTE(v155) = 45;
  if ( v115 )
  {
    DigitalPanels::DigitalPanels(v115, this);
    v117 = v116;
  }
  else
  {
    v117 = 0.0;
  }
  LOBYTE(v155) = 41;
  uff = v117;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  LODWORD(gain) = 224;
  *(_DWORD *)(LODWORD(v117) + 36) = this;
  v118 = (Flames *)operator new(LODWORD(gain));
  v130 = v118;
  LOBYTE(v155) = 46;
  if ( v118 )
  {
    Flames::Flames(v118, this);
    v120 = v119;
  }
  else
  {
    v120 = 0.0;
  }
  LOBYTE(v155) = 41;
  uff = v120;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  LODWORD(gain) = 192;
  *(_DWORD *)(LODWORD(v120) + 36) = this;
  v121 = (BrakeDiscGraphics *)operator new(LODWORD(gain));
  v130 = v121;
  LOBYTE(v155) = 47;
  if ( v121 )
  {
    BrakeDiscGraphics::BrakeDiscGraphics(v121, this);
    v123 = v122;
  }
  else
  {
    v123 = 0.0;
  }
  LOBYTE(v155) = 41;
  uff = v123;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  *(_DWORD *)(LODWORD(v123) + 36) = this;
  CarAvatar::initCameraCar(this, v6);
  v124 = (DynamicCarEffects *)operator new(80);
  v130 = v124;
  LOBYTE(v155) = 48;
  if ( v124 )
  {
    DynamicCarEffects::DynamicCarEffects(v124, this);
    v126 = v125;
  }
  else
  {
    v126 = 0.0;
  }
  LOBYTE(v155) = 41;
  uff = v126;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&uff);
  *(_DWORD *)(LODWORD(v126) + 36) = this;
  if ( !this->guid )
  {
    gain = 0.0;
    std::wstring::wstring(&v127, L"cfg/user_ff.ini");
    INIReaderDocuments::INIReaderDocuments(&ini, LODWORD(v126), v127, SLOBYTE(gain));
    LOBYTE(v155) = 49;
    if ( ini.ready && INIReader::hasSection(&ini, &this->unixName) )
    {
      std::wstring::wstring(&key, L"VALUE");
      LOBYTE(v155) = 50;
      uff = INIReader::getFloat(&ini, &this->unixName, &key);
      LOBYTE(v155) = 49;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      CarAvatar::setUserFFGain(this, uff);
      _printf("User FF gain loaded and set to %f\n", this->userFFGain);
    }
    LOBYTE(v155) = 41;
    INIReaderDocuments::~INIReaderDocuments(&ini);
  }
  LOBYTE(v155) = 32;
  SuspensionGraphicsGenerator::~SuspensionGraphicsGenerator(&generator);
  LOBYTE(v155) = 19;
  INIReaderDocuments::~INIReaderDocuments(&vini);
  if ( bankFilename._Myres >= 8 )
    operator delete(bankFilename._Bx._Ptr);
  bankFilename._Myres = 7;
  bankFilename._Mysize = 0;
  bankFilename._Bx._Buf[0] = 0;
  LOBYTE(v155) = 2;
  DebugTimer::~DebugTimer(&dtAudio);
  v155 = -1;
  INIReader::~INIReader(&smini);
}

void __usercall CarAvatar::initControls(@<ecx>, char a2@<bl>)
{
  DICarControl *v3; // eax
  ICarControlsProvider *v4; // eax
  Car *v5; // ecx
  JoypadCarControl *v6; // eax
  ICarControlsProvider *v7; // eax
  Car *v8; // ecx
  KeyboardCarControl *v9; // eax
  ICarControlsProvider *v10; // eax
  Car *v11; // ecx
  AIDriver *v12; // eax
  ICarControlsProvider *v13; // eax
  Car *v14; // ecx
  std::wstring v15; // [esp-1Ch] [ebp-C4h] BYREF
  BOOL v16; // [esp-4h] [ebp-ACh]
  void *v17; // [esp+8h] [ebp-A0h]
  std::wstring ct; // [esp+Ch] [ebp-9Ch] BYREF
  std::wstring section; // [esp+24h] [ebp-84h] BYREF
  std::wstring key; // [esp+3Ch] [ebp-6Ch] BYREF
  INIReaderDocuments ini; // [esp+54h] [ebp-54h] BYREF
  int v22; // [esp+A4h] [ebp-4h]

  if ( this->physics )
  {
    v16 = 0;
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    std::wstring::assign(&v15, L"cfg/controls.ini", 0x10u);
    INIReaderDocuments::INIReaderDocuments(&ini, a2, v15, v16);
    v22 = 0;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"INPUT_METHOD", 0xCu);
    LOBYTE(v22) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v22) = 2;
    INIReader::getString(&ini, &ct, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v22) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( !std::wstring::compare(&ct, 0, ct._Mysize, L"WHEEL", 5u) )
    {
      v3 = (DICarControl *)operator new(2164);
      v17 = v3;
      LOBYTE(v22) = 6;
      if ( v3 )
        DICarControl::DICarControl(v3, a2);
      else
        v4 = 0;
      v5 = this->physics;
      LOBYTE(v22) = 5;
      Car::setControllerProvider(v5, v4);
    }
    if ( !std::wstring::compare(&ct, 0, ct._Mysize, L"X360", 4u) )
    {
      v6 = (JoypadCarControl *)operator new(400);
      v17 = v6;
      LOBYTE(v22) = 7;
      if ( v6 )
        JoypadCarControl::JoypadCarControl(v6, this->physics, this->game->joypadManager.joypad._Myptr);
      else
        v7 = 0;
      v8 = this->physics;
      LOBYTE(v22) = 5;
      Car::setControllerProvider(v8, v7);
    }
    if ( !std::wstring::compare(&ct, 0, ct._Mysize, L"KEYBOARD", 8u) )
    {
      v9 = (KeyboardCarControl *)operator new(248);
      v17 = v9;
      LOBYTE(v22) = 8;
      if ( v9 )
        KeyboardCarControl::KeyboardCarControl(v9, a2, this->physics);
      else
        v10 = 0;
      v11 = this->physics;
      LOBYTE(v22) = 5;
      Car::setControllerProvider(v11, v10);
    }
    if ( !std::wstring::compare(&ct, 0, ct._Mysize, L"AI", 2u) )
    {
      v12 = (AIDriver *)operator new(872);
      v17 = v12;
      LOBYTE(v22) = 9;
      if ( v12 )
        AIDriver::AIDriver(v12, this->physics);
      else
        v13 = 0;
      v14 = this->physics;
      LOBYTE(v22) = 5;
      Car::setControllerProvider(v14, v13);
    }
    if ( ct._Myres >= 8 )
      operator delete(ct._Bx._Ptr);
    ct._Myres = 7;
    ct._Mysize = 0;
    ct._Bx._Buf[0] = 0;
    v22 = -1;
    INIReaderDocuments::~INIReaderDocuments(&ini);
  }
}
// 5CD623: variable 'v4' is possibly undefined
// 5CD688: variable 'v7' is possibly undefined
// 5CD6E4: variable 'v10' is possibly undefined
// 5CD740: variable 'v13' is possibly undefined
// 78E1CE: using guessed type int __cdecl operator new(_DWORD);
// 78E1D4: using guessed type int __cdecl operator delete(_DWORD);

//----- (005CD7B0) --------------------------------------------------------
void __usercall CarAvatar::initDriver(@<ecx>, unsigned int a2@<ebx>)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  char v5; // bl
  ICollisionObject *v6; // eax
  DriverModel *v7; // eax
  DriverModel *v8; // edi
  ICollisionObject *v9; // eax
  DriverModel *v10; // eax
  DriverModel *v11; // edi
  ICollisionObject *_Val; // [esp+10h] [ebp-44h] BYREF
  std::wstring v13; // [esp+14h] [ebp-40h] BYREF
  std::wstring result; // [esp+2Ch] [ebp-28h] BYREF
  int v15; // [esp+50h] [ebp-4h]

  this->driverModel_HR = 0;
  this->driverModel_LR = 0;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &this->unixName);
  v15 = 0;
  v4 = std::operator+<wchar_t>(&v13, v3, L"/data/driver3d.ini");
  LOBYTE(v15) = 1;
  v5 = Path::fileExists(a2, v4, 0);
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  v15 = -1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v5 )
  {
    v6 = (ICollisionObject *)operator new(288);
    _Val = v6;
    v15 = 2;
    if ( v6 )
    {
      DriverModel::DriverModel((DriverModel *)v6, this, this->game->graphics, 1);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    v15 = -1;
    this->driverModel_HR = v8;
    _Val = (ICollisionObject *)v8;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v8->parent = this;
    this->bodyTransform->addChild(this->bodyTransform, this->driverModel_HR->driver_root);
    v9 = (ICollisionObject *)operator new(288);
    _Val = v9;
    v15 = 3;
    if ( v9 )
    {
      DriverModel::DriverModel((DriverModel *)v9, this, this->game->graphics, 0);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    v15 = -1;
    this->driverModel_LR = v11;
    _Val = (ICollisionObject *)v11;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v11->parent = this;
    this->bodyTransform->addChild(this->bodyTransform, this->driverModel_LR->driver_root);
  }
}
// 5CD8B4: variable 'v7' is possibly undefined
// 5CD920: variable 'v10' is possibly undefined
// 78E1CE: using guessed type int __cdecl operator new(_DWORD);
// 78E1D4: using guessed type int __cdecl operator delete(_DWORD);

//----- (005CD980) --------------------------------------------------------
void CarAvatar::initGhostCar(bool isRecording, BOOL isPlaying)
{
  Car *v4; // eax
  GhostCarRecorder *v5; // eax
  GhostCarRecorder *v6; // eax
  GhostCarRecorder *v7; // edi
  GhostCar *v8; // eax
  int v9; // eax
  int v10; // edi

  v4 = this->physics;
  if ( v4 && !v4->physicsGUID && !GameObject::getGameObject<GhostCar>(this) )
  {
    v5 = (GhostCarRecorder *)operator new(248);
    if ( v5 )
    {
      GhostCarRecorder::GhostCarRecorder(v5, this, this->physics, isRecording, isPlaying);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    isPlaying = (BOOL)v7;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&this->gameObjects,
      (ICollisionObject *const *)&isPlaying);
    v7->parent = this;
    v8 = (GhostCar *)operator new(720);
    isPlaying = (BOOL)v8;
    if ( v8 )
    {
      GhostCar::GhostCar(v8, this, v7);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    isPlaying = v10;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&this->gameObjects,
      (ICollisionObject *const *)&isPlaying);
    *(_DWORD *)(v10 + 36) = this;
  }
}
// 5CDA01: variable 'v6' is possibly undefined
// 5CDA49: variable 'v9' is possibly undefined
// 78E1CE: using guessed type int __cdecl operator new(_DWORD);

//----- (005CDA80) --------------------------------------------------------
void CarAvatar::initMirrorMaterials()
{
  ICollisionObject *v2; // eax
  ICollisionObject *v3; // eax
  ICollisionObject *v4; // edi
  ICollisionObject *_Val; // [esp+Ch] [ebp-10h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  if ( this->sim->mirrorTextureRenderer )
  {
    v2 = (ICollisionObject *)operator new(68);
    _Val = v2;
    v6 = 0;
    if ( v2 )
    {
      CarMirrorManager::CarMirrorManager((CarMirrorManager *)v2, this, &this->sim->mirrorTextureRenderer->texture);
      v4 = v3;
    }
    else
    {
      v4 = 0;
    }
    v6 = -1;
    _Val = v4;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v4[9].__vftable = (ICollisionObject_vtbl *)this;
  }
}
// 5CDAE2: variable 'v3' is possibly undefined
// 78E1CE: using guessed type int __cdecl operator new(_DWORD);

//----- (005CDB20) --------------------------------------------------------
void __usercall CarAvatar::initPhysics(@<ecx>, char a2@<bl>, __m128 a3@<xmm3>, __m128 a4@<xmm4>)
{
  CarAvatar *v4; // edi
  int v5; // eax
  _DWORD *v6; // esi
  float v7; // esi
  Car *v8; // edx
  Car *v9; // eax
  std::_Callable_obj<<lambda_77ca9348bb85863f3ac03214213671f3>,0> *v10; // eax
  std::_Callable_obj<<lambda_77ca9348bb85863f3ac03214213671f3>,0> *v11; // eax
  Sim *v12; // ecx
  Console *v13; // eax
  Console *v14; // eax
  Console *v15; // eax
  Console *v16; // eax
  Console *v17; // eax
  Console *v18; // eax
  std::_Callable_obj<<lambda_77ca9348bb85863f3ac03214213671f3>,0> *v19; // eax
  const std::wstring *v20; // esi
  Track *v21; // edi
  Console *v22; // eax
  Console *v23; // eax
  Console *v24; // eax
  Console *v25; // eax
  Console *v26; // eax
  Car *v27; // ecx
  bool v28; // al
  double v29; // st7
  Car *v30; // eax
  int v31; // xmm0_4
  long double v32; // xmm0_8
  Car *v33; // esi
  int v34; // ecx
  unsigned int v35; // edx
  int v36; // edx
  int v37; // eax
  float *v38; // esi
  int v39; // ecx
  float v40; // xmm0_4
  char *v41; // ecx
  float v42; // xmm0_4
  Car *v43; // eax
  int v44; // eax
  Car *v45; // eax
  int v46; // ecx
  int v47; // eax
  float v48; // edx
  int v49; // ecx
  Car *v50; // eax
  int v51; // eax
  Car *v52; // eax
  Car *v53; // eax
  Car *v54; // esi
  const WingData *v55; // edi
  const WingData *v56; // esi
  std::vector<WingData> *v57; // eax
  RaceEngineer *v58; // eax
  CarAvatar *v59; // edi
  RaceEngineer *v60; // eax
  RaceEngineer *v61; // ecx
  double v62; // st7
  Engine *v63; // ecx
  double v64; // st7
  Car *v65; // ecx
  double v66; // st7
  RaceEngineer *v67; // ecx
  KPI *v68; // eax
  Curve *v69; // ecx
  int v70; // eax
  bool v71; // zf
  Car *v72; // ecx
  std::function<void __cdecl(void)> *v73; // esi
  std::_Func_base<void> *v74; // ecx
  double v75; // st7
  Car *v76; // eax
  Event<OnPhysicsStepCompleted> *v77; // ecx
  Event<SessionInfo> *v78; // ecx
  Event<SessionInfo> *v79; // ecx
  Event<OnPhysicsStepCompleted> *v80; // ecx
  std::wstring *v81; // eax
  void (*v82)(const char *const, ...); // esi
  std::wstring *v83; // eax
  std::wstring *v84; // edx
  unsigned int v85; // ecx
  Node *v86; // esi
  int v87; // eax
  Mesh *v88; // esi
  Material *v89; // esi
  Material *v90; // eax
  Node *v91; // esi
  Node *v92; // eax
  const __m128i *v93; // eax
  std::_Ref_count_base *v94; // esi
  Car *v95; // eax
  bool v96; // al
  double v97; // st7
  bool v98; // cf
  Car *v99; // eax
  Sim *v100; // ecx
  Console *v101; // eax
  Sim *v102; // ecx
  Console *v103; // eax
  Car *v104; // eax
  ISuspensionAvatar *v105; // ecx
  float v106; // xmm0_4
  ISuspensionAvatar_vtbl *v107; // eax
  double v108; // st7
  Car *v109; // eax
  ISuspensionAvatar *v110; // ecx
  float v111; // xmm0_4
  ISuspensionAvatar_vtbl *v112; // eax
  std::wstring v113; // [esp-48h] [ebp-2ACh] BYREF
  _BYTE v114[28]; // [esp-30h] [ebp-294h] BYREF
  std::wstring v115; // [esp-14h] [ebp-278h] BYREF
  _BYTE multiplier[48]; // [esp+4h] [ebp-260h] BYREF
  mat44f bm_12; // [esp+58h] [ebp-20Ch] BYREF
  mat44f res_12; // [esp+98h] [ebp-1CCh] BYREF
  ErrorBlob v119; // [esp+D8h] [ebp-18Ch] BYREF
  std::wstring *v120; // [esp+E8h] [ebp-17Ch]
  std::shared_ptr<Material> mat; // [esp+ECh] [ebp-178h] BYREF
  float v122; // [esp+F4h] [ebp-170h]
  CarAvatar *v123; // [esp+F8h] [ebp-16Ch]
  float v124; // [esp+FCh] [ebp-168h]
  int v125; // [esp+100h] [ebp-164h] BYREF
  float v126; // [esp+104h] [ebp-160h]
  int v; // [esp+108h] [ebp-15Ch] BYREF
  int v128; // [esp+10Ch] [ebp-158h]
  float v129; // [esp+110h] [ebp-154h]
  KN5IO v130; // [esp+114h] [ebp-150h] BYREF
  INIReaderDocuments v131; // [esp+180h] [ebp-E4h] BYREF
  std::wstring v132; // [esp+1C4h] [ebp-A0h] BYREF
  std::wstring filename; // [esp+1DCh] [ebp-88h] BYREF
  std::wstring path; // [esp+1F4h] [ebp-70h] BYREF
  std::wstring name; // [esp+20Ch] [ebp-58h] BYREF
  std::wstring _Right; // [esp+224h] [ebp-40h] BYREF
  std::wstring n; // [esp+23Ch] [ebp-28h] BYREF
  int v138; // [esp+260h] [ebp-4h]

  v4 = this;
  v123 = this;
  v126 = 0.0;
  v122 = 0.0;
  ErrorBlob::ErrorBlob(&v119);
  v5 = (int)v4->sim;
  v138 = 0;
  v = v5;
  v6 = *(_DWORD **)(v5 + 40);
  if ( v6 == *(_DWORD **)(v5 + 44) )
  {
LABEL_4:
    v7 = 0.0;
  }
  else
  {
    while ( 1 )
    {
      v124 = COERCE_FLOAT(__RTDynamicCast(*v6, 0, &GameObject `RTTI Type Descriptor', &PhysicsAvatar `RTTI Type Descriptor', 0));
      if ( v124 != 0.0 )
        break;
      if ( ++v6 == *(_DWORD **)(v + 44) )
        goto LABEL_4;
    }
    v7 = v124;
  }
  *(float *)&v8 = COERCE_FLOAT(operator new(11872));
  v129 = *(float *)&v8;
  LOBYTE(v138) = 1;
  if ( *(float *)&v8 == 0.0 )
    v9 = 0;
  else
    Car::Car(v8, a3, a4, (PhysicsEngine *)(LODWORD(v7) + 56), &v4->unixName, &v4->configName);
  v4->physics = v9;
  LOBYTE(v138) = 0;
  v9->tag = v4;
  v10 = std::_Func_impl<std::_Callable_obj<_lambda_034d48754ea12fd9a7c51584058b5d75_,0>,std::allocator<std::_Func_class<void,>>,void,>::_Get((std::_Func_impl<std::_Callable_obj<<lambda_77ca9348bb85863f3ac03214213671f3>,0>,std::allocator<std::_Func_class<void,SessionInfo const &> >,void,SessionInfo const &> *)&v119);
  if ( ((char *)v10[1]._Object.__this - (char *)v10->_Object.__this) / 24 )
  {
    v11 = std::_Func_impl<std::_Callable_obj<_lambda_034d48754ea12fd9a7c51584058b5d75_,0>,std::allocator<std::_Func_class<void,>>,void,>::_Get((std::_Func_impl<std::_Callable_obj<<lambda_77ca9348bb85863f3ac03214213671f3>,0>,std::allocator<std::_Func_class<void,SessionInfo const &> >,void,SessionInfo const &> *)&v119);
    v129 = COERCE_FLOAT(&multiplier[24]);
    v = ((char *)v11[1]._Object.__this - (char *)v11->_Object.__this) / 24;
    *(_DWORD *)&multiplier[44] = 7;
    *(_DWORD *)&multiplier[40] = 0;
    *(_WORD *)&multiplier[24] = 0;
    std::wstring::assign((std::wstring *)&multiplier[24], L"\n", 1u);
    LOBYTE(v138) = 2;
    v124 = COERCE_FLOAT(multiplier);
    *(_DWORD *)&multiplier[20] = 7;
    *(_DWORD *)&multiplier[16] = 0;
    *(_WORD *)multiplier = 0;
    std::wstring::assign((std::wstring *)multiplier, &v4->unixName, 0, 0xFFFFFFFF);
    LOBYTE(v138) = 3;
    v120 = &v115;
    v115._Myres = 7;
    v115._Mysize = 0;
    v115._Bx._Buf[0] = 0;
    std::wstring::assign(&v115, L"errors loading car model: ", 0x1Au);
    LOBYTE(v138) = 4;
    mat._Rep = (std::_Ref_count_base *)&v114[4];
    *(_DWORD *)&v114[24] = 7;
    *(_DWORD *)&v114[20] = 0;
    *(_WORD *)&v114[4] = 0;
    std::wstring::assign((std::wstring *)&v114[4], L" ", 1u);
    LOBYTE(v138) = 5;
    *(_DWORD *)v114 = &v;
    name._Myres = (unsigned int)&v113;
    v113._Myres = 7;
    v113._Mysize = 0;
    v113._Bx._Buf[0] = 0;
    std::wstring::assign(&v113, L"There were ", 0xBu);
    v12 = v4->sim;
    LOBYTE(v138) = 6;
    v13 = Sim::getConsole(v12);
    LOBYTE(v138) = 5;
    v14 = Console::operator<<(v13, v113);
    v15 = Console::operator<<(v14, *(const int **)v114);
    LOBYTE(v138) = 4;
    v16 = Console::operator<<(v15, *(std::wstring *)&v114[4]);
    LOBYTE(v138) = 3;
    v17 = Console::operator<<(v16, v115);
    LOBYTE(v138) = 2;
    v18 = Console::operator<<(v17, *(std::wstring *)multiplier);
    LOBYTE(v138) = 0;
    Console::operator<<(v18, *(std::wstring *)&multiplier[24]);
    v125 = 1;
    v19 = std::_Func_impl<std::_Callable_obj<_lambda_034d48754ea12fd9a7c51584058b5d75_,0>,std::allocator<std::_Func_class<void,>>,void,>::_Get((std::_Func_impl<std::_Callable_obj<<lambda_77ca9348bb85863f3ac03214213671f3>,0>,std::allocator<std::_Func_class<void,SessionInfo const &> >,void,SessionInfo const &> *)&v119);
    v20 = (const std::wstring *)v19->_Object.__this;
    v21 = v19[1]._Object.__this;
    if ( v19->_Object.__this != v21 )
    {
      do
      {
        _Right._Myres = 7;
        _Right._Mysize = 0;
        _Right._Bx._Buf[0] = 0;
        std::wstring::assign(&_Right, v20, 0, 0xFFFFFFFF);
        LOBYTE(v138) = 7;
        name._Myres = (unsigned int)&multiplier[24];
        *(_DWORD *)&multiplier[44] = 7;
        *(_DWORD *)&multiplier[40] = 0;
        *(_WORD *)&multiplier[24] = 0;
        std::wstring::assign((std::wstring *)&multiplier[24], L"\n", 1u);
        LOBYTE(v138) = 8;
        mat._Rep = (std::_Ref_count_base *)multiplier;
        *(_DWORD *)&multiplier[20] = 7;
        *(_DWORD *)&multiplier[16] = 0;
        *(_WORD *)multiplier = 0;
        std::wstring::assign((std::wstring *)multiplier, &_Right, 0, 0xFFFFFFFF);
        LOBYTE(v138) = 9;
        v120 = &v115;
        v115._Myres = 7;
        v115._Mysize = 0;
        v115._Bx._Buf[0] = 0;
        std::wstring::assign(&v115, L": ", 2u);
        LOBYTE(v138) = 10;
        *(_DWORD *)&v114[24] = &v125;
        v129 = COERCE_FLOAT(v114);
        *(_DWORD *)&v114[20] = 7;
        *(_DWORD *)&v114[16] = 0;
        *(_WORD *)v114 = 0;
        std::wstring::assign((std::wstring *)v114, L"ERR:", 4u);
        LOBYTE(v138) = 11;
        v22 = Sim::getConsole(v123->sim);
        LOBYTE(v138) = 10;
        v23 = Console::operator<<(v22, *(std::wstring *)v114);
        v24 = Console::operator<<(v23, *(const int **)&v114[24]);
        LOBYTE(v138) = 9;
        v25 = Console::operator<<(v24, v115);
        LOBYTE(v138) = 8;
        v26 = Console::operator<<(v25, *(std::wstring *)multiplier);
        LOBYTE(v138) = 7;
        Console::operator<<(v26, *(std::wstring *)&multiplier[24]);
        ++v125;
        LOBYTE(v138) = 0;
        if ( _Right._Myres >= 8 )
          operator delete(_Right._Bx._Ptr);
        ++v20;
      }
      while ( v20 != (const std::wstring *)v21 );
    }
    v4 = v123;
  }
  v27 = v4->physics;
  v4->physicsInfo.engineDamageRPM = (int)(float)(v27->drivetrain.acEngine.rpmDamageThreshold * 0.94999999);
  v4->physicsInfo.hasDRS = v27->drs.isPresent;
  v28 = v27->ers.present;
  v4->physicsInfo.hasERS = v28;
  if ( v28 )
  {
    v4->physicsInfo.hasCockpitERSDeliveryProfile = v27->ers.cockpitControls.deliveryProfile;
    v4->physicsInfo.hasCockpitERSMguHMode = v27->ers.cockpitControls.mguHMode;
    v4->physicsInfo.hasCockpitERSRecovery = v27->ers.cockpitControls.recovery;
  }
  v4->physicsInfo.hasKERS = v27->kers.present;
  v4->physicsInfo.hasAdjustableTurbo = v27->drivetrain.acEngine.turboAdjustableFromCockpit;
  v4->physicsInfo.powerClassIndex = v27->powerClassIndex;
  if ( v27->ers.present )
    v4->physicsInfo.ersMaxJ = v27->ers.maxJ;
  if ( v27->kers.present )
    v4->physicsInfo.kersMaxJ = v27->kers.maxJ;
  v4->physicsInfo.steerLock = v27->steerLock;
  v4->physicsInfo.maxGear = v27->drivetrain.gears._Mylast - v27->drivetrain.gears._Myfirst - 2;
  v29 = ((double (*)(IRigidBody *))v27->body->getMass)(v27->body);
  v30 = v4->physics;
  *(float *)&v = v29;
  v31 = v;
  v4->physicsInfo.bodyMass = *(float *)&v;
  LODWORD(v4->physicsInfo.totalMass) = v31;
  v32 = v30->maxFuel;
  *(_DWORD *)&multiplier[44] = &v30->tyreCompounds;
  v4->physicsInfo.maxFuel = v32;
  std::vector<std::wstring>::operator=(
    &v4->physicsInfo.tyreCompounds,
    *(const std::vector<std::wstring> **)&multiplier[44]);
  v33 = v4->physics;
  v4->physicsInfo.minHeightM = v33->setupManager.minimumHeight_m;
  *(float *)&v34 = 0.0;
  v35 = (int)((unsigned __int64)(780903145i64
                               * ((char *)v33->ers.ersPowerControllers._Mylast
                                - (char *)v33->ers.ersPowerControllers._Myfirst)) >> 32) >> 3;
  *(float *)&v = 0.0;
  v4->physicsInfo.ersPowerControllerCount = v35 + (v35 >> 31);
  v36 = -3396 - (_DWORD)v4;
  v37 = v33->ers.defaultPowerControllerIndex;
  v38 = v4->physicsInfo.tyreRadius;
  v4->currentERSPowerIndex = v37;
  LODWORD(v124) = v4->physicsInfo.susBasePos;
  v125 = -3396 - (_DWORD)v4;
  do
  {
    v38[4] = *(float *)((char *)&v4->physics->tyres[0].data.width + v34);
    *v38 = *(float *)((char *)&v4->physics->tyres[0].data.radius + v34);
    v39 = *(_DWORD *)((char *)v38 + v36 + (unsigned int)v4->physics->suspensions._Myfirst);
    v129 = ((double (*)(int))*(_DWORD *)(*(_DWORD *)v39 + 72))(v39);
    v40 = v129;
    v41 = (char *)v38 + v125;
    v38[10] = v129;
    v42 = v40 + v4->physicsInfo.totalMass;
    v43 = v4->physics;
    *(_DWORD *)&multiplier[44] = 0;
    *(_DWORD *)&multiplier[40] = &Suspension `RTTI Type Descriptor';
    *(_DWORD *)&multiplier[36] = &ISuspension `RTTI Type Descriptor';
    v4->physicsInfo.totalMass = v42;
    v44 = __RTDynamicCast(
            *(ISuspension **)((char *)v43->suspensions._Myfirst + (unsigned int)v41),
            0,
            *(_DWORD *)&multiplier[36],
            *(_DWORD *)&multiplier[40],
            *(_DWORD *)&multiplier[44]);
    if ( v44 )
    {
      v38[23] = *(float *)(v44 + 28);
      v38[19] = *(float *)(v44 + 24);
    }
    else
    {
      v38[23] = 0.0;
      v38[19] = 0.0;
    }
    v45 = v4->physics;
    *(_DWORD *)&multiplier[44] = &name._Bx._Alias[12];
    v46 = *(_DWORD *)((char *)v38 + v125 + (unsigned int)v45->suspensions._Myfirst);
    v47 = (*(int (**)(int, char *))(*(_DWORD *)v46 + 40))(v46, &name._Bx._Alias[12]);
    v48 = v124;
    v49 = v;
    *(_QWORD *)LODWORD(v124) = *(_QWORD *)v47;
    *(_DWORD *)(LODWORD(v48) + 8) = *(_DWORD *)(v47 + 8);
    v50 = v4->physics;
    LODWORD(v124) = LODWORD(v48) + 12;
    v36 = v125;
    v51 = *(_DWORD *)((char *)&v50->tyres[0].data.angularInertia + v49);
    v34 = v49 + 1632;
    *((_DWORD *)v38++ + 51) = v51;
    v = v34;
  }
  while ( v34 < 6528 );
  v52 = v4->physics;
  *(_QWORD *)&v4->physicsInfo.ridePickupPoint[0].x = *(_QWORD *)&v52->ridePickupPoint[0].x;
  v4->physicsInfo.ridePickupPoint[0].z = v52->ridePickupPoint[0].z;
  v53 = v4->physics;
  *(_QWORD *)&v4->physicsInfo.ridePickupPoint[1].x = *(_QWORD *)&v53->ridePickupPoint[1].x;
  v4->physicsInfo.ridePickupPoint[1].z = v53->ridePickupPoint[1].z;
  v54 = v4->physics;
  v55 = &v54->aeroMap.wings._Mylast->data;
  v56 = &v54->aeroMap.wings._Myfirst->data;
  if ( v56 != v55 )
  {
    v57 = &v123->physicsInfo.wingData;
    LODWORD(v129) = &v123->physicsInfo.wingData;
    do
    {
      std::vector<WingData>::push_back(v57, v56);
      v57 = (std::vector<WingData> *)LODWORD(v129);
      v56 = (const WingData *)((char *)v56 + 528);
    }
    while ( v56 != v55 );
  }
  v58 = (RaceEngineer *)operator new(12);
  name._Myres = (unsigned int)v58;
  v59 = v123;
  LOBYTE(v138) = 12;
  if ( v58 )
    RaceEngineer::RaceEngineer(v58, v123->physics);
  else
    v60 = 0;
  v61 = v59->raceEngineer._Myptr;
  LOBYTE(v138) = 0;
  v59->raceEngineer._Myptr = v60;
  if ( v61 )
    ((void (*)(RaceEngineer *, int))v61->~RaceEngineer)(v61, 1);
  v62 = RaceEngineer::getFrontCasterRAD(v59->raceEngineer._Myptr);
  v63 = &v59->physics->drivetrain.acEngine;
  v59->physicsInfo.caster = v62 * 57.29578;
  v64 = Engine::getMaxPowerW(v63);
  v65 = v59->physics;
  v59->physicsInfo.maxPowerW = v64;
  v66 = Engine::getMaxTorqueNM(&v65->drivetrain.acEngine);
  v67 = v59->raceEngineer._Myptr;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = &name._Mysize;
  v59->physicsInfo.maxTorqueNM = v66;
  v68 = RaceEngineer::getKPI_RAD(v67, *(KPI **)&multiplier[40], *(int *)&multiplier[44]);
  v59->physicsInfo.kpi.angleRAD = v68->angleRAD;
  v69 = &v59->physics->drivetrain.acEngine.gasCoastOffsetCurve;
  v59->physicsInfo.kpi.scrubRadius = v68->scrubRadius;
  v70 = Curve::getCount(v69);
  v71 = v59->guid == 0;
  v72 = v59->physics;
  v59->physicsInfo.engineBrakeSettingsCount = v70;
  v59->physicsInfo.maxRpm = v72->drivetrain.acEngine.defaultEngineLimiter;
  v59->currentEngineBrakeSetting = v72->drivetrain.acEngine.coastSettingsDefaultIndex;
  if ( v71 )
  {
    CarAvatar::initControls(v59, a2);
    if ( v59->showDownShiftProtetion )
    {
      v73 = &v59->physics->drivetrain.downshiftProtectionFunction;
      v74 = v59->physics->drivetrain.downshiftProtectionFunction._Impl;
      if ( v74 )
      {
        ((void (__stdcall *)(bool))v74->_Delete_this)(v74 != (std::_Func_base<void> *)v73);
        v73->_Impl = 0;
      }
      v73->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_21d2bc46b57398bfae7fef3b7ac4d66f_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
      v73->_Space._Pfn[1] = (void (__cdecl *)())v59;
      v73->_Impl = (std::_Func_base<void> *)v73;
    }
  }
  v75 = Engine::getMaxTurboBoost(&v59->physics->drivetrain.acEngine, 0);
  v76 = v59->physics;
  v59->physicsInfo.maxTurboBoost = v75;
  *(_DWORD *)&multiplier[44] = v59;
  v59->physicsInfo.turboCount = v76->drivetrain.acEngine.turbos._Mylast - v76->drivetrain.acEngine.turbos._Myfirst;
  *(_DWORD *)&multiplier[20] = &std::_Func_impl<std::_Callable_obj<_lambda_6e1b510aee438ddd7ada08f7ff0b30e0_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  *(_DWORD *)&multiplier[24] = v59;
  *(_DWORD *)&multiplier[36] = &multiplier[20];
  v77 = (Event<OnPhysicsStepCompleted> *)&v59->physics->evOnLapCompleted;
  LOBYTE(v138) = 0;
  Event<std::wstring>::addHandler(
    v77,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&multiplier[20],
    *(void **)&multiplier[44]);
  *(_DWORD *)&multiplier[44] = v59;
  *(_DWORD *)&multiplier[20] = &std::_Func_impl<std::_Callable_obj<_lambda_d99b5d3b5c4cdd889728c1c781509766_,0>,std::allocator<std::_Func_class<void,OnSectorSplitEvent const &>>,void,OnSectorSplitEvent const &>::`vftable';
  *(_DWORD *)&multiplier[24] = v59;
  *(_DWORD *)&multiplier[36] = &multiplier[20];
  v78 = (Event<SessionInfo> *)&v59->physics->evOnSectorSplit;
  LOBYTE(v138) = 0;
  Event<float>::addHandler(v78, *(std::function<void __cdecl(SessionInfo const &)> *)&multiplier[20], v59);
  *(_DWORD *)&multiplier[44] = v59;
  *(_DWORD *)&multiplier[20] = &std::_Func_impl<std::_Callable_obj<_lambda_b2a641b87b72d2a0d3338d9f168de1ea_,0>,std::allocator<std::_Func_class<void,std::pair<int,int> const &>>,void,std::pair<int,int> const &>::`vftable';
  *(_DWORD *)&multiplier[24] = v59;
  *(_DWORD *)&multiplier[36] = &multiplier[20];
  v79 = (Event<SessionInfo> *)&v59->physics->evOnTyreCompoundChanged;
  LOBYTE(v138) = 0;
  Event<float>::addHandler(v79, *(std::function<void __cdecl(SessionInfo const &)> *)&multiplier[20], v59);
  *(_DWORD *)&multiplier[44] = v59;
  *(_DWORD *)&multiplier[20] = &std::_Func_impl<std::_Callable_obj<_lambda_00b212ba64b49c859d631241c9189281_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&multiplier[24] = v59;
  *(_DWORD *)&multiplier[36] = &multiplier[20];
  v80 = (Event<OnPhysicsStepCompleted> *)&v59->sim->evOnNewSession;
  LOBYTE(v138) = 0;
  Event<std::wstring>::addHandler(
    v80,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&multiplier[20],
    v59);
  v81 = std::operator+<wchar_t>(&v132, L"content/cars/", &v59->unixName);
  LOBYTE(v138) = 17;
  std::operator+<wchar_t>(&path, v81, L"/collider.kn5");
  LOBYTE(v138) = 19;
  if ( v132._Myres >= 8 )
    operator delete(v132._Bx._Ptr);
  v132._Myres = 7;
  v132._Bx._Buf[0] = 0;
  v132._Mysize = 0;
  v82 = (void (*)(const char *const, ...))_printf;
  if ( Path::fileExists(a2, &path, 0) )
  {
    v83 = &path;
    if ( path._Myres >= 8 )
      v83 = (std::wstring *)path._Bx._Ptr;
    _printf("LOADING COLLIDER MESH FILE: %S\n", v83->_Bx._Buf);
    KN5IO::KN5IO(&v130, v59->game->graphics);
    v84 = &path;
    filename._Myres = 7;
    if ( path._Myres >= 8 )
      v84 = (std::wstring *)path._Bx._Ptr;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    LOBYTE(v138) = 20;
    if ( v84->_Bx._Buf[0] )
      v85 = wcslen(v84->_Bx._Buf);
    else
      v85 = 0;
    std::wstring::assign(&filename, v84->_Bx._Buf, v85);
    LOBYTE(v138) = 21;
    *(float *)&v86 = COERCE_FLOAT(KN5IO::load(&v130, &filename));
    v129 = *(float *)&v86;
    LOBYTE(v138) = 20;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Bx._Buf[0] = 0;
    filename._Mysize = 0;
    v87 = __RTDynamicCast(
            *(*v86->nodes._Myfirst)->nodes._Myfirst,
            0,
            &Node `RTTI Type Descriptor',
            &Mesh `RTTI Type Descriptor',
            0);
    *(_OWORD *)&res_12.M11 = 0i64;
    v88 = (Mesh *)v87;
    *(_OWORD *)&res_12.M21 = 0i64;
    *(_OWORD *)&res_12.M31 = 0i64;
    *(_OWORD *)&res_12.M41 = 0i64;
    *(_OWORD *)&bm_12.M11 = _xmm;
    *(_OWORD *)&bm_12.M21 = _xmm;
    *(_OWORD *)&bm_12.M31 = _xmm;
    *(_OWORD *)&bm_12.M41 = _xmm;
    CarAvatar::makeBodyMatrix(v59, (int)v59, v87, &bm_12, &res_12);
    Car::initColliderMesh(v59->physics, v88, &res_12);
    GraphicsManager::compile(v59->game->graphics, v88);
    v89 = (Material *)operator new(104);
    name._Myres = (unsigned int)v89;
    v90 = 0;
    LOBYTE(v138) = 22;
    if ( v89 )
    {
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      std::wstring::assign(&_Right, L"MESH_COLLIDER_MATERIAL", 0x16u);
      LOBYTE(v138) = 23;
      LODWORD(v126) = 1;
      LODWORD(v122) = 1;
      Material::Material(v89, &_Right, v59->game->graphics);
    }
    v138 = 24;
    mat._Ptr = 0;
    mat._Rep = 0;
    std::shared_ptr<Material>::_Resetp<Material>(&mat, v90);
    v138 = 26;
    if ( (LOBYTE(v126) & 1) != 0 )
    {
      LODWORD(v126) &= 0xFFFFFFFE;
      if ( _Right._Myres >= 8 )
        operator delete(_Right._Bx._Ptr);
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
    }
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"ksColourShader", 0xEu);
    LOBYTE(v138) = 27;
    Material::setShader(mat._Ptr, a2, &name);
    LOBYTE(v138) = 26;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    *(_DWORD *)&multiplier[44] = 6;
    *(_DWORD *)&multiplier[40] = L"colour";
    n._Myres = 7;
    mat._Ptr->blendMode = eAlphaBlend;
    n._Mysize = 0;
    mat._Ptr->doubleFace = 1;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, *(const wchar_t **)&multiplier[40], *(unsigned int *)&multiplier[44]);
    LOBYTE(v138) = 28;
    *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&name._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
    Material::setVar(mat._Ptr, &n, (const vec4f *)&name._Bx._Alias[8]);
    LOBYTE(v138) = 26;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
    v91 = (Node *)operator new(188);
    name._Myres = (unsigned int)v91;
    v92 = 0;
    LOBYTE(v138) = 29;
    if ( v91 )
    {
      n._Myres = 7;
      n._Mysize = 0;
      n._Bx._Buf[0] = 0;
      std::wstring::assign(&n, L"MESH_COLLIDER", 0xDu);
      LOBYTE(v138) = 30;
      LODWORD(v126) |= 2u;
      v122 = v126;
      Node::Node(v91, &n);
    }
    v59->meshCollider = v92;
    v138 = 26;
    if ( (LOBYTE(v126) & 2) != 0 )
    {
      LODWORD(v126) &= 0xFFFFFFFD;
      if ( n._Myres >= 8 )
        operator delete(n._Bx._Ptr);
    }
    ((void (*)(Node *, float))v59->meshCollider->addChild)(v59->meshCollider, COERCE_FLOAT(LODWORD(v129)));
    v59->meshCollider->isActive = 0;
    assignColliderMaterials(&mat, v59->meshCollider);
    v59->carNode->addChild(v59->carNode, v59->meshCollider);
    v93 = (const __m128i *)ModelBoundaries::computeAAModelBoundaries(
                             (ModelBoundariesCoordinates *)&n,
                             v59->meshCollider);
    v94 = mat._Rep;
    LOBYTE(v138) = 20;
    *(__m128i *)&v59->modelBoundaries.front = _mm_loadu_si128(v93);
    *(_QWORD *)&v59->modelBoundaries.top = v93[1].m128i_i64[0];
    if ( v94 )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v94->_Uses, 0xFFFFFFFF) )
      {
        v94->_Destroy(v94);
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v94->_Weaks, 0xFFFFFFFF) )
          v94->_Delete_this(v94);
      }
    }
    LOBYTE(v138) = 19;
    KN5IO::~KN5IO(&v130);
    v82 = (void (*)(const char *const, ...))_printf;
  }
  v95 = v59->physics;
  *(_DWORD *)&multiplier[44] = 0;
  v59->graphicSteerLockDegrees = v95->steerLock;
  *(_DWORD *)&multiplier[40] = 7;
  *(_DWORD *)&multiplier[36] = 0;
  *(_WORD *)&multiplier[20] = 0;
  std::wstring::assign((std::wstring *)&multiplier[20], L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&v131, a2, *(std::wstring *)&multiplier[20], multiplier[44]);
  LOBYTE(v138) = 32;
  if ( !v131.ready )
    goto LABEL_73;
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"STEER_ANIMATION", 0xFu);
  LOBYTE(v138) = 33;
  LODWORD(v126) |= 4u;
  v122 = v126;
  v96 = INIReader::hasSection(&v131, &n);
  HIBYTE(v128) = 1;
  if ( !v96 )
LABEL_73:
    HIBYTE(v128) = 0;
  v138 = 32;
  if ( (LOBYTE(v126) & 4) != 0 && n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  if ( HIBYTE(v128) )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"MAX_DEGREES", 0xBu);
    LOBYTE(v138) = 34;
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    std::wstring::assign(&_Right, L"STEER_ANIMATION", 0xFu);
    LOBYTE(v138) = 35;
    v129 = INIReader::getFloat(&v131, &_Right, &n);
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    LOBYTE(v138) = 32;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
    if ( v129 != 0.0 && v59->graphicSteerLockDegrees > v129 )
    {
      n._Myres = 7;
      n._Mysize = 0;
      n._Bx._Buf[0] = 0;
      std::wstring::assign(&n, L"MAX_DEGREES", 0xBu);
      LOBYTE(v138) = 36;
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      std::wstring::assign(&_Right, L"STEER_ANIMATION", 0xFu);
      LOBYTE(v138) = 37;
      v97 = INIReader::getFloat(&v131, &_Right, &n);
      v98 = _Right._Myres < 8;
      v59->graphicSteerLockDegrees = v97;
      if ( !v98 )
        operator delete(_Right._Bx._Ptr);
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      LOBYTE(v138) = 32;
      if ( n._Myres >= 8 )
        operator delete(n._Bx._Ptr);
    }
  }
  v99 = v59->physics;
  *(_DWORD *)&multiplier[44] = 1065353216;
  *(_DWORD *)&multiplier[40] = 0;
  *(_QWORD *)&multiplier[32] = (unsigned int)&v99->steerAssist;
  name._Myres = (unsigned int)&multiplier[8];
  *(_DWORD *)&multiplier[28] = 7;
  *(_DWORD *)&multiplier[24] = 0;
  *(_WORD *)&multiplier[8] = 0;
  std::wstring::assign((std::wstring *)&multiplier[8], L"steerAssist", 0xBu);
  v100 = v59->sim;
  LOBYTE(v138) = 38;
  v101 = Sim::getConsole(v100);
  LOBYTE(v138) = 32;
  Console::addVar(
    v101,
    *(std::wstring *)&multiplier[8],
    *(float **)&multiplier[32],
    *(IVarCallback **)&multiplier[36],
    multiplier[40],
    *(float *)&multiplier[44]);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"getSteerAssist", 0xEu);
  name._Myres = (unsigned int)&multiplier[24];
  *(_DWORD *)&multiplier[24] = &std::_Func_impl<std::_Callable_obj<_lambda_9f8ec50c785701d61ef10e4025ebf7de_,0>,std::allocator<std::_Func_class<std::wstring,>>,std::wstring,>::`vftable';
  *(_DWORD *)&multiplier[40] = &multiplier[24];
  mat._Rep = (std::_Ref_count_base *)multiplier;
  *(_DWORD *)multiplier = &std::_Func_impl<std::_Callable_obj<_lambda_7d5b8bdd81bacc0d5b732cf601aab567_,0>,std::allocator<std::_Func_class<bool,std::wstring>>,bool,std::wstring>::`vftable';
  *(_DWORD *)&multiplier[4] = v59;
  *(_DWORD *)&multiplier[16] = multiplier;
  v102 = v59->sim;
  v115._Myres = (unsigned int)&n;
  LOBYTE(v138) = 43;
  v103 = Sim::getConsole(v102);
  LOBYTE(v138) = 39;
  Console::addCommand(
    v103,
    (const std::wstring *)v115._Myres,
    *(std::function<bool __cdecl(std::wstring)> *)multiplier,
    *(std::function<std::wstring __cdecl(void)> *)&multiplier[24]);
  LOBYTE(v138) = 32;
  if ( n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  v104 = v59->physics;
  v105 = v59->suspensionAvatar;
  *(_DWORD *)&multiplier[44] = 0;
  v106 = v104->tyres[0].data.radius;
  v107 = v105->__vftable;
  v129 = v106;
  v108 = ((double (*)(ISuspensionAvatar *, _DWORD))v107->getGraphicsRadius)(v105, 0);
  v109 = v59->physics;
  v110 = v59->suspensionAvatar;
  *(float *)&v = v108;
  *(_DWORD *)&multiplier[44] = 1;
  v111 = v109->tyres[2].data.radius;
  v112 = v110->__vftable;
  v124 = v111;
  v122 = v112->getGraphicsRadius(v110, 1);
  v82("RADIUS FRONT, P:%f , G:%f , diff:%f\n", v129, *(float *)&v, (float)(v129 - *(float *)&v));
  v82("RADIUS REAR, P:%f , G:%f , diff:%f\n", v124, v122, (float)(v124 - v122));
  LOBYTE(v138) = 19;
  INIReaderDocuments::~INIReaderDocuments(&v131);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  v138 = -1;
  ErrorBlob::~ErrorBlob(&v119);
}
// 5CDC1C: variable 'v9' is possibly undefined
// 5CE34C: variable 'v60' is possibly undefined
// 5CE819: variable 'v90' is possibly undefined
// 5CEA07: variable 'v92' is possibly undefined
// 78E1CE: using guessed type int __cdecl operator new(_DWORD);
// 78E1D4: using guessed type int __cdecl operator delete(_DWORD);
// 78E358: using guessed type int __cdecl __RTDynamicCast(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 89278C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_21d2bc46b57398bfae7fef3b7ac4d66f_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
// 8927AC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_6e1b510aee438ddd7ada08f7ff0b30e0_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
// 8927CC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_d99b5d3b5c4cdd889728c1c781509766_,0>,std::allocator<std::_Func_class<void,OnSectorSplitEvent const &>>,void,OnSectorSplitEvent const &>::`vftable';
// 8927EC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_b2a641b87b72d2a0d3338d9f168de1ea_,0>,std::allocator<std::_Func_class<void,std::pair<int,int> const &>>,void,std::pair<int,int> const &>::`vftable';
// 89280C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_00b212ba64b49c859d631241c9189281_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
// 89282C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_7d5b8bdd81bacc0d5b732cf601aab567_,0>,std::allocator<std::_Func_class<bool,std::wstring>>,bool,std::wstring>::`vftable';
// 89284C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_9f8ec50c785701d61ef10e4025ebf7de_,0>,std::allocator<std::_Func_class<std::wstring,>>,std::wstring,>::`vftable';
// 17CC400: using guessed type __int128 _xmm;
// 17CC450: using guessed type __int128 _xmm;
// 17CC460: using guessed type __int128 _xmm;
// 17CC4F0: using guessed type __int128 _xmm;
// 17CC5A0: using guessed type __int128 _xmm;
// 184053C: using guessed type struct Mesh Mesh `RTTI Type Descriptor';
// 1847280: using guessed type struct ISuspension ISuspension `RTTI Type Descriptor';
// 184729C: using guessed type struct Suspension Suspension `RTTI Type Descriptor';
// 185F62C: using guessed type struct Node Node `RTTI Type Descriptor';
// 18600E0: using guessed type struct GameObject GameObject `RTTI Type Descriptor';
// 1861E2C: using guessed type struct PhysicsAvatar PhysicsAvatar `RTTI Type Descriptor';

//----- (005CF0A0) --------------------------------------------------------
bool CarAvatar::isAbsAvailable()
{
  Car *v1; // eax
  bool result; // al

  v1 = this->physics;
  if ( v1 )
    result = v1->abs.isPresent;
  else
    result = 0;
  return result;
}

//----- (005CF0C0) --------------------------------------------------------
bool CarAvatar::isAbsEnabled()
{
  Car *v1; // eax

  v1 = this->physics;
  if ( !v1 )
    return 0;
  return v1->abs.isActive && v1->abs.isPresent;
}

//----- (005CF0F0) --------------------------------------------------------
bool CarAvatar::isAbsInAction()
{
  float *v1; // edx

  v1 = (float *)this->physics;
  if ( !v1 )
    return 0;
  return this->physicsState.brake > 0.1 && (v1[716] != 1.0 || v1[1124] != 1.0 || v1[1532] != 1.0 || v1[1940] != 1.0);
}

//----- (005CF170) --------------------------------------------------------
bool CarAvatar::isConnected()
{
  return this->carNode->isActive;
}

//----- (005CF180) --------------------------------------------------------
bool CarAvatar::isCurrentLapValid()
{
  Car *v2; // ecx
  bool result; // al

  if ( ReplayManager::isInReplaymode(this->sim->replayManager) || (v2 = this->physics) == 0 )
    result = 1;
  else
    result = TimeTransponder::getCuts(&v2->transponder) == 0;
  return result;
}

//----- (005CF1C0) --------------------------------------------------------
bool CarAvatar::isEdlEnabled()
{
  Car *v1; // eax

  v1 = this->physics;
  if ( !v1 )
    return 0;
  return v1->edl.isActive && v1->edl.isPresent;
}

//----- (005CF1F0) --------------------------------------------------------
BOOL CarAvatar::isInPit()
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  v1 = this->physicsState.worldMatrix.M41 - this->pitPosition.M41;
  v2 = (float)((float)(this->physicsState.worldMatrix.M42 - this->pitPosition.M42)
             * (float)(this->physicsState.worldMatrix.M42 - this->pitPosition.M42))
     + (float)(v1 * v1);
  v3 = 0.0;
  v4 = v2
     + (float)((float)(this->physicsState.worldMatrix.M43 - this->pitPosition.M43)
             * (float)(this->physicsState.worldMatrix.M43 - this->pitPosition.M43));
  if ( v4 != 0.0 )
    v3 = fsqrt(v4);
  return v3 < 1.5;
}

//----- (005CF260) --------------------------------------------------------
bool CarAvatar::isInPitlane()
{
  return this->inPitlane;
}

//----- (005CF270) --------------------------------------------------------
BOOL CarAvatar::isInSpawnPosition(const std::wstring *setName)
{
  Sim *v3; // ebx
  GameObject **v4; // esi
  TrackAvatar *v5; // edi
  unsigned int v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  mat44f pos; // [esp+10h] [ebp-40h] BYREF

  v3 = this->sim;
  v4 = v3->gameObjects._Myfirst;
  if ( v4 == v3->gameObjects._Mylast )
  {
LABEL_4:
    v5 = 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = (TrackAvatar *)__RTDynamicCast(
                            *v4,
                            0,
                            &GameObject `RTTI Type Descriptor',
                            &TrackAvatar `RTTI Type Descriptor',
                            0);
      if ( v5 )
        break;
      if ( ++v4 == v3->gameObjects._Mylast )
        goto LABEL_4;
    }
  }
  v6 = CarRaceInfo::getSpawnPositionIndex(&this->raceInfo, setName);
  TrackAvatar::getSpawnPosition(v5, &pos, setName, v6);
  v7 = 0.0;
  v8 = (float)((float)((float)(this->physicsState.worldMatrix.M42 - pos.M42)
                     * (float)(this->physicsState.worldMatrix.M42 - pos.M42))
             + (float)((float)(this->physicsState.worldMatrix.M41 - pos.M41)
                     * (float)(this->physicsState.worldMatrix.M41 - pos.M41)))
     + (float)((float)(this->physicsState.worldMatrix.M43 - pos.M43)
             * (float)(this->physicsState.worldMatrix.M43 - pos.M43));
  if ( v8 != 0.0 )
    v7 = fsqrt(v8);
  return v7 < 1.0;
}
// 78E358: using guessed type int __cdecl __RTDynamicCast(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 18600E0: using guessed type struct GameObject GameObject `RTTI Type Descriptor';
// 1861908: using guessed type struct TrackAvatar TrackAvatar `RTTI Type Descriptor';

//----- (005CF350) --------------------------------------------------------
bool CarAvatar::isMinSpeedPenaltyClearDisabled()
{
  Car *v1; // ecx
  bool result; // al

  v1 = this->physics;
  if ( v1 )
    result = Car::isMinSpeedPenaltyClearDisabled(v1);
  else
    result = 0;
  return result;
}

//----- (005CF370) --------------------------------------------------------
bool Kers::isPresent(Kers *this)
{
  return this->present;
}

//----- (005CF380) --------------------------------------------------------
bool CarAvatar::isRequestingPitStop()
{
  Car *v1; // eax
  bool result; // al

  v1 = this->physics;
  if ( v1 )
    result = v1->isRequestingPitStop;
  else
    result = 0;
  return result;
}

//----- (005CF3A0) --------------------------------------------------------
bool CarAvatar::isTcAvailable()
{
  Car *v1; // eax
  bool result; // al

  v1 = this->physics;
  if ( v1 )
    result = v1->tractionControl.isPresent;
  else
    result = 0;
  return result;
}

//----- (005CF3C0) --------------------------------------------------------
bool CarAvatar::isTcEnabled()
{
  Car *v1; // eax

  v1 = this->physics;
  if ( !v1 )
    return 0;
  return v1->tractionControl.isActive && v1->tractionControl.isPresent;
}

//----- (005CF3F0) --------------------------------------------------------
bool CarAvatar::isTcInAction()
{
  Car *v1; // eax
  bool result; // al

  v1 = this->physics;
  if ( v1 )
    result = v1->tractionControl.isInAction;
  else
    result = 0;
  return result;
}

//----- (005CF410) --------------------------------------------------------
bool CarAvatar::isVisible()
{
  return this->bodyTransform->isActive;
}

//----- (005CF420) --------------------------------------------------------
bool Sim::isVrRoom(Sim *this)
{
  return this->isRoomVR;
}

//----- (005CF430) --------------------------------------------------------
void CarAvatar::lockControlsUntilTime(long double time, long double start, bool forceToPits)
{
  std::function<void __cdecl(void)> v5; // [esp-18h] [ebp-34h] BYREF
  CarAvatar::lockControlsUntilTime::__l13::<lambda_d1ac94c667261f9685880a1644e28d33> _Func; // [esp+4h] [ebp-18h] BYREF

  if ( this->physics )
  {
    _Func.forceToPits = forceToPits;
    _Func.time = time;
    _Func.__this = this;
    _Func.start = start;
    std::function<void __cdecl (void)>::function<void __cdecl (void)>(&v5, &_Func);
    PhysicsAvatar::executeOnPhysicsThread(this->sim->physicsAvatar, v5);
  }
}

//----- (005CF490) --------------------------------------------------------
void __userpurge CarAvatar::makeBodyMatrix(@<ecx>, int a2@<edi>, int a3@<esi>, const mat44f *bm, mat44f *res)
{
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  __m128 v14; // xmm3
  __int128 v15; // xmm2
  __int128 v16; // xmm3
  __int128 v17; // xmm1
  float v18; // [esp+Ch] [ebp-8Ch]
  float v19; // [esp+10h] [ebp-88h]
  mat44f v20; // [esp+18h] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+58h] [ebp-40h] BYREF

  *(__m128i *)&res->M11 = _mm_loadu_si128((const __m128i *)bm);
  *(__m128i *)&res->M21 = _mm_loadu_si128((const __m128i *)&bm->M21);
  *(__m128i *)&res->M31 = _mm_loadu_si128((const __m128i *)&bm->M31);
  *(__m128i *)&res->M41 = _mm_loadu_si128((const __m128i *)&bm->M41);
  v6 = this->graphicsOffset.x;
  v7 = this->graphicsOffset.y;
  v8 = this->graphicsOffset.z;
  v9 = (float)((float)((float)(bm->M12 * v6) + (float)(bm->M22 * v7)) + (float)(bm->M32 * v8)) + bm->M42;
  v10 = (float)((float)((float)(bm->M13 * v6) + (float)(bm->M23 * v7)) + (float)(bm->M33 * v8)) + bm->M43;
  res->M41 = (float)((float)((float)(bm->M21 * v7) + (float)(v6 * bm->M11)) + (float)(bm->M31 * v8)) + bm->M41;
  res->M42 = v9;
  res->M43 = v10;
  if ( this->graphicsPitchRotation != 0.0 )
  {
    v18 = __libm_sse2_cosf(a2, a3).m128_f32[0];
    v19 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f(&v20);
    v20.M44 = 1.0;
    v20.M11 = (float)(1.0 - v18) + v18;
    v20.M22 = (float)((float)(1.0 - v18) * 0.0) + v18;
    v20.M33 = v20.M22;
    v20.M12 = (float)(v19 * 0.0) + (float)((float)(1.0 - v18) * 0.0);
    v20.M21 = (float)((float)(1.0 - v18) * 0.0) - (float)(v19 * 0.0);
    v20.M13 = v20.M21;
    v20.M31 = v20.M12;
    v11 = *(__m128 *)&res->M31;
    v12 = *(__m128 *)&res->M21;
    v20.M23 = v19 + (float)((float)(1.0 - v18) * 0.0);
    v13 = *(__m128 *)&res->M41;
    v20.M32 = (float)((float)(1.0 - v18) * 0.0) - v19;
    v14 = *(__m128 *)&res->M11;
    M2.r[1] = v12;
    v15 = *(_OWORD *)&v20.M31;
    M2.r[0] = v14;
    v16 = *(_OWORD *)&v20.M41;
    M2.r[2] = v11;
    v17 = *(_OWORD *)&v20.M21;
    M2.r[3] = v13;
    *(__m128 *)&res->M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v20.M11);
    *(_OWORD *)&res->M21 = v17;
    *(_OWORD *)&res->M31 = v15;
    *(_OWORD *)&res->M41 = v16;
  }
}
// 5CF490: could not find valid save-restore pair for edi
// 5CF490: could not find valid save-restore pair for esi
// 78E7F2: using guessed type __m128 __stdcall __libm_sse2_cosf(_DWORD, _DWORD);
// 78E7F8: using guessed type __m128 __libm_sse2_sinf(void);

//----- (005CF6B0) --------------------------------------------------------
void __cdecl makeTyresDoubleFacedShadows(Node *node)
{
  int v1; // eax
  int v2; // esi
  Node **v3; // esi
  int v4; // edi
  unsigned int v5; // ebx

  v1 = __RTDynamicCast(node, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
  v2 = v1;
  if ( v1
    && !std::wstring::compare(
          (std::wstring *)(*(_DWORD *)(*(_DWORD *)(v1 + 248) + 24) + 4),
          0,
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 248) + 24) + 20),
          L"ksTyres",
          7u) )
  {
    *(_BYTE *)(*(_DWORD *)(v2 + 248) + 100) = 1;
  }
  v3 = node->nodes._Myfirst;
  v4 = 0;
  v5 = (unsigned int)((char *)node->nodes._Mylast - (char *)v3 + 3) >> 2;
  if ( v3 > node->nodes._Mylast )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      makeTyresDoubleFacedShadows(*v3);
      ++v4;
      ++v3;
    }
    while ( v4 != v5 );
  }
}
// 78E358: using guessed type int __cdecl __RTDynamicCast(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 184053C: using guessed type struct Mesh Mesh `RTTI Type Descriptor';
// 185F62C: using guessed type struct Node Node `RTTI Type Descriptor';

//----- (005CF740) --------------------------------------------------------
double CarAvatar::modifyUserFFGain(float offset)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  Sim *v5; // ecx
  std::function<void __cdecl(void)> v7; // [esp-18h] [ebp-38h] BYREF
  float v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-4h]

  if ( this->physics && offset != 0.0 )
  {
    v3 = this->userFFGain + offset;
    v4 = FLOAT_200_0;
    if ( v3 <= 200.0 )
    {
      if ( v3 >= 0.0 )
        v4 = this->userFFGain + offset;
      else
        v4 = 0.0;
    }
    this->userFFGain = v4;
    v8 = v4;
    v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_db015e9c94bad3e0f44628fbe783c09e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v7._Space._Alias[4] = __PAIR64__(LODWORD(v4), (unsigned int)this);
    v7._Impl = (std::_Func_base<void> *)&v7;
    v5 = this->sim;
    v9 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v5->physicsAvatar, v7);
  }
  return this->userFFGain;
}
// 892B4C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_db015e9c94bad3e0f44628fbe783c09e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
// 17CC21C: using guessed type const float FLOAT_200_0;

//----- (005CF800) --------------------------------------------------------
void CarAvatar::onNewSession()
{
  Session *v2; // eax
  Sim *v3; // ecx
  std::function<void __cdecl(void)> v4; // [esp-18h] [ebp-98h] BYREF
  Session result; // [esp+10h] [ebp-70h] BYREF
  int v6; // [esp+7Ch] [ebp-4h]

  v2 = RaceManager::getCurrentSession(this->sim->raceManager, &result);
  v6 = 0;
  CarAvatar::goToSpawnPosition(this, &v2->spawSet);
  v6 = -1;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  if ( this->physics )
  {
    v4._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_33c5f6518538af62fe8724a8493e6b8e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    v4._Space._Pfn[1] = (void (__cdecl *)())this;
    v4._Impl = (std::_Func_base<void> *)&v4;
    v3 = this->sim;
    v6 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v3->physicsAvatar, v4);
  }
}
// 78E1D4: using guessed type int __cdecl operator delete(_DWORD);
// 892AAC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_33c5f6518538af62fe8724a8493e6b8e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005CF900) --------------------------------------------------------
void CarAvatar::onPostLoad(unsigned int a2@<ebx>)
{
  ICollisionObject *v3; // eax
  ICollisionObject *v4; // eax
  ICollisionObject *v5; // esi
  Sim *v6; // ebx
  GameObject **v7; // esi
  int v8; // edi
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v9[2]; // [esp-1Ch] [ebp-4Ch] BYREF
  ICollisionObject *_Val; // [esp+20h] [ebp-10h] BYREF
  int v11; // [esp+2Ch] [ebp-4h]

  v3 = (ICollisionObject *)operator new(232);
  _Val = v3;
  v11 = 0;
  if ( v3 )
  {
    CarFakeShadow::CarFakeShadow((CarFakeShadow *)v3, a2, this);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v11 = -1;
  _Val = v5;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
  v5[9].__vftable = (ICollisionObject_vtbl *)this;
  v6 = this->sim;
  v7 = v6->gameObjects._Myfirst;
  if ( v7 != v6->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v8 = __RTDynamicCast(*v7, 0, &GameObject `RTTI Type Descriptor', &ReplayManager `RTTI Type Descriptor', 0);
      if ( v8 )
        break;
      if ( ++v7 == v6->gameObjects._Mylast )
        return;
    }
    v9[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_be99df9070aa0c099bca5887c9856fd4_,0>,std::allocator<std::_Func_class<void,int const &>>,void,int const &>::`vftable';
    v9[0]._Space._Pfn[1] = (void (__cdecl *)())this;
    v9[0]._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)v9;
    v11 = -1;
    Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)(v8 + 76), v9[0], this);
    v9[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_62b6e2b8032ba7c6f0fdf3e52f500a08_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
    v9[0]._Space._Pfn[1] = (void (__cdecl *)())this;
    v9[0]._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)v9;
    v11 = -1;
    Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)(v8 + 52), v9[0], this);
    v9[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_7eaf1073bac1e48eea38acd85c1f65ee_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
    v9[0]._Space._Pfn[1] = (void (__cdecl *)())this;
    v9[0]._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)v9;
    v11 = -1;
    Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)(v8 + 64), v9[0], this);
  }
}
// 5CF94E: variable 'v4' is possibly undefined
// 78E1CE: using guessed type int __cdecl operator new(_DWORD);
// 78E358: using guessed type int __cdecl __RTDynamicCast(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 8928CC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_be99df9070aa0c099bca5887c9856fd4_,0>,std::allocator<std::_Func_class<void,int const &>>,void,int const &>::`vftable';
// 8928EC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_62b6e2b8032ba7c6f0fdf3e52f500a08_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
// 89290C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_7eaf1073bac1e48eea38acd85c1f65ee_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
// 18472DC: using guessed type struct ReplayManager ReplayManager `RTTI Type Descriptor';
// 18600E0: using guessed type struct GameObject GameObject `RTTI Type Descriptor';

//----- (005CFA40) --------------------------------------------------------
void CarAvatar::onStartReplay(const bool *mode)
{
  SkidMarkBuffer **v3; // esi
  int v4; // ebx
  GameObject **v5; // esi
  int v6; // ecx
  ICarPhysicsStateProvider *v8; // ecx
  Car *v9; // ecx
  ICarControlsProvider *v10; // eax
  ICarControlsProvider *v11; // eax
  __int128 v12; // [esp+1Ch] [ebp-14h] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  CarAvatar::resetFlames(this);
  v3 = this->skidMarkBuffers;
  v4 = 4;
  do
  {
    if ( *v3 )
      SkidMarkBuffer::reset(*v3);
    ++v3;
    --v4;
  }
  while ( v4 );
  v5 = this->gameObjects._Myfirst;
  if ( v5 == this->gameObjects._Mylast )
  {
LABEL_8:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      v6 = __RTDynamicCast(*v5, 0, &GameObject `RTTI Type Descriptor', &ReplayRecorder `RTTI Type Descriptor', 0);
      if ( v6 )
        break;
      if ( ++v5 == this->gameObjects._Mylast )
        goto LABEL_8;
    }
  }
  if ( !this->nonReplayPhysicsStateProvider )
  {
    if ( v6 ? v6 + 52 : 0 )
      this->nonReplayPhysicsStateProvider = this->physicsStateProvider;
  }
  if ( v6 )
    v8 = (ICarPhysicsStateProvider *)(v6 + 52);
  else
    v8 = 0;
  this->physicsStateProvider = v8;
  v9 = this->physics;
  if ( v9 )
  {
    if ( Car::getControlsProvider(v9) )
    {
      v10 = Car::getControlsProvider(this->physics);
      v13 = 0;
      v12 = 0i64;
      v10->setVibrations(v10, (const VibrationDef *)&v12);
      v11 = Car::getControlsProvider(this->physics);
      ((void (*)(ICarControlsProvider *, _DWORD, _DWORD, _DWORD))v11->sendFF)(v11, 0, 0, 0);
    }
  }
}
// 78E358: using guessed type int __cdecl __RTDynamicCast(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 18472F8: using guessed type struct ReplayRecorder ReplayRecorder `RTTI Type Descriptor';
// 18600E0: using guessed type struct GameObject GameObject `RTTI Type Descriptor';

//----- (005CFB40) --------------------------------------------------------
void CarAvatar::onStopReplay(const bool *mode)
{
  GameObject **i; // esi
  ICarPhysicsStateProvider *v4; // eax
  std::wstring *v5; // eax
  std::wstring v6; // [esp+Ch] [ebp-28h] BYREF
  int v7; // [esp+30h] [ebp-4h]

  CarAvatar::resetFlames(this);
  for ( i = this->gameObjects._Myfirst; i != this->gameObjects._Mylast; ++i )
  {
    if ( __RTDynamicCast(*i, 0, &GameObject `RTTI Type Descriptor', &ReplayRecorder `RTTI Type Descriptor', 0) )
      break;
  }
  v4 = this->nonReplayPhysicsStateProvider;
  if ( v4 )
  {
    this->physicsStateProvider = v4;
  }
  else
  {
    v6._Myres = 7;
    v6._Mysize = 0;
    v6._Bx._Buf[0] = 0;
    std::wstring::assign(&v6, L"ERROR, nonReplayPhysicsStateProvider is null on CarAvatar::stopReplay", 0x45u);
    v5 = &v6;
    v7 = 0;
    if ( v6._Myres >= 8 )
      v5 = (std::wstring *)v6._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v5->_Bx._Buf);
    ksGenerateCrash();
    if ( v6._Myres >= 8 )
      operator delete(v6._Bx._Ptr);
  }
  this->nonReplayPhysicsStateProvider = 0;
}
// 78E1D4: using guessed type int __cdecl operator delete(_DWORD);
// 78E358: using guessed type int __cdecl __RTDynamicCast(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 18472F8: using guessed type struct ReplayRecorder ReplayRecorder `RTTI Type Descriptor';
// 18600E0: using guessed type struct GameObject GameObject `RTTI Type Descriptor';

//----- (005CFC50) --------------------------------------------------------
INIReader *CarAvatar::openINI(INIReader *result, const std::wstring *filename)
{
  std::wstring *v4; // esi
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring config_data_folder_file; // [esp+18h] [ebp-A0h] BYREF
  std::wstring v12; // [esp+30h] [ebp-88h] BYREF
  std::wstring v13; // [esp+48h] [ebp-70h] BYREF
  std::wstring v14; // [esp+60h] [ebp-58h] BYREF
  std::wstring v15; // [esp+78h] [ebp-40h] BYREF
  std::wstring v16; // [esp+90h] [ebp-28h] BYREF
  int v17; // [esp+B4h] [ebp-4h]

  if ( !this->configName._Mysize )
  {
LABEL_20:
    INIReader::INIReader(result, filename);
    return result;
  }
  v4 = Path::getFileName(&v16, filename);
  v17 = 0;
  v5 = std::operator+<wchar_t>(&v14, L"content/cars/", &this->unixName);
  LOBYTE(v17) = 1;
  v6 = std::operator+<wchar_t>(&v13, v5, L"/data_");
  LOBYTE(v17) = 2;
  v7 = std::operator+<wchar_t>(&v12, v6, &this->configName);
  LOBYTE(v17) = 3;
  v8 = std::operator+<wchar_t>(&v15, v7, L"/");
  LOBYTE(v17) = 4;
  std::operator+<wchar_t>(&config_data_folder_file, v8, v4);
  if ( v15._Myres >= 8 )
    operator delete(v15._Bx._Ptr);
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  if ( v12._Myres >= 8 )
    operator delete(v12._Bx._Ptr);
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  LOBYTE(v17) = 10;
  if ( v16._Myres >= 8 )
    operator delete(v16._Bx._Ptr);
  v16._Myres = 7;
  v16._Bx._Buf[0] = 0;
  v16._Mysize = 0;
  if ( !Path::fileExists((unsigned int)this, &config_data_folder_file, 0) )
  {
    v17 = -1;
    if ( config_data_folder_file._Myres >= 8 )
      operator delete(config_data_folder_file._Bx._Ptr);
    config_data_folder_file._Myres = 7;
    config_data_folder_file._Mysize = 0;
    config_data_folder_file._Bx._Buf[0] = 0;
    goto LABEL_20;
  }
  v9 = &config_data_folder_file;
  if ( config_data_folder_file._Myres >= 8 )
    v9 = (std::wstring *)config_data_folder_file._Bx._Ptr;
  _printf("USING CONFIG DATA FOLDER FOR INI FILE: %S\n", v9->_Bx._Buf);
  INIReader::INIReader(result, &config_data_folder_file);
  if ( config_data_folder_file._Myres >= 8 )
    operator delete(config_data_folder_file._Bx._Ptr);
  return result;
}
// 78E1D4: using guessed type int __cdecl operator delete(_DWORD);

//----- (005CFFC0) --------------------------------------------------------
void CarAvatar::resetFlames()
{
  GameObject **v2; // esi
  Flames *v3; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 != this->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v3 = (Flames *)__RTDynamicCast(*v2, 0, &GameObject `RTTI Type Descriptor', &Flames `RTTI Type Descriptor', 0);
      if ( v3 )
        break;
      if ( ++v2 == this->gameObjects._Mylast )
        return;
    }
    Flames::reset(v3);
  }
}
// 78E358: using guessed type int __cdecl __RTDynamicCast(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 1847330: using guessed type struct Flames Flames `RTTI Type Descriptor';
// 18600E0: using guessed type struct GameObject GameObject `RTTI Type Descriptor';

//----- (005D0000) --------------------------------------------------------
void CarAvatar::resetMultVolume()
{
  this->carAudioFMOD->mixVolumes.tyresMult = 1.0;
  this->carAudioFMOD->mixVolumes.engineMult = 1.0;
}

//----- (005D0030) --------------------------------------------------------
void CarAvatar::resetPenalty(bool isTotalReset)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v4) = isTotalReset;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_056f802c574fdbb7f83b7b9158a49803_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(v4, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892B0C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_056f802c574fdbb7f83b7b9158a49803_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D00B0) --------------------------------------------------------
void CarAvatar::resetTimeTransponder()
{
  Sim *v1; // ecx
  std::function<void __cdecl(void)> v2; // [esp-18h] [ebp-30h] BYREF
  int v3; // [esp+14h] [ebp-4h]

  if ( this->physics )
  {
    v2._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_33c5f6518538af62fe8724a8493e6b8e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    v2._Space._Pfn[1] = (void (__cdecl *)())this;
    v2._Impl = (std::_Func_base<void> *)&v2;
    v1 = this->sim;
    v3 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v1->physicsAvatar, v2);
  }
}
// 892AAC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_33c5f6518538af62fe8724a8493e6b8e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0120) --------------------------------------------------------
void CarAvatar::setAbsEnabled(bool mode, bool force)
{
  Sim *v3; // ecx
  std::function<void __cdecl(void)> v4; // [esp-18h] [ebp-34h] BYREF
  unsigned int v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v5) = mode;
    BYTE1(v5) = force;
    v4._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_4901d67fd949aea2695f20fd3ff4f918_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v4._Space._Alias[4] = __PAIR64__(v5, (unsigned int)this);
    v4._Impl = (std::_Func_base<void> *)&v4;
    v3 = this->sim;
    v6 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v3->physicsAvatar, v4);
  }
}
// 89294C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_4901d67fd949aea2695f20fd3ff4f918_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D01B0) --------------------------------------------------------
void CarAvatar::setAutoBlip(bool mode)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v4) = mode;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_9178bbef4882a0348f3bb36b5f6a03f4_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(v4, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 8929CC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_9178bbef4882a0348f3bb36b5f6a03f4_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0230) --------------------------------------------------------
void CarAvatar::setAutoClutchEnabled(bool mode)
{
  Car *v3; // ecx
  ICarControlsProvider *v4; // eax

  v3 = this->physics;
  if ( v3 )
  {
    v4 = Car::getControlsProvider(v3);
    if ( !mode && v4 && v4->isAutoclutchNeeded )
    {
      _printf("Selected controlProvider requires autoclutch, request to turn off ignored\n");
    }
    else
    {
      this->physics->autoClutch.useAutoOnStart = mode;
      if ( mode )
        this->physics->autoClutch.useAutoOnChange = mode;
    }
  }
}

//----- (005D0290) --------------------------------------------------------
void CarAvatar::setAutoShifter(bool mode)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v4) = mode;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_b6dea921543dec5aeabe68da18dd931c_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(v4, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892A0C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_b6dea921543dec5aeabe68da18dd931c_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0310) --------------------------------------------------------
void CarAvatar::setBallastKG(float ballast)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  float v4; // [esp+8h] [ebp-14h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    v4 = ballast;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_3f31443afbdaf5b80a4187021ab89a3b_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__((unsigned int)this, LODWORD(ballast));
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892BEC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_3f31443afbdaf5b80a4187021ab89a3b_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0390) --------------------------------------------------------
void CarAvatar::setBlackFlag(PenaltyDescription descr)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-2Ch] BYREF
  int v4; // [esp+10h] [ebp-4h]

  if ( this->physics )
  {
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_8da18ebd38ce3b17e93a086d8b386755_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(descr, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v4 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892B8C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_8da18ebd38ce3b17e93a086d8b386755_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0400) --------------------------------------------------------
void CarAvatar::setControlsLock(bool value)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v4) = value;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_87512cd7822b1b0942f6a06efe0f503e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(v4, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892A2C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_87512cd7822b1b0942f6a06efe0f503e_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0480) --------------------------------------------------------
void CarAvatar::setControlsProvider(ICarControlsProvider *controls)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-2Ch] BYREF
  int v4; // [esp+10h] [ebp-4h]

  if ( this->physics )
  {
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_b6b080bf082dbf8c438fa78df5fb4ceb_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__((unsigned int)controls, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v4 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 8928AC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_b6b080bf082dbf8c438fa78df5fb4ceb_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D04F0) --------------------------------------------------------
void CarAvatar::setDamageLevel(float lvl)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  float v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    v4 = lvl;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_9d2a8902c54476f1d9eaae39e5d5e3dc_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(LODWORD(lvl), (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892A6C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_9d2a8902c54476f1d9eaae39e5d5e3dc_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0570) --------------------------------------------------------
void CarAvatar::setDriverInfo(const DriverInfo *info)
{
  DriverInfo *v3; // edi
  Sim *v4; // ecx
  std::function<void __cdecl(void)> v5; // [esp-18h] [ebp-A0h] BYREF
  std::function<void __cdecl(void)> *v6; // [esp+10h] [ebp-78h]
  CarAvatar::setDriverInfo::__l6::<lambda_3561ae953e098720cd88ad11dd6e6bb6> _Val; // [esp+14h] [ebp-74h] BYREF
  int v8; // [esp+84h] [ebp-4h]

  v3 = &this->driverInfo;
  if ( &this->driverInfo != info )
    std::wstring::assign(&this->driverInfo.name, &info->name, 0, 0xFFFFFFFF);
  if ( &v3->team != &info->team )
    std::wstring::assign(&v3->team, &info->team, 0, 0xFFFFFFFF);
  if ( &v3->nationality != &info->nationality )
    std::wstring::assign(&v3->nationality, &info->nationality, 0, 0xFFFFFFFF);
  if ( &v3->nationCode != &info->nationCode )
    std::wstring::assign(&v3->nationCode, &info->nationCode, 0, 0xFFFFFFFF);
  if ( this->physics )
  {
    _Val.__this = this;
    DriverInfo::DriverInfo((DriverInfo *)&_Val.info, info);
    v8 = 1;
    v6 = &v5;
    v5._Impl = 0;
    std::_Func_class<void,>::_Reset<_lambda_3561ae953e098720cd88ad11dd6e6bb6_>(&v5, &_Val);
    v4 = this->sim;
    LOBYTE(v8) = 0;
    PhysicsAvatar::executeOnPhysicsThread(v4->physicsAvatar, v5);
    SetupItemText::~SetupItemText((DriverInfo *)&_Val.info);
  }
}

//----- (005D0690) --------------------------------------------------------
void CarAvatar::setFFMult(float mult)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  float v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    v4 = mult;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_c661273354399506f15d61a79db73e0f_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(LODWORD(mult), (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892B2C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_c661273354399506f15d61a79db73e0f_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0710) --------------------------------------------------------
void CarAvatar::setGentleStop(bool mode)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v4) = mode;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_b76d4e82898b94b9125c3d59067df2bc_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(v4, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892A4C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_b76d4e82898b94b9125c3d59067df2bc_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0790) --------------------------------------------------------
void CarAvatar::setGraphicsOffset(vec3f np)
{
  float v2; // eax

  v2 = np.z;
  *(_QWORD *)&this->graphicsOffset.x = *(_QWORD *)&np.x;
  this->graphicsOffset.z = v2;
}

//----- (005D07B0) --------------------------------------------------------
void CarAvatar::setGraphicsPitchRotation(float v)
{
  this->graphicsPitchRotation = v;
}

//----- (005D07D0) --------------------------------------------------------
void CarAvatar::setHeadlights(bool value)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v4) = value;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_172641183db25f7a95167a564fb472cc_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(v4, (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892C8C: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_172641183db25f7a95167a564fb472cc_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0850) --------------------------------------------------------
void CarAvatar::setMultVolume(int value, bool active)
{
  CarAudioFMOD *v3; // eax

  v3 = this->carAudioFMOD;
  if ( value == 1 )
  {
    if ( active )
      v3->mixVolumes.tyresMult = 1.5;
    else
      v3->mixVolumes.tyresMult = 1.0;
  }
  else if ( active )
  {
    v3->mixVolumes.engineMult = 1.5;
  }
  else
  {
    v3->mixVolumes.engineMult = 1.0;
  }
}

//----- (005D08A0) --------------------------------------------------------
void CarAvatar::setNewPhysicsState(CarPhysicsState *ps, float dt)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  float v6; // xmm4_4

  if ( this->guid )
  {
    v3 = dt * 10.0;
    v4 = FLOAT_1_0;
    if ( (float)(dt * 10.0) <= 1.0 )
    {
      if ( v3 >= 0.0 )
        v5 = dt * 10.0;
      else
        v5 = 0.0;
    }
    else
    {
      v5 = FLOAT_1_0;
    }
    ps->steer = (float)((float)(ps->steer - this->physicsState.steer) * v5) + this->physicsState.steer;
    if ( v3 <= 1.0 )
    {
      if ( v3 >= 0.0 )
        v6 = dt * 10.0;
      else
        v6 = 0.0;
    }
    else
    {
      v6 = FLOAT_1_0;
    }
    ps->gas = (float)((float)(ps->gas - this->physicsState.gas) * v6) + this->physicsState.gas;
    if ( v3 <= 1.0 )
    {
      if ( v3 >= 0.0 )
        v4 = dt * 10.0;
      else
        v4 = 0.0;
    }
    ps->brake = (float)((float)(ps->brake - this->physicsState.brake) * v4) + this->physicsState.brake;
  }
  qmemcpy(&this->physicsState, ps, sizeof(this->physicsState));
}

//----- (005D0990) --------------------------------------------------------
void CarAvatar::setP2PActivations(int activations)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-2Ch] BYREF
  int v4; // [esp+10h] [ebp-4h]

  if ( this->physics )
  {
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_bd429c1645364981527be4f3a5f25577_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__((unsigned int)this, activations);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v4 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892CCC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_bd429c1645364981527be4f3a5f25577_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0A00) --------------------------------------------------------
void CarAvatar::setP2PStartingActivations(int pos)
{
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-28h] BYREF
  CarAvatar::setP2PStartingActivations::__l6::<lambda_1083ce7b5f8a49dc0b490fdb5c9697c2> _Func; // [esp+4h] [ebp-Ch] BYREF

  if ( this->physics )
  {
    _Func.pos = pos;
    _Func.carGuid = this->guid;
    _Func.__this = this;
    std::function<void __cdecl (void)>::function<void __cdecl (void)>(&v3, &_Func);
    PhysicsAvatar::executeOnPhysicsThread(this->sim->physicsAvatar, v3);
  }
}

//----- (005D0A50) --------------------------------------------------------
void CarAvatar::setRestrictor(float v)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  float v4; // [esp+8h] [ebp-14h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    v4 = v;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_f728251f2d5ca677207215f6bc43a2e5_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__((unsigned int)this, LODWORD(v));
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}
// 892CAC: using guessed type void *std::_Func_impl<std::_Callable_obj<_lambda_f728251f2d5ca677207215f6bc43a2e5_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';

//----- (005D0AD0) --------------------------------------------------------
void CarAvatar::setSlipStreamEffects(float receive, float generationSpeedFactor)
{
  Car *v3; // ecx

  v3 = this->physics;
  if ( v3 )
    Car::setSlipStreamEffects(v3, receive, generationSpeedFactor);
}

//----- (005D0B00) --------------------------------------------------------
void CarAvatar::setSpawnPositionIndex(const std::wstring *setName, int index)
{
  Sim *v4; // ecx
  const __m128i *v5; // eax
  bool v6; // cf
  __m128i v7; // xmm0
  Car *v8; // eax
  mat44f result; // [esp+10h] [ebp-68h] BYREF
  std::wstring v10; // [esp+50h] [ebp-28h] BYREF
  int v11; // [esp+74h] [ebp-4h]

  if ( !std::wstring::compare((std::wstring *)setName, 0, setName->_Mysize, L"PIT", 3u) && this->physics )
  {
    std::wstring::wstring(&v10, L"PIT");
    v4 = this->sim;
    v11 = 0;
    v5 = (const __m128i *)TrackAvatar::getSpawnPosition(v4->track, &result, &v10, index);
    v6 = v10._Myres < 8;
    v11 = -1;
    *(__m128i *)&this->pitPosition.M11 = _mm_loadu_si128(v5);
    *(__m128i *)&this->pitPosition.M21 = _mm_loadu_si128(v5 + 1);
    *(__m128i *)&this->pitPosition.M31 = _mm_loadu_si128(v5 + 2);
    *(__m128i *)&this->pitPosition.M41 = _mm_loadu_si128(v5 + 3);
    if ( !v6 )
      operator delete(v10._Bx._Ptr);
    v7 = _mm_loadu_si128((const __m128i *)&this->pitPosition);
    v10._Myres = 7;
    v10._Bx._Buf[0] = 0;
    v8 = this->physics;
    v10._Mysize = 0;
    *(__m128i *)&v8->pitPosition.M11 = v7;
    *(__m128i *)&v8->pitPosition.M21 = _mm_loadu_si128((const __m128i *)&this->pitPosition.M21);
    *(__m128i *)&v8->pitPosition.M31 = _mm_loadu_si128((const __m128i *)&this->pitPosition.M31);
    *(__m128i *)&v8->pitPosition.M41 = _mm_loadu_si128((const __m128i *)&this->pitPosition.M41);
  }
  CarRaceInfo::setSpawnPositionIndex(&this->raceInfo, setName, index);
}
// 78E1D4: using guessed type int __cdecl operator delete(_DWORD);

//----- (005D0C70) --------------------------------------------------------
void CarAvatar::setStabilityControl(float gain)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  float v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    v4 = gain;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_e86ea91c3a840f1879fb69a62ded7d96_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(LODWORD(gain), (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}

void CarAvatar::setTcEnabled(bool mode, bool force)
{
  Sim *v3; // ecx
  std::function<void __cdecl(void)> v4; // [esp-18h] [ebp-34h] BYREF
  unsigned int v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    LOBYTE(v5) = mode;
    BYTE1(v5) = force;
    v4._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_fb2aaab739b92ef2e2add669e2952c3a_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v4._Space._Alias[4] = __PAIR64__(v5, (unsigned int)this);
    v4._Impl = (std::_Func_base<void> *)&v4;
    v3 = this->sim;
    v6 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v3->physicsAvatar, v4);
  }
}

void CarAvatar::setTurboBoost(float value)
{
  Car *v3; // ecx
  std::wostream *v4; // eax
  std::wostream *v5; // eax
  const std::wstring *v6; // eax
  const char *v7; // [esp+8h] [ebp-108h]
  float v8; // [esp+14h] [ebp-FCh]
  float v9; // [esp+14h] [ebp-FCh]
  float v10; // [esp+18h] [ebp-F8h]
  int v11; // [esp+1Ch] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v12; // [esp+20h] [ebp-F0h] BYREF
  std::wstring description; // [esp+D0h] [ebp-40h] BYREF
  std::wstring result; // [esp+E8h] [ebp-28h] BYREF
  int v15; // [esp+108h] [ebp-8h]
  int v16; // [esp+10Ch] [ebp-4h]
  void *retaddr; // [esp+110h] [ebp+0h]

  v11 = 0;
  v3 = this->physics;
  v10 = value;
  if ( v3->drivetrain.acEngine.turboAdjustableFromCockpit )
  {
    Engine::setTurboBoostLevel(&v3->drivetrain.acEngine, value);
    *(_DWORD *)v12.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v12.gap68);
    retaddr = 0;
    *(_DWORD *)v12.gap0 = 1;
    std::wiostream::basic_iostream<wchar_t>(&v12.gap0[4], &v12.gap10[12], 0);
    v15 = 1;
    *(int *)((char *)&v11 + *(_DWORD *)(v11 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v10 + *(_DWORD *)(v11 + 4)) = *(_DWORD *)(v11 + 4) - 104;
    std::wstreambuf::wstreambuf(&v12.gap10[4]);
    *(_DWORD *)&v12.gap10[4] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v12.gap10[60] = 0;
    *(_DWORD *)&v12.gap10[64] = 0;
    v15 = 3;
    v9 = _roundf(v8 * 10.0);
    v4 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)((char *)&v12._Chcount + 4), "Turbo: ");
    v5 = (std::wostream *)std::wostream::operator<<(v4, (int)(float)(v9 * 10.0));
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v5, v7);
    description._Myres = 7;
    description._Mysize = 0;
    description._Bx._Buf[0] = 0;
    std::wstring::assign(&description, word_17BE9D8, 0);
    LOBYTE(v16) = 4;
    v6 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v12, &result);
    LOBYTE(v16) = 5;
    SystemMessage::addMessage(this->sim->systemMessage, v6, &description, eTurbo);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( description._Myres >= 8 )
      operator delete(description._Bx._Ptr);
    description._Myres = 7;
    description._Bx._Buf[0] = 0;
    description._Mysize = 0;
    v16 = -1;
    *(_DWORD *)&v12.gap0[*(_DWORD *)(*(_DWORD *)v12.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v11 + *(_DWORD *)(*(_DWORD *)v12.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v12.gap0 + 4) - 104;
    *(_DWORD *)&v12.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v12.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v12.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v12.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v12.gap68);
  }
}

void CarAvatar::setTyreCompound(unsigned int index, const std::wstring *name)
{
  CarAvatar *v3; // ebp
  std::wstring *v4; // esi
  std::wstring *v5; // edi
  const std::wstring *v6; // eax
  int v7; // eax
  std::function<void __cdecl(void)> v8; // [esp-18h] [ebp-4Ch]
  int i; // [esp+14h] [ebp-20h]

  v3 = this;
  if ( this->physics )
  {
    v4 = this->physicsInfo.tyreCompounds._Myfirst;
    v5 = this->physicsInfo.tyreCompounds._Mylast;
    for ( i = 0; v4 != v5; ++v4 )
    {
      if ( name->_Myres < 8 )
        v6 = name;
      else
        v6 = (const std::wstring *)name->_Bx._Ptr;
      if ( !std::wstring::compare(v4, 0, v4->_Mysize, v6->_Bx._Buf, name->_Mysize) )
      {
        v7 = operator new(20);
        if ( !v7 )
        {
          std::_Xbad_alloc();
          JUMPOUT(0x5D1165);
        }
        *(_DWORD *)v7 = &std::_Func_impl<std::_Callable_obj<_lambda_13d47212e0a565f7432eed5d6e032636_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
        *(_QWORD *)(v7 + 4) = __PAIR64__(index, (unsigned int)v3);
        *(_DWORD *)(v7 + 12) = i;
        v8._Impl = (std::_Func_base<void> *)v7;
        v3 = this;
        PhysicsAvatar::executeOnPhysicsThread(this->sim->physicsAvatar, v8);
      }
      ++i;
    }
  }
}

void CarAvatar::setUserFFGain(float gain)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  float v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  if ( this->physics )
  {
    this->userFFGain = gain;
    v4 = gain;
    v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_ab41e3cd4750575bedb0a39208fbd35a_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(LODWORD(gain), (unsigned int)this);
    v3._Impl = (std::_Func_base<void> *)&v3;
    v2 = this->sim;
    v5 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v2->physicsAvatar, v3);
  }
}

void CarAvatar::setVisible(bool vis)
{
  int v3; // esi
  Node *v4; // eax

  v3 = 0;
  this->bodyTransform->isActive = vis;
  do
  {
    this->suspensionAvatar->getWheelTransform(this->suspensionAvatar, v3)->isActive = vis;
    v4 = this->suspensionAvatar->getSusTransform(this->suspensionAvatar, v3++);
    v4->isActive = vis;
  }
  while ( v3 < 4 );
}

void CarAvatar::update(int a2@<edi>, int a3@<esi>, float deltaT)
{
  BackfireParams *v5; // ecx
  IEventTrigger **i; // esi
  Node *v7; // eax
  Node *v8; // eax
  Node *v9; // eax
  Car *v10; // eax
  float v11; // xmm0_4
  Node *v12; // esi
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __int128 v17; // xmm2
  __int128 v18; // xmm1
  __int128 v19; // xmm3
  DriverModel *v20; // ecx
  DriverModel *v21; // eax
  DriverModel *v22; // esi
  Sim *v23; // ecx
  _DWORD *v24; // eax
  Node *v25; // ecx
  char v26; // al
  Node *v27; // ecx
  bool v28; // al
  bool v29; // al
  Car *v30; // ecx
  float v31; // xmm0_4
  char message; // [esp+1Bh] [ebp-8Dh] BYREF
  unsigned int message_1; // [esp+1Ch] [ebp-8Ch]
  float message_5; // [esp+20h] [ebp-88h]
  unsigned int v37; // [esp+24h] [ebp-84h]
  __m128 v38; // [esp+28h] [ebp-80h] BYREF
  __int128 v39; // [esp+38h] [ebp-70h]
  __int128 v40; // [esp+48h] [ebp-60h]
  __int128 v41; // [esp+58h] [ebp-50h]
  DirectX::XMMATRIX M2_4; // [esp+68h] [ebp-40h] BYREF

  CarAvatar::updateInPitlaneState(this, deltaT);
  v5 = this->backfireParams;
  if ( v5 && this->physicsState.engineLifeLeft > 0.0 && BackfireParams::checkBackfire(v5, deltaT) )
  {
    message = 0;
    Event<std::wstring>::trigger(
      (Event<OnGearRequestEvent> *)&this->evOnBackfireTriggered,
      (const OnGearRequestEvent *)&message);
  }
  if ( !this->nonReplayPhysicsStateProvider )
    CarAvatar::updateFromChannels(this, deltaT);
  CarAvatar::makeBodyMatrix(this, (int)this, a3, &this->physicsState.worldMatrix, &this->bodyMatrix);
  for ( i = this->eventTriggers._Myfirst; i != this->eventTriggers._Mylast; ++i )
    ((void (*)(IEventTrigger *, _DWORD))(*i)->update)(*i, LODWORD(deltaT));
  v7 = this->bodyTransform;
  *(__m128i *)&v7->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->bodyMatrix);
  *(__m128i *)&v7->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->bodyMatrix.M21);
  *(__m128i *)&v7->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->bodyMatrix.M31);
  *(__m128i *)&v7->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->bodyMatrix.M41);
  if ( this->steerTransformHR )
  {
    if ( this->lockVirtualSteer && ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this) )
    {
      v8 = this->steerTransformHR;
      *(__m128i *)&v8->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix);
      *(__m128i *)&v8->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix.M21);
      *(__m128i *)&v8->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix.M31);
      *(__m128i *)&v8->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix.M41);
    }
    else
    {
      v9 = this->steerTransformHR;
      *(__m128i *)&v9->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix);
      *(__m128i *)&v9->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix.M21);
      *(__m128i *)&v9->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix.M31);
      *(__m128i *)&v9->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->orgSteerMatrix.M41);
      v10 = this->physics;
      v11 = this->physicsState.steer;
      if ( v10 )
        v11 = (float)(v11 / v10->steerLock) * this->graphicSteerLockDegrees;
      message_5 = v11 * 0.017453;
      message_1 = __libm_sse2_cosf(a2, a3).m128_u32[0];
      v37 = __libm_sse2_sinf().m128_u32[0];
      message_5 = 1.0 - *(float *)&message_1;
      mat44f::mat44f((mat44f *)&v38);
      v12 = this->steerTransformHR;
      HIDWORD(v41) = 1065353216;
      v13 = *(__m128 *)&this->orgSteerMatrix.M31;
      *((float *)&v40 + 2) = message_5 + *(float *)&message_1;
      M2_4.r[2] = v13;
      *((float *)&v39 + 1) = (float)(message_5 * 0.0) + *(float *)&message_1;
      v38.m128_f32[0] = *((float *)&v39 + 1);
      v38.m128_f32[1] = *(float *)&v37 + (float)(message_5 * 0.0);
      *(float *)&v39 = (float)(message_5 * 0.0) - *(float *)&v37;
      v38.m128_f32[2] = (float)(message_5 * 0.0) - (float)(*(float *)&v37 * 0.0);
      *(float *)&v40 = (float)(*(float *)&v37 * 0.0) + (float)(message_5 * 0.0);
      v14 = *(__m128 *)&this->orgSteerMatrix.M21;
      *((float *)&v39 + 2) = *(float *)&v40;
      v15 = *(__m128 *)&this->orgSteerMatrix.M11;
      *((float *)&v40 + 1) = v38.m128_f32[2];
      v16 = *(__m128 *)&this->orgSteerMatrix.M41;
      v17 = v40;
      M2_4.r[0] = v15;
      M2_4.r[1] = v14;
      v18 = v39;
      M2_4.r[3] = v16;
      v19 = v41;
      *(__m128 *)&v12->matrix.M11 = DirectX::XMMatrixMultiply(M2_4.r, v38);
      *(_OWORD *)&v12->matrix.M21 = v18;
      *(_OWORD *)&v12->matrix.M31 = v17;
      *(_OWORD *)&v12->matrix.M41 = v19;
    }
  }
  if ( this->lockVirtualSteer )
  {
    if ( this->driverModel_HR )
    {
      this->driverModel_HR->lockAnimation = ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this);
      if ( ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this) )
        DriverModel::setLockedPosition(this->driverModel_HR);
    }
    if ( this->lockVirtualSteer )
    {
      if ( this->driverModel_LR )
      {
        this->driverModel_LR->lockAnimation = ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this);
        if ( ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this) )
          DriverModel::setLockedPosition(this->driverModel_LR);
      }
    }
  }
  v20 = this->driverModel_HR;
  if ( v20 )
    v20->driver_root->isActive = this->isDriverHR;
  v21 = this->driverModel_LR;
  if ( v21 )
    v21->driver_root->isActive = !this->isDriverHR;
  if ( this->isDriverHR )
    v22 = this->driverModel_HR;
  else
    v22 = this->driverModel_LR;
  if ( this->guid || this->sim->cameraManager->mode != eStart )
  {
    CarAnimations::setDoorOpen(this->carAnimations, 0);
    v23 = this->sim;
    v24 = &v23->cameraManager->__vftable;
    LOBYTE(v24) = v24[42] == 2
               && (v24 = (_DWORD *)v24[26], v24[13] == 4)
               && (v24 = (_DWORD *)Sim::getFocusedCarIndex(v23), v24 == (_DWORD *)this->guid);
    if ( v22 )
    {
      LOBYTE(v24) = (_BYTE)v24 == 0;
      message_1 = (unsigned int)v24;
      DriverModel::setVisible(v22, (bool)v24);
      v25 = this->steerTransformHR;
      v26 = message_1;
      if ( v25 )
        v25->isActive = message_1;
      v27 = this->steerTransformLR;
      if ( v27 )
        v27->isActive = v26;
      if ( this->hideArmsInCockpit )
      {
        v28 = ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this);
        DriverModel::setVisible(v22, !v28);
      }
      if ( this->hideSteer )
      {
        v29 = ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this);
        DriverModel::setVisible(v22, !v29);
        if ( this->steerTransformHR )
          this->steerTransformHR->isActive = !ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this);
        if ( this->steerTransformLR )
          this->steerTransformLR->isActive = !ACCameraManager::isCameraOnBoard(this->sim->cameraManager, this);
      }
    }
  }
  else
  {
    DriverModel::setVisible(v22, 0);
    CarAnimations::setDoorOpen(this->carAnimations, 1);
  }
  v30 = this->physics;
  if ( v30 )
  {
    Car::getAIState(v30, &this->aiState);
    if ( !this->guid )
      CarAvatar::updateERSCharge(this);
  }
  CarAvatar::updateSkidMarks(this, deltaT);
  v31 = deltaT * 0.2;
  if ( (float)(deltaT * 0.2) <= 1.0 )
  {
    if ( v31 < 0.0 )
      v31 = 0.0;
  }
  else
  {
    v31 = FLOAT_1_0;
  }
  this->filteredSpeed = (float)((float)(this->physicsState.speed.value - this->filteredSpeed) * v31)
                      + this->filteredSpeed;
}