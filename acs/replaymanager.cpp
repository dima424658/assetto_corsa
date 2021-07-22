#include "replaymanager.h"
void ReplayManager::ReplayManager(ReplayManager *this, Sim *a_sim, PhysicsAvatar *physicsAvatar)
{
  std::_Tree_node<std::pair<CarAvatar * const,std::vector<ReplayLap> >,void *> *v4; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v5; // eax
  char v6; // al
  double v7; // xmm1_8
  float v8; // xmm0_4
  char v9; // al
  double v10; // st7
  bool v11; // cf
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // eax
  char v15; // al
  int v16; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v17; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v18; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v19; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v20; // eax
  std::pair<enum SessionType,ReplayAutosave> *v21; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v22; // eax
  std::pair<enum SessionType,ReplayAutosave> *v23; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v24; // eax
  std::pair<enum SessionType,ReplayAutosave> *v25; // eax
  std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *v26; // eax
  Sim *v27; // ecx
  unsigned int v28; // edx
  CarAvatar *v29; // edi
  GameObject **v30; // esi
  ReplayRecorder *v31; // eax
  Sim *v32; // ecx
  FrameInformation *v33; // edi
  FrameInformation *i; // esi
  unsigned int j; // esi
  std::vector<WingState> *v36; // eax
  Sim *v37; // ecx
  CarAvatar *v38; // eax
  ReplayInterface *v39; // eax
  Sim *v40; // edi
  ReplayInterface *v41; // eax
  RaceManager *v42; // ecx
  Session *v43; // eax
  std::wstring *v44; // eax
  const std::wstring *v45; // eax
  std::wstring *v46; // esi
  std::wstring *v47; // edi
  const wchar_t *v48; // eax
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  const std::wstring *v51; // eax
  unsigned int k; // esi
  CarAvatar *v53; // eax
  Sim *v54; // eax
  std::wstring v55; // [esp-14h] [ebp-220h] BYREF
  Game *X_4; // [esp+4h] [ebp-208h]
  char v57; // [esp+63h] [ebp-1A9h] BYREF
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<enum SessionType const ,ReplayAutosave> > > >,bool> minSize; // [esp+64h] [ebp-1A8h] BYREF
  long double rr; // [esp+6Ch] [ebp-1A0h] BYREF
  Sim *aSim; // [esp+78h] [ebp-194h]
  ReplayManager *v61; // [esp+7Ch] [ebp-190h]
  std::vector<std::wstring> temp_files; // [esp+80h] [ebp-18Ch] BYREF
  int v63; // [esp+90h] [ebp-17Ch]
  unsigned int v64; // [esp+94h] [ebp-178h]
  SGearRatio key; // [esp+98h] [ebp-174h] BYREF
  ReplayAutosave autoSave; // [esp+B8h] [ebp-154h] BYREF
  std::wstring v67; // [esp+D4h] [ebp-138h] BYREF
  std::wstring v68; // [esp+ECh] [ebp-120h] BYREF
  std::wstring v69; // [esp+104h] [ebp-108h] BYREF
  INIReaderDocuments replayINI; // [esp+11Ch] [ebp-F0h] BYREF
  Session result; // [esp+164h] [ebp-A8h] BYREF
  int v72; // [esp+208h] [ebp-4h]

  v61 = this;
  aSim = a_sim;
  X_4 = a_sim->game;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"REPLAY_MANAGER", 0xEu);
  GameObject::GameObject(this, v55, X_4);
  this->__vftable = (ReplayManager_vtbl *)&ReplayManager::`vftable';
  v72 = 0;
  this->evOnReplayStarted.handlers._Myfirst = 0;
  this->evOnReplayStarted.handlers._Mylast = 0;
  this->evOnReplayStarted.handlers._Myend = 0;
  this->evOnReplayStopped.handlers._Myfirst = 0;
  this->evOnReplayStopped.handlers._Mylast = 0;
  this->evOnReplayStopped.handlers._Myend = 0;
  this->evOnReplayRewind.handlers._Myfirst = 0;
  this->evOnReplayRewind.handlers._Mylast = 0;
  this->evOnReplayRewind.handlers._Myend = 0;
  this->evDidFinishedSavingReplay.handlers._Myfirst = 0;
  this->evDidFinishedSavingReplay.handlers._Mylast = 0;
  this->evDidFinishedSavingReplay.handlers._Myend = 0;
  this->hasLoadedReplay = 0;
  this->status = eReplayStop;
  this->lastFilename._Myres = 7;
  this->lastFilename._Mysize = 0;
  this->lastFilename._Bx._Buf[0] = 0;
  this->recorders._Myfirst = 0;
  this->recorders._Mylast = 0;
  this->recorders._Myend = 0;
  LOBYTE(v72) = 6;
  this->replayLaps._Myhead = 0;
  this->replayLaps._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::pair<unsigned int,std::pair<unsigned int,float>> const,FW1FontWrapper::CFW1GlyphProvider::GlyphMap *>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::pair<unsigned int,std::pair<unsigned int,float> > const ,FW1FontWrapper::CFW1GlyphProvider::GlyphMap *>> > *)&this->replayLaps);
  this->replayLaps._Myhead = v4;
  this->sim = a_sim;
  this->oldStatus = eReplayStop;
  this->oldCameraMode = eCockpit;
  this->oldDrivableMode = eChase;
  this->oldCameraTrackSet = 0;
  this->oldCameraCar = 0;
  this->timeMult = 1.0;
  this->slowMoCounter = 0.0;
  this->slowMoLevel = 2.0;
  this->playCounter = 0.0;
  this->replayMode = 0;
  this->recordedFrames = 0;
  this->currentRecordingIndex = 0;
  this->lastRecordTime = 0.0;
  this->maxFrames = 0;
  this->minFrames = 0;
  this->cutOut = 0;
  this->cutIn = 0;
  this->maxSizeMB = 10.0;
  this->currentFrame = 0;
  this->currentSessionType = Undefined;
  LOBYTE(v72) = 7;
  this->autoSaveData._Myhead = 0;
  this->autoSaveData._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<enum SessionType const,ReplayAutosave>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::map<std::wstring,INISection> >> > *)&this->autoSaveData);
  this->autoSaveData._Myhead = v5;
  this->autoSaveEnabled = 0;
  this->isActive = 0;
  X_4 = 0;
  LOBYTE(v72) = 8;
  this->maxFrames = (int)(ReplayRecorder::recordIntervalMS * 60.0 * 10.0);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"cfg/replay.ini", 0xEu);
  INIReaderDocuments::INIReaderDocuments(&replayINI, (unsigned int)this, v55, (bool)X_4);
  LOBYTE(v72) = 9;
  if ( replayINI.ready )
  {
    v64 = 7;
    v63 = 0;
    LOWORD(temp_files._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&temp_files, L"QUALITY", 7u);
    LOBYTE(v72) = 10;
    v6 = INIReader::hasSection(&replayINI, (const std::wstring *)&temp_files);
    v57 = v6;
    LOBYTE(v72) = 9;
    if ( v64 >= 8 )
    {
      operator delete(temp_files._Myfirst);
      v6 = v57;
    }
    if ( v6 )
    {
      std::wstring::wstring((std::wstring *)&key, L"LEVEL");
      LOBYTE(v72) = 11;
      std::wstring::wstring((std::wstring *)&temp_files, L"QUALITY");
      LOBYTE(v72) = 12;
      minSize.first._Ptr = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)INIReader::getInt(&replayINI, (const std::wstring *)&temp_files, (const std::wstring *)&key);
      if ( v64 >= 8 )
        operator delete(temp_files._Myfirst);
      v64 = 7;
      v63 = 0;
      LOWORD(temp_files._Myfirst) = 0;
      LOBYTE(v72) = 9;
      if ( *(_DWORD *)&key.name._Bx._Alias[12] >= 8u )
        operator delete(LODWORD(key.ratio));
      switch ( (unsigned int)minSize.first._Ptr )
      {
        case 0u:
          v7 = DOUBLE_120_0;
          ReplayRecorder::recordIntervalMS = DOUBLE_120_0;
          break;
        case 1u:
          v7 = DOUBLE_90_0;
          ReplayRecorder::recordIntervalMS = DOUBLE_90_0;
          break;
        case 2u:
          v7 = DOUBLE_60_0;
          ReplayRecorder::recordIntervalMS = DOUBLE_60_0;
          break;
        case 3u:
          v7 = DOUBLE_30_0;
          ReplayRecorder::recordIntervalMS = DOUBLE_30_0;
          break;
        case 4u:
          v7 = DOUBLE_15_0;
          ReplayRecorder::recordIntervalMS = DOUBLE_15_0;
          break;
        default:
          _printf("ERROR: Replay Quality Level %d not supported, using default 30Hz\n", minSize.first._Ptr);
          v7 = ReplayRecorder::recordIntervalMS;
          break;
      }
      _printf("REPLAY QUALITY AT %f Hz\n", 1000.0 / v7);
    }
    v8 = (float)(unsigned int)(272 * (this->sim->cars._Mylast - this->sim->cars._Myfirst));
    *(float *)&minSize.first._Ptr = v8;
    if ( v8 == 0.0 )
      *(float *)&minSize.first._Ptr = FLOAT_272_0;
    v64 = 7;
    v63 = 0;
    LOWORD(temp_files._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&temp_files, L"REPLAY", 6u);
    LOBYTE(v72) = 13;
    v9 = INIReader::hasSection(&replayINI, (const std::wstring *)&temp_files);
    v57 = v9;
    LOBYTE(v72) = 9;
    if ( v64 >= 8 )
    {
      operator delete(temp_files._Myfirst);
      v9 = v57;
    }
    if ( v9 )
    {
      std::wstring::wstring((std::wstring *)&key, L"MAX_SIZE_MB");
      LOBYTE(v72) = 14;
      std::wstring::wstring((std::wstring *)&temp_files, L"REPLAY");
      LOBYTE(v72) = 15;
      v10 = INIReader::getFloat(&replayINI, (const std::wstring *)&temp_files, (const std::wstring *)&key);
      v11 = v64 < 8;
      this->maxSizeMB = v10;
      if ( !v11 )
        operator delete(temp_files._Myfirst);
      v64 = 7;
      v63 = 0;
      LOWORD(temp_files._Myfirst) = 0;
      LOBYTE(v72) = 9;
      if ( *(_DWORD *)&key.name._Bx._Alias[12] >= 8u )
        operator delete(LODWORD(key.ratio));
      v12 = this->maxSizeMB;
      v13 = FLOAT_500_0;
      if ( v12 <= 500.0 )
      {
        v13 = FLOAT_10_0;
        if ( v12 >= 10.0 )
          v13 = this->maxSizeMB;
      }
      this->maxSizeMB = v13;
      _printf("MAX SIZE MB %f\n", v13);
      this->maxFrames = (int)(float)((float)(this->maxSizeMB * 1000000.0) / *(float *)&minSize.first._Ptr);
    }
    v14 = this->maxFrames;
    rr = 1000.0 / ReplayRecorder::recordIntervalMS;
    _printf(
      "ReplayManager MAX FRAMES COUNT %d WHICH IS %f MINS\n",
      v14,
      (double)((double)v14 / (1000.0 / ReplayRecorder::recordIntervalMS * 60.0)));
    v64 = 7;
    v63 = 0;
    LOWORD(temp_files._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&temp_files, L"AUTOSAVE", 8u);
    LOBYTE(v72) = 16;
    v15 = INIReader::hasSection(&replayINI, (const std::wstring *)&temp_files);
    v57 = v15;
    LOBYTE(v72) = 9;
    if ( v64 >= 8 )
    {
      operator delete(temp_files._Myfirst);
      v15 = v57;
    }
    if ( v15 )
    {
      std::wstring::wstring((std::wstring *)&key, L"ENABLED");
      LOBYTE(v72) = 17;
      std::wstring::wstring((std::wstring *)&temp_files, L"AUTOSAVE");
      LOBYTE(v72) = 18;
      v16 = INIReader::getInt(&replayINI, (const std::wstring *)&temp_files, (const std::wstring *)&key);
      v11 = v64 < 8;
      this->autoSaveEnabled = v16 != 0;
      if ( !v11 )
        operator delete(temp_files._Myfirst);
      v64 = 7;
      v63 = 0;
      LOWORD(temp_files._Myfirst) = 0;
      LOBYTE(v72) = 9;
      if ( *(_DWORD *)&key.name._Bx._Alias[12] >= 8u )
        operator delete(LODWORD(key.ratio));
      if ( this->autoSaveEnabled )
      {
        autoSave.shortName._Myres = 7;
        autoSave.shortName._Mysize = 0;
        autoSave.shortName._Bx._Buf[0] = 0;
        LOBYTE(v72) = 19;
        std::wstring::wstring((std::wstring *)&key, L"RACE");
        LOBYTE(v72) = 20;
        std::wstring::wstring((std::wstring *)&temp_files, L"AUTOSAVE");
        LOBYTE(v72) = 21;
        autoSave.size = INIReader::getInt(&replayINI, (const std::wstring *)&temp_files, (const std::wstring *)&key);
        if ( v64 >= 8 )
          operator delete(temp_files._Myfirst);
        v64 = 7;
        v63 = 0;
        LOWORD(temp_files._Myfirst) = 0;
        LOBYTE(v72) = 19;
        if ( *(_DWORD *)&key.name._Bx._Alias[12] >= 8u )
          operator delete(LODWORD(key.ratio));
        std::wstring::assign(&autoSave.shortName, L"R", 1u);
        HIDWORD(key.ratio) = autoSave.size;
        key.name._Bx._Buf[0] = 0;
        LODWORD(key.ratio) = 3;
        key.name._Myres = 7;
        key.name._Mysize = 0;
        std::wstring::assign(&key.name, &autoSave.shortName, 0, 0xFFFFFFFF);
        LOBYTE(v72) = 22;
        v17 = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)std::_Tree_buy<std::pair<enum SessionType const,ReplayAutosave>>::_Buynode<std::pair<enum SessionType,ReplayAutosave>>(
                                                                                             &this->autoSaveData,
                                                                                             (std::pair<enum SessionType,ReplayAutosave> *)&key);
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Insert_nohint<std::pair<enum SessionType const,ReplayAutosave> &,std::_Tree_node<std::pair<enum SessionType const,ReplayAutosave>,void *> *>(
          &this->autoSaveData,
          &minSize,
          0,
          &v17->_Myval,
          v17);
        LOBYTE(v72) = 19;
        if ( key.name._Myres >= 8 )
          operator delete(key.name._Bx._Ptr);
        std::wstring::wstring((std::wstring *)&key, L"QUALIFY");
        LOBYTE(v72) = 23;
        std::wstring::wstring((std::wstring *)&temp_files, L"AUTOSAVE");
        LOBYTE(v72) = 24;
        autoSave.size = INIReader::getInt(&replayINI, (const std::wstring *)&temp_files, (const std::wstring *)&key);
        if ( v64 >= 8 )
          operator delete(temp_files._Myfirst);
        v64 = 7;
        v63 = 0;
        LOWORD(temp_files._Myfirst) = 0;
        LOBYTE(v72) = 19;
        if ( *(_DWORD *)&key.name._Bx._Alias[12] >= 8u )
          operator delete(LODWORD(key.ratio));
        std::wstring::assign(&autoSave.shortName, L"Q", 1u);
        HIDWORD(key.ratio) = autoSave.size;
        key.name._Bx._Buf[0] = 0;
        LODWORD(key.ratio) = 2;
        key.name._Myres = 7;
        key.name._Mysize = 0;
        std::wstring::assign(&key.name, &autoSave.shortName, 0, 0xFFFFFFFF);
        LOBYTE(v72) = 25;
        v18 = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)std::_Tree_buy<std::pair<enum SessionType const,ReplayAutosave>>::_Buynode<std::pair<enum SessionType,ReplayAutosave>>(
                                                                                             &this->autoSaveData,
                                                                                             (std::pair<enum SessionType,ReplayAutosave> *)&key);
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Insert_nohint<std::pair<enum SessionType const,ReplayAutosave> &,std::_Tree_node<std::pair<enum SessionType const,ReplayAutosave>,void *> *>(
          &this->autoSaveData,
          &minSize,
          0,
          &v18->_Myval,
          v18);
        LOBYTE(v72) = 19;
        if ( key.name._Myres >= 8 )
          operator delete(key.name._Bx._Ptr);
        std::wstring::wstring((std::wstring *)&key, L"OTHERS");
        LOBYTE(v72) = 26;
        std::wstring::wstring((std::wstring *)&temp_files, L"AUTOSAVE");
        LOBYTE(v72) = 27;
        autoSave.size = INIReader::getInt(&replayINI, (const std::wstring *)&temp_files, (const std::wstring *)&key);
        if ( v64 >= 8 )
          operator delete(temp_files._Myfirst);
        v64 = 7;
        v63 = 0;
        LOWORD(temp_files._Myfirst) = 0;
        LOBYTE(v72) = 19;
        if ( *(_DWORD *)&key.name._Bx._Alias[12] >= 8u )
          operator delete(LODWORD(key.ratio));
        std::wstring::assign(&autoSave.shortName, L"O", 1u);
        HIDWORD(key.ratio) = autoSave.size;
        key.name._Bx._Buf[0] = 0;
        LODWORD(key.ratio) = 1;
        key.name._Myres = 7;
        key.name._Mysize = 0;
        std::wstring::assign(&key.name, &autoSave.shortName, 0, 0xFFFFFFFF);
        LOBYTE(v72) = 28;
        v19 = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)std::_Tree_buy<std::pair<enum SessionType const,ReplayAutosave>>::_Buynode<std::pair<enum SessionType,ReplayAutosave>>(
                                                                                             &this->autoSaveData,
                                                                                             (std::pair<enum SessionType,ReplayAutosave> *)&key);
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Insert_nohint<std::pair<enum SessionType const,ReplayAutosave> &,std::_Tree_node<std::pair<enum SessionType const,ReplayAutosave>,void *> *>(
          &this->autoSaveData,
          &minSize,
          0,
          &v19->_Myval,
          v19);
        LOBYTE(v72) = 19;
        if ( key.name._Myres >= 8 )
          operator delete(key.name._Bx._Ptr);
        HIDWORD(key.ratio) = autoSave.size;
        key.name._Bx._Buf[0] = 0;
        LODWORD(key.ratio) = 4;
        key.name._Myres = 7;
        key.name._Mysize = 0;
        std::wstring::assign(&key.name, &autoSave.shortName, 0, 0xFFFFFFFF);
        LOBYTE(v72) = 29;
        v20 = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)std::_Tree_buy<std::pair<enum SessionType const,ReplayAutosave>>::_Buynode<std::pair<enum SessionType,ReplayAutosave>>(
                                                                                             &this->autoSaveData,
                                                                                             (std::pair<enum SessionType,ReplayAutosave> *)&key);
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Insert_nohint<std::pair<enum SessionType const,ReplayAutosave> &,std::_Tree_node<std::pair<enum SessionType const,ReplayAutosave>,void *> *>(
          &this->autoSaveData,
          &minSize,
          0,
          &v20->_Myval,
          v20);
        LOBYTE(v72) = 19;
        BonusInfo::~BonusInfo(&key);
        minSize.first._Ptr = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)5;
        std::pair<enum SessionType,ReplayAutosave>::pair<enum SessionType,ReplayAutosave>(
          (std::pair<enum SessionType,ReplayAutosave> *)&key,
          (SessionType *)&minSize,
          &autoSave);
        LOBYTE(v72) = 30;
        v22 = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)std::_Tree_buy<std::pair<enum SessionType const,ReplayAutosave>>::_Buynode<std::pair<enum SessionType,ReplayAutosave>>(
                                                                                             &this->autoSaveData,
                                                                                             v21);
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Insert_nohint<std::pair<enum SessionType const,ReplayAutosave> &,std::_Tree_node<std::pair<enum SessionType const,ReplayAutosave>,void *> *>(
          &this->autoSaveData,
          &minSize,
          0,
          &v22->_Myval,
          v22);
        LOBYTE(v72) = 19;
        BonusInfo::~BonusInfo(&key);
        minSize.first._Ptr = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)6;
        std::pair<enum SessionType,ReplayAutosave>::pair<enum SessionType,ReplayAutosave>(
          (std::pair<enum SessionType,ReplayAutosave> *)&key,
          (SessionType *)&minSize,
          &autoSave);
        LOBYTE(v72) = 31;
        v24 = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)std::_Tree_buy<std::pair<enum SessionType const,ReplayAutosave>>::_Buynode<std::pair<enum SessionType,ReplayAutosave>>(
                                                                                             &this->autoSaveData,
                                                                                             v23);
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Insert_nohint<std::pair<enum SessionType const,ReplayAutosave> &,std::_Tree_node<std::pair<enum SessionType const,ReplayAutosave>,void *> *>(
          &this->autoSaveData,
          &minSize,
          0,
          &v24->_Myval,
          v24);
        LOBYTE(v72) = 19;
        BonusInfo::~BonusInfo(&key);
        minSize.first._Ptr = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)7;
        std::pair<enum SessionType,ReplayAutosave>::pair<enum SessionType,ReplayAutosave>(
          (std::pair<enum SessionType,ReplayAutosave> *)&key,
          (SessionType *)&minSize,
          &autoSave);
        LOBYTE(v72) = 32;
        v26 = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)std::_Tree_buy<std::pair<enum SessionType const,ReplayAutosave>>::_Buynode<std::pair<enum SessionType,ReplayAutosave>>(
                                                                                             &this->autoSaveData,
                                                                                             v25);
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Insert_nohint<std::pair<enum SessionType const,ReplayAutosave> &,std::_Tree_node<std::pair<enum SessionType const,ReplayAutosave>,void *> *>(
          &this->autoSaveData,
          &minSize,
          0,
          &v26->_Myval,
          v26);
        LOBYTE(v72) = 19;
        BonusInfo::~BonusInfo(&key);
        std::wstring::wstring(&v67, L"MIN_TIME_SECONDS");
        LOBYTE(v72) = 33;
        std::wstring::wstring((std::wstring *)&key, L"AUTOSAVE");
        LOBYTE(v72) = 34;
        *(float *)&minSize.first._Ptr = INIReader::getFloat(&replayINI, (const std::wstring *)&key, &v67);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v67);
        *(float *)&minSize.first._Ptr = *(float *)&minSize.first._Ptr * rr;
        v55._Mysize = (int)ceil(*(float *)&minSize.first._Ptr);
        *(_DWORD *)&v55._Bx._Alias[12] = "Autosave replay options min frame: %d \n";
        this->minFrames = v55._Mysize;
        _printf(*(const char *const *)&v55._Bx._Alias[12], v55._Mysize);
        LOBYTE(v72) = 9;
        OnSetupAppCreated::~OnSetupAppCreated((Texture *)&autoSave);
      }
    }
  }
  v27 = this->sim;
  v28 = 0;
  minSize.first._Ptr = 0;
  if ( v27->cars._Mylast - v27->cars._Myfirst )
  {
    do
    {
      v29 = Sim::getCar(this->sim, v28);
      v30 = v29->gameObjects._Myfirst;
      if ( v30 == v29->gameObjects._Mylast )
      {
LABEL_61:
        v31 = 0;
      }
      else
      {
        while ( 1 )
        {
          v31 = (ReplayRecorder *)__RTDynamicCast(
                                    *v30,
                                    0,
                                    &GameObject `RTTI Type Descriptor',
                                    &ReplayRecorder `RTTI Type Descriptor',
                                    0);
          if ( v31 )
            break;
          if ( ++v30 == v29->gameObjects._Mylast )
            goto LABEL_61;
        }
      }
      LODWORD(rr) = v31;
      if ( v31 )
      {
        ReplayRecorder::setFrameSize(v31, this->maxFrames);
        std::vector<SpinnerData *>::push_back(
          (std::vector<ICollisionObject *> *)&this->recorders,
          (ICollisionObject *const *)&rr);
      }
      v32 = this->sim;
      v28 = (unsigned int)&minSize.first._Ptr->_Left + 1;
      minSize.first._Ptr = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)v28;
    }
    while ( v28 < v32->cars._Mylast - v32->cars._Myfirst );
  }
  std::vector<FrameInformation>::resize(&frameInformation, this->maxFrames);
  if ( this->sim->track )
  {
    v33 = frameInformation._Mylast;
    for ( i = frameInformation._Myfirst; i != v33; ++i )
      std::vector<CompressedTransform>::resize(
        &i->trackObjects,
        this->sim->track->trackObjects._Mylast - this->sim->track->trackObjects._Myfirst);
  }
  for ( j = 0; j < this->sim->cars._Mylast - this->sim->cars._Myfirst; ++j )
  {
    LODWORD(rr) = Sim::getCar(this->sim, j);
    temp_files._Myfirst = 0;
    temp_files._Mylast = 0;
    temp_files._Myend = 0;
    LOBYTE(v72) = 35;
    X_4 = (Game *)&temp_files;
    v36 = (std::vector<WingState> *)std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](
                                      &this->replayLaps,
                                      (CarAvatar *const *)&rr);
    std::vector<WingState>::operator=(v36, (std::vector<WingState> *)X_4);
    LOBYTE(v72) = 9;
    if ( temp_files._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&temp_files);
      operator delete(temp_files._Myfirst);
      temp_files._Myfirst = 0;
      temp_files._Mylast = 0;
      temp_files._Myend = 0;
    }
    X_4 = (Game *)this;
    minSize.first._Ptr = (std::_Tree_node<std::pair<enum SessionType const ,ReplayAutosave>,void *> *)&v55;
    v55._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_af1081906530a8c1d2e3152aeed4b845_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
    *(_DWORD *)&v55._Bx._Alias[4] = this;
    v55._Mysize = (unsigned int)&v55;
    v37 = this->sim;
    LOBYTE(v72) = 37;
    v38 = Sim::getCar(v37, j);
    LOBYTE(v72) = 9;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v38->evOnLapCompleted,
      (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v55,
      X_4);
  }
  v55._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_e693394010a1497d94434f1322d343a3_,0>,std::allocator<std::_Func_class<void,OnPhysicsStepCompleted const &>>,void,OnPhysicsStepCompleted const &>::`vftable';
  *(_DWORD *)&v55._Bx._Alias[4] = this;
  v55._Mysize = (unsigned int)&v55;
  LOBYTE(v72) = 9;
  Event<std::wstring>::addHandler(
    &physicsAvatar->evOnStepCompleted,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v55,
    this);
  v39 = (ReplayInterface *)operator new(544);
  LODWORD(rr) = v39;
  v40 = aSim;
  LOBYTE(v72) = 39;
  if ( v39 )
    ReplayInterface::ReplayInterface(v39, this, aSim);
  else
    v41 = 0;
  this->replayInterface = v41;
  v42 = v40->raceManager;
  LOBYTE(v72) = 9;
  v43 = RaceManager::getCurrentSession(v42, &result);
  v11 = result.name._Myres < 8;
  this->currentSessionType = v43->sessionType;
  if ( !v11 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  _printf("ReplayManager initialized current type %d\n", this->currentSessionType);
  if ( !this->autoSaveEnabled )
  {
    v44 = Path::getDocumentPath(&v69);
    LOBYTE(v72) = 40;
    v45 = std::operator+<wchar_t>(&v68, v44, L"/Assetto Corsa/replay/temp/*.*");
    LOBYTE(v72) = 41;
    Path::getFiles(&temp_files, v45);
    if ( v68._Myres >= 8 )
      operator delete(v68._Bx._Ptr);
    v68._Myres = 7;
    v68._Mysize = 0;
    v68._Bx._Buf[0] = 0;
    LOBYTE(v72) = 44;
    if ( v69._Myres >= 8 )
      operator delete(v69._Bx._Ptr);
    v46 = temp_files._Myfirst;
    v47 = temp_files._Mylast;
    v69._Myres = 7;
    v69._Mysize = 0;
    v69._Bx._Buf[0] = 0;
    if ( temp_files._Myfirst != temp_files._Mylast )
    {
      do
      {
        if ( v46->_Myres < 8 )
          v48 = (const wchar_t *)v46;
        else
          v48 = v46->_Bx._Ptr;
        _printf("Deleting temp replay file %S\n", v48);
        v49 = Path::getDocumentPath((std::wstring *)&autoSave);
        LOBYTE(v72) = 45;
        v50 = std::operator+<wchar_t>((std::wstring *)&key, v49, L"/Assetto Corsa/replay/temp/");
        LOBYTE(v72) = 46;
        v51 = std::operator+<wchar_t>(&v67, v50, v46);
        LOBYTE(v72) = 47;
        Path::deleteFile(v51);
        if ( v67._Myres >= 8 )
          operator delete(v67._Bx._Ptr);
        v67._Myres = 7;
        v67._Mysize = 0;
        v67._Bx._Buf[0] = 0;
        if ( *(_DWORD *)&key.name._Bx._Alias[12] >= 8u )
          operator delete(LODWORD(key.ratio));
        *(_QWORD *)&key.name._Bx._Alias[8] = 0x700000000i64;
        LOWORD(key.ratio) = 0;
        LOBYTE(v72) = 44;
        if ( autoSave.shortName._Mysize >= 8 )
          operator delete(autoSave.size);
        ++v46;
      }
      while ( v46 != v47 );
      v46 = temp_files._Myfirst;
    }
    LOBYTE(v72) = 9;
    if ( v46 )
    {
      std::_Container_base0::_Orphan_all(&temp_files);
      X_4 = (Game *)v61;
      v55._Myres = (unsigned int)&v57;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(temp_files._Myfirst, temp_files._Mylast);
      operator delete(temp_files._Myfirst);
    }
    v40 = aSim;
  }
  v55._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_562fc1d8e92378e53abe7b05a860c0a3_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v55._Bx._Alias[4] = this;
  v55._Mysize = (unsigned int)&v55;
  LOBYTE(v72) = 9;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v40->evOnNewSession,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v55,
    this);
  for ( k = 0; k < this->sim->cars._Mylast - this->sim->cars._Myfirst; ++k )
  {
    X_4 = (Game *)this;
    LODWORD(rr) = &v55;
    v55._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_df4e9314c62adb0d0142d9b310a7f325_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
    *(_DWORD *)&v55._Bx._Alias[4] = this;
    v55._Mysize = (unsigned int)&v55;
    LOBYTE(v72) = 50;
    v53 = Sim::getCar(v40, k);
    LOBYTE(v72) = 9;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v53->evOnLapCompleted,
      (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v55,
      X_4);
  }
  X_4 = (Game *)this;
  v55._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_2201f2254f9e4add1f74a935e2c652bc_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
  *(_DWORD *)&v55._Bx._Alias[4] = this;
  v55._Mysize = (unsigned int)&v55;
  v54 = this->sim;
  LOBYTE(v72) = 9;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v54->game->evOnPostUpdate,
    (std::function<void __cdecl(SessionInfo const &)>)v55,
    this);
  ksgui::GUI::addControl(v40->game->gui, this->replayInterface);
  ksgui::Control::setVisible(this->replayInterface, 0);
  LOBYTE(v72) = 8;
  INIReaderDocuments::~INIReaderDocuments(&replayINI);
}
void ReplayManager::~ReplayManager(ReplayManager *this)
{
  std::map<enum SessionType,ReplayAutosave> *v2; // esi
  std::vector<ReplayRecorder *> *v3; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<enum SessionType const ,ReplayAutosave> > > > result; // [esp+Ch] [ebp-4h] BYREF

  this->__vftable = (ReplayManager_vtbl *)&ReplayManager::`vftable';
  std::_Container_base0::_Orphan_all(&frameInformation);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::LightGroup>>>(
    (DRSDetection *)frameInformation._Myfirst,
    (DRSDetection *)frameInformation._Mylast);
  v2 = &this->autoSaveData;
  frameInformation._Mylast = frameInformation._Myfirst;
  std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::_Erase(
    &this->autoSaveData,
    this->autoSaveData._Myhead->_Parent);
  v2->_Myhead->_Parent = v2->_Myhead;
  v2->_Myhead->_Left = v2->_Myhead;
  v2->_Myhead->_Right = v2->_Myhead;
  this->autoSaveData._Mysize = 0;
  std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::erase(
    &this->autoSaveData,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<enum SessionType const ,ReplayAutosave> > > >)v2->_Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<enum SessionType const ,ReplayAutosave> > > >)v2->_Myhead);
  operator delete(this->autoSaveData._Myhead);
  std::_Tree<std::_Tmap_traits<CarAvatar *,std::vector<ReplayLap>,std::less<CarAvatar *>,std::allocator<std::pair<CarAvatar * const,std::vector<ReplayLap>>>,0>>::erase(
    &this->replayLaps,
    (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,std::vector<ReplayLap> > > > > *)&result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,std::vector<ReplayLap> > > > >)this->replayLaps._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,std::vector<ReplayLap> > > > >)this->replayLaps._Myhead);
  operator delete(this->replayLaps._Myhead);
  v3 = &this->recorders;
  if ( this->recorders._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->recorders);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->recorders._Mylast = 0;
    this->recorders._Myend = 0;
  }
  if ( this->lastFilename._Myres >= 8 )
    operator delete(this->lastFilename._Bx._Ptr);
  this->lastFilename._Myres = 7;
  this->lastFilename._Mysize = 0;
  this->lastFilename._Bx._Buf[0] = 0;
  if ( this->evDidFinishedSavingReplay.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evDidFinishedSavingReplay);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evDidFinishedSavingReplay,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evDidFinishedSavingReplay.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evDidFinishedSavingReplay.handlers._Mylast);
    operator delete(this->evDidFinishedSavingReplay.handlers._Myfirst);
    this->evDidFinishedSavingReplay.handlers._Myfirst = 0;
    this->evDidFinishedSavingReplay.handlers._Mylast = 0;
    this->evDidFinishedSavingReplay.handlers._Myend = 0;
  }
  if ( this->evOnReplayRewind.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnReplayRewind);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnReplayRewind,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayRewind.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayRewind.handlers._Mylast);
    operator delete(this->evOnReplayRewind.handlers._Myfirst);
    this->evOnReplayRewind.handlers._Myfirst = 0;
    this->evOnReplayRewind.handlers._Mylast = 0;
    this->evOnReplayRewind.handlers._Myend = 0;
  }
  if ( this->evOnReplayStopped.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnReplayStopped);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnReplayStopped,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayStopped.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayStopped.handlers._Mylast);
    operator delete(this->evOnReplayStopped.handlers._Myfirst);
    this->evOnReplayStopped.handlers._Myfirst = 0;
    this->evOnReplayStopped.handlers._Mylast = 0;
    this->evOnReplayStopped.handlers._Myend = 0;
  }
  if ( this->evOnReplayStarted.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnReplayStarted);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnReplayStarted,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayStarted.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayStarted.handlers._Mylast);
    operator delete(this->evOnReplayStarted.handlers._Myfirst);
    this->evOnReplayStarted.handlers._Myfirst = 0;
    this->evOnReplayStarted.handlers._Mylast = 0;
    this->evOnReplayStarted.handlers._Myend = 0;
  }
  GameObject::~GameObject(this);
}
ReplayManager *ReplayManager::`vector deleting destructor'(ReplayManager *this, unsigned int a2)
{
  ReplayManager::~ReplayManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ReplayManager::clearSaved(ReplayManager *this, std::wstring session, int maxSize)
{
  std::wstring *v3; // esi
  unsigned int v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // ecx
  const std::wstring *v8; // eax
  std::vector<std::wstring> files; // [esp+8h] [ebp-84h] BYREF
  int v10; // [esp+18h] [ebp-74h]
  std::wstring result; // [esp+1Ch] [ebp-70h] BYREF
  std::wstring v12; // [esp+34h] [ebp-58h] BYREF
  std::wstring v13; // [esp+4Ch] [ebp-40h] BYREF
  std::wstring v14; // [esp+64h] [ebp-28h] BYREF
  int v15; // [esp+88h] [ebp-4h]

  v15 = 0;
  if ( maxSize >= 0 )
  {
    Path::getDocumentPath(&result);
    LOBYTE(v15) = 1;
    std::wstring::append(&result, L"/Assetto Corsa/replay/temp/AC_*", 0x1Fu);
    std::wstring::append(&result, &session, 0, 0xFFFFFFFF);
    std::wstring::append(&result, L"_*.*", 4u);
    Path::getFiles(&files, &result);
    v3 = files._Myfirst;
    LOBYTE(v15) = 2;
    v4 = files._Mylast - files._Myfirst;
    if ( v4 && v4 >= maxSize )
    {
      LOBYTE(v10) = 0;
      std::_Sort<std::wstring *,int,std::less<void>>(files._Myfirst, files._Mylast, files._Mylast - files._Myfirst, 0);
      v5 = Path::getDocumentPath(&v14);
      LOBYTE(v15) = 3;
      v6 = std::operator+<wchar_t>(&v12, v5, L"/Assetto Corsa/replay/temp/");
      v7 = files._Myfirst;
      LOBYTE(v15) = 4;
      if ( files._Myfirst->_Myres >= 8 )
        v7 = (std::wstring *)files._Myfirst->_Bx._Ptr;
      v8 = std::operator+<wchar_t>(&v13, v6, v7->_Bx._Buf);
      LOBYTE(v15) = 5;
      Path::deleteFile(v8);
      if ( v13._Myres >= 8 )
        operator delete(v13._Bx._Ptr);
      v13._Myres = 7;
      v13._Mysize = 0;
      v13._Bx._Buf[0] = 0;
      if ( v12._Myres >= 8 )
        operator delete(v12._Bx._Ptr);
      v12._Myres = 7;
      v12._Mysize = 0;
      v12._Bx._Buf[0] = 0;
      if ( v14._Myres >= 8 )
        operator delete(v14._Bx._Ptr);
      v3 = files._Myfirst;
    }
    LOBYTE(v15) = 1;
    if ( v3 )
    {
      std::_Container_base0::_Orphan_all(&files);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(files._Myfirst, files._Mylast);
      operator delete(files._Myfirst);
      files._Myfirst = 0;
      files._Mylast = 0;
      files._Myend = 0;
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  if ( session._Myres >= 8 )
    operator delete(session._Bx._Ptr);
}
void ReplayManager::fastForward(ReplayManager *this, int speed, bool pression)
{
  int v4; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  Event<OnGearRequestEvent> *v7; // ecx
  OnGearRequestEvent message; // [esp+4h] [ebp-Ch] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  if ( pression )
  {
    v4 = speed + this->currentFrame;
    if ( v4 <= 1 )
    {
      if ( v4 < 0 )
        v4 = 0;
      this->currentFrame = v4;
    }
    else
    {
      this->currentFrame = 1;
    }
  }
  else
  {
    if ( this->timeMult <= 1.0 )
      this->timeMult = 1.0;
    v5 = FLOAT_20_0;
    this->oldStatus = this->status;
    this->status = eReplayFastForward;
    v6 = (float)speed + this->timeMult;
    if ( v6 <= 20.0 )
    {
      v5 = 0.0;
      if ( v6 >= 0.0 )
        v5 = (float)speed + this->timeMult;
    }
    v7 = (Event<OnGearRequestEvent> *)&this->sim->evOnReplayStatusChanged;
    this->timeMult = v5;
    message.request = 4;
    *(float *)&message.nextGear = v5;
    v9 = 1065353216;
    Event<std::wstring>::trigger(v7, &message);
    ReplayManager::updateReplayAudio(this);
  }
}
std::wstring *ReplayManager::getAutoFileName(ReplayManager *this, std::wstring *result)
{
  Sim *v3; // ecx
  CarAvatar *v4; // eax
  const std::wstring *v5; // eax
  struct tm *v6; // eax
  struct tm *v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // esi
  int v16; // esi
  int v17; // ecx
  int v18; // ebp
  int v19; // esi
  int v20; // ecx
  const std::wstring *v21; // eax
  const char *v23; // [esp-4h] [ebp-158h]
  int v24; // [esp+18h] [ebp-13Ch]
  int v25; // [esp+18h] [ebp-13Ch]
  int v26; // [esp+18h] [ebp-13Ch]
  __int64 now; // [esp+20h] [ebp-134h] BYREF
  std::wstring *v28; // [esp+28h] [ebp-12Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v29; // [esp+2Ch] [ebp-128h] BYREF
  char v30[16]; // [esp+DCh] [ebp-78h] BYREF
  char v31[16]; // [esp+ECh] [ebp-68h] BYREF
  char v32[16]; // [esp+FCh] [ebp-58h] BYREF
  int v33[5]; // [esp+10Ch] [ebp-48h] BYREF
  int v34[3]; // [esp+120h] [ebp-34h] BYREF
  std::wstring v35; // [esp+12Ch] [ebp-28h] BYREF
  int v36; // [esp+150h] [ebp-4h]

  v3 = this->sim;
  v28 = result;
  v4 = Sim::getCar(v3, 0);
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &v4->unixName, 0, 0xFFFFFFFF);
  v36 = 0;
  std::wstring::append(result, L"_", 1u);
  std::wstring::append(result, &this->sim->track->name, 0, 0xFFFFFFFF);
  std::wstring::append(result, L"_", 1u);
  v5 = TrackAvatar::getConfig(this->sim->track, &v35);
  v36 = 1;
  std::wstring::append(result, v5, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 0;
  if ( v35._Myres >= 8 )
    operator delete(v35._Bx._Ptr);
  std::wstring::append(result, L"_", 1u);
  now = __time64(0);
  v6 = __localtime64(&now);
  *(_DWORD *)v29.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v29.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  v7 = v6;
  std::wios::wios(v29.gap68);
  v36 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v29, &v29.gap10[8], 0);
  v36 = 3;
  *(_DWORD *)&v29.gap0[*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::wstring **)((char *)&v28 + *(_DWORD *)(*(_DWORD *)v29.gap0 + 4)) = (std::wstring *)(*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)
                                                                                           - 104);
  std::wstreambuf::wstreambuf(&v29.gap10[8]);
  *(_DWORD *)&v29.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v29.gap10[64] = 0;
  *(_DWORD *)&v29.gap10[68] = 0;
  v36 = 5;
  v8 = std::setw(v33, 2, 0);
  (*(void (__cdecl **)(_BYTE *, _DWORD, _DWORD))v8)(
    &v29.gap10[*(_DWORD *)(*(_DWORD *)v29.gap10 + 4)],
    *(_DWORD *)(v8 + 8),
    *(_DWORD *)(v8 + 12));
  *(_WORD *)&v29.gap10[*(_DWORD *)(*(_DWORD *)v29.gap10 + 4) + 64] = 48;
  v24 = std::setw(v30, 2, 0);
  v9 = std::wostream::operator<<(v29.gap10, v7->tm_mday);
  if ( v9 )
    v10 = v9 + *(_DWORD *)(*(_DWORD *)v9 + 4);
  else
    v10 = 0;
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v24)(v10, *(_DWORD *)(v24 + 8), *(_DWORD *)(v24 + 12));
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v9 + 4) + v9 + 64) = 48;
  v25 = std::setw(v32, 2, 0);
  v11 = std::wostream::operator<<(v9, v7->tm_mon + 1);
  v12 = v11;
  if ( v11 )
    v11 += *(_DWORD *)(*(_DWORD *)v11 + 4);
  (*(void (__stdcall **)(int))v25)(v11);
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v12 + 4) + v12 + 64) = 48;
  std::setw(v34, 2, 0);
  v13 = (std::wostream *)std::wostream::operator<<(v12, v7->tm_year - 100);
  v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, v23);
  v15 = v14;
  if ( v14 )
    v14 = (std::wostream *)((char *)v14 + *(_DWORD *)(*(_DWORD *)v14->gap0 + 4));
  (*(void (__cdecl **)(std::wostream *, _DWORD, _DWORD, const char *))v25)(
    v14,
    *(_DWORD *)(v25 + 8),
    *(_DWORD *)(v25 + 12),
    "-");
  *(_WORD *)&v15->gap0[*(_DWORD *)(*(_DWORD *)v15->gap0 + 4) + 64] = 48;
  v26 = std::setw(v31, 2, 0);
  v16 = std::wostream::operator<<(v15, v7->tm_hour);
  if ( v16 )
    v17 = v16 + *(_DWORD *)(*(_DWORD *)v16 + 4);
  else
    v17 = 0;
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v26)(v17, *(_DWORD *)(v26 + 8), *(_DWORD *)(v26 + 12));
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v16 + 4) + v16 + 64) = 48;
  v18 = std::setw(&v35, 2, 0);
  v19 = std::wostream::operator<<(v16, v7->tm_min);
  if ( v19 )
    v20 = v19 + *(_DWORD *)(*(_DWORD *)v19 + 4);
  else
    v20 = 0;
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v18)(v20, *(_DWORD *)(v18 + 8), *(_DWORD *)(v18 + 12));
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v19 + 4) + v19 + 64) = 48;
  std::wostream::operator<<(v19, v7->tm_sec);
  v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v29, &v35);
  LOBYTE(v36) = 6;
  std::wstring::append(result, v21, 0, 0xFFFFFFFF);
  if ( v35._Myres >= 8 )
    operator delete(v35._Bx._Ptr);
  LOBYTE(v36) = 0;
  *(_DWORD *)&v29.gap0[*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::wstring **)((char *)&v28 + *(_DWORD *)(*(_DWORD *)v29.gap0 + 4)) = (std::wstring *)(*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)
                                                                                           - 104);
  *(_DWORD *)&v29.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v29.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v29.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v29.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v29.gap68);
  return result;
}
int ReplayManager::getCarLeaderboardPosition(ReplayManager *this, CarAvatar *avatar)
{
  return -1;
}
int ReplayManager::getCurrentFrame(ReplayManager *this)
{
  return this->currentFrame;
}
double ReplayManager::getCurrentSunAngle(ReplayManager *this)
{
  unsigned int v1; // edx

  v1 = frameInformation._Myfirst[(this->currentRecordingIndex + this->currentFrame) % this->recordedFrames].sunAngle.data_;
  return COERCE_FLOAT(
           `half_float::detail::half2float_impl'::`2'::exponent_table[v1 >> 10]
         + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v1 & 0x3FF)
                                                                    + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v1 >> 10]]);
}
std::vector<Lap> *ReplayManager::getLaps(ReplayManager *this, std::vector<Lap> *result, CarAvatar *car)
{
  CarAvatar *const *v3; // eax
  unsigned int v4; // esi
  CarAvatar *_Keyval[2]; // [esp+Ch] [ebp-58h] BYREF
  std::vector<ReplayLap> totalLaps; // [esp+14h] [ebp-50h] BYREF
  std::vector<Lap> *v8; // [esp+20h] [ebp-44h]
  Lap l; // [esp+24h] [ebp-40h] BYREF
  int i; // [esp+60h] [ebp-4h]

  v8 = result;
  _Keyval[0] = car;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  i = 0;
  _Keyval[1] = (CarAvatar *)1;
  v3 = std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](&this->replayLaps, _Keyval);
  std::vector<ReplayLap>::vector<ReplayLap>(&totalLaps, (const std::vector<ReplayLap> *)v3);
  v4 = 0;
  for ( i = 1; v4 < _Keyval[0]->physicsState.lapCount; ++v4 )
  {
    l.splits._Myfirst = 0;
    l.splits._Mylast = 0;
    l.splits._Myend = 0;
    l.compound._Myres = 7;
    l.compound._Mysize = 0;
    l.compound._Bx._Buf[0] = 0;
    l.time = 0;
    l.isValid = 0;
    l.cuts = 0;
    LOBYTE(i) = 2;
    if ( v4 < totalLaps._Mylast - totalLaps._Myfirst )
    {
      l.isValid = totalLaps._Myfirst[v4].isValid;
      l.time = totalLaps._Myfirst[v4].time;
    }
    std::vector<Lap>::push_back(result, &l);
    LOBYTE(i) = 1;
    if ( l.compound._Myres >= 8 )
      operator delete(l.compound._Bx._Ptr);
    l.compound._Myres = 7;
    l.compound._Mysize = 0;
    l.compound._Bx._Buf[0] = 0;
    if ( l.splits._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&l.splits);
      operator delete(l.splits._Myfirst);
    }
  }
  LOBYTE(i) = 0;
  if ( totalLaps._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&totalLaps);
    operator delete(totalLaps._Myfirst);
  }
  return result;
}
std::vector<LeaderboardEntry> *ReplayManager::getLeaderboard(ReplayManager *this, std::vector<LeaderboardEntry> *result)
{
  unsigned int v2; // edx
  std::vector<LeaderboardEntry> *v3; // eax

  v2 = (this->currentRecordingIndex + this->currentFrame) % this->recordedFrames;
  if ( v2 >= frameInformation._Mylast - frameInformation._Myfirst
    || replayLeaderboards._Myfirst == replayLeaderboards._Mylast )
  {
    v3 = result;
    result->_Myfirst = 0;
    result->_Mylast = 0;
    result->_Myend = 0;
  }
  else
  {
    std::vector<LeaderboardEntry>::vector<LeaderboardEntry>(
      result,
      &replayLeaderboards._Myfirst[frameInformation._Myfirst[v2].lbIndex]);
    v3 = result;
  }
  return v3;
}
void ReplayManager::getNormalizedLapChange(ReplayManager *this, unsigned int carIndex, std::vector<float> *argumentLapFrames)
{
  ReplayManager *v3; // ebp
  ReplayRecorder **v4; // eax
  unsigned int *v5; // edi
  unsigned int *v6; // esi
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // eax
  float *v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // ebp
  float *v14; // ecx
  float *v15; // eax
  float v16; // [esp+14h] [ebp-20h] BYREF
  ReplayManager *v17; // [esp+18h] [ebp-1Ch]
  std::vector<unsigned int> lapFrames; // [esp+1Ch] [ebp-18h] BYREF
  int v19; // [esp+30h] [ebp-4h]

  v3 = this;
  v17 = this;
  lapFrames._Myfirst = 0;
  lapFrames._Mylast = 0;
  lapFrames._Myend = 0;
  v4 = this->recorders._Myfirst;
  v19 = 0;
  ReplayRecorder::fetchLapFrames(v4[carIndex], &lapFrames);
  v5 = lapFrames._Mylast;
  v6 = lapFrames._Myfirst;
  if ( lapFrames._Myfirst != lapFrames._Mylast )
  {
    do
    {
      v7 = *v6;
      v8 = v3->currentRecordingIndex;
      if ( *v6 >= v8 )
        v9 = v7 - v8;
      else
        v9 = v7 + v3->recordedFrames - v8;
      v10 = argumentLapFrames->_Mylast;
      v11 = (float)v9;
      v12 = v11 / (float)v3->recordedFrames;
      v16 = v12;
      if ( &v16 >= v10 || argumentLapFrames->_Myfirst > &v16 )
      {
        if ( v10 == argumentLapFrames->_Myend )
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)argumentLapFrames, 1u);
        v15 = argumentLapFrames->_Mylast;
        if ( v15 )
          *v15 = v12;
      }
      else
      {
        v13 = &v16 - argumentLapFrames->_Myfirst;
        if ( v10 == argumentLapFrames->_Myend )
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)argumentLapFrames, 1u);
        v14 = argumentLapFrames->_Mylast;
        if ( v14 )
          *v14 = argumentLapFrames->_Myfirst[v13];
        v3 = v17;
      }
      ++argumentLapFrames->_Mylast;
      ++v6;
    }
    while ( v6 != v5 );
    v6 = lapFrames._Myfirst;
  }
  v19 = -1;
  if ( v6 )
  {
    std::_Container_base0::_Orphan_all(&lapFrames);
    operator delete(lapFrames._Myfirst);
  }
}
double ReplayManager::getNormalizedPosition(ReplayManager *this)
{
  return (float)((float)this->currentFrame / (float)(this->recordedFrames - 2));
}
int ReplayManager::getRecordedFrames(ReplayManager *this)
{
  return this->recordedFrames;
}
std::wstring *ReplayManager::getReplayFileName(ReplayManager *this, std::wstring *result, std::wstring session)
{
  struct tm *v3; // eax
  struct tm *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // esi
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // ebp
  int v16; // eax
  int v17; // esi
  std::wstring *v18; // eax
  Sim *v19; // ecx
  std::wostream *v20; // eax
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  std::wostream *v23; // eax
  std::wostream *v24; // eax
  std::wostream *v25; // eax
  std::wostream *v26; // eax
  std::wstring *v28; // [esp-10h] [ebp-168h]
  const std::wstring *v29; // [esp-8h] [ebp-160h]
  const char *v30; // [esp+0h] [ebp-158h]
  const std::wstring *v31; // [esp+0h] [ebp-158h]
  int v32; // [esp+1Ch] [ebp-13Ch]
  int v33; // [esp+1Ch] [ebp-13Ch]
  int v34; // [esp+1Ch] [ebp-13Ch]
  int v35; // [esp+20h] [ebp-138h]
  __int64 now; // [esp+28h] [ebp-130h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v37; // [esp+30h] [ebp-128h] BYREF
  char v38[16]; // [esp+E0h] [ebp-78h] BYREF
  char v39[16]; // [esp+F0h] [ebp-68h] BYREF
  char v40[16]; // [esp+100h] [ebp-58h] BYREF
  int v41[5]; // [esp+110h] [ebp-48h] BYREF
  int v42[3]; // [esp+124h] [ebp-34h] BYREF
  std::wstring v43; // [esp+130h] [ebp-28h] BYREF
  int v44; // [esp+154h] [ebp-4h]

  v44 = 0;
  now = __time64(0);
  v3 = __localtime64(&now);
  *(_DWORD *)v37.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v37.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  v4 = v3;
  std::wios::wios(v37.gap68);
  LOBYTE(v44) = 1;
  std::wiostream::basic_iostream<wchar_t>(&v37, &v37.gap10[8], 0);
  v44 = 2;
  *(_DWORD *)&v37.gap0[*(_DWORD *)(*(_DWORD *)v37.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&now + *(_DWORD *)(*(_DWORD *)v37.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v37.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v37.gap10[8]);
  *(_DWORD *)&v37.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v37.gap10[64] = 0;
  *(_DWORD *)&v37.gap10[68] = 0;
  LOBYTE(v44) = 4;
  std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v37.gap10, L"AC_");
  v5 = std::setw(v41, 2, 0);
  (*(void (__cdecl **)(_BYTE *, _DWORD, _DWORD))v5)(
    &v37.gap10[*(_DWORD *)(*(_DWORD *)v37.gap10 + 4)],
    *(_DWORD *)(v5 + 8),
    *(_DWORD *)(v5 + 12));
  *(_WORD *)&v37.gap10[*(_DWORD *)(*(_DWORD *)v37.gap10 + 4) + 64] = 48;
  v32 = std::setw(v38, 2, 0);
  v6 = std::wostream::operator<<(v37.gap10, v4->tm_mday);
  v7 = v6;
  if ( v6 )
    v6 += *(_DWORD *)(*(_DWORD *)v6 + 4);
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v32)(v6, *(_DWORD *)(v32 + 8), *(_DWORD *)(v32 + 12));
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v7 + 4) + v7 + 64) = 48;
  v33 = std::setw(v40, 2, 0);
  v8 = std::wostream::operator<<(v7, v4->tm_mon + 1);
  v9 = v8;
  if ( v8 )
    v8 += *(_DWORD *)(*(_DWORD *)v8 + 4);
  (*(void (__stdcall **)(int))v33)(v8);
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v9 + 4) + v9 + 64) = 48;
  v35 = std::setw(v42, 2, 0);
  v10 = (std::wostream *)std::wostream::operator<<(v9, v4->tm_year - 100);
  v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v10, v30);
  v12 = v11;
  if ( v11 )
    v11 = (std::wostream *)((char *)v11 + *(_DWORD *)(*(_DWORD *)v11->gap0 + 4));
  (*(void (__cdecl **)(std::wostream *, _DWORD, _DWORD, const char *))v33)(
    v11,
    *(_DWORD *)(v33 + 8),
    *(_DWORD *)(v33 + 12),
    "-");
  *(_WORD *)&v12->gap0[*(_DWORD *)(*(_DWORD *)v12->gap0 + 4) + 64] = 48;
  v34 = std::setw(v39, 2, 0);
  v13 = std::wostream::operator<<(v12, v4->tm_hour);
  v14 = v13;
  if ( v13 )
    v13 += *(_DWORD *)(*(_DWORD *)v13 + 4);
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v34)(v13, *(_DWORD *)(v34 + 8), *(_DWORD *)(v34 + 12));
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v14 + 4) + v14 + 64) = 48;
  v15 = std::setw(&v43, 2, 0);
  v16 = std::wostream::operator<<(v14, v4->tm_min);
  v17 = v16;
  if ( v16 )
    v16 += *(_DWORD *)(*(_DWORD *)v16 + 4);
  (*(void (__cdecl **)(int, _DWORD, _DWORD))v15)(v16, *(_DWORD *)(v15 + 8), *(_DWORD *)(v15 + 12));
  *(_WORD *)(*(_DWORD *)(*(_DWORD *)v17 + 4) + v17 + 64) = 48;
  std::wostream::operator<<(v17, v4->tm_sec);
  v18 = TrackAvatar::getConfig(*(TrackAvatar **)(*(_DWORD *)(v35 + 176) + 180), &v43);
  v19 = *(Sim **)(v35 + 176);
  v31 = v18;
  LOBYTE(v44) = 5;
  v29 = &v19->track->name;
  v28 = &Sim::getCar(v19, 0)->unixName;
  v20 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v37.gap10, "_");
  v21 = std::operator<<<wchar_t>(v20, &session);
  v22 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v21, "_");
  v23 = std::operator<<<wchar_t>(v22, v28);
  v24 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v23, "_");
  v25 = std::operator<<<wchar_t>(v24, v29);
  v26 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v25, "_");
  std::operator<<<wchar_t>(v26, v31);
  LOBYTE(v44) = 4;
  if ( v43._Myres >= 8 )
    operator delete(v43._Bx._Ptr);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, result);
  LOBYTE(v44) = 0;
  *(_DWORD *)&v37.gap0[*(_DWORD *)(*(_DWORD *)v37.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&now + *(_DWORD *)(*(_DWORD *)v37.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v37.gap0 + 4) - 104;
  *(_DWORD *)&v37.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v37.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v37.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v37.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v37.gap68);
  if ( session._Myres >= 8 )
    operator delete(session._Bx._Ptr);
  return result;
}
bool ReplayManager::isInReplaymode(ReplayManager *this)
{
  return this->replayMode;
}
char __userpurge ReplayManager::load@<al>(ReplayManager *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *filename)
{
  ReplayManager *v4; // ebx
  int v5; // esi
  __m128 v6; // xmm0
  std::wstring *v7; // esi
  std::wstring *v8; // esi
  unsigned int v9; // ebx
  int v10; // edi
  unsigned int v11; // eax
  __int16 v12; // ax
  unsigned int v13; // esi
  int v14; // edi
  Sim *v15; // ecx
  CarAvatar *v16; // edi
  GameObject **v17; // esi
  ReplayRecorder *v18; // eax
  std::map<CarAvatar *,std::vector<ReplayLap>> *v19; // ebx
  CarAvatar **v20; // esi
  unsigned int v21; // ebp
  std::vector<SplineIndexBound> *v22; // esi
  SplineIndexBound *v23; // ecx
  SplineIndexBound *v24; // ebx
  SplineIndexBound *v25; // edx
  int v26; // edi
  int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // edx
  SplineIndexBound *v30; // ecx
  SplineIndexBound *v31; // edx
  unsigned int v32; // eax
  SplineIndexBound *v33; // edx
  int v34; // ecx
  unsigned int v35; // edx
  unsigned int v36; // edx
  char v37; // bl
  unsigned int v38; // ebp
  ReplayManager *v39; // ebp
  CarAvatar *v40; // esi
  bool v41; // bl
  LeaderboardEntry *v42; // eax
  LeaderboardEntry *v43; // ecx
  int v44; // esi
  unsigned int v45; // esi
  __m128i v46; // xmm0
  ReplayManager *v47; // esi
  std::vector<ICollisionObject *> *v48; // ebp
  unsigned int v49; // ebx
  CarAvatar *v50; // edi
  GameObject **v51; // esi
  int v52; // eax
  unsigned int v54; // [esp+A8h] [ebp-24Ch] BYREF
  int aVersion; // [esp+ACh] [ebp-248h] BYREF
  unsigned int lapsCount; // [esp+B0h] [ebp-244h] BYREF
  int v57; // [esp+B4h] [ebp-240h] BYREF
  CarAvatar *car; // [esp+B8h] [ebp-23Ch] BYREF
  ReplayManager *v59; // [esp+BCh] [ebp-238h]
  unsigned int index[2]; // [esp+C0h] [ebp-234h] BYREF
  int v61; // [esp+C8h] [ebp-22Ch] BYREF
  ReplayLap l; // [esp+CCh] [ebp-228h] BYREF
  LeaderboardEntry lb; // [esp+D4h] [ebp-220h] BYREF
  std::ifstream in; // [esp+F4h] [ebp-200h] BYREF
  std::vector<LeaderboardEntry> leaderboard; // [esp+1ACh] [ebp-148h] BYREF
  int v66; // [esp+1BCh] [ebp-138h]
  unsigned int v67; // [esp+1C0h] [ebp-134h]
  std::vector<unsigned int> bestSplits; // [esp+1C4h] [ebp-130h] BYREF
  int v69; // [esp+1D0h] [ebp-124h]
  int v70; // [esp+1D4h] [ebp-120h]
  unsigned int v71; // [esp+1D8h] [ebp-11Ch]
  std::wstring weather_set; // [esp+1DCh] [ebp-118h] BYREF
  std::wstring track_config; // [esp+1F4h] [ebp-100h] BYREF
  std::wstring driver_name; // [esp+20Ch] [ebp-E8h] BYREF
  std::wstring model; // [esp+224h] [ebp-D0h] BYREF
  std::wstring driver_team; // [esp+23Ch] [ebp-B8h] BYREF
  std::wstring driver_nationcode; // [esp+254h] [ebp-A0h] BYREF
  std::wstring track_name; // [esp+26Ch] [ebp-88h] BYREF
  DriverInfo v79; // [esp+284h] [ebp-70h] BYREF
  int v80; // [esp+2F0h] [ebp-4h]

  v4 = this;
  v59 = this;
  PhysicsAvatar::pausePhysics(this->sim->physicsAvatar, 1);
  if ( !Path::fileExists((unsigned int)v4, filename, 0) )
  {
    _printf("ERROR: REPLAY MANAGER :: LOAD FAILED\n");
    return 0;
  }
  std::ifstream::ifstream(&in, filename, 32, 64, 1);
  v80 = 1;
  weather_set._Myres = 7;
  weather_set._Mysize = 0;
  weather_set._Bx._Buf[0] = 0;
  std::istream::read(&in, &aVersion);
  v5 = aVersion;
  _printf("Loading replay version %d\n", aVersion);
  if ( v5 < 13 )
  {
    v6 = (__m128)*(unsigned __int64 *)&DOUBLE_32_0;
    ReplayRecorder::recordIntervalMS = DOUBLE_32_0;
  }
  else
  {
    std::istream::read(&in, index);
    v6 = (__m128)*(unsigned __int64 *)index;
    ReplayRecorder::recordIntervalMS = *(long double *)index;
    v7 = ksLoadString(&model, &in);
    if ( &weather_set != v7 )
    {
      if ( weather_set._Myres >= 8 )
        operator delete(weather_set._Bx._Ptr);
      weather_set._Myres = 7;
      weather_set._Mysize = 0;
      weather_set._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&weather_set, v7);
    }
    if ( model._Myres >= 8 )
      operator delete(model._Bx._Ptr);
    v5 = aVersion;
  }
  ksLoadString(&track_name, &in);
  track_config._Myres = 7;
  track_config._Mysize = 0;
  track_config._Bx._Buf[0] = 0;
  LOBYTE(v80) = 3;
  if ( v5 >= 14 )
  {
    v8 = ksLoadString(&model, &in);
    if ( &track_config != v8 )
    {
      if ( track_config._Myres >= 8 )
        operator delete(track_config._Bx._Ptr);
      track_config._Myres = 7;
      track_config._Mysize = 0;
      track_config._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&track_config, v8);
    }
    if ( model._Myres >= 8 )
      operator delete(model._Bx._Ptr);
    v5 = aVersion;
  }
  Sim::loadTrack(v4->sim, v6, a2, a3, &track_name, &track_config, 0);
  std::istream::read(&in, &v61);
  if ( v5 >= 2 )
  {
    std::istream::read(&in, &v54);
    v4->currentRecordingIndex = v54;
  }
  v4->currentRecordingIndex = 0;
  if ( v5 >= 8 )
  {
    std::istream::read(&in, &v57);
    std::_Container_base0::_Orphan_all(&frameInformation);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::LightGroup>>>(
      (DRSDetection *)frameInformation._Myfirst,
      (DRSDetection *)frameInformation._Mylast);
    v9 = 0;
    frameInformation._Mylast = frameInformation._Myfirst;
    if ( v5 >= 11 )
    {
      std::istream::read(&in, &v54);
      v9 = v54;
    }
    v10 = v57;
    if ( v57 )
    {
      v54 = 0;
      v11 = 0;
      index[0] = 0;
      do
      {
        bestSplits._Myfirst = (unsigned int *)(unsigned __int16)(`half_float::detail::float2half_impl<-1>'::`2'::base_table[0]
                                                               + (v11 >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[0]));
        bestSplits._Mylast = 0;
        bestSplits._Myend = 0;
        v69 = 0;
        LOBYTE(v80) = 4;
        if ( v5 < 9 )
        {
          std::istream::read(&in, &v54);
          v57 = v54;
          LOWORD(bestSplits._Myfirst) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v54 >> 23]
                                      + ((((unsigned int)&loc_7FFFFD + 2) & v54) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v54 >> 23]);
        }
        else
        {
          LOWORD(lapsCount) = 0;
          std::istream::read(&in, &lapsCount);
          LOWORD(bestSplits._Myfirst) = lapsCount;
        }
        if ( v5 < 10 )
        {
          v12 = 0;
        }
        else
        {
          std::istream::read(&in, &car);
          v12 = (__int16)car;
        }
        HIWORD(bestSplits._Myfirst) = v12;
        if ( v5 >= 11 && v9 )
        {
          v13 = v9;
          do
          {
            leaderboard._Myfirst = 0;
            LOWORD(leaderboard._Mylast) = 0;
            *(LeaderboardEntry **)((char *)&leaderboard._Mylast + 2) = 0;
            HIWORD(leaderboard._Myend) = 0;
            std::istream::read(&in, &leaderboard);
            std::vector<PitStopStrategy>::push_back(
              (std::vector<PenaltyRecord> *)&bestSplits._Mylast,
              (PenaltyRecord *)&leaderboard);
            --v13;
          }
          while ( v13 );
          v5 = aVersion;
        }
        std::vector<FrameInformation>::push_back(&frameInformation, (const FrameInformation *)&bestSplits);
        LOBYTE(v80) = 3;
        if ( bestSplits._Mylast )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)&bestSplits._Mylast);
          operator delete(bestSplits._Mylast);
          bestSplits._Mylast = 0;
          bestSplits._Myend = 0;
          v69 = 0;
        }
        v11 = index[0];
        --v10;
      }
      while ( v10 );
    }
    v4 = v59;
  }
  v14 = v61;
  v54 = 0;
  if ( v61 > 0 )
  {
    while ( 1 )
    {
      ksLoadString(&model, &in);
      LOBYTE(v80) = 5;
      ksLoadString(&driver_name, &in);
      LOBYTE(v80) = 6;
      ksLoadString(&driver_nationcode, &in);
      LOBYTE(v80) = 7;
      ksLoadString(&driver_team, &in);
      LOBYTE(v80) = 8;
      ksLoadString((std::wstring *)&bestSplits, &in);
      LOBYTE(v80) = 9;
      v67 = 7;
      v66 = 0;
      LOWORD(leaderboard._Myfirst) = 0;
      std::wstring::assign((std::wstring *)&leaderboard, word_17BE9D8, 0);
      v15 = v4->sim;
      LOBYTE(v80) = 10;
      *(float *)&car = COERCE_FLOAT(
                         Sim::addCar(
                           v15,
                           a2,
                           a3,
                           &model,
                           (const std::wstring *)&leaderboard,
                           (const std::wstring *)&bestSplits));
      if ( v67 >= 8 )
        operator delete(leaderboard._Myfirst);
      v79.name._Myres = 7;
      v79.name._Mysize = 0;
      v79.name._Bx._Buf[0] = 0;
      v79.team._Myres = 7;
      v79.team._Mysize = 0;
      v79.team._Bx._Buf[0] = 0;
      v79.nationality._Myres = 7;
      v79.nationality._Mysize = 0;
      v79.nationality._Bx._Buf[0] = 0;
      v79.nationCode._Myres = 7;
      v79.nationCode._Mysize = 0;
      v79.nationCode._Bx._Buf[0] = 0;
      LOBYTE(v80) = 11;
      std::wstring::assign(&v79.name, &driver_name, 0, 0xFFFFFFFF);
      std::wstring::assign(&v79.nationCode, &driver_nationcode, 0, 0xFFFFFFFF);
      if ( v79.nationCode._Mysize > 3 )
        std::wstring::assign(&v79.nationCode, L"AC", 2u);
      std::wstring::assign(&v79.team, &driver_team, 0, 0xFFFFFFFF);
      CarAvatar::setDriverInfo(car, &v79);
      v16 = car;
      v17 = car->gameObjects._Myfirst;
      if ( v17 == car->gameObjects._Mylast )
      {
LABEL_49:
        v18 = 0;
      }
      else
      {
        while ( 1 )
        {
          v18 = (ReplayRecorder *)__RTDynamicCast(
                                    *v17,
                                    0,
                                    &GameObject `RTTI Type Descriptor',
                                    &ReplayRecorder `RTTI Type Descriptor',
                                    0);
          if ( v18 )
            break;
          if ( ++v17 == v16->gameObjects._Mylast )
            goto LABEL_49;
        }
      }
      v4->recordedFrames = ReplayRecorder::load(v18, &in, aVersion);
      lapsCount = 0;
      std::istream::read(&in, &lapsCount);
      if ( lapsCount > 0x270F )
      {
        SetupItemText::~SetupItemText(&v79);
        if ( v71 >= 8 )
          operator delete(bestSplits._Myfirst);
        v71 = 7;
        v70 = 0;
        LOWORD(bestSplits._Myfirst) = 0;
        if ( driver_team._Myres >= 8 )
          operator delete(driver_team._Bx._Ptr);
        driver_team._Myres = 7;
        driver_team._Mysize = 0;
        driver_team._Bx._Buf[0] = 0;
        if ( driver_nationcode._Myres >= 8 )
          operator delete(driver_nationcode._Bx._Ptr);
        driver_nationcode._Myres = 7;
        driver_nationcode._Mysize = 0;
        driver_nationcode._Bx._Buf[0] = 0;
        if ( driver_name._Myres >= 8 )
          operator delete(driver_name._Bx._Ptr);
        driver_name._Myres = 7;
        driver_name._Mysize = 0;
        driver_name._Bx._Buf[0] = 0;
        if ( model._Myres >= 8 )
          operator delete(model._Bx._Ptr);
        v37 = 0;
        goto LABEL_135;
      }
      v19 = &v4->replayLaps;
      index[0] = (unsigned int)v19;
      v20 = (CarAvatar **)std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](v19, &car);
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)v20);
      v21 = 0;
      v20[1] = *v20;
      v57 = 0;
      if ( lapsCount )
        break;
LABEL_78:
      SetupItemText::~SetupItemText(&v79);
      if ( v71 >= 8 )
        operator delete(bestSplits._Myfirst);
      v71 = 7;
      v70 = 0;
      LOWORD(bestSplits._Myfirst) = 0;
      if ( driver_team._Myres >= 8 )
        operator delete(driver_team._Bx._Ptr);
      driver_team._Myres = 7;
      driver_team._Mysize = 0;
      driver_team._Bx._Buf[0] = 0;
      if ( driver_nationcode._Myres >= 8 )
        operator delete(driver_nationcode._Bx._Ptr);
      driver_nationcode._Myres = 7;
      driver_nationcode._Mysize = 0;
      driver_nationcode._Bx._Buf[0] = 0;
      if ( driver_name._Myres >= 8 )
        operator delete(driver_name._Bx._Ptr);
      driver_name._Myres = 7;
      driver_name._Mysize = 0;
      driver_name._Bx._Buf[0] = 0;
      LOBYTE(v80) = 3;
      if ( model._Myres >= 8 )
        operator delete(model._Bx._Ptr);
      v14 = v61;
      if ( (int)++v54 >= v61 )
        goto LABEL_102;
      v4 = v59;
    }
    while ( 1 )
    {
      l.time = 0;
      l.isValid = 0;
      std::istream::read(&in, &l);
      v22 = (std::vector<SplineIndexBound> *)std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](v19, &car);
      v23 = v22->_Mylast;
      if ( &l >= (ReplayLap *)v23 || (v24 = v22->_Myfirst, v22->_Myfirst > (SplineIndexBound *)&l) )
      {
        v33 = v22->_Myend;
        if ( v23 == v33 && !(v33 - v23) )
        {
          v34 = v23 - v22->_Myfirst;
          if ( v34 == 0x1FFFFFFF )
LABEL_90:
            std::_Xlength_error("vector<T> too long");
          v35 = v33 - v22->_Myfirst;
          if ( 0x1FFFFFFF - (v35 >> 1) >= v35 )
            v36 = (v35 >> 1) + v35;
          else
            v36 = 0;
          if ( v36 < v34 + 1 )
            v36 = v34 + 1;
          std::vector<ReplayLap>::_Reallocate(v22, v36);
        }
        v30 = v22->_Mylast;
        if ( !v30 )
          goto LABEL_77;
        v30->minIndex = l.time;
        v32 = *(_DWORD *)&l.isValid;
      }
      else
      {
        v25 = v22->_Myend;
        v26 = ((char *)&l - (char *)v24) >> 3;
        if ( v23 == v25 && !(v25 - v23) )
        {
          v27 = v23 - v24;
          if ( v27 == 0x1FFFFFFF )
            goto LABEL_90;
          v28 = v25 - v24;
          if ( 0x1FFFFFFF - (v28 >> 1) >= v28 )
            v29 = (v28 >> 1) + v28;
          else
            v29 = 0;
          if ( v29 < v27 + 1 )
            v29 = v27 + 1;
          std::vector<ReplayLap>::_Reallocate(v22, v29);
          v21 = v57;
        }
        v30 = v22->_Mylast;
        v31 = v22->_Myfirst;
        if ( !v30 )
          goto LABEL_77;
        v30->minIndex = v31[v26].minIndex;
        v32 = v31[v26].maxIndex;
      }
      v30->maxIndex = v32;
LABEL_77:
      ++v22->_Mylast;
      ++v21;
      v19 = (std::map<CarAvatar *,std::vector<ReplayLap>> *)index[0];
      v57 = v21;
      if ( v21 >= lapsCount )
        goto LABEL_78;
    }
  }
LABEL_102:
  if ( aVersion < 10 )
    goto LABEL_124;
  std::istream::read(&in, index);
  v38 = index[0];
  v54 = index[0];
  if ( !index[0] )
    goto LABEL_124;
  do
  {
    leaderboard._Myfirst = 0;
    leaderboard._Mylast = 0;
    leaderboard._Myend = 0;
    LOBYTE(v80) = 12;
    if ( v14 <= 0 )
      goto LABEL_121;
    v39 = v59;
    do
    {
      std::istream::read(&in, index);
      v40 = Sim::getCar(v39->sim, index[0]);
      std::istream::read(&in, &car);
      std::istream::read(&in, &v57);
      v41 = v57 > 0;
      std::istream::read(&in, &lapsCount);
      std::istream::read(&in, &aVersion);
      bestSplits._Myfirst = 0;
      bestSplits._Mylast = 0;
      bestSplits._Myend = 0;
      lb.isBlackFlagged = v40->isBlackFlagged;
      lb.laps = lapsCount;
      v42 = leaderboard._Mylast;
      LOBYTE(v80) = 13;
      lb.car = v40;
      lb.isRaceMode = v41;
      lb.totalTime = *(float *)&aVersion;
      lb.hasCompletedLastLap = 0;
      lb.bestLap = *(float *)&car;
      if ( &lb >= leaderboard._Mylast || (v43 = leaderboard._Myfirst, leaderboard._Myfirst > &lb) )
      {
        if ( leaderboard._Mylast == leaderboard._Myend )
        {
          std::vector<ClientCollisionEvent>::_Reserve((std::vector<ClientCollisionEvent> *)&leaderboard, 1u);
          v42 = leaderboard._Mylast;
        }
        if ( v42 )
        {
          *(__m128i *)&v42->car = _mm_loadu_si128((const __m128i *)&lb);
          v46 = _mm_loadu_si128((const __m128i *)&lb.bestLap);
          goto LABEL_116;
        }
      }
      else
      {
        v44 = (char *)&lb - (char *)leaderboard._Myfirst;
        if ( leaderboard._Mylast == leaderboard._Myend )
        {
          std::vector<ClientCollisionEvent>::_Reserve((std::vector<ClientCollisionEvent> *)&leaderboard, 1u);
          v42 = leaderboard._Mylast;
          v43 = leaderboard._Myfirst;
        }
        v45 = v44 & 0xFFFFFFE0;
        if ( v42 )
        {
          *(__m128i *)&v42->car = _mm_loadu_si128((const __m128i *)((char *)v43 + v45));
          v46 = _mm_loadu_si128((const __m128i *)((char *)&v43->bestLap + v45));
LABEL_116:
          *(__m128i *)&v42->bestLap = v46;
          v42 = leaderboard._Mylast;
          goto LABEL_117;
        }
      }
LABEL_117:
      LOBYTE(v80) = 12;
      leaderboard._Mylast = v42 + 1;
      if ( bestSplits._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&bestSplits);
        operator delete(bestSplits._Myfirst);
        bestSplits._Myfirst = 0;
        bestSplits._Mylast = 0;
        bestSplits._Myend = 0;
      }
      --v14;
    }
    while ( v14 );
    v38 = v54;
    v14 = v61;
LABEL_121:
    std::vector<std::vector<LeaderboardEntry>>::push_back(&replayLeaderboards, &leaderboard);
    LOBYTE(v80) = 3;
    if ( leaderboard._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&leaderboard);
      operator delete(leaderboard._Myfirst);
      leaderboard._Myfirst = 0;
      leaderboard._Mylast = 0;
      leaderboard._Myend = 0;
    }
    v54 = --v38;
  }
  while ( v38 );
LABEL_124:
  v47 = v59;
  v48 = (std::vector<ICollisionObject *> *)&v59->recorders;
  v59->hasLoadedReplay = 1;
  std::_Container_base0::_Orphan_all(v48);
  v49 = 0;
  v48->_Mylast = v48->_Myfirst;
  if ( v14 )
  {
    do
    {
      v50 = Sim::getCar(v47->sim, v49);
      v51 = v50->gameObjects._Myfirst;
      if ( v51 == v50->gameObjects._Mylast )
      {
LABEL_128:
        v52 = 0;
      }
      else
      {
        while ( 1 )
        {
          v52 = __RTDynamicCast(*v51, 0, &GameObject `RTTI Type Descriptor', &ReplayRecorder `RTTI Type Descriptor', 0);
          if ( v52 )
            break;
          if ( ++v51 == v50->gameObjects._Mylast )
            goto LABEL_128;
        }
      }
      index[0] = v52;
      std::vector<SpinnerData *>::push_back(v48, (ICollisionObject *const *)index);
      v47 = v59;
      ++v49;
    }
    while ( v49 < v61 );
  }
  if ( !std::filebuf::close((std::filebuf *)in.gap10) )
    std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
  if ( weather_set._Mysize )
    Sim::applyCustomWeather(v47->sim, &weather_set);
  v37 = 1;
LABEL_135:
  if ( track_config._Myres >= 8 )
    operator delete(track_config._Bx._Ptr);
  track_config._Myres = 7;
  track_config._Mysize = 0;
  track_config._Bx._Buf[0] = 0;
  if ( track_name._Myres >= 8 )
    operator delete(track_name._Bx._Ptr);
  track_name._Myres = 7;
  track_name._Mysize = 0;
  track_name._Bx._Buf[0] = 0;
  if ( weather_set._Myres >= 8 )
    operator delete(weather_set._Bx._Ptr);
  weather_set._Myres = 7;
  weather_set._Mysize = 0;
  weather_set._Bx._Buf[0] = 0;
  std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
  std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
  return v37;
}
void ReplayManager::nextFrame(ReplayManager *this)
{
  this->status = eSingleFrame;
  this->oldStatus = eSingleFrame;
  this->timeMult = 0.49000001;
  ReplayManager::updateReplayAudio(this);
}
void ReplayManager::nextLap(ReplayManager *this)
{
  Sim *v2; // ecx
  unsigned int v3; // eax
  int v4; // edx
  unsigned int *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  std::vector<unsigned int> lapFrames; // [esp+14h] [ebp-18h] BYREF
  int v10; // [esp+28h] [ebp-4h]

  if ( this->recorders._Myfirst != this->recorders._Mylast )
  {
    lapFrames._Myfirst = 0;
    lapFrames._Mylast = 0;
    lapFrames._Myend = 0;
    v2 = this->sim;
    v10 = 0;
    v3 = Sim::getFocusedCarIndex(v2);
    ReplayRecorder::fetchLapFrames(this->recorders._Myfirst[v3], &lapFrames);
    v4 = 0;
    v5 = lapFrames._Myfirst;
    v6 = 0;
    v7 = lapFrames._Mylast - lapFrames._Myfirst;
    if ( v7 )
    {
      do
      {
        v8 = lapFrames._Myfirst[v6];
        if ( this->currentFrame < v8 && !v4 )
          v4 = v8 + 60;
        ++v6;
      }
      while ( v6 < v7 );
      if ( v4 )
        this->currentFrame = v4;
    }
    v10 = -1;
    if ( v5 )
    {
      std::_Container_base0::_Orphan_all(&lapFrames);
      operator delete(lapFrames._Myfirst);
    }
  }
}
void ReplayManager::onStepCompleted(ReplayManager *this, const OnPhysicsStepCompleted *ev)
{
  ReplayManager *v2; // edi
  const OnPhysicsStepCompleted *v3; // edx
  ReplayRecorder **v4; // eax
  ReplayRecorder **v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  int v8; // esi
  int v9; // eax
  unsigned int v10; // esi
  int v11; // edx
  PhysicsObject *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  long double v16; // st7
  long double v17; // st6
  float v18; // xmm0_4
  unsigned int v19; // eax
  unsigned int v20; // edx
  float v21; // xmm2_4
  unsigned int v22; // eax
  unsigned int v23; // edx
  int v24; // ecx
  Sim *v25; // eax
  int v26; // eax
  int v27; // ecx
  mat44f result; // [esp+4h] [ebp-5Ch] BYREF
  float v29; // [esp+44h] [ebp-1Ch]
  float v30; // [esp+4Ch] [ebp-14h]
  float v31; // [esp+50h] [ebp-10h]
  unsigned int v32; // [esp+54h] [ebp-Ch]
  unsigned int v33; // [esp+58h] [ebp-8h]
  int v34; // [esp+5Ch] [ebp-4h]

  v2 = this;
  v31 = *(float *)&this;
  if ( (dword_186E930 & 1) == 0 )
  {
    perfCounter_1.name = "ReplayManager::onStepCompleted";
    dword_186E930 |= 1u;
    perfCounter_1.group = Physics;
    perfCounter_1.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"ReplayManager::onStepCompleted" | 0xFF000000;
  }
  v3 = ev;
  if ( ev->pt - this->lastRecordTime >= ReplayRecorder::recordIntervalMS && !this->hasLoadedReplay )
  {
    v4 = this->recorders._Mylast;
    v5 = this->recorders._Myfirst;
    v33 = 0;
    v6 = (unsigned int)((char *)v4 - (char *)v5 + 3) >> 2;
    v34 = 0;
    if ( v5 > v4 )
      v6 = v33;
    v32 = v6;
    if ( v6 )
    {
      v7 = 0;
      v33 = 0;
      do
      {
        ReplayRecorder::recordFrame(*v5++, (const CarPhysicsState *)((char *)v3->states->_Myfirst + v7));
        v3 = ev;
        v7 = v33 + 2872;
        ++v34;
        v33 += 2872;
      }
      while ( v34 != v32 );
      v2 = (ReplayManager *)LODWORD(v31);
    }
    v31 = v2->game->graphics->lightingSettings.angle;
    frameInformation._Myfirst[v2->currentRecordingIndex].sunAngle.data_ = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v31) >> 23]
                                                                        + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v31)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v31) >> 23]);
    v8 = replayLeaderboards._Mylast - replayLeaderboards._Myfirst;
    v9 = v8 - 1;
    if ( v8 - 1 <= v8 )
    {
      LOWORD(v8) = v8 - 1;
      if ( v9 < 0 )
        LOWORD(v8) = 0;
    }
    frameInformation._Myfirst[v2->currentRecordingIndex].lbIndex = v8;
    v10 = 0;
    if ( v2->sim->track->trackObjects._Mylast - v2->sim->track->trackObjects._Myfirst )
    {
      v11 = 0;
      v34 = 0;
      do
      {
        v12 = v2->sim->track->trackObjects._Myfirst[v10]->physicsObject;
        if ( v12 )
        {
          PhysicsObject::getWorldMatrix(v12, &result);
          LODWORD(v31) = LODWORD(result.M31) ^ _xmm;
          v13 = result.M32;
          v14 = FLOAT_1_0;
          v29 = atan2(COERCE_FLOAT(LODWORD(result.M31) ^ _xmm), result.M33);
          if ( result.M32 > 1.0 || (v14 = FLOAT_N1_0, result.M32 < -1.0) )
            v13 = v14;
          __libm_sse2_asinf();
          v15 = 0.0;
          if ( result.M12 == 0.0 && result.M22 == 0.0 )
          {
            v16 = result.M21;
            v17 = result.M11;
          }
          else
          {
            v15 = v29;
            LODWORD(v31) = LODWORD(result.M12) ^ _xmm;
            v16 = COERCE_FLOAT(LODWORD(result.M12) ^ _xmm);
            v17 = result.M22;
          }
          v31 = v13;
          v30 = atan2(v16, v17);
          v18 = v30;
          *(unsigned __int16 *)((char *)&frameInformation._Myfirst[v2->currentRecordingIndex].trackObjects._Myfirst->euler[0].data_
                              + v34) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v15) >> 23]
                                     + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v15)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v15) >> 23]);
          v19 = LODWORD(v31) >> 23;
          v20 = ((unsigned int)&loc_7FFFFD + 2) & LODWORD(v31);
          v31 = v18;
          *(unsigned __int16 *)((char *)&frameInformation._Myfirst[v2->currentRecordingIndex].trackObjects._Myfirst->euler[1].data_
                              + v34) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v19]
                                     + (v20 >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v19]);
          *(unsigned __int16 *)((char *)&frameInformation._Myfirst[v2->currentRecordingIndex].trackObjects._Myfirst->euler[2].data_
                              + v34) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v31) >> 23]
                                     + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v31)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v31) >> 23]);
          v21 = result.M43;
          v31 = result.M42;
          *(unsigned __int16 *)((char *)&frameInformation._Myfirst[v2->currentRecordingIndex].trackObjects._Myfirst->translation[0].data_
                              + v34) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(result.M41) >> 23]
                                     + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(result.M41)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(result.M41) >> 23]);
          v22 = LODWORD(v31) >> 23;
          v23 = ((unsigned int)&loc_7FFFFD + 2) & LODWORD(v31);
          v31 = v21;
          *(unsigned __int16 *)((char *)&frameInformation._Myfirst[v2->currentRecordingIndex].trackObjects._Myfirst->translation[1].data_
                              + v34) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[v22]
                                     + (v23 >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[v22]);
          v24 = v34;
          *(unsigned __int16 *)((char *)&frameInformation._Myfirst[v2->currentRecordingIndex].trackObjects._Myfirst->translation[2].data_
                              + v34) = `half_float::detail::float2half_impl<-1>'::`2'::base_table[LODWORD(v31) >> 23]
                                     + ((((unsigned int)&loc_7FFFFD + 2) & LODWORD(v31)) >> `half_float::detail::float2half_impl<-1>'::`2'::shift_table[LODWORD(v31) >> 23]);
          v11 = v24;
        }
        v25 = v2->sim;
        ++v10;
        v11 += 12;
        v34 = v11;
      }
      while ( v10 < v25->track->trackObjects._Mylast - v25->track->trackObjects._Myfirst );
    }
    v26 = v2->recordedFrames;
    v27 = v2->maxFrames;
    if ( v26 < v27 )
      v2->recordedFrames = v26 + 1;
    if ( ++v2->currentRecordingIndex >= v27 )
      v2->currentRecordingIndex = 0;
    v2->lastRecordTime = ev->pt;
  }
}
void ReplayManager::pause(ReplayManager *this)
{
  Sim *v2; // ebx
  float v3; // xmm0_4
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v4; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v5; // edi
  int v6[3]; // [esp+10h] [ebp-Ch] BYREF

  v6[0] = 1;
  v6[1] = 0;
  v2 = this->sim;
  v3 = this->slowMoLevel;
  this->status = eReplayPause;
  this->timeMult = 0.0;
  *(float *)&v6[2] = v3;
  v4 = v2->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v4 != v2->evOnReplayStatusChanged.handlers._Mylast )
  {
    v5 = &v4->second._Impl;
    do
    {
      if ( !*v5 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x64CA4F);
      }
      (*v5)->_Do_call(*v5, (const OnReplayStatusChanged *)v6);
      ++v4;
      v5 += 8;
    }
    while ( v4 != v2->evOnReplayStatusChanged.handlers._Mylast );
  }
  ReplayManager::updateReplayAudio(this);
}
void ReplayManager::photoMode(ReplayManager *this)
{
  ReplayInterface *v2; // ecx
  Sim *v3; // ebx
  eReplayStatus v4; // eax
  float v5; // xmm0_4
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v6; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v7; // edi
  int v8[3]; // [esp+10h] [ebp-Ch] BYREF

  v2 = this->replayInterface;
  this->status = ePhotoMode;
  this->timeMult = 0.0;
  ReplayInterface::onReplayManagerStatusChanged(v2, ePhotoMode);
  v3 = this->sim;
  v4 = this->status;
  v8[1] = LODWORD(this->timeMult);
  v5 = this->slowMoLevel;
  v8[0] = v4;
  *(float *)&v8[2] = v5;
  v6 = v3->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v6 != v3->evOnReplayStatusChanged.handlers._Mylast )
  {
    v7 = &v6->second._Impl;
    do
    {
      if ( !*v7 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x64CADF);
      }
      (*v7)->_Do_call(*v7, (const OnReplayStatusChanged *)v8);
      ++v6;
      v7 += 8;
    }
    while ( v6 != v3->evOnReplayStatusChanged.handlers._Mylast );
  }
  ReplayManager::updateReplayAudio(this);
}
void ReplayManager::play(ReplayManager *this)
{
  Sim *v2; // ebx
  float v3; // xmm0_4
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v4; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v5; // edi
  int v6[3]; // [esp+10h] [ebp-Ch] BYREF

  v6[0] = 0;
  v6[1] = 1065353216;
  v2 = this->sim;
  v3 = this->slowMoLevel;
  this->status = eReplayPlay;
  this->timeMult = 1.0;
  *(float *)&v6[2] = v3;
  v4 = v2->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v4 != v2->evOnReplayStatusChanged.handlers._Mylast )
  {
    v5 = &v4->second._Impl;
    do
    {
      if ( !*v5 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x64CB5F);
      }
      (*v5)->_Do_call(*v5, (const OnReplayStatusChanged *)v6);
      ++v4;
      v5 += 8;
    }
    while ( v4 != v2->evOnReplayStatusChanged.handlers._Mylast );
  }
  ReplayManager::updateReplayAudio(this);
}
void ReplayManager::previousLap(ReplayManager *this)
{
  Sim *v2; // ecx
  unsigned int v3; // eax
  int v4; // edx
  unsigned int *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  std::vector<unsigned int> lapFrames; // [esp+14h] [ebp-18h] BYREF
  int v10; // [esp+28h] [ebp-4h]

  if ( this->recorders._Myfirst != this->recorders._Mylast )
  {
    lapFrames._Myfirst = 0;
    lapFrames._Mylast = 0;
    lapFrames._Myend = 0;
    v2 = this->sim;
    v10 = 0;
    v3 = Sim::getFocusedCarIndex(v2);
    ReplayRecorder::fetchLapFrames(this->recorders._Myfirst[v3], &lapFrames);
    v4 = 0;
    v5 = lapFrames._Myfirst;
    v6 = 0;
    v7 = lapFrames._Mylast - lapFrames._Myfirst;
    if ( v7 )
    {
      do
      {
        v8 = lapFrames._Myfirst[v6];
        if ( this->currentFrame > v8 )
          v4 = v8 - 60;
        ++v6;
      }
      while ( v6 < v7 );
      if ( v4 )
        this->currentFrame = v4;
    }
    v10 = -1;
    if ( v5 )
    {
      std::_Container_base0::_Orphan_all(&lapFrames);
      operator delete(lapFrames._Myfirst);
    }
  }
}
void ReplayManager::resetReplay(ReplayManager *this)
{
  std::map<CarAvatar *,std::vector<ReplayLap>> *v2; // esi
  int v3; // edi
  ReplayRecorder **v4; // esi
  unsigned int v5; // ebx
  std::vector<LeaderboardEntry> *v6; // edi
  std::vector<LeaderboardEntry> *v7; // esi

  v2 = &this->replayLaps;
  std::_Tree<std::_Tmap_traits<CarAvatar *,std::vector<ReplayLap>,std::less<CarAvatar *>,std::allocator<std::pair<CarAvatar * const,std::vector<ReplayLap>>>,0>>::_Erase(
    &this->replayLaps,
    this->replayLaps._Myhead->_Parent);
  v3 = 0;
  v2->_Myhead->_Parent = v2->_Myhead;
  v2->_Myhead->_Left = v2->_Myhead;
  v2->_Myhead->_Right = v2->_Myhead;
  v2->_Mysize = 0;
  v4 = this->recorders._Myfirst;
  v5 = (unsigned int)((char *)this->recorders._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > this->recorders._Mylast )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      ReplayRecorder::clearFrames(*v4);
      ++v3;
      ++v4;
    }
    while ( v3 != v5 );
  }
  this->recordedFrames = 0;
  this->playCounter = 0.0;
  this->currentRecordingIndex = 0;
  std::_Container_base0::_Orphan_all(&replayLeaderboards);
  v6 = replayLeaderboards._Mylast;
  v7 = replayLeaderboards._Myfirst;
  if ( replayLeaderboards._Myfirst == replayLeaderboards._Mylast )
  {
    replayLeaderboards._Mylast = replayLeaderboards._Myfirst;
  }
  else
  {
    do
    {
      if ( v7->_Myfirst )
      {
        std::_Container_base0::_Orphan_all(v7);
        operator delete(v7->_Myfirst);
        v7->_Myfirst = 0;
        v7->_Mylast = 0;
        v7->_Myend = 0;
      }
      ++v7;
    }
    while ( v7 != v6 );
    replayLeaderboards._Mylast = replayLeaderboards._Myfirst;
  }
}
void __userpurge ReplayManager::rewind(ReplayManager *this@<ecx>, int speed, __int64 pression)
{
  int v4; // eax
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  int v8; // xmm0_4
  Event<OnGearRequestEvent> *v9; // ecx
  OnGearRequestEvent message; // [esp+4h] [ebp-Ch] BYREF
  int v11; // [esp+Ch] [ebp-4h]

  if ( (_BYTE)pression )
  {
    v4 = this->currentFrame - speed;
    if ( v4 <= 1 )
    {
      if ( v4 < 0 )
        v4 = 0;
      this->currentFrame = v4;
    }
    else
    {
      this->currentFrame = 1;
    }
  }
  else
  {
    if ( this->timeMult > -1.0 )
      this->timeMult = -1.0;
    v5 = this->timeMult;
    this->status = eReplayRewind;
    v6 = v5 - (float)speed;
    v7 = 0.0;
    if ( v6 <= 0.0 )
    {
      v7 = FLOAT_N20_0;
      if ( v6 >= -20.0 )
        v7 = v6;
    }
    this->timeMult = v7;
    LODWORD(pression) = (int)v7;
    Event<std::wstring>::trigger(
      (Event<OnGearRequestEvent> *)&this->evOnReplayRewind,
      (const OnGearRequestEvent *)&pression);
    v8 = LODWORD(this->timeMult);
    v9 = (Event<OnGearRequestEvent> *)&this->sim->evOnReplayStatusChanged;
    message.request = this->status;
    message.nextGear = v8;
    v11 = 1065353216;
    Event<std::wstring>::trigger(v9, &message);
    LODWORD(pression) = 0;
    Event<std::wstring>::trigger(
      (Event<OnGearRequestEvent> *)&this->evOnReplayRewind,
      (const OnGearRequestEvent *)&pression);
    ReplayManager::updateReplayAudio(this);
  }
}
char ReplayManager::save(ReplayManager *this, std::wstring fn, eSaveReplayDir saveDir)
{
  ReplayManager *v3; // ebx
  char v4; // bl
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  WeatherManager *v13; // eax
  const std::wstring *v14; // eax
  int *v15; // eax
  bool v16; // cc
  unsigned int v17; // ebp
  int v18; // ebx
  unsigned int v19; // edi
  int v20; // esi
  int v21; // edi
  float v22; // ebp
  std::wstring *v23; // eax
  int v24; // ebx
  _DWORD *v25; // esi
  ReplayRecorder *v26; // edi
  int v27; // esi
  int v28; // ebx
  int v29; // ecx
  int v30; // edx
  int v31; // esi
  CarAvatar *const *v32; // eax
  unsigned int v33; // esi
  CarAvatar *const *v34; // eax
  CarAvatar *const *v35; // eax
  CarAvatar *const *v36; // eax
  std::vector<LeaderboardEntry> *v37; // edi
  std::vector<LeaderboardEntry> *i; // ebp
  SectorData *v39; // ebx
  const __m128i *v40; // esi
  __m128i v41; // xmm0
  _BYTE *v42; // esi
  ReplayManager *v43; // ebx
  std::pair<void *,std::function<void __cdecl(bool const &)> > *v44; // esi
  std::_Func_base<void,bool const &> **v45; // edi
  int v46; // ecx
  char message[9]; // [esp+14Dh] [ebp-26Dh] BYREF
  std::vector<SectorData> v49; // [esp+156h] [ebp-264h] BYREF
  ReplayManager *v50; // [esp+162h] [ebp-258h]
  int v51; // [esp+166h] [ebp-254h] BYREF
  float bestLap; // [esp+16Ah] [ebp-250h] BYREF
  int raceMode; // [esp+16Eh] [ebp-24Ch] BYREF
  int v54; // [esp+172h] [ebp-248h]
  int frameInformationSize; // [esp+176h] [ebp-244h] BYREF
  float totalTime; // [esp+17Ah] [ebp-240h] BYREF
  int guid; // [esp+17Eh] [ebp-23Ch] BYREF
  int trackObjectNumber; // [esp+182h] [ebp-238h] BYREF
  int cc; // [esp+186h] [ebp-234h] BYREF
  int laps; // [esp+18Ah] [ebp-230h] BYREF
  __m128i v61; // [esp+18Eh] [ebp-22Ch] BYREF
  std::vector<char> v62; // [esp+19Eh] [ebp-21Ch] BYREF
  std::vector<char> v63; // [esp+1AAh] [ebp-210h] BYREF
  __m128i v64; // [esp+1B6h] [ebp-204h] BYREF
  int v65; // [esp+1C6h] [ebp-1F4h] BYREF
  int v66; // [esp+1CAh] [ebp-1F0h] BYREF
  int v67; // [esp+1CEh] [ebp-1ECh] BYREF
  int v68; // [esp+1D2h] [ebp-1E8h] BYREF
  int frameLeaderboardSize; // [esp+1D6h] [ebp-1E4h] BYREF
  int version[2]; // [esp+1DAh] [ebp-1E0h] BYREF
  std::ofstream out; // [esp+1E2h] [ebp-1D8h] BYREF
  std::wstring currentSkin; // [esp+28Ah] [ebp-130h] BYREF
  std::wstring path; // [esp+2A2h] [ebp-118h] BYREF
  std::wstring _Left; // [esp+2BAh] [ebp-100h] BYREF
  std::wstring filename; // [esp+2D2h] [ebp-E8h] BYREF
  std::wstring last_weather_name; // [esp+2EAh] [ebp-D0h] BYREF
  std::wstring v77; // [esp+302h] [ebp-B8h] BYREF
  std::wstring v78; // [esp+31Ah] [ebp-A0h] BYREF
  std::wstring result; // [esp+332h] [ebp-88h] BYREF
  DriverInfo v80; // [esp+34Ah] [ebp-70h] BYREF
  int v81; // [esp+3B6h] [ebp-4h]

  v3 = this;
  v50 = this;
  v81 = 0;
  if ( Path::doesFilenameContainsIllegalChar(&fn) )
  {
    message[0] = 0;
    Event<std::wstring>::trigger(
      (Event<OnGearRequestEvent> *)&v3->evDidFinishedSavingReplay,
      (const OnGearRequestEvent *)message);
    v4 = 0;
  }
  else
  {
    if ( &v3->lastFilename != &fn )
      std::wstring::assign(&v3->lastFilename, &fn, 0, 0xFFFFFFFF);
    if ( saveDir == TEMP_DIR )
    {
      v5 = std::operator+<wchar_t>(&path, L"temp/", &fn);
      if ( &fn != v5 )
      {
        if ( fn._Myres >= 8 )
          operator delete(fn._Bx._Ptr);
        fn._Myres = 7;
        fn._Mysize = 0;
        fn._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&fn, v5);
      }
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
    }
    v6 = Path::getDocumentPath(&path);
    LOBYTE(v81) = 1;
    v7 = std::operator+<wchar_t>(&currentSkin, v6, L"/Assetto Corsa/replay");
    LOBYTE(v81) = 2;
    Path::createFolder(v7);
    if ( currentSkin._Myres >= 8 )
      operator delete(currentSkin._Bx._Ptr);
    currentSkin._Myres = 7;
    currentSkin._Mysize = 0;
    currentSkin._Bx._Buf[0] = 0;
    LOBYTE(v81) = 0;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    v8 = Path::getDocumentPath(&path);
    LOBYTE(v81) = 3;
    v9 = std::operator+<wchar_t>(&currentSkin, v8, L"/Assetto Corsa/replay/temp");
    LOBYTE(v81) = 4;
    Path::createFolder(v9);
    if ( currentSkin._Myres >= 8 )
      operator delete(currentSkin._Bx._Ptr);
    currentSkin._Myres = 7;
    currentSkin._Mysize = 0;
    currentSkin._Bx._Buf[0] = 0;
    LOBYTE(v81) = 0;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    v10 = Path::getDocumentPath(&result);
    LOBYTE(v81) = 5;
    v11 = std::operator+<wchar_t>(&v78, v10, L"/Assetto Corsa/replay/");
    LOBYTE(v81) = 6;
    std::operator+<wchar_t>(&filename, v11, &fn);
    if ( v78._Myres >= 8 )
      operator delete(v78._Bx._Ptr);
    v78._Myres = 7;
    v78._Mysize = 0;
    v78._Bx._Buf[0] = 0;
    LOBYTE(v81) = 9;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    v12 = &filename;
    if ( filename._Myres >= 8 )
      v12 = (std::wstring *)filename._Bx._Ptr;
    result._Mysize = 0;
    _printf("Saving replay: %S\n", v12->_Bx._Buf);
    std::ofstream::ofstream(&out, &filename, 34, 64, 1);
    LOBYTE(v81) = 10;
    version[0] = 16;
    std::ostream::write(&out, version, 4, 0);
    std::ostream::write(&out, &ReplayRecorder::recordIntervalMS, 8, 0);
    v13 = GameObject::getGameObject<WeatherManager>(v3->sim);
    WeatherManager::getLastWeatherName(v13, &last_weather_name);
    LOBYTE(v81) = 11;
    ksSaveString(&out, &last_weather_name);
    ksSaveString(&out, &v3->sim->track->name);
    v14 = TrackAvatar::getConfig(v3->sim->track, &path);
    LOBYTE(v81) = 12;
    ksSaveString(&out, v14);
    LOBYTE(v81) = 11;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    cc = v3->sim->cars._Mylast - v3->sim->cars._Myfirst;
    std::ostream::write(&out, &cc, 4, 0);
    LODWORD(totalTime) = &v3->currentRecordingIndex;
    std::ostream::write(&out, &v3->currentRecordingIndex, 4, 0);
    v15 = &v51;
    v16 = frameInformation._Mylast - frameInformation._Myfirst < v3->recordedFrames;
    v51 = frameInformation._Mylast - frameInformation._Myfirst;
    if ( !v16 )
      v15 = &v3->recordedFrames;
    frameInformationSize = *v15;
    std::ostream::write(&out, &frameInformationSize, 4, 0);
    trackObjectNumber = v3->sim->track->trackObjects._Mylast - v3->sim->track->trackObjects._Myfirst;
    std::ostream::write(&out, &trackObjectNumber, 4, 0);
    v17 = 0;
    if ( frameInformationSize )
    {
      v18 = 0;
      do
      {
        *(_DWORD *)&message[5] = *(_DWORD *)&frameInformation._Myfirst[v18].sunAngle.data_;
        std::vector<SectorData>::vector<SectorData>(
          &v49,
          (const std::vector<SectorData> *)&frameInformation._Myfirst[v18].trackObjects);
        LOBYTE(v81) = 13;
        std::ostream::write(&out, &message[5], 2, 0);
        std::ostream::write(&out, &message[7], 2, 0);
        v19 = 0;
        if ( trackObjectNumber )
        {
          v20 = 0;
          do
          {
            std::ostream::write(&out, &v49._Myfirst[v20], 12, 0);
            ++v19;
            ++v20;
          }
          while ( v19 < trackObjectNumber );
        }
        LOBYTE(v81) = 11;
        if ( v49._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&v49);
          operator delete(v49._Myfirst);
          v49._Myfirst = 0;
          v49._Mylast = 0;
          v49._Myend = 0;
        }
        ++v17;
        ++v18;
      }
      while ( v17 < frameInformationSize );
      v3 = v50;
    }
    v21 = 0;
    v54 = 0;
    if ( cc > 0 )
    {
      LODWORD(v22) = &v3->replayLaps;
      LODWORD(bestLap) = &v3->replayLaps;
      while ( 1 )
      {
        *(_DWORD *)&message[1] = Sim::getCar(v3->sim, v21);
        ksEncodeUtf8(&v62, (const std::wstring *)(*(_DWORD *)&message[1] + 176));
        v65 = v62._Mylast - v62._Myfirst;
        LOBYTE(v81) = 14;
        std::ostream::write(&out, &v65, 4, 0);
        std::ostream::write(&out, v62._Myfirst, v65, v65 >> 31);
        LOBYTE(v81) = 11;
        if ( v62._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&v62);
          operator delete(v62._Myfirst);
          v62._Myfirst = 0;
          v62._Mylast = 0;
          v62._Myend = 0;
        }
        DriverInfo::DriverInfo(&v80, (const DriverInfo *)(*(_DWORD *)&message[1] + 3888));
        LOBYTE(v81) = 15;
        ksEncodeUtf8(&v63, &v80.name);
        v66 = v63._Mylast - v63._Myfirst;
        LOBYTE(v81) = 16;
        std::ostream::write(&out, &v66, 4, 0);
        std::ostream::write(&out, v63._Myfirst, v66, v66 >> 31);
        LOBYTE(v81) = 15;
        if ( v63._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&v63);
          operator delete(v63._Myfirst);
          v63._Myfirst = 0;
          v63._Mylast = 0;
          v63._Myend = 0;
        }
        ksEncodeUtf8((std::vector<char> *)&v64, &v80.nationCode);
        v68 = v64.m128i_i32[1] - v64.m128i_i32[0];
        LOBYTE(v81) = 17;
        std::ostream::write(&out, &v68, 4, 0);
        std::ostream::write(&out, v64.m128i_i32[0], v68, v68 >> 31);
        LOBYTE(v81) = 15;
        if ( v64.m128i_i32[0] )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v64);
          operator delete(v64.m128i_i32[0]);
          v64.m128i_i64[0] = 0i64;
          v64.m128i_i32[2] = 0;
        }
        ksEncodeUtf8((std::vector<char> *)&v61, &v80.team);
        v67 = v61.m128i_i32[1] - v61.m128i_i32[0];
        LOBYTE(v81) = 18;
        std::ostream::write(&out, &v67, 4, 0);
        std::ostream::write(&out, v61.m128i_i32[0], v67, v67 >> 31);
        LOBYTE(v81) = 15;
        if ( v61.m128i_i32[0] )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v61);
          operator delete(v61.m128i_i32[0]);
          v61.m128i_i64[0] = 0i64;
          v61.m128i_i32[2] = 0;
        }
        _Left._Myres = 7;
        _Left._Mysize = 0;
        _Left._Bx._Buf[0] = 0;
        std::wstring::assign(&_Left, L"content/cars/", 0xDu);
        LOBYTE(v81) = 19;
        v23 = std::operator+<wchar_t>(&v77, &_Left, (const std::wstring *)(*(_DWORD *)&message[1] + 176));
        LOBYTE(v81) = 20;
        std::operator+<wchar_t>(&path, v23, L"/skins/");
        if ( v77._Myres >= 8 )
          operator delete(v77._Bx._Ptr);
        v77._Myres = 7;
        v77._Mysize = 0;
        v77._Bx._Buf[0] = 0;
        LOBYTE(v81) = 23;
        if ( _Left._Myres >= 8 )
          operator delete(_Left._Bx._Ptr);
        _Left._Bx._Buf[0] = 0;
        _Left._Myres = 7;
        _Left._Mysize = 0;
        CarAvatar::getCurrentSkin(*(CarAvatar **)&message[1], &currentSkin);
        LOBYTE(v81) = 24;
        ksEncodeUtf8((std::vector<char> *)&message[5], &currentSkin);
        v51 = (int)v49._Myfirst - *(_DWORD *)&message[5];
        LOBYTE(v81) = 25;
        std::ostream::write(&out, &v51, 4, 0);
        std::ostream::write(&out, *(_DWORD *)&message[5], v51, v51 >> 31);
        LOBYTE(v81) = 24;
        if ( *(_DWORD *)&message[5] )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)&message[5]);
          operator delete(*(_DWORD *)&message[5]);
          *(_DWORD *)&message[5] = 0;
          v49._Myfirst = 0;
          v49._Mylast = 0;
        }
        v24 = *(_DWORD *)&message[1];
        v25 = *(_DWORD **)(*(_DWORD *)&message[1] + 40);
        if ( v25 != *(_DWORD **)(*(_DWORD *)&message[1] + 44) )
        {
          while ( 1 )
          {
            v26 = (ReplayRecorder *)__RTDynamicCast(
                                      *v25,
                                      0,
                                      &GameObject `RTTI Type Descriptor',
                                      &ReplayRecorder `RTTI Type Descriptor',
                                      0);
            if ( v26 )
              break;
            if ( ++v25 == *(_DWORD **)(v24 + 44) )
              goto LABEL_63;
          }
          v27 = v50->currentRecordingIndex;
          v28 = v50->recordedFrames;
          raceMode = v50->cutIn;
          laps = v50->cutOut;
          v29 = (v27 + raceMode) % v28;
          v30 = (v27 + laps) % v28;
          v31 = 0;
          do
          {
            ++v31;
            v29 = (v29 + 1) % v28;
          }
          while ( v29 != v30 );
          ReplayRecorder::save(v26, &out, raceMode, laps, v31, *(_DWORD *)LODWORD(totalTime));
          v22 = bestLap;
LABEL_63:
          v21 = v54;
        }
        v32 = std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](
                (std::map<CarAvatar *,std::vector<ReplayLap>> *)LODWORD(v22),
                (CarAvatar *const *)&message[1]);
        guid = (signed int)(*((_DWORD *)v32 + 1) - (unsigned int)*v32) >> 3;
        std::ostream::write(&out, &guid, 4, 0);
        v33 = 0;
        v34 = std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](
                (std::map<CarAvatar *,std::vector<ReplayLap>> *)LODWORD(v22),
                (CarAvatar *const *)&message[1]);
        if ( (signed int)(*((_DWORD *)v34 + 1) - (unsigned int)*v34) >> 3 )
        {
          do
          {
            v35 = std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](
                    (std::map<CarAvatar *,std::vector<ReplayLap>> *)LODWORD(v22),
                    (CarAvatar *const *)&message[1]);
            std::ostream::write(&out, (char *)*v35 + 8 * v33++, 8, 0);
            v36 = std::map<CarAvatar *,std::vector<ReplayLap>>::operator[](
                    (std::map<CarAvatar *,std::vector<ReplayLap>> *)LODWORD(v22),
                    (CarAvatar *const *)&message[1]);
          }
          while ( v33 < (signed int)(*((_DWORD *)v36 + 1) - (unsigned int)*v36) >> 3 );
        }
        if ( currentSkin._Myres >= 8 )
          operator delete(currentSkin._Bx._Ptr);
        currentSkin._Myres = 7;
        currentSkin._Mysize = 0;
        currentSkin._Bx._Buf[0] = 0;
        if ( path._Myres >= 8 )
          operator delete(path._Bx._Ptr);
        path._Myres = 7;
        path._Mysize = 0;
        path._Bx._Buf[0] = 0;
        LOBYTE(v81) = 11;
        SetupItemText::~SetupItemText(&v80);
        v54 = ++v21;
        if ( v21 >= cc )
          break;
        v3 = v50;
      }
    }
    frameLeaderboardSize = replayLeaderboards._Mylast - replayLeaderboards._Myfirst;
    std::ostream::write(&out, &frameLeaderboardSize, 4, 0);
    v37 = replayLeaderboards._Myfirst;
    for ( i = replayLeaderboards._Mylast; v37 != i; ++v37 )
    {
      std::vector<LeaderboardEntry>::vector<LeaderboardEntry>((std::vector<LeaderboardEntry> *)&message[5], v37);
      v39 = v49._Myfirst;
      v40 = *(const __m128i **)&message[5];
      LOBYTE(v81) = 26;
      if ( *(SectorData **)&message[5] != v49._Myfirst )
      {
        do
        {
          v41 = _mm_loadu_si128(v40 + 1);
          v64 = _mm_loadu_si128(v40);
          v61 = v41;
          guid = CarAvatar::getGuid((CarAvatar *)_mm_cvtsi128_si32(v64));
          std::ostream::write(&out, &guid, 4, 0);
          bestLap = *(double *)v61.m128i_i64;
          std::ostream::write(&out, &bestLap, 4, 0);
          raceMode = (unsigned __int8)_mm_cvtsi128_si32(_mm_srli_si128(_mm_loadu_si128(&v61), 12));
          std::ostream::write(&out, &raceMode, 4, 0);
          laps = _mm_cvtsi128_si32(_mm_srli_si128(_mm_loadu_si128(&v61), 8));
          std::ostream::write(&out, &laps, 4, 0);
          *(float *)v41.m128i_i32 = *(double *)&v64.m128i_i64[1];
          totalTime = *(float *)v41.m128i_i32;
          std::ostream::write(&out, &totalTime, 4, 0);
          v40 += 2;
        }
        while ( v40 != (const __m128i *)v39 );
        v40 = *(const __m128i **)&message[5];
      }
      LOBYTE(v81) = 11;
      if ( v40 )
      {
        std::_Container_base0::_Orphan_all((std::_Container_base0 *)&message[5]);
        operator delete(*(_DWORD *)&message[5]);
        *(_DWORD *)&message[5] = 0;
        v49._Myfirst = 0;
        v49._Mylast = 0;
      }
    }
    v42 = &out.gap0[4];
    if ( *(_DWORD *)&out._Filebuffer[4] )
    {
      if ( !std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]) )
        v42 = 0;
      if ( _fclose(*(FILE **)&out._Filebuffer[4]) )
        v42 = 0;
    }
    else
    {
      v42 = 0;
    }
    out._Filebuffer[0] = 0;
    out.gap0[73] = 0;
    std::streambuf::_Init(&out.gap0[4]);
    *(_DWORD *)&out._Filebuffer[4] = 0;
    *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&out.gap0[68] = 0;
    if ( !v42 )
      std::ios::setstate((char *)&out + *(_DWORD *)(*(_DWORD *)out.gap0 + 4), 2, 0);
    v43 = v50;
    message[0] = 1;
    v44 = v50->evDidFinishedSavingReplay.handlers._Myfirst;
    if ( v44 != v50->evDidFinishedSavingReplay.handlers._Mylast )
    {
      v45 = &v44->second._Impl;
      do
      {
        if ( !*v45 )
        {
          std::_Xbad_function_call();
          JUMPOUT(0x64E2F7);
        }
        (*v45)->_Do_call(*v45, (const bool *)message);
        ++v44;
        v45 += 8;
      }
      while ( v44 != v43->evDidFinishedSavingReplay.handlers._Mylast );
    }
    v4 = 1;
    if ( last_weather_name._Myres >= 8 )
      operator delete(last_weather_name._Bx._Ptr);
    last_weather_name._Myres = 7;
    last_weather_name._Bx._Buf[0] = 0;
    last_weather_name._Mysize = 0;
    LOBYTE(v81) = 9;
    *(_DWORD *)&out.gap0[*(_DWORD *)(*(_DWORD *)out.gap0 + 4)] = &std::ofstream::`vftable';
    *(int *)((char *)&version[1] + *(_DWORD *)(*(_DWORD *)out.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)out.gap0 + 4) - 96;
    v46 = *(_DWORD *)&out._Filebuffer[4];
    *(_DWORD *)&out.gap0[4] = &std::filebuf::`vftable';
    if ( *(_DWORD *)&out._Filebuffer[4] && **(std::ofstream ***)&out.gap0[16] == (std::ofstream *)&out.gap0[72] )
    {
      std::streambuf::setg(&out.gap0[4], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[64]);
      v46 = *(_DWORD *)&out._Filebuffer[4];
    }
    if ( out._Filebuffer[0] )
    {
      if ( v46 )
      {
        std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]);
        _fclose(*(FILE **)&out._Filebuffer[4]);
      }
      out._Filebuffer[0] = 0;
      out.gap0[73] = 0;
      std::streambuf::_Init(&out.gap0[4]);
      *(_DWORD *)&out._Filebuffer[4] = 0;
      *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
      *(_DWORD *)&out.gap0[68] = 0;
    }
    std::streambuf::~streambuf<char,std::char_traits<char>>(&out.gap0[4]);
    std::ostream::~ostream<char,std::char_traits<char>>(&out.gap0[8]);
    std::ios::~ios<char,std::char_traits<char>>(&out.gap58[8]);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
  }
  if ( fn._Myres >= 8 )
    operator delete(fn._Bx._Ptr);
  return v4;
}
void ReplayManager::setCurrentFrame(ReplayManager *this, int frame)
{
  this->currentFrame = 0;
}
double ReplayManager::setCutInPerc(ReplayManager *this, float aPerc)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  int v5; // eax
  float v6; // xmm1_4

  v2 = aPerc;
  v3 = FLOAT_1_0;
  if ( aPerc > 1.0 || (v3 = 0.0, aPerc < 0.0) )
    v2 = v3;
  v5 = (int)(float)((float)(this->recordedFrames - 1) * v2);
  this->cutIn = v5;
  if ( this->currentFrame < v5 )
    this->currentFrame = v5;
  ReplayManager::updateReplayRecorders(this, this->currentFrame);
  v6 = (float)this->cutIn / (float)(this->recordedFrames - 2);
  if ( v6 > 1.0 )
    return 1.0;
  if ( v6 >= 0.0 )
    return v6;
  return 0.0;
}
double ReplayManager::setCutOutPerc(ReplayManager *this, float aPerc)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  int v5; // eax
  float v6; // xmm1_4

  v2 = aPerc;
  v3 = FLOAT_1_0;
  if ( aPerc > 1.0 || (v3 = 0.0, aPerc < 0.0) )
    v2 = v3;
  v5 = (int)(float)((float)(this->recordedFrames - 1) * v2);
  this->cutOut = v5;
  if ( this->currentFrame >= v5 )
    this->currentFrame = v5;
  ReplayManager::updateReplayRecorders(this, this->currentFrame);
  v6 = (float)this->cutOut / (float)(this->recordedFrames - 2);
  if ( v6 > 1.0 )
    return 1.0;
  if ( v6 >= 0.0 )
    return v6;
  return 0.0;
}
void ReplayManager::setNormalizedPosition(ReplayManager *this, float percentage)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  Sim *v5; // ebp
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v9; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v10; // edi
  std::pair<void *,std::function<void __cdecl(int const &)> > *v11; // esi
  std::_Func_base<void,int const &> **i; // edi
  int v13[3]; // [esp+0h] [ebp-Ch] BYREF

  v2 = percentage;
  v3 = FLOAT_1_0;
  if ( percentage > 1.0 || (v3 = 0.0, percentage < 0.0) )
    v2 = v3;
  v5 = this->sim;
  v6 = (float)this->recordedFrames;
  v13[0] = 9;
  v7 = (int)(float)(v6 * v2);
  v13[1] = LODWORD(this->timeMult);
  v8 = this->slowMoLevel;
  this->currentFrame = v7;
  *(float *)&v13[2] = v8;
  v9 = v5->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v9 != v5->evOnReplayStatusChanged.handlers._Mylast )
  {
    v10 = &v9->second._Impl;
    while ( *v10 )
    {
      (*v10)->_Do_call(*v10, (const OnReplayStatusChanged *)v13);
      ++v9;
      v10 += 8;
      if ( v9 == v5->evOnReplayStatusChanged.handlers._Mylast )
        goto LABEL_8;
    }
LABEL_13:
    std::_Xbad_function_call();
    JUMPOUT(0x64E55E);
  }
LABEL_8:
  v11 = this->evOnReplayRewind.handlers._Myfirst;
  percentage = 0.0;
  if ( v11 != this->evOnReplayRewind.handlers._Mylast )
  {
    for ( i = &v11->second._Impl; *i; i += 8 )
    {
      (*i)->_Do_call(*i, (const int *)&percentage);
      if ( ++v11 == this->evOnReplayRewind.handlers._Mylast )
        return;
    }
    goto LABEL_13;
  }
}
void __usercall ReplayManager::shutdown(ReplayManager *this@<ecx>, const std::wstring *a2@<esi>)
{
  _BYTE v3[28]; // [esp-18h] [ebp-58h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<enum SessionType const ,ReplayAutosave> > > > result; // [esp+14h] [ebp-2Ch] BYREF
  std::wstring fileName; // [esp+18h] [ebp-28h] BYREF
  int v6; // [esp+3Ch] [ebp-4h]

  if ( !this->hasLoadedReplay )
  {
    if ( this->autoSaveEnabled )
    {
      if ( this->recordedFrames >= this->minFrames )
      {
        std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::find(
          (std::_Tree<std::_Tmap_traits<enum DWRITE_RENDERING_MODE,IDWriteRenderingParams *,std::less<enum DWRITE_RENDERING_MODE>,std::allocator<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *> >,0> > *)&this->autoSaveData,
          (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *> > > > *)&result,
          (const DWRITE_RENDERING_MODE *)&this->currentSessionType);
        a2 = (const std::wstring *)result._Ptr;
        if ( result._Ptr != this->autoSaveData._Myhead )
        {
          if ( result._Ptr->_Myval.second.size )
          {
            std::wstring::wstring((std::wstring *)&v3[4], &result._Ptr->_Myval.second.shortName);
            ReplayManager::getReplayFileName(this, &fileName, *(std::wstring *)&v3[4]);
            *(_DWORD *)&v3[24] = a2->_Myres;
            ++a2;
            v6 = 0;
            std::wstring::wstring((std::wstring *)v3, a2);
            ReplayManager::clearSaved(this, *(std::wstring *)v3, *(int *)&v3[24]);
            *(_DWORD *)&v3[24] = 0;
            std::wstring::wstring((std::wstring *)v3, &fileName);
            ReplayManager::save(this, *(std::wstring *)v3, *(eSaveReplayDir *)&v3[24]);
            v6 = -1;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&fileName);
          }
        }
      }
    }
    else
    {
      *(_DWORD *)&v3[24] = 1;
      std::wstring::wstring((std::wstring *)v3, L"cr");
      ReplayManager::save(this, *(std::wstring *)v3, *(eSaveReplayDir *)&v3[24]);
    }
  }
  AudioEngine::setVolume(this->sim->game->audioEngine, (int)a2, 0.0);
  AudioEngine::stop(this->sim->game->audioEngine);
}
void ReplayManager::slowMotion(ReplayManager *this, float value)
{
  bool v3; // zf
  Sim *v4; // ebp
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v5; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v6; // edi
  int v7[3]; // [esp+0h] [ebp-Ch] BYREF

  v3 = this->status == eReplaySlowMotion;
  this->slowMoLevel = value;
  if ( v3 )
    this->timeMult = 1.0 / value;
  else
    this->slowMoCounter = 0.0;
  v4 = this->sim;
  this->status = eReplaySlowMotion;
  v7[0] = 5;
  v7[1] = 1065353216;
  *(float *)&v7[2] = value;
  v5 = v4->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v5 != v4->evOnReplayStatusChanged.handlers._Mylast )
  {
    v6 = &v5->second._Impl;
    do
    {
      if ( !*v6 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x64E762);
      }
      (*v6)->_Do_call(*v6, (const OnReplayStatusChanged *)v7);
      ++v5;
      v6 += 8;
    }
    while ( v5 != v4->evOnReplayStatusChanged.handlers._Mylast );
  }
  ReplayManager::updateReplayAudio(this);
}
void __userpurge ReplayManager::startReplayMode(ReplayManager *this@<ecx>, int a2@<ebp>, unsigned int rewindSeconds)
{
  Sim *v4; // ebx
  GameObject **v5; // esi
  _DWORD *v6; // eax
  CameraMode v7; // ecx
  __int32 v8; // ecx
  __int32 v9; // ecx
  int v10; // ecx
  double v11; // xmm1_8
  Sim *v12; // eax
  std::pair<void *,std::function<void __cdecl(bool const &)> > *v13; // esi
  std::_Func_base<void,bool const &> **v14; // ebx
  CarAvatar *v15; // eax
  ICarControlsProvider *v16; // eax
  ICarControlsProvider_vtbl *v17; // edx
  Sim *v18; // ebp
  float v19; // xmm0_4
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v20; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v21; // ebx
  int v23; // [esp+4h] [ebp-1Ch] BYREF
  __int128 v24; // [esp+8h] [ebp-18h] BYREF
  int v25; // [esp+18h] [ebp-8h]

  v4 = this->sim;
  this->isActive = 1;
  v5 = v4->gameObjects._Myfirst;
  if ( v5 != v4->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v6 = (_DWORD *)__RTDynamicCast(
                       *v5,
                       0,
                       &GameObject `RTTI Type Descriptor',
                       &ACCameraManager `RTTI Type Descriptor',
                       0);
      if ( v6 )
        break;
      if ( ++v5 == v4->gameObjects._Mylast )
        goto LABEL_11;
    }
    v7 = v6[42];
    this->oldCameraMode = v7;
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
          this->oldCameraTrackSet = *(_DWORD *)(v6[22] + 92);
      }
      else
      {
        this->oldDrivableMode = *(_DWORD *)(v6[26] + 52);
      }
    }
    else
    {
      this->oldCameraCar = *(_DWORD *)(v6[25] + 60);
    }
  }
LABEL_11:
  v10 = this->recordedFrames;
  this->cutIn = 0;
  this->currentFrame = 0;
  this->cutOut = v10 - 1;
  v11 = (double)rewindSeconds * ReplayRecorder::recordIntervalMS;
  if ( (double)v10 > v11 )
    this->currentFrame = (int)((double)v10 - v11);
  v12 = this->sim;
  this->replayMode = 1;
  AudioEngine::start(v12->game->audioEngine);
  ksgui::Control::setVisible(this->replayInterface, 1);
  ReplayInterface::resetCuts(this->replayInterface);
  v13 = this->evOnReplayStarted.handlers._Myfirst;
  LOBYTE(rewindSeconds) = 1;
  if ( v13 != this->evOnReplayStarted.handlers._Mylast )
  {
    v14 = &v13->second._Impl;
    while ( *v14 )
    {
      (*v14)->_Do_call(*v14, (const bool *)&rewindSeconds);
      ++v13;
      v14 += 8;
      if ( v13 == this->evOnReplayStarted.handlers._Mylast )
        goto LABEL_17;
    }
    std::_Xbad_function_call();
$LN166:
    std::_Xbad_function_call();
    JUMPOUT(0x64E985);
  }
LABEL_17:
  v15 = Sim::getCar(this->sim, 0);
  if ( v15 )
  {
    v16 = CarAvatar::getControlsProvider(v15);
    if ( v16 )
    {
      v17 = v16->__vftable;
      v25 = 0;
      v24 = 0i64;
      v17->setVibrations(v16, (const VibrationDef *)&v24);
    }
  }
  Sim::setFocusedCarIndex(this->sim, 0);
  v18 = this->sim;
  *(float *)&v24 = this->timeMult;
  v19 = this->slowMoLevel;
  this->status = eReplayModeEnter;
  v23 = 6;
  *((float *)&v24 + 1) = v19;
  v20 = v18->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v20 != v18->evOnReplayStatusChanged.handlers._Mylast )
  {
    v21 = &v20->second._Impl;
    while ( *v21 )
    {
      ((void (*)(std::_Func_base<void,OnReplayStatusChanged const &> *, int *, int))(*v21)->_Do_call)(
        *v21,
        &v23,
        a2);
      ++v20;
      v21 += 8;
      if ( v20 == v18->evOnReplayStatusChanged.handlers._Mylast )
        goto LABEL_24;
    }
    goto $LN166;
  }
LABEL_24:
  ReplayManager::play(this);
  ACCameraManager::setMode(this->sim->cameraManager, eTrack, 1, 0);
}
void __usercall ReplayManager::stop(ReplayManager *this@<ecx>, int a2@<ebp>)
{
  int v3; // eax
  std::pair<void *,std::function<void __cdecl(int const &)> > *v4; // esi
  std::_Func_base<void,int const &> **v5; // edi
  eReplayStatus v6; // eax
  Sim *v7; // ebp
  float v8; // xmm0_4
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v9; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v10; // edi
  int v12[4]; // [esp+Ch] [ebp-10h] BYREF

  v12[0] = 0;
  v3 = this->cutIn;
  this->timeMult = 0.0;
  this->currentFrame = v3;
  this->status = eReplayStop;
  v4 = this->evOnReplayRewind.handlers._Myfirst;
  if ( v4 != this->evOnReplayRewind.handlers._Mylast )
  {
    v5 = &v4->second._Impl;
    while ( *v5 )
    {
      (*v5)->_Do_call(*v5, v12);
      ++v4;
      v5 += 8;
      if ( v4 == this->evOnReplayRewind.handlers._Mylast )
        goto LABEL_5;
    }
    std::_Xbad_function_call();
$LN106_1:
    std::_Xbad_function_call();
    JUMPOUT(0x64EA4D);
  }
LABEL_5:
  v6 = this->status;
  v7 = this->sim;
  v12[1] = LODWORD(this->timeMult);
  v8 = this->slowMoLevel;
  v12[0] = v6;
  *(float *)&v12[2] = v8;
  v9 = v7->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v9 != v7->evOnReplayStatusChanged.handlers._Mylast )
  {
    v10 = &v9->second._Impl;
    while ( *v10 )
    {
      ((void (*)(std::_Func_base<void,OnReplayStatusChanged const &> *, int *, int))(*v10)->_Do_call)(
        *v10,
        v12,
        a2);
      ++v9;
      v10 += 8;
      if ( v9 == v7->evOnReplayStatusChanged.handlers._Mylast )
        goto LABEL_9;
    }
    goto $LN106_1;
  }
LABEL_9:
  ReplayManager::updateReplayAudio(this);
}
void ReplayManager::stopReplayMode(ReplayManager *this)
{
  Sim *v2; // ecx
  ACCameraManager *v3; // edi
  float v4; // xmm0_4
  Sim *v5; // ecx
  char message[9]; // [esp+7h] [ebp-Dh] BYREF
  float v7; // [esp+10h] [ebp-4h]

  if ( this->replayMode )
  {
    AudioEngine::start(this->sim->game->audioEngine);
    v2 = this->sim;
    this->isActive = 0;
    this->status = eReplayModeExit;
    this->replayMode = 0;
    this->timeMult = 1.0;
    v3 = GameObject::getGameObject<ACCameraManager>(v2);
    ACCameraManager::setMode(v3, eCockpit, 1, 0);
    ACCameraManager::setMode(v3, this->oldCameraMode, 1, 0);
    switch ( this->oldCameraMode )
    {
      case eCar:
        CameraCarManager::setCurrentCamera(v3->cameraCar, this->oldCameraCar);
        break;
      case eDrivable:
        v3->cameraDrivable->currentMode = this->oldDrivableMode;
        break;
      case eTrack:
        CameraTrack::setCurrentCameraSet(v3->cameraTrack, this->oldCameraTrackSet);
        break;
    }
    ksgui::Control::setVisible(this->replayInterface, 0);
    message[0] = 1;
    Event<std::wstring>::trigger(
      (Event<OnGearRequestEvent> *)&this->evOnReplayStopped,
      (const OnGearRequestEvent *)message);
    v4 = this->timeMult;
    v5 = this->sim;
    *(_DWORD *)&message[1] = this->status;
    *(float *)&message[5] = v4;
    v7 = this->slowMoLevel;
    Event<std::wstring>::trigger(
      (Event<OnGearRequestEvent> *)&v5->evOnReplayStatusChanged,
      (const OnGearRequestEvent *)&message[1]);
  }
}
void ReplayManager::updatePlayState(ReplayManager *this, float deltaT)
{
  float v2; // xmm6_4
  eReplayStatus v4; // eax
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  long double v10; // xmm1_8
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  int v14; // eax
  int v15; // eax
  long double v16; // xmm0_8
  eReplayStatus v17; // eax
  ReplayManager *v18; // [esp+0h] [ebp-4h] BYREF

  v18 = this;
  v2 = FLOAT_1_0;
  if ( this->slowMoLevel <= 0.0 )
    this->slowMoLevel = 1.0;
  v4 = this->status;
  if ( v4 == eSingleFrame )
  {
    if ( this->oldStatus == eSingleFrame )
      this->oldStatus = eReplayPause;
    else
      this->timeMult = 0.0;
  }
  if ( v4 == eReplayRewind )
  {
    v18 = 0;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnReplayRewind, (const OnGearRequestEvent *)&v18);
    v2 = FLOAT_1_0;
  }
  if ( this->status == eReplaySlowMotion )
  {
    v5 = this->slowMoCounter;
    if ( v5 >= 0.40000001 )
    {
      v7 = v2 / this->slowMoLevel;
    }
    else
    {
      v6 = (float)(v5 * 2.5) * (float)(v2 - this->slowMoLevel);
      this->slowMoCounter = v5 + deltaT;
      v7 = v2 / (float)(v2 - v6);
    }
    this->timeMult = v7;
  }
  v8 = this->timeMult;
  v9 = FLOAT_5_0;
  if ( v8 <= 5.0 )
  {
    v9 = FLOAT_N5_0;
    if ( v8 >= -5.0 )
      v9 = this->timeMult;
  }
  this->timeMult = v9;
  v10 = COERCE_FLOAT(LODWORD(v9) & _xmm) * (deltaT * 1000.0) + this->playCounter;
  this->playCounter = v10;
  if ( v10 >= ReplayRecorder::recordIntervalMS )
  {
    do
    {
      v11 = this->timeMult;
      if ( v11 <= 0.0 )
      {
        if ( v11 >= 0.0 )
          v12 = 0.0;
        else
          v12 = FLOAT_N1_0;
      }
      else
      {
        v12 = v2;
      }
      v13 = (this->currentFrame + (int)v12) % this->recordedFrames;
      v14 = this->cutIn;
      this->currentFrame = v13;
      if ( v13 <= v14 )
      {
        this->currentFrame = v14;
        ReplayManager::pause(this);
      }
      v15 = this->cutOut;
      if ( this->currentFrame >= v15 )
      {
        this->currentFrame = v15 - 1;
        ReplayManager::pause(this);
      }
      v16 = this->playCounter - ReplayRecorder::recordIntervalMS;
      v2 = FLOAT_1_0;
      this->playCounter = v16;
    }
    while ( v16 >= ReplayRecorder::recordIntervalMS );
  }
  ReplayManager::updateReplayRecorders(this, this->currentFrame);
  v17 = this->status;
  if ( v17 != eSingleFrame )
    this->oldStatus = v17;
}
void ReplayManager::updateReplayAudio(ReplayManager *this)
{
  float v1; // xmm0_4
  AudioEngine *v2; // ecx
  float v3; // xmm0_4

  if ( this->status == eReplaySlowMotion )
  {
    v1 = this->slowMoLevel;
    v2 = this->sim->game->audioEngine;
    if ( v1 > 2.0 )
    {
      AudioEngine::stop(v2);
      return;
    }
LABEL_10:
    AudioEngine::start(v2);
    return;
  }
  v3 = this->timeMult;
  if ( v3 < 0.5 || v3 > 2.0 )
  {
    AudioEngine::stop(this->sim->game->audioEngine);
    return;
  }
  if ( v3 >= 0.5 && v3 <= 2.0 )
  {
    v2 = this->sim->game->audioEngine;
    goto LABEL_10;
  }
}
void ReplayManager::updateReplayRecorders(ReplayManager *this, int aFrame)
{
  FrameInformation *v3; // esi
  int v4; // ebx
  int v5; // edi
  float blend; // xmm1_4
  int v7; // eax
  int v8; // ebx
  CompressedTransform *v9; // esi
  int v10; // ecx
  CompressedTransform *v11; // esi
  unsigned int v12; // ecx
  CompressedTransform *v13; // esi
  ReplayRecorder **v14; // esi
  unsigned int v15; // ecx
  ReplayRecorder *v16; // edi
  ICarPhysicsStateProvider_vtbl *v17; // edx
  CarAvatar *v18; // ebx
  mat44f v19; // [esp-3Ch] [ebp-158h]
  vec3f v20; // [esp-14h] [ebp-130h]
  vec3f v21; // [esp-14h] [ebp-130h]
  vec3f v22; // [esp-8h] [ebp-124h]
  vec3f v23; // [esp-8h] [ebp-124h]
  unsigned int v24; // [esp+1Ch] [ebp-100h]
  int v25; // [esp+1Ch] [ebp-100h]
  float v26; // [esp+20h] [ebp-FCh]
  int v27; // [esp+24h] [ebp-F8h]
  unsigned int v28; // [esp+24h] [ebp-F8h]
  int v29; // [esp+28h] [ebp-F4h]
  __int64 trasl1; // [esp+2Ch] [ebp-F0h]
  __int64 euler2; // [esp+38h] [ebp-E4h]
  __int64 trasl2; // [esp+44h] [ebp-D8h]
  __int64 euler1; // [esp+50h] [ebp-CCh]
  mat44f finalMath; // [esp+5Ch] [ebp-C0h] BYREF
  mat44f mat1; // [esp+9Ch] [ebp-80h] BYREF
  mat44f mat2; // [esp+DCh] [ebp-40h] BYREF

  v3 = frameInformation._Myfirst;
  v4 = (this->currentFrame + this->currentRecordingIndex) % this->recordedFrames;
  v24 = 0;
  v29 = v4;
  v5 = v4;
  blend = (float)this->playCounter / (float)ReplayRecorder::recordIntervalMS;
  v26 = blend;
  if ( frameInformation._Myfirst[v4].trackObjects._Mylast - frameInformation._Myfirst[v4].trackObjects._Myfirst )
  {
    v7 = v4 - 1;
    v8 = 0;
    v27 = v7;
    do
    {
      v9 = &v3[v5].trackObjects._Myfirst[v8];
      HIDWORD(euler1) = `half_float::detail::half2float_impl'::`2'::exponent_table[v9->euler[1].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v9->euler[1].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v9->euler[1].data_ >> 10]];
      LODWORD(euler1) = `half_float::detail::half2float_impl'::`2'::exponent_table[v9->euler[0].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v9->euler[0].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v9->euler[0].data_ >> 10]];
      HIDWORD(trasl1) = `half_float::detail::half2float_impl'::`2'::exponent_table[v9->translation[1].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v9->translation[1].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v9->translation[1].data_ >> 10]];
      LODWORD(trasl1) = `half_float::detail::half2float_impl'::`2'::exponent_table[v9->translation[0].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v9->translation[0].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v9->translation[0].data_ >> 10]];
      *(_QWORD *)&v22.x = trasl1;
      LODWORD(v22.z) = `half_float::detail::half2float_impl'::`2'::exponent_table[v9->translation[2].data_ >> 10]
                     + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v9->translation[2].data_ & 0x3FF)
                                                                                + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v9->translation[2].data_ >> 10]];
      *(_QWORD *)&v20.x = euler1;
      LODWORD(v20.z) = `half_float::detail::half2float_impl'::`2'::exponent_table[v9->euler[2].data_ >> 10]
                     + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v9->euler[2].data_ & 0x3FF)
                                                                                + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v9->euler[2].data_ >> 10]];
      mat44f::createFromEulerSafe(&mat1, v20, v22);
      v10 = 0;
      if ( v27 >= 0 )
        v10 = v27;
      v11 = frameInformation._Myfirst[v10].trackObjects._Myfirst;
      v12 = v11[v8].euler[2].data_;
      v13 = &v11[v8];
      HIDWORD(euler2) = `half_float::detail::half2float_impl'::`2'::exponent_table[v13->euler[1].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v13->euler[1].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v13->euler[1].data_ >> 10]];
      LODWORD(euler2) = `half_float::detail::half2float_impl'::`2'::exponent_table[v13->euler[0].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v13->euler[0].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v13->euler[0].data_ >> 10]];
      HIDWORD(trasl2) = `half_float::detail::half2float_impl'::`2'::exponent_table[v13->translation[1].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v13->translation[1].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v13->translation[1].data_ >> 10]];
      LODWORD(trasl2) = `half_float::detail::half2float_impl'::`2'::exponent_table[v13->translation[0].data_ >> 10]
                      + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v13->translation[0].data_ & 0x3FF)
                                                                                 + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v13->translation[0].data_ >> 10]];
      *(_QWORD *)&v23.x = trasl2;
      LODWORD(v23.z) = `half_float::detail::half2float_impl'::`2'::exponent_table[v13->translation[2].data_ >> 10]
                     + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v13->translation[2].data_ & 0x3FF)
                                                                                + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v13->translation[2].data_ >> 10]];
      *(_QWORD *)&v21.x = euler2;
      LODWORD(v21.z) = `half_float::detail::half2float_impl'::`2'::exponent_table[v12 >> 10]
                     + `half_float::detail::half2float_impl'::`2'::mantissa_table[(v12 & 0x3FF)
                                                                                + (unsigned __int16)`half_float::detail::half2float_impl'::`2'::offset_table[v12 >> 10]];
      mat44f::createFromEulerSafe(&mat2, v21, v23);
      lerp(&finalMath, &mat2, &mat1, blend);
      *(__m128i *)&v19.M11 = _mm_loadu_si128((const __m128i *)&finalMath);
      *(__m128i *)&v19.M21 = _mm_loadu_si128((const __m128i *)&finalMath.M21);
      *(__m128i *)&v19.M31 = _mm_loadu_si128((const __m128i *)&finalMath.M31);
      *(__m128i *)&v19.M41 = _mm_loadu_si128((const __m128i *)&finalMath.M41);
      TrackObject::setMatrix(this->sim->track->trackObjects._Myfirst[v24++], v19);
      ++v8;
      v3 = frameInformation._Myfirst;
    }
    while ( v24 < frameInformation._Myfirst[v5].trackObjects._Mylast
                - frameInformation._Myfirst[v5].trackObjects._Myfirst );
    v4 = v29;
  }
  v14 = this->recorders._Myfirst;
  v25 = 0;
  v15 = (unsigned int)((char *)this->recorders._Mylast - (char *)v14 + 3) >> 2;
  if ( v14 > this->recorders._Mylast )
    v15 = 0;
  v28 = v15;
  if ( v15 )
  {
    do
    {
      v16 = *v14;
      if ( this->status == eReplayRewind )
      {
        v16->isRewinding = 1;
        v16->frameBlend = 1.0 - blend;
      }
      else
      {
        v16->isRewinding = 0;
        v16->frameBlend = blend;
      }
      if ( this->currentFrame == this->recordedFrames - 1 )
        v16->frameBlend = 0.0;
      v17 = v16->ICarPhysicsStateProvider::__vftable;
      v16->playingPos = v4;
      v18 = v16->avatar;
      v17->getPhysicsState(&v16->ICarPhysicsStateProvider, &v18->physicsState);
      v16->getWingState(&v16->ICarPhysicsStateProvider, &v18->wingsStatus);
      CarAvatar::makeBodyMatrix(v18, (int)v16, (int)v14++, &v18->physicsState.worldMatrix, &v18->bodyMatrix);
      blend = v26;
      v4 = v29;
      ++v25;
    }
    while ( v25 != v28 );
  }
}
