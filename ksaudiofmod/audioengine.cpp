#include "audioengine.h
void __usercall AudioEngine::AudioEngine(AudioEngine *this@<ecx>, unsigned int a2@<ebx>)
{
  std::_Tree_node<std::pair<std::wstring const ,AudioEngine::GUID>,void *> *v3; // eax
  std::_List_node<AudioEngine::BankEntry,void *> *v4; // eax
  std::_List_node<AudioEvent *,void *> *v5; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::vector<AudioEvent *> >,void *> *v6; // eax
  std::_List_node<AudioEvent,void *> *v7; // eax
  std::wstring *v8; // esi
  FMOD_RESULT v9; // eax
  int i; // esi
  FMOD_RESULT v11; // eax
  std::wstring *v12; // ecx
  std::wstring *v13; // eax
  int v14; // eax
  char v15; // al
  int v16; // eax
  FMOD::System **v17; // esi
  FMOD_RESULT v18; // eax
  FMOD_RESULT v19; // eax
  FMOD_RESULT v20; // eax
  FMOD_RESULT v21; // eax
  FMOD_RESULT v22; // eax
  FMOD_DSP_DESCRIPTION *v23; // eax
  FMOD_RESULT v24; // eax
  FMOD_DSP_DESCRIPTION *v25; // eax
  FMOD_RESULT v26; // eax
  FMOD_RESULT v27; // eax
  FMOD_RESULT v28; // eax
  FMOD_RESULT v29; // eax
  FMOD_RESULT v30; // eax
  std::wstring v31; // [esp+54h] [ebp-1C4h] BYREF
  unsigned int v32; // [esp+6Ch] [ebp-1ACh]
  int v33[28]; // [esp+7Ch] [ebp-19Ch] BYREF
  int v34; // [esp+ECh] [ebp-12Ch] BYREF
  int v35; // [esp+F0h] [ebp-128h] BYREF
  int v36; // [esp+F4h] [ebp-124h] BYREF
  int v37; // [esp+F8h] [ebp-120h] BYREF
  int v38; // [esp+FCh] [ebp-11Ch] BYREF
  int v39; // [esp+100h] [ebp-118h] BYREF
  int v40; // [esp+104h] [ebp-114h] BYREF
  bool v41; // [esp+10Ah] [ebp-10Eh]
  char v42; // [esp+10Bh] [ebp-10Dh]
  INIReader v43; // [esp+10Ch] [ebp-10Ch] BYREF
  INIReaderDocuments v44; // [esp+150h] [ebp-C8h] BYREF
  __int128 v45; // [esp+194h] [ebp-84h] BYREF
  int v46; // [esp+1A4h] [ebp-74h]
  std::wstring v47; // [esp+1A8h] [ebp-70h] BYREF
  std::wstring section; // [esp+1C0h] [ebp-58h] BYREF
  std::wstring key; // [esp+1D8h] [ebp-40h] BYREF
  std::wstring result; // [esp+1F0h] [ebp-28h] BYREF
  int v51; // [esp+214h] [ebp-4h]

  this->masterVolume = 0.0;
  this->targetVolume = 1.0;
  v33[27] = (int)this;
  this->registeredGuids._Myhead = 0;
  this->registeredGuids._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<ksgui::Spinner * const,GearDef>>>::_Buyheadnode(&this->registeredGuids);
  this->registeredGuids._Myhead = v3;
  v32 = 0;
  v31._Myres = 0;
  v51 = 0;
  this->loadedBanks._Myhead = 0;
  this->loadedBanks._Mysize = 0;
  std::_List_alloc<0,std::_List_base_types<AudioEngine::BankEntry>>::_Buynode0(
    (std::_List_alloc<0,std::_List_base_types<AudioEvent> > *)&this->loadedBanks,
    (std::_List_node<AudioEvent,void *> *)v31._Myres,
    (std::_List_node<AudioEvent,void *> *)v32);
  this->loadedBanks._Myhead = v4;
  v32 = 0;
  v31._Myres = 0;
  this->registeredEvents._Myhead = 0;
  this->registeredEvents._Mysize = 0;
  std::_List_alloc<0,std::_List_base_types<AudioEvent *>>::_Buynode0(
    &this->registeredEvents,
    (std::_List_node<AudioEvent *,void *> *)v31._Myres,
    (std::_List_node<AudioEvent *,void *> *)v32);
  this->registeredEvents._Myhead = v5;
  this->timeFromStart = 0.0;
  this->freeEvents._Myhead = 0;
  this->freeEvents._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,GearSetDef>>>::_Buyheadnode(&this->freeEvents);
  this->freeEvents._Myhead = v6;
  v32 = 0;
  v31._Myres = 0;
  this->cachedEvents._Myhead = 0;
  this->cachedEvents._Mysize = 0;
  std::_List_alloc<0,std::_List_base_types<AudioEngine::BankEntry>>::_Buynode0(
    &this->cachedEvents,
    (std::_List_node<AudioEvent,void *> *)v31._Myres,
    (std::_List_node<AudioEvent,void *> *)v32);
  this->cachedEvents._Myhead = v7;
  v32 = 0;
  this->reverbValue = 0.0;
  this->playing = 1;
  LOBYTE(v51) = 4;
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"cfg/audio.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&v44, a2, v31, v32);
  LOBYTE(v51) = 5;
  INIReader::setVerboseMode(&v44, 1);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  std::wstring::assign(&v47, word_17BE9D8, 0);
  LOBYTE(v51) = 6;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"DRIVER_NAME", 0xBu);
  LOBYTE(v51) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SETTINGS", 8u);
  LOBYTE(v51) = 8;
  v42 = INIReader::hasKey(&v44, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v51) = 6;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v42 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DRIVER_NAME", 0xBu);
    LOBYTE(v51) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v51) = 10;
    v8 = INIReader::getString(&v44, &result, &section, &key);
    if ( &v47 != v8 )
    {
      if ( v47._Myres >= 8 )
        operator delete(v47._Bx._Ptr);
      v47._Myres = 7;
      v47._Mysize = 0;
      v47._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&v47, v8);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v51) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"system/cfg/audio_engine.ini", 0x1Bu);
  LOBYTE(v51) = 11;
  INIReader::INIReader(&v43, &section);
  LOBYTE(v51) = 13;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&v43, 1);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"LIVE_UPDATE", 0xBu);
  LOBYTE(v51) = 14;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SETTINGS", 8u);
  LOBYTE(v51) = 15;
  v41 = INIReader::getInt(&v43, &key, &result) != 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v51) = 13;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"MAX_CHANNELS", 0xCu);
  LOBYTE(v51) = 16;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SETTINGS", 8u);
  LOBYTE(v51) = 17;
  v39 = INIReader::getInt(&v43, &key, &result);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v51) = 13;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v32 = 67602;
  v31._Myres = (unsigned int)this;
  this->startUpTime = 0.89999998;
  this->timeFromStart = 0.0;
  v9 = FMOD::Studio::System::create(v31._Myres, v32);
  if ( v9 )
    audioFmodCallError("AudioEngine.cpp", 868, v9);
  for ( i = 0; ; ++i )
  {
    FMOD::Studio::System::getLowLevelSystem(this->system, &v40);
    v37 = 0;
    v11 = FMOD::System::getNumDrivers(v40, &v37);
    if ( v11 )
      audioFmodCallError("AudioEngine.cpp", 798, v11);
    if ( i >= v37 )
      break;
    v12 = AudioEngine::getDriverInfo(this, &result, i);
    v13 = &v47;
    v32 = v47._Mysize;
    if ( v47._Myres >= 8 )
      v13 = (std::wstring *)v47._Bx._Ptr;
    v31._Myres = (unsigned int)v13;
    v31._Mysize = v12->_Mysize;
    LOBYTE(v51) = 18;
    v14 = std::wstring::compare(v12, 0, v31._Mysize, v13->_Bx._Buf, v32);
    LOBYTE(v51) = 13;
    v15 = v14 == 0;
    v42 = v15;
    if ( result._Myres >= 8 )
    {
      operator delete(result._Bx._Ptr);
      v15 = v42;
    }
    if ( v15 )
      AudioEngine::setDriver(this, i);
  }
  v16 = 0;
  v46 = 0;
  v32 = 108;
  if ( v41 )
    v16 = 1;
  v40 = v16;
  v45 = 0x8000000000014ui64;
  memset(v33, 0, v32);
  v33[0] = 108;
  v17 = &this->lowLevelSystem;
  v33[14] = 973279855;
  v18 = FMOD::Studio::System::getLowLevelSystem(this->system, &this->lowLevelSystem);
  if ( v18 )
    audioFmodCallError("AudioEngine.cpp", 903, v18);
  v19 = FMOD::Studio::System::setAdvancedSettings(this->system, &v45);
  if ( v19 )
    audioFmodCallError("AudioEngine.cpp", 904, v19);
  v20 = FMOD::System::setAdvancedSettings(*v17, v33);
  if ( v20 )
    audioFmodCallError("AudioEngine.cpp", 905, v20);
  v21 = FMOD::System::setSoftwareChannels(*v17, v39);
  if ( v21 )
    audioFmodCallError("AudioEngine.cpp", 906, v21);
  FMOD::System::getSoftwareFormat(*v17, &v36, &v35, &v34);
  _printf("FMOD running @%d speaker mode:%d speakers: %d\n", v36, v35, v34);
  v22 = FMOD::Studio::System::initialize(this->system, 2048, v40, 4, 0);
  if ( v22 )
    audioFmodCallError("AudioEngine.cpp", 919, v22);
  v23 = FMODGetDSPDescription_DistanceFilter();
  v24 = FMOD::Studio::System::registerPlugin(this->system, v23);
  if ( v24 )
    audioFmodCallError("AudioEngine.cpp", 921, v24);
  v25 = FMODGetDSPDescription_Gain();
  v26 = FMOD::Studio::System::registerPlugin(this->system, v25);
  if ( v26 )
    audioFmodCallError("AudioEngine.cpp", 922, v26);
  v27 = FMOD::System::setGeometrySettings(*v17, 1167867904);
  if ( v27 )
    audioFmodCallError("AudioEngine.cpp", 926, v27);
  listDrivers(*v17);
  v28 = FMOD::System::setCallback(*v17, fmodCallback, 2);
  if ( v28 )
    audioFmodCallError("AudioEngine.cpp", 931, v28);
  v29 = FMOD::System::getDSPBufferSize(*v17, &v40, &v39);
  if ( v29 )
    audioFmodCallError("AudioEngine.cpp", 938, v29);
  audioLog("AudioEngine.cpp", 939, "log", "Audio DSP buffer size: bufferLength %d, numBuffers %d", v40, v39);
  v38 = 0;
  v30 = FMOD::System::getVersion(*v17, &v38);
  if ( v30 )
    audioFmodCallError("AudioEngine.cpp", 943, v30);
  _printf("Checking FMOD version %d required: %d\n", v38, 67602);
  if ( v38 != 67602 )
    audioLog(
      "AudioEngine.cpp",
      947,
      "error",
      "fmodVersion == REQUIRED_FMOD_VERSION. A different version of FMOD is required in order to run the game");
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"content/sfx/GUIDs.txt", 0x15u);
  LOBYTE(v51) = 19;
  AudioEngine::parseGUIDs(this, &result);
  LOBYTE(v51) = 13;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"content/sfx/common.bank", 0x17u);
  LOBYTE(v51) = 20;
  AudioEngine::addBankRef(this, &result);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->playing = 1;
  LOBYTE(v51) = 6;
  INIReader::~INIReader(&v43);
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  LOBYTE(v51) = 4;
  INIReaderDocuments::~INIReaderDocuments(&v44);
}
void AudioEngine::~AudioEngine(AudioEngine *this)
{
  std::_Tree_node<std::pair<std::wstring const ,std::vector<AudioEvent *> >,void *> *v2; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::vector<AudioEvent *> >,void *> *v3; // eax
  FMOD_RESULT v4; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::vector<AudioEvent *> >,void *> *v5; // eax
  std::_List_node<AudioEvent *,void *> *v6; // eax
  std::_List_node<AudioEvent *,void *> *v7; // ecx
  std::_List_node<AudioEvent *,void *> *v8; // esi
  std::_Tree_node<std::pair<std::wstring const ,AudioEngine::GUID>,void *> *v9; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<AudioEvent *> > > > > result; // [esp+10h] [ebp-30h] BYREF
  AudioEngine *v11; // [esp+14h] [ebp-2Ch]
  std::wstring path; // [esp+18h] [ebp-28h] BYREF
  int v13; // [esp+3Ch] [ebp-4h]

  v11 = this;
  v13 = 4;
  std::list<AudioEvent>::clear(&this->cachedEvents);
  std::_Tree<std::_Tmap_traits<std::wstring,std::vector<AudioEvent *>,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::vector<AudioEvent *>>>,0>>::_Erase(
    &this->freeEvents,
    this->freeEvents._Myhead->_Parent);
  v2 = this->freeEvents._Myhead;
  path._Myres = 7;
  v2->_Parent = v2;
  v3 = this->freeEvents._Myhead;
  path._Mysize = 0;
  v3->_Left = v3;
  this->freeEvents._Myhead->_Right = this->freeEvents._Myhead;
  this->freeEvents._Mysize = 0;
  path._Bx._Buf[0] = 0;
  std::wstring::assign(&path, L"content/sfx/common.bank", 0x17u);
  LOBYTE(v13) = 5;
  AudioEngine::removeBankRef(this, &path);
  LOBYTE(v13) = 4;
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  v4 = FMOD::Studio::System::release(this->system);
  if ( v4 )
    audioFmodCallError("AudioEngine.cpp", 965, v4);
  this->system = 0;
  std::list<AudioEvent>::clear(&this->cachedEvents);
  operator delete(this->cachedEvents._Myhead);
  v5 = this->freeEvents._Myhead;
  LOBYTE(v13) = 2;
  std::_Tree<std::_Tmap_traits<std::wstring,std::vector<AudioEvent *>,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::vector<AudioEvent *>>>,0>>::erase(
    &this->freeEvents,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<AudioEvent *> > > > >)v5->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<AudioEvent *> > > > >)v5);
  operator delete(this->freeEvents._Myhead);
  v6 = this->registeredEvents._Myhead;
  v7 = v6->_Next;
  v6->_Next = v6;
  this->registeredEvents._Myhead->_Prev = this->registeredEvents._Myhead;
  this->registeredEvents._Mysize = 0;
  if ( v7 != this->registeredEvents._Myhead )
  {
    do
    {
      v8 = v7->_Next;
      operator delete(v7);
      v7 = v8;
    }
    while ( v8 != this->registeredEvents._Myhead );
  }
  operator delete(this->registeredEvents._Myhead);
  std::list<AudioEngine::BankEntry>::clear(&this->loadedBanks);
  operator delete(this->loadedBanks._Myhead);
  v9 = this->registeredGuids._Myhead;
  v13 = -1;
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->registeredGuids,
    (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > *)&result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v9->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v9);
  operator delete(this->registeredGuids._Myhead);
}
void AudioEngine::addBankRef(AudioEngine *this, const std::wstring *path)
{
  std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,std::wstring > >,0> > *v2; // ebx
  std::string *v3; // eax
  std::wstring *v4; // eax
  const __m128i *v5; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *v6; // ecx
  std::_List_buy<AudioEngine::BankEntry> *v7; // ebp
  AudioEngine::GUID v8; // xmm0
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *v9; // eax
  const std::wstring *v10; // edx
  unsigned int v11; // ecx
  char v12; // al
  bool v13; // bl
  std::string *v14; // eax
  const std::wstring *v15; // eax
  AudioEngine::GUID v16; // xmm0
  std::string *v17; // eax
  FMOD_RESULT v18; // eax
  std::_List_node<AudioEngine::BankEntry,void *> *v19; // esi
  __m128i *v20; // edx
  unsigned int v21; // eax
  unsigned int _Off; // [esp+14h] [ebp-C4h] BYREF
  std::bidirectional_iterator_tag __formal[4]; // [esp+18h] [ebp-C0h]
  std::vector<char> encodedPath; // [esp+1Ch] [ebp-BCh] BYREF
  AudioEngine::GUID v25; // [esp+28h] [ebp-B0h] BYREF
  AudioEngine::GUID guid; // [esp+38h] [ebp-A0h] BYREF
  int v27; // [esp+48h] [ebp-90h]
  unsigned int v28; // [esp+4Ch] [ebp-8Ch]
  std::string sPath; // [esp+50h] [ebp-88h] BYREF
  std::string result; // [esp+68h] [ebp-70h] BYREF
  AudioEngine::BankEntry newEntry; // [esp+80h] [ebp-58h] BYREF
  std::wstring guidPath; // [esp+B0h] [ebp-28h] BYREF
  int v33; // [esp+D4h] [ebp-4h]

  v2 = (std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,std::wstring > >,0> > *)this;
  *(_DWORD *)&__formal[0].gap0 = this;
  v3 = wstring2string(&result, path);
  if ( v3->_Myres >= 0x10 )
    v3 = (std::string *)v3->_Bx._Ptr;
  audioLog("AudioEngine.cpp", 1198, "log", "Loading bank %s", v3->_Bx._Buf);
  if ( result._Myres >= 0x10 )
    operator delete(result._Bx._Ptr);
  v4 = Path::getFileNameWithoutExtension((std::wstring *)&result, path);
  v33 = 0;
  std::operator+<wchar_t>(&guidPath, L"bank:/", v4);
  LOBYTE(v33) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  *(_WORD *)result._Bx._Buf = 0;
  result._Mysize = 0;
  std::_Tree<std::_Tmap_traits<std::wstring,AudioEngine::GUID,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,AudioEngine::GUID>>,0>>::_Eqrange(
    v2 + 2,
    (std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::wstring > > > >,std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::wstring > > > > > *)&guid,
    &guidPath);
  _Off = 0;
  std::_Distance2<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const,AudioEngine::GUID>>>>,unsigned int>(
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::wstring > > > >)guid.data[0],
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::wstring > > > >)guid.data[1],
    &_Off);
  if ( !_Off )
    audioLog(
      "AudioEngine.cpp",
      1200,
      "error",
      "registeredGuids.count(guidPath). The specified bank was not present in any registered GUID file");
  v5 = (const __m128i *)std::map<std::wstring,AudioEngine::GUID>::operator[](
                          (std::map<std::wstring,AudioEngine::GUID> *)&v2[2],
                          &guidPath);
  v6 = v2[3]._Myhead;
  v7 = (std::_List_buy<AudioEngine::BankEntry> *)&v2[3];
  _Off = (unsigned int)&v2[3];
  v8 = (AudioEngine::GUID)_mm_loadu_si128(v5);
  v9 = v6->_Left;
  v25 = v8;
  guid = v8;
  if ( v9 == v6 )
  {
LABEL_17:
    if ( path->_Myres < 8 )
      v10 = path;
    else
      v10 = (const std::wstring *)path->_Bx._Ptr;
    v28 = 7;
    v27 = 0;
    LOWORD(guid.data[0]) = 0;
    if ( v10->_Bx._Buf[0] )
      v11 = wcslen(v10->_Bx._Buf);
    else
      v11 = 0;
    std::wstring::assign((std::wstring *)&guid, v10->_Bx._Buf, v11);
    LOBYTE(v33) = 3;
    v12 = Path::fileExists((unsigned int)v2, (const std::wstring *)&guid, 0);
    LOBYTE(v33) = 2;
    v13 = v12 == 0;
    if ( v28 >= 8 )
      operator delete(guid.data[0]);
    if ( v13 )
    {
      v14 = wstring2string((std::string *)&guid, path);
      if ( v14->_Myres >= 0x10 )
        v14 = (std::string *)v14->_Bx._Ptr;
      audioLog(
        "AudioEngine.cpp",
        1212,
        "error",
        "Path::fileExists(path.c_str()). Tried to add a reference to a bank file that does not exist: %s",
        v14->_Bx._Buf);
      if ( v28 >= 0x10 )
        operator delete(guid.data[0]);
    }
    v15 = Path::getPlatformSpecificPath((std::wstring *)&guid, path);
    LOBYTE(v33) = 4;
    ksEncodeUtf8(&encodedPath, v15);
    LOBYTE(v33) = 6;
    if ( v28 >= 8 )
      operator delete(guid.data[0]);
    v28 = 7;
    v27 = 0;
    LOWORD(guid.data[0]) = 0;
    sPath._Myres = 15;
    sPath._Mysize = 0;
    sPath._Bx._Buf[0] = 0;
    std::string::_Construct<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<char>>>>(
      &sPath,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<char> > >)encodedPath._Myfirst,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<char> > >)encodedPath._Mylast,
      __formal[0].std::forward_iterator_tag);
    newEntry.path._Myres = 7;
    newEntry.path._Mysize = 0;
    newEntry.path._Bx._Buf[0] = 0;
    newEntry.bank = 0;
    newEntry.refCount = 0;
    LOBYTE(v33) = 8;
    if ( &newEntry != (AudioEngine::BankEntry *)path )
      std::wstring::assign(&newEntry.path, path, 0, 0xFFFFFFFF);
    v16 = (AudioEngine::GUID)_mm_loadu_si128((const __m128i *)&v25);
    v17 = &sPath;
    if ( sPath._Myres >= 0x10 )
      v17 = (std::string *)sPath._Bx._Ptr;
    newEntry.guid = v16;
    v18 = FMOD::Studio::System::loadBankFile(**(_DWORD **)&__formal[0].gap0, v17, 0, &newEntry.bank);
    if ( v18 )
      audioFmodCallError("AudioEngine.cpp", 1220, v18);
    v19 = v7->_Myhead;
    newEntry.refCount = 1;
    v20 = std::_List_buy<AudioEngine::BankEntry>::_Buynode<AudioEngine::BankEntry const &>(
            v7,
            v19,
            v19->_Prev,
            &newEntry);
    v21 = v7->_Mysize;
    if ( v21 == 76695843 )
      std::_Xlength_error("list<T> too long");
    v7->_Mysize = v21 + 1;
    v19->_Prev = (std::_List_node<AudioEngine::BankEntry,void *> *)v20;
    *(_DWORD *)v20->m128i_i32[1] = v20;
    if ( newEntry.path._Myres >= 8 )
      operator delete(newEntry.path._Bx._Ptr);
    newEntry.path._Myres = 7;
    newEntry.path._Mysize = 0;
    newEntry.path._Bx._Buf[0] = 0;
    if ( sPath._Myres >= 0x10 )
      operator delete(sPath._Bx._Ptr);
    sPath._Myres = 15;
    sPath._Mysize = 0;
    sPath._Bx._Buf[0] = 0;
    if ( encodedPath._Myfirst )
    {
      operator delete(encodedPath._Myfirst);
      encodedPath._Myfirst = 0;
      encodedPath._Mylast = 0;
      encodedPath._Myend = 0;
    }
  }
  else
  {
    v2 = (std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,std::wstring > >,0> > *)guid.data[1];
    while ( v9->_Myval.first._Mysize != guid.data[0]
         || v9->_Myval.first._Myres != guid.data[1]
         || v9->_Myval.second._Bx._Ptr != (wchar_t *)guid.data[2]
         || *(_DWORD *)&v9->_Myval.second._Bx._Alias[4] != guid.data[3] )
    {
      v9 = v9->_Left;
      if ( v9 == v6 )
      {
        v7 = (std::_List_buy<AudioEngine::BankEntry> *)_Off;
        goto LABEL_17;
      }
    }
    ++*(_DWORD *)&v9->_Myval.second._Bx._Alias[12];
  }
  if ( guidPath._Myres >= 8 )
    operator delete(guidPath._Bx._Ptr);
}
void AudioEngine::addCache(AudioEngine *this, const std::wstring *path)
{
  const std::wstring *v3; // edi
  std::vector<AudioEvent *> *v4; // eax
  int v5; // ebx
  std::_List_node<AudioEvent,void *> *v6; // esi
  std::_List_node<AudioEvent,void *> *v7; // edx
  unsigned int v8; // eax
  std::map<std::wstring,std::vector<AudioEvent *>> *v9; // ecx
  AudioEvent *v10; // edi
  std::vector<jsonwriter::Node *> *v11; // esi
  jsonwriter::Node **v12; // ecx
  int v13; // edi
  jsonwriter::Node **v14; // ecx
  _DWORD *v15; // eax
  AudioEvent *v16; // [esp+8h] [ebp-Ch] BYREF
  AudioEngine *v17; // [esp+Ch] [ebp-8h] BYREF
  std::map<std::wstring,std::vector<AudioEvent *>> *v18; // [esp+10h] [ebp-4h]

  v3 = path;
  v18 = &this->freeEvents;
  v4 = std::map<std::wstring,std::vector<AudioEvent *>>::operator[](&this->freeEvents, path);
  if ( v4->_Myfirst == v4->_Mylast )
  {
    v5 = 0;
    v17 = this;
    do
    {
      v6 = this->cachedEvents._Myhead;
      v7 = std::_List_buy<AudioEvent>::_Buynode<AudioEngine * const,std::wstring const &>(
             &this->cachedEvents,
             v6,
             v6->_Prev,
             &v17,
             v3);
      v8 = this->cachedEvents._Mysize;
      if ( v8 == 76695843 )
        std::_Xlength_error("list<T> too long");
      this->cachedEvents._Mysize = v8 + 1;
      v9 = v18;
      v6->_Prev = v7;
      v7->_Prev->_Next = v7;
      v10 = &this->cachedEvents._Myhead->_Prev->_Myval;
      v16 = v10;
      v11 = (std::vector<jsonwriter::Node *> *)std::map<std::wstring,std::vector<AudioEvent *>>::operator[](v9, path);
      v12 = v11->_Mylast;
      if ( &v16 >= (AudioEvent **)v12 || v11->_Myfirst > (jsonwriter::Node **)&v16 )
      {
        if ( v12 == v11->_Myend )
          std::vector<AudioEvent *>::_Reserve(v11, 1u);
        v15 = v11->_Mylast;
        if ( v15 )
          *v15 = v10;
      }
      else
      {
        v13 = ((char *)&v16 - (char *)v11->_Myfirst) >> 2;
        if ( v12 == v11->_Myend )
          std::vector<AudioEvent *>::_Reserve(v11, 1u);
        v14 = v11->_Mylast;
        if ( v14 )
          *v14 = v11->_Myfirst[v13];
      }
      ++v11->_Mylast;
      ++v5;
      v3 = path;
    }
    while ( v5 < 12 );
  }
}
AudioEvent *AudioEngine::getCachedEvent(AudioEngine *this, const std::wstring *path)
{
  std::map<std::wstring,std::vector<AudioEvent *>> *v2; // esi
  std::vector<AudioEvent *> *v3; // eax
  int v4; // ebx
  std::vector<AudioEvent *> *v5; // eax

  v2 = &this->freeEvents;
  v3 = std::map<std::wstring,std::vector<AudioEvent *>>::operator[](&this->freeEvents, path);
  if ( v3->_Myfirst == v3->_Mylast )
    return 0;
  v4 = *((_DWORD *)std::map<std::wstring,std::vector<AudioEvent *>>::operator[](v2, path)->_Mylast - 1);
  if ( !v4 )
    return 0;
  v5 = std::map<std::wstring,std::vector<AudioEvent *>>::operator[](v2, path);
  --v5->_Mylast;
  return (AudioEvent *)v4;
}
std::wstring *AudioEngine::getDriverInfo(AudioEngine *this, std::wstring *result, int driverIndex)
{
  FMOD_RESULT v3; // eax
  std::wstring *v4; // edi
  bool v5; // cf
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  FMOD::Studio::System *v11; // [esp+10h] [ebp-CCh]
  FMOD::System *fsystem; // [esp+24h] [ebp-B8h] BYREF
  int v13; // [esp+28h] [ebp-B4h]
  int speakermodechannels; // [esp+2Ch] [ebp-B0h] BYREF
  int systemrate[2]; // [esp+30h] [ebp-ACh] BYREF
  FMOD_SPEAKERMODE speakermode; // [esp+38h] [ebp-A4h] BYREF
  FMOD_GUID guid; // [esp+3Ch] [ebp-A0h] BYREF
  char name[128]; // [esp+4Ch] [ebp-90h] BYREF
  int v19; // [esp+D8h] [ebp-4h]

  v13 = 0;
  v11 = this->system;
  v19 = 0;
  systemrate[1] = (int)result;
  FMOD::Studio::System::getLowLevelSystem(v11, &fsystem);
  v3 = FMOD::System::getDriverInfo(
         fsystem,
         driverIndex,
         name,
         128,
         &guid,
         systemrate,
         &speakermode,
         &speakermodechannels);
  if ( v3 )
    audioFmodCallError("AudioEngine.cpp", 812, v3);
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  if ( result->_Myres < 0x80 )
    std::wstring::_Copy(result, 0x80u, result->_Mysize);
  if ( result->_Myres < 8 )
    v4 = result;
  else
    v4 = (std::wstring *)result->_Bx._Ptr;
  memset32(v4, 2097184, 0x40u);
  v5 = result->_Myres < 8;
  result->_Mysize = 128;
  if ( v5 )
    v6 = result;
  else
    v6 = (std::wstring *)result->_Bx._Ptr;
  LOWORD(v6[10]._Mysize) = 0;
  v5 = result->_Myres < 8;
  v19 = 0;
  v13 = 1;
  if ( v5 )
    v7 = result;
  else
    v7 = (std::wstring *)result->_Bx._Ptr;
  v8 = _mbstowcs(v7->_Bx._Buf, name, 0x80u);
  v9 = result->_Mysize;
  if ( v8 > v9 )
  {
    std::wstring::append(result, v8 - v9, 0);
  }
  else
  {
    v5 = result->_Myres < 8;
    result->_Mysize = v8;
    if ( v5 )
      result->_Bx._Buf[v8] = 0;
    else
      result->_Bx._Ptr[v8] = 0;
  }
  return result;
}
int AudioEngine::getDriverNum(AudioEngine *this)
{
  FMOD_RESULT v1; // eax
  int numdrivers; // [esp+10h] [ebp-8h] BYREF
  FMOD::System *fsystem; // [esp+14h] [ebp-4h] BYREF

  FMOD::Studio::System::getLowLevelSystem(this->system, &fsystem);
  numdrivers = 0;
  v1 = FMOD::System::getNumDrivers(fsystem, &numdrivers);
  if ( v1 )
    audioFmodCallError("AudioEngine.cpp", 798, v1);
  return numdrivers;
}
vec3f *AudioEngine::getListenerPosition(AudioEngine *this, vec3f *result)
{
  FMOD_RESULT v2; // eax
  vec3f *v3; // eax
  FMOD_3D_ATTRIBUTES attribs; // [esp+Ch] [ebp-34h] BYREF

  v2 = FMOD::Studio::System::getListenerAttributes(this->system, 0, &attribs);
  if ( !logged_34 && v2 )
  {
    logged_34 = 1;
    audioFmodCallError("AudioEngine.cpp", 1096, v2);
  }
  v3 = result;
  *result = (vec3f)attribs.position;
  return v3;
}
AudioStats *AudioEngine::getPerformanceStats(AudioEngine *this, AudioStats *result)
{
  FMOD_RESULT v3; // eax
  FMOD_RESULT v4; // eax
  FMOD_RESULT v5; // eax
  __m128i v6; // xmm1
  float v7; // xmm0_4
  AudioStats *v8; // eax
  __m128i v9; // xmm0
  int numChannels; // [esp+1Ch] [ebp-44h] BYREF
  FMOD_STUDIO_CPU_USAGE cpuUsage; // [esp+20h] [ebp-40h] BYREF
  FMOD_STUDIO_BUFFER_USAGE bufferUsage; // [esp+34h] [ebp-2Ch] BYREF

  v3 = FMOD::System::getChannelsPlaying(this->lowLevelSystem, &numChannels, 0);
  if ( !logged_30 && v3 )
  {
    logged_30 = 1;
    audioFmodCallError("AudioEngine.cpp", 1072, v3);
  }
  v4 = FMOD::Studio::System::getBufferUsage(this->system, &bufferUsage);
  if ( !logged_31 && v4 )
  {
    logged_31 = 1;
    audioFmodCallError("AudioEngine.cpp", 1073, v4);
  }
  v5 = FMOD::Studio::System::getCPUUsage(this->system, &cpuUsage);
  if ( !logged_32 && v5 )
  {
    logged_32 = 1;
    audioFmodCallError("AudioEngine.cpp", 1074, v5);
  }
  v6 = _mm_cvtsi32_si128(bufferUsage.studioCommandQueue.currentUsage);
  v7 = (float)bufferUsage.studioCommandQueue.capacity;
  result->numChannels = numChannels;
  v8 = result;
  *(float *)v6.m128i_i32 = _mm_cvtepi32_ps(v6).m128_f32[0] / v7;
  result->commandQueueStallTime = bufferUsage.studioCommandQueue.stallTime * 1000.0;
  v9 = _mm_cvtsi32_si128(bufferUsage.studioHandle.capacity);
  result->commandQueueUsage = *(float *)v6.m128i_i32 * 100.0;
  *(float *)v6.m128i_i32 = (float)((float)bufferUsage.studioHandle.currentUsage / _mm_cvtepi32_ps(v9).m128_f32[0])
                         * 100.0;
  result->handleStallTime = bufferUsage.studioHandle.stallTime * 1000.0;
  result->dspCpuUsage = cpuUsage.dspUsage;
  *(float *)v9.m128i_i32 = cpuUsage.studioUsage + cpuUsage.updateUsage;
  LODWORD(result->handleUsage) = v6.m128i_i32[0];
  LODWORD(result->updateCpuUsage) = v9.m128i_i32[0];
  return v8;
}
double AudioEngine::getVolume(AudioEngine *this, const bool target)
{
  double result; // st7

  if ( target )
    result = this->targetVolume;
  else
    result = this->masterVolume;
  return result;
}
bool AudioEngine::hasEvent(AudioEngine *this, const std::wstring *path)
{
  std::wstring *v3; // ecx
  std::wstring *v4; // edi
  wchar_t *v5; // eax
  std::wstring *v6; // ecx
  bool v7; // bl
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > result; // [esp+10h] [ebp-34h] BYREF
  std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::wstring > > > >,std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::wstring > > > > > v10; // [esp+14h] [ebp-30h] BYREF
  std::wstring lowerPath; // [esp+1Ch] [ebp-28h] BYREF
  int v12; // [esp+40h] [ebp-4h]

  lowerPath._Bx._Buf[0] = 0;
  lowerPath._Myres = 7;
  lowerPath._Mysize = 0;
  std::wstring::assign(&lowerPath, path, 0, 0xFFFFFFFF);
  v3 = &lowerPath;
  v4 = &lowerPath;
  v12 = 0;
  if ( lowerPath._Myres >= 8 )
    v3 = (std::wstring *)lowerPath._Bx._Ptr;
  if ( lowerPath._Myres >= 8 )
    v4 = (std::wstring *)lowerPath._Bx._Ptr;
  v5 = &v3->_Bx._Buf[lowerPath._Mysize];
  v6 = &lowerPath;
  if ( lowerPath._Myres >= 8 )
    v6 = (std::wstring *)lowerPath._Bx._Ptr;
  if ( v6 != (std::wstring *)v5 )
    std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
      &result,
      v6->_Bx._Buf,
      v5,
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v4,
      _tolower);
  std::_Tree<std::_Tmap_traits<std::wstring,AudioEngine::GUID,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,AudioEngine::GUID>>,0>>::_Eqrange(
    (std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,std::wstring > >,0> > *)&this->registeredGuids,
    &v10,
    &lowerPath);
  result._Ptr = 0;
  std::_Distance2<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const,AudioEngine::GUID>>>>,unsigned int>(
    v10.first,
    v10.second,
    (unsigned int *)&result);
  v7 = result._Ptr != 0;
  if ( lowerPath._Myres >= 8 )
    operator delete(lowerPath._Bx._Ptr);
  return v7;
}
double AudioEngine::listenerDistance(AudioEngine *this, vec3f position)
{
  FMOD_RESULT v3; // eax
  FMOD_RESULT v4; // eax
  float v6; // [esp+Ch] [ebp-48h]
  char v7[12]; // [esp+10h] [ebp-44h] BYREF
  FMOD_3D_ATTRIBUTES listenerAttribs; // [esp+20h] [ebp-34h] BYREF

  v3 = FMOD::Studio::System::getListenerAttributes(this->system, 0, &listenerAttribs);
  if ( v3 )
    audioFmodCallError("AudioEngine.cpp", 1314, v3);
  v4 = FMOD::System::get3DSettings(this->lowLevelSystem, 0);
  if ( v4 )
    audioFmodCallError("AudioEngine.cpp", 1315, v4);
  return fsqrt(
           (float)((float)((float)(COERCE_FLOAT(v7) - listenerAttribs.forward.z)
                         * (float)(COERCE_FLOAT(v7) - listenerAttribs.forward.z))
                 + (float)((float)(0.0 - listenerAttribs.forward.y) * (float)(0.0 - listenerAttribs.forward.y)))
         + (float)((float)(v6 - listenerAttribs.up.x) * (float)(v6 - listenerAttribs.up.x)));
}
AudioEngine::GUID *AudioEngine::lookupGUID(AudioEngine *this, AudioEngine::GUID *result, const std::wstring *path)
{
  std::wstring *v4; // ecx
  std::wstring *v5; // ebx
  wchar_t *v6; // eax
  std::wstring *v7; // ecx
  const __m128i *v8; // eax
  bool v9; // cf
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v11; // [esp+14h] [ebp-2Ch] BYREF
  std::wstring lowerPath; // [esp+18h] [ebp-28h] BYREF
  int v13; // [esp+3Ch] [ebp-4h]

  lowerPath._Bx._Buf[0] = 0;
  lowerPath._Myres = 7;
  lowerPath._Mysize = 0;
  std::wstring::assign(&lowerPath, path, 0, 0xFFFFFFFF);
  v4 = &lowerPath;
  v5 = &lowerPath;
  v13 = 0;
  if ( lowerPath._Myres >= 8 )
    v4 = (std::wstring *)lowerPath._Bx._Ptr;
  if ( lowerPath._Myres >= 8 )
    v5 = (std::wstring *)lowerPath._Bx._Ptr;
  v6 = &v4->_Bx._Buf[lowerPath._Mysize];
  v7 = &lowerPath;
  if ( lowerPath._Myres >= 8 )
    v7 = (std::wstring *)lowerPath._Bx._Ptr;
  if ( v7 != (std::wstring *)v6 )
    std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
      &v11,
      v7->_Bx._Buf,
      v6,
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v5,
      _tolower);
  v8 = (const __m128i *)std::map<std::wstring,AudioEngine::GUID>::operator[](&this->registeredGuids, &lowerPath);
  v9 = lowerPath._Myres < 8;
  *(__m128i *)result = _mm_loadu_si128(v8);
  if ( !v9 )
    operator delete(lowerPath._Bx._Ptr);
  return result;
}
void AudioEngine::parseGUIDs(AudioEngine *this, const std::wstring *path)
{
  const std::wstring *v2; // eax
  _DWORD *v3; // ecx
  int (__cdecl *v4)(int); // ebp
  wchar_t v5; // ax
  std::wstring *v6; // esi
  std::wstring *v7; // eax
  int v8; // edi
  wchar_t *v9; // esi
  wchar_t *v10; // ebx
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  wchar_t *v14; // ebx
  int v15; // esi
  wchar_t *v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // ebx
  unsigned int *v20; // edi
  unsigned int *v21; // esi
  int v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // esi
  std::wstring *v26; // ebx
  unsigned int *v27; // esi
  int v28; // eax
  int v29; // eax
  wchar_t *v30; // ebx
  int v31; // ebp
  unsigned __int16 *v32; // esi
  int v33; // eax
  int v34; // eax
  unsigned int v35; // edi
  unsigned int v36; // ecx
  int v37; // eax
  unsigned int v38; // edi
  int v39; // eax
  int v40; // eax
  std::wstring *v41; // ecx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v42; // ecx
  std::wstring *v43; // eax
  unsigned int v44; // edx
  std::wstring *v45; // ecx
  wchar_t *v46; // ebx
  std::wstring *v47; // esi
  wchar_t *v48; // eax
  std::wstring *v49; // ecx
  std::_Tree_buy<std::pair<std::wstring const ,AudioEngine::GUID>> *v50; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,AudioEngine::GUID> > > > v51; // esi
  std::_Tree_node<std::pair<std::wstring const ,AudioEngine::GUID>,void *> *v52; // edi
  std::wstring *v53; // eax
  const wchar_t *v54; // eax
  std::_Tree_node<std::pair<std::wstring const ,AudioEngine::GUID>,void *> *v55; // eax
  __m128i v56; // xmm0
  std::_Tree<std::_Tmap_traits<std::wstring,AudioEngine::GUID,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,AudioEngine::GUID> >,0> > *v57; // [esp+14h] [ebp-13Ch]
  std::_Tree<std::_Tmap_traits<std::wstring,AudioEngine::GUID,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,AudioEngine::GUID> >,0> > *v58; // [esp+14h] [ebp-13Ch]
  int v59; // [esp+18h] [ebp-138h] BYREF
  std::tuple<std::wstring const &> v60; // [esp+1Ch] [ebp-134h] BYREF
  int v61; // [esp+20h] [ebp-130h]
  std::forward_iterator_tag __formal[4]; // [esp+24h] [ebp-12Ch] BYREF
  AudioEngine *v63; // [esp+28h] [ebp-128h]
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v64; // [esp+2Ch] [ebp-124h] BYREF
  AudioEngine::GUID guid; // [esp+30h] [ebp-120h] BYREF
  std::wifstream stream; // [esp+40h] [ebp-110h] BYREF
  std::wstring line; // [esp+F8h] [ebp-58h] BYREF
  std::wstring result; // [esp+110h] [ebp-40h] BYREF
  std::wstring v69; // [esp+128h] [ebp-28h] BYREF
  int v70; // [esp+14Ch] [ebp-4h]

  v63 = this;
  v2 = Path::getPlatformSpecificPath(&result, path);
  v70 = 0;
  std::wifstream::wifstream(&stream, v2, 1, 64, 1);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  line._Myres = 7;
  line._Mysize = 0;
  line._Bx._Buf[0] = 0;
  v3 = (_DWORD *)(*(_DWORD *)stream.gap0 + 4);
  LOBYTE(v70) = 3;
  if ( (*((_BYTE *)&stream._Chcount + *(_DWORD *)(*(_DWORD *)stream.gap0 + 4) + 4) & 1) == 0 )
  {
    v4 = _isdigit;
    while ( 1 )
    {
      v5 = std::wios::widen((char *)&stream + *v3, 10);
      std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&stream, &line, v5);
      v6 = ksTrim(&v69, &line);
      if ( &line != v6 )
      {
        if ( line._Myres >= 8 )
          operator delete(line._Bx._Ptr);
        line._Myres = 7;
        line._Mysize = 0;
        line._Bx._Buf[0] = 0;
        if ( v6->_Myres >= 8 )
        {
          line._Bx._Ptr = v6->_Bx._Ptr;
          v6->_Bx._Ptr = 0;
        }
        else if ( v6->_Mysize != -1 )
        {
          _memmove(&line, v6, 2 * (v6->_Mysize + 1));
        }
        line._Mysize = v6->_Mysize;
        line._Myres = v6->_Myres;
        v6->_Myres = 7;
        v6->_Mysize = 0;
        v6->_Bx._Buf[0] = 0;
      }
      if ( v69._Myres >= 8 )
        operator delete(v69._Bx._Ptr);
      if ( !line._Mysize )
        goto LABEL_83;
      v7 = &line;
      if ( line._Myres >= 8 )
        v7 = (std::wstring *)line._Bx._Ptr;
      v8 = 0;
      v57 = (std::_Tree<std::_Tmap_traits<std::wstring,AudioEngine::GUID,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,AudioEngine::GUID> >,0> > *)v7;
      v9 = &v7->_Bx._Buf[1];
      v10 = (wchar_t *)&v7->_Mysize + 1;
      if ( (char *)&v7->_Bx._Ptr + 2 < (char *)&v7->_Mysize + 2 )
      {
        do
        {
          v11 = v4(*v9) == 0;
          v12 = *v9;
          if ( v11 )
            v13 = v12 - 87;
          else
            v13 = v12 - 48;
          ++v9;
          v8 = v13 | (16 * v8);
        }
        while ( v9 < v10 );
        v7 = (std::wstring *)v57;
      }
      guid.data[0] = v8;
      v14 = &v7[1]._Bx._Buf[7];
      v15 = 0;
      v16 = &v7[1]._Bx._Buf[3];
      v61 = 0;
      if ( &v7[1]._Bx._Alias[6] < &v7[1]._Bx._Alias[14] )
      {
        do
        {
          v11 = v4(*v16) == 0;
          v17 = *v16;
          if ( v11 )
            v18 = v17 - 87;
          else
            v18 = v17 - 48;
          ++v16;
          v15 = v18 | (16 * v15);
        }
        while ( v16 < v14 );
        v7 = (std::wstring *)v57;
        v61 = v15;
      }
      v19 = 0;
      v20 = &v7->_Myres;
      v60._Myfirst._Val = (std::wstring *)((char *)v7 + 28);
      if ( &v7->_Myres < (unsigned int *)&v7[1]._Bx._Alias[4] )
      {
        v21 = (unsigned int *)&v7[1]._Bx._Alias[4];
        do
        {
          v11 = v4(*(unsigned __int16 *)v20) == 0;
          v22 = *(unsigned __int16 *)v20;
          if ( v11 )
            v23 = v22 - 87;
          else
            v23 = v22 - 48;
          v20 = (unsigned int *)((char *)v20 + 2);
          v19 = v23 | (16 * v19);
        }
        while ( v20 < v21 );
        v15 = v61;
        v7 = (std::wstring *)v57;
      }
      v24 = 0;
      v25 = v19 | (v15 << 16);
      v26 = v7 + 2;
      guid.data[1] = v25;
      v27 = &v7[1]._Mysize;
      if ( &v7[1]._Mysize < (unsigned int *)&v7[2] )
      {
        do
        {
          v11 = v4(*(unsigned __int16 *)v27) == 0;
          v28 = *(unsigned __int16 *)v27;
          if ( v11 )
            v29 = v28 - 87;
          else
            v29 = v28 - 48;
          v27 = (unsigned int *)((char *)v27 + 2);
          v24 = v29 | (16 * v24);
        }
        while ( v27 < (unsigned int *)v26 );
        v7 = (std::wstring *)v57;
      }
      v30 = &v7[2]._Bx._Buf[1];
      v31 = 0;
      v32 = &v7[2]._Bx._Buf[5];
      if ( (char *)&v7[2]._Bx._Ptr + 2 < &v7[2]._Bx._Alias[10] )
      {
        do
        {
          v11 = _isdigit(*v30) == 0;
          v33 = *v30;
          if ( v11 )
            v34 = v33 - 87;
          else
            v34 = v33 - 48;
          ++v30;
          v31 = v34 | (16 * v31);
        }
        while ( v30 < v32 );
      }
      v35 = v31 | (v24 << 16);
      v4 = _isdigit;
      v36 = (HIWORD(v35) | (unsigned int)&unk_FF0000 & v35) >> 8;
      v37 = (v35 & 0xFF00 | (v35 << 16)) << 8;
      v38 = 0;
      for ( guid.data[2] = v37 | v36; v32 < (unsigned __int16 *)&v57[9]._Myhead + 1; v38 = v40 | (16 * v38) )
      {
        v11 = _isdigit(*v32) == 0;
        v39 = *v32;
        if ( v11 )
          v40 = v39 - 87;
        else
          v40 = v39 - 48;
        ++v32;
      }
      result._Myres = 7;
      result._Mysize = 0;
      guid.data[3] = ((v38 & 0xFF00 | (v38 << 16)) << 8) | ((HIWORD(v38) | (unsigned int)&unk_FF0000 & v38) >> 8);
      v41 = &line;
      if ( line._Myres >= 8 )
        v41 = (std::wstring *)line._Bx._Ptr;
      v42._Ptr = &v41->_Bx._Buf[line._Mysize];
      v43 = &line;
      if ( line._Myres >= 8 )
        v43 = (std::wstring *)line._Bx._Ptr;
      result._Bx._Buf[0] = 0;
      std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
        &result,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&v43[3]._Bx._Alias[6],
        v42,
        __formal[0]);
      v44 = result._Myres;
      v45 = &result;
      v46 = result._Bx._Ptr;
      v47 = &result;
      LOBYTE(v70) = 4;
      if ( result._Myres >= 8 )
        v45 = (std::wstring *)result._Bx._Ptr;
      if ( result._Myres >= 8 )
        v47 = (std::wstring *)result._Bx._Ptr;
      v48 = &v45->_Bx._Buf[result._Mysize];
      v49 = &result;
      if ( result._Myres >= 8 )
        v49 = (std::wstring *)result._Bx._Ptr;
      if ( v49 == (std::wstring *)v48 )
      {
        v64._Ptr = (const wchar_t *)v47;
      }
      else
      {
        std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
          &v64,
          v49->_Bx._Buf,
          v48,
          (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v47,
          _tolower);
        v44 = result._Myres;
        v46 = result._Bx._Ptr;
      }
      v50 = &v63->registeredGuids;
      v58 = &v63->registeredGuids;
      v51._Ptr = v63->registeredGuids._Myhead;
      v52 = v51._Ptr->_Parent;
      if ( !v52->_Isnil )
      {
        while ( 1 )
        {
          v53 = &result;
          if ( v44 >= 8 )
            v53 = (std::wstring *)v46;
          if ( std::wstring::compare(
                 (std::wstring *)&v52->_Myval.first,
                 0,
                 v52->_Myval.first._Mysize,
                 v53->_Bx._Buf,
                 result._Mysize) >= 0 )
          {
            v51._Ptr = v52;
            v52 = v52->_Left;
          }
          else
          {
            v52 = v52->_Right;
          }
          if ( v52->_Isnil )
            break;
          v44 = result._Myres;
          v46 = result._Bx._Ptr;
        }
        v50 = v58;
      }
      if ( v51._Ptr != v50->_Myhead )
      {
        v54 = v51._Ptr->_Myval.first._Bx._Buf;
        if ( v51._Ptr->_Myval.first._Myres >= 8 )
          v54 = *(const wchar_t **)v54;
        if ( std::wstring::compare(&result, 0, result._Mysize, v54, v51._Ptr->_Myval.first._Mysize) >= 0 )
          goto LABEL_81;
        v50 = v58;
      }
      v60._Myfirst._Val = &result;
      v55 = (std::_Tree_node<std::pair<std::wstring const ,AudioEngine::GUID>,void *> *)std::_Tree_buy<std::pair<std::wstring const,AudioEngine::GUID>>::_Buynode<std::piecewise_construct_t const &,std::tuple<std::wstring const &>,std::tuple<>>(
                                                                                          v50,
                                                                                          &piecewise_construct_67,
                                                                                          &v60,
                                                                                          (std::tuple<> *)&v59 + 3);
      std::_Tree<std::_Tmap_traits<std::wstring,AudioEngine::GUID,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,AudioEngine::GUID>>,0>>::_Insert_hint<std::pair<std::wstring const,AudioEngine::GUID> &,std::_Tree_node<std::pair<std::wstring const,AudioEngine::GUID>,void *> *>(
        v58,
        (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,AudioEngine::GUID> > > > *)__formal,
        v51,
        &v55->_Myval,
        v55);
      v51._Ptr = *(std::_Tree_node<std::pair<std::wstring const ,AudioEngine::GUID>,void *> **)&__formal[0].gap0;
LABEL_81:
      v56 = _mm_loadu_si128((const __m128i *)&guid);
      LOBYTE(v70) = 3;
      v51._Ptr->_Myval.second = (AudioEngine::GUID)v56;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
LABEL_83:
      v3 = (_DWORD *)(*(_DWORD *)stream.gap0 + 4);
      if ( (*((_BYTE *)&stream._Chcount + *(_DWORD *)(*(_DWORD *)stream.gap0 + 4) + 4) & 1) != 0 )
      {
        if ( line._Myres >= 8 )
          operator delete(line._Bx._Ptr);
        break;
      }
    }
  }
  line._Myres = 7;
  line._Mysize = 0;
  line._Bx._Buf[0] = 0;
  std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&stream.gap64[12]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&stream.gap64[12]);
}
void AudioEngine::releaseCachedEvent(AudioEngine *this, AudioEvent *_event)
{
  AudioEvent *v2; // esi
  FMOD_RESULT v4; // eax
  std::vector<jsonwriter::Node *> *v5; // eax

  v2 = _event;
  if ( _event )
  {
    v4 = FMOD::Studio::EventInstance::stop(_event->instance, 0);
    if ( !logged_7 )
    {
      if ( v4 )
      {
        logged_7 = 1;
        audioFmodCallError("AudioEngine.cpp", 404, v4);
      }
    }
    v5 = (std::vector<jsonwriter::Node *> *)std::map<std::wstring,std::vector<AudioEvent *>>::operator[](
                                              &this->freeEvents,
                                              &v2->path);
    std::vector<AudioEvent *>::push_back(v5, (jsonwriter::Node **)&_event);
  }
}
void AudioEngine::removeBankRef(AudioEngine *this, const std::wstring *path)
{
  std::_List_node<AudioEngine::BankEntry,void *> *v3; // eax
  std::_List_node<AudioEngine::BankEntry,void *> *v4; // esi
  const std::wstring *v5; // eax

  v3 = this->loadedBanks._Myhead;
  v4 = v3->_Next;
  if ( v3->_Next != v3 )
  {
    while ( 1 )
    {
      v5 = path->_Myres < 8 ? path : path->_Bx._Ptr;
      if ( !std::wstring::compare(&v4->_Myval.path, 0, v4->_Myval.path._Mysize, v5->_Bx._Buf, path->_Mysize) )
        break;
      v4 = v4->_Next;
      if ( v4 == this->loadedBanks._Myhead )
        return;
    }
    if ( v4->_Myval.refCount-- == 1 )
    {
      FMOD::Studio::Bank::unload(v4->_Myval.bank);
      v4->_Prev->_Next = v4->_Next;
      v4->_Next->_Prev = v4->_Prev;
      --this->loadedBanks._Mysize;
      if ( v4->_Myval.path._Myres >= 8 )
        operator delete(v4->_Myval.path._Bx._Ptr);
      v4->_Myval.path._Myres = 7;
      v4->_Myval.path._Mysize = 0;
      v4->_Myval.path._Bx._Buf[0] = 0;
      operator delete(v4);
    }
  }
}
void AudioEngine::setDistanceScale(AudioEngine *this, const float scale)
{
  FMOD_RESULT v2; // eax

  v2 = FMOD::System::set3DSettings(this->lowLevelSystem, 1065353216, 1065353216, LODWORD(scale));
  if ( !logged_43 )
  {
    if ( v2 )
    {
      logged_43 = 1;
      audioFmodCallError("AudioEngine.cpp", 1193, v2);
    }
  }
}
void AudioEngine::setDriver(AudioEngine *this, int driverIndex)
{
  FMOD_RESULT v2; // eax
  FMOD_RESULT v3; // eax
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  int speakerChannels; // [esp+50h] [ebp-170h] BYREF
  FMOD::System *fsystem; // [esp+54h] [ebp-16Ch] BYREF
  int systemRate; // [esp+58h] [ebp-168h] BYREF
  FMOD_SPEAKERMODE speakerMode; // [esp+5Ch] [ebp-164h] BYREF
  std::array<std::wstring,8> speakerModes; // [esp+60h] [ebp-160h] BYREF
  FMOD_GUID guid; // [esp+120h] [ebp-A0h] BYREF
  char name[128]; // [esp+130h] [ebp-90h] BYREF
  int v13; // [esp+1BCh] [ebp-4h]

  FMOD::Studio::System::getLowLevelSystem(this->system, &fsystem);
  FMOD::System::setDriver(fsystem, driverIndex);
  v2 = FMOD::System::getDriverInfo(fsystem, driverIndex, name, 128, &guid, &systemRate, &speakerMode, &speakerChannels);
  if ( v2 )
    audioFmodCallError("AudioEngine.cpp", 759, v2);
  v3 = FMOD::System::setSoftwareFormat(fsystem, systemRate, speakerMode, speakerChannels);
  if ( v3 )
    audioFmodCallError("AudioEngine.cpp", 761, v3);
  speakerModes._Elems[0]._Myres = 7;
  speakerModes._Elems[0]._Mysize = 0;
  speakerModes._Elems[0]._Bx._Buf[0] = 0;
  std::wstring::assign(speakerModes._Elems, L"DEFAULT", 7u);
  v13 = 0;
  speakerModes._Elems[1]._Myres = 7;
  speakerModes._Elems[1]._Mysize = 0;
  speakerModes._Elems[1]._Bx._Buf[0] = 0;
  std::wstring::assign(&speakerModes._Elems[1], L"RAW", 3u);
  LOBYTE(v13) = 1;
  speakerModes._Elems[2]._Myres = 7;
  speakerModes._Elems[2]._Mysize = 0;
  speakerModes._Elems[2]._Bx._Buf[0] = 0;
  std::wstring::assign(&speakerModes._Elems[2], L"MONO", 4u);
  LOBYTE(v13) = 2;
  speakerModes._Elems[3]._Myres = 7;
  speakerModes._Elems[3]._Mysize = 0;
  speakerModes._Elems[3]._Bx._Buf[0] = 0;
  std::wstring::assign(&speakerModes._Elems[3], L"STEREO", 6u);
  LOBYTE(v13) = 3;
  speakerModes._Elems[4]._Myres = 7;
  speakerModes._Elems[4]._Mysize = 0;
  speakerModes._Elems[4]._Bx._Buf[0] = 0;
  std::wstring::assign(&speakerModes._Elems[4], L"QUAD", 4u);
  LOBYTE(v13) = 4;
  speakerModes._Elems[5]._Myres = 7;
  speakerModes._Elems[5]._Mysize = 0;
  speakerModes._Elems[5]._Bx._Buf[0] = 0;
  std::wstring::assign(&speakerModes._Elems[5], L"SURROUND", 8u);
  LOBYTE(v13) = 5;
  speakerModes._Elems[6]._Myres = 7;
  speakerModes._Elems[6]._Mysize = 0;
  speakerModes._Elems[6]._Bx._Buf[0] = 0;
  std::wstring::assign(&speakerModes._Elems[6], L"5POINT1", 7u);
  LOBYTE(v13) = 6;
  speakerModes._Elems[7]._Myres = 7;
  speakerModes._Elems[7]._Mysize = 0;
  speakerModes._Elems[7]._Bx._Buf[0] = 0;
  std::wstring::assign(&speakerModes._Elems[7], L"7POINT1", 7u);
  v13 = 7;
  _printf("FMOD driver switched to:\n");
  _printf("Id: %d\n", driverIndex);
  _printf("Name: %s\n", name);
  _printf("System Rate: %d\n", systemRate);
  v4 = speakerModes._Elems[speakerMode]._Bx._Buf;
  if ( *(&speakerModes._Elems[0]._Myres + 6 * speakerMode) >= 8 )
    v4 = *(const wchar_t **)v4;
  _printf("Speaker Mode: %S\n", v4);
  _printf("Speaker Channels: %d\n\n", speakerChannels);
  FMOD::System::getSoftwareFormat(fsystem, &systemRate, &speakerMode, &speakerChannels);
  _printf("Check:\n");
  _printf("Id: %d\n", driverIndex);
  _printf("Name: %s\n", name);
  _printf("System Rate: %d\n", systemRate);
  v5 = speakerModes._Elems[speakerMode]._Bx._Buf;
  if ( *(&speakerModes._Elems[0]._Myres + 6 * speakerMode) >= 8 )
    v5 = *(const wchar_t **)v5;
  _printf("Speaker Mode: %S\n", v5);
  _printf("Speaker Channels: %d\n\n", speakerChannels);
  v13 = -1;
  `eh vector destructor iterator'(&speakerModes, 0x18u, 8, (void (*)(void *))std::wstring::~wstring);
}
void AudioEngine::setListener(AudioEngine *this, const mat44f *transform, const vec3f *velocity)
{
  __m128 v3; // xmm3
  unsigned __int64 v4; // xmm2_8
  float v5; // xmm1_4
  float v6; // eax
  __m128 v7; // xmm2
  float v8; // xmm0_4
  __m128 v9; // xmm1
  int v10; // eax
  float v11; // xmm0_4
  __m128 v12; // xmm2
  int v13; // eax
  __m128i v14; // xmm0
  FMOD_RESULT v15; // eax
  FMOD::Studio::System *v16; // [esp-Ch] [ebp-80h]
  char v17[20]; // [esp+4h] [ebp-70h] BYREF
  float v18; // [esp+18h] [ebp-5Ch]
  unsigned __int64 v19; // [esp+1Ch] [ebp-58h]
  __m128i v20; // [esp+24h] [ebp-50h] BYREF
  float v21; // [esp+3Ch] [ebp-38h]
  __int128 v22[3]; // [esp+40h] [ebp-34h] BYREF

  v3 = (__m128)LODWORD(transform->M31);
  v4 = _mm_unpacklo_ps((__m128)LODWORD(transform->M41), (__m128)LODWORD(transform->M42)).m128_u64[0];
  v5 = transform->M33;
  v21 = transform->M43;
  v6 = v21;
  *(_QWORD *)v17 = v4;
  v7 = _mm_xor_ps((__m128)LODWORD(transform->M32), (__m128)(unsigned int)_xmm);
  LODWORD(v21) = LODWORD(v5) ^ _xmm;
  v8 = transform->M23;
  v3.m128_u64[0] = _mm_unpacklo_ps(_mm_xor_ps(v3, (__m128)(unsigned int)_xmm), v7).m128_u64[0];
  v7.m128_u64[0] = _mm_unpacklo_ps((__m128)LODWORD(transform->M21), (__m128)LODWORD(transform->M22)).m128_u64[0];
  v9 = (__m128)LODWORD(velocity->y);
  *(float *)&v17[8] = v6;
  v10 = LODWORD(v21);
  v21 = v8;
  v11 = velocity->z;
  *(__int64 *)((char *)v20.m128i_i64 + 4) = v7.m128_u64[0];
  v12 = (__m128)LODWORD(velocity->x);
  v20.m128i_i32[0] = v10;
  v13 = LODWORD(v21);
  v21 = v11;
  *(_QWORD *)&v17[12] = _mm_unpacklo_ps(v12, v9).m128_u64[0];
  v14 = _mm_loadu_si128((const __m128i *)v17);
  v20.m128i_i32[3] = v13;
  v18 = v21;
  v22[0] = (__int128)v14;
  v19 = v3.m128_u64[0];
  v16 = this->system;
  v22[1] = (__int128)_mm_loadu_si128((const __m128i *)&v17[16]);
  v22[2] = (__int128)_mm_loadu_si128(&v20);
  v15 = FMOD::Studio::System::setListenerAttributes(v16, 0, v22);
  if ( !logged_33 )
  {
    if ( v15 )
    {
      logged_33 = 1;
      audioFmodCallError("AudioEngine.cpp", 1090, v15);
    }
  }
}
void __userpurge AudioEngine::setVolume(AudioEngine *this@<ecx>, int a2@<esi>, const float volume)
{
  FMOD_RESULT v4; // eax
  FMOD_RESULT v5; // eax
  FMOD::System *v6; // [esp+4h] [ebp-10h]
  FMOD::ChannelGroup *masterChannelGroup; // [esp+10h] [ebp-4h] BYREF

  masterChannelGroup = (FMOD::ChannelGroup *)this;
  v6 = this->lowLevelSystem;
  this->targetVolume = volume;
  this->timeFromStart = 0.0;
  v4 = ((int (__stdcall *)(FMOD::System *, FMOD::ChannelGroup **, int))FMOD::System::getMasterChannelGroup)(
         v6,
         &masterChannelGroup,
         a2);
  if ( !logged_39 && v4 )
  {
    logged_39 = 1;
    audioFmodCallError("AudioEngine.cpp", 1153, v4);
  }
  v5 = FMOD::ChannelControl::setVolume(LODWORD(volume), LODWORD(this->targetVolume));
  if ( !logged_40 && v5 )
  {
    logged_40 = 1;
    audioFmodCallError("AudioEngine.cpp", 1154, v5);
  }
  if ( this->startUpTime > 0.0 )
    this->masterVolume = 0.0;
  else
    this->masterVolume = volume;
}
void AudioEngine::start(AudioEngine *this)
{
  FMOD_RESULT v2; // eax
  FMOD_RESULT v3; // eax
  int v4; // [esp+Ch] [ebp-8h]
  FMOD::ChannelGroup *masterChannelGroup; // [esp+10h] [ebp-4h] BYREF

  v2 = ((int (__stdcall *)(FMOD::System *, FMOD::ChannelGroup **, int))FMOD::System::getMasterChannelGroup)(
         this->lowLevelSystem,
         &masterChannelGroup,
         v4);
  if ( !logged_37 && v2 )
  {
    logged_37 = 1;
    audioFmodCallError("AudioEngine.cpp", 1140, v2);
  }
  v3 = FMOD::ChannelControl::setVolume(masterChannelGroup, LODWORD(this->masterVolume));
  if ( !logged_38 && v3 )
  {
    logged_38 = 1;
    audioFmodCallError("AudioEngine.cpp", 1142, v3);
  }
  this->playing = 1;
}
void AudioEngine::stop(AudioEngine *this)
{
  FMOD_RESULT v2; // eax
  FMOD_RESULT v3; // eax
  int v4; // [esp+Ch] [ebp-8h]
  FMOD::ChannelGroup *masterChannelGroup; // [esp+10h] [ebp-4h] BYREF

  v2 = ((int (__stdcall *)(FMOD::System *, FMOD::ChannelGroup **, int))FMOD::System::getMasterChannelGroup)(
         this->lowLevelSystem,
         &masterChannelGroup,
         v4);
  if ( !logged_35 && v2 )
  {
    logged_35 = 1;
    audioFmodCallError("AudioEngine.cpp", 1131, v2);
  }
  v3 = FMOD::ChannelControl::setVolume(masterChannelGroup, 0);
  if ( !logged_36 && v3 )
  {
    logged_36 = 1;
    audioFmodCallError("AudioEngine.cpp", 1133, v3);
  }
  this->playing = 0;
}
void __userpurge AudioEngine::update(AudioEngine *this@<ecx>, int a2@<ebp>, int a3@<edi>, float *a4@<esi>, const float dt)
{
  FMOD_RESULT v6; // eax
  std::_List_node<AudioEvent *,void *> *v7; // edi
  std::_List_node<AudioEvent *,void *> *i; // esi
  AudioEvent *v9; // ebp
  FMOD_RESULT v10; // eax
  FMOD_RESULT v11; // eax
  FMOD_RESULT v12; // eax
  FMOD_RESULT v13; // eax
  float reverbOcclusion; // [esp+44h] [ebp-68h]
  FMOD_3D_ATTRIBUTES eventAttribs; // [esp+48h] [ebp-64h] BYREF
  FMOD_3D_ATTRIBUTES listenerAttribs; // [esp+78h] [ebp-34h] BYREF

  if ( this->playing && this->targetVolume != this->masterVolume )
    AudioEngine::rampVolume(this, dt);
  v6 = FMOD::Studio::System::getListenerAttributes(this->system, 0, &listenerAttribs);
  if ( !logged_25 && v6 )
  {
    logged_25 = 1;
    audioFmodCallError("AudioEngine.cpp", 1035, v6);
  }
  v7 = this->registeredEvents._Myhead;
  for ( i = v7->_Next; i != v7; i = i->_Next )
  {
    v9 = i->_Myval;
    v10 = FMOD::Studio::EventInstance::get3DAttributes(v9->instance, &eventAttribs, a2, a3, a4);
    if ( !logged_26 && v10 )
    {
      logged_26 = 1;
      audioFmodCallError("AudioEngine.cpp", 1043, v10);
    }
    a4 = &eventAttribs.position.z;
    v11 = FMOD::System::getGeometryOcclusion(
            this->lowLevelSystem,
            &listenerAttribs.velocity,
            &eventAttribs.velocity,
            &eventAttribs);
    if ( !logged_27 && v11 )
    {
      logged_27 = 1;
      audioFmodCallError("AudioEngine.cpp", 1048, v11);
    }
    v12 = FMOD::Studio::EventInstance::setVolume(v9->instance, (float)(1.0 - reverbOcclusion) * eventAttribs.position.x);
    if ( !logged_28 && v12 )
    {
      logged_28 = 1;
      audioFmodCallError("AudioEngine.cpp", 1054, v12);
    }
  }
  v13 = FMOD::Studio::System::update(this->system);
  if ( !logged_29 && v13 )
  {
    logged_29 = 1;
    audioFmodCallError("AudioEngine.cpp", 1058, v13);
  }
  checkOutputSanity(this->lowLevelSystem);
}
void AudioEngine::updateProperties(AudioEngine *this)
{
  FMOD_RESULT v2; // eax
  std::_List_node<AudioEvent *,void *> *v3; // edi
  std::_List_node<AudioEvent *,void *> *i; // esi
  AudioEvent *v5; // ebx
  FMOD_RESULT v6; // eax
  FMOD_RESULT v7; // eax
  int v8; // [esp+1Ch] [ebp-4h] BYREF

  v2 = FMOD::Studio::System::flushCommands(this->system);
  if ( !logged_44 && v2 )
  {
    logged_44 = 1;
    audioFmodCallError("AudioEngine.cpp", 1256, v2);
  }
  v3 = this->registeredEvents._Myhead;
  for ( i = v3->_Next; i != v3; i = i->_Next )
  {
    v5 = i->_Myval;
    v6 = FMOD::Studio::EventInstance::getChannelGroup(v5->instance, &v8);
    if ( v6 )
      audioFmodCallError("AudioEngine.cpp", 380, v6);
    if ( v8 && v5->reverbResponse == Off )
    {
      v7 = FMOD::ChannelControl::setReverbProperties(v8, 0, 981668463);
      if ( v7 )
        audioFmodCallError("AudioEngine.cpp", 385, v7);
    }
  }
}
