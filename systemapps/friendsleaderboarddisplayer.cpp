#include "friendsleaderboarddisplayer.h
void __userpurge FriendsLeaderboardDisplayer::FriendsLeaderboardDisplayer(FriendsLeaderboardDisplayer *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  const std::wstring *v4; // eax
  SteamInterface *v5; // eax
  Font *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // ebx
  ksgui::ActiveButton *v9; // ebx
  ksgui::ActiveButton *v10; // eax
  const std::wstring *v11; // eax
  ksgui::ActiveButton *v12; // ecx
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  ksgui::ActiveButton *v20; // ecx
  ksgui::ActiveButton *v21; // eax
  Font *v22; // ebx
  ksgui::ActiveButton *v23; // eax
  ksgui::ActiveButton *v24; // ecx
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  const std::wstring *v32; // eax
  ksgui::ActiveButton *v33; // ecx
  ksgui::ActiveButton *v34; // eax
  Texture *v35; // eax
  Texture *v36; // eax
  Texture *v37; // eax
  _BYTE v38[64]; // [esp-8h] [ebp-94h] BYREF
  int _Val; // [esp+38h] [ebp-54h] BYREF
  std::shared_ptr<Font> v40; // [esp+3Ch] [ebp-50h] BYREF
  FriendsLeaderboardDisplayer *v41; // [esp+44h] [ebp-48h]
  std::wstring text; // [esp+48h] [ebp-44h] BYREF
  Texture result; // [esp+60h] [ebp-2Ch] BYREF
  int v44; // [esp+88h] [ebp-4h]

  *(_DWORD *)&v38[28] = 0;
  v41 = this;
  *(_DWORD *)&v38[24] = aSim->game->gui;
  *(_DWORD *)&v38[20] = 7;
  *(_DWORD *)&v38[16] = 0;
  *(_WORD *)v38 = 0;
  std::wstring::assign((std::wstring *)v38, L"FRIENDS_LEADERBOARD", 0x13u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v38, *(ksgui::GUI **)&v38[24], v38[28]);
  v44 = 0;
  this->__vftable = (FriendsLeaderboardDisplayer_vtbl *)&FriendsLeaderboardDisplayer::`vftable';
  this->sim = aSim;
  this->steamInterface = 0;
  this->resetButton = 0;
  this->refreshButton = 0;
  this->texUp.kid = 0;
  this->texUp.fileName._Myres = 7;
  this->texUp.fileName._Mysize = 0;
  this->texUp.fileName._Bx._Buf[0] = 0;
  this->texMark.kid = 0;
  this->texMark.fileName._Myres = 7;
  this->texMark.fileName._Mysize = 0;
  this->texMark.fileName._Bx._Buf[0] = 0;
  this->texDown.kid = 0;
  this->texDown.fileName._Myres = 7;
  this->texDown.fileName._Mysize = 0;
  this->texDown.fileName._Bx._Buf[0] = 0;
  this->leaderboardElements._Myfirst = 0;
  this->leaderboardElements._Mylast = 0;
  this->leaderboardElements._Myend = 0;
  LOBYTE(v44) = 4;
  *(_DWORD *)&v38[28] = 19;
  *(_DWORD *)&v38[24] = L"Friends Leaderboard";
  this->devApp = 0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v38[24], *(unsigned int *)&v38[28]);
  LOBYTE(v44) = 5;
  v4 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v44) = 6;
  this->formTitle->setText(this->formTitle, v4);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v44) = 4;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v5 = GameObject::getGameObject<SteamInterface>(this->sim);
  *(_DWORD *)&v38[28] = this;
  this->steamInterface = v5;
  *(_DWORD *)&v38[4] = &std::_Func_impl<std::_Callable_obj<_lambda_8d056ed3cbf33029f77a1aded06f61a9_,0>,std::allocator<std::_Func_class<void,std::vector<SteamLeaderboardEntry> const &>>,void,std::vector<SteamLeaderboardEntry> const &>::`vftable';
  *(_DWORD *)&v38[8] = this;
  *(_DWORD *)&v38[20] = &v38[4];
  LOBYTE(v44) = 4;
  Event<std::vector<SteamLeaderboardEntry>>::addHandler(
    &this->steamInterface->evOnLeaderboardUpdated,
    *(std::function<void __cdecl(std::vector<SteamLeaderboardEntry> const &)> *)&v38[4],
    *(void **)&v38[28]);
  v6 = (Font *)operator new(0x18u);
  _Val = (int)v6;
  LOBYTE(v44) = 8;
  if ( v6 )
    Font::Font(v6, eFontProportional, 17.0, 0, 0);
  else
    v7 = 0;
  LOBYTE(v44) = 4;
  v40 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v40, v7);
  v8 = this->font._Rep;
  this->font = v40;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v8->_Weaks) )
        v8->_Delete_this(v8);
    }
  }
  Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  ksgui::Form::setSize(this, 450.0, 250.0);
  v9 = (ksgui::ActiveButton *)operator new(0x1C0u);
  _Val = (int)v9;
  v10 = 0;
  LOBYTE(v44) = 9;
  if ( v9 )
  {
    *(_DWORD *)&v38[28] = this->gui;
    *(_DWORD *)&v38[24] = 7;
    *(_DWORD *)&v38[20] = 0;
    *(_WORD *)&v38[4] = 0;
    std::wstring::assign((std::wstring *)&v38[4], L"RESET_BUTTON", 0xCu);
    ksgui::ActiveButton::ActiveButton(v9, *(std::wstring *)&v38[4], *(ksgui::GUI **)&v38[28]);
  }
  LOBYTE(v44) = 4;
  this->resetButton = v10;
  *(_DWORD *)&v38[28] = 7;
  *(_DWORD *)&v38[24] = 0;
  *(_WORD *)&v38[8] = 0;
  std::wstring::assign((std::wstring *)&v38[8], L"content/gui/friendsLeaderboardDisplayer/reset", 0x2Du);
  ksgui::ActiveButton::setMultipleTexture(this->resetButton, (unsigned int)v9, *(std::wstring *)&v38[8]);
  ((void (*)(ksgui::ActiveButton *, int, int))this->resetButton->setSize)(
    this->resetButton,
    1112014848,
    1112014848);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Reset my score", 0xEu);
  LOBYTE(v44) = 10;
  v11 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v44) = 11;
  this->resetButton->setText(this->resetButton, v11);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v12 = this->resetButton;
  v13 = this->rect.right - this->rect.left;
  v14 = v12->rect.right - v12->rect.left;
  v15 = (float)(this->rect.bottom - this->rect.top) - (float)(v12->rect.bottom - v12->rect.top);
  v16 = (float)(v12->rect.bottom - v12->rect.top) + v15;
  v12->rect.top = v15;
  v17 = v13 - v14;
  v18 = v12->rectBase.left;
  v19 = v14 + v17;
  v12->rect.left = v17;
  v12->rect.bottom = v16;
  v12->rect.right = v19;
  if ( v18 == 0.0 && v12->rectBase.top == 0.0 )
  {
    v12->rectBase.left = v17;
    v12->rectBase.top = v15;
    v12->rectBase.right = v19;
    v12->rectBase.bottom = v16;
  }
  v20 = this->resetButton;
  v40._Ptr = (Font *)-1043857408;
  v40._Rep = (std::_Ref_count_base *)1092616192;
  v20->textCoord.x = -25.0;
  LODWORD(v20->textCoord.y) = v40._Rep;
  v21 = this->resetButton;
  *(_DWORD *)&v38[28] = this;
  v21->font._Ptr->scale = 20.0;
  this->resetButton->fontAlign = eAlignRight;
  *(_DWORD *)&v38[4] = &std::_Func_impl<std::_Callable_obj<_lambda_f7932af84dd68b8b3e68cd8d517b0c58_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v38[8] = this;
  *(_DWORD *)&v38[20] = &v38[4];
  LOBYTE(v44) = 4;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->resetButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v38[4],
    *(void **)&v38[28]);
  _Val = (int)this->resetButton;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&v38[28] = 448;
  *(_DWORD *)(_Val + 148) = this;
  v22 = (Font *)operator new(*(unsigned int *)&v38[28]);
  v40._Ptr = v22;
  v23 = 0;
  LOBYTE(v44) = 13;
  if ( v22 )
  {
    *(_DWORD *)&v38[28] = this->gui;
    *(_DWORD *)&v38[24] = 7;
    *(_DWORD *)&v38[20] = 0;
    *(_WORD *)&v38[4] = 0;
    std::wstring::assign((std::wstring *)&v38[4], L"REFRESH_BUTTON", 0xEu);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v22, *(std::wstring *)&v38[4], *(ksgui::GUI **)&v38[28]);
  }
  LOBYTE(v44) = 4;
  this->refreshButton = v23;
  *(_DWORD *)&v38[28] = 7;
  *(_DWORD *)&v38[24] = 0;
  *(_WORD *)&v38[8] = 0;
  std::wstring::assign((std::wstring *)&v38[8], L"content/gui/friendsLeaderboardDisplayer/refresh", 0x2Fu);
  ksgui::ActiveButton::setMultipleTexture(this->refreshButton, (unsigned int)v22, *(std::wstring *)&v38[8]);
  ((void (*)(ksgui::ActiveButton *, int, int))this->refreshButton->setSize)(
    this->refreshButton,
    1112014848,
    1112014848);
  v24 = this->refreshButton;
  v25 = this->rect.bottom - this->rect.top;
  v26 = this->resetButton->rect.bottom - this->resetButton->rect.top;
  v27 = v24->rect.right - v24->rect.left;
  v24->rect.left = 0.0;
  v28 = v25 - v26;
  v29 = v24->rect.bottom - v24->rect.top;
  v24->rect.right = v27;
  v24->rect.top = v28;
  v30 = v28 + v29;
  v31 = v24->rectBase.left;
  v24->rect.bottom = v30;
  if ( v31 == 0.0 && v24->rectBase.top == 0.0 )
  {
    v24->rectBase.left = 0.0;
    v24->rectBase.top = v28;
    v24->rectBase.right = v27;
    v24->rectBase.bottom = v30;
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Refresh", 7u);
  LOBYTE(v44) = 14;
  v32 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v44) = 15;
  this->refreshButton->setText(this->refreshButton, v32);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v33 = this->refreshButton;
  v40._Ptr = (Font *)1103626240;
  v40._Rep = (std::_Ref_count_base *)1092616192;
  v33->textCoord.x = 25.0;
  LODWORD(v33->textCoord.y) = v40._Rep;
  v34 = this->refreshButton;
  *(_DWORD *)&v38[28] = this;
  v34->font._Ptr->scale = 20.0;
  this->refreshButton->fontAlign = eAlignLeft;
  *(_DWORD *)&v38[4] = &std::_Func_impl<std::_Callable_obj<_lambda_17f707116808ff48c53c01cdad86bb7d_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v38[8] = this;
  *(_DWORD *)&v38[20] = &v38[4];
  LOBYTE(v44) = 4;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->refreshButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v38[4],
    *(void **)&v38[28]);
  _Val = (int)this->refreshButton;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&v38[28] = 46;
  *(_DWORD *)&v38[24] = L"content/gui/friendsLeaderboardDisplayer/up.png";
  text._Myres = 7;
  *(_DWORD *)(_Val + 148) = this;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v38[24], *(unsigned int *)&v38[28]);
  LOBYTE(v44) = 17;
  v35 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v44) = 18;
  this->texUp.kid = v35->kid;
  if ( &this->texUp.fileName != &v35->fileName )
    std::wstring::assign(&this->texUp.fileName, &v35->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v44) = 17;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v44) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/friendsLeaderboardDisplayer/down.png", 0x30u);
  LOBYTE(v44) = 19;
  v36 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v44) = 20;
  this->texDown.kid = v36->kid;
  if ( &this->texDown.fileName != &v36->fileName )
    std::wstring::assign(&this->texDown.fileName, &v36->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v44) = 19;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v44) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/friendsLeaderboardDisplayer/marker.png", 0x32u);
  LOBYTE(v44) = 21;
  v37 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v44) = 22;
  this->texMark.kid = v37->kid;
  if ( &this->texMark.fileName != &v37->fileName )
    std::wstring::assign(&this->texMark.fileName, &v37->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v44) = 21;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v44) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->gameMode = GameObject::getGameObject<GameMode>(this->sim);
}
FriendsLeaderboardDisplayer *FriendsLeaderboardDisplayer::`scalar deleting destructor'(FriendsLeaderboardDisplayer *this, unsigned int a2)
{
  FriendsLeaderboardDisplayer::~FriendsLeaderboardDisplayer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FriendsLeaderboardDisplayer::~FriendsLeaderboardDisplayer(FriendsLeaderboardDisplayer *this)
{
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v2; // eax

  this->__vftable = (FriendsLeaderboardDisplayer_vtbl *)&FriendsLeaderboardDisplayer::`vftable';
  v2 = this->leaderboardElements._Myfirst;
  if ( v2 )
  {
    std::vector<KGLShaderCBuffer>::_Destroy(
      (std::vector<FriendsLeaderboardDisplayer::FriendsLeaderboardElement> *)this,
      v2,
      this->leaderboardElements._Mylast);
    operator delete(this->leaderboardElements._Myfirst);
    this->leaderboardElements._Myfirst = 0;
    this->leaderboardElements._Mylast = 0;
    this->leaderboardElements._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->texDown);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texMark);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texUp);
  this->__vftable = (FriendsLeaderboardDisplayer_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void __userpurge FriendsLeaderboardDisplayer::render(FriendsLeaderboardDisplayer *this@<ecx>, int a2@<edi>, int a3@<esi>, float dt)
{
  int v5; // esi
  SessionType v6; // eax
  const std::wstring *v7; // eax
  unsigned int v8; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v9; // edx
  int v10; // eax
  void (__cdecl *v11)(void *); // edi
  int v12; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v13; // edi
  std::wostream *v14; // eax
  Font *v15; // ecx
  unsigned int v16; // eax
  bool v17; // zf
  const std::wstring *v18; // eax
  std::wstring *v19; // ecx
  std::wostream *v20; // eax
  std::wostream *v21; // eax
  const std::wstring *v22; // eax
  std::wostream *v23; // eax
  std::wostream *v24; // eax
  const std::wstring *v25; // eax
  GameMode *v26; // eax
  const std::wstring *v27; // eax
  const std::wstring *g; // [esp+38h] [ebp-188h]
  int a; // [esp+40h] [ebp-180h]
  __int64 v30; // [esp+44h] [ebp-17Ch]
  float v31; // [esp+4Ch] [ebp-174h]
  float x; // [esp+58h] [ebp-168h]
  unsigned int v33; // [esp+58h] [ebp-168h]
  float v34; // [esp+5Ch] [ebp-164h]
  int v35; // [esp+5Ch] [ebp-164h]
  int v36; // [esp+60h] [ebp-160h]
  unsigned int v37; // [esp+64h] [ebp-15Ch]
  int v38; // [esp+68h] [ebp-158h]
  int v39; // [esp+6Ch] [ebp-154h]
  int v40; // [esp+70h] [ebp-150h]
  float v41; // [esp+74h] [ebp-14Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v42; // [esp+78h] [ebp-148h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement le; // [esp+12Ch] [ebp-94h] BYREF
  std::wstring clampedName; // [esp+14Ch] [ebp-74h] BYREF
  std::wstring text; // [esp+164h] [ebp-5Ch] BYREF
  std::wstring result; // [esp+17Ch] [ebp-44h] BYREF
  std::wstring v47; // [esp+194h] [ebp-2Ch] BYREF
  int v48; // [esp+1BCh] [ebp-4h]

  v40 = 0;
  ksgui::Control::render(this, a2, a3, dt, v30, v31);
  v5 = (int)(float)(this->rect.left + 25.0);
  v38 = v5;
  v36 = (int)(float)(this->rect.top + 30.0);
  v6 = RaceManager::getCurrentSessionType(this->sim->raceManager);
  x = (float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left;
  v34 = (float)((float)(this->rect.bottom - this->rect.top) * 0.33333334) + this->rect.top;
  if ( v6 != Hotlap && v6 != Drift && v6 != TimeAttack )
  {
    std::wstring::wstring(&text, L"LEADERBOARDS N.A. FOR CURRENT MODE");
    v48 = 0;
    v7 = acTranslate(&clampedName, &text);
    LOBYTE(v48) = 1;
LABEL_5:
    Font::blitString(this->font._Ptr, x, v34, v7, 1.0, eAlignCenter);
    if ( clampedName._Myres >= 8 )
      operator delete(clampedName._Bx._Ptr);
    clampedName._Myres = 7;
    clampedName._Mysize = 0;
    clampedName._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    return;
  }
  if ( !this->sim->raceManager->penaltiesEnabled )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"ACTIVATE PENALTIES TO COMPETE", 0x1Du);
    v48 = 2;
    v7 = acTranslate(&clampedName, &text);
    LOBYTE(v48) = 3;
    goto LABEL_5;
  }
  if ( this->leaderboardElements._Myfirst == this->leaderboardElements._Mylast )
  {
    std::wstring::wstring(&text, L"NO LEADERBOARDS FOUND");
    v48 = 4;
    v7 = acTranslate(&clampedName, &text);
    LOBYTE(v48) = 5;
    goto LABEL_5;
  }
  v8 = 0;
  v35 = 0;
  v37 = -1;
  if ( this->leaderboardElements._Mylast - this->leaderboardElements._Myfirst )
  {
    v9 = this->leaderboardElements._Myfirst;
    v10 = 0;
    do
    {
      if ( v9[v10].isPlayer )
      {
        v35 = v9[v10].score;
        v37 = v8;
      }
      ++v8;
      ++v10;
    }
    while ( v8 < this->leaderboardElements._Mylast - v9 );
  }
  v11 = operator delete;
  v33 = 0;
  if ( this->leaderboardElements._Mylast - this->leaderboardElements._Myfirst )
  {
    v12 = v5 + 250;
    v39 = 0;
    do
    {
      *(_DWORD *)v42.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v42.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v42.gap68);
      v48 = 6;
      v40 |= 1u;
      std::wiostream::basic_iostream<wchar_t>(&v42, &v42.gap10[8], 0);
      v48 = 7;
      *(_DWORD *)&v42.gap0[*(_DWORD *)(*(_DWORD *)v42.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&v41 + *(_DWORD *)(*(_DWORD *)v42.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v42.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v42.gap10[8]);
      *(_DWORD *)&v42.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v42.gap10[64] = 0;
      *(_DWORD *)&v42.gap10[68] = 0;
      v48 = 9;
      v13 = &this->leaderboardElements._Myfirst[v39];
      le.name._Myres = 7;
      le.name._Mysize = 0;
      le.name._Bx._Buf[0] = 0;
      std::wstring::assign(&le.name, &v13->name, 0, 0xFFFFFFFF);
      le.score = v13->score;
      le.isPlayer = v13->isPlayer;
      LOBYTE(v48) = 10;
      std::wstring::substr(&le.name, &clampedName, 0, 0x19u);
      LOBYTE(v48) = 11;
      v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v42.gap10, "  ");
      std::operator<<<wchar_t>(v14, &clampedName);
      v15 = this->font._Ptr;
      if ( v33 == v37 )
        Font::setColor(v15, 1.0, 0.0, 0.0, 1.0);
      else
        Font::setColor(v15, 1.0, 1.0, 1.0, 1.0);
      GLRenderer::color4f(this->gui->graphics->gl, 1.0, 1.0, 1.0, 1.0);
      v16 = v37;
      v17 = v33 == v37;
      if ( v33 < v37 )
      {
        GraphicsManager::setTexture(this->gui->graphics, 0, &this->texUp);
        GLRenderer::quad(this->gui->graphics->gl, (float)(v38 - 20), (float)v36, 20.0, 20.0, 1, 0);
        v16 = v37;
        v17 = v33 == v37;
      }
      if ( v17 )
      {
        GraphicsManager::setTexture(this->gui->graphics, 0, &this->texMark);
        GLRenderer::quad(this->gui->graphics->gl, (float)(v38 - 20), (float)v36, 20.0, 20.0, 1, 0);
        v16 = v37;
      }
      if ( v33 > v16 )
      {
        GraphicsManager::setTexture(this->gui->graphics, 0, &this->texDown);
        GLRenderer::quad(this->gui->graphics->gl, (float)(v38 - 20), (float)v36, 20.0, 20.0, 1, 0);
      }
      v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &result);
      LOBYTE(v48) = 12;
      Font::blitString(this->font._Ptr, (float)v38, (float)v36, v18, 1.0, eAlignLeft);
      LOBYTE(v48) = 11;
      v11 = operator delete;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      text._Myres = 7;
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
      std::wstring::assign(&text, word_17BE9D8, 0);
      LOBYTE(v48) = 13;
      if ( (v42.gap10[68] & 1) != 0 )
        operator delete(**(void ***)&v42.gap10[20]);
      std::wstreambuf::setg(&v42.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v42.gap10[8], 0, 0);
      v19 = &text;
      *(_DWORD *)&v42.gap10[64] = 0;
      a = *(_DWORD *)&v42.gap10[68] & 0xFFFFFFFE;
      if ( text._Myres >= 8 )
        v19 = (std::wstring *)text._Bx._Ptr;
      *(_DWORD *)&v42.gap10[68] &= 0xFFFFFFFE;
      std::wstringbuf::_Init((std::wstringbuf *)&v42.gap10[8], v19->_Bx._Buf, text._Mysize, a);
      LOBYTE(v48) = 11;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == Hotlap )
      {
        v22 = timeToString(&v47, le.score, 3);
        LOBYTE(v48) = 14;
        std::operator<<<wchar_t>((std::wostream *)v42.gap10, v22);
        LOBYTE(v48) = 11;
        if ( v47._Myres >= 8 )
          operator delete(v47._Bx._Ptr);
        v47._Myres = 7;
        v47._Bx._Buf[0] = 0;
        v47._Mysize = 0;
        if ( v33 != v37 )
        {
          if ( v35 )
          {
            g = timeToDiffString(&result, le.score - v35, 3);
            LOBYTE(v48) = 15;
            v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v42.gap10, "    (");
            v24 = std::operator<<<wchar_t>(v23, g);
            std::operator<<<wchar_t,std::char_traits<wchar_t>>(v24, ")");
            LOBYTE(v48) = 11;
            if ( result._Myres >= 8 )
              operator delete(result._Bx._Ptr);
          }
        }
      }
      else
      {
        v20 = (std::wostream *)std::wostream::operator<<(v42.gap10, le.score);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v20, " pt");
        if ( v33 != v37 && v35 )
        {
          std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v42.gap10, "    (");
          v41 = (float)(le.score - v35);
          if ( v41 > 0.0 )
            std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v42.gap10, "+");
          v21 = (std::wostream *)std::wostream::operator<<(v42.gap10);
          std::operator<<<wchar_t,std::char_traits<wchar_t>>(v21, ")");
        }
      }
      v25 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &result);
      LOBYTE(v48) = 16;
      Font::blitString(this->font._Ptr, (float)v12, (float)v36, v25, 1.0, eAlignLeft);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v36 += 20;
      if ( clampedName._Myres >= 8 )
        operator delete(clampedName._Bx._Ptr);
      clampedName._Myres = 7;
      clampedName._Mysize = 0;
      clampedName._Bx._Buf[0] = 0;
      if ( le.name._Myres >= 8 )
        operator delete(le.name._Bx._Ptr);
      v48 = -1;
      le.name._Bx._Buf[0] = 0;
      le.name._Myres = 7;
      le.name._Mysize = 0;
      *(_DWORD *)&v42.gap0[*(_DWORD *)(*(_DWORD *)v42.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&v41 + *(_DWORD *)(*(_DWORD *)v42.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v42.gap0 + 4) - 104;
      *(_DWORD *)&v42.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v42.gap10[68] & 1) != 0 )
        operator delete(**(void ***)&v42.gap10[20]);
      std::wstreambuf::setg(&v42.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v42.gap10[8], 0, 0);
      *(_DWORD *)&v42.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v42.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v42.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v42.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v42.gap68);
      ++v39;
      ++v33;
    }
    while ( v33 < this->leaderboardElements._Mylast - this->leaderboardElements._Myfirst );
  }
  v26 = this->gameMode;
  if ( v26 && !v26->valid )
  {
    Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    v47._Myres = 7;
    v47._Mysize = 0;
    v47._Bx._Buf[0] = 0;
    std::wstring::assign(&v47, L"Player current perf. not valid!", 0x1Fu);
    v48 = 17;
    v27 = acTranslate(&result, &v47);
    LOBYTE(v48) = 18;
    Font::blitString(
      this->font._Ptr,
      (float)((float)(this->rect.right - this->rect.left) * 0.5) + this->rect.left,
      (float)v36,
      v27,
      1.0,
      eAlignCenter);
    if ( result._Myres >= 8 )
      v11(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v47._Myres >= 8 )
      v11(v47._Bx._Ptr);
  }
}
