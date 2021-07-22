#include "fanatecupdater.h"
void FanatecUpdater::FanatecUpdater(FanatecUpdater *this, CarAvatar *carAvatar)
{
  void **v3; // ebx
  int v4; // eax
  bool v5; // bl
  bool v6; // cf
  double v7; // st7
  double v8; // st7
  double v9; // st7
  int v10; // eax
  Game *v11; // esi
  IFSDevice *v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  IFSDevice *v17; // eax
  IFSDevice *v18; // ecx
  std::wstring v19; // [esp-1Ch] [ebp-4FCh] BYREF
  Game *v20; // [esp-4h] [ebp-4E4h]
  _FS_DEVICE_CAPS DeviceCaps; // [esp+14h] [ebp-4CCh] BYREF
  FanatecUpdater *v22; // [esp+18h] [ebp-4C8h]
  std::wstring key; // [esp+20h] [ebp-4C0h] BYREF
  std::wstring sect; // [esp+38h] [ebp-4A8h] BYREF
  std::wstring ifilename; // [esp+50h] [ebp-490h] BYREF
  INIReader ini; // [esp+68h] [ebp-478h] BYREF
  _FS_DEVICE_INFO DeviceInfo; // [esp+ACh] [ebp-434h] BYREF
  int v28; // [esp+4DCh] [ebp-4h]

  v22 = this;
  v20 = carAvatar->game;
  v19._Myres = 7;
  v19._Mysize = 0;
  v19._Bx._Buf[0] = 0;
  std::wstring::assign(&v19, L"FANATEC_UPDATER", 0xFu);
  GameObject::GameObject(this, v19, v20);
  this->car = carAvatar;
  v3 = (void **)&this->pCmdWheel;
  v20 = (Game *)"Init Fanatec Updater...\n";
  v28 = 0;
  this->__vftable = (FanatecUpdater_vtbl *)&FanatecUpdater::`vftable';
  this->pDeviceWheel = 0;
  this->pCmdLedRevs = 0;
  this->pCmdWheel = 0;
  this->pCmdSevenSegmentLedDisplay = 0;
  this->bIsConnected = 0;
  this->maxRpm = 0.0;
  this->minRpm = 0.0;
  this->blinkingOn = 0;
  this->blinkingTime = 0.0;
  this->BLINK_MAX_TIME = 0.1;
  this->MessageTime = 0.0;
  this->lastGear = -1;
  this->MESSAGE_MAX_TIME = 1.0;
  this->showGearTime = 0.0;
  this->GEAR_MAX_TIME = 1.0;
  this->showNextGear = 0;
  _printf((const char *const)v20);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/fanatec.ini", 0x16u);
  LOBYTE(v28) = 1;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v28) = 3;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    sect._Myres = 7;
    sect._Mysize = 0;
    sect._Bx._Buf[0] = 0;
    std::wstring::assign(&sect, L"SETTINGS", 8u);
    LOBYTE(v28) = 4;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ENABLED", 7u);
    LOBYTE(v28) = 5;
    v4 = INIReader::getInt(&ini, &sect, &key);
    LOBYTE(v28) = 4;
    v5 = v4 == 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v5 )
    {
      v6 = sect._Myres < 8;
      this->bIsConnected = 0;
      if ( !v6 )
        operator delete(sect._Bx._Ptr);
      sect._Myres = 7;
      sect._Mysize = 0;
      sect._Bx._Buf[0] = 0;
      LOBYTE(v28) = 0;
      goto LABEL_44;
    }
    std::wstring::wstring(&key, L"BLINK_MAX_TIME");
    LOBYTE(v28) = 6;
    v7 = INIReader::getFloat(&ini, &sect, &key);
    v6 = key._Myres < 8;
    this->BLINK_MAX_TIME = v7;
    LOBYTE(v28) = 4;
    if ( !v6 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"MESSAGE_MAX_TIME");
    LOBYTE(v28) = 7;
    v8 = INIReader::getFloat(&ini, &sect, &key);
    v6 = key._Myres < 8;
    this->MESSAGE_MAX_TIME = v8;
    LOBYTE(v28) = 4;
    if ( !v6 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"GEAR_MAX_TIME");
    LOBYTE(v28) = 8;
    v9 = INIReader::getFloat(&ini, &sect, &key);
    v6 = key._Myres < 8;
    this->GEAR_MAX_TIME = v9;
    LOBYTE(v28) = 4;
    if ( !v6 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SHOW_NEXT_GEAR");
    LOBYTE(v28) = 9;
    v10 = INIReader::getInt(&ini, &sect, &key);
    v6 = key._Myres < 8;
    this->showNextGear = v10 != 0;
    if ( !v6 )
      operator delete(key._Bx._Ptr);
    LOBYTE(v28) = 3;
    if ( sect._Myres >= 8 )
      operator delete(sect._Bx._Ptr);
    v3 = (void **)&this->pCmdWheel;
  }
  _printf("Loading Fanatec Updater...\n");
  v11 = 0;
  v12 = FSDeviceEnumerator::EnumerateInstance(0);
  this->pDeviceWheel = v12;
  if ( v12 )
  {
    do
    {
      v11 = (Game *)((char *)v11 + 1);
      memset(&DeviceInfo, 0, sizeof(DeviceInfo));
      this->pDeviceWheel->GetDeviceInfo(this->pDeviceWheel, &DeviceInfo);
      v13 = wcscmp(DeviceInfo.Name, L"FSDeviceWheelPorsche");
      if ( v13 )
        v13 = v13 < 0 ? -1 : 1;
      if ( !v13 )
        break;
      v14 = wcscmp(DeviceInfo.Name, L"FSDeviceWheelCSR");
      if ( v14 )
        v14 = v14 < 0 ? -1 : 1;
      if ( !v14 )
        break;
      v15 = wcscmp(DeviceInfo.Name, L"FSDeviceWheelCSW");
      if ( v15 )
        v15 = v15 < 0 ? -1 : 1;
      if ( !v15 )
        break;
      v16 = wcscmp(DeviceInfo.Name, L"FSDeviceWheelCSL");
      if ( v16 )
        v16 = v16 < 0 ? -1 : 1;
      if ( !v16 )
        break;
      this->pDeviceWheel->Release(this->pDeviceWheel);
      v20 = v11;
      this->pDeviceWheel = 0;
      v17 = FSDeviceEnumerator::EnumerateInstance((int)v20);
      this->pDeviceWheel = v17;
    }
    while ( v17 );
  }
  v18 = this->pDeviceWheel;
  if ( v18 )
  {
    this->bIsConnected = 1;
    DeviceCaps.0 = 0;
    v18->GetDeviceCaps(v18, &DeviceCaps);
    if ( (*(_BYTE *)&DeviceCaps.0 & 0x10) != 0 )
    {
      this->pDeviceWheel->QueryInterface(
        this->pDeviceWheel,
        FS_INTERFACETYPE_LED_REVS_WHEEL_RIM,
        (void **)&this->pCmdLedRevs);
      if ( !this->pCmdLedRevs )
        this->pDeviceWheel->QueryInterface(
          this->pDeviceWheel,
          FS_INTERFACETYPE_LED_REVS_WHEEL_BASE,
          (void **)&this->pCmdLedRevs);
    }
    if ( (*(_BYTE *)&DeviceCaps.0 & 4) != 0 )
      this->pDeviceWheel->QueryInterface(
        this->pDeviceWheel,
        FS_INTERFACETYPE_LED_DISPLAY_SEVEN_SEGMENT,
        (void **)&this->pCmdSevenSegmentLedDisplay);
    this->pDeviceWheel->QueryInterface(this->pDeviceWheel, FS_INTERFACETYPE_WHEEL, v3);
    if ( *v3 )
      (*(void (__cdecl **)(void *, _DWORD))(*(_DWORD *)*v3 + 4))(*v3, 0);
  }
  LOBYTE(v28) = 0;
LABEL_44:
  INIReader::~INIReader(&ini);
}
void FanatecUpdater::~FanatecUpdater(FanatecUpdater *this)
{
  IFSCmdLedRevs *v2; // ecx
  IFSCmdLedSevenSegmentDisplayThreeDigits *v3; // ecx
  IFSCmdWheel *v4; // ecx
  IFSDevice *v5; // ecx

  this->__vftable = (FanatecUpdater_vtbl *)&FanatecUpdater::`vftable';
  v2 = this->pCmdLedRevs;
  if ( v2 )
  {
    v2->ItemSetOff(v2, -1);
    this->pCmdLedRevs->SubmitToDevice(this->pCmdLedRevs);
    this->pCmdLedRevs->Destroy(this->pCmdLedRevs);
  }
  v3 = this->pCmdSevenSegmentLedDisplay;
  if ( v3 )
  {
    v3->SetNumber(v3, 0);
    this->pCmdSevenSegmentLedDisplay->ItemSetOff(this->pCmdSevenSegmentLedDisplay, -1);
    this->pCmdSevenSegmentLedDisplay->SubmitToDevice(this->pCmdSevenSegmentLedDisplay);
    this->pCmdSevenSegmentLedDisplay->Destroy(this->pCmdSevenSegmentLedDisplay);
  }
  v4 = this->pCmdWheel;
  if ( v4 )
    v4->Destroy(this->pCmdWheel);
  v5 = this->pDeviceWheel;
  this->pCmdLedRevs = 0;
  this->pCmdSevenSegmentLedDisplay = 0;
  this->pCmdWheel = 0;
  if ( v5 )
    v5->Release(v5);
  this->pDeviceWheel = 0;
  GameObject::~GameObject(this);
}
FanatecUpdater *FanatecUpdater::`vector deleting destructor'(FanatecUpdater *this, unsigned int a2)
{
  FanatecUpdater::~FanatecUpdater(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FanatecUpdater::update(FanatecUpdater *this, float dt)
{
  float v2; // xmm4_4
  IFSCmdLedRevs *v4; // edx
  CarAvatar *v5; // eax
  CarAvatar *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  bool v9; // cc
  float v10; // xmm0_4
  bool v11; // zf
  IFSCmdLedRevs_vtbl *v12; // ecx
  IFSCmdLedRevs *v13; // eax
  int v14; // ebp
  int v15; // edi
  int v16; // ebx
  float v17; // xmm2_4
  IFSCmdLedRevs_vtbl *v18; // ecx
  IFSCmdLedSevenSegmentDisplayThreeDigits *v19; // edx
  int v20; // edi
  int v21; // ecx
  int v22; // eax
  CarAvatar *v23; // eax
  float v24; // xmm0_4
  IFSCmdLedRevs *v25; // [esp-18h] [ebp-1Ch]
  BOOL v26; // [esp-18h] [ebp-1Ch]
  IFSCmdLedRevs *v27; // [esp-10h] [ebp-14h]
  BOOL v28; // [esp-10h] [ebp-14h]
  float i; // [esp+0h] [ebp-4h]

  v2 = dt;
  v4 = this->pCmdLedRevs;
  if ( v4 )
  {
    if ( this->maxRpm == 0.0 || this->minRpm == 0.0 )
    {
      v5 = this->car;
      this->maxRpm = (float)v5->physicsState.limiterRPM * 0.94999999;
      this->minRpm = (float)v5->physicsState.limiterRPM * 0.75;
    }
    v6 = this->car;
    if ( this->lastGear != v6->physicsState.gear )
    {
      this->MessageTime = 0.0;
      this->lastGear = v6->physicsState.gear;
      this->showGearTime = 0.000099999997;
    }
    v7 = this->MessageTime;
    if ( v7 > 0.0 )
    {
      v8 = v7 + dt;
      v9 = v8 <= this->MESSAGE_MAX_TIME;
      this->MessageTime = v8;
      if ( !v9 )
        this->MessageTime = 0.0;
    }
    if ( v6->physicsState.engineRPM > (float)v6->physicsState.limiterRPM )
      this->MessageTime = 0.000099999997;
    v4->RimToBaseRevLedsMirrorEnable(v4, 0);
    if ( this->MessageTime <= 0.0 )
    {
      v13 = this->pCmdLedRevs;
      this->blinkingOn = 0;
      this->blinkingTime = 0.0;
      v14 = v13->GetItemCount(v13);
      v15 = 0;
      v16 = v14;
      v17 = (float)(this->maxRpm - this->minRpm) / (float)(v14 - 1);
      for ( i = v17; v15 <= v14; --v16 )
      {
        v25 = this->pCmdLedRevs;
        v18 = v25->__vftable;
        if ( this->car->physicsState.engineRPM < (float)((float)((float)v15 * v17) + (float)(this->minRpm + 10.0)) )
          v18->ItemSetOff(v25, v16);
        else
          v18->ItemSetOn(v25, v16);
        v17 = i;
        ++v15;
      }
    }
    else
    {
      v10 = this->blinkingTime + dt;
      v9 = v10 <= this->BLINK_MAX_TIME;
      this->blinkingTime = v10;
      if ( !v9 )
      {
        v11 = !this->blinkingOn;
        this->blinkingTime = 0.0;
        this->blinkingOn = v11;
      }
      v27 = this->pCmdLedRevs;
      v12 = v27->__vftable;
      if ( this->blinkingOn )
        v12->ItemSetOn(v27, -1);
      else
        v12->ItemSetOff(v27, -1);
    }
    this->pCmdLedRevs->SubmitToDevice(this->pCmdLedRevs);
    this->pCmdLedRevs->RimToBaseRevLedsMirrorEnable(this->pCmdLedRevs, 1);
    v2 = dt;
  }
  v19 = this->pCmdSevenSegmentLedDisplay;
  if ( v19 )
  {
    v20 = this->lastGear;
    if ( this->MessageTime > 0.0 )
    {
      v19->DigitSetOn(v19, 0, 1, 0, 0, 1, 1, 1, 0, 0);
      if ( !this->blinkingOn )
      {
        v28 = 0;
        v26 = 0;
LABEL_45:
        this->pCmdSevenSegmentLedDisplay->DigitSetOn(this->pCmdSevenSegmentLedDisplay, 1, 0, 0, 0, 0, v26, 0, v28, 0);
LABEL_46:
        this->pCmdSevenSegmentLedDisplay->DigitSetOn(this->pCmdSevenSegmentLedDisplay, 2, 1, 1, 1, 1, 0, 0, 0, 0);
        this->pCmdSevenSegmentLedDisplay->SubmitToDevice(this->pCmdSevenSegmentLedDisplay);
        return;
      }
      if ( this->showNextGear )
      {
        v21 = this->lastGear;
        if ( v21 <= this->car->physicsInfo.maxGear )
          v20 = v21 + 1;
      }
      v22 = v20;
      if ( v20 )
        goto LABEL_31;
LABEL_44:
      v28 = 1;
      v26 = 1;
      goto LABEL_45;
    }
    if ( this->showGearTime > this->GEAR_MAX_TIME )
      this->showGearTime = 0.0;
    v23 = this->car;
    if ( (float)(v23->physicsState.speed.value * 3.5999999) < 5.0 || this->showGearTime > 0.0 )
    {
      this->showGearTime = this->showGearTime + v2;
      v19->DigitSetOn(v19, 0, 1, 0, 0, 1, 1, 1, 0, 0);
      v22 = v20;
      if ( v20 )
      {
LABEL_31:
        if ( v22 == 1 )
          this->pCmdSevenSegmentLedDisplay->DigitSetOn(this->pCmdSevenSegmentLedDisplay, 1, 0, 0, 1, 0, 1, 0, 1, 0);
        else
          this->pCmdSevenSegmentLedDisplay->DigitSetOn(this->pCmdSevenSegmentLedDisplay, 1, v20 - 1, 0);
        goto LABEL_46;
      }
      goto LABEL_44;
    }
    v24 = v23->physicsState.speed.value;
    if ( Speed::useMPH )
      v19->SetNumber(v19, (int)(float)(v24 * 2.2369363));
    else
      v19->SetNumber(v19, (int)(float)(v24 * 3.5999999));
    this->pCmdSevenSegmentLedDisplay->SubmitToDevice(this->pCmdSevenSegmentLedDisplay);
  }
}
bool FanatecUpdater::IsConnected(FanatecUpdater *this)
{
  return this->bIsConnected;
}
