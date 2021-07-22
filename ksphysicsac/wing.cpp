#include "wing.h
void Wing::Wing(Wing *this, Car *a_car, INIReader *ini, int index, bool isVertical)
{
  Wing *v5; // edi
  std::wstring *v6; // eax
  Car *v7; // eax
  std::wstring *v8; // eax
  std::wostream *v9; // eax
  std::wstring *v10; // esi
  std::wstring *v11; // esi
  double v12; // st7
  bool v13; // cf
  double v14; // st7
  float v15; // xmm0_4
  vec3f *v16; // eax
  std::wstring *v17; // eax
  const std::wstring *v18; // eax
  Car *v19; // ecx
  const std::wstring *v20; // eax
  std::wstring *v21; // eax
  const std::wstring *v22; // eax
  Car *v23; // ecx
  const std::wstring *v24; // eax
  const std::wstring *v25; // eax
  Car *v26; // ecx
  const std::wstring *v27; // eax
  char v28; // bl
  const std::wstring *v29; // eax
  Car *v30; // ecx
  const std::wstring *v31; // eax
  const std::wstring *v32; // eax
  Car *v33; // ecx
  const std::wstring *v34; // eax
  char v35; // bl
  const std::wstring *v36; // eax
  Car *v37; // ecx
  const std::wstring *v38; // eax
  double v39; // st7
  double v40; // st7
  double v41; // st7
  int v42; // ebx
  float *v43; // ebx
  std::wstring *v44; // esi
  int v45; // edi
  std::wstring *v46; // eax
  const std::wstring *v47; // eax
  double v48; // st7
  std::wstring *v49; // eax
  const std::wstring *v50; // eax
  double v51; // st7
  double v52; // st7
  int v53; // [esp+14h] [ebp-238h]
  _BYTE *v55; // [esp+20h] [ebp-22Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v56; // [esp+24h] [ebp-228h] BYREF
  std::wstring v57; // [esp+D4h] [ebp-178h] BYREF
  std::wstring key; // [esp+ECh] [ebp-160h] BYREF
  std::wstring v59; // [esp+104h] [ebp-148h] BYREF
  std::wstring v60; // [esp+11Ch] [ebp-130h] BYREF
  std::wstring section; // [esp+134h] [ebp-118h] BYREF
  std::wstring _Left; // [esp+14Ch] [ebp-100h] BYREF
  std::wstring data_path; // [esp+164h] [ebp-E8h] BYREF
  std::wstring lutwh_cl_name; // [esp+17Ch] [ebp-D0h] BYREF
  std::wstring lutwh_cd_name; // [esp+194h] [ebp-B8h] BYREF
  std::wstring result; // [esp+1ACh] [ebp-A0h] BYREF
  std::wstring zones[5]; // [esp+1C4h] [ebp-88h] BYREF
  int v68; // [esp+248h] [ebp-4h]

  v5 = this;
  WingData::WingData(&this->data);
  v68 = 0;
  WingState::WingState(&v5->status);
  v5->dynamicControllers._Myfirst = 0;
  v5->dynamicControllers._Mylast = 0;
  v5->dynamicControllers._Myend = 0;
  RaceEngineer::RaceEngineer(&v5->engineer, a_car);
  v5->hasDamage = 0;
  v5->overrideStatus.overrideAngle = 0.0;
  v5->overrideStatus.isActive = 0;
  v5->SPEED_DAMAGE_COEFF = 300.0;
  v5->SURFACE_DAMAGE_COEFF = 300.0;
  v5->car = a_car;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v68) = 3;
  *(_DWORD *)v56.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v56.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v56.gap68);
  LOBYTE(v68) = 4;
  std::wiostream::basic_iostream<wchar_t>(&v56, &v56.gap10[8], 0);
  v68 = 5;
  *(_DWORD *)&v56.gap0[*(_DWORD *)(*(_DWORD *)v56.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_BYTE **)((char *)&v55 + *(_DWORD *)(*(_DWORD *)v56.gap0 + 4)) = (_BYTE *)(*(_DWORD *)(*(_DWORD *)v56.gap0 + 4) - 104);
  v55 = &v56.gap10[8];
  std::wstreambuf::wstreambuf(&v56.gap10[8]);
  v6 = &section;
  if ( section._Myres >= 8 )
    v6 = (std::wstring *)section._Bx._Ptr;
  LOBYTE(v68) = 6;
  *(_DWORD *)&v56.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Init((std::wstringbuf *)&v56.gap10[8], v6->_Bx._Buf, section._Mysize, 0);
  LOBYTE(v68) = 7;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v7 = v5->car;
  LOBYTE(v68) = 8;
  v8 = std::operator+<wchar_t>(&result, &_Left, &v7->unixName);
  LOBYTE(v68) = 9;
  std::operator+<wchar_t>(&data_path, v8, L"/data/");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v68) = 12;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Bx._Buf[0] = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  if ( isVertical )
    v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v56.gap10, "FIN_");
  else
    v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v56.gap10, "WING_");
  std::wostream::operator<<(v9, index);
  v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v56, &v57);
  if ( &section != v10 )
  {
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&section, v10);
  }
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  v5->data.isVertical = isVertical;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"NAME", 4u);
  LOBYTE(v68) = 13;
  v11 = INIReader::getString(ini, &v59, &section, &key);
  if ( v5 != (Wing *)v11 )
  {
    if ( v5->data.name._Myres >= 8 )
      operator delete(v5->data.name._Bx._Ptr);
    v5->data.name._Myres = 7;
    v5->data.name._Mysize = 0;
    v5->data.name._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&v5->data.name, v11);
  }
  if ( v59._Myres >= 8 )
    operator delete(v59._Bx._Ptr);
  v59._Myres = 7;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  LOBYTE(v68) = 12;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CHORD", 5u);
  LOBYTE(v68) = 14;
  v12 = INIReader::getFloat(ini, &section, &key);
  v13 = key._Myres < 8;
  v5->data.chord = v12;
  LOBYTE(v68) = 12;
  if ( !v13 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SPAN", 4u);
  LOBYTE(v68) = 15;
  v14 = INIReader::getFloat(ini, &section, &key);
  v13 = key._Myres < 8;
  v5->data.span = v14;
  LOBYTE(v68) = 12;
  if ( !v13 )
    operator delete(key._Bx._Ptr);
  v15 = v5->data.chord * v5->data.span;
  v59._Myres = 7;
  v5->data.area = v15;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  std::wstring::assign(&v59, L"POSITION", 8u);
  LOBYTE(v68) = 16;
  v16 = INIReader::getFloat3(ini, (vec3f *)&key, &section, &v59);
  v13 = v59._Myres < 8;
  LOBYTE(v68) = 12;
  v5->data.position = *v16;
  if ( !v13 )
    operator delete(v59._Bx._Ptr);
  v59._Myres = 7;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  std::wstring::assign(&v59, L"LUT_AOA_CL", 0xAu);
  LOBYTE(v68) = 17;
  v17 = INIReader::getString(ini, &v57, &section, &v59);
  LOBYTE(v68) = 18;
  v18 = std::operator+<wchar_t>(&v60, &data_path, v17);
  v19 = v5->car;
  LOBYTE(v68) = 19;
  v20 = Car::getConfigPath(v19, &key, v18);
  LOBYTE(v68) = 20;
  Curve::load(&v5->data.lutAOA_CL, v20);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( v60._Myres >= 8 )
    operator delete(v60._Bx._Ptr);
  v60._Myres = 7;
  v60._Mysize = 0;
  v60._Bx._Buf[0] = 0;
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  v57._Myres = 7;
  v57._Mysize = 0;
  v57._Bx._Buf[0] = 0;
  LOBYTE(v68) = 12;
  if ( v59._Myres >= 8 )
    operator delete(v59._Bx._Ptr);
  v59._Myres = 7;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  std::wstring::assign(&v59, L"LUT_AOA_CD", 0xAu);
  LOBYTE(v68) = 21;
  v21 = INIReader::getString(ini, &key, &section, &v59);
  LOBYTE(v68) = 22;
  v22 = std::operator+<wchar_t>(&v60, &data_path, v21);
  v23 = v5->car;
  LOBYTE(v68) = 23;
  v24 = Car::getConfigPath(v23, &v57, v22);
  LOBYTE(v68) = 24;
  Curve::load(&v5->data.lutAOA_CD, v24);
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  v57._Myres = 7;
  v57._Mysize = 0;
  v57._Bx._Buf[0] = 0;
  if ( v60._Myres >= 8 )
    operator delete(v60._Bx._Ptr);
  v60._Myres = 7;
  v60._Mysize = 0;
  v60._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v68) = 12;
  if ( v59._Myres >= 8 )
    operator delete(v59._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"LUT_GH_CL", 9u);
  LOBYTE(v68) = 25;
  INIReader::getString(ini, &lutwh_cl_name, &section, &key);
  LOBYTE(v68) = 27;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Bx._Buf[0] = 0;
  key._Mysize = 0;
  v25 = std::operator+<wchar_t>(&v60, &data_path, &lutwh_cl_name);
  v26 = v5->car;
  LOBYTE(v68) = 28;
  v27 = Car::getConfigPath(v26, &v57, v25);
  LOBYTE(v68) = 29;
  v28 = Path::fileExists(isVertical, v27, 0);
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  v57._Myres = 7;
  v57._Mysize = 0;
  v57._Bx._Buf[0] = 0;
  LOBYTE(v68) = 27;
  if ( v60._Myres >= 8 )
    operator delete(v60._Bx._Ptr);
  if ( v28 )
  {
    v29 = std::operator+<wchar_t>(&v60, &data_path, &lutwh_cl_name);
    v30 = v5->car;
    LOBYTE(v68) = 30;
    v31 = Car::getConfigPath(v30, &v57, v29);
    LOBYTE(v68) = 31;
    Curve::load(&v5->data.lutGH_CL, v31);
    if ( v57._Myres >= 8 )
      operator delete(v57._Bx._Ptr);
    v57._Myres = 7;
    v57._Mysize = 0;
    v57._Bx._Buf[0] = 0;
    LOBYTE(v68) = 27;
    if ( v60._Myres >= 8 )
      operator delete(v60._Bx._Ptr);
  }
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"LUT_GH_CD", 9u);
  LOBYTE(v68) = 32;
  INIReader::getString(ini, &lutwh_cd_name, &section, &_Left);
  LOBYTE(v68) = 34;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  _Left._Mysize = 0;
  v32 = std::operator+<wchar_t>(&v60, &data_path, &lutwh_cd_name);
  v33 = v5->car;
  LOBYTE(v68) = 35;
  v34 = Car::getConfigPath(v33, &v57, v32);
  LOBYTE(v68) = 36;
  v35 = Path::fileExists(v28, v34, 0);
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  v57._Myres = 7;
  v57._Mysize = 0;
  v57._Bx._Buf[0] = 0;
  LOBYTE(v68) = 34;
  if ( v60._Myres >= 8 )
    operator delete(v60._Bx._Ptr);
  if ( v35 )
  {
    v36 = std::operator+<wchar_t>(&v60, &data_path, &lutwh_cd_name);
    v37 = v5->car;
    LOBYTE(v68) = 37;
    v38 = Car::getConfigPath(v37, &v57, v36);
    LOBYTE(v68) = 38;
    Curve::load(&v5->data.lutGH_CD, v38);
    if ( v57._Myres >= 8 )
      operator delete(v57._Bx._Ptr);
    v57._Myres = 7;
    v57._Mysize = 0;
    v57._Bx._Buf[0] = 0;
    LOBYTE(v68) = 34;
    if ( v60._Myres >= 8 )
      operator delete(v60._Bx._Ptr);
  }
  std::wstring::wstring(&v57, L"CD_GAIN");
  LOBYTE(v68) = 39;
  v39 = INIReader::getFloat(ini, &section, &v57);
  v13 = v57._Myres < 8;
  v5->data.cdGain = v39;
  LOBYTE(v68) = 34;
  if ( !v13 )
    operator delete(v57._Bx._Ptr);
  std::wstring::wstring(&v57, L"CL_GAIN");
  LOBYTE(v68) = 40;
  v40 = INIReader::getFloat(ini, &section, &v57);
  v13 = v57._Myres < 8;
  v5->data.clGain = v40;
  LOBYTE(v68) = 34;
  if ( !v13 )
    operator delete(v57._Bx._Ptr);
  std::wstring::wstring(&v57, L"ANGLE");
  LOBYTE(v68) = 41;
  v41 = INIReader::getFloat(ini, &section, &v57);
  v13 = v57._Myres < 8;
  v5->status.angle = v41;
  LOBYTE(v68) = 34;
  if ( !v13 )
    operator delete(v57._Bx._Ptr);
  v5->status.inputAngle = v5->status.angle;
  v5->status.frontShare = RaceEngineer::getPointFrontShare(&v5->engineer, &v5->data.position);
  std::wstring::wstring(&v57, L"VERSION");
  LOBYTE(v68) = 42;
  std::wstring::wstring(&v59, L"HEADER");
  LOBYTE(v68) = 43;
  v42 = INIReader::getInt(ini, &v59, &v57);
  v53 = v42;
  if ( v59._Myres >= 8 )
    operator delete(v59._Bx._Ptr);
  v59._Myres = 7;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  LOBYTE(v68) = 34;
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  if ( v42 >= 2 )
  {
    std::wstring::wstring(zones, L"FRONT");
    LOBYTE(v68) = 44;
    std::wstring::wstring(&zones[1], L"REAR");
    LOBYTE(v68) = 45;
    std::wstring::wstring(&zones[2], L"LEFT");
    LOBYTE(v68) = 46;
    std::wstring::wstring(&zones[3], L"RIGHT");
    LOBYTE(v68) = 47;
    std::wstring::wstring(&zones[4], L"CENTER");
    v43 = v5->damageCL;
    LOBYTE(v68) = 48;
    v44 = zones;
    v45 = 4;
    do
    {
      v46 = std::operator+<wchar_t>(&v60, L"ZONE_", v44);
      LOBYTE(v68) = 49;
      v47 = std::operator+<wchar_t>(&v57, v46, L"_CD");
      LOBYTE(v68) = 50;
      v48 = INIReader::getFloat(ini, &section, v47);
      v13 = v57._Myres < 8;
      v43[5] = v48;
      if ( !v13 )
        operator delete(v57._Bx._Ptr);
      v57._Myres = 7;
      v57._Mysize = 0;
      v57._Bx._Buf[0] = 0;
      LOBYTE(v68) = 48;
      if ( v60._Myres >= 8 )
        operator delete(v60._Bx._Ptr);
      v49 = std::operator+<wchar_t>(&v60, L"ZONE_", v44);
      LOBYTE(v68) = 51;
      v50 = std::operator+<wchar_t>(&v57, v49, L"_CL");
      LOBYTE(v68) = 52;
      v51 = INIReader::getFloat(ini, &section, v50);
      v13 = v57._Myres < 8;
      *v43 = v51;
      if ( !v13 )
        operator delete(v57._Bx._Ptr);
      v57._Myres = 7;
      v57._Mysize = 0;
      v57._Bx._Buf[0] = 0;
      LOBYTE(v68) = 48;
      if ( v60._Myres >= 8 )
        operator delete(v60._Bx._Ptr);
      ++v43;
      ++v44;
      --v45;
    }
    while ( v45 );
    v5 = this;
    this->hasDamage = 1;
    LOBYTE(v68) = 34;
    `eh vector destructor iterator'(zones, 0x18u, 5, (void (*)(void *))std::wstring::~wstring);
    v42 = v53;
  }
  if ( v42 >= 3 )
  {
    std::wstring::wstring(&v57, L"YAW_CL_GAIN");
    LOBYTE(v68) = 53;
    v52 = INIReader::getFloat(ini, &section, &v57);
    v13 = v57._Myres < 8;
    v5->data.yawGain = v52;
    if ( !v13 )
      operator delete(v57._Bx._Ptr);
  }
  if ( lutwh_cd_name._Myres >= 8 )
    operator delete(lutwh_cd_name._Bx._Ptr);
  lutwh_cd_name._Myres = 7;
  lutwh_cd_name._Mysize = 0;
  lutwh_cd_name._Bx._Buf[0] = 0;
  if ( lutwh_cl_name._Myres >= 8 )
    operator delete(lutwh_cl_name._Bx._Ptr);
  lutwh_cl_name._Myres = 7;
  lutwh_cl_name._Mysize = 0;
  lutwh_cl_name._Bx._Buf[0] = 0;
  if ( data_path._Myres >= 8 )
    operator delete(data_path._Bx._Ptr);
  data_path._Myres = 7;
  data_path._Mysize = 0;
  data_path._Bx._Buf[0] = 0;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v56);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void Wing::~Wing(Wing *this)
{
  RaceEngineer::~RaceEngineer(&this->engineer);
  std::vector<DynamicWingController>::_Tidy(&this->dynamicControllers);
  WingData::~WingData(&this->data);
}
void Wing::addDrag(Wing *this, vec3f *lv)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // eax
  float v6; // xmm0_4
  double v7; // st7
  bool v8; // zf
  Car *v9; // edx
  float v10; // xmm4_4
  int i; // ecx
  unsigned int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float j; // xmm3_4
  float v16; // xmm3_4
  unsigned int v17; // eax
  float v18; // xmm1_4
  float v19; // xmm0_4
  Car *v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm1_4
  __int64 v23; // [esp+Ch] [ebp-1Ch] BYREF
  float v24; // [esp+14h] [ebp-14h]
  float v25; // [esp+18h] [ebp-10h]
  float v26; // [esp+1Ch] [ebp-Ch]
  float v27; // [esp+20h] [ebp-8h]
  float v28; // [esp+24h] [ebp-4h]
  float lva; // [esp+2Ch] [ebp+4h]
  float lvb; // [esp+2Ch] [ebp+4h]

  if ( this->data.isVertical )
    v3 = this->status.yawAngle;
  else
    v3 = this->status.aoa;
  v4 = (float)((float)(lv->x * lv->x) + (float)(lv->y * lv->y)) + (float)(lv->z * lv->z);
  v5 = lv->z;
  v23 = *(_QWORD *)&lv->x;
  v24 = v5;
  v25 = v4;
  v27 = *((float *)&v23 + 1);
  v28 = *(float *)&v23;
  v26 = v5;
  v6 = fsqrt(
         (float)((float)(*(float *)&v23 * *(float *)&v23) + (float)(*((float *)&v23 + 1) * *((float *)&v23 + 1)))
       + (float)(v5 * v5));
  if ( v6 != 0.0 )
  {
    v28 = (float)(1.0 / v6) * *(float *)&v23;
    v27 = (float)(1.0 / v6) * *((float *)&v23 + 1);
    v26 = (float)(1.0 / v6) * v5;
  }
  v7 = Curve::getValue(&this->data.lutAOA_CD, (float)(this->status.angleMult * this->status.angle) + v3);
  v8 = !this->hasDamage;
  lva = v7 * this->data.cdGain;
  this->status.cd = lva;
  if ( !v8 )
  {
    v9 = this->car;
    if ( v9->ksPhysics->mechanicalDamageRate > 0.0 )
    {
      v10 = 0.0;
      for ( i = 2926; i < 2930; ++i )
      {
        v12 = 2;
        v13 = *(float *)&(&v9->__vftable)[i] * (float)(1.0 / (float)this->SPEED_DAMAGE_COEFF);
        v14 = FLOAT_1_0;
        for ( j = v13; ; j = j * j )
        {
          if ( (v12 & 1) != 0 )
            v14 = v14 * j;
          v12 >>= 1;
          if ( !v12 )
            break;
        }
        v16 = *(float *)((char *)&this[-21] + i * 4 - 128) * (float)this->SURFACE_DAMAGE_COEFF;
        if ( v10 <= (float)(v16 * v14) )
        {
          v17 = 2;
          v18 = FLOAT_1_0;
          while ( 1 )
          {
            if ( (v17 & 1) != 0 )
              v18 = v18 * v13;
            v17 >>= 1;
            if ( !v17 )
              break;
            v13 = v13 * v13;
          }
          v10 = v16 * v18;
        }
      }
      if ( v10 <= 1.0 )
      {
        if ( v10 < 0.0 )
          v10 = 0.0;
      }
      else
      {
        v10 = FLOAT_1_0;
      }
      this->status.cd = (float)(v10 + 1.0) * lva;
    }
  }
  if ( Curve::getCount(&this->data.lutGH_CD) )
  {
    lvb = Curve::getValue(&this->data.lutGH_CD, this->status.groundHeight);
    v19 = this->status.cd * lvb;
    this->status.groundEffectDrag = lvb;
    this->status.cd = v19;
  }
  v20 = this->car;
  v8 = v25 == 0.0;
  v21 = (float)((float)((float)(this->status.cd * v25) * v20->aeroMap.airDensity) * this->data.area) * 0.5;
  this->status.dragKG = v21 * 0.10197838;
  if ( !v8 )
  {
    LODWORD(v22) = LODWORD(v21) ^ _xmm;
    *(float *)&v23 = v28 * v22;
    *((float *)&v23 + 1) = v27 * v22;
    v24 = v26 * v22;
    v20->body->addLocalForceAtLocalPos(v20->body, (const vec3f *)&v23, &this->data.position);
  }
}
void Wing::addLift(Wing *this, vec3f *lv)
{
  bool v3; // al
  float v4; // xmm1_4
  float v5; // xmm2_4
  int v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  __m128 v9; // xmm6
  Car *v10; // edx
  float v11; // xmm4_4
  int i; // ecx
  unsigned int v13; // eax
  float v14; // xmm3_4
  float v15; // xmm1_4
  float j; // xmm2_4
  float v17; // xmm2_4
  unsigned int v18; // eax
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  Car *v22; // ecx
  float v23; // xmm3_4
  __m128 v24; // xmm5
  float v25; // xmm0_4
  float v26; // xmm2_4
  __m128 v27; // xmm4
  float v28; // xmm0_4
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  float v31; // xmm2_4
  float v32; // xmm0_4
  unsigned __int64 v33; // xmm1_8
  float v34; // xmm4_4
  __m128 v35; // xmm2
  float v36; // xmm0_4
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  float v39; // xmm3_4
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  float v42; // [esp+14h] [ebp-18h]
  vec3f v43; // [esp+18h] [ebp-14h]
  float v44; // [esp+24h] [ebp-8h]
  float v45; // [esp+28h] [ebp-4h]

  v3 = this->data.isVertical;
  if ( v3 )
    v4 = this->status.yawAngle;
  else
    v4 = this->status.aoa;
  if ( v3 )
    v5 = lv->x;
  else
    v5 = lv->y;
  v45 = (float)(v5 * v5) + (float)(lv->z * lv->z);
  this->status.cl = Curve::getValue(&this->data.lutAOA_CL, (float)(this->status.angleMult * this->status.angle) + v4)
                  * this->data.clGain;
  if ( lv->z < 0.0 )
    this->status.cl = 0.0;
  if ( this->data.yawGain != 0.0 && !this->data.isVertical )
  {
    v7 = FLOAT_1_0;
    v8 = (float)(__libm_sse2_sinf(v6).m128_f32[0] * this->data.yawGain) + 1.0;
    if ( v8 > 1.0 || (v7 = 0.0, v8 < 0.0) )
      v8 = v7;
    this->status.cl = v8 * this->status.cl;
  }
  if ( Curve::getCount(&this->data.lutGH_CL) )
  {
    v44 = Curve::getValue(&this->data.lutGH_CL, this->status.groundHeight);
    this->status.groundEffectLift = v44;
    this->status.cl = v44 * this->status.cl;
  }
  v9 = (__m128)LODWORD(FLOAT_1_0);
  if ( this->hasDamage )
  {
    v10 = this->car;
    if ( v10->ksPhysics->mechanicalDamageRate > 0.0 )
    {
      v11 = 0.0;
      for ( i = 2926; i < 2930; ++i )
      {
        v13 = 2;
        v14 = *(float *)&(&v10->__vftable)[i] * (float)(1.0 / (float)this->SPEED_DAMAGE_COEFF);
        v15 = FLOAT_1_0;
        for ( j = v14; ; j = j * j )
        {
          if ( (v13 & 1) != 0 )
            v15 = v15 * j;
          v13 >>= 1;
          if ( !v13 )
            break;
        }
        v17 = *(float *)((char *)&this[-21] + i * 4 - 148) * (float)this->SURFACE_DAMAGE_COEFF;
        if ( v11 <= (float)(v17 * v15) )
        {
          v18 = 2;
          v19 = FLOAT_1_0;
          while ( 1 )
          {
            if ( (v18 & 1) != 0 )
              v19 = v19 * v14;
            v18 >>= 1;
            if ( !v18 )
              break;
            v14 = v14 * v14;
          }
          v11 = v17 * v19;
        }
      }
      if ( this->data.isVertical )
      {
        if ( v11 <= 1.0 )
        {
          if ( v11 < 0.0 )
            v11 = 0.0;
        }
        else
        {
          v11 = FLOAT_1_0;
        }
        v21 = (float)(1.0 - v11) * this->status.cl;
      }
      else
      {
        v20 = this->status.cl;
        if ( v20 <= 0.0 )
          goto LABEL_46;
        if ( v11 <= 1.0 )
        {
          if ( v11 < 0.0 )
            v11 = 0.0;
          v21 = (float)(1.0 - v11) * v20;
        }
        else
        {
          v21 = (float)(1.0 - 1.0) * v20;
        }
      }
      this->status.cl = v21;
    }
  }
LABEL_46:
  v22 = this->car;
  v23 = (float)((float)((float)(v45 * this->status.cl) * v22->aeroMap.airDensity) * this->data.area) * 0.5;
  this->status.liftKG = v23 * 0.10197838;
  if ( v45 != 0.0 )
  {
    v43 = *lv;
    v24 = (__m128)LODWORD(lv->y);
    v25 = v24.m128_f32[0] * v24.m128_f32[0];
    if ( this->data.isVertical )
    {
      v34 = v43.x;
      v35 = (__m128)LODWORD(v43.z);
      v36 = fsqrt((float)((float)(v34 * v34) + v25) + (float)(v35.m128_f32[0] * v35.m128_f32[0]));
      if ( v36 != 0.0 )
      {
        v9.m128_f32[0] = 1.0 / v36;
        v35.m128_f32[0] = v43.z * (float)(1.0 / v36);
        v34 = (float)(1.0 / v36) * v43.x;
        v37 = v9;
        v37.m128_f32[0] = v9.m128_f32[0] * v24.m128_f32[0];
        v24 = v37;
      }
      v24.m128_f32[0] = v24.m128_f32[0] * 0.0;
      v38 = v24;
      v38.m128_f32[0] = v24.m128_f32[0] - v35.m128_f32[0];
      v35.m128_f32[0] = (float)(v35.m128_f32[0] * 0.0) - (float)(v34 * 0.0);
      v42 = v34 - v24.m128_f32[0];
      v33 = _mm_unpacklo_ps(v38, v35).m128_u64[0];
    }
    else
    {
      v26 = v43.x;
      v27 = (__m128)LODWORD(v43.z);
      v28 = fsqrt((float)((float)(v26 * v26) + v25) + (float)(v27.m128_f32[0] * v27.m128_f32[0]));
      if ( v28 != 0.0 )
      {
        v9.m128_f32[0] = 1.0 / v28;
        v27.m128_f32[0] = v43.z * (float)(1.0 / v28);
        v26 = (float)(1.0 / v28) * v43.x;
        v29 = v9;
        v29.m128_f32[0] = v9.m128_f32[0] * v24.m128_f32[0];
        v24 = v29;
      }
      v30 = v24;
      v31 = v26 * 0.0;
      v32 = v27.m128_f32[0] * 0.0;
      v27.m128_f32[0] = v27.m128_f32[0] - v31;
      v30.m128_f32[0] = (float)(v24.m128_f32[0] * 0.0) - v32;
      v42 = v31 - v24.m128_f32[0];
      v33 = _mm_unpacklo_ps(v30, v27).m128_u64[0];
    }
    LODWORD(v39) = LODWORD(v23) ^ _xmm;
    v40 = (__m128)(unsigned int)v33;
    v41 = (__m128)HIDWORD(v33);
    v40.m128_f32[0] = v40.m128_f32[0] * v39;
    v41.m128_f32[0] = v41.m128_f32[0] * v39;
    *(_QWORD *)&this->status.liftVector.x = _mm_unpacklo_ps(v40, v41).m128_u64[0];
    this->status.liftVector.z = v42 * v39;
    v22->body->addLocalForceAtLocalPos(v22->body, &this->status.liftVector, &this->data.position);
  }
}
void Wing::clearOverrides(Wing *this)
{
  this->overrideStatus.isActive = 0;
}
double Wing::getCurrentModifiedAngle(Wing *this)
{
  double result; // st7

  if ( this->overrideStatus.isActive )
    result = this->overrideStatus.overrideAngle;
  else
    result = this->status.angleMult * this->status.angle;
  return result;
}
void Wing::setOverrideAngle(Wing *this, float iangle)
{
  this->overrideStatus.isActive = 1;
  this->overrideStatus.overrideAngle = iangle;
}
void Wing::step(Wing *this, float dt)
{
  vec3f *v3; // eax
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  Car *v6; // eax
  const vec3f *v7; // eax
  double v8; // st7
  bool v9; // zf
  float v10; // xmm2_4
  vec3f lv; // [esp+1Ch] [ebp-18h] BYREF
  vec3f result; // [esp+28h] [ebp-Ch] BYREF

  if ( (dword_186F278 & 1) == 0 )
  {
    perfCounter_44.name = "Wing::step";
    dword_186F278 |= 1u;
    perfCounter_44.group = Physics;
    perfCounter_44.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Wing::step" | 0xFF000000;
  }
  if ( !this->overrideStatus.isActive )
    Wing::stepDynamicControllers(this, dt);
  this->car->body->getLocalPointVelocity(this->car->body, &lv, &this->data.position);
  v3 = Car::getGroundWindVector(this->car, &result);
  v4 = (__m128)LODWORD(v3->x);
  v5 = (__m128)LODWORD(v3->y);
  v4.m128_f32[0] = v4.m128_f32[0] + lv.x;
  v5.m128_f32[0] = v5.m128_f32[0] + lv.y;
  result.z = v3->z + lv.z;
  lv.z = result.z;
  v6 = this->car;
  *(_QWORD *)&lv.x = _mm_unpacklo_ps(v4, v5).m128_u64[0];
  lv = *v6->body->worldToLocalNormal(v6->body, &result, &lv);
  v7 = this->car->body->localToWorld(this->car->body, &result, &this->data.position);
  v8 = RaceEngineer::getPointGroundHeight(&this->engineer, v7);
  v9 = !this->overrideStatus.isActive;
  v10 = this->status.angle;
  this->status.groundHeight = v8;
  if ( !v9 )
    this->status.angle = this->overrideStatus.overrideAngle;
  if ( lv.z == 0.0 )
  {
    this->status.aoa = 0.0;
    this->status.yawAngle = 0.0;
    this->status.cd = 0.0;
    this->status.cl = 0.0;
  }
  else
  {
    this->status.aoa = __libm_sse2_atanf().m128_f32[0] * 57.29578;
    this->status.yawAngle = __libm_sse2_atanf().m128_f32[0] * 57.29578;
    Wing::addDrag(this, &lv);
    Wing::addLift(this, &lv);
  }
  if ( this->overrideStatus.isActive )
    this->status.angle = v10;
}
void Wing::stepDynamicControllers(Wing *this, float dt)
{
  DynamicWingController *v3; // eax
  float v4; // xmm0_4
  DynamicWingController *v5; // edi
  DynamicWingController *v6; // esi
  float v7; // [esp+4h] [ebp-4h]

  v3 = this->dynamicControllers._Myfirst;
  if ( v3 != this->dynamicControllers._Mylast )
  {
    v4 = this->status.inputAngle;
    v5 = this->dynamicControllers._Mylast;
    v6 = this->dynamicControllers._Myfirst;
    v7 = v4;
    if ( v3 != v5 )
    {
      while ( 1 )
      {
        DynamicWingController::step(v6);
        if ( v6->combinatorMode == eAdd )
        {
          v4 = v6->outputAngle + v7;
          v7 = v4;
        }
        else if ( v6->combinatorMode == eMult )
        {
          v4 = v6->outputAngle * v7;
          v7 = v4;
        }
        else
        {
          v4 = v7;
        }
        if ( v4 > v6->upLimit )
          break;
        if ( v6->downLimit > v4 )
        {
          v4 = v6->downLimit;
          goto LABEL_12;
        }
LABEL_13:
        if ( ++v6 == v5 )
          goto LABEL_14;
      }
      v4 = v6->upLimit;
LABEL_12:
      v7 = v4;
      goto LABEL_13;
    }
LABEL_14:
    this->status.angle = v4;
  }
}
void Wing::Wing(Wing *this, const Wing *__that)
{
  WingData::WingData(&this->data, &__that->data);
  *(__m128i *)&this->status.aoa = _mm_loadu_si128((const __m128i *)&__that->status);
  *(__m128i *)&this->status.inputAngle = _mm_loadu_si128((const __m128i *)&__that->status.inputAngle);
  *(__m128i *)&this->status.liftKG = _mm_loadu_si128((const __m128i *)&__that->status.liftKG);
  *(__m128i *)&this->status.yawAngle = _mm_loadu_si128((const __m128i *)&__that->status.yawAngle);
  this->status.liftVector.z = __that->status.liftVector.z;
  std::vector<DynamicWingController>::vector<DynamicWingController>(
    &this->dynamicControllers,
    &__that->dynamicControllers);
  this->car = __that->car;
  this->engineer.__vftable = (RaceEngineer_vtbl *)&RaceEngineer::`vftable';
  this->engineer.car = __that->engineer.car;
  this->engineer.fuelPerLapEvaluated = __that->engineer.fuelPerLapEvaluated;
  *(__m128i *)this->damageCL = _mm_loadu_si128((const __m128i *)__that->damageCL);
  this->damageCL[4] = __that->damageCL[4];
  *(__m128i *)this->damageCD = _mm_loadu_si128((const __m128i *)__that->damageCD);
  this->damageCD[4] = __that->damageCD[4];
  this->hasDamage = __that->hasDamage;
  this->overrideStatus = __that->overrideStatus;
  this->SPEED_DAMAGE_COEFF = __that->SPEED_DAMAGE_COEFF;
  this->SURFACE_DAMAGE_COEFF = __that->SURFACE_DAMAGE_COEFF;
}
