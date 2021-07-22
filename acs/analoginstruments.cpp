#include "analoginstruments.h"
void AnalogInstruments::AnalogInstruments(AnalogInstruments *this, CarAvatar *car)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  std::wstring v5; // [esp-1Ch] [ebp-B4h] BYREF
  Game *v6; // [esp-4h] [ebp-9Ch]
  AnalogInstruments *v7; // [esp+Ch] [ebp-8Ch]
  std::wstring v8; // [esp+14h] [ebp-84h] BYREF
  std::wstring result; // [esp+2Ch] [ebp-6Ch] BYREF
  INIReader r; // [esp+44h] [ebp-54h] BYREF
  int v11; // [esp+94h] [ebp-4h]

  v7 = this;
  v6 = car->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"ANALOG_INSTRUMENTS", 0x12u);
  GameObject::GameObject(this, v5, v6);
  v11 = 0;
  this->__vftable = (AnalogInstruments_vtbl *)&AnalogInstruments::`vftable';
  this->car = car;
  this->maxRPMRecorded = 0.0;
  this->currentRPM = 0.0;
  Curve::Curve(&this->fuelLut);
  LOBYTE(v11) = 1;
  Curve::Curve(&this->rpmLut);
  LOBYTE(v11) = 2;
  Curve::Curve(&this->speedLut);
  LOBYTE(v11) = 3;
  Curve::Curve(&this->waterLut);
  this->fuel.target = 0;
  this->fuel.zero = 0.0;
  this->fuel.step = 0.0;
  this->fuel.min = 0.0;
  mat44f::mat44f(&this->fuel.baseMatrix);
  this->rpm.target = 0;
  this->rpm.zero = 0.0;
  this->rpm.step = 0.0;
  this->rpm.min = 0.0;
  mat44f::mat44f(&this->rpm.baseMatrix);
  this->rpmMax.target = 0;
  this->rpmMax.zero = 0.0;
  this->rpmMax.step = 0.0;
  this->rpmMax.min = 0.0;
  mat44f::mat44f(&this->rpmMax.baseMatrix);
  this->speed.target = 0;
  this->speed.zero = 0.0;
  this->speed.step = 0.0;
  this->speed.min = 0.0;
  mat44f::mat44f(&this->speed.baseMatrix);
  this->water.target = 0;
  this->water.zero = 0.0;
  this->water.step = 0.0;
  this->water.min = 0.0;
  mat44f::mat44f(&this->water.baseMatrix);
  this->turbos._Myfirst = 0;
  this->turbos._Mylast = 0;
  this->turbos._Myend = 0;
  this->turboLimiters._Myfirst = 0;
  this->turboLimiters._Mylast = 0;
  this->turboLimiters._Myend = 0;
  this->turboValues._Myfirst = 0;
  this->turboValues._Mylast = 0;
  this->turboValues._Myend = 0;
  this->turboUseBar = 0;
  this->placeHolders._Myfirst = 0;
  this->placeHolders._Mylast = 0;
  this->placeHolders._Myend = 0;
  LOBYTE(v11) = 8;
  v6 = (Game *)&car->unixName;
  this->placeHolderSet = 0;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", (const std::wstring *)v6);
  LOBYTE(v11) = 9;
  v4 = std::operator+<wchar_t>(&v8, v3, L"/data/analog_instruments.ini");
  LOBYTE(v11) = 10;
  CarAvatar::openINI(car, &r, v4);
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  LOBYTE(v11) = 13;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( r.ready )
  {
    AnalogInstruments::initFuel(this, &r);
    AnalogInstruments::initRPM(this, &r);
    AnalogInstruments::initSpeed(this, &r);
    AnalogInstruments::initTurbo(this, &r);
    AnalogInstruments::initWater(this, &r);
    AnalogInstruments::initPlaceHolders(this, &r);
  }
  LOBYTE(v11) = 8;
  INIReader::~INIReader(&r);
}
void AnalogInstruments::~AnalogInstruments(AnalogInstruments *this)
{
  std::vector<AnalogNeedle> *v2; // edi
  std::vector<std::pair<float,float>> *v3; // edi
  std::vector<AnalogNeedle> *v4; // edi
  std::vector<AnalogNeedle> *v5; // edi

  this->__vftable = (AnalogInstruments_vtbl *)&AnalogInstruments::`vftable';
  v2 = &this->placeHolders;
  if ( this->placeHolders._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->placeHolders);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = &this->turboValues;
  if ( this->turboValues._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->turboValues);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->turboValues._Mylast = 0;
    this->turboValues._Myend = 0;
  }
  v4 = &this->turboLimiters;
  if ( this->turboLimiters._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->turboLimiters);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->turboLimiters._Mylast = 0;
    this->turboLimiters._Myend = 0;
  }
  v5 = &this->turbos;
  if ( this->turbos._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->turbos);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->turbos._Mylast = 0;
    this->turbos._Myend = 0;
  }
  Curve::~Curve(&this->waterLut);
  Curve::~Curve(&this->speedLut);
  Curve::~Curve(&this->rpmLut);
  Curve::~Curve(&this->fuelLut);
  GameObject::~GameObject(this);
}
AnalogInstruments *AnalogInstruments::`scalar deleting destructor'(AnalogInstruments *this, unsigned int a2)
{
  AnalogInstruments::~AnalogInstruments(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void AnalogInstruments::initFuel(AnalogInstruments *this, INIReader *r)
{
  bool v3; // bl
  std::wstring *v4; // eax
  CarAvatar *v5; // ecx
  Node *v6; // eax
  bool v7; // cf
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  double v10; // st7
  double v11; // st7
  Node *v12; // eax
  float *v13; // ebp
  __m128i v14; // xmm0
  char v15; // bl
  double v16; // st7
  char v17; // bl
  const Curve *v18; // eax
  Console *v19; // esi
  std::wstring v20; // [esp-1Ch] [ebp-118h] BYREF
  float *v21; // [esp-4h] [ebp-100h]
  IVarCallback *v22; // [esp+0h] [ebp-FCh]
  BOOL v23; // [esp+4h] [ebp-F8h]
  float multiplier; // [esp+8h] [ebp-F4h]
  float *v25; // [esp+20h] [ebp-DCh]
  float *var; // [esp+24h] [ebp-D8h]
  std::wstring key; // [esp+28h] [ebp-D4h] BYREF
  std::wstring result; // [esp+40h] [ebp-BCh] BYREF
  std::wstring section; // [esp+58h] [ebp-A4h] BYREF
  std::wstring v30; // [esp+70h] [ebp-8Ch] BYREF
  std::wstring v31; // [esp+88h] [ebp-74h] BYREF
  Curve v32; // [esp+A0h] [ebp-5Ch] BYREF
  int v33; // [esp+F8h] [ebp-4h]

  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FUEL_INDICATOR", 0xEu);
  v33 = 0;
  v3 = INIReader::hasSection(r, &section);
  v33 = -1;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v3 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OBJECT_NAME", 0xBu);
    v33 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FUEL_INDICATOR", 0xEu);
    LOBYTE(v33) = 2;
    v4 = INIReader::getString(r, &result, &section, &key);
    v5 = this->car;
    LOBYTE(v33) = 3;
    v6 = v5->bodyTransform->findChildByName(v5->bodyTransform, v4, 1);
    v7 = result._Myres < 8;
    this->fuel.target = v6;
    if ( !v7 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v33 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( this->fuel.target )
    {
      std::wstring::wstring(&result, L"ZERO");
      v33 = 7;
      std::wstring::wstring(&key, L"FUEL_INDICATOR");
      LOBYTE(v33) = 8;
      v25 = &this->fuel.zero;
      v10 = INIReader::getFloat(r, &key, &result);
      v7 = key._Myres < 8;
      this->fuel.zero = v10;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      v33 = -1;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"STEP");
      v33 = 9;
      std::wstring::wstring(&key, L"FUEL_INDICATOR");
      LOBYTE(v33) = 10;
      var = &this->fuel.step;
      v11 = INIReader::getFloat(r, &key, &result);
      v7 = key._Myres < 8;
      this->fuel.step = v11;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      v33 = -1;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v12 = this->fuel.target;
      v13 = &this->fuel.min;
      LODWORD(multiplier) = L"MIN_VALUE";
      *(__m128i *)&this->fuel.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v12->matrix);
      *(__m128i *)&this->fuel.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v12->matrix.M21);
      *(__m128i *)&this->fuel.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v12->matrix.M31);
      v14 = _mm_loadu_si128((const __m128i *)&v12->matrix.M41);
      this->fuel.min = 0.0;
      *(__m128i *)&this->fuel.baseMatrix.M41 = v14;
      std::wstring::wstring(&result, (const wchar_t *)LODWORD(multiplier));
      v33 = 11;
      std::wstring::wstring(&key, L"FUEL_INDICATOR");
      LOBYTE(v33) = 12;
      v15 = INIReader::hasKey(r, &key, &result);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      v33 = -1;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( v15 )
      {
        std::wstring::wstring(&result, L"MIN_VALUE");
        v33 = 13;
        std::wstring::wstring(&key, L"FUEL_INDICATOR");
        LOBYTE(v33) = 14;
        v16 = INIReader::getFloat(r, &key, &result);
        v7 = key._Myres < 8;
        *v13 = v16;
        if ( !v7 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        v33 = -1;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
      std::wstring::wstring(&result, L"LUT");
      v33 = 15;
      std::wstring::wstring(&key, L"FUEL_INDICATOR");
      LOBYTE(v33) = 16;
      v17 = INIReader::hasKey(r, &key, &result);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      v33 = -1;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( v17 )
      {
        std::wstring::wstring(&v30, L"LUT");
        v33 = 17;
        std::wstring::wstring(&v31, L"FUEL_INDICATOR");
        LOBYTE(v33) = 18;
        v18 = INIReader::getCurve(r, &v32, &v31, &v30);
        LOBYTE(v33) = 19;
        Curve::operator=(&this->fuelLut, v18);
        LOBYTE(v33) = 18;
        Curve::~Curve(&v32);
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        v33 = -1;
        if ( v30._Myres >= 8 )
          operator delete(v30._Bx._Ptr);
        v30._Myres = 7;
        v30._Mysize = 0;
        v30._Bx._Buf[0] = 0;
      }
      if ( !CarAvatar::getGuid(this->car) )
      {
        multiplier = 1.0;
        v19 = Console::singleton();
        v23 = 0;
        v22 = 0;
        v21 = var;
        std::wstring::wstring(&v20, L"FUEL_STEP");
        Console::addVar(v19, v20, v21, v22, v23, multiplier);
        multiplier = 1.0;
        v23 = 0;
        v22 = 0;
        v21 = v25;
        std::wstring::wstring(&v20, L"FUEL_ZERO");
        Console::addVar(v19, v20, v21, v22, v23, multiplier);
        multiplier = 1.0;
        v23 = 0;
        v22 = 0;
        v21 = v13;
        std::wstring::wstring(&v20, L"FUEL_MIN");
        Console::addVar(v19, v20, v21, v22, v23, multiplier);
      }
    }
    else
    {
      std::wstring::wstring(&section, L"OBJECT_NAME");
      v33 = 4;
      std::wstring::wstring(&key, L"FUEL_INDICATOR");
      LOBYTE(v33) = 5;
      v8 = INIReader::getString(r, &result, &key, &section);
      if ( v8->_Myres >= 8 )
        v8 = (std::wstring *)v8->_Bx._Ptr;
      _printf("ERROR: Cannot find FUEL_INDICATOR target: %S\n", v8->_Bx._Buf);
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
      v33 = -1;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      std::wstring::wstring(&result, L"Cannot find FUEL_INDICATOR target");
      v9 = &result;
      v33 = 6;
      if ( result._Myres >= 8 )
        v9 = (std::wstring *)result._Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v9->_Bx._Buf);
      ksGenerateCrash();
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
}
void AnalogInstruments::initPlaceHolders(AnalogInstruments *this, INIReader *ini)
{
  int v2; // esi
  std::wstring *v3; // eax
  int v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // esi
  bool v7; // al
  AnalogNeedle _Val; // [esp+Ch] [ebp-FCh] BYREF
  int v9; // [esp+5Ch] [ebp-ACh]
  std::vector<AnalogNeedle> *v10; // [esp+60h] [ebp-A8h]
  AnalogInstruments *v11; // [esp+64h] [ebp-A4h]
  std::wstring v12; // [esp+68h] [ebp-A0h] BYREF
  std::wstring v13; // [esp+80h] [ebp-88h] BYREF
  std::wstring result; // [esp+98h] [ebp-70h] BYREF
  std::wstring key; // [esp+B0h] [ebp-58h] BYREF
  std::wstring section; // [esp+C8h] [ebp-40h] BYREF
  std::wstring v17; // [esp+E0h] [ebp-28h] BYREF
  int v18; // [esp+104h] [ebp-4h]

  v11 = this;
  v2 = 0;
  v3 = std::to_wstring(&result, 0);
  v18 = 0;
  std::operator+<wchar_t>(&section, L"PLACE_HOLDER_", v3);
  LOBYTE(v18) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( INIReader::hasSection(ini, &section) )
  {
    v10 = &v11->placeHolders;
    do
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      *(_OWORD *)&_Val.baseMatrix.M11 = 0i64;
      *(_OWORD *)&_Val.baseMatrix.M21 = 0i64;
      *(_OWORD *)&_Val.baseMatrix.M31 = 0i64;
      *(_OWORD *)&_Val.baseMatrix.M41 = 0i64;
      std::wstring::assign(&key, L"OBJECT_NAME", 0xBu);
      LOBYTE(v18) = 3;
      INIReader::getString(ini, &v13, &section, &key);
      LOBYTE(v18) = 5;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Bx._Buf[0] = 0;
      key._Mysize = 0;
      v4 = (int)v11->car->carNode->findChildByName(v11->car->carNode, &v13, 1);
      _Val.target = (Node *)v4;
      if ( v4 )
      {
        *(__m128i *)&_Val.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)(v4 + 4));
        *(__m128i *)&_Val.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)(v4 + 20));
        *(__m128i *)&_Val.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)(v4 + 36));
        *(__m128i *)&_Val.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)(v4 + 52));
      }
      v17._Myres = 7;
      v17._Mysize = 0;
      v17._Bx._Buf[0] = 0;
      std::wstring::assign(&v17, L"ZERO", 4u);
      LOBYTE(v18) = 6;
      _Val.zero = INIReader::getFloat(ini, &section, &v17);
      LOBYTE(v18) = 5;
      if ( v17._Myres >= 8 )
        operator delete(v17._Bx._Ptr);
      v17._Myres = 7;
      v17._Mysize = 0;
      v17._Bx._Buf[0] = 0;
      std::wstring::assign(&v17, L"STEP", 4u);
      LOBYTE(v18) = 7;
      _Val.step = INIReader::getFloat(ini, &section, &v17);
      LOBYTE(v18) = 5;
      if ( v17._Myres >= 8 )
        operator delete(v17._Bx._Ptr);
      v17._Myres = 7;
      v17._Mysize = 0;
      v17._Bx._Buf[0] = 0;
      std::wstring::assign(&v17, L"MIN_VALUE", 9u);
      LOBYTE(v18) = 8;
      _Val.min = INIReader::getFloat(ini, &section, &v17);
      LOBYTE(v18) = 5;
      if ( v17._Myres >= 8 )
        operator delete(v17._Bx._Ptr);
      std::vector<AnalogNeedle>::push_back(v10, &_Val);
      v9 = v2 + 1;
      v5 = std::to_wstring(&v12, v2 + 1);
      LOBYTE(v18) = 9;
      v6 = std::operator+<wchar_t>(&v17, L"PLACE_HOLDER_", v5);
      if ( &section != v6 )
      {
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        if ( v6->_Myres >= 8 )
        {
          section._Bx._Ptr = v6->_Bx._Ptr;
          v6->_Bx._Ptr = 0;
        }
        else if ( v6->_Mysize != -1 )
        {
          _memmove(&section, v6, 2 * (v6->_Mysize + 1));
        }
        section._Mysize = v6->_Mysize;
        section._Myres = v6->_Myres;
        v6->_Myres = 7;
        v6->_Mysize = 0;
        v6->_Bx._Buf[0] = 0;
      }
      if ( v17._Myres >= 8 )
        operator delete(v17._Bx._Ptr);
      v17._Myres = 7;
      v17._Mysize = 0;
      v17._Bx._Buf[0] = 0;
      if ( v12._Myres >= 8 )
        operator delete(v12._Bx._Ptr);
      LOBYTE(v18) = 2;
      if ( v13._Myres >= 8 )
        operator delete(v13._Bx._Ptr);
      v7 = INIReader::hasSection(ini, &section);
      v2 = v9;
    }
    while ( v7 );
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void AnalogInstruments::initRPM(AnalogInstruments *this, INIReader *r)
{
  CarAvatar *v3; // eax
  Node *v4; // eax
  bool v5; // cf
  CarAvatar *v6; // eax
  Node *v7; // eax
  Node *v8; // eax
  Node *v9; // eax
  float *v10; // ebp
  float *v11; // ebx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  char v15; // bl
  const Curve *v16; // eax
  Node *v17; // eax
  std::wstring *v18; // edi
  Node *v19; // eax
  Console *v20; // esi
  std::wstring v21; // [esp-4h] [ebp-114h] BYREF
  float *v22; // [esp+14h] [ebp-FCh]
  IVarCallback *v23; // [esp+18h] [ebp-F8h]
  BOOL v24; // [esp+1Ch] [ebp-F4h]
  float multiplier; // [esp+20h] [ebp-F0h]
  std::wstring key; // [esp+3Ch] [ebp-D4h] BYREF
  std::wstring target_name; // [esp+54h] [ebp-BCh] BYREF
  std::wstring section; // [esp+6Ch] [ebp-A4h] BYREF
  std::wstring v29; // [esp+84h] [ebp-8Ch] BYREF
  std::wstring v30; // [esp+9Ch] [ebp-74h] BYREF
  Curve result; // [esp+B4h] [ebp-5Ch] BYREF
  int v32; // [esp+10Ch] [ebp-4h]

  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ARROW_RPM", 9u);
  v3 = this->car;
  v32 = 0;
  v4 = v3->carNode->findChildByName(v3->carNode, &key, 1);
  v5 = key._Myres < 8;
  this->rpm.target = v4;
  v32 = -1;
  if ( !v5 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ARROW_LIMITER", 0xDu);
  v6 = this->car;
  v32 = 1;
  v7 = v6->carNode->findChildByName(v6->carNode, &key, 1);
  v5 = key._Myres < 8;
  this->rpmMax.target = v7;
  v32 = -1;
  if ( !v5 )
    operator delete(key._Bx._Ptr);
  v8 = this->rpm.target;
  if ( v8 )
  {
    *(__m128i *)&this->rpm.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v8->matrix);
    *(__m128i *)&this->rpm.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v8->matrix.M21);
    *(__m128i *)&this->rpm.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v8->matrix.M31);
    *(__m128i *)&this->rpm.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v8->matrix.M41);
  }
  v9 = this->rpmMax.target;
  if ( v9 )
  {
    *(__m128i *)&this->rpmMax.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v9->matrix);
    *(__m128i *)&this->rpmMax.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v9->matrix.M21);
    *(__m128i *)&this->rpmMax.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v9->matrix.M31);
    *(__m128i *)&this->rpmMax.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v9->matrix.M41);
  }
  LODWORD(multiplier) = 13;
  this->rpm.step = 0.02;
  v10 = &this->rpm.step;
  this->rpm.zero = -110.0;
  v11 = &this->rpm.zero;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"RPM_INDICATOR", LODWORD(multiplier));
  v32 = 2;
  if ( INIReader::hasSection(r, &section) )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEP", 4u);
    LOBYTE(v32) = 3;
    v12 = INIReader::getFloat(r, &section, &key);
    v5 = key._Myres < 8;
    *v10 = v12;
    LOBYTE(v32) = 2;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ZERO", 4u);
    LOBYTE(v32) = 4;
    v13 = INIReader::getFloat(r, &section, &key);
    v5 = key._Myres < 8;
    *v11 = v13;
    LOBYTE(v32) = 2;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_VALUE", 9u);
    LOBYTE(v32) = 5;
    v14 = INIReader::getFloat(r, &section, &key);
    v5 = key._Myres < 8;
    this->rpm.min = v14;
    LOBYTE(v32) = 2;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LUT", 3u);
    LOBYTE(v32) = 6;
    v15 = INIReader::hasKey(r, &section, &key);
    LOBYTE(v32) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v15 )
    {
      std::wstring::wstring(&v29, L"LUT");
      LOBYTE(v32) = 7;
      v16 = INIReader::getCurve(r, &result, &section, &v29);
      LOBYTE(v32) = 8;
      Curve::operator=(&this->rpmLut, v16);
      LOBYTE(v32) = 7;
      Curve::~Curve(&result);
      LOBYTE(v32) = 2;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OBJECT_NAME", 0xBu);
    LOBYTE(v32) = 9;
    INIReader::getString(r, &target_name, &section, &key);
    LOBYTE(v32) = 11;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( std::wstring::compare(&target_name, 0, target_name._Mysize, word_17BE9D8, 0) )
    {
      v17 = this->car->carNode->findChildByName(this->car->carNode, &target_name, 1);
      this->rpm.target = v17;
      if ( v17 )
      {
        *(__m128i *)&this->rpm.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v17->matrix);
        *(__m128i *)&this->rpm.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v17->matrix.M21);
        *(__m128i *)&this->rpm.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v17->matrix.M31);
        *(__m128i *)&this->rpm.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v17->matrix.M41);
      }
    }
    v30._Myres = 7;
    v30._Mysize = 0;
    v30._Bx._Buf[0] = 0;
    std::wstring::assign(&v30, L"OBJECT_NAME_MAX", 0xFu);
    LOBYTE(v32) = 12;
    v18 = INIReader::getString(r, &v29, &section, &v30);
    if ( &target_name != v18 )
    {
      if ( target_name._Myres >= 8 )
        operator delete(target_name._Bx._Ptr);
      target_name._Myres = 7;
      target_name._Mysize = 0;
      target_name._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&target_name, v18);
    }
    if ( v29._Myres >= 8 )
      operator delete(v29._Bx._Ptr);
    v29._Myres = 7;
    v29._Mysize = 0;
    v29._Bx._Buf[0] = 0;
    LOBYTE(v32) = 11;
    if ( v30._Myres >= 8 )
      operator delete(v30._Bx._Ptr);
    if ( std::wstring::compare(&target_name, 0, target_name._Mysize, word_17BE9D8, 0) )
    {
      v19 = this->car->carNode->findChildByName(this->car->carNode, &target_name, 1);
      this->rpmMax.target = v19;
      if ( v19 )
      {
        *(__m128i *)&this->rpmMax.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v19->matrix);
        *(__m128i *)&this->rpmMax.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v19->matrix.M21);
        *(__m128i *)&this->rpmMax.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v19->matrix.M31);
        *(__m128i *)&this->rpmMax.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v19->matrix.M41);
      }
    }
    LOBYTE(v32) = 2;
    if ( target_name._Myres >= 8 )
      operator delete(target_name._Bx._Ptr);
    v11 = &this->rpm.zero;
  }
  if ( !CarAvatar::getGuid(this->car) )
  {
    multiplier = 1.0;
    v20 = Console::singleton();
    v24 = 0;
    v23 = 0;
    v22 = v10;
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    std::wstring::assign(&v21, L"RPM_STEP", 8u);
    Console::addVar(v20, v21, v22, v23, v24, multiplier);
    multiplier = 1.0;
    v24 = 0;
    v23 = 0;
    v22 = v11;
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    std::wstring::assign(&v21, L"RPM_ZERO", 8u);
    Console::addVar(v20, v21, v22, v23, v24, multiplier);
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void AnalogInstruments::initSpeed(AnalogInstruments *this, INIReader *r)
{
  CarAvatar *v3; // eax
  Node *v4; // eax
  bool v5; // cf
  Node *v6; // eax
  float *v7; // ebx
  float *v8; // ebp
  double v9; // st7
  double v10; // st7
  Node *v11; // eax
  CarAvatar *v12; // eax
  std::wstring *v13; // eax
  Console *v14; // esi
  std::wstring v15; // [esp-14h] [ebp-B0h] BYREF
  float *v16; // [esp+4h] [ebp-98h]
  IVarCallback *v17; // [esp+8h] [ebp-94h]
  BOOL v18; // [esp+Ch] [ebp-90h]
  float multiplier; // [esp+10h] [ebp-8Ch]
  std::wstring key; // [esp+2Ch] [ebp-70h] BYREF
  std::wstring target_name; // [esp+44h] [ebp-58h] BYREF
  std::wstring section; // [esp+5Ch] [ebp-40h] BYREF
  std::wstring curvefile; // [esp+74h] [ebp-28h] BYREF
  int v24; // [esp+98h] [ebp-4h]

  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ARROW_SPEED", 0xBu);
  v3 = this->car;
  v24 = 0;
  v4 = v3->carNode->findChildByName(v3->carNode, &key, 1);
  v5 = key._Myres < 8;
  this->speed.target = v4;
  v24 = -1;
  if ( !v5 )
    operator delete(key._Bx._Ptr);
  v6 = this->speed.target;
  if ( v6 )
  {
    *(__m128i *)&this->speed.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v6->matrix);
    *(__m128i *)&this->speed.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v6->matrix.M21);
    *(__m128i *)&this->speed.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v6->matrix.M31);
    *(__m128i *)&this->speed.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v6->matrix.M41);
  }
  LODWORD(multiplier) = 15;
  this->speed.step = 0.02;
  v7 = &this->speed.step;
  this->speed.zero = -110.0;
  v8 = &this->speed.zero;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SPEED_INDICATOR", LODWORD(multiplier));
  v24 = 1;
  if ( INIReader::hasSection(r, &section) )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEP", 4u);
    LOBYTE(v24) = 2;
    v9 = INIReader::getFloat(r, &section, &key);
    v5 = key._Myres < 8;
    *v7 = v9;
    LOBYTE(v24) = 1;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ZERO", 4u);
    LOBYTE(v24) = 3;
    v10 = INIReader::getFloat(r, &section, &key);
    v5 = key._Myres < 8;
    *v8 = v10;
    LOBYTE(v24) = 1;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OBJECT_NAME", 0xBu);
    LOBYTE(v24) = 4;
    INIReader::getString(r, &target_name, &section, &key);
    LOBYTE(v24) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( std::wstring::compare(&target_name, 0, target_name._Mysize, word_17BE9D8, 0) )
    {
      v11 = this->car->carNode->findChildByName(this->car->carNode, &target_name, 1);
      this->speed.target = v11;
      if ( v11 )
      {
        *(__m128i *)&this->speed.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v11->matrix);
        *(__m128i *)&this->speed.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v11->matrix.M21);
        *(__m128i *)&this->speed.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v11->matrix.M31);
        *(__m128i *)&this->speed.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v11->matrix.M41);
      }
    }
    LOBYTE(v24) = 1;
    if ( target_name._Myres >= 8 )
      operator delete(target_name._Bx._Ptr);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/cars/", 0xDu);
  v12 = this->car;
  LOBYTE(v24) = 7;
  v13 = std::operator+<wchar_t>(&target_name, &key, &v12->unixName);
  LOBYTE(v24) = 8;
  std::operator+<wchar_t>(&curvefile, v13, L"/data/analog_speed_curve.lut");
  if ( target_name._Myres >= 8 )
    operator delete(target_name._Bx._Ptr);
  target_name._Myres = 7;
  target_name._Mysize = 0;
  target_name._Bx._Buf[0] = 0;
  LOBYTE(v24) = 11;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Bx._Buf[0] = 0;
  key._Mysize = 0;
  if ( Path::fileExists((unsigned int)v7, &curvefile, 0) )
    Curve::load(&this->speedLut, &curvefile);
  if ( !CarAvatar::getGuid(this->car) )
  {
    multiplier = 1.0;
    v14 = Console::singleton();
    v18 = 0;
    v17 = 0;
    v16 = v7;
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    std::wstring::assign(&v15, L"SPEED_STEP", 0xAu);
    Console::addVar(v14, v15, v16, v17, v18, multiplier);
    multiplier = 1.0;
    v18 = 0;
    v17 = 0;
    v16 = v8;
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    std::wstring::assign(&v15, L"SPEED_ZERO", 0xAu);
    Console::addVar(v14, v15, v16, v17, v18, multiplier);
  }
  if ( curvefile._Myres >= 8 )
    operator delete(curvefile._Bx._Ptr);
  curvefile._Myres = 7;
  curvefile._Mysize = 0;
  curvefile._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void AnalogInstruments::initTurbo(AnalogInstruments *this, INIReader *r)
{
  AnalogInstruments *v2; // esi
  int v3; // ebx
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // esi
  std::wstring section; // [esp+18h] [ebp-70h] BYREF
  std::wstring result; // [esp+30h] [ebp-58h] BYREF
  std::wstring v10; // [esp+48h] [ebp-40h] BYREF
  std::wstring v11; // [esp+60h] [ebp-28h] BYREF
  int v12; // [esp+84h] [ebp-4h]

  v2 = this;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"TURBO_INDICATOR", 0xFu);
  v12 = 0;
  AnalogInstruments::readTurboSection(v2, r, &result);
  v12 = -1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v3 = 0;
  v4 = std::to_wstring(&result, 0);
  v12 = 1;
  std::operator+<wchar_t>(&section, L"TURBO_INDICATOR_", v4);
  LOBYTE(v12) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  for ( result._Mysize = 0; INIReader::hasSection(r, &section); v2 = this )
  {
    AnalogInstruments::readTurboSection(v2, r, &section);
    v5 = std::to_wstring(&v11, ++v3);
    LOBYTE(v12) = 4;
    v6 = std::operator+<wchar_t>(&v10, L"TURBO_INDICATOR_", v5);
    if ( &section != v6 )
    {
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( v6->_Myres >= 8 )
      {
        section._Bx._Ptr = v6->_Bx._Ptr;
        v6->_Bx._Ptr = 0;
      }
      else if ( v6->_Mysize != -1 )
      {
        _memmove(&section, v6, 2 * (v6->_Mysize + 1));
      }
      section._Mysize = v6->_Mysize;
      section._Myres = v6->_Myres;
      v6->_Myres = 7;
      v6->_Mysize = 0;
      v6->_Bx._Buf[0] = 0;
    }
    if ( v10._Myres >= 8 )
      operator delete(v10._Bx._Ptr);
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
    LOBYTE(v12) = 3;
    if ( v11._Myres >= 8 )
      operator delete(v11._Bx._Ptr);
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void AnalogInstruments::initWater(AnalogInstruments *this, INIReader *ini)
{
  CarAvatar *v3; // eax
  int v4; // eax
  double v5; // st7
  bool v6; // cf
  double v7; // st7
  double v8; // st7
  Curve *v9; // esi
  const std::wstring *v10; // esi
  Console *v11; // esi
  std::wstring v12; // [esp-1Ch] [ebp-FCh] BYREF
  float *v13; // [esp-4h] [ebp-E4h]
  IVarCallback *v14; // [esp+0h] [ebp-E0h]
  BOOL v15; // [esp+4h] [ebp-DCh]
  float multiplier; // [esp+8h] [ebp-D8h]
  std::wstring v17; // [esp+24h] [ebp-BCh] BYREF
  std::wstring section; // [esp+3Ch] [ebp-A4h] BYREF
  std::wstring key; // [esp+54h] [ebp-8Ch] BYREF
  std::wstring target_name; // [esp+6Ch] [ebp-74h] BYREF
  Curve result; // [esp+84h] [ebp-5Ch] BYREF
  int v22; // [esp+DCh] [ebp-4h]

  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"WATER_TEMP", 0xAu);
  v22 = 0;
  if ( INIReader::hasSection(ini, &section) )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OBJECT_NAME", 0xBu);
    LOBYTE(v22) = 1;
    INIReader::getString(ini, &target_name, &section, &key);
    LOBYTE(v22) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Bx._Buf[0] = 0;
    v3 = this->car;
    key._Mysize = 0;
    v4 = (int)v3->carNode->findChildByName(v3->carNode, &target_name, 1);
    this->water.target = (Node *)v4;
    if ( v4 )
    {
      *(__m128i *)&this->water.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)(v4 + 4));
      *(__m128i *)&this->water.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)(v4 + 20));
      *(__m128i *)&this->water.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)(v4 + 36));
      *(__m128i *)&this->water.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)(v4 + 52));
    }
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    std::wstring::assign(&v17, L"ZERO", 4u);
    LOBYTE(v22) = 4;
    v5 = INIReader::getFloat(ini, &section, &v17);
    v6 = v17._Myres < 8;
    this->water.zero = v5;
    LOBYTE(v22) = 3;
    if ( !v6 )
      operator delete(v17._Bx._Ptr);
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    std::wstring::assign(&v17, L"STEP", 4u);
    LOBYTE(v22) = 5;
    v7 = INIReader::getFloat(ini, &section, &v17);
    v6 = v17._Myres < 8;
    this->water.step = v7;
    LOBYTE(v22) = 3;
    if ( !v6 )
      operator delete(v17._Bx._Ptr);
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    std::wstring::assign(&v17, L"MIN_VALUE", 9u);
    LOBYTE(v22) = 6;
    v8 = INIReader::getFloat(ini, &section, &v17);
    v6 = v17._Myres < 8;
    this->water.min = v8;
    LOBYTE(v22) = 3;
    if ( !v6 )
      operator delete(v17._Bx._Ptr);
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    std::wstring::assign(&v17, L"LUT", 3u);
    LOBYTE(v22) = 7;
    v9 = INIReader::getCurve(ini, &result, &section, &v17);
    LOBYTE(v22) = 8;
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)&this->waterLut.references,
      (const std::vector<unsigned int> *)&v9->references);
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)&this->waterLut.values,
      (const std::vector<unsigned int> *)&v9->values);
    this->waterLut.fastStep = v9->fastStep;
    this->waterLut.cubicSplineReady = v9->cubicSplineReady;
    std::vector<CTData>::operator=(&this->waterLut.cSpline.mElements, &v9->cSpline.mElements);
    v10 = &v9->filename;
    if ( &this->waterLut.filename != v10 )
      std::wstring::assign(&this->waterLut.filename, v10, 0, 0xFFFFFFFF);
    LOBYTE(v22) = 7;
    Curve::~Curve(&result);
    LOBYTE(v22) = 3;
    if ( v17._Myres >= 8 )
      operator delete(v17._Bx._Ptr);
    if ( !CarAvatar::getGuid(this->car) )
    {
      multiplier = 1.0;
      v11 = Console::singleton();
      v15 = 0;
      v14 = 0;
      v13 = &this->water.step;
      std::wstring::wstring(&v12, L"wATER_STEP");
      Console::addVar(v11, v12, v13, v14, v15, multiplier);
      multiplier = 1.0;
      v15 = 0;
      v14 = 0;
      v13 = &this->water.zero;
      std::wstring::wstring(&v12, L"WATER_ZERO");
      Console::addVar(v11, v12, v13, v14, v15, multiplier);
      multiplier = 1.0;
      v15 = 0;
      v14 = 0;
      v13 = &this->water.min;
      std::wstring::wstring(&v12, L"WATER_MIN");
      Console::addVar(v11, v12, v13, v14, v15, multiplier);
    }
    if ( target_name._Myres >= 8 )
      operator delete(target_name._Bx._Ptr);
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void AnalogInstruments::readTurboSection(AnalogInstruments *this, INIReader *r, const std::wstring *section)
{
  CarAvatar *v4; // eax
  Node *v5; // eax
  CarAvatar *v6; // eax
  int v7; // ebx
  int v8; // eax
  bool v9; // cf
  std::wstring *v10; // ebx
  Node *v11; // eax
  char v12; // bl
  std::wstring *v13; // esi
  Node *v14; // eax
  Console *v15; // esi
  std::wstring v16; // [esp-4h] [ebp-13Ch] BYREF
  float *v17; // [esp+14h] [ebp-124h]
  IVarCallback *v18; // [esp+18h] [ebp-120h]
  BOOL v19; // [esp+1Ch] [ebp-11Ch]
  float multiplier; // [esp+20h] [ebp-118h]
  std::pair<float,float> p; // [esp+38h] [ebp-100h] BYREF
  AnalogNeedle turbo; // [esp+40h] [ebp-F8h] BYREF
  AnalogNeedle turboLimiter; // [esp+90h] [ebp-A8h] BYREF
  std::wstring key; // [esp+E0h] [ebp-58h] BYREF
  std::wstring target_name; // [esp+F8h] [ebp-40h] BYREF
  std::wstring result; // [esp+110h] [ebp-28h] BYREF
  int v27; // [esp+134h] [ebp-4h]

  turbo.target = 0;
  turbo.zero = 0.0;
  turbo.step = 0.0;
  turbo.min = 0.0;
  mat44f::mat44f(&turbo.baseMatrix);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ARROW_TURBO", 0xBu);
  v4 = this->car;
  v27 = 0;
  v5 = v4->carNode->findChildByName(v4->carNode, &key, 1);
  turbo.target = v5;
  v27 = -1;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v5 = turbo.target;
  }
  if ( v5 )
  {
    *(__m128i *)&turbo.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v5->matrix);
    *(__m128i *)&turbo.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v5->matrix.M21);
    *(__m128i *)&turbo.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v5->matrix.M31);
    *(__m128i *)&turbo.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v5->matrix.M41);
  }
  turboLimiter.zero = 0.0;
  turboLimiter.step = 0.0;
  turboLimiter.min = 0.0;
  mat44f::mat44f(&turboLimiter.baseMatrix);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ARROW_TURBO_LIMITER", 0x13u);
  v6 = this->car;
  v27 = 1;
  v7 = (int)v6->carNode->findChildByName(v6->carNode, &key, 1);
  turboLimiter.target = (Node *)v7;
  v27 = -1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v7 )
  {
    *(__m128i *)&turboLimiter.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)(v7 + 4));
    *(__m128i *)&turboLimiter.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)(v7 + 20));
    *(__m128i *)&turboLimiter.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)(v7 + 36));
    *(__m128i *)&turboLimiter.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)(v7 + 52));
  }
  turbo.step = 0.02;
  turbo.zero = -110.0;
  if ( INIReader::hasSection(r, section) )
  {
    target_name._Myres = 7;
    target_name._Mysize = 0;
    target_name._Bx._Buf[0] = 0;
    v27 = 2;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"STEP", 4u);
    LOBYTE(v27) = 3;
    turbo.step = INIReader::getFloat(r, section, &key);
    LOBYTE(v27) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ZERO", 4u);
    LOBYTE(v27) = 4;
    turbo.zero = INIReader::getFloat(r, section, &key);
    LOBYTE(v27) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_VALUE", 9u);
    LOBYTE(v27) = 5;
    turbo.min = INIReader::getFloat(r, section, &key);
    LOBYTE(v27) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"USE_BAR", 7u);
    LOBYTE(v27) = 6;
    v8 = INIReader::getInt(r, section, &key);
    LOBYTE(v27) = 2;
    v9 = key._Myres < 8;
    this->turboUseBar = v8 != 0;
    if ( !v9 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OBJECT_NAME", 0xBu);
    LOBYTE(v27) = 7;
    v10 = INIReader::getString(r, &result, section, &key);
    if ( &target_name != v10 )
    {
      if ( target_name._Myres >= 8 )
        operator delete(target_name._Bx._Ptr);
      target_name._Myres = 7;
      target_name._Mysize = 0;
      target_name._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&target_name, v10);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v27) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( std::wstring::compare(&target_name, 0, target_name._Mysize, word_17BE9D8, 0) )
    {
      v11 = this->car->carNode->findChildByName(this->car->carNode, &target_name, 1);
      turbo.target = v11;
      if ( v11 )
      {
        *(__m128i *)&turbo.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v11->matrix);
        *(__m128i *)&turbo.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v11->matrix.M21);
        *(__m128i *)&turbo.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v11->matrix.M31);
        *(__m128i *)&turbo.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v11->matrix.M41);
      }
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OBJECT_NAME_MAX", 0xFu);
    LOBYTE(v27) = 8;
    v12 = INIReader::hasKey(r, section, &key);
    LOBYTE(v27) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v12 )
    {
      std::wstring::wstring(&key, L"OBJECT_NAME_MAX");
      LOBYTE(v27) = 9;
      v13 = INIReader::getString(r, &result, section, &key);
      if ( &target_name != v13 )
      {
        if ( target_name._Myres >= 8 )
          operator delete(target_name._Bx._Ptr);
        target_name._Myres = 7;
        target_name._Mysize = 0;
        target_name._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&target_name, v13);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v27) = 2;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( std::wstring::compare(&target_name, 0, target_name._Mysize, word_17BE9D8, 0) )
      {
        v14 = this->car->carNode->findChildByName(this->car->carNode, &target_name, 1);
        turboLimiter.target = v14;
        if ( v14 )
        {
          *(__m128i *)&turboLimiter.baseMatrix.M11 = _mm_loadu_si128((const __m128i *)&v14->matrix);
          *(__m128i *)&turboLimiter.baseMatrix.M21 = _mm_loadu_si128((const __m128i *)&v14->matrix.M21);
          *(__m128i *)&turboLimiter.baseMatrix.M31 = _mm_loadu_si128((const __m128i *)&v14->matrix.M31);
          *(__m128i *)&turboLimiter.baseMatrix.M41 = _mm_loadu_si128((const __m128i *)&v14->matrix.M41);
        }
      }
    }
    if ( !CarAvatar::getGuid(this->car) )
    {
      multiplier = 1.0;
      v15 = Console::singleton();
      v19 = 0;
      v18 = 0;
      v17 = &turbo.step;
      std::wstring::wstring(&v16, L"TURBO_STEP");
      Console::addVar(v15, v16, v17, v18, v19, multiplier);
      multiplier = 1.0;
      v19 = 0;
      v18 = 0;
      v17 = &turbo.zero;
      std::wstring::wstring(&v16, L"TURBO_ZERO");
      Console::addVar(v15, v16, v17, v18, v19, multiplier);
    }
    v27 = -1;
    if ( target_name._Myres >= 8 )
      operator delete(target_name._Bx._Ptr);
    target_name._Myres = 7;
    target_name._Mysize = 0;
    target_name._Bx._Buf[0] = 0;
  }
  std::vector<AnalogNeedle>::push_back(&this->turbos, &turbo);
  std::vector<AnalogNeedle>::push_back(&this->turboLimiters, &turboLimiter);
  p.first = 0.0;
  p.second = 0.0;
  std::vector<std::pair<float,float>>::push_back(&this->turboValues, &p);
}
void __userpurge AnalogInstruments::update(AnalogInstruments *this@<ecx>, int a2@<ebx>, float dt)
{
  int v4; // esi

  v4 = Sim::getFocusedCarIndex(this->car->sim);
  if ( v4 == CarAvatar::getGuid(this->car) )
  {
    AnalogInstruments::updateRPM(this, (int)this, v4, dt);
    AnalogInstruments::updateFuel(this, a2, (int)this, dt);
    AnalogInstruments::updateSpeed(this, (int)this, dt);
    AnalogInstruments::updateTurbo(this, dt);
    AnalogInstruments::updateWater(this, a2, (int)this, dt);
    if ( !this->placeHolderSet )
    {
      AnalogInstruments::updatePlaceHolders(this, dt);
      this->placeHolderSet = 1;
    }
  }
}
void __userpurge AnalogInstruments::updateFuel(AnalogInstruments *this@<ecx>, int a2@<ebx>, int a3@<edi>, float dt)
{
  float *v5; // eax
  float *v6; // edx
  Curve *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm4_4
  mat44f *v10; // [esp-8h] [ebp-64h]
  float ref; // [esp+10h] [ebp-4Ch]
  float v12; // [esp+14h] [ebp-48h]
  mat44f matrix1; // [esp+1Ch] [ebp-40h] BYREF

  if ( this->fuel.target )
  {
    v5 = &this->fuel.min;
    v6 = &this->car->physicsState.fuel;
    v7 = &this->fuelLut;
    if ( *v6 > this->fuel.min )
      v5 = v6;
    ref = *v5;
    if ( Curve::getCount(v7) )
      Curve::getValue(&this->fuelLut, ref);
    v12 = __libm_sse2_cosf(a3, a2).m128_f32[0];
    v8 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f(&matrix1);
    matrix1.M33 = (float)(1.0 - v12) + v12;
    matrix1.M44 = 1.0;
    v9 = (float)(1.0 - v12) * 0.0;
    v10 = &this->fuel.target->matrix;
    matrix1.M22 = v9 + v12;
    matrix1.M11 = v9 + v12;
    matrix1.M12 = v8 + v9;
    matrix1.M21 = v9 - v8;
    matrix1.M13 = v9 - (float)(v8 * 0.0);
    matrix1.M31 = (float)(v8 * 0.0) + v9;
    matrix1.M23 = matrix1.M31;
    matrix1.M32 = matrix1.M13;
    mul(v10, &matrix1, &this->fuel.baseMatrix);
  }
}
void AnalogInstruments::updatePlaceHolders(AnalogInstruments *this, float dt)
{
  const __m128i *v2; // esi
  AnalogNeedle *i; // edi
  float v4; // xmm0_4
  float v5; // xmm1_4
  int v6; // [esp+0h] [ebp-B0h]
  int v7; // [esp+4h] [ebp-ACh]
  int v8; // [esp+14h] [ebp-9Ch]
  float v9; // [esp+1Ch] [ebp-94h]
  __m128 v10; // [esp+20h] [ebp-90h]
  __int128 v11; // [esp+30h] [ebp-80h]
  _BYTE v12[32]; // [esp+40h] [ebp-70h]
  DirectX::XMMATRIX M2; // [esp+70h] [ebp-40h] BYREF

  v2 = (const __m128i *)this->placeHolders._Myfirst;
  for ( i = this->placeHolders._Mylast; v2 != (const __m128i *)i; v2 += 5 )
  {
    v8 = v2->m128i_i32[0];
    if ( v2->m128i_i32[0] )
    {
      v9 = __libm_sse2_cosf(v6, v7).m128_f32[0];
      v4 = __libm_sse2_sinf().m128_f32[0];
      v10.m128_i32[3] = 0;
      HIDWORD(v11) = 0;
      *(_OWORD *)&v12[12] = 0i64;
      *(_DWORD *)&v12[28] = 1065353216;
      v5 = (float)(1.0 - v9) * 0.0;
      *(float *)&v12[8] = (float)(1.0 - v9) + v9;
      *((float *)&v11 + 1) = v5 + v9;
      v10.m128_f32[0] = v5 + v9;
      v10.m128_f32[1] = v4 + v5;
      *(float *)&v11 = v5 - v4;
      v10.m128_f32[2] = v5 - (float)(v4 * 0.0);
      *(float *)v12 = (float)(v4 * 0.0) + v5;
      *((float *)&v11 + 2) = *(float *)v12;
      *(float *)&v12[4] = v10.m128_f32[2];
      M2.r[0] = (__m128)_mm_loadu_si128(v2 + 1);
      M2.r[1] = (__m128)_mm_loadu_si128(v2 + 2);
      M2.r[2] = (__m128)_mm_loadu_si128(v2 + 3);
      M2.r[3] = (__m128)_mm_loadu_si128(v2 + 4);
      *(__m128 *)(v8 + 4) = DirectX::XMMatrixMultiply(M2.r, v10);
      *(_OWORD *)(v8 + 20) = v11;
      *(_OWORD *)(v8 + 36) = *(_OWORD *)v12;
      *(_OWORD *)(v8 + 52) = *(_OWORD *)&v12[16];
    }
  }
}
void __userpurge AnalogInstruments::updateRPM(AnalogInstruments *this@<ecx>, int a2@<edi>, int a3@<esi>, float dt)
{
  float v4; // xmm1_4
  float v6; // xmm3_4
  bool v7; // zf
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float *v12; // ecx
  float *v13; // eax
  float v14; // xmm0_4
  Node *v15; // edi
  float v16; // xmm1_4
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __int128 v21; // xmm2
  __int128 v22; // xmm1
  __int128 v23; // xmm3
  Node *v24; // edi
  __m128 v25; // xmm3
  __int128 v26; // xmm3
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __int128 v30; // xmm1
  __int128 v31; // xmm2
  float v34; // [esp+14h] [ebp-90h] BYREF
  float v35; // [esp+18h] [ebp-8Ch]
  float ref; // [esp+1Ch] [ebp-88h]
  float v37; // [esp+20h] [ebp-84h]
  mat44f v38; // [esp+24h] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+64h] [ebp-40h] BYREF

  v4 = dt * 10.0;
  v6 = this->currentRPM;
  ref = 0.0;
  if ( (float)(dt * 10.0) <= 1.0 )
  {
    if ( v4 < 0.0 )
      v4 = 0.0;
  }
  else
  {
    v4 = FLOAT_1_0;
  }
  v7 = this->rpm.target == 0;
  v8 = (float)((float)(this->car->physicsState.engineRPM - v6) * v4) + v6;
  this->currentRPM = v8;
  if ( !v7 )
  {
    v9 = FLOAT_40000_0;
    v10 = this->rpm.min;
    ref = FLOAT_40000_0;
    if ( v8 <= 40000.0 )
    {
      if ( v10 <= v8 )
        v9 = v8;
      else
        v9 = v10;
      ref = v9;
    }
    v11 = this->maxRPMRecorded;
    v12 = &this->maxRPMRecorded;
    v13 = &v34;
    v34 = v9;
    if ( v11 > v9 )
      v13 = &this->maxRPMRecorded;
    *v12 = *v13;
  }
  v35 = 0.0;
  v34 = 0.0;
  if ( Curve::getCount(&this->rpmLut) )
  {
    if ( this->rpm.target )
      v35 = Curve::getValue(&this->rpmLut, ref);
    if ( this->rpmMax.target )
    {
      v34 = Curve::getValue(&this->rpmLut, this->maxRPMRecorded);
      v14 = v34;
LABEL_23:
      v34 = v14;
      goto LABEL_24;
    }
  }
  else
  {
    if ( this->rpm.target )
      v35 = (float)((float)(ref - this->rpm.min) * this->rpm.step) + this->rpm.zero;
    if ( this->rpmMax.target )
    {
      v14 = (float)((float)(this->maxRPMRecorded - this->rpm.min) * this->rpm.step) + this->rpm.zero;
      goto LABEL_23;
    }
  }
LABEL_24:
  v15 = this->rpm.target;
  v16 = FLOAT_0_017453;
  if ( v15 )
  {
    v35 = v35 * 0.017453;
    LODWORD(ref) = __libm_sse2_cosf(a2, a3).m128_u32[0];
    LODWORD(v37) = __libm_sse2_sinf().m128_u32[0];
    v35 = 1.0 - ref;
    mat44f::mat44f(&v38);
    v38.M44 = 1.0;
    v17 = *(__m128 *)&this->rpm.baseMatrix.M31;
    v38.M33 = v35 + ref;
    M2.r[2] = v17;
    v38.M22 = (float)(v35 * 0.0) + ref;
    v38.M11 = v38.M22;
    v38.M12 = v37 + (float)(v35 * 0.0);
    v38.M21 = (float)(v35 * 0.0) - v37;
    v38.M13 = (float)(v35 * 0.0) - (float)(v37 * 0.0);
    v38.M31 = (float)(v37 * 0.0) + (float)(v35 * 0.0);
    v18 = *(__m128 *)&this->rpm.baseMatrix.M21;
    v38.M23 = v38.M31;
    v19 = *(__m128 *)&this->rpm.baseMatrix.M11;
    v38.M32 = v38.M13;
    v20 = *(__m128 *)&this->rpm.baseMatrix.M41;
    v21 = *(_OWORD *)&v38.M31;
    M2.r[0] = v19;
    M2.r[1] = v18;
    v22 = *(_OWORD *)&v38.M21;
    M2.r[3] = v20;
    v23 = *(_OWORD *)&v38.M41;
    *(__m128 *)&v15->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v38.M11);
    *(_OWORD *)&v15->matrix.M21 = v22;
    v16 = FLOAT_0_017453;
    *(_OWORD *)&v15->matrix.M31 = v21;
    *(_OWORD *)&v15->matrix.M41 = v23;
  }
  v24 = this->rpmMax.target;
  if ( v24 )
  {
    v34 = v34 * v16;
    LODWORD(v35) = __libm_sse2_cosf(a2, a3).m128_u32[0];
    LODWORD(v34) = __libm_sse2_sinf().m128_u32[0];
    v37 = 1.0 - v35;
    mat44f::mat44f(&v38);
    v38.M44 = 1.0;
    v38.M33 = v37 + v35;
    v38.M22 = (float)(v37 * 0.0) + v35;
    v38.M11 = v38.M22;
    v38.M12 = v34 + (float)(v37 * 0.0);
    v25 = *(__m128 *)&this->rpmMax.baseMatrix.M41;
    v38.M21 = (float)(v37 * 0.0) - v34;
    M2.r[3] = v25;
    v26 = *(_OWORD *)&v38.M41;
    v38.M13 = (float)(v37 * 0.0) - (float)(v34 * 0.0);
    v38.M31 = (float)(v34 * 0.0) + (float)(v37 * 0.0);
    v27 = *(__m128 *)&this->rpmMax.baseMatrix.M21;
    v38.M23 = v38.M31;
    v28 = *(__m128 *)&this->rpmMax.baseMatrix.M11;
    v38.M32 = v38.M13;
    v29 = *(__m128 *)&this->rpmMax.baseMatrix.M31;
    M2.r[0] = v28;
    M2.r[1] = v27;
    v30 = *(_OWORD *)&v38.M21;
    M2.r[2] = v29;
    v31 = *(_OWORD *)&v38.M31;
    *(__m128 *)&v24->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v38.M11);
    *(_OWORD *)&v24->matrix.M21 = v30;
    *(_OWORD *)&v24->matrix.M31 = v31;
    *(_OWORD *)&v24->matrix.M41 = v26;
  }
}
void __userpurge AnalogInstruments::updateSpeed(AnalogInstruments *this@<ecx>, int a2@<edi>, float dt)
{
  float v4; // xmm0_4
  float v5; // xmm4_4
  mat44f *v6; // [esp-8h] [ebp-60h]
  int v7; // [esp+8h] [ebp-50h]
  float ref; // [esp+10h] [ebp-48h]
  float v9; // [esp+10h] [ebp-48h]
  mat44f matrix1; // [esp+18h] [ebp-40h] BYREF

  if ( this->speed.target )
  {
    ref = this->car->physicsState.speed.value * 3.5999999;
    if ( Curve::getCount(&this->speedLut) )
      Curve::getValue(&this->speedLut, ref);
    v9 = __libm_sse2_cosf(a2, v7).m128_f32[0];
    v4 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f(&matrix1);
    matrix1.M33 = (float)(1.0 - v9) + v9;
    matrix1.M44 = 1.0;
    v5 = (float)(1.0 - v9) * 0.0;
    v6 = &this->speed.target->matrix;
    matrix1.M22 = v5 + v9;
    matrix1.M11 = v5 + v9;
    matrix1.M12 = v4 + v5;
    matrix1.M21 = v5 - v4;
    matrix1.M13 = v5 - (float)(v4 * 0.0);
    matrix1.M31 = (float)(v4 * 0.0) + v5;
    matrix1.M23 = matrix1.M31;
    matrix1.M32 = matrix1.M13;
    mul(v6, &matrix1, &this->speed.baseMatrix);
  }
}
void AnalogInstruments::updateTurbo(AnalogInstruments *this, float dt)
{
  unsigned int v3; // ecx
  int v4; // esi
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm2_4
  AnalogNeedle *v10; // edx
  float v11; // xmm0_4
  float *v12; // eax
  float *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm0_4
  AnalogNeedle *v16; // eax
  float v17; // xmm1_4
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __int128 v20; // xmm3
  float v21; // xmm4_4
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __int128 v24; // xmm2
  __int128 v25; // xmm1
  __m128 v26; // xmm0
  float v27; // eax
  std::pair<float,float> *v28; // edx
  float v29; // xmm0_4
  float v30; // xmm1_4
  float *v31; // ecx
  float *v32; // eax
  unsigned int v33; // edx
  float v34; // xmm0_4
  AnalogNeedle *v35; // eax
  int v36; // esi
  float v37; // xmm1_4
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __int128 v40; // xmm3
  float v41; // xmm4_4
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __int128 v44; // xmm2
  __int128 v45; // xmm1
  int v46; // ecx
  int v47; // edx
  int v48; // [esp+0h] [ebp-E0h]
  int v49; // [esp+4h] [ebp-DCh]
  float v50; // [esp+Ch] [ebp-D4h] BYREF
  float v51; // [esp+10h] [ebp-D0h] BYREF
  unsigned int v52; // [esp+14h] [ebp-CCh]
  float v53; // [esp+18h] [ebp-C8h]
  int v54; // [esp+1Ch] [ebp-C4h]
  __m128 v55; // [esp+20h] [ebp-C0h]
  __int128 v56; // [esp+30h] [ebp-B0h]
  _BYTE v57[32]; // [esp+40h] [ebp-A0h]
  DirectX::XMMATRIX M2; // [esp+60h] [ebp-80h] BYREF
  DirectX::XMMATRIX v59; // [esp+A0h] [ebp-40h] BYREF
  float dta; // [esp+E8h] [ebp+8h]

  v3 = 0;
  v52 = 0;
  if ( this->turbos._Mylast - this->turbos._Myfirst )
  {
    v4 = 0;
    v5 = dt * 10.0;
    v54 = 0;
    v6 = FLOAT_1_0;
    v7 = FLOAT_0_017453;
    v8 = FLOAT_100_0;
    dta = dt * 10.0;
    do
    {
      if ( v5 <= v6 )
      {
        if ( v5 >= 0.0 )
          v9 = v5;
        else
          v9 = 0.0;
      }
      else
      {
        v9 = v6;
      }
      this->turboValues._Myfirst[v3].first = (float)((float)(this->car->physicsState.turboBoost
                                                           - this->turboValues._Myfirst[v3].first)
                                                   * v9)
                                           + this->turboValues._Myfirst[v3].first;
      v10 = this->turbos._Myfirst;
      v53 = *(float *)((char *)&v10->target + v4);
      if ( v53 != 0.0 )
      {
        v11 = this->car->physicsState.turboBoost;
        if ( this->turboUseBar )
        {
          v50 = 0.0;
          v12 = &v50;
          v13 = &v51;
          v14 = (float)(v11 + v6) - *(float *)((char *)&v10->min + v4);
          v51 = v14;
        }
        else
        {
          v14 = v11 - *(float *)((char *)&v10->min + v4);
          v51 = 0.0;
          v12 = &v51;
          v13 = &v50;
          v50 = v14;
        }
        if ( v14 >= 0.0 )
          v12 = v13;
        v51 = (float)((float)(*(float *)((char *)&v10->step + v4) * *v12) + *(float *)((char *)&v10->zero + v4)) * v7;
        LODWORD(v50) = __libm_sse2_cosf(v48, v49).m128_u32[0];
        v15 = __libm_sse2_sinf().m128_f32[0];
        v16 = this->turbos._Myfirst;
        v55.m128_i32[3] = 0;
        *(_OWORD *)&v57[12] = 0i64;
        HIDWORD(v56) = 0;
        *(_DWORD *)&v57[28] = 1065353216;
        v17 = (float)(1.0 - v50) * 0.0;
        *(float *)&v57[8] = (float)(1.0 - v50) + v50;
        v18 = *(__m128 *)((char *)&v16->baseMatrix.M31 + v4);
        v19 = *(__m128 *)((char *)&v16->baseMatrix.M41 + v4);
        *((float *)&v56 + 1) = v17 + v50;
        v55.m128_f32[0] = v17 + v50;
        M2.r[2] = v18;
        M2.r[3] = v19;
        v20 = *(_OWORD *)&v57[16];
        v55.m128_f32[1] = v15 + v17;
        v21 = v15 * 0.0;
        *(float *)&v56 = v17 - v15;
        v55.m128_f32[2] = v17 - (float)(v15 * 0.0);
        *(float *)v57 = (float)(v15 * 0.0) + v17;
        *((float *)&v56 + 2) = *(float *)v57;
        v22 = *(__m128 *)((char *)&v16->baseMatrix.M11 + v4);
        *(float *)&v57[4] = v17 - v21;
        v23 = *(__m128 *)((char *)&v16->baseMatrix.M21 + v4);
        v24 = *(_OWORD *)v57;
        M2.r[0] = v22;
        M2.r[1] = v23;
        v25 = v56;
        v26 = DirectX::XMMatrixMultiply(M2.r, v55);
        v27 = v53;
        v8 = FLOAT_100_0;
        v7 = FLOAT_0_017453;
        v3 = v52;
        *(__m128 *)(LODWORD(v53) + 4) = v26;
        *(_OWORD *)(LODWORD(v27) + 20) = v25;
        *(_OWORD *)(LODWORD(v27) + 36) = v24;
        *(_OWORD *)(LODWORD(v27) + 52) = v20;
      }
      if ( *(Node **)((char *)&this->turboLimiters._Myfirst->target + v4) )
      {
        v28 = this->turboValues._Myfirst;
        v29 = v28[v3].first;
        v30 = *(float *)((char *)&this->turbos._Myfirst->min + v4);
        if ( v29 <= v8 )
        {
          if ( v30 <= v29 )
            v30 = v28[v3].first;
        }
        else
        {
          v30 = v8;
        }
        v50 = v30;
        v31 = &v28[v3].second;
        v32 = &v50;
        v33 = v52;
        if ( *v31 > v30 )
          v32 = v31;
        *v31 = *v32;
        v53 = (float)((float)(this->turboValues._Myfirst[v33].second
                            * *(float *)((char *)&this->turbos._Myfirst->step + v4))
                    + *(float *)((char *)&this->turbos._Myfirst->zero + v4))
            * v7;
        LODWORD(v51) = __libm_sse2_cosf(v48, v49).m128_u32[0];
        v34 = __libm_sse2_sinf().m128_f32[0];
        v35 = this->turboLimiters._Myfirst;
        *(_OWORD *)&v57[12] = 0i64;
        v55.m128_i32[3] = 0;
        v36 = *(int *)((char *)&v35->target + v4);
        HIDWORD(v56) = 0;
        v37 = (float)(1.0 - v51) * 0.0;
        *(_DWORD *)&v57[28] = 1065353216;
        *(float *)&v57[8] = (float)(1.0 - v51) + v51;
        v38 = *(__m128 *)((char *)&v35->baseMatrix.M31 + v54);
        v39 = *(__m128 *)((char *)&v35->baseMatrix.M41 + v54);
        *((float *)&v56 + 1) = v37 + v51;
        v55.m128_f32[0] = v37 + v51;
        v59.r[2] = v38;
        v59.r[3] = v39;
        v40 = *(_OWORD *)&v57[16];
        v55.m128_f32[1] = v34 + v37;
        v41 = v34 * 0.0;
        *(float *)&v56 = v37 - v34;
        v55.m128_f32[2] = v37 - (float)(v34 * 0.0);
        *(float *)v57 = (float)(v34 * 0.0) + v37;
        *((float *)&v56 + 2) = *(float *)v57;
        v42 = *(__m128 *)((char *)&v35->baseMatrix.M11 + v54);
        *(float *)&v57[4] = v37 - v41;
        v43 = *(__m128 *)((char *)&v35->baseMatrix.M21 + v54);
        v44 = *(_OWORD *)v57;
        v59.r[0] = v42;
        v59.r[1] = v43;
        v45 = v56;
        *(__m128 *)(v36 + 4) = DirectX::XMMatrixMultiply(v59.r, v55);
        *(_OWORD *)(v36 + 20) = v45;
        *(_OWORD *)(v36 + 36) = v44;
        *(_OWORD *)(v36 + 52) = v40;
        v4 = v54;
      }
      v46 = (char *)this->turbos._Mylast - (char *)this->turbos._Myfirst;
      v4 += 80;
      ++v52;
      v5 = dta;
      v6 = FLOAT_1_0;
      v8 = FLOAT_100_0;
      v7 = FLOAT_0_017453;
      v47 = (unsigned __int64)(1717986919i64 * v46) >> 32;
      v3 = v52;
      v54 = v4;
    }
    while ( v52 < (v47 >> 5) + ((unsigned int)v47 >> 31) );
  }
}
void __userpurge AnalogInstruments::updateWater(AnalogInstruments *this@<ecx>, int a2@<ebx>, int a3@<edi>, float dt)
{
  float *v5; // eax
  float *v6; // edx
  Curve *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm4_4
  mat44f *v10; // [esp-8h] [ebp-64h]
  float ref; // [esp+10h] [ebp-4Ch]
  float v12; // [esp+14h] [ebp-48h]
  mat44f matrix1; // [esp+1Ch] [ebp-40h] BYREF

  if ( this->water.target )
  {
    v5 = &this->water.min;
    v6 = &this->car->physicsState.water;
    v7 = &this->waterLut;
    if ( *v6 > this->water.min )
      v5 = v6;
    ref = *v5;
    if ( Curve::getCount(v7) )
      Curve::getValue(&this->waterLut, ref);
    v12 = __libm_sse2_cosf(a3, a2).m128_f32[0];
    v8 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f(&matrix1);
    matrix1.M33 = (float)(1.0 - v12) + v12;
    matrix1.M44 = 1.0;
    v9 = (float)(1.0 - v12) * 0.0;
    v10 = &this->water.target->matrix;
    matrix1.M22 = v9 + v12;
    matrix1.M11 = v9 + v12;
    matrix1.M12 = v8 + v9;
    matrix1.M21 = v9 - v8;
    matrix1.M13 = v9 - (float)(v8 * 0.0);
    matrix1.M31 = (float)(v8 * 0.0) + v9;
    matrix1.M23 = matrix1.M31;
    matrix1.M32 = matrix1.M13;
    mul(v10, &matrix1, &this->water.baseMatrix);
  }
}
