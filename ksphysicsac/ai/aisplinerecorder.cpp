#include "aisplinerecorder.h"
InterpolatingSpline *AISplineRecorder::getLeftSpline(AISplineRecorder *this)
{
  return &this->leftSpline;
}
void __userpurge AISplineRecorder::AISplineRecorder(AISplineRecorder *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, PhysicsEngine *pe, Track *track)
{
  this->__vftable = (AISplineRecorder_vtbl *)&AISplineRecorder::`vftable';
  AISpline::AISpline(&this->splineCurrent);
  AISpline::AISpline(&this->bestLapSpline);
  AISpline::AISpline(&this->pitLaneSpline);
  InterpolatingSpline::InterpolatingSpline(&this->leftSpline);
  InterpolatingSpline::InterpolatingSpline(&this->rightSpline);
  this->track = track;
  InitializeCriticalSection(&this->mutex.criticalSection);
  this->pitLaneSplineAttachPoint = -1.0;
  this->hints._Myfirst = 0;
  this->hints._Mylast = 0;
  this->hints._Myend = 0;
  this->hintsBrake._Myfirst = 0;
  this->hintsBrake._Mylast = 0;
  this->hintsBrake._Myend = 0;
  this->hintsDanger._Myfirst = 0;
  this->hintsDanger._Mylast = 0;
  this->hintsDanger._Myend = 0;
  this->hintsMaxSpeed._Myfirst = 0;
  this->hintsMaxSpeed._Mylast = 0;
  this->hintsMaxSpeed._Myend = 0;
  this->physicsEngine = pe;
  this->recordingStep = 1.5;
  this->isRecordingPitlane = 0;
  this->isActive = 1;
  this->isSaveNeeded = 0;
  this->car = 0;
  AISplineRecorder::load(this, a2, a3, a4);
  AISplineRecorder::loadHints(this);
}
void __usercall AISplineRecorder::~AISplineRecorder(AISplineRecorder *this@<ecx>, __m128 a2@<xmm0>)
{
  bool v3; // zf
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  char v6; // bl
  const std::wstring *v7; // eax
  char v8; // [esp+Fh] [ebp-79h]
  std::wstring result; // [esp+18h] [ebp-70h] BYREF
  std::wstring v10; // [esp+30h] [ebp-58h] BYREF
  std::wstring sideSplinesBasePath; // [esp+48h] [ebp-40h] BYREF
  std::wstring v12; // [esp+60h] [ebp-28h] BYREF
  int v13; // [esp+84h] [ebp-4h]

  this->__vftable = (AISplineRecorder_vtbl *)&AISplineRecorder::`vftable';
  v3 = !this->isSaveNeeded;
  v13 = 9;
  if ( !v3 )
  {
    v4 = Track::getDataFolder(this->track, &result);
    LOBYTE(v13) = 10;
    std::operator+<wchar_t>(&sideSplinesBasePath, v4, L"/data/side_");
    LOBYTE(v13) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    v5 = std::operator+<wchar_t>(&v12, &sideSplinesBasePath, L"l.csv");
    v6 = 1;
    LOBYTE(v13) = 13;
    if ( !Path::fileExists(1u, v5, 0)
      || (v7 = std::operator+<wchar_t>(&v10, &sideSplinesBasePath, L"r.csv"),
          v6 = 3,
          v13 = 14,
          v8 = 1,
          !Path::fileExists(3u, v7, 0)) )
    {
      v8 = 0;
    }
    if ( (v6 & 2) != 0 )
    {
      v6 &= 0xFDu;
      if ( v10._Myres >= 8 )
        operator delete(v10._Bx._Ptr);
      v10._Myres = 7;
      v10._Mysize = 0;
      v10._Bx._Buf[0] = 0;
    }
    v13 = 12;
    if ( (v6 & 1) != 0 && v12._Myres >= 8 )
      operator delete(v12._Bx._Ptr);
    if ( v8 )
      AISplineRecorder::recomputeSidesFromCsv(this);
    AISplineRecorder::save(this, a2, 0);
    if ( sideSplinesBasePath._Myres >= 8 )
      operator delete(sideSplinesBasePath._Bx._Ptr);
  }
  if ( this->hintsMaxSpeed._Myfirst )
  {
    operator delete(this->hintsMaxSpeed._Myfirst);
    this->hintsMaxSpeed._Myfirst = 0;
    this->hintsMaxSpeed._Mylast = 0;
    this->hintsMaxSpeed._Myend = 0;
  }
  if ( this->hintsDanger._Myfirst )
  {
    operator delete(this->hintsDanger._Myfirst);
    this->hintsDanger._Myfirst = 0;
    this->hintsDanger._Mylast = 0;
    this->hintsDanger._Myend = 0;
  }
  if ( this->hintsBrake._Myfirst )
  {
    operator delete(this->hintsBrake._Myfirst);
    this->hintsBrake._Myfirst = 0;
    this->hintsBrake._Mylast = 0;
    this->hintsBrake._Myend = 0;
  }
  if ( this->hints._Myfirst )
  {
    operator delete(this->hints._Myfirst);
    this->hints._Myfirst = 0;
    this->hints._Mylast = 0;
    this->hints._Myend = 0;
  }
  DeleteCriticalSection(&this->mutex.criticalSection);
  LOBYTE(v13) = 3;
  InterpolatingSpline::~InterpolatingSpline(&this->rightSpline);
  LOBYTE(v13) = 2;
  InterpolatingSpline::~InterpolatingSpline(&this->leftSpline);
  LOBYTE(v13) = 1;
  AISpline::~AISpline(&this->pitLaneSpline);
  LOBYTE(v13) = 0;
  AISpline::~AISpline(&this->bestLapSpline);
  v13 = -1;
  AISpline::~AISpline(&this->splineCurrent);
}
AISplineRecorder *__userpurge AISplineRecorder::`scalar deleting destructor'@<eax>(AISplineRecorder *this@<ecx>, __m128 a2@<xmm0>, unsigned int a3)
{
  AISplineRecorder::~AISplineRecorder(this, a2);
  if ( (a3 & 1) != 0 )
    operator delete(this);
  return this;
}
void AISplineRecorder::beginPitLaneSpline(AISplineRecorder *this)
{
  ThreadMutex *v2; // esi

  v2 = &this->mutex;
  if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
    EnterCriticalSection(&v2->criticalSection);
  AISpline::clear(&this->splineCurrent);
  this->isRecordingPitlane = 1;
  this->isSaveNeeded = 1;
  LeaveCriticalSection(&v2->criticalSection);
}
void AISplineRecorder::endPitLaneSpline(AISplineRecorder *this)
{
  ThreadMutex *v2; // esi

  v2 = &this->mutex;
  if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
    EnterCriticalSection(&v2->criticalSection);
  AISpline::operator=(&this->pitLaneSpline, &this->splineCurrent);
  this->pitLaneSpline.lapTime = 0;
  AISpline::clear(&this->splineCurrent);
  this->isRecordingPitlane = 0;
  LeaveCriticalSection(&v2->criticalSection);
}
AISpline *AISplineRecorder::getBestLapSpline(AISplineRecorder *this)
{
  return &this->bestLapSpline;
}
double AISplineRecorder::getBrakeHintAtSplinePos(AISplineRecorder *this, float normalizedPos)
{
  AISplineHint *v2; // eax
  AISplineHint *v3; // ecx

  v2 = this->hintsBrake._Myfirst;
  v3 = this->hintsBrake._Mylast;
  if ( v2 == v3 )
    return 1.0;
  while ( normalizedPos < v2->startPos || v2->endPos < normalizedPos )
  {
    if ( ++v2 == v3 )
      return 1.0;
  }
  return v2->value;
}
bool AISplineRecorder::getDangerAtSplinePos(AISplineRecorder *this, float normalizedPos, float *left, float *right)
{
  AISplineDanger *v4; // eax
  AISplineDanger *v5; // ecx
  bool result; // al

  v4 = this->hintsDanger._Myfirst;
  v5 = this->hintsDanger._Mylast;
  if ( v4 == v5 )
  {
LABEL_5:
    *left = 0.0;
    *right = 0.0;
    result = 0;
  }
  else
  {
    while ( normalizedPos < v4->startPos || v4->endPos < normalizedPos )
    {
      if ( ++v4 == v5 )
        goto LABEL_5;
    }
    *left = v4->left;
    *right = v4->right;
    result = 1;
  }
  return result;
}
double AISplineRecorder::getHintAtSplinePos(AISplineRecorder *this, float normalizedPos)
{
  AISplineHint *v2; // eax
  AISplineHint *v3; // ecx

  v2 = this->hints._Myfirst;
  v3 = this->hints._Mylast;
  if ( v2 == v3 )
    return 1.0;
  while ( normalizedPos < v2->startPos || v2->endPos < normalizedPos )
  {
    if ( ++v2 == v3 )
      return 1.0;
  }
  return v2->value;
}
double AISplineRecorder::getMaxSpeedHintAtSplinePos(AISplineRecorder *this, float normalizedPos)
{
  AISplineHint *v2; // eax
  AISplineHint *v3; // ecx

  v2 = this->hintsMaxSpeed._Myfirst;
  v3 = this->hintsMaxSpeed._Mylast;
  if ( v2 == v3 )
    return -1.0;
  while ( normalizedPos < v2->startPos || v2->endPos < normalizedPos )
  {
    if ( ++v2 == v3 )
      return -1.0;
  }
  return v2->value;
}
AISpline *AISplineRecorder::getPitLaneSpline(AISplineRecorder *this)
{
  return &this->pitLaneSpline;
}
void __usercall AISplineRecorder::load(AISplineRecorder *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>)
{
  Track *v5; // ebx
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  char v11; // bl
  const std::wstring *v12; // eax
  _FILETIME v13; // kr00_8
  const std::wstring *v14; // eax
  _FILETIME v15; // kr08_8
  const std::wstring *v16; // eax
  _FILETIME v17; // rax
  unsigned int v18; // ecx
  unsigned int v19; // eax
  AISpline *v20; // ebx
  int v21; // eax
  std::wstring v22; // [esp-18h] [ebp-C8h] BYREF
  char v23; // [esp+17h] [ebp-99h]
  unsigned int v24; // [esp+18h] [ebp-98h]
  unsigned int v25; // [esp+1Ch] [ebp-94h]
  unsigned int v26; // [esp+20h] [ebp-90h]
  unsigned int v27; // [esp+24h] [ebp-8Ch]
  std::wstring fastlane_name_new; // [esp+28h] [ebp-88h] BYREF
  std::wstring result; // [esp+40h] [ebp-70h] BYREF
  std::wstring sideSplinesBasePath; // [esp+58h] [ebp-58h] BYREF
  std::wstring v31; // [esp+70h] [ebp-40h] BYREF
  std::wstring v32; // [esp+88h] [ebp-28h] BYREF
  int v33; // [esp+ACh] [ebp-4h]

  v24 = 0;
  v5 = this->physicsEngine->track;
  v6 = Track::getDataFolder(v5, &result);
  v33 = 0;
  std::operator+<wchar_t>(&fastlane_name_new, v6, L"/ai/fast_lane.ai");
  LOBYTE(v33) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Bx._Buf[0] = 0;
  v7 = &fastlane_name_new;
  if ( fastlane_name_new._Myres >= 8 )
    v7 = (std::wstring *)fastlane_name_new._Bx._Ptr;
  result._Myres = 7;
  result._Mysize = 0;
  _printf("LOOKING FOR: %S\n", v7->_Bx._Buf);
  if ( Path::fileExists((unsigned int)v5, &fastlane_name_new, 0) )
  {
    v8 = &fastlane_name_new;
    if ( fastlane_name_new._Myres >= 8 )
      v8 = (std::wstring *)fastlane_name_new._Bx._Ptr;
    _printf("LOADING SPLINE: %S\n", v8->_Bx._Buf);
    AISpline::load(&this->bestLapSpline, a3, a4, &fastlane_name_new);
    if ( this->bestLapSpline.version >= 7 )
    {
      _printf("Spline is at last version\n");
    }
    else
    {
      _printf("LOADED OLD SPLINE old Version : %d\n", this->bestLapSpline.version);
      _printf("SAVING AND UPDATING TO 7\n");
      AISplineRecorder::save(this, a2, 1);
    }
  }
  AISpline::calculateNormals(&this->bestLapSpline, a2, this->physicsEngine->track);
  v9 = Track::getDataFolder(v5, &v32);
  LOBYTE(v33) = 3;
  std::operator+<wchar_t>(&sideSplinesBasePath, v9, L"/data/side_");
  LOBYTE(v33) = 5;
  if ( v32._Myres >= 8 )
    operator delete(v32._Bx._Ptr);
  v32._Myres = 7;
  v32._Bx._Buf[0] = 0;
  v32._Mysize = 0;
  v10 = std::operator+<wchar_t>(&v31, &sideSplinesBasePath, L"l.csv");
  v11 = 1;
  LOBYTE(v33) = 6;
  v24 = 1;
  if ( !Path::fileExists(1u, v10, 0)
    || (v12 = std::operator+<wchar_t>(&result, &sideSplinesBasePath, L"r.csv"),
        v11 = 3,
        v33 = 7,
        v24 = 3,
        v23 = 1,
        !Path::fileExists(3u, v12, 0)) )
  {
    v23 = 0;
  }
  if ( (v11 & 2) != 0 )
  {
    v11 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v33 = 5;
  if ( (v11 & 1) != 0 && v31._Myres >= 8 )
    operator delete(v31._Bx._Ptr);
  if ( !v23 )
    goto LABEL_32;
  v13 = Path::getLastModificationTime(&fastlane_name_new);
  v14 = std::operator+<wchar_t>(&v31, &sideSplinesBasePath, L"l.csv");
  LOBYTE(v33) = 8;
  v15 = Path::getLastModificationTime(v14);
  v27 = v15.dwHighDateTime;
  v25 = v15.dwLowDateTime;
  LOBYTE(v33) = 5;
  if ( v31._Myres >= 8 )
    operator delete(v31._Bx._Ptr);
  v16 = std::operator+<wchar_t>(&v31, &sideSplinesBasePath, L"r.csv");
  LOBYTE(v33) = 9;
  v17 = Path::getLastModificationTime(v16);
  v18 = v17.dwLowDateTime;
  LOBYTE(v33) = 5;
  v26 = v17.dwLowDateTime;
  v19 = v17.dwHighDateTime;
  v24 = v17.dwHighDateTime;
  if ( v31._Myres >= 8 )
  {
    operator delete(v31._Bx._Ptr);
    v19 = v24;
    v18 = v26;
  }
  if ( __PAIR64__(v19, v18) > *(_QWORD *)&v13 || __PAIR64__(v27, v25) > *(_QWORD *)&v13 || GetAsyncKeyState(16) )
  {
    _printf("AISplineRecorder :: recomputing track boundaries from side splines\n");
    AISplineRecorder::recomputeSidesFromCsv(this);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, &fastlane_name_new, 0, 0xFFFFFFFF);
    v20 = &this->bestLapSpline;
    AISpline::save(&this->bestLapSpline, v22);
  }
  else
  {
LABEL_32:
    v20 = &this->bestLapSpline;
  }
  AISplineRecorder::loadPitLaneSpline(this, (unsigned int)v20, a3, a4);
  v22._Myres = this->bestLapSpline.payloads._Mylast - this->bestLapSpline.payloads._Myfirst;
  v21 = AISpline::pointsCount(v20);
  _printf("SPLINE POINTS COUNT : %u  | PAYLOADS COUNT : %u\n", v21, v22._Myres);
  if ( sideSplinesBasePath._Myres >= 8 )
    operator delete(sideSplinesBasePath._Bx._Ptr);
  sideSplinesBasePath._Myres = 7;
  sideSplinesBasePath._Mysize = 0;
  sideSplinesBasePath._Bx._Buf[0] = 0;
  if ( fastlane_name_new._Myres >= 8 )
    operator delete(fastlane_name_new._Bx._Ptr);
}
void AISplineRecorder::loadHints(AISplineRecorder *this)
{
  AISplineRecorder *v1; // edi
  std::wstring *v2; // eax
  std::wstring *v3; // eax
  int i; // esi
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  int j; // esi
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  int k; // esi
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  int l; // ebx
  std::wstring *v14; // eax
  float v15; // eax
  AISplineDanger *v16; // ecx
  std::vector<AISplineDanger> *v17; // esi
  int v18; // edi
  __m128i *v19; // eax
  const __m128i *v20; // edi
  __m128i *v21; // eax
  __m128i v22; // [esp+34h] [ebp-F8h] BYREF
  AISplineRecorder *v23; // [esp+44h] [ebp-E8h]
  std::wstring key; // [esp+48h] [ebp-E4h] BYREF
  std::wstring section; // [esp+60h] [ebp-CCh] BYREF
  AISplineHint hint; // [esp+78h] [ebp-B4h] BYREF
  unsigned int v27; // [esp+8Ch] [ebp-A0h]
  std::wstring v28; // [esp+90h] [ebp-9Ch] BYREF
  std::wstring filename; // [esp+A8h] [ebp-84h] BYREF
  INIReader ini; // [esp+C0h] [ebp-6Ch] BYREF
  std::wstring result; // [esp+104h] [ebp-28h] BYREF
  int v32; // [esp+128h] [ebp-4h]

  v1 = this;
  v23 = this;
  v2 = Track::getDataFolder(this->track, &result);
  v32 = 0;
  std::operator+<wchar_t>(&filename, v2, L"/data/ai_hints.ini");
  LOBYTE(v32) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&ini, &filename);
  v3 = &filename;
  LOBYTE(v32) = 3;
  if ( ini.ready )
  {
    if ( filename._Myres >= 8 )
      v3 = (std::wstring *)filename._Bx._Ptr;
    _printf("Loading AI Hints from: %S\n", v3->_Bx._Buf);
    for ( i = 0; ; ++i )
    {
      v5 = std::to_wstring(&v28, i);
      LOBYTE(v32) = 4;
      std::operator+<wchar_t>(&section, L"HINT_", v5);
      LOBYTE(v32) = 6;
      if ( v28._Myres >= 8 )
        operator delete(v28._Bx._Ptr);
      v28._Myres = 7;
      v28._Bx._Buf[0] = 0;
      v28._Mysize = 0;
      if ( !INIReader::hasSection(&ini, &section) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"START", 5u);
      LOBYTE(v32) = 7;
      hint.startPos = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"END", 3u);
      LOBYTE(v32) = 8;
      hint.endPos = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"VALUE", 5u);
      LOBYTE(v32) = 9;
      hint.value = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v6 = &section;
      if ( section._Myres >= 8 )
        v6 = (std::wstring *)section._Bx._Ptr;
      _printf("%S START:%f END:%f VALUE:%f\n", v6->_Bx._Buf, hint.startPos, hint.endPos, hint.value);
      std::vector<AISplineHint>::push_back(&v1->hints, &hint);
      LOBYTE(v32) = 3;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    LOBYTE(v32) = 3;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    for ( j = 0; ; ++j )
    {
      v8 = std::to_wstring(&v28, j);
      LOBYTE(v32) = 10;
      std::operator+<wchar_t>(&section, L"BRAKEHINT_", v8);
      LOBYTE(v32) = 12;
      if ( v28._Myres >= 8 )
        operator delete(v28._Bx._Ptr);
      v28._Myres = 7;
      v28._Bx._Buf[0] = 0;
      v28._Mysize = 0;
      if ( !INIReader::hasSection(&ini, &section) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"START", 5u);
      LOBYTE(v32) = 13;
      hint.startPos = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"END", 3u);
      LOBYTE(v32) = 14;
      hint.endPos = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"VALUE", 5u);
      LOBYTE(v32) = 15;
      hint.value = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v9 = &section;
      if ( section._Myres >= 8 )
        v9 = (std::wstring *)section._Bx._Ptr;
      _printf("%S START:%f END:%f VALUE:%f\n", v9->_Bx._Buf, hint.startPos, hint.endPos, hint.value);
      std::vector<AISplineHint>::push_back(&v1->hintsBrake, &hint);
      LOBYTE(v32) = 3;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    LOBYTE(v32) = 3;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    for ( k = 0; ; ++k )
    {
      v11 = std::to_wstring(&v28, k);
      LOBYTE(v32) = 16;
      std::operator+<wchar_t>(&section, L"MAXSPEED_", v11);
      LOBYTE(v32) = 18;
      if ( v28._Myres >= 8 )
        operator delete(v28._Bx._Ptr);
      v28._Myres = 7;
      v28._Bx._Buf[0] = 0;
      v28._Mysize = 0;
      if ( !INIReader::hasSection(&ini, &section) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"START", 5u);
      LOBYTE(v32) = 19;
      hint.startPos = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 18;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"END", 3u);
      LOBYTE(v32) = 20;
      hint.endPos = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 18;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"VALUE", 5u);
      LOBYTE(v32) = 21;
      hint.value = INIReader::getFloat(&ini, &section, &key);
      LOBYTE(v32) = 18;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v12 = &section;
      if ( section._Myres >= 8 )
        v12 = (std::wstring *)section._Bx._Ptr;
      _printf("%S START:%f END:%f VALUE:%f\n", v12->_Bx._Buf, hint.startPos, hint.endPos, hint.value);
      std::vector<AISplineHint>::push_back(&v1->hintsMaxSpeed, &hint);
      LOBYTE(v32) = 3;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    LOBYTE(v32) = 3;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    for ( l = 0; ; ++l )
    {
      v14 = std::to_wstring(&v28, l);
      LOBYTE(v32) = 22;
      std::operator+<wchar_t>((std::wstring *)&hint, L"DANGER_", v14);
      LOBYTE(v32) = 24;
      if ( v28._Myres >= 8 )
        operator delete(v28._Bx._Ptr);
      v28._Myres = 7;
      v28._Bx._Buf[0] = 0;
      v28._Mysize = 0;
      if ( !INIReader::hasSection(&ini, (const std::wstring *)&hint) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"START", 5u);
      LOBYTE(v32) = 25;
      *(float *)v22.m128i_i32 = INIReader::getFloat(&ini, (const std::wstring *)&hint, &key);
      LOBYTE(v32) = 24;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"END", 3u);
      LOBYTE(v32) = 26;
      *(float *)&v22.m128i_i32[1] = INIReader::getFloat(&ini, (const std::wstring *)&hint, &key);
      LOBYTE(v32) = 24;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"LEFT", 4u);
      LOBYTE(v32) = 27;
      *(float *)&v22.m128i_i32[2] = INIReader::getFloat(&ini, (const std::wstring *)&hint, &key);
      LOBYTE(v32) = 24;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"RIGHT", 5u);
      LOBYTE(v32) = 28;
      *(float *)&v22.m128i_i32[3] = INIReader::getFloat(&ini, (const std::wstring *)&hint, &key);
      LOBYTE(v32) = 24;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v15 = COERCE_FLOAT(&hint);
      if ( v27 >= 8 )
        v15 = hint.startPos;
      _printf(
        "%S START:%f END:%f LEFT:%f RIGHT:%f\n",
        (const wchar_t *)LODWORD(v15),
        *(float *)v22.m128i_i32,
        *(float *)&v22.m128i_i32[1],
        *(float *)&v22.m128i_i32[2],
        *(float *)&v22.m128i_i32[3]);
      v16 = v1->hintsDanger._Mylast;
      v17 = &v1->hintsDanger;
      if ( &v22 >= (__m128i *)v16 || v17->_Myfirst > (AISplineDanger *)&v22 )
      {
        if ( v16 == v1->hintsDanger._Myend )
          std::vector<AISplineDanger>::_Reserve(&v1->hintsDanger, 1u);
        v21 = (__m128i *)v1->hintsDanger._Mylast;
        if ( v21 )
          *v21 = _mm_loadu_si128(&v22);
      }
      else
      {
        v18 = (char *)&v22 - (char *)v17->_Myfirst;
        if ( v16 == v17->_Myend )
          std::vector<AISplineDanger>::_Reserve(v17, 1u);
        v19 = (__m128i *)v17->_Mylast;
        v20 = (const __m128i *)((char *)v17->_Myfirst + (v18 & 0xFFFFFFF0));
        if ( v19 )
          *v19 = _mm_loadu_si128(v20);
        v1 = v23;
      }
      ++v17->_Mylast;
      LOBYTE(v32) = 3;
      if ( v27 >= 8 )
        operator delete(LODWORD(hint.startPos));
    }
    if ( v27 >= 8 )
      operator delete(LODWORD(hint.startPos));
  }
  else
  {
    if ( filename._Myres >= 8 )
      v3 = (std::wstring *)filename._Bx._Ptr;
    _printf("Hint file :%S not available\n", v3->_Bx._Buf);
  }
  LOBYTE(v32) = 2;
  INIReader::~INIReader(&ini);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void __usercall AISplineRecorder::loadPitLaneSpline(AISplineRecorder *this@<ecx>, unsigned int a2@<ebx>, __m128 a3@<xmm3>, __m128 a4@<xmm4>)
{
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  bool v7; // zf
  std::wstring *v8; // eax
  bool v9; // bl
  int v10; // eax
  unsigned int i; // esi
  float v12; // xmm2_4
  float v13; // xmm0_4
  float pos; // [esp+18h] [ebp-60h]
  float posa; // [esp+18h] [ebp-60h]
  int index; // [esp+1Ch] [ebp-5Ch] BYREF
  vec3f pt; // [esp+20h] [ebp-58h] BYREF
  vec3f spos; // [esp+2Ch] [ebp-4Ch] BYREF
  std::wstring pitlane_name_new; // [esp+38h] [ebp-40h] BYREF
  std::wstring result; // [esp+50h] [ebp-28h] BYREF
  int v21; // [esp+74h] [ebp-4h]

  v5 = Track::getDataFolder(this->track, &result);
  v21 = 0;
  std::operator+<wchar_t>(&pitlane_name_new, v5, L"/ai/pit_lane.ai");
  LOBYTE(v21) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Bx._Buf[0] = 0;
  v6 = &pitlane_name_new;
  if ( pitlane_name_new._Myres >= 8 )
    v6 = (std::wstring *)pitlane_name_new._Bx._Ptr;
  result._Myres = 7;
  result._Mysize = 0;
  _printf("LOOKING FOR: %S\n", v6->_Bx._Buf);
  v7 = Path::fileExists(a2, &pitlane_name_new, 0) == 0;
  v8 = &pitlane_name_new;
  if ( v7 )
  {
    if ( pitlane_name_new._Myres >= 8 )
      v8 = (std::wstring *)pitlane_name_new._Bx._Ptr;
    _printf("NO PIT LANE FOUND: %S\n", v8->_Bx._Buf);
  }
  else
  {
    if ( pitlane_name_new._Myres >= 8 )
      v8 = (std::wstring *)pitlane_name_new._Bx._Ptr;
    _printf("LOADING SPLINE: %S\n", v8->_Bx._Buf);
    AISpline::load(&this->pitLaneSpline, a3, a4, &pitlane_name_new);
  }
  v9 = 0;
  v10 = Spline::pointsCount(&this->pitLaneSpline.spline);
  _printf("Scanning %u points\n", v10);
  for ( i = 0; i < Spline::pointsCount(&this->pitLaneSpline.spline); ++i )
  {
    Spline::pointAt(&this->pitLaneSpline.spline, &pt, i);
    index = -1;
    pos = SplineLocator::locateOnSpline(&this->bestLapSpline, &pt, &index);
    InterpolatingSpline::splineToWorld(&this->bestLapSpline.spline, &spos, pos);
    v12 = (float)((float)((float)(pt.y - spos.y) * (float)(pt.y - spos.y))
                + (float)((float)(pt.x - spos.x) * (float)(pt.x - spos.x)))
        + (float)((float)(pt.z - spos.z) * (float)(pt.z - spos.z));
    v13 = 0.0;
    if ( v12 != 0.0 )
      v13 = fsqrt(v12);
    if ( v9 )
    {
      if ( v13 <= 1.0 && i > (unsigned int)Spline::pointsCount(&this->pitLaneSpline.spline) >> 1 )
      {
        posa = (float)i;
        this->pitLaneSplineAttachPoint = posa / (float)(unsigned int)Spline::pointsCount(&this->pitLaneSpline.spline);
        break;
      }
    }
    else
    {
      v9 = v13 > 1.0;
    }
  }
  AISpline::initPitlane(&this->pitLaneSpline, this->track);
  if ( pitlane_name_new._Myres >= 8 )
    operator delete(pitlane_name_new._Bx._Ptr);
}
void AISplineRecorder::loadSideSpline(AISplineRecorder *this, InterpolatingSpline *is, std::wstring filename)
{
  unsigned int i; // esi
  vec3f *v4; // esi
  vec3f *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  const vec3f *v10; // eax
  const vec3f *v11; // esi
  vec3f *v12; // eax
  int v13; // ecx
  float *v14; // edi
  Spline *v15; // esi
  int v16; // eax
  vec3f *v17; // eax
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  std::wstring v22; // [esp+0h] [ebp-5Ch] BYREF
  vec3f v23; // [esp+24h] [ebp-38h] BYREF
  Spline *v24; // [esp+30h] [ebp-2Ch]
  vec3f result; // [esp+34h] [ebp-28h] BYREF
  float v26; // [esp+40h] [ebp-1Ch]
  float v27; // [esp+44h] [ebp-18h]
  AISplineRecorder *v28; // [esp+48h] [ebp-14h]
  float v29; // [esp+4Ch] [ebp-10h]
  int v30; // [esp+58h] [ebp-4h]

  v28 = this;
  v24 = is;
  v30 = 0;
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  std::wstring::assign(&v22, &filename, 0, 0xFFFFFFFF);
  Spline::loadFromCSV(is, v22);
  is->interpolationMode = eLinear;
  InterpolatingSpline::filterPointsTooClose(is, 0.1);
  for ( i = 0; i < Spline::pointsCount(is); ++i )
  {
    Spline::pointAt(is, &result, i);
    LODWORD(result.z) ^= _xmm;
    Spline::setPointAt(is, i, result);
  }
  v4 = Spline::pointAt(&v28->bestLapSpline.spline, &result, 0);
  v5 = Spline::pointAt(&v28->bestLapSpline.spline, &v23, 1u);
  v6 = v5->x - v4->x;
  v7 = v5->y - v4->y;
  v8 = v5->z - v4->z;
  v26 = v6;
  v27 = v7;
  v29 = v8;
  v9 = fsqrt((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8));
  if ( v9 != 0.0 )
  {
    v26 = (float)(1.0 / v9) * v6;
    v27 = (float)(1.0 / v9) * v7;
    v29 = (float)(1.0 / v9) * v8;
  }
  v22._Myres = 0;
  v10 = Spline::pointAt(&v28->bestLapSpline.spline, &v23, 0);
  v11 = InterpolatingSpline::closestPointIndex(is, v10, (float *)v22._Myres);
  v12 = Spline::pointAt(is, &v23, (unsigned int)v11);
  v13 = (int)&v11->x + 1;
  v14 = &v12->x;
  v15 = v24;
  v16 = Spline::wrapIndex(v24, v13);
  v17 = Spline::pointAt(v15, &result, v16);
  v18 = v17->x - *v14;
  v19 = v17->y - v14[1];
  v20 = v17->z - v14[2];
  v21 = fsqrt((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v20 * v20));
  if ( v21 != 0.0 )
  {
    v18 = (float)(1.0 / v21) * v18;
    v19 = (float)(1.0 / v21) * v19;
    v20 = (float)(1.0 / v21) * v20;
  }
  if ( (float)((float)((float)(v19 * v27) + (float)(v18 * v26)) + (float)(v20 * v29)) < 0.0 )
  {
    _printf("REVERSE NEEDED\n");
    Spline::reverse(v15);
  }
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void AISplineRecorder::onLapCompleted(AISplineRecorder *this, const OnLapCompletedEvent *message)
{
  int v3; // eax

  if ( this->isActive && message->carIndex == this->car->physicsGUID && !this->isRecordingPitlane )
  {
    if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
      EnterCriticalSection(&this->mutex.criticalSection);
    _printf("OnLapCompletedEvent: %u  bls:%u", message->lapTime, this->bestLapSpline.lapTime);
    if ( this->isSaveNeeded )
    {
      v3 = AISpline::pointsCount(&this->splineCurrent);
      _printf("Updating spline splineCurrent %u\n", v3);
      if ( Spline::isClosed(&this->splineCurrent.spline) )
        AISpline::closeSmooth(&this->splineCurrent);
      AISpline::operator=(&this->bestLapSpline, &this->splineCurrent);
      this->bestLapSpline.lapTime = message->lapTime;
      this->isSaveNeeded = 1;
    }
    AISpline::clear(&this->splineCurrent);
    LeaveCriticalSection(&this->mutex.criticalSection);
  }
}
void AISplineRecorder::recomputeSidesFromCsv(AISplineRecorder *this)
{
  double v2; // st7
  Track *v3; // ecx
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  int v6; // eax
  signed int v7; // esi
  wchar_t *v8; // edi
  std::thread *v9; // esi
  std::thread *v10; // edi
  std::thread *v11; // esi
  std::thread *v12; // ebx
  double v13; // st7
  std::thread *v14; // eax
  std::wstring v15[2]; // [esp-Ch] [ebp-DCh] BYREF
  int v16; // [esp+2Ch] [ebp-A4h]
  struct _Thrd_imp_t v17; // [esp+30h] [ebp-A0h] BYREF
  int points_per_thread; // [esp+38h] [ebp-98h] BYREF
  std::vector<std::thread> threads; // [esp+3Ch] [ebp-94h] BYREF
  double v20; // [esp+48h] [ebp-88h]
  std::_Pad v21; // [esp+54h] [ebp-7Ch] BYREF
  __int64 v22; // [esp+64h] [ebp-6Ch]
  AISplineRecorder *v23; // [esp+6Ch] [ebp-64h]
  std::wstring result; // [esp+74h] [ebp-5Ch] BYREF
  int v25; // [esp+CCh] [ebp-4h]

  v2 = ksGetTime();
  v3 = this->track;
  v20 = v2;
  v4 = Track::getDataFolder(v3, &result);
  v25 = 0;
  std::operator+<wchar_t>(v15, v4, L"/data/side_l.csv");
  AISplineRecorder::loadSideSpline(this, &this->leftSpline, v15[0]);
  v25 = -1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v5 = Track::getDataFolder(this->track, &result);
  v25 = 1;
  std::operator+<wchar_t>(v15, v5, L"/data/side_r.csv");
  AISplineRecorder::loadSideSpline(this, &this->rightSpline, v15[0]);
  v25 = -1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v6 = AISpline::pointsCount(&this->bestLapSpline);
  _printf("CALCULATING: %u\n", v6);
  points_per_thread = 2000;
  v7 = AISpline::pointsCount(&this->bestLapSpline) / 0x7D0u + 1;
  v16 = v7;
  _printf("DISPATCHING %d threads\n", v7);
  std::vector<std::thread>::vector<std::thread>(&threads, v7);
  v8 = 0;
  v25 = 2;
  if ( v7 > 0 )
  {
    v9 = threads._Myfirst;
    *(_DWORD *)&result._Bx._Alias[4] = &points_per_thread;
    while ( 1 )
    {
      result._Bx._Ptr = v8;
      std::_Pad::_Pad(&v21);
      v21.__vftable = (std::_Pad_vtbl *)&std::_LaunchPad<std::_Bind<0,void,_lambda_7ddde326f03d9f826f37875905f4ba7d_,>>::`vftable';
      v22 = *(_QWORD *)result._Bx._Buf;
      v23 = this;
      LOBYTE(v25) = 3;
      std::_Pad::_Launch(&v21, &v17);
      LOBYTE(v25) = 2;
      std::_Pad::~_Pad(&v21);
      if ( v9->_Thr._Id )
        break;
      v8 = (wchar_t *)((char *)v8 + 1);
      v9->_Thr = v17;
      ++v9;
      v17._Id = 0;
      if ( (int)v8 >= v16 )
        goto LABEL_9;
    }
LABEL_25:
    terminate();
  }
LABEL_9:
  v10 = threads._Myfirst;
  v11 = threads._Myfirst;
  v12 = threads._Mylast;
  if ( threads._Myfirst != threads._Mylast )
  {
    do
    {
      if ( !v11->_Thr._Id )
      {
        std::_Throw_Cpp_error(1);
        if ( !v11->_Thr._Id )
          std::_Throw_Cpp_error(1);
      }
      *(_Thrd_t *)&v15[0]._Mysize = __Thrd_current();
      if ( __Thrd_equal(v11->_Thr, *(_Thrd_t *)&v15[0]._Mysize) )
        std::_Throw_Cpp_error(5);
      if ( __Thrd_join(v11->_Thr, 0) )
        std::_Throw_Cpp_error(2);
      v11->_Thr._Id = 0;
      ++v11;
    }
    while ( v11 != v12 );
    v10 = threads._Myfirst;
  }
  v13 = ksGetTime();
  _printf("FINISHED COMPUTING SIDES IN  %f\n", v13 - v20);
  v25 = -1;
  if ( v10 )
  {
    v14 = v10;
    if ( v10 != v12 )
    {
      while ( !v14->_Thr._Id )
      {
        if ( ++v14 == v12 )
          goto LABEL_23;
      }
      goto LABEL_25;
    }
LABEL_23:
    operator delete(v10);
  }
}
void __userpurge AISplineRecorder::save(AISplineRecorder *this@<ecx>, __m128 a2@<xmm0>, bool updateFile)
{
  int v4; // eax
  int v5; // eax
  std::wstring *v6; // eax
  Track *v7; // ecx
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring v14; // [esp-18h] [ebp-BCh] BYREF
  std::wstring *v15; // [esp+14h] [ebp-90h]
  ThreadLocker lock; // [esp+18h] [ebp-8Ch]
  std::wstring result; // [esp+1Ch] [ebp-88h] BYREF
  std::wstring fastlane_name; // [esp+34h] [ebp-70h] BYREF
  std::wstring pitlane_name; // [esp+4Ch] [ebp-58h] BYREF
  std::wstring v20; // [esp+64h] [ebp-40h] BYREF
  std::wstring v21; // [esp+7Ch] [ebp-28h] BYREF
  int v22; // [esp+A0h] [ebp-4h]

  _printf("SAVING SPLINE\n");
  lock.guard = &this->mutex;
  if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
    EnterCriticalSection(&this->mutex.criticalSection);
  v22 = 0;
  v4 = AISpline::pointsCount(&this->bestLapSpline);
  _printf("BEST LAP POINT COUNT:%u\n", v4);
  v5 = AISpline::pointsCount(&this->bestLapSpline);
  _printf("PITLANE POINT COUNT:%u\n", v5);
  v6 = Track::getDataFolder(this->track, &result);
  LOBYTE(v22) = 1;
  std::operator+<wchar_t>(&fastlane_name, v6, L"/ai/fast_lane.ai.candidate");
  LOBYTE(v22) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v7 = this->track;
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  v8 = Track::getDataFolder(v7, &v20);
  LOBYTE(v22) = 4;
  std::operator+<wchar_t>(&pitlane_name, v8, L"/ai/pit_lane.ai.candidate");
  LOBYTE(v22) = 6;
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  v20._Myres = 7;
  v20._Mysize = 0;
  v20._Bx._Buf[0] = 0;
  if ( updateFile )
  {
    v9 = Track::getDataFolder(this->track, &v21);
    LOBYTE(v22) = 7;
    v10 = std::operator+<wchar_t>(&result, v9, L"/ai/fast_lane.ai");
    v15 = v10;
    if ( &fastlane_name != v10 )
    {
      if ( fastlane_name._Myres >= 8 )
      {
        operator delete(fastlane_name._Bx._Ptr);
        v10 = v15;
      }
      fastlane_name._Myres = 7;
      fastlane_name._Bx._Buf[0] = 0;
      fastlane_name._Mysize = 0;
      std::wstring::_Assign_rv(&fastlane_name, v10);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v22) = 6;
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
    v11 = Track::getDataFolder(this->track, &v21);
    LOBYTE(v22) = 8;
    v12 = std::operator+<wchar_t>(&result, v11, L"/ai/pit_lane.ai");
    v15 = v12;
    if ( &pitlane_name != v12 )
    {
      if ( pitlane_name._Myres >= 8 )
      {
        operator delete(pitlane_name._Bx._Ptr);
        v12 = v15;
      }
      pitlane_name._Myres = 7;
      pitlane_name._Bx._Buf[0] = 0;
      pitlane_name._Mysize = 0;
      std::wstring::_Assign_rv(&pitlane_name, v12);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v22) = 6;
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
  }
  v13 = &fastlane_name;
  if ( fastlane_name._Myres >= 8 )
    v13 = (std::wstring *)fastlane_name._Bx._Ptr;
  _printf("FILENAME: %S\n", v13->_Bx._Buf);
  if ( AISpline::pointsCount(&this->pitLaneSpline) )
  {
    v14._Myres = 7;
    v14._Mysize = 0;
    v14._Bx._Buf[0] = 0;
    std::wstring::assign(&v14, &pitlane_name, 0, 0xFFFFFFFF);
    AISpline::save(&this->pitLaneSpline, v14);
  }
  if ( AISpline::pointsCount(&this->bestLapSpline) )
  {
    AISpline::calculateRadius(&this->bestLapSpline, 5);
    this->bestLapSpline.lapTime = 0;
    AISpline::buildSides(&this->bestLapSpline, a2, this->physicsEngine->track);
    AISpline::cleanSpline(&this->bestLapSpline);
    if ( Spline::isClosed(&this->bestLapSpline.spline) )
      AISpline::closeSmooth(&this->bestLapSpline);
    InterpolatingSpline::computeSplineLength(&this->bestLapSpline.spline);
    AISpline::calculateNormals(&this->bestLapSpline, a2, this->physicsEngine->track);
    AISpline::buildGrid(&this->bestLapSpline);
    v14._Myres = 7;
    v14._Mysize = 0;
    v14._Bx._Buf[0] = 0;
    std::wstring::assign(&v14, &fastlane_name, 0, 0xFFFFFFFF);
    AISpline::save(&this->bestLapSpline, v14);
  }
  _printf("FINISHED SAVING SPLINE\n");
  if ( pitlane_name._Myres >= 8 )
    operator delete(pitlane_name._Bx._Ptr);
  pitlane_name._Myres = 7;
  pitlane_name._Mysize = 0;
  pitlane_name._Bx._Buf[0] = 0;
  if ( fastlane_name._Myres >= 8 )
    operator delete(fastlane_name._Bx._Ptr);
  fastlane_name._Myres = 7;
  fastlane_name._Mysize = 0;
  fastlane_name._Bx._Buf[0] = 0;
  LeaveCriticalSection(&this->mutex.criticalSection);
}
void AISplineRecorder::startRecording(AISplineRecorder *this)
{
  ThreadMutex *v2; // esi

  v2 = &this->mutex;
  if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
    EnterCriticalSection(&v2->criticalSection);
  this->isSaveNeeded = 1;
  _printf("AI RECORDING STARTED\n");
  LeaveCriticalSection(&v2->criticalSection);
}
void AISplineRecorder::step(AISplineRecorder *this, float dt)
{
  PhysicsEngine *v3; // eax
  Event<OnLapCompletedEvent> *v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm0_4
  Car *v7; // eax
  IRigidBody *v8; // ecx
  const vec3f *v9; // eax
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v10; // [esp-Ch] [ebp-C0h] BYREF
  AISplinePayload *v11; // [esp+Ch] [ebp-A8h]
  Speed result; // [esp+24h] [ebp-90h] BYREF
  vec3f cp; // [esp+28h] [ebp-8Ch] BYREF
  vec3f lp; // [esp+34h] [ebp-80h] BYREF
  ThreadLocker lock; // [esp+40h] [ebp-74h]
  char v16[12]; // [esp+44h] [ebp-70h] BYREF
  AISplinePayload pl; // [esp+50h] [ebp-64h] BYREF
  int v18; // [esp+B0h] [ebp-4h]

  if ( !this->isActive )
    return;
  if ( !this->isSaveNeeded )
    goto LABEL_5;
  if ( !this->car )
  {
    v3 = this->physicsEngine;
    v11 = (AISplinePayload *)this;
    this->car = *v3->cars._Myfirst;
    v10._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_ee9681f74593d010f75da26732cea64a_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
    v10._Space._Pfn[1] = (void (__cdecl *)())this;
    v10._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v10;
    v4 = &this->car->evOnLapCompleted;
    v18 = -1;
    Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)v4, v10, v11);
LABEL_5:
    if ( !this->car )
      return;
  }
  lock.guard = &this->mutex;
  if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
    EnterCriticalSection(&this->mutex.criticalSection);
  v18 = 1;
  if ( !AISpline::pointsCount(&this->splineCurrent) )
    goto LABEL_12;
  AISpline::getLastPoint(&this->splineCurrent, &lp);
  ((void (*)(IRigidBody *, vec3f *, _DWORD))this->car->body->getPosition)(this->car->body, &cp, 0);
  v5 = (float)((float)(cp.z - lp.z) * (float)(cp.z - lp.z)) + (float)((float)(cp.x - lp.x) * (float)(cp.x - lp.x));
  v6 = 0.0;
  if ( v5 != 0.0 )
    v6 = fsqrt(v5);
  if ( v6 >= this->recordingStep )
  {
LABEL_12:
    AISplinePayload::AISplinePayload(&pl);
    pl.speedMS = Car::getSpeed(this->car, &result)->value;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    v7 = this->car;
    pl.gas = v7->controls.gas;
    pl.brake = v7->controls.brake;
    v8 = v7->body;
    v11 = &pl;
    v9 = (const vec3f *)((int (*)(IRigidBody *, char *, _DWORD))v8->getPosition)(v8, v16, 0);
    AISpline::addPoint(&this->splineCurrent, v9, v11);
  }
  LeaveCriticalSection(&this->mutex.criticalSection);
}
