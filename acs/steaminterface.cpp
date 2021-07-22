#include "steaminterface.h"
void SteamInterface::SteamInterface(SteamInterface *this, Sim *aSim)
{
  std::_Tree_node<std::pair<std::wstring const ,Achievement>,void *> *v3; // eax
  Sim *v4; // edi
  GameObject **v5; // esi
  GameMode *v6; // eax
  Event<SessionInfo> *v7; // ecx
  Event<float> *v8; // ecx
  CarTrackComb *v9; // eax
  CarTrackComb *v10; // eax
  CarTrackComb *v11; // eax
  CarTrackComb *v12; // eax
  CarTrackComb *v13; // esi
  CarTrackComb *v14; // edi
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  Console *v18; // eax
  Sim *v19; // ecx
  void (***v20)(_DWORD); // eax
  _BYTE secondsStandard[80]; // [esp-48h] [ebp-210h] BYREF
  int v22; // [esp+8h] [ebp-1C0h]
  int v23; // [esp+Ch] [ebp-1BCh]
  int v24; // [esp+10h] [ebp-1B8h]
  _BYTE *v25; // [esp+28h] [ebp-1A0h]
  _BYTE *v26; // [esp+2Ch] [ebp-19Ch]
  _BYTE *v27; // [esp+30h] [ebp-198h]
  SteamInterface *v28; // [esp+34h] [ebp-194h]
  std::wstring key; // [esp+38h] [ebp-190h] BYREF
  std::wstring section; // [esp+50h] [ebp-178h] BYREF
  std::wstring name; // [esp+68h] [ebp-160h] BYREF
  std::wstring carName; // [esp+80h] [ebp-148h] BYREF
  std::wstring trackName; // [esp+98h] [ebp-130h] BYREF
  std::wstring configTrack; // [esp+B0h] [ebp-118h] BYREF
  std::wstring v35; // [esp+C8h] [ebp-100h] BYREF
  CarTrackComb times; // [esp+E0h] [ebp-E8h] BYREF
  INIReaderDocuments raceINI; // [esp+130h] [ebp-98h] BYREF
  INIReaderDocuments ini; // [esp+174h] [ebp-54h] BYREF
  int v39; // [esp+1C4h] [ebp-4h]

  v28 = this;
  *(_DWORD *)&secondsStandard[76] = aSim->game;
  *(_DWORD *)&secondsStandard[72] = 7;
  *(_DWORD *)&secondsStandard[68] = 0;
  *(_WORD *)&secondsStandard[52] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[52], L"STEAM_INTERFACE", 0xFu);
  GameObject::GameObject(this, *(std::wstring *)&secondsStandard[52], *(Game **)&secondsStandard[76]);
  this->__vftable = (SteamInterface_vtbl *)&SteamInterface::`vftable';
  v39 = 0;
  this->evOnLeaderboardUpdated.handlers._Myfirst = 0;
  this->evOnLeaderboardUpdated.handlers._Mylast = 0;
  this->evOnLeaderboardUpdated.handlers._Myend = 0;
  this->userStatsCB.m_nCallbackFlags = 0;
  this->userStatsCB.m_iCallback = 0;
  this->userStatsCB.__vftable = (CCallback<SteamInterface,UserStatsReceived_t,0>_vtbl *)&CCallback<SteamInterface,UserStatsReceived_t,0>::`vftable';
  this->userStatsCB.m_pObj = 0;
  this->userStatsCB.m_Func = 0;
  if ( SteamInterface::onUserStatsReceived )
  {
    *(_DWORD *)&secondsStandard[76] = 1101;
    *(_DWORD *)&secondsStandard[72] = &this->userStatsCB;
    this->userStatsCB.m_pObj = this;
    this->userStatsCB.m_Func = (void (*)(SteamInterface *, UserStatsReceived_t *))SteamInterface::onUserStatsReceived;
    _SteamAPI_RegisterCallback(*(_DWORD *)&secondsStandard[72], *(_DWORD *)&secondsStandard[76]);
  }
  this->userStatStoredCB.m_nCallbackFlags = 0;
  this->userStatStoredCB.m_iCallback = 0;
  this->userStatStoredCB.__vftable = (CCallback<SteamInterface,UserStatsStored_t,0>_vtbl *)&CCallback<SteamInterface,UserStatsStored_t,0>::`vftable';
  this->userStatStoredCB.m_pObj = 0;
  this->userStatStoredCB.m_Func = 0;
  if ( SteamInterface::onUserStatsStored )
  {
    *(_DWORD *)&secondsStandard[76] = 1102;
    *(_DWORD *)&secondsStandard[72] = &this->userStatStoredCB;
    this->userStatStoredCB.m_pObj = this;
    this->userStatStoredCB.m_Func = SteamInterface::onUserStatsStored;
    _SteamAPI_RegisterCallback(*(_DWORD *)&secondsStandard[72], *(_DWORD *)&secondsStandard[76]);
  }
  this->gameMode = 0;
  this->sim = aSim;
  this->driftMode = 0;
  LOBYTE(v39) = 3;
  this->achievements._Myhead = 0;
  this->achievements._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,Achievement>>>::_Buyheadnode(&this->achievements);
  this->achievements._Myhead = v3;
  this->playerAvatar.kid = 0;
  this->playerAvatar.fileName._Myres = 7;
  this->playerAvatar.fileName._Mysize = 0;
  this->playerAvatar.fileName._Bx._Buf[0] = 0;
  this->carPosition.x = 0.0;
  this->carPosition.y = 0.0;
  this->carPosition.z = 0.0;
  LODWORD(this->currentLeaderboard) = 0;
  HIDWORD(this->currentLeaderboard) = 0;
  this->m_SteamCallResultCreateLeaderboard.m_nCallbackFlags = 0;
  this->m_SteamCallResultCreateLeaderboard.__vftable = (CCallResult<SteamInterface,LeaderboardFindResult_t>_vtbl *)&CCallResult<SteamInterface,LeaderboardFindResult_t>::`vftable';
  LODWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall) = 0;
  HIDWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall) = 0;
  this->m_SteamCallResultCreateLeaderboard.m_pObj = 0;
  this->m_SteamCallResultCreateLeaderboard.m_Func = 0;
  this->m_SteamCallResultCreateLeaderboard.m_iCallback = 1104;
  this->m_SteamCallResultUploadScore.m_nCallbackFlags = 0;
  this->m_SteamCallResultUploadScore.__vftable = (CCallResult<SteamInterface,LeaderboardScoreUploaded_t>_vtbl *)&CCallResult<SteamInterface,LeaderboardScoreUploaded_t>::`vftable';
  LODWORD(this->m_SteamCallResultUploadScore.m_hAPICall) = 0;
  HIDWORD(this->m_SteamCallResultUploadScore.m_hAPICall) = 0;
  this->m_SteamCallResultUploadScore.m_pObj = 0;
  this->m_SteamCallResultUploadScore.m_Func = 0;
  this->m_SteamCallResultUploadScore.m_iCallback = 1106;
  this->m_SteamCallResultDownloadScore.m_nCallbackFlags = 0;
  this->m_SteamCallResultDownloadScore.__vftable = (CCallResult<SteamInterface,LeaderboardScoresDownloaded_t>_vtbl *)&CCallResult<SteamInterface,LeaderboardScoresDownloaded_t>::`vftable';
  LODWORD(this->m_SteamCallResultDownloadScore.m_hAPICall) = 0;
  HIDWORD(this->m_SteamCallResultDownloadScore.m_hAPICall) = 0;
  this->m_SteamCallResultDownloadScore.m_pObj = 0;
  this->m_SteamCallResultDownloadScore.m_Func = 0;
  this->m_SteamCallResultDownloadScore.m_iCallback = 1105;
  this->m_SteamCallResultFileShareRequest.m_nCallbackFlags = 0;
  this->m_SteamCallResultFileShareRequest.__vftable = (CCallResult<SteamInterface,RemoteStorageFileShareResult_t>_vtbl *)&CCallResult<SteamInterface,RemoteStorageFileShareResult_t>::`vftable';
  LODWORD(this->m_SteamCallResultFileShareRequest.m_hAPICall) = 0;
  HIDWORD(this->m_SteamCallResultFileShareRequest.m_hAPICall) = 0;
  this->m_SteamCallResultFileShareRequest.m_pObj = 0;
  this->m_SteamCallResultFileShareRequest.m_Func = 0;
  this->m_SteamCallResultFileShareRequest.m_iCallback = 1307;
  this->publishCB.m_nCallbackFlags = 0;
  this->publishCB.__vftable = (CCallResult<SteamInterface,RemoteStoragePublishFileResult_t>_vtbl *)&CCallResult<SteamInterface,RemoteStoragePublishFileResult_t>::`vftable';
  LODWORD(this->publishCB.m_hAPICall) = 0;
  HIDWORD(this->publishCB.m_hAPICall) = 0;
  this->publishCB.m_pObj = 0;
  this->publishCB.m_Func = 0;
  this->publishCB.m_iCallback = 1309;
  v4 = this->sim;
  this->maxDamage = 0.0;
  this->distanceTraveled = 0.0;
  this->standardTimeToBeat = 0;
  this->proTimeToBeat = 0;
  *(_WORD *)&this->timeAttackOn = 0;
  v5 = v4->gameObjects._Myfirst;
  LOBYTE(v39) = 10;
  if ( v5 == v4->gameObjects._Mylast )
  {
LABEL_8:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      v6 = (GameMode *)__RTDynamicCast(*v5, 0, &GameObject `RTTI Type Descriptor', &GameMode `RTTI Type Descriptor', 0);
      if ( v6 )
        break;
      if ( ++v5 == v4->gameObjects._Mylast )
        goto LABEL_8;
    }
  }
  this->gameMode = v6;
  if ( v6 )
  {
    *(_DWORD *)&secondsStandard[76] = this;
    *(_DWORD *)&secondsStandard[52] = &std::_Func_impl<std::_Callable_obj<_lambda_d03904bc9dd08604e6ae7859b5a40846_,0>,std::allocator<std::_Func_class<void,SpecialEventAchievement const &>>,void,SpecialEventAchievement const &>::`vftable';
    *(_DWORD *)&secondsStandard[56] = this;
    *(_DWORD *)&secondsStandard[68] = &secondsStandard[52];
    v7 = (Event<SessionInfo> *)&this->gameMode->evOnTierCompleted;
    LOBYTE(v39) = 10;
    Event<float>::addHandler(v7, *(std::function<void __cdecl(SessionInfo const &)> *)&secondsStandard[52], this);
    *(_DWORD *)&secondsStandard[76] = this;
    *(_DWORD *)&secondsStandard[52] = &std::_Func_impl<std::_Callable_obj<_lambda_409b327e16c7dfd0efeda47555bff056_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
    *(_DWORD *)&secondsStandard[56] = this;
    *(_DWORD *)&secondsStandard[68] = &secondsStandard[52];
    v8 = &this->gameMode->evOnLeaderboardScore;
    LOBYTE(v39) = 10;
    Event<float>::addHandler(
      (Event<SessionInfo> *)v8,
      *(std::function<void __cdecl(SessionInfo const &)> *)&secondsStandard[52],
      this);
  }
  v26 = &secondsStandard[48];
  *(_DWORD *)&secondsStandard[76] = 1122238464;
  *(_DWORD *)&secondsStandard[72] = 1122579251;
  *(_DWORD *)&secondsStandard[68] = 7;
  *(_DWORD *)&secondsStandard[64] = 0;
  *(_WORD *)&secondsStandard[48] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[48], word_17BE9D8, 0);
  LOBYTE(v39) = 13;
  v27 = &secondsStandard[24];
  *(_DWORD *)&secondsStandard[44] = 7;
  *(_DWORD *)&secondsStandard[40] = 0;
  *(_WORD *)&secondsStandard[24] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[24], L"imola", 5u);
  LOBYTE(v39) = 14;
  *(_DWORD *)&secondsStandard[20] = 7;
  *(_DWORD *)&secondsStandard[16] = 0;
  *(_WORD *)secondsStandard = 0;
  std::wstring::assign((std::wstring *)secondsStandard, L"ferrari_458", 0xBu);
  LOBYTE(v39) = 10;
  CarTrackComb::CarTrackComb(
    &times,
    *(std::wstring *)secondsStandard,
    *(std::wstring *)&secondsStandard[24],
    *(std::wstring *)&secondsStandard[48],
    *(float *)&secondsStandard[72],
    *(float *)&secondsStandard[76]);
  LOBYTE(v39) = 15;
  std::vector<CarTrackComb>::push_back(&timesToBeat, v9);
  LOBYTE(v39) = 10;
  std::pair<std::wstring const,Achievement>::~pair<std::wstring const,Achievement>(&times);
  v25 = &secondsStandard[48];
  *(_DWORD *)&secondsStandard[76] = 1118896128;
  *(_DWORD *)&secondsStandard[72] = 1119092736;
  *(_DWORD *)&secondsStandard[68] = 7;
  *(_DWORD *)&secondsStandard[64] = 0;
  *(_WORD *)&secondsStandard[48] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[48], L"r", 1u);
  LOBYTE(v39) = 16;
  v27 = &secondsStandard[24];
  *(_DWORD *)&secondsStandard[44] = 7;
  *(_DWORD *)&secondsStandard[40] = 0;
  *(_WORD *)&secondsStandard[24] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[24], L"m", 1u);
  LOBYTE(v39) = 17;
  *(_DWORD *)&secondsStandard[20] = 7;
  *(_DWORD *)&secondsStandard[16] = 0;
  *(_WORD *)secondsStandard = 0;
  std::wstring::assign((std::wstring *)secondsStandard, L"lotus_49", 8u);
  LOBYTE(v39) = 10;
  CarTrackComb::CarTrackComb(
    &times,
    *(std::wstring *)secondsStandard,
    *(std::wstring *)&secondsStandard[24],
    *(std::wstring *)&secondsStandard[48],
    *(float *)&secondsStandard[72],
    *(float *)&secondsStandard[76]);
  LOBYTE(v39) = 18;
  std::vector<CarTrackComb>::push_back(&timesToBeat, v10);
  LOBYTE(v39) = 10;
  std::pair<std::wstring const,Achievement>::~pair<std::wstring const,Achievement>(&times);
  v25 = &secondsStandard[48];
  *(_DWORD *)&secondsStandard[76] = 1119485952;
  *(_DWORD *)&secondsStandard[72] = 1119617024;
  *(_DWORD *)&secondsStandard[68] = 7;
  *(_DWORD *)&secondsStandard[64] = 0;
  *(_WORD *)&secondsStandard[48] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[48], L"e", 1u);
  LOBYTE(v39) = 19;
  v27 = &secondsStandard[24];
  *(_DWORD *)&secondsStandard[44] = 7;
  *(_DWORD *)&secondsStandard[40] = 0;
  *(_WORD *)&secondsStandard[24] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[24], L"v", 1u);
  LOBYTE(v39) = 20;
  *(_DWORD *)&secondsStandard[20] = 7;
  *(_DWORD *)&secondsStandard[16] = 0;
  *(_WORD *)secondsStandard = 0;
  std::wstring::assign((std::wstring *)secondsStandard, L"tatuusfa1", 9u);
  LOBYTE(v39) = 10;
  CarTrackComb::CarTrackComb(
    &times,
    *(std::wstring *)secondsStandard,
    *(std::wstring *)&secondsStandard[24],
    *(std::wstring *)&secondsStandard[48],
    *(float *)&secondsStandard[72],
    *(float *)&secondsStandard[76]);
  LOBYTE(v39) = 21;
  std::vector<CarTrackComb>::push_back(&timesToBeat, v11);
  LOBYTE(v39) = 10;
  std::pair<std::wstring const,Achievement>::~pair<std::wstring const,Achievement>(&times);
  v25 = &secondsStandard[48];
  *(_DWORD *)&secondsStandard[76] = 1120665600;
  *(_DWORD *)&secondsStandard[72] = 1120796672;
  *(_DWORD *)&secondsStandard[68] = 7;
  *(_DWORD *)&secondsStandard[64] = 0;
  *(_WORD *)&secondsStandard[48] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[48], word_17BE9D8, 0);
  LOBYTE(v39) = 22;
  v27 = &secondsStandard[24];
  *(_DWORD *)&secondsStandard[44] = 7;
  *(_DWORD *)&secondsStandard[40] = 0;
  *(_WORD *)&secondsStandard[24] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[24], L"imola", 5u);
  LOBYTE(v39) = 23;
  *(_DWORD *)&secondsStandard[20] = 7;
  *(_DWORD *)&secondsStandard[16] = 0;
  *(_WORD *)secondsStandard = 0;
  std::wstring::assign((std::wstring *)secondsStandard, L"bmw_m3_gt2", 0xAu);
  LOBYTE(v39) = 10;
  CarTrackComb::CarTrackComb(
    &times,
    *(std::wstring *)secondsStandard,
    *(std::wstring *)&secondsStandard[24],
    *(std::wstring *)&secondsStandard[48],
    *(float *)&secondsStandard[72],
    *(float *)&secondsStandard[76]);
  LOBYTE(v39) = 24;
  std::vector<CarTrackComb>::push_back(&timesToBeat, v12);
  LOBYTE(v39) = 10;
  std::pair<std::wstring const,Achievement>::~pair<std::wstring const,Achievement>(&times);
  *(_DWORD *)&secondsStandard[76] = 0;
  *(_DWORD *)&secondsStandard[72] = 7;
  *(_DWORD *)&secondsStandard[68] = 0;
  *(_WORD *)&secondsStandard[52] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[52], L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(
    &raceINI,
    (unsigned int)this,
    *(std::wstring *)&secondsStandard[52],
    secondsStandard[76]);
  LOBYTE(v39) = 25;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"MODEL", 5u);
  LOBYTE(v39) = 26;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"RACE", 4u);
  LOBYTE(v39) = 27;
  INIReader::getString(&raceINI, &carName, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v39) = 30;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"TRACK", 5u);
  LOBYTE(v39) = 31;
  v35._Myres = 7;
  v35._Mysize = 0;
  v35._Bx._Buf[0] = 0;
  std::wstring::assign(&v35, L"RACE", 4u);
  LOBYTE(v39) = 32;
  INIReader::getString(&raceINI, &trackName, &v35, &name);
  if ( v35._Myres >= 8 )
    operator delete(v35._Bx._Ptr);
  v35._Myres = 7;
  v35._Mysize = 0;
  v35._Bx._Buf[0] = 0;
  LOBYTE(v39) = 35;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"CONFIG_TRACK", 0xCu);
  LOBYTE(v39) = 36;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"RACE", 4u);
  LOBYTE(v39) = 37;
  INIReader::getString(&raceINI, &configTrack, &key, &section);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v39) = 40;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v13 = timesToBeat._Myfirst;
  v14 = timesToBeat._Mylast;
  section._Myres = 7;
  section._Mysize = 0;
  for ( section._Bx._Buf[0] = 0; v13 != v14; ++v13 )
  {
    CarTrackComb::CarTrackComb(&times, v13);
    LOBYTE(v39) = 41;
    if ( !std::wstring::compare(&carName, 0, carName._Mysize, L"tatuusfa1", 9u)
      && !std::wstring::compare(&trackName, 0, trackName._Mysize, L"ks_vallelunga", 0xDu)
      && !std::wstring::compare(&configTrack, 0, configTrack._Mysize, L"extended_circuit", 0x10u)
      && !std::wstring::compare(&times.track, L"v")
      && std::operator==<wchar_t>(&times.trackConfig, L"e") )
    {
      this->standardTimeToBeat = times.standardTime;
      this->proTimeToBeat = times.proTime;
    }
    if ( !std::wstring::compare(&carName, 0, carName._Mysize, L"lotus_49", 8u)
      && !std::wstring::compare(&trackName, 0, trackName._Mysize, L"ks_monza66", 0xAu)
      && !std::wstring::compare(&configTrack, 0, configTrack._Mysize, L"road", 4u)
      && !std::wstring::compare(&times.track, L"m")
      && std::operator==<wchar_t>(&times.trackConfig, L"r") )
    {
      this->standardTimeToBeat = times.standardTime;
      this->proTimeToBeat = times.proTime;
    }
    v15 = &carName;
    *(_DWORD *)&secondsStandard[76] = carName._Mysize;
    if ( carName._Myres >= 8 )
      v15 = (std::wstring *)carName._Bx._Ptr;
    if ( !std::wstring::compare(&times.car, 0, times.car._Mysize, v15->_Bx._Buf, *(unsigned int *)&secondsStandard[76]) )
    {
      v16 = &trackName;
      *(_DWORD *)&secondsStandard[76] = trackName._Mysize;
      if ( trackName._Myres >= 8 )
        v16 = (std::wstring *)trackName._Bx._Ptr;
      if ( !std::wstring::compare(
              &times.track,
              0,
              times.track._Mysize,
              v16->_Bx._Buf,
              *(unsigned int *)&secondsStandard[76]) )
      {
        v17 = &configTrack;
        *(_DWORD *)&secondsStandard[76] = configTrack._Mysize;
        if ( configTrack._Myres >= 8 )
          v17 = (std::wstring *)configTrack._Bx._Ptr;
        if ( !std::wstring::compare(
                &times.trackConfig,
                0,
                times.trackConfig._Mysize,
                v17->_Bx._Buf,
                *(unsigned int *)&secondsStandard[76]) )
        {
          this->standardTimeToBeat = times.standardTime;
          this->proTimeToBeat = times.proTime;
        }
      }
    }
    LOBYTE(v39) = 40;
    std::pair<std::wstring const,Achievement>::~pair<std::wstring const,Achievement>(&times);
  }
  if ( !this->standardTimeToBeat || !this->proTimeToBeat )
    _printf("Steam Interface :: COULDN't FIND A TIME TO BEAT!\n");
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"rSsA", 4u);
  v25 = &secondsStandard[56];
  *(_DWORD *)&secondsStandard[56] = &std::_Func_impl<std::_Callable_obj<_lambda_d215e4f63103bf9b8f209205814c8e60_,0>,std::allocator<std::_Func_class<std::wstring,>>,std::wstring,>::`vftable';
  *(_DWORD *)&secondsStandard[72] = &secondsStandard[56];
  v27 = &secondsStandard[32];
  *(_DWORD *)&secondsStandard[32] = &std::_Func_impl<std::_Callable_obj<_lambda_90bb88c99c2e7661e845ce5bffd200c4_,0>,std::allocator<std::_Func_class<bool,std::wstring>>,bool,std::wstring>::`vftable';
  *(_DWORD *)&secondsStandard[36] = this;
  *(_DWORD *)&secondsStandard[48] = &secondsStandard[32];
  LOBYTE(v39) = 46;
  *(_DWORD *)&secondsStandard[28] = &name;
  v18 = Console::singleton();
  LOBYTE(v39) = 42;
  Console::addCommand(
    v18,
    *(const std::wstring **)&secondsStandard[28],
    *(std::function<bool __cdecl(std::wstring)> *)&secondsStandard[32],
    *(std::function<std::wstring __cdecl(void)> *)&secondsStandard[56]);
  LOBYTE(v39) = 40;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  SteamInterface::fetchPlayerImage(this);
  *(_DWORD *)&secondsStandard[76] = 0;
  *(_DWORD *)&secondsStandard[72] = 7;
  *(_DWORD *)&secondsStandard[68] = 0;
  *(_WORD *)&secondsStandard[52] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[52], L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(
    &ini,
    (unsigned int)this,
    *(std::wstring *)&secondsStandard[52],
    secondsStandard[76]);
  v19 = this->sim;
  LOBYTE(v39) = 47;
  if ( RaceManager::getCurrentSessionType(v19->raceManager) == TimeAttack )
    this->timeAttackOn = 1;
  if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == Hotlap )
    this->hotlapOn = 1;
  v20 = (void (***)(_DWORD))_SteamUserStats(v22, v23, v24);
  (**v20)(v20);
  v25 = &secondsStandard[56];
  *(_DWORD *)&secondsStandard[76] = 7;
  *(_DWORD *)&secondsStandard[72] = 0;
  *(_WORD *)&secondsStandard[56] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[56], &configTrack, 0, 0xFFFFFFFF);
  LOBYTE(v39) = 48;
  v27 = &secondsStandard[32];
  *(_DWORD *)&secondsStandard[52] = 7;
  *(_DWORD *)&secondsStandard[48] = 0;
  *(_WORD *)&secondsStandard[32] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[32], &trackName, 0, 0xFFFFFFFF);
  LOBYTE(v39) = 49;
  *(_DWORD *)&secondsStandard[28] = 7;
  *(_DWORD *)&secondsStandard[24] = 0;
  *(_WORD *)&secondsStandard[8] = 0;
  std::wstring::assign((std::wstring *)&secondsStandard[8], &carName, 0, 0xFFFFFFFF);
  LOBYTE(v39) = 47;
  SteamInterface::createLeaderboards(
    this,
    *(std::wstring *)&secondsStandard[8],
    *(std::wstring *)&secondsStandard[32],
    *(std::wstring *)&secondsStandard[56]);
  LOBYTE(v39) = 40;
  INIReaderDocuments::~INIReaderDocuments(&ini);
  if ( configTrack._Myres >= 8 )
    operator delete(configTrack._Bx._Ptr);
  configTrack._Myres = 7;
  configTrack._Mysize = 0;
  configTrack._Bx._Buf[0] = 0;
  if ( trackName._Myres >= 8 )
    operator delete(trackName._Bx._Ptr);
  trackName._Myres = 7;
  trackName._Mysize = 0;
  trackName._Bx._Buf[0] = 0;
  if ( carName._Myres >= 8 )
    operator delete(carName._Bx._Ptr);
  carName._Myres = 7;
  carName._Mysize = 0;
  carName._Bx._Buf[0] = 0;
  LOBYTE(v39) = 10;
  INIReaderDocuments::~INIReaderDocuments(&raceINI);
}
void SteamInterface::~SteamInterface(SteamInterface *this)
{
  bool v2; // zf
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  std::_Tree_node<std::pair<std::wstring const ,Achievement>,void *> *v13; // [esp-4h] [ebp-2Ch]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Achievement> > > > result; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+24h] [ebp-4h]

  this->__vftable = (SteamInterface_vtbl *)&SteamInterface::`vftable';
  v2 = this->playerAvatar.kid == 0;
  v15 = 10;
  if ( !v2 )
    Texture::release(&this->playerAvatar);
  v3 = this->publishCB.m_hAPICall;
  v4 = HIDWORD(this->publishCB.m_hAPICall);
  v2 = this->publishCB.m_hAPICall == 0;
  this->publishCB.__vftable = (CCallResult<SteamInterface,RemoteStoragePublishFileResult_t>_vtbl *)&CCallResult<SteamInterface,RemoteStoragePublishFileResult_t>::`vftable';
  if ( !v2 )
  {
    _SteamAPI_UnregisterCallResult(&this->publishCB, v3, v4);
    LODWORD(this->publishCB.m_hAPICall) = 0;
    HIDWORD(this->publishCB.m_hAPICall) = 0;
  }
  v5 = this->m_SteamCallResultFileShareRequest.m_hAPICall;
  v6 = HIDWORD(this->m_SteamCallResultFileShareRequest.m_hAPICall);
  v2 = this->m_SteamCallResultFileShareRequest.m_hAPICall == 0;
  this->m_SteamCallResultFileShareRequest.__vftable = (CCallResult<SteamInterface,RemoteStorageFileShareResult_t>_vtbl *)&CCallResult<SteamInterface,RemoteStorageFileShareResult_t>::`vftable';
  if ( !v2 )
  {
    _SteamAPI_UnregisterCallResult(&this->m_SteamCallResultFileShareRequest, v5, v6);
    LODWORD(this->m_SteamCallResultFileShareRequest.m_hAPICall) = 0;
    HIDWORD(this->m_SteamCallResultFileShareRequest.m_hAPICall) = 0;
  }
  v7 = this->m_SteamCallResultDownloadScore.m_hAPICall;
  v8 = HIDWORD(this->m_SteamCallResultDownloadScore.m_hAPICall);
  v2 = this->m_SteamCallResultDownloadScore.m_hAPICall == 0;
  this->m_SteamCallResultDownloadScore.__vftable = (CCallResult<SteamInterface,LeaderboardScoresDownloaded_t>_vtbl *)&CCallResult<SteamInterface,LeaderboardScoresDownloaded_t>::`vftable';
  if ( !v2 )
  {
    _SteamAPI_UnregisterCallResult(&this->m_SteamCallResultDownloadScore, v7, v8);
    LODWORD(this->m_SteamCallResultDownloadScore.m_hAPICall) = 0;
    HIDWORD(this->m_SteamCallResultDownloadScore.m_hAPICall) = 0;
  }
  v9 = this->m_SteamCallResultUploadScore.m_hAPICall;
  v10 = HIDWORD(this->m_SteamCallResultUploadScore.m_hAPICall);
  v2 = this->m_SteamCallResultUploadScore.m_hAPICall == 0;
  this->m_SteamCallResultUploadScore.__vftable = (CCallResult<SteamInterface,LeaderboardScoreUploaded_t>_vtbl *)&CCallResult<SteamInterface,LeaderboardScoreUploaded_t>::`vftable';
  if ( !v2 )
  {
    _SteamAPI_UnregisterCallResult(&this->m_SteamCallResultUploadScore, v9, v10);
    LODWORD(this->m_SteamCallResultUploadScore.m_hAPICall) = 0;
    HIDWORD(this->m_SteamCallResultUploadScore.m_hAPICall) = 0;
  }
  v11 = this->m_SteamCallResultCreateLeaderboard.m_hAPICall;
  v12 = HIDWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall);
  v2 = this->m_SteamCallResultCreateLeaderboard.m_hAPICall == 0;
  this->m_SteamCallResultCreateLeaderboard.__vftable = (CCallResult<SteamInterface,LeaderboardFindResult_t>_vtbl *)&CCallResult<SteamInterface,LeaderboardFindResult_t>::`vftable';
  if ( !v2 )
  {
    _SteamAPI_UnregisterCallResult(&this->m_SteamCallResultCreateLeaderboard, v11, v12);
    LODWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall) = 0;
    HIDWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall) = 0;
  }
  LOBYTE(v15) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&this->playerAvatar);
  v13 = this->achievements._Myhead;
  LOBYTE(v15) = 3;
  std::_Tree<std::_Tmap_traits<std::wstring,Achievement,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,Achievement>>,0>>::erase(
    &this->achievements,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Achievement> > > >)v13->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Achievement> > > >)v13);
  operator delete(this->achievements._Myhead);
  this->userStatStoredCB.__vftable = (CCallback<SteamInterface,UserStatsStored_t,0>_vtbl *)&CCallbackImpl<16>::`vftable';
  if ( (this->userStatStoredCB.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(&this->userStatStoredCB);
  v2 = (this->userStatsCB.m_nCallbackFlags & 1) == 0;
  this->userStatsCB.__vftable = (CCallback<SteamInterface,UserStatsReceived_t,0>_vtbl *)&CCallbackImpl<24>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(&this->userStatsCB);
  v2 = this->evOnLeaderboardUpdated.handlers._Myfirst == 0;
  LOBYTE(v15) = 0;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnLeaderboardUpdated);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnLeaderboardUpdated,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnLeaderboardUpdated.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnLeaderboardUpdated.handlers._Mylast);
    operator delete(this->evOnLeaderboardUpdated.handlers._Myfirst);
    this->evOnLeaderboardUpdated.handlers._Myfirst = 0;
    this->evOnLeaderboardUpdated.handlers._Mylast = 0;
    this->evOnLeaderboardUpdated.handlers._Myend = 0;
  }
  v15 = -1;
  GameObject::~GameObject(this);
}
SteamInterface *SteamInterface::`vector deleting destructor'(SteamInterface *this, unsigned int a2)
{
  SteamInterface::~SteamInterface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SteamInterface::OnDownloadScore(SteamInterface *this, LeaderboardScoresDownloaded_t *pDownloadLeaderboardResult, bool bIOFailure)
{
  int v4; // esi
  int v5; // eax
  int v6; // eax
  const char *v7; // eax
  SteamLeaderboardEntry *v8; // ebx
  int v9; // eax
  _DWORD *v10; // eax
  bool v11; // zf
  std::pair<void *,std::function<void __cdecl(std::vector<SteamLeaderboardEntry> const &)> > *v12; // esi
  std::_Func_base<void,std::vector<SteamLeaderboardEntry> const &> **v13; // edi
  std::vector<SteamLeaderboardEntry> lbEntries; // [esp+2Ah] [ebp-98h] BYREF
  LeaderboardEntry_t leaderboardEntry; // [esp+36h] [ebp-8Ch] BYREF
  int v16; // [esp+56h] [ebp-6Ch] BYREF
  SteamLeaderboardEntry entry; // [esp+5Eh] [ebp-64h] BYREF
  std::wstring result; // [esp+82h] [ebp-40h] BYREF
  std::string s; // [esp+9Ah] [ebp-28h] BYREF
  int i; // [esp+BEh] [ebp-4h]

  if ( !pDownloadLeaderboardResult->m_hSteamLeaderboardEntries || bIOFailure )
  {
$LN361:
    _printf("ERROR: SteamInterface::OnDownloadScore ERROR\n");
    return;
  }
  lbEntries._Myfirst = 0;
  lbEntries._Mylast = 0;
  lbEntries._Myend = 0;
  v4 = 0;
  for ( i = 0; v4 < pDownloadLeaderboardResult->m_cEntryCount; ++v4 )
  {
    HIWORD(leaderboardEntry.m_steamIDUser.m_steamid.m_unAll64Bits) = BYTE6(leaderboardEntry.m_steamIDUser.m_steamid.m_unAll64Bits) & 0xF;
    leaderboardEntry.m_steamIDUser.m_steamid.m_unAll64Bits &= 0xFFF0000000000000ui64;
    v5 = _SteamUserStats();
    (*(void (**)(int, _DWORD, _DWORD, int, LeaderboardEntry_t *, _DWORD, _DWORD))(*(_DWORD *)v5 + 120))(
      v5,
      pDownloadLeaderboardResult->m_hSteamLeaderboardEntries,
      HIDWORD(pDownloadLeaderboardResult->m_hSteamLeaderboardEntries),
      v4,
      &leaderboardEntry,
      0,
      0);
    if ( leaderboardEntry.m_nScore && leaderboardEntry.m_nScore != 1316134911 )
    {
      entry.name._Myres = 7;
      entry.name._Mysize = 0;
      entry.name._Bx._Buf[0] = 0;
      entry.isPlayer = 0;
      LOBYTE(i) = 1;
      v6 = _SteamFriends();
      v7 = (const char *)(*(int (**)(int, _DWORD, _DWORD))(*(_DWORD *)v6 + 28))(
                           v6,
                           *(_DWORD *)&leaderboardEntry.m_steamIDUser.m_steamid.m_comp,
                           *((_DWORD *)&leaderboardEntry.m_steamIDUser.m_steamid.m_comp + 1));
      std::string::string(&s, v7);
      LOBYTE(i) = 2;
      v8 = (SteamLeaderboardEntry *)string2wstring(&result, &s);
      if ( &entry != v8 )
      {
        if ( entry.name._Myres >= 8 )
          operator delete(entry.name._Bx._Ptr);
        entry.name._Myres = 7;
        entry.name._Mysize = 0;
        entry.name._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&entry.name, &v8->name);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(i) = 1;
      if ( s._Myres >= 0x10 )
        operator delete(s._Bx._Ptr);
      entry.score = leaderboardEntry.m_nScore;
      entry.globalRank = leaderboardEntry.m_nGlobalRank;
      v9 = _SteamUser();
      v10 = (_DWORD *)(*(int (**)(int, int *))(*(_DWORD *)v9 + 8))(v9, &v16);
      if ( leaderboardEntry.m_steamIDUser.m_steamid.m_comp != *v10
        || (v11 = *((_DWORD *)&leaderboardEntry.m_steamIDUser.m_steamid.m_comp + 1) == v10[1], entry.isPlayer = 1, !v11) )
      {
        entry.isPlayer = 0;
      }
      std::vector<SteamLeaderboardEntry>::push_back(&lbEntries, &entry);
      LOBYTE(i) = 0;
      if ( entry.name._Myres >= 8 )
        operator delete(entry.name._Bx._Ptr);
    }
  }
  v12 = this->evOnLeaderboardUpdated.handlers._Myfirst;
  if ( v12 != this->evOnLeaderboardUpdated.handlers._Mylast )
  {
    v13 = &v12->second._Impl;
    while ( *v13 )
    {
      (*v13)->_Do_call(*v13, &lbEntries);
      ++v12;
      v13 += 8;
      if ( v12 == this->evOnLeaderboardUpdated.handlers._Mylast )
        goto LABEL_24;
    }
    std::_Xbad_function_call();
    goto $LN361;
  }
LABEL_24:
  i = -1;
  if ( lbEntries._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&lbEntries);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<SteamLeaderboardEntry>>>(lbEntries._Myfirst, lbEntries._Mylast);
    operator delete(lbEntries._Myfirst);
  }
}
void SteamInterface::OnUploadScore(SteamInterface *this, LeaderboardScoreUploaded_t *pScoreUploadedResult, bool bIOFailure)
{
  int v4; // eax
  unsigned __int64 v5; // rax

  if ( pScoreUploadedResult->m_bSuccess )
  {
    if ( pScoreUploadedResult->m_bScoreChanged )
    {
      _printf("STEAM INTERFACE Score changed\n");
      v4 = _SteamUserStats();
      v5 = ((__int64 (*)(int, _DWORD, _DWORD, int, int, int))*(_DWORD *)(*(_DWORD *)v4 + 112))(
             v4,
             this->currentLeaderboard,
             HIDWORD(this->currentLeaderboard),
             2,
             -2,
             2);
      CCallResult<SteamInterface,LeaderboardScoresDownloaded_t>::Set(
        &this->m_SteamCallResultDownloadScore,
        v5,
        this,
        SteamInterface::OnDownloadScore);
    }
  }
  else
  {
    _printf("STEAM INTERFACE ERROR OnUploadScore\n");
  }
}
void SteamInterface::achievementCheck(SteamInterface *this)
{
  bool v2; // bl
  std::wstring v3; // [esp-18h] [ebp-88h] BYREF
  Session result; // [esp+Ch] [ebp-64h] BYREF

  SteamInterface::generalAchievements(this);
  SteamInterface::damageRelatedAchievements(this);
  if ( this->hotlapOn && Sim::getCar(this->sim, 0)->physicsState.lapCount >= 0xA )
  {
    v3._Myres = 7;
    v3._Mysize = 0;
    v3._Bx._Buf[0] = 0;
    std::wstring::assign(&v3, L"AC_HOTLAPPER", 0xCu);
    SteamInterface::achievementCompleted(this, v3);
  }
  v2 = RaceManager::getCurrentSession(this->sim->raceManager, &result)->sessionType == Pratice;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  if ( v2 )
    SteamInterface::practiceAchievements(this);
  if ( this->timeAttackOn )
    SteamInterface::timeAttackAchievements(this);
  if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == Drift )
    SteamInterface::driftAchievements(this);
}
void SteamInterface::achievementCompleted(SteamInterface *this, std::wstring achievementName)
{
  Achievement *v3; // eax
  int v4; // esi
  std::string *v5; // eax
  std::string *v6; // ecx
  bool v7; // cf
  int v8; // eax
  std::wstring *v9; // [esp-8h] [ebp-3Ch]
  int v10; // [esp+0h] [ebp-34h]
  int v11; // [esp+0h] [ebp-34h]
  int v12; // [esp+4h] [ebp-30h]
  int v13; // [esp+4h] [ebp-30h]
  int v14; // [esp+8h] [ebp-2Ch]
  int v15; // [esp+8h] [ebp-2Ch]
  std::string result; // [esp+Ch] [ebp-28h] BYREF
  int v17; // [esp+30h] [ebp-4h]

  v17 = 0;
  if ( !std::map<std::wstring,Achievement>::operator[](&this->achievements, &achievementName)->achieved
    && std::map<std::wstring,Achievement>::operator[](&this->achievements, &achievementName)->added
    && this->sim->raceManager->penaltiesEnabled )
  {
    v9 = &std::map<std::wstring,Achievement>::operator[](&this->achievements, &achievementName)->displayDescription;
    v3 = std::map<std::wstring,Achievement>::operator[](&this->achievements, &achievementName);
    SystemMessage::addMessage(this->sim->systemMessage, &v3->displayName, v9, eDefault);
    std::map<std::wstring,Achievement>::operator[](&this->achievements, &achievementName)->achieved = 1;
    v4 = _SteamUserStats(v10, v12, v14);
    v5 = wstring2string(&result, &achievementName);
    v6 = v5;
    v7 = v5->_Myres < 0x10;
    LOBYTE(v17) = 1;
    if ( !v7 )
      v6 = (std::string *)v5->_Bx._Ptr;
    (*(void (**)(int, std::string *))(*(_DWORD *)v4 + 28))(v4, v6);
    LOBYTE(v17) = 0;
    if ( result._Myres >= 0x10 )
      operator delete(result._Bx._Ptr);
    v8 = _SteamUserStats(v11, v13, v15);
    (*(void (**)(int))(*(_DWORD *)v8 + 40))(v8);
  }
  if ( achievementName._Myres >= 8 )
    operator delete(achievementName._Bx._Ptr);
}
void SteamInterface::addAchievement(SteamInterface *this, std::wstring aName)
{
  int v3; // esi
  std::string *v4; // eax
  std::string *v5; // ecx
  bool v6; // cf
  char v7; // bl
  int v8; // esi
  std::string *v9; // eax
  std::string *v10; // ecx
  const char *v11; // eax
  const char *v12; // edx
  unsigned int v13; // ecx
  int v14; // esi
  std::string *v15; // eax
  std::string *v16; // ecx
  const char *v17; // eax
  const char *v18; // edx
  unsigned int v19; // ecx
  Achievement *v20; // esi
  int v21; // [esp+4h] [ebp-E8h]
  int v22; // [esp+4h] [ebp-E8h]
  int v23; // [esp+4h] [ebp-E8h]
  int v24; // [esp+8h] [ebp-E4h]
  int v25; // [esp+8h] [ebp-E4h]
  int v26; // [esp+8h] [ebp-E4h]
  int v27; // [esp+Ch] [ebp-E0h]
  int v28; // [esp+Ch] [ebp-E0h]
  int v29; // [esp+Ch] [ebp-E0h]
  Achievement ac; // [esp+18h] [ebp-D4h] BYREF
  std::wstring displayName; // [esp+4Ch] [ebp-A0h] BYREF
  std::string s; // [esp+64h] [ebp-88h] BYREF
  std::string v33; // [esp+7Ch] [ebp-70h] BYREF
  std::string result; // [esp+94h] [ebp-58h] BYREF
  std::wstring displayDescription; // [esp+ACh] [ebp-40h] BYREF
  std::string v36; // [esp+C4h] [ebp-28h] BYREF
  int v37; // [esp+E8h] [ebp-4h]

  v37 = 1;
  ac.displayName._Myres = 7;
  ac.displayName._Mysize = 0;
  ac.displayName._Bx._Buf[0] = 0;
  ac.displayDescription._Myres = 7;
  ac.displayDescription._Mysize = 0;
  ac.displayDescription._Bx._Buf[0] = 0;
  *(_WORD *)&ac.achieved = 0;
  v3 = _SteamUserStats(v21, v24, v27);
  v4 = wstring2string(&result, &aName);
  v5 = v4;
  v6 = v4->_Myres < 0x10;
  LOBYTE(v37) = 2;
  if ( !v6 )
    v5 = (std::string *)v4->_Bx._Ptr;
  v7 = (*(int (**)(int, std::string *, bool *))(*(_DWORD *)v3 + 24))(v3, v5, &ac.achieved);
  LOBYTE(v37) = 1;
  if ( result._Myres >= 0x10 )
    operator delete(result._Bx._Ptr);
  if ( v7 )
  {
    v8 = _SteamUserStats(v22, v25, v28);
    v9 = wstring2string(&v36, &aName);
    v10 = v9;
    v6 = v9->_Myres < 0x10;
    LOBYTE(v37) = 3;
    if ( !v6 )
      v10 = (std::string *)v9->_Bx._Ptr;
    v11 = (const char *)(*(int (**)(int, std::string *, const char *))(*(_DWORD *)v8 + 48))(v8, v10, "name");
    v12 = v11;
    s._Myres = 15;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( *v11 )
      v13 = strlen(v11);
    else
      v13 = 0;
    std::string::assign(&s, v12, v13);
    LOBYTE(v37) = 4;
    string2wstring(&displayName, &s);
    if ( s._Myres >= 0x10 )
      operator delete(s._Bx._Ptr);
    s._Myres = 15;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    LOBYTE(v37) = 7;
    if ( v36._Myres >= 0x10 )
      operator delete(v36._Bx._Ptr);
    v36._Myres = 15;
    v36._Mysize = 0;
    v36._Bx._Buf[0] = 0;
    if ( !std::wstring::compare(&displayName, 0, displayName._Mysize, word_17BE9D8, 0) )
      std::wstring::assign(&displayName, &aName, 0, 0xFFFFFFFF);
    std::wstring::assign(&ac.displayName, &displayName, 0, 0xFFFFFFFF);
    v14 = _SteamUserStats(v23, v26, v29);
    v15 = wstring2string(&result, &aName);
    v16 = v15;
    v6 = v15->_Myres < 0x10;
    LOBYTE(v37) = 8;
    if ( !v6 )
      v16 = (std::string *)v15->_Bx._Ptr;
    v17 = (const char *)(*(int (**)(int, std::string *, const char *))(*(_DWORD *)v14 + 48))(
                          v14,
                          v16,
                          "desc");
    v18 = v17;
    v33._Myres = 15;
    v33._Mysize = 0;
    v33._Bx._Buf[0] = 0;
    if ( *v17 )
      v19 = strlen(v17);
    else
      v19 = 0;
    std::string::assign(&v33, v18, v19);
    LOBYTE(v37) = 9;
    string2wstring(&displayDescription, &v33);
    if ( v33._Myres >= 0x10 )
      operator delete(v33._Bx._Ptr);
    v33._Myres = 15;
    v33._Mysize = 0;
    v33._Bx._Buf[0] = 0;
    LOBYTE(v37) = 12;
    if ( result._Myres >= 0x10 )
      operator delete(result._Bx._Ptr);
    result._Myres = 15;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&ac.displayDescription, &displayDescription, 0, 0xFFFFFFFF);
    ac.added = 1;
    v20 = std::map<std::wstring,Achievement>::operator[](&this->achievements, &aName);
    if ( v20 != &ac )
      std::wstring::assign(&v20->displayName, &ac.displayName, 0, 0xFFFFFFFF);
    if ( &v20->displayDescription != &ac.displayDescription )
      std::wstring::assign(&v20->displayDescription, &ac.displayDescription, 0, 0xFFFFFFFF);
    v20->achieved = ac.achieved;
    v20->added = ac.added;
    if ( displayDescription._Myres >= 8 )
      operator delete(displayDescription._Bx._Ptr);
    displayDescription._Myres = 7;
    displayDescription._Mysize = 0;
    displayDescription._Bx._Buf[0] = 0;
    if ( displayName._Myres >= 8 )
      operator delete(displayName._Bx._Ptr);
    displayName._Myres = 7;
    displayName._Mysize = 0;
    displayName._Bx._Buf[0] = 0;
  }
  if ( ac.displayDescription._Myres >= 8 )
    operator delete(ac.displayDescription._Bx._Ptr);
  ac.displayDescription._Myres = 7;
  ac.displayDescription._Bx._Buf[0] = 0;
  ac.displayDescription._Mysize = 0;
  if ( ac.displayName._Myres >= 8 )
    operator delete(ac.displayName._Bx._Ptr);
  ac.displayName._Myres = 7;
  ac.displayName._Bx._Buf[0] = 0;
  ac.displayName._Mysize = 0;
  if ( aName._Myres >= 8 )
    operator delete(aName._Bx._Ptr);
}
void SteamInterface::addAchievements(SteamInterface *this)
{
  SteamInterface *v1; // ebx
  int v2; // edi
  unsigned int i; // ebp
  unsigned int j; // esi
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  int v8; // eax
  _DWORD *v9; // esi
  GameMode *v10; // ebp
  unsigned int k; // esi
  const std::wstring *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  const std::wstring *v15; // eax
  std::string *v16; // eax
  std::string *v17; // ecx
  bool v18; // cf
  CarTrackComb *v19; // esi
  CarTrackComb *l; // edi
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  std::wstring v31; // [esp-2h] [ebp-2C4h] BYREF
  int v32; // [esp+16h] [ebp-2ACh]
  int v33; // [esp+1Ah] [ebp-2A8h]
  int v34; // [esp+1Eh] [ebp-2A4h]
  _DWORD *v35; // [esp+32h] [ebp-290h]
  int v36; // [esp+36h] [ebp-28Ch]
  SteamInterface *v37; // [esp+3Ah] [ebp-288h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v38; // [esp+3Eh] [ebp-284h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v39; // [esp+EEh] [ebp-1D4h] BYREF
  std::string v40; // [esp+19Eh] [ebp-124h] BYREF
  std::wstring aName; // [esp+1B6h] [ebp-10Ch] BYREF
  std::wstring result; // [esp+1CEh] [ebp-F4h] BYREF
  Achievement ac; // [esp+1E6h] [ebp-DCh] BYREF
  std::wstring v44; // [esp+21Ah] [ebp-A8h] BYREF
  std::wstring v45; // [esp+232h] [ebp-90h] BYREF
  std::wstring v46; // [esp+24Ah] [ebp-78h] BYREF
  CarTrackComb t; // [esp+262h] [ebp-60h] BYREF
  int v48; // [esp+2BAh] [ebp-8h]
  int v49; // [esp+2BEh] [ebp-4h]
  void *retaddr; // [esp+2C2h] [ebp+0h]

  v1 = this;
  v37 = this;
  v2 = 0;
  v35 = 0;
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_ONEHUNDRED", 0xDu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_TWOHUNDRED", 0xDu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_THREEHUNDRED", 0xFu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_CLEANDRIVE", 0xDu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_HOTLAPPER", 0xCu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_TIMEATTACK_3", 0xFu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_TIMEATTACK_5", 0xFu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_TIMEATTACK_10", 0x10u);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_CRASH", 8u);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_PRACTICE_10", 0xEu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_NOASSISTS_PRACTICE", 0x15u);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_DISTANCE_50", 0xEu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_DISTANCE_100", 0xFu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_DISTANCE_250", 0xFu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_COMBO_10", 0xBu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_COMBO_25", 0xBu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"AC_COMBO_50", 0xBu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"DRIFT_LEVEL_10", 0xEu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"DRIFT_LEVEL_25", 0xEu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"DRIFT_LEVEL_50", 0xEu);
  SteamInterface::addAchievement(v1, v31);
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"DRIFT_LEVEL_100", 0xFu);
  SteamInterface::addAchievement(v1, v31);
  for ( i = 0; i < 0x190; ++i )
  {
    for ( j = 0; j < 4; ++j )
    {
      *(_DWORD *)v38.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v38.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v38.gap68);
      retaddr = 0;
      v2 |= 1u;
      v36 = v2;
      std::wiostream::basic_iostream<wchar_t>(&v38.gap0[4], &v38.gap10[12], 0);
      v48 = 1;
      *(SteamInterface **)((char *)&v37 + (unsigned int)v37->game) = (SteamInterface *)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(int *)((char *)&v36 + (unsigned int)v37->game) = (int)&v37->game[-1].keyboardManager.listeners._Myend;
      std::wstreambuf::wstreambuf(&v38.gap10[4]);
      *(_DWORD *)&v38.gap10[4] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v38.gap10[60] = 0;
      *(_DWORD *)&v38.gap10[64] = 0;
      v31._Mysize = j;
      *(_QWORD *)&v31._Bx._Alias[8] = __PAIR64__("_", i);
      v48 = 3;
      v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
             (std::wostream *)((char *)&v38._Chcount + 4),
             "SPECIAL_EVENT_");
      v6 = (std::wostream *)std::wostream::operator<<(v5, *(_DWORD *)&v31._Bx._Alias[8]);
      v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, (const char *)v31._Myres);
      std::wostream::operator<<(v7, v32);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &v31);
      SteamInterface::addAchievement(v1, v31);
      v49 = -1;
      *(_DWORD *)&v38.gap0[*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(SteamInterface **)((char *)&v37 + *(_DWORD *)(*(_DWORD *)v38.gap0 + 4)) = (SteamInterface *)(*(_DWORD *)(*(_DWORD *)v38.gap0 + 4) - 104);
      *(_DWORD *)&v38.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v38.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v38.gap10[8]) )
          std::wstreambuf::epptr(&v38.gap10[8]);
        else
          std::wstreambuf::egptr(&v38.gap10[8]);
        std::wstreambuf::eback(&v38.gap10[8]);
        v8 = std::wstreambuf::eback(&v38.gap10[8]);
        operator delete(v8);
      }
      std::wstreambuf::setg(&v38.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v38.gap10[8], 0, 0);
      *(_DWORD *)&v38.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v38.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v38.gap68);
    }
  }
  v35 = &v1->sim->__vftable;
  v9 = (_DWORD *)v35[10];
  if ( v9 != (_DWORD *)v35[11] )
  {
    while ( 1 )
    {
      v10 = (GameMode *)__RTDynamicCast(*v9, 0, &GameObject `RTTI Type Descriptor', &GameMode `RTTI Type Descriptor', 0);
      if ( v10 )
        break;
      if ( ++v9 == (_DWORD *)v35[11] )
        goto LABEL_31;
    }
    for ( k = 0; k < 4; ++k )
    {
      *(_DWORD *)v39.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v39.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v39.gap68);
      v49 = 4;
      v2 |= 2u;
      v35 = (_DWORD *)v2;
      std::wiostream::basic_iostream<wchar_t>(&v39, &v39.gap10[8], 0);
      v49 = 5;
      *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v38.gap68[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v39.gap10[8]);
      *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v39.gap10[64] = 0;
      *(_DWORD *)&v39.gap10[68] = 0;
      v49 = 7;
      std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v39.gap10, "SPECIAL_EVENT_");
      v12 = GameMode::getGUID(v10, &result);
      v31._Myres = k;
      v31._Mysize = (unsigned int)"_";
      LOBYTE(v49) = 8;
      v13 = std::operator<<<wchar_t>((std::wostream *)v39.gap10, v12);
      v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, (const char *)v31._Mysize);
      std::wostream::operator<<(v14, v31._Myres);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      ac.displayName._Myres = 7;
      ac.displayName._Mysize = 0;
      ac.displayName._Bx._Buf[0] = 0;
      ac.displayDescription._Myres = 7;
      ac.displayDescription._Mysize = 0;
      ac.displayDescription._Bx._Buf[0] = 0;
      *(_WORD *)&ac.achieved = 0;
      LOBYTE(v49) = 9;
      v35 = (_DWORD *)_SteamUserStats(v32, v33, v34);
      v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &result);
      LOBYTE(v49) = 10;
      v16 = wstring2string(&v40, v15);
      v17 = v16;
      v18 = v16->_Myres < 0x10;
      LOBYTE(v49) = 11;
      if ( !v18 )
        v17 = (std::string *)v16->_Bx._Ptr;
      HIBYTE(v36) = (*(int (**)(_DWORD *, std::string *, bool *))(*v35 + 24))(v35, v17, &ac.achieved);
      if ( v40._Myres >= 0x10 )
        operator delete(v40._Bx._Ptr);
      v40._Myres = 15;
      v40._Mysize = 0;
      v40._Bx._Buf[0] = 0;
      LOBYTE(v49) = 9;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( HIBYTE(v36) )
        GameMode::forceConditionAchieved(v10, k, ac.achieved);
      if ( ac.displayDescription._Myres >= 8 )
        operator delete(ac.displayDescription._Bx._Ptr);
      ac.displayDescription._Myres = 7;
      ac.displayDescription._Mysize = 0;
      ac.displayDescription._Bx._Buf[0] = 0;
      if ( ac.displayName._Myres >= 8 )
        operator delete(ac.displayName._Bx._Ptr);
      ac.displayName._Myres = 7;
      ac.displayName._Bx._Buf[0] = 0;
      ac.displayName._Mysize = 0;
      v49 = -1;
      *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v38.gap68[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104;
      *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v39.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v39.gap68);
    }
    v1 = v37;
  }
LABEL_31:
  v19 = timesToBeat._Myfirst;
  for ( l = timesToBeat._Mylast; v19 != l; ++v19 )
  {
    CarTrackComb::CarTrackComb(&t, v19);
    v31._Myres = (unsigned int)L"_";
    v49 = 12;
    v31._Mysize = (unsigned int)&t;
    if ( t.trackConfig._Mysize )
    {
      v24 = std::operator+<wchar_t>(&v45, (const std::wstring *)v31._Mysize, (const wchar_t *)v31._Myres);
      LOBYTE(v49) = 16;
      v25 = std::operator+<wchar_t>(&aName, v24, &t.track);
      LOBYTE(v49) = 17;
      v26 = std::operator+<wchar_t>((std::wstring *)&v40, v25, L"_");
      LOBYTE(v49) = 18;
      std::operator+<wchar_t>(&v31, v26, &t.trackConfig);
      SteamInterface::addAchievement(v1, v31);
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      v40._Myres = 7;
      v40._Mysize = 0;
      *(_WORD *)v40._Bx._Buf = 0;
      if ( aName._Myres >= 8 )
        operator delete(aName._Bx._Ptr);
      aName._Myres = 7;
      aName._Mysize = 0;
      aName._Bx._Buf[0] = 0;
      LOBYTE(v49) = 12;
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
      v27 = std::operator+<wchar_t>(&result, &t.car, L"_");
      LOBYTE(v49) = 19;
      v28 = std::operator+<wchar_t>(&v44, v27, &t.track);
      LOBYTE(v49) = 20;
      v29 = std::operator+<wchar_t>(&v46, v28, L"_");
      LOBYTE(v49) = 21;
      v30 = std::operator+<wchar_t>(&aName, v29, &t.trackConfig);
      LOBYTE(v49) = 22;
      std::operator+<wchar_t>(&v31, v30, L"_pro");
      SteamInterface::addAchievement(v1, v31);
      if ( aName._Myres >= 8 )
        operator delete(aName._Bx._Ptr);
      aName._Myres = 7;
      aName._Mysize = 0;
      aName._Bx._Buf[0] = 0;
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      if ( v44._Myres >= 8 )
        operator delete(v44._Bx._Ptr);
      v44._Myres = 7;
      v44._Mysize = 0;
      v44._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    else
    {
      v21 = std::operator+<wchar_t>(
              (std::wstring *)&v40,
              (const std::wstring *)v31._Mysize,
              (const wchar_t *)v31._Myres);
      LOBYTE(v49) = 13;
      std::operator+<wchar_t>(&v31, v21, &t.track);
      SteamInterface::addAchievement(v1, v31);
      LOBYTE(v49) = 12;
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      v22 = std::operator+<wchar_t>(&v45, &t.car, L"_");
      LOBYTE(v49) = 14;
      v23 = std::operator+<wchar_t>((std::wstring *)&v40, v22, &t.track);
      LOBYTE(v49) = 15;
      std::operator+<wchar_t>(&v31, v23, L"_pro");
      SteamInterface::addAchievement(v1, v31);
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      v40._Myres = 7;
      v40._Mysize = 0;
      *(_WORD *)v40._Bx._Buf = 0;
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
    }
    v49 = -1;
    std::pair<std::wstring const,Achievement>::~pair<std::wstring const,Achievement>(&t);
  }
}
void SteamInterface::createLeaderboards(SteamInterface *this, std::wstring carName, std::wstring trackName, std::wstring trackConfig)
{
  Sim *v5; // eax
  Sim *v6; // ecx
  __int32 v7; // eax
  __int32 v8; // eax
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v11; // ecx
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  const std::wstring *v15; // eax
  int v16; // esi
  std::string *v17; // eax
  std::string *v18; // ecx
  bool v19; // cf
  int v20; // ebx
  int v21; // edi
  __int64 v22; // kr00_8
  std::wstring *v23; // eax
  const std::wstring *v24; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v25; // ecx
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  const std::wstring *v29; // eax
  int v30; // esi
  std::string *v31; // eax
  std::string *v32; // ecx
  __int64 v33; // kr08_8
  std::wstring *v34; // eax
  const std::wstring *v35; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v36; // ecx
  std::wstring *v37; // eax
  std::wstring *v38; // eax
  std::wstring *v39; // eax
  const std::wstring *v40; // eax
  int v41; // esi
  std::string *v42; // eax
  std::string *v43; // ecx
  __int64 v44; // kr10_8
  std::wstring *v45; // eax
  int v46; // [esp+0h] [ebp-234h]
  int v47; // [esp+4h] [ebp-230h]
  int v48; // [esp+8h] [ebp-22Ch]
  std::wstring leaderBoardName; // [esp+14h] [ebp-220h] BYREF
  std::string v50; // [esp+2Ch] [ebp-208h] BYREF
  std::string v51; // [esp+44h] [ebp-1F0h] BYREF
  std::string v52; // [esp+5Ch] [ebp-1D8h] BYREF
  std::wstring v53; // [esp+74h] [ebp-1C0h] BYREF
  std::wstring v54; // [esp+8Ch] [ebp-1A8h] BYREF
  std::wstring result; // [esp+A4h] [ebp-190h] BYREF
  std::wstring v56; // [esp+BCh] [ebp-178h] BYREF
  std::wstring v57; // [esp+D4h] [ebp-160h] BYREF
  std::wstring v58; // [esp+ECh] [ebp-148h] BYREF
  std::wstring v59; // [esp+104h] [ebp-130h] BYREF
  std::wstring v60; // [esp+11Ch] [ebp-118h] BYREF
  std::wstring v61; // [esp+134h] [ebp-100h] BYREF
  std::wstring v62; // [esp+14Ch] [ebp-E8h] BYREF
  std::wstring v63; // [esp+164h] [ebp-D0h] BYREF
  std::wstring v64; // [esp+17Ch] [ebp-B8h] BYREF
  std::wstring v65; // [esp+194h] [ebp-A0h] BYREF
  std::wstring v66; // [esp+1ACh] [ebp-88h] BYREF
  std::wstring v67; // [esp+1C4h] [ebp-70h] BYREF
  std::wstring v68; // [esp+1DCh] [ebp-58h] BYREF
  std::wstring v69; // [esp+1F4h] [ebp-40h] BYREF
  std::wstring v70; // [esp+20Ch] [ebp-28h] BYREF
  int v71; // [esp+230h] [ebp-4h]

  v5 = this->sim;
  v71 = 2;
  if ( !v5->raceManager->penaltiesEnabled )
    goto LABEL_34;
  leaderBoardName._Myres = 7;
  leaderBoardName._Mysize = 0;
  leaderBoardName._Bx._Buf[0] = 0;
  std::wstring::assign(&leaderBoardName, L"_lb_", 4u);
  v6 = this->sim;
  LOBYTE(v71) = 3;
  v7 = RaceManager::getCurrentSessionType(v6->raceManager) - 4;
  if ( !v7 )
  {
    std::wstring::append(&leaderBoardName, L"HOTLAP_", 7u);
    if ( trackConfig._Mysize )
    {
      v37 = std::operator+<wchar_t>(&v70, &carName, L"_");
      LOBYTE(v71) = 13;
      v38 = std::operator+<wchar_t>(&v68, v37, &trackName);
      LOBYTE(v71) = 14;
      v39 = std::operator+<wchar_t>(&v66, v38, L"_");
      LOBYTE(v71) = 15;
      v40 = std::operator+<wchar_t>(&v64, v39, &trackConfig);
      LOBYTE(v71) = 16;
      std::wstring::append(&leaderBoardName, v40, 0, 0xFFFFFFFF);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v64);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v66);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
      v36 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70;
    }
    else
    {
      v34 = std::operator+<wchar_t>(&v62, &carName, L"_");
      LOBYTE(v71) = 11;
      v35 = std::operator+<wchar_t>(&v60, v34, &trackName);
      LOBYTE(v71) = 12;
      std::wstring::append(&leaderBoardName, v35, 0, 0xFFFFFFFF);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v60);
      v36 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62;
    }
    LOBYTE(v71) = 3;
    std::wstring::~wstring(v36);
    v41 = _SteamUserStats(v46, v47, v48);
    v42 = wstring2string(&v52, &leaderBoardName);
    v43 = v42;
    v19 = v42->_Myres < 0x10;
    LOBYTE(v71) = 17;
    if ( !v19 )
      v43 = (std::string *)v42->_Bx._Ptr;
    v44 = ((__int64 (*)(int, std::string *, int, int))*(_DWORD *)(*(_DWORD *)v41 + 88))(v41, v43, 1, 1);
    v20 = HIDWORD(v44);
    v21 = v44;
    if ( v52._Myres >= 0x10 )
      operator delete(v52._Bx._Ptr);
    goto LABEL_26;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    std::wstring::append(&leaderBoardName, L"TIME_ATTACK_", 0xCu);
    if ( trackConfig._Mysize )
    {
      v26 = std::operator+<wchar_t>(&v58, &carName, L"_");
      LOBYTE(v71) = 20;
      v27 = std::operator+<wchar_t>(&v56, v26, &trackName);
      LOBYTE(v71) = 21;
      v28 = std::operator+<wchar_t>(&v54, v27, L"_");
      LOBYTE(v71) = 22;
      v29 = std::operator+<wchar_t>(&v69, v28, &trackConfig);
      LOBYTE(v71) = 23;
      std::wstring::append(&leaderBoardName, v29, 0, 0xFFFFFFFF);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v54);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
      v25 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v58;
    }
    else
    {
      v23 = std::operator+<wchar_t>(&v61, &carName, L"_");
      LOBYTE(v71) = 18;
      v24 = std::operator+<wchar_t>(&v53, v23, &trackName);
      LOBYTE(v71) = 19;
      std::wstring::append(&leaderBoardName, v24, 0, 0xFFFFFFFF);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v53);
      v25 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61;
    }
    LOBYTE(v71) = 3;
    std::wstring::~wstring(v25);
    v30 = _SteamUserStats(v46, v47, v48);
    v31 = wstring2string(&v51, &leaderBoardName);
    v32 = v31;
    v19 = v31->_Myres < 0x10;
    LOBYTE(v71) = 24;
    if ( !v19 )
      v32 = (std::string *)v31->_Bx._Ptr;
    v33 = ((__int64 (*)(int, std::string *, int, int))*(_DWORD *)(*(_DWORD *)v30 + 88))(v30, v32, 2, 1);
    v20 = HIDWORD(v33);
    v21 = v33;
    if ( v51._Myres >= 0x10 )
      operator delete(v51._Bx._Ptr);
    goto LABEL_26;
  }
  if ( v8 == 1 )
  {
    std::wstring::append(&leaderBoardName, L"DRIFT_", 6u);
    if ( trackConfig._Mysize )
    {
      v12 = std::operator+<wchar_t>(&v59, &carName, L"_");
      LOBYTE(v71) = 6;
      v13 = std::operator+<wchar_t>(&v67, v12, &trackName);
      LOBYTE(v71) = 7;
      v14 = std::operator+<wchar_t>(&v57, v13, L"_");
      LOBYTE(v71) = 8;
      v15 = std::operator+<wchar_t>(&v63, v14, &trackConfig);
      LOBYTE(v71) = 9;
      std::wstring::append(&leaderBoardName, v15, 0, 0xFFFFFFFF);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v57);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v67);
      v11 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59;
    }
    else
    {
      v9 = std::operator+<wchar_t>(&result, &carName, L"_");
      LOBYTE(v71) = 4;
      v10 = std::operator+<wchar_t>(&v65, v9, &trackName);
      LOBYTE(v71) = 5;
      std::wstring::append(&leaderBoardName, v10, 0, 0xFFFFFFFF);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v65);
      v11 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
    }
    LOBYTE(v71) = 3;
    std::wstring::~wstring(v11);
    v16 = _SteamUserStats(v46, v47, v48);
    v17 = wstring2string(&v50, &leaderBoardName);
    v18 = v17;
    v19 = v17->_Myres < 0x10;
    LOBYTE(v71) = 10;
    if ( !v19 )
      v18 = (std::string *)v17->_Bx._Ptr;
    v22 = ((__int64 (*)(int, std::string *, int, int))*(_DWORD *)(*(_DWORD *)v16 + 88))(v16, v18, 2, 1);
    v20 = HIDWORD(v22);
    v21 = v22;
    if ( v50._Myres >= 0x10 )
      operator delete(v50._Bx._Ptr);
LABEL_26:
    v45 = &leaderBoardName;
    if ( leaderBoardName._Myres >= 8 )
      v45 = (std::wstring *)leaderBoardName._Bx._Ptr;
    _printf("CREATING STEAM LEADERBOARD %S\n", v45->_Bx._Buf);
    if ( this->m_SteamCallResultCreateLeaderboard.m_hAPICall )
      _SteamAPI_UnregisterCallResult(
        &this->m_SteamCallResultCreateLeaderboard,
        this->m_SteamCallResultCreateLeaderboard.m_hAPICall,
        HIDWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall));
    LODWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall) = v21;
    HIDWORD(this->m_SteamCallResultCreateLeaderboard.m_hAPICall) = v20;
    this->m_SteamCallResultCreateLeaderboard.m_pObj = this;
    this->m_SteamCallResultCreateLeaderboard.m_Func = SteamInterface::OnFindLeaderboard;
    if ( v20 | v21 )
      _SteamAPI_RegisterCallResult(&this->m_SteamCallResultCreateLeaderboard, v21, v20);
  }
  if ( leaderBoardName._Myres >= 8 )
    operator delete(leaderBoardName._Bx._Ptr);
LABEL_34:
  if ( carName._Myres >= 8 )
    operator delete(carName._Bx._Ptr);
  carName._Myres = 7;
  carName._Mysize = 0;
  carName._Bx._Buf[0] = 0;
  if ( trackName._Myres >= 8 )
    operator delete(trackName._Bx._Ptr);
  trackName._Myres = 7;
  trackName._Mysize = 0;
  trackName._Bx._Buf[0] = 0;
  if ( trackConfig._Myres >= 8 )
    operator delete(trackConfig._Bx._Ptr);
}
void SteamInterface::damageRelatedAchievements(SteamInterface *this)
{
  unsigned int i; // edi
  CarAvatar *v3; // eax
  Sim *v4; // ecx
  CarAvatar *v5; // eax
  float v6; // xmm0_4
  float *v7; // ecx
  float *v8; // eax
  std::wstring v9; // [esp-1Ch] [ebp-2Ch] BYREF
  float v10; // [esp+8h] [ebp-8h]

  v10 = 0.0;
  for ( i = 2264; i < 0x8EC; i += 4 )
  {
    v3 = Sim::getCar(this->sim, 0);
    v4 = this->sim;
    v9._Myres = 0;
    v10 = *(float *)((char *)&v3->__vftable + i) + v10;
    v5 = Sim::getCar(v4, 0);
    v6 = *(float *)((char *)&v5->__vftable + i);
    v7 = (float *)((char *)v5 + i);
    v8 = &this->maxDamage;
    if ( v6 > this->maxDamage )
      v8 = v7;
    this->maxDamage = *v8;
  }
  if ( Sim::getCar(this->sim, 0)->physicsState.lapCount >= 5
    && this->maxDamage == 0.0
    && RaceManager::getCurrentSessionType(this->sim->raceManager) != Drag )
  {
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    std::wstring::assign(&v9, L"AC_CLEANDRIVE", 0xDu);
    SteamInterface::achievementCompleted(this, v9);
  }
  if ( v10 > 200.0 )
  {
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    std::wstring::assign(&v9, L"AC_CRASH", 8u);
    SteamInterface::achievementCompleted(this, v9);
  }
}
void SteamInterface::driftAchievements(SteamInterface *this)
{
  DriftMode *v2; // eax
  std::wstring v3; // [esp-18h] [ebp-20h] BYREF

  if ( Sim::getCar(this->sim, 0)->physicsState.driftComboCounter >= 10 )
  {
    v3._Myres = 7;
    v3._Mysize = 0;
    v3._Bx._Buf[0] = 0;
    std::wstring::assign(&v3, L"AC_COMBO_10", 0xBu);
    SteamInterface::achievementCompleted(this, v3);
  }
  if ( Sim::getCar(this->sim, 0)->physicsState.driftComboCounter >= 25 )
  {
    v3._Myres = 7;
    v3._Mysize = 0;
    v3._Bx._Buf[0] = 0;
    std::wstring::assign(&v3, L"AC_COMBO_25", 0xBu);
    SteamInterface::achievementCompleted(this, v3);
  }
  if ( Sim::getCar(this->sim, 0)->physicsState.driftComboCounter >= 50 )
  {
    v3._Myres = 7;
    v3._Mysize = 0;
    v3._Bx._Buf[0] = 0;
    std::wstring::assign(&v3, L"AC_COMBO_50", 0xBu);
    SteamInterface::achievementCompleted(this, v3);
  }
  if ( this->driftMode || (v2 = GameObject::getGameObject<DriftMode>(this->sim), (this->driftMode = v2) != 0) )
  {
    if ( this->driftMode->currentLevel >= 9 )
    {
      v3._Myres = 7;
      v3._Mysize = 0;
      v3._Bx._Buf[0] = 0;
      std::wstring::assign(&v3, L"DRIFT_LEVEL_10", 0xEu);
      SteamInterface::achievementCompleted(this, v3);
    }
    if ( this->driftMode->currentLevel >= 24 )
    {
      v3._Myres = 7;
      v3._Mysize = 0;
      v3._Bx._Buf[0] = 0;
      std::wstring::assign(&v3, L"DRIFT_LEVEL_25", 0xEu);
      SteamInterface::achievementCompleted(this, v3);
    }
    if ( this->driftMode->currentLevel >= 49 )
    {
      v3._Myres = 7;
      v3._Mysize = 0;
      v3._Bx._Buf[0] = 0;
      std::wstring::assign(&v3, L"DRIFT_LEVEL_50", 0xEu);
      SteamInterface::achievementCompleted(this, v3);
    }
    if ( this->driftMode->currentLevel >= 99 )
    {
      v3._Myres = 7;
      v3._Mysize = 0;
      v3._Bx._Buf[0] = 0;
      std::wstring::assign(&v3, L"DRIFT_LEVEL_100", 0xFu);
      SteamInterface::achievementCompleted(this, v3);
    }
  }
}
void SteamInterface::fetchPlayerImage(SteamInterface *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // eax
  void **v7; // eax
  void *v8; // ecx
  const std::wstring *v9; // eax
  CSteamID id; // [esp+10h] [ebp-34h] BYREF
  Texture v11; // [esp+18h] [ebp-2Ch] BYREF
  int v12; // [esp+40h] [ebp-4h]

  v2 = _SteamUser();
  (*(void (**)(int, CSteamID *))(*(_DWORD *)v2 + 8))(v2, &id);
  v3 = _SteamFriends();
  v4 = (*(int (**)(int, _DWORD, _DWORD))(*(_DWORD *)v3 + 144))(
         v3,
         *(_DWORD *)&id.m_steamid.m_comp,
         *((_DWORD *)&id.m_steamid.m_comp + 1));
  if ( v4 > 0 )
  {
    v5 = (unsigned __int8 *)operator new[](0x21100u);
    v6 = _SteamUtils();
    if ( (*(unsigned __int8 (**)(int, int, unsigned __int8 *, int))(*(_DWORD *)v6 + 24))(v6, v4, v5, 135424) )
    {
      Texture::Texture(&v11, v5, 0xB8u, 0xB8u, eRGBA8);
      v8 = *v7;
      v9 = (const std::wstring *)(v7 + 1);
      this->playerAvatar.kid = v8;
      v12 = 0;
      if ( &this->playerAvatar.fileName != v9 )
        std::wstring::assign(&this->playerAvatar.fileName, v9, 0, 0xFFFFFFFF);
      v12 = -1;
      OnSetupAppCreated::~OnSetupAppCreated(&v11);
    }
    else
    {
      _printf("WARNING: SteamInterface::Couldn't get steam image\n");
    }
    operator delete[](v5);
  }
}
void SteamInterface::generalAchievements(SteamInterface *this)
{
  Sim *v2; // ecx
  CarAvatar *v3; // eax
  unsigned int v4; // ecx
  TrackAvatar *v5; // ecx
  bool v6; // bl
  Sim *v7; // ecx
  CarAvatar *v8; // eax
  std::wstring *v9; // eax
  Sim *v10; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v11; // ecx
  CarAvatar *v12; // eax
  const std::wstring *v13; // eax
  int v14; // ebx
  Sim *v15; // ecx
  CarAvatar *v16; // eax
  const std::wstring *v17; // eax
  bool v18; // al
  CarAvatar *v19; // eax
  std::wstring *v20; // esi
  Sim *v21; // ecx
  CarAvatar *v22; // eax
  std::wstring *v23; // eax
  Sim *v24; // ecx
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  unsigned int v27; // ecx
  TrackAvatar *v28; // ecx
  bool v29; // bl
  Sim *v30; // ecx
  CarAvatar *v31; // eax
  std::wstring *v32; // eax
  Sim *v33; // ecx
  std::wstring *v34; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v35; // ecx
  CarAvatar *v36; // eax
  const std::wstring *v37; // eax
  int v38; // ebx
  Sim *v39; // ecx
  CarAvatar *v40; // eax
  const std::wstring *v41; // eax
  bool v42; // al
  CarAvatar *v43; // eax
  std::wstring *v44; // esi
  Sim *v45; // ecx
  CarAvatar *v46; // eax
  std::wstring *v47; // eax
  Sim *v48; // ecx
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  std::wstring *v51; // eax
  CarAvatar *v52; // eax
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  Sim *v56; // ecx
  float v57; // xmm0_4
  unsigned int *v58; // eax
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  float v61; // xmm0_4
  float v62; // eax
  const wchar_t *v63; // [esp-1Ch] [ebp-F0h]
  const wchar_t *v64; // [esp-1Ch] [ebp-F0h]
  std::wstring v65; // [esp-18h] [ebp-ECh] BYREF
  char v66; // [esp+13h] [ebp-C1h]
  int v67; // [esp+14h] [ebp-C0h]
  unsigned int v68; // [esp+18h] [ebp-BCh]
  std::wstring result; // [esp+1Ch] [ebp-B8h] BYREF
  std::wstring v70; // [esp+34h] [ebp-A0h] BYREF
  Lap lap; // [esp+4Ch] [ebp-88h] BYREF
  std::wstring v72; // [esp+7Ch] [ebp-58h] BYREF
  std::wstring achievementName; // [esp+94h] [ebp-40h] BYREF
  std::wstring v74; // [esp+ACh] [ebp-28h] BYREF
  int v75; // [esp+D0h] [ebp-4h]

  v67 = 0;
  v2 = this->sim;
  v68 = 0;
  if ( (float)(Sim::getCar(v2, 0)->physicsState.speed.value * 3.5999999) > 100.0 )
  {
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    std::wstring::assign(&v65, L"AC_ONEHUNDRED", 0xDu);
    SteamInterface::achievementCompleted(this, v65);
  }
  if ( (float)(Sim::getCar(this->sim, 0)->physicsState.speed.value * 3.5999999) > 200.0 )
  {
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    std::wstring::assign(&v65, L"AC_TWOHUNDRED", 0xDu);
    SteamInterface::achievementCompleted(this, v65);
  }
  if ( (float)(Sim::getCar(this->sim, 0)->physicsState.speed.value * 3.5999999) > 300.0 )
  {
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    std::wstring::assign(&v65, L"AC_THREEHUNDRED", 0xFu);
    SteamInterface::achievementCompleted(this, v65);
  }
  v3 = Sim::getCar(this->sim, 0);
  RaceManager::getLastLap(this->sim->raceManager, &lap, v3);
  v4 = this->standardTimeToBeat;
  v75 = 0;
  if ( !v4 )
    goto LABEL_35;
  if ( !lap.isValid )
    goto LABEL_35;
  if ( !lap.time )
    goto LABEL_35;
  if ( lap.time >= v4 )
    goto LABEL_35;
  v5 = this->sim->track;
  if ( ((((char *)lap.splits._Mylast - (char *)lap.splits._Myfirst) ^ ((char *)v5->physicsTrack.sectorsNormalizedPositions._Mylast
                                                                     - (char *)v5->physicsTrack.sectorsNormalizedPositions._Myfirst)) & 0xFFFFFFFC) != 0 )
    goto LABEL_35;
  v6 = TrackAvatar::getConfig(v5, &result)->_Mysize == 0;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  v7 = this->sim;
  if ( v6 )
  {
    v65._Myres = (unsigned int)L"_";
    v8 = Sim::getCar(v7, 0);
    v9 = std::operator+<wchar_t>(&result, &v8->unixName, (const wchar_t *)v65._Myres);
    v10 = this->sim;
    LOBYTE(v75) = 1;
    std::operator+<wchar_t>(&v65, v9, &v10->track->name);
    SteamInterface::achievementCompleted(this, v65);
    v11 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
LABEL_34:
    LOBYTE(v75) = 0;
    std::wstring::~wstring(v11);
    goto LABEL_35;
  }
  v65._Myres = (unsigned int)L"tatuusfa1";
  v12 = Sim::getCar(v7, 0);
  if ( !std::operator==<wchar_t>(&v12->unixName, (const wchar_t *)v65._Myres)
    || !std::operator==<wchar_t>(&this->sim->track->name, L"ks_vallelunga") )
  {
    v14 = v68;
    goto LABEL_19;
  }
  v13 = TrackAvatar::getConfig(this->sim->track, &result);
  v14 = 1;
  LOBYTE(v75) = 2;
  v68 = 1;
  v67 = 1;
  if ( !std::operator==<wchar_t>(v13, L"extended_circuit") )
  {
LABEL_19:
    v66 = 0;
    goto LABEL_20;
  }
  v66 = 1;
LABEL_20:
  v75 = 0;
  if ( (v14 & 1) != 0 )
  {
    v14 &= 0xFFFFFFFE;
    v68 = v14;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  }
  v15 = this->sim;
  if ( v66 )
  {
    v63 = L"_v_e";
  }
  else
  {
    v65._Myres = (unsigned int)L"lotus_49";
    v16 = Sim::getCar(v15, 0);
    if ( !std::operator==<wchar_t>(&v16->unixName, (const wchar_t *)v65._Myres)
      || !std::operator==<wchar_t>(&this->sim->track->name, L"ks_monza66")
      || (v17 = TrackAvatar::getConfig(this->sim->track, &result),
          v14 |= 2u,
          LOBYTE(v75) = 3,
          v68 = v14,
          v67 = v14,
          v18 = std::operator==<wchar_t>(v17, L"road"),
          v66 = 1,
          !v18) )
    {
      v66 = 0;
    }
    v75 = 0;
    if ( (v14 & 2) != 0 )
    {
      v68 = v14 & 0xFFFFFFFD;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    }
    v15 = this->sim;
    if ( !v66 )
    {
      v20 = TrackAvatar::getConfig(v15->track, &v70);
      v21 = this->sim;
      v65._Myres = (unsigned int)L"_";
      LOBYTE(v75) = 4;
      v22 = Sim::getCar(v21, 0);
      v23 = std::operator+<wchar_t>(&v72, &v22->unixName, (const wchar_t *)v65._Myres);
      v24 = this->sim;
      LOBYTE(v75) = 5;
      v25 = std::operator+<wchar_t>(&achievementName, v23, &v24->track->name);
      LOBYTE(v75) = 6;
      v26 = std::operator+<wchar_t>(&result, v25, L"_");
      LOBYTE(v75) = 7;
      std::operator+<wchar_t>(&v65, v26, v20);
      SteamInterface::achievementCompleted(this, v65);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&achievementName);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
      v11 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70;
      goto LABEL_34;
    }
    v63 = L"_m_r";
  }
  v19 = Sim::getCar(v15, 0);
  std::operator+<wchar_t>(&v65, &v19->unixName, v63);
  SteamInterface::achievementCompleted(this, v65);
LABEL_35:
  v27 = this->proTimeToBeat;
  if ( v27 )
  {
    if ( lap.isValid )
    {
      if ( lap.time )
      {
        if ( lap.time < v27 )
        {
          v28 = this->sim->track;
          if ( ((((char *)lap.splits._Mylast - (char *)lap.splits._Myfirst) ^ ((char *)v28->physicsTrack.sectorsNormalizedPositions._Mylast
                                                                             - (char *)v28->physicsTrack.sectorsNormalizedPositions._Myfirst)) & 0xFFFFFFFC) == 0 )
          {
            v29 = TrackAvatar::getConfig(v28, &v70)->_Mysize == 0;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
            v30 = this->sim;
            if ( v29 )
            {
              v65._Myres = (unsigned int)L"_";
              v31 = Sim::getCar(v30, 0);
              v32 = std::operator+<wchar_t>(&v72, &v31->unixName, (const wchar_t *)v65._Myres);
              v33 = this->sim;
              LOBYTE(v75) = 8;
              v34 = std::operator+<wchar_t>(&v70, v32, &v33->track->name);
              LOBYTE(v75) = 9;
              std::operator+<wchar_t>(&v65, v34, L"_pro");
              SteamInterface::achievementCompleted(this, v65);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
              v35 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72;
LABEL_62:
              LOBYTE(v75) = 0;
              std::wstring::~wstring(v35);
              goto LABEL_63;
            }
            v65._Myres = (unsigned int)L"tatuusfa1";
            v36 = Sim::getCar(v30, 0);
            if ( std::operator==<wchar_t>(&v36->unixName, (const wchar_t *)v65._Myres)
              && std::operator==<wchar_t>(&this->sim->track->name, L"ks_vallelunga") )
            {
              v37 = TrackAvatar::getConfig(this->sim->track, &v70);
              v38 = v68 | 4;
              LOBYTE(v75) = 10;
              v67 = v68 | 4;
              if ( std::operator==<wchar_t>(v37, L"extended_circuit") )
              {
                v66 = 1;
                goto LABEL_48;
              }
            }
            else
            {
              v38 = v68;
            }
            v66 = 0;
LABEL_48:
            v75 = 0;
            if ( (v38 & 4) != 0 )
            {
              v38 &= 0xFFFFFFFB;
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
            }
            v39 = this->sim;
            if ( v66 )
            {
              v64 = L"_v_e_pro";
            }
            else
            {
              v65._Myres = (unsigned int)L"lotus_49";
              v40 = Sim::getCar(v39, 0);
              if ( !std::operator==<wchar_t>(&v40->unixName, (const wchar_t *)v65._Myres)
                || !std::operator==<wchar_t>(&this->sim->track->name, L"ks_monza66")
                || (v41 = TrackAvatar::getConfig(this->sim->track, &v70),
                    v38 |= 8u,
                    LOBYTE(v75) = 11,
                    v67 = v38,
                    v42 = std::operator==<wchar_t>(v41, L"road"),
                    v66 = 1,
                    !v42) )
              {
                v66 = 0;
              }
              v75 = 0;
              if ( (v38 & 8) != 0 )
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
              v39 = this->sim;
              if ( !v66 )
              {
                v44 = TrackAvatar::getConfig(v39->track, &v74);
                v45 = this->sim;
                v65._Myres = (unsigned int)L"_";
                LOBYTE(v75) = 12;
                v46 = Sim::getCar(v45, 0);
                v47 = std::operator+<wchar_t>(&result, &v46->unixName, (const wchar_t *)v65._Myres);
                v48 = this->sim;
                LOBYTE(v75) = 13;
                v49 = std::operator+<wchar_t>(&achievementName, v47, &v48->track->name);
                LOBYTE(v75) = 14;
                v50 = std::operator+<wchar_t>(&v72, v49, L"_");
                LOBYTE(v75) = 15;
                v51 = std::operator+<wchar_t>(&v70, v50, v44);
                LOBYTE(v75) = 16;
                std::operator+<wchar_t>(&v65, v51, L"_pro");
                SteamInterface::achievementCompleted(this, v65);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&achievementName);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
                v35 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74;
                goto LABEL_62;
              }
              v64 = L"_m_r_pro";
            }
            v43 = Sim::getCar(v39, 0);
            std::operator+<wchar_t>(&v65, &v43->unixName, v64);
            SteamInterface::achievementCompleted(this, v65);
            goto LABEL_63;
          }
        }
      }
    }
  }
LABEL_63:
  v52 = Sim::getCar(this->sim, 0);
  v53 = this->carPosition.z - v52->bodyMatrix.M43;
  v54 = (float)((float)((float)(this->carPosition.x - v52->bodyMatrix.M41)
                      * (float)(this->carPosition.x - v52->bodyMatrix.M41))
              + (float)((float)(this->carPosition.y - v52->bodyMatrix.M42)
                      * (float)(this->carPosition.y - v52->bodyMatrix.M42)))
      + (float)(v53 * v53);
  v55 = 0.0;
  if ( v54 != 0.0 )
    v55 = fsqrt(v54);
  v56 = this->sim;
  v57 = this->distanceTraveled + v55;
  v65._Myres = 0;
  this->distanceTraveled = v57;
  v58 = (unsigned int *)Sim::getCar(v56, v65._Myres);
  v59 = (__m128)v58[103];
  v60 = (__m128)v58[104];
  *(_DWORD *)&result._Bx._Alias[8] = v58[105];
  v61 = this->distanceTraveled;
  v62 = *(float *)&result._Bx._Alias[8];
  *(_QWORD *)&this->carPosition.x = _mm_unpacklo_ps(v59, v60).m128_u64[0];
  this->carPosition.z = v62;
  if ( v61 > 50000.0 )
  {
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    std::wstring::assign(&v65, L"AC_DISTANCE_50", 0xEu);
    SteamInterface::achievementCompleted(this, v65);
  }
  if ( this->distanceTraveled > 100000.0 )
  {
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    std::wstring::assign(&v65, L"AC_DISTANCE_100", 0xFu);
    SteamInterface::achievementCompleted(this, v65);
  }
  if ( this->distanceTraveled > 250000.0 )
  {
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    std::wstring::assign(&v65, L"AC_DISTANCE_250", 0xFu);
    SteamInterface::achievementCompleted(this, v65);
  }
  v75 = -1;
  if ( lap.compound._Myres >= 8 )
    operator delete(lap.compound._Bx._Ptr);
  lap.compound._Myres = 7;
  lap.compound._Mysize = 0;
  lap.compound._Bx._Buf[0] = 0;
  if ( lap.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&lap.splits);
    operator delete(lap.splits._Myfirst);
  }
}
void SteamInterface::incrementStat(SteamInterface *this, std::wstring name)
{
  int v2; // ebp
  _DWORD *v3; // esi
  std::string *v4; // eax
  std::string *v5; // edi
  bool v6; // cf
  int v7; // esi
  _DWORD *v8; // eax
  char v9; // al
  int v10; // esi
  std::string *v11; // eax
  std::string *v12; // ecx
  char v13; // al
  bool v14; // al
  int v15; // eax
  std::wstring *v16; // eax
  int v17; // [esp+6h] [ebp-50h]
  int v18; // [esp+6h] [ebp-50h]
  int v19; // [esp+6h] [ebp-50h]
  int v20; // [esp+Ah] [ebp-4Ch]
  int v21; // [esp+Ah] [ebp-4Ch]
  int v22; // [esp+Ah] [ebp-4Ch]
  int v23; // [esp+Eh] [ebp-48h]
  int v24; // [esp+Eh] [ebp-48h]
  int v25; // [esp+Eh] [ebp-48h]
  char v26; // [esp+1Dh] [ebp-39h]
  bool v27; // [esp+1Dh] [ebp-39h]
  int data; // [esp+1Eh] [ebp-38h] BYREF
  _DWORD *v29; // [esp+22h] [ebp-34h]
  int v30; // [esp+26h] [ebp-30h] BYREF
  std::string result; // [esp+2Eh] [ebp-28h] BYREF
  int v32; // [esp+52h] [ebp-4h]

  v32 = 0;
  data = 0;
  v2 = _SteamUser(this);
  v3 = (_DWORD *)_SteamUserStats(v17, v20, v23);
  v29 = v3;
  v4 = wstring2string(&result, &name);
  v5 = v4;
  v6 = v4->_Myres < 0x10;
  LOBYTE(v32) = 1;
  if ( !v6 )
    v5 = (std::string *)v4->_Bx._Ptr;
  v7 = *v3;
  v8 = (_DWORD *)(*(int (**)(int, int *))(*(_DWORD *)v2 + 8))(v2, &v30);
  v9 = (*(int (**)(_DWORD *, _DWORD, _DWORD, std::string *, int *))(v7 + 72))(v29, *v8, v8[1], v5, &data);
  v26 = v9;
  LOBYTE(v32) = 0;
  if ( result._Myres >= 0x10 )
  {
    operator delete(result._Bx._Ptr);
    v9 = v26;
  }
  if ( v9 )
  {
    ++data;
    v10 = _SteamUserStats(v18, v21, v24);
    v11 = wstring2string(&result, &name);
    v12 = v11;
    v6 = v11->_Myres < 0x10;
    LOBYTE(v32) = 2;
    if ( !v6 )
      v12 = (std::string *)v11->_Bx._Ptr;
    v13 = (*(int (**)(int, std::string *, int))(*(_DWORD *)v10 + 16))(v10, v12, data);
    LOBYTE(v32) = 0;
    v14 = v13 == 0;
    v27 = v14;
    if ( result._Myres >= 0x10 )
    {
      operator delete(result._Bx._Ptr);
      v14 = v27;
    }
    if ( v14 )
    {
      _printf("ERROR: Steam SET STAT FAILED\n");
    }
    else
    {
      v15 = _SteamUserStats(v19, v22, v25);
      if ( !(*(unsigned __int8 (**)(int))(*(_DWORD *)v15 + 40))(v15) )
        _printf("ERROR: Steam StoreStats FAILED\n");
    }
  }
  else
  {
    v16 = &name;
    if ( name._Myres >= 8 )
      v16 = (std::wstring *)name._Bx._Ptr;
    _printf("ERROR: NO STAT FOR %S\n", v16->_Bx._Buf);
  }
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void __userpurge SteamInterface::onUserStatsReceived(SteamInterface *this@<ecx>, unsigned int a2@<ebx>, UserStatsReceived_t *parameters)
{
  SteamInterface::addAchievements(this);
  SteamInterface::updateStats(this, a2);
}
void SteamInterface::onUserStatsStored(SteamInterface *this, UserStatsStored_t *parameters)
{
  if ( parameters->m_eResult == k_EResultInvalidParam )
    _printf("ERROR: FAILED Steam UserStatStored\n");
}
void SteamInterface::practiceAchievements(SteamInterface *this)
{
  CarAvatar *v2; // eax
  CarAvatar *v3; // eax
  CarAvatar *v4; // eax
  CarAvatar *v5; // eax
  std::wstring v6; // [esp-18h] [ebp-20h] BYREF

  if ( Sim::getCar(this->sim, 0)->physicsState.lapCount >= 0xA )
  {
    v6._Myres = 7;
    v6._Mysize = 0;
    v6._Bx._Buf[0] = 0;
    std::wstring::assign(&v6, L"AC_PRACTICE_10", 0xEu);
    SteamInterface::achievementCompleted(this, v6);
  }
  if ( Sim::getCar(this->sim, 0)->physicsState.lapCount >= 0xA )
  {
    v2 = Sim::getCar(this->sim, 0);
    if ( !CarAvatar::isAbsEnabled(v2) )
    {
      v3 = Sim::getCar(this->sim, 0);
      if ( !CarAvatar::isTcEnabled(v3) )
      {
        v4 = Sim::getCar(this->sim, 0);
        if ( !CarAvatar::getAutoShifter(v4) )
        {
          v5 = Sim::getCar(this->sim, 0);
          if ( !CarAvatar::getAutoBlip(v5) )
          {
            std::wstring::wstring(&v6, L"AC_NOASSISTS_PRACTICE");
            SteamInterface::achievementCompleted(this, v6);
          }
        }
      }
    }
  }
}
void SteamInterface::refreshPlayerLeaderboard(SteamInterface *this)
{
  int v2; // eax
  __int64 v3; // rax
  int v4; // ebx
  int v5; // edi
  int v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+4h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-8h]

  v2 = _SteamUserStats(v6, v7, v8);
  v3 = ((__int64 (*)(int, _DWORD, _DWORD, int, int, int))*(_DWORD *)(*(_DWORD *)v2 + 112))(
         v2,
         this->currentLeaderboard,
         HIDWORD(this->currentLeaderboard),
         2,
         -2,
         2);
  v4 = HIDWORD(v3);
  v5 = v3;
  if ( this->m_SteamCallResultDownloadScore.m_hAPICall )
    _SteamAPI_UnregisterCallResult(
      &this->m_SteamCallResultDownloadScore,
      this->m_SteamCallResultDownloadScore.m_hAPICall,
      HIDWORD(this->m_SteamCallResultDownloadScore.m_hAPICall));
  LODWORD(this->m_SteamCallResultDownloadScore.m_hAPICall) = v5;
  HIDWORD(this->m_SteamCallResultDownloadScore.m_hAPICall) = v4;
  this->m_SteamCallResultDownloadScore.m_pObj = this;
  this->m_SteamCallResultDownloadScore.m_Func = SteamInterface::OnDownloadScore;
  if ( v4 | v5 )
    _SteamAPI_RegisterCallResult(&this->m_SteamCallResultDownloadScore, v5, v4);
}
void SteamInterface::resetAchievements(SteamInterface *this)
{
  std::_Tree_node<std::pair<std::wstring const ,Achievement>,void *> *v2; // edi
  std::_Tree_node<std::pair<std::wstring const ,Achievement>,void *> *v3; // esi
  int v4; // ebx
  std::string *v5; // eax
  std::string *v6; // ecx
  bool v7; // cf
  std::_Tree_node<std::pair<std::wstring const ,Achievement>,void *> *v8; // eax
  std::_Tree_node<std::pair<std::wstring const ,Achievement>,void *> *j; // eax
  std::_Tree_node<std::pair<std::wstring const ,Achievement>,void *> *i; // eax
  int v11; // eax
  int v12; // [esp+0h] [ebp-8Ch]
  int v13; // [esp+4h] [ebp-88h]
  int v14; // [esp+8h] [ebp-84h]
  std::pair<std::wstring const ,Achievement> a; // [esp+18h] [ebp-74h] BYREF
  std::string result; // [esp+64h] [ebp-28h] BYREF
  int v17; // [esp+88h] [ebp-4h]

  _printf("RESETTING STEAM ACHIEVEMENTS\n");
  v2 = this->achievements._Myhead;
  v3 = v2->_Left;
  while ( v3 != v2 )
  {
    a.first._Myres = 7;
    a.first._Mysize = 0;
    a.first._Bx._Buf[0] = 0;
    std::wstring::assign((std::wstring *)&a.first, &v3->_Myval.first, 0, 0xFFFFFFFF);
    v17 = 0;
    a.second.displayName._Myres = 7;
    a.second.displayName._Mysize = 0;
    a.second.displayName._Bx._Buf[0] = 0;
    std::wstring::assign(&a.second.displayName, &v3->_Myval.second.displayName, 0, 0xFFFFFFFF);
    LOBYTE(v17) = 1;
    a.second.displayDescription._Bx._Buf[0] = 0;
    a.second.displayDescription._Myres = 7;
    a.second.displayDescription._Mysize = 0;
    std::wstring::assign(&a.second.displayDescription, &v3->_Myval.second.displayDescription, 0, 0xFFFFFFFF);
    a.second.achieved = v3->_Myval.second.achieved;
    a.second.added = v3->_Myval.second.added;
    v17 = 2;
    v4 = _SteamUserStats(v12, v13, v14);
    v5 = wstring2string(&result, &a.first);
    v6 = v5;
    v7 = v5->_Myres < 0x10;
    LOBYTE(v17) = 3;
    if ( !v7 )
      v6 = (std::string *)v5->_Bx._Ptr;
    (*(void (**)(int, std::string *))(*(_DWORD *)v4 + 32))(v4, v6);
    if ( result._Myres >= 0x10 )
      operator delete(result._Bx._Ptr);
    a.second.achieved = 0;
    v17 = -1;
    if ( a.second.displayDescription._Myres >= 8 )
      operator delete(a.second.displayDescription._Bx._Ptr);
    a.second.displayDescription._Myres = 7;
    a.second.displayDescription._Mysize = 0;
    a.second.displayDescription._Bx._Buf[0] = 0;
    if ( a.second.displayName._Myres >= 8 )
      operator delete(a.second.displayName._Bx._Ptr);
    a.second.displayName._Myres = 7;
    a.second.displayName._Mysize = 0;
    a.second.displayName._Bx._Buf[0] = 0;
    if ( a.first._Myres >= 8 )
      operator delete(a.first._Bx._Ptr);
    if ( !v3->_Isnil )
    {
      v8 = v3->_Right;
      if ( v8->_Isnil )
      {
        for ( i = v3->_Parent; !i->_Isnil; i = i->_Parent )
        {
          if ( v3 != i->_Right )
            break;
          v3 = i;
        }
        v3 = i;
      }
      else
      {
        v3 = v3->_Right;
        for ( j = v8->_Left; !j->_Isnil; j = j->_Left )
          v3 = j;
      }
    }
  }
  v11 = _SteamUserStats(v12, v13, v14);
  (*(void (**)(void))(*(_DWORD *)v11 + 40))();
}
void SteamInterface::resetPlayerLeaderboard(SteamInterface *this)
{
  int v2; // eax
  __int64 v3; // rax
  int v4; // ebp
  int v5; // ebx
  int v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+4h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-8h]

  RaceManager::getCurrentSessionType(this->sim->raceManager);
  v2 = _SteamUserStats(v6, v7, v8);
  v3 = ((__int64 (*)(int, _DWORD, _DWORD, int))*(_DWORD *)(*(_DWORD *)v2 + 124))(
         v2,
         this->currentLeaderboard,
         HIDWORD(this->currentLeaderboard),
         2);
  v4 = HIDWORD(v3);
  v5 = v3;
  if ( this->m_SteamCallResultUploadScore.m_hAPICall )
    _SteamAPI_UnregisterCallResult(
      &this->m_SteamCallResultUploadScore,
      this->m_SteamCallResultUploadScore.m_hAPICall,
      HIDWORD(this->m_SteamCallResultUploadScore.m_hAPICall));
  LODWORD(this->m_SteamCallResultUploadScore.m_hAPICall) = v5;
  HIDWORD(this->m_SteamCallResultUploadScore.m_hAPICall) = v4;
  this->m_SteamCallResultUploadScore.m_pObj = this;
  this->m_SteamCallResultUploadScore.m_Func = SteamInterface::OnUploadScore;
  if ( v4 | v5 )
    _SteamAPI_RegisterCallResult(&this->m_SteamCallResultUploadScore, v5, v4);
}
void SteamInterface::timeAttackAchievements(SteamInterface *this)
{
  std::wstring v2; // [esp-18h] [ebp-20h] BYREF

  if ( Sim::getCar(this->sim, 0)->physicsState.lapCount >= 3 )
  {
    v2._Myres = 7;
    v2._Mysize = 0;
    v2._Bx._Buf[0] = 0;
    std::wstring::assign(&v2, L"AC_TIMEATTACK_3", 0xFu);
    SteamInterface::achievementCompleted(this, v2);
  }
  if ( Sim::getCar(this->sim, 0)->physicsState.lapCount >= 5 )
  {
    v2._Myres = 7;
    v2._Mysize = 0;
    v2._Bx._Buf[0] = 0;
    std::wstring::assign(&v2, L"AC_TIMEATTACK_5", 0xFu);
    SteamInterface::achievementCompleted(this, v2);
  }
  if ( Sim::getCar(this->sim, 0)->physicsState.lapCount >= 0xA )
  {
    v2._Myres = 7;
    v2._Mysize = 0;
    v2._Bx._Buf[0] = 0;
    std::wstring::assign(&v2, L"AC_TIMEATTACK_10", 0x10u);
    SteamInterface::achievementCompleted(this, v2);
  }
}
void SteamInterface::update(SteamInterface *this, float dt)
{
  _SteamAPI_RunCallbacks();
  if ( !ReplayManager::isInReplaymode(this->sim->replayManager) && this->sim->raceManager->penaltiesEnabled )
    SteamInterface::achievementCheck(this);
}
void __usercall SteamInterface::updateStats(SteamInterface *this@<ecx>, unsigned int a2@<ebx>)
{
  bool v3; // zf
  CarAvatar *v4; // eax
  Sim *v5; // eax
  const std::wstring *v6; // eax
  std::wstring *v7; // edi
  std::wstring *v8; // edi
  std::wstring *v9; // edi
  std::wstring *v10; // edi
  std::wstring *v11; // edi
  std::wstring *v12; // edi
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  const std::wstring *v17; // eax
  bool v18; // bl
  const std::wstring *v19; // eax
  bool v20; // bl
  _BYTE v21[48]; // [esp-30h] [ebp-114h] BYREF
  _BYTE *v22; // [esp+10h] [ebp-D4h]
  _BYTE *v23; // [esp+14h] [ebp-D0h]
  std::wstring carName; // [esp+18h] [ebp-CCh] BYREF
  std::wstring result; // [esp+30h] [ebp-B4h] BYREF
  std::wstring trackName; // [esp+48h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+60h] [ebp-84h] BYREF
  std::wstring section; // [esp+78h] [ebp-6Ch] BYREF
  INIReaderDocuments controlsINI; // [esp+90h] [ebp-54h] BYREF
  int v30; // [esp+E0h] [ebp-4h]

  *(_DWORD *)&v21[44] = 7;
  *(_DWORD *)&v21[40] = 0;
  *(_WORD *)&v21[24] = 0;
  std::wstring::assign((std::wstring *)&v21[24], L"runs", 4u);
  SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
  v3 = !this->sim->replayManager->hasLoadedReplay;
  *(_DWORD *)&v21[44] = 7;
  *(_DWORD *)&v21[40] = 0;
  if ( v3 )
  {
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"games", 5u);
    SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
    v4 = Sim::getCar(this->sim, 0);
    carName._Myres = 7;
    carName._Bx._Buf[0] = 0;
    carName._Mysize = 0;
    std::wstring::assign(&carName, &v4->unixName, 0, 0xFFFFFFFF);
    v5 = this->sim;
    *(_DWORD *)&v21[44] = -1;
    *(_DWORD *)&v21[40] = 0;
    v30 = 0;
    v6 = &v5->track->name;
    trackName._Bx._Buf[0] = 0;
    trackName._Myres = 7;
    trackName._Mysize = 0;
    std::wstring::assign(&trackName, v6, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v23 = &v21[24];
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"_step1", 6u);
    LOBYTE(v30) = 2;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v7 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    if ( &carName != v7 )
    {
      if ( carName._Myres >= 8 )
        operator delete(carName._Bx._Ptr);
      carName._Myres = 7;
      carName._Mysize = 0;
      carName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&carName, v7);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"_step2", 6u);
    LOBYTE(v30) = 3;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v8 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    if ( &carName != v8 )
    {
      if ( carName._Myres >= 8 )
        operator delete(carName._Bx._Ptr);
      carName._Myres = 7;
      carName._Mysize = 0;
      carName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&carName, v8);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"_step3", 6u);
    LOBYTE(v30) = 4;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v9 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    if ( &carName != v9 )
    {
      if ( carName._Myres >= 8 )
        operator delete(carName._Bx._Ptr);
      carName._Myres = 7;
      carName._Mysize = 0;
      carName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&carName, v9);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"_drift", 6u);
    LOBYTE(v30) = 5;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v10 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    if ( &carName != v10 )
    {
      if ( carName._Myres >= 8 )
        operator delete(carName._Bx._Ptr);
      carName._Myres = 7;
      carName._Mysize = 0;
      carName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&carName, v10);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"_S1", 3u);
    LOBYTE(v30) = 6;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v11 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    if ( &carName != v11 )
    {
      if ( carName._Myres >= 8 )
        operator delete(carName._Bx._Ptr);
      carName._Myres = 7;
      carName._Mysize = 0;
      carName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&carName, v11);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"_S2", 3u);
    LOBYTE(v30) = 7;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v12 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    if ( &carName != v12 )
    {
      if ( carName._Myres >= 8 )
        operator delete(carName._Bx._Ptr);
      carName._Myres = 7;
      carName._Mysize = 0;
      carName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&carName, v12);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    std::wstring::wstring((std::wstring *)&v21[24], L"_S3");
    LOBYTE(v30) = 8;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v13 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    std::wstring::operator=(&carName, v13);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    std::wstring::wstring((std::wstring *)&v21[24], L"_s1");
    LOBYTE(v30) = 9;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v14 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    std::wstring::operator=(&carName, v14);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    std::wstring::wstring((std::wstring *)&v21[24], L"_s2");
    LOBYTE(v30) = 10;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v15 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    std::wstring::operator=(&carName, v15);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = &v21[24];
    std::wstring::wstring((std::wstring *)&v21[24], L"_s3");
    LOBYTE(v30) = 11;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, &carName, 0, 0xFFFFFFFF);
    LOBYTE(v30) = 1;
    v16 = cleanCarName(&result, *(std::wstring *)v21, *(std::wstring *)&v21[24]);
    std::wstring::operator=(&carName, v16);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], &carName, 0, 0xFFFFFFFF);
    SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
    *(_DWORD *)&v21[44] = 7;
    *(_DWORD *)&v21[40] = 0;
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], &trackName, 0, 0xFFFFFFFF);
    SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
    if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == Drift )
    {
      std::wstring::wstring((std::wstring *)&v21[24], L"drift_mode");
      SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
    }
    if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == TimeAttack )
    {
      std::wstring::wstring((std::wstring *)&v21[24], L"time_attack_mode");
      SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
    }
    if ( trackName._Myres >= 8 )
      operator delete(trackName._Bx._Ptr);
    trackName._Myres = 7;
    trackName._Mysize = 0;
    trackName._Bx._Buf[0] = 0;
    v30 = -1;
    if ( carName._Myres >= 8 )
      operator delete(carName._Bx._Ptr);
  }
  else
  {
    *(_WORD *)&v21[24] = 0;
    std::wstring::assign((std::wstring *)&v21[24], L"replay_mode", 0xBu);
    SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
  }
  *(_DWORD *)&v21[44] = 0;
  std::wstring::wstring((std::wstring *)&v21[20], L"cfg/controls.ini");
  INIReaderDocuments::INIReaderDocuments(&controlsINI, a2, *(std::wstring *)&v21[20], v21[44]);
  v30 = 12;
  if ( controlsINI.ready )
  {
    std::wstring::wstring(&result, L"INPUT_METHOD");
    LOBYTE(v30) = 13;
    std::wstring::wstring(&trackName, L"HEADER");
    LOBYTE(v30) = 14;
    v17 = INIReader::getString(&controlsINI, &key, &trackName, &result);
    LOBYTE(v30) = 15;
    v18 = std::operator==<wchar_t>(v17, L"X360");
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( trackName._Myres >= 8 )
      operator delete(trackName._Bx._Ptr);
    trackName._Myres = 7;
    trackName._Mysize = 0;
    trackName._Bx._Buf[0] = 0;
    LOBYTE(v30) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v18 )
    {
      *(_DWORD *)&v21[20] = L"controls_x360";
    }
    else
    {
      std::wstring::wstring(&key, L"INPUT_METHOD");
      LOBYTE(v30) = 16;
      std::wstring::wstring(&section, L"HEADER");
      LOBYTE(v30) = 17;
      v19 = INIReader::getString(&controlsINI, &result, &section, &key);
      LOBYTE(v30) = 18;
      v20 = std::operator==<wchar_t>(v19, L"KEYBOARD");
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
      LOBYTE(v30) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( v20 )
        *(_DWORD *)&v21[20] = L"controls_keyboard";
      else
        *(_DWORD *)&v21[20] = L"controls_wheel";
    }
    std::wstring::wstring((std::wstring *)&v21[24], *(const wchar_t **)&v21[20]);
    SteamInterface::incrementStat(this, *(std::wstring *)&v21[24]);
  }
  v30 = -1;
  INIReaderDocuments::~INIReaderDocuments(&controlsINI);
}
