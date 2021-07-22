#include "dynamicwingcontroller.h
void DynamicWingController::~DynamicWingController(DynamicWingController *this)
{
  Curve::~Curve(&this->lut);
}
void DynamicWingController::DynamicWingController(DynamicWingController *this, Car *car, INIReader *ini, const std::wstring *section)
{
  Curve::Curve(&this->lut);
  this->car = car;
  this->state = 0;
  DynamicWingController::initCommon(this, &car->unixName, ini, section);
}
void DynamicWingController::DynamicWingController(DynamicWingController *this, const CarPhysicsState *state, const std::wstring *carUnixName, INIReader *ini, const std::wstring *section)
{
  Curve::Curve(&this->lut);
  this->state = state;
  this->car = 0;
  DynamicWingController::initCommon(this, carUnixName, ini, section);
}
double DynamicWingController::getInput(DynamicWingController *this)
{
  Car *v2; // edx
  double v3; // st7
  const CarPhysicsState *v4; // ecx
  Speed result; // [esp+0h] [ebp-8h] BYREF
  float v6; // [esp+4h] [ebp-4h]

  v2 = this->car;
  if ( v2 )
  {
    switch ( this->inputVar )
    {
      case eBrake:
        v3 = v2->controls.brake;
        break;
      case eGas:
        v3 = v2->controls.gas;
        break;
      case eLatG:
        v3 = v2->accG.x;
        break;
      case eLonG:
        v3 = v2->accG.z;
        break;
      case eSteer:
        v3 = v2->controls.steer;
        break;
      case eSpeed:
        v6 = Car::getSpeed(this->car, &result)->value * 3.5999999;
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
        v3 = v6;
        break;
      case SusTravelLR:
        v3 = *(float *)(*(int (**)(_DWORD))(**((_DWORD **)v2->suspensions._Myfirst + 2) + 36))(*((_DWORD *)v2->suspensions._Myfirst + 2))
           * 1000.0;
        break;
      case SusTravelRR:
        v3 = *(float *)(*(int (**)(_DWORD))(**((_DWORD **)v2->suspensions._Myfirst + 3) + 36))(*((_DWORD *)v2->suspensions._Myfirst + 3))
           * 1000.0;
        break;
      default:
        goto LABEL_21;
    }
  }
  else
  {
    v4 = this->state;
    if ( v4 )
    {
      switch ( this->inputVar )
      {
        case eBrake:
          v3 = v4->brake;
          break;
        case eGas:
          v3 = v4->gas;
          break;
        case eLatG:
          v3 = v4->accG.x;
          break;
        case eLonG:
          v3 = v4->accG.z;
          break;
        case eSteer:
          v3 = v4->steer;
          break;
        case eSpeed:
          v3 = v4->speed.value * 3.5999999;
          break;
        case SusTravelLR:
          v3 = v4->suspensionTravel[2] * 1000.0;
          break;
        case SusTravelRR:
          v3 = v4->suspensionTravel[3] * 1000.0;
          break;
        default:
          goto LABEL_21;
      }
    }
    else
    {
LABEL_21:
      v3 = 0.0;
    }
  }
  return v3;
}
void DynamicWingController::initCommon(DynamicWingController *this, const std::wstring *carUnixName, INIReader *ini, const std::wstring *section)
{
  const std::wstring *v5; // ecx
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // ebp
  const std::wstring *v9; // ecx
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  const std::wstring *v13; // eax
  double v14; // st7
  bool v15; // cf
  double v16; // st7
  double v17; // st7
  unsigned int v18; // [esp-Ch] [ebp-E0h]
  unsigned int v19; // [esp-Ch] [ebp-E0h]
  float v20; // [esp+14h] [ebp-C0h]
  std::wstring key; // [esp+1Ch] [ebp-B8h] BYREF
  std::wstring inp; // [esp+34h] [ebp-A0h] BYREF
  std::wstring _Left; // [esp+4Ch] [ebp-88h] BYREF
  std::wstring result; // [esp+64h] [ebp-70h] BYREF
  std::wstring data_path; // [esp+7Ch] [ebp-58h] BYREF
  std::wstring v26; // [esp+94h] [ebp-40h] BYREF
  std::wstring v27; // [esp+ACh] [ebp-28h] BYREF
  int v28; // [esp+D0h] [ebp-4h]

  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"INPUT", 5u);
  v28 = 0;
  INIReader::getString(ini, &inp, section, &key);
  LOBYTE(v28) = 2;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v18 = inp._Mysize;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  this->inputVar = eUndefined;
  if ( !std::wstring::compare(&inp, 0, v18, L"BRAKE", 5u) )
    this->inputVar = eBrake;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"GAS", 3u) )
    this->inputVar = eGas;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"STEER", 5u) )
    this->inputVar = eSteer;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"LATG", 4u) )
    this->inputVar = eLatG;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"LONG", 4u) )
    this->inputVar = eLonG;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"SPEED_KMH", 9u) )
    this->inputVar = eSpeed;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"SUS_TRAVEL_LR", 0xDu) )
    this->inputVar = SusTravelLR;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"SUS_TRAVEL_RR", 0xDu) )
    this->inputVar = SusTravelRR;
  if ( this->inputVar == eUndefined )
  {
    if ( section->_Myres < 8 )
      v5 = section;
    else
      v5 = (const std::wstring *)section->_Bx._Ptr;
    v6 = &inp;
    if ( inp._Myres >= 8 )
      v6 = (std::wstring *)inp._Bx._Ptr;
    _printf("ERROR: INPUT UNDEFINED (%S) FOR DYNAMIC WING CONTROLLER STAGE %S\n", v6->_Bx._Buf, v5->_Bx._Buf);
    if ( INIReader::crashAtError )
    {
      std::wstring::wstring(&_Left, L"Undefined controller requested");
      v7 = &_Left;
      LOBYTE(v28) = 3;
      if ( _Left._Myres >= 8 )
        v7 = (std::wstring *)_Left._Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v7->_Bx._Buf);
      ksGenerateCrash();
      LOBYTE(v28) = 2;
      if ( _Left._Myres >= 8 )
        operator delete(_Left._Bx._Ptr);
    }
  }
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"COMBINATOR", 0xAu);
  LOBYTE(v28) = 4;
  v8 = INIReader::getString(ini, &result, section, &_Left);
  if ( &inp != v8 )
  {
    if ( inp._Myres >= 8 )
      operator delete(inp._Bx._Ptr);
    inp._Myres = 7;
    inp._Mysize = 0;
    inp._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&inp, v8);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v28) = 2;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v19 = inp._Mysize;
  this->combinatorMode = eUndefinedMode;
  if ( !std::wstring::compare(&inp, 0, v19, L"ADD", 3u) )
    this->combinatorMode = eAdd;
  if ( !std::wstring::compare(&inp, 0, inp._Mysize, L"MULT", 4u) )
    this->combinatorMode = eMult;
  if ( this->combinatorMode == eUndefinedMode )
  {
    if ( section->_Myres < 8 )
      v9 = section;
    else
      v9 = (const std::wstring *)section->_Bx._Ptr;
    v10 = &inp;
    if ( inp._Myres >= 8 )
      v10 = (std::wstring *)inp._Bx._Ptr;
    _printf("ERROR: COMBINATOR MODE UNDEFINED (%S) FOR DYNAMIC WING CONTROLLER STAGE %S\n", v10->_Bx._Buf, v9->_Bx._Buf);
  }
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  LOBYTE(v28) = 5;
  v11 = std::operator+<wchar_t>(&result, &_Left, carUnixName);
  LOBYTE(v28) = 6;
  std::operator+<wchar_t>(&data_path, v11, L"/data/");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v28) = 9;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"LUT", 3u);
  LOBYTE(v28) = 10;
  v12 = INIReader::getString(ini, &v27, section, &key);
  LOBYTE(v28) = 11;
  v13 = std::operator+<wchar_t>(&v26, &data_path, v12);
  LOBYTE(v28) = 12;
  Curve::load(&this->lut, v13);
  if ( v26._Myres >= 8 )
    operator delete(v26._Bx._Ptr);
  v26._Myres = 7;
  v26._Mysize = 0;
  v26._Bx._Buf[0] = 0;
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  LOBYTE(v28) = 9;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"FILTER", 6u);
  LOBYTE(v28) = 13;
  v14 = INIReader::getFloat(ini, section, &key);
  v15 = key._Myres < 8;
  v20 = v14;
  LOBYTE(v28) = 9;
  this->filter = (float)((float)(1.0 - v20) * 1.3333334) * 333.33334;
  if ( !v15 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"UP_LIMIT", 8u);
  LOBYTE(v28) = 14;
  v16 = INIReader::getFloat(ini, section, &key);
  v15 = key._Myres < 8;
  this->upLimit = v16;
  LOBYTE(v28) = 9;
  if ( !v15 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"DOWN_LIMIT", 0xAu);
  LOBYTE(v28) = 15;
  v17 = INIReader::getFloat(ini, section, &key);
  v15 = key._Myres < 8;
  this->downLimit = v17;
  if ( !v15 )
    operator delete(key._Bx._Ptr);
  v15 = data_path._Myres < 8;
  this->outputAngle = 0.0;
  if ( !v15 )
    operator delete(data_path._Bx._Ptr);
  data_path._Myres = 7;
  data_path._Mysize = 0;
  data_path._Bx._Buf[0] = 0;
  if ( inp._Myres >= 8 )
    operator delete(inp._Bx._Ptr);
}
void DynamicWingController::step(DynamicWingController *this)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm0_4
  float ref; // [esp+0h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-4h]

  ref = DynamicWingController::getInput(this);
  v6 = Curve::getValue(&this->lut, ref);
  v2 = v6;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v6 - this->outputAngle) & _xmm) >= 0.001 )
  {
    v3 = this->filter * 0.003;
    v4 = FLOAT_1_0;
    if ( v3 <= 1.0 )
    {
      v4 = 0.0;
      if ( v3 >= 0.0 )
        v4 = this->filter * 0.003;
    }
    v2 = (float)((float)(v6 - this->outputAngle) * v4) + this->outputAngle;
  }
  this->outputAngle = v2;
}
