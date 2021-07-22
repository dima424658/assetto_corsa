#include "carhintloader.h"
void CarHintLoader::CarHintLoader(CarHintLoader *this, const std::wstring *unixName, const std::wstring *config)
{
  char v4; // bl
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // ebp
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // ebp
  const std::wstring *v12; // eax
  std::wstring *v13; // ebp
  const std::wstring *v14; // eax
  int v15; // esi
  std::wstring *v16; // esi
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  const std::wstring *v19; // eax
  int v20; // esi
  std::wstring *v21; // eax
  bool v22; // al
  std::wstring *v23; // eax
  const std::wstring *v24; // eax
  int i; // esi
  std::wstring *v26; // eax
  char v27; // al
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  const std::wstring *v30; // eax
  std::wstring *v31; // eax
  const std::wstring *v32; // eax
  int v33; // eax
  std::wstring *v34; // eax
  bool v35; // bl
  std::wstring *v36; // eax
  std::wstring v37; // [esp-1Ch] [ebp-330h] BYREF
  std::wstring *v38; // [esp-4h] [ebp-318h]
  bool v39; // [esp+16h] [ebp-2FEh]
  bool v40; // [esp+17h] [ebp-2FDh]
  int v41; // [esp+18h] [ebp-2FCh]
  CarHintLoader *v42; // [esp+1Ch] [ebp-2F8h]
  std::wstring iniName; // [esp+20h] [ebp-2F4h] BYREF
  std::wstring section; // [esp+38h] [ebp-2DCh] BYREF
  std::wstring key; // [esp+50h] [ebp-2C4h] BYREF
  std::wstring text; // [esp+68h] [ebp-2ACh] BYREF
  std::wstring data_folder; // [esp+80h] [ebp-294h] BYREF
  std::wstring result; // [esp+98h] [ebp-27Ch] BYREF
  std::wstring v49; // [esp+B0h] [ebp-264h] BYREF
  std::wstring v50; // [esp+C8h] [ebp-24Ch] BYREF
  std::wstring v51; // [esp+E0h] [ebp-234h] BYREF
  std::wstring v52; // [esp+F8h] [ebp-21Ch] BYREF
  std::wstring v53; // [esp+110h] [ebp-204h] BYREF
  INIReader tini; // [esp+128h] [ebp-1ECh] BYREF
  INIReader dini; // [esp+16Ch] [ebp-1A8h] BYREF
  INIReader bini; // [esp+1B0h] [ebp-164h] BYREF
  INIReader idrs; // [esp+1F4h] [ebp-120h] BYREF
  INIReader ityre; // [esp+238h] [ebp-DCh] BYREF
  INIReaderDocuments iass; // [esp+27Ch] [ebp-98h] BYREF
  INIReader icar; // [esp+2C0h] [ebp-54h] BYREF
  int v61; // [esp+310h] [ebp-4h]

  v4 = 0;
  v41 = 0;
  v42 = this;
  this->hints._Myfirst = 0;
  this->hints._Mylast = 0;
  this->hints._Myend = 0;
  v5 = &this->carName;
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  v61 = 0;
  this->carName._Bx._Buf[0] = 0;
  data_folder._Myres = 7;
  data_folder._Mysize = 0;
  data_folder._Bx._Buf[0] = 0;
  v38 = (std::wstring *)unixName;
  LOBYTE(v61) = 2;
  v37._Myres = (unsigned int)L"content/cars/";
  v37._Mysize = (unsigned int)&result;
  if ( config->_Mysize )
  {
    v8 = std::operator+<wchar_t>((std::wstring *)v37._Mysize, (const wchar_t *)v37._Myres, v38);
    LOBYTE(v61) = 4;
    v9 = std::operator+<wchar_t>(&key, v8, L"/data_");
    LOBYTE(v61) = 5;
    v10 = std::operator+<wchar_t>(&section, v9, config);
    LOBYTE(v61) = 6;
    v11 = std::operator+<wchar_t>(&iniName, v10, L"/");
    if ( &data_folder != v11 )
    {
      if ( data_folder._Myres >= 8 )
        operator delete(data_folder._Bx._Ptr);
      data_folder._Myres = 7;
      data_folder._Mysize = 0;
      data_folder._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&data_folder, v11);
    }
    if ( iniName._Myres >= 8 )
      operator delete(iniName._Bx._Ptr);
    iniName._Myres = 7;
    iniName._Mysize = 0;
    iniName._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
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
  else
  {
    v6 = std::operator+<wchar_t>((std::wstring *)v37._Mysize, (const wchar_t *)v37._Myres, v38);
    LOBYTE(v61) = 3;
    v7 = std::operator+<wchar_t>(&iniName, v6, L"/data/");
    if ( &data_folder != v7 )
    {
      if ( data_folder._Myres >= 8 )
        operator delete(data_folder._Bx._Ptr);
      data_folder._Myres = 7;
      data_folder._Mysize = 0;
      data_folder._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&data_folder, v7);
    }
    if ( iniName._Myres >= 8 )
      operator delete(iniName._Bx._Ptr);
    iniName._Myres = 7;
    iniName._Mysize = 0;
    iniName._Bx._Buf[0] = 0;
  }
  LOBYTE(v61) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v12 = std::operator+<wchar_t>(&v53, &data_folder, L"car.ini");
  LOBYTE(v61) = 7;
  INIReader::INIReader(&icar, v12);
  LOBYTE(v61) = 9;
  if ( v53._Myres >= 8 )
    operator delete(v53._Bx._Ptr);
  v53._Myres = 7;
  v53._Mysize = 0;
  v53._Bx._Buf[0] = 0;
  if ( icar.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SCREEN_NAME", 0xBu);
    LOBYTE(v61) = 10;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"INFO", 4u);
    LOBYTE(v61) = 11;
    v13 = INIReader::getString(&icar, &iniName, &key, &section);
    if ( v5 != v13 )
    {
      if ( v5->_Myres >= 8 )
        operator delete(v5->_Bx._Ptr);
      v5->_Myres = 7;
      v5->_Mysize = 0;
      v38 = v13;
      v5->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(v5, v38);
    }
    if ( iniName._Myres >= 8 )
      operator delete(iniName._Bx._Ptr);
    iniName._Myres = 7;
    iniName._Mysize = 0;
    iniName._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v61) = 9;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  v14 = std::operator+<wchar_t>(&v51, &data_folder, L"tyres.ini");
  LOBYTE(v61) = 12;
  INIReader::INIReader(&ityre, v14);
  LOBYTE(v61) = 14;
  if ( v51._Myres >= 8 )
    operator delete(v51._Bx._Ptr);
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  if ( ityre.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"VERSION", 7u);
    LOBYTE(v61) = 15;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HEADER", 6u);
    LOBYTE(v61) = 16;
    v15 = INIReader::getInt(&ityre, &key, &section);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v61) = 14;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v15 > 4 )
    {
      std::wstring::wstring(&text, L"Tyre Model Version ");
      LOBYTE(v61) = 17;
      v16 = std::to_wstring(&key, v15);
      LOBYTE(v61) = 18;
      v17 = acTranslate(&section, &text);
      LOBYTE(v61) = 19;
      v18 = std::operator+<wchar_t>(&iniName, v17, v16);
      LOBYTE(v61) = 20;
      std::vector<std::wstring>::push_back(&this->hints, v18);
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v61) = 14;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
  }
  v19 = std::operator+<wchar_t>(&v49, &data_folder, L"drs.ini");
  LOBYTE(v61) = 21;
  INIReader::INIReader(&idrs, v19);
  LOBYTE(v61) = 23;
  if ( v49._Myres >= 8 )
    operator delete(v49._Bx._Ptr);
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  if ( idrs.ready )
  {
    v20 = 0;
    while ( 1 )
    {
      v21 = std::to_wstring(&iniName, v20);
      LOBYTE(v61) = 24;
      std::operator+<wchar_t>(&section, L"WING_", v21);
      LOBYTE(v61) = 26;
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Bx._Buf[0] = 0;
      iniName._Mysize = 0;
      v22 = INIReader::hasSection(&idrs, &section);
      LOBYTE(v61) = 23;
      if ( v22 )
        break;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      if ( ++v20 >= 20 )
        goto LABEL_68;
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"Manually operated DRS. Use the assigned control to activate it", 0x3Eu);
    LOBYTE(v61) = 27;
    v23 = acTranslate(&iniName, &section);
    LOBYTE(v61) = 28;
    std::vector<std::wstring>::push_back(&this->hints, v23);
    if ( iniName._Myres >= 8 )
      operator delete(iniName._Bx._Ptr);
    iniName._Myres = 7;
    iniName._Mysize = 0;
    iniName._Bx._Buf[0] = 0;
    LOBYTE(v61) = 23;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
LABEL_68:
  v24 = std::operator+<wchar_t>(&v52, &data_folder, L"engine.ini");
  LOBYTE(v61) = 29;
  INIReader::INIReader(&tini, v24);
  LOBYTE(v61) = 31;
  if ( v52._Myres >= 8 )
    operator delete(v52._Bx._Ptr);
  v52._Myres = 7;
  v52._Mysize = 0;
  v52._Bx._Buf[0] = 0;
  v39 = 0;
  if ( tini.ready )
  {
    for ( i = 0; ; ++i )
    {
      v26 = std::to_wstring(&iniName, i);
      LOBYTE(v61) = 32;
      std::operator+<wchar_t>(&key, L"TURBO_", v26);
      LOBYTE(v61) = 34;
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Bx._Buf[0] = 0;
      iniName._Mysize = 0;
      if ( !INIReader::hasSection(&tini, &key) )
        break;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"COCKPIT_ADJUSTABLE", 0x12u);
      LOBYTE(v61) = 35;
      v27 = INIReader::getInt(&tini, &key, &section) != 0;
      v40 = v27;
      if ( section._Myres >= 8 )
      {
        operator delete(section._Bx._Ptr);
        v27 = v40;
      }
      LOBYTE(v61) = 31;
      if ( v27 )
      {
        v39 = 1;
        goto LABEL_82;
      }
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    LOBYTE(v61) = 31;
LABEL_82:
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&text, L"PUSH_TO_PASS");
    LOBYTE(v61) = 36;
    v40 = INIReader::hasSection(&tini, &text);
    LOBYTE(v61) = 31;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    if ( v39 )
    {
      std::wstring::wstring(&text, L"Cockpit adjustable Turbo(s). Use assigned controllers to operate it");
      LOBYTE(v61) = 37;
      v28 = acTranslate(&iniName, &text);
      LOBYTE(v61) = 38;
      std::vector<std::wstring>::push_back(&this->hints, v28);
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
      LOBYTE(v61) = 31;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
    if ( v40 )
    {
      std::wstring::wstring(&text, L"'Push 2 Pass' enabled in Practice and Race");
      LOBYTE(v61) = 39;
      v29 = acTranslate(&iniName, &text);
      LOBYTE(v61) = 40;
      std::vector<std::wstring>::push_back(&this->hints, v29);
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
      LOBYTE(v61) = 31;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
  }
  v30 = std::operator+<wchar_t>(&v50, &data_folder, L"brakes.ini");
  LOBYTE(v61) = 41;
  INIReader::INIReader(&bini, v30);
  LOBYTE(v61) = 43;
  if ( v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  if ( bini.ready )
  {
    std::wstring::wstring(&text, L"COCKPIT_ADJUSTABLE");
    LOBYTE(v61) = 44;
    std::wstring::wstring(&section, L"DATA");
    LOBYTE(v61) = 45;
    v40 = INIReader::getInt(&bini, &section, &text) != 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v61) = 43;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    if ( v40 )
    {
      std::wstring::wstring(&text, L"Cockpit operated Brake Balance. Use assigned controllers to operate it");
      LOBYTE(v61) = 46;
      v31 = acTranslate(&iniName, &text);
      LOBYTE(v61) = 47;
      std::vector<std::wstring>::push_back(&this->hints, v31);
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
      LOBYTE(v61) = 43;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
  }
  v38 = 0;
  v39 = 0;
  std::wstring::wstring(&v37, L"cfg/assists.ini");
  INIReaderDocuments::INIReaderDocuments(&iass, 0, v37, (bool)v38);
  LOBYTE(v61) = 48;
  if ( iass.ready )
  {
    std::wstring::wstring(&text, L"AUTO_BLIP");
    LOBYTE(v61) = 49;
    std::wstring::wstring(&section, L"ASSISTS");
    LOBYTE(v61) = 50;
    v39 = INIReader::getInt(&iass, &section, &text) != 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v61) = 48;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v32 = std::operator+<wchar_t>(&text, &data_folder, L"drivetrain.ini");
  LOBYTE(v61) = 51;
  INIReader::INIReader(&dini, v32);
  LOBYTE(v61) = 53;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( dini.ready )
  {
    if ( v39 )
      goto LABEL_119;
    std::wstring::wstring(&result, L"SUPPORTS_SHIFTER");
    LOBYTE(v61) = 54;
    v41 = 1;
    std::wstring::wstring(&iniName, L"GEARBOX");
    v61 = 55;
    v4 = 3;
    v41 = 3;
    if ( INIReader::getInt(&dini, &iniName, &result) )
      goto LABEL_119;
    std::wstring::wstring(&key, L"AUTO_CUTOFF_TIME");
    v61 = 56;
    v41 = 7;
    std::wstring::wstring(&section, L"GEARBOX");
    v61 = 57;
    v4 = 15;
    v41 = 15;
    v33 = INIReader::getInt(&dini, &section, &key);
    v39 = 1;
    if ( !v33 )
LABEL_119:
      v39 = 0;
    if ( (v4 & 8) != 0 )
    {
      v4 &= 0xF7u;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    if ( (v4 & 4) != 0 )
    {
      v4 &= 0xFBu;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
    }
    if ( (v4 & 2) != 0 )
    {
      v4 &= 0xFDu;
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
    }
    v61 = 53;
    if ( (v4 & 1) != 0 && result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v39 )
    {
      std::wstring::wstring(&result, L"Automatic Engine Cut Off: No need to close the gas for upshifts");
      LOBYTE(v61) = 58;
      v34 = acTranslate(&iniName, &result);
      LOBYTE(v61) = 59;
      std::vector<std::wstring>::push_back(&this->hints, v34);
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
      LOBYTE(v61) = 53;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    std::wstring::wstring(&result, L"ELECTRONIC");
    LOBYTE(v61) = 60;
    std::wstring::wstring(&iniName, L"AUTOBLIP");
    LOBYTE(v61) = 61;
    v35 = INIReader::getInt(&dini, &iniName, &result) != 0;
    if ( iniName._Myres >= 8 )
      operator delete(iniName._Bx._Ptr);
    iniName._Myres = 7;
    iniName._Mysize = 0;
    iniName._Bx._Buf[0] = 0;
    LOBYTE(v61) = 53;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v35 )
    {
      std::wstring::wstring(&result, L"Electronic Kicker: No need to blip the gas for downshifts");
      LOBYTE(v61) = 62;
      v36 = acTranslate(&iniName, &result);
      LOBYTE(v61) = 63;
      std::vector<std::wstring>::push_back(&this->hints, v36);
      if ( iniName._Myres >= 8 )
        operator delete(iniName._Bx._Ptr);
      iniName._Myres = 7;
      iniName._Mysize = 0;
      iniName._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  LOBYTE(v61) = 48;
  INIReader::~INIReader(&dini);
  LOBYTE(v61) = 43;
  INIReaderDocuments::~INIReaderDocuments(&iass);
  LOBYTE(v61) = 31;
  INIReader::~INIReader(&bini);
  LOBYTE(v61) = 23;
  INIReader::~INIReader(&tini);
  LOBYTE(v61) = 14;
  INIReader::~INIReader(&idrs);
  LOBYTE(v61) = 9;
  INIReader::~INIReader(&ityre);
  LOBYTE(v61) = 2;
  INIReader::~INIReader(&icar);
  if ( data_folder._Myres >= 8 )
    operator delete(data_folder._Bx._Ptr);
}
void CarHintLoader::~CarHintLoader(CarHintLoader *this)
{
  if ( this->carName._Myres >= 8 )
    operator delete(this->carName._Bx._Ptr);
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  this->carName._Bx._Buf[0] = 0;
  if ( this->hints._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)this);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(this->hints._Myfirst, this->hints._Mylast);
    operator delete(this->hints._Myfirst);
    this->hints._Myfirst = 0;
    this->hints._Mylast = 0;
    this->hints._Myend = 0;
  }
}
std::wstring *CarHintLoader::getCarName(CarHintLoader *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->carName, 0, 0xFFFFFFFF);
  return result;
}
std::vector<std::wstring> *CarHintLoader::getHints(CarHintLoader *this, std::vector<std::wstring> *result)
{
  std::vector<std::wstring>::vector<std::wstring>(result, &this->hints);
  return result;
}
