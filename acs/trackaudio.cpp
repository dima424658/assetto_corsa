#include "trackaudio.h"
void TrackAudio::TrackAudio(TrackAudio *this, TrackAvatar *track, Sim *sim)
{
  TrackAvatar *v4; // ebx
  std::vector<AudioEvent> *v5; // ebp
  Game *v6; // eax
  Node *v7; // ecx
  AudioEngine *v8; // esi
  FMOD::Reverb3D *v9; // edi
  FMOD::Studio::System *v10; // ebx
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  std::vector<AudioReverb> *v13; // ebp
  float v14; // edi
  int v15; // eax
  std::wstring *v16; // ecx
  std::wostream *v17; // eax
  const std::wstring *v18; // eax
  bool v19; // al
  bool v20; // bl
  const std::wstring *v21; // eax
  bool v22; // bl
  const std::wstring *v23; // eax
  const std::wstring *v24; // eax
  const std::wstring *v25; // eax
  const std::wstring *v26; // eax
  int v27; // esi
  std::wstring *v28; // eax
  bool v29; // cf
  int v30; // eax
  FMOD::Geometry *v31; // xmm1_4
  float v32; // xmm2_4
  const std::wstring *v33; // eax
  const std::wstring *v34; // eax
  const std::wstring *v35; // eax
  const std::wstring *v36; // eax
  const std::wstring *v37; // eax
  const std::wstring *v38; // eax
  const std::wstring *v39; // eax
  const std::wstring *v40; // eax
  const std::wstring *v41; // eax
  const std::wstring *v42; // eax
  const std::wstring *v43; // eax
  const std::wstring *v44; // eax
  int v45; // eax
  float i; // ebp
  std::wstring *v47; // eax
  std::wostream *v48; // eax
  const std::wstring *v49; // eax
  bool v50; // al
  bool v51; // bl
  const std::wstring *v52; // eax
  const std::wstring *v53; // eax
  const std::wstring *v54; // eax
  const std::wstring *v55; // eax
  Node *v56; // ecx
  int v57; // eax
  Mesh *v58; // ebx
  int v59; // edi
  int j; // esi
  std::wstring v61; // [esp+20h] [ebp-244h] BYREF
  float maxDistance; // [esp+38h] [ebp-22Ch]
  float volumeOcclusion; // [esp+54h] [ebp-210h]
  float doubleSided; // [esp+58h] [ebp-20Ch]
  std::vector<AudioReverb> *enabled; // [esp+5Ch] [ebp-208h]
  AudioReverb reverb; // [esp+60h] [ebp-204h] BYREF
  TrackAudio *v67; // [esp+6Ch] [ebp-1F8h]
  AudioOccluder occluder; // [esp+70h] [ebp-1F4h] BYREF
  Sim *v69; // [esp+84h] [ebp-1E0h]
  std::vector<AudioOccluder> *v70; // [esp+88h] [ebp-1DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v71; // [esp+8Ch] [ebp-1D8h] BYREF
  TrackAudio *v72; // [esp+13Ch] [ebp-128h]
  std::wstring meshName; // [esp+140h] [ebp-124h] BYREF
  std::wstring v74; // [esp+158h] [ebp-10Ch] BYREF
  std::wstring result; // [esp+170h] [ebp-F4h] BYREF
  std::wstring v76; // [esp+188h] [ebp-DCh] BYREF
  std::wstring presetName; // [esp+1A0h] [ebp-C4h] BYREF
  std::wstring nodeName; // [esp+1B8h] [ebp-ACh] BYREF
  INIReader ini; // [esp+1D0h] [ebp-94h] BYREF
  Triangle triangle; // [esp+214h] [ebp-50h] BYREF
  int v81; // [esp+260h] [ebp-4h]

  v67 = this;
  v4 = track;
  volumeOcclusion = 0.0;
  v72 = this;
  maxDistance = *(float *)&track->game;
  doubleSided = *(float *)&track;
  v69 = sim;
  v61._Myres = 7;
  v61._Mysize = 0;
  v61._Bx._Buf[0] = 0;
  std::wstring::assign(&v61, L"TRACK_AUDIO", 0xBu);
  GameObject::GameObject(this, v61, (Game *)LODWORD(maxDistance));
  v5 = &this->events;
  this->__vftable = (TrackAudio_vtbl *)&TrackAudio::`vftable';
  this->track = track;
  v81 = 0;
  this->events._Myfirst = 0;
  this->events._Mylast = 0;
  this->events._Myend = 0;
  this->reverbs._Myfirst = 0;
  enabled = &this->reverbs;
  this->reverbs._Mylast = 0;
  this->reverbs._Myend = 0;
  this->started = 0;
  v70 = &this->occluders;
  this->occluders._Myfirst = 0;
  this->occluders._Mylast = 0;
  this->occluders._Myend = 0;
  v6 = this->game;
  LOBYTE(v81) = 3;
  if ( v6->audioEngine )
  {
    reverb.engine = 0;
    reverb.reverb = 0;
    reverb.wetLevel = 0.0;
    LOBYTE(v81) = 4;
    presetName._Myres = 7;
    presetName._Mysize = 0;
    presetName._Bx._Buf[0] = 0;
    std::wstring::assign(&presetName, L"AC_AUDIO_", 9u);
    v7 = sim->trackNode;
    LOBYTE(v81) = 5;
    v7->findChildrenByPrefix(v7, &presetName, (std::vector<Node *> *)&reverb);
    LOBYTE(v81) = 4;
    if ( presetName._Myres >= 8 )
      operator delete(presetName._Bx._Ptr);
    v8 = reverb.engine;
    v9 = reverb.reverb;
    if ( reverb.engine != (AudioEngine *)reverb.reverb )
    {
      do
      {
        v10 = v8->system;
        if ( !__RTDynamicCast(v8->system, 0, &Node `RTTI Type Descriptor', &Renderable `RTTI Type Descriptor', 0) )
        {
          meshName._Myres = 7;
          meshName._Mysize = 0;
          meshName._Bx._Buf[0] = 0;
          std::wstring::assign(&meshName, L"event:/common/ambience", 0x16u);
          LOBYTE(v81) = 6;
          AudioEvent::AudioEvent((AudioEvent *)&triangle, v67->game->audioEngine, &meshName, Off);
          LOBYTE(v81) = 8;
          if ( meshName._Myres >= 8 )
            operator delete(meshName._Bx._Ptr);
          meshName._Myres = 7;
          meshName._Bx._Buf[0] = 0;
          occluder.engine = 0;
          occluder.geometry = 0;
          occluder.volumeOcclusion = 0.0;
          meshName._Mysize = 0;
          AudioEvent::set3DAttributes((AudioEvent *)&triangle, (const mat44f *)&v10[4], (const vec3f *)&occluder);
          std::vector<AudioEvent>::push_back(v5, (AudioEvent *)&triangle);
          LOBYTE(v81) = 4;
          AudioEvent::~AudioEvent((AudioEvent *)&triangle);
        }
        v8 = (AudioEngine *)((char *)v8 + 4);
      }
      while ( v8 != (AudioEngine *)v9 );
      v8 = reverb.engine;
      v4 = (TrackAvatar *)LODWORD(doubleSided);
    }
    LOBYTE(v81) = 3;
    if ( v8 )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&reverb);
      operator delete(reverb.engine);
    }
    v11 = TrackAvatar::getDataFolder(v4, &result);
    LOBYTE(v81) = 9;
    v12 = std::operator+<wchar_t>(&presetName, v11, L"/data/audio_sources.ini");
    LOBYTE(v81) = 10;
    INIReader::INIReader(&ini, v12);
    if ( presetName._Myres >= 8 )
      operator delete(presetName._Bx._Ptr);
    presetName._Myres = 7;
    presetName._Mysize = 0;
    presetName._Bx._Buf[0] = 0;
    LOBYTE(v81) = 13;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( ini.ready )
    {
      *(_DWORD *)v71.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v71.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v71.gap68);
      LOBYTE(v81) = 14;
      LODWORD(volumeOcclusion) = 1;
      std::wiostream::basic_iostream<wchar_t>(&v71, &v71.gap10[8], 0);
      v81 = 15;
      *(_DWORD *)&v71.gap0[*(_DWORD *)(*(_DWORD *)v71.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(std::vector<AudioOccluder> **)((char *)&v70 + *(_DWORD *)(*(_DWORD *)v71.gap0 + 4)) = (std::vector<AudioOccluder> *)(*(_DWORD *)(*(_DWORD *)v71.gap0 + 4) - 104);
      std::wstreambuf::wstreambuf(&v71.gap10[8]);
      *(_DWORD *)&v71.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v71.gap10[64] = 0;
      *(_DWORD *)&v71.gap10[68] = 0;
      v13 = enabled;
      v14 = 0.0;
      LOBYTE(v81) = 17;
      while ( 1 )
      {
        meshName._Myres = 7;
        meshName._Mysize = 0;
        meshName._Bx._Buf[0] = 0;
        std::wstring::assign(&meshName, word_17BE9D8, 0);
        LOBYTE(v81) = 18;
        if ( (v71.gap10[68] & 1) != 0 )
        {
          if ( std::wstreambuf::pptr(&v71.gap10[8]) )
            std::wstreambuf::epptr(&v71.gap10[8]);
          else
            std::wstreambuf::egptr(&v71.gap10[8]);
          std::wstreambuf::eback(&v71.gap10[8]);
          v15 = std::wstreambuf::eback(&v71.gap10[8]);
          operator delete(v15);
        }
        std::wstreambuf::setg(&v71.gap10[8], 0, 0, 0);
        std::wstreambuf::setp(&v71.gap10[8], 0, 0);
        v16 = &meshName;
        *(_DWORD *)&v71.gap10[64] = 0;
        LODWORD(maxDistance) = *(_DWORD *)&v71.gap10[68] & 0xFFFFFFFE;
        if ( meshName._Myres >= 8 )
          v16 = (std::wstring *)meshName._Bx._Ptr;
        *(_DWORD *)&v71.gap10[68] &= 0xFFFFFFFE;
        std::wstringbuf::_Init((std::wstringbuf *)&v71.gap10[8], v16->_Bx._Buf, meshName._Mysize, SLODWORD(maxDistance));
        LOBYTE(v81) = 17;
        if ( meshName._Myres >= 8 )
          operator delete(meshName._Bx._Ptr);
        maxDistance = v14;
        v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v71.gap10, "REVERB_");
        std::wostream::operator<<(v17, LODWORD(maxDistance));
        v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v76);
        LOBYTE(v81) = 19;
        v19 = INIReader::hasSection(&ini, v18);
        LOBYTE(v81) = 17;
        v20 = !v19;
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        if ( v20 )
          break;
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"ENABLED", 7u);
        LOBYTE(v81) = 20;
        v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &meshName);
        LOBYTE(v81) = 21;
        v22 = INIReader::getInt(&ini, v21, &result) != 0;
        LOBYTE(enabled) = v22;
        if ( meshName._Myres >= 8 )
          operator delete(meshName._Bx._Ptr);
        meshName._Myres = 7;
        meshName._Mysize = 0;
        meshName._Bx._Buf[0] = 0;
        LOBYTE(v81) = 17;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        if ( v22 )
        {
          meshName._Myres = 7;
          meshName._Mysize = 0;
          meshName._Bx._Buf[0] = 0;
          std::wstring::assign(&meshName, L"NODE", 4u);
          LOBYTE(v81) = 22;
          v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
          LOBYTE(v81) = 23;
          INIReader::getString(&ini, &nodeName, v23, &meshName);
          if ( v74._Myres >= 8 )
            operator delete(v74._Bx._Ptr);
          v74._Myres = 7;
          v74._Mysize = 0;
          v74._Bx._Buf[0] = 0;
          LOBYTE(v81) = 26;
          if ( meshName._Myres >= 8 )
            operator delete(meshName._Bx._Ptr);
          meshName._Myres = 7;
          meshName._Mysize = 0;
          meshName._Bx._Buf[0] = 0;
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          std::wstring::assign(&result, L"MINDISTANCE", 0xBu);
          LOBYTE(v81) = 27;
          v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v76);
          LOBYTE(v81) = 28;
          doubleSided = INIReader::getFloat(&ini, v24, &result);
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          LOBYTE(v81) = 26;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          std::wstring::assign(&result, L"MAXDISTANCE", 0xBu);
          LOBYTE(v81) = 29;
          v25 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v76);
          LOBYTE(v81) = 30;
          volumeOcclusion = INIReader::getFloat(&ini, v25, &result);
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          LOBYTE(v81) = 26;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          std::wstring::assign(&result, L"PRESET", 6u);
          LOBYTE(v81) = 31;
          v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v76);
          LOBYTE(v81) = 32;
          INIReader::getString(&ini, &presetName, v26, &result);
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          LOBYTE(v81) = 35;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Bx._Buf[0] = 0;
          result._Mysize = 0;
          v27 = (int)v69->trackNode->findChildByName(v69->trackNode, &nodeName, 1);
          if ( !v27 )
          {
            v28 = std::operator+<wchar_t>(&v74, L"ERROR: Reverb node does not exist:", &nodeName);
            v29 = v28->_Myres < 8;
            LOBYTE(v81) = 36;
            if ( !v29 )
              v28 = (std::wstring *)v28->_Bx._Ptr;
            _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v28->_Bx._Buf);
            ksGenerateCrash();
            LOBYTE(v81) = 35;
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
          }
          v30 = (*(int (**)(int, Triangle *))(*(_DWORD *)v27 + 32))(v27, &triangle);
          v31 = *(FMOD::Geometry **)(v30 + 52);
          v32 = *(float *)(v30 + 56);
          occluder.engine = *(AudioEngine **)(v30 + 48);
          occluder.geometry = v31;
          occluder.volumeOcclusion = v32;
          AudioReverb::AudioReverb(&reverb, v67->game->audioEngine);
          LOBYTE(v81) = 37;
          AudioReverb::enable(&reverb, (int)enabled);
          AudioReverb::set3DAttributes(&reverb, (const vec3f *)&occluder, doubleSided, volumeOcclusion);
          if ( std::wstring::compare(&presetName, 0, presetName._Mysize, L"CUSTOM", 6u) )
          {
            v45 = AudioReverb::getPresetFromName(&presetName);
            AudioReverb::setPreset(&reverb, (const AudioReverbPreset)v45);
          }
          else
          {
            meshName._Myres = 7;
            meshName._Mysize = 0;
            meshName._Bx._Buf[0] = 0;
            std::wstring::assign(&meshName, L"DECAY_TIME", 0xAu);
            LOBYTE(v81) = 38;
            v33 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 39;
            *(float *)&triangle.__vftable = INIReader::getFloat(&ini, v33, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            meshName._Myres = 7;
            meshName._Mysize = 0;
            meshName._Bx._Buf[0] = 0;
            std::wstring::assign(&meshName, L"EARLY_DELAY", 0xBu);
            LOBYTE(v81) = 40;
            v34 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 41;
            triangle.points[0].x = INIReader::getFloat(&ini, v34, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            meshName._Myres = 7;
            meshName._Mysize = 0;
            meshName._Bx._Buf[0] = 0;
            std::wstring::assign(&meshName, L"LATE_DELAY", 0xAu);
            LOBYTE(v81) = 42;
            v35 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 43;
            triangle.points[0].y = INIReader::getFloat(&ini, v35, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"HF_REFERENCE");
            LOBYTE(v81) = 44;
            v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 45;
            triangle.points[0].z = INIReader::getFloat(&ini, v36, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"HF_DECAY_RATIO");
            LOBYTE(v81) = 46;
            v37 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 47;
            triangle.points[1].x = INIReader::getFloat(&ini, v37, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"DIFFUSION");
            LOBYTE(v81) = 48;
            v38 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 49;
            triangle.points[1].y = INIReader::getFloat(&ini, v38, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"DENSITY");
            LOBYTE(v81) = 50;
            v39 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 51;
            triangle.points[1].z = INIReader::getFloat(&ini, v39, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"LOW_SHELF_FREQUENCY");
            LOBYTE(v81) = 52;
            v40 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 53;
            triangle.points[2].x = INIReader::getFloat(&ini, v40, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"LOW_SHELF_GAIN");
            LOBYTE(v81) = 54;
            v41 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 55;
            triangle.points[2].y = INIReader::getFloat(&ini, v41, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"HIGH_CUT");
            LOBYTE(v81) = 56;
            v42 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 57;
            triangle.points[2].z = INIReader::getFloat(&ini, v42, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"EARLY_LATE_MIX");
            LOBYTE(v81) = 58;
            v43 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 59;
            triangle.plane.normal.x = INIReader::getFloat(&ini, v43, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            std::wstring::wstring(&meshName, L"WET_LEVEL");
            LOBYTE(v81) = 60;
            v44 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
            LOBYTE(v81) = 61;
            triangle.plane.normal.y = INIReader::getFloat(&ini, v44, &meshName);
            if ( v74._Myres >= 8 )
              operator delete(v74._Bx._Ptr);
            v74._Myres = 7;
            v74._Mysize = 0;
            v74._Bx._Buf[0] = 0;
            LOBYTE(v81) = 37;
            if ( meshName._Myres >= 8 )
              operator delete(meshName._Bx._Ptr);
            AudioReverb::setProperties(&reverb, (const AudioReverbProperties *)&triangle);
          }
          std::vector<AudioReverb>::push_back(v13, &reverb);
          LOBYTE(v81) = 35;
          AudioReverb::~AudioReverb(&reverb);
          if ( presetName._Myres >= 8 )
            operator delete(presetName._Bx._Ptr);
          presetName._Myres = 7;
          presetName._Mysize = 0;
          presetName._Bx._Buf[0] = 0;
          LOBYTE(v81) = 17;
          if ( nodeName._Myres >= 8 )
            operator delete(nodeName._Bx._Ptr);
        }
        ++LODWORD(v14);
      }
      for ( i = 0.0; ; ++LODWORD(i) )
      {
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, word_17BE9D8, 0);
        LOBYTE(v81) = 62;
        std::wstringbuf::_Tidy((std::wstringbuf *)&v71.gap10[8]);
        maxDistance = *(float *)&v71.gap10[68];
        v47 = &result;
        v61._Myres = result._Mysize;
        if ( result._Myres >= 8 )
          v47 = (std::wstring *)result._Bx._Ptr;
        std::wstringbuf::_Init((std::wstringbuf *)&v71.gap10[8], v47->_Bx._Buf, v61._Myres, SLODWORD(maxDistance));
        LOBYTE(v81) = 17;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        maxDistance = i;
        v48 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v71.gap10, "OCCLUDER_");
        std::wostream::operator<<(v48, LODWORD(maxDistance));
        v49 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &nodeName);
        LOBYTE(v81) = 63;
        v50 = INIReader::hasSection(&ini, v49);
        LOBYTE(v81) = 17;
        v51 = !v50;
        if ( nodeName._Myres >= 8 )
          operator delete(nodeName._Bx._Ptr);
        if ( v51 )
          break;
        presetName._Myres = 7;
        presetName._Mysize = 0;
        presetName._Bx._Buf[0] = 0;
        std::wstring::assign(&presetName, L"ENABLED", 7u);
        LOBYTE(v81) = 64;
        v52 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v76);
        LOBYTE(v81) = 65;
        LOBYTE(enabled) = INIReader::getInt(&ini, v52, &presetName) != 0;
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        LOBYTE(v81) = 17;
        if ( presetName._Myres >= 8 )
          operator delete(presetName._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"MESH", 4u);
        LOBYTE(v81) = 66;
        v53 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v76);
        LOBYTE(v81) = 67;
        INIReader::getString(&ini, &meshName, v53, &result);
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        LOBYTE(v81) = 70;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::wstring(&nodeName, L"VOLUME_OCCLUSION");
        LOBYTE(v81) = 71;
        v54 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
        LOBYTE(v81) = 72;
        volumeOcclusion = INIReader::getFloat(&ini, v54, &nodeName);
        if ( v74._Myres >= 8 )
          operator delete(v74._Bx._Ptr);
        v74._Myres = 7;
        v74._Mysize = 0;
        v74._Bx._Buf[0] = 0;
        LOBYTE(v81) = 70;
        if ( nodeName._Myres >= 8 )
          operator delete(nodeName._Bx._Ptr);
        std::wstring::wstring(&nodeName, L"DOUBLESIDED");
        LOBYTE(v81) = 73;
        v55 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v71, &v74);
        LOBYTE(v81) = 74;
        LOBYTE(doubleSided) = INIReader::getInt(&ini, v55, &nodeName) != 0;
        if ( v74._Myres >= 8 )
          operator delete(v74._Bx._Ptr);
        v74._Myres = 7;
        v74._Mysize = 0;
        v74._Bx._Buf[0] = 0;
        LOBYTE(v81) = 70;
        if ( nodeName._Myres >= 8 )
          operator delete(nodeName._Bx._Ptr);
        maxDistance = 0.0;
        v61._Myres = (unsigned int)&Mesh `RTTI Type Descriptor';
        v61._Mysize = (unsigned int)&Node `RTTI Type Descriptor';
        v56 = v69->trackNode;
        *(_DWORD *)&v61._Bx._Alias[12] = 0;
        v57 = (int)v56->findChildByName(v56, &meshName, 1);
        v58 = (Mesh *)__RTDynamicCast(
                        v57,
                        *(_DWORD *)&v61._Bx._Alias[12],
                        v61._Mysize,
                        v61._Myres,
                        LODWORD(maxDistance));
        v59 = (v58->indices._Mylast - v58->indices._Myfirst) / 3;
        AudioOccluder::AudioOccluder(
          &occluder,
          v67->game->audioEngine,
          v59,
          v58->indices._Mylast - v58->indices._Myfirst);
        LOBYTE(v81) = 75;
        AudioOccluder::enable(&occluder, (int)enabled);
        AudioOccluder::setVolumeOcclusion(&occluder, volumeOcclusion);
        AudioOccluder::setDoubleSided(&occluder, SLOBYTE(doubleSided));
        for ( j = 0; j < v59; ++j )
        {
          Mesh::getTriangle(v58, &triangle, j);
          LOBYTE(v81) = 76;
          AudioOccluder::addTriangle(&occluder, triangle.points, &triangle.points[1], &triangle.points[2]);
          LOBYTE(v81) = 75;
          Triangle::~Triangle(&triangle);
        }
        std::vector<AudioOccluder>::push_back(v70, &occluder);
        LOBYTE(v81) = 70;
        AudioOccluder::~AudioOccluder(&occluder);
        LOBYTE(v81) = 17;
        if ( meshName._Myres >= 8 )
          operator delete(meshName._Bx._Ptr);
      }
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v71);
    }
    LOBYTE(v81) = 3;
    INIReader::~INIReader(&ini);
  }
}
TrackAudio *TrackAudio::`scalar deleting destructor'(TrackAudio *this, unsigned int a2)
{
  this->__vftable = (TrackAudio_vtbl *)&TrackAudio::`vftable';
  std::vector<AudioOccluder>::_Tidy(&this->occluders);
  std::vector<AudioReverb>::_Tidy(&this->reverbs);
  std::vector<AudioEvent>::_Tidy(&this->events);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TrackAudio::render(TrackAudio *this, float deltaT)
{
  AudioEvent *v3; // edi
  AudioEvent *i; // esi
  AudioReverb *v5; // edi
  float v6; // xmm0_4
  AudioReverb *v7; // esi
  float j; // [esp+Ch] [ebp-8h]
  float value; // [esp+10h] [ebp-4h]

  if ( !this->started )
  {
    v3 = this->events._Mylast;
    for ( i = this->events._Myfirst; i != v3; ++i )
      AudioEvent::start(i);
    this->started = 1;
  }
  v5 = this->reverbs._Mylast;
  v6 = 0.0;
  v7 = this->reverbs._Myfirst;
  for ( j = 0.0; v7 != v5; ++v7 )
  {
    value = AudioReverb::hearValue(v7);
    v6 = value;
    if ( value <= j )
      v6 = j;
    else
      j = value;
  }
  this->game->audioEngine->reverbValue = v6;
}
