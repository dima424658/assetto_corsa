#include "digitalitem.h
void DigitalItem::DigitalItem(DigitalItem *this, CarAvatar *a_car, INIReader *ini, const std::wstring *section, std::vector<DigitalItem *> *items)
{
  INIReader *v6; // ebx
  char v7; // al
  double v8; // st7
  bool v9; // cf
  int v10; // eax
  char v11; // al
  double v12; // st7
  int v13; // eax
  char v14; // al
  int v15; // eax
  double v16; // st7
  double v17; // st7
  char v18; // al
  double v19; // st7
  const __m128i *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  char v28; // al
  int v29; // eax
  char v30; // al
  std::wstring *v31; // eax
  char v32; // al
  int v33; // eax
  char v34; // al
  int v35; // eax
  char v36; // al
  int v37; // eax
  const __m128i *v38; // eax
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  const __m128i *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm0_4
  char v48; // al
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  char v51; // al
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  int v54; // eax
  DisplayNode *v55; // esi
  DisplayNode *v56; // eax
  std::wstring *v57; // esi
  std::wstring *v58; // eax
  std::wstring *v59; // ecx
  CarAvatar *v60; // eax
  std::wstring *v61; // eax
  std::wstring *v62; // eax
  ResourceStore *v63; // eax
  const Texture *v64; // eax
  DisplayNode *v65; // ecx
  Console *v66; // eax
  Console *v67; // eax
  Console *v68; // eax
  Console *v69; // eax
  std::wstring *v70; // esi
  std::wstring *v71; // eax
  std::wstring *v72; // ecx
  CarAvatar *v73; // eax
  std::wstring *v74; // eax
  std::wstring *v75; // eax
  std::wstring *v76; // eax
  ResourceStore *v77; // eax
  const Texture *v78; // eax
  DisplayNode *v79; // ecx
  Console *v80; // eax
  Console *v81; // eax
  Console *v82; // eax
  Console *v83; // eax
  double v84; // st7
  DisplayNode *v85; // eax
  double v86; // st7
  DisplayNode *v87; // eax
  double v88; // st7
  DisplayNode *v89; // esi
  DisplayNode *v90; // eax
  std::wstring *v91; // esi
  std::wstring *v92; // eax
  std::wstring *v93; // ecx
  CarAvatar *v94; // eax
  std::wstring *v95; // eax
  std::wstring *v96; // eax
  ResourceStore *v97; // eax
  const Texture *v98; // eax
  DisplayNode *v99; // ecx
  Console *v100; // eax
  Console *v101; // eax
  Console *v102; // eax
  Console *v103; // eax
  std::wstring *v104; // esi
  std::wstring *v105; // eax
  std::wstring *v106; // ecx
  CarAvatar *v107; // eax
  std::wstring *v108; // eax
  std::wstring *v109; // eax
  std::wstring *v110; // eax
  ResourceStore *v111; // eax
  const Texture *v112; // eax
  DisplayNode *v113; // ecx
  Console *v114; // eax
  Console *v115; // eax
  Console *v116; // eax
  Console *v117; // eax
  double v118; // st7
  DisplayNode *v119; // eax
  double v120; // st7
  DisplayNode *v121; // eax
  double v122; // st7
  DisplayNode *v123; // eax
  double v124; // st7
  DisplayNode *v125; // esi
  DisplayNode *v126; // eax
  std::wstring *v127; // esi
  std::wstring *v128; // eax
  std::wstring *v129; // ecx
  CarAvatar *v130; // eax
  std::wstring *v131; // eax
  std::wstring *v132; // eax
  ResourceStore *v133; // eax
  const Texture *v134; // eax
  DisplayNode *v135; // ecx
  Console *v136; // eax
  Console *v137; // eax
  Console *v138; // eax
  Console *v139; // eax
  double v140; // st7
  DisplayNode *v141; // eax
  double v142; // st7
  DisplayNode *v143; // eax
  double v144; // st7
  DisplayNode *v145; // eax
  char v146; // al
  char v147; // bl
  unsigned int v148; // esi
  Console *v149; // eax
  Console *v150; // eax
  Console *v151; // eax
  Console *v152; // eax
  CarAvatar *v153; // eax
  float v154; // esi
  Node *v155; // eax
  Console *v156; // eax
  Console *v157; // eax
  Console *v158; // eax
  Console *v159; // eax
  const __m128i *v160; // eax
  double v161; // st7
  float v162; // xmm1_4
  DisplayNode *v163; // eax
  StringBlitter3D *v164; // esi
  const std::wstring *v165; // eax
  StringBlitter3D *v166; // eax
  char v167; // al
  TextNode *v168; // esi
  int v169; // eax
  __m128i v170; // xmm0
  double v171; // st7
  StringBlitter3D *v172; // ecx
  double v173; // st7
  TextNode *v174; // eax
  const vec3f *v175; // eax
  char v176; // al
  char v177; // bl
  INIReader *v178; // ebx
  unsigned __int16 v179; // ax
  unsigned __int16 v180; // si
  __m128i v181; // xmm0
  const vec3f *v182; // eax
  std::wstring v183; // [esp-60h] [ebp-218h] BYREF
  std::wstring v184; // [esp-48h] [ebp-200h] BYREF
  _BYTE v185[48]; // [esp-30h] [ebp-1E8h] BYREF
  char v186; // [esp+17h] [ebp-1A1h]
  float intensity3; // [esp+18h] [ebp-1A0h]
  std::wstring *v188; // [esp+1Ch] [ebp-19Ch]
  int v189; // [esp+20h] [ebp-198h]
  std::wstring *v190; // [esp+24h] [ebp-194h]
  float intensity; // [esp+28h] [ebp-190h]
  INIReader *v192; // [esp+2Ch] [ebp-18Ch]
  int v193; // [esp+30h] [ebp-188h]
  DigitalItem *v194; // [esp+34h] [ebp-184h]
  std::wstring units; // [esp+38h] [ebp-180h] BYREF
  std::wstring result; // [esp+50h] [ebp-168h] BYREF
  std::wstring filename; // [esp+68h] [ebp-150h] BYREF
  std::wstring t; // [esp+80h] [ebp-138h] BYREF
  Texture v199; // [esp+98h] [ebp-120h] BYREF
  std::wstring key; // [esp+B4h] [ebp-104h] BYREF
  std::wstring v201; // [esp+CCh] [ebp-ECh] BYREF
  std::wstring v202; // [esp+E4h] [ebp-D4h] BYREF
  std::wstring v203; // [esp+FCh] [ebp-BCh] BYREF
  std::wstring v204; // [esp+114h] [ebp-A4h] BYREF
  Texture v205; // [esp+12Ch] [ebp-8Ch] BYREF
  std::wstring v206; // [esp+148h] [ebp-70h] BYREF
  std::wstring s; // [esp+160h] [ebp-58h] BYREF
  std::wstring v208; // [esp+178h] [ebp-40h] BYREF
  std::wstring p; // [esp+190h] [ebp-28h] BYREF
  int v210; // [esp+1B4h] [ebp-4h]

  v6 = ini;
  intensity = *(float *)&items;
  v189 = 0;
  this->color.x = 0.0;
  this->color.y = 0.0;
  this->color.z = 0.0;
  this->color.w = 0.0;
  this->color2.x = 0.0;
  this->color2.y = 0.0;
  this->color2.z = 0.0;
  this->color2.w = 0.0;
  this->color3.x = 0.0;
  this->color3.y = 0.0;
  this->color3.z = 0.0;
  this->color3.w = 0.0;
  this->preFix._Myres = 7;
  this->preFix._Mysize = 0;
  v194 = this;
  v192 = ini;
  v193 = 0;
  this->preFix._Bx._Buf[0] = 0;
  this->postFix._Myres = 7;
  this->postFix._Mysize = 0;
  v210 = 0;
  this->postFix._Bx._Buf[0] = 0;
  this->car = a_car;
  *(_DWORD *)&v185[44] = 7;
  this->maxRPM = 0;
  this->maxSpeed = 0;
  this->blitter = 0;
  this->textNode = 0;
  this->displayNode = 0;
  this->speedometerUnits = SystemDefault;
  this->fuelConsumptionUnits = KmPerLiter;
  this->tyreNumber = 0;
  this->updateRefresh = 0.0;
  this->currentRefresh = 0.0;
  this->type = UnknownItem;
  key._Mysize = 0;
  *(_DWORD *)&v185[40] = L"REFRESH";
  LOBYTE(v210) = 1;
  this->lastGear = 1;
  this->timeToIgnore = -1.0;
  this->timeToIgnoreBase = -1.0;
  this->decimals = 3;
  key._Myres = 7;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, *(const wchar_t **)&v185[40], *(unsigned int *)&v185[44]);
  LOBYTE(v210) = 2;
  v7 = INIReader::hasKey(ini, section, &key);
  v186 = v7;
  LOBYTE(v210) = 1;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v7 = v186;
  }
  if ( v7 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"REFRESH", 7u);
    LOBYTE(v210) = 3;
    v8 = INIReader::getFloat(ini, section, &key);
    v9 = key._Myres < 8;
    this->updateRefresh = v8;
    LOBYTE(v210) = 1;
    if ( !v9 )
      operator delete(key._Bx._Ptr);
    intensity3 = this->updateRefresh;
    this->currentRefresh = (float)((float)_rand() * 0.000030518509) * intensity3;
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TYPE", 4u);
  LOBYTE(v210) = 4;
  INIReader::getString(ini, &t, section, &key);
  LOBYTE(v210) = 6;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( !std::wstring::compare(&t, 0, t._Mysize, L"PRESSURE", 8u) )
  {
    *(_DWORD *)&v185[44] = 11;
    *(_DWORD *)&v185[40] = L"TYRE_NUMBER";
    this->type = 15;
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, *(const wchar_t **)&v185[40], *(unsigned int *)&v185[44]);
    LOBYTE(v210) = 7;
    v10 = (int)INIReader::getFloat(ini, section, &filename);
    v9 = filename._Myres < 8;
    this->tyreNumber = v10;
    LOBYTE(v210) = 6;
    if ( !v9 )
      operator delete(filename._Bx._Ptr);
  }
  if ( !std::wstring::compare(&t, 0, t._Mysize, L"GEAR", 4u) )
  {
    *(_DWORD *)&v185[44] = 6;
    *(_DWORD *)&v185[40] = L"N_TIME";
    this->type = FullPosition;
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, *(const wchar_t **)&v185[40], *(unsigned int *)&v185[44]);
    LOBYTE(v210) = 8;
    v11 = INIReader::hasKey(ini, section, &filename);
    v186 = v11;
    LOBYTE(v210) = 6;
    if ( filename._Myres >= 8 )
    {
      operator delete(filename._Bx._Ptr);
      v11 = v186;
    }
    if ( v11 )
    {
      std::wstring::wstring(&units, L"N_TIME");
      LOBYTE(v210) = 9;
      v12 = INIReader::getFloat(ini, section, &units);
      v9 = units._Myres < 8;
      this->timeToIgnoreBase = v12;
      LOBYTE(v210) = 6;
      if ( !v9 )
        operator delete(units._Bx._Ptr);
    }
  }
  if ( !std::wstring::compare(&t, 0, t._Mysize, L"GFORCES", 7u) )
  {
    *(_DWORD *)&v185[44] = 8;
    *(_DWORD *)&v185[40] = L"DECIMALS";
    this->type = 27;
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, *(const wchar_t **)&v185[40], *(unsigned int *)&v185[44]);
    LOBYTE(v210) = 10;
    v13 = INIReader::getInt(ini, section, &filename);
    v9 = filename._Myres < 8;
    this->decimals = v13;
    LOBYTE(v210) = 6;
    if ( !v9 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"DIRECTION", 9u);
    LOBYTE(v210) = 11;
    v14 = INIReader::hasKey(ini, section, &filename);
    v186 = v14;
    LOBYTE(v210) = 6;
    if ( filename._Myres >= 8 )
    {
      operator delete(filename._Bx._Ptr);
      v14 = v186;
    }
    if ( v14 )
    {
      std::wstring::wstring(&result, L"DIRECTION");
      LOBYTE(v210) = 12;
      INIReader::getString(ini, &filename, section, &result);
      LOBYTE(v210) = 14;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( !std::wstring::compare(&filename, 0, filename._Mysize, L"X", 1u) )
        this->tyreNumber = 0;
      if ( !std::wstring::compare(&filename, 0, filename._Mysize, L"Y", 1u) )
        this->tyreNumber = 1;
      if ( !std::wstring::compare(&filename, 0, filename._Mysize, L"Z", 1u) )
        this->tyreNumber = 2;
      LOBYTE(v210) = 6;
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
    }
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"ADDSIGN", 7u);
    LOBYTE(v210) = 15;
    v15 = INIReader::getInt(ini, section, &result);
    v9 = result._Myres < 8;
    this->lastGear = v15;
    LOBYTE(v210) = 6;
    if ( !v9 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"MIN", 3u);
    LOBYTE(v210) = 16;
    v16 = INIReader::getFloat(ini, section, &result);
    v9 = result._Myres < 8;
    this->rpmGraphMin = v16;
    LOBYTE(v210) = 6;
    if ( !v9 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"MAX", 3u);
    LOBYTE(v210) = 17;
    v17 = INIReader::getFloat(ini, section, &result);
    v9 = result._Myres < 8;
    this->rpmGraphMax = v17;
    LOBYTE(v210) = 6;
    if ( !v9 )
      operator delete(result._Bx._Ptr);
  }
  if ( !std::wstring::compare(&t, 0, t._Mysize, L"GEAR_COLOR", 0xAu) )
  {
    *(_DWORD *)&v185[44] = 6;
    *(_DWORD *)&v185[40] = L"N_TIME";
    this->type = 26;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, *(const wchar_t **)&v185[40], *(unsigned int *)&v185[44]);
    LOBYTE(v210) = 18;
    v18 = INIReader::hasKey(ini, section, &result);
    v186 = v18;
    LOBYTE(v210) = 6;
    if ( result._Myres >= 8 )
    {
      operator delete(result._Bx._Ptr);
      v18 = v186;
    }
    if ( v18 )
    {
      std::wstring::wstring(&units, L"N_TIME");
      LOBYTE(v210) = 19;
      v19 = INIReader::getFloat(ini, section, &units);
      v9 = units._Myres < 8;
      this->timeToIgnoreBase = v19;
      LOBYTE(v210) = 6;
      if ( !v9 )
        operator delete(units._Bx._Ptr);
    }
    std::wstring::wstring(&units, L"COLOR_2");
    LOBYTE(v210) = 20;
    v20 = (const __m128i *)INIReader::getFloat4(ini, (vec4f *)&filename, section, &units);
    v9 = units._Myres < 8;
    LOBYTE(v210) = 6;
    this->color2 = (vec4f)_mm_loadu_si128(v20);
    if ( !v9 )
      operator delete(units._Bx._Ptr);
    std::wstring::wstring(&units, L"INTENSITY_2");
    LOBYTE(v210) = 21;
    intensity3 = INIReader::getFloat(ini, section, &units);
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    v21 = intensity3 * 0.0039215689;
    *(_DWORD *)&v185[44] = L"RPM_TRIGGER";
    this->color2.x = (float)(intensity3 * 0.0039215689) * this->color2.x;
    v22 = v21 * this->color2.y;
    v23 = v21 * this->color2.z;
    this->color2.y = v22;
    v24 = this->color2.w * 0.0039215689;
    this->color2.z = v23;
    this->color2.w = v24;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 22;
    v25 = INIReader::getInt(ini, section, &units);
    v9 = units._Myres < 8;
    this->maxRPM = v25;
    LOBYTE(v210) = 6;
    if ( !v9 )
      operator delete(units._Bx._Ptr);
  }
  if ( !std::wstring::compare(&t, L"SPEED") )
  {
    *(_DWORD *)&v185[44] = L"UNITS";
    this->type = Push2Pass;
    std::wstring::wstring(&result, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 23;
    INIReader::getString(ini, &units, section, &result);
    LOBYTE(v210) = 25;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    if ( std::operator==<wchar_t>(&units, L"KMH") )
    {
      this->speedometerUnits = Kmh;
    }
    else if ( std::operator==<wchar_t>(&units, L"MPH") )
    {
      this->speedometerUnits = Mph;
    }
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
  }
  if ( !std::wstring::compare(&t, L"WATER_TEMP") )
    this->type = 17;
  if ( !std::wstring::compare(&t, L"AMBIENT_TEMP") )
    this->type = 18;
  if ( !std::wstring::compare(&t, L"TOTAL_LAPS") )
    this->type = Push2Pass|FullPosition|0x10;
  if ( !std::wstring::compare(&t, L"CURRENT_LAP") )
  {
    *(_DWORD *)&v185[44] = L"PREFIX";
    this->type = 20;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 26;
    v26 = INIReader::getString(ini, &result, section, &units);
    std::wstring::operator=(&this->preFix, v26);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    std::wstring::wstring(&units, L"POSTFIX");
    LOBYTE(v210) = 27;
    v27 = INIReader::getString(ini, &result, section, &units);
    std::wstring::operator=(&this->postFix, v27);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
  }
  if ( !std::wstring::compare(&t, L"KERS_CHARGE") )
    this->type = 21;
  if ( !std::wstring::compare(&t, L"KERS_LOAD") )
  {
    *(_DWORD *)&v185[44] = L"INVERTED";
    this->type = 28;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 28;
    v28 = INIReader::hasKey(ini, section, &units);
    v186 = v28;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
    {
      operator delete(units._Bx._Ptr);
      v28 = v186;
    }
    if ( v28 )
    {
      std::wstring::wstring(&units, L"INVERTED");
      LOBYTE(v210) = 29;
      v29 = INIReader::getInt(ini, section, &units);
      v9 = units._Myres < 8;
      this->decimals = v29;
      LOBYTE(v210) = 6;
      if ( !v9 )
        operator delete(units._Bx._Ptr);
    }
  }
  if ( std::operator==<wchar_t>(&t, L"EST_LAPS") )
    this->type = 22;
  if ( std::operator==<wchar_t>(&t, L"FUEL_CONS") )
  {
    *(_DWORD *)&v185[44] = L"UNITS";
    this->type = 23;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 30;
    v30 = INIReader::hasKey(ini, section, &units);
    v186 = v30;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
    {
      operator delete(units._Bx._Ptr);
      v30 = v186;
    }
    if ( v30 )
    {
      std::wstring::wstring(&result, L"UNITS");
      LOBYTE(v210) = 31;
      INIReader::getString(ini, &filename, section, &result);
      LOBYTE(v210) = 33;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      if ( std::operator==<wchar_t>(&filename, L"MPG_UK") )
        this->fuelConsumptionUnits = MilesPerGallonUK;
      if ( std::operator==<wchar_t>(&filename, L"MPG_US") )
        this->fuelConsumptionUnits = MilesPerGallonUS;
      if ( std::operator==<wchar_t>(&filename, L"L100") )
        this->fuelConsumptionUnits = LitersPer100;
      LOBYTE(v210) = 6;
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
    }
  }
  if ( std::operator==<wchar_t>(&t, L"PLACE_HOLDER") )
  {
    *(_DWORD *)&v185[44] = L"TEXT";
    this->type = 24;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 34;
    v31 = INIReader::getString(ini, &result, section, &units);
    std::wstring::operator=(&this->preFix, v31);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
  }
  if ( std::operator==<wchar_t>(&t, L"RPM") )
    this->type = Push2Pass|FullPosition;
  if ( std::operator==<wchar_t>(&t, L"MAX_RPM") )
    this->type = 4;
  if ( std::operator==<wchar_t>(&t, L"MAX_SPEED") )
    this->type = 5;
  if ( std::operator==<wchar_t>(&t, L"LAST_LAP") )
  {
    *(_DWORD *)&v185[44] = L"DECIMALS";
    this->type = 9;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 35;
    v32 = INIReader::hasKey(ini, section, &units);
    v186 = v32;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
    {
      operator delete(units._Bx._Ptr);
      v32 = v186;
    }
    if ( v32 )
    {
      std::wstring::wstring(&units, L"DECIMALS");
      LOBYTE(v210) = 36;
      v33 = INIReader::getInt(ini, section, &units);
      v9 = units._Myres < 8;
      this->decimals = v33;
      LOBYTE(v210) = 6;
      if ( !v9 )
        operator delete(units._Bx._Ptr);
    }
  }
  if ( std::operator==<wchar_t>(&t, L"LAPTIME") )
  {
    *(_DWORD *)&v185[44] = L"DECIMALS";
    this->type = Push2Pass|FullPosition|0x8;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 37;
    v34 = INIReader::hasKey(ini, section, &units);
    v186 = v34;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
    {
      operator delete(units._Bx._Ptr);
      v34 = v186;
    }
    if ( v34 )
    {
      std::wstring::wstring(&units, L"DECIMALS");
      LOBYTE(v210) = 38;
      v35 = INIReader::getInt(ini, section, &units);
      v9 = units._Myres < 8;
      this->decimals = v35;
      LOBYTE(v210) = 6;
      if ( !v9 )
        operator delete(units._Bx._Ptr);
    }
  }
  if ( std::operator==<wchar_t>(&t, L"BEST_LAP") )
  {
    *(_DWORD *)&v185[44] = L"DECIMALS";
    this->type = 29;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 39;
    v36 = INIReader::hasKey(ini, section, &units);
    v186 = v36;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
    {
      operator delete(units._Bx._Ptr);
      v36 = v186;
    }
    if ( v36 )
    {
      std::wstring::wstring(&units, L"DECIMALS");
      LOBYTE(v210) = 40;
      v37 = INIReader::getInt(ini, section, &units);
      v9 = units._Myres < 8;
      this->decimals = v37;
      LOBYTE(v210) = 6;
      if ( !v9 )
        operator delete(units._Bx._Ptr);
    }
  }
  if ( std::operator==<wchar_t>(&t, L"TURBO_BOOST") )
    this->type = 13;
  if ( std::operator==<wchar_t>(&t, L"TURBO_LEVEL") )
    this->type = 14;
  if ( std::operator==<wchar_t>(&t, L"POSITION_CAR") )
    this->type = 30;
  if ( std::operator==<wchar_t>(&t, L"POSITION_COUNT") )
    this->type = 31;
  if ( std::operator==<wchar_t>(&t, L"P2P_DASH") )
  {
    *(_DWORD *)&v185[44] = L"COLOR_ACTIVE";
    this->type = 32;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 41;
    v38 = (const __m128i *)INIReader::getFloat4(ini, (vec4f *)&filename, section, &units);
    v9 = units._Myres < 8;
    LOBYTE(v210) = 6;
    this->color2 = (vec4f)_mm_loadu_si128(v38);
    if ( !v9 )
      operator delete(units._Bx._Ptr);
    std::wstring::wstring(&units, L"INTENSITY_ACTIVE");
    LOBYTE(v210) = 42;
    intensity3 = INIReader::getFloat(ini, section, &units);
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    v39 = intensity3 * 0.0039215689;
    *(_DWORD *)&v185[44] = L"COLOR_COOLING";
    this->color2.x = (float)(intensity3 * 0.0039215689) * this->color2.x;
    v40 = v39 * this->color2.y;
    v41 = v39 * this->color2.z;
    this->color2.y = v40;
    v42 = this->color2.w * 0.0039215689;
    this->color2.z = v41;
    this->color2.w = v42;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 43;
    v43 = (const __m128i *)INIReader::getFloat4(ini, (vec4f *)&filename, section, &units);
    v9 = units._Myres < 8;
    LOBYTE(v210) = 6;
    this->color3 = (vec4f)_mm_loadu_si128(v43);
    if ( !v9 )
      operator delete(units._Bx._Ptr);
    std::wstring::wstring(&units, L"INTENSITY_COOLING");
    LOBYTE(v210) = 44;
    intensity3 = INIReader::getFloat(ini, section, &units);
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    v44 = intensity3 * 0.0039215689;
    this->color3.x = (float)(intensity3 * 0.0039215689) * this->color3.x;
    v45 = v44 * this->color3.y;
    v46 = v44 * this->color3.z;
    this->color3.y = v45;
    v47 = this->color3.w * 0.0039215689;
    this->color3.z = v46;
    this->color3.w = v47;
  }
  if ( std::operator==<wchar_t>(&t, L"PERF") )
  {
    *(_DWORD *)&v185[44] = L"DECIMALS";
    this->type = 10;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 45;
    v48 = INIReader::hasKey(ini, section, &units);
    v186 = v48;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
    {
      operator delete(units._Bx._Ptr);
      v48 = v186;
    }
    if ( v48 )
    {
      std::wstring::wstring(&units, L"DECIMALS");
      LOBYTE(v210) = 46;
      this->decimals = INIReader::getInt(ini, section, &units);
      LOBYTE(v210) = 6;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&units);
    }
  }
  if ( std::operator==<wchar_t>(&t, L"TC_LEVEL") )
    this->type = 12;
  if ( std::operator==<wchar_t>(&t, L"ABS_LEVEL") )
    this->type = 16;
  if ( std::operator==<wchar_t>(&t, L"FUEL") )
  {
    *(_DWORD *)&v185[44] = L"PREFIX";
    this->type = Push2Pass|FullPosition|0x4;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 47;
    v49 = INIReader::getString(ini, &result, section, &units);
    std::wstring::operator=(&this->preFix, v49);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    std::wstring::wstring(&units, L"POSTFIX");
    LOBYTE(v210) = 48;
    v50 = INIReader::getString(ini, &result, section, &units);
    std::wstring::operator=(&this->postFix, v50);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    *(_DWORD *)&v185[44] = L"DECIMALS";
    this->decimals = 0;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 49;
    v51 = INIReader::hasKey(ini, section, &units);
    v186 = v51;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
    {
      operator delete(units._Bx._Ptr);
      v51 = v186;
    }
    if ( v51 )
    {
      std::wstring::wstring(&units, L"DECIMALS");
      LOBYTE(v210) = 50;
      this->decimals = INIReader::getInt(ini, section, &units);
      LOBYTE(v210) = 6;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&units);
    }
  }
  if ( std::operator==<wchar_t>(&t, L"FUEL_PERC") )
  {
    *(_DWORD *)&v185[44] = L"PREFIX";
    this->type = 34;
    std::wstring::wstring(&units, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 51;
    v52 = INIReader::getString(ini, &result, section, &units);
    std::wstring::operator=(&this->preFix, v52);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    std::wstring::wstring(&units, L"POSTFIX");
    LOBYTE(v210) = 52;
    v53 = INIReader::getString(ini, &result, section, &units);
    std::wstring::operator=(&this->postFix, v53);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v210) = 6;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    std::wstring::wstring(&units, L"DECIMALS");
    LOBYTE(v210) = 53;
    v54 = INIReader::getInt(ini, section, &units);
    v9 = units._Myres < 8;
    this->decimals = v54;
    LOBYTE(v210) = 6;
    if ( !v9 )
      operator delete(units._Bx._Ptr);
  }
  if ( std::operator==<wchar_t>(&t, L"CLOCK") )
    this->type = 8;
  if ( std::operator==<wchar_t>(&t, L"RPM_GRAPH") )
  {
    *(_DWORD *)&v185[44] = 292;
    this->type = 6;
    *(float *)&v55 = COERCE_FLOAT(operator new(*(_DWORD *)&v185[44]));
    intensity3 = *(float *)&v55;
    LOBYTE(v210) = 54;
    if ( *(float *)&v55 == 0.0 )
    {
      v56 = 0;
    }
    else
    {
      *(_DWORD *)&v185[44] = this->type;
      std::wstring::wstring((std::wstring *)&v185[20], L"RPM_DISPLAY");
      DisplayNode::DisplayNode(v55, *(std::wstring *)&v185[20], *(DigitalItemType *)&v185[44]);
    }
    *(_DWORD *)&v185[44] = L"TEXTURE_BASE";
    LOBYTE(v210) = 6;
    this->displayNode = v56;
    std::wstring::wstring(&result, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 55;
    v57 = INIReader::getString(ini, &units, section, &result);
    LOBYTE(v210) = 56;
    std::wstring::wstring(&v203, L"content/cars/");
    v59 = v58;
    v60 = this->car;
    LOBYTE(v210) = 57;
    v61 = std::operator+<wchar_t>(&v206, v59, &v60->unixName);
    LOBYTE(v210) = 58;
    v62 = std::operator+<wchar_t>(&s, v61, L"/texture/");
    LOBYTE(v210) = 59;
    std::operator+<wchar_t>(&filename, v62, v57);
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( v206._Myres >= 8 )
      operator delete(v206._Bx._Ptr);
    v206._Myres = 7;
    v206._Mysize = 0;
    v206._Bx._Buf[0] = 0;
    if ( v203._Myres >= 8 )
      operator delete(v203._Bx._Ptr);
    v203._Myres = 7;
    v203._Mysize = 0;
    v203._Bx._Buf[0] = 0;
    if ( units._Myres >= 8 )
      operator delete(units._Bx._Ptr);
    units._Myres = 7;
    units._Mysize = 0;
    units._Bx._Buf[0] = 0;
    LOBYTE(v210) = 65;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    if ( std::operator!=<wchar_t>(&filename, L"NULL") )
    {
      if ( Path::fileExists((unsigned int)ini, &filename, 0) )
      {
        *(_DWORD *)&v185[44] = 0;
        *(_DWORD *)&v185[40] = &filename;
        *(_DWORD *)&v185[36] = &v205;
        v63 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->car->game->graphics->resourceStore);
        v64 = ResourceStore::getTexture(v63, *(Texture **)&v185[36], *(const std::wstring **)&v185[40], v185[44]);
        v65 = this->displayNode;
        LOBYTE(v210) = 66;
        Texture::operator=(&v65->txBase, v64);
        LOBYTE(v210) = 65;
        OnSetupAppCreated::~OnSetupAppCreated(&v205);
      }
      else
      {
        intensity3 = COERCE_FLOAT(&v185[24]);
        std::wstring::wstring((std::wstring *)&v185[24], L"\n");
        LOBYTE(v210) = 67;
        v189 = (int)v185;
        std::wstring::wstring((std::wstring *)v185, L" NOT FOUND");
        LOBYTE(v210) = 68;
        v190 = &v184;
        std::wstring::wstring(&v184, &filename);
        LOBYTE(v210) = 69;
        v188 = &v183;
        std::wstring::wstring(&v183, L"[ERROR]: TEXTURE_BASE ");
        LOBYTE(v210) = 70;
        v66 = Console::singleton();
        LOBYTE(v210) = 69;
        v67 = Console::operator<<(v66, v183);
        LOBYTE(v210) = 68;
        v68 = Console::operator<<(v67, v184);
        LOBYTE(v210) = 67;
        v69 = Console::operator<<(v68, *(std::wstring *)v185);
        LOBYTE(v210) = 65;
        Console::operator<<(v69, *(std::wstring *)&v185[24]);
      }
    }
    std::wstring::wstring(&v202, L"TEXTURE_TOP");
    LOBYTE(v210) = 71;
    v70 = INIReader::getString(ini, (std::wstring *)&v205, section, &v202);
    LOBYTE(v210) = 72;
    std::wstring::wstring(&v208, L"content/cars/");
    v72 = v71;
    v73 = this->car;
    LOBYTE(v210) = 73;
    v74 = std::operator+<wchar_t>(&v201, v72, &v73->unixName);
    LOBYTE(v210) = 74;
    v75 = std::operator+<wchar_t>((std::wstring *)&v199, v74, L"/texture/");
    LOBYTE(v210) = 75;
    v76 = std::operator+<wchar_t>(&v204, v75, v70);
    std::wstring::operator=(&filename, v76);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v208);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v205);
    LOBYTE(v210) = 65;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202);
    if ( Path::fileExists((unsigned int)ini, &filename, 0) )
    {
      *(_DWORD *)&v185[44] = 0;
      *(_DWORD *)&v185[40] = &filename;
      *(_DWORD *)&v185[36] = &v205;
      v77 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->car->game->graphics->resourceStore);
      v78 = ResourceStore::getTexture(v77, *(Texture **)&v185[36], *(const std::wstring **)&v185[40], v185[44]);
      v79 = this->displayNode;
      LOBYTE(v210) = 76;
      Texture::operator=(&v79->txTop, v78);
      LOBYTE(v210) = 65;
      OnSetupAppCreated::~OnSetupAppCreated(&v205);
    }
    else
    {
      v188 = (std::wstring *)&v185[24];
      std::wstring::wstring((std::wstring *)&v185[24], L"\n");
      LOBYTE(v210) = 77;
      v190 = (std::wstring *)v185;
      std::wstring::wstring((std::wstring *)v185, L" NOT FOUND");
      LOBYTE(v210) = 78;
      intensity3 = COERCE_FLOAT(&v184);
      std::wstring::wstring(&v184, &filename);
      LOBYTE(v210) = 79;
      v189 = (int)&v183;
      std::wstring::wstring(&v183, L"[ERROR]: TEXTURE_TOP ");
      LOBYTE(v210) = 80;
      v80 = Console::singleton();
      LOBYTE(v210) = 79;
      v81 = Console::operator<<(v80, v183);
      LOBYTE(v210) = 78;
      v82 = Console::operator<<(v81, v184);
      LOBYTE(v210) = 77;
      v83 = Console::operator<<(v82, *(std::wstring *)v185);
      LOBYTE(v210) = 65;
      Console::operator<<(v83, *(std::wstring *)&v185[24]);
    }
    std::wstring::wstring(&v202, L"WIDTH");
    LOBYTE(v210) = 81;
    v84 = INIReader::getFloat(ini, section, &v202);
    v85 = this->displayNode;
    LOBYTE(v210) = 65;
    v85->size.x = v84;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202);
    std::wstring::wstring(&v201, L"HEIGHT");
    LOBYTE(v210) = 82;
    v86 = INIReader::getFloat(ini, section, &v201);
    v87 = this->displayNode;
    LOBYTE(v210) = 65;
    v87->size.y = v86;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
    std::wstring::wstring((std::wstring *)&v199, L"RPM_MIN");
    LOBYTE(v210) = 83;
    v88 = INIReader::getFloat(ini, section, (const std::wstring *)&v199);
    LOBYTE(v210) = 65;
    this->rpmGraphMin = v88;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    std::wstring::wstring(&v204, L"RPM_MAX");
    LOBYTE(v210) = 84;
    this->rpmGraphMax = INIReader::getFloat(ini, section, &v204);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
    LOBYTE(v210) = 6;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  }
  if ( std::operator==<wchar_t>(&t, L"DELTA_GRAPH") )
  {
    *(_DWORD *)&v185[44] = 292;
    this->type = 33;
    v89 = (DisplayNode *)operator new(*(_DWORD *)&v185[44]);
    v188 = (std::wstring *)v89;
    LOBYTE(v210) = 85;
    if ( v89 )
    {
      *(_DWORD *)&v185[44] = this->type;
      std::wstring::wstring((std::wstring *)&v185[20], L"DELTA_DISPLAY");
      DisplayNode::DisplayNode(v89, *(std::wstring *)&v185[20], *(DigitalItemType *)&v185[44]);
    }
    else
    {
      v90 = 0;
    }
    *(_DWORD *)&v185[44] = L"TEXTURE_BASE";
    LOBYTE(v210) = 6;
    this->displayNode = v90;
    std::wstring::wstring(&v204, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 86;
    v91 = INIReader::getString(ini, &s, section, &v204);
    LOBYTE(v210) = 87;
    std::wstring::wstring(&v206, L"content/cars/");
    v93 = v92;
    v94 = this->car;
    LOBYTE(v210) = 88;
    v95 = std::operator+<wchar_t>(&v208, v93, &v94->unixName);
    LOBYTE(v210) = 89;
    v96 = std::operator+<wchar_t>((std::wstring *)&v205, v95, L"/texture/");
    LOBYTE(v210) = 90;
    std::operator+<wchar_t>(&filename, v96, v91);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v205);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v208);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v206);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LOBYTE(v210) = 96;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
    if ( std::operator!=<wchar_t>(&filename, L"NULL") )
    {
      if ( Path::fileExists((unsigned int)ini, &filename, 0) )
      {
        *(_DWORD *)&v185[44] = 0;
        *(_DWORD *)&v185[40] = &filename;
        *(_DWORD *)&v185[36] = &v199;
        v97 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->car->game->graphics->resourceStore);
        v98 = ResourceStore::getTexture(v97, *(Texture **)&v185[36], *(const std::wstring **)&v185[40], v185[44]);
        v99 = this->displayNode;
        LOBYTE(v210) = 97;
        Texture::operator=(&v99->txBase, v98);
        LOBYTE(v210) = 96;
        OnSetupAppCreated::~OnSetupAppCreated(&v199);
      }
      else
      {
        v188 = (std::wstring *)&v185[24];
        std::wstring::wstring((std::wstring *)&v185[24], L"\n");
        LOBYTE(v210) = 98;
        v190 = (std::wstring *)v185;
        std::wstring::wstring((std::wstring *)v185, L" NOT FOUND");
        LOBYTE(v210) = 99;
        intensity3 = COERCE_FLOAT(&v184);
        std::wstring::wstring(&v184, &filename);
        LOBYTE(v210) = 100;
        v189 = (int)&v183;
        std::wstring::wstring(&v183, L"[ERROR]: TEXTURE_BASE ");
        LOBYTE(v210) = 101;
        v100 = Console::singleton();
        LOBYTE(v210) = 100;
        v101 = Console::operator<<(v100, v183);
        LOBYTE(v210) = 99;
        v102 = Console::operator<<(v101, v184);
        LOBYTE(v210) = 98;
        v103 = Console::operator<<(v102, *(std::wstring *)v185);
        LOBYTE(v210) = 96;
        Console::operator<<(v103, *(std::wstring *)&v185[24]);
      }
    }
    std::wstring::wstring((std::wstring *)&v199, L"TEXTURE_TOP");
    LOBYTE(v210) = 102;
    v104 = INIReader::getString(ini, &result, section, (const std::wstring *)&v199);
    LOBYTE(v210) = 103;
    std::wstring::wstring(&v203, L"content/cars/");
    v106 = v105;
    v107 = this->car;
    LOBYTE(v210) = 104;
    v108 = std::operator+<wchar_t>(&units, v106, &v107->unixName);
    LOBYTE(v210) = 105;
    v109 = std::operator+<wchar_t>(&v202, v108, L"/texture/");
    LOBYTE(v210) = 106;
    v110 = std::operator+<wchar_t>(&v201, v109, v104);
    std::wstring::operator=(&filename, v110);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&units);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v203);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v210) = 96;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    if ( Path::fileExists((unsigned int)ini, &filename, 0) )
    {
      *(_DWORD *)&v185[44] = 0;
      *(_DWORD *)&v185[40] = &filename;
      *(_DWORD *)&v185[36] = &v199;
      v111 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->car->game->graphics->resourceStore);
      v112 = ResourceStore::getTexture(v111, *(Texture **)&v185[36], *(const std::wstring **)&v185[40], v185[44]);
      v113 = this->displayNode;
      LOBYTE(v210) = 107;
      Texture::operator=(&v113->txTop, v112);
      LOBYTE(v210) = 96;
      OnSetupAppCreated::~OnSetupAppCreated(&v199);
    }
    else
    {
      v188 = (std::wstring *)&v185[24];
      std::wstring::wstring((std::wstring *)&v185[24], L"\n");
      LOBYTE(v210) = 108;
      v190 = (std::wstring *)v185;
      std::wstring::wstring((std::wstring *)v185, L" NOT FOUND");
      LOBYTE(v210) = 109;
      intensity3 = COERCE_FLOAT(&v184);
      std::wstring::wstring(&v184, &filename);
      LOBYTE(v210) = 110;
      v189 = (int)&v183;
      std::wstring::wstring(&v183, L"[ERROR]: TEXTURE_TOP ");
      LOBYTE(v210) = 111;
      v114 = Console::singleton();
      LOBYTE(v210) = 110;
      v115 = Console::operator<<(v114, v183);
      LOBYTE(v210) = 109;
      v116 = Console::operator<<(v115, v184);
      LOBYTE(v210) = 108;
      v117 = Console::operator<<(v116, *(std::wstring *)v185);
      LOBYTE(v210) = 96;
      Console::operator<<(v117, *(std::wstring *)&v185[24]);
    }
    std::wstring::wstring((std::wstring *)&v199, L"WIDTH");
    LOBYTE(v210) = 112;
    v118 = INIReader::getFloat(ini, section, (const std::wstring *)&v199);
    v119 = this->displayNode;
    LOBYTE(v210) = 96;
    v119->size.x = v118;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    std::wstring::wstring(&v201, L"HEIGHT");
    LOBYTE(v210) = 113;
    v120 = INIReader::getFloat(ini, section, &v201);
    v121 = this->displayNode;
    LOBYTE(v210) = 96;
    v121->size.y = v120;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
    std::wstring::wstring(&v202, L"DIRECTION");
    LOBYTE(v210) = 114;
    v122 = INIReader::getFloat(ini, section, &v202);
    v123 = this->displayNode;
    LOBYTE(v210) = 96;
    v123->trigger = v122;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202);
    std::wstring::wstring(&units, L"DELTA_MAX");
    LOBYTE(v210) = 115;
    v124 = INIReader::getFloat(ini, section, &units);
    LOBYTE(v210) = 96;
    this->rpmGraphMax = v124;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&units);
    std::wstring::wstring(&v203, L"DEBUG");
    LOBYTE(v210) = 116;
    this->rpmGraphMin = (float)INIReader::getInt(ini, section, &v203);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v203);
    LOBYTE(v210) = 6;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  }
  if ( std::operator==<wchar_t>(&t, L"GEAR_TX") )
  {
    *(_DWORD *)&v185[44] = 292;
    this->type = 25;
    v125 = (DisplayNode *)operator new(*(_DWORD *)&v185[44]);
    v188 = (std::wstring *)v125;
    LOBYTE(v210) = 117;
    if ( v125 )
    {
      *(_DWORD *)&v185[44] = this->type;
      std::wstring::wstring((std::wstring *)&v185[20], L"GEAR_TX");
      DisplayNode::DisplayNode(v125, *(std::wstring *)&v185[20], *(DigitalItemType *)&v185[44]);
    }
    else
    {
      v126 = 0;
    }
    *(_DWORD *)&v185[44] = L"TEXTURE_BASE";
    LOBYTE(v210) = 6;
    this->displayNode = v126;
    std::wstring::wstring(&v204, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = 118;
    v127 = INIReader::getString(ini, &s, section, &v204);
    LOBYTE(v210) = 119;
    std::wstring::wstring(&v206, L"content/cars/");
    v129 = v128;
    v130 = this->car;
    LOBYTE(v210) = 120;
    v131 = std::operator+<wchar_t>(&v208, v129, &v130->unixName);
    LOBYTE(v210) = 121;
    v132 = std::operator+<wchar_t>((std::wstring *)&v205, v131, L"/texture/");
    LOBYTE(v210) = 122;
    std::operator+<wchar_t>(&units, v132, v127);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v205);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v208);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v206);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LOBYTE(v210) = 0x80;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
    if ( std::operator!=<wchar_t>(&units, L"NULL") )
    {
      if ( Path::fileExists((unsigned int)ini, &units, 0) )
      {
        *(_DWORD *)&v185[44] = 0;
        *(_DWORD *)&v185[40] = &units;
        *(_DWORD *)&v185[36] = &v199;
        v133 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->car->game->graphics->resourceStore);
        v134 = ResourceStore::getTexture(v133, *(Texture **)&v185[36], *(const std::wstring **)&v185[40], v185[44]);
        v135 = this->displayNode;
        LOBYTE(v210) = -127;
        Texture::operator=(&v135->txBase, v134);
        LOBYTE(v210) = 0x80;
        OnSetupAppCreated::~OnSetupAppCreated(&v199);
      }
      else
      {
        v188 = (std::wstring *)&v185[24];
        std::wstring::wstring((std::wstring *)&v185[24], L"\n");
        LOBYTE(v210) = -126;
        v190 = (std::wstring *)v185;
        std::wstring::wstring((std::wstring *)v185, L" NOT FOUND");
        LOBYTE(v210) = -125;
        intensity3 = COERCE_FLOAT(&v184);
        std::wstring::wstring(&v184, &units);
        LOBYTE(v210) = -124;
        v189 = (int)&v183;
        std::wstring::wstring(&v183, L"[ERROR]: TEXTURE_BASE ");
        LOBYTE(v210) = -123;
        v136 = Console::singleton();
        LOBYTE(v210) = -124;
        v137 = Console::operator<<(v136, v183);
        LOBYTE(v210) = -125;
        v138 = Console::operator<<(v137, v184);
        LOBYTE(v210) = -126;
        v139 = Console::operator<<(v138, *(std::wstring *)v185);
        LOBYTE(v210) = 0x80;
        Console::operator<<(v139, *(std::wstring *)&v185[24]);
      }
    }
    std::wstring::wstring((std::wstring *)&v199, L"WIDTH");
    LOBYTE(v210) = -122;
    v140 = INIReader::getFloat(ini, section, (const std::wstring *)&v199);
    v141 = this->displayNode;
    LOBYTE(v210) = 0x80;
    v141->size.x = v140;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    std::wstring::wstring(&v201, L"HEIGHT");
    LOBYTE(v210) = -121;
    v142 = INIReader::getFloat(ini, section, &v201);
    v143 = this->displayNode;
    LOBYTE(v210) = 0x80;
    v143->size.y = v142;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
    std::wstring::wstring(&v202, L"TRIGGER");
    LOBYTE(v210) = -120;
    v144 = INIReader::getFloat(ini, section, &v202);
    v145 = this->displayNode;
    LOBYTE(v210) = 0x80;
    v145->trigger = v144;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202);
    std::wstring::wstring(&v203, L"ITEM_REF");
    LOBYTE(v210) = -119;
    v146 = INIReader::hasKey(ini, section, &v203);
    LOBYTE(v210) = 0x80;
    v147 = v146;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v203);
    if ( v147 )
    {
      std::wstring::wstring((std::wstring *)&v199, L"ITEM_REF");
      v6 = v192;
      LOBYTE(v210) = -118;
      intensity3 = INIReader::getFloat(v192, section, (const std::wstring *)&v199);
      v148 = (int)intensity3;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
      this->displayNode->valueInt = &(*std::vector<DigitalItem *>::operator[](
                                         (std::vector<DigitalItem *> *)LODWORD(intensity),
                                         v148))->lastGear;
    }
    else
    {
      v6 = v192;
    }
    LOBYTE(v210) = 6;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&units);
  }
  if ( this->type == UnknownItem )
  {
    v188 = (std::wstring *)&v185[24];
    std::wstring::wstring((std::wstring *)&v185[24], L"\n");
    LOBYTE(v210) = -117;
    v190 = (std::wstring *)v185;
    std::wstring::wstring((std::wstring *)v185, L" UNKNOWN");
    LOBYTE(v210) = -116;
    intensity = COERCE_FLOAT(&v184);
    std::wstring::wstring(&v184, &t);
    LOBYTE(v210) = -115;
    intensity3 = COERCE_FLOAT(&v183);
    std::wstring::wstring(&v183, L"[ERROR] DIGITAL ITEM TYPE:");
    LOBYTE(v210) = -114;
    v149 = Console::singleton();
    LOBYTE(v210) = -115;
    v150 = Console::operator<<(v149, v183);
    LOBYTE(v210) = -116;
    v151 = Console::operator<<(v150, v184);
    LOBYTE(v210) = -117;
    v152 = Console::operator<<(v151, *(std::wstring *)v185);
    LOBYTE(v210) = 6;
    Console::operator<<(v152, *(std::wstring *)&v185[24]);
  }
  std::wstring::wstring(&v204, L"PARENT");
  LOBYTE(v210) = -113;
  INIReader::getString(v6, &p, section, &v204);
  LOBYTE(v210) = -111;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
  v153 = this->car;
  *(_DWORD *)&v185[44] = L"NULL";
  v154 = *(float *)&v153->bodyTransform;
  intensity3 = v154;
  if ( std::operator!=<wchar_t>(&p, L"NULL") )
  {
    *(float *)&v155 = COERCE_FLOAT((int)this->car->bodyTransform->findChildByName(this->car->bodyTransform, &p, 1));
    if ( *(float *)&v155 == 0.0 )
    {
      v188 = (std::wstring *)&v185[24];
      std::wstring::wstring((std::wstring *)&v185[24], L"\n");
      LOBYTE(v210) = -110;
      v190 = (std::wstring *)v185;
      std::wstring::wstring((std::wstring *)v185, L" NOT FOUND");
      LOBYTE(v210) = -109;
      intensity = COERCE_FLOAT(&v184);
      std::wstring::wstring(&v184, &p);
      LOBYTE(v210) = -108;
      v189 = (int)&v183;
      std::wstring::wstring(&v183, L"[ERROR] DIGITAL ITEM PARENT:");
      LOBYTE(v210) = -107;
      v156 = Console::singleton();
      LOBYTE(v210) = -108;
      v157 = Console::operator<<(v156, v183);
      LOBYTE(v210) = -109;
      v158 = Console::operator<<(v157, v184);
      LOBYTE(v210) = -110;
      v159 = Console::operator<<(v158, *(std::wstring *)v185);
      LOBYTE(v210) = -111;
      Console::operator<<(v159, *(std::wstring *)&v185[24]);
    }
    else
    {
      v154 = *(float *)&v155;
      intensity3 = *(float *)&v155;
    }
  }
  std::wstring::wstring((std::wstring *)&v199, L"COLOR");
  LOBYTE(v210) = -106;
  v160 = (const __m128i *)INIReader::getFloat4(v6, (vec4f *)&filename, section, (const std::wstring *)&v199);
  LOBYTE(v210) = -111;
  this->color = (vec4f)_mm_loadu_si128(v160);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
  std::wstring::wstring(&v201, L"INTENSITY");
  LOBYTE(v210) = -105;
  v161 = INIReader::getFloat(v6, section, &v201);
  LOBYTE(v210) = -111;
  intensity = v161;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
  v162 = intensity * 0.0039215689;
  v163 = this->displayNode;
  this->color.x = (float)(intensity * 0.0039215689) * this->color.x;
  this->color.y = this->color.y * v162;
  this->color.z = this->color.z * v162;
  this->color.w = this->color.w * 0.0039215689;
  if ( v163 )
  {
    v181 = _mm_loadu_si128((const __m128i *)&this->color);
    *(_DWORD *)&v185[44] = L"POSITION";
    v163->color = (vec4f)v181;
    std::wstring::wstring((std::wstring *)&v199, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = -91;
    v182 = INIReader::getFloat3(v6, (vec3f *)&filename, section, (const std::wstring *)&v199);
    mat44f::setTranslation(&this->displayNode->matrix, v182);
    LOBYTE(v210) = -111;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    (*(void (**)(float, DisplayNode *))(*(_DWORD *)LODWORD(v154) + 4))(
      COERCE_FLOAT(LODWORD(v154)),
      this->displayNode);
  }
  else
  {
    v164 = (StringBlitter3D *)operator new(84);
    v188 = (std::wstring *)v164;
    LOBYTE(v210) = -104;
    if ( v164 )
    {
      std::wstring::wstring((std::wstring *)&v199, L"FONT");
      LOBYTE(v210) = -103;
      v189 = 1;
      v165 = INIReader::getString(v6, (std::wstring *)&v205, section, (const std::wstring *)&v199);
      v210 = 154;
      v193 = 3;
      v189 = 3;
      StringBlitter3D::StringBlitter3D(v164, v165, this->car->game->graphics);
    }
    else
    {
      v166 = 0;
    }
    this->blitter = v166;
    v167 = v193;
    if ( (v193 & 2) != 0 )
    {
      v193 &= 0xFFFFFFFD;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v205);
      v167 = v193;
    }
    v210 = 145;
    if ( (v167 & 1) != 0 )
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    v168 = (TextNode *)operator new(244);
    v188 = (std::wstring *)v168;
    LOBYTE(v210) = -99;
    if ( v168 )
    {
      *(_DWORD *)&v185[44] = this->blitter;
      std::wstring::wstring((std::wstring *)&v185[20], section);
      TextNode::TextNode(v168, *(std::wstring *)&v185[20], *(StringBlitter3D **)&v185[44]);
    }
    else
    {
      v169 = 0;
    }
    v170 = _mm_loadu_si128((const __m128i *)&this->color);
    this->textNode = (TextNode *)v169;
    *(_DWORD *)&v185[44] = L"SIZE";
    LOBYTE(v210) = -111;
    *(__m128i *)(v169 + 216) = v170;
    std::wstring::wstring((std::wstring *)&v199, *(const wchar_t **)&v185[44]);
    LOBYTE(v210) = -98;
    v171 = INIReader::getFloat(v6, section, (const std::wstring *)&v199);
    v172 = this->blitter;
    intensity = v171;
    v173 = StringBlitter3D::getFontSize(v172);
    v174 = this->textNode;
    LOBYTE(v210) = -111;
    v174->scale = intensity / v173;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    std::wstring::wstring(&v201, L"POSITION");
    LOBYTE(v210) = -97;
    v175 = INIReader::getFloat3(v6, (vec3f *)&filename, section, &v201);
    mat44f::setTranslation(&this->textNode->matrix, v175);
    LOBYTE(v210) = -111;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
    std::wstring::wstring(&v202, L"VERSION");
    LOBYTE(v210) = -96;
    v176 = INIReader::hasKey(v6, section, &v202);
    LOBYTE(v210) = -111;
    v177 = v176;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202);
    if ( v177 )
    {
      std::wstring::wstring((std::wstring *)&v199, L"VERSION");
      v178 = v192;
      LOBYTE(v210) = -95;
      v179 = INIReader::getInt(v192, section, (const std::wstring *)&v199);
      LOBYTE(v210) = -111;
      v180 = v179;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
      this->textNode->version = v180;
    }
    else
    {
      v178 = v192;
    }
    std::wstring::wstring((std::wstring *)&v199, L"ALIGN");
    LOBYTE(v210) = -94;
    INIReader::getString(v178, &units, section, (const std::wstring *)&v199);
    LOBYTE(v210) = -92;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
    if ( std::operator==<wchar_t>(&units, L"CENTER") )
      this->textNode->align = eAlignCenter;
    if ( std::operator==<wchar_t>(&units, L"RIGHT") )
      this->textNode->align = eAlignRight;
    (*(void (**)(_DWORD, TextNode *))(*(_DWORD *)LODWORD(intensity3) + 4))(
      LODWORD(intensity3),
      this->textNode);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&units);
  }
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&p);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&t);
}
void DigitalItem::~DigitalItem(DigitalItem *this)
{
  StringBlitter3D *v2; // edi

  v2 = this->blitter;
  if ( v2 )
  {
    StringBlitter3D::~StringBlitter3D(v2);
    operator delete(v2);
  }
  if ( this->postFix._Myres >= 8 )
    operator delete(this->postFix._Bx._Ptr);
  this->postFix._Myres = 7;
  this->postFix._Mysize = 0;
  this->postFix._Bx._Buf[0] = 0;
  if ( this->preFix._Myres >= 8 )
    operator delete(this->preFix._Bx._Ptr);
  this->preFix._Myres = 7;
  this->preFix._Mysize = 0;
  this->preFix._Bx._Buf[0] = 0;
}
void DigitalItem::cleanup(DigitalItem *this)
{
  TextNode *v2; // ecx
  Node *v3; // eax
  TextNode *v4; // ecx
  DisplayNode *v5; // ecx
  Node *v6; // eax
  DisplayNode *v7; // ecx

  v2 = this->textNode;
  if ( v2 )
  {
    v3 = Node::getParent(v2);
    v3->removeChild(v3, this->textNode);
    v4 = this->textNode;
    if ( v4 )
      ((void (*)(TextNode *, int))v4->~Node)(v4, 1);
  }
  v5 = this->displayNode;
  this->textNode = 0;
  if ( v5 )
  {
    v6 = Node::getParent(v5);
    v6->removeChild(v6, this->displayNode);
    v7 = this->displayNode;
    if ( v7 )
      ((void (*)(DisplayNode *, int))v7->~Node)(v7, 1);
  }
  this->displayNode = 0;
}
void DigitalItem::update(DigitalItem *this, float dt)
{
  unsigned int v3; // esi
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  CarAvatar *v7; // eax
  std::wstring *v8; // eax
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *v9; // ecx
  CarAvatar *v10; // eax
  std::wstring *v11; // eax
  int v12; // eax
  int v13; // eax
  double v14; // st7
  std::wostream *v15; // eax
  std::wostream *v16; // ecx
  std::wstring *v17; // eax
  CarAvatar *v18; // eax
  int v19; // eax
  std::wstring *v20; // eax
  CarAvatar *v21; // ecx
  std::wostream *v22; // eax
  std::wostream *v23; // eax
  std::wstring *v24; // eax
  SessionType v25; // eax
  RaceManager *v26; // ecx
  unsigned int v27; // eax
  std::wostream *v28; // eax
  std::wostream *v29; // eax
  std::wstring *v30; // eax
  CarAvatar *v31; // eax
  std::wostream *v32; // eax
  std::wostream *v33; // eax
  std::wstring *v34; // eax
  CarAvatar *v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // eax
  std::wostream *v38; // eax
  std::wstring *v39; // eax
  std::wostream *v40; // eax
  double v41; // st7
  FuelConsumptionUnits v42; // eax
  double v43; // xmm1_8
  std::wstring *v44; // eax
  std::wstring *v45; // ecx
  int v46; // eax
  std::wstring *v47; // eax
  CarAvatar *v48; // ecx
  std::pair<unsigned int,unsigned int> *v49; // eax
  std::wstring *v50; // eax
  CarAvatar *v51; // ecx
  std::pair<unsigned int,unsigned int> *v52; // eax
  std::wstring *v53; // eax
  int v54; // eax
  const std::wstring *v55; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v56; // ecx
  const std::wstring *v57; // eax
  std::wstring *v58; // eax
  int v59; // eax
  const std::wstring *v60; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v61; // ecx
  const std::wstring *v62; // eax
  std::wstring *v63; // eax
  int v64; // eax
  const std::wstring *v65; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v66; // ecx
  const std::wstring *v67; // eax
  std::wstring *v68; // eax
  CarAvatar *v69; // ecx
  unsigned int v70; // eax
  const std::wstring *v71; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v72; // ecx
  const std::wstring *v73; // eax
  const std::wstring *v74; // eax
  const std::wstring *v75; // eax
  std::wstring *v76; // eax
  CarAvatar *v77; // eax
  const std::_Smanip<__int64> *v78; // eax
  std::wostream *v79; // esi
  std::wostream *v80; // eax
  std::wostream *v81; // eax
  std::wostream *v82; // eax
  std::wstring *v83; // eax
  CarAvatar *v84; // ecx
  int v85; // eax
  float v86; // xmm0_4
  float v87; // xmm0_4
  CarAvatar *v88; // ecx
  int v89; // eax
  float v90; // xmm0_4
  float v91; // xmm0_4
  float v92; // xmm0_4
  vec4f *v93; // ecx
  std::wostream *v94; // eax
  std::wostream *v95; // eax
  std::wostream *v96; // eax
  std::wostream *v97; // eax
  std::wstring *v98; // eax
  CarAvatar *v99; // ecx
  std::wostream *v100; // eax
  std::wostream *v101; // eax
  std::wostream *v102; // eax
  std::wostream *v103; // eax
  std::wstring *v104; // eax
  SpeedometerUnits v105; // eax
  __int32 v106; // eax
  float v107; // xmm0_4
  std::wstring *v108; // eax
  CarAvatar *v109; // eax
  std::wstring *v110; // eax
  int *v111; // esi
  int *v112; // eax
  bool v113; // cc
  std::wstring *v114; // eax
  int *v115; // esi
  int *v116; // eax
  std::wstring *v117; // eax
  double v118; // st7
  std::wostream *v119; // eax
  std::wstring *v120; // eax
  std::wstring *v121; // eax
  std::wstring *v122; // eax
  std::wostream *v123; // eax
  CarAvatar *v124; // ecx
  float v125; // xmm0_4
  std::wostream *v126; // eax
  std::wstring *v127; // eax
  int v128; // [esp+8h] [ebp-1028h]
  int v129; // [esp+8h] [ebp-1028h]
  const char *v130; // [esp+8h] [ebp-1028h]
  double v131; // [esp+8h] [ebp-1028h]
  __int64 v132; // [esp+Ch] [ebp-1024h]
  int v133; // [esp+Ch] [ebp-1024h]
  float v134; // [esp+Ch] [ebp-1024h]
  int v135; // [esp+10h] [ebp-1020h]
  const std::wstring *v136; // [esp+10h] [ebp-1020h]
  CarAvatar *v137; // [esp+10h] [ebp-1020h]
  unsigned int v138; // [esp+10h] [ebp-1020h]
  const std::wstring *v139; // [esp+10h] [ebp-1020h]
  const std::wstring *v140; // [esp+10h] [ebp-1020h]
  const std::_Smanip<__int64> *v141; // [esp+10h] [ebp-1020h]
  const std::_Smanip<__int64> *v142; // [esp+10h] [ebp-1020h]
  const std::wstring *v143; // [esp+10h] [ebp-1020h]
  int v144; // [esp+10h] [ebp-1020h]
  int v145; // [esp+10h] [ebp-1020h]
  const std::_Smanip<__int64> *v146; // [esp+10h] [ebp-1020h]
  const std::_Smanip<__int64> *v147; // [esp+14h] [ebp-101Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v148; // [esp+60h] [ebp-FD0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v149; // [esp+110h] [ebp-F20h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v150; // [esp+1C0h] [ebp-E70h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v151; // [esp+270h] [ebp-DC0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v152; // [esp+320h] [ebp-D10h] BYREF
  char v153[12]; // [esp+3D4h] [ebp-C5Ch] BYREF
  char v154[16]; // [esp+3E0h] [ebp-C50h] BYREF
  char v155[16]; // [esp+3F0h] [ebp-C40h] BYREF
  char v156[16]; // [esp+400h] [ebp-C30h] BYREF
  char v157[16]; // [esp+410h] [ebp-C20h] BYREF
  char v158[20]; // [esp+420h] [ebp-C10h] BYREF
  char v159[12]; // [esp+434h] [ebp-BFCh] BYREF
  char v160[16]; // [esp+440h] [ebp-BF0h] BYREF
  char v161[12]; // [esp+450h] [ebp-BE0h] BYREF
  int v162; // [esp+45Ch] [ebp-BD4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v163; // [esp+460h] [ebp-BD0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v164; // [esp+510h] [ebp-B20h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v165; // [esp+5C0h] [ebp-A70h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v166; // [esp+670h] [ebp-9C0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v167; // [esp+720h] [ebp-910h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v168; // [esp+7D0h] [ebp-860h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v169; // [esp+880h] [ebp-7B0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v170; // [esp+930h] [ebp-700h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v171; // [esp+9E0h] [ebp-650h] BYREF
  std::pair<unsigned int,unsigned int> v172; // [esp+A90h] [ebp-5A0h] BYREF
  std::pair<unsigned int,unsigned int> v173; // [esp+A98h] [ebp-598h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v174; // [esp+AA0h] [ebp-590h] BYREF
  KSTime v175; // [esp+B50h] [ebp-4E0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v176; // [esp+B5Ch] [ebp-4D4h] BYREF
  long double v177; // [esp+C0Ch] [ebp-424h] BYREF
  int v178; // [esp+C14h] [ebp-41Ch]
  Session v179; // [esp+C18h] [ebp-418h] BYREF
  std::wstring v180; // [esp+C78h] [ebp-3B8h] BYREF
  std::wstring v181; // [esp+C90h] [ebp-3A0h] BYREF
  std::wstring v182; // [esp+CA8h] [ebp-388h] BYREF
  std::wstring v183; // [esp+CC0h] [ebp-370h] BYREF
  std::wstring v184; // [esp+CD8h] [ebp-358h] BYREF
  std::wstring v185; // [esp+CF0h] [ebp-340h] BYREF
  std::wstring v186; // [esp+D08h] [ebp-328h] BYREF
  std::wstring v187; // [esp+D20h] [ebp-310h] BYREF
  std::wstring v188; // [esp+D38h] [ebp-2F8h] BYREF
  std::wstring v189; // [esp+D50h] [ebp-2E0h] BYREF
  std::wstring v190; // [esp+D68h] [ebp-2C8h] BYREF
  std::wstring v191; // [esp+D80h] [ebp-2B0h] BYREF
  std::wstring v192; // [esp+D98h] [ebp-298h] BYREF
  std::wstring v193; // [esp+DB0h] [ebp-280h] BYREF
  std::wstring v194; // [esp+DC8h] [ebp-268h] BYREF
  std::wstring v195; // [esp+DE0h] [ebp-250h] BYREF
  std::wstring v196; // [esp+DF8h] [ebp-238h] BYREF
  std::wstring v197; // [esp+E10h] [ebp-220h] BYREF
  std::wstring v198; // [esp+E28h] [ebp-208h] BYREF
  std::wstring v199; // [esp+E40h] [ebp-1F0h] BYREF
  std::wstring v200; // [esp+E58h] [ebp-1D8h] BYREF
  std::wstring v201; // [esp+E70h] [ebp-1C0h] BYREF
  std::wstring v202; // [esp+E88h] [ebp-1A8h] BYREF
  std::wstring v203; // [esp+EA0h] [ebp-190h] BYREF
  std::wstring v204; // [esp+EB8h] [ebp-178h] BYREF
  std::wstring v205; // [esp+ED0h] [ebp-160h] BYREF
  std::wstring v206; // [esp+EE8h] [ebp-148h] BYREF
  std::wstring v207; // [esp+F00h] [ebp-130h] BYREF
  std::wstring v208; // [esp+F18h] [ebp-118h] BYREF
  std::wstring v209; // [esp+F30h] [ebp-100h] BYREF
  std::wstring v210; // [esp+F48h] [ebp-E8h] BYREF
  std::wstring v211; // [esp+F60h] [ebp-D0h] BYREF
  std::wstring v212; // [esp+F78h] [ebp-B8h] BYREF
  std::wstring v213; // [esp+F90h] [ebp-A0h] BYREF
  std::wstring result; // [esp+FA8h] [ebp-88h] BYREF
  std::wstring v215; // [esp+FC0h] [ebp-70h] BYREF
  std::wstring v216; // [esp+FD8h] [ebp-58h] BYREF
  std::wstring v217; // [esp+FF0h] [ebp-40h] BYREF
  std::wstring v218; // [esp+1008h] [ebp-28h] BYREF
  int v219; // [esp+1028h] [ebp-8h]
  int v220; // [esp+102Ch] [ebp-4h]
  int retaddr; // [esp+1030h] [ebp+0h]

  HIDWORD(v177) = this;
  *(float *)&v178 = 0.0;
  v3 = Sim::getFocusedCarIndex(this->car->sim);
  if ( CarAvatar::getGuid(this->car) == v3 )
  {
    v4 = this->updateRefresh;
    v5 = 0.0;
    *(float *)&v178 = 0.0;
    if ( v4 == 0.0 )
    {
LABEL_5:
      switch ( this->type )
      {
        case 1:
          v84 = this->car;
          v85 = v84->physicsState.gear;
          if ( v85 > 9 || v85 < 0 )
            return;
          v86 = this->timeToIgnoreBase;
          if ( v86 <= 0.0 )
            goto LABEL_94;
          if ( this->lastGear == v85 || this->timeToIgnore > 0.0 )
          {
            if ( v85 == 1 )
              v87 = this->timeToIgnore - dt;
            else
              v87 = 0.0;
            this->timeToIgnore = v87;
            if ( v87 <= 0.0 )
            {
              this->timeToIgnore = 0.0;
              v85 = v84->physicsState.gear;
LABEL_94:
              this->lastGear = v85;
            }
          }
          else
          {
            this->timeToIgnore = v86;
          }
          std::wstring::operator=(&this->textNode->text, &gears[this->lastGear]);
          return;
        case 2:
          v105 = this->speedometerUnits;
          if ( v105 )
          {
            v106 = v105 - 1;
            if ( v106 )
            {
              if ( v106 != 1 )
              {
LABEL_120:
                std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
                  &v176,
                  3,
                  1);
                v220 = 79;
                std::wostream::operator<<(v176.gap10, (int)*(float *)&v178);
                v108 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                         &v176,
                         &v192);
                std::wstring::operator=(&this->textNode->text, v108);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v192);
                v9 = &v176;
                goto LABEL_141;
              }
              v107 = this->car->physicsState.speed.value * 2.2369363;
            }
            else
            {
              v107 = this->car->physicsState.speed.value * 3.5999999;
            }
          }
          else
          {
            *((float *)&v177 + 1) = Speed::toSystemDefault(&this->car->physicsState.speed);
            v107 = *((float *)&v177 + 1);
          }
          *(float *)&v178 = v107;
          goto LABEL_120;
        case 3:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v176,
            3,
            1);
          v109 = this->car;
          v220 = 80;
          std::wostream::operator<<(v176.gap10, (int)v109->physicsState.engineRPM);
          v110 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v190);
          std::wstring::operator=(&this->textNode->text, v110);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v190);
          v9 = &v176;
          goto LABEL_141;
        case 4:
          v111 = &this->maxRPM;
          v112 = (int *)&v177 + 1;
          v113 = this->maxRPM < (int)this->car->physicsState.engineRPM;
          HIDWORD(v177) = (int)this->car->physicsState.engineRPM;
          if ( !v113 )
            v112 = &this->maxRPM;
          *v111 = *v112;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v176,
            3,
            1);
          v144 = *v111;
          v220 = 81;
          std::wostream::operator<<(v176.gap10, v144);
          v114 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v188);
          std::wstring::operator=(&this->textNode->text, v114);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v188);
          v9 = &v176;
          goto LABEL_141;
        case 5:
          *((float *)&v177 + 1) = Speed::toSystemDefault(&this->car->physicsState.speed);
          v115 = &this->maxSpeed;
          v116 = (int *)&v177 + 1;
          v113 = this->maxSpeed < (int)*((float *)&v177 + 1);
          HIDWORD(v177) = (int)*((float *)&v177 + 1);
          if ( !v113 )
            v116 = &this->maxSpeed;
          *v115 = *v116;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v176,
            3,
            1);
          v145 = *v115;
          v220 = 82;
          std::wostream::operator<<(v176.gap10, v145);
          v117 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v186);
          std::wstring::operator=(&this->textNode->text, v117);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v186);
          v9 = &v176;
          goto LABEL_141;
        case 6:
          v118 = saturate(
                   (float)(this->car->physicsState.engineRPM - this->rpmGraphMin)
                 / (float)(this->rpmGraphMax - this->rpmGraphMin));
          goto LABEL_129;
        case 7:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v149,
            3,
            1);
          v220 = 77;
          v134 = this->car->physicsState.fuel;
          std::setprecision(v158, this->decimals, this->decimals >> 31);
          v94 = std::operator<<<wchar_t>((std::wostream *)v149.gap10, &this->preFix);
          v95 = (std::wostream *)std::wostream::operator<<(v94, std::fixed);
          v96 = std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(
                  v95,
                  (const std::_Smanip<__int64> *)LODWORD(v134));
          v97 = (std::wostream *)std::wostream::operator<<(v96);
          std::operator<<<wchar_t>(v97, &this->postFix);
          v98 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v149, &v196);
          std::wstring::operator=(&this->textNode->text, v98);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v196);
          v9 = &v149;
          goto LABEL_141;
        case 8:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v150,
            3,
            1);
          v77 = this->car;
          v220 = 76;
          ksTimeFromAngle(&v175, v77->game->graphics->lightingSettings.angle);
          v78 = (const std::_Smanip<__int64> *)std::setw(v160, 2, 0);
          v79 = std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>((std::wostream *)v150.gap10, v78);
          *(_WORD *)&v79->gap0[*(_DWORD *)(*(_DWORD *)v79->gap0 + 4) + 64] = 48;
          std::setw(v156, 2, 0);
          v80 = (std::wostream *)std::wostream::operator<<(v79, v175.hours);
          v81 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v80, v130);
          v82 = std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(v81, &Manip);
          v133 = v175.hours;
          *(_WORD *)&v82->gap0[*(_DWORD *)(*(_DWORD *)v82->gap0 + 4) + 64] = 48;
          std::wostream::operator<<(v82, v133);
          v83 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v150, &v198);
          std::wstring::operator=((std::wstring *)(*(_DWORD *)(HIDWORD(v177) + 52) + 188), v83);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v198);
          v9 = &v150;
          goto LABEL_141;
        case 9:
          *(_DWORD *)v167.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v167.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v167.gap68);
          v220 = 59;
          v178 = 0x4000;
          std::wiostream::basic_iostream<wchar_t>(&v167, &v167.gap10[8], 0);
          v220 = 60;
          *(_DWORD *)&v167.gap0[*(_DWORD *)(*(_DWORD *)v167.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v166.gap68[*(_DWORD *)(*(_DWORD *)v167.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v167.gap0 + 4)
                                                                             - 104;
          std::wstreambuf::wstreambuf(&v167.gap10[8]);
          *(_DWORD *)&v167.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v167.gap10[64] = 0;
          *(_DWORD *)&v167.gap10[68] = 0;
          v59 = this->decimals;
          v220 = 62;
          if ( v59 )
          {
            v62 = timeToString(&v216, this->car->physicsState.lastLap, v59);
            LOBYTE(v220) = 64;
            std::operator<<<wchar_t>((std::wostream *)v167.gap10, v62);
            v61 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v216;
          }
          else
          {
            v60 = timeToSecsString(&v215, this->car->physicsState.lastLap);
            LOBYTE(v220) = 63;
            std::operator<<<wchar_t>((std::wostream *)v167.gap10, v60);
            v61 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v215;
          }
          LOBYTE(v220) = 62;
          std::wstring::~wstring(v61);
          v63 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v167, &v212);
          std::wstring::operator=(&this->textNode->text, v63);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v212);
          v9 = &v167;
          goto LABEL_141;
        case 0xA:
          *(_DWORD *)v168.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v168.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v168.gap68);
          v220 = 53;
          v178 = 0x2000;
          std::wiostream::basic_iostream<wchar_t>(&v168, &v168.gap10[8], 0);
          v220 = 54;
          *(_DWORD *)&v168.gap0[*(_DWORD *)(*(_DWORD *)v168.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v167.gap68[*(_DWORD *)(*(_DWORD *)v168.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v168.gap0 + 4)
                                                                             - 104;
          std::wstreambuf::wstreambuf(&v168.gap10[8]);
          *(_DWORD *)&v168.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v168.gap10[64] = 0;
          *(_DWORD *)&v168.gap10[68] = 0;
          v54 = this->decimals;
          v220 = 56;
          if ( v54 )
          {
            v57 = timeToDiffString(&v199, (int)(float)(this->car->physicsState.performanceMeter * 1000.0), v54);
            LOBYTE(v220) = 58;
            std::operator<<<wchar_t>((std::wostream *)v168.gap10, v57);
            v56 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199;
          }
          else
          {
            v55 = timeToDiffString(&v185, (int)(float)(this->car->physicsState.performanceMeter * 1000.0), 3);
            LOBYTE(v220) = 57;
            std::operator<<<wchar_t>((std::wostream *)v168.gap10, v55);
            v56 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185;
          }
          LOBYTE(v220) = 56;
          std::wstring::~wstring(v56);
          v58 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v168, &v189);
          std::wstring::operator=(&this->textNode->text, v58);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v189);
          v9 = &v168;
          goto LABEL_141;
        case 0xB:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v152,
            3,
            1);
          v69 = this->car;
          v220 = 71;
          v70 = v69->physicsState.lapTime;
          if ( v70 >= 0x2710 )
          {
            if ( this->decimals )
            {
              v75 = timeToString(&v202, v70, this->decimals);
              LOBYTE(v220) = 75;
              std::operator<<<wchar_t>((std::wostream *)v152.gap10, v75);
              v72 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202;
            }
            else
            {
              v74 = timeToSecsString(&v204, v70);
              LOBYTE(v220) = 74;
              std::operator<<<wchar_t>((std::wostream *)v152.gap10, v74);
              v72 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204;
            }
          }
          else if ( this->decimals )
          {
            v73 = timeToString(&v206, v69->physicsState.lastLap, this->decimals);
            LOBYTE(v220) = 73;
            std::operator<<<wchar_t>((std::wostream *)v152.gap10, v73);
            v72 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v206;
          }
          else
          {
            v71 = timeToSecsString(&v208, v69->physicsState.lastLap);
            LOBYTE(v220) = 72;
            std::operator<<<wchar_t>((std::wostream *)v152.gap10, v71);
            v72 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v208;
          }
          LOBYTE(v220) = 71;
          std::wstring::~wstring(v72);
          v76 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &v200);
          std::wstring::operator=(&this->textNode->text, v76);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v200);
          v9 = &v152;
          goto LABEL_141;
        case 0xC:
          *(_DWORD *)v176.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v176.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v176.gap68);
          v220 = 49;
          v178 = 4096;
          std::wiostream::basic_iostream<wchar_t>(&v176, &v176.gap10[8], 0);
          v220 = 50;
          *(_DWORD *)&v176.gap0[*(_DWORD *)(*(_DWORD *)v176.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v175.seconds + *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)
                                                                                  - 104;
          std::wstreambuf::wstreambuf(&v176.gap10[8]);
          *(_DWORD *)&v176.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v176.gap10[64] = 0;
          *(_DWORD *)&v176.gap10[68] = 0;
          v51 = this->car;
          v220 = 52;
          v52 = CarAvatar::getTCMode(v51, &v173);
          std::wostream::operator<<(v176.gap10, v52->first);
          v53 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v201);
          std::wstring::operator=(&this->textNode->text, v53);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
          v9 = &v176;
          goto LABEL_141;
        case 0xD:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v176,
            3,
            1);
          v220 = 83;
          std::setprecision(v154, 1, 0);
          v119 = (std::wostream *)std::wostream::operator<<(v176.gap10, std::fixed);
          std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(v119, v147);
          std::wostream::operator<<(&v176.gap10[4]);
          v120 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v184);
          std::wstring::operator=(&this->textNode->text, v120);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v184);
          v9 = &v176;
          goto LABEL_141;
        case 0xE:
          *((float *)&v177 + 1) = _roundf(this->car->physicsState.turboBoostLevel * 10.0) * 10.0;
          v121 = std::to_wstring(&v180, (int)*((float *)&v177 + 1));
          v220 = 84;
          v122 = std::operator+<wchar_t>(&v182, v121, L"%");
          std::wstring::operator=(&this->textNode->text, v122);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v182);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v180);
          return;
        case 0xF:
          *(_DWORD *)v176.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v176.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v176.gap68);
          v220 = 41;
          v178 = 1024;
          std::wiostream::basic_iostream<wchar_t>(&v176, &v176.gap10[8], 0);
          v220 = 42;
          *(_DWORD *)&v176.gap0[*(_DWORD *)(*(_DWORD *)v176.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v175.seconds + *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)
                                                                                  - 104;
          std::wstreambuf::wstreambuf(&v176.gap10[8]);
          *(_DWORD *)&v176.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v176.gap10[64] = 0;
          *(_DWORD *)&v176.gap10[68] = 0;
          v46 = this->tyreNumber;
          v220 = 44;
          std::wostream::operator<<(v176.gap10, (int)this->car->physicsState.tyreThermalStates[v46].dynamicPressure);
          v47 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v203);
          std::wstring::operator=(&this->textNode->text, v47);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v203);
          v9 = &v176;
          goto LABEL_141;
        case 0x10:
          *(_DWORD *)v176.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v176.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v176.gap68);
          v220 = 45;
          v178 = 2048;
          std::wiostream::basic_iostream<wchar_t>(&v176, &v176.gap10[8], 0);
          v220 = 46;
          *(_DWORD *)&v176.gap0[*(_DWORD *)(*(_DWORD *)v176.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v175.seconds + *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)
                                                                                  - 104;
          std::wstreambuf::wstreambuf(&v176.gap10[8]);
          *(_DWORD *)&v176.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v176.gap10[64] = 0;
          *(_DWORD *)&v176.gap10[68] = 0;
          v48 = this->car;
          v220 = 48;
          v49 = CarAvatar::getABSMode(v48, &v172);
          std::wostream::operator<<(v176.gap10, v49->first);
          v50 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v191);
          std::wstring::operator=(&this->textNode->text, v50);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v191);
          v9 = &v176;
          goto LABEL_141;
        case 0x11:
          *(_DWORD *)v176.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v176.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v176.gap68);
          v220 = 0;
          v178 = 1;
          std::wiostream::basic_iostream<wchar_t>(&v176, &v176.gap10[8], 0);
          v220 = 1;
          *(_DWORD *)&v176.gap0[*(_DWORD *)(*(_DWORD *)v176.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v175.seconds + *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)
                                                                                  - 104;
          std::wstreambuf::wstreambuf(&v176.gap10[8]);
          *(_DWORD *)&v176.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v176.gap10[64] = 0;
          *(_DWORD *)&v176.gap10[68] = 0;
          v7 = this->car;
          v220 = 3;
          std::wostream::operator<<(v176.gap10, (int)v7->physicsState.water);
          v8 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &result);
          std::wstring::operator=(&this->textNode->text, v8);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v9 = &v176;
          goto LABEL_141;
        case 0x12:
          *(_DWORD *)v176.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v176.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v176.gap68);
          v220 = 4;
          v178 = 2;
          std::wiostream::basic_iostream<wchar_t>(&v176, &v176.gap10[8], 0);
          v220 = 5;
          *(_DWORD *)&v176.gap0[*(_DWORD *)(*(_DWORD *)v176.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v175.seconds + *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)
                                                                                  - 104;
          std::wstreambuf::wstreambuf(&v176.gap10[8]);
          *(_DWORD *)&v176.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v176.gap10[64] = 0;
          *(_DWORD *)&v176.gap10[68] = 0;
          v10 = this->car;
          v220 = 7;
          std::wostream::operator<<(v176.gap10, (int)v10->sim->physicsAvatar->engine.ambientTemperature);
          v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v213);
          std::wstring::operator=(&this->textNode->text, v11);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v213);
          v9 = &v176;
          goto LABEL_141;
        case 0x13:
          *(_DWORD *)v166.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v166.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v166.gap68);
          v220 = 12;
          v178 = 8;
          std::wiostream::basic_iostream<wchar_t>(&v166, &v166.gap10[8], 0);
          v220 = 13;
          *(_DWORD *)&v166.gap0[*(_DWORD *)(*(_DWORD *)v166.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v165.gap68[*(_DWORD *)(*(_DWORD *)v166.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v166.gap0 + 4)
                                                                             - 104;
          std::wstreambuf::wstreambuf(&v166.gap10[8]);
          *(_DWORD *)&v166.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v166.gap10[64] = 0;
          *(_DWORD *)&v166.gap10[68] = 0;
          v18 = this->car;
          v220 = 15;
          if ( RaceManager::getCurrentSessionType(v18->sim->raceManager) == Race )
          {
            v19 = RaceManager::getCurrentSessionIndex(this->car->sim->raceManager);
            v135 = RaceManager::getSessionInfo(this->car->sim->raceManager, &v179, v19)->laps;
            LOBYTE(v220) = 16;
            std::wostream::operator<<(v166.gap10, v135);
            LOBYTE(v220) = 15;
            Session::~Session(&v179);
          }
          else
          {
            std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v166.gap10, "---");
          }
          v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v166, &v211);
          std::wstring::operator=(&this->textNode->text, v20);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v211);
          v9 = &v166;
          goto LABEL_141;
        case 0x14:
          *(_DWORD *)v163.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v163.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v163.gap68);
          retaddr = 17;
          v179.sessionType = 16;
          std::wiostream::basic_iostream<wchar_t>(&v163.gap0[4], &v163.gap10[12], 0);
          v219 = 18;
          *(int *)((char *)&v162 + *(_DWORD *)(v162 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v161[*(_DWORD *)(v162 + 4) + 8] = *(_DWORD *)(v162 + 4) - 104;
          std::wstreambuf::wstreambuf(&v163.gap10[4]);
          *(_DWORD *)&v163.gap10[4] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v163.gap10[60] = 0;
          *(_DWORD *)&v163.gap10[64] = 0;
          v21 = this->car;
          v219 = 20;
          v128 = RaceManager::getLapCount(v21->sim->raceManager, v21) + 1;
          v22 = std::operator<<<wchar_t>((std::wostream *)((char *)&v163._Chcount + 4), &this->preFix);
          v23 = (std::wostream *)std::wostream::operator<<(v22, v128);
          std::operator<<<wchar_t>(v23, v136);
          v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v163, &v195);
          std::wstring::operator=(&this->textNode->text, v24);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v195);
          v9 = &v163;
          goto LABEL_141;
        case 0x15:
          *(_DWORD *)v176.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v176.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v176.gap68);
          v220 = 29;
          v178 = 128;
          std::wiostream::basic_iostream<wchar_t>(&v176, &v176.gap10[8], 0);
          v220 = 30;
          *(_DWORD *)&v176.gap0[*(_DWORD *)(*(_DWORD *)v176.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v175.seconds + *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)
                                                                                  - 104;
          std::wstreambuf::wstreambuf(&v176.gap10[8]);
          *(_DWORD *)&v176.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v176.gap10[64] = 0;
          *(_DWORD *)&v176.gap10[68] = 0;
          v35 = this->car;
          v220 = 32;
          std::wostream::operator<<(v176.gap10, (int)(float)(v35->physicsState.kersCharge * 100.0));
          v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &v207);
          std::wstring::operator=(&this->textNode->text, v36);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v207);
          v9 = &v176;
          goto LABEL_141;
        case 0x16:
          *(_DWORD *)v170.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v170.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v170.gap68);
          v179.sessionType = 256;
          std::wiostream::basic_iostream<wchar_t>(&v170.gap0[4], &v170.gap10[12], 0);
          *(_DWORD *)&v170.gap0[*(_DWORD *)(*(_DWORD *)&v170.gap0[4] + 4) + 4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v170.gap0[*(_DWORD *)(*(_DWORD *)&v170.gap0[4] + 4)] = *(_DWORD *)(*(_DWORD *)&v170.gap0[4] + 4)
                                                                           - 104;
          std::wstreambuf::wstreambuf(&v170.gap10[12]);
          *(_DWORD *)&v170.gap10[12] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v170.gap10[68] = 0;
          *(_DWORD *)&v170.gap10[72] = 0;
          retaddr = 36;
          std::setprecision(v153, 1, 0);
          v38 = (std::wostream *)std::wostream::operator<<(&v170.gap10[4], std::fixed);
          std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(v38, v141);
          if ( this->car->physicsState.fuelLaps >= 0.0 )
            std::wostream::operator<<(v170.gap10);
          else
            std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v170.gap10, "--.-");
          v39 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v170, &v205);
          std::wstring::operator=(&this->textNode->text, v39);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v205);
          v9 = &v170;
          goto LABEL_141;
        case 0x17:
          *(_DWORD *)v174.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v174.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v174.gap68);
          v179.sessionType = 512;
          std::wiostream::basic_iostream<wchar_t>(&v174.gap0[4], &v174.gap10[12], 0);
          *(_DWORD *)&v174.gap0[*(_DWORD *)(*(_DWORD *)&v174.gap0[4] + 4) + 4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v174.gap0[*(_DWORD *)(*(_DWORD *)&v174.gap0[4] + 4)] = *(_DWORD *)(*(_DWORD *)&v174.gap0[4] + 4)
                                                                           - 104;
          std::wstreambuf::wstreambuf(&v174.gap10[12]);
          *(_DWORD *)&v174.gap10[12] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v174.gap10[68] = 0;
          *(_DWORD *)&v174.gap10[72] = 0;
          retaddr = 40;
          std::setprecision(v159, 1, 0);
          v40 = (std::wostream *)std::wostream::operator<<(&v174.gap10[4], std::fixed);
          std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(v40, v142);
          v41 = CarAvatar::getKmPerLiter(this->car);
          v42 = this->fuelConsumptionUnits;
          v177 = v41;
          switch ( v42 )
          {
            case KmPerLiter:
              LODWORD(v43) = LODWORD(v177);
              if ( v177 > 0.0 && v177 <= 99.0 )
                goto LABEL_56;
              goto LABEL_45;
            case MilesPerGallonUK:
              if ( v177 <= 0.0 || v177 > 99.0 )
                goto LABEL_45;
              v43 = v177 * 2.819999933242798;
              goto LABEL_56;
            case MilesPerGallonUS:
              if ( v177 <= 0.0 || v177 > 99.0 )
                goto LABEL_45;
              v43 = v177 * 2.349999904632568;
LABEL_56:
              std::wostream::operator<<(v174.gap10, LODWORD(v43));
              break;
            case LitersPer100:
              if ( v177 <= 0.0 || v177 > 99.0 )
LABEL_45:
                std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v174.gap10, "--.-");
              else
                std::wostream::operator<<(v174.gap10, COERCE_UNSIGNED_INT64(100.0 / v177));
              break;
            default:
              break;
          }
          v44 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v174, &v183);
          std::wstring::operator=(&this->textNode->text, v44);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v183);
          v9 = &v174;
          goto LABEL_141;
        case 0x18:
          v45 = &this->textNode->text;
          if ( v45 != &this->preFix )
            std::wstring::assign(v45, &this->preFix, 0, 0xFFFFFFFF);
          return;
        case 0x1A:
          v88 = this->car;
          v89 = v88->physicsState.gear;
          if ( v89 > 9 || v89 < 0 )
            return;
          v90 = this->timeToIgnoreBase;
          if ( v90 <= 0.0 )
            goto LABEL_107;
          if ( this->lastGear == v89 || this->timeToIgnore > 0.0 )
          {
            if ( v89 == 1 )
              v91 = this->timeToIgnore - dt;
            else
              v91 = 0.0;
            this->timeToIgnore = v91;
            if ( v91 <= 0.0 )
            {
              this->timeToIgnore = 0.0;
              v89 = v88->physicsState.gear;
LABEL_107:
              this->lastGear = v89;
            }
          }
          else
          {
            this->timeToIgnore = v90;
          }
          v92 = v88->physicsState.engineRPM;
          v93 = &this->color2;
          if ( v92 < (float)this->maxRPM )
            v93 = &this->color;
          this->textNode->color = (vec4f)_mm_loadu_si128((const __m128i *)v93);
          std::wstring::operator=(&this->textNode->text, &gears[this->lastGear]);
          return;
        case 0x1B:
          v12 = this->tyreNumber;
          if ( v12 )
          {
            v13 = v12 - 1;
            if ( v13 )
            {
              if ( v13 == 1 )
                v5 = this->car->physicsState.accG.z;
            }
            else
            {
              v5 = this->car->physicsState.accG.y;
            }
          }
          else
          {
            v5 = this->car->physicsState.accG.x;
          }
          v14 = clamp<float>(v5, this->rpmGraphMin, this->rpmGraphMax);
          *(_DWORD *)v171.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v171.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          *((float *)&v177 + 1) = v14;
          std::wios::wios(v171.gap68);
          v220 = 8;
          v178 = 4;
          std::wiostream::basic_iostream<wchar_t>(&v171, &v171.gap10[8], 0);
          v220 = 9;
          *(_DWORD *)&v171.gap0[*(_DWORD *)(*(_DWORD *)v171.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v170.gap68[*(_DWORD *)(*(_DWORD *)v171.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v171.gap0 + 4)
                                                                             - 104;
          std::wstreambuf::wstreambuf(&v171.gap10[8]);
          *(_DWORD *)&v171.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v171.gap10[64] = 0;
          *(_DWORD *)&v171.gap10[68] = 0;
          v132 = this->decimals;
          v220 = 11;
          std::setprecision(v161, v132, HIDWORD(v132));
          v15 = (std::wostream *)std::wostream::operator<<(v171.gap10, std::fixed);
          std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(v15, v147);
          if ( !this->lastGear )
            goto LABEL_19;
          if ( *(float *)&v178 <= 0.0 )
          {
            if ( *(float *)&v178 >= 0.0 )
LABEL_19:
              v16 = (std::wostream *)&v171.gap10[4];
            else
              v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v171.gap10[4], L"-");
          }
          else
          {
            v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v171.gap10[4], L"+");
          }
          std::wostream::operator<<(v16);
          v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v171, &v181);
          std::wstring::operator=(&this->textNode->text, v17);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v181);
          v9 = &v171;
LABEL_141:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(v9);
          return;
        case 0x1C:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v151,
            3,
            1);
          v220 = 85;
          std::setprecision(v155, 0, 0);
          v123 = (std::wostream *)std::wostream::operator<<(&v151.gap10[4], std::fixed);
          std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(v123, v146);
          v124 = this->car;
          if ( v124->physicsInfo.hasKERS )
          {
            v125 = (float)(v124->physicsState.kersCurrentKJ / v124->physicsInfo.kersMaxJ) * 100000.0;
            if ( this->decimals )
              clamp<float>(v125, 0.0, 100.0);
            else
              clamp<float>(100.0 - v125, 0.0, 100.0);
            v126 = (std::wostream *)std::wostream::operator<<(v151.gap10);
            std::operator<<<wchar_t>(v126, &this->postFix);
          }
          v127 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v151, &v197);
          std::wstring::operator=(&this->textNode->text, v127);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v197);
          v9 = &v151;
          goto LABEL_141;
        case 0x1D:
          *(_DWORD *)v165.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v165.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v165.gap68);
          v220 = 65;
          v178 = 0x8000;
          std::wiostream::basic_iostream<wchar_t>(&v165, &v165.gap10[8], 0);
          v220 = 66;
          *(_DWORD *)&v165.gap0[*(_DWORD *)(*(_DWORD *)v165.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v164.gap68[*(_DWORD *)(*(_DWORD *)v165.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v165.gap0 + 4)
                                                                             - 104;
          std::wstreambuf::wstreambuf(&v165.gap10[8]);
          *(_DWORD *)&v165.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v165.gap10[64] = 0;
          *(_DWORD *)&v165.gap10[68] = 0;
          v64 = this->decimals;
          v220 = 68;
          if ( v64 )
          {
            v67 = timeToString(&v217, this->car->physicsState.bestLap, v64);
            LOBYTE(v220) = 70;
            std::operator<<<wchar_t>((std::wostream *)v165.gap10, v67);
            v66 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v217;
          }
          else
          {
            v65 = timeToSecsString(&v218, this->car->physicsState.bestLap);
            LOBYTE(v220) = 69;
            std::operator<<<wchar_t>((std::wostream *)v165.gap10, v65);
            v66 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v218;
          }
          LOBYTE(v220) = 68;
          std::wstring::~wstring(v66);
          v68 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v165, &v210);
          std::wstring::operator=(&this->textNode->text, v68);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v210);
          v9 = &v165;
          goto LABEL_141;
        case 0x1E:
          *(_DWORD *)v169.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v169.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v169.gap68);
          v179.sessionType = 32;
          std::wiostream::basic_iostream<wchar_t>(&v169.gap0[4], &v169.gap10[12], 0);
          *(_DWORD *)&v169.gap0[*(_DWORD *)(*(_DWORD *)&v169.gap0[4] + 4) + 4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v169.gap0[*(_DWORD *)(*(_DWORD *)&v169.gap0[4] + 4)] = *(_DWORD *)(*(_DWORD *)&v169.gap0[4] + 4)
                                                                           - 104;
          std::wstreambuf::wstreambuf(&v169.gap10[12]);
          *(_DWORD *)&v169.gap10[12] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v169.gap10[68] = 0;
          *(_DWORD *)&v169.gap10[72] = 0;
          retaddr = 24;
          v25 = RaceManager::getCurrentSessionType(this->car->sim->raceManager);
          v137 = this->car;
          v26 = v137->sim->raceManager;
          if ( v25 == Race )
            v27 = RaceManager::getCarRealTimePosition(v26, v137) + 1;
          else
            v27 = RaceManager::getCarLeaderboardPosition(v26, v137);
          v138 = v27;
          v28 = std::operator<<<wchar_t>((std::wostream *)&v169.gap10[4], &this->preFix);
          v29 = (std::wostream *)std::wostream::operator<<(v28, v138);
          std::operator<<<wchar_t>(v29, v139);
          v30 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v169, &v209);
          std::wstring::operator=(&this->textNode->text, v30);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v209);
          v9 = &v169;
          goto LABEL_141;
        case 0x1F:
          *(_DWORD *)v164.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v164.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v164.gap68);
          retaddr = 25;
          v179.sessionType = 64;
          std::wiostream::basic_iostream<wchar_t>(&v164.gap0[4], &v164.gap10[12], 0);
          v219 = 26;
          *(_DWORD *)&v163.gap68[*(_DWORD *)(*(_DWORD *)&v163.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v163.gap68[*(_DWORD *)(*(_DWORD *)&v163.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v163.gap68[68]
                                                                                               + 4)
                                                                                   - 104;
          std::wstreambuf::wstreambuf(&v164.gap10[4]);
          *(_DWORD *)&v164.gap10[4] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v164.gap10[60] = 0;
          *(_DWORD *)&v164.gap10[64] = 0;
          v31 = this->car;
          v219 = 28;
          v129 = v31->sim->cars._Mylast - v31->sim->cars._Myfirst;
          v32 = std::operator<<<wchar_t>((std::wostream *)((char *)&v164._Chcount + 4), &this->preFix);
          v33 = (std::wostream *)std::wostream::operator<<(v32, v129);
          std::operator<<<wchar_t>(v33, v140);
          v34 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v164, &v187);
          std::wstring::operator=(&this->textNode->text, v34);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v187);
          v9 = &v164;
          goto LABEL_141;
        case 0x20:
          v37 = std::to_wstring(&v193, this->car->physicsState.p2pActivations);
          std::wstring::operator=(&this->textNode->text, v37);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v193);
          switch ( this->car->physicsState.p2pStatus )
          {
            case 1u:
              this->textNode->color = (vec4f)_mm_loadu_si128((const __m128i *)&this->color3);
              break;
            case 2u:
              this->textNode->color = (vec4f)_mm_loadu_si128((const __m128i *)&this->color);
              break;
            case 3u:
              this->textNode->color = (vec4f)_mm_loadu_si128((const __m128i *)&this->color2);
              break;
          }
          return;
        case 0x21:
          if ( this->rpmGraphMin <= 0.0 )
          {
            v118 = saturate(this->car->physicsState.performanceMeter / this->rpmGraphMax);
LABEL_129:
            this->displayNode->blendX = v118;
          }
          else
          {
            this->displayNode->blendX = 1.0;
          }
          return;
        case 0x22:
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v148,
            3,
            1);
          v99 = this->car;
          v220 = 78;
          v177 = saturate(v99->physicsState.fuel / v99->physicsInfo.maxFuel) * 100.0;
          v131 = ceil<int>((int)v177);
          std::setprecision(v157, this->decimals, this->decimals >> 31);
          v100 = std::operator<<<wchar_t>((std::wostream *)v148.gap10, &this->preFix);
          v101 = (std::wostream *)std::wostream::operator<<(v100, std::fixed);
          v102 = std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(
                   v101,
                   (const std::_Smanip<__int64> *)HIDWORD(v131));
          v103 = (std::wostream *)std::wostream::operator<<(v102, &this->postFix);
          std::operator<<<wchar_t>(v103, v143);
          v104 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v148, &v194);
          std::wstring::operator=(&this->textNode->text, v104);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v194);
          v9 = &v148;
          goto LABEL_141;
        default:
          return;
      }
    }
    v6 = this->currentRefresh + dt;
    this->currentRefresh = v6;
    if ( v4 <= v6 )
    {
      this->currentRefresh = 0.0;
      goto LABEL_5;
    }
  }
}
