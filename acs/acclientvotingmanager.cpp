#include "acclientvotingmanager.h
void ACClientVotingManager::ACClientVotingManager(ACClientVotingManager *this, Sim *aSim, ACClient *aClient)
{
  Console *v4; // eax
  Console *v5; // eax
  Console *v6; // eax
  _BYTE v7[48]; // [esp-30h] [ebp-90h] BYREF
  _BYTE *v8; // [esp+2Ch] [ebp-34h]
  _BYTE *v9; // [esp+30h] [ebp-30h]
  ACClientVotingManager *v10; // [esp+34h] [ebp-2Ch]
  std::wstring name; // [esp+38h] [ebp-28h] BYREF
  int v12; // [esp+5Ch] [ebp-4h]

  v10 = this;
  *(_DWORD *)&v7[44] = aSim->game;
  *(_DWORD *)&v7[40] = 7;
  *(_DWORD *)&v7[36] = 0;
  *(_WORD *)&v7[20] = 0;
  std::wstring::assign((std::wstring *)&v7[20], L"AACLIENT_VOTING_MANAGER", 0x17u);
  GameObject::GameObject(this, *(std::wstring *)&v7[20], *(Game **)&v7[44]);
  this->__vftable = (ACClientVotingManager_vtbl *)&ACClientVotingManager::`vftable';
  this->sim = aSim;
  v12 = 0;
  this->currentVote.voteType = eVoteUnkonw;
  this->currentVote.hasVoted = 0;
  this->currentVote.timeLeftSeconds = 0.0;
  this->currentVote.maxTime = 0.0;
  this->currentVote.target = 0;
  Trigger::Trigger(&this->btYesTrigger);
  LOBYTE(v12) = 1;
  Trigger::Trigger(&this->btNoTrigger);
  *(_DWORD *)&v7[20] = &std::_Func_impl<std::_Callable_obj<_lambda_27ea4f82da8c4bad790896e1e9dfe62e_,0>,std::allocator<std::_Func_class<void,ReceivedVoteDef const &>>,void,ReceivedVoteDef const &>::`vftable';
  *(_DWORD *)&v7[24] = this;
  *(_DWORD *)&v7[36] = &v7[20];
  LOBYTE(v12) = 2;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&aClient->evOnVoteReceived,
    *(std::function<void __cdecl(SessionInfo const &)> *)&v7[20],
    this);
  *(_DWORD *)&v7[20] = &std::_Func_impl<std::_Callable_obj<_lambda_96080666a02d8705771faf4a925a4ff0_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v7[24] = this;
  *(_DWORD *)&v7[36] = &v7[20];
  LOBYTE(v12) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&aClient->evOnVoteNotPassed,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v7[20],
    this);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"vote_next", 9u);
  v8 = &v7[24];
  *(_DWORD *)&v7[24] = &std::_Func_impl<std::_Callable_obj<_lambda_eb39b18eba66b5c84fa469eaebd8b4b2_,0>,std::allocator<std::_Func_class<std::wstring,>>,std::wstring,>::`vftable';
  *(_DWORD *)&v7[40] = &v7[24];
  v9 = v7;
  *(_DWORD *)v7 = &std::_Func_impl<std::_Callable_obj<_lambda_64a2e5a7b602561a4360b6ad55ab368b_,0>,std::allocator<std::_Func_class<bool,std::wstring>>,bool,std::wstring>::`vftable';
  *(_DWORD *)&v7[4] = this;
  *(_DWORD *)&v7[16] = v7;
  LOBYTE(v12) = 9;
  v4 = Console::singleton();
  LOBYTE(v12) = 5;
  Console::addCommand(
    v4,
    &name,
    *(std::function<bool __cdecl(std::wstring)> *)v7,
    *(std::function<std::wstring __cdecl(void)> *)&v7[24]);
  LOBYTE(v12) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"vote_restart", 0xCu);
  v9 = &v7[24];
  *(_DWORD *)&v7[24] = &std::_Func_impl<std::_Callable_obj<_lambda_24cbc0b64d4fe93ea5626370da3f9258_,0>,std::allocator<std::_Func_class<std::wstring,>>,std::wstring,>::`vftable';
  *(_DWORD *)&v7[40] = &v7[24];
  v8 = v7;
  *(_DWORD *)v7 = &std::_Func_impl<std::_Callable_obj<_lambda_c30245db0ab22c60bd421578e1fa631a_,0>,std::allocator<std::_Func_class<bool,std::wstring>>,bool,std::wstring>::`vftable';
  *(_DWORD *)&v7[4] = this;
  *(_DWORD *)&v7[16] = v7;
  LOBYTE(v12) = 14;
  v5 = Console::singleton();
  LOBYTE(v12) = 10;
  Console::addCommand(
    v5,
    &name,
    *(std::function<bool __cdecl(std::wstring)> *)v7,
    *(std::function<std::wstring __cdecl(void)> *)&v7[24]);
  LOBYTE(v12) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"vote_kick", 9u);
  v9 = &v7[24];
  *(_DWORD *)&v7[24] = &std::_Func_impl<std::_Callable_obj<_lambda_103f01dfb6db843aa824736d7104cc2c_,0>,std::allocator<std::_Func_class<std::wstring,>>,std::wstring,>::`vftable';
  *(_DWORD *)&v7[40] = &v7[24];
  v8 = v7;
  *(_DWORD *)v7 = &std::_Func_impl<std::_Callable_obj<_lambda_8d19dac72f07b22f55a6368dd5bc5841_,0>,std::allocator<std::_Func_class<bool,std::wstring>>,bool,std::wstring>::`vftable';
  *(_DWORD *)&v7[4] = this;
  *(_DWORD *)&v7[16] = v7;
  LOBYTE(v12) = 19;
  v6 = Console::singleton();
  LOBYTE(v12) = 15;
  Console::addCommand(
    v6,
    &name,
    *(std::function<bool __cdecl(std::wstring)> *)v7,
    *(std::function<std::wstring __cdecl(void)> *)&v7[24]);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
ACClientVotingManager *ACClientVotingManager::`scalar deleting destructor'(ACClientVotingManager *this, unsigned int a2)
{
  this->__vftable = (ACClientVotingManager_vtbl *)&ACClientVotingManager::`vftable';
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->btNoTrigger);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->btYesTrigger);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACClientVotingManager::update(ACClientVotingManager *this, float dt)
{
  SHORT v3; // ax
  bool v4; // bl
  SHORT v5; // ax
  bool v6; // bh
  int v7; // esi
  CarAvatar *v8; // ecx
  Sim *v9; // ecx
  Sim *v10; // ecx
  float v11; // xmm0_4
  int v12; // eax
  std::wostream *v13; // eax
  VoteType v14; // eax
  __int32 v15; // eax
  const std::wstring *v16; // eax
  Sim *v17; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v18; // ecx
  const std::wstring *v19; // esi
  DriverInfo *v20; // ecx
  std::wstring *v21; // eax
  const std::wstring *v22; // eax
  SystemMessage *v23; // ecx
  const std::wstring *v24; // eax
  Sim *v25; // ecx
  const std::wstring *v26; // eax
  Sim *v27; // ecx
  int v28; // [esp-4h] [ebp-1E4h]
  int v29; // [esp+14h] [ebp-1CCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v30; // [esp+18h] [ebp-1C8h] BYREF
  std::wstring imessage; // [esp+C8h] [ebp-118h] BYREF
  std::wstring description; // [esp+E0h] [ebp-100h] BYREF
  std::wstring v33; // [esp+F8h] [ebp-E8h] BYREF
  std::wstring v34; // [esp+110h] [ebp-D0h] BYREF
  std::wstring v35; // [esp+128h] [ebp-B8h] BYREF
  std::wstring result; // [esp+140h] [ebp-A0h] BYREF
  std::wstring v37; // [esp+158h] [ebp-88h] BYREF
  std::wstring v38; // [esp+170h] [ebp-70h] BYREF
  std::wstring v39; // [esp+188h] [ebp-58h] BYREF
  std::wstring v40; // [esp+1A0h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v41; // [esp+1B8h] [ebp-28h] BYREF
  int v42; // [esp+1DCh] [ebp-4h]

  v29 = 0;
  v3 = GetAsyncKeyState(89);
  v4 = Trigger::ignoreSubsequentTrue(&this->btYesTrigger, v3 != 0) && !this->sim->escMenu->visible;
  v5 = GetAsyncKeyState(78);
  v6 = Trigger::ignoreSubsequentTrue(&this->btNoTrigger, v5 != 0) && !this->sim->escMenu->visible;
  if ( this->currentVote.timeLeftSeconds > 0.0 && !this->currentVote.hasVoted )
  {
    v7 = -1;
    if ( ACClient::getCurrentVoteType(this->sim->client) == eVoteKickUser )
    {
      v8 = this->currentVote.target;
      if ( v8 )
        v7 = CarAvatar::getGuid(v8);
    }
    if ( v4 )
    {
      SystemMessage::clearMessage(this->sim->systemMessage);
      ACClient::sendVote(this->sim->client, this->currentVote.voteType, 1, v7);
      std::wstring::wstring(&description, L"Your vote has been submitted");
      v42 = 0;
      std::wstring::wstring(&imessage, L"You voted YES");
      v9 = this->sim;
      LOBYTE(v42) = 1;
      SystemMessage::addMessage(v9->systemMessage, &imessage, &description, eServerVote);
      if ( imessage._Myres >= 8 )
        operator delete(imessage._Bx._Ptr);
      imessage._Myres = 7;
      imessage._Mysize = 0;
      imessage._Bx._Buf[0] = 0;
      v42 = -1;
      if ( description._Myres >= 8 )
        operator delete(description._Bx._Ptr);
      this->currentVote.hasVoted = 1;
    }
    if ( v6 )
    {
      SystemMessage::clearMessage(this->sim->systemMessage);
      ACClient::sendVote(this->sim->client, this->currentVote.voteType, 0, v7);
      std::wstring::wstring(&description, L"Your vote has been submitted");
      v42 = 2;
      std::wstring::wstring(&imessage, L"You voted NO");
      v10 = this->sim;
      LOBYTE(v42) = 3;
      SystemMessage::addMessage(v10->systemMessage, &imessage, &description, eServerVote);
      if ( imessage._Myres >= 8 )
        operator delete(imessage._Bx._Ptr);
      imessage._Myres = 7;
      imessage._Mysize = 0;
      imessage._Bx._Buf[0] = 0;
      v42 = -1;
      if ( description._Myres >= 8 )
        operator delete(description._Bx._Ptr);
      this->currentVote.hasVoted = 1;
    }
  }
  v11 = this->currentVote.timeLeftSeconds - dt;
  this->currentVote.timeLeftSeconds = v11;
  if ( v11 > 0.0 && !this->currentVote.hasVoted )
  {
    *(_DWORD *)v30.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v30.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v30.gap68);
    v42 = 4;
    v29 = 1;
    std::wiostream::basic_iostream<wchar_t>(&v30, &v30.gap10[8], 0);
    v42 = 5;
    *(_DWORD *)&v30.gap0[*(_DWORD *)(*(_DWORD *)v30.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v29 + *(_DWORD *)(*(_DWORD *)v30.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v30.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v30.gap10[8]);
    *(_DWORD *)&v30.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v30.gap10[64] = 0;
    *(_DWORD *)&v30.gap10[68] = 0;
    v12 = (int)this->currentVote.timeLeftSeconds;
    v42 = 7;
    v28 = v12;
    v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v30.gap10, "Seconds remaining ");
    std::wostream::operator<<(v13, v28);
    v14 = this->currentVote.voteType;
    if ( v14 )
    {
      v15 = v14 - 1;
      if ( v15 )
      {
        if ( v15 == 1 )
        {
          v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v40);
          v20 = &this->currentVote.target->driverInfo;
          LOBYTE(v42) = 12;
          v21 = std::operator+<wchar_t>(&v38, L"Kick ", &v20->name);
          LOBYTE(v42) = 13;
          v22 = std::operator+<wchar_t>(&v41.name, v21, L" voting in progress. Press key \"Y\" or \"N\" to vote ");
          v23 = this->sim->systemMessage;
          LOBYTE(v42) = 14;
          SystemMessage::addMessage(v23, v22, v19, eServerKickVoting);
          std::wstring::~wstring(&v41);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v38);
          v18 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v40;
        }
        else
        {
          std::wstring::wstring(&v33, L"Voting unknown vote: ");
          LOBYTE(v42) = 15;
          v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &result);
          v17 = this->sim;
          LOBYTE(v42) = 16;
          SystemMessage::addMessage(v17->systemMessage, &v33, v16, eServerVote);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v18 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v33;
        }
      }
      else
      {
        std::wstring::wstring(&v35, L"Restart session voting in progress. Press key \"Y\" or \"N\" to vote ");
        LOBYTE(v42) = 10;
        v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v37);
        v25 = this->sim;
        LOBYTE(v42) = 11;
        SystemMessage::addMessage(v25->systemMessage, &v35, v24, eServerSessionVoting);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v37);
        v18 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v35;
      }
    }
    else
    {
      std::wstring::wstring(&v34, L"Skip session voting in progress. Press key \"Y\" or \"N\" to vote ");
      LOBYTE(v42) = 8;
      v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v39);
      v27 = this->sim;
      LOBYTE(v42) = 9;
      SystemMessage::addMessage(v27->systemMessage, &v34, v26, eServerSessionVoting);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v39);
      v18 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v34;
    }
    std::wstring::~wstring(v18);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v30);
  }
}
