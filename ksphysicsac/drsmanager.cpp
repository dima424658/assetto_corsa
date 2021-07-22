#include "drsmanager.h
void DRSManager::DRSManager(DRSManager *this, PhysicsEngine *engine)
{
  Track *v3; // ecx
  std::wstring *v4; // eax
  int i; // esi
  std::wstring *v6; // eax
  DRSZone z; // [esp+10h] [ebp-DCh] BYREF
  DRSManager *v8; // [esp+1Ch] [ebp-D0h]
  std::wstring key; // [esp+20h] [ebp-CCh] BYREF
  std::wstring section; // [esp+38h] [ebp-B4h] BYREF
  std::wstring v11; // [esp+50h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+68h] [ebp-84h] BYREF
  std::wstring filename; // [esp+80h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+98h] [ebp-54h] BYREF
  int v15; // [esp+E8h] [ebp-4h]

  v8 = this;
  this->detections._Myfirst = 0;
  this->detections._Mylast = 0;
  this->detections._Myend = 0;
  this->engine = engine;
  v15 = 0;
  this->zones._Myfirst = 0;
  this->zones._Mylast = 0;
  this->zones._Myend = 0;
  v3 = engine->track;
  LOBYTE(v15) = 1;
  v4 = Track::getDataFolder(v3, &result);
  LOBYTE(v15) = 2;
  std::operator+<wchar_t>(&filename, v4, L"/data/drs_zones.ini");
  LOBYTE(v15) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&ini, &filename);
  LOBYTE(v15) = 5;
  if ( ini.ready )
  {
    for ( i = 0; ; ++i )
    {
      v6 = std::to_wstring(&v11, i);
      LOBYTE(v15) = 6;
      std::operator+<wchar_t>(&section, L"ZONE_", v6);
      LOBYTE(v15) = 8;
      if ( v11._Myres >= 8 )
        operator delete(v11._Bx._Ptr);
      v11._Myres = 7;
      v11._Bx._Buf[0] = 0;
      v11._Mysize = 0;
      if ( !INIReader::hasSection(&ini, &section) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"DETECTION", 9u);
      LOBYTE(v15) = 9;
      z.detection = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v15) = 8;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"START", 5u);
      LOBYTE(v15) = 10;
      z.start = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v15) = 8;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"END", 3u);
      LOBYTE(v15) = 11;
      z.end = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v15) = 8;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::vector<DRSZone>::push_back((std::vector<vec3f> *)&this->zones, (const vec3f *)&z);
      LOBYTE(v15) = 5;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  LOBYTE(v15) = 4;
  INIReader::~INIReader(&ini);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void DRSManager::~DRSManager(DRSManager *this)
{
  if ( this->zones._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->zones);
    operator delete(this->zones._Myfirst);
    this->zones._Myfirst = 0;
    this->zones._Mylast = 0;
    this->zones._Myend = 0;
  }
  if ( this->detections._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)this);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::LightGroup>>>(
      this->detections._Myfirst,
      this->detections._Mylast);
    operator delete(this->detections._Myfirst);
    this->detections._Myfirst = 0;
    this->detections._Mylast = 0;
    this->detections._Myend = 0;
  }
}
char DRSManager::isDRSAvailable(DRSManager *this, const Car *car)
{
  DRSZone *v2; // eax
  DRSZone *v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  bool v8; // cf

  v2 = this->zones._Myfirst;
  if ( v2 == this->zones._Mylast )
    return 1;
  v4 = this->zones._Mylast;
  if ( v2 != v4 )
  {
    while ( 1 )
    {
      v5 = v2->end;
      v6 = v2->start;
      v7 = car->splineLocatorData.npos;
      if ( v5 <= v6 )
        break;
      if ( v7 >= v6 )
      {
        v8 = v5 < v7;
        goto LABEL_10;
      }
LABEL_11:
      if ( ++v2 == v4 )
        return 0;
    }
    if ( v7 >= 0.5 )
      v8 = v7 < v6;
    else
      v8 = v5 < v7;
LABEL_10:
    if ( !v8 )
      return 1;
    goto LABEL_11;
  }
  return 0;
}
void DRSManager::setZones(DRSManager *this, std::vector<DRSZone> *zv)
{
  std::vector<DRSZone>::operator=(&this->zones, zv);
}
char DRSManager::wasRaceSwitchedOn(DRSManager *this, const Car *car)
{
  DRSDetection *v2; // esi
  unsigned int v3; // edx
  int v4; // edx
  DRSDetectionStatus *v5; // eax
  DRSDetectionStatus *v6; // ecx

  v2 = this->detections._Myfirst;
  v3 = car->physicsGUID;
  if ( v3 >= this->detections._Mylast - this->detections._Myfirst )
    return 0;
  v4 = v3;
  v5 = v2[v4].statuses._Myfirst;
  v6 = v2[v4].statuses._Mylast;
  if ( v5 == v6 )
    return 0;
  while ( !v5->hasBeenSwitchedOnThisStep )
  {
    if ( ++v5 == v6 )
      return 0;
  }
  return 1;
}
