#include "aeromap.h
void AeroMap::AeroMap(AeroMap *this)
{
  this->referenceArea = 0.0;
  this->CD = 0.0;
  this->CL = 0.0;
  this->frontShare = 0.0;
  this->CDX = 0.0;
  this->CDY = 0.0;
  this->CDA = 0.0;
  this->carBody = 0;
  this->dynamicCD = 0.0;
  this->dynamicCL = 0.0;
  this->airDensity = 0.0;
  this->frontApplicationPoint.x = 0.0;
  this->frontApplicationPoint.y = 0.0;
  this->frontApplicationPoint.z = 0.0;
  this->wings._Myfirst = 0;
  this->wings._Mylast = 0;
  this->wings._Myend = 0;
  this->rearApplicationPoint.x = 0.0;
  this->rearApplicationPoint.y = 0.0;
  this->rearApplicationPoint.z = 0.0;
  this->car = 0;
}
void AeroMap::~AeroMap(AeroMap *this)
{
  std::vector<Wing>::_Tidy(&this->wings);
}
void AeroMap::addDrag(AeroMap *this, const vec3f *lv)
{
  float v3; // xmm4_4
  float v4; // eax
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  IRigidBody *v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  IRigidBody *v20; // ecx
  float v21; // [esp+8h] [ebp-18h] BYREF
  float v22; // [esp+Ch] [ebp-14h]
  float v23; // [esp+10h] [ebp-10h]
  __int64 v24; // [esp+14h] [ebp-Ch] BYREF
  float v25; // [esp+1Ch] [ebp-4h]

  v3 = (float)((float)(lv->x * lv->x) + (float)(lv->y * lv->y)) + (float)(lv->z * lv->z);
  if ( v3 != 0.0 )
  {
    v4 = lv->z;
    v24 = *(_QWORD *)&lv->x;
    v5 = *((float *)&v24 + 1);
    v6 = *(float *)&v24;
    v25 = v4;
    v7 = v4;
    v8 = fsqrt((float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v7 * v7));
    if ( v8 != 0.0 )
    {
      v6 = (float)(1.0 / v8) * *(float *)&v24;
      v5 = (float)(1.0 / v8) * *((float *)&v24 + 1);
      v7 = (float)(1.0 / v8) * v4;
    }
    v9 = this->CD;
    v10 = this->carBody;
    v11 = (float)((float)(COERCE_FLOAT(LODWORD(v5) & _xmm) * v9) * this->CDY)
        + (float)((float)((float)(COERCE_FLOAT(LODWORD(v6) & _xmm) * v9) * this->CDX) + v9);
    this->dynamicCD = v11;
    LODWORD(v12) = COERCE_UNSIGNED_INT((float)((float)((float)(v11 * v3) * this->airDensity) * this->referenceArea) * 0.5) ^ _xmm;
    v23 = v7 * v12;
    v21 = v12 * v6;
    v22 = v12 * v5;
    v10->addLocalForce(v10, (const vec3f *)&v21);
    this->carBody->getAngularVelocity(this->carBody, (vec3f *)&v24);
    v13 = *(float *)&v24;
    v14 = *((float *)&v24 + 1);
    v15 = v25;
    v16 = (float)((float)(v13 * v13) + (float)(v14 * v14)) + (float)(v15 * v15);
    if ( v16 != 0.0 )
    {
      v17 = fsqrt(v16);
      if ( v17 != 0.0 )
      {
        v13 = (float)(1.0 / v17) * *(float *)&v24;
        v14 = (float)(1.0 / v17) * *((float *)&v24 + 1);
        *(float *)&v24 = v13;
        *((float *)&v24 + 1) = v14;
        v15 = (float)(1.0 / v17) * v25;
        v25 = v15;
      }
      LODWORD(v18) = LODWORD(v16) ^ _xmm;
      v19 = this->CDA;
      v20 = this->carBody;
      v21 = (float)(v13 * v18) * v19;
      v22 = (float)(v14 * v18) * v19;
      v23 = (float)(v15 * v18) * v19;
      v20->addLocalTorque(v20, (const vec3f *)&v21);
    }
  }
}
void AeroMap::addLift(AeroMap *this, const vec3f *localVelocity)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  IRigidBody *v6; // ecx
  float v7; // xmm0_4
  IRigidBody *v8; // ecx
  int v9; // [esp+8h] [ebp-Ch] BYREF
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v3 = localVelocity->z * localVelocity->z;
  v4 = (float)((float)((float)(this->CL * v3) * this->airDensity) * this->referenceArea) * 0.5;
  if ( v3 != 0.0 )
  {
    v5 = this->frontShare;
    v6 = this->carBody;
    v9 = 0;
    v11 = 0;
    v10 = COERCE_UNSIGNED_INT(v5 * v4) ^ _xmm;
    v6->addLocalForceAtLocalPos(v6, (const vec3f *)&v9, &this->frontApplicationPoint);
    v7 = 1.0 - this->frontShare;
    v8 = this->carBody;
    v9 = 0;
    v11 = 0;
    v10 = COERCE_UNSIGNED_INT(v7 * v4) ^ _xmm;
    v8->addLocalForceAtLocalPos(v8, (const vec3f *)&v9, &this->rearApplicationPoint);
  }
}
double AeroMap::getCurrentDragKG(AeroMap *this)
{
  Wing *v1; // edx
  float v2; // xmm1_4
  Wing *v3; // eax
  float l; // [esp+0h] [ebp-4h]

  v1 = this->wings._Mylast;
  v2 = 0.0;
  v3 = this->wings._Myfirst;
  l = 0.0;
  if ( v3 != v1 )
  {
    do
    {
      v2 = v2 + v3->status.dragKG;
      ++v3;
    }
    while ( v3 != v1 );
    l = v2;
  }
  return l;
}
double AeroMap::getCurrentLiftKG(AeroMap *this)
{
  Wing *v1; // edx
  float v2; // xmm1_4
  Wing *v3; // eax
  float l; // [esp+0h] [ebp-4h]

  v1 = this->wings._Mylast;
  v2 = 0.0;
  v3 = this->wings._Myfirst;
  l = 0.0;
  if ( v3 != v1 )
  {
    do
    {
      v2 = v2 + v3->status.liftKG;
      ++v3;
    }
    while ( v3 != v1 );
    l = v2;
  }
  return l;
}
std::vector<WingState> *AeroMap::getWingStatus(AeroMap *this, std::vector<WingState> *result)
{
  Wing *v2; // edi
  Wing *v3; // esi
  __m128i v4; // xmm0
  double v5; // st7
  WingState st; // [esp+14h] [ebp-50h] BYREF
  int i; // [esp+60h] [ebp-4h]

  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v2 = this->wings._Mylast;
  v3 = this->wings._Myfirst;
  for ( i = 0; v3 != v2; ++v3 )
  {
    v4 = _mm_loadu_si128((const __m128i *)&v3->status);
    st.liftVector.z = v3->status.liftVector.z;
    *(__m128i *)&st.aoa = v4;
    *(__m128i *)&st.inputAngle = _mm_loadu_si128((const __m128i *)&v3->status.inputAngle);
    *(__m128i *)&st.liftKG = _mm_loadu_si128((const __m128i *)&v3->status.liftKG);
    *(__m128i *)&st.yawAngle = _mm_loadu_si128((const __m128i *)&v3->status.yawAngle);
    v5 = Wing::getCurrentModifiedAngle(v3);
    st.isVertical = v3->data.isVertical;
    st.angle = v5;
    std::vector<WingState>::push_back(result, &st);
  }
  return result;
}
void AeroMap::init(AeroMap *this, Car *a_car, const vec3f *frontAP, const vec3f *rearAP, std::wstring dataPath)
{
  this->car = a_car;
  this->carBody = a_car->body;
  this->CDY = 0.0;
  this->CDX = 0.0;
  this->dynamicCD = 0.0;
  this->dynamicCL = 0.0;
  this->CDA = 0.1;
  this->referenceArea = 1.0;
  this->CD = 0.0;
  this->CL = 0.0;
  this->frontShare = 0.5;
  this->airDensity = 1.221;
  AeroMap::loadINI(this, &dataPath);
  if ( dataPath._Myres >= 8 )
    operator delete(dataPath._Bx._Ptr);
}
void AeroMap::loadINI(AeroMap *this, const std::wstring *dataPath)
{
  int v3; // esi
  const std::wstring *v4; // eax
  Car *v5; // ecx
  const std::wstring *v6; // eax
  bool v7; // bl
  int v8; // ebx
  std::wstring *v9; // eax
  std::wostream *v10; // eax
  std::wstring *v11; // esi
  Wing *v12; // eax
  int v13; // eax
  int v14; // ebx
  std::wstring *v15; // eax
  std::wostream *v16; // eax
  std::wstring *v17; // esi
  Wing *v18; // eax
  int v19; // eax
  bool v20; // al
  bool v21; // bl
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  bool v24; // cf
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  bool v30; // bl
  std::wstring *v31; // eax
  std::wstring *v32; // eax
  int v33; // ebx
  std::wostream *v34; // eax
  const std::wstring *v35; // eax
  bool v36; // al
  const std::wstring *v37; // eax
  unsigned int v38; // esi
  int v39; // ecx
  const std::wstring *v40; // eax
  int v41; // esi
  std::vector<DynamicWingController> *v42; // ecx
  DynamicWingController *v43; // eax
  Wing *v44; // eax
  std::wstring *v45; // eax
  int v46; // [esp+20h] [ebp-5B0h]
  bool v47; // [esp+27h] [ebp-5A9h]
  _BYTE *v48; // [esp+2Ch] [ebp-5A4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v49; // [esp+30h] [ebp-5A0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v50; // [esp+E0h] [ebp-4F0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v51; // [esp+190h] [ebp-440h] BYREF
  std::wstring key; // [esp+240h] [ebp-390h] BYREF
  std::wstring section; // [esp+258h] [ebp-378h] BYREF
  std::wstring v54; // [esp+270h] [ebp-360h] BYREF
  std::wstring wing; // [esp+288h] [ebp-348h] BYREF
  std::wstring _Ptr; // [esp+2A0h] [ebp-330h] BYREF
  INIReader r; // [esp+2B8h] [ebp-318h] BYREF
  std::wstring v58; // [esp+2FCh] [ebp-2D4h] BYREF
  std::wstring result; // [esp+314h] [ebp-2BCh] BYREF
  std::wstring v60; // [esp+32Ch] [ebp-2A4h] BYREF
  DynamicWingController v61; // [esp+344h] [ebp-28Ch] BYREF
  Wing v62; // [esp+3B0h] [ebp-220h] BYREF
  int v63; // [esp+5CCh] [ebp-4h]

  v3 = 0;
  v4 = std::operator+<wchar_t>(&result, dataPath, L"aero.ini");
  v5 = this->car;
  v63 = 0;
  v6 = Car::getConfigPath(v5, &v58, v4);
  LOBYTE(v63) = 1;
  INIReader::INIReader(&r, v6);
  if ( v58._Myres >= 8 )
    operator delete(v58._Bx._Ptr);
  v58._Myres = 7;
  v58._Mysize = 0;
  v58._Bx._Buf[0] = 0;
  LOBYTE(v63) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SLIPSTREAM", 0xAu);
  LOBYTE(v63) = 5;
  v7 = INIReader::hasSection(&r, &section);
  LOBYTE(v63) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v7 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"EFFECT_GAIN_MULT", 0x10u);
    LOBYTE(v63) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SLIPSTREAM", 0xAu);
    LOBYTE(v63) = 7;
    this->car->slipStream.effectGainMult = INIReader::getFloat(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v63) = 4;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SPEED_FACTOR_MULT", 0x11u);
    LOBYTE(v63) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SLIPSTREAM", 0xAu);
    LOBYTE(v63) = 9;
    this->car->slipStream.speedFactorMult = INIReader::getFloat(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v8 = 0;
  v48 = &v50.gap10[8];
  while ( 1 )
  {
    wing._Myres = 7;
    wing._Mysize = 0;
    wing._Bx._Buf[0] = 0;
    LOBYTE(v63) = 10;
    *(_DWORD *)v50.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v50.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v50.gap68);
    LOBYTE(v63) = 11;
    v46 = v3 | 1;
    std::wiostream::basic_iostream<wchar_t>(&v50, &v50.gap10[8], 0);
    v63 = 12;
    *(_DWORD *)&v50.gap0[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v49.gap68[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v50.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v50.gap10[8]);
    v9 = &wing;
    if ( wing._Myres >= 8 )
      v9 = (std::wstring *)wing._Bx._Ptr;
    LOBYTE(v63) = 13;
    *(_DWORD *)&v50.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Init((std::wstringbuf *)&v50.gap10[8], v9->_Bx._Buf, wing._Mysize, 0);
    LOBYTE(v63) = 14;
    v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v50.gap10, "WING_");
    std::wostream::operator<<(v10, v8);
    v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v50, &v54);
    if ( &wing != v11 )
    {
      if ( wing._Myres >= 8 )
        operator delete(wing._Bx._Ptr);
      wing._Myres = 7;
      wing._Mysize = 0;
      wing._Bx._Buf[0] = 0;
      if ( v11->_Myres >= 8 )
      {
        wing._Bx._Ptr = v11->_Bx._Ptr;
        v11->_Bx._Ptr = 0;
      }
      else if ( v11->_Mysize != -1 )
      {
        _memmove(&wing, v11, 2 * (v11->_Mysize + 1));
      }
      wing._Mysize = v11->_Mysize;
      wing._Myres = v11->_Myres;
      v11->_Myres = 7;
      v11->_Mysize = 0;
      v11->_Bx._Buf[0] = 0;
    }
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    if ( !INIReader::hasSection(&r, &wing) )
      break;
    Wing::Wing(&v62, this->car, &r, v8, 0);
    LOBYTE(v63) = 15;
    std::vector<Wing>::push_back(&this->wings, v12);
    LOBYTE(v63) = 14;
    Wing::~Wing(&v62);
    ++v8;
    LOBYTE(v63) = 10;
    *(_DWORD *)&v50.gap0[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v49.gap68[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v50.gap0 + 4) - 104;
    *(_DWORD *)&v50.gap10[8] = &std::wstringbuf::`vftable';
    if ( (v50.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v50.gap10[8]) )
        std::wstreambuf::epptr(&v50.gap10[8]);
      else
        std::wstreambuf::egptr(&v50.gap10[8]);
      std::wstreambuf::eback(&v50.gap10[8]);
      v13 = std::wstreambuf::eback(&v50.gap10[8]);
      operator delete(v13);
    }
    std::wstreambuf::setg(&v50.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v50.gap10[8], 0, 0);
    *(_DWORD *)&v50.gap10[68] &= 0xFFFFFFFE;
    *(_DWORD *)&v50.gap10[64] = 0;
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v50.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v50.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v50.gap68);
    v3 = v46;
    if ( wing._Myres >= 8 )
      operator delete(wing._Bx._Ptr);
  }
  LOBYTE(v63) = 10;
  *(_DWORD *)&v50.gap0[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v49.gap68[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v50.gap0 + 4) - 104;
  *(_DWORD *)&v50.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v50.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v50.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v50.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v50.gap68);
  if ( wing._Myres >= 8 )
    operator delete(wing._Bx._Ptr);
  v14 = 0;
  v48 = &v49.gap10[8];
  while ( 1 )
  {
    _Ptr._Myres = 7;
    _Ptr._Mysize = 0;
    _Ptr._Bx._Buf[0] = 0;
    LOBYTE(v63) = 16;
    *(_DWORD *)v49.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v49.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v49.gap68);
    v46 |= 2u;
    LOBYTE(v63) = 17;
    std::wiostream::basic_iostream<wchar_t>(&v49, &v49.gap10[8], 0);
    v63 = 18;
    *(_DWORD *)&v49.gap0[*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_BYTE **)((char *)&v48 + *(_DWORD *)(*(_DWORD *)v49.gap0 + 4)) = (_BYTE *)(*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)
                                                                               - 104);
    std::wstreambuf::wstreambuf(&v49.gap10[8]);
    v15 = &_Ptr;
    if ( _Ptr._Myres >= 8 )
      v15 = (std::wstring *)_Ptr._Bx._Ptr;
    LOBYTE(v63) = 19;
    *(_DWORD *)&v49.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Init((std::wstringbuf *)&v49.gap10[8], v15->_Bx._Buf, _Ptr._Mysize, 0);
    LOBYTE(v63) = 20;
    v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v49.gap10, "FIN_");
    std::wostream::operator<<(v16, v14);
    v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v49, &v54);
    if ( &_Ptr != v17 )
    {
      if ( _Ptr._Myres >= 8 )
        operator delete(_Ptr._Bx._Ptr);
      _Ptr._Myres = 7;
      _Ptr._Mysize = 0;
      _Ptr._Bx._Buf[0] = 0;
      if ( v17->_Myres >= 8 )
      {
        _Ptr._Bx._Ptr = v17->_Bx._Ptr;
        v17->_Bx._Ptr = 0;
      }
      else if ( v17->_Mysize != -1 )
      {
        _memmove(&_Ptr, v17, 2 * (v17->_Mysize + 1));
      }
      _Ptr._Mysize = v17->_Mysize;
      _Ptr._Myres = v17->_Myres;
      v17->_Myres = 7;
      v17->_Mysize = 0;
      v17->_Bx._Buf[0] = 0;
    }
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    if ( !INIReader::hasSection(&r, &_Ptr) )
      break;
    Wing::Wing(&v62, this->car, &r, v14, 1);
    LOBYTE(v63) = 21;
    std::vector<Wing>::push_back(&this->wings, v18);
    LOBYTE(v63) = 20;
    Wing::~Wing(&v62);
    ++v14;
    LOBYTE(v63) = 16;
    *(_DWORD *)&v49.gap0[*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_BYTE **)((char *)&v48 + *(_DWORD *)(*(_DWORD *)v49.gap0 + 4)) = (_BYTE *)(*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)
                                                                               - 104);
    *(_DWORD *)&v49.gap10[8] = &std::wstringbuf::`vftable';
    if ( (v49.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v49.gap10[8]) )
        std::wstreambuf::epptr(&v49.gap10[8]);
      else
        std::wstreambuf::egptr(&v49.gap10[8]);
      std::wstreambuf::eback(&v49.gap10[8]);
      v19 = std::wstreambuf::eback(&v49.gap10[8]);
      operator delete(v19);
    }
    std::wstreambuf::setg(&v49.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v49.gap10[8], 0, 0);
    *(_DWORD *)&v49.gap10[68] &= 0xFFFFFFFE;
    *(_DWORD *)&v49.gap10[64] = 0;
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v49.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v49.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v49.gap68);
    if ( _Ptr._Myres >= 8 )
      operator delete(_Ptr._Bx._Ptr);
  }
  LOBYTE(v63) = 16;
  *(_DWORD *)&v49.gap0[*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_BYTE **)((char *)&v48 + *(_DWORD *)(*(_DWORD *)v49.gap0 + 4)) = (_BYTE *)(*(_DWORD *)(*(_DWORD *)v49.gap0 + 4) - 104);
  *(_DWORD *)&v49.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v49.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v49.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v49.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v49.gap68);
  LOBYTE(v63) = 4;
  if ( _Ptr._Myres >= 8 )
    operator delete(_Ptr._Bx._Ptr);
  if ( this->wings._Myfirst == this->wings._Mylast )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DATA", 4u);
    LOBYTE(v63) = 22;
    v20 = INIReader::hasSection(&r, &key);
    LOBYTE(v63) = 4;
    v21 = !v20;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v21 )
    {
      v22 = std::operator+<wchar_t>(&v54, L"ERROR: aero.ini does not contain WINGS nor DATA in ", dataPath);
      LOBYTE(v63) = 23;
      v23 = std::operator+<wchar_t>(&key, v22, L"aero.ini");
      v24 = v23->_Myres < 8;
      LOBYTE(v63) = 24;
      if ( !v24 )
        v23 = (std::wstring *)v23->_Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v23->_Bx._Buf);
      ksGenerateCrash();
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v63) = 4;
      if ( v54._Myres >= 8 )
        operator delete(v54._Bx._Ptr);
    }
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"REFERENCE_AREA", 0xEu);
    LOBYTE(v63) = 25;
    std::wstring::wstring(&key, L"DATA");
    LOBYTE(v63) = 26;
    v25 = INIReader::getFloat(&r, &key, &section);
    v24 = key._Myres < 8;
    this->referenceArea = v25;
    if ( !v24 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v63) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&v54, L"CD");
    LOBYTE(v63) = 27;
    std::wstring::wstring(&key, L"DATA");
    LOBYTE(v63) = 28;
    v26 = INIReader::getFloat(&r, &key, &v54);
    v24 = key._Myres < 8;
    this->CD = v26;
    if ( !v24 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v63) = 4;
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    std::wstring::wstring(&v54, L"CL");
    LOBYTE(v63) = 29;
    std::wstring::wstring(&key, L"DATA");
    LOBYTE(v63) = 30;
    v27 = INIReader::getFloat(&r, &key, &v54);
    v24 = key._Myres < 8;
    this->CL = v27;
    if ( !v24 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v63) = 4;
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    std::wstring::wstring(&v54, L"FRONT_SHARE");
    LOBYTE(v63) = 31;
    std::wstring::wstring(&key, L"DATA");
    LOBYTE(v63) = 32;
    v28 = INIReader::getFloat(&r, &key, &v54);
    v24 = key._Myres < 8;
    this->frontShare = v28;
    if ( !v24 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v63) = 4;
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    std::wstring::wstring(&v54, L"CDX");
    LOBYTE(v63) = 33;
    std::wstring::wstring(&key, L"DATA");
    LOBYTE(v63) = 34;
    v29 = INIReader::getFloat(&r, &key, &v54);
    v24 = key._Myres < 8;
    this->CDX = v29;
    if ( !v24 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v63) = 4;
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    std::wstring::wstring(&v54, L"CDY");
    LOBYTE(v63) = 35;
    std::wstring::wstring(&key, L"DATA");
    LOBYTE(v63) = 36;
    this->CDY = INIReader::getFloat(&r, &key, &v54);
LABEL_99:
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    LOBYTE(v63) = 4;
    key._Bx._Buf[0] = 0;
    key._Mysize = 0;
    key._Myres = 7;
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    goto LABEL_103;
  }
  std::wstring::wstring(&v54, L"DATA");
  LOBYTE(v63) = 37;
  v30 = INIReader::hasSection(&r, &v54);
  LOBYTE(v63) = 4;
  if ( v54._Myres >= 8 )
    operator delete(v54._Bx._Ptr);
  if ( v30 )
  {
    v31 = std::operator+<wchar_t>(&v54, L"ERROR: aero.ini contains DATA with WINGS, which is redundant. ", dataPath);
    LOBYTE(v63) = 38;
    v32 = std::operator+<wchar_t>(&key, v31, L"aero.ini");
    v24 = v32->_Myres < 8;
    LOBYTE(v63) = 39;
    if ( !v24 )
      v32 = (std::wstring *)v32->_Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v32->_Bx._Buf);
    ksGenerateCrash();
    goto LABEL_99;
  }
LABEL_103:
  v33 = 0;
  while ( 1 )
  {
    *(_DWORD *)v51.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v51.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v51.gap68);
    v46 |= 4u;
    LOBYTE(v63) = 40;
    std::wiostream::basic_iostream<wchar_t>(&v51, &v51.gap10[8], 0);
    v63 = 41;
    *(_DWORD *)&v51.gap0[*(_DWORD *)(*(_DWORD *)v51.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v50.gap68[*(_DWORD *)(*(_DWORD *)v51.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v51.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v51.gap10[8]);
    *(_DWORD *)&v51.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v51.gap10[64] = 0;
    *(_DWORD *)&v51.gap10[68] = 0;
    LOBYTE(v63) = 43;
    v34 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v51.gap10, "DYNAMIC_CONTROLLER_");
    std::wostream::operator<<(v34, v33);
    v35 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v51, &key);
    LOBYTE(v63) = 44;
    v36 = INIReader::hasSection(&r, v35);
    v47 = v36;
    LOBYTE(v63) = 43;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v36 = v47;
    }
    if ( !v36 )
      break;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"WING", 4u);
    LOBYTE(v63) = 45;
    v37 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v51, &key);
    LOBYTE(v63) = 46;
    v38 = INIReader::getInt(&r, v37, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v63) = 43;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    v39 = (char *)this->wings._Mylast - (char *)this->wings._Myfirst;
    section._Bx._Buf[0] = 0;
    section._Myres = 7;
    section._Mysize = 0;
    if ( v38 >= v39 / 528 )
    {
      v45 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v51, &v54);
      if ( v45->_Myres >= 8 )
        v45 = (std::wstring *)v45->_Bx._Ptr;
      _printf("ERROR: DYNAMIC CONTROLLER %S WING OUT OF RANGE %u\n", v45->_Bx._Buf, v38);
      if ( v54._Myres >= 8 )
        operator delete(v54._Bx._Ptr);
      v54._Myres = 7;
      v54._Mysize = 0;
      v54._Bx._Buf[0] = 0;
      ++v33;
      LOBYTE(v63) = 4;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v51);
    }
    else
    {
      v40 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v51, &v60);
      LOBYTE(v63) = 47;
      DynamicWingController::DynamicWingController(&v61, this->car, &r, v40);
      v41 = 528 * v38;
      v42 = &this->wings._Myfirst->dynamicControllers;
      LOBYTE(v63) = 48;
      std::vector<DynamicWingController>::push_back(&v42[v41 / 0xCu], v43);
      LOBYTE(v63) = 47;
      Curve::~Curve(&v61.lut);
      if ( v60._Myres >= 8 )
        operator delete(v60._Bx._Ptr);
      v44 = this->wings._Myfirst;
      ++v33;
      LOBYTE(v63) = 4;
      v44[v41 / 0x210u].data.hasController = 1;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v51);
    }
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v51);
  v63 = -1;
  INIReader::~INIReader(&r);
}
void AeroMap::step(AeroMap *this, float dt)
{
  Wing *v3; // edi
  Wing *i; // esi
  vec3f lv; // [esp+10h] [ebp-Ch] BYREF

  if ( this->wings._Myfirst == this->wings._Mylast )
  {
    this->carBody->getLocalVelocity(this->carBody, &lv);
    AeroMap::addDrag(this, &lv);
    AeroMap::addLift(this, &lv);
  }
  v3 = this->wings._Mylast;
  for ( i = this->wings._Myfirst; i != v3; ++i )
    Wing::step(i, dt);
}
