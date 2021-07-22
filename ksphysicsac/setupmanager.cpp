#include "setupmanager.h
void SetupManager::~SetupManager(SetupManager *this)
{
  if ( this->gearSettings._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->gearSettings);
    operator delete(this->gearSettings._Myfirst);
    this->gearSettings._Myfirst = 0;
    this->gearSettings._Mylast = 0;
    this->gearSettings._Myend = 0;
  }
  std::vector<SetupItem>::_Tidy(&this->items);
}
SetupItem *SetupManager::getSetupItem(SetupManager *this, const std::wstring *name)
{
  SetupItem *v2; // esi
  SetupItem *v3; // edi
  const std::wstring *v4; // eax

  v2 = this->items._Myfirst;
  v3 = this->items._Mylast;
  if ( this->items._Myfirst == v3 )
    return 0;
  while ( 1 )
  {
    v4 = name->_Myres < 8 ? name : name->_Bx._Ptr;
    if ( !std::wstring::compare(&v2->name, 0, v2->name._Mysize, v4->_Bx._Buf, name->_Mysize) )
      break;
    if ( ++v2 == v3 )
      return 0;
  }
  return v2;
}
void SetupManager::init(SetupManager *this, Car *acar)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Car *v5; // ecx
  const std::wstring *v6; // eax
  bool v7; // bl
  double v8; // st7
  bool v9; // cf
  float v10; // [esp+10h] [ebp-D0h]
  std::wstring section; // [esp+14h] [ebp-CCh] BYREF
  std::wstring key; // [esp+2Ch] [ebp-B4h] BYREF
  std::wstring v13; // [esp+44h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+5Ch] [ebp-84h] BYREF
  std::wstring v15; // [esp+74h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+8Ch] [ebp-54h] BYREF
  int v17; // [esp+DCh] [ebp-4h]

  this->car = acar;
  SetupManager::initItems(this, 0);
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &acar->unixName);
  v17 = 0;
  v4 = std::operator+<wchar_t>(&v15, v3, L"/data/car.ini");
  v5 = this->car;
  LOBYTE(v17) = 1;
  v6 = Car::getConfigPath(v5, &v13, v4);
  LOBYTE(v17) = 2;
  INIReader::INIReader(&ini, v6);
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  if ( v15._Myres >= 8 )
    operator delete(v15._Bx._Ptr);
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  LOBYTE(v17) = 6;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"RULES", 5u);
    LOBYTE(v17) = 7;
    v7 = INIReader::hasSection(&ini, &section);
    LOBYTE(v17) = 6;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v7 )
    {
      this->checkRules = 1;
      std::wstring::wstring(&key, L"MIN_HEIGHT");
      LOBYTE(v17) = 8;
      std::wstring::wstring(&section, L"RULES");
      LOBYTE(v17) = 9;
      v10 = INIReader::getFloat(&ini, &section, &key);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v17) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v10 > 0.0 )
      {
        std::wstring::wstring(&key, L"MIN_HEIGHT");
        LOBYTE(v17) = 10;
        std::wstring::wstring(&section, L"RULES");
        LOBYTE(v17) = 11;
        v8 = INIReader::getFloat(&ini, &section, &key);
        v9 = section._Myres < 8;
        this->minimumHeight_m = v8;
        if ( !v9 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
      }
    }
  }
  v17 = -1;
  INIReader::~INIReader(&ini);
}
void SetupManager::initItems(SetupManager *this, bool attached)
{
  float v3; // ebp
  float *v4; // eax
  SetupItem *v5; // eax
  float *v6; // eax
  SetupItem *v7; // eax
  float *v8; // eax
  SetupItem *v9; // eax
  float *v10; // eax
  SetupItem *v11; // eax
  Car *v12; // edi
  Wing *v13; // esi
  Wing *v14; // edi
  std::wostream *v15; // eax
  bool v16; // zf
  SetupItem *v17; // eax
  int v18; // eax
  float *v19; // eax
  SetupItem *v20; // eax
  float *v21; // eax
  SetupItem *v22; // eax
  float *v23; // eax
  SetupItem *v24; // eax
  DifferentialSetting *v25; // eax
  SetupItem *v26; // eax
  float *v27; // eax
  SetupItem *v28; // eax
  float *v29; // eax
  SetupItem *v30; // eax
  DifferentialSetting *v31; // eax
  SetupItem *v32; // eax
  float *v33; // eax
  SetupItem *v34; // eax
  float *v35; // eax
  SetupItem *v36; // eax
  DifferentialSetting *v37; // eax
  SetupItem *v38; // eax
  float *v39; // eax
  SetupItem *v40; // eax
  float *v41; // eax
  SetupItem *v42; // eax
  Car *v43; // eax
  SetupItem *v44; // eax
  float *v45; // eax
  SetupItem *v46; // eax
  float *v47; // eax
  SetupItem *v48; // eax
  float *v49; // eax
  SetupItem *v50; // eax
  float *v51; // eax
  SetupItem *v52; // eax
  float *v53; // eax
  SetupItem *v54; // eax
  BrakeSystem *v55; // eax
  SetupItem *v56; // eax
  ISuspension **v57; // eax
  ISuspension *v58; // esi
  ISuspension_vtbl *v59; // eax
  SetupItem *v60; // eax
  ISuspension_vtbl *v61; // eax
  SetupItem *v62; // eax
  ISuspension_vtbl *v63; // eax
  SetupItem *v64; // eax
  ISuspension_vtbl *v65; // eax
  SetupItem *v66; // eax
  SetupItem *v67; // eax
  SetupItem *v68; // eax
  SetupItem *v69; // eax
  SetupItem *v70; // eax
  SetupItem *v71; // eax
  SetupItem *v72; // eax
  SetupItem *v73; // eax
  ISuspension **v74; // eax
  ISuspension *v75; // esi
  ISuspension_vtbl *v76; // eax
  SetupItem *v77; // eax
  ISuspension_vtbl *v78; // eax
  SetupItem *v79; // eax
  ISuspension_vtbl *v80; // eax
  SetupItem *v81; // eax
  ISuspension_vtbl *v82; // eax
  SetupItem *v83; // eax
  SetupItem *v84; // eax
  SetupItem *v85; // eax
  SetupItem *v86; // eax
  SetupItem *v87; // eax
  SetupItem *v88; // eax
  SetupItem *v89; // eax
  SetupItem *v90; // eax
  ISuspension **v91; // eax
  ISuspension *v92; // edi
  ISuspension_vtbl *v93; // eax
  SetupItem *v94; // eax
  ISuspension_vtbl *v95; // eax
  SetupItem *v96; // eax
  ISuspension_vtbl *v97; // eax
  SetupItem *v98; // eax
  ISuspension_vtbl *v99; // eax
  SetupItem *v100; // eax
  SetupItem *v101; // eax
  SetupItem *v102; // eax
  SetupItem *v103; // eax
  SetupItem *v104; // eax
  SetupItem *v105; // eax
  SetupItem *v106; // eax
  std::function<void __cdecl(SetupItem *)> *v107; // esi
  std::function<void __cdecl(SetupItem *)> *v108; // ecx
  SetupItem *v109; // eax
  ISuspension **v110; // eax
  ISuspension *v111; // esi
  ISuspension_vtbl *v112; // eax
  SetupItem *v113; // eax
  ISuspension_vtbl *v114; // eax
  SetupItem *v115; // eax
  ISuspension_vtbl *v116; // eax
  SetupItem *v117; // eax
  ISuspension_vtbl *v118; // eax
  SetupItem *v119; // eax
  SetupItem *v120; // eax
  SetupItem *v121; // eax
  SetupItem *v122; // eax
  SetupItem *v123; // eax
  SetupItem *v124; // eax
  SetupItem *v125; // eax
  std::function<void __cdecl(SetupItem *)> *v126; // edi
  std::function<void __cdecl(SetupItem *)> *v127; // ecx
  SetupItem *v128; // eax
  float *v129; // eax
  SetupItem *v130; // eax
  float *v131; // eax
  SetupItem *v132; // eax
  float *v133; // eax
  SetupItem *v134; // eax
  Damper *v135; // eax
  SetupItem *v136; // eax
  float *v137; // eax
  SetupItem *v138; // eax
  float *v139; // eax
  SetupItem *v140; // eax
  float *v141; // eax
  SetupItem *v142; // eax
  float *v143; // eax
  SetupItem *v144; // eax
  SetupItem *v145; // eax
  float *v146; // eax
  SetupItem *v147; // eax
  float *v148; // eax
  SetupItem *v149; // eax
  float *v150; // eax
  SetupItem *v151; // eax
  Damper *v152; // eax
  SetupItem *v153; // eax
  float *v154; // eax
  SetupItem *v155; // eax
  float *v156; // eax
  SetupItem *v157; // eax
  float *v158; // eax
  SetupItem *v159; // eax
  float *v160; // eax
  SetupItem *v161; // eax
  SetupItem *v162; // eax
  float v163; // edi
  std::vector<SGearRatio> *v164; // ecx
  int v165; // edx
  std::wostream *v166; // eax
  float *v167; // eax
  SetupItem *v168; // eax
  std::function<void __cdecl(SetupItem *)> *v169; // esi
  std::function<void __cdecl(SetupItem *)> *v170; // ecx
  SetupItem *v171; // eax
  float *v172; // eax
  SetupItem *v173; // eax
  SetupItem *v174; // eax
  float *v175; // esi
  SetupItem *v176; // eax
  SetupItem *v177; // eax
  float *v178; // eax
  SetupItem *v179; // eax
  float *v180; // eax
  SetupItem *v181; // eax
  std::wstring v182; // [esp+0h] [ebp-2B0h] BYREF
  Damper *v183; // [esp+18h] [ebp-298h]
  std::wstring v184; // [esp+1Ch] [ebp-294h] BYREF
  float v185; // [esp+34h] [ebp-27Ch]
  float multiplier; // [esp+38h] [ebp-278h]
  float labelMult; // [esp+3Ch] [ebp-274h]
  std::wstring *v188; // [esp+5Ch] [ebp-254h]
  std::wstring *v189; // [esp+60h] [ebp-250h]
  bool isAttached[4]; // [esp+64h] [ebp-24Ch]
  float *aconnectedFloat; // [esp+68h] [ebp-248h]
  int v192; // [esp+6Ch] [ebp-244h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v193; // [esp+70h] [ebp-240h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v194; // [esp+120h] [ebp-190h] BYREF
  SetupItem v195; // [esp+1D0h] [ebp-E0h] BYREF
  SetupItem v196; // [esp+238h] [ebp-78h] BYREF
  int v197; // [esp+2ACh] [ebp-4h]

  v192 = 0;
  isAttached[0] = attached;
  v3 = *(float *)isAttached;
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = *(float *)isAttached;
  *(float *)isAttached = COERCE_FLOAT(&v184);
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"N/m", 3u);
  v4 = &this->car->antirollBars[0].k;
  v197 = 0;
  v183 = (Damper *)v4;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"ARB_FRONT", 9u);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 1;
  std::vector<SetupItem>::push_back(&this->items, v5);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  *(float *)isAttached = COERCE_FLOAT(&v184);
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"N/m", 3u);
  v6 = &this->car->antirollBars[1].k;
  v197 = 2;
  v183 = (Damper *)v6;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"ARB_REAR", 8u);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 3;
  std::vector<SetupItem>::push_back(&this->items, v7);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  *(float *)isAttached = COERCE_FLOAT(&v184);
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"N/mm", 4u);
  v8 = &this->car->antirollBars[0].k;
  v197 = 4;
  v183 = (Damper *)v8;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"ARB_FRONT_NMM", 0xDu);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 5;
  std::vector<SetupItem>::push_back(&this->items, v9);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  *(float *)isAttached = COERCE_FLOAT(&v184);
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"N/mm", 4u);
  v10 = &this->car->antirollBars[1].k;
  v197 = 6;
  v183 = (Damper *)v10;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"ARB_REAR_NMM", 0xCu);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 7;
  std::vector<SetupItem>::push_back(&this->items, v11);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v12 = this->car;
  *(float *)isAttached = 0.0;
  v13 = v12->aeroMap.wings._Myfirst;
  v14 = v12->aeroMap.wings._Mylast;
  if ( v13 != v14 )
  {
    aconnectedFloat = &v13->status.inputAngle;
    do
    {
      *(_DWORD *)v193.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v193.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v193.gap68);
      v192 |= 1u;
      v197 = 8;
      std::wiostream::basic_iostream<wchar_t>(&v193, &v193.gap10[8], 0);
      v197 = 9;
      *(_DWORD *)&v193.gap0[*(_DWORD *)(*(_DWORD *)v193.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(int *)((char *)&v192 + *(_DWORD *)(*(_DWORD *)v193.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v193.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v193.gap10[8]);
      *(_DWORD *)&v193.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v193.gap10[64] = 0;
      *(_DWORD *)&v193.gap10[68] = 0;
      labelMult = *(float *)isAttached;
      v197 = 11;
      v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v193.gap10, "WING_");
      std::wostream::operator<<(v15, LODWORD(labelMult));
      labelMult = 1.0;
      multiplier = 1.0;
      v185 = v3;
      v16 = *((_BYTE *)aconnectedFloat - 32) == 0;
      v184._Myres = 7;
      v184._Mysize = 0;
      if ( v16 )
      {
        v188 = &v184;
        v184._Bx._Buf[0] = 0;
        std::wstring::assign(&v184, L"deg", 3u);
        LOBYTE(v197) = 14;
        v183 = (Damper *)(aconnectedFloat - 1);
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v193, &v182);
        LOBYTE(v197) = 11;
        SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
        LOBYTE(v197) = 15;
      }
      else
      {
        v189 = &v184;
        v184._Bx._Buf[0] = 0;
        std::wstring::assign(&v184, L"deg", 3u);
        v183 = (Damper *)aconnectedFloat;
        LOBYTE(v197) = 12;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v193, &v182);
        LOBYTE(v197) = 11;
        SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
        LOBYTE(v197) = 13;
      }
      std::vector<SetupItem>::push_back(&this->items, v17);
      LOBYTE(v197) = 11;
      SetupItem::~SetupItem(&v195);
      ++*(_DWORD *)isAttached;
      v197 = -1;
      *(_DWORD *)&v193.gap0[*(_DWORD *)(*(_DWORD *)v193.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(int *)((char *)&v192 + *(_DWORD *)(*(_DWORD *)v193.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v193.gap0 + 4) - 104;
      *(_DWORD *)&v193.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v193.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v193.gap10[8]) )
          std::wstreambuf::epptr(&v193.gap10[8]);
        else
          std::wstreambuf::egptr(&v193.gap10[8]);
        std::wstreambuf::eback(&v193.gap10[8]);
        v18 = std::wstreambuf::eback(&v193.gap10[8]);
        operator delete(v18);
      }
      std::wstreambuf::setg(&v193.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v193.gap10[8], 0, 0);
      *(_DWORD *)&v193.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v193.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v193.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v193.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v193.gap68);
      aconnectedFloat += 132;
      ++v13;
    }
    while ( v13 != v14 );
  }
  if ( !Drivetrain::hasDynamicControllers(&this->car->drivetrain) )
  {
    labelMult = 1.0;
    multiplier = 0.0099999998;
    v185 = v3;
    v188 = &v184;
    v184._Myres = 7;
    v184._Mysize = 0;
    v184._Bx._Buf[0] = 0;
    std::wstring::assign(&v184, L"%", 1u);
    v19 = &this->car->drivetrain.diffPowerRamp;
    v197 = 16;
    v183 = (Damper *)v19;
    v182._Myres = 7;
    v182._Mysize = 0;
    v182._Bx._Buf[0] = 0;
    std::wstring::assign(&v182, L"DIFF_POWER", 0xAu);
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 17;
    std::vector<SetupItem>::push_back(&this->items, v20);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 0.0099999998;
    v185 = v3;
    v188 = &v184;
    v184._Myres = 7;
    v184._Mysize = 0;
    v184._Bx._Buf[0] = 0;
    std::wstring::assign(&v184, L"%", 1u);
    v21 = &this->car->drivetrain.diffCoastRamp;
    v197 = 18;
    v183 = (Damper *)v21;
    v182._Myres = 7;
    v182._Mysize = 0;
    v182._Bx._Buf[0] = 0;
    std::wstring::assign(&v182, L"DIFF_COAST", 0xAu);
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 19;
    std::vector<SetupItem>::push_back(&this->items, v22);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    v184._Myres = 7;
    v184._Mysize = 0;
    v184._Bx._Buf[0] = 0;
    std::wstring::assign(&v184, L"Nm", 2u);
    v23 = &this->car->drivetrain.diffPreLoad;
    v197 = 20;
    v183 = (Damper *)v23;
    v182._Myres = 7;
    v182._Mysize = 0;
    v182._Bx._Buf[0] = 0;
    std::wstring::assign(&v182, L"DIFF_PRELOAD", 0xCu);
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 21;
    std::vector<SetupItem>::push_back(&this->items, v24);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
  }
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"%", 1u);
  v25 = &this->car->drivetrain.awdFrontDiff;
  v197 = 22;
  v183 = (Damper *)v25;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"FRONT_DIFF_POWER", 0x10u);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 23;
  std::vector<SetupItem>::push_back(&this->items, v26);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"%", 1u);
  v27 = &this->car->drivetrain.awdFrontDiff.coast;
  v197 = 24;
  v183 = (Damper *)v27;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"FRONT_DIFF_COAST", 0x10u);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 25;
  std::vector<SetupItem>::push_back(&this->items, v28);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"Nm", 2u);
  v29 = &this->car->drivetrain.awdFrontDiff.preload;
  v197 = 26;
  v183 = (Damper *)v29;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"FRONT_DIFF_PRELOAD", 0x12u);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 27;
  std::vector<SetupItem>::push_back(&this->items, v30);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"%", 1u);
  v31 = &this->car->drivetrain.awdRearDiff;
  v197 = 28;
  v183 = (Damper *)v31;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"REAR_DIFF_POWER", 0xFu);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 29;
  std::vector<SetupItem>::push_back(&this->items, v32);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  v184._Myres = 7;
  v184._Mysize = 0;
  v184._Bx._Buf[0] = 0;
  std::wstring::assign(&v184, L"%", 1u);
  v33 = &this->car->drivetrain.awdRearDiff.coast;
  v197 = 30;
  v183 = (Damper *)v33;
  v182._Myres = 7;
  v182._Mysize = 0;
  v182._Bx._Buf[0] = 0;
  std::wstring::assign(&v182, L"REAR_DIFF_COAST", 0xFu);
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 31;
  std::vector<SetupItem>::push_back(&this->items, v34);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"Nm");
  v35 = &this->car->drivetrain.awdRearDiff.preload;
  v197 = 32;
  v183 = (Damper *)v35;
  std::wstring::wstring(&v182, L"REAR_DIFF_PRELOAD");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 33;
  std::vector<SetupItem>::push_back(&this->items, v36);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"%");
  v37 = &this->car->drivetrain.awdCenterDiff;
  v197 = 34;
  v183 = (Damper *)v37;
  std::wstring::wstring(&v182, L"CENTER_DIFF_POWER");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 35;
  std::vector<SetupItem>::push_back(&this->items, v38);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"%");
  v39 = &this->car->drivetrain.awdCenterDiff.coast;
  v197 = 36;
  v183 = (Damper *)v39;
  std::wstring::wstring(&v182, L"CENTER_DIFF_COAST");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 37;
  std::vector<SetupItem>::push_back(&this->items, v40);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"Nm");
  v41 = &this->car->drivetrain.awdCenterDiff.preload;
  v197 = 38;
  v183 = (Damper *)v41;
  std::wstring::wstring(&v182, L"CENTER_DIFF_PRELOAD");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 39;
  std::vector<SetupItem>::push_back(&this->items, v42);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"%");
  v43 = this->car;
  v197 = 40;
  v183 = (Damper *)&v43->drivetrain.awdFrontShare;
  std::wstring::wstring(&v182, L"AWD_FRONT_TORQUE_DISTRIBUTION");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 41;
  std::vector<SetupItem>::push_back(&this->items, v44);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"psi");
  v45 = &this->car->tyres[0].status.pressureStatic;
  v197 = 42;
  v183 = (Damper *)v45;
  std::wstring::wstring(&v182, L"PRESSURE_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 43;
  std::vector<SetupItem>::push_back(&this->items, v46);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"psi");
  v47 = &this->car->tyres[1].status.pressureStatic;
  v197 = 44;
  v183 = (Damper *)v47;
  std::wstring::wstring(&v182, L"PRESSURE_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 45;
  std::vector<SetupItem>::push_back(&this->items, v48);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"psi");
  v49 = &this->car->tyres[2].status.pressureStatic;
  v197 = 46;
  v183 = (Damper *)v49;
  std::wstring::wstring(&v182, L"PRESSURE_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 47;
  std::vector<SetupItem>::push_back(&this->items, v50);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"psi");
  v51 = &this->car->tyres[3].status.pressureStatic;
  v197 = 48;
  v183 = (Damper *)v51;
  std::wstring::wstring(&v182, L"PRESSURE_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 49;
  std::vector<SetupItem>::push_back(&this->items, v52);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  aconnectedFloat = (float *)&this->car->drivetrain.acEngine;
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"%");
  v53 = &this->car->brakeSystem.brakePowerMultiplier;
  v197 = 50;
  v183 = (Damper *)v53;
  std::wstring::wstring(&v182, L"BRAKE_POWER_MULT");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 51;
  std::vector<SetupItem>::push_back(&this->items, v54);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"%");
  v55 = &this->car->brakeSystem;
  v197 = 52;
  v183 = (Damper *)v55;
  std::wstring::wstring(&v182, L"FRONT_BIAS");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 53;
  std::vector<SetupItem>::push_back(&this->items, v56);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v57 = this->car->suspensions._Myfirst;
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v58 = *v57;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v59 = v58->__vftable;
  v197 = 54;
  v183 = (Damper *)&v59->getDamper(v58)->bumpFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_BUMP_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 55;
  std::vector<SetupItem>::push_back(&this->items, v60);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v61 = v58->__vftable;
  v197 = 56;
  v183 = (Damper *)&v61->getDamper(v58)->bumpSlow;
  std::wstring::wstring(&v182, L"DAMP_BUMP_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 57;
  std::vector<SetupItem>::push_back(&this->items, v62);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v63 = v58->__vftable;
  v197 = 58;
  v183 = (Damper *)&v63->getDamper(v58)->reboundFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_REBOUND_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 59;
  std::vector<SetupItem>::push_back(&this->items, v64);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v65 = v58->__vftable;
  v197 = 60;
  v183 = v65->getDamper(v58);
  std::wstring::wstring(&v182, L"DAMP_REBOUND_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 61;
  std::vector<SetupItem>::push_back(&this->items, v66);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 62;
  v183 = (Damper *)&v58->bumpStopRate;
  std::wstring::wstring(&v182, L"BUMP_STOP_RATE_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 63;
  std::vector<SetupItem>::push_back(&this->items, v67);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"N/mm");
  v197 = 64;
  v183 = (Damper *)&v58->k;
  std::wstring::wstring(&v182, L"SPRING_RATE_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 65;
  std::vector<SetupItem>::push_back(&this->items, v68);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 66;
  v183 = (Damper *)&v58->progressiveK;
  std::wstring::wstring(&v182, L"PROGRESSIVE_SPRING_RATE_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 67;
  std::vector<SetupItem>::push_back(&this->items, v69);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 68;
  v183 = (Damper *)&v58->rodLength;
  std::wstring::wstring(&v182, L"ROD_LENGTH_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 69;
  std::vector<SetupItem>::push_back(&this->items, v70);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 0.1;
  multiplier = -0.0017453292;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"deg");
  v197 = 70;
  v183 = (Damper *)&v58->staticCamber;
  std::wstring::wstring(&v182, L"CAMBER_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 71;
  std::vector<SetupItem>::push_back(&this->items, v71);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 72;
  v183 = (Damper *)&v58->toeOUT_Linear;
  std::wstring::wstring(&v182, L"TOE_OUT_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 73;
  std::vector<SetupItem>::push_back(&this->items, v72);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.001;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"mm");
  v197 = 74;
  v183 = (Damper *)&v58->packerRange;
  std::wstring::wstring(&v182, L"PACKER_RANGE_LF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 75;
  std::vector<SetupItem>::push_back(&this->items, v73);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v74 = this->car->suspensions._Myfirst;
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v75 = v74[1];
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v76 = v75->__vftable;
  v197 = 76;
  v183 = (Damper *)&v76->getDamper(v75)->bumpFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_BUMP_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 77;
  std::vector<SetupItem>::push_back(&this->items, v77);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v78 = v75->__vftable;
  v197 = 78;
  v183 = (Damper *)&v78->getDamper(v75)->bumpSlow;
  std::wstring::wstring(&v182, L"DAMP_BUMP_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 79;
  std::vector<SetupItem>::push_back(&this->items, v79);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v80 = v75->__vftable;
  v197 = 80;
  v183 = (Damper *)&v80->getDamper(v75)->reboundFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_REBOUND_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 81;
  std::vector<SetupItem>::push_back(&this->items, v81);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v82 = v75->__vftable;
  v197 = 82;
  v183 = v82->getDamper(v75);
  std::wstring::wstring(&v182, L"DAMP_REBOUND_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 83;
  std::vector<SetupItem>::push_back(&this->items, v83);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 84;
  v183 = (Damper *)&v75->bumpStopRate;
  std::wstring::wstring(&v182, L"BUMP_STOP_RATE_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 85;
  std::vector<SetupItem>::push_back(&this->items, v84);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"N/mm");
  v197 = 86;
  v183 = (Damper *)&v75->k;
  std::wstring::wstring(&v182, L"SPRING_RATE_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 87;
  std::vector<SetupItem>::push_back(&this->items, v85);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 88;
  v183 = (Damper *)&v75->progressiveK;
  std::wstring::wstring(&v182, L"PROGRESSIVE_SPRING_RATE_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 89;
  std::vector<SetupItem>::push_back(&this->items, v86);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 90;
  v183 = (Damper *)&v75->rodLength;
  std::wstring::wstring(&v182, L"ROD_LENGTH_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 91;
  std::vector<SetupItem>::push_back(&this->items, v87);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 0.1;
  multiplier = 0.0017453292;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"deg");
  v197 = 92;
  v183 = (Damper *)&v75->staticCamber;
  std::wstring::wstring(&v182, L"CAMBER_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 93;
  std::vector<SetupItem>::push_back(&this->items, v88);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 94;
  v183 = (Damper *)&v75->toeOUT_Linear;
  std::wstring::wstring(&v182, L"TOE_OUT_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 95;
  std::vector<SetupItem>::push_back(&this->items, v89);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.001;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"mm");
  v197 = 96;
  v183 = (Damper *)&v75->packerRange;
  std::wstring::wstring(&v182, L"PACKER_RANGE_RF");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 97;
  std::vector<SetupItem>::push_back(&this->items, v90);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v91 = this->car->suspensions._Myfirst;
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v92 = v91[2];
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v93 = v92->__vftable;
  v197 = 98;
  v183 = (Damper *)&v93->getDamper(v92)->bumpFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_BUMP_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 99;
  std::vector<SetupItem>::push_back(&this->items, v94);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v95 = v92->__vftable;
  v197 = 100;
  v183 = (Damper *)&v95->getDamper(v92)->bumpSlow;
  std::wstring::wstring(&v182, L"DAMP_BUMP_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 101;
  std::vector<SetupItem>::push_back(&this->items, v96);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v97 = v92->__vftable;
  v197 = 102;
  v183 = (Damper *)&v97->getDamper(v92)->reboundFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_REBOUND_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 103;
  std::vector<SetupItem>::push_back(&this->items, v98);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v99 = v92->__vftable;
  v197 = 104;
  v183 = v99->getDamper(v92);
  std::wstring::wstring(&v182, L"DAMP_REBOUND_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 105;
  std::vector<SetupItem>::push_back(&this->items, v100);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 106;
  v183 = (Damper *)&v92->bumpStopRate;
  std::wstring::wstring(&v182, L"BUMP_STOP_RATE_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 107;
  std::vector<SetupItem>::push_back(&this->items, v101);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"N/mm");
  v197 = 108;
  v183 = (Damper *)&v92->k;
  std::wstring::wstring(&v182, L"SPRING_RATE_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 109;
  std::vector<SetupItem>::push_back(&this->items, v102);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 110;
  v183 = (Damper *)&v92->progressiveK;
  std::wstring::wstring(&v182, L"PROGRESSIVE_SPRING_RATE_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 111;
  std::vector<SetupItem>::push_back(&this->items, v103);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 112;
  v183 = (Damper *)&v92->rodLength;
  std::wstring::wstring(&v182, L"ROD_LENGTH_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 113;
  std::vector<SetupItem>::push_back(&this->items, v104);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 0.1;
  multiplier = -0.0017453292;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"deg");
  v197 = 114;
  v183 = (Damper *)&v92->staticCamber;
  std::wstring::wstring(&v182, L"CAMBER_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 115;
  std::vector<SetupItem>::push_back(&this->items, v105);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 116;
  v183 = (Damper *)&v92->toeOUT_Linear;
  std::wstring::wstring(&v182, L"TOE_OUT_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 117;
  std::vector<SetupItem>::push_back(&this->items, v106);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v107 = &this->items._Mylast[-1].onValueChanged;
  v108 = (std::function<void __cdecl(SetupItem *)> *)v107->_Impl;
  if ( v108 )
  {
    (*((void (__stdcall **)(bool))v108->_Space._Pfn[0] + 4))(v108 != v107);
    v107->_Impl = 0;
  }
  v107->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_e679b03f85efbc9b2d13b039819b645b_,0>,std::allocator<std::_Func_class<void,SetupItem *>>,void,SetupItem *>::`vftable';
  v107->_Space._Pfn[1] = (void (__cdecl *)())this;
  v107->_Impl = (std::_Func_base<void,SetupItem *> *)v107;
  labelMult = 1.0;
  multiplier = 0.001;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"mm");
  v197 = 118;
  v183 = (Damper *)&v92->packerRange;
  std::wstring::wstring(&v182, L"PACKER_RANGE_LR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 119;
  std::vector<SetupItem>::push_back(&this->items, v109);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v110 = this->car->suspensions._Myfirst;
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v111 = v110[3];
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v112 = v111->__vftable;
  v197 = 120;
  v183 = (Damper *)&v112->getDamper(v111)->bumpFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_BUMP_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 121;
  std::vector<SetupItem>::push_back(&this->items, v113);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v114 = v111->__vftable;
  v197 = 122;
  v183 = (Damper *)&v114->getDamper(v111)->bumpSlow;
  std::wstring::wstring(&v182, L"DAMP_BUMP_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 123;
  std::vector<SetupItem>::push_back(&this->items, v115);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v116 = v111->__vftable;
  v197 = 124;
  v183 = (Damper *)&v116->getDamper(v111)->reboundFast;
  std::wstring::wstring(&v182, L"DAMP_FAST_REBOUND_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 125;
  std::vector<SetupItem>::push_back(&this->items, v117);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v118 = v111->__vftable;
  v197 = 126;
  v183 = v118->getDamper(v111);
  std::wstring::wstring(&v182, L"DAMP_REBOUND_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 127;
  std::vector<SetupItem>::push_back(&this->items, v119);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 128;
  v183 = (Damper *)&v111->bumpStopRate;
  std::wstring::wstring(&v182, L"BUMP_STOP_RATE_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 129;
  std::vector<SetupItem>::push_back(&this->items, v120);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"N/mm");
  v197 = 130;
  v183 = (Damper *)&v111->k;
  std::wstring::wstring(&v182, L"SPRING_RATE_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 131;
  std::vector<SetupItem>::push_back(&this->items, v121);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1000.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 132;
  v183 = (Damper *)&v111->progressiveK;
  std::wstring::wstring(&v182, L"PROGRESSIVE_SPRING_RATE_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 133;
  std::vector<SetupItem>::push_back(&this->items, v122);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 134;
  v183 = (Damper *)&v111->rodLength;
  std::wstring::wstring(&v182, L"ROD_LENGTH_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 135;
  std::vector<SetupItem>::push_back(&this->items, v123);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 0.1;
  multiplier = 0.0017453292;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"deg");
  v197 = 136;
  v183 = (Damper *)&v111->staticCamber;
  std::wstring::wstring(&v182, L"CAMBER_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 137;
  std::vector<SetupItem>::push_back(&this->items, v124);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0000099999997;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 138;
  v183 = (Damper *)&v111->toeOUT_Linear;
  std::wstring::wstring(&v182, L"TOE_OUT_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 139;
  std::vector<SetupItem>::push_back(&this->items, v125);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v126 = &this->items._Mylast[-1].onValueChanged;
  v127 = (std::function<void __cdecl(SetupItem *)> *)v126->_Impl;
  if ( v127 )
  {
    (*((void (__stdcall **)(bool))v127->_Space._Pfn[0] + 4))(v127 != v126);
    v126->_Impl = 0;
  }
  v126->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_829818c412f79d133a0bd8f7ed74bf7f_,0>,std::allocator<std::_Func_class<void,SetupItem *>>,void,SetupItem *>::`vftable';
  v126->_Space._Pfn[1] = (void (__cdecl *)())this;
  v126->_Impl = (std::_Func_base<void,SetupItem *> *)v126;
  labelMult = 1.0;
  multiplier = 0.001;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"mm");
  v197 = 140;
  v183 = (Damper *)&v111->packerRange;
  std::wstring::wstring(&v182, L"PACKER_RANGE_RR");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 141;
  std::vector<SetupItem>::push_back(&this->items, v128);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  if ( this->car->heaveSprings[0].isPresent )
  {
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v129 = &this->car->heaveSprings[0].damper.bumpFast;
    v197 = 142;
    v183 = (Damper *)v129;
    std::wstring::wstring(&v182, L"DAMP_FAST_BUMP_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 143;
    std::vector<SetupItem>::push_back(&this->items, v130);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v131 = &this->car->heaveSprings[0].damper.bumpSlow;
    v197 = 144;
    v183 = (Damper *)v131;
    std::wstring::wstring(&v182, L"DAMP_BUMP_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 145;
    std::vector<SetupItem>::push_back(&this->items, v132);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v133 = &this->car->heaveSprings[0].damper.reboundFast;
    v197 = 146;
    v183 = (Damper *)v133;
    std::wstring::wstring(&v182, L"DAMP_FAST_REBOUND_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 147;
    std::vector<SetupItem>::push_back(&this->items, v134);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v135 = &this->car->heaveSprings[0].damper;
    v197 = 148;
    v183 = v135;
    std::wstring::wstring(&v182, L"DAMP_REBOUND_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 149;
    std::vector<SetupItem>::push_back(&this->items, v136);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1000.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v137 = &this->car->heaveSprings[0].bumpStopRate;
    v197 = 150;
    v183 = (Damper *)v137;
    std::wstring::wstring(&v182, L"BUMP_STOP_RATE_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 151;
    std::vector<SetupItem>::push_back(&this->items, v138);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1000.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, L"N/mm");
    v139 = &this->car->heaveSprings[0].k;
    v197 = 152;
    v183 = (Damper *)v139;
    std::wstring::wstring(&v182, L"SPRING_RATE_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 153;
    std::vector<SetupItem>::push_back(&this->items, v140);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1000.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v141 = &this->car->heaveSprings[0].progressiveK;
    v197 = 154;
    v183 = (Damper *)v141;
    std::wstring::wstring(&v182, L"PROGRESSIVE_SPRING_RATE_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 155;
    std::vector<SetupItem>::push_back(&this->items, v142);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 0.000099999997;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v143 = &this->car->heaveSprings[0].rodLength;
    v197 = 156;
    v183 = (Damper *)v143;
    std::wstring::wstring(&v182, L"ROD_LENGTH_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 157;
    std::vector<SetupItem>::push_back(&this->items, v144);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 0.001;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, L"mm");
    v197 = 158;
    v183 = (Damper *)&this->car->heaveSprings[0].packerRange;
    std::wstring::wstring(&v182, L"PACKER_RANGE_HF");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 159;
    std::vector<SetupItem>::push_back(&this->items, v145);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
  }
  if ( this->car->heaveSprings[1].isPresent )
  {
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v146 = &this->car->heaveSprings[1].damper.bumpFast;
    v197 = 160;
    v183 = (Damper *)v146;
    std::wstring::wstring(&v182, L"DAMP_FAST_BUMP_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 161;
    std::vector<SetupItem>::push_back(&this->items, v147);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v148 = &this->car->heaveSprings[1].damper.bumpSlow;
    v197 = 162;
    v183 = (Damper *)v148;
    std::wstring::wstring(&v182, L"DAMP_BUMP_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 163;
    std::vector<SetupItem>::push_back(&this->items, v149);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v150 = &this->car->heaveSprings[1].damper.reboundFast;
    v197 = 164;
    v183 = (Damper *)v150;
    std::wstring::wstring(&v182, L"DAMP_FAST_REBOUND_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 165;
    std::vector<SetupItem>::push_back(&this->items, v151);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v152 = &this->car->heaveSprings[1].damper;
    v197 = 166;
    v183 = v152;
    std::wstring::wstring(&v182, L"DAMP_REBOUND_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 167;
    std::vector<SetupItem>::push_back(&this->items, v153);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1000.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v154 = &this->car->heaveSprings[1].bumpStopRate;
    v197 = 168;
    v183 = (Damper *)v154;
    std::wstring::wstring(&v182, L"BUMP_STOP_RATE_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 169;
    std::vector<SetupItem>::push_back(&this->items, v155);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1000.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, L"N/mm");
    v156 = &this->car->heaveSprings[1].k;
    v197 = 170;
    v183 = (Damper *)v156;
    std::wstring::wstring(&v182, L"SPRING_RATE_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 171;
    std::vector<SetupItem>::push_back(&this->items, v157);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 1000.0;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v158 = &this->car->heaveSprings[1].progressiveK;
    v197 = 172;
    v183 = (Damper *)v158;
    std::wstring::wstring(&v182, L"PROGRESSIVE_SPRING_RATE_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 173;
    std::vector<SetupItem>::push_back(&this->items, v159);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 0.000099999997;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, word_17BE9D8);
    v160 = &this->car->heaveSprings[1].rodLength;
    v197 = 174;
    v183 = (Damper *)v160;
    std::wstring::wstring(&v182, L"ROD_LENGTH_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 175;
    std::vector<SetupItem>::push_back(&this->items, v161);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
    labelMult = 1.0;
    multiplier = 0.001;
    v185 = v3;
    v188 = &v184;
    std::wstring::wstring(&v184, L"mm");
    v197 = 176;
    v183 = (Damper *)&this->car->heaveSprings[1].packerRange;
    std::wstring::wstring(&v182, L"PACKER_RANGE_HR");
    v197 = -1;
    SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
    v197 = 177;
    std::vector<SetupItem>::push_back(&this->items, v162);
    v197 = -1;
    SetupItem::~SetupItem(&v195);
  }
  std::vector<float>::resize(
    &this->gearSettings,
    this->car->drivetrain.gears._Mylast - this->car->drivetrain.gears._Myfirst);
  v163 = 0.0;
  v164 = &this->car->drivetrain.gears;
  if ( this->car->drivetrain.gears._Mylast - v164->_Myfirst )
  {
    v165 = 0;
    *(float *)isAttached = 0.0;
    do
    {
      this->gearSettings._Myfirst[LODWORD(v163)] = *(double *)((char *)&v164->_Myfirst->ratio + v165);
      *(_DWORD *)v194.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v194.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v194.gap68);
      v192 |= 2u;
      v197 = 178;
      std::wiostream::basic_iostream<wchar_t>(&v194, &v194.gap10[8], 0);
      v197 = 179;
      *(_DWORD *)&v194.gap0[*(_DWORD *)(*(_DWORD *)v194.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v193.gap68[*(_DWORD *)(*(_DWORD *)v194.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v194.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v194.gap10[8]);
      *(_DWORD *)&v194.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v194.gap10[64] = 0;
      *(_DWORD *)&v194.gap10[68] = 0;
      labelMult = v163;
      v197 = 181;
      v166 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v194.gap10, "INTERNAL_GEAR_");
      std::wostream::operator<<(v166, LODWORD(labelMult));
      labelMult = 1.0;
      multiplier = 1.0;
      v185 = v3;
      v188 = &v184;
      v184._Myres = 7;
      v184._Mysize = 0;
      v184._Bx._Buf[0] = 0;
      std::wstring::assign(&v184, word_17BE9D8, 0);
      v167 = &this->gearSettings._Myfirst[LODWORD(v163)];
      LOBYTE(v197) = -74;
      v183 = (Damper *)v167;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v194, &v182);
      LOBYTE(v197) = -75;
      SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
      LOBYTE(v197) = -73;
      std::vector<SetupItem>::push_back(&this->items, v168);
      LOBYTE(v197) = -75;
      SetupItem::~SetupItem(&v195);
      v169 = &this->items._Mylast[-1].onValueChanged;
      v170 = (std::function<void __cdecl(SetupItem *)> *)v169->_Impl;
      if ( v170 )
      {
        (*((void (__stdcall **)(bool))v170->_Space._Pfn[0] + 4))(v170 != v169);
        v169->_Impl = 0;
      }
      v169->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_ac215f37f6f1ac6a05cc355676d028ae_,0>,std::allocator<std::_Func_class<void,SetupItem *>>,void,SetupItem *>::`vftable';
      v169->_Space._Pfn[1] = (void (__cdecl *)())this;
      *(float *)&v169->_Space._Pfn[2] = v163;
      v169->_Impl = (std::_Func_base<void,SetupItem *> *)v169;
      v171 = this->items._Mylast;
      v197 = -1;
      v171[-1].attached = 1;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v194);
      ++LODWORD(v163);
      v164 = &this->car->drivetrain.gears;
      v165 = *(_DWORD *)isAttached + 32;
      *(_DWORD *)isAttached += 32;
    }
    while ( LODWORD(v163) < v164->_Mylast - v164->_Myfirst );
  }
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v172 = &this->car->drivetrain.finalRatio;
  v197 = 184;
  v183 = (Damper *)v172;
  std::wstring::wstring(&v182, L"FINAL_RATIO");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 185;
  std::vector<SetupItem>::push_back(&this->items, v173);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  v174 = this->items._Mylast;
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v174[-1].attached = 1;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v175 = aconnectedFloat;
  v197 = 186;
  v183 = (Damper *)(aconnectedFloat + 57);
  std::wstring::wstring(&v182, L"ENGINE_LIMITER");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 187;
  std::vector<SetupItem>::push_back(&this->items, v176);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v197 = 188;
  v183 = (Damper *)(v175 + 56);
  std::wstring::wstring(&v182, L"COAST_TORQUE_MULT");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 189;
  std::vector<SetupItem>::push_back(&this->items, v177);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 1.0;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, L"%");
  v178 = &this->car->userFFGain;
  v197 = 190;
  v183 = (Damper *)v178;
  std::wstring::wstring(&v182, L"FF_GAIN");
  v197 = -1;
  SetupItem::SetupItem(&v195, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 191;
  std::vector<SetupItem>::push_back(&this->items, v179);
  v197 = -1;
  SetupItem::~SetupItem(&v195);
  labelMult = 1.0;
  multiplier = 0.0099999998;
  v185 = v3;
  v188 = &v184;
  std::wstring::wstring(&v184, word_17BE9D8);
  v180 = &this->car->steerAssist;
  v197 = 192;
  v183 = (Damper *)v180;
  std::wstring::wstring(&v182, L"STEER_ASSIST");
  v197 = -1;
  SetupItem::SetupItem(&v196, v182, &v183->reboundSlow, v184, SLOBYTE(v185), multiplier, labelMult);
  v197 = 193;
  std::vector<SetupItem>::push_back(&this->items, v181);
  v197 = -1;
  SetupItem::~SetupItem(&v196);
}
char SetupManager::isSetupRespectingRules(SetupManager *this)
{
  int v2; // esi
  float h; // [esp+Ch] [ebp-1Ch]
  RaceEngineer eng; // [esp+10h] [ebp-18h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  if ( this->minimumHeight_m == -1.0 )
    return 1;
  RaceEngineer::RaceEngineer(&eng, this->car);
  v6 = 0;
  v2 = 0;
  while ( 1 )
  {
    h = RaceEngineer::evalRideHeight(&eng, v2);
    if ( this->minimumHeight_m > h )
      break;
    if ( ++v2 >= 2 )
    {
      v6 = -1;
      RaceEngineer::~RaceEngineer(&eng);
      return 1;
    }
  }
  v6 = -1;
  RaceEngineer::~RaceEngineer(&eng);
  return 0;
}
void SetupManager::load(SetupManager *this, const std::wstring *filename)
{
  const std::wstring *v3; // eax
  Car *v4; // eax
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  SetupItem *v7; // esi
  SetupItem *v8; // edi
  std::wstring *v9; // ebx
  int v10; // ebp
  int v11; // ebp
  float v12; // xmm0_4
  float value; // [esp+14h] [ebp-ECh]
  float step; // [esp+18h] [ebp-E8h]
  float min; // [esp+1Ch] [ebp-E4h]
  std::wstring key; // [esp+20h] [ebp-E0h] BYREF
  std::wstring result; // [esp+38h] [ebp-C8h] BYREF
  std::wstring v18; // [esp+50h] [ebp-B0h] BYREF
  INIReader paramINI; // [esp+68h] [ebp-98h] BYREF
  INIReader ini; // [esp+ACh] [ebp-54h] BYREF
  int v21; // [esp+FCh] [ebp-4h]

  if ( filename->_Myres < 8 )
    v3 = filename;
  else
    v3 = (const std::wstring *)filename->_Bx._Ptr;
  _printf("SetupManager::load: %S\n", v3->_Bx._Buf);
  INIReader::INIReader(&ini, filename);
  v4 = this->car;
  v21 = 0;
  v5 = std::operator+<wchar_t>(&result, L"content/cars/", &v4->unixName);
  LOBYTE(v21) = 1;
  v6 = std::operator+<wchar_t>(&v18, v5, L"/data/setup.ini");
  LOBYTE(v21) = 2;
  INIReader::INIReader(&paramINI, v6);
  if ( v18._Myres >= 8 )
    operator delete(v18._Bx._Ptr);
  v18._Myres = 7;
  v18._Mysize = 0;
  v18._Bx._Buf[0] = 0;
  LOBYTE(v21) = 5;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready && paramINI.ready )
  {
    v7 = this->items._Myfirst;
    v8 = this->items._Mylast;
    if ( v7 != v8 )
    {
      v9 = &v7->name;
      do
      {
        if ( INIReader::hasSection(&ini, v9) && INIReader::hasSection(&paramINI, v9) )
        {
          v9[2]._Bx._Alias[12] = 1;
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"VALUE", 5u);
          LOBYTE(v21) = 6;
          value = INIReader::getFloat(&ini, v9, &key);
          LOBYTE(v21) = 5;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"STEP", 4u);
          LOBYTE(v21) = 7;
          step = INIReader::getFloat(&paramINI, v9, &key);
          LOBYTE(v21) = 5;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"MIN", 3u);
          LOBYTE(v21) = 8;
          min = INIReader::getFloat(&paramINI, v9, &key);
          LOBYTE(v21) = 5;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"SHOW_CLICKS", 0xBu);
          LOBYTE(v21) = 9;
          v10 = INIReader::getInt(&paramINI, v9, &key);
          LOBYTE(v21) = 5;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          v11 = v10 - 1;
          if ( v11 )
          {
            if ( v11 == 1 )
              v12 = (float)(step * value) + min;
            else
              v12 = value;
          }
          else
          {
            v12 = step * value;
          }
          *(float *)&v9[2]._Bx._Alias[8] = v12;
        }
        ++v7;
        v9 = (std::wstring *)((char *)v9 + 104);
      }
      while ( v7 != v8 );
    }
  }
  else
  {
    _printf("ERROR: Cannot find specified setup file\n");
  }
  LOBYTE(v21) = 0;
  INIReader::~INIReader(&paramINI);
  v21 = -1;
  INIReader::~INIReader(&ini);
}
void SetupManager::step(SetupManager *this, float dt)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  SetupManager::step::__l9::<lambda_8990424759d146c5289371a5e8fa8e68> _Func; // [esp+4h] [ebp-4h] BYREF

  _Func.__this = this;
  std::_For_each<SetupItem *,_lambda_8990424759d146c5289371a5e8fa8e68_>(
    this->items._Myfirst,
    this->items._Mylast,
    &_Func);
  v3 = this->waitTime;
  if ( v3 > 0.0 && this->checkRules )
  {
    v4 = v3 - dt;
    this->setupState = UnKnown;
    this->waitTime = v4;
    if ( v4 <= 0.0 )
      this->setupState = 2 - (SetupManager::isSetupRespectingRules(this) != 0);
  }
}
