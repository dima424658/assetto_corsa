#include "caraudiofmod.h
void CarAudioFMOD::CarAudioFMOD(CarAudioFMOD *this, CarAvatar *car)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  const std::wstring *v6; // edi
  Game *v7; // eax
  AudioEngine *v8; // esi
  std::wstring *v9; // edi
  std::wstring *v10; // eax
  const std::wstring *v11; // eax
  CarAvatar *v12; // esi
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  Game *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  Game *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  Game *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  Game *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  Game *v27; // eax
  CarAvatar *v28; // ebx
  Game *v29; // eax
  INIReader *v30; // edi
  std::unique_ptr<AudioEvent> *v31; // esi
  std::wstring *v32; // eax
  std::wstring *v33; // eax
  CarAudioFMOD *v34; // ecx
  AudioEvent *v35; // eax
  AudioEvent *v36; // edi
  CarAudioFMOD *v37; // ecx
  AudioEvent *v38; // eax
  AudioEvent *v39; // edi
  bool v40; // cf
  bool v41; // zf
  std::wstring *v42; // edi
  std::wstring *v43; // eax
  const std::wstring *v44; // eax
  bool v45; // al
  int v46; // ebx
  std::wstring *v47; // eax
  std::wstring *v48; // eax
  CarAvatar *v49; // esi
  Game *v50; // eax
  AudioEvent *v51; // eax
  AudioEvent *v52; // ecx
  std::wstring *v53; // eax
  char v54; // al
  Game *v55; // eax
  AudioEvent *v56; // eax
  AudioEvent *v57; // ecx
  std::wstring *v58; // eax
  std::wstring *v59; // eax
  const std::wstring *v60; // eax
  std::wstring *v61; // eax
  int v62; // ebx
  std::wstring *v63; // eax
  Game *v64; // eax
  AudioEvent *v65; // eax
  AudioEvent *v66; // ecx
  std::wstring *v67; // eax
  std::wstring *v68; // eax
  int v69; // ebx
  const std::wstring *v70; // eax
  int v71; // ebx
  std::wstring *v72; // eax
  int v73; // ebx
  const std::wstring *v74; // eax
  bool v75; // al
  std::wstring *v76; // eax
  int v77; // ebx
  const std::wstring *v78; // eax
  AudioEvent *v79; // eax
  AudioEvent *v80; // ecx
  std::wstring *v81; // eax
  std::wstring *v82; // eax
  int v83; // ebx
  const std::wstring *v84; // eax
  AudioEvent *v85; // eax
  AudioEvent *v86; // ecx
  std::wstring *v87; // eax
  std::wstring *v88; // eax
  int v89; // ebx
  const std::wstring *v90; // eax
  int v91; // ebx
  std::wstring *v92; // eax
  int v93; // ebx
  const std::wstring *v94; // eax
  bool v95; // al
  std::wstring *v96; // eax
  int v97; // ebx
  std::wstring *v98; // eax
  Game *v99; // eax
  AudioEvent *v100; // eax
  AudioEvent *v101; // ecx
  std::wstring *v102; // eax
  std::wstring *v103; // eax
  int v104; // ebx
  std::wstring *v105; // eax
  Game *v106; // eax
  AudioEvent *v107; // eax
  AudioEvent *v108; // ecx
  std::wstring *v109; // eax
  std::wstring *v110; // eax
  const std::wstring *v111; // eax
  std::wstring *v112; // eax
  int v113; // ebx
  std::wstring *v114; // eax
  Game *v115; // eax
  AudioEvent *v116; // eax
  AudioEvent *v117; // ecx
  std::wstring *v118; // eax
  std::wstring *v119; // eax
  const std::wstring *v120; // eax
  std::wstring *v121; // eax
  unsigned int v122; // ebx
  std::wstring *v123; // eax
  Game *v124; // eax
  AudioEvent *v125; // eax
  AudioEvent *v126; // esi
  std::wstring *v127; // eax
  const std::wstring *v128; // eax
  CarAvatar *v129; // edi
  float v130; // esi
  char v131; // bl
  std::wstring *v132; // eax
  std::wostream *v133; // eax
  const std::wstring *v134; // eax
  bool v135; // al
  char v136; // al
  const std::wstring *v137; // eax
  double v138; // st7
  int v139; // ebx
  std::wstring *v140; // eax
  int v141; // ebx
  const std::wstring *v142; // eax
  bool v143; // al
  std::wstring *v144; // eax
  int v145; // ebx
  const std::wstring *v146; // eax
  AudioEvent *v147; // eax
  int v148; // ebp
  std::wstring *v149; // eax
  AudioEngine **v150; // eax
  CarAudioFMOD *v151; // ebp
  signed int v152; // esi
  std::wstring *v153; // eax
  std::wstring *v154; // eax
  AudioEvent *v155; // eax
  unsigned int v156; // ebx
  signed int i; // esi
  std::wstring *v158; // eax
  AudioEngine **v159; // eax
  AudioEvent *v160; // eax
  CarAudioFMOD *v161; // ebp
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *v162; // eax
  std::wstring *v163; // eax
  const std::wstring *v164; // eax
  bool v165; // al
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v166; // edi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v167; // esi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v168; // eax
  float v169; // xmm0_4
  CarAudioFMOD::{ctor}::__l64::<lambda_6817fd2273d1010f1094d841cc9dd6ff> *v170; // eax
  CarAudioFMOD::{ctor}::__l71::<lambda_9978203bfa93d47158f91df2e13620d5> *v171; // eax
  AudioEngine *v172; // ecx
  std::wstring v173; // [esp-Ch] [ebp-204h] BYREF
  float volume; // [esp+Ch] [ebp-1ECh]
  bool v175; // [esp+2Bh] [ebp-1CDh]
  int v176; // [esp+2Ch] [ebp-1CCh]
  std::wstring *carUnixName; // [esp+30h] [ebp-1C8h]
  AudioEngine *engine; // [esp+34h] [ebp-1C4h]
  unsigned int v179; // [esp+38h] [ebp-1C0h]
  EventReverbResponse v180; // [esp+3Ch] [ebp-1BCh] BYREF
  CarAvatar *v181; // [esp+40h] [ebp-1B8h]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v182; // [esp+44h] [ebp-1B4h] BYREF
  CarAudioFMOD *_This; // [esp+48h] [ebp-1B0h] BYREF
  std::vector<AudioEvent> *v184; // [esp+4Ch] [ebp-1ACh]
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v185; // [esp+50h] [ebp-1A8h] BYREF
  INIReader *v186; // [esp+54h] [ebp-1A4h]
  int v187; // [esp+58h] [ebp-1A0h]
  CarAudioFMOD *v188; // [esp+5Ch] [ebp-19Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > turboSection; // [esp+60h] [ebp-198h] BYREF
  std::wstring path; // [esp+110h] [ebp-E8h] BYREF
  std::wstring result; // [esp+128h] [ebp-D0h] BYREF
  std::wstring positionOption; // [esp+140h] [ebp-B8h] BYREF
  std::wstring hitEventName; // [esp+158h] [ebp-A0h] BYREF
  std::wstring v194; // [esp+170h] [ebp-88h] BYREF
  std::wstring v195; // [esp+188h] [ebp-70h] BYREF
  INIReader reader; // [esp+1A0h] [ebp-58h] BYREF
  int v197; // [esp+1E4h] [ebp-14h]
  int v198; // [esp+1F4h] [ebp-4h]

  _This = this;
  v176 = 0;
  v188 = this;
  v181 = car;
  volume = *(float *)&car->game;
  v179 = 0;
  v173._Myres = 7;
  v173._Mysize = 0;
  v173._Bx._Buf[0] = 0;
  std::wstring::assign(&v173, L"CARAUDIO", 8u);
  GameObject::GameObject(this, v173, (Game *)LODWORD(volume));
  LODWORD(volume) = std::unique_ptr<AudioEvent>::~unique_ptr<AudioEvent>;
  v173._Myres = (unsigned int)std::unique_ptr<AudioEvent>::unique_ptr<AudioEvent>;
  v173._Mysize = 3;
  *(_DWORD *)&v173._Bx._Alias[12] = 4;
  v198 = 0;
  *(_DWORD *)&v173._Bx._Alias[8] = this->hitEvents;
  this->__vftable = (CarAudioFMOD_vtbl *)&CarAudioFMOD::`vftable';
  this->car = car;
  this->cameraManager = 0;
  `eh vector constructor iterator'(
    *(void **)&v173._Bx._Alias[8],
    *(unsigned int *)&v173._Bx._Alias[12],
    v173._Mysize,
    (void (*)(void *))v173._Myres,
    (void (*)(void *))LODWORD(volume));
  LOBYTE(v198) = 1;
  `eh vector constructor iterator'(
    this->scrapeEvents,
    4u,
    3,
    (void (*)(void *))std::unique_ptr<AudioEvent>::unique_ptr<AudioEvent>,
    (void (*)(void *))std::unique_ptr<AudioEvent>::~unique_ptr<AudioEvent>);
  LOBYTE(v198) = 2;
  positionOption._Myres = 7;
  positionOption._Mysize = 0;
  positionOption._Bx._Buf[0] = 0;
  std::wstring::assign(&positionOption, L"event:/common/dirt", 0x12u);
  LOBYTE(v198) = 3;
  AudioEvent::AudioEvent(&this->dirtEvent, car->game->audioEngine, &positionOption, Off);
  LOBYTE(v198) = 5;
  if ( positionOption._Myres >= 8 )
    operator delete(positionOption._Bx._Ptr);
  positionOption._Myres = 7;
  positionOption._Bx._Buf[0] = 0;
  positionOption._Mysize = 0;
  carUnixName = &car->unixName;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &car->unixName);
  LOBYTE(v198) = 6;
  v4 = std::operator+<wchar_t>(&hitEventName, v3, L"/sfx/");
  LOBYTE(v198) = 7;
  v5 = std::operator+<wchar_t>(&v194, v4, &car->unixName);
  LOBYTE(v198) = 8;
  v6 = std::operator+<wchar_t>(&v195, v5, L".bank");
  v7 = car->game;
  v180 = (EventReverbResponse)&this->bank;
  volume = NAN;
  LOBYTE(v198) = 9;
  v8 = v7->audioEngine;
  this->bank.engine = v8;
  v173._Myres = 0;
  v173._Mysize = (unsigned int)v6;
  this->bank.path._Myres = 7;
  this->bank.path._Mysize = 0;
  this->bank.path._Bx._Buf[0] = 0;
  std::wstring::assign(&this->bank.path, (const std::wstring *)v173._Mysize, v173._Myres, LODWORD(volume));
  LOBYTE(v198) = 10;
  AudioEngine::addBankRef(v8, v6);
  if ( v195._Myres >= 8 )
    operator delete(v195._Bx._Ptr);
  v195._Myres = 7;
  v195._Mysize = 0;
  v195._Bx._Buf[0] = 0;
  if ( v194._Myres >= 8 )
    operator delete(v194._Bx._Ptr);
  v194._Myres = 7;
  v194._Mysize = 0;
  v194._Bx._Buf[0] = 0;
  if ( hitEventName._Myres >= 8 )
    operator delete(hitEventName._Bx._Ptr);
  hitEventName._Myres = 7;
  hitEventName._Mysize = 0;
  hitEventName._Bx._Buf[0] = 0;
  LOBYTE(v198) = 15;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v9 = carUnixName;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  MixVolumes::MixVolumes(&this->mixVolumes, 0, carUnixName);
  v10 = std::operator+<wchar_t>(&path, L"event:/cars/", v9);
  LOBYTE(v198) = 16;
  v11 = std::operator+<wchar_t>(&positionOption, v10, L"/engine_ext");
  v12 = v181;
  LOBYTE(v198) = 17;
  AudioEvent::AudioEvent(&this->engineExtEvent, v181->game->audioEngine, v11, On);
  if ( positionOption._Myres >= 8 )
    operator delete(positionOption._Bx._Ptr);
  positionOption._Myres = 7;
  positionOption._Mysize = 0;
  positionOption._Bx._Buf[0] = 0;
  LOBYTE(v198) = 20;
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Bx._Buf[0] = 0;
  path._Mysize = 0;
  v13 = std::operator+<wchar_t>(&hitEventName, L"event:/cars/", v9);
  LOBYTE(v198) = 21;
  v14 = std::operator+<wchar_t>(&result, v13, L"/engine_int");
  volume = 0.0;
  v173._Myres = (unsigned int)v14;
  v15 = v12->game;
  LOBYTE(v198) = 22;
  AudioEvent::AudioEvent(&this->engineIntEvent, v15->audioEngine, (const std::wstring *)v173._Myres, Off);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v198) = 25;
  if ( hitEventName._Myres >= 8 )
    operator delete(hitEventName._Bx._Ptr);
  hitEventName._Myres = 7;
  hitEventName._Bx._Buf[0] = 0;
  hitEventName._Mysize = 0;
  v16 = std::operator+<wchar_t>(&v194, L"event:/cars/", v9);
  LOBYTE(v198) = 26;
  v17 = std::operator+<wchar_t>(&path, v16, L"/gear_ext");
  LODWORD(volume) = 1;
  v173._Myres = (unsigned int)v17;
  v18 = v12->game;
  LOBYTE(v198) = 27;
  AudioEvent::AudioEvent(&this->gearExtEvent, v18->audioEngine, (const std::wstring *)v173._Myres, On);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  LOBYTE(v198) = 30;
  if ( v194._Myres >= 8 )
    operator delete(v194._Bx._Ptr);
  v194._Myres = 7;
  v194._Bx._Buf[0] = 0;
  v194._Mysize = 0;
  v19 = std::operator+<wchar_t>(&hitEventName, L"event:/cars/", v9);
  LOBYTE(v198) = 31;
  v20 = std::operator+<wchar_t>(&result, v19, L"/gear_int");
  volume = 0.0;
  v173._Myres = (unsigned int)v20;
  v21 = v12->game;
  LOBYTE(v198) = 32;
  AudioEvent::AudioEvent(&this->gearIntEvent, v21->audioEngine, (const std::wstring *)v173._Myres, Off);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v198) = 35;
  if ( hitEventName._Myres >= 8 )
    operator delete(hitEventName._Bx._Ptr);
  hitEventName._Myres = 7;
  hitEventName._Bx._Buf[0] = 0;
  hitEventName._Mysize = 0;
  v22 = std::operator+<wchar_t>(&v194, L"event:/cars/", v9);
  LOBYTE(v198) = 36;
  v23 = std::operator+<wchar_t>(&path, v22, L"/bodywork");
  volume = 0.0;
  v173._Myres = (unsigned int)v23;
  v24 = v12->game;
  LOBYTE(v198) = 37;
  AudioEvent::AudioEvent(&this->bodyworkEvent, v24->audioEngine, (const std::wstring *)v173._Myres, Off);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  LOBYTE(v198) = 40;
  if ( v194._Myres >= 8 )
    operator delete(v194._Bx._Ptr);
  v194._Myres = 7;
  v194._Bx._Buf[0] = 0;
  v194._Mysize = 0;
  v25 = std::operator+<wchar_t>(&hitEventName, L"event:/cars/", v9);
  LOBYTE(v198) = 41;
  v26 = std::operator+<wchar_t>(&result, v25, L"/wind");
  volume = 0.0;
  v173._Myres = (unsigned int)v26;
  v27 = v12->game;
  LOBYTE(v198) = 42;
  AudioEvent::AudioEvent(&this->windEvent, v27->audioEngine, (const std::wstring *)v173._Myres, Off);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( hitEventName._Myres >= 8 )
    operator delete(hitEventName._Bx._Ptr);
  this->downShiftEvent._Myptr = 0;
  this->hornEvent._Myptr = 0;
  this->gearGrindEvent._Myptr = 0;
  this->backfireExtEvent._Myptr = 0;
  this->backfireIntEvent._Myptr = 0;
  this->tractionControlExtEvent._Myptr = 0;
  this->tractionControlIntEvent._Myptr = 0;
  this->transmissionEvent._Myptr = 0;
  this->limiterEvent._Myptr = 0;
  this->turboEvent._Myptr = 0;
  this->wheelEvents._Myfirst = 0;
  v185._Ptr = (const wchar_t *)&this->wheelEvents;
  this->wheelEvents._Mylast = 0;
  this->wheelEvents._Myend = 0;
  this->skidExtEvents._Myfirst = 0;
  v180 = (EventReverbResponse)&this->skidExtEvents;
  this->skidExtEvents._Mylast = 0;
  this->skidExtEvents._Myend = 0;
  this->skidIntEvents._Myfirst = 0;
  v184 = &this->skidIntEvents;
  this->skidIntEvents._Mylast = 0;
  this->skidIntEvents._Myend = 0;
  LOBYTE(v198) = 58;
  `eh vector constructor iterator'(
    &this->surfaceEvents,
    0x1Cu,
    4,
    (void (*)(void *))CarAudioFMOD::SurfaceList::SurfaceList,
    (void (*)(void *))std::pair<std::wstring,jsonwriter::Node &>::~pair<std::wstring,jsonwriter::Node &>);
  v28 = v181;
  LODWORD(volume) = v181;
  LOBYTE(v198) = 59;
  this->enginePosition = ENGINEPOSITION_UNSPECIFIED;
  SkidParams::SkidParams(&this->skidParams, (CarAvatar *)LODWORD(volume));
  this->backfireTriggerReady = 0;
  this->lastGear = 0;
  this->gas.alpha = 0.89999998;
  this->gas.value = 0.0;
  this->bodyworkVolume.alpha = 0.89999998;
  this->bodyworkVolume.value = 0.0;
  this->skidVolumes[0].alpha = 0.89999998;
  this->skidVolumes[0].value = 0.0;
  this->skidVolumes[1].alpha = 0.89999998;
  this->skidVolumes[1].value = 0.0;
  this->skidVolumes[2].alpha = 0.89999998;
  this->skidVolumes[2].value = 0.0;
  this->skidVolumes[3].alpha = 0.89999998;
  this->skidVolumes[3].value = 0.0;
  this->skidPitches[0].alpha = 0.89999998;
  this->skidPitches[0].value = 0.0;
  this->skidPitches[1].alpha = 0.89999998;
  this->skidPitches[1].value = 0.0;
  this->skidPitches[2].alpha = 0.89999998;
  this->skidPitches[2].value = 0.0;
  this->skidPitches[3].alpha = 0.89999998;
  this->skidPitches[3].value = 0.0;
  this->tractionControlDecay = 0.0;
  this->limiterDecay = 10.0;
  this->turboBovDecay = 10.0;
  this->listenerPriority = 0;
  this->listenerDistance = 0.0;
  this->usingCache = 0;
  v29 = v28->game;
  LODWORD(volume) = 3;
  v173._Myres = (unsigned int)L"car";
  engine = v29->audioEngine;
  *(_QWORD *)&reader.filename._Bx._Alias[8] = 0x700000000i64;
  LOWORD(reader.__vftable) = 0;
  std::wstring::assign((std::wstring *)&reader, L"car", 3u);
  LOBYTE(v198) = 60;
  reader.code._Bx._Ptr = (wchar_t *)7;
  *(_DWORD *)&reader.m_isEncrypted = 0;
  LOWORD(reader.filename._Mysize) = 0;
  std::wstring::assign((std::wstring *)&reader.filename._Mysize, L"track", 5u);
  LOBYTE(v198) = 61;
  v197 = 7;
  reader.code._Myres = 0;
  reader.code._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&reader.code._Bx._Alias[4], L"object", 6u);
  v30 = &reader;
  LOBYTE(v198) = 62;
  v186 = &reader;
  v31 = this->scrapeEvents;
  v187 = 3;
  do
  {
    v32 = std::operator+<wchar_t>(&path, L"event:/collisions/", (const std::wstring *)v30);
    LOBYTE(v198) = 63;
    std::operator+<wchar_t>(&hitEventName, v32, L"/hit");
    LOBYTE(v198) = 65;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    path._Myres = 7;
    path._Bx._Buf[0] = 0;
    path._Mysize = 0;
    v33 = std::operator+<wchar_t>(&result, L"event:/collisions/", (const std::wstring *)v30);
    LOBYTE(v198) = 66;
    std::operator+<wchar_t>(&positionOption, v33, L"/scrape");
    LOBYTE(v198) = 68;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Bx._Buf[0] = 0;
    result._Myres = 7;
    result._Mysize = 0;
    if ( AudioEngine::hasEvent(engine, &hitEventName) )
    {
      v34 = (CarAudioFMOD *)operator new(48);
      v182.__this = v34;
      LOBYTE(v198) = 69;
      if ( v34 )
        AudioEvent::AudioEvent((AudioEvent *)v34, v28->game->audioEngine, &hitEventName, Off);
      else
        v35 = 0;
      v36 = v31[-3]._Myptr;
      LOBYTE(v198) = 68;
      v31[-3]._Myptr = v35;
      if ( v36 )
      {
        AudioEvent::~AudioEvent(v36);
        operator delete(v36);
      }
    }
    if ( AudioEngine::hasEvent(engine, &positionOption) )
    {
      v37 = (CarAudioFMOD *)operator new(48);
      v182.__this = v37;
      LOBYTE(v198) = 70;
      if ( v37 )
        AudioEvent::AudioEvent((AudioEvent *)v37, v28->game->audioEngine, &positionOption, Off);
      else
        v38 = 0;
      v39 = v31->_Myptr;
      LOBYTE(v198) = 68;
      v31->_Myptr = v38;
      if ( v39 )
      {
        AudioEvent::~AudioEvent(v39);
        operator delete(v39);
      }
    }
    v40 = positionOption._Myres < 8;
    v31[3]._Myptr = 0;
    if ( !v40 )
      operator delete(positionOption._Bx._Ptr);
    positionOption._Myres = 7;
    positionOption._Mysize = 0;
    positionOption._Bx._Buf[0] = 0;
    LOBYTE(v198) = 62;
    if ( hitEventName._Myres >= 8 )
      operator delete(hitEventName._Bx._Ptr);
    ++v31;
    v30 = (INIReader *)&v186->filename._Mysize;
    v41 = v187-- == 1;
    v186 = (INIReader *)((char *)v186 + 24);
  }
  while ( !v41 );
  LOBYTE(v198) = 59;
  `eh vector destructor iterator'(&reader, 0x18u, 3, (void (*)(void *))std::wstring::~wstring);
  v42 = carUnixName;
  v43 = std::operator+<wchar_t>(&result, L"event:/cars/", carUnixName);
  LOBYTE(v198) = 71;
  v44 = std::operator+<wchar_t>(&path, v43, L"/horn");
  LOBYTE(v198) = 72;
  v45 = AudioEngine::hasEvent(engine, v44);
  v46 = v179;
  v175 = v45;
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  LOBYTE(v198) = 59;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v175 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 73;
    if ( carUnixName )
    {
      v47 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 74;
      v176 = 1;
      v48 = std::operator+<wchar_t>(&path, v47, L"/horn");
      v49 = v181;
      v46 = 3;
      volume = 0.0;
      v173._Myres = (unsigned int)v48;
      v50 = v181->game;
      v198 = 75;
      v176 = 3;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, v50->audioEngine, (const std::wstring *)v173._Myres, Off);
      v52 = v51;
    }
    else
    {
      v49 = v181;
      v52 = 0;
    }
    v53 = (std::wstring *)this->hornEvent._Myptr;
    v198 = 77;
    carUnixName = v53;
    this->hornEvent._Myptr = v52;
    if ( v53 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v53);
      operator delete(carUnixName);
    }
    if ( (v46 & 2) != 0 )
    {
      v46 &= 0xFFFFFFFD;
      v176 = v46;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( (v46 & 1) != 0 )
    {
      v46 &= 0xFFFFFFFE;
      v176 = v46;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  else
  {
    v49 = v181;
  }
  positionOption._Myres = 7;
  positionOption._Mysize = 0;
  positionOption._Bx._Buf[0] = 0;
  std::wstring::assign(&positionOption, L"event:/common/ds_protection", 0x1Bu);
  LOBYTE(v198) = 78;
  v54 = AudioEngine::hasEvent(engine, &positionOption);
  v175 = v54;
  LOBYTE(v198) = 59;
  if ( positionOption._Myres >= 8 )
  {
    operator delete(positionOption._Bx._Ptr);
    v54 = v175;
  }
  if ( v54 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 79;
    if ( carUnixName )
    {
      std::wstring::wstring(&path, L"event:/common/ds_protection");
      volume = 0.0;
      v173._Myres = (unsigned int)&path;
      v55 = v49->game;
      v46 |= 4u;
      LOBYTE(v198) = 80;
      v176 = v46;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, v55->audioEngine, &path, Off);
      v57 = v56;
    }
    else
    {
      v57 = 0;
    }
    v58 = (std::wstring *)this->downShiftEvent._Myptr;
    v198 = 81;
    carUnixName = v58;
    this->downShiftEvent._Myptr = v57;
    if ( v58 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v58);
      operator delete(carUnixName);
    }
    v198 = 59;
    if ( (v46 & 4) != 0 )
    {
      v46 &= 0xFFFFFFFB;
      v176 = v46;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
    }
  }
  v59 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
  LOBYTE(v198) = 82;
  v60 = std::operator+<wchar_t>(&path, v59, L"/gear_grind");
  LOBYTE(v198) = 83;
  v175 = AudioEngine::hasEvent(engine, v60);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  LOBYTE(v198) = 59;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v175 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 84;
    if ( carUnixName )
    {
      v61 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 85;
      v62 = v46 | 8;
      v176 = v62;
      v63 = std::operator+<wchar_t>(&path, v61, L"/gear_grind");
      v46 = v62 | 0x10;
      volume = 0.0;
      v173._Myres = (unsigned int)v63;
      v64 = v49->game;
      v198 = 86;
      v176 = v46;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, v64->audioEngine, (const std::wstring *)v173._Myres, Off);
      v66 = v65;
    }
    else
    {
      v66 = 0;
    }
    v67 = (std::wstring *)this->gearGrindEvent._Myptr;
    v198 = 88;
    carUnixName = v67;
    this->gearGrindEvent._Myptr = v66;
    if ( v67 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v67);
      operator delete(carUnixName);
    }
    if ( (v46 & 0x10) != 0 )
    {
      v46 &= 0xFFFFFFEF;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( (v46 & 8) != 0 )
    {
      v46 &= 0xFFFFFFF7;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  v68 = std::operator+<wchar_t>(&v194, L"event:/cars/", v42);
  LOBYTE(v198) = 89;
  v69 = v46 | 0x20;
  v176 = v69;
  v70 = std::operator+<wchar_t>(&hitEventName, v68, L"/backfire_ext");
  v71 = v69 | 0x40;
  v198 = 90;
  v176 = v71;
  if ( !AudioEngine::hasEvent(engine, v70) )
    goto LABEL_105;
  v72 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
  v198 = 91;
  v73 = v71 | 0x80;
  v176 = v73;
  v74 = std::operator+<wchar_t>(&path, v72, L"/backfire_int");
  v71 = v73 | 0x100;
  v198 = 92;
  v176 = v71;
  v75 = AudioEngine::hasEvent(engine, v74);
  v175 = 1;
  if ( !v75 )
LABEL_105:
    v175 = 0;
  if ( (v71 & 0x100) != 0 )
  {
    v71 &= 0xFFFFFEFF;
    v176 = v71;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    path._Myres = 7;
    path._Mysize = 0;
    path._Bx._Buf[0] = 0;
  }
  if ( (v71 & 0x80u) != 0 )
  {
    v71 &= 0xFFFFFF7F;
    v176 = v71;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  if ( (v71 & 0x40) != 0 )
  {
    v71 &= 0xFFFFFFBF;
    v176 = v71;
    if ( hitEventName._Myres >= 8 )
      operator delete(hitEventName._Bx._Ptr);
    hitEventName._Myres = 7;
    hitEventName._Mysize = 0;
    hitEventName._Bx._Buf[0] = 0;
  }
  v198 = 59;
  if ( (v71 & 0x20) != 0 )
  {
    v71 &= 0xFFFFFFDF;
    v176 = v71;
    if ( v194._Myres >= 8 )
      operator delete(v194._Bx._Ptr);
  }
  if ( v175 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 93;
    if ( carUnixName )
    {
      v76 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 94;
      v77 = v71 | 0x200;
      v176 = v77;
      v78 = std::operator+<wchar_t>(&path, v76, L"/backfire_ext");
      v71 = v77 | 0x400;
      v198 = 95;
      v176 = v71;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, engine, v78, On);
      v80 = v79;
    }
    else
    {
      v80 = 0;
    }
    v81 = (std::wstring *)this->backfireExtEvent._Myptr;
    v198 = 97;
    carUnixName = v81;
    this->backfireExtEvent._Myptr = v80;
    if ( v81 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v81);
      operator delete(carUnixName);
    }
    if ( (v71 & 0x400) != 0 )
    {
      v71 &= 0xFFFFFBFF;
      v176 = v71;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( (v71 & 0x200) != 0 )
    {
      v71 &= 0xFFFFFDFF;
      v176 = v71;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 98;
    if ( carUnixName )
    {
      v82 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 99;
      v83 = v71 | 0x800;
      v176 = v83;
      v84 = std::operator+<wchar_t>(&path, v82, L"/backfire_int");
      v71 = v83 | 0x1000;
      v198 = 100;
      v176 = v71;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, engine, v84, Off);
      v86 = v85;
    }
    else
    {
      v86 = 0;
    }
    v87 = (std::wstring *)this->backfireIntEvent._Myptr;
    v198 = 102;
    carUnixName = v87;
    this->backfireIntEvent._Myptr = v86;
    if ( v87 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v87);
      operator delete(carUnixName);
    }
    if ( (v71 & 0x1000) != 0 )
    {
      v71 &= 0xFFFFEFFF;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( (v71 & 0x800) != 0 )
    {
      v71 &= 0xFFFFF7FF;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  v88 = std::operator+<wchar_t>(&v194, L"event:/cars/", v42);
  LOBYTE(v198) = 103;
  v89 = v71 | 0x2000;
  v176 = v89;
  v90 = std::operator+<wchar_t>(&hitEventName, v88, L"/tractioncontrol_ext");
  v91 = v89 | 0x4000;
  v198 = 104;
  v176 = v91;
  if ( !AudioEngine::hasEvent(engine, v90) )
    goto LABEL_148;
  v92 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
  v198 = 105;
  v93 = v91 | 0x8000;
  v176 = v93;
  v94 = std::operator+<wchar_t>(&path, v92, L"/tractioncontrol_int");
  v91 = v93 | 0x10000;
  v198 = 106;
  v176 = v91;
  v95 = AudioEngine::hasEvent(engine, v94);
  v175 = 1;
  if ( !v95 )
LABEL_148:
    v175 = 0;
  if ( (v91 & 0x10000) != 0 )
  {
    v91 &= 0xFFFEFFFF;
    v176 = v91;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    path._Myres = 7;
    path._Mysize = 0;
    path._Bx._Buf[0] = 0;
  }
  if ( (v91 & 0x8000) != 0 )
  {
    v91 &= 0xFFFF7FFF;
    v176 = v91;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  if ( (v91 & 0x4000) != 0 )
  {
    v91 &= 0xFFFFBFFF;
    v176 = v91;
    if ( hitEventName._Myres >= 8 )
      operator delete(hitEventName._Bx._Ptr);
    hitEventName._Myres = 7;
    hitEventName._Mysize = 0;
    hitEventName._Bx._Buf[0] = 0;
  }
  v198 = 59;
  if ( (v91 & 0x2000) != 0 )
  {
    v91 &= 0xFFFFDFFF;
    v176 = v91;
    if ( v194._Myres >= 8 )
      operator delete(v194._Bx._Ptr);
  }
  if ( v175 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 107;
    if ( carUnixName )
    {
      v96 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 108;
      v97 = v91 | 0x20000;
      v176 = v97;
      v98 = std::operator+<wchar_t>(&path, v96, L"/tractioncontrol_ext");
      v91 = v97 | 0x40000;
      LODWORD(volume) = 1;
      v173._Myres = (unsigned int)v98;
      v99 = v49->game;
      v198 = 109;
      v176 = v91;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, v99->audioEngine, (const std::wstring *)v173._Myres, On);
      v101 = v100;
    }
    else
    {
      v101 = 0;
    }
    v102 = (std::wstring *)this->tractionControlExtEvent._Myptr;
    v198 = 111;
    carUnixName = v102;
    this->tractionControlExtEvent._Myptr = v101;
    if ( v102 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v102);
      operator delete(carUnixName);
    }
    if ( (v91 & 0x40000) != 0 )
    {
      v91 &= 0xFFFBFFFF;
      v176 = v91;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( (v91 & 0x20000) != 0 )
    {
      v91 &= 0xFFFDFFFF;
      v176 = v91;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 112;
    if ( carUnixName )
    {
      v103 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 113;
      v104 = v91 | 0x80000;
      v176 = v104;
      v105 = std::operator+<wchar_t>(&path, v103, L"/tractioncontrol_int");
      v91 = v104 | 0x100000;
      volume = 0.0;
      v173._Myres = (unsigned int)v105;
      v106 = v49->game;
      v198 = 114;
      v176 = v91;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, v106->audioEngine, (const std::wstring *)v173._Myres, Off);
      v108 = v107;
    }
    else
    {
      v108 = 0;
    }
    v109 = (std::wstring *)this->tractionControlIntEvent._Myptr;
    v198 = 116;
    carUnixName = v109;
    this->tractionControlIntEvent._Myptr = v108;
    if ( v109 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v109);
      operator delete(carUnixName);
    }
    if ( (v91 & 0x100000) != 0 )
    {
      v91 &= 0xFFEFFFFF;
      v176 = v91;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( (v91 & 0x80000) != 0 )
    {
      v91 &= 0xFFF7FFFF;
      v176 = v91;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  v110 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
  LOBYTE(v198) = 117;
  v111 = std::operator+<wchar_t>(&path, v110, L"/transmission");
  LOBYTE(v198) = 118;
  v175 = AudioEngine::hasEvent(engine, v111);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  LOBYTE(v198) = 59;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v175 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 119;
    if ( carUnixName )
    {
      v112 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 120;
      v113 = v91 | 0x200000;
      v176 = v113;
      v114 = std::operator+<wchar_t>(&path, v112, L"/transmission");
      v91 = (unsigned int)&_ImageBase | v113;
      volume = 0.0;
      v173._Myres = (unsigned int)v114;
      v115 = v49->game;
      v198 = 121;
      v176 = v91;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, v115->audioEngine, (const std::wstring *)v173._Myres, Off);
      v117 = v116;
    }
    else
    {
      v117 = 0;
    }
    v118 = (std::wstring *)this->transmissionEvent._Myptr;
    v198 = 123;
    carUnixName = v118;
    this->transmissionEvent._Myptr = v117;
    if ( v118 )
    {
      AudioEvent::~AudioEvent((AudioEvent *)v118);
      operator delete(carUnixName);
    }
    if ( ((unsigned int)&_ImageBase & v91) != 0 )
    {
      v91 &= 0xFFBFFFFF;
      v176 = v91;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( (v91 & 0x200000) != 0 )
    {
      v91 &= 0xFFDFFFFF;
      v176 = v91;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  v119 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
  LOBYTE(v198) = 124;
  v120 = std::operator+<wchar_t>(&path, v119, L"/limiter");
  LOBYTE(v198) = 125;
  v175 = AudioEngine::hasEvent(engine, v120);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  LOBYTE(v198) = 59;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v175 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = 126;
    if ( carUnixName )
    {
      v121 = std::operator+<wchar_t>(&result, L"event:/cars/", v42);
      LOBYTE(v198) = 127;
      v122 = (unsigned int)&loc_800000 | v91;
      v176 = v122;
      v123 = std::operator+<wchar_t>(&path, v121, L"/limiter");
      v91 = (unsigned int)&unk_1000000 | v122;
      volume = 0.0;
      v173._Myres = (unsigned int)v123;
      v124 = v49->game;
      v198 = 128;
      v176 = v91;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, v124->audioEngine, (const std::wstring *)v173._Myres, Off);
    }
    else
    {
      v125 = 0;
    }
    v126 = this->limiterEvent._Myptr;
    v198 = 130;
    this->limiterEvent._Myptr = v125;
    if ( v126 )
    {
      AudioEvent::~AudioEvent(v126);
      operator delete(v126);
    }
    if ( ((unsigned int)&unk_1000000 & v91) != 0 )
    {
      v91 &= 0xFEFFFFFF;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
    }
    v198 = 59;
    if ( ((unsigned int)&loc_800000 & v91) != 0 )
    {
      v91 &= 0xFF7FFFFF;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  LODWORD(volume) = v42;
  v175 = 0;
  v173._Myres = (unsigned int)L"content/cars/";
  v173._Mysize = (unsigned int)&result;
  this->maxTurboBoost = 0.0;
  v127 = std::operator+<wchar_t>(
           (std::wstring *)v173._Mysize,
           (const wchar_t *)v173._Myres,
           (const std::wstring *)LODWORD(volume));
  LOBYTE(v198) = -125;
  v128 = std::operator+<wchar_t>(&path, v127, L"/data/engine.ini");
  v129 = v181;
  LOBYTE(v198) = -124;
  CarAvatar::openINI(v181, &reader, v128);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  LOBYTE(v198) = -121;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v130 = 0.0;
  *(_DWORD *)turboSection.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)turboSection.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(turboSection.gap68);
  LOBYTE(v198) = -120;
  v179 = v91 | 0x40000000;
  v176 = v91 | 0x40000000;
  std::wiostream::basic_iostream<wchar_t>(&turboSection, &turboSection.gap10[8], 0);
  v198 = 137;
  *(_DWORD *)&turboSection.gap0[*(_DWORD *)(*(_DWORD *)turboSection.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(CarAudioFMOD **)((char *)&v188 + *(_DWORD *)(*(_DWORD *)turboSection.gap0 + 4)) = (CarAudioFMOD *)(*(_DWORD *)(*(_DWORD *)turboSection.gap0 + 4) - 104);
  std::wstreambuf::wstreambuf(&turboSection.gap10[8]);
  *(_DWORD *)&turboSection.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&turboSection.gap10[64] = 0;
  *(_DWORD *)&turboSection.gap10[68] = 0;
  v131 = v175;
  LOBYTE(v198) = -117;
  while ( 1 )
  {
    std::wstring::wstring(&positionOption, word_17BE9D8);
    LOBYTE(v198) = -116;
    std::wstringbuf::_Tidy((std::wstringbuf *)&turboSection.gap10[8]);
    volume = *(float *)&turboSection.gap10[68];
    v132 = &positionOption;
    v173._Myres = positionOption._Mysize;
    if ( positionOption._Myres >= 8 )
      v132 = (std::wstring *)positionOption._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&turboSection.gap10[8], v132->_Bx._Buf, v173._Myres, SLODWORD(volume));
    LOBYTE(v198) = -117;
    if ( positionOption._Myres >= 8 )
      operator delete(positionOption._Bx._Ptr);
    volume = v130;
    v133 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)turboSection.gap10, "TURBO_");
    std::wostream::operator<<(v133, LODWORD(volume));
    ++LODWORD(v130);
    v134 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&turboSection, &path);
    LOBYTE(v198) = -115;
    v135 = INIReader::hasSection(&reader, v134);
    LOBYTE(v198) = -117;
    v136 = !v135;
    v175 = v136;
    if ( path._Myres >= 8 )
    {
      operator delete(path._Bx._Ptr);
      v136 = v175;
    }
    if ( v136 )
      break;
    v131 = 1;
    std::wstring::wstring(&result, L"MAX_BOOST");
    LOBYTE(v198) = -114;
    v137 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&turboSection, &path);
    LOBYTE(v198) = -113;
    v138 = INIReader::getFloat(&reader, v137, &result);
    v40 = path._Myres < 8;
    this->maxTurboBoost = v138 + this->maxTurboBoost;
    if ( !v40 )
      operator delete(path._Bx._Ptr);
    path._Myres = 7;
    path._Mysize = 0;
    path._Bx._Buf[0] = 0;
    LOBYTE(v198) = -117;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v41 = v131 == 0;
  v139 = v179;
  if ( v41 )
    goto LABEL_241;
  v140 = std::operator+<wchar_t>(&result, L"event:/cars/", &v129->unixName);
  LOBYTE(v198) = -112;
  v141 = v139 | 0x2000000;
  v176 = v141;
  v142 = std::operator+<wchar_t>(&path, v140, L"/turbo");
  v139 = v141 | 0x4000000;
  v198 = 145;
  v179 = v139;
  v176 = v139;
  v143 = AudioEngine::hasEvent(engine, v142);
  v175 = 1;
  if ( !v143 )
LABEL_241:
    v175 = 0;
  if ( (v139 & 0x4000000) != 0 )
  {
    v139 &= 0xFBFFFFFF;
    v179 = v139;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    path._Myres = 7;
    path._Mysize = 0;
    path._Bx._Buf[0] = 0;
  }
  v198 = 139;
  if ( (v139 & 0x2000000) != 0 )
  {
    v139 &= 0xFDFFFFFF;
    v179 = v139;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  }
  if ( v175 )
  {
    carUnixName = (std::wstring *)operator new(48);
    LOBYTE(v198) = -110;
    if ( carUnixName )
    {
      v144 = std::operator+<wchar_t>(&result, L"event:/cars/", &v129->unixName);
      LOBYTE(v198) = -109;
      v145 = v139 | 0x8000000;
      v176 = v145;
      v146 = std::operator+<wchar_t>(&path, v144, L"/turbo");
      v139 = v145 | 0x10000000;
      v198 = 148;
      v179 = v139;
      v176 = v139;
      AudioEvent::AudioEvent((AudioEvent *)carUnixName, engine, v146, Off);
    }
    else
    {
      v147 = 0;
    }
    std::unique_ptr<AudioEvent>::reset(&this->turboEvent, v147);
    if ( (v139 & 0x10000000) != 0 )
    {
      v139 &= 0xEFFFFFFF;
      v179 = v139;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    }
    v198 = 139;
    if ( (v139 & 0x8000000) != 0 )
    {
      v179 = v139 & 0xF7FFFFFF;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    }
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&turboSection);
  LOBYTE(v198) = 59;
  INIReader::~INIReader(&reader);
  std::vector<AudioEvent>::reserve((std::vector<AudioEvent> *)v185._Ptr, 4u);
  v148 = 4;
  do
  {
    v149 = std::operator+<wchar_t>(&result, L"event:/cars/", &v129->unixName);
    LOBYTE(v198) = -105;
    LODWORD(volume) = std::operator+<wchar_t>(&path, v149, L"/wheel");
    v150 = &v129->game->audioEngine;
    LOBYTE(v198) = -104;
    std::vector<AudioEvent>::emplace_back<AudioEngine * &,std::wstring>(
      (std::vector<AudioEvent> *)v185._Ptr,
      v150,
      (std::wstring *)LODWORD(volume));
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    LOBYTE(v198) = 59;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    --v148;
  }
  while ( v148 );
  std::vector<AudioEvent>::reserve((std::vector<AudioEvent> *)v180, 4u);
  v151 = _This;
  v152 = 0;
  v180 = On;
  do
  {
    v153 = std::operator+<wchar_t>(&result, L"event:/cars/", &v129->unixName);
    LOBYTE(v198) = -103;
    v154 = std::operator+<wchar_t>(&path, v153, L"/skid_ext");
    LOBYTE(v198) = -102;
    std::vector<AudioEvent>::emplace_back<AudioEngine * &,std::wstring,enum EventReverbResponse>(
      &v151->skidExtEvents,
      &v129->game->audioEngine,
      v154,
      &v180);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    LOBYTE(v198) = 59;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    volume = 0.0;
    v155 = std::vector<AudioEvent>::operator[](&v151->skidExtEvents, v152);
    AudioEvent::setBaseVolume(v155, volume);
    ++v152;
  }
  while ( v152 < 4 );
  std::vector<AudioEvent>::reserve(v184, 4u);
  v156 = v179;
  for ( i = 0; i < 4; ++i )
  {
    v158 = std::operator+<wchar_t>(&result, L"event:/cars/", &v129->unixName);
    LOBYTE(v198) = -101;
    LODWORD(volume) = std::operator+<wchar_t>(&path, v158, L"/skid_int");
    v159 = &v129->game->audioEngine;
    LOBYTE(v198) = -100;
    std::vector<AudioEvent>::emplace_back<AudioEngine * &,std::wstring>(v184, v159, (std::wstring *)LODWORD(volume));
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    LOBYTE(v198) = 59;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    volume = 0.0;
    v160 = std::vector<AudioEvent>::operator[](v184, i);
    AudioEvent::setBaseVolume(v160, volume);
  }
  v161 = _This;
  LODWORD(volume) = _This;
  CommandItem::CommandItem(&v182, _This);
  std::function<void __cdecl (OnValueChanged const &)>::function<void __cdecl (OnValueChanged const &)>(
    (std::function<void __cdecl(OnValueChanged const &)> *)&v173,
    v162);
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v129->evOnGearChanged.Event<OnValueChanged>,
    (std::function<void __cdecl(SessionInfo const &)>)v173,
    (void *)LODWORD(volume));
  v163 = std::operator+<wchar_t>(&v194, L"content/cars/", &v129->unixName);
  LOBYTE(v198) = -99;
  v164 = std::operator+<wchar_t>(&hitEventName, v163, L"/data/sounds.ini");
  LOBYTE(v198) = -98;
  CarAvatar::openINI(v129, &reader, v164);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&hitEventName);
  LOBYTE(v198) = -95;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v194);
  if ( !reader.ready
    || (std::wstring::wstring(&path, L"ENGINE"),
        LOBYTE(v198) = -94,
        v156 |= 0x20000000u,
        v176 = v156,
        v165 = INIReader::hasSection(&reader, &path),
        v175 = 1,
        !v165) )
  {
    v175 = 0;
  }
  v198 = 161;
  if ( (v156 & 0x20000000) != 0 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
  if ( v175 )
  {
    std::wstring::wstring(&result, L"POSITION");
    LOBYTE(v198) = -93;
    std::wstring::wstring(&path, L"ENGINE");
    LOBYTE(v198) = -92;
    INIReader::getString(&reader, &positionOption, &path, &result);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    LOBYTE(v198) = -89;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    v166 = std::wstring::begin(
             &positionOption,
             (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&v182);
    v167 = std::wstring::end(
             &positionOption,
             (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&v180);
    v168 = std::wstring::begin(
             &positionOption,
             (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&_This);
    std::transform<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
      &v185,
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v168->_Ptr,
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v167->_Ptr,
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v166->_Ptr,
      _tolower);
    if ( std::operator==<wchar_t>(&positionOption, L"front") )
    {
      v161->enginePosition = ENGINEPOSITION_FRONT;
    }
    else if ( std::operator==<wchar_t>(&positionOption, L"rear") )
    {
      v161->enginePosition = ENGINEPOSITION_REAR;
    }
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&positionOption);
    v129 = v181;
  }
  LOBYTE(v198) = 59;
  INIReader::~INIReader(&reader);
  if ( CarAudioFMOD::isOpponentCar(v161) )
    v169 = FLOAT_10_0;
  else
    v169 = 0.0;
  LODWORD(volume) = v161;
  v173._Myres = (unsigned int)v161;
  v161->gas.alpha = v169;
  v161->bodyworkVolume.alpha = 3.2;
  CommandItem::CommandItem(&v182, (CarAudioFMOD *)v173._Myres);
  std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
    (std::function<void __cdecl(bool const &)> *)&v173,
    v170);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v129->evOnDownshiftProtection,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v173,
    (void *)LODWORD(volume));
  LODWORD(volume) = v161;
  CommandItem::CommandItem(&v182, v161);
  std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
    (std::function<void __cdecl(bool const &)> *)&v173,
    v171);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v129->evOnBackfireTriggered,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v173,
    (void *)LODWORD(volume));
  v172 = engine;
  v161->skidVolumes[0].alpha = v161->skidParams.smoothAlhpa;
  v161->skidPitches[0].alpha = v161->skidParams.smoothAlhpa;
  v161->skidVolumes[1].alpha = v161->skidParams.smoothAlhpa;
  v161->skidPitches[1].alpha = v161->skidParams.smoothAlhpa;
  v161->skidVolumes[2].alpha = v161->skidParams.smoothAlhpa;
  v161->skidPitches[2].alpha = v161->skidParams.smoothAlhpa;
  v161->skidVolumes[3].alpha = v161->skidParams.smoothAlhpa;
  v161->skidPitches[3].alpha = v161->skidParams.smoothAlhpa;
  v161->limiterDecay = 0.0;
  AudioEngine::updateProperties(v172);
}
void CarAudioFMOD::~CarAudioFMOD(CarAudioFMOD *this)
{
  std::array<CarAudioFMOD::SurfaceList,4> *v2; // ebp
  EnginePosition *v3; // esi
  AudioEvent **v4; // ebx
  AudioEngine *v5; // ecx
  std::vector<AudioEvent> *v6; // ebx
  AudioEvent *v7; // ebp
  AudioEvent *i; // esi
  std::vector<AudioEvent> *v9; // ebx
  AudioEvent *v10; // ebp
  AudioEvent *j; // esi
  std::vector<AudioEvent> *v12; // ebx
  AudioEvent *v13; // ebp
  AudioEvent *k; // esi
  AudioEvent *v15; // esi
  AudioEvent *v16; // esi
  AudioEvent *v17; // esi
  AudioEvent *v18; // esi
  AudioEvent *v19; // esi
  AudioEvent *v20; // esi
  AudioEvent *v21; // esi
  AudioEvent *v22; // esi
  AudioEvent *v23; // esi
  AudioEvent *v24; // esi
  std::wstring *v25; // esi

  this->__vftable = (CarAudioFMOD_vtbl *)&CarAudioFMOD::`vftable';
  v2 = &this->surfaceEvents;
  v3 = &this->enginePosition;
  if ( &this->surfaceEvents != (std::array<CarAudioFMOD::SurfaceList,4> *)&this->enginePosition )
  {
    v4 = &this->surfaceEvents._Elems[0].event;
    do
    {
      if ( *v4 )
      {
        v5 = this->car->game->audioEngine;
        if ( v5 )
          AudioEngine::releaseCachedEvent(v5, *v4);
      }
      v4 += 7;
    }
    while ( v4 - 6 != (AudioEvent **)v3 );
  }
  `eh vector destructor iterator'(
    v2,
    0x1Cu,
    4,
    (void (*)(void *))std::pair<std::wstring,jsonwriter::Node &>::~pair<std::wstring,jsonwriter::Node &>);
  v6 = &this->skidIntEvents;
  if ( this->skidIntEvents._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->skidIntEvents);
    v7 = this->skidIntEvents._Mylast;
    for ( i = v6->_Myfirst; i != v7; ++i )
      AudioEvent::~AudioEvent(i);
    operator delete(v6->_Myfirst);
    v6->_Myfirst = 0;
    this->skidIntEvents._Mylast = 0;
    this->skidIntEvents._Myend = 0;
  }
  v9 = &this->skidExtEvents;
  if ( this->skidExtEvents._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->skidExtEvents);
    v10 = this->skidExtEvents._Mylast;
    for ( j = v9->_Myfirst; j != v10; ++j )
      AudioEvent::~AudioEvent(j);
    operator delete(v9->_Myfirst);
    v9->_Myfirst = 0;
    this->skidExtEvents._Mylast = 0;
    this->skidExtEvents._Myend = 0;
  }
  v12 = &this->wheelEvents;
  if ( this->wheelEvents._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->wheelEvents);
    v13 = this->wheelEvents._Mylast;
    for ( k = v12->_Myfirst; k != v13; ++k )
      AudioEvent::~AudioEvent(k);
    operator delete(v12->_Myfirst);
    v12->_Myfirst = 0;
    this->wheelEvents._Mylast = 0;
    this->wheelEvents._Myend = 0;
  }
  v15 = this->turboEvent._Myptr;
  if ( v15 )
  {
    AudioEvent::~AudioEvent(v15);
    operator delete(v15);
  }
  v16 = this->limiterEvent._Myptr;
  if ( v16 )
  {
    AudioEvent::~AudioEvent(v16);
    operator delete(v16);
  }
  v17 = this->transmissionEvent._Myptr;
  if ( v17 )
  {
    AudioEvent::~AudioEvent(v17);
    operator delete(v17);
  }
  v18 = this->tractionControlIntEvent._Myptr;
  if ( v18 )
  {
    AudioEvent::~AudioEvent(v18);
    operator delete(v18);
  }
  v19 = this->tractionControlExtEvent._Myptr;
  if ( v19 )
  {
    AudioEvent::~AudioEvent(v19);
    operator delete(v19);
  }
  v20 = this->backfireIntEvent._Myptr;
  if ( v20 )
  {
    AudioEvent::~AudioEvent(v20);
    operator delete(v20);
  }
  v21 = this->backfireExtEvent._Myptr;
  if ( v21 )
  {
    AudioEvent::~AudioEvent(v21);
    operator delete(v21);
  }
  v22 = this->gearGrindEvent._Myptr;
  if ( v22 )
  {
    AudioEvent::~AudioEvent(v22);
    operator delete(v22);
  }
  v23 = this->hornEvent._Myptr;
  if ( v23 )
  {
    AudioEvent::~AudioEvent(v23);
    operator delete(v23);
  }
  v24 = this->downShiftEvent._Myptr;
  if ( v24 )
  {
    AudioEvent::~AudioEvent(v24);
    operator delete(v24);
  }
  AudioEvent::~AudioEvent(&this->windEvent);
  AudioEvent::~AudioEvent(&this->bodyworkEvent);
  AudioEvent::~AudioEvent(&this->gearIntEvent);
  AudioEvent::~AudioEvent(&this->gearExtEvent);
  AudioEvent::~AudioEvent(&this->engineIntEvent);
  AudioEvent::~AudioEvent(&this->engineExtEvent);
  v25 = &this->bank.path;
  AudioEngine::removeBankRef(this->bank.engine, &this->bank.path);
  if ( this->bank.path._Myres >= 8 )
    operator delete(v25->_Bx._Ptr);
  this->bank.path._Myres = 7;
  this->bank.path._Mysize = 0;
  v25->_Bx._Buf[0] = 0;
  AudioEvent::~AudioEvent(&this->dirtEvent);
  `eh vector destructor iterator'(
    this->scrapeEvents,
    4u,
    3,
    (void (*)(void *))std::unique_ptr<AudioEvent>::~unique_ptr<AudioEvent>);
  `eh vector destructor iterator'(
    this->hitEvents,
    4u,
    3,
    (void (*)(void *))std::unique_ptr<AudioEvent>::~unique_ptr<AudioEvent>);
  GameObject::~GameObject(this);
}
CarAudioFMOD *CarAudioFMOD::`vector deleting destructor'(CarAudioFMOD *this, unsigned int a2)
{
  CarAudioFMOD::~CarAudioFMOD(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CarAudioFMOD::computeTransforms(CarAudioFMOD *this, mat44f *carTransform, mat44f *engineTransform, mat44f *backfiresTransform, mat44f *hoodTrasform)
{
  unsigned int v6; // esi
  ACCameraManager *v7; // eax
  bool v8; // cl
  CarAvatar *v9; // eax
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  EnginePosition v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  mat44f *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  __m128i v27; // xmm5
  __m128i v28; // xmm6
  __m128i v29; // xmm7
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  __m128i v33; // xmm0
  __m128i v34; // xmm0
  __m128i v35; // xmm3
  EnginePosition v36; // ecx
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v40; // xmm2_4
  __m128i v41; // xmm0
  float v42; // xmm3_4
  __m128i listenerPosition; // [esp+8h] [ebp-B0h] OVERLAPPED BYREF
  __m128i v44; // [esp+18h] [ebp-A0h] BYREF
  __m128i v45; // [esp+28h] [ebp-90h] BYREF
  mat44f rearAxle; // [esp+38h] [ebp-80h] BYREF
  mat44f frontAxle; // [esp+78h] [ebp-40h] BYREF

  v6 = Sim::getFocusedCarIndex(this->car->sim);
  v8 = 0;
  if ( CarAvatar::getGuid(this->car) == v6 )
  {
    v7 = this->cameraManager;
    if ( v7 )
    {
      if ( v7->mode == eCockpit )
        v8 = 1;
    }
  }
  v9 = this->car;
  *(__m128i *)&carTransform->M11 = _mm_loadu_si128((const __m128i *)&v9->physicsState.worldMatrix);
  *(__m128i *)&carTransform->M21 = _mm_loadu_si128((const __m128i *)&v9->physicsState.worldMatrix.M21);
  *(__m128i *)&carTransform->M31 = _mm_loadu_si128((const __m128i *)&v9->physicsState.worldMatrix.M31);
  *(__m128i *)&carTransform->M41 = _mm_loadu_si128((const __m128i *)&v9->physicsState.worldMatrix.M41);
  if ( v8 )
  {
    AudioEngine::getListenerPosition(this->car->game->audioEngine, (vec3f *)&listenerPosition);
    v10 = *(float *)listenerPosition.m128i_i32;
    v11 = *(float *)&listenerPosition.m128i_i32[1];
    v12 = *(float *)&listenerPosition.m128i_i32[2];
    *(__m128i *)&engineTransform->M11 = _mm_loadu_si128((const __m128i *)carTransform);
    *(__m128i *)&engineTransform->M21 = _mm_loadu_si128((const __m128i *)&carTransform->M21);
    *(__m128i *)&engineTransform->M31 = _mm_loadu_si128((const __m128i *)&carTransform->M31);
    *(__m128i *)&engineTransform->M41 = _mm_loadu_si128((const __m128i *)&carTransform->M41);
    v13 = this->enginePosition;
    if ( v13 == ENGINEPOSITION_FRONT )
    {
      v14 = engineTransform->M31 * 0.5;
      v15 = engineTransform->M32 * 0.5;
      v16 = engineTransform->M33 * 0.5;
    }
    else
    {
      if ( v13 != ENGINEPOSITION_REAR )
      {
        engineTransform->M41 = v10;
        engineTransform->M42 = v11;
        engineTransform->M43 = v12;
        goto LABEL_13;
      }
      v14 = engineTransform->M31 * -0.5;
      v15 = engineTransform->M32 * -0.5;
      v16 = engineTransform->M33 * -0.5;
    }
    engineTransform->M42 = v15 + v11;
    engineTransform->M41 = v14 + v10;
    engineTransform->M43 = v16 + v12;
LABEL_13:
    *(__m128i *)&backfiresTransform->M11 = _mm_loadu_si128((const __m128i *)carTransform);
    *(__m128i *)&backfiresTransform->M21 = _mm_loadu_si128((const __m128i *)&carTransform->M21);
    *(__m128i *)&backfiresTransform->M31 = _mm_loadu_si128((const __m128i *)&carTransform->M31);
    *(__m128i *)&backfiresTransform->M41 = _mm_loadu_si128((const __m128i *)&carTransform->M41);
    v17 = (float)(backfiresTransform->M32 * -0.5) + v11;
    v18 = (float)(backfiresTransform->M33 * -0.5) + v12;
    backfiresTransform->M41 = (float)(backfiresTransform->M31 * -0.5) + v10;
    backfiresTransform->M42 = v17;
    backfiresTransform->M43 = v18;
    v19 = hoodTrasform;
    *(__m128i *)&hoodTrasform->M11 = _mm_loadu_si128((const __m128i *)carTransform);
    *(__m128i *)&hoodTrasform->M21 = _mm_loadu_si128((const __m128i *)&carTransform->M21);
    *(__m128i *)&hoodTrasform->M31 = _mm_loadu_si128((const __m128i *)&carTransform->M31);
    *(__m128i *)&hoodTrasform->M41 = _mm_loadu_si128((const __m128i *)&carTransform->M41);
    v20 = (float)(hoodTrasform->M31 * 0.5) + v10;
    v21 = (float)(hoodTrasform->M32 * 0.5) + v11;
    v22 = (float)(hoodTrasform->M33 * 0.5) + v12;
    goto LABEL_19;
  }
  v23 = (float *)this->car;
  listenerPosition = _mm_loadu_si128((const __m128i *)carTransform);
  v24 = v23[202];
  v45 = _mm_loadu_si128((const __m128i *)&carTransform->M21);
  v25 = v24 + v23[218];
  v26 = v23[203] + v23[219];
  v44 = _mm_loadu_si128((const __m128i *)&carTransform->M31);
  v27 = listenerPosition;
  *(__m128i *)&frontAxle.M41 = _mm_loadu_si128((const __m128i *)&carTransform->M41);
  v28 = _mm_loadu_si128((const __m128i *)&carTransform->M21);
  v29 = _mm_loadu_si128((const __m128i *)&carTransform->M31);
  frontAxle.M41 = (float)(v23[201] + v23[217]) * 0.5;
  *(__m128i *)&rearAxle.M41 = _mm_loadu_si128((const __m128i *)&carTransform->M41);
  v30 = v23[233] + v23[249];
  frontAxle.M42 = v25 * 0.5;
  v31 = v23[234] + v23[250];
  frontAxle.M43 = v26 * 0.5;
  v32 = v23[235] + v23[251];
  rearAxle.M41 = v30 * 0.5;
  *(__m128i *)&engineTransform->M11 = _mm_loadu_si128((const __m128i *)carTransform);
  v33 = _mm_loadu_si128((const __m128i *)&carTransform->M21);
  rearAxle.M42 = v31 * 0.5;
  *(__m128i *)&engineTransform->M21 = v33;
  v34 = _mm_loadu_si128((const __m128i *)&carTransform->M31);
  rearAxle.M43 = v32 * 0.5;
  v35 = _mm_loadu_si128((const __m128i *)&rearAxle.M41);
  *(__m128i *)&engineTransform->M31 = v34;
  *(__m128i *)&engineTransform->M41 = _mm_loadu_si128((const __m128i *)&carTransform->M41);
  v36 = this->enginePosition;
  if ( v36 == ENGINEPOSITION_FRONT )
  {
    *(__m128i *)&engineTransform->M11 = _mm_loadu_si128(&listenerPosition);
    *(__m128i *)&engineTransform->M21 = _mm_loadu_si128(&v45);
    *(__m128i *)&engineTransform->M31 = _mm_loadu_si128(&v44);
    *(__m128i *)&engineTransform->M41 = _mm_loadu_si128((const __m128i *)&frontAxle.M41);
  }
  else if ( v36 == ENGINEPOSITION_REAR )
  {
    *(__m128i *)&engineTransform->M11 = v27;
    *(__m128i *)&engineTransform->M21 = v28;
    *(__m128i *)&engineTransform->M31 = v29;
    *(__m128i *)&engineTransform->M41 = v35;
    v37 = (float)(engineTransform->M32 * 0.5) + engineTransform->M42;
    v38 = (float)(engineTransform->M33 * 0.5) + engineTransform->M43;
    engineTransform->M41 = (float)(engineTransform->M31 * 0.5) + engineTransform->M41;
    engineTransform->M42 = v37;
    engineTransform->M43 = v38;
  }
  *(__m128i *)&backfiresTransform->M11 = v27;
  *(__m128i *)&backfiresTransform->M21 = v28;
  *(__m128i *)&backfiresTransform->M31 = v29;
  *(__m128i *)&backfiresTransform->M41 = v35;
  v40 = (float)(backfiresTransform->M32 * -0.5) + backfiresTransform->M42;
  v41 = _mm_loadu_si128((const __m128i *)&rearAxle.M41);
  v42 = (float)(backfiresTransform->M33 * -0.5) + backfiresTransform->M43;
  backfiresTransform->M41 = (float)(backfiresTransform->M31 * -0.5) + backfiresTransform->M41;
  backfiresTransform->M42 = v40;
  backfiresTransform->M43 = v42;
  v19 = hoodTrasform;
  *(__m128i *)&hoodTrasform->M11 = v27;
  *(__m128i *)&hoodTrasform->M21 = v28;
  *(__m128i *)&hoodTrasform->M31 = v29;
  *(__m128i *)&hoodTrasform->M41 = v41;
  v20 = (float)(hoodTrasform->M31 * 0.5) + hoodTrasform->M41;
  v21 = (float)(v19->M32 * 0.5) + v19->M42;
  v22 = (float)(v19->M33 * 0.5) + v19->M43;
LABEL_19:
  v19->M43 = v22;
  v19->M42 = v21;
  v19->M41 = v20;
}
bool CarAudioFMOD::isExternalCamera(CarAudioFMOD *this)
{
  ACCameraManager *v1; // eax
  bool result; // al
  CameraMode v3; // eax

  v1 = this->cameraManager;
  result = 0;
  if ( v1 )
  {
    v3 = v1->mode;
    if ( v3 == eFree || v3 == eTrack )
      result = 1;
  }
  return result;
}
BOOL CarAudioFMOD::isOpponentCar(CarAudioFMOD *this)
{
  return CarAvatar::getGuid(this->car) != 0;
}
void CarAudioFMOD::onCarHit(CarAudioFMOD *this, float normalForce, const vec3f *pos, const vec3f *normal, float impactAngle, float relativeSpeed, const unsigned int colliderCategory)
{
  int v8; // esi
  AudioEvent *v9; // ecx
  bool v10; // bl
  AudioEvent *v11; // ecx
  AudioEvent *v12; // ecx
  AudioEvent *v13; // ecx
  Speed result; // [esp+10h] [ebp-50h] BYREF
  vec3f velocity; // [esp+14h] [ebp-4Ch] BYREF
  mat44f transform; // [esp+20h] [ebp-40h] BYREF
  float relativeSpeeda; // [esp+74h] [ebp+14h]

  relativeSpeeda = Speed::fromMS(&result, relativeSpeed)->value * 3.5999999;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( relativeSpeeda >= 2.0 )
  {
    mat44f::mat44f(&transform);
    mat44f::loadIdentity(&transform);
    *(vec3f *)&transform.M41 = *pos;
    switch ( colliderCategory )
    {
      case 4u:
      case 8u:
        v8 = 0;
        break;
      case 0x10u:
        v8 = 2;
        break;
      default:
        v8 = 1;
        break;
    }
    v9 = this->hitEvents[v8]._Myptr;
    v10 = this->listenerPriority < 7;
    if ( v9 )
    {
      if ( !AudioEvent::isPlaying(v9) )
      {
        v11 = this->hitEvents[v8]._Myptr;
        velocity.x = 0.0;
        velocity.y = 0.0;
        velocity.z = 0.0;
        AudioEvent::set3DAttributes(v11, &transform, &velocity);
        AudioEvent::setParameter(this->hitEvents[v8]._Myptr, "impact_speed", relativeSpeeda);
        if ( !AudioEvent::isPlaying(this->hitEvents[v8]._Myptr) && v10 )
          AudioEvent::start(this->hitEvents[v8]._Myptr);
      }
    }
    v12 = this->scrapeEvents[v8]._Myptr;
    if ( v12 )
    {
      if ( !AudioEvent::isPlaying(v12) && v10 )
        AudioEvent::start(this->scrapeEvents[v8]._Myptr);
      if ( AudioEvent::isPaused(this->scrapeEvents[v8]._Myptr) && v10 )
        AudioEvent::resume(this->scrapeEvents[v8]._Myptr, 1);
      v13 = this->scrapeEvents[v8]._Myptr;
      velocity.x = 0.0;
      velocity.y = 0.0;
      velocity.z = 0.0;
      AudioEvent::set3DAttributes(v13, &transform, &velocity);
      this->scrapeDecays[v8] = 0.0;
    }
  }
}
char CarAudioFMOD::onGearChanged(CarAudioFMOD *this, GearChangeRequestDirection direction)
{
  AudioEvent *v3; // edi
  bool v4; // bl

  v3 = &this->gearIntEvent;
  if ( !CarAudioFMOD::shouldUseInternalSounds(this) )
    v3 = &this->gearExtEvent;
  v4 = this->listenerPriority < 7;
  if ( !AudioEvent::isPlaying(v3) && v4 )
  {
    AudioEvent::stop(v3);
    AudioEvent::setParameter(v3, "state", (float)(direction != DownShift));
    AudioEvent::start(v3);
  }
  return 1;
}
void CarAudioFMOD::playSurface(CarAudioFMOD *this, int wheelID, std::wstring path, const vec3f *carVelocity)
{
  const vec3f *v5; // ebp
  int v6; // esi
  bool v7; // zf
  std::wstring *v8; // esi
  std::wstring *v9; // eax
  AudioEvent *v10; // ecx
  float value; // xmm0_4
  float Px; // [esp+18h] [ebp-14h] BYREF
  float v13; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+28h] [ebp-4h]

  v5 = carVelocity;
  v14 = 0;
  v6 = 7 * wheelID + 143;
  v7 = *(&this->name._Mysize + v6) == 0;
  v8 = (std::wstring *)(&this->__vftable + v6);
  if ( v7 )
    goto LABEL_7;
  v9 = &path;
  if ( path._Myres >= 8 )
    v9 = (std::wstring *)path._Bx._Ptr;
  if ( std::wstring::compare(v8, 0, v8->_Mysize, v9->_Bx._Buf, path._Mysize) )
  {
    AudioEngine::releaseCachedEvent(this->car->game->audioEngine, (AudioEvent *)v8[1]._Bx._Ptr);
    v8[1]._Bx._Ptr = 0;
  }
  if ( !v8[1]._Bx._Ptr )
  {
LABEL_7:
    v8[1]._Bx._Ptr = (wchar_t *)AudioEngine::getCachedEvent(this->car->game->audioEngine, &path);
    if ( v8 != &path )
      std::wstring::assign(v8, &path, 0, 0xFFFFFFFF);
    this->usingCache = 1;
  }
  v10 = (AudioEvent *)v8[1]._Bx._Ptr;
  if ( v10 )
  {
    if ( !AudioEvent::isPlaying(v10) )
      AudioEvent::start((AudioEvent *)v8[1]._Bx._Ptr);
    AudioEvent::set3DAttributes((AudioEvent *)v8[1]._Bx._Ptr, &this->car->physicsState.tyreMatrix[wheelID], v5);
    v13 = this->car->physicsState.speed.value * 3.5999999;
    Px = v13;
    if ( __fdtest(&Px) <= 0 )
      value = v13;
    else
      value = 0.0;
    AudioEvent::setParameter((AudioEvent *)v8[1]._Bx._Ptr, "speed", value);
  }
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
}
void CarAudioFMOD::renderAudio(CarAudioFMOD *this, float deltaT)
{
  CarAvatar *v3; // ecx
  AudioEvent **v4; // ebx
  AudioEngine *v5; // ecx
  float v6; // xmm3_4
  CarAvatar *v7; // ecx
  std::unique_ptr<AudioEvent> *v8; // esi
  int v9; // ebx
  AudioEvent *v10; // ecx
  float value; // xmm0_4
  CarAvatar *v12; // eax
  float v13; // xmm0_4
  float *v14; // eax
  float *v15; // ecx
  float *v16; // eax
  float *v17; // ecx
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  AudioEvent *v21; // ecx
  float v22; // xmm0_4
  AudioEvent *v23; // ecx
  AudioEvent *v24; // ecx
  AudioEvent *v25; // ecx
  AudioEvent *v26; // ecx
  AudioEvent *v27; // ecx
  AudioEvent *v28; // ecx
  AudioEvent *v29; // ecx
  CarAvatar *v30; // eax
  float Px; // [esp+18h] [ebp-124h] BYREF
  float v32; // [esp+1Ch] [ebp-120h] BYREF
  vec3f result; // [esp+20h] [ebp-11Ch] BYREF
  float v34; // [esp+2Ch] [ebp-110h]
  vec3f listenerPosition; // [esp+30h] [ebp-10Ch] BYREF
  mat44f engineTransform; // [esp+3Ch] [ebp-100h] BYREF
  mat44f carTransform; // [esp+7Ch] [ebp-C0h] BYREF
  mat44f backfiresTransform; // [esp+BCh] [ebp-80h] BYREF
  mat44f hoodTrasform; // [esp+FCh] [ebp-40h] BYREF

  if ( !this->cameraManager )
    this->cameraManager = GameObject::getGameObject<ACCameraManager>(this->car->sim);
  CarAudioFMOD::startStopEvents(this);
  CarAudioFMOD::setEventVolumes(this);
  v3 = this->car;
  if ( v3->carNode->isActive )
  {
    AudioEngine::getListenerPosition(v3->game->audioEngine, &listenerPosition);
    getVelocitySafe(&result, this->car);
    v34 = this->car->physicsState.speed.value * 3.5999999;
    Px = v34;
    if ( __fdtest(&Px) > 0 )
      v34 = 0.0;
    mat44f::mat44f(&carTransform);
    mat44f::mat44f(&engineTransform);
    mat44f::mat44f(&backfiresTransform);
    mat44f::mat44f(&hoodTrasform);
    CarAudioFMOD::computeTransforms(this, &carTransform, &engineTransform, &backfiresTransform, &hoodTrasform);
    Px = this->car->physicsState.gas;
    v32 = Px;
    if ( __fdtest(&v32) <= 0 )
    {
      v6 = this->gas.alpha;
      if ( v6 == 0.0 || (float)(v6 * deltaT) >= 1.0 )
        this->gas.value = Px;
      else
        this->gas.value = (float)((float)((float)(Px - this->gas.value) * v6) * deltaT) + this->gas.value;
    }
    v7 = this->car;
    this->tractionControlDecay = deltaT + this->tractionControlDecay;
    if ( CarAvatar::isTcInAction(v7) )
      this->tractionControlDecay = 0.0;
    v8 = this->scrapeEvents;
    v9 = 3;
    do
    {
      v10 = v8->_Myptr;
      if ( v8->_Myptr )
      {
        value = deltaT + *(float *)&v8[3]._Myptr;
        *(float *)&v8[3]._Myptr = value;
        if ( value <= 1.0 )
        {
          AudioEvent::setParameter(v10, "decay", value);
          AudioEvent::setParameter(v8->_Myptr, "speed", v34);
          if ( !AudioEvent::isPlaying(v8->_Myptr) )
            AudioEvent::start(v8->_Myptr);
        }
        else
        {
          AudioEvent::stop(v10);
        }
      }
      ++v8;
      --v9;
    }
    while ( v9 );
    v12 = this->car;
    Px = FLOAT_1_0;
    v13 = (float)((float)((float)(v12->physicsState.tyreDirtyLevel[0] + v12->physicsState.tyreDirtyLevel[1])
                        + v12->physicsState.tyreDirtyLevel[2])
                + v12->physicsState.tyreDirtyLevel[3])
        * 0.1;
    if ( v13 <= 1.0 )
    {
      if ( v13 >= 0.0 )
        Px = (float)((float)((float)(v12->physicsState.tyreDirtyLevel[0] + v12->physicsState.tyreDirtyLevel[1])
                           + v12->physicsState.tyreDirtyLevel[2])
                   + v12->physicsState.tyreDirtyLevel[3])
           * 0.1;
      else
        Px = 0.0;
    }
    AudioEvent::set3DAttributes(&this->dirtEvent, &carTransform, &result);
    AudioEvent::setParameter(&this->dirtEvent, "dirtiness", Px);
    AudioEvent::setParameter(&this->dirtEvent, "speed", v34);
    AudioEvent::set3DAttributes(&this->engineExtEvent, &engineTransform, &result);
    v14 = &v32;
    v15 = &this->car->physicsState.engineRPM;
    v32 = 1.0;
    if ( *v15 >= 1.0 )
      v14 = v15;
    AudioEvent::setParameter(&this->engineExtEvent, "rpms", *v14);
    AudioEvent::setParameter(&this->engineExtEvent, "throttle", this->gas.value);
    AudioEvent::set3DAttributes(&this->engineIntEvent, &engineTransform, &result);
    v16 = &v32;
    v17 = &this->car->physicsState.engineRPM;
    v32 = 1.0;
    if ( *v17 >= 1.0 )
      v16 = v17;
    AudioEvent::setParameter(&this->engineIntEvent, "rpms", *v16);
    AudioEvent::setParameter(&this->engineIntEvent, "throttle", this->gas.value);
    AudioEvent::set3DAttributes(&this->gearIntEvent, &carTransform, &result);
    AudioEvent::set3DAttributes(&this->gearExtEvent, &carTransform, &result);
    Px = this->car->physicsState.bodyWorkVolume;
    v32 = Px;
    v18 = FLOAT_1_0;
    if ( __fdtest(&v32) <= 0 )
    {
      v19 = this->bodyworkVolume.alpha;
      if ( v19 == 0.0 || (float)(v19 * deltaT) >= 1.0 )
        this->bodyworkVolume.value = Px;
      else
        this->bodyworkVolume.value = (float)((float)((float)(Px - this->bodyworkVolume.value) * v19) * deltaT)
                                   + this->bodyworkVolume.value;
    }
    v20 = this->bodyworkVolume.value;
    if ( v20 <= 1.0 )
    {
      if ( v20 >= 0.0 )
        v18 = this->bodyworkVolume.value;
      else
        v18 = 0.0;
    }
    this->bodyworkVolume.value = v18;
    AudioEvent::set3DAttributes(&this->bodyworkEvent, &carTransform, &result);
    AudioEvent::setParameter(&this->bodyworkEvent, "susp_travel_speed", this->bodyworkVolume.value);
    AudioEvent::set3DAttributes(&this->windEvent, &hoodTrasform, &result);
    AudioEvent::setParameter(&this->windEvent, "speed", v34);
    v21 = &this->windEvent;
    v22 = this->car->physicsState.airDensity;
    if ( v22 == 0.0 )
      AudioEvent::setParameter(v21, "air_pressure", 1.2102);
    else
      AudioEvent::setParameter(v21, "air_pressure", v22);
    v23 = this->hornEvent._Myptr;
    if ( v23 )
      AudioEvent::set3DAttributes(v23, &carTransform, &result);
    v24 = this->gearGrindEvent._Myptr;
    if ( v24 )
      AudioEvent::set3DAttributes(v24, &carTransform, &result);
    v25 = this->downShiftEvent._Myptr;
    if ( v25 )
      AudioEvent::set3DAttributes(v25);
    if ( this->backfireExtEvent._Myptr )
    {
      v26 = this->backfireIntEvent._Myptr;
      if ( v26 )
      {
        AudioEvent::set3DAttributes(v26, &backfiresTransform, &result);
        AudioEvent::setParameter(this->backfireIntEvent._Myptr, "throttle", this->gas.value);
        AudioEvent::set3DAttributes(this->backfireExtEvent._Myptr, &backfiresTransform, &result);
        AudioEvent::setParameter(this->backfireExtEvent._Myptr, "throttle", this->gas.value);
      }
    }
    v27 = this->tractionControlExtEvent._Myptr;
    if ( v27 && this->tractionControlIntEvent._Myptr )
    {
      AudioEvent::set3DAttributes(v27, &engineTransform, &result);
      AudioEvent::setParameter(this->tractionControlExtEvent._Myptr, "decay", this->tractionControlDecay);
      AudioEvent::set3DAttributes(this->tractionControlIntEvent._Myptr, &engineTransform, &result);
      AudioEvent::setParameter(this->tractionControlIntEvent._Myptr, "decay", this->tractionControlDecay);
    }
    v28 = this->transmissionEvent._Myptr;
    if ( v28 )
    {
      AudioEvent::set3DAttributes(v28, &engineTransform, &result);
      AudioEvent::setParameter(
        this->transmissionEvent._Myptr,
        "drivetrain_speed",
        this->car->physicsState.drivetrainSpeed);
      AudioEvent::setParameter(this->transmissionEvent._Myptr, "throttle", this->gas.value);
    }
    v29 = this->limiterEvent._Myptr;
    if ( v29 )
    {
      v30 = this->car;
      this->limiterDecay = this->limiterDecay + deltaT;
      if ( v30->physicsState.isEngineLimiterOn )
        this->limiterDecay = 0.0;
      AudioEvent::set3DAttributes(v29, &engineTransform, &result);
      AudioEvent::setParameter(this->limiterEvent._Myptr, "decay", this->limiterDecay);
    }
    CarAudioFMOD::updateTurbo(this, deltaT, &engineTransform, &result);
    CarAudioFMOD::updateWheels(this, &result);
    CarAudioFMOD::updateSkids(this, &result, &listenerPosition, deltaT);
    CarAudioFMOD::updateSurfaces(this, deltaT, &result);
  }
  else if ( this->usingCache )
  {
    if ( &this->surfaceEvents != (std::array<CarAudioFMOD::SurfaceList,4> *)&this->enginePosition )
    {
      v4 = &this->surfaceEvents._Elems[0].event;
      do
      {
        if ( *v4 )
        {
          v5 = this->car->game->audioEngine;
          if ( v5 )
            AudioEngine::releaseCachedEvent(v5, *v4);
        }
        v4 += 7;
      }
      while ( v4 - 6 != (AudioEvent **)&this->enginePosition );
    }
    this->usingCache = 0;
  }
}
void CarAudioFMOD::setEventVolumes(CarAudioFMOD *this)
{
  unsigned int v2; // esi
  bool v3; // zf
  ACCameraManager *v4; // eax
  bool v5; // dl
  CameraMode v6; // eax
  float v7; // xmm6_4
  float v8; // xmm2_4
  float volume; // xmm2_4
  float v10; // xmm4_4
  int v11; // eax
  AudioEvent *v12; // ecx
  float v13; // xmm0_4
  AudioEvent *v14; // ecx
  AudioEvent *v15; // ecx
  AudioEvent *v16; // ecx
  AudioEvent *v17; // ecx
  AudioEvent *v18; // ecx
  AudioEvent *v19; // ecx
  AudioEvent *v20; // edi
  AudioEvent *i; // esi
  AudioEvent **v22; // edi
  std::unique_ptr<AudioEvent> *v23; // esi
  int v24; // edi
  AudioEvent *v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm0_4
  bool v28; // [esp+13h] [ebp-2Dh]
  float v29; // [esp+18h] [ebp-28h]
  float v30; // [esp+1Ch] [ebp-24h]
  float v31; // [esp+20h] [ebp-20h]
  float v32; // [esp+24h] [ebp-1Ch]
  float v33; // [esp+28h] [ebp-18h]
  float v34; // [esp+2Ch] [ebp-14h]
  float v35; // [esp+30h] [ebp-10h]
  float v36; // [esp+34h] [ebp-Ch]
  float v37; // [esp+38h] [ebp-8h]
  float v38; // [esp+3Ch] [ebp-4h]

  v2 = Sim::getFocusedCarIndex(this->car->sim);
  v3 = CarAvatar::getGuid(this->car) == v2;
  v4 = this->cameraManager;
  v28 = v3;
  if ( v4 )
  {
    v6 = v4->mode;
    v5 = v6 == eFree || v6 == eTrack;
  }
  else
  {
    v5 = 0;
  }
  v7 = this->mixVolumes.engineMult;
  if ( v5 )
    v7 = FLOAT_2_5;
  if ( v3 || v5 )
    v8 = this->mixVolumes.engineVolume;
  else
    v8 = this->mixVolumes.opponentsVolume;
  volume = v8 * v7;
  v36 = this->mixVolumes.windVolume;
  if ( v3 )
    v10 = volume;
  else
    v10 = this->mixVolumes.opponentsVolume * volume;
  v11 = this->listenerPriority;
  v31 = v10;
  if ( v11 > 4 && v11 < 7 )
    v31 = v10 * (float)(1.0 - (float)(this->listenerDistance * 0.013333334));
  v32 = volume;
  if ( v11 > 4 && v11 < 7 )
    v32 = (float)(1.0 - (float)(this->listenerDistance * 0.013333334)) * volume;
  v38 = this->mixVolumes.tyresVolume;
  if ( v3 )
    v30 = this->mixVolumes.surfacesVolume;
  else
    v30 = this->mixVolumes.opponentsVolume * 0.30000001;
  if ( v5 )
  {
    v30 = this->mixVolumes.surfacesVolume;
    if ( v11 > 2 && v11 < 5 )
      v30 = this->mixVolumes.surfacesVolume * (float)(1.0 - (float)(this->listenerDistance * 0.013333334));
  }
  v33 = this->mixVolumes.surfacesVolume;
  if ( v11 > 4 && v11 < 7 )
    v33 = (float)(1.0 - (float)(this->listenerDistance * 0.013333334)) * this->mixVolumes.surfacesVolume;
  v29 = volume;
  v37 = this->mixVolumes.transmissionVolume * v7;
  if ( v11 > 4 && v11 < 7 )
    v29 = (float)(1.0 - (float)(this->listenerDistance * 0.013333334)) * volume;
  v35 = volume;
  if ( v11 > 3 && v11 < 6 )
    v35 = (float)(1.0 - (float)(this->listenerDistance * 0.013333334)) * volume;
  AudioEvent::setBaseVolume(&this->dirtEvent, this->mixVolumes.dirtVolume);
  v12 = this->downShiftEvent._Myptr;
  if ( v12 )
    AudioEvent::setBaseVolume(v12, volume);
  v34 = this->car->game->audioEngine->reverbValue;
  if ( v34 < 0.05 )
    v34 = 0.0;
  if ( v28 && CarAudioFMOD::shouldUseInternalSounds(this) && v34 >= 0.0 )
    v13 = v29 * v34;
  else
    v13 = v29;
  AudioEvent::setBaseVolume(&this->engineExtEvent, v13);
  AudioEvent::setBaseVolume(&this->engineIntEvent, volume);
  AudioEvent::setBaseVolume(&this->gearExtEvent, volume);
  AudioEvent::setBaseVolume(&this->gearIntEvent, volume);
  AudioEvent::setBaseVolume(&this->bodyworkEvent, volume);
  v14 = this->tractionControlExtEvent._Myptr;
  if ( v14 && this->tractionControlIntEvent._Myptr )
  {
    AudioEvent::setBaseVolume(v14, volume);
    AudioEvent::setBaseVolume(this->tractionControlIntEvent._Myptr, volume);
  }
  AudioEvent::setBaseVolume(&this->windEvent, v36);
  v15 = this->hornEvent._Myptr;
  if ( v15 )
    AudioEvent::setBaseVolume(v15, v31);
  v16 = this->backfireExtEvent._Myptr;
  if ( v16 && this->backfireIntEvent._Myptr )
  {
    AudioEvent::setBaseVolume(v16, v32);
    AudioEvent::setBaseVolume(this->backfireIntEvent._Myptr, v32);
  }
  v17 = this->transmissionEvent._Myptr;
  if ( v17 )
    AudioEvent::setBaseVolume(v17, v37);
  v18 = this->limiterEvent._Myptr;
  if ( v18 )
    AudioEvent::setBaseVolume(v18, v29);
  v19 = this->turboEvent._Myptr;
  if ( v19 )
    AudioEvent::setBaseVolume(v19, v35);
  v20 = this->wheelEvents._Mylast;
  for ( i = this->wheelEvents._Myfirst; i != v20; ++i )
    AudioEvent::setBaseVolume(i, v38);
  if ( &this->surfaceEvents != (std::array<CarAudioFMOD::SurfaceList,4> *)&this->enginePosition )
  {
    v22 = &this->surfaceEvents._Elems[0].event;
    do
    {
      if ( *v22 )
        AudioEvent::setBaseVolume(*v22, v30);
      v22 += 7;
    }
    while ( v22 - 6 != (AudioEvent **)&this->enginePosition );
  }
  v23 = this->scrapeEvents;
  v24 = 3;
  do
  {
    v25 = v23[-3]._Myptr;
    if ( v25 )
    {
      if ( v28 )
        v26 = FLOAT_1_0;
      else
        v26 = this->mixVolumes.opponentsVolume;
      AudioEvent::setBaseVolume(v25, v26 * v33);
    }
    if ( v23->_Myptr )
    {
      if ( v28 )
        v27 = FLOAT_1_0;
      else
        v27 = this->mixVolumes.opponentsVolume;
      AudioEvent::setBaseVolume(v23->_Myptr, v27 * v33);
    }
    ++v23;
    --v24;
  }
  while ( v24 );
}
bool CarAudioFMOD::shouldUseInternalSounds(CarAudioFMOD *this)
{
  unsigned int v2; // esi
  ACCameraManager *v3; // ecx
  CameraMode v4; // eax
  bool result; // al

  v2 = Sim::getFocusedCarIndex(this->car->sim);
  if ( CarAvatar::getGuid(this->car) != v2 )
    goto LABEL_10;
  v3 = this->cameraManager;
  if ( !v3 )
    goto LABEL_10;
  v4 = v3->mode;
  switch ( v4 )
  {
    case eCockpit:
      return 1;
    case eOnBoardFree:
      goto LABEL_10;
    case eDrivable:
      return CameraDrivableManager::shouldUseInternalSounds(v3->cameraDrivable);
    case eCar:
      result = !this->car->cameras._Myfirst[v3->cameraCar->currentCameraIndex].externalSound;
      break;
    default:
LABEL_10:
      result = 0;
      break;
  }
  return result;
}
void CarAudioFMOD::startStopEvents(CarAudioFMOD *this)
{
  CarAudioFMOD *v1; // ebx
  CarAvatar *v2; // ecx
  unsigned int v3; // esi
  bool v4; // al
  CarAvatar *v5; // ecx
  bool v6; // dl
  bool v7; // al
  AudioEvent *v8; // ecx
  bool v9; // al
  AudioEvent *v10; // ecx
  bool v11; // cl
  bool v12; // al
  AudioEvent *v13; // ecx
  bool v14; // al
  AudioEvent *v15; // ecx
  bool v16; // zf
  AudioEvent *v17; // ecx
  bool v18; // al
  AudioEvent *v19; // ecx
  AudioEvent *v20; // ecx
  bool v21; // al
  AudioEvent *v22; // esi
  AudioEvent *v23; // ecx
  bool v24; // al
  AudioEvent *v25; // esi
  AudioEvent *v26; // ecx
  bool v27; // cl
  bool v28; // al
  AudioEvent *v29; // esi
  AudioEvent *v30; // ecx
  bool v31; // al
  AudioEvent *v32; // esi
  AudioEvent *v33; // ecx
  bool v34; // al
  AudioEvent *v35; // esi
  AudioEvent *v36; // ecx
  bool v37; // al
  AudioEvent *v38; // ecx
  bool v39; // al
  AudioEvent *v40; // ecx
  bool v41; // al
  AudioEvent *v42; // ecx
  bool v43; // al
  AudioEvent *v44; // ecx
  AudioEvent *v45; // esi
  AudioEvent *v46; // ecx
  AudioEvent *v47; // esi
  AudioEvent *v48; // edi
  bool v49; // al
  AudioEvent *v50; // esi
  AudioEvent *v51; // ecx
  bool v52; // [esp+8h] [ebp-Ch]
  bool v53; // [esp+9h] [ebp-Bh]
  bool v54; // [esp+Ah] [ebp-Ah]
  bool v55; // [esp+Bh] [ebp-9h]
  bool v56; // [esp+Ch] [ebp-8h]
  char v57; // [esp+Dh] [ebp-7h]
  char v58; // [esp+Eh] [ebp-6h]
  bool v59; // [esp+Fh] [ebp-5h]

  v1 = this;
  v2 = this->car;
  v52 = v2->carNode->isActive;
  v3 = Sim::getFocusedCarIndex(v2->sim);
  v54 = CarAvatar::getGuid(v1->car) == v3;
  v4 = CarAudioFMOD::shouldUseInternalSounds(v1);
  v5 = v1->car;
  v53 = v4;
  v59 = (float)((float)((float)(v5->physicsState.tyreDirtyLevel[1] + v5->physicsState.tyreDirtyLevel[0])
                      + v5->physicsState.tyreDirtyLevel[2])
              + v5->physicsState.tyreDirtyLevel[3]) > 0.0;
  if ( v5->physicsState.fuel <= 0.0 || (v57 = 1, v5->physicsState.engineLifeLeft <= 0.0) )
    v57 = 0;
  v6 = CarAvatar::isInPit(v5);
  v55 = v6;
  if ( !v54 || !v53 || (v58 = 1, v1->car->game->audioEngine->reverbValue == 0.0) )
    v58 = 0;
  v56 = v1->listenerPriority < 7;
  v7 = v54 && v53 && v59;
  if ( v1 != (CarAudioFMOD *)-96 )
  {
    v8 = &v1->dirtEvent;
    if ( v52 && v7 )
    {
      v9 = AudioEvent::isPaused(v8);
      v10 = &v1->dirtEvent;
      if ( v9 )
      {
        AudioEvent::resume(v10, 1);
      }
      else if ( !AudioEvent::isPlaying(v10) )
      {
        AudioEvent::start(&v1->dirtEvent);
      }
    }
    else
    {
      AudioEvent::stop(v8);
    }
    v6 = v55;
  }
  v11 = v54;
  v12 = v54 && v53 && !v6;
  if ( v1 != (CarAudioFMOD *)-400 )
  {
    v13 = &v1->bodyworkEvent;
    if ( v52 && v12 )
    {
      v14 = AudioEvent::isPaused(v13);
      v15 = &v1->bodyworkEvent;
      if ( v14 )
      {
        AudioEvent::resume(v15, 1);
      }
      else if ( !AudioEvent::isPlaying(v15) )
      {
        AudioEvent::start(&v1->bodyworkEvent);
      }
    }
    else
    {
      AudioEvent::stop(v13);
    }
    v11 = v54;
  }
  if ( v1 != (CarAudioFMOD *)-448 )
  {
    if ( v52 )
    {
      v16 = !v11;
      v17 = &v1->windEvent;
      if ( !v16 )
      {
        v18 = AudioEvent::isPaused(v17);
        v19 = &v1->windEvent;
        if ( v18 )
        {
          AudioEvent::resume(v19, 1);
        }
        else if ( !AudioEvent::isPlaying(v19) )
        {
          AudioEvent::start(&v1->windEvent);
        }
        goto LABEL_45;
      }
    }
    else
    {
      v17 = &v1->windEvent;
    }
    AudioEvent::stop(v17);
  }
LABEL_45:
  v21 = 0;
  if ( (v1->car->physicsState.actionsState.state & 0x40) != 0 )
  {
    v20 = v1->hornEvent._Myptr;
    if ( v20 )
    {
      if ( AudioEvent::isWithinRange(v20) && v56 )
        v21 = 1;
    }
  }
  v22 = v1->hornEvent._Myptr;
  if ( v22 )
  {
    v23 = v1->hornEvent._Myptr;
    if ( v52 && v21 )
    {
      if ( AudioEvent::isPaused(v23) )
      {
        AudioEvent::resume(v22, 1);
      }
      else if ( !AudioEvent::isPlaying(v22) )
      {
        AudioEvent::start(v22);
      }
    }
    else
    {
      AudioEvent::stop(v23);
    }
  }
  v24 = v54 && v1->car->physicsState.isGearGrinding;
  v25 = v1->gearGrindEvent._Myptr;
  if ( v25 )
  {
    v26 = v1->gearGrindEvent._Myptr;
    if ( v52 && v24 )
    {
      if ( AudioEvent::isPaused(v26) )
      {
        AudioEvent::resume(v25, 1);
      }
      else if ( !AudioEvent::isPlaying(v25) )
      {
        AudioEvent::start(v25);
      }
    }
    else
    {
      AudioEvent::stop(v26);
    }
  }
  v27 = v53;
  v28 = !v53 && v1->tractionControlDecay <= 10.0 && v56;
  v29 = v1->tractionControlExtEvent._Myptr;
  if ( v29 )
  {
    v30 = v1->tractionControlExtEvent._Myptr;
    if ( v52 && v28 )
    {
      if ( AudioEvent::isPaused(v30) )
      {
        AudioEvent::resume(v29, 1);
      }
      else if ( !AudioEvent::isPlaying(v29) )
      {
        AudioEvent::start(v29);
      }
    }
    else
    {
      AudioEvent::stop(v30);
    }
    v27 = v53;
  }
  v31 = v54 && v27 && v1->tractionControlDecay <= 10.0;
  v32 = v1->tractionControlIntEvent._Myptr;
  if ( v32 )
  {
    v33 = v1->tractionControlIntEvent._Myptr;
    if ( v52 && v31 )
    {
      if ( AudioEvent::isPaused(v33) )
      {
        AudioEvent::resume(v32, 1);
      }
      else if ( !AudioEvent::isPlaying(v32) )
      {
        AudioEvent::start(v32);
      }
    }
    else
    {
      AudioEvent::stop(v33);
    }
  }
  v34 = v54 && v53;
  v35 = v1->transmissionEvent._Myptr;
  if ( v35 )
  {
    v36 = v1->transmissionEvent._Myptr;
    if ( v52 && v34 )
    {
      if ( AudioEvent::isPaused(v36) )
      {
        AudioEvent::resume(v35, 1);
      }
      else if ( !AudioEvent::isPlaying(v35) )
      {
        AudioEvent::start(v35);
      }
    }
    else
    {
      AudioEvent::stop(v36);
    }
  }
  v37 = v57 && (!v53 || v58) && AudioEvent::isWithinRange(&v1->engineExtEvent) && v56;
  if ( v1 != (CarAudioFMOD *)-208 )
  {
    v38 = &v1->engineExtEvent;
    if ( v52 && v37 )
    {
      v39 = AudioEvent::isPaused(v38);
      v40 = &v1->engineExtEvent;
      if ( v39 )
      {
        AudioEvent::resume(v40, 1);
      }
      else if ( !AudioEvent::isPlaying(v40) )
      {
        AudioEvent::start(&v1->engineExtEvent);
      }
    }
    else
    {
      AudioEvent::stop(v38);
    }
  }
  v41 = v54 && v57 && v53;
  if ( v1 != (CarAudioFMOD *)-256 )
  {
    v42 = &v1->engineIntEvent;
    if ( v52 && v41 )
    {
      v43 = AudioEvent::isPaused(v42);
      v44 = &v1->engineIntEvent;
      if ( v43 )
      {
        AudioEvent::resume(v44, 1);
      }
      else if ( !AudioEvent::isPlaying(v44) )
      {
        AudioEvent::start(&v1->engineIntEvent);
      }
    }
    else
    {
      AudioEvent::stop(v42);
    }
  }
  v45 = v1->turboEvent._Myptr;
  if ( v45 )
  {
    v46 = v1->turboEvent._Myptr;
    if ( v52 && v1->listenerPriority < 6 )
    {
      if ( AudioEvent::isPaused(v46) )
      {
        AudioEvent::resume(v45, 1);
      }
      else if ( !AudioEvent::isPlaying(v45) )
      {
        AudioEvent::start(v45);
      }
    }
    else
    {
      AudioEvent::stop(v46);
    }
  }
  v47 = v1->wheelEvents._Myfirst;
  v48 = v1->wheelEvents._Mylast;
  if ( v47 != v48 )
  {
    do
    {
      if ( v47 )
      {
        if ( v52 && v54 )
        {
          if ( AudioEvent::isPaused(v47) )
          {
            AudioEvent::resume(v47, 1);
          }
          else if ( !AudioEvent::isPlaying(v47) )
          {
            AudioEvent::start(v47);
          }
        }
        else
        {
          AudioEvent::stop(v47);
        }
      }
      ++v47;
    }
    while ( v47 != v48 );
    v1 = this;
  }
  v49 = v1->limiterDecay <= 10.0 && v56;
  v50 = v1->limiterEvent._Myptr;
  if ( v50 )
  {
    v51 = v1->limiterEvent._Myptr;
    if ( v52 && v49 )
    {
      if ( AudioEvent::isPaused(v51) )
      {
        AudioEvent::resume(v50, 1);
      }
      else if ( !AudioEvent::isPlaying(v50) )
      {
        AudioEvent::start(v50);
      }
    }
    else
    {
      AudioEvent::stop(v51);
    }
  }
}
void CarAudioFMOD::updateSkids(CarAudioFMOD *this, const vec3f *carVelocity, const vec3f *listenerPosition, float dt)
{
  bool v5; // al
  CarAvatar *v6; // ecx
  unsigned int v7; // esi
  CarAvatar *v8; // eax
  float v9; // xmm5_4
  int v10; // xmm7_4
  float *v11; // esi
  float v12; // xmm6_4
  int v13; // edx
  int v14; // ecx
  CarAvatar *v15; // eax
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm0_4
  float *v27; // eax
  float v28; // xmm2_4
  float v29; // xmm2_4
  AudioEvent *v30; // esi
  float v31; // xmm1_4
  float v32; // xmm0_4
  float volume; // xmm2_4
  int v34; // eax
  AudioEvent *v35; // edi
  AudioEvent *i; // esi
  int v37; // [esp+Ch] [ebp-38h] BYREF
  float Px; // [esp+10h] [ebp-34h] BYREF
  std::vector<AudioEvent> *v39; // [esp+14h] [ebp-30h]
  float v40; // [esp+18h] [ebp-2Ch]
  int v41; // [esp+1Ch] [ebp-28h]
  int v42; // [esp+20h] [ebp-24h]
  std::vector<AudioEvent> *v43; // [esp+24h] [ebp-20h]
  unsigned int v44; // [esp+28h] [ebp-1Ch]
  unsigned int v45; // [esp+2Ch] [ebp-18h]
  float v46; // [esp+30h] [ebp-14h] BYREF
  float v47; // [esp+34h] [ebp-10h]
  CarAudioFMOD *v48; // [esp+38h] [ebp-Ch]
  float v49; // [esp+3Ch] [ebp-8h]
  bool v50; // [esp+41h] [ebp-3h]
  bool v51; // [esp+42h] [ebp-2h]
  bool v52; // [esp+43h] [ebp-1h]

  v5 = CarAudioFMOD::shouldUseInternalSounds(this);
  v6 = this->car;
  v52 = v5;
  v7 = Sim::getFocusedCarIndex(v6->sim);
  v50 = CarAvatar::getGuid(this->car) == v7;
  if ( v52 )
  {
    v43 = &this->skidIntEvents;
    v39 = &this->skidExtEvents;
  }
  else
  {
    v43 = &this->skidExtEvents;
    v39 = &this->skidIntEvents;
  }
  v8 = this->car;
  v51 = this->listenerPriority < 4;
  v40 = (float)((float)((float)(v8->physicsState.load[1] + v8->physicsState.load[0]) + v8->physicsState.load[2])
              + v8->physicsState.load[3])
      * 0.125;
  v9 = v40;
  if ( v40 == 0.0 )
  {
    v9 = FLOAT_0_0099999998;
    v40 = FLOAT_0_0099999998;
  }
  v10 = _xmm;
  v11 = &this->skidVolumes[0].value;
  v12 = FLOAT_1_2;
  v13 = 0;
  v14 = 1156;
  v37 = 1036831949;
  v44 = 0;
  v45 = 0;
  v41 = 0;
  v42 = 1156;
  v48 = (CarAudioFMOD *)&this->skidVolumes[0].value;
  do
  {
    v15 = this->car;
    v16 = 0.0;
    v46 = 0.0;
    v49 = 0.0;
    if ( *(float *)((char *)&v15->physicsState.tyreSurfaceDef[0].gripMod + v13) < 0.89999998 )
      goto LABEL_36;
    v17 = v15->physicsState.speed.value;
    if ( v17 <= 1.0 && COERCE_FLOAT(*(_DWORD *)((char *)v15 + v14 - 136) & v10) <= 8.0
      || COERCE_FLOAT(*(_DWORD *)((char *)v15 + v14 - 32) & v10) <= 0.80000001 )
    {
      if ( v17 > 1.0 )
      {
        v20 = *(float *)((char *)&v15->__vftable + v14);
        v21 = this->skidParams.entryPoint;
        if ( v20 >= v21 )
        {
          v22 = (float)(v20 - v21) * 0.16666667;
          if ( v22 <= 1.0 )
          {
            if ( v22 < 0.0 )
              v22 = 0.0;
          }
          else
          {
            v22 = FLOAT_1_0;
          }
          v23 = *(float *)&v15->name._Bx._Alias[v14 + 8];
          v24 = &Px;
          v46 = 0.2;
          Px = v23 / v9;
          if ( (float)(v23 / v9) <= 0.2 )
            v24 = &v46;
          v25 = (float)(this->skidParams.volumeGain * v22) * *v24;
          v49 = v25;
          if ( v25 <= 1.0 )
          {
            if ( v25 < 0.0 )
              v49 = 0.0;
          }
          else
          {
            v49 = FLOAT_1_0;
          }
          v16 = this->skidParams.pitchBase;
          v26 = (float)(this->skidParams.pitchGain * v22) + v16;
          if ( v26 <= v12 )
          {
            if ( v16 <= v26 )
              v16 = (float)(this->skidParams.pitchGain * v22) + v16;
          }
          else
          {
            v16 = v12;
          }
          v46 = v16;
        }
      }
    }
    else
    {
      v47 = v12;
      v46 = v12;
      v49 = v17 * 3.5999999;
      Px = v17 * 3.5999999;
      if ( __fdtest(&Px) <= 0 )
        v18 = v49;
      else
        v18 = 0.0;
      v19 = v18 * 0.050000001;
      v49 = v19;
      if ( v19 > 1.0 )
      {
        v49 = FLOAT_1_0;
LABEL_16:
        v16 = v47;
        goto LABEL_36;
      }
      if ( v19 >= 0.0 )
        goto LABEL_16;
      v49 = 0.0;
      v16 = v47;
    }
LABEL_36:
    v27 = &v46;
    if ( v16 <= 0.1 )
      v27 = (float *)&v37;
    v46 = *v27;
    Px = v46;
    if ( __fdtest(&Px) <= 0 )
    {
      v28 = v11[7];
      if ( v28 == 0.0 || (float)(v28 * dt) >= 1.0 )
        v11[8] = v46;
      else
        v11[8] = (float)((float)((float)(v46 - v11[8]) * v28) * dt) + v11[8];
    }
    Px = v49;
    if ( __fdtest(&Px) <= 0 )
    {
      v29 = *(v11 - 1);
      if ( v29 == 0.0 || (float)(v29 * dt) >= 1.0 )
        *v11 = v49;
      else
        *v11 = (float)((float)((float)(v49 - *v11) * v29) * dt) + *v11;
    }
    v30 = &v43->_Myfirst[v45 / 0x30];
    if ( v51 )
    {
      if ( !AudioEvent::isPlaying(v30) )
        AudioEvent::start(v30);
    }
    else
    {
      v48->__vftable = 0;
      AudioEvent::stop(v30);
    }
    Px = FLOAT_0_60000002;
    if ( CarAudioFMOD::isExternalCamera(this) )
      v31 = FLOAT_1_0;
    else
      v31 = Px;
    if ( v50 )
      v32 = FLOAT_1_0;
    else
      v32 = this->mixVolumes.opponentsVolume * v31;
    volume = (float)(*(float *)&v48->__vftable * this->mixVolumes.tyresVolume) * v32;
    if ( !v52 )
      volume = this->mixVolumes.tyresMult * volume;
    v34 = this->listenerPriority;
    if ( v34 > 1 && v34 < 4 )
      volume = (float)(1.0 - (float)(this->listenerDistance * 0.013333334)) * volume;
    AudioEvent::setBaseVolume(v30, volume);
    AudioEvent::setBasePitch(v30, *(const float *)&v48->isActive);
    AudioEvent::set3DAttributes(v30, &this->car->physicsState.tyreMatrix[v44 / 0x40], carVelocity);
    v14 = v42 + 4;
    v13 = v41 + 188;
    v45 += 48;
    v11 = (float *)&v48->name._Bx._Ptr;
    v44 += 64;
    v9 = v40;
    v12 = FLOAT_1_2;
    v10 = _xmm;
    v42 = v14;
    v41 += 188;
    v48 = (CarAudioFMOD *)((char *)v48 + 8);
  }
  while ( v14 < 1172 );
  v35 = v39->_Mylast;
  for ( i = v39->_Myfirst; i != v35; ++i )
    AudioEvent::stop(i);
}
void CarAudioFMOD::updateSurfaces(CarAudioFMOD *this, const float deltaT, const vec3f *carVelocity)
{
  bool v4; // sf
  bool v5; // of
  ACCameraManager *v6; // eax
  CameraMode v7; // eax
  unsigned int v8; // esi
  AudioEvent **v9; // edi
  AudioEvent **v10; // ebp
  int i; // edi
  unsigned int v12; // eax
  SurfaceDef *v13; // edx
  const unsigned __int16 *v14; // edx
  std::wstring *v15; // eax
  unsigned int v16; // eax
  std::wstring *v17; // esi
  std::wstring *v18; // esi
  int v19; // esi
  std::wstring v20; // [esp-1Ch] [ebp-B0h] BYREF
  vec3f *v21; // [esp-4h] [ebp-98h]
  char v22; // [esp+17h] [ebp-7Dh]
  int wheelID; // [esp+18h] [ebp-7Ch]
  vec3f *v24; // [esp+1Ch] [ebp-78h]
  std::wstring eventPath; // [esp+24h] [ebp-70h] BYREF
  std::wstring surfaceWav; // [esp+3Ch] [ebp-58h] BYREF
  std::wstring surfaceType; // [esp+54h] [ebp-40h] BYREF
  std::wstring result; // [esp+6Ch] [ebp-28h] BYREF
  int v29; // [esp+90h] [ebp-4h]

  v5 = __OFSUB__(this->listenerPriority, 3);
  v4 = this->listenerPriority - 3 < 0;
  v24 = (vec3f *)carVelocity;
  v22 = v4 ^ v5;
  v6 = this->cameraManager;
  if ( (v6 && ((v7 = v6->mode, v7 == eFree) || v7 == eTrack)
     || (v8 = Sim::getFocusedCarIndex(this->car->sim), CarAvatar::getGuid(this->car) != v8))
    && !v22 )
  {
    if ( &this->surfaceEvents != (std::array<CarAudioFMOD::SurfaceList,4> *)&this->enginePosition )
    {
      v9 = &this->surfaceEvents._Elems[0].event;
      do
      {
        if ( *v9 )
        {
          AudioEngine::releaseCachedEvent(this->car->game->audioEngine, *v9);
          *v9 = 0;
        }
        v9 += 7;
      }
      while ( v9 - 6 != (AudioEvent **)&this->enginePosition );
    }
  }
  else
  {
    wheelID = 0;
    v10 = &this->surfaceEvents._Elems[0].event;
    for ( i = 0; i < 4; ++i )
    {
      v12 = 0;
      v13 = this->car->physicsState.tyreSurfaceDef;
      surfaceWav._Myres = 7;
      v14 = v13[i].wavString;
      surfaceWav._Mysize = 0;
      surfaceWav._Bx._Buf[0] = 0;
      if ( *v14 )
        v12 = wcslen(v14);
      std::wstring::assign(&surfaceWav, v14, v12);
      v29 = 0;
      eventPath._Myres = 7;
      eventPath._Mysize = 0;
      eventPath._Bx._Buf[0] = 0;
      std::wstring::assign(&eventPath, word_17BE9D8, 0);
      LOBYTE(v29) = 1;
      if ( surfaceWav._Mysize )
      {
        v15 = &surfaceWav;
        surfaceType._Myres = 7;
        if ( surfaceWav._Myres >= 8 )
          v15 = (std::wstring *)surfaceWav._Bx._Ptr;
        surfaceType._Mysize = 0;
        v16 = (unsigned int)v15 + 2 * surfaceWav._Mysize - 8;
        v17 = &surfaceWav;
        if ( surfaceWav._Myres >= 8 )
          v17 = (std::wstring *)surfaceWav._Bx._Ptr;
        surfaceType._Bx._Buf[0] = 0;
        if ( v17 != (std::wstring *)v16 )
          std::wstring::assign(&surfaceType, v17->_Bx._Buf, (int)(v16 - (_DWORD)v17) >> 1);
        LOBYTE(v29) = 2;
        v18 = std::operator+<wchar_t>(&result, L"event:/surfaces/", &surfaceType);
        if ( &eventPath != v18 )
        {
          if ( eventPath._Myres >= 8 )
            operator delete(eventPath._Bx._Ptr);
          eventPath._Myres = 7;
          eventPath._Mysize = 0;
          eventPath._Bx._Buf[0] = 0;
          std::wstring::_Assign_rv(&eventPath, v18);
        }
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v21 = v24;
        v20._Myres = 7;
        v20._Mysize = 0;
        v20._Bx._Buf[0] = 0;
        std::wstring::assign(&v20, &eventPath, 0, 0xFFFFFFFF);
        v19 = wheelID;
        CarAudioFMOD::playSurface(this, wheelID, v20, v21);
        if ( surfaceType._Myres >= 8 )
          operator delete(surfaceType._Bx._Ptr);
      }
      else
      {
        if ( *v10 )
        {
          AudioEngine::releaseCachedEvent(this->car->game->audioEngine, *v10);
          *v10 = 0;
        }
        v19 = wheelID;
      }
      if ( eventPath._Myres >= 8 )
        operator delete(eventPath._Bx._Ptr);
      eventPath._Myres = 7;
      eventPath._Mysize = 0;
      eventPath._Bx._Buf[0] = 0;
      v29 = -1;
      if ( surfaceWav._Myres >= 8 )
        operator delete(surfaceWav._Bx._Ptr);
      v10 += 7;
      wheelID = v19 + 1;
    }
  }
}
void CarAudioFMOD::updateTurbo(CarAudioFMOD *this, const float deltaT, const mat44f *engineTransform, const vec3f *carVelocity)
{
  AudioEvent *v5; // ecx
  CarAvatar *v6; // eax

  v5 = this->turboEvent._Myptr;
  if ( v5 )
  {
    v6 = this->car;
    this->turboBovDecay = deltaT + this->turboBovDecay;
    if ( v6->physicsState.turboBov > 0.0 )
      this->turboBovDecay = 0.0;
    AudioEvent::set3DAttributes(v5, engineTransform, carVelocity);
    AudioEvent::setParameter(this->turboEvent._Myptr, "boost", this->car->physicsState.turboBoost / this->maxTurboBoost);
    AudioEvent::setParameter(this->turboEvent._Myptr, "bov", this->car->physicsState.turboBov);
    AudioEvent::setParameter(this->turboEvent._Myptr, "bov_decay", this->turboBovDecay);
  }
}
void CarAudioFMOD::updateWheels(CarAudioFMOD *this, const vec3f *carVelocity)
{
  int v2; // ebp
  int v3; // ebx
  int v4; // eax
  AudioEvent *v6; // esi
  float value; // xmm0_4
  int v8; // [esp+14h] [ebp-Ch]
  float Px; // [esp+18h] [ebp-8h] BYREF
  float v10; // [esp+1Ch] [ebp-4h]

  v2 = 0;
  v3 = 2416;
  v4 = 0;
  v8 = 0;
  do
  {
    v6 = (AudioEvent *)((char *)this->wheelEvents._Myfirst + v4);
    AudioEvent::set3DAttributes(v6, &this->car->physicsState.tyreMatrix[v2], carVelocity);
    AudioEvent::setParameter(v6, "brake", this->car->physicsState.brake);
    v10 = this->car->physicsState.speed.value * 3.5999999;
    Px = v10;
    if ( __fdtest(&Px) <= 0 )
      value = v10;
    else
      value = 0.0;
    AudioEvent::setParameter(v6, "speed", value);
    AudioEvent::setParameter(v6, "inflation", *(const float *)((char *)this->car + v3 - 28));
    AudioEvent::setParameter(v6, "suspension_damage", *(const float *)((char *)&this->car->__vftable + v3));
    v3 += 4;
    v4 = v8 + 48;
    ++v2;
    v8 += 48;
  }
  while ( v3 < 2432 );
}
