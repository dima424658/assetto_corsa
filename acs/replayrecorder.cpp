#include "replayrecorder.h
void ReplayRecorder::ReplayRecorder(ReplayRecorder *this, CarAvatar *iavatar, ICarPhysicsStateProvider *aPhysics)
{
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  int v6; // eax
  bool v7; // cf
  CarAvatar *v8; // eax
  unsigned int v9; // ebp
  int v10; // esi
  GameObject **v11; // esi
  DynamicCarEffects *v12; // eax
  GameObject **v13; // esi
  CarBrakeLights *v14; // eax
  bool v15; // zf
  std::wstring v16; // [esp-1Ch] [ebp-F8h] BYREF
  Game *v17; // [esp-4h] [ebp-E0h]
  std::vector<WingState> ws; // [esp+14h] [ebp-C8h] BYREF
  unsigned int _Pval[2]; // [esp+20h] [ebp-BCh] BYREF
  std::wstring section; // [esp+28h] [ebp-B4h] BYREF
  std::wstring key; // [esp+40h] [ebp-9Ch] BYREF
  std::wstring v22; // [esp+58h] [ebp-84h] BYREF
  std::wstring result; // [esp+70h] [ebp-6Ch] BYREF
  INIReader r; // [esp+88h] [ebp-54h] BYREF
  int v25; // [esp+D8h] [ebp-4h]

  _Pval[1] = (unsigned int)this;
  v17 = iavatar->game;
  v16._Myres = 7;
  v16._Mysize = 0;
  v16._Bx._Buf[0] = 0;
  std::wstring::assign(&v16, L"REPLAY_RECORDER", 0xFu);
  GameObject::GameObject(this, v16, v17);
  v25 = 0;
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&ICarPhysicsStateProvider::`vftable';
  this->GameObject::__vftable = (ReplayRecorder_vtbl *)&ReplayRecorder::`vftable'{for `GameObject'};
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&ReplayRecorder::`vftable'{for `ICarPhysicsStateProvider'};
  this->frameBlend = 0.0;
  this->isRewinding = 0;
  this->avatar = iavatar;
  this->dynamicCarEffects = 0;
  this->brakeLights = 0;
  this->frames._Myfirst = 0;
  this->frames._Mylast = 0;
  this->frames._Myend = 0;
  this->framesAdditionalInfo._Myfirst = 0;
  this->framesAdditionalInfo._Mylast = 0;
  this->framesAdditionalInfo._Myend = 0;
  this->frames_wings._Myfirst = 0;
  this->frames_wings._Mylast = 0;
  this->frames_wings._Myend = 0;
  this->physics = aPhysics;
  this->version = 16;
  this->metaData.frameCount = 0;
  this->metaData.numberOfWings = 0;
  this->recordedFrames = 0;
  this->maxLapFrameSize = 999;
  v17 = (Game *)_Pval;
  v16._Myres = 999;
  LOBYTE(v25) = 4;
  _Pval[0] = -1;
  this->lapFrameIndexCache._Myfirst = 0;
  this->lapFrameIndexCache._Mylast = 0;
  this->lapFrameIndexCache._Myend = 0;
  std::vector<unsigned int>::_Construct_n(&this->lapFrameIndexCache, v16._Myres, (const unsigned int *)v17);
  LOBYTE(v25) = 5;
  v17 = (Game *)&iavatar->unixName;
  this->lapCacheIndex = 0;
  v16._Myres = (unsigned int)L"content/cars/";
  v16._Mysize = (unsigned int)&result;
  this->isRewinding = 0;
  this->frameBlend = 0.0;
  this->playingPos = 0;
  this->currentRecordingCue = 0;
  v4 = std::operator+<wchar_t>((std::wstring *)v16._Mysize, (const wchar_t *)v16._Myres, (const std::wstring *)v17);
  LOBYTE(v25) = 6;
  v5 = std::operator+<wchar_t>(&v22, v4, L"/data/engine.ini");
  LOBYTE(v25) = 7;
  CarAvatar::openINI(iavatar, &r, v5);
  if ( v22._Myres >= 8 )
    operator delete(v22._Bx._Ptr);
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  LOBYTE(v25) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LIMITER", 7u);
    LOBYTE(v25) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ENGINE_DATA", 0xBu);
    LOBYTE(v25) = 12;
    v6 = INIReader::getInt(&r, &section, &key);
    v7 = section._Myres < 8;
    this->stdEngineLimiter = v6;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  else
  {
    this->stdEngineLimiter = 9999;
  }
  ws._Myfirst = 0;
  ws._Mylast = 0;
  ws._Myend = 0;
  v8 = this->avatar;
  LOBYTE(v25) = 13;
  v8->physicsStateProvider->getWingState(v8->physicsStateProvider, &ws);
  v9 = 0;
  if ( this->frames_wings._Mylast - this->frames_wings._Myfirst )
  {
    v10 = 0;
    do
    {
      std::vector<ReplayFrameWingStatus>::resize(&this->frames_wings._Myfirst[v10], ws._Mylast - ws._Myfirst);
      ++v9;
      ++v10;
    }
    while ( v9 < this->frames_wings._Mylast - this->frames_wings._Myfirst );
  }
  v11 = iavatar->gameObjects._Myfirst;
  if ( v11 == iavatar->gameObjects._Mylast )
  {
LABEL_17:
    v12 = 0;
  }
  else
  {
    while ( 1 )
    {
      v12 = (DynamicCarEffects *)__RTDynamicCast(
                                   *v11,
                                   0,
                                   &GameObject `RTTI Type Descriptor',
                                   &DynamicCarEffects `RTTI Type Descriptor',
                                   0);
      if ( v12 )
        break;
      if ( ++v11 == iavatar->gameObjects._Mylast )
        goto LABEL_17;
    }
  }
  this->dynamicCarEffects = v12;
  v13 = iavatar->gameObjects._Myfirst;
  if ( v13 == iavatar->gameObjects._Mylast )
  {
LABEL_21:
    v14 = 0;
  }
  else
  {
    while ( 1 )
    {
      v14 = (CarBrakeLights *)__RTDynamicCast(
                                *v13,
                                0,
                                &GameObject `RTTI Type Descriptor',
                                &CarBrakeLights `RTTI Type Descriptor',
                                0);
      if ( v14 )
        break;
      if ( ++v13 == iavatar->gameObjects._Mylast )
        goto LABEL_21;
    }
  }
  v15 = ws._Myfirst == 0;
  this->brakeLights = v14;
  LOBYTE(v25) = 10;
  if ( !v15 )
  {
    std::_Container_base0::_Orphan_all(&ws);
    operator delete(ws._Myfirst);
    ws._Myfirst = 0;
    ws._Mylast = 0;
    ws._Myend = 0;
  }
  LOBYTE(v25) = 5;
  INIReader::~INIReader(&r);
}
void ReplayRecorder::~ReplayRecorder(ReplayRecorder *this)
{
  std::vector<unsigned int> *v2; // edi

  v2 = &this->lapFrameIndexCache;
  this->GameObject::__vftable = (ReplayRecorder_vtbl *)&ReplayRecorder::`vftable'{for `GameObject'};
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&ReplayRecorder::`vftable'{for `ICarPhysicsStateProvider'};
  if ( this->lapFrameIndexCache._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lapFrameIndexCache);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  if ( this->frames_wings._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->frames_wings);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
      (std::vector<unsigned char> *)this->frames_wings._Myfirst,
      (std::vector<unsigned char> *)this->frames_wings._Mylast);
    operator delete(this->frames_wings._Myfirst);
    this->frames_wings._Myfirst = 0;
    this->frames_wings._Mylast = 0;
    this->frames_wings._Myend = 0;
  }
  if ( this->framesAdditionalInfo._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->framesAdditionalInfo);
    operator delete(this->framesAdditionalInfo._Myfirst);
    this->framesAdditionalInfo._Myfirst = 0;
    this->framesAdditionalInfo._Mylast = 0;
    this->framesAdditionalInfo._Myend = 0;
  }
  if ( this->frames._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->frames);
    operator delete(this->frames._Myfirst);
    this->frames._Myfirst = 0;
    this->frames._Mylast = 0;
    this->frames._Myend = 0;
  }
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&ICarPhysicsStateProvider::`vftable';
  GameObject::~GameObject(this);
}
ReplayRecorder *ReplayRecorder::`vector deleting destructor'(char *this, unsigned int a2)
{
  return ReplayRecorder::`vector deleting destructor'((ReplayRecorder *)(this - 52), a2);
}
ReplayRecorder *ReplayRecorder::`vector deleting destructor'(ReplayRecorder *this, unsigned int a2)
{
  ReplayRecorder::~ReplayRecorder(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ReplayRecorder::clearFrames(ReplayRecorder *this)
{
  this->currentRecordingCue = 0;
  this->recordedFrames = 0;
}
void ReplayRecorder::fetchLapFrames(ReplayRecorder *this, std::vector<unsigned int> *lapFramesArgument)
{
  ReplayRecorder *v2; // eax
  unsigned int *v3; // esi
  unsigned int *i; // edi
  unsigned int v5; // ebp
  unsigned int *v6; // eax
  int v7; // ebp
  unsigned int *v8; // ecx
  unsigned int *v9; // eax
  unsigned int lapFrame; // [esp+8h] [ebp-8h] BYREF
  ReplayRecorder *v11; // [esp+Ch] [ebp-4h]

  v2 = this;
  v11 = this;
  v3 = this->lapFrameIndexCache._Myfirst;
  for ( i = this->lapFrameIndexCache._Mylast; v3 != i; ++v3 )
  {
    v5 = *v3;
    lapFrame = v5;
    if ( v5 == -1 )
      break;
    if ( (v2->frames._Myfirst[v5].status._Array[0] & 0x800) != 0 )
    {
      v6 = lapFramesArgument->_Mylast;
      if ( &lapFrame >= v6 || lapFramesArgument->_Myfirst > &lapFrame )
      {
        if ( v6 == lapFramesArgument->_Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)lapFramesArgument, 1u);
        v9 = lapFramesArgument->_Mylast;
        if ( v9 )
          *v9 = v5;
      }
      else
      {
        v7 = &lapFrame - lapFramesArgument->_Myfirst;
        if ( v6 == lapFramesArgument->_Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)lapFramesArgument, 1u);
        v8 = lapFramesArgument->_Mylast;
        if ( v8 )
          *v8 = lapFramesArgument->_Myfirst[v7];
      }
      ++lapFramesArgument->_Mylast;
    }
    v2 = v11;
  }
}
void ReplayRecorder::getPhysicsState(ReplayRecorder *this, CarPhysicsState *ps)
{
  int v3; // edx
  std::vector<ReplayFrameWingStatus> *v4; // eax
  unsigned int v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  unsigned __int8 v8; // cl
  float v9; // xmm0_4
  unsigned __int8 v10; // cl
  float v11; // xmm0_4
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // cl
  float v14; // xmm0_4
  unsigned int v15; // edx
  float v16; // xmm2_4
  float v17; // xmm0_4
  unsigned int v18; // edx
  unsigned int v19; // edx
  unsigned int v20; // edx
  int v21; // edi
  unsigned int v22; // esi
  vec3f *v23; // eax
  const __m128i *v24; // eax
  int v25; // esi
  __m128i *v26; // ecx
  int v27; // edi
  int v28; // eax
  AISpline *v29; // eax
  int v30; // eax
  __m128 *v31; // eax
  unsigned __int64 v32; // xmm0_8
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  float v37; // xmm4_4
  __m128 v38; // xmm6
  __m128 v39; // xmm5
  __m128 v40; // xmm3
  float v41; // xmm7_4
  __m128 v42; // xmm5
  float v43; // xmm7_4
  float v44; // xmm4_4
  __m128i v45; // xmm7
  __m128 v46; // xmm2
  __m128i v47; // xmm5
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  DynamicCarEffects *v50; // eax
  unsigned __int8 v51; // cl
  unsigned __int8 v52; // cl
  float v53; // xmm0_4
  float v54; // esi
  unsigned __int8 v55; // cl
  double v56; // xmm2_8
  float v57; // xmm0_4
  unsigned __int8 v58; // cl
  float v59; // xmm0_4
  unsigned __int8 v60; // cl
  int v61; // eax
  int v62; // esi
  vec3f *v63; // eax
  int v64; // eax
  AISpline *v65; // eax
  double v66; // st7
  bool v67; // zf
  double v68; // xmm0_8
  unsigned __int8 v69; // cl
  int v70; // esi
  float v71; // xmm1_4
  int v72; // eax
  int v73; // ecx
  float v74; // xmm0_4
  float v75; // xmm3_4
  unsigned __int8 v76; // cl
  int v77; // eax
  int v78; // ecx
  float v79; // xmm0_4
  unsigned int v80; // edx
  const __m128i *v81; // eax
  int v82; // ecx
  float v83; // xmm1_4
  unsigned int v84; // edx
  int v85; // ecx
  int v86; // eax
  int v87; // ecx
  float v88; // xmm0_4
  float v89; // xmm1_4
  unsigned int v90; // edx
  float v91; // xmm0_4
  float v92; // xmm1_4
  int v93; // ecx
  float v94; // xmm1_4
  unsigned int v95; // eax
  int v96; // eax
  int v97; // ecx
  float v98; // xmm2_4
  unsigned __int8 v99; // cl
  int v100; // eax
  int v101; // ecx
  float v102; // xmm2_4
  float v103; // xmm1_4
  float v104; // xmm2_4
  unsigned int v105; // edx
  const __m128i *v106; // eax
  int v107; // ecx
  float v108; // xmm2_4
  float v109; // xmm1_4
  float v110; // xmm0_4
  unsigned int v111; // edx
  int v112; // ecx
  int v113; // eax
  int v114; // ecx
  float v115; // xmm2_4
  unsigned int v116; // edx
  float v117; // xmm0_4
  float v118; // xmm1_4
  bool v119; // cc
  int v120; // edx
  int v121; // esi
  vec3f *v122; // eax
  vec3f *v123; // eax
  float v124; // esi
  unsigned int v125; // edx
  unsigned int v126; // edx
  float v127; // ecx
  float v128; // xmm0_4
  float v129; // ecx
  float v130; // xmm0_4
  unsigned int v131; // edx
  unsigned int v132; // edx
  unsigned int v133; // edx
  const __m128i *v134; // eax
  __m128i v135; // xmm0
  int v136; // eax
  int v137; // esi
  vec3f *v138; // eax
  vec3f *v139; // eax
  const __m128i *v140; // eax
  __m128i v141; // xmm0
  int v142; // eax
  int v143; // xmm2_4
  unsigned int v144; // xmm1_4
  int v145; // ecx
  __int64 v146; // xmm0_8
  float v147; // eax
  CarPhysicsState *v148; // esi
  int v149; // ecx
  __int64 v150; // xmm0_8
  float v151; // eax
  int v152; // ecx
  int v153; // eax
  float v154; // ecx
  float v155; // xmm0_4
  float v156; // xmm1_4
  float v157; // xmm6_4
  float v158; // xmm7_4
  float v159; // xmm4_4
  float v160; // xmm1_4
  float v161; // xmm0_4
  float v162; // xmm2_4
  float v163; // xmm3_4
  float v164; // xmm5_4
  float v165; // xmm7_4
  float v166; // xmm6_4
  float v167; // xmm1_4
  float v168; // xmm2_4
  float v169; // xmm0_4
  float v170; // xmm1_4
  int v171; // edx
  int v172; // edx
  int v173; // edx
  int v174; // edx
  int v175; // edx
  int v176; // edx
  int v177; // edx
  float ms; // [esp+0h] [ebp-264h]
  float v179; // [esp+18h] [ebp-24Ch]
  int v180; // [esp+18h] [ebp-24Ch]
  Speed result; // [esp+1Ch] [ebp-248h] BYREF
  int v182; // [esp+20h] [ebp-244h]
  float v183; // [esp+24h] [ebp-240h]
  float v184; // [esp+28h] [ebp-23Ch]
  float v185; // [esp+2Ch] [ebp-238h]
  int v186; // [esp+30h] [ebp-234h]
  int v187; // [esp+34h] [ebp-230h]
  CarPhysicsState *v188; // [esp+38h] [ebp-22Ch]
  __m128 v189; // [esp+3Ch] [ebp-228h] BYREF
  float v190; // [esp+50h] [ebp-214h]
  __m128 v191; // [esp+54h] [ebp-210h] BYREF
  __m128 v192; // [esp+64h] [ebp-200h] BYREF
  __m128 v193; // [esp+74h] [ebp-1F0h] BYREF
  mat44f m2; // [esp+84h] [ebp-1E0h] BYREF
  __m128 v195; // [esp+C4h] [ebp-1A0h] BYREF
  __m128 v196; // [esp+D4h] [ebp-190h] BYREF
  __m128 pDeterminant; // [esp+E4h] [ebp-180h] BYREF
  __m128 v198; // [esp+F4h] [ebp-170h]
  __m128 v199; // [esp+104h] [ebp-160h]
  mat44f v200; // [esp+11Ch] [ebp-148h] BYREF
  mat44f v201; // [esp+15Ch] [ebp-108h] BYREF
  mat44f m1; // [esp+19Ch] [ebp-C8h] BYREF
  mat44f v203; // [esp+1DCh] [ebp-88h] BYREF
  mat44f v204; // [esp+220h] [ebp-44h] BYREF

  v190 = *(float *)&this;
  v3 = (unsigned __int64)(2021161081i64 * (this->name._Myres - this->name._Mysize)) >> 32;
  v4 = this->frames_wings._Myfirst;
  ps->timeStamp = 0.0;
  ps->limiterRPM = 0;
  ps->statusBytes = 0;
  ps->clutch = 1.0;
  v188 = ps;
  v5 = ((unsigned int)&v4->_Myfirst + 1) % ((v3 >> 7) + ((unsigned int)v3 >> 31));
  ps->limiterRPM = (int)this->frames_wings._Myend;
  ps->isEngineLimiterOn = 0;
  v6 = 272 * (int)this->frames_wings._Myfirst;
  v7 = this->name._Mysize;
  v183 = *(float *)&v5;
  ps->gear = *(unsigned __int8 *)(v6 + v7 + 254);
  ps->lapCount = *(unsigned __int8 *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 266);
  ps->fuelLaps = (float)*(unsigned __int8 *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 253);
  ps->lastLap = *(_DWORD *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 244);
  ps->bestLap = *(_DWORD *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 248);
  v8 = *(_BYTE *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 264);
  if ( v8 < RANGE_UCHAR.min )
    v8 = RANGE_UCHAR.min;
  if ( v8 > RANGE_UCHAR.max )
    v8 = RANGE_UCHAR.max;
  v9 = ((double)v8 - RANGE_UCHAR.dMin)
     / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
     * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin)
     + RANGE_FLOAT_0_1.min;
  ps->gas = v9;
  v10 = *(_BYTE *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 265);
  if ( v10 < RANGE_UCHAR.min )
    v10 = RANGE_UCHAR.min;
  if ( v10 > RANGE_UCHAR.max )
    v10 = RANGE_UCHAR.max;
  v11 = ((double)v10 - RANGE_UCHAR.dMin)
      / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
      * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin)
      + RANGE_FLOAT_0_1.min;
  ps->brake = v11;
  v12 = *(_BYTE *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 252);
  if ( v12 < RANGE_UCHAR.min )
    v12 = RANGE_UCHAR.min;
  if ( v12 > RANGE_UCHAR.max )
    v12 = RANGE_UCHAR.max;
  ps->fuel = (float)(((double)v12 - RANGE_UCHAR.dMin)
                   / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                   * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin)
                   + RANGE_FLOAT_0_1.min)
           * (float)*(double *)(*(_DWORD *)&this->name._Bx._Alias[4] + 3504);
  v13 = *((_BYTE *)&this->parent->GameObject::__vftable + 4 * (int)this->frames_wings._Myfirst + 1);
  if ( v13 < RANGE_UCHAR.min )
    v13 = RANGE_UCHAR.min;
  if ( v13 > RANGE_UCHAR.max )
    v13 = RANGE_UCHAR.max;
  v14 = ((double)v13 - RANGE_UCHAR.dMin)
      / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
      * (RANGE_FLOAT_0_1000.dMax - RANGE_FLOAT_0_1000.dMin)
      + RANGE_FLOAT_0_1000.min;
  ps->engineLifeLeft = v14;
  v15 = *(unsigned __int16 *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 190);
  LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v15 >> 10]
                                + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v15 & 0x3FF)
                                                                                           + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v15 >> 10]]);
  ps->engineRPM = result.value;
  ps->velocity = *hTF3(
                    (vec3f *)&v189,
                    (half_float::half *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 184));
  v16 = (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
      + (float)(ps->velocity.z * ps->velocity.z);
  v17 = 0.0;
  if ( v16 != 0.0 )
    v17 = fsqrt(v16);
  ps->speed = LODWORD(Speed::fromMS(&result, v17)->value);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v18 = *(unsigned __int16 *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 232);
  LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v18 >> 10]
                                + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v18 & 0x3FF)
                                                                                           + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v18 >> 10]]);
  ps->steer = result.value;
  v19 = *(unsigned __int16 *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 234);
  LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v19 >> 10]
                                + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v19 & 0x3FF)
                                                                                           + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v19 >> 10]]);
  ps->bodyWorkVolume = result.value;
  v20 = *(unsigned __int16 *)(272 * (int)this->frames_wings._Myfirst + this->name._Mysize + 236);
  LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v20 >> 10]
                                + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v20 & 0x3FF)
                                                                                           + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v20 >> 10]]);
  ps->drivetrainSpeed = result.value;
  v21 = 272 * (int)this->frames_wings._Myfirst;
  v22 = this->name._Mysize;
  v23 = hTF3((vec3f *)&v189, (half_float::half *)(v21 + v22 + 32));
  v24 = (const __m128i *)mat44f::createFromEulerSafe(&v200, *v23, *(vec3f *)(v21 + v22 + 20));
  v25 = (int)v188;
  v26 = (__m128i *)&v188->worldMatrix;
  LODWORD(result.value) = (Speed)&v188->worldMatrix;
  *(__m128i *)&v188->worldMatrix.M11 = _mm_loadu_si128(v24);
  v26[1] = _mm_loadu_si128(v24 + 1);
  v27 = LODWORD(v190);
  v26[2] = _mm_loadu_si128(v24 + 2);
  v26[3] = _mm_loadu_si128(v24 + 3);
  v28 = *(_DWORD *)(v27 + 12);
  v192.m128_u64[0] = v26[3].m128i_u64[0];
  v192.m128_i32[2] = v26[3].m128i_i32[2];
  v29 = TrackAvatar::getAISpline(*(TrackAvatar **)(*(_DWORD *)(v28 + 172) + 180));
  *(float *)(v25 + 1768) = InterpolatingSpline::worldToSpline(&v29->spline, (const vec3f *)&v192, -1);
  v30 = *(_DWORD *)(v27 + 100);
  if ( v30 <= 0 )
  {
    v189.m128_u64[0] = 0i64;
    v31 = &v189;
    v189.m128_i32[2] = 0;
  }
  else
  {
    v31 = (__m128 *)hTF3((vec3f *)&v189, (half_float::half *)(272 * v30 + *(_DWORD *)(v27 + 24) - 88));
  }
  v32 = v31->m128_u64[0];
  v192.m128_i32[2] = v31->m128_i32[2];
  v192.m128_u64[0] = v32;
  if ( (dword_186E93C & 1) == 0 )
  {
    dword_186E93C |= 1u;
    denominator = ReplayRecorder::recordIntervalMS * 0.001;
  }
  LODWORD(m2.M44) = HIDWORD(*(unsigned __int128 *)&_mm_loadu_si128((const __m128i *)(LODWORD(result.value) + 48)));
  m2.M41 = 0.0;
  m2.M42 = 0.0;
  m2.M43 = 0.0;
  mat44f::mat44f(&v200);
  v33 = (__m128)_mm_loadu_si128((const __m128i *)(v25 + 20));
  v34 = (__m128)_mm_loadu_si128((const __m128i *)(v25 + 36));
  v35 = *(__m128 *)&m2.M41;
  v36 = DirectX::XMMatrixInverse(
          &pDeterminant,
          (__m128)_mm_loadu_si128((const __m128i *)(v25 + 4)),
          v33,
          v34,
          *(__m128 *)&m2.M41);
  v37 = v192.m128_f32[1];
  v38 = v35;
  v193 = v36;
  v39 = v34;
  v40 = v33;
  v33.m128_i32[0] = v192.m128_i32[0];
  v196 = v40;
  v34.m128_i32[0] = v192.m128_i32[2];
  v195 = v39;
  v41 = (float)((float)(v40.m128_f32[0] * v192.m128_f32[1]) + (float)(v36.m128_f32[0] * v192.m128_f32[0]))
      + (float)(v39.m128_f32[0] * v192.m128_f32[2]);
  v192 = _mm_shuffle_ps(v40, v40, 85);
  v189 = v38;
  result.value = v41 + v38.m128_f32[0];
  v191 = _mm_shuffle_ps(v193, v193, 85);
  v199 = _mm_shuffle_ps(v39, v39, 85);
  v198 = _mm_shuffle_ps(v38, v38, 85);
  v38.m128_f32[0] = _mm_shuffle_ps(v40, v40, 170).m128_f32[0];
  v42 = v36;
  v179 = (float)((float)((float)(v192.m128_f32[0] * v37) + (float)(v191.m128_f32[0] * v33.m128_f32[0]))
               + (float)(v199.m128_f32[0] * v34.m128_f32[0]))
       + v198.m128_f32[0];
  pDeterminant = _mm_shuffle_ps(v193, v193, 170);
  v43 = (float)(v38.m128_f32[0] * v37) + (float)(pDeterminant.m128_f32[0] * v33.m128_f32[0]);
  v44 = _mm_shuffle_ps(v195, v195, 170).m128_f32[0];
  v36.m128_f32[0] = v44 * v34.m128_f32[0];
  v34.m128_i32[0] = *(_DWORD *)(v25 + 632);
  v40.m128_f32[0] = _mm_shuffle_ps(v189, v189, 170).m128_f32[0];
  v184 = (float)(v43 + v36.m128_f32[0]) + v40.m128_f32[0];
  v36.m128_i32[0] = *(_DWORD *)(v25 + 628);
  v33.m128_i32[0] = *(_DWORD *)(v25 + 636);
  v38.m128_f32[0] = v38.m128_f32[0] * v34.m128_f32[0];
  v45 = (__m128i)v191;
  *(float *)v45.m128i_i32 = v191.m128_f32[0] * v36.m128_f32[0];
  v42.m128_f32[0] = (float)((float)((float)(v193.m128_f32[0] * v36.m128_f32[0])
                                  + (float)(v196.m128_f32[0] * v34.m128_f32[0]))
                          + (float)(v195.m128_f32[0] * v33.m128_f32[0]))
                  + v189.m128_f32[0];
  v191 = (__m128)v45;
  *(float *)v45.m128i_i32 = v192.m128_f32[0] * v34.m128_f32[0];
  v46 = (__m128)LODWORD(FLOAT_1_0);
  v46.m128_f32[0] = 1.0 / denominator;
  v193 = v42;
  v47 = (__m128i)v191;
  *(float *)v47.m128i_i32 = (float)(v191.m128_f32[0] + *(float *)v45.m128i_i32)
                          + (float)(v199.m128_f32[0] * v33.m128_f32[0]);
  v191 = (__m128)v47;
  *(float *)v45.m128i_i32 = *(float *)v47.m128i_i32 + v198.m128_f32[0];
  *(float *)v47.m128i_i32 = (float)((float)((float)(pDeterminant.m128_f32[0] * v36.m128_f32[0]) + v38.m128_f32[0])
                                  + (float)(v44 * v33.m128_f32[0]))
                          + v40.m128_f32[0];
  v48 = v46;
  v49 = v46;
  v48.m128_f32[0] = (float)((float)(1.0 / denominator) * (float)(result.value - v193.m128_f32[0])) * 0.10204081;
  v49.m128_f32[0] = (float)((float)(1.0 / denominator) * (float)(v179 - *(float *)v45.m128i_i32)) * 0.10204081;
  v46.m128_f32[0] = (float)((float)(1.0 / denominator) * (float)(v184 - *(float *)v47.m128i_i32)) * 0.10204081;
  *(_QWORD *)(v25 + 1560) = _mm_unpacklo_ps(v48, v49).m128_u64[0];
  v189.m128_i32[2] = v46.m128_i32[0];
  *(_DWORD *)(v25 + 1568) = v46.m128_i32[0];
  *(_DWORD *)(v25 + 1568) ^= _xmm;
  *(_DWORD *)(v25 + 1560) ^= _xmm;
  if ( *(_DWORD *)(v27 + 16)
    || (v50 = GameObject::getGameObject<DynamicCarEffects>(*(GameObject **)(v27 + 12)),
        (*(_DWORD *)(v27 + 16) = v50) != 0) )
  {
    v51 = *(_BYTE *)(*(_DWORD *)(v27 + 36) + 4 * *(_DWORD *)(v27 + 100));
    if ( v51 < RANGE_UCHAR.min )
      v51 = RANGE_UCHAR.min;
    if ( v51 > RANGE_UCHAR.max )
      v51 = RANGE_UCHAR.max;
    ms = ((double)v51 - RANGE_UCHAR.dMin)
       / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
       * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin)
       + RANGE_FLOAT_0_1.min;
    DynamicCarEffects::setDirtLevel(*(DynamicCarEffects **)(v27 + 16), ms);
  }
  if ( *(int *)(v27 + 60) < 7 )
  {
    *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v27 + 12) + 348) + 184) = 1;
    v58 = *(_BYTE *)(*(_DWORD *)(v27 + 36) + 4 * *(_DWORD *)(v27 + 100) + 2);
    if ( v58 < RANGE_UCHAR.min )
      v58 = RANGE_UCHAR.min;
    if ( v58 > RANGE_UCHAR.max )
      v58 = RANGE_UCHAR.max;
    v59 = ((double)v58 - RANGE_UCHAR.dMin)
        / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
        * (RANGE_FLOAT_0_05.dMax - RANGE_FLOAT_0_05.dMin)
        + RANGE_FLOAT_0_05.min;
    *(float *)(v25 + 1796) = v59;
    v54 = v183;
    v60 = *(_BYTE *)(*(_DWORD *)(v27 + 36) + 4 * LODWORD(v183) + 2);
    if ( v60 < RANGE_UCHAR.min )
      v60 = RANGE_UCHAR.min;
    if ( v60 > RANGE_UCHAR.max )
      v60 = RANGE_UCHAR.max;
    v56 = ((double)v60 - RANGE_UCHAR.dMin)
        / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
        * (RANGE_FLOAT_0_05.dMax - RANGE_FLOAT_0_05.dMin);
    v57 = RANGE_FLOAT_0_05.min;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v27 + 12) + 348) + 184) = *(_BYTE *)(*(_DWORD *)(v27 + 36)
                                                                          + 4 * *(_DWORD *)(v27 + 100)
                                                                          + 3) != 0;
    v52 = *(_BYTE *)(*(_DWORD *)(v27 + 36) + 4 * *(_DWORD *)(v27 + 100) + 2);
    if ( v52 < RANGE_UCHAR.min )
      v52 = RANGE_UCHAR.min;
    if ( v52 > RANGE_UCHAR.max )
      v52 = RANGE_UCHAR.max;
    v53 = ((double)v52 - RANGE_UCHAR.dMin)
        / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
        * (RANGE_FLOAT_0_5.dMax - RANGE_FLOAT_0_5.dMin)
        + RANGE_FLOAT_0_5.min;
    *(float *)(v25 + 1796) = v53;
    v54 = v183;
    v55 = *(_BYTE *)(*(_DWORD *)(v27 + 36) + 4 * LODWORD(v183) + 2);
    if ( v55 < RANGE_UCHAR.min )
      v55 = RANGE_UCHAR.min;
    if ( v55 > RANGE_UCHAR.max )
      v55 = RANGE_UCHAR.max;
    v56 = ((double)v55 - RANGE_UCHAR.dMin)
        / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
        * (RANGE_FLOAT_0_5.dMax - RANGE_FLOAT_0_5.dMin);
    v57 = RANGE_FLOAT_0_5.min;
  }
  v61 = 272 * LODWORD(v54);
  v62 = *(_DWORD *)(v27 + 24);
  v182 = v61;
  v185 = v56 + v57;
  v63 = hTF3((vec3f *)&v189, (half_float::half *)(v62 + v61 + 32));
  mat44f::createFromEulerSafe(&m2, *v63, *(vec3f *)(v182 + v62 + 20));
  v64 = *(_DWORD *)(v27 + 12);
  v189.m128_u64[0] = *(_QWORD *)&m2.M41;
  v189.m128_i32[2] = LODWORD(m2.M43);
  v65 = TrackAvatar::getAISpline(*(TrackAvatar **)(*(_DWORD *)(v64 + 172) + 180));
  v66 = InterpolatingSpline::worldToSpline(&v65->spline, (const vec3f *)&v189, -1);
  v67 = *(_BYTE *)(v27 + 8) == 0;
  v68 = RANGE_UCHAR.dMax - RANGE_UCHAR.dMin;
  v69 = *(_BYTE *)(v182 + *(_DWORD *)(v27 + 24) + 265);
  v70 = (int)v188;
  v183 = v66;
  if ( v67 )
  {
    if ( v69 < RANGE_UCHAR.min )
      v69 = RANGE_UCHAR.min;
    if ( v69 > RANGE_UCHAR.max )
      v69 = RANGE_UCHAR.max;
    v71 = v188->drivetrainSpeed;
    v72 = v69;
    v73 = v182;
    v74 = ((double)v72 - RANGE_UCHAR.dMin) / v68 * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin) + RANGE_FLOAT_0_1.min;
    v75 = v188->gas;
    v188->brake = (float)((float)(v74 - v188->brake) * *(float *)(v27 + 4)) + v188->brake;
    v76 = *(_BYTE *)(v73 + *(_DWORD *)(v27 + 24) + 264);
    if ( v76 < RANGE_UCHAR.min )
      v76 = RANGE_UCHAR.min;
    if ( v76 > RANGE_UCHAR.max )
      v76 = RANGE_UCHAR.max;
    v77 = v76;
    v78 = v182;
    v79 = ((double)v77 - RANGE_UCHAR.dMin)
        / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
        * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin)
        + RANGE_FLOAT_0_1.min;
    *(float *)(v70 + 608) = (float)((float)(v79 - v75) * *(float *)(v27 + 4)) + v75;
    v80 = *(unsigned __int16 *)(v78 + *(_DWORD *)(v27 + 24) + 236);
    LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v80 >> 10]
                                  + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v80 & 0x3FF)
                                                                                             + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v80 >> 10]]);
    *(float *)(v70 + 1792) = (float)((float)(result.value - v71) * *(float *)(v27 + 4)) + v71;
    v81 = (const __m128i *)lerp(&v200, (mat44f *)(v70 + 4), &m2, *(float *)(v27 + 4));
    v82 = v182;
    v83 = *(float *)(v70 + 604);
    *(__m128i *)(v70 + 4) = _mm_loadu_si128(v81);
    *(__m128i *)(v70 + 20) = _mm_loadu_si128(v81 + 1);
    *(__m128i *)(v70 + 36) = _mm_loadu_si128(v81 + 2);
    *(__m128i *)(v70 + 52) = _mm_loadu_si128(v81 + 3);
    v84 = *(unsigned __int16 *)(v82 + *(_DWORD *)(v27 + 24) + 232);
    v85 = v84 & 0x3FF;
    v84 >>= 10;
    v86 = v85 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v84];
    v87 = v182;
    LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v84]
                                  + `half_float::detail::half2float_impl'::`2'::mantissa_table[v86]);
    v88 = (float)((float)(result.value - v83) * *(float *)(v27 + 4)) + v83;
    v89 = *(float *)(v70 + 580);
    *(float *)(v70 + 604) = v88;
    v90 = *(unsigned __int16 *)(v87 + *(_DWORD *)(v27 + 24) + 190);
    LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v90 >> 10]
                                  + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v90 & 0x3FF)
                                                                                             + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v90 >> 10]]);
    v91 = (float)((float)(result.value - v89) * *(float *)(v27 + 4)) + v89;
    v92 = *(float *)(v70 + 1768);
    *(float *)(v70 + 580) = v91;
    if ( v183 > v92 )
      *(float *)(v70 + 1768) = (float)((float)(v183 - v92) * *(float *)(v27 + 4)) + v92;
    *(float *)(v70 + 1796) = (float)((float)(v185 - *(float *)(v70 + 1796)) * *(float *)(v27 + 4))
                           + *(float *)(v70 + 1796);
    v93 = *(_DWORD *)(v27 + 24);
    v94 = (float)*(unsigned int *)(272 * *(_DWORD *)(v27 + 100) + v93 + 240);
    v95 = (unsigned int)(float)((float)((float)((float)*(unsigned int *)(v93 + v182 + 240) - v94) * *(float *)(v27 + 4))
                              + v94);
  }
  else
  {
    if ( v69 < RANGE_UCHAR.min )
      v69 = RANGE_UCHAR.min;
    if ( v69 > RANGE_UCHAR.max )
      v69 = RANGE_UCHAR.max;
    v96 = v69;
    v97 = v182;
    v98 = ((double)v96 - RANGE_UCHAR.dMin) / v68 * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin) + RANGE_FLOAT_0_1.min;
    v188->brake = (float)((float)(v188->brake - v98) * (float)(1.0 - *(float *)(v27 + 4))) + v98;
    v99 = *(_BYTE *)(v97 + *(_DWORD *)(v27 + 24) + 264);
    if ( v99 < RANGE_UCHAR.min )
      v99 = RANGE_UCHAR.min;
    if ( v99 > RANGE_UCHAR.max )
      v99 = RANGE_UCHAR.max;
    v100 = v99;
    v101 = v182;
    v102 = ((double)v100 - RANGE_UCHAR.dMin)
         / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
         * (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin)
         + RANGE_FLOAT_0_1.min;
    v103 = (float)((float)(*(float *)(v70 + 608) - v102) * (float)(1.0 - *(float *)(v27 + 4))) + v102;
    v104 = *(float *)(v70 + 1792);
    *(float *)(v70 + 608) = v103;
    v105 = *(unsigned __int16 *)(v101 + *(_DWORD *)(v27 + 24) + 236);
    LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v105 >> 10]
                                  + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v105 & 0x3FF)
                                                                                             + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v105 >> 10]]);
    *(float *)(v70 + 1792) = (float)((float)(v104 - result.value) * (float)(1.0 - *(float *)(v27 + 4))) + result.value;
    v106 = (const __m128i *)lerp(&v200, &m2, (mat44f *)(v70 + 4), 1.0 - *(float *)(v27 + 4));
    v107 = v182;
    v108 = *(float *)(v70 + 604);
    v109 = *(float *)(v70 + 580);
    *(__m128i *)(v70 + 4) = _mm_loadu_si128(v106);
    *(__m128i *)(v70 + 20) = _mm_loadu_si128(v106 + 1);
    *(__m128i *)(v70 + 36) = _mm_loadu_si128(v106 + 2);
    *(__m128i *)(v70 + 52) = _mm_loadu_si128(v106 + 3);
    v110 = 1.0 - *(float *)(v27 + 4);
    v111 = *(unsigned __int16 *)(v107 + *(_DWORD *)(v27 + 24) + 232);
    v112 = v111 & 0x3FF;
    v111 >>= 10;
    v113 = v112 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v111];
    v114 = v182;
    LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v111]
                                  + `half_float::detail::half2float_impl'::`2'::mantissa_table[v113]);
    *(float *)(v70 + 604) = (float)((float)(v108 - result.value) * v110) + result.value;
    v115 = v183;
    v116 = *(unsigned __int16 *)(v114 + *(_DWORD *)(v27 + 24) + 190);
    LODWORD(result.value) = (Speed)(`half_float::detail::half2float_impl'::`2'::exponent_table[v116 >> 10]
                                  + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v116 & 0x3FF)
                                                                                             + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v116 >> 10]]);
    v117 = (float)((float)(result.value - v109) * *(float *)(v27 + 4)) + v109;
    v118 = *(float *)(v70 + 1768);
    v119 = v183 <= v118;
    *(float *)(v70 + 580) = v117;
    if ( !v119 )
      *(float *)(v70 + 1768) = (float)((float)(v118 - v115) * (float)(1.0 - *(float *)(v27 + 4))) + v115;
    *(float *)(v70 + 1796) = (float)((float)(*(float *)(v70 + 1796) - v185) * (float)(1.0 - *(float *)(v27 + 4))) + v185;
    v95 = *(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 240);
  }
  *(_DWORD *)(v70 + 1572) = v95;
  v120 = 0;
  v186 = 0;
  LODWORD(v183) = v70 + 804;
  v185 = 0.0;
  LODWORD(result.value) = (Speed)(v70 + 708);
  v187 = 0;
  v180 = v70 + 376;
  do
  {
    v121 = 272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24);
    v122 = hTF3((vec3f *)&v195, (half_float::half *)(v121 + v120 + 88));
    mat44f::createFromEulerSafe(&m1, *v122, *(vec3f *)(v121 + v187 + 40));
    v123 = hTF3((vec3f *)&v196, (half_float::half *)(v182 + 88 + *(_DWORD *)(v27 + 24) + LODWORD(v185)));
    mat44f::createFromEulerSafe(&v201, *v123, *(vec3f *)(*(_DWORD *)(v27 + 24) + v187 + v182 + 40));
    v124 = result.value;
    v125 = *(unsigned __int16 *)(*(_DWORD *)(v27 + 24) + 2 * (v186 + 136 * *(_DWORD *)(v27 + 100)) + 192);
    *(_DWORD *)(LODWORD(result.value) - 120) = `half_float::detail::half2float_impl'::`2'::exponent_table[v125 >> 10]
                                             + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v125 & 0x3FF) + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v125 >> 10]];
    v126 = *(unsigned __int16 *)(*(_DWORD *)(v27 + 24) + 2 * (v186 + 136 * *(_DWORD *)(v27 + 100)) + 200);
    *(_DWORD *)LODWORD(v124) = `half_float::detail::half2float_impl'::`2'::exponent_table[v126 >> 10]
                             + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v126 & 0x3FF)
                                                                                        + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v126 >> 10]];
    LODWORD(v184) = *(unsigned __int8 *)(v186 + 272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 255);
    v127 = v184;
    if ( LOBYTE(v184) < RANGE_UCHAR.min )
      LODWORD(v127) = RANGE_UCHAR.min;
    v184 = v127;
    if ( LOBYTE(v127) > RANGE_UCHAR.max )
      LOBYTE(v127) = RANGE_UCHAR.max;
    v128 = ((double)LOBYTE(v127) - RANGE_UCHAR.dMin)
         / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
         * (RANGE_FLOAT_0_20.dMax - RANGE_FLOAT_0_20.dMin)
         + RANGE_FLOAT_0_20.min;
    *(float *)(LODWORD(v124) + 80) = v128;
    LODWORD(v184) = *(unsigned __int8 *)(v186 + 272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 259);
    v129 = v184;
    if ( LOBYTE(v184) < RANGE_UCHAR.min )
      LODWORD(v129) = RANGE_UCHAR.min;
    v184 = v129;
    if ( LOBYTE(v129) > RANGE_UCHAR.max )
      LOBYTE(v129) = RANGE_UCHAR.max;
    v130 = ((double)LOBYTE(v129) - RANGE_UCHAR.dMin)
         / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
         * (RANGE_FLOAT_0_255.dMax - RANGE_FLOAT_0_255.dMin)
         + RANGE_FLOAT_0_255.min;
    *(float *)(LODWORD(v124) + 1124) = v130;
    v131 = *(unsigned __int16 *)(*(_DWORD *)(v27 + 24) + 2 * (v186 + 136 * *(_DWORD *)(v27 + 100)) + 216);
    *(_DWORD *)(LODWORD(v124) + 16) = `half_float::detail::half2float_impl'::`2'::exponent_table[v131 >> 10]
                                    + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v131 & 0x3FF)
                                                                                               + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v131 >> 10]];
    v132 = *(unsigned __int16 *)(*(_DWORD *)(v27 + 24) + 2 * (v186 + 136 * *(_DWORD *)(v27 + 100)) + 224);
    *(_DWORD *)(LODWORD(v124) + 32) = `half_float::detail::half2float_impl'::`2'::exponent_table[v132 >> 10]
                                    + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v132 & 0x3FF)
                                                                                               + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v132 >> 10]];
    v133 = *(unsigned __int16 *)(*(_DWORD *)(v27 + 24) + 2 * (v186 + 136 * *(_DWORD *)(v27 + 100)) + 208);
    *(_DWORD *)(LODWORD(v124) - 16) = `half_float::detail::half2float_impl'::`2'::exponent_table[v133 >> 10]
                                    + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v133 & 0x3FF)
                                                                                               + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v133 >> 10]];
    *(_DWORD *)(LODWORD(v124) + 1248) = 1065353216;
    v134 = (const __m128i *)lerp(&v204, &m1, &v201, *(float *)(v27 + 4));
    *(__m128i *)(v180 - 308) = _mm_loadu_si128(v134);
    *(__m128i *)(v180 - 292) = _mm_loadu_si128(v134 + 1);
    *(__m128i *)(v180 - 276) = _mm_loadu_si128(v134 + 2);
    v135 = _mm_loadu_si128(v134 + 3);
    v136 = LODWORD(v185) + 160;
    *(__m128i *)(v180 - 260) = v135;
    v137 = *(_DWORD *)(v27 + 24) + 272 * *(_DWORD *)(v27 + 100);
    v138 = hTF3((vec3f *)&v193, (half_float::half *)(v137 + v136));
    mat44f::createFromEulerSafe(&v200, *v138, *(vec3f *)(v137 + v187 + 112));
    v139 = hTF3((vec3f *)&v191, (half_float::half *)(v182 + 160 + *(_DWORD *)(v27 + 24) + LODWORD(v185)));
    mat44f::createFromEulerSafe(&v203, *v139, *(vec3f *)(*(_DWORD *)(v27 + 24) + v187 + v182 + 112));
    v140 = (const __m128i *)lerp(&v204, &v200, &v203, *(float *)(v27 + 4));
    *(__m128i *)(v180 - 52) = _mm_loadu_si128(v140);
    *(__m128i *)(v180 - 36) = _mm_loadu_si128(v140 + 1);
    *(__m128i *)(v180 - 20) = _mm_loadu_si128(v140 + 2);
    v141 = _mm_loadu_si128(v140 + 3);
    m2.M22 = 0.0;
    m2.M23 = 0.0;
    *(__m128i *)(v180 - 4) = v141;
    v142 = *(_DWORD *)(v27 + 12);
    v143 = *(_DWORD *)(v180 + 4);
    *(float *)&v144 = *(float *)v180 + 1.0;
    *(_OWORD *)&m2.M12 = 0i64;
    m2.M11 = 0.0;
    v141.m128i_i32[0] = *(_DWORD *)(v180 - 4);
    LOBYTE(m2.M24) = 0;
    m2.M31 = 0.0;
    v145 = *(_DWORD *)(*(_DWORD *)(v142 + 172) + 180) + 168;
    v189.m128_u64[0] = 0xBF80000000000000ui64;
    v189.m128_i32[2] = 0;
    v192.m128_u64[0] = __PAIR64__(v144, v141.m128i_u32[0]);
    v192.m128_i32[2] = v143;
    (*(void (**)(int, __m128 *, __m128 *, mat44f *, int))(*(_DWORD *)v145 + 4))(
      v145,
      &v192,
      &v189,
      &m2,
      1084227584);
    if ( LOBYTE(m2.M24) && LODWORD(m2.M11) )
    {
      v146 = *(_QWORD *)&m2.M21;
      v147 = m2.M23;
      qmemcpy((void *)LODWORD(v183), (const void *)LODWORD(m2.M11), 0xBCu);
      v148 = v188;
      v149 = v187;
      v27 = LODWORD(v190);
      *(_QWORD *)((char *)&v188->tyreContactNormal[0].x + v187) = v146;
      v150 = *(_QWORD *)&m2.M12;
      *(float *)((char *)&v148->tyreContactNormal[0].z + v149) = v147;
      v151 = m2.M14;
      *(_QWORD *)((char *)&v148->tyreContactPoint[0].x + v149) = v150;
      *(float *)((char *)&v148->tyreContactPoint[0].z + v149) = v151;
    }
    else
    {
      v149 = v187;
      v148 = v188;
    }
    ++v186;
    v120 = LODWORD(v185) + 6;
    LODWORD(result.value) += 4;
    v180 += 64;
    LODWORD(v183) += 188;
    v187 = v149 + 12;
    LODWORD(v185) += 6;
  }
  while ( v149 + 12 < 48 );
  v152 = 272 * *(_DWORD *)(v27 + 100);
  v153 = *(_DWORD *)(v27 + 24);
  v191.m128_u64[0] = 0i64;
  v191.m128_i32[2] = 0;
  LODWORD(v183) = *(unsigned __int8 *)(v152 + v153 + 263);
  v154 = v183;
  if ( LOBYTE(v183) < RANGE_UCHAR.min )
    LODWORD(v154) = RANGE_UCHAR.min;
  v183 = v154;
  if ( LOBYTE(v154) > RANGE_UCHAR.max )
    LOBYTE(v154) = RANGE_UCHAR.max;
  v155 = ((double)LOBYTE(v154) - RANGE_UCHAR.dMin)
       / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
       * (RANGE_FLOAT_0_255.dMax - RANGE_FLOAT_0_255.dMin)
       + RANGE_FLOAT_0_255.min;
  v148->damageZoneLevel[4] = v155;
  v156 = v148->tyreContactPoint[0].y;
  v157 = v148->tyreContactPoint[2].y - v156;
  v158 = v148->tyreContactPoint[0].z;
  v159 = v148->tyreContactPoint[1].y - v156;
  v160 = v148->tyreContactPoint[2].z - v158;
  v161 = v148->tyreContactPoint[0].x;
  v162 = v148->tyreContactPoint[1].z - v158;
  v163 = v148->tyreContactPoint[2].x - v161;
  v164 = v148->tyreContactPoint[1].x - v161;
  v183 = v158;
  v165 = (float)(v160 * v159) - (float)(v157 * v162);
  v166 = (float)(v157 * v164) - (float)(v163 * v159);
  v190 = (float)(v163 * v162) - (float)(v160 * v164);
  v167 = (float)((float)(v190 * v190) + (float)(v165 * v165)) + (float)(v166 * v166);
  if ( v167 <= 0.0 )
  {
    v191.m128_i32[3] = 0;
  }
  else
  {
    v168 = 1.0 / fsqrt(v167);
    v191.m128_f32[1] = v168 * v190;
    v169 = (float)(v168 * v190) * v148->tyreContactPoint[0].y;
    v191.m128_f32[0] = v168 * v165;
    v170 = (float)(v168 * v165) * v148->tyreContactPoint[0].x;
    v191.m128_f32[2] = v168 * v166;
    v191.m128_i32[3] = COERCE_UNSIGNED_INT((float)(v169 + v170) + (float)((float)(v168 * v166) * v183)) ^ _xmm;
  }
  v148->groundPlane = (plane4f)_mm_loadu_si128((const __m128i *)&v191);
  v148->isGearGrinding = (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x200) != 0;
  v148->isDriftValid = (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x400) == 0;
  v171 = *(_DWORD *)(v27 + 12);
  if ( (*(_BYTE *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 1) != 0 )
    *(_DWORD *)(v171 + 2380) |= 0x100000u;
  else
    *(_DWORD *)(v171 + 2380) &= 0xFFEFFFFF;
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 2) != 0 )
    v148->statusBytes |= 4u;
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 4) != 0 )
    v148->statusBytes |= 1u;
  v172 = *(_DWORD *)(v27 + 12);
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 8) != 0 )
    *(_DWORD *)(v172 + 2380) |= 0x40u;
  else
    *(_DWORD *)(v172 + 2380) &= 0xFFFFFFBF;
  v173 = *(_DWORD *)(v27 + 12);
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x10) != 0 )
    *(_DWORD *)(v173 + 2380) |= 1u;
  else
    *(_DWORD *)(v173 + 2380) &= 0xFFFFFFFE;
  v174 = *(_DWORD *)(v27 + 12);
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x20) != 0 )
    *(_DWORD *)(v174 + 2380) |= 2u;
  else
    *(_DWORD *)(v174 + 2380) &= 0xFFFFFFFD;
  v175 = *(_DWORD *)(v27 + 12);
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x40) != 0 )
    *(_DWORD *)(v175 + 2380) |= 0x100u;
  else
    *(_DWORD *)(v175 + 2380) &= 0xFFFFFEFF;
  v176 = *(_DWORD *)(v27 + 12);
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x80) != 0 )
    *(_DWORD *)(v176 + 2380) |= 0x80u;
  else
    *(_DWORD *)(v176 + 2380) &= 0xFFFFFF7F;
  v177 = *(_DWORD *)(v27 + 12);
  if ( (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x1000) != 0 )
    *(_DWORD *)(v177 + 2380) |= 0x400u;
  else
    *(_DWORD *)(v177 + 2380) &= 0xFFFFFBFF;
  v148->kersIsCharging = (*(_DWORD *)(272 * *(_DWORD *)(v27 + 100) + *(_DWORD *)(v27 + 24) + 268) & 0x2000) != 0;
}
void ReplayRecorder::getWingState(ReplayRecorder *this, std::vector<WingState> *wingStatuses)
{
  std::vector<ReplayFrameWingStatus> *v3; // eax
  GameObject **v4; // ebx
  unsigned int v5; // ebx
  std::vector<ReplayFrameWingStatus> *v6; // esi
  GameObject **v7; // ebp
  unsigned int v8; // edx
  GameObject **v9; // ecx
  int v10; // esi
  GameObject *v11; // eax
  double v12; // xmm5_8
  double v13; // xmm4_8
  unsigned __int8 v14; // dl
  unsigned __int8 v15; // cl
  GameObject *v16; // eax
  float v17; // xmm3_4
  float v18; // xmm2_4
  unsigned __int8 v19; // dl
  unsigned __int8 v20; // cl
  float v21; // eax
  WingState *v22; // ecx
  int v23; // ecx
  int v24; // eax
  int v25; // [esp+8h] [ebp-48h]
  WingState ws; // [esp+Ch] [ebp-44h] BYREF

  if ( this->gameObjects._Myend != (GameObject **)this->ICarPhysicsStateProvider::__vftable )
  {
    v3 = this->frames_wings._Myfirst;
    v4 = this->gameObjects._Myend;
    if ( wingStatuses->_Mylast - wingStatuses->_Myfirst != ((char *)v4[3 * (_DWORD)v3 + 1] - (char *)v4[3 * (_DWORD)v3]) >> 2 )
      std::vector<WingState>::resize(wingStatuses, ((char *)v4[3 * (_DWORD)v3 + 1] - (char *)v4[3 * (_DWORD)v3]) >> 2);
    v5 = 0;
    v6 = this->frames_wings._Myfirst;
    v7 = this->gameObjects._Myend;
    v8 = ((unsigned int)&v6->_Myfirst + 1) % (((char *)this->ICarPhysicsStateProvider::__vftable - (char *)v7) / 12);
    v9 = &v7[3 * (_DWORD)v6];
    if ( ((char *)v9[1] - (char *)*v9) >> 2 )
    {
      v10 = 0;
      v25 = 3 * v8;
      do
      {
        v11 = *v9;
        v12 = RANGE_FLOAT_0_100.dMax - RANGE_FLOAT_0_100.dMin;
        ws.aoa = 0.0;
        v13 = 1.0 / (RANGE_UCHAR.dMax - RANGE_UCHAR.dMin);
        v14 = *((_BYTE *)&v11->__vftable + 4 * v5);
        if ( v14 < RANGE_UCHAR.min )
          v14 = RANGE_UCHAR.min;
        v15 = v14;
        if ( v14 > RANGE_UCHAR.max )
          v15 = RANGE_UCHAR.max;
        ws.cd = 0.0;
        ws.cl = 0.0;
        ws.yawAngle = 0.0;
        ws.isVertical = 0;
        ws.liftVector.x = 0.0;
        ws.liftVector.y = 0.0;
        ws.liftVector.z = 0.0;
        v16 = v7[v25];
        v17 = ((double)v15 - RANGE_UCHAR.dMin) * v13 * v12 + RANGE_FLOAT_0_100.min;
        ws.angle = v17;
        if ( v16 != v7[v25 + 1] )
        {
          v18 = *(float *)&this->game;
          if ( this->name._Bx._Alias[0] )
            v18 = 1.0 - v18;
          v19 = *((_BYTE *)&v16->__vftable + 4 * v5);
          if ( v19 < RANGE_UCHAR.min )
            v19 = RANGE_UCHAR.min;
          v20 = v19;
          if ( v19 > RANGE_UCHAR.max )
            v20 = RANGE_UCHAR.max;
          ws.angle = (float)((float)((float)(((double)v20 - RANGE_UCHAR.dMin) * v13 * v12 + RANGE_FLOAT_0_100.min) - v17)
                           * v18)
                   + v17;
        }
        ++v5;
        v21 = ws.liftVector.z;
        v22 = &wingStatuses->_Myfirst[v10++];
        *(__m128i *)&v22->aoa = _mm_loadu_si128((const __m128i *)&ws);
        *(_OWORD *)&v22->inputAngle = 0i64;
        *(_OWORD *)&v22->liftKG = _xmm;
        *(__m128i *)&v22->yawAngle = _mm_loadu_si128((const __m128i *)&ws.yawAngle);
        v22->liftVector.z = v21;
        v7 = this->gameObjects._Myend;
        v23 = 3 * (int)this->frames_wings._Myfirst;
        v24 = (char *)v7[v23 + 1] - (char *)v7[v23];
        v9 = &v7[v23];
      }
      while ( v5 < v24 >> 2 );
    }
  }
}
unsigned int ReplayRecorder::load(ReplayRecorder *this, std::ifstream *in, int aVersion)
{
  std::wstring *v4; // eax
  ReplayRecorderMetaData *v5; // edi
  unsigned int v6; // esi
  CarAvatar *v7; // eax
  unsigned int v8; // edi
  int v9; // esi
  unsigned int v10; // esi
  ReplayRecorderMetaData *v11; // edi
  int v12; // eax
  unsigned int v13; // esi
  unsigned int *v14; // ecx
  std::vector<unsigned int> *v15; // edi
  unsigned int *v16; // edx
  int v17; // esi
  int v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // edx
  unsigned int *v21; // ecx
  unsigned int *v22; // edx
  int v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // edx
  unsigned int *v26; // eax
  unsigned int v27; // esi
  unsigned int v28; // edi
  bool v29; // cc
  unsigned int v30; // esi
  unsigned int i; // [esp+4Ch] [ebp-268h] BYREF
  ReplayFrameWingStatusV5 oldWs; // [esp+50h] [ebp-264h] BYREF
  ReplayFrameAdditionalInfo additionalInfo; // [esp+54h] [ebp-260h] BYREF
  ReplayFrameWingStatus v35; // [esp+58h] [ebp-25Ch] BYREF
  std::vector<WingState> ws; // [esp+60h] [ebp-254h] BYREF
  std::wstring v37; // [esp+6Ch] [ebp-248h] BYREF
  ReplayFrame rf; // [esp+84h] [ebp-230h] BYREF
  ReplayFrameV15 rf15; // [esp+194h] [ebp-120h] BYREF
  int v40; // [esp+2B0h] [ebp-4h]

  this->version = aVersion;
  _printf("Loading replay version: %d\n", aVersion);
  if ( this->version < 15 )
  {
    v37._Myres = 7;
    v37._Mysize = 0;
    v37._Bx._Buf[0] = 0;
    std::wstring::assign(&v37, L"Loading replay with version <15 is no longer supported\n", 0x37u);
    v4 = &v37;
    v40 = 0;
    if ( v37._Myres >= 8 )
      v4 = (std::wstring *)v37._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v4->_Bx._Buf);
    ksGenerateCrash();
    v40 = -1;
    if ( v37._Myres >= 8 )
      operator delete(v37._Bx._Ptr);
  }
  v5 = &this->metaData;
  std::istream::read(in, &this->metaData);
  v6 = this->metaData.frameCount;
  this->recordedFrames = v6;
  if ( v6 != this->frames._Mylast - this->frames._Myfirst )
  {
    std::vector<ReplayFrame>::resize(&this->frames, v6);
    std::vector<std::vector<LeaderboardEntry>>::resize(
      (std::vector<std::vector<WingState>> *)&this->frames_wings,
      v5->frameCount);
    std::vector<ReplayFrameAdditionalInfo>::resize(&this->framesAdditionalInfo, v5->frameCount);
  }
  std::_Container_base0::_Orphan_all(&this->lapFrameIndexCache);
  this->lapFrameIndexCache._Mylast = this->lapFrameIndexCache._Myfirst;
  ws._Myfirst = 0;
  ws._Mylast = 0;
  ws._Myend = 0;
  v7 = this->avatar;
  v40 = 1;
  v7->physicsStateProvider->getWingState(v7->physicsStateProvider, &ws);
  v8 = 0;
  if ( this->frames_wings._Mylast - this->frames_wings._Myfirst )
  {
    v9 = 0;
    do
    {
      std::vector<ReplayFrameWingStatus>::resize(&this->frames_wings._Myfirst[v9], ws._Mylast - ws._Myfirst);
      ++v8;
      ++v9;
    }
    while ( v8 < this->frames_wings._Mylast - this->frames_wings._Myfirst );
  }
  v10 = 0;
  v11 = &this->metaData;
  for ( i = 0; v10 < this->metaData.frameCount; i = v10 )
  {
    ReplayFrame::ReplayFrame(&rf);
    if ( this->version < 16 )
    {
      ReplayFrameV15::ReplayFrameV15(&rf15);
      std::istream::read(in, &rf15);
      convertReplayFormat(&rf, &rf15);
    }
    else
    {
      std::istream::read(in, &rf);
    }
    qmemcpy(&this->frames._Myfirst[v10], &rf, sizeof(this->frames._Myfirst[v10]));
    v12 = this->version;
    if ( v12 < 6 )
    {
      *(_QWORD *)v37._Bx._Buf = 0x447A000000000000i64;
      *(_DWORD *)&v37._Bx._Alias[8] = 0;
      if ( v12 >= 2 )
        std::istream::read(in, &v37);
      if ( this->version >= 3 )
        std::istream::read(in, &v37._Bx._Alias[4]);
      if ( this->version >= 5 )
        std::istream::read(in, &v37._Bx._Alias[8]);
      v13 = i;
      this->framesAdditionalInfo._Myfirst[i].carDirt = 0;
      this->framesAdditionalInfo._Myfirst[v13].engineLife = -24;
      this->framesAdditionalInfo._Myfirst[v13].turboBoost = 0;
    }
    else
    {
      additionalInfo = (ReplayFrameAdditionalInfo)65280;
      std::istream::read(in, &additionalInfo);
      v13 = i;
      this->framesAdditionalInfo._Myfirst[i] = additionalInfo;
    }
    if ( (rf.status._Array[0] & 0x800) != 0 )
    {
      v14 = this->lapFrameIndexCache._Mylast;
      v15 = &this->lapFrameIndexCache;
      if ( &i >= v14 || v15->_Myfirst > &i )
      {
        v22 = this->lapFrameIndexCache._Myend;
        if ( v14 == v22 && !(v22 - v14) )
        {
          v23 = v14 - v15->_Myfirst;
          if ( v23 == 0x3FFFFFFF )
LABEL_61:
            std::_Xlength_error("vector<T> too long");
          v24 = v22 - v15->_Myfirst;
          LODWORD(oldWs.angle) = (ReplayFrameWingStatusV5)(v23 + 1);
          if ( 0x3FFFFFFF - (v24 >> 1) >= v24 )
            v25 = (v24 >> 1) + v24;
          else
            v25 = 0;
          if ( v25 < (unsigned int)oldWs.angle )
            v25 = (unsigned int)LODWORD(oldWs.angle);
          std::vector<ID3D11ShaderResourceView *>::_Reallocate(
            (std::vector<TyreThermalPatch *> *)&this->lapFrameIndexCache,
            v25);
        }
        v26 = this->lapFrameIndexCache._Mylast;
        if ( v26 )
          *v26 = v13;
      }
      else
      {
        v16 = this->lapFrameIndexCache._Myend;
        v17 = &i - v15->_Myfirst;
        if ( v14 == v16 && !(v16 - v14) )
        {
          v18 = v14 - v15->_Myfirst;
          if ( v18 == 0x3FFFFFFF )
            goto LABEL_61;
          v19 = v16 - v15->_Myfirst;
          LODWORD(oldWs.angle) = (ReplayFrameWingStatusV5)(v18 + 1);
          if ( 0x3FFFFFFF - (v19 >> 1) >= v19 )
            v20 = (v19 >> 1) + v19;
          else
            v20 = 0;
          if ( v20 < (unsigned int)oldWs.angle )
            v20 = (unsigned int)LODWORD(oldWs.angle);
          std::vector<ID3D11ShaderResourceView *>::_Reallocate(
            (std::vector<TyreThermalPatch *> *)&this->lapFrameIndexCache,
            v20);
        }
        v21 = this->lapFrameIndexCache._Mylast;
        if ( v21 )
          *v21 = v15->_Myfirst[v17];
      }
      ++this->lapFrameIndexCache._Mylast;
    }
    if ( this->metaData.numberOfWings )
    {
      v27 = 0;
      v28 = i;
      do
      {
        v29 = this->version < 6;
        v35.angle = 0;
        if ( v29 )
        {
          LODWORD(oldWs.angle) = 0;
          std::istream::read(in, &oldWs);
          v35.angle = 0;
        }
        else
        {
          std::istream::read(in, &v35);
        }
        this->frames_wings._Myfirst[v28]._Myfirst[v27++] = v35;
      }
      while ( v27 < this->metaData.numberOfWings );
    }
    v11 = &this->metaData;
    v10 = i + 1;
  }
  v30 = v11->frameCount;
  v40 = -1;
  if ( ws._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&ws);
    operator delete(ws._Myfirst);
  }
  return v30;
}
void ReplayRecorder::recordFrame(ReplayRecorder *this, const CarPhysicsState *physicsState)
{
  int v3; // edx
  unsigned int v4; // ecx
  int v5; // edi
  ReplayFrame *v6; // esi
  float v7; // xmm0_4
  ReplayRecorder *v8; // esi
  float v9; // xmm0_4
  int v10; // edi
  ReplayFrame *v11; // esi
  ReplayRecorder *v12; // edi
  int v13; // esi
  ReplayFrame *v14; // edx
  unsigned __int64 v15; // xmm2_8
  float v16; // eax
  ReplayFrame *v17; // esi
  vec3f *v18; // eax
  __int64 v19; // xmm0_8
  float v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // edx
  int v24; // edi
  __int64 v25; // xmm0_8
  ReplayFrame *v26; // esi
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // edx
  ReplayRecorder *v30; // esi
  int v31; // edi
  ReplayFrame *v32; // esi
  ReplayRecorder *v33; // esi
  float v34; // xmm1_4
  int v35; // eax
  ReplayFrame *v36; // ecx
  float v37; // xmm0_4
  float v38; // xmm0_4
  DynamicCarEffects *v39; // eax
  float v40; // xmm0_4
  int v41; // edi
  ReplayFrameAdditionalInfo *v42; // esi
  int v43; // eax
  ReplayRecorder *v44; // edi
  float *v45; // esi
  int v46; // edi
  int v47; // edi
  int *v48; // eax
  int v49; // edi
  float v50; // xmm0_4
  ReplayRecorder *v51; // esi
  unsigned int v52; // xmm0_4
  int v53; // edi
  ReplayFrame *v54; // esi
  int v55; // eax
  const CarPhysicsState *v56; // eax
  ReplayRecorder *v57; // esi
  float *v58; // edi
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  ReplayFrame *v61; // ecx
  int v62; // edx
  int v63; // eax
  unsigned int v64; // xmm0_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  unsigned int v67; // xmm1_4
  float v68; // xmm0_4
  long double v69; // st7
  int v70; // edi
  ReplayFrame *v71; // esi
  int v72; // edi
  float v73; // xmm0_4
  unsigned int v74; // eax
  unsigned int v75; // edx
  unsigned int *v76; // eax
  int v77; // edx
  ReplayFrame *v78; // ecx
  unsigned __int64 v79; // xmm2_8
  int v80; // edx
  float v81; // eax
  int v82; // esi
  float v83; // xmm0_4
  float v84; // xmm0_4
  CarAvatar *v85; // eax
  unsigned int v86; // esi
  float v87; // ecx
  float v88; // xmm0_4
  int v89; // edx
  ReplayFrame *v90; // esi
  ReplayFrame *v91; // edx
  int v92; // ecx
  int v93; // ecx
  ReplayFrame *v94; // edx
  ReplayFrame *v95; // edx
  int v96; // ecx
  ReplayFrame *v97; // edx
  int v98; // ecx
  int v99; // ecx
  ReplayFrame *v100; // edx
  int v101; // ecx
  ReplayFrame *v102; // edx
  int v103; // ecx
  ReplayFrame *v104; // edx
  int v105; // ecx
  ReplayFrame *v106; // edx
  int v107; // ecx
  ReplayFrame *v108; // edx
  int v109; // esi
  ReplayFrame *v110; // edx
  int v111; // ecx
  ReplayFrame *v112; // edx
  int v113; // ecx
  ReplayFrame *v114; // edx
  vec3f v115; // [esp-Ch] [ebp-80h]
  vec3f v116; // [esp+Ch] [ebp-68h] BYREF
  vec3f result; // [esp+18h] [ebp-5Ch] BYREF
  int v118; // [esp+2Ch] [ebp-48h]
  __int64 v119; // [esp+30h] [ebp-44h]
  float v120; // [esp+38h] [ebp-3Ch]
  int v121; // [esp+3Ch] [ebp-38h] BYREF
  int v122; // [esp+40h] [ebp-34h]
  int v123; // [esp+44h] [ebp-30h]
  float v124; // [esp+48h] [ebp-2Ch]
  unsigned int v125; // [esp+4Ch] [ebp-28h]
  float v126; // [esp+50h] [ebp-24h]
  int v127; // [esp+54h] [ebp-20h]
  unsigned int *v128; // [esp+58h] [ebp-1Ch]
  CarPhysicsState *v129; // [esp+5Ch] [ebp-18h]
  int v130; // [esp+60h] [ebp-14h]
  ReplayRecorder *v131; // [esp+64h] [ebp-10h]
  int v132; // [esp+70h] [ebp-4h]

  v131 = this;
  v3 = (char *)this->frames._Mylast - (char *)this->frames._Myfirst;
  v4 = this->recordedFrames;
  if ( v4 < v3 / 272 )
    this->recordedFrames = v4 + 1;
  if ( this->currentRecordingCue >= (unsigned int)(this->frames._Mylast - this->frames._Myfirst) )
    this->currentRecordingCue = 0;
  if ( !this->dynamicCarEffects )
    this->dynamicCarEffects = GameObject::getGameObject<DynamicCarEffects>(this->avatar);
  if ( !this->brakeLights )
    this->brakeLights = GameObject::getGameObject<CarBrakeLights>(this->avatar);
  v5 = this->currentRecordingCue;
  v6 = this->frames._Myfirst;
  v126 = physicsState->engineRPM;
  v6[v5].engineRPM.data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v126) >> 23]
                         + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v126) >> 23]);
  v7 = physicsState->gas;
  if ( RANGE_FLOAT_0_1.min > v7 )
    v7 = RANGE_FLOAT_0_1.min;
  if ( v7 > RANGE_FLOAT_0_1.max )
    v7 = RANGE_FLOAT_0_1.max;
  v8 = v131;
  v131->frames._Myfirst[v131->currentRecordingCue].gas = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                             * ((v7 - RANGE_FLOAT_0_1.dMin)
                                                              / (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin))
                                                             + (double)RANGE_UCHAR.min);
  v9 = physicsState->brake;
  if ( RANGE_FLOAT_0_1.min > v9 )
    v9 = RANGE_FLOAT_0_1.min;
  if ( v9 > RANGE_FLOAT_0_1.max )
    v9 = RANGE_FLOAT_0_1.max;
  v8->frames._Myfirst[v8->currentRecordingCue].brake = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                           * ((v9 - RANGE_FLOAT_0_1.dMin)
                                                            / (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin))
                                                           + (double)RANGE_UCHAR.min);
  v8->frames._Myfirst[v8->currentRecordingCue].gear = physicsState->gear;
  v10 = v8->currentRecordingCue;
  v11 = v8->frames._Myfirst;
  v126 = physicsState->steer;
  v11[v10].steer.data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v126) >> 23]
                       + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v126) >> 23]);
  v12 = v131;
  v13 = v131->currentRecordingCue;
  v14 = v131->frames._Myfirst;
  v15 = _mm_unpacklo_ps((__m128)LODWORD(physicsState->worldMatrix.M41), (__m128)LODWORD(physicsState->worldMatrix.M42)).m128_u64[0];
  v120 = physicsState->worldMatrix.M43;
  v16 = v120;
  *(_QWORD *)&v14[v13].worldTranslation.x = v15;
  v14[v13].worldTranslation.z = v16;
  v17 = &v12->frames._Myfirst[v12->currentRecordingCue];
  v18 = mat44f::toEuler(&physicsState->worldMatrix, &result);
  v19 = *(_QWORD *)&v18->x;
  v20 = v18->z;
  v119 = v19;
  v120 = v20;
  v21 = v19;
  v126 = *((float *)&v19 + 1);
  *(float *)&v19 = v120;
  v17->worldOrientation[0].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v21 >> 23]
                                 + ((((unsigned int)&loc_7FFFFD + 2) & v21) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v21 >> 23]);
  v22 = LODWORD(v126) >> 23;
  v23 = ((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126);
  v126 = *(float *)&v19;
  v17->worldOrientation[1].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v22]
                                 + (v23 >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v22]);
  v17->worldOrientation[2].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v126) >> 23]
                                 + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v126) >> 23]);
  v24 = v12->currentRecordingCue;
  v25 = *(_QWORD *)&physicsState->velocity.x;
  v120 = physicsState->velocity.z;
  v119 = v25;
  v126 = *(float *)&v25;
  v26 = v131->frames._Myfirst;
  v27 = v25;
  v126 = *((float *)&v25 + 1);
  *(float *)&v25 = v120;
  v26[v24].velocity[0].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v27 >> 23]
                             + ((((unsigned int)&loc_7FFFFD + 2) & v27) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v27 >> 23]);
  v28 = LODWORD(v126) >> 23;
  v29 = ((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126);
  v126 = *(float *)&v25;
  v26[v24].velocity[1].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v28]
                             + (v29 >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v28]);
  v26[v24].velocity[2].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v126) >> 23]
                             + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v126) >> 23]);
  v126 = physicsState->bodyWorkVolume;
  v131->frames._Myfirst[v131->currentRecordingCue].bodyworkVolume.data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v126) >> 23]
                                                                        + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v126) >> 23]);
  v30 = v131;
  v131->frames._Myfirst[v131->currentRecordingCue].lapTime = physicsState->lapTime;
  v30->frames._Myfirst[v30->currentRecordingCue].lastLap = physicsState->lastLap;
  v30->frames._Myfirst[v30->currentRecordingCue].bestLap = physicsState->bestLap;
  v30->frames._Myfirst[v30->currentRecordingCue].lapCount = physicsState->lapCount;
  v31 = v30->currentRecordingCue;
  v32 = v30->frames._Myfirst;
  v126 = physicsState->drivetrainSpeed;
  v32[v31].drivetrainSpeed.data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v126) >> 23]
                                 + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v126)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v126) >> 23]);
  v33 = v131;
  *(float *)&v25 = v131->avatar->physicsInfo.maxFuel;
  v34 = physicsState->fuel / *(float *)&v25;
  if ( RANGE_FLOAT_0_1.min > v34 )
    v34 = RANGE_FLOAT_0_1.min;
  if ( v34 > RANGE_FLOAT_0_1.max )
    v34 = RANGE_FLOAT_0_1.max;
  v131->frames._Myfirst[v131->currentRecordingCue].fuel = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                              * ((v34 - RANGE_FLOAT_0_1.dMin)
                                                               / (RANGE_FLOAT_0_1.dMax - RANGE_FLOAT_0_1.dMin))
                                                              + (double)RANGE_UCHAR.min);
  v35 = v33->currentRecordingCue;
  v36 = v33->frames._Myfirst;
  if ( !v36[v35].fuel && physicsState->fuel > 0.0 )
    v36[v35].fuel = 1;
  v33->frames._Myfirst[v33->currentRecordingCue].fuelLaps = (int)physicsState->fuelLaps;
  v37 = physicsState->turboBoost;
  if ( RANGE_FLOAT_0_5.min > v37 )
    v37 = RANGE_FLOAT_0_5.min;
  if ( v37 > RANGE_FLOAT_0_5.max )
    v37 = RANGE_FLOAT_0_5.max;
  v33->framesAdditionalInfo._Myfirst[v33->currentRecordingCue].turboBoost = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                                                * ((v37 - RANGE_FLOAT_0_5.dMin)
                                                                                 / (RANGE_FLOAT_0_5.dMax
                                                                                  - RANGE_FLOAT_0_5.dMin))
                                                                                + (double)RANGE_UCHAR.min);
  v38 = physicsState->engineLifeLeft;
  if ( RANGE_FLOAT_0_1000.min > v38 )
    v38 = RANGE_FLOAT_0_1000.min;
  if ( v38 > RANGE_FLOAT_0_1000.max )
    v38 = RANGE_FLOAT_0_1000.max;
  v33->framesAdditionalInfo._Myfirst[v33->currentRecordingCue].engineLife = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                                                * ((v38 - RANGE_FLOAT_0_1000.dMin)
                                                                                 / (RANGE_FLOAT_0_1000.dMax
                                                                                  - RANGE_FLOAT_0_1000.dMin))
                                                                                + (double)RANGE_UCHAR.min);
  v39 = v33->dynamicCarEffects;
  if ( v39 )
  {
    v40 = v39->currentDirtLevel;
    if ( RANGE_FLOAT_0_1.min > v40 )
      v40 = RANGE_FLOAT_0_1.min;
    if ( v40 > RANGE_FLOAT_0_1.max )
      v40 = RANGE_FLOAT_0_1.max;
    v33->framesAdditionalInfo._Myfirst[v33->currentRecordingCue].carDirt = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                                               * ((v40 - RANGE_FLOAT_0_1.dMin)
                                                                                / (RANGE_FLOAT_0_1.dMax
                                                                                 - RANGE_FLOAT_0_1.dMin))
                                                                               + (double)RANGE_UCHAR.min);
  }
  else
  {
    v33->framesAdditionalInfo._Myfirst[v33->currentRecordingCue].carDirt = 0;
  }
  v41 = v33->currentRecordingCue;
  v42 = v33->framesAdditionalInfo._Myfirst;
  v42[v41].connected = CarAvatar::isConnected(v131->avatar);
  v43 = 0;
  v44 = v131;
  v45 = physicsState->tyreSlip;
  v130 = 0;
  v126 = 0.0;
  v127 = 0;
  v129 = (CarPhysicsState *)physicsState->tyreSlip;
  v128 = (unsigned int *)&physicsState->suspensionMatrix[0].M42;
  do
  {
    v46 = 136 * v44->currentRecordingCue;
    v125 = *((unsigned int *)v45 - 30);
    v47 = v43 + v46;
    v48 = (int *)v129;
    v131->frames._Myfirst->wheelAngularSpeed[v47].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v125 >> 23]
                                                        + ((((unsigned int)&loc_7FFFFD + 2) & v125) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v125 >> 23]);
    v125 = *(unsigned int *)v48;
    v131->frames._Myfirst[v131->currentRecordingCue].tyreSlipAngle[v130].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v125 >> 23]
                                                                               + ((((unsigned int)&loc_7FFFFD + 2) & v125) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v125 >> 23]);
    v49 = (int)v129;
    v50 = v129->suspensionMatrix[0].M14;
    if ( RANGE_FLOAT_0_20.min > v50 )
      v50 = RANGE_FLOAT_0_20.min;
    if ( v50 > RANGE_FLOAT_0_20.max )
      v50 = RANGE_FLOAT_0_20.max;
    v51 = v131;
    v131->frames._Myfirst[v131->currentRecordingCue].tyreDirtyLevel[v130] = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                                                * ((v50 - RANGE_FLOAT_0_20.dMin)
                                                                                 / (RANGE_FLOAT_0_20.dMax
                                                                                  - RANGE_FLOAT_0_20.dMin))
                                                                                + (double)RANGE_UCHAR.min);
    v52 = *(unsigned int *)(v49 + 16);
    v53 = 136 * v51->currentRecordingCue;
    v54 = v51->frames._Myfirst;
    v125 = v52;
    v55 = (int)v129;
    v54->ndSlip[v130 + v53].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v52 >> 23]
                                  + ((((unsigned int)&loc_7FFFFD + 2) & v52) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v52 >> 23]);
    v125 = *(unsigned int *)(v55 + 32);
    v56 = v129;
    v131->frames._Myfirst[v131->currentRecordingCue].load[v130].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v125 >> 23]
                                                                      + ((((unsigned int)&loc_7FFFFD + 2) & v125) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v125 >> 23]);
    v125 = LODWORD(v56[-1].antiSquat);
    v131->frames._Myfirst[v131->currentRecordingCue].slipRatio[v130].data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v125 >> 23]
                                                                           + ((((unsigned int)&loc_7FFFFD + 2) & v125) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v125 >> 23]);
    v57 = v131;
    v58 = (float *)v128;
    v59 = (__m128)*(v128 - 1);
    v60 = (__m128)*v128;
    v61 = v131->frames._Myfirst;
    v62 = v127 + 272 * v131->currentRecordingCue;
    v118 = v128[1];
    v63 = v118;
    *(_QWORD *)((char *)&v61->susTranslation[0].x + v62) = _mm_unpacklo_ps(v59, v60).m128_u64[0];
    *(_DWORD *)((char *)&v61->susTranslation[0].z + v62) = v63;
    v125 = *((_DWORD *)v58 - 5) ^ _xmm;
    v124 = *(v58 - 3);
    *(float *)&v119 = atan2(*(float *)&v125, v124);
    v64 = __libm_sse2_asinf().m128_u32[0];
    v65 = *(v58 - 12);
    v66 = *(float *)&v64;
    if ( v65 == 0.0 && *(v58 - 8) == 0.0 )
    {
      v67 = 0;
      v124 = *(v58 - 9);
      v68 = *(v58 - 13);
    }
    else
    {
      v68 = *(v58 - 8);
      v67 = v119;
      LODWORD(v124) = LODWORD(v65) ^ _xmm;
    }
    *(float *)&v125 = v68;
    v69 = atan2(v124, v68);
    v70 = 272 * v57->currentRecordingCue;
    v71 = v57->frames._Myfirst;
    v72 = LODWORD(v126) + v70;
    v124 = v66;
    v120 = v69;
    v73 = v120;
    *(unsigned __int16 *)((char *)&v71->susOrientation[0][0].data_ + v72) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v67 >> 23]
                                                                          + ((((unsigned int)&loc_7FFFFD + 2) & v67) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v67 >> 23]);
    v74 = LODWORD(v124) >> 23;
    v75 = ((unsigned int)&loc_7FFFFD + 2) & LODWORD(v124);
    v124 = v73;
    *(unsigned __int16 *)((char *)&v71->susOrientation[0][1].data_ + v72) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v74]
                                                                          + (v75 >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v74]);
    v76 = v128;
    *(unsigned __int16 *)((char *)&v71->susOrientation[0][2].data_ + v72) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v124) >> 23]
                                                                          + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v124)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v124) >> 23]);
    v44 = v131;
    v77 = 272 * v131->currentRecordingCue;
    v78 = v131->frames._Myfirst;
    v79 = _mm_unpacklo_ps((__m128)v76[63], (__m128)v76[64]).m128_u64[0];
    LODWORD(result.z) = v76[65];
    v80 = v127 + v77;
    v81 = result.z;
    *(_QWORD *)((char *)&v78->tyreTranslation[0].x + v80) = v79;
    *(float *)((char *)&v78->tyreTranslation[0].z + v80) = v81;
    v82 = (int)&v44->frames._Myfirst[v44->currentRecordingCue];
    v115 = *mat44f::toEuler((mat44f *)(v128 + 51), &v116);
    fTH3((half_float::half *)(v82 + LODWORD(v126) + 160), v115);
    v83 = *(float *)&v129->tyreSurfaceDef[1].userPointer;
    if ( RANGE_FLOAT_0_255.min > v83 )
      v83 = RANGE_FLOAT_0_255.min;
    if ( v83 > RANGE_FLOAT_0_255.max )
      v83 = RANGE_FLOAT_0_255.max;
    v45 = &v129->worldMatrix.M11;
    v128 += 16;
    LODWORD(v126) += 6;
    v129 = (CarPhysicsState *)((char *)v129 + 4);
    v44->frames._Myfirst[v44->currentRecordingCue].damageZoneLevel[v130] = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                                               * ((v83 - RANGE_FLOAT_0_255.dMin)
                                                                                / (RANGE_FLOAT_0_255.dMax
                                                                                 - RANGE_FLOAT_0_255.dMin))
                                                                               + (double)RANGE_UCHAR.min);
    v43 = v130 + 1;
    v127 += 12;
    ++v130;
  }
  while ( v127 < 48 );
  v84 = physicsState->damageZoneLevel[4];
  if ( RANGE_FLOAT_0_255.min > v84 )
    v84 = RANGE_FLOAT_0_255.min;
  if ( v84 > RANGE_FLOAT_0_255.max )
    v84 = RANGE_FLOAT_0_255.max;
  v44->frames._Myfirst[v44->currentRecordingCue].damageZoneLevel[4] = (int)((RANGE_UCHAR.dMax - RANGE_UCHAR.dMin)
                                                                          * ((v84 - RANGE_FLOAT_0_255.dMin)
                                                                           / (RANGE_FLOAT_0_255.dMax
                                                                            - RANGE_FLOAT_0_255.dMin))
                                                                          + (double)RANGE_UCHAR.min);
  v121 = 0;
  v122 = 0;
  v123 = 0;
  v85 = v44->avatar;
  v132 = 0;
  v85->physicsStateProvider->getWingState(v85->physicsStateProvider, (std::vector<WingState> *)&v121);
  v86 = 0;
  if ( (v122 - v121) / 68 )
  {
    v87 = 0.0;
    v126 = 0.0;
    do
    {
      v88 = *(float *)(v121 + LODWORD(v87) + 12);
      if ( RANGE_FLOAT_0_100.min > v88 )
        v88 = RANGE_FLOAT_0_100.min;
      if ( v88 > RANGE_FLOAT_0_100.max )
        v88 = RANGE_FLOAT_0_100.max;
      LODWORD(v126) += 68;
      v44->frames_wings._Myfirst[v44->currentRecordingCue]._Myfirst[v86++].angle = (int)((RANGE_UCHAR.dMax
                                                                                        - RANGE_UCHAR.dMin)
                                                                                       * ((v88 - RANGE_FLOAT_0_100.dMin)
                                                                                        / (RANGE_FLOAT_0_100.dMax
                                                                                         - RANGE_FLOAT_0_100.dMin))
                                                                                       + (double)RANGE_UCHAR.min);
      v87 = v126;
    }
    while ( v86 < (v122 - v121) / 68 );
  }
  v89 = v44->currentRecordingCue;
  v90 = v44->frames._Myfirst;
  if ( physicsState->isGearGrinding )
    v90[v89].status._Array[0] |= 0x200u;
  else
    v90[v89].status._Array[0] &= 0xFFFFFDFF;
  v91 = v44->frames._Myfirst;
  v92 = v44->currentRecordingCue;
  if ( physicsState->isDriftValid )
    v91[v92].status._Array[0] &= 0xFFFFFBFF;
  else
    v91[v92].status._Array[0] |= 0x400u;
  v93 = v44->currentRecordingCue;
  v94 = v44->frames._Myfirst;
  if ( (v44->avatar->physicsState.actionsState.state & 0x100000) != 0 )
    v94[v93].status._Array[0] |= 1u;
  else
    v94[v93].status._Array[0] &= 0xFFFFFFFE;
  v95 = v44->frames._Myfirst;
  v96 = v44->currentRecordingCue;
  if ( (v44->avatar->physicsState.statusBytes & 4) != 0 )
    v95[v96].status._Array[0] |= 2u;
  else
    v95[v96].status._Array[0] &= 0xFFFFFFFD;
  v97 = v44->frames._Myfirst;
  v98 = v44->currentRecordingCue;
  if ( (v44->avatar->physicsState.statusBytes & 1) != 0 )
    v97[v98].status._Array[0] |= 4u;
  else
    v97[v98].status._Array[0] &= 0xFFFFFFFB;
  v99 = v44->currentRecordingCue;
  v100 = v44->frames._Myfirst;
  if ( (v44->avatar->physicsState.actionsState.state & 0x40) != 0 )
    v100[v99].status._Array[0] |= 8u;
  else
    v100[v99].status._Array[0] &= 0xFFFFFFF7;
  v101 = v44->currentRecordingCue;
  v102 = v44->frames._Myfirst;
  if ( (v44->avatar->physicsState.actionsState.state & 1) != 0 )
    v102[v101].status._Array[0] |= 0x10u;
  else
    v102[v101].status._Array[0] &= 0xFFFFFFEF;
  v103 = v44->currentRecordingCue;
  v104 = v44->frames._Myfirst;
  if ( (v44->avatar->physicsState.actionsState.state & 2) != 0 )
    v104[v103].status._Array[0] |= 0x20u;
  else
    v104[v103].status._Array[0] &= 0xFFFFFFDF;
  v105 = v44->currentRecordingCue;
  v106 = v44->frames._Myfirst;
  if ( (v44->avatar->physicsState.actionsState.state & 0x100) != 0 )
    v106[v105].status._Array[0] |= 0x40u;
  else
    v106[v105].status._Array[0] &= 0xFFFFFFBF;
  v107 = v44->currentRecordingCue;
  v108 = v44->frames._Myfirst;
  if ( (v44->avatar->physicsState.actionsState.state & 0x80) != 0 )
    v108[v107].status._Array[0] |= 0x80u;
  else
    v108[v107].status._Array[0] &= 0xFFFFFF7F;
  v44->frames._Myfirst[v44->currentRecordingCue].status._Array[0] &= 0xFFFFFEFF;
  v109 = v44->currentRecordingCue;
  if ( v109 <= 0 || (v110 = v44->frames._Myfirst, v110[v109].lapCount == v110[v109 - 1].lapCount) )
  {
    v44->frames._Myfirst[v109].status._Array[0] &= 0xFFFFF7FF;
  }
  else
  {
    v110[v109].status._Array[0] |= 0x800u;
    v44->lapFrameIndexCache._Myfirst[v44->lapCacheIndex] = v44->currentRecordingCue;
    v44->lapCacheIndex = (v44->lapCacheIndex + 1)
                       % (unsigned int)(v44->lapFrameIndexCache._Mylast - v44->lapFrameIndexCache._Myfirst);
  }
  v111 = v44->currentRecordingCue;
  v112 = v44->frames._Myfirst;
  if ( (v44->avatar->physicsState.actionsState.state & 0x400) != 0 )
    v112[v111].status._Array[0] |= 0x1000u;
  else
    v112[v111].status._Array[0] &= 0xFFFFEFFF;
  v113 = v44->currentRecordingCue;
  v114 = v44->frames._Myfirst;
  if ( v44->avatar->physicsState.kersIsCharging )
    v114[v113].status._Array[0] |= 0x2000u;
  else
    v114[v113].status._Array[0] &= 0xFFFFDFFF;
  ++v44->currentRecordingCue;
  v132 = -1;
  if ( v121 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v121);
    operator delete(v121);
  }
}
void ReplayRecorder::save(ReplayRecorder *this, std::ofstream *out, int cutIn, int cutOut, int cutSize, int pivot)
{
  std::ofstream *v7; // ebx
  int v8; // esi
  int v9; // ebp
  unsigned int i; // esi
  int cutSizea; // [esp+3Ch] [ebp+10h]

  v7 = out;
  this->metaData.frameCount = cutSize;
  this->metaData.numberOfWings = this->avatar->wingsStatus._Mylast - this->avatar->wingsStatus._Myfirst;
  std::ostream::write(out, &this->metaData, 8, 0);
  v8 = this->recordedFrames;
  cutSizea = (pivot + cutOut) % v8;
  v9 = (pivot + cutIn) % v8;
  do
  {
    std::ostream::write(v7, &this->frames._Myfirst[v9], 272, 0);
    std::ostream::write(v7, &this->framesAdditionalInfo._Myfirst[v9], 4, 0);
    if ( this->metaData.numberOfWings )
    {
      for ( i = 0; i < this->frames_wings._Myfirst[v9]._Mylast - this->frames_wings._Myfirst[v9]._Myfirst; ++i )
        std::ostream::write(out, &this->frames_wings._Myfirst[v9]._Myfirst[i], 4, 0);
      v7 = out;
    }
    v9 = (v9 + 1) % this->recordedFrames;
  }
  while ( v9 != cutSizea );
}
void ReplayRecorder::setFrameSize(ReplayRecorder *this, int size)
{
  std::vector<std::vector<ReplayFrameWingStatus>> *v3; // ebx
  CarAvatar *v4; // eax
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // esi
  std::vector<WingState> ws; // [esp+10h] [ebp-18h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  std::vector<ReplayFrame>::resize(&this->frames, size);
  v3 = &this->frames_wings;
  std::vector<std::vector<LeaderboardEntry>>::resize((std::vector<std::vector<WingState>> *)&this->frames_wings, size);
  std::vector<ReplayFrameAdditionalInfo>::resize(&this->framesAdditionalInfo, size);
  ws._Myfirst = 0;
  ws._Mylast = 0;
  ws._Myend = 0;
  v4 = this->avatar;
  v9 = 0;
  v4->physicsStateProvider->getWingState(v4->physicsStateProvider, &ws);
  v5 = (char *)this->frames_wings._Mylast - (char *)this->frames_wings._Myfirst;
  v6 = 0;
  if ( v5 / 12 )
  {
    v7 = 0;
    do
    {
      std::vector<ReplayFrameWingStatus>::resize(&v3->_Myfirst[v7], ws._Mylast - ws._Myfirst);
      ++v6;
      ++v7;
    }
    while ( v6 < v3->_Mylast - v3->_Myfirst );
  }
  v9 = -1;
  if ( ws._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&ws);
    operator delete(ws._Myfirst);
  }
}
