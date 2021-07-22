#include "drivingassistmanager.h
void DrivingAssistManager::DrivingAssistManager(DrivingAssistManager *this, Sim *sim)
{
  int v3; // ebx
  int v4; // eax
  bool v5; // cf
  Sim *v6; // eax
  bool v7; // cl
  TrackAvatar *v8; // eax
  CarAvatar *v9; // eax
  Sim *v10; // ecx
  ACClient *v11; // eax
  CarAvatar *v12; // eax
  CarAvatar *v13; // eax
  int v14; // esi
  ACClient *v15; // eax
  int v16; // esi
  CarAvatar *v17; // eax
  int v18; // esi
  ACClient *v19; // eax
  int v20; // esi
  CarAvatar *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  int v24; // eax
  int v25; // ebx
  int v26; // ebx
  ACClient *v27; // eax
  CarAvatar *v28; // eax
  int *v29; // esi
  unsigned int i; // ebx
  float v31; // xmm0_4
  CarAvatar *v32; // eax
  std::wstring receive; // [esp-14h] [ebp-16Ch] BYREF
  float gain; // [esp+4h] [ebp-154h]
  int autoclutch; // [esp+1Ch] [ebp-13Ch] BYREF
  char v36; // [esp+23h] [ebp-135h]
  int v37[3]; // [esp+24h] [ebp-134h] BYREF
  std::wstring section; // [esp+30h] [ebp-128h] BYREF
  std::wstring key; // [esp+48h] [ebp-110h] BYREF
  std::wstring v40; // [esp+60h] [ebp-F8h] BYREF
  std::wstring result; // [esp+78h] [ebp-E0h] BYREF
  std::wstring v42; // [esp+90h] [ebp-C8h] BYREF
  std::wstring v43; // [esp+A8h] [ebp-B0h] BYREF
  INIReaderDocuments ini; // [esp+C0h] [ebp-98h] BYREF
  INIReaderDocuments controlsINI; // [esp+104h] [ebp-54h] BYREF
  int v46; // [esp+154h] [ebp-4h]

  v37[1] = (int)this;
  v3 = 0;
  *(float *)&autoclutch = 0.0;
  v37[2] = (int)this;
  gain = *(float *)&sim->game;
  receive._Myres = 7;
  receive._Mysize = 0;
  receive._Bx._Buf[0] = 0;
  std::wstring::assign(&receive, L"DrivingAIDSManager", 0x12u);
  GameObject::GameObject(this, receive, (Game *)LODWORD(gain));
  gain = 0.0;
  this->__vftable = (DrivingAssistManager_vtbl *)&DrivingAssistManager::`vftable';
  this->sim = sim;
  v46 = 0;
  receive._Myres = 7;
  receive._Mysize = 0;
  receive._Bx._Buf[0] = 0;
  std::wstring::assign(&receive, L"cfg/assists.ini", 0xFu);
  INIReaderDocuments::INIReaderDocuments(&ini, 0, receive, SLOBYTE(gain));
  LOBYTE(v46) = 1;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"IDEAL_LINE", 0xAu);
  LOBYTE(v46) = 2;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v46) = 3;
  v4 = INIReader::getInt(&ini, &section, &key);
  v5 = section._Myres < 8;
  this->idealLine = v4 != 0;
  if ( !v5 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v46) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v6 = this->sim;
  v7 = this->idealLine;
  LODWORD(gain) = 9;
  receive._Myres = (unsigned int)L"AUTO_BLIP";
  v8 = v6->track;
  key._Myres = 7;
  key._Mysize = 0;
  v8->idealLine->isActive = v7;
  this->idealLine = v7;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, (const wchar_t *)receive._Myres, LODWORD(gain));
  LOBYTE(v46) = 4;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v46) = 5;
  LOBYTE(autoclutch) = INIReader::getInt(&ini, &section, &key) != 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v46) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LODWORD(gain) = autoclutch;
  v9 = Sim::getCar(this->sim, 0);
  CarAvatar::setAutoBlip(v9, SLOBYTE(gain));
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"STABILITY_CONTROL", 0x11u);
  LOBYTE(v46) = 6;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v46) = 7;
  *(float *)&autoclutch = INIReader::getFloat(&ini, &section, &key) * 0.0099999998;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v46) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v10 = this->sim;
  v11 = v10->client;
  if ( !v11 || v11->serverDrivingAssists.stability )
    LODWORD(gain) = autoclutch;
  else
    gain = 0.0;
  v12 = Sim::getCar(v10, 0);
  CarAvatar::setStabilityControl(v12, gain);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"AUTO_SHIFTER", 0xCu);
  LOBYTE(v46) = 8;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v46) = 9;
  LOBYTE(autoclutch) = INIReader::getInt(&ini, &section, &key) != 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v46) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LODWORD(gain) = autoclutch;
  v13 = Sim::getCar(this->sim, 0);
  CarAvatar::setAutoShifter(v13, SLOBYTE(gain));
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ABS", 3u);
  LOBYTE(v46) = 10;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v46) = 11;
  v14 = INIReader::getInt(&ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v46) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v15 = sim->client;
  if ( v15 )
  {
    v14 = v15->serverDrivingAssists.abs;
    _printf("USING SERVER BASED ABS SETTING:%d\n", v14);
  }
  if ( v14 )
  {
    v16 = v14 - 1;
    if ( v16 )
    {
      if ( v16 != 1 )
        goto LABEL_34;
      LODWORD(gain) = 1;
      receive._Myres = 1;
    }
    else
    {
      gain = 0.0;
      receive._Myres = 1;
    }
  }
  else
  {
    LODWORD(gain) = 1;
    receive._Myres = 0;
  }
  v17 = Sim::getCar(sim, 0);
  CarAvatar::setAbsEnabled(v17, receive._Myres, SLOBYTE(gain));
LABEL_34:
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACTION_CONTROL", 0x10u);
  LOBYTE(v46) = 12;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v46) = 13;
  v18 = INIReader::getInt(&ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v46) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v19 = sim->client;
  if ( v19 )
  {
    v18 = v19->serverDrivingAssists.tc;
    _printf("USING SERVER BASED TC SETTING:%d\n", v18);
  }
  if ( v18 )
  {
    v20 = v18 - 1;
    if ( v20 )
    {
      if ( v20 != 1 )
        goto LABEL_47;
      LODWORD(gain) = 1;
      receive._Myres = 1;
    }
    else
    {
      gain = 0.0;
      receive._Myres = 1;
    }
  }
  else
  {
    LODWORD(gain) = 1;
    receive._Myres = 0;
  }
  v21 = Sim::getCar(sim, 0);
  CarAvatar::setTcEnabled(v21, receive._Myres, SLOBYTE(gain));
LABEL_47:
  gain = 0.0;
  v36 = 0;
  receive._Myres = 7;
  receive._Mysize = 0;
  receive._Bx._Buf[0] = 0;
  std::wstring::assign(&receive, L"cfg/controls.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&controlsINI, 0, receive, SLOBYTE(gain));
  LOBYTE(v46) = 14;
  if ( controlsINI.ready )
  {
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, L"INPUT_METHOD", 0xCu);
    LOBYTE(v46) = 15;
    autoclutch = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    v46 = 16;
    autoclutch = 3;
    v22 = INIReader::getString(&controlsINI, &result, &section, &v40);
    LODWORD(gain) = 4;
    receive._Myres = (unsigned int)L"X360";
    receive._Mysize = v22->_Mysize;
    v3 = 7;
    v46 = 17;
    autoclutch = 7;
    if ( !std::wstring::compare(v22, 0, receive._Mysize, L"X360", 4u) )
      goto LABEL_50;
    std::wstring::wstring(&v42, L"INPUT_METHOD");
    v46 = 18;
    autoclutch = 15;
    std::wstring::wstring(&key, L"HEADER");
    v46 = 19;
    autoclutch = 31;
    v23 = INIReader::getString(&controlsINI, &v43, &key, &v42);
    LODWORD(gain) = 8;
    receive._Myres = (unsigned int)L"KEYBOARD";
    receive._Mysize = v23->_Mysize;
    v3 = 63;
    v46 = 20;
    autoclutch = 63;
    v24 = std::wstring::compare(v23, 0, receive._Mysize, L"KEYBOARD", 8u);
    v36 = 0;
    if ( !v24 )
LABEL_50:
      v36 = 1;
    if ( (v3 & 0x20) != 0 )
    {
      v3 &= 0xFFFFFFDF;
      if ( v43._Myres >= 8 )
        operator delete(v43._Bx._Ptr);
      v43._Myres = 7;
      v43._Mysize = 0;
      v43._Bx._Buf[0] = 0;
    }
    if ( (v3 & 0x10) != 0 )
    {
      v3 &= 0xFFFFFFEF;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
    }
    if ( (v3 & 8) != 0 )
    {
      v3 &= 0xFFFFFFF7;
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v42._Myres = 7;
      v42._Mysize = 0;
      v42._Bx._Buf[0] = 0;
    }
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFFFFFFFB;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFFFFFFFD;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    v46 = 14;
    if ( (v3 & 1) != 0 )
    {
      v3 &= 0xFFFFFFFE;
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
    }
  }
  v42._Myres = 7;
  v42._Mysize = 0;
  v42._Bx._Buf[0] = 0;
  std::wstring::assign(&v42, L"AUTO_CLUTCH", 0xBu);
  v25 = v3 | 0x40;
  LOBYTE(v46) = 21;
  autoclutch = v25;
  std::wstring::wstring(&v40, L"ASSISTS");
  v46 = 22;
  v26 = v25 | 0x80;
  autoclutch = v26;
  if ( INIReader::getInt(&ini, &v40, &v42) || (LOBYTE(autoclutch) = 0, v36) )
    LOBYTE(autoclutch) = 1;
  if ( (v26 & 0x80u) != 0 )
  {
    LOBYTE(v26) = v26 & 0x7F;
    if ( v40._Myres >= 8 )
      operator delete(v40._Bx._Ptr);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
  }
  v46 = 14;
  if ( (v26 & 0x40) != 0 && v42._Myres >= 8 )
    operator delete(v42._Bx._Ptr);
  v27 = sim->client;
  if ( !v27 || v27->serverDrivingAssists.autoClutch )
  {
    LODWORD(gain) = autoclutch;
  }
  else
  {
    _printf("AUTO CLUTCH TURNED OFF BY THE SERVER\n");
    gain = 0.0;
  }
  v28 = Sim::getCar(sim, 0);
  CarAvatar::setAutoClutchEnabled(v28, SLOBYTE(gain));
  if ( !sim->client )
  {
    std::wstring::wstring(&result, L"DAMAGE");
    LOBYTE(v46) = 23;
    std::wstring::wstring(&v40, L"ASSISTS");
    LOBYTE(v46) = 24;
    sim->physicsAvatar->engine.mechanicalDamageRate = (float)INIReader::getInt(&ini, &v40, &result) * 0.0099999998;
    if ( v40._Myres >= 8 )
      operator delete(v40._Bx._Ptr);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    LOBYTE(v46) = 14;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"FUEL_RATE");
    LOBYTE(v46) = 25;
    std::wstring::wstring(&v40, L"ASSISTS");
    LOBYTE(v46) = 26;
    sim->physicsAvatar->engine.fuelConsumptionRate = INIReader::getFloat(&ini, &v40, &result);
    if ( v40._Myres >= 8 )
      operator delete(v40._Bx._Ptr);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    LOBYTE(v46) = 14;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"TYRE_WEAR");
    LOBYTE(v46) = 27;
    std::wstring::wstring(&v40, L"ASSISTS");
    LOBYTE(v46) = 28;
    sim->physicsAvatar->engine.tyreConsumptionRate = INIReader::getFloat(&ini, &v40, &result);
    if ( v40._Myres >= 8 )
      operator delete(v40._Bx._Ptr);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    LOBYTE(v46) = 14;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"TYRE_BLANKETS");
    LOBYTE(v46) = 29;
    std::wstring::wstring(&v40, L"ASSISTS");
    LOBYTE(v46) = 30;
    sim->physicsAvatar->engine.allowTyreBlankets = INIReader::getInt(&ini, &v40, &result) != 0;
    if ( v40._Myres >= 8 )
      operator delete(v40._Bx._Ptr);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    LOBYTE(v46) = 14;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"SLIPSTREAM");
    LOBYTE(v46) = 31;
    std::wstring::wstring(&v40, L"ASSISTS");
    LOBYTE(v46) = 32;
    *(float *)&autoclutch = INIReader::getFloat(&ini, &v40, &result);
    v29 = &autoclutch;
    v37[0] = 1065353216;
    if ( *(float *)&autoclutch <= 1.0 )
      v29 = v37;
    if ( v40._Myres >= 8 )
      operator delete(v40._Bx._Ptr);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    LOBYTE(v46) = 14;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    for ( i = 0; i < sim->cars._Mylast - sim->cars._Myfirst; ++i )
    {
      v31 = *(float *)v29;
      if ( i )
      {
        LODWORD(gain) = *v29;
        receive._Myres = 1065353216;
        receive._Mysize = i;
      }
      else
      {
        gain = 1.0;
        *(float *)&receive._Myres = v31;
        receive._Mysize = 0;
      }
      v32 = Sim::getCar(sim, receive._Mysize);
      CarAvatar::setSlipStreamEffects(v32, *(float *)&receive._Myres, gain);
    }
  }
  LOBYTE(v46) = 1;
  INIReaderDocuments::~INIReaderDocuments(&controlsINI);
  LOBYTE(v46) = 0;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
DrivingAssistManager *DrivingAssistManager::`vector deleting destructor'(DrivingAssistManager *this, unsigned int a2)
{
  this->__vftable = (DrivingAssistManager_vtbl *)&DrivingAssistManager::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double DrivingAssistManager::getStabilityControl(DrivingAssistManager *this)
{
  CarAvatar *v1; // eax

  v1 = Sim::getCar(this->sim, 0);
  return CarAvatar::getStabilityControl(v1);
}
void DrivingAssistManager::setIdealLine(DrivingAssistManager *this, bool mode)
{
  this->sim->track->idealLine->isActive = mode;
  this->idealLine = mode;
}
void DrivingAssistManager::update(DrivingAssistManager *this, float dt)
{
  this->sim->track->idealLine->isActive = this->idealLine;
}
