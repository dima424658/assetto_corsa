#include "track.h
std::wstring *Track::getDataFolder(Track *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->dataFolder, 0, 0xFFFFFFFF);
  return result;
}
void Track::Track(Track *this, PhysicsEngine *pe, const std::wstring *iname, const std::wstring *config)
{
  const std::wstring *v5; // ebx
  std::wstring *v6; // edi
  bool v7; // cf
  const std::wstring *v8; // eax
  std::wstring *v9; // ebx
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // ebx
  Track *v13; // ecx
  AISplineRecorder *v14; // ecx
  DRSManager *v15; // eax
  DRSManager *v16; // eax
  DRSManager *v17; // edi
  std::wstring *v18; // [esp-4h] [ebp-78h]
  std::wstring result; // [esp+1Ch] [ebp-58h] BYREF
  std::wstring v20; // [esp+34h] [ebp-40h] BYREF
  std::wstring v21; // [esp+4Ch] [ebp-28h] BYREF
  int v22; // [esp+70h] [ebp-4h]

  v5 = iname;
  this->__vftable = (Track_vtbl *)&Track::`vftable';
  this->ksPhysics = pe;
  v22 = 0;
  this->surfaces._Myfirst = 0;
  this->surfaces._Mylast = 0;
  this->surfaces._Myend = 0;
  this->timeLines._Myfirst = 0;
  this->timeLines._Mylast = 0;
  this->timeLines._Myend = 0;
  mat44f::mat44f(&this->worldMatrix);
  this->aiSplineRecorder._Myptr = 0;
  this->drsMamanger._Myptr = 0;
  this->startingBounds._Myfirst = 0;
  this->startingBounds._Mylast = 0;
  this->startingBounds._Myend = 0;
  *(_WORD *)&this->dynamicTrack.isExternal = 0;
  this->dynamicTrack.sessionStartGrip = 1.0;
  this->dynamicTrack.baseGrip = 1.0;
  this->dynamicTrack.randomGrip = 0.0099999998;
  this->dynamicTrack.gripPerLap = 0.1;
  this->dynamicTrack.sessionTransfer = 0.0;
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  std::wstring::assign(&this->name, iname, 0, 0xFFFFFFFF);
  this->config._Myres = 7;
  LOBYTE(v22) = 6;
  this->config._Mysize = 0;
  this->config._Bx._Buf[0] = 0;
  std::wstring::assign(&this->config, config, 0, 0xFFFFFFFF);
  v6 = &this->dataFolder;
  this->dataFolder._Myres = 7;
  this->dataFolder._Mysize = 0;
  this->dataFolder._Bx._Buf[0] = 0;
  this->dynamicGripLevel = 1.0;
  this->sectorsNormalizedPositions._Myfirst = 0;
  this->sectorsNormalizedPositions._Mylast = 0;
  this->sectorsNormalizedPositions._Myend = 0;
  v7 = config->_Myres < 8;
  LOBYTE(v22) = 9;
  if ( v7 )
    v8 = config;
  else
    v8 = (const std::wstring *)config->_Bx._Ptr;
  if ( iname->_Myres >= 8 )
    v5 = (const std::wstring *)iname->_Bx._Ptr;
  _printf("Creating physics track: %S [%S]\n", v5->_Bx._Buf, v8->_Bx._Buf);
  v18 = &this->name;
  if ( config->_Mysize )
  {
    v10 = std::operator+<wchar_t>(&v21, L"content/tracks/", v18);
    LOBYTE(v22) = 10;
    v11 = std::operator+<wchar_t>(&result, v10, L"/");
    LOBYTE(v22) = 11;
    v12 = std::operator+<wchar_t>(&v20, v11, config);
    if ( v6 != v12 )
    {
      if ( this->dataFolder._Myres >= 8 )
        operator delete(v6->_Bx._Ptr);
      this->dataFolder._Myres = 7;
      this->dataFolder._Mysize = 0;
      v6->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->dataFolder, v12);
    }
    if ( v20._Myres >= 8 )
      operator delete(v20._Bx._Ptr);
    v20._Myres = 7;
    v20._Mysize = 0;
    v20._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v22) = 9;
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
  }
  else
  {
    v9 = std::operator+<wchar_t>(&result, L"content/tracks/", v18);
    if ( v6 != v9 )
    {
      if ( this->dataFolder._Myres >= 8 )
        operator delete(v6->_Bx._Ptr);
      this->dataFolder._Myres = 7;
      this->dataFolder._Mysize = 0;
      v6->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->dataFolder, v9);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v13 = this->ksPhysics->track;
  if ( v13 )
    ((void (*)(Track *, int))v13->~IRayTrackCollisionProvider)(v13, 1);
  v14 = this->aiSplineRecorder._Myptr;
  this->aiSplineRecorder._Myptr = 0;
  if ( v14 )
    ((void (*)(AISplineRecorder *, int))v14->~AISplineRecorder)(v14, 1);
  this->ksPhysics->track = this;
  mat44f::loadIdentity(&this->worldMatrix);
  this->isOpen = 0;
  Track::initDynamicTrack(this);
  v15 = (DRSManager *)operator new(28);
  LOBYTE(v22) = 12;
  if ( v15 )
    DRSManager::DRSManager(v15, this->ksPhysics);
  else
    v16 = 0;
  v17 = this->drsMamanger._Myptr;
  LOBYTE(v22) = 9;
  this->drsMamanger._Myptr = v16;
  if ( v17 )
  {
    DRSManager::~DRSManager(v17);
    operator delete(v17);
  }
}
void Track::~Track(Track *this)
{
  AISplineRecorder *v2; // ecx
  ICollisionObject **v3; // esi
  int v4; // ebx
  unsigned int v5; // ebp
  std::vector<float> *v6; // esi
  DRSManager *v7; // esi
  AISplineRecorder *v8; // ecx
  TimeLine *v9; // ebp
  TimeLine *i; // esi

  this->__vftable = (Track_vtbl *)&Track::`vftable';
  v2 = this->aiSplineRecorder._Myptr;
  this->aiSplineRecorder._Myptr = 0;
  if ( v2 )
    ((void (*)(AISplineRecorder *, int))v2->~AISplineRecorder)(v2, 1);
  v3 = this->surfaces._Myfirst;
  v4 = 0;
  v5 = (unsigned int)((char *)this->surfaces._Mylast - (char *)v3 + 3) >> 2;
  if ( v3 > this->surfaces._Mylast )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      (*v3)->release(*v3);
      ++v4;
      ++v3;
    }
    while ( v4 != v5 );
  }
  v6 = &this->sectorsNormalizedPositions;
  if ( this->sectorsNormalizedPositions._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->sectorsNormalizedPositions);
    operator delete(v6->_Myfirst);
    v6->_Myfirst = 0;
    this->sectorsNormalizedPositions._Mylast = 0;
    this->sectorsNormalizedPositions._Myend = 0;
  }
  if ( this->dataFolder._Myres >= 8 )
    operator delete(this->dataFolder._Bx._Ptr);
  this->dataFolder._Myres = 7;
  this->dataFolder._Mysize = 0;
  this->dataFolder._Bx._Buf[0] = 0;
  if ( this->config._Myres >= 8 )
    operator delete(this->config._Bx._Ptr);
  this->config._Myres = 7;
  this->config._Mysize = 0;
  this->config._Bx._Buf[0] = 0;
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  if ( this->startingBounds._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->startingBounds);
    operator delete(this->startingBounds._Myfirst);
    this->startingBounds._Myfirst = 0;
    this->startingBounds._Mylast = 0;
    this->startingBounds._Myend = 0;
  }
  v7 = this->drsMamanger._Myptr;
  if ( v7 )
  {
    DRSManager::~DRSManager(v7);
    operator delete(v7);
  }
  v8 = this->aiSplineRecorder._Myptr;
  if ( v8 )
    ((void (*)(AISplineRecorder *, int))v8->~AISplineRecorder)(v8, 1);
  if ( this->timeLines._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->timeLines);
    v9 = this->timeLines._Mylast;
    for ( i = this->timeLines._Myfirst; i != v9; ++i )
      ((void (*)(TimeLine *, _DWORD))i->~TimeLine)(i, 0);
    operator delete(this->timeLines._Myfirst);
    this->timeLines._Myfirst = 0;
    this->timeLines._Mylast = 0;
    this->timeLines._Myend = 0;
  }
  if ( this->surfaces._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->surfaces);
    operator delete(this->surfaces._Myfirst);
    this->surfaces._Myfirst = 0;
    this->surfaces._Mylast = 0;
    this->surfaces._Myend = 0;
  }
  this->__vftable = (Track_vtbl *)&IRayTrackCollisionProvider::`vftable';
}
Track *Track::`scalar deleting destructor'(Track *this, unsigned int a2)
{
  Track::~Track(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
unsigned int Track::addSurface(Track *this, const std::wstring *iname, float *vertices, int numVertices, unsigned __int16 *indices, int indexCount, const SurfaceDef *surfaceDef, unsigned int sector_id)
{
  IPhysicsCore *v9; // eax
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edx

  v9 = PhysicsEngine::getCore(this->ksPhysics);
  v10 = (unsigned int)v9->createCollisionMesh(
                        v9,
                        vertices,
                        numVertices,
                        indices,
                        indexCount,
                        &this->worldMatrix,
                        0,
                        surfaceDef->collisionCategory,
                        20u,
                        sector_id);
  sector_id = v10;
  v11 = (_DWORD *)operator new(188);
  v12 = v11;
  if ( v11 )
  {
    v11[37] = 0;
    v11[43] = 0;
    v11[44] = 0;
    v11[45] = 0;
    v11[46] = 1069547520;
    qmemcpy(v11, surfaceDef, 0xBCu);
  }
  else
  {
    v12 = 0;
  }
  (*(void (**)(unsigned int, _DWORD *))(*(_DWORD *)v10 + 4))(v10, v12);
  std::vector<SpinnerData *>::push_back(&this->surfaces, (ICollisionObject *const *)&sector_id);
  return sector_id;
}
void Track::addTimeLine(Track *this, const vec3f *p1, const vec3f *p2, TimeLineType type)
{
  unsigned int v5; // edx
  TimeLine *v6; // eax
  AISplineRecorder *v7; // ecx
  float v8; // xmm2_4
  float v9; // xmm3_4
  AISpline *v10; // eax
  float normPos; // [esp+14h] [ebp-54h] BYREF
  vec3f sectorAVGPos; // [esp+18h] [ebp-50h] BYREF
  TimeLine v13; // [esp+24h] [ebp-44h] BYREF
  int v14; // [esp+64h] [ebp-4h]

  v5 = (int)((unsigned __int64)(1321528399i64 * ((char *)this->timeLines._Mylast - (char *)this->timeLines._Myfirst)) >> 32) >> 4;
  normPos = *(float *)&p2;
  TimeLine::TimeLine(&v13, p1, p2, v5 + (v5 >> 31), type);
  v14 = 0;
  std::vector<TimeLine>::push_back(&this->timeLines, v6);
  v14 = -1;
  TimeLine::~TimeLine(&v13);
  if ( type == Particle || type == Skinned )
  {
    this->isOpen = 1;
  }
  else
  {
    v7 = this->aiSplineRecorder._Myptr;
    v8 = (float)(*(float *)(LODWORD(normPos) + 4) + p1->y) * 0.5;
    v9 = (float)(*(float *)(LODWORD(normPos) + 8) + p1->z) * 0.5;
    sectorAVGPos.x = (float)(p1->x + *(float *)LODWORD(normPos)) * 0.5;
    sectorAVGPos.y = v8;
    sectorAVGPos.z = v9;
    v10 = AISplineRecorder::getBestLapSpline(v7);
    normPos = InterpolatingSpline::worldToSpline(&v10->spline, &sectorAVGPos, -1);
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->sectorsNormalizedPositions, (int *)&normPos);
  }
}
IRayCaster *Track::createRayCaster(Track *this, float length)
{
  IPhysicsCore *v2; // eax

  v2 = PhysicsEngine::getCore(this->ksPhysics);
  return (IRayCaster *)((int (*)(IPhysicsCore *, _DWORD))v2->createRayCaster)(v2, LODWORD(length));
}
int Track::getSector(Track *this, float normalizedPosition)
{
  int v2; // edx
  float *v3; // esi

  v2 = 1;
  if ( (unsigned int)(this->sectorsNormalizedPositions._Mylast - this->sectorsNormalizedPositions._Myfirst) <= 1 )
    return this->sectorsNormalizedPositions._Mylast - this->sectorsNormalizedPositions._Myfirst - 1;
  v3 = this->sectorsNormalizedPositions._Myfirst;
  while ( normalizedPosition <= v3[v2 - 1] || v3[v2] <= normalizedPosition )
  {
    if ( ++v2 >= (unsigned int)(this->sectorsNormalizedPositions._Mylast - v3) )
      return this->sectorsNormalizedPositions._Mylast - this->sectorsNormalizedPositions._Myfirst - 1;
  }
  return v2 - 1;
}
void __usercall Track::initAISpline(Track *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>)
{
  AISplineRecorder *v5; // eax
  AISplineRecorder *v6; // eax
  AISplineRecorder *v7; // ecx

  v5 = (AISplineRecorder *)operator new(620);
  if ( v5 )
    AISplineRecorder::AISplineRecorder(v5, a2, a3, a4, this->ksPhysics, this);
  else
    v6 = 0;
  v7 = this->aiSplineRecorder._Myptr;
  this->aiSplineRecorder._Myptr = v6;
  if ( v7 )
    ((void (*)(AISplineRecorder *, int))v7->~AISplineRecorder)(v7, 1);
  Track::initStartingBounds(this);
}
void Track::initDynamicTrack(Track *this)
{
  char v2; // bl
  bool v3; // al
  double v4; // st7
  bool v5; // cf
  double v6; // st7
  double v7; // st7
  int v8; // eax
  Event<SessionInfo> *v9; // ecx
  std::wstring v10; // [esp-1Ch] [ebp-B8h] BYREF
  unsigned int v11; // [esp-4h] [ebp-A0h]
  char v12; // [esp+13h] [ebp-89h]
  float lapGain; // [esp+14h] [ebp-88h]
  std::wstring section; // [esp+18h] [ebp-84h] BYREF
  std::wstring key; // [esp+30h] [ebp-6Ch] BYREF
  INIReaderDocuments ini; // [esp+48h] [ebp-54h] BYREF
  int v17; // [esp+98h] [ebp-4h]

  v2 = 0;
  v11 = 0;
  lapGain = 0.0;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&ini, 0, v10, v11);
  v17 = 0;
  if ( !ini.ready )
    goto LABEL_3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DYNAMIC_TRACK", 0xDu);
  LOBYTE(v17) = 1;
  v2 = 1;
  LODWORD(lapGain) = 1;
  v3 = INIReader::hasSection(&ini, &section);
  v12 = 1;
  if ( !v3 )
LABEL_3:
    v12 = 0;
  v17 = 0;
  if ( (v2 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v12 )
  {
    v11 = 8;
    this->dynamicTrack.enabled = 1;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LAP_GAIN", v11);
    LOBYTE(v17) = 2;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DYNAMIC_TRACK", 0xDu);
    LOBYTE(v17) = 3;
    lapGain = INIReader::getFloat(&ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( lapGain > 0.0 )
      this->dynamicTrack.gripPerLap = 0.0099999998 / lapGain;
    else
      this->dynamicTrack.gripPerLap = 0.0;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SESSION_START", 0xDu);
    LOBYTE(v17) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DYNAMIC_TRACK", 0xDu);
    LOBYTE(v17) = 5;
    v4 = INIReader::getFloat(&ini, &section, &key);
    v5 = section._Myres < 8;
    this->dynamicTrack.sessionStartGrip = v4 * 0.0099999998;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( this->dynamicTrack.sessionStartGrip < 0.85000002 )
      this->dynamicTrack.sessionStartGrip = 0.85000002;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"RANDOMNESS", 0xAu);
    LOBYTE(v17) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DYNAMIC_TRACK", 0xDu);
    LOBYTE(v17) = 7;
    v6 = INIReader::getFloat(&ini, &section, &key);
    v5 = section._Myres < 8;
    this->dynamicTrack.randomGrip = v6 * 0.0099999998;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SESSION_TRANSFER", 0x10u);
    LOBYTE(v17) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DYNAMIC_TRACK", 0xDu);
    LOBYTE(v17) = 9;
    v7 = INIReader::getFloat(&ini, &section, &key);
    v5 = section._Myres < 8;
    this->dynamicTrack.sessionTransfer = v7 * 0.0099999998;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v8 = _rand();
    v11 = (unsigned int)this;
    this->dynamicTrack.baseGrip = (float)((float)((float)((float)((float)v8 * 0.000030518509) * 2.0) - 1.0)
                                        * this->dynamicTrack.randomGrip)
                                + this->dynamicTrack.sessionStartGrip;
    v10._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_77ca9348bb85863f3ac03214213671f3_,0>,std::allocator<std::_Func_class<void,SessionInfo const &>>,void,SessionInfo const &>::`vftable';
    *(_DWORD *)&v10._Bx._Alias[4] = this;
    v10._Mysize = (unsigned int)&v10;
    v9 = &this->ksPhysics->evOnNewSessionPhysics;
    LOBYTE(v17) = 0;
    Event<float>::addHandler(v9, (std::function<void __cdecl(SessionInfo const &)>)v10, (void *)v11);
  }
  v17 = -1;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
void Track::initStartingBounds(Track *this)
{
  std::vector<SplineIndexBound> *v2; // esi
  const std::wstring *v3; // eax
  int v4; // ebx
  AISpline *v5; // eax
  int v6; // edi
  std::wstring *v7; // eax
  double v8; // st7
  double v9; // st7
  unsigned int v10; // edi
  SplineIndexBound *v11; // ecx
  int v12; // edi
  SplineIndexBound *v13; // ecx
  SplineIndexBound *v14; // edx
  SplineIndexBound *v15; // eax
  unsigned int v16; // ecx
  float maxi; // [esp+10h] [ebp-D4h]
  int v18; // [esp+14h] [ebp-D0h]
  unsigned int v19; // [esp+18h] [ebp-CCh] BYREF
  unsigned int v20; // [esp+1Ch] [ebp-C8h]
  float mini; // [esp+20h] [ebp-C4h]
  std::wstring key; // [esp+24h] [ebp-C0h] BYREF
  std::wstring section; // [esp+3Ch] [ebp-A8h] BYREF
  std::wstring v24; // [esp+54h] [ebp-90h] BYREF
  std::wstring result; // [esp+6Ch] [ebp-78h] BYREF
  INIReader ini; // [esp+84h] [ebp-60h] BYREF
  int v27; // [esp+E0h] [ebp-4h]

  v2 = &this->startingBounds;
  std::_Container_base0::_Orphan_all(&this->startingBounds);
  v2->_Mylast = v2->_Myfirst;
  v3 = std::operator+<wchar_t>(&result, &this->dataFolder, L"/data/starting_bounds.ini");
  v27 = 0;
  INIReader::INIReader(&ini, v3);
  LOBYTE(v27) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    v4 = 0;
    v5 = AISplineRecorder::getBestLapSpline(this->aiSplineRecorder._Myptr);
    v6 = Spline::pointsCount(&v5->spline);
    v18 = v6;
    _printf("Loading bounds, pcount: %d\n", v6);
    while ( 1 )
    {
      v7 = std::to_wstring(&v24, v4);
      LOBYTE(v27) = 3;
      std::operator+<wchar_t>(&section, L"BOUND_", v7);
      LOBYTE(v27) = 5;
      if ( v24._Myres >= 8 )
        operator delete(v24._Bx._Ptr);
      v24._Myres = 7;
      v24._Bx._Buf[0] = 0;
      v24._Mysize = 0;
      if ( !INIReader::hasSection(&ini, &section) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"MIN", 3u);
      LOBYTE(v27) = 6;
      v8 = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v27) = 5;
      mini = v8 * (float)v6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"MAX", 3u);
      LOBYTE(v27) = 7;
      v9 = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v27) = 5;
      maxi = v9 * (float)v6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v10 = (unsigned int)mini;
      v19 = (unsigned int)mini;
      v11 = v2->_Mylast;
      v20 = (unsigned int)maxi;
      if ( &v19 >= (unsigned int *)v11 || v2->_Myfirst > (SplineIndexBound *)&v19 )
      {
        if ( v11 == v2->_Myend )
          std::vector<DriverNameDisplayer::CarDistandeOrder>::_Reserve(v2, 1u);
        v15 = v2->_Mylast;
        if ( v15 )
        {
          v16 = v20;
          v15->minIndex = v10;
          v15->maxIndex = v16;
        }
      }
      else
      {
        v12 = ((char *)&v19 - (char *)v2->_Myfirst) >> 3;
        if ( v11 == v2->_Myend )
          std::vector<DriverNameDisplayer::CarDistandeOrder>::_Reserve(v2, 1u);
        v13 = v2->_Mylast;
        v14 = v2->_Myfirst;
        if ( v13 )
        {
          v13->minIndex = v14[v12].minIndex;
          v13->maxIndex = v14[v12].maxIndex;
        }
      }
      ++v2->_Mylast;
      ++v4;
      v6 = v18;
      LOBYTE(v27) = 2;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
  }
  v27 = -1;
  INIReader::~INIReader(&ini);
}
bool Track::rayCast(Track *this, const vec3f *org, const vec3f *dir, RayCastResult *result, float length)
{
  IPhysicsCore *v5; // eax
  const __m128i *v6; // eax
  __m128i v7; // xmm1
  __int64 v8; // xmm0_8
  float v9; // eax
  ICollisionObject *v10; // esi
  ICollisionObject *v11; // ecx
  bool v12; // al
  RayCastHit hit; // [esp+10h] [ebp-40h]
  char v14[32]; // [esp+30h] [ebp-20h] BYREF

  v5 = PhysicsEngine::getCore(this->ksPhysics);
  v6 = (const __m128i *)((int (*)(IPhysicsCore *, char *, const vec3f *, const vec3f *, _DWORD))v5->rayCast)(
                          v5,
                          v14,
                          org,
                          dir,
                          LODWORD(length));
  v7 = _mm_loadu_si128(v6);
  *(__m128i *)&hit.normal.y = _mm_loadu_si128(v6 + 1);
  LODWORD(hit.normal.x) = v7.m128i_i32[3];
  if ( (unsigned __int8)_mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)&hit.normal.y, 12)) )
  {
    v8 = *(_QWORD *)&hit.normal.x;
    v9 = hit.normal.z;
    v10 = hit.collisionObject;
    v11 = hit.collisionObject;
    *(_QWORD *)&result->pos.x = v7.m128i_i64[0];
    *(_QWORD *)&result->normal.x = v8;
    LODWORD(result->pos.z) = _mm_cvtsi128_si32(_mm_srli_si128(v7, 8));
    result->normal.z = v9;
    result->surfaceDef = (SurfaceDef *)v11->getUserPointer(v11);
    v12 = 1;
    result->collisionObject = v10;
    result->hasHit = 1;
  }
  else
  {
    result->hasHit = 0;
    v12 = 0;
  }
  return v12;
}
bool Track::rayCastWithRayCaster(Track *this, const vec3f *org, const vec3f *dir, RayCastResult *result, float length, IRayCaster *rayCaster)
{
  float v6; // eax
  ICollisionObject *v7; // ecx
  __int64 v8; // xmm0_8
  float v9; // eax
  bool v10; // al
  RayCastHit hit; // [esp+Ch] [ebp-20h] BYREF

  rayCaster->rayCast(rayCaster, &hit, org, dir);
  if ( hit.hasContact )
  {
    v6 = hit.pos.z;
    v7 = hit.collisionObject;
    *(_QWORD *)&result->pos.x = *(_QWORD *)&hit.pos.x;
    v8 = *(_QWORD *)&hit.normal.x;
    result->pos.z = v6;
    v9 = hit.normal.z;
    *(_QWORD *)&result->normal.x = v8;
    result->normal.z = v9;
    result->surfaceDef = (SurfaceDef *)v7->getUserPointer(v7);
    result->collisionObject = hit.collisionObject;
    v10 = 1;
    result->hasHit = 1;
  }
  else
  {
    result->hasHit = 0;
    v10 = 0;
  }
  return v10;
}
void Track::setGripLevelExternal(Track *this, float grip)
{
  *(_WORD *)&this->dynamicTrack.isExternal = 1;
  this->dynamicGripLevel = grip;
}
void Track::step(Track *this, float dt)
{
  PhysicsEngine *v3; // eax
  int v4; // edx
  Car **v5; // ecx
  Car **v6; // eax
  unsigned int v7; // ebx
  int v8; // edi
  Car *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  AISplineRecorder *v13; // ecx

  if ( (dword_186F17C & 1) == 0 )
  {
    perfCounter_33.name = "Track::step";
    dword_186F17C |= 1u;
    perfCounter_33.group = Physics;
    perfCounter_33.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Track::step" | 0xFF000000;
  }
  if ( this->dynamicTrack.enabled )
  {
    v3 = this->ksPhysics;
    v4 = 0;
    v5 = v3->cars._Myfirst;
    v6 = v3->cars._Mylast;
    v7 = (unsigned int)((char *)v6 - (char *)v5 + 3) >> 2;
    v8 = 0;
    if ( v5 > v6 )
      v7 = 0;
    if ( v7 )
    {
      do
      {
        v9 = *v5;
        ++v4;
        ++v5;
        v8 += v9->transponder.lapCount;
      }
      while ( v4 != v7 );
    }
    v10 = FLOAT_1_0;
    v11 = (float)((float)v8 * this->dynamicTrack.gripPerLap) + this->dynamicTrack.baseGrip;
    if ( v11 <= 1.0 )
    {
      v12 = FLOAT_0_85000002;
      if ( v11 < 0.0 || v11 < 0.85000002 )
        goto LABEL_16;
      if ( v11 <= 1.0 )
      {
        if ( v11 < 0.0 )
        {
          this->dynamicGripLevel = 0.0;
          goto LABEL_19;
        }
        v10 = (float)((float)v8 * this->dynamicTrack.gripPerLap) + this->dynamicTrack.baseGrip;
      }
    }
    v12 = v10;
LABEL_16:
    this->dynamicGripLevel = v12;
    goto LABEL_19;
  }
  if ( !this->dynamicTrack.isExternal )
    this->dynamicGripLevel = 1.0;
LABEL_19:
  GhostCarRecorder::update((TyreTester *)this->drsMamanger._Myptr, dt);
  v13 = this->aiSplineRecorder._Myptr;
  if ( v13 )
    AISplineRecorder::step(v13, dt);
}
std::wstring *Track::getName(Track *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->name, 0, 0xFFFFFFFF);
  return result;
}
