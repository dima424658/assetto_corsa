#include "drs.h
void DRS::init(DRS *this, Car *car)
{
  Car *v3; // esi
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  const std::wstring *v6; // eax
  bool v7; // bl
  bool v8; // bl
  int v9; // eax
  bool v10; // cf
  bool v11; // bl
  double v12; // st7
  unsigned int v13; // edi
  std::wostream *v14; // eax
  const std::wstring *v15; // eax
  bool v16; // bl
  Wing *v17; // eax
  const std::wstring *v18; // eax
  const std::wstring *v19; // eax
  const std::wstring *v20; // eax
  std::wstring *v21; // esi
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  DRSWingConnection *v25; // eax
  DRSWingConnection *v26; // ecx
  int v27; // edi
  DRSWingConnection *v28; // eax
  const __m128i *v29; // edi
  DRSWingConnection *v30; // eax
  int v31; // eax
  int v32; // [esp+20h] [ebp-218h]
  int v33; // [esp+24h] [ebp-214h]
  unsigned int v34; // [esp+28h] [ebp-210h]
  int v35; // [esp+2Ch] [ebp-20Ch]
  DRSWingConnection wc; // [esp+30h] [ebp-208h] BYREF
  Car *v37; // [esp+40h] [ebp-1F8h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v38; // [esp+44h] [ebp-1F4h] BYREF
  std::wstring mode; // [esp+F4h] [ebp-144h] BYREF
  std::wstring key; // [esp+10Ch] [ebp-12Ch] BYREF
  std::wstring v41; // [esp+124h] [ebp-114h] BYREF
  std::wstring v42; // [esp+13Ch] [ebp-FCh] BYREF
  std::wstring v43; // [esp+154h] [ebp-E4h] BYREF
  std::wstring result; // [esp+16Ch] [ebp-CCh] BYREF
  std::wstring v45; // [esp+184h] [ebp-B4h] BYREF
  std::wstring v46; // [esp+19Ch] [ebp-9Ch] BYREF
  std::wstring v47; // [esp+1B4h] [ebp-84h] BYREF
  INIReader ini; // [esp+1CCh] [ebp-6Ch] BYREF
  std::wstring v49; // [esp+210h] [ebp-28h] BYREF
  int v50; // [esp+234h] [ebp-4h]

  v3 = car;
  v35 = 0;
  v37 = car;
  this->car = car;
  *(_WORD *)&this->isPresent = 0;
  v4 = std::operator+<wchar_t>(&result, L"content/cars/", &car->unixName);
  v50 = 0;
  v5 = std::operator+<wchar_t>(&v46, v4, L"/data/drs.ini");
  LOBYTE(v50) = 1;
  v6 = Car::getConfigPath(car, &v47, v5);
  LOBYTE(v50) = 2;
  INIReader::INIReader(&ini, v6);
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  if ( v46._Myres >= 8 )
    operator delete(v46._Bx._Ptr);
  v46._Myres = 7;
  v46._Mysize = 0;
  v46._Bx._Buf[0] = 0;
  LOBYTE(v50) = 6;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  ini.suppressErrorReporting = 1;
  if ( ini.ready )
  {
    _printf("LOADING DRS\n");
    v33 = 1;
    mode._Myres = 7;
    mode._Mysize = 0;
    mode._Bx._Buf[0] = 0;
    std::wstring::assign(&mode, L"HEADER", 6u);
    LOBYTE(v50) = 7;
    v7 = INIReader::hasSection(&ini, &mode);
    LOBYTE(v50) = 6;
    if ( mode._Myres >= 8 )
      operator delete(mode._Bx._Ptr);
    if ( v7 )
    {
      std::wstring::wstring(&key, L"VERSION");
      LOBYTE(v50) = 8;
      std::wstring::wstring(&mode, L"HEADER");
      LOBYTE(v50) = 9;
      v33 = INIReader::getInt(&ini, &mode, &key);
      if ( mode._Myres >= 8 )
        operator delete(mode._Bx._Ptr);
      mode._Myres = 7;
      mode._Mysize = 0;
      mode._Bx._Buf[0] = 0;
      LOBYTE(v50) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    mode._Myres = 7;
    mode._Mysize = 0;
    mode._Bx._Buf[0] = 0;
    std::wstring::assign(&mode, L"DRS_ZONES", 9u);
    LOBYTE(v50) = 10;
    v8 = INIReader::hasSection(&ini, &mode);
    LOBYTE(v50) = 6;
    if ( mode._Myres >= 8 )
      operator delete(mode._Bx._Ptr);
    if ( v8 )
    {
      std::wstring::wstring(&key, L"IGNORE_ZONES");
      LOBYTE(v50) = 11;
      std::wstring::wstring(&mode, L"DRS_ZONES");
      LOBYTE(v50) = 12;
      v9 = INIReader::getInt(&ini, &mode, &key);
      v10 = mode._Myres < 8;
      this->ignoreZones = v9 != 0;
      if ( !v10 )
        operator delete(mode._Bx._Ptr);
      mode._Myres = 7;
      mode._Mysize = 0;
      mode._Bx._Buf[0] = 0;
      LOBYTE(v50) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    mode._Myres = 7;
    mode._Mysize = 0;
    mode._Bx._Buf[0] = 0;
    std::wstring::assign(&mode, L"DEACTIVATION", 0xCu);
    LOBYTE(v50) = 13;
    v11 = INIReader::hasSection(&ini, &mode);
    LOBYTE(v50) = 6;
    if ( mode._Myres >= 8 )
      operator delete(mode._Bx._Ptr);
    if ( v11 )
    {
      std::wstring::wstring(&key, L"LIMIT_G");
      LOBYTE(v50) = 14;
      std::wstring::wstring(&mode, L"DEACTIVATION");
      LOBYTE(v50) = 15;
      v12 = INIReader::getFloat(&ini, &mode, &key);
      v10 = mode._Myres < 8;
      this->limitG = v12;
      if ( !v10 )
        operator delete(mode._Bx._Ptr);
      mode._Myres = 7;
      mode._Mysize = 0;
      mode._Bx._Buf[0] = 0;
      LOBYTE(v50) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    v13 = 0;
    v34 = 0;
    if ( car->aeroMap.wings._Mylast - car->aeroMap.wings._Myfirst )
    {
      v32 = 0;
      do
      {
        *(_DWORD *)v38.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v38.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v38.gap68);
        v35 |= 1u;
        LOBYTE(v50) = 16;
        std::wiostream::basic_iostream<wchar_t>(&v38, &v38.gap10[8], 0);
        v50 = 17;
        *(_DWORD *)&v38.gap0[*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(Car **)((char *)&v37 + *(_DWORD *)(*(_DWORD *)v38.gap0 + 4)) = (Car *)(*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)
                                                                               - 104);
        std::wstreambuf::wstreambuf(&v38.gap10[8]);
        *(_DWORD *)&v38.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v38.gap10[64] = 0;
        *(_DWORD *)&v38.gap10[68] = 0;
        LOBYTE(v50) = 19;
        v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v38.gap10, "WING_");
        std::wostream::operator<<(v14, v13);
        v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &key);
        LOBYTE(v50) = 20;
        v16 = INIReader::hasSection(&ini, v15);
        LOBYTE(v50) = 19;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        if ( v16 )
        {
          v17 = &v3->aeroMap.wings._Myfirst[v32];
          wc.angle = 0.0;
          wc.wing = v17;
          wc.mode = UseEffect;
          mode._Myres = 7;
          mode._Mysize = 0;
          mode._Bx._Buf[0] = 0;
          std::wstring::assign(&mode, L"EFFECT", 6u);
          LOBYTE(v50) = 21;
          v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &v41);
          LOBYTE(v50) = 22;
          wc.effect = INIReader::getFloat(&ini, v18, &mode);
          if ( v41._Myres >= 8 )
            operator delete(v41._Bx._Ptr);
          v41._Myres = 7;
          v41._Mysize = 0;
          v41._Bx._Buf[0] = 0;
          LOBYTE(v50) = 19;
          if ( mode._Myres >= 8 )
            operator delete(mode._Bx._Ptr);
          if ( v33 >= 2 )
          {
            v43._Myres = 7;
            v43._Mysize = 0;
            v43._Bx._Buf[0] = 0;
            std::wstring::assign(&v43, L"MODE", 4u);
            LOBYTE(v50) = 23;
            v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &v45);
            LOBYTE(v50) = 24;
            INIReader::getString(&ini, &mode, v19, &v43);
            if ( v45._Myres >= 8 )
              operator delete(v45._Bx._Ptr);
            v45._Myres = 7;
            v45._Mysize = 0;
            v45._Bx._Buf[0] = 0;
            LOBYTE(v50) = 27;
            if ( v43._Myres >= 8 )
              operator delete(v43._Bx._Ptr);
            v43._Myres = 7;
            v43._Mysize = 0;
            v43._Bx._Buf[0] = 0;
            if ( std::wstring::compare(&mode, 0, mode._Mysize, L"ANGLE", 5u) )
            {
              if ( std::wstring::compare(&mode, 0, mode._Mysize, L"EFFECT", 6u) )
              {
                v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                        &v38,
                        &v49);
                LOBYTE(v50) = 30;
                v22 = std::operator+<wchar_t>(&key, L"ERROR: Unknown DRS mode ", &mode);
                LOBYTE(v50) = 31;
                v23 = std::operator+<wchar_t>(&v41, v22, L" for wing ");
                LOBYTE(v50) = 32;
                v24 = std::operator+<wchar_t>(&v42, v23, v21);
                v10 = v24->_Myres < 8;
                LOBYTE(v50) = 33;
                if ( !v10 )
                  v24 = (std::wstring *)v24->_Bx._Ptr;
                _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v24->_Bx._Buf);
                ksGenerateCrash();
                if ( v42._Myres >= 8 )
                  operator delete(v42._Bx._Ptr);
                v42._Myres = 7;
                v42._Mysize = 0;
                v42._Bx._Buf[0] = 0;
                if ( v41._Myres >= 8 )
                  operator delete(v41._Bx._Ptr);
                v41._Myres = 7;
                v41._Mysize = 0;
                v41._Bx._Buf[0] = 0;
                if ( key._Myres >= 8 )
                  operator delete(key._Bx._Ptr);
                key._Myres = 7;
                key._Mysize = 0;
                key._Bx._Buf[0] = 0;
                if ( v49._Myres >= 8 )
                  operator delete(v49._Bx._Ptr);
              }
            }
            else
            {
              wc.mode = UseAngle;
              v41._Myres = 7;
              v41._Mysize = 0;
              v41._Bx._Buf[0] = 0;
              std::wstring::assign(&v41, L"ANGLE", 5u);
              LOBYTE(v50) = 28;
              v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &v42);
              LOBYTE(v50) = 29;
              wc.angle = INIReader::getFloat(&ini, v20, &v41);
              if ( v42._Myres >= 8 )
                operator delete(v42._Bx._Ptr);
              v42._Myres = 7;
              v42._Mysize = 0;
              v42._Bx._Buf[0] = 0;
              if ( v41._Myres >= 8 )
                operator delete(v41._Bx._Ptr);
            }
            LOBYTE(v50) = 19;
            if ( mode._Myres >= 8 )
              operator delete(mode._Bx._Ptr);
          }
          v25 = this->wings._Mylast;
          if ( &wc >= v25 || (v26 = this->wings._Myfirst, v26 > &wc) )
          {
            if ( v25 == this->wings._Myend )
              std::vector<VisualDamageManager::ScratchablePart>::_Reserve(&this->wings, 1u);
            v30 = this->wings._Mylast;
            if ( v30 )
              *(__m128i *)v30 = _mm_loadu_si128((const __m128i *)&wc);
          }
          else
          {
            v27 = (char *)&wc - (char *)v26;
            if ( v25 == this->wings._Myend )
              std::vector<VisualDamageManager::ScratchablePart>::_Reserve(&this->wings, 1u);
            v28 = this->wings._Mylast;
            v29 = (const __m128i *)((char *)this->wings._Myfirst + (v27 & 0xFFFFFFF0));
            if ( v28 )
              *(__m128i *)v28 = _mm_loadu_si128(v29);
            v13 = v34;
          }
          ++this->wings._Mylast;
          v3 = v37;
          this->isPresent = 1;
        }
        LOBYTE(v50) = 6;
        *(_DWORD *)&v38.gap0[*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(Car **)((char *)&v37 + *(_DWORD *)(*(_DWORD *)v38.gap0 + 4)) = (Car *)(*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)
                                                                               - 104);
        *(_DWORD *)&v38.gap10[8] = &std::wstringbuf::`vftable';
        if ( (v38.gap10[68] & 1) != 0 )
        {
          if ( std::wstreambuf::pptr(&v38.gap10[8]) )
            std::wstreambuf::epptr(&v38.gap10[8]);
          else
            std::wstreambuf::egptr(&v38.gap10[8]);
          std::wstreambuf::eback(&v38.gap10[8]);
          v31 = std::wstreambuf::eback(&v38.gap10[8]);
          operator delete(v31);
        }
        std::wstreambuf::setg(&v38.gap10[8], 0, 0, 0);
        std::wstreambuf::setp(&v38.gap10[8], 0, 0);
        *(_DWORD *)&v38.gap10[68] &= 0xFFFFFFFE;
        *(_DWORD *)&v38.gap10[64] = 0;
        std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[8]);
        std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[16]);
        std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v38.gap68);
        v34 = ++v13;
        ++v32;
      }
      while ( v13 < v3->aeroMap.wings._Mylast - v3->aeroMap.wings._Myfirst );
    }
  }
  v50 = -1;
  INIReader::~INIReader(&ini);
}
void DRS::step(DRS *this, float dt)
{
  bool v3; // cl
  Car *v4; // edx
  float v5; // xmm1_4
  bool v6; // zf
  DRSWingConnection *v7; // esi
  DRSWingConnection *v8; // edi
  DRWWingConnectionMode v9; // eax
  DRWWingConnectionMode v10; // eax

  if ( this->isPresent )
  {
    v3 = this->ignoreZones || DRSManager::isDRSAvailable(this->car->ksPhysics->track->drsMamanger._Myptr, this->car);
    v4 = this->car;
    this->isAvailable = v3;
    if ( v4->controls.drs && !this->lastState && v3 )
      this->isActive = !this->isActive;
    this->lastState = v4->controls.drs;
    if ( !v3
      || v4->controls.brake > 0.1
      || (v5 = this->limitG, v5 > 0.0) && COERCE_FLOAT(LODWORD(v4->accG.x) & _xmm) > v5 )
    {
      this->isActive = 0;
    }
    v6 = !this->isActive;
    v7 = this->wings._Myfirst;
    v8 = this->wings._Mylast;
    if ( v6 )
    {
      for ( ; v7 != v8; ++v7 )
      {
        v10 = v7->mode;
        if ( v10 )
        {
          if ( v10 == UseAngle )
            Wing::clearOverrides(v7->wing);
        }
        else
        {
          v7->wing->status.angleMult = 1.0;
        }
      }
    }
    else
    {
      for ( ; v7 != v8; ++v7 )
      {
        v9 = v7->mode;
        if ( v9 )
        {
          if ( v9 == UseAngle )
            Wing::setOverrideAngle(v7->wing, v7->angle);
        }
        else
        {
          v7->wing->status.angleMult = v7->effect;
        }
      }
    }
  }
}
