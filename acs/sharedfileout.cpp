#include "sharedfileout.h"
void SharedFileOut::SharedFileOut(SharedFileOut *this, Sim *isim)
{
  HANDLE v3; // eax
  unsigned __int8 *v4; // eax
  HWND v5; // eax
  std::wstring v6; // [esp-1Ch] [ebp-44h] BYREF
  Game *v7; // [esp-4h] [ebp-2Ch]
  wchar_t szName[12]; // [esp+Ch] [ebp-1Ch] BYREF

  v7 = isim->game;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, L"SHAREDFILE_OUTPUT", 0x11u);
  GameObject::GameObject(this, v6, v7);
  this->__vftable = (SharedFileOut_vtbl *)&SharedFileOut::`vftable';
  v7 = (Game *)szName;
  this->sim = isim;
  this->lastPosition.x = 0.0;
  this->lastPosition.y = 0.0;
  this->lastPosition.z = 0.0;
  v6._Myres = 412;
  this->packetId = 0;
  this->currentDistance = 0.0;
  this->car = 0;
  this->nullCounts = 0;
  *(__m128i *)szName = _mm_loadu_si128((const __m128i *)aLocalAc);
  *(_QWORD *)&szName[8] = 0x66006D0070i64;
  v3 = CreateFileMappingW((HANDLE)0xFFFFFFFF, 0, 4u, 0, v6._Myres, (LPCWSTR)v7);
  this->hMapFile = v3;
  if ( v3 )
  {
    v4 = (unsigned __int8 *)MapViewOfFile(v3, 0xF001Fu, 0, 0, 0x19Cu);
    this->mapFileBuffer = v4;
    if ( v4 )
      return;
    v7 = 0;
    v6._Myres = (unsigned int)"AssettoCorsa";
    v6._Mysize = (unsigned int)"MapViewOfFile failed";
  }
  else
  {
    v7 = 0;
    v6._Myres = (unsigned int)"AssettoCorsa";
    v6._Mysize = (unsigned int)"CreateFileMappingn failed";
  }
  v5 = GetActiveWindow();
  MessageBoxA(v5, (LPCSTR)v6._Mysize, (LPCSTR)v6._Myres, (UINT)v7);
}
SharedFileOut *SharedFileOut::`vector deleting destructor'(SharedFileOut *this, unsigned int a2)
{
  unsigned __int8 *v4; // [esp-4h] [ebp-8h]

  v4 = this->mapFileBuffer;
  this->__vftable = (SharedFileOut_vtbl *)&SharedFileOut::`vftable';
  UnmapViewOfFile(v4);
  CloseHandle(this->hMapFile);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SharedFileOut::update(SharedFileOut *this, float deltaT)
{
  unsigned int *v3; // eax
  unsigned __int64 v4; // xmm2_8
  float v5; // eax
  CarAvatar *v6; // esi
  wchar_t **v7; // ecx
  int *v8; // edx
  __int16 v9; // ax
  TrackData *v10; // eax
  TrackData *v11; // ecx
  int *v12; // edx
  wchar_t v13; // ax
  CarAvatar *v14; // ecx
  std::wstring *v15; // eax
  CarAvatar *v16; // ecx
  int v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm3_4
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  float v26; // xmm0_4
  Sim *v27; // ecx
  unsigned int v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // edx
  Sim *v31; // eax
  unsigned int v32; // esi
  float v33; // eax
  float v34; // xmm0_4
  CarAvatar *v35; // eax
  mat44f *v36; // esi
  unsigned int v37; // xmm0_4
  float v38; // xmm2_4
  int v39; // xmm1_4
  int v40; // xmm3_4
  float v41; // xmm0_4
  unsigned __int8 *v42; // edi
  CarAvatar *v43; // [esp-4h] [ebp-240h]
  float v44; // [esp+Ch] [ebp-230h]
  int *v45; // [esp+10h] [ebp-22Ch]
  int v46[103]; // [esp+14h] [ebp-228h] BYREF
  TrackData result; // [esp+1B0h] [ebp-8Ch] BYREF
  Lap v48; // [esp+1E4h] [ebp-58h] BYREF
  std::wstring v49; // [esp+214h] [ebp-28h] BYREF
  int v50; // [esp+238h] [ebp-4h]

  if ( this->nullCounts >= 30 )
  {
    if ( !this->car )
      this->car = GameObject::getGameObject<CarAvatar>(this->sim);
    v6 = this->car;
    v7 = (wchar_t **)&v6->unixName;
    if ( v6->unixName._Myres >= 8 )
      v7 = (wchar_t **)*v7;
    v8 = &v46[1];
    do
    {
      v9 = *(_WORD *)v7;
      v7 = (wchar_t **)((char *)v7 + 2);
      *(_WORD *)v8 = v9;
      v8 = (int *)((char *)v8 + 2);
    }
    while ( v9 );
    v10 = Sim::getTrackData(v6->sim, &result);
    v11 = v10;
    if ( v10->name._Myres >= 8 )
      v11 = (TrackData *)v10->name._Bx._Ptr;
    v12 = &v46[17];
    do
    {
      v13 = v11->name._Bx._Buf[0];
      v11 = (TrackData *)((char *)v11 + 2);
      *(_WORD *)v12 = v13;
      v12 = (int *)((char *)v12 + 2);
    }
    while ( v13 );
    if ( result.configuration._Myres >= 8 )
      operator delete(result.configuration._Bx._Ptr);
    result.configuration._Myres = 7;
    result.configuration._Mysize = 0;
    result.configuration._Bx._Buf[0] = 0;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    v14 = this->car;
    v46[34] = LODWORD(v14->physicsInfo.maxPowerW);
    v46[33] = LODWORD(v14->physicsInfo.maxTorqueNM);
    v46[35] = v14->physicsState.gear - 1;
    v46[36] = (int)v14->physicsState.engineRPM;
    v15 = timeToString(&v49, v14->physicsState.bestLap, 3);
    if ( v15->_Myres >= 8 )
      v15 = (std::wstring *)v15->_Bx._Ptr;
    _wcscpy_s((wchar_t *)&v46[48], 0xAu, v15->_Bx._Buf);
    if ( v49._Myres >= 8 )
      operator delete(v49._Bx._Ptr);
    _wcscpy_s((wchar_t *)&v46[43], 0xAu, L" ");
    _wcscpy_s((wchar_t *)&v46[38], 0xAu, L" ");
    _wcscpy_s((wchar_t *)&v46[53], 0xAu, L" ");
    v16 = this->car;
    v46[59] = LODWORD(v16->physicsState.brake);
    v46[60] = LODWORD(v16->physicsState.fuel);
    v46[58] = LODWORD(v16->physicsState.gas);
    v46[37] = v16->physicsState.limiterRPM;
    v46[62] = LODWORD(v16->physicsState.speed.value);
    v46[63] = v16->physicsState.lapCount;
    v46[66] = -1;
    *(float *)&v17 = v16->physicsInfo.maxFuel;
    v46[65] = 1;
    v46[64] = 1;
    v46[61] = v17;
    v46[67] = v16->physicsState.lapTime;
    v46[68] = v16->physicsState.lastLap;
    v46[69] = v16->physicsState.bestLap;
    v46[0] = this->packetId;
    this->packetId = v46[0] + 1;
    v46[77] = LODWORD(v16->physicsState.ndSlip[0]);
    v46[81] = LODWORD(v16->physicsState.load[0]);
    *(float *)&v46[73] = v16->physicsState.suspensionTravel[0] - v16->physicsInfo.bumpStopsDn[0];
    *(float *)&v46[85] = v16->physicsInfo.bumpStopsUp[0] - v16->physicsInfo.bumpStopsDn[0];
    v46[78] = LODWORD(v16->physicsState.ndSlip[1]);
    v46[82] = LODWORD(v16->physicsState.load[1]);
    *(float *)&v46[74] = v16->physicsState.suspensionTravel[1] - v16->physicsInfo.bumpStopsDn[1];
    *(float *)&v46[86] = v16->physicsInfo.bumpStopsUp[1] - v16->physicsInfo.bumpStopsDn[1];
    v46[79] = LODWORD(v16->physicsState.ndSlip[2]);
    v46[83] = LODWORD(v16->physicsState.load[2]);
    *(float *)&v46[75] = v16->physicsState.suspensionTravel[2] - v16->physicsInfo.bumpStopsDn[2];
    *(float *)&v46[87] = v16->physicsInfo.bumpStopsUp[2] - v16->physicsInfo.bumpStopsDn[2];
    v46[80] = LODWORD(v16->physicsState.ndSlip[3]);
    v46[84] = LODWORD(v16->physicsState.load[3]);
    v18 = this->lastPosition.x;
    *(float *)&v46[76] = v16->physicsState.suspensionTravel[3] - v16->physicsInfo.bumpStopsDn[3];
    v19 = this->lastPosition.z;
    *(float *)&v46[88] = v16->physicsInfo.bumpStopsUp[3] - v16->physicsInfo.bumpStopsDn[3];
    v46[70] = LODWORD(v16->physicsState.accG.x);
    v46[71] = LODWORD(v16->physicsState.accG.y);
    v46[72] = LODWORD(v16->physicsState.accG.z);
    v20 = this->lastPosition.y - v16->bodyMatrix.M42;
    v21 = (float)((float)((float)(v18 - v16->bodyMatrix.M41) * (float)(v18 - v16->bodyMatrix.M41)) + (float)(v20 * v20))
        + (float)((float)(v19 - v16->bodyMatrix.M43) * (float)(v19 - v16->bodyMatrix.M43));
    v22 = 0.0;
    if ( v21 != 0.0 )
      v22 = fsqrt(v21);
    v23 = v22 + this->currentDistance;
    v43 = v16;
    this->currentDistance = v23;
    v24 = (__m128)LODWORD(v16->bodyMatrix.M41);
    v25 = (__m128)LODWORD(v16->bodyMatrix.M42);
    v26 = v16->bodyMatrix.M43;
    v27 = this->sim;
    *(float *)&v49._Myres = v26;
    *(_QWORD *)&this->lastPosition.x = _mm_unpacklo_ps(v24, v25).m128_u64[0];
    this->lastPosition.z = v26;
    *(float *)&v46[89] = v23;
    v46[90] = 0;
    RaceManager::getCurrentLap(v27->raceManager, &v48, v43);
    v28 = 0;
    v29 = v48.time;
    v30 = v48.splits._Mylast - v48.splits._Myfirst;
    v50 = 0;
    v46[92] = v48.time;
    if ( v30 )
    {
      do
      {
        v29 -= v48.splits._Myfirst[v28++];
        v46[92] = v29;
      }
      while ( v28 < v30 );
    }
    v31 = this->sim;
    v46[91] = v48.splits._Mylast - v48.splits._Myfirst;
    v46[93] = v31->track->physicsTrack.sectorsNormalizedPositions._Mylast
            - v31->track->physicsTrack.sectorsNormalizedPositions._Myfirst;
    if ( this->car->raceEngineer._Myptr )
    {
      v32 = 0;
      v45 = &v46[94];
      do
      {
        v33 = RaceEngineer::getCar(this->car->raceEngineer._Myptr)->tyres[v32++].status.pressureDynamic;
        *(float *)v45++ = v33;
      }
      while ( v32 < 4 );
      v46[98] = RaceEngineer::getCar(this->car->raceEngineer._Myptr)->drs.isPresent;
      v34 = RaceEngineer::getCar(this->car->raceEngineer._Myptr)->tractionControl.slipRatioLimit;
      v35 = this->car;
      *(float *)&v46[99] = v34;
      if ( !RaceEngineer::getCar(v35->raceEngineer._Myptr)->tractionControl.isActive )
        v46[99] = 0;
    }
    v36 = &this->car->bodyMatrix;
    *(float *)&v49._Bx._Alias[12] = atan2(
                                      COERCE_FLOAT(LODWORD(this->car->bodyMatrix.M31) ^ _xmm),
                                      this->car->bodyMatrix.M33);
    v37 = __libm_sse2_asinf().m128_u32[0];
    v38 = v36->M12;
    v39 = 0;
    v40 = v37;
    if ( v38 == 0.0 && v36->M22 == 0.0 )
    {
      v44 = v36->M21;
      v41 = v36->M11;
    }
    else
    {
      v41 = v36->M22;
      v39 = *(_DWORD *)&v49._Bx._Alias[12];
      LODWORD(v44) = LODWORD(v38) ^ _xmm;
    }
    v42 = this->mapFileBuffer;
    v50 = -1;
    v46[100] = v39;
    *(float *)&v49._Myres = atan2(v44, v41);
    v46[101] = v40;
    v46[102] = v49._Myres;
    qmemcpy(v42, v46, 0x19Cu);
    if ( v48.compound._Myres >= 8 )
      operator delete(v48.compound._Bx._Ptr);
    v48.compound._Myres = 7;
    v48.compound._Mysize = 0;
    v48.compound._Bx._Buf[0] = 0;
    if ( v48.splits._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&v48.splits);
      operator delete(v48.splits._Myfirst);
    }
  }
  else
  {
    if ( Sim::getCar(this->sim, 0) )
    {
      v3 = (unsigned int *)Sim::getCar(this->sim, 0);
      v4 = _mm_unpacklo_ps((__m128)v3[103], (__m128)v3[104]).m128_u64[0];
      v49._Myres = v3[105];
      v5 = *(float *)&v49._Myres;
      *(_QWORD *)&this->lastPosition.x = v4;
      this->lastPosition.z = v5;
    }
    ++this->nullCounts;
  }
}
