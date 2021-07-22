#include "acstandardleaderboard.h
void ACStandardLeaderboard::ACStandardLeaderboard(ACStandardLeaderboard *this, Sim *aSim, int numberOfRows, bool aFocusOnPlayer)
{
  std::_Tree_node<std::pair<CarAvatar * const,Texture>,void *> *v5; // eax
  Font *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // ebp
  Font *v9; // eax
  Font *v10; // eax
  std::_Ref_count_base *v11; // ebp
  Font *v12; // eax
  Font *v13; // eax
  std::_Ref_count_base *v14; // ebp
  Font *v15; // eax
  Font *v16; // eax
  std::_Ref_count_base *v17; // ebp
  unsigned int i; // ebp
  CarAvatar *v19; // eax
  Sim *v20; // ecx
  CarAvatar *v21; // eax
  std::wstring *v22; // esi
  CarAvatar *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  const std::wstring *v27; // eax
  Texture *v28; // esi
  CarAvatar **v29; // eax
  CarAvatar *v30; // ecx
  const std::wstring *v31; // esi
  Texture *v32; // eax
  void *v33; // ecx
  const std::wstring *v34; // eax
  ksgui::ActiveButton *v35; // esi
  ksgui::ActiveButton *v36; // eax
  ksgui::ActiveButton *v37; // ecx
  ksgui::ActiveButton_vtbl *v38; // eax
  ksgui::ActiveButton *v39; // ecx
  std::vector<ksgui::Control *> *v40; // ebp
  ksgui::Control **v41; // eax
  int v42; // esi
  ksgui::Control **v43; // edx
  ksgui::Control **v44; // eax
  ksgui::ActiveButton *v45; // esi
  ksgui::ActiveButton *v46; // eax
  ksgui::ActiveButton *v47; // ecx
  ksgui::ActiveButton_vtbl *v48; // eax
  unsigned int v49; // esi
  std::wostream *v50; // eax
  ksgui::ActiveButton *v51; // esi
  int v52; // eax
  int v53; // esi
  std::wostream *v54; // eax
  int v55; // eax
  Sim *v56; // ecx
  ksgui::Control *v57; // esi
  ksgui::Control *v58; // eax
  ksgui::Control *v59; // eax
  ksgui::Control *v60; // eax
  const std::wstring *v61; // eax
  ksgui::Control *v62; // ecx
  ksgui::Control_vtbl *v63; // eax
  ksgui::Control *v64; // esi
  ksgui::Control *v65; // eax
  ksgui::Control *v66; // eax
  ksgui::Control *v67; // eax
  __m128i v68; // xmm0
  const std::wstring *v69; // eax
  ksgui::Control *v70; // ecx
  ksgui::Control_vtbl *v71; // eax
  ksgui::ActiveButton *v72; // esi
  ksgui::ActiveButton *v73; // eax
  ksgui::ActiveButton *v74; // ecx
  ksgui::ActiveButton_vtbl *v75; // eax
  ACStandardLeaderboard::{ctor}::__l25::<lambda_3825e3cd8294afc0dd1b67c8ed39c176> *v76; // eax
  _BYTE v77[56]; // [esp+64h] [ebp-278h] BYREF
  int _Val; // [esp+B4h] [ebp-228h] BYREF
  vec4f button; // [esp+B8h] [ebp-224h] OVERLAPPED BYREF
  int v80; // [esp+C8h] [ebp-214h]
  int v81; // [esp+CCh] [ebp-210h]
  ksgui::ActiveButton *v82; // [esp+D0h] [ebp-20Ch] BYREF
  ACStandardLeaderboard *v83; // [esp+D4h] [ebp-208h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+D8h] [ebp-204h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > wsButtonImage; // [esp+188h] [ebp-154h] BYREF
  std::wstring iname; // [esp+238h] [ebp-A4h] BYREF
  std::wstring v87; // [esp+250h] [ebp-8Ch] BYREF
  std::wstring filename; // [esp+268h] [ebp-74h] BYREF
  std::wstring v89; // [esp+280h] [ebp-5Ch] BYREF
  Texture v90; // [esp+298h] [ebp-44h] BYREF
  std::wstring result; // [esp+2B4h] [ebp-28h] BYREF
  int v92; // [esp+2D8h] [ebp-4h]

  v83 = this;
  _Val = 0;
  v80 = 0;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"RACE_CONTROL_KICK_PLAYER", 0x18u);
  v92 = 0;
  ksgui::Control::Control(this, &iname, aSim->game->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->focusOnPlayer = aFocusOnPlayer;
  this->__vftable = (ACStandardLeaderboard_vtbl *)&ACStandardLeaderboard::`vftable';
  this->sessionID = 0;
  this->rows = numberOfRows;
  this->currentPage = 0;
  this->selectedCarIndex = -1;
  this->showModeButtons = 0;
  this->printedCars._Myfirst = 0;
  this->printedCars._Mylast = 0;
  this->printedCars._Myend = 0;
  this->btNextPage = 0;
  this->btPreviousPage = 0;
  this->btKick = 0;
  this->btSessions._Myfirst = 0;
  this->btSessions._Mylast = 0;
  this->btSessions._Myend = 0;
  this->btEntryList = 0;
  this->btTimeTable = 0;
  this->btLapTable = 0;
  this->buttonsFont._Ptr = 0;
  this->buttonsFont._Rep = 0;
  this->mode = eEntryList;
  this->lastMode = eEntryList;
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  this->dataFont._Ptr = 0;
  this->dataFont._Rep = 0;
  this->blackFont._Ptr = 0;
  this->blackFont._Rep = 0;
  LOBYTE(v92) = 8;
  this->sim = aSim;
  this->avatarToBeKicked = 0;
  this->skinTextures._Myhead = 0;
  this->skinTextures._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<CarAvatar * const,Texture>>>::_Buyheadnode(&this->skinTextures);
  this->skinTextures._Myhead = v5;
  this->txMiniFinish.kid = 0;
  this->txMiniFinish.fileName._Myres = 7;
  this->txMiniFinish.fileName._Mysize = 0;
  this->txMiniFinish.fileName._Bx._Buf[0] = 0;
  LOBYTE(v92) = 10;
  *(_DWORD *)&v77[24] = 24;
  this->ui = eRaceControl;
  this->isLoaded = 0;
  this->entry_nameX = 0.0;
  this->entry_carX = 0.0;
  this->entry_tyresX = 0.0;
  this->entry_ballastX = 0.0;
  this->entry_lapsX = 0.0;
  this->entry_timeX = 0.0;
  this->entry_gapX = 0.0;
  this->entry_pingX = 0.0;
  this->entry_kickX = 0.0;
  this->entry_flagX = 0.0;
  this->time_nameX = 0.0;
  this->time_carX = 0.0;
  this->time_lastlapX = 0.0;
  this->time_deltaX = 0.0;
  this->time_timeX = 0.0;
  this->time_gapX = 0.0;
  this->time_pingX = 0.0;
  this->time_kickX = 0.0;
  this->time_flagX = 0.0;
  this->wtop1 = 0.0;
  v6 = (Font *)operator new(*(unsigned int *)&v77[24]);
  LODWORD(button.x) = v6;
  LOBYTE(v92) = 11;
  if ( v6 )
    Font::Font(v6, eFontMonospaced, 14.0, 1, 1);
  else
    v7 = 0;
  LOBYTE(v92) = 10;
  *(_QWORD *)&button.x = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&button, v7);
  v8 = this->titleFont._Rep;
  this->titleFont = *(std::shared_ptr<Font> *)&button.x;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Weaks, 0xFFFFFFFF) )
        v8->_Delete_this(v8);
    }
  }
  v9 = (Font *)operator new(0x18u);
  LODWORD(button.x) = v9;
  LOBYTE(v92) = 12;
  if ( v9 )
    Font::Font(v9, eFontMonospaced, 14.0, 1, 1);
  else
    v10 = 0;
  LOBYTE(v92) = 10;
  *(_QWORD *)&button.x = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&button, v10);
  v11 = this->buttonsFont._Rep;
  this->buttonsFont = *(std::shared_ptr<Font> *)&button.x;
  if ( v11 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v11->_Uses, 0xFFFFFFFF) )
    {
      v11->_Destroy(v11);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v11->_Weaks, 0xFFFFFFFF) )
        v11->_Delete_this(v11);
    }
  }
  v12 = (Font *)operator new(0x18u);
  LODWORD(button.x) = v12;
  LOBYTE(v92) = 13;
  if ( v12 )
    Font::Font(v12, eFontMonospaced, 14.0, 0, 1);
  else
    v13 = 0;
  LOBYTE(v92) = 10;
  *(_QWORD *)&button.x = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&button, v13);
  v14 = this->dataFont._Rep;
  this->dataFont = *(std::shared_ptr<Font> *)&button.x;
  if ( v14 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v14->_Uses, 0xFFFFFFFF) )
    {
      v14->_Destroy(v14);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v14->_Weaks, 0xFFFFFFFF) )
        v14->_Delete_this(v14);
    }
  }
  v15 = (Font *)operator new(0x18u);
  LODWORD(button.x) = v15;
  LOBYTE(v92) = 14;
  if ( v15 )
    Font::Font(v15, eFontMonospaced, 14.0, 0, 1);
  else
    v16 = 0;
  LOBYTE(v92) = 10;
  *(_QWORD *)&button.x = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&button, v16);
  v17 = this->blackFont._Rep;
  this->blackFont = *(std::shared_ptr<Font> *)&button.x;
  if ( v17 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v17->_Uses, 0xFFFFFFFF) )
    {
      v17->_Destroy(v17);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v17->_Weaks) )
        v17->_Delete_this(v17);
    }
  }
  Font::setColor(this->blackFont._Ptr, 0.0, 0.0, 0.0, 1.0);
  for ( i = 0; i < this->sim->cars._Mylast - this->sim->cars._Myfirst; ++i )
  {
    v19 = Sim::getCar(this->sim, i);
    v20 = this->sim;
    LODWORD(button.x) = v19;
    v21 = Sim::getCar(v20, i);
    v22 = CarAvatar::getCurrentSkin(v21, &result);
    LOBYTE(v92) = 15;
    v23 = Sim::getCar(this->sim, i);
    v24 = std::operator+<wchar_t>(&v87, L"content/cars/", &v23->unixName);
    LOBYTE(v92) = 16;
    v25 = std::operator+<wchar_t>(&filename, v24, L"/skins/");
    LOBYTE(v92) = 17;
    v26 = std::operator+<wchar_t>(&v89, v25, v22);
    LOBYTE(v92) = 18;
    v27 = std::operator+<wchar_t>(&iname, v26, L"/livery.png");
    LOBYTE(v92) = 19;
    v28 = ResourceStore::getTexture(this->sim->game->graphics->resourceStore._Myptr, &v90, v27, 0);
    LOBYTE(v92) = 20;
    v29 = std::map<CarAvatar *,Texture>::operator[](&this->skinTextures, (CarAvatar **)&button);
    v30 = (CarAvatar *)v28->kid;
    v31 = &v28->fileName;
    *v29 = v30;
    if ( v29 + 1 != (CarAvatar **)v31 )
      std::wstring::assign((std::wstring *)(v29 + 1), v31, 0, 0xFFFFFFFF);
    LOBYTE(v92) = 19;
    OnSetupAppCreated::~OnSetupAppCreated(&v90);
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    if ( v89._Myres >= 8 )
      operator delete(v89._Bx._Ptr);
    v89._Myres = 7;
    v89._Mysize = 0;
    v89._Bx._Buf[0] = 0;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    if ( v87._Myres >= 8 )
      operator delete(v87._Bx._Ptr);
    LOBYTE(v92) = 10;
    v87._Myres = 7;
    v87._Mysize = 0;
    v87._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/texture/mini_finish.png", 0x1Fu);
  LOBYTE(v92) = 21;
  v32 = ResourceStore::getTexture(this->sim->game->graphics->resourceStore._Myptr, &v90, &iname, 0);
  LOBYTE(v92) = 22;
  v33 = v32->kid;
  v34 = &v32->fileName;
  this->txMiniFinish.kid = v33;
  if ( &this->txMiniFinish.fileName != v34 )
    std::wstring::assign(&this->txMiniFinish.fileName, v34, 0, 0xFFFFFFFF);
  LOBYTE(v92) = 21;
  OnSetupAppCreated::~OnSetupAppCreated(&v90);
  LOBYTE(v92) = 10;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v35 = (ksgui::ActiveButton *)operator new(0x1C0u);
  LODWORD(button.x) = v35;
  v36 = 0;
  LOBYTE(v92) = 23;
  if ( v35 )
  {
    *(_DWORD *)&v77[24] = this->sim->game->gui;
    *(_DWORD *)&v77[20] = 7;
    *(_DWORD *)&v77[16] = 0;
    *(_WORD *)v77 = 0;
    std::wstring::assign((std::wstring *)v77, L"BUT_VOTE_NEXT_PAGE", 0x12u);
    ksgui::ActiveButton::ActiveButton(v35, *(std::wstring *)v77, *(ksgui::GUI **)&v77[24]);
  }
  LOBYTE(v92) = 10;
  this->btNextPage = v36;
  *(_DWORD *)&v77[24] = 7;
  *(_DWORD *)&v77[20] = 0;
  *(_WORD *)&v77[4] = 0;
  std::wstring::assign((std::wstring *)&v77[4], L"content/gui/raceControl/right_icon", 0x22u);
  ksgui::ActiveButton::setMultipleTexture(this->btNextPage, (unsigned int)operator delete, *(std::wstring *)&v77[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, word_17BE9D8, 0);
  LOBYTE(v92) = 24;
  this->btNextPage->setText(this->btNextPage, &iname);
  LOBYTE(v92) = 10;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btNextPage->setSize)(
    this->btNextPage,
    1109393408,
    1109393408);
  *(_DWORD *)v77 = &std::_Func_impl<std::_Callable_obj<_lambda_3bca28c9cccc021e25a9bccfd24dd075_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v77[4] = this;
  *(_DWORD *)&v77[16] = v77;
  LOBYTE(v92) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->btNextPage->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v77,
    this);
  v37 = this->btNextPage;
  if ( v37->visible )
  {
    v38 = v37->__vftable;
    *(_DWORD *)&v77[24] = 0;
    v37->visible = 0;
    ((void (__stdcall *)(_DWORD))v38->onVisibleChanged)(*(_DWORD *)&v77[24]);
  }
  v39 = this->btNextPage;
  v40 = &this->controls;
  v41 = this->controls._Mylast;
  _Val = (int)v39;
  v82 = v39;
  if ( &v82 >= v41 || v40->_Myfirst > &v82 )
  {
    if ( v41 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v39 = (ksgui::ActiveButton *)_Val;
    }
    v44 = this->controls._Mylast;
    if ( v44 )
      *v44 = v39;
  }
  else
  {
    v42 = &v82 - (ksgui::ActiveButton **)v40->_Myfirst;
    if ( v41 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v39 = (ksgui::ActiveButton *)_Val;
    }
    v43 = this->controls._Mylast;
    if ( v43 )
      *v43 = v40->_Myfirst[v42];
  }
  ++this->controls._Mylast;
  *(_DWORD *)&v77[24] = 448;
  v39->parent = this;
  v45 = (ksgui::ActiveButton *)operator new(*(unsigned int *)&v77[24]);
  LODWORD(button.x) = v45;
  v46 = 0;
  LOBYTE(v92) = 26;
  if ( v45 )
  {
    *(_DWORD *)&v77[24] = this->sim->game->gui;
    *(_DWORD *)&v77[20] = 7;
    *(_DWORD *)&v77[16] = 0;
    *(_WORD *)v77 = 0;
    std::wstring::assign((std::wstring *)v77, L"BUT_VOTE_NEXT_PAGE", 0x12u);
    ksgui::ActiveButton::ActiveButton(v45, *(std::wstring *)v77, *(ksgui::GUI **)&v77[24]);
  }
  LOBYTE(v92) = 10;
  this->btPreviousPage = v46;
  *(_DWORD *)&v77[24] = 7;
  *(_DWORD *)&v77[20] = 0;
  *(_WORD *)&v77[4] = 0;
  std::wstring::assign((std::wstring *)&v77[4], L"content/gui/raceControl/left_icon", 0x21u);
  ksgui::ActiveButton::setMultipleTexture(this->btPreviousPage, (unsigned int)operator delete, *(std::wstring *)&v77[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, word_17BE9D8, 0);
  LOBYTE(v92) = 27;
  this->btPreviousPage->setText(this->btPreviousPage, &iname);
  LOBYTE(v92) = 10;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btPreviousPage->setSize)(
    this->btPreviousPage,
    1109393408,
    1109393408);
  *(_DWORD *)v77 = &std::_Func_impl<std::_Callable_obj<_lambda_1a8360018460b8efe31fd7db7eb348cc_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v77[4] = this;
  *(_DWORD *)&v77[16] = v77;
  LOBYTE(v92) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->btPreviousPage->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v77,
    this);
  v47 = this->btPreviousPage;
  if ( v47->visible )
  {
    v48 = v47->__vftable;
    *(_DWORD *)&v77[24] = 0;
    v47->visible = 0;
    ((void (__stdcall *)(_DWORD))v48->onVisibleChanged)(*(_DWORD *)&v77[24]);
  }
  _Val = (int)this->btPreviousPage;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  v49 = 0;
  v81 = 0;
  *(_DWORD *)(_Val + 148) = this;
  if ( RaceManager::getSessionCount(this->sim->raceManager) )
  {
    do
    {
      *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(ws.gap68);
      LOBYTE(v92) = 29;
      v80 |= 4u;
      _Val = v80;
      std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
      v92 = 30;
      *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(ACStandardLeaderboard **)((char *)&v83 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = (ACStandardLeaderboard *)(*(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104);
      std::wstreambuf::wstreambuf(&ws.gap10[8]);
      *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&ws.gap10[64] = 0;
      *(_DWORD *)&ws.gap10[68] = 0;
      *(_DWORD *)&v77[24] = v49;
      LOBYTE(v92) = 32;
      v50 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)ws.gap10, "BUT_SESSION_");
      std::wostream::operator<<(v50, *(_DWORD *)&v77[24]);
      v51 = (ksgui::ActiveButton *)operator new(0x1C0u);
      LODWORD(button.x) = v51;
      LOBYTE(v92) = 33;
      if ( v51 )
      {
        *(_DWORD *)&v77[24] = this->sim->game->gui;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &ws,
          (std::wstring *)v77);
        ksgui::ActiveButton::ActiveButton(v51, *(std::wstring *)v77, *(ksgui::GUI **)&v77[24]);
        v53 = v52;
      }
      else
      {
        v53 = 0;
      }
      LOBYTE(v92) = 32;
      LODWORD(button.x) = v53;
      *(_DWORD *)wsButtonImage.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)wsButtonImage.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(wsButtonImage.gap68);
      LOBYTE(v92) = 34;
      v80 |= 8u;
      _Val = v80;
      std::wiostream::basic_iostream<wchar_t>(&wsButtonImage, &wsButtonImage.gap10[8], 0);
      v92 = 35;
      *(_DWORD *)&wsButtonImage.gap0[*(_DWORD *)(*(_DWORD *)wsButtonImage.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&ws.gap68[*(_DWORD *)(*(_DWORD *)wsButtonImage.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)wsButtonImage.gap0
                                                                                            + 4)
                                                                                - 104;
      std::wstreambuf::wstreambuf(&wsButtonImage.gap10[8]);
      *(_DWORD *)&wsButtonImage.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&wsButtonImage.gap10[64] = 0;
      *(_DWORD *)&wsButtonImage.gap10[68] = 0;
      LOBYTE(v92) = 37;
      *(_DWORD *)&v77[24] = v81;
      v54 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
              (std::wostream *)wsButtonImage.gap10,
              L"content/gui/raceControl/session_");
      std::wostream::operator<<(v54, *(_DWORD *)&v77[24]);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
        &wsButtonImage,
        (std::wstring *)&v77[4]);
      ksgui::ActiveButton::setMultipleTexture(
        (ksgui::ActiveButton *)v53,
        (unsigned int)operator delete,
        *(std::wstring *)&v77[4]);
      iname._Myres = 7;
      iname._Mysize = 0;
      iname._Bx._Buf[0] = 0;
      std::wstring::assign(&iname, word_17BE9D8, 0);
      LOBYTE(v92) = 38;
      (*(void (**)(int, std::wstring *))(*(_DWORD *)v53 + 68))(v53, &iname);
      LOBYTE(v92) = 37;
      if ( iname._Myres >= 8 )
        operator delete(iname._Bx._Ptr);
      (*(void (**)(int, int, int))(*(_DWORD *)v53 + 28))(v53, 1109393408, 1109393408);
      *(_DWORD *)v77 = &std::_Func_impl<std::_Callable_obj<_lambda_04c3fdb93060f2f1a1911efbe2e12fe2_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
      *(_DWORD *)&v77[8] = v81;
      *(_DWORD *)&v77[4] = this;
      *(_DWORD *)&v77[16] = v77;
      LOBYTE(v92) = 37;
      Event<ksgui::OnControlClicked>::addHandler(
        (Event<OnMouseWheelMovedEvent> *)(v53 + 156),
        *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v77,
        this);
      if ( *(_BYTE *)(v53 + 244) )
      {
        v55 = *(_DWORD *)v53;
        *(_DWORD *)&v77[24] = 0;
        *(_BYTE *)(v53 + 244) = 0;
        (*(void (**)(int, _DWORD))(v55 + 32))(v53, *(_DWORD *)&v77[24]);
      }
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->btSessions, (int *)&button);
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&button);
      *(_DWORD *)(LODWORD(button.x) + 148) = this;
      *(_DWORD *)&wsButtonImage.gap0[*(_DWORD *)(*(_DWORD *)wsButtonImage.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&ws.gap68[*(_DWORD *)(*(_DWORD *)wsButtonImage.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)wsButtonImage.gap0
                                                                                            + 4)
                                                                                - 104;
      *(_DWORD *)&wsButtonImage.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&wsButtonImage.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&wsButtonImage.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&wsButtonImage.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(wsButtonImage.gap68);
      LOBYTE(v92) = 10;
      *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(ACStandardLeaderboard **)((char *)&v83 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = (ACStandardLeaderboard *)(*(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104);
      *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&ws.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ws.gap68);
      v56 = this->sim;
      v49 = ++v81;
    }
    while ( v49 < RaceManager::getSessionCount(v56->raceManager) );
  }
  v57 = (ksgui::Control *)operator new(0x118u);
  LODWORD(button.x) = v57;
  v58 = 0;
  LOBYTE(v92) = 40;
  if ( v57 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"LEADERBOARD_ENTRY_LIST", 0x16u);
    LOBYTE(v92) = 41;
    v80 |= 1u;
    _Val = v80;
    ksgui::Control::Control(v57, &iname, this->sim->game->gui);
  }
  this->btEntryList = v58;
  v92 = 10;
  if ( (v80 & 1) != 0 )
  {
    v80 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v59 = this->btEntryList;
  *(_DWORD *)&v77[24] = 10;
  *(_DWORD *)&v77[20] = L"ENTRY LIST";
  v59->borderColor = (vec4f)_xmm;
  v60 = this->btEntryList;
  iname._Myres = 7;
  iname._Mysize = 0;
  button = colTitleBar;
  v60->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&button);
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, *(const wchar_t **)&v77[20], *(unsigned int *)&v77[24]);
  LOBYTE(v92) = 43;
  v61 = acTranslate(&v87, &iname);
  LOBYTE(v92) = 44;
  this->btEntryList->setText(this->btEntryList, v61);
  if ( v87._Myres >= 8 )
    operator delete(v87._Bx._Ptr);
  LOBYTE(v92) = 10;
  v87._Myres = 7;
  v87._Mysize = 0;
  v87._Bx._Buf[0] = 0;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, int))this->btEntryList->setSize)(
    this->btEntryList,
    1120403456,
    1099956224);
  std::shared_ptr<Font>::operator=(&this->btEntryList->font, &this->buttonsFont);
  this->btEntryList->fontAlign = eAlignCenter;
  v62 = this->btEntryList;
  if ( v62->visible )
  {
    v63 = v62->__vftable;
    *(_DWORD *)&v77[24] = 0;
    v62->visible = 0;
    ((void (__stdcall *)(_DWORD))v63->onVisibleChanged)(*(_DWORD *)&v77[24]);
  }
  LODWORD(button.x) = this->btEntryList;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&button);
  *(_DWORD *)&v77[24] = 280;
  *(_DWORD *)(LODWORD(button.x) + 148) = this;
  v64 = (ksgui::Control *)operator new(*(unsigned int *)&v77[24]);
  LODWORD(button.x) = v64;
  v65 = 0;
  LOBYTE(v92) = 45;
  if ( v64 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"LEADERBOARD_TIME_TABLE", 0x16u);
    LOBYTE(v92) = 46;
    v80 |= 2u;
    _Val = v80;
    ksgui::Control::Control(v64, &iname, this->sim->game->gui);
  }
  this->btTimeTable = v65;
  v92 = 10;
  if ( (v80 & 2) != 0 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v66 = this->btTimeTable;
  button.w = 0.0;
  *(_DWORD *)&v77[24] = 10;
  v66->borderColor = (vec4f)_xmm;
  v67 = this->btTimeTable;
  *(_QWORD *)&button.x = *(_QWORD *)&colTitleBar.x;
  button.z = colTitleBar.z;
  v68 = _mm_loadu_si128((const __m128i *)&button);
  *(_DWORD *)&v77[20] = L"TIME TABLE";
  iname._Myres = 7;
  v67->backColor = (vec4f)v68;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, *(const wchar_t **)&v77[20], *(unsigned int *)&v77[24]);
  LOBYTE(v92) = 48;
  v69 = acTranslate(&v87, &iname);
  LOBYTE(v92) = 49;
  this->btTimeTable->setText(this->btTimeTable, v69);
  if ( v87._Myres >= 8 )
    operator delete(v87._Bx._Ptr);
  LOBYTE(v92) = 10;
  v87._Myres = 7;
  v87._Mysize = 0;
  v87._Bx._Buf[0] = 0;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, int))this->btTimeTable->setSize)(
    this->btTimeTable,
    1120403456,
    1099956224);
  std::shared_ptr<Font>::operator=(&this->btTimeTable->font, &this->buttonsFont);
  this->btTimeTable->fontAlign = eAlignCenter;
  v70 = this->btTimeTable;
  if ( v70->visible )
  {
    v71 = v70->__vftable;
    *(_DWORD *)&v77[24] = 0;
    v70->visible = 0;
    ((void (__stdcall *)(_DWORD))v71->onVisibleChanged)(*(_DWORD *)&v77[24]);
  }
  LODWORD(button.x) = this->btTimeTable;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&button);
  *(_DWORD *)(LODWORD(button.x) + 148) = this;
  *(_DWORD *)&v77[24] = this->btEntryList;
  *(_DWORD *)v77 = &std::_Func_impl<std::_Callable_obj<_lambda_3eeadbc337cdb20284c4dcd7c5248d65_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v77[4] = this;
  *(_DWORD *)&v77[16] = v77;
  LOBYTE(v92) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->btEntryList->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v77,
    *(void **)&v77[24]);
  *(_DWORD *)&v77[24] = this->btTimeTable;
  *(_DWORD *)v77 = &std::_Func_impl<std::_Callable_obj<_lambda_2f0a929f979284146d931cdf2e5a85ce_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v77[4] = this;
  *(_DWORD *)&v77[16] = v77;
  LOBYTE(v92) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->btTimeTable->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v77,
    *(void **)&v77[24]);
  if ( this->sim->client )
  {
    v72 = (ksgui::ActiveButton *)operator new(0x1C0u);
    LODWORD(button.x) = v72;
    LOBYTE(v92) = 52;
    if ( v72 )
    {
      *(_DWORD *)&v77[24] = this->sim->game->gui;
      std::wstring::wstring((std::wstring *)v77, L"BUT_KICK_USER");
      ksgui::ActiveButton::ActiveButton(v72, *(std::wstring *)v77, *(ksgui::GUI **)&v77[24]);
    }
    else
    {
      v73 = 0;
    }
    LOBYTE(v92) = 10;
    this->btKick = v73;
    std::wstring::wstring((std::wstring *)&v77[4], L"content/gui/raceControl/kick_icon");
    ksgui::ActiveButton::setMultipleTexture(this->btKick, (unsigned int)operator delete, *(std::wstring *)&v77[4]);
    std::wstring::wstring(&v87, word_17BE9D8);
    LOBYTE(v92) = 53;
    this->btKick->setText(this->btKick, &v87);
    LOBYTE(v92) = 10;
    if ( v87._Myres >= 8 )
      operator delete(v87._Bx._Ptr);
    ((void (*)(ksgui::ActiveButton *, int, int))this->btKick->setSize)(this->btKick, 1106247680, 1106247680);
    v74 = this->btKick;
    if ( v74->visible )
    {
      v75 = v74->__vftable;
      *(_DWORD *)&v77[24] = 0;
      v74->visible = 0;
      ((void (__stdcall *)(_DWORD))v75->onVisibleChanged)(*(_DWORD *)&v77[24]);
    }
    *(_DWORD *)v77 = &std::_Func_impl<std::_Callable_obj<_lambda_ac3cb27f3c5b29d7a099a089c33afa52_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
    *(_DWORD *)&v77[4] = this;
    *(_DWORD *)&v77[16] = v77;
    LOBYTE(v92) = 10;
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)&this->btKick->evClicked,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v77,
      this);
    ksgui::Control::addControl(this, this->btKick);
  }
  ksgui::Control::setSize(this, 780.0, 325.0);
  *(_DWORD *)&v77[24] = this;
  *(_DWORD *)&v77[20] = this;
  *(_WORD *)&this->drawBorder = 0;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&button,
    *(CarAudioFMOD **)&v77[20]);
  std::function<void __cdecl (OnNewSessionEvent const &)>::function<void __cdecl (OnNewSessionEvent const &)>(
    (std::function<void __cdecl(OnNewSessionEvent const &)> *)v77,
    v76);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->sim->evOnNewSession,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v77,
    *(void **)&v77[24]);
}
ACStandardLeaderboard *ACStandardLeaderboard::`scalar deleting destructor'(ACStandardLeaderboard *this, unsigned int a2)
{
  ACStandardLeaderboard::~ACStandardLeaderboard(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACStandardLeaderboard::~ACStandardLeaderboard(ACStandardLeaderboard *this)
{
  std::_Ref_count_base *v2; // ebx
  std::_Ref_count_base *v3; // ebx
  std::_Ref_count_base *v4; // ebx
  std::_Ref_count_base *v5; // ebx
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Texture> > > > result; // [esp+18h] [ebp-10h] BYREF
  int v7; // [esp+24h] [ebp-4h]

  this->__vftable = (ACStandardLeaderboard_vtbl *)&ACStandardLeaderboard::`vftable';
  v7 = 6;
  OnSetupAppCreated::~OnSetupAppCreated(&this->txMiniFinish);
  std::_Tree<std::_Tmap_traits<CarAvatar *,Texture,std::less<CarAvatar *>,std::allocator<std::pair<CarAvatar * const,Texture>>,0>>::erase(
    &this->skinTextures,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Texture> > > >)this->skinTextures._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Texture> > > >)this->skinTextures._Myhead);
  operator delete(this->skinTextures._Myhead);
  LOBYTE(v7) = 5;
  v2 = this->blackFont._Rep;
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Uses, 0xFFFFFFFF) )
    {
      v2->_Destroy(v2);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Weaks, 0xFFFFFFFF) )
        v2->_Delete_this(v2);
    }
  }
  LOBYTE(v7) = 4;
  v3 = this->dataFont._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Weaks, 0xFFFFFFFF) )
        v3->_Delete_this(v3);
    }
  }
  LOBYTE(v7) = 3;
  v4 = this->titleFont._Rep;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Uses, 0xFFFFFFFF) )
    {
      v4->_Destroy(v4);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Weaks, 0xFFFFFFFF) )
        v4->_Delete_this(v4);
    }
  }
  LOBYTE(v7) = 2;
  v5 = this->buttonsFont._Rep;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v5->_Uses, 0xFFFFFFFF) )
    {
      v5->_Destroy(v5);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v5->_Weaks) )
        v5->_Delete_this(v5);
    }
  }
  if ( this->btSessions._Myfirst )
  {
    operator delete(this->btSessions._Myfirst);
    this->btSessions._Myfirst = 0;
    this->btSessions._Mylast = 0;
    this->btSessions._Myend = 0;
  }
  if ( this->printedCars._Myfirst )
  {
    operator delete(this->printedCars._Myfirst);
    this->printedCars._Myfirst = 0;
    this->printedCars._Mylast = 0;
    this->printedCars._Myend = 0;
  }
  v7 = -1;
  ksgui::Control::~Control(this);
}
void ACStandardLeaderboard::onVisibleChanged(ACStandardLeaderboard *this, BOOL newValue)
{
  ksgui::Control **v3; // edi
  ksgui::Control **i; // esi
  Sim *v5; // eax
  RaceManager *v6; // ecx

  v3 = this->controls._Mylast;
  for ( i = this->controls._Myfirst; i != v3; ++i )
    (*i)->onVisibleChanged(*i, newValue);
  if ( newValue )
  {
    v5 = this->sim;
    if ( v5 )
    {
      v6 = v5->raceManager;
      if ( v6 )
        this->sessionID = RaceManager::getCurrentSessionIndex(v6);
    }
  }
}
void ACStandardLeaderboard::setLastSession(ACStandardLeaderboard *this)
{
  this->sessionID = RaceManager::getSessionCount(this->sim->raceManager) - 1;
}
void ACStandardLeaderboard::render(ACStandardLeaderboard *this, float dt)
{
  ACStandardLeaderboard *v2; // esi
  void (__cdecl *v3)(void *); // edi
  float v4; // xmm2_4
  float v5; // xmm7_4
  ksgui::Control *v6; // ecx
  ksgui::Control_vtbl *v7; // eax
  ksgui::Control *v8; // ecx
  ksgui::Control_vtbl *v9; // eax
  float *v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float *v18; // ecx
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  ksgui::ActiveButton *v26; // ecx
  ksgui::ActiveButton_vtbl *v27; // eax
  float *v28; // ecx
  float v29; // xmm5_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  ksgui::ActiveButton *v36; // ecx
  ksgui::ActiveButton_vtbl *v37; // eax
  float *v38; // ecx
  float v39; // xmm5_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm2_4
  float v43; // xmm4_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  unsigned int v47; // edi
  bool v48; // cl
  ksgui::ActiveButton *v49; // edx
  ksgui::ActiveButton_vtbl *v50; // eax
  float v51; // xmm3_4
  float *v52; // ecx
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm5_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  ksgui::ActiveButton *v58; // eax
  int v59; // eax
  ksgui::Control *v60; // ecx
  bool v61; // al
  ksgui::Control *v62; // ecx
  bool v63; // al
  ACStandardLeaderboard_vtbl *v64; // eax
  bool v65; // zf
  float v66; // xmm7_4
  float v67; // xmm0_4
  float v68; // xmm6_4
  LeaderboardUI v69; // eax
  __int32 v70; // eax
  float v71; // xmm6_4
  float v72; // xmm1_4
  float v73; // xmm0_4
  float v74; // xmm6_4
  float v75; // xmm1_4
  float v76; // xmm6_4
  float v77; // xmm1_4
  float v78; // xmm6_4
  float v79; // xmm1_4
  float v80; // xmm6_4
  float v81; // xmm1_4
  float v82; // xmm1_4
  float v83; // xmm6_4
  float v84; // xmm6_4
  float v85; // xmm6_4
  float v86; // xmm6_4
  float v87; // xmm6_4
  GLRenderer *v88; // ecx
  LeaderboardMode v89; // eax
  const std::wstring *v90; // eax
  const std::wstring *v91; // eax
  const std::wstring *v92; // eax
  int v93; // eax
  std::wstring *v94; // eax
  const std::wstring *v95; // eax
  const std::wstring *v96; // eax
  const std::wstring *v97; // eax
  const std::wstring *v98; // eax
  Sim *v99; // eax
  const std::wstring *v100; // eax
  float v101; // xmm6_4
  float v102; // xmm1_4
  float v103; // xmm0_4
  float v104; // xmm6_4
  float v105; // xmm1_4
  float v106; // xmm6_4
  float v107; // xmm1_4
  float v108; // xmm6_4
  float v109; // xmm1_4
  float v110; // xmm1_4
  float v111; // xmm1_4
  float v112; // xmm6_4
  float v113; // xmm6_4
  const std::wstring *v114; // eax
  const std::wstring *v115; // eax
  const std::wstring *v116; // eax
  const std::wstring *v117; // eax
  Sim *v118; // ecx
  const std::wstring *v119; // eax
  const std::wstring *v120; // eax
  const std::wstring *v121; // eax
  Sim *v122; // eax
  const std::wstring *v123; // eax
  const std::wstring *v124; // eax
  ksgui::ActiveButton *v125; // ecx
  ksgui::ActiveButton_vtbl *v126; // eax
  LeaderboardEntry *v127; // esi
  int v128; // eax
  LeaderboardEntry *v129; // edi
  int v130; // eax
  int v131; // edx
  int v132; // eax
  int v133; // edi
  int v134; // ecx
  int v135; // eax
  int v136; // eax
  int v137; // eax
  int v138; // eax
  int v139; // ecx
  int v140; // edx
  int v141; // edi
  Session *v142; // eax
  const std::wstring *v143; // eax
  int r_12; // [esp+28h] [ebp-428h]
  __int64 v145; // [esp+2Ch] [ebp-424h]
  float v146; // [esp+34h] [ebp-41Ch]
  unsigned int v147; // [esp+38h] [ebp-418h]
  float *v148; // [esp+38h] [ebp-418h]
  int v149; // [esp+38h] [ebp-418h]
  int v150; // [esp+38h] [ebp-418h]
  int leaderboardIndex; // [esp+3Ch] [ebp-414h]
  int leaderboardIndexa; // [esp+3Ch] [ebp-414h]
  SessionType v153; // [esp+40h] [ebp-410h]
  int v154; // [esp+40h] [ebp-410h]
  int v155; // [esp+40h] [ebp-410h]
  ACStandardLeaderboard *v157; // [esp+44h] [ebp-40Ch]
  GLRenderer *v158; // [esp+48h] [ebp-408h]
  bool v159; // [esp+4Fh] [ebp-401h]
  ksgui::ksRect a; // [esp+50h] [ebp-400h] BYREF
  std::vector<LeaderboardEntry> lb; // [esp+64h] [ebp-3ECh] BYREF
  ACStandardLeaderboard::RowInfo v162; // [esp+70h] [ebp-3E0h] BYREF
  std::wstring v163; // [esp+78h] [ebp-3D8h] BYREF
  std::wstring v164; // [esp+90h] [ebp-3C0h] BYREF
  std::wstring v165; // [esp+A8h] [ebp-3A8h] BYREF
  std::wstring v166; // [esp+C0h] [ebp-390h] BYREF
  std::wstring v167; // [esp+D8h] [ebp-378h] BYREF
  std::wstring v168; // [esp+F0h] [ebp-360h] BYREF
  std::wstring v169; // [esp+108h] [ebp-348h] BYREF
  std::wstring v170; // [esp+120h] [ebp-330h] BYREF
  std::wstring s; // [esp+138h] [ebp-318h] BYREF
  std::wstring v172; // [esp+150h] [ebp-300h] BYREF
  std::wstring v173; // [esp+168h] [ebp-2E8h] BYREF
  std::wstring v174; // [esp+180h] [ebp-2D0h] BYREF
  std::wstring v175; // [esp+198h] [ebp-2B8h] BYREF
  std::wstring v176; // [esp+1B0h] [ebp-2A0h] BYREF
  std::wstring text; // [esp+1C8h] [ebp-288h] BYREF
  std::wstring v178; // [esp+1E0h] [ebp-270h] BYREF
  std::wstring v179; // [esp+1F8h] [ebp-258h] BYREF
  std::wstring v180; // [esp+210h] [ebp-240h] BYREF
  std::wstring v181; // [esp+228h] [ebp-228h] BYREF
  std::wstring v182; // [esp+240h] [ebp-210h] BYREF
  std::wstring v183; // [esp+258h] [ebp-1F8h] BYREF
  std::wstring v184; // [esp+270h] [ebp-1E0h] BYREF
  std::wstring v185; // [esp+288h] [ebp-1C8h] BYREF
  std::wstring v186; // [esp+2A0h] [ebp-1B0h] BYREF
  std::wstring v187; // [esp+2B8h] [ebp-198h] BYREF
  std::wstring v188; // [esp+2D0h] [ebp-180h] BYREF
  std::wstring v189; // [esp+2E8h] [ebp-168h] BYREF
  std::wstring v190; // [esp+300h] [ebp-150h] BYREF
  std::wstring v191; // [esp+318h] [ebp-138h] BYREF
  std::wstring v192; // [esp+330h] [ebp-120h] BYREF
  std::wstring v193; // [esp+348h] [ebp-108h] BYREF
  std::wstring v194; // [esp+360h] [ebp-F0h] BYREF
  std::wstring v195; // [esp+378h] [ebp-D8h] BYREF
  std::wstring v196; // [esp+390h] [ebp-C0h] BYREF
  std::wstring v197; // [esp+3A8h] [ebp-A8h] BYREF
  std::wstring v198; // [esp+3C0h] [ebp-90h] BYREF
  Session result; // [esp+3D8h] [ebp-78h] BYREF
  int v200; // [esp+44Ch] [ebp-4h]

  v2 = this;
  this->printedCars._Mylast = this->printedCars._Myfirst;
  v3 = operator delete;
  v153 = RaceManager::getSessionInfo(this->sim->raceManager, &result, this->sessionID)->sessionType;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  v4 = FLOAT_5_0;
  v5 = FLOAT_10_0;
  result.spawSet._Bx._Buf[0] = 0;
  result.spawSet._Myres = 7;
  result.spawSet._Mysize = 0;
  if ( (unsigned int)(v153 - 1) > 2 )
  {
    v2->showModeButtons = 0;
  }
  else
  {
    v6 = v2->btTimeTable;
    if ( !v6->visible )
    {
      v7 = v6->__vftable;
      v6->visible = 1;
      ((void (__stdcall *)(int))v7->onVisibleChanged)(1);
      v4 = FLOAT_5_0;
      v5 = FLOAT_10_0;
    }
    v8 = v2->btEntryList;
    if ( !v8->visible )
    {
      v9 = v8->__vftable;
      v8->visible = 1;
      ((void (__stdcall *)(int))v9->onVisibleChanged)(1);
      v4 = FLOAT_5_0;
      v5 = FLOAT_10_0;
    }
    v10 = (float *)v2->btTimeTable;
    v11 = v2->rect.right - v2->rect.left;
    v12 = v10[8] - v10[7];
    v13 = (float)(v2->rect.bottom - v2->rect.top) + v5;
    v14 = (float)(v10[10] - v10[9]) + v13;
    v10[9] = v13;
    v15 = v11 - (float)((float)(v12 + v4) * 2.0);
    v16 = v10[66];
    v17 = v12 + v15;
    v10[7] = v15;
    v10[10] = v14;
    v10[8] = v17;
    if ( v16 == 0.0 && v10[68] == 0.0 )
    {
      v10[66] = v15;
      v10[68] = v13;
      v10[67] = v17;
      v10[69] = v14;
    }
    v18 = (float *)v2->btEntryList;
    v19 = v18[8] - v18[7];
    v20 = v19 + v4;
    v21 = (float)(v2->rect.bottom - v2->rect.top) + v5;
    v22 = (float)(v2->rect.right - v2->rect.left) - (float)(v20 * 3.0);
    v23 = v18[66];
    v24 = (float)(v18[10] - v18[9]) + v21;
    v18[9] = v21;
    v25 = v19 + v22;
    v18[7] = v22;
    v18[10] = v24;
    v18[8] = v25;
    if ( v23 == 0.0 && v18[68] == 0.0 )
    {
      v18[66] = v22;
      v18[68] = v21;
      v18[67] = v25;
      v18[69] = v24;
    }
  }
  if ( (unsigned int)(v2->sim->cars._Mylast - v2->sim->cars._Myfirst) > v2->rows && !v2->focusOnPlayer )
  {
    v26 = v2->btNextPage;
    if ( !v26->visible )
    {
      v27 = v26->__vftable;
      v26->visible = 1;
      ((void (__stdcall *)(int))v27->onVisibleChanged)(1);
    }
    v28 = (float *)v2->btNextPage;
    v29 = v2->rect.bottom - v2->rect.top;
    v30 = v28[8] - v28[7];
    v31 = v28[10] - v28[9];
    v32 = (float)(v2->rect.right - v2->rect.left) - v30;
    v28[9] = v29;
    v33 = v28[66];
    v34 = v30 + v32;
    v28[7] = v32;
    v35 = v31 + v29;
    v28[8] = v34;
    v28[10] = v35;
    if ( v33 == 0.0 && v28[68] == 0.0 )
    {
      v28[66] = v32;
      v28[68] = v29;
      v28[67] = v34;
      v28[69] = v35;
    }
    v36 = v2->btPreviousPage;
    if ( !v36->visible )
    {
      v37 = v36->__vftable;
      v36->visible = 1;
      ((void (__stdcall *)(int))v37->onVisibleChanged)(1);
    }
    v38 = (float *)v2->btPreviousPage;
    v39 = v2->rect.bottom - v2->rect.top;
    v40 = v38[8] - v38[7];
    v41 = v38[10] - v38[9];
    v42 = (float)(v2->rect.right - v2->rect.left) - (float)(v2->btNextPage->rect.right - v2->btNextPage->rect.left);
    v38[9] = v39;
    v43 = v41 + v39;
    v44 = v38[66];
    v45 = (float)(v42 - v40) - 20.0;
    v38[10] = v43;
    v38[7] = v45;
    v46 = v40 + v45;
    v38[8] = v46;
    if ( v44 == 0.0 && v38[68] == 0.0 )
    {
      v38[66] = v45;
      v38[68] = v39;
      v38[67] = v46;
      v38[69] = v43;
    }
  }
  if ( v2->btSessions._Mylast - v2->btSessions._Myfirst )
  {
    v147 = 150;
    v47 = 0;
    do
    {
      v48 = RaceManager::getCurrentSessionIndex(v2->sim->raceManager) >= v47
         && RaceManager::getCurrentSessionIndex(v2->sim->raceManager) > 0;
      v49 = v2->btSessions._Myfirst[v47];
      if ( v49->visible != v48 )
      {
        v50 = v49->__vftable;
        v49->visible = v48;
        v50->onVisibleChanged(v49, v48);
      }
      v51 = v2->rect.bottom - v2->rect.top;
      v52 = (float *)v2->btSessions._Myfirst[v47];
      v53 = v52[8] - v52[7];
      v54 = (float)(v52[10] - v52[9]) + v51;
      v52[9] = v51;
      v52[10] = v54;
      v55 = (float)v147;
      v56 = v52[66];
      v57 = v53 + v55;
      v52[7] = v55;
      v52[8] = v57;
      if ( v56 == 0.0 && v52[68] == 0.0 )
      {
        v52[66] = v55;
        v52[68] = v51;
        v52[67] = v57;
        v52[69] = v54;
      }
      v58 = v2->btSessions._Myfirst[v47];
      if ( v2->sessionID == v47 )
      {
        v58->selected = 1;
        if ( v2->showModeButtons )
        {
          v59 = RaceManager::getCurrentSessionIndex(v2->sim->raceManager);
          v60 = v2->btTimeTable;
          v61 = v47 == v59;
          LOBYTE(v153) = v61;
          if ( v60->visible != v61 )
          {
            v60->visible = v61;
            v60->onVisibleChanged(v60, v153);
          }
          v62 = v2->btEntryList;
          v63 = v2->btTimeTable->visible;
          if ( v62->visible != v63 )
          {
            v62->visible = v63;
            v62->onVisibleChanged(v62, v63);
          }
          if ( !v2->btTimeTable->visible )
            v2->mode = eEntryList;
        }
      }
      else
      {
        v58->selected = 0;
      }
      ++v47;
      v147 += 75;
    }
    while ( v47 < v2->btSessions._Mylast - v2->btSessions._Myfirst );
    v3 = operator delete;
  }
  v64 = v2->__vftable;
  a.left = 0.0;
  a.top = 0.0;
  a.right = 1.0;
  a.bottom = 1.0;
  v64->getWorldRect(v2, &a);
  v65 = !v2->isLoaded;
  v66 = v2->rect.top + a.top;
  v67 = v2->rect.bottom - v2->rect.top;
  v68 = a.left + v2->rect.left;
  a.top = v66;
  a.left = v68;
  a.bottom = v67 + v66;
  if ( v65 )
  {
    v69 = v2->ui;
    if ( v69 )
    {
      v70 = v69 - 1;
      if ( !v70 )
      {
        v101 = v68 + 10.0;
        v2->entry_nameX = v101;
        v2->time_nameX = v101;
        v2->entry_carX = v101 + 180.0;
        v102 = (float)(v101 + 180.0) + 195.0;
        v2->entry_flagX = v101 + 23.0;
        v103 = v101;
        v104 = v101 + 180.0;
        v2->entry_tyresX = v102;
        v105 = v102 + 65.0;
        v2->time_carX = v104;
        v106 = v104 + 125.0;
        v2->time_flagX = v103 + 23.0;
        v2->entry_ballastX = v105;
        v107 = v105 + 65.0;
        v2->time_lastlapX = v106;
        v108 = v106 + 50.0;
        v2->entry_lapsX = v107;
        v109 = v107 + 110.0;
        v2->entry_timeX = v109;
        v110 = v109 + 75.0;
        v2->entry_gapX = v110;
        v111 = v110 + 45.0;
        v2->entry_pingX = v111;
        v2->entry_kickX = v111 + 10.0;
        v2->time_splitX[0] = v108;
        v112 = v108 + 50.0;
        v2->time_splitX[1] = v112;
        v113 = v112 + 50.0;
        v2->time_splitX[2] = v113;
        v84 = v113 + 60.0;
        v2->isLoaded = 0;
        v2->time_deltaX = v84;
        goto LABEL_56;
      }
      if ( v70 != 1 )
      {
LABEL_57:
        v2->wtop1 = v66 + 1.0;
        goto LABEL_58;
      }
    }
    v71 = v68 + 10.0;
    v2->entry_nameX = v71;
    v2->time_nameX = v71;
    v2->entry_carX = v71 + 180.0;
    v72 = (float)(v71 + 180.0) + 195.0;
    v2->entry_flagX = v71 + 23.0;
    v73 = v71;
    v74 = v71 + 180.0;
    v2->entry_tyresX = v72;
    v75 = v72 + 65.0;
    v2->time_carX = v74;
    v76 = v74 + 125.0;
    v2->time_flagX = v73 + 23.0;
    v2->entry_ballastX = v75;
    v77 = v75 + 65.0;
    v2->time_lastlapX = v76;
    v78 = v76 + 70.0;
    v2->entry_lapsX = v77;
    v79 = v77 + 110.0;
    v2->time_deltaX = v78;
    v80 = v78 + 50.0;
    v2->entry_timeX = v79;
    v81 = v79 + 75.0;
    v2->entry_gapX = v81;
    v82 = v81 + 45.0;
    v2->entry_pingX = v82;
    v2->entry_kickX = v82 + 10.0;
    v2->time_splitX[0] = v80;
    v83 = v80 + 50.0;
    v2->time_splitX[1] = v83;
    v84 = v83 + 50.0;
    v2->time_splitX[2] = v84;
    v2->isLoaded = 1;
LABEL_56:
    v85 = v84 + 90.0;
    v2->time_timeX = v85;
    v86 = v85 + 75.0;
    v2->time_gapX = v86;
    v87 = v86 + 45.0;
    v2->time_pingX = v87;
    v2->time_kickX = v87 + 10.0;
    goto LABEL_57;
  }
LABEL_58:
  v88 = v2->sim->game->graphics->gl;
  v89 = v2->mode;
  v158 = v88;
  if ( v89 == eEntryList )
  {
    GLRenderer::color4f(v88, 0.74000001, 0.0, 0.0, 1.0);
    GLRenderer::quad(v158, a.left, a.top, v2->rect.right - v2->rect.left, 20.0, 0, 0);
    Font::setColor(v2->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
    v167._Myres = 7;
    v167._Mysize = 0;
    v167._Bx._Buf[0] = 0;
    std::wstring::assign(&v167, L"DRIVER", 6u);
    v200 = 0;
    v114 = acTranslate(&v198, &v167);
    LOBYTE(v200) = 1;
    Font::blitString(v2->titleFont._Ptr, v2->entry_nameX, v2->wtop1, v114, 1.0, eAlignLeft);
    if ( v198._Myres >= 8 )
      v3(v198._Bx._Ptr);
    v200 = -1;
    v198._Myres = 7;
    v198._Mysize = 0;
    v198._Bx._Buf[0] = 0;
    if ( v167._Myres >= 8 )
      v3(v167._Bx._Ptr);
    v167._Myres = 7;
    v167._Mysize = 0;
    v167._Bx._Buf[0] = 0;
    v175._Myres = 7;
    v175._Mysize = 0;
    v175._Bx._Buf[0] = 0;
    std::wstring::assign(&v175, L"CAR", 3u);
    v200 = 2;
    v115 = acTranslate(&v183, &v175);
    LOBYTE(v200) = 3;
    Font::blitString(v2->titleFont._Ptr, v2->entry_carX, v2->wtop1, v115, 1.0, eAlignLeft);
    if ( v183._Myres >= 8 )
      v3(v183._Bx._Ptr);
    v200 = -1;
    v183._Myres = 7;
    v183._Mysize = 0;
    v183._Bx._Buf[0] = 0;
    if ( v175._Myres >= 8 )
      v3(v175._Bx._Ptr);
    v175._Myres = 7;
    v175._Mysize = 0;
    v175._Bx._Buf[0] = 0;
    v169._Myres = 7;
    v169._Mysize = 0;
    v169._Bx._Buf[0] = 0;
    std::wstring::assign(&v169, L"TYRE", 4u);
    v200 = 4;
    v116 = acTranslate(&v185, &v169);
    LOBYTE(v200) = 5;
    Font::blitString(v2->titleFont._Ptr, v2->entry_tyresX - 5.0, v2->wtop1, v116, 1.0, eAlignLeft);
    if ( v185._Myres >= 8 )
      v3(v185._Bx._Ptr);
    v200 = -1;
    v185._Myres = 7;
    v185._Mysize = 0;
    v185._Bx._Buf[0] = 0;
    if ( v169._Myres >= 8 )
      v3(v169._Bx._Ptr);
    v169._Myres = 7;
    v169._Mysize = 0;
    v169._Bx._Buf[0] = 0;
    v173._Myres = 7;
    v173._Mysize = 0;
    v173._Bx._Buf[0] = 0;
    std::wstring::assign(&v173, L"LAPS", 4u);
    v200 = 6;
    v117 = acTranslate(&v187, &v173);
    LOBYTE(v200) = 7;
    Font::blitString(v2->titleFont._Ptr, v2->entry_lapsX + 15.0, v2->wtop1, v117, 1.0, eAlignRight);
    if ( v187._Myres >= 8 )
      v3(v187._Bx._Ptr);
    v200 = -1;
    v187._Myres = 7;
    v187._Mysize = 0;
    v187._Bx._Buf[0] = 0;
    if ( v173._Myres >= 8 )
      v3(v173._Bx._Ptr);
    v118 = v2->sim;
    r_12 = v2->sessionID;
    v173._Bx._Buf[0] = 0;
    v173._Myres = 7;
    v173._Mysize = 0;
    v159 = RaceManager::getSessionInfo(v118->raceManager, &result, r_12)->sessionType == Race;
    if ( result.name._Myres >= 8 )
      v3(result.name._Bx._Ptr);
    result.name._Myres = 7;
    result.name._Mysize = 0;
    result.name._Bx._Buf[0] = 0;
    if ( result.spawSet._Myres >= 8 )
      v3(result.spawSet._Bx._Ptr);
    result.spawSet._Myres = 7;
    result.spawSet._Mysize = 0;
    result.spawSet._Bx._Buf[0] = 0;
    if ( v159 )
    {
      v165._Myres = 7;
      v165._Mysize = 0;
      v165._Bx._Buf[0] = 0;
      std::wstring::assign(&v165, L"TOTAL", 5u);
      v200 = 8;
      v119 = acTranslate(&v189, &v165);
      LOBYTE(v200) = 9;
      Font::blitString(v2->titleFont._Ptr, v2->entry_timeX - 5.0, v2->wtop1, v119, 1.0, eAlignRight);
      if ( v189._Myres >= 8 )
        v3(v189._Bx._Ptr);
      v200 = -1;
      v189._Myres = 7;
      v189._Mysize = 0;
      v189._Bx._Buf[0] = 0;
      if ( v165._Myres >= 8 )
        v3(v165._Bx._Ptr);
      v165._Myres = 7;
      v165._Mysize = 0;
      v165._Bx._Buf[0] = 0;
    }
    else
    {
      v166._Mysize = 0;
      v166._Myres = 7;
      v166._Bx._Buf[0] = 0;
      std::wstring::assign(&v166, L"LAPTIME", 7u);
      v200 = 10;
      v120 = acTranslate(&v191, &v166);
      LOBYTE(v200) = 11;
      Font::blitString(v2->titleFont._Ptr, v2->entry_timeX - 5.0, v2->wtop1, v120, 1.0, eAlignRight);
      if ( v191._Myres >= 8 )
        v3(v191._Bx._Ptr);
      v200 = -1;
      v191._Myres = 7;
      v191._Mysize = 0;
      v191._Bx._Buf[0] = 0;
      if ( v166._Myres >= 8 )
        v3(v166._Bx._Ptr);
      v166._Myres = 7;
      v166._Mysize = 0;
      v166._Bx._Buf[0] = 0;
    }
    v168._Myres = 7;
    v168._Mysize = 0;
    v168._Bx._Buf[0] = 0;
    std::wstring::assign(&v168, L"GAP", 3u);
    v200 = 12;
    v121 = acTranslate(&v193, &v168);
    LOBYTE(v200) = 13;
    Font::blitString(v2->titleFont._Ptr, v2->entry_gapX - 5.0, v2->wtop1, v121, 1.0, eAlignRight);
    if ( v193._Myres >= 8 )
      v3(v193._Bx._Ptr);
    v200 = -1;
    v193._Myres = 7;
    v193._Mysize = 0;
    v193._Bx._Buf[0] = 0;
    if ( v168._Myres >= 8 )
      v3(v168._Bx._Ptr);
    v168._Myres = 7;
    v168._Bx._Buf[0] = 0;
    v122 = v2->sim;
    v168._Mysize = 0;
    if ( v122->client )
    {
      v170._Myres = 7;
      v170._Mysize = 0;
      v170._Bx._Buf[0] = 0;
      std::wstring::assign(&v170, L"P", 1u);
      v200 = 14;
      v123 = acTranslate(&v195, &v170);
      LOBYTE(v200) = 15;
      Font::blitString(v2->titleFont._Ptr, v2->entry_pingX - 5.0, v2->wtop1, v123, 1.0, eAlignRight);
      if ( v195._Myres >= 8 )
        v3(v195._Bx._Ptr);
      v200 = -1;
      v195._Myres = 7;
      v195._Mysize = 0;
      v195._Bx._Buf[0] = 0;
      if ( v170._Myres >= 8 )
        v3(v170._Bx._Ptr);
      v170._Myres = 7;
      v170._Mysize = 0;
      v170._Bx._Buf[0] = 0;
      v172._Myres = 7;
      v172._Mysize = 0;
      v172._Bx._Buf[0] = 0;
      std::wstring::assign(&v172, L"BoP", 3u);
      v200 = 16;
      v124 = acTranslate(&v163, &v172);
      LOBYTE(v200) = 17;
      Font::blitString(v2->titleFont._Ptr, v2->entry_ballastX + 10.0, v2->wtop1, v124, 1.0, eAlignRight);
      if ( v163._Myres >= 8 )
        v3(v163._Bx._Ptr);
      v200 = -1;
      v163._Myres = 7;
      v163._Mysize = 0;
      v163._Bx._Buf[0] = 0;
      if ( v172._Myres >= 8 )
        v3(v172._Bx._Ptr);
      v172._Myres = 7;
      v172._Mysize = 0;
      v172._Bx._Buf[0] = 0;
      v174._Myres = 7;
      v174._Mysize = 0;
      v174._Bx._Buf[0] = 0;
      std::wstring::assign(&v174, word_17BE9D8, 0);
      v200 = 18;
      Font::blitString(v2->titleFont._Ptr, v2->entry_kickX, v2->wtop1, &v174, 1.0, eAlignLeft);
      v200 = -1;
      if ( v174._Myres >= 8 )
        v3(v174._Bx._Ptr);
      v174._Myres = 7;
      v174._Mysize = 0;
      v174._Bx._Buf[0] = 0;
    }
    goto LABEL_146;
  }
  if ( v89 == eTimeTable )
  {
    GLRenderer::color4f(v88, 0.74000001, 0.0, 0.0, 1.0);
    GLRenderer::quad(v158, a.left, a.top, v2->rect.right - v2->rect.left, 20.0, 0, 0);
    Font::setColor(v2->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
    std::wstring::wstring(&text, L"DRIVER");
    v200 = 19;
    v90 = acTranslate(&v194, &text);
    LOBYTE(v200) = 20;
    Font::blitString(v2->titleFont._Ptr, v2->time_nameX, v2->wtop1, v90, 1.0, eAlignLeft);
    if ( v194._Myres >= 8 )
      v3(v194._Bx._Ptr);
    v200 = -1;
    v194._Myres = 7;
    v194._Mysize = 0;
    v194._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      v3(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::wstring(&v180, L"CAR");
    v200 = 21;
    v91 = acTranslate(&v197, &v180);
    LOBYTE(v200) = 22;
    Font::blitString(v2->titleFont._Ptr, v2->time_carX, v2->wtop1, v91, 1.0, eAlignLeft);
    if ( v197._Myres >= 8 )
      v3(v197._Bx._Ptr);
    v200 = -1;
    v197._Myres = 7;
    v197._Mysize = 0;
    v197._Bx._Buf[0] = 0;
    if ( v180._Myres >= 8 )
      v3(v180._Bx._Ptr);
    v180._Myres = 7;
    v180._Mysize = 0;
    v180._Bx._Buf[0] = 0;
    std::wstring::wstring(&v181, L"LASTLAP");
    v200 = 23;
    v92 = acTranslate(&v184, &v181);
    LOBYTE(v200) = 24;
    Font::blitString(v2->titleFont._Ptr, v2->time_lastlapX - 5.0, v2->wtop1, v92, 1.0, eAlignRight);
    if ( v184._Myres >= 8 )
      v3(v184._Bx._Ptr);
    v200 = -1;
    v184._Myres = 7;
    v184._Mysize = 0;
    v184._Bx._Buf[0] = 0;
    if ( v181._Myres >= 8 )
      v3(v181._Bx._Ptr);
    v93 = 0;
    v181._Myres = 7;
    v181._Mysize = 0;
    v181._Bx._Buf[0] = 0;
    v148 = v2->time_splitX;
    do
    {
      v154 = v93 + 1;
      v94 = std::to_wstring(&v196, v93 + 1);
      v200 = 25;
      v95 = std::operator+<wchar_t>(&v186, L"S", v94);
      LOBYTE(v200) = 26;
      v96 = acTranslate(&v192, v95);
      LOBYTE(v200) = 27;
      Font::blitString(v2->titleFont._Ptr, *v148 - 5.0, v2->wtop1, v96, 1.0, eAlignRight);
      if ( v192._Myres >= 8 )
        v3(v192._Bx._Ptr);
      v192._Myres = 7;
      v192._Mysize = 0;
      v192._Bx._Buf[0] = 0;
      if ( v186._Myres >= 8 )
        v3(v186._Bx._Ptr);
      v200 = -1;
      v186._Myres = 7;
      v186._Mysize = 0;
      v186._Bx._Buf[0] = 0;
      if ( v196._Myres >= 8 )
        v3(v196._Bx._Ptr);
      ++v148;
      v196._Bx._Buf[0] = 0;
      v93 = v154;
      v196._Myres = 7;
      v196._Mysize = 0;
    }
    while ( v154 < 3 );
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    std::wstring::assign(&s, L"  DELTA", 7u);
    v200 = 28;
    Font::blitString(v2->titleFont._Ptr, v2->time_deltaX - 5.0, v2->wtop1, &s, 1.0, eAlignRight);
    v200 = -1;
    if ( s._Myres >= 8 )
      v3(s._Bx._Ptr);
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    v176._Myres = 7;
    v176._Mysize = 0;
    v176._Bx._Buf[0] = 0;
    std::wstring::assign(&v176, L"BESTLAP", 7u);
    v200 = 29;
    v97 = acTranslate(&v188, &v176);
    LOBYTE(v200) = 30;
    Font::blitString(v2->titleFont._Ptr, v2->time_timeX - 5.0, v2->wtop1, v97, 1.0, eAlignRight);
    if ( v188._Myres >= 8 )
      v3(v188._Bx._Ptr);
    v200 = -1;
    v188._Myres = 7;
    v188._Mysize = 0;
    v188._Bx._Buf[0] = 0;
    if ( v176._Myres >= 8 )
      v3(v176._Bx._Ptr);
    v176._Myres = 7;
    v176._Mysize = 0;
    v176._Bx._Buf[0] = 0;
    v164._Myres = 7;
    v164._Mysize = 0;
    v164._Bx._Buf[0] = 0;
    std::wstring::assign(&v164, L"GAP", 3u);
    v200 = 31;
    v98 = acTranslate(&v182, &v164);
    LOBYTE(v200) = 32;
    Font::blitString(v2->titleFont._Ptr, v2->time_gapX - 5.0, v2->wtop1, v98, 1.0, eAlignRight);
    if ( v182._Myres >= 8 )
      v3(v182._Bx._Ptr);
    v200 = -1;
    v182._Myres = 7;
    v182._Mysize = 0;
    v182._Bx._Buf[0] = 0;
    if ( v164._Myres >= 8 )
      v3(v164._Bx._Ptr);
    v164._Myres = 7;
    v164._Bx._Buf[0] = 0;
    v99 = v2->sim;
    v164._Mysize = 0;
    if ( v99->client )
    {
      std::wstring::wstring(&v178, L"P");
      v200 = 33;
      v100 = acTranslate(&v190, &v178);
      LOBYTE(v200) = 34;
      Font::blitString(v2->titleFont._Ptr, v2->time_pingX - 5.0, v2->wtop1, v100, 1.0, eAlignRight);
      if ( v190._Myres >= 8 )
        v3(v190._Bx._Ptr);
      v200 = -1;
      v190._Myres = 7;
      v190._Mysize = 0;
      v190._Bx._Buf[0] = 0;
      if ( v178._Myres >= 8 )
        v3(v178._Bx._Ptr);
      v178._Myres = 7;
      v178._Mysize = 0;
      v178._Bx._Buf[0] = 0;
      std::wstring::wstring(&v179, word_17BE9D8);
      v200 = 35;
      Font::blitString(v2->titleFont._Ptr, v2->time_kickX, v2->wtop1, &v179, 1.0, eAlignLeft);
      v200 = -1;
      if ( v179._Myres >= 8 )
        v3(v179._Bx._Ptr);
      v179._Myres = 7;
      v179._Mysize = 0;
      v179._Bx._Buf[0] = 0;
    }
LABEL_146:
    GLRenderer::color4f(v158, &colDarkTransp_12);
    GLRenderer::quad(
      v158,
      a.left,
      (float)(v2->rect.bottom - v2->rect.top) + a.top,
      v2->rect.right - v2->rect.left,
      40.0,
      0,
      0);
    a.top = a.top + 20.0;
  }
  v125 = v2->btKick;
  if ( v125 && v125->visible )
  {
    v126 = v125->__vftable;
    v125->visible = 0;
    ((void (__stdcall *)(_DWORD))v126->onVisibleChanged)(0);
  }
  v149 = 0;
  RaceManager::getLeaderboardFromSession(v2->sim->raceManager, &lb, v2->sessionID);
  v200 = 36;
  if ( v2->focusOnPlayer )
  {
    v127 = lb._Myfirst;
    v128 = 0;
    v129 = lb._Mylast;
    leaderboardIndex = 0;
    if ( lb._Myfirst != lb._Mylast )
    {
      do
      {
        v65 = v127->car == Sim::getCar(this->sim, 0);
        v128 = leaderboardIndex;
        if ( v65 )
          break;
        v128 = leaderboardIndex + 1;
        ++v127;
        ++leaderboardIndex;
      }
      while ( v127 != v129 );
      v129 = lb._Mylast;
      v127 = lb._Myfirst;
    }
    this->currentPage = v128 / this->rows;
    if ( leaderboardIndex - 3 <= leaderboardIndex )
    {
      v130 = leaderboardIndex - 3;
      if ( leaderboardIndex - 3 < 0 )
        v130 = 0;
      leaderboardIndex = v130;
    }
    v131 = this->rows;
    v132 = v129 - v127 - 1;
    v133 = leaderboardIndex;
    v162.time = v132;
    v134 = v131 + leaderboardIndex;
    if ( v131 + leaderboardIndex <= v132 )
    {
      if ( v134 < 0 )
        v134 = 0;
      v155 = v134;
    }
    else
    {
      v134 = v132;
      v155 = v132;
    }
    if ( v134 - leaderboardIndex < v131 )
    {
      v133 = v162.time;
      v135 = v134 - v131 + 1;
      if ( v135 <= v162.time )
      {
        v133 = v134 - v131 + 1;
        if ( v135 < 0 )
          v133 = 0;
      }
    }
    if ( v133 > v134 )
    {
      v2 = this;
    }
    else
    {
      v136 = 32 * v133;
      leaderboardIndexa = v133;
      while ( 1 )
      {
        v137 = std::wstring::compare(
                 &(*(CarAvatar **)((char *)&v127->car + v136))->driverInfo.name,
                 0,
                 (*(CarAvatar **)((char *)&v127->car + v136))->driverInfo.name._Mysize,
                 word_17BE9D8,
                 0);
        v2 = this;
        if ( v137 )
        {
          ACStandardLeaderboard::retrieveRowInfo(this, &v162, &lb, v133);
          ACStandardLeaderboard::printLBCar(
            this,
            v133,
            &lb._Myfirst[leaderboardIndexa],
            v162.time,
            v162.gap,
            (ksgui::ksRect)_mm_loadu_si128((const __m128i *)&a));
          std::vector<CarAvatar *>::push_back(
            (std::vector<int> *)&this->printedCars,
            (int *)&lb._Myfirst[leaderboardIndexa]);
          v138 = ++v149;
          a.top = a.top + 30.5;
        }
        else
        {
          v138 = v149;
        }
        if ( v138 >= this->rows )
          break;
        ++v133;
        v136 = leaderboardIndexa * 32 + 32;
        ++leaderboardIndexa;
        if ( v133 > v155 )
          break;
        v127 = lb._Myfirst;
      }
    }
  }
  else
  {
    v139 = 0;
    v157 = 0;
    if ( !(lb._Mylast - lb._Myfirst) )
      goto LABEL_187;
    v140 = 0;
    v141 = 0;
    v150 = 0;
    do
    {
      if ( v139 >= v2->currentPage * v2->rows && v139 < v2->rows * (v2->currentPage + 1) )
      {
        if ( std::wstring::compare(
               &(*(CarAvatar **)((char *)&lb._Myfirst->car + v140))->driverInfo.name,
               0,
               (*(CarAvatar **)((char *)&lb._Myfirst->car + v140))->driverInfo.name._Mysize,
               word_17BE9D8,
               0) )
        {
          ACStandardLeaderboard::retrieveRowInfo(v2, &v162, &lb, (const int)v157);
          ACStandardLeaderboard::printLBCar(
            v2,
            v141 + v2->currentPage * v2->rows,
            (const LeaderboardEntry *)((char *)lb._Myfirst + v150),
            v162.time,
            v162.gap,
            (ksgui::ksRect)_mm_loadu_si128((const __m128i *)&a));
          std::vector<CarAvatar *>::push_back((std::vector<int> *)&v2->printedCars, (int *)((char *)lb._Myfirst + v150));
          ++v141;
          a.top = a.top + 30.5;
        }
        v140 = v150;
        v139 = (int)v157;
      }
      ++v139;
      v140 += 32;
      v157 = (ACStandardLeaderboard *)v139;
      v150 = v140;
    }
    while ( v139 < (unsigned int)(lb._Mylast - lb._Myfirst) );
    v149 = v141;
  }
  v3 = operator delete;
LABEL_187:
  Font::setColor(v2->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v142 = RaceManager::getSessionInfo(v2->sim->raceManager, &result, v2->sessionID);
  LOBYTE(v200) = 37;
  v143 = acTranslate(&v163, &v142->name);
  LOBYTE(v200) = 38;
  Font::blitString(v2->dataFont._Ptr, v2->entry_nameX, a.bottom + 10.0, v143, 1.0, eAlignLeft);
  if ( v163._Myres >= 8 )
    v3(v163._Bx._Ptr);
  v163._Myres = 7;
  v163._Mysize = 0;
  v163._Bx._Buf[0] = 0;
  LOBYTE(v200) = 36;
  Session::~Session(&result);
  if ( v149 != v2->rows )
  {
    GLRenderer::color4f(v158, colDarkTransp_12.x, colDarkTransp_12.y, colDarkTransp_12.z, colDarkTransp_12.w);
    GLRenderer::quad(v158, a.left, a.top, v2->rect.right - v2->rect.left, (float)(v2->rows - v149) * 30.5, 0, 0);
  }
  ksgui::Control::render(v2, (int)v3, (int)v2, dt, v145, v146);
  v200 = -1;
  if ( lb._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&lb);
    v3(lb._Myfirst);
  }
}
ACStandardLeaderboard::RowInfo *ACStandardLeaderboard::retrieveRowInfo(ACStandardLeaderboard *this, ACStandardLeaderboard::RowInfo *result, const std::vector<LeaderboardEntry> *lb, const int leaderboardIndex)
{
  bool v4; // bl
  int v5; // ecx
  LeaderboardEntry *v6; // eax
  int v7; // ebx
  LeaderboardEntry *v8; // edi
  int v9; // eax
  ACStandardLeaderboard::RowInfo *v10; // eax
  Session v11; // [esp+10h] [ebp-68h] BYREF

  result->time = 0;
  result->gap = 0;
  v4 = RaceManager::getSessionInfo(this->sim->raceManager, &v11, this->sessionID)->sessionType == Race;
  if ( v11.name._Myres >= 8 )
    operator delete(v11.name._Bx._Ptr);
  v11.name._Myres = 7;
  v11.name._Mysize = 0;
  v11.name._Bx._Buf[0] = 0;
  if ( v11.spawSet._Myres >= 8 )
    operator delete(v11.spawSet._Bx._Ptr);
  v5 = leaderboardIndex;
  v6 = lb->_Myfirst;
  if ( v4 )
  {
    v7 = (int)v6[v5].totalTime;
    result->time = v7;
    if ( leaderboardIndex - 1 >= 0 )
    {
      if ( v7 )
      {
        v8 = lb->_Myfirst;
        if ( v8[v5 - 1].laps == v8[v5].laps )
          result->gap = (int)((double)v7 - v8->totalTime);
      }
    }
  }
  else
  {
    v9 = (int)v6[v5].bestLap;
    if ( v9 < 0 )
      v9 = 0;
    result->time = v9;
    if ( time )
      result->gap = (int)((double)result->time - lb->_Myfirst->bestLap);
  }
  v10 = result;
  if ( !leaderboardIndex )
    result->gap = -1;
  return v10;
}
void ACStandardLeaderboard::printLBCar(ACStandardLeaderboard *this, int rowIndex, const LeaderboardEntry *lb, int time, int gap, ksgui::ksRect wrect)
{
  int v7; // ebx
  Sim *v8; // eax
  GLRenderer *v9; // esi
  vec4f r; // xmm0
  std::wstring *v11; // eax
  void (__cdecl *v12)(void *); // esi
  DriverInfo *v13; // ecx
  signed int v14; // eax
  std::wostream *v15; // eax
  std::wostream *v16; // eax
  int v17; // esi
  ACStandardLeaderboard_vtbl *v18; // eax
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v19; // xmm0
  Font *v20; // ecx
  const std::wstring *v21; // eax
  CarAvatar *const *v22; // eax
  int v23; // eax
  const Texture *v24; // eax
  const std::wstring *v25; // eax
  std::wstring *v26; // eax
  int v27; // eax
  const std::wstring *v28; // eax
  LeaderboardMode v29; // eax
  const std::wstring *v30; // eax
  const std::wstring *v31; // eax
  bool v32; // al
  float v33; // xmm0_4
  Sim *v34; // ecx
  Sim *v35; // ecx
  RaceManager *v36; // ecx
  const std::wstring *v37; // eax
  const std::wstring *v38; // eax
  Font *v39; // ecx
  unsigned int v40; // eax
  float v41; // xmm0_4
  Sim *v42; // ecx
  RaceManager *v43; // ecx
  const std::wstring *v44; // eax
  Sim *v45; // ecx
  const std::wstring *v46; // eax
  const std::wstring *v47; // eax
  Font *v48; // ecx
  bool v49; // al
  RaceManager *v50; // ecx
  unsigned int v51; // esi
  Lap *v52; // eax
  const std::wstring *v53; // eax
  void (__cdecl *v54)(void *); // esi
  Lap *v55; // eax
  const std::wstring *v56; // eax
  Lap *v57; // eax
  const std::wstring *v58; // eax
  float v59; // xmm1_4
  const std::wstring *v60; // eax
  int v61; // ebx
  Font *v62; // ecx
  const std::wstring *v63; // eax
  const std::wstring *v64; // eax
  const std::wstring *v65; // eax
  const std::wstring *v66; // eax
  std::wstring *v67; // eax
  int v68; // ebx
  Session *v69; // eax
  char v70; // bl
  bool v71; // zf
  Session *v72; // eax
  const std::wstring *v73; // eax
  const std::wstring *v74; // eax
  double v75; // st7
  CarAvatar *v76; // ecx
  int v77; // ebx
  std::wstring *v78; // eax
  std::wstring *v79; // eax
  std::wstring *v80; // eax
  std::wstring *v81; // eax
  const std::wstring *v82; // eax
  const char *r_8; // [esp+18h] [ebp-540h]
  CarAvatar *r_16a; // [esp+20h] [ebp-538h]
  CarAvatar *r_16b; // [esp+20h] [ebp-538h]
  CarAvatar *r_16c; // [esp+20h] [ebp-538h]
  CarAvatar *r_16d; // [esp+20h] [ebp-538h]
  CarAvatar *r_16; // [esp+20h] [ebp-538h]
  float y; // [esp+3Ch] [ebp-51Ch]
  int s; // [esp+40h] [ebp-518h] BYREF
  GLRenderer *v91; // [esp+44h] [ebp-514h]
  std::wstring *nationCode; // [esp+48h] [ebp-510h]
  int v93; // [esp+4Ch] [ebp-50Ch]
  CarAvatar *v94; // [esp+50h] [ebp-508h]
  int v95; // [esp+54h] [ebp-504h]
  bool isGlobal[4]; // [esp+58h] [ebp-500h] BYREF
  int t; // [esp+5Ch] [ebp-4FCh] BYREF
  vec2f localCoords; // [esp+60h] [ebp-4F8h] BYREF
  Lap l; // [esp+68h] [ebp-4F0h] BYREF
  std::wstring v100; // [esp+98h] [ebp-4C0h] BYREF
  std::wstring result; // [esp+B0h] [ebp-4A8h] BYREF
  std::wstring v102; // [esp+C8h] [ebp-490h] BYREF
  std::wstring v103; // [esp+E0h] [ebp-478h] BYREF
  std::wstring text; // [esp+F8h] [ebp-460h] BYREF
  std::wstring carSubStr; // [esp+110h] [ebp-448h] BYREF
  std::wstring v106; // [esp+128h] [ebp-430h] BYREF
  std::wstring v107; // [esp+140h] [ebp-418h] BYREF
  std::wstring v108; // [esp+158h] [ebp-400h] BYREF
  std::wstring v109; // [esp+170h] [ebp-3E8h] BYREF
  std::wstring v110; // [esp+188h] [ebp-3D0h] BYREF
  std::wstring v111; // [esp+1A0h] [ebp-3B8h] BYREF
  std::wstring v112; // [esp+1B8h] [ebp-3A0h] BYREF
  std::wstring v113; // [esp+1D0h] [ebp-388h] BYREF
  std::wstring v114; // [esp+1E8h] [ebp-370h] BYREF
  std::wstring v115; // [esp+200h] [ebp-358h] BYREF
  std::wstring v116; // [esp+218h] [ebp-340h] BYREF
  std::wstring v117; // [esp+230h] [ebp-328h] BYREF
  std::wstring v118; // [esp+248h] [ebp-310h] BYREF
  std::wstring v119; // [esp+260h] [ebp-2F8h] BYREF
  std::wstring v120; // [esp+278h] [ebp-2E0h] BYREF
  std::wstring v121; // [esp+290h] [ebp-2C8h] BYREF
  std::wstring v122; // [esp+2A8h] [ebp-2B0h] BYREF
  std::wstring substring; // [esp+2C0h] [ebp-298h] BYREF
  std::wstring v124; // [esp+2D8h] [ebp-280h] BYREF
  std::wstring v125; // [esp+2F0h] [ebp-268h] BYREF
  Lap v126; // [esp+308h] [ebp-250h] BYREF
  std::wstring v127; // [esp+338h] [ebp-220h] BYREF
  std::wstring v128; // [esp+350h] [ebp-208h] BYREF
  std::wstring v129; // [esp+368h] [ebp-1F0h] BYREF
  std::wstring v130; // [esp+380h] [ebp-1D8h] BYREF
  std::wstring v131; // [esp+398h] [ebp-1C0h] BYREF
  std::wstring v132; // [esp+3B0h] [ebp-1A8h] BYREF
  Lap v133; // [esp+3C8h] [ebp-190h] BYREF
  Lap v134; // [esp+3F8h] [ebp-160h] BYREF
  Lap v135; // [esp+428h] [ebp-130h] BYREF
  Lap v136; // [esp+458h] [ebp-100h] BYREF
  Session v137; // [esp+488h] [ebp-D0h] BYREF
  Session v138; // [esp+4E8h] [ebp-70h] BYREF
  int v139; // [esp+554h] [ebp-4h]

  v7 = 0;
  t = time;
  v95 = 0;
  s = gap;
  v8 = this->sim;
  v94 = (CarAvatar *)rowIndex;
  y = wrect.top + 5.0;
  v9 = v8->game->graphics->gl;
  v91 = v9;
  if ( rowIndex % 2 )
    r = colDarkTransp_12;
  else
    r = colDarkBar;
  GLRenderer::color4f(v9, r.x, r.y, r.z, r.w);
  GLRenderer::quad(v9, wrect.left, wrect.top, this->rect.right - this->rect.left, 30.5, 0, 0);
  v100._Myres = 7;
  v100._Mysize = 0;
  v100._Bx._Buf[0] = 0;
  std::wstring::assign(&v100, word_17BE9D8, 0);
  v139 = 0;
  std::wstringbuf::_Tidy((std::wstringbuf *)&wstringStream.gap10[8]);
  v11 = &v100;
  if ( v100._Myres >= 8 )
    v11 = (std::wstring *)v100._Bx._Ptr;
  std::wstringbuf::_Init(
    (std::wstringbuf *)&wstringStream.gap10[8],
    v11->_Bx._Buf,
    v100._Mysize,
    *(int *)&wstringStream.gap10[68]);
  v139 = -1;
  v12 = operator delete;
  if ( v100._Myres >= 8 )
    operator delete(v100._Bx._Ptr);
  v13 = &lb->car->driverInfo;
  nationCode = &lb->car->driverInfo.nationCode;
  v14 = v13->name._Mysize;
  if ( v14 > 20 )
    v14 = 20;
  std::wstring::substr(&v13->name, &substring, 0, v14);
  v139 = 1;
  if ( (int)&v94->__vftable + 1 < 10 )
    r_8 = ".    ";
  else
    r_8 = ".   ";
  v15 = (std::wostream *)std::wostream::operator<<(wstringStream.gap10, (char *)&v94->__vftable + 1);
  v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v15, r_8);
  std::operator<<<wchar_t>(v16, &substring);
  v94 = this->avatarToBeKicked;
  if ( *(float *)&v94 != 0.0 )
  {
    v17 = CarAvatar::getGuid(lb->car);
    if ( CarAvatar::getGuid(v94) == v17 && CarAvatar::isConnected(lb->car) )
    {
      GLRenderer::color4f(v91, 0.74000001, 0.0, 0.0, 1.0);
      GLRenderer::quad(v91, wrect.left, wrect.top, 5.0, 30.5, 0, 0);
      if ( this->btKick )
      {
        if ( CarAvatar::getGuid(lb->car) )
        {
          v18 = this->__vftable;
          v100._Bx._Ptr = (wchar_t *)LODWORD(this->time_kickX);
          *(float *)&v100._Bx._Alias[4] = wrect.top;
          v18->worldToLocal(this, &localCoords, (const vec2f *)&v100);
          ksgui::Form::setPosition((ksgui::Form *)this->btKick, localCoords.x, localCoords.y);
          ksgui::Control::setVisible(this->btKick, 1);
        }
      }
    }
    v12 = operator delete;
  }
  if ( CarAvatar::getGuid(lb->car) )
  {
    if ( CarAvatar::isConnected(lb->car) )
      v19 = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
    else
      v19 = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
  }
  else
  {
    v19 = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
  }
  v20 = this->dataFont._Ptr;
  v100._Bx = v19;
  Font::setColor(v20, (const vec4f *)&v100);
  v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&wstringStream, &result);
  LOBYTE(v139) = 2;
  Font::blitString(this->dataFont._Ptr, this->time_nameX, y, v21, 1.0, eAlignLeft);
  LOBYTE(v139) = 1;
  if ( result._Myres >= 8 )
    v12(result._Bx._Ptr);
  v22 = std::map<CarAvatar *,Texture>::operator[](&this->skinTextures, &lb->car);
  GraphicsManager::setTexture(this->sim->game->graphics, 0, (const Texture *)v22);
  GLRenderer::color4f(v91, 1.0, 1.0, 1.0, 1.0);
  GLRenderer::quad(v91, this->time_carX, wrect.top + 3.0, 21.0, 21.0, 1, 0);
  v23 = lb->car->guiShortName._Mysize;
  if ( v23 > 18 )
    v23 = 18;
  std::wstring::substr(&lb->car->guiShortName, &carSubStr, 0, v23);
  LOBYTE(v139) = 3;
  v24 = Sim::getNationFlag(this->sim, nationCode);
  GraphicsManager::setTexture(this->sim->game->graphics, 0, v24);
  GLRenderer::color4f(v91, 1.0, 1.0, 1.0, 1.0);
  GLRenderer::quad(v91, this->time_flagX, wrect.top + 4.0, 20.0, 20.0, 1, 0);
  if ( s >= 0 )
  {
    v25 = timeToDiffString(&result, s, 3);
    LOBYTE(v139) = 4;
    Font::blitString(this->dataFont._Ptr, this->time_gapX, y, v25, 1.0, eAlignRight);
    LOBYTE(v139) = 3;
    if ( result._Myres >= 8 )
      v12(result._Bx._Ptr);
  }
  if ( this->sim->client )
  {
    v100._Myres = 7;
    v100._Mysize = 0;
    v100._Bx._Buf[0] = 0;
    std::wstring::assign(&v100, word_17BE9D8, 0);
    LOBYTE(v139) = 5;
    std::wstringbuf::_Tidy((std::wstringbuf *)&wstringStream.gap10[8]);
    v26 = &v100;
    if ( v100._Myres >= 8 )
      v26 = (std::wstring *)v100._Bx._Ptr;
    std::wstringbuf::_Init(
      (std::wstringbuf *)&wstringStream.gap10[8],
      v26->_Bx._Buf,
      v100._Mysize,
      *(int *)&wstringStream.gap10[68]);
    LOBYTE(v139) = 3;
    if ( v100._Myres >= 8 )
      v12(v100._Bx._Ptr);
    if ( CarAvatar::isConnected(lb->car) )
    {
      v27 = ACClient::getPing(this->sim->client, lb->car);
      std::wostream::operator<<(wstringStream.gap10, v27);
    }
    else
    {
      std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)wstringStream.gap10, "---");
    }
    v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            &wstringStream,
            &result);
    LOBYTE(v139) = 6;
    Font::blitString(this->dataFont._Ptr, this->entry_pingX, y, v28, 1.0, eAlignRight);
    LOBYTE(v139) = 3;
    if ( result._Myres >= 8 )
      v12(result._Bx._Ptr);
  }
  v29 = this->mode;
  if ( v29 == eEntryList )
  {
    if ( lb->car->isBlackFlagged )
    {
      std::wstring::wstring(&text, L"Retired");
      LOBYTE(v139) = 7;
      v64 = acTranslate(&v114, &text);
      LOBYTE(v139) = 8;
      Font::blitString(this->dataFont._Ptr, this->entry_timeX, y, v64, 1.0, eAlignRight);
      if ( v114._Myres >= 8 )
        v12(v114._Bx._Ptr);
      LOBYTE(v139) = 3;
      v114._Myres = 7;
      v114._Mysize = 0;
      v114._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        v12(text._Bx._Ptr);
      text._Myres = 7;
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
    }
    else
    {
      v65 = timeToString(&v116, t, 3);
      LOBYTE(v139) = 9;
      Font::blitString(this->dataFont._Ptr, this->entry_timeX, y, v65, 1.0, eAlignRight);
      LOBYTE(v139) = 3;
      if ( v116._Myres >= 8 )
        v12(v116._Bx._Ptr);
      v116._Myres = 7;
      v116._Mysize = 0;
      v116._Bx._Buf[0] = 0;
    }
    Font::blitString(this->dataFont._Ptr, this->entry_carX + 30.0, y, &carSubStr, 1.0, eAlignLeft);
    v66 = CarAvatar::getCurrentCompoundShortName(lb->car, &v118);
    LOBYTE(v139) = 10;
    Font::blitString(this->dataFont._Ptr, this->entry_tyresX + 5.0, y, v66, 1.0, eAlignLeft);
    LOBYTE(v139) = 3;
    if ( v118._Myres >= 8 )
      v12(v118._Bx._Ptr);
    v118._Myres = 7;
    v118._Mysize = 0;
    v118._Bx._Buf[0] = 0;
    std::wstring::wstring(&v102, word_17BE9D8);
    LOBYTE(v139) = 11;
    std::wstringbuf::_Tidy((std::wstringbuf *)&wstringStream.gap10[8]);
    v67 = &v102;
    if ( v102._Myres >= 8 )
      v67 = (std::wstring *)v102._Bx._Ptr;
    std::wstringbuf::_Init(
      (std::wstringbuf *)&wstringStream.gap10[8],
      v67->_Bx._Buf,
      v102._Mysize,
      *(int *)&wstringStream.gap10[68]);
    LOBYTE(v139) = 3;
    if ( v102._Myres >= 8 )
      v12(v102._Bx._Ptr);
    v102._Myres = 7;
    v102._Mysize = 0;
    v102._Bx._Buf[0] = 0;
    if ( lb->hasCompletedLastLap
      && (v68 = this->sessionID, v68 == RaceManager::getCurrentSessionIndex(this->sim->raceManager)) )
    {
      v69 = RaceManager::getSessionInfo(this->sim->raceManager, &v138, v68);
      LOBYTE(v139) = 12;
      v70 = 1;
      v71 = v69->sessionType == Race;
      v95 = 1;
      if ( !v71
        || (v72 = RaceManager::getSessionInfo(this->sim->raceManager, &v137, this->sessionID),
            v70 = 3,
            HIBYTE(v93) = 1,
            !v72->isTimedRace) )
      {
        HIBYTE(v93) = 0;
      }
      if ( (v70 & 2) != 0 )
      {
        v70 &= 0xFDu;
        Session::~Session(&v137);
      }
      v139 = 3;
      if ( (v70 & 1) != 0 )
        Session::~Session(&v138);
      if ( HIBYTE(v93) )
      {
        std::wostream::operator<<(wstringStream.gap10, lb->laps);
        v73 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &wstringStream,
                &v127);
        LOBYTE(v139) = 13;
        Font::blitString(this->dataFont._Ptr, this->entry_lapsX, y, v73, 1.0, eAlignRight);
        LOBYTE(v139) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v127);
      }
      else
      {
        GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txMiniFinish);
        GLRenderer::color4f(v91, 1.0, 1.0, 1.0, 1.0);
        GLRenderer::quad(v91, this->entry_lapsX - 21.0, wrect.top + 3.0, 21.0, 21.0, 1, 0);
      }
    }
    else
    {
      std::wostream::operator<<(wstringStream.gap10, lb->laps);
      v74 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &wstringStream,
              &v120);
      LOBYTE(v139) = 14;
      Font::blitString(this->dataFont._Ptr, this->entry_lapsX, y, v74, 1.0, eAlignRight);
      LOBYTE(v139) = 3;
      if ( v120._Myres >= 8 )
        v12(v120._Bx._Ptr);
      v120._Myres = 7;
      v120._Mysize = 0;
      v120._Bx._Buf[0] = 0;
    }
    if ( this->sim->client )
    {
      v75 = CarAvatar::getBallastKG(lb->car);
      v76 = lb->car;
      *(float *)&nationCode = v75;
      *(float *)&v94 = CarAvatar::getRestrictor(v76);
      v77 = (int)*(float *)&v94;
      std::wstring::wstring((std::wstring *)&l, word_17BE9D8);
      LOBYTE(v139) = 15;
      if ( (int)*(float *)&nationCode )
      {
        v78 = std::to_wstring(&v131, (int)*(float *)&nationCode);
        LOBYTE(v139) = 16;
        v79 = std::operator+<wchar_t>(&v129, L"+", v78);
        LOBYTE(v139) = 17;
        v80 = std::operator+<wchar_t>(&v132, v79, L"Kg/");
        std::wstring::operator=((std::wstring *)&l, v80);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v132);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v129);
        LOBYTE(v139) = 15;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v131);
      }
      else
      {
        std::wstring::assign((std::wstring *)&l, L"0Kg/");
      }
      if ( v77 )
      {
        v81 = std::to_wstring(&v124, v77);
        LOBYTE(v139) = 18;
        v82 = std::operator+<wchar_t>(&v128, v81, L"%");
        LOBYTE(v139) = 19;
        std::wstring::append((std::wstring *)&l, v82, 0, 0xFFFFFFFF);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v128);
        LOBYTE(v139) = 15;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v124);
      }
      else
      {
        std::wstring::operator+=((std::wstring *)&l, L"0%");
      }
      Font::blitString(
        this->dataFont._Ptr,
        this->entry_ballastX + 20.0,
        y + 2.0,
        (const std::wstring *)&l,
        0.80000001,
        eAlignRight);
      if ( *(_DWORD *)&l.isValid >= 8u )
        v12((void *)l.time);
    }
    goto LABEL_175;
  }
  if ( v29 != eTimeTable )
  {
LABEL_175:
    v54 = operator delete;
    goto LABEL_176;
  }
  if ( lb->car->isBlackFlagged )
  {
    std::wstring::wstring(&result, L"Retired");
    LOBYTE(v139) = 40;
    v63 = acTranslate(&v112, &result);
    LOBYTE(v139) = 41;
    Font::blitString(this->dataFont._Ptr, this->time_timeX, y, v63, 1.0, eAlignRight);
    if ( v112._Myres >= 8 )
      v12(v112._Bx._Ptr);
    v112._Myres = 7;
    v112._Mysize = 0;
    v112._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      v12(result._Bx._Ptr);
    goto LABEL_175;
  }
  RaceManager::getLastLap(this->sim->raceManager, &l, lb->car);
  LOBYTE(v139) = 20;
  if ( l.isValid || !l.time )
  {
    v31 = timeToString(&v113, l.time, 3);
    LOBYTE(v139) = 22;
    Font::blitString(this->dataFont._Ptr, this->time_lastlapX, y, v31, 1.0, eAlignRight);
    LOBYTE(v139) = 20;
    if ( v113._Myres >= 8 )
      v12(v113._Bx._Ptr);
    v113._Myres = 7;
    v113._Mysize = 0;
    v113._Bx._Buf[0] = 0;
  }
  else
  {
    GLRenderer::color4f(v91, 1.0, 0.0, 0.0, 0.69999999);
    GLRenderer::quad(v91, this->time_lastlapX - 94.0, y, 96.0, 18.0, 0, 0);
    v30 = timeToString(&v125, l.time, 3);
    LOBYTE(v139) = 21;
    Font::blitString(this->blackFont._Ptr, this->time_lastlapX, y, v30, 1.0, eAlignRight);
    LOBYTE(v139) = 20;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v125);
  }
  for ( s = 0; s < 3; ++s )
  {
    v32 = RaceManager::getHasCompletedFlag(this->sim->raceManager, lb->car);
    v33 = 0.0;
    *(float *)&nationCode = 0.0;
    if ( !v32 )
    {
      RaceManager::getCurrentLap(this->sim->raceManager, &v126, lb->car);
      LOBYTE(v139) = 26;
      if ( v126.splits._Myfirst == v126.splits._Mylast )
      {
        if ( RaceManager::getLastSplit(this->sim->raceManager, lb->car, &s) < 0xF423F )
        {
          v40 = RaceManager::getLastSplit(this->sim->raceManager, lb->car, &s);
LABEL_75:
          v41 = (float)v40;
          *(float *)&nationCode = v41;
LABEL_80:
          r_16c = lb->car;
          v42 = this->sim;
          isGlobal[0] = 1;
          v100._Bx._Ptr = (wchar_t *)(int)v41;
          v43 = v42->raceManager;
          v94 = (CarAvatar *)(int)v41;
          if ( RaceManager::isBestSplit(v43, &s, (const int *)&v100, isGlobal, r_16c) && *(float *)&nationCode != 0.0 )
          {
            GLRenderer::color4f(v91, 1.0, 0.0, 1.0, 0.69999999);
            GLRenderer::quad(v91, this->time_splitX[s] - 44.0, y, 46.0, 18.0, 0, 0);
            v44 = timeToSectorString(&v119, (int)v94, 1);
            LOBYTE(v139) = 27;
            Font::blitString(this->blackFont._Ptr, this->time_splitX[s], y, v44, 1.0, eAlignRight);
            if ( v119._Myres >= 8 )
              v12(v119._Bx._Ptr);
            v119._Myres = 7;
            v119._Mysize = 0;
            v119._Bx._Buf[0] = 0;
            goto LABEL_99;
          }
          r_16d = lb->car;
          v45 = this->sim;
          t = (int)v94;
          isGlobal[2] = 0;
          if ( RaceManager::isBestSplit(v45->raceManager, &s, &t, &isGlobal[2], r_16d) )
          {
            if ( *(float *)&nationCode != 0.0 )
            {
              GLRenderer::color4f(v91, 0.0, 1.0, 0.0, 0.69999999);
              GLRenderer::quad(v91, this->time_splitX[s] - 44.0, y, 46.0, 18.0, 0, 0);
              v46 = timeToSectorString(&v130, (int)v94, 1);
              LOBYTE(v139) = 28;
              Font::blitString(this->blackFont._Ptr, this->time_splitX[s], y, v46, 1.0, eAlignRight);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v130);
LABEL_99:
              LOBYTE(v139) = 20;
              Lap::~Lap(&v126);
              continue;
            }
          }
          else if ( *(float *)&nationCode != 0.0 )
          {
            v47 = timeToSectorString(&v117, (int)*(float *)&nationCode, 1);
            LOBYTE(v139) = 29;
            v7 |= 0x10u;
LABEL_91:
            v48 = this->dataFont._Ptr;
            v95 = v7;
            Font::blitString(v48, this->time_splitX[s], y, v47, 1.0, eAlignRight);
            if ( (v7 & 0x20) != 0 )
            {
              v7 &= 0xFFFFFFDF;
              v95 = v7;
              if ( v111._Myres >= 8 )
                v12(v111._Bx._Ptr);
              v111._Myres = 7;
              v111._Mysize = 0;
              v111._Bx._Buf[0] = 0;
            }
            v139 = 26;
            if ( (v7 & 0x10) != 0 )
            {
              v7 &= 0xFFFFFFEF;
              v95 = v7;
              if ( v117._Myres >= 8 )
                v12(v117._Bx._Ptr);
              v117._Myres = 7;
              v117._Mysize = 0;
              v117._Bx._Buf[0] = 0;
            }
            goto LABEL_99;
          }
          std::wstring::wstring(&v111, L"---");
          v139 = 30;
          v7 |= 0x20u;
          goto LABEL_91;
        }
      }
      else
      {
        if ( s >= (unsigned int)(v126.splits._Mylast - v126.splits._Myfirst) )
        {
          v41 = *(float *)&nationCode;
          goto LABEL_80;
        }
        if ( RaceManager::getSplit(this->sim->raceManager, lb->car, &s) < 0xF423F )
        {
          v40 = RaceManager::getSplit(this->sim->raceManager, lb->car, &s);
          goto LABEL_75;
        }
      }
      v40 = 999999;
      goto LABEL_75;
    }
    if ( s < (unsigned int)(l.splits._Mylast - l.splits._Myfirst) )
    {
      r_16a = lb->car;
      v34 = this->sim;
      isGlobal[1] = 0;
      v33 = (float)RaceManager::getBestSplit(v34->raceManager, &s, &isGlobal[1], r_16a);
      *(float *)&nationCode = v33;
    }
    r_16b = lb->car;
    v35 = this->sim;
    isGlobal[3] = 1;
    LODWORD(localCoords.x) = (int)v33;
    v36 = v35->raceManager;
    v94 = (CarAvatar *)(int)v33;
    if ( !RaceManager::isBestSplit(v36, &s, (const int *)&localCoords, &isGlobal[3], r_16b)
      || *(float *)&nationCode == 0.0 )
    {
      GLRenderer::color4f(v91, 1.0, 1.0, 1.0, 1.0);
      GLRenderer::quad(v91, this->time_splitX[s] - 44.0, y, 46.0, 18.0, 0, 0);
      if ( *(float *)&nationCode == 0.0 )
      {
        std::wstring::wstring(&v122, L"---");
        v139 = 25;
        v7 |= 8u;
      }
      else
      {
        v38 = timeToSectorString(&v109, (int)*(float *)&nationCode, 1);
        LOBYTE(v139) = 24;
        v7 |= 4u;
      }
      v39 = this->blackFont._Ptr;
      v95 = v7;
      Font::blitString(v39, this->time_splitX[s], y, v38, 1.0, eAlignRight);
      if ( (v7 & 8) != 0 )
      {
        v7 &= 0xFFFFFFF7;
        v95 = v7;
        if ( v122._Myres >= 8 )
          v12(v122._Bx._Ptr);
        v122._Myres = 7;
        v122._Mysize = 0;
        v122._Bx._Buf[0] = 0;
      }
      v139 = 20;
      if ( (v7 & 4) != 0 )
      {
        v7 &= 0xFFFFFFFB;
        v95 = v7;
        if ( v109._Myres >= 8 )
          v12(v109._Bx._Ptr);
        v109._Myres = 7;
        v109._Mysize = 0;
        v109._Bx._Buf[0] = 0;
      }
    }
    else
    {
      GLRenderer::color4f(v91, 1.0, 0.0, 1.0, 0.69999999);
      GLRenderer::quad(v91, this->time_splitX[s] - 44.0, y, 46.0, 18.0, 0, 0);
      v37 = timeToSectorString(&v115, (int)v94, 1);
      LOBYTE(v139) = 23;
      Font::blitString(this->blackFont._Ptr, this->time_splitX[s], y, v37, 1.0, eAlignRight);
      LOBYTE(v139) = 20;
      if ( v115._Myres >= 8 )
        v12(v115._Bx._Ptr);
      v115._Myres = 7;
      v115._Mysize = 0;
      v115._Bx._Buf[0] = 0;
    }
  }
  v49 = RaceManager::getHasCompletedFlag(this->sim->raceManager, lb->car);
  r_16 = lb->car;
  v50 = this->sim->raceManager;
  if ( v49 )
  {
    v51 = RaceManager::getBestLap(v50, &v133, r_16)->time;
    Lap::~Lap(&v133);
    if ( v51 > RaceManager::getBestLap(this->sim->raceManager) )
    {
      GLRenderer::color4f(v91, 1.0, 1.0, 1.0, 1.0);
      GLRenderer::quad(v91, this->time_timeX - 84.0, y, 86.0, 18.0, 0, 0);
      v55 = RaceManager::getBestLap(this->sim->raceManager, &v136, lb->car);
      LOBYTE(v139) = 33;
      v56 = timeToString(&v121, v55->time, 3);
      LOBYTE(v139) = 34;
      Font::blitString(this->blackFont._Ptr, this->time_timeX, y, v56, 1.0, eAlignRight);
      v54 = operator delete;
      if ( v121._Myres >= 8 )
        operator delete(v121._Bx._Ptr);
      v121._Myres = 7;
      v121._Mysize = 0;
      v121._Bx._Buf[0] = 0;
      LOBYTE(v139) = 20;
      Lap::~Lap(&v136);
    }
    else
    {
      GLRenderer::color4f(v91, 1.0, 0.0, 1.0, 0.69999999);
      GLRenderer::quad(v91, this->time_timeX - 84.0, y, 86.0, 18.0, 0, 0);
      v52 = RaceManager::getBestLap(this->sim->raceManager, &v135, lb->car);
      LOBYTE(v139) = 31;
      v53 = timeToString(&v106, v52->time, 3);
      LOBYTE(v139) = 32;
      Font::blitString(this->blackFont._Ptr, this->time_timeX, y, v53, 1.0, eAlignRight);
      v54 = operator delete;
      if ( v106._Myres >= 8 )
        operator delete(v106._Bx._Ptr);
      v106._Myres = 7;
      v106._Mysize = 0;
      v106._Bx._Buf[0] = 0;
      LOBYTE(v139) = 20;
      Lap::~Lap(&v135);
    }
  }
  else
  {
    v57 = RaceManager::getBestLap(v50, &v134, r_16);
    LOBYTE(v139) = 35;
    v58 = timeToString(&v107, v57->time, 3);
    LOBYTE(v139) = 36;
    Font::blitString(this->dataFont._Ptr, this->time_timeX, y, v58, 1.0, eAlignRight);
    if ( v107._Myres >= 8 )
      v12(v107._Bx._Ptr);
    v107._Myres = 7;
    v107._Mysize = 0;
    v107._Bx._Buf[0] = 0;
    LOBYTE(v139) = 20;
    Lap::~Lap(&v134);
    v54 = operator delete;
  }
  v59 = lb->car->physicsState.performanceMeter;
  if ( v59 > 99.0 || v59 < -99.0 )
  {
    v103._Myres = 7;
    v103._Mysize = 0;
    v103._Bx._Buf[0] = 0;
    std::wstring::assign(&v103, L"---", 3u);
    LOBYTE(v139) = 37;
    Font::blitString(this->dataFont._Ptr, this->time_deltaX, y, &v103, 1.0, eAlignRight);
    if ( v103._Myres >= 8 )
      v54(v103._Bx._Ptr);
    v103._Myres = 7;
    v103._Mysize = 0;
    v103._Bx._Buf[0] = 0;
  }
  else
  {
    if ( CarAvatar::isInPitlane(lb->car) )
    {
      std::wstring::wstring(&v110, L"Pit");
      LOBYTE(v139) = 38;
      v61 = v7 | 0x40;
    }
    else
    {
      v60 = timeToDiffString(&v108, (int)(float)(lb->car->physicsState.performanceMeter * 1000.0), 1);
      v139 = 39;
      v61 = v7 | 0x80;
    }
    v62 = this->dataFont._Ptr;
    v95 = v61;
    Font::blitString(v62, this->time_deltaX, y, v60, 1.0, eAlignRight);
    if ( (v61 & 0x80u) != 0 )
    {
      LOBYTE(v61) = v61 & 0x7F;
      if ( v108._Myres >= 8 )
        v54(v108._Bx._Ptr);
      v108._Myres = 7;
      v108._Mysize = 0;
      v108._Bx._Buf[0] = 0;
    }
    if ( (v61 & 0x40) != 0 )
    {
      if ( v110._Myres >= 8 )
        v54(v110._Bx._Ptr);
      v110._Myres = 7;
      v110._Mysize = 0;
      v110._Bx._Buf[0] = 0;
    }
  }
  if ( l.compound._Myres >= 8 )
    v54(l.compound._Bx._Ptr);
  l.compound._Myres = 7;
  l.compound._Bx._Buf[0] = 0;
  l.compound._Mysize = 0;
  if ( l.splits._Myfirst )
    v54(l.splits._Myfirst);
LABEL_176:
  if ( carSubStr._Myres >= 8 )
    v54(carSubStr._Bx._Ptr);
  carSubStr._Myres = 7;
  carSubStr._Mysize = 0;
  carSubStr._Bx._Buf[0] = 0;
  if ( substring._Myres >= 8 )
    v54(substring._Bx._Ptr);
}
char ACStandardLeaderboard::onMouseDown(ACStandardLeaderboard *this, const OnMouseDownEvent *message)
{
  ACStandardLeaderboard_vtbl *v3; // eax
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  CarAvatar *v14; // ecx
  unsigned int v15; // eax
  ksgui::ksRect wrect; // [esp+8h] [ebp-10h] BYREF

  ksgui::Control::onMouseDown(this, message);
  if ( !this->focusOnPlayer )
  {
    v3 = this->__vftable;
    wrect.left = 0.0;
    wrect.top = 0.0;
    wrect.right = 1.0;
    wrect.bottom = 1.0;
    v3->getWorldRect(this, &wrect);
    v4 = this->rect.left;
    v5 = v4 + wrect.right;
    v6 = this->rect.bottom - this->rect.top;
    v7 = v4 + wrect.left;
    wrect.right = v5;
    v8 = this->rect.top;
    wrect.left = v7;
    wrect.top = v8 + wrect.top;
    v9 = wrect.top + 20.0;
    v10 = v6 + wrect.top;
    wrect.bottom = v8 + wrect.bottom;
    v11 = (float)message->x;
    if ( v11 > v7 && (float)((float)(this->rect.right - this->rect.left) + v7) > v11 )
    {
      v12 = (float)message->y;
      if ( v12 > v9 && v10 > v12 )
      {
        v13 = (float)((float)(v12 - v9) / (float)(v10 - v9)) * (float)this->rows;
        this->selectedCarIndex = (int)v13;
        if ( (int)v13 < (unsigned int)(this->printedCars._Mylast - this->printedCars._Myfirst) )
        {
          v14 = this->printedCars._Myfirst[v13];
          this->avatarToBeKicked = v14;
          if ( CarAvatar::isConnected(v14) )
          {
            v15 = CarAvatar::getGuid(this->avatarToBeKicked);
            Sim::setFocusedCarIndex(this->sim, v15);
          }
        }
      }
    }
  }
  return 1;
}
