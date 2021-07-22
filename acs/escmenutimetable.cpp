#include "escmenutimetable.h
void __userpurge EscMenuTimeTable::EscMenuTimeTable(EscMenuTimeTable *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  Game *v4; // eax
  std::_Tree_node<std::pair<CarAvatar * const,Texture>,void *> *v5; // eax
  CarAvatar *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // esi
  CarAvatar *v9; // eax
  Font *v10; // eax
  std::_Ref_count_base *v11; // esi
  CarAvatar *v12; // eax
  Font *v13; // eax
  std::_Ref_count_base *v14; // esi
  CarAvatar *v15; // eax
  Font *v16; // eax
  std::_Ref_count_base *v17; // esi
  CarAvatar *v18; // esi
  ksgui::ActiveButton *v19; // eax
  ksgui::ActiveButton *v20; // ecx
  Event<OnMouseWheelMovedEvent> *v21; // ecx
  Font *v22; // esi
  ksgui::ActiveButton *v23; // eax
  ksgui::ActiveButton *v24; // ecx
  Event<OnMouseWheelMovedEvent> *v25; // ecx
  unsigned int i; // ebx
  CarAvatar *v27; // eax
  Sim *v28; // ecx
  CarAvatar *v29; // eax
  std::wstring *v30; // esi
  Sim *v31; // ecx
  CarAvatar *v32; // eax
  std::wstring *v33; // eax
  std::wstring *v34; // eax
  std::wstring *v35; // eax
  const std::wstring *v36; // ecx
  Sim *v37; // eax
  Texture *v38; // esi
  CarAvatar **v39; // ecx
  CarAvatar *v40; // eax
  const std::wstring *v41; // esi
  std::wstring *v42; // ecx
  Font *v43; // esi
  ksgui::Control *v44; // eax
  Sim *v45; // eax
  bool v46; // zf
  ksgui::Control *v47; // ecx
  std::_Ref_count_base *v48; // ebx
  CarAvatar *v49; // eax
  ksgui::Control *v50; // edx
  volatile signed __int32 *v51; // esi
  Event<OnMouseWheelMovedEvent> *v52; // ecx
  EscMenuTimeTable *j; // eax
  EscMenuTimeTable *k; // eax
  EscMenuTimeTable *l; // eax
  _BYTE v56[56]; // [esp+8h] [ebp-F4h] BYREF
  std::shared_ptr<Font> _Right; // [esp+44h] [ebp-B8h] BYREF
  CarAvatar *_Keyval; // [esp+4Ch] [ebp-B0h] BYREF
  int v59; // [esp+50h] [ebp-ACh]
  EscMenuTimeTable *v60; // [esp+54h] [ebp-A8h]
  std::wstring iname; // [esp+58h] [ebp-A4h] BYREF
  std::wstring v62; // [esp+70h] [ebp-8Ch] BYREF
  std::wstring v63; // [esp+88h] [ebp-74h] BYREF
  std::wstring v64; // [esp+A0h] [ebp-5Ch] BYREF
  std::wstring result; // [esp+B8h] [ebp-44h] BYREF
  Texture v66; // [esp+D0h] [ebp-2Ch] BYREF
  int v67; // [esp+F8h] [ebp-4h]

  v59 = 0;
  v60 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"ESC_MENU_TIME_TABLE", 0x13u);
  v4 = aSim->game;
  v67 = 0;
  ksgui::Control::Control(this, &iname, v4->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (EscMenuTimeTable_vtbl *)&EscMenuTimeTable::`vftable';
  this->sim = aSim;
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  this->dataFont._Ptr = 0;
  this->dataFont._Rep = 0;
  this->blackFont._Ptr = 0;
  this->blackFont._Rep = 0;
  this->bigFont._Ptr = 0;
  this->bigFont._Rep = 0;
  this->btDriverNextPage = 0;
  this->btDriverPreviousPage = 0;
  this->btLapNextPage = 0;
  this->btLapPreviousPage = 0;
  this->btPrint = 0;
  this->lastDriverIndex = -1;
  this->currentDriverPage = 0;
  this->currentLapPage = 0;
  this->btSessions._Myfirst = 0;
  this->btSessions._Mylast = 0;
  this->btSessions._Myend = 0;
  this->sessionID = 0;
  this->updateDriver = 0;
  this->maxRows = 0;
  this->driverButtonsTop = 0.0;
  this->lapsButtonsTop = 0.0;
  this->tableWidth = 0.0;
  this->txCarSkins._Myfirst = 0;
  this->txCarSkins._Mylast = 0;
  this->txCarSkins._Myend = 0;
  this->updateSelectedBest = 0;
  this->selectedLaps._Myfirst = 0;
  this->selectedLaps._Mylast = 0;
  this->selectedLaps._Myend = 0;
  *(_DWORD *)&v56[24] = std::wstring::~wstring;
  *(_DWORD *)&v56[20] = std::wstring::wstring;
  *(_DWORD *)&v56[16] = 3;
  *(_DWORD *)&v56[12] = 24;
  LOBYTE(v67) = 9;
  *(_DWORD *)&v56[8] = this->bestSplitsDrivers;
  this->selectedLapCount = 0;
  this->selectedBestlap = 0;
  this->bestlap = 0;
  this->playerBestlap = 0;
  `eh vector constructor iterator'(
    *(void **)&v56[8],
    *(unsigned int *)&v56[12],
    *(int *)&v56[16],
    *(void (**)(void *))&v56[20],
    *(void (**)(void *))&v56[24]);
  this->bestLapDriver._Myres = 7;
  this->bestLapDriver._Mysize = 0;
  this->bestLapDriver._Bx._Buf[0] = 0;
  LOBYTE(v67) = 11;
  this->skinTextures._Myhead = 0;
  this->skinTextures._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<CarAvatar * const,Texture>>>::_Buyheadnode(&this->skinTextures);
  this->skinTextures._Myhead = v5;
  *(_DWORD *)&v56[24] = 24;
  LOBYTE(v67) = 12;
  this->nameX = 0.0;
  this->carX = 0.0;
  this->lapsX = 0.0;
  this->bestlapX = 0.0;
  this->lapcountX = 0.0;
  this->compoundX = 0.0;
  this->laptimeX = 0.0;
  this->deltaX = 0.0;
  v6 = (CarAvatar *)operator new(*(_DWORD *)&v56[24]);
  _Keyval = v6;
  LOBYTE(v67) = 13;
  if ( v6 )
    Font::Font((Font *)v6, eFontMonospaced, 14.0, 1, 1);
  else
    v7 = 0;
  LOBYTE(v67) = 12;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v7);
  std::shared_ptr<Font>::operator=(&this->titleFont, &_Right);
  v8 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Weaks, 0xFFFFFFFF) )
        v8->_Delete_this(v8);
    }
  }
  v9 = (CarAvatar *)operator new(24);
  _Keyval = v9;
  LOBYTE(v67) = 14;
  if ( v9 )
    Font::Font((Font *)v9, eFontMonospaced, 14.0, 0, 1);
  else
    v10 = 0;
  LOBYTE(v67) = 12;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v10);
  std::shared_ptr<Font>::operator=(&this->dataFont, &_Right);
  v11 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v11->_Destroy(v11);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v11->_Weaks, 0xFFFFFFFF) )
        v11->_Delete_this(v11);
    }
  }
  v12 = (CarAvatar *)operator new(24);
  _Keyval = v12;
  LOBYTE(v67) = 15;
  if ( v12 )
    Font::Font((Font *)v12, eFontMonospaced, 14.0, 0, 1);
  else
    v13 = 0;
  LOBYTE(v67) = 12;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v13);
  std::shared_ptr<Font>::operator=(&this->blackFont, &_Right);
  v14 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v14->_Destroy(v14);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v14->_Weaks, 0xFFFFFFFF) )
        v14->_Delete_this(v14);
    }
  }
  v15 = (CarAvatar *)operator new(24);
  _Keyval = v15;
  LOBYTE(v67) = 16;
  if ( v15 )
    Font::Font((Font *)v15, eFontMonospaced, 25.0, 1, 1);
  else
    v16 = 0;
  LOBYTE(v67) = 12;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v16);
  std::shared_ptr<Font>::operator=(&this->bigFont, &_Right);
  v17 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v17->_Destroy(v17);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v17->_Weaks, 0xFFFFFFFF) )
        v17->_Delete_this(v17);
    }
  }
  Font::setColor(this->blackFont._Ptr, 0.0, 0.0, 0.0, 1.0);
  v18 = (CarAvatar *)operator new(448);
  _Keyval = v18;
  LOBYTE(v67) = 17;
  if ( v18 )
  {
    *(_DWORD *)&v56[24] = this->sim->game->gui;
    *(_DWORD *)&v56[20] = 7;
    *(_DWORD *)&v56[16] = 0;
    *(_WORD *)v56 = 0;
    std::wstring::assign((std::wstring *)v56, L"BUT_LAP_NEXT_PAGE", 0x11u);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v18, *(std::wstring *)v56, *(ksgui::GUI **)&v56[24]);
  }
  else
  {
    v19 = 0;
  }
  this->btLapNextPage = v19;
  LOBYTE(v67) = 12;
  *(_DWORD *)&v56[24] = 7;
  *(_DWORD *)&v56[20] = 0;
  *(_WORD *)&v56[4] = 0;
  std::wstring::assign((std::wstring *)&v56[4], L"content/gui/raceControl/right_icon", 0x22u);
  ksgui::ActiveButton::setMultipleTexture(this->btLapNextPage, a2, *(std::wstring *)&v56[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, word_17BE9D8, 0);
  v20 = this->btLapNextPage;
  LOBYTE(v67) = 18;
  v20->setText(v20, &iname);
  LOBYTE(v67) = 12;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btLapNextPage->setSize)(
    this->btLapNextPage,
    1109393408,
    1109393408);
  *(_DWORD *)&v56[24] = this;
  *(_DWORD *)v56 = &std::_Func_impl<std::_Callable_obj<_lambda_d6a705da459ed759ea4061ffbdd2e6b1_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v56[4] = this;
  *(_DWORD *)&v56[16] = v56;
  v21 = (Event<OnMouseWheelMovedEvent> *)&this->btLapNextPage->evClicked;
  LOBYTE(v67) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v21,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v56,
    this);
  ksgui::Control::setVisible(this->btLapNextPage, 0);
  ksgui::Control::addControl(this, this->btLapNextPage);
  v22 = (Font *)operator new(448);
  _Right._Ptr = v22;
  LOBYTE(v67) = 20;
  if ( v22 )
  {
    *(_DWORD *)&v56[24] = this->sim->game->gui;
    *(_DWORD *)&v56[20] = 7;
    *(_DWORD *)&v56[16] = 0;
    *(_WORD *)v56 = 0;
    std::wstring::assign((std::wstring *)v56, L"BUT_LAP_PREV_PAGE", 0x11u);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v22, *(std::wstring *)v56, *(ksgui::GUI **)&v56[24]);
  }
  else
  {
    v23 = 0;
  }
  this->btLapPreviousPage = v23;
  LOBYTE(v67) = 12;
  *(_DWORD *)&v56[24] = 7;
  *(_DWORD *)&v56[20] = 0;
  *(_WORD *)&v56[4] = 0;
  std::wstring::assign((std::wstring *)&v56[4], L"content/gui/raceControl/left_icon", 0x21u);
  ksgui::ActiveButton::setMultipleTexture(this->btLapPreviousPage, a2, *(std::wstring *)&v56[4]);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, word_17BE9D8, 0);
  v24 = this->btLapPreviousPage;
  LOBYTE(v67) = 21;
  v24->setText(v24, &iname);
  LOBYTE(v67) = 12;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btLapPreviousPage->setSize)(
    this->btLapPreviousPage,
    1109393408,
    1109393408);
  *(_DWORD *)&v56[24] = this;
  *(_DWORD *)v56 = &std::_Func_impl<std::_Callable_obj<_lambda_84d4eadc980523b609fb3812aa477557_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v56[4] = this;
  *(_DWORD *)&v56[16] = v56;
  v25 = (Event<OnMouseWheelMovedEvent> *)&this->btLapPreviousPage->evClicked;
  LOBYTE(v67) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v25,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v56,
    this);
  ksgui::Control::setVisible(this->btLapPreviousPage, 0);
  ksgui::Control::addControl(this, this->btLapPreviousPage);
  for ( i = 0; i < this->sim->cars._Mylast - this->sim->cars._Myfirst; ++i )
  {
    v27 = Sim::getCar(this->sim, i);
    v28 = this->sim;
    _Keyval = v27;
    *(_DWORD *)&v56[24] = &result;
    v29 = Sim::getCar(v28, i);
    v30 = CarAvatar::getCurrentSkin(v29, *(std::wstring **)&v56[24]);
    v31 = this->sim;
    LOBYTE(v67) = 23;
    v32 = Sim::getCar(v31, i);
    v33 = std::operator+<wchar_t>(&v62, L"content/cars/", &v32->unixName);
    LOBYTE(v67) = 24;
    v34 = std::operator+<wchar_t>(&v64, v33, L"/skins/");
    LOBYTE(v67) = 25;
    v35 = std::operator+<wchar_t>(&v63, v34, v30);
    LOBYTE(v67) = 26;
    v36 = std::operator+<wchar_t>(&iname, v35, L"/livery.png");
    v37 = this->sim;
    LOBYTE(v67) = 27;
    v38 = ResourceStore::getTexture(v37->game->graphics->resourceStore._Myptr, &v66, v36, 0);
    LOBYTE(v67) = 28;
    v39 = std::map<CarAvatar *,Texture>::operator[](&this->skinTextures, &_Keyval);
    v40 = (CarAvatar *)v38->kid;
    v41 = &v38->fileName;
    *v39 = v40;
    v42 = (std::wstring *)(v39 + 1);
    if ( v42 != v41 )
      std::wstring::assign(v42, v41, 0, 0xFFFFFFFF);
    LOBYTE(v67) = 27;
    OnSetupAppCreated::~OnSetupAppCreated(&v66);
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    if ( v63._Myres >= 8 )
      operator delete(v63._Bx._Ptr);
    v63._Myres = 7;
    v63._Mysize = 0;
    v63._Bx._Buf[0] = 0;
    if ( v64._Myres >= 8 )
      operator delete(v64._Bx._Ptr);
    v64._Myres = 7;
    v64._Mysize = 0;
    v64._Bx._Buf[0] = 0;
    if ( v62._Myres >= 8 )
      operator delete(v62._Bx._Ptr);
    v62._Myres = 7;
    v62._Mysize = 0;
    v62._Bx._Buf[0] = 0;
    LOBYTE(v67) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  *(_DWORD *)&v56[24] = 280;
  this->tableWidth = 486.0;
  this->maxRows = 16;
  v43 = (Font *)operator new(*(_DWORD *)&v56[24]);
  _Right._Ptr = v43;
  v44 = 0;
  LOBYTE(v67) = 29;
  if ( v43 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"BUT_PRINT", 9u);
    v59 = 1;
    v45 = this->sim;
    LOBYTE(v67) = 30;
    ksgui::Control::Control((ksgui::Control *)v43, &iname, v45->game->gui);
  }
  v46 = (v59 & 1) == 0;
  this->btPrint = v44;
  v67 = 12;
  if ( !v46 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"PRINT", 5u);
  LOBYTE(v67) = 32;
  *(_DWORD *)&v56[24] = acTranslate(&v62, &iname);
  v47 = this->btPrint;
  LOBYTE(v67) = 33;
  v47->setText(v47, *(const std::wstring **)&v56[24]);
  if ( v62._Myres >= 8 )
    operator delete(v62._Bx._Ptr);
  v62._Myres = 7;
  v62._Mysize = 0;
  v62._Bx._Buf[0] = 0;
  LOBYTE(v67) = 12;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v48 = this->titleFont._Rep;
  v49 = (CarAvatar *)this->titleFont._Ptr;
  v50 = this->btPrint;
  _Keyval = v49;
  if ( v48 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)&v48->_Uses, 1u);
    v49 = _Keyval;
  }
  v51 = (volatile signed __int32 *)v50->font._Rep;
  v50->font._Rep = v48;
  v50->font._Ptr = (Font *)v49;
  if ( v51 )
  {
    if ( !_InterlockedExchangeAdd(v51 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v51)(v51);
      if ( !_InterlockedDecrement(v51 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v51 + 4))(v51);
    }
  }
  this->btPrint->fontAlign = eAlignCenter;
  ((void (*)(ksgui::Control *, int, int))this->btPrint->setSize)(this->btPrint, 1117782016, 1099956224);
  this->btPrint->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&colTitleBar_3);
  ksgui::Control::addControl(this, this->btPrint);
  *(_DWORD *)&v56[24] = this;
  *(_DWORD *)v56 = &std::_Func_impl<std::_Callable_obj<_lambda_bbad77a336e0ab7291c2722a8541661d_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v56[4] = this;
  *(_DWORD *)&v56[16] = v56;
  v52 = (Event<OnMouseWheelMovedEvent> *)&this->btPrint->evClicked;
  LOBYTE(v67) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v52,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v56,
    this);
  for ( j = (EscMenuTimeTable *)this->selectedBestSplits;
        j != (EscMenuTimeTable *)&this->selectedBestlap;
        j = (EscMenuTimeTable *)((char *)j + 4) )
  {
    j->__vftable = 0;
  }
  for ( k = (EscMenuTimeTable *)this->playerSplits;
        k != (EscMenuTimeTable *)&this->playerBestlap;
        k = (EscMenuTimeTable *)((char *)k + 4) )
  {
    k->__vftable = 0;
  }
  for ( l = (EscMenuTimeTable *)this->bestSplits;
        l != (EscMenuTimeTable *)&this->bestlap;
        l = (EscMenuTimeTable *)((char *)l + 4) )
  {
    l->__vftable = 0;
  }
  this->splitX[0] = 0.0;
  this->splitX[1] = 0.0;
  this->splitX[2] = 0.0;
  this->lapSplitX[0] = 0.0;
  this->lapSplitX[1] = 0.0;
  this->lapSplitX[2] = 0.0;
}
void EscMenuTimeTable::~EscMenuTimeTable(EscMenuTimeTable *this)
{
  std::_Tree_node<std::pair<CarAvatar * const,Texture>,void *> *v2; // eax
  bool v3; // zf
  std::vector<Lap> *v4; // esi
  std::vector<ksgui::ActiveButton *> *v5; // esi
  std::_Ref_count_base *v6; // ebx
  std::_Ref_count_base *v7; // ebx
  std::_Ref_count_base *v8; // ebx
  std::_Ref_count_base *v9; // ebx
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Texture> > > > result; // [esp+18h] [ebp-10h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  this->__vftable = (EscMenuTimeTable_vtbl *)&EscMenuTimeTable::`vftable';
  v2 = this->skinTextures._Myhead;
  v11 = 7;
  std::_Tree<std::_Tmap_traits<CarAvatar *,Texture,std::less<CarAvatar *>,std::allocator<std::pair<CarAvatar * const,Texture>>,0>>::erase(
    &this->skinTextures,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Texture> > > >)v2->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Texture> > > >)v2);
  operator delete(this->skinTextures._Myhead);
  if ( this->bestLapDriver._Myres >= 8 )
    operator delete(this->bestLapDriver._Bx._Ptr);
  this->bestLapDriver._Myres = 7;
  this->bestLapDriver._Mysize = 0;
  this->bestLapDriver._Bx._Buf[0] = 0;
  `eh vector destructor iterator'(
    this->bestSplitsDrivers,
    0x18u,
    3,
    (void (*)(void *))std::wstring::~wstring);
  v3 = this->selectedLaps._Myfirst == 0;
  v4 = &this->selectedLaps;
  LOBYTE(v11) = 6;
  if ( !v3 )
  {
    std::_Container_base0::_Orphan_all(&this->selectedLaps);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(v4->_Myfirst, this->selectedLaps._Mylast);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->selectedLaps._Mylast = 0;
    this->selectedLaps._Myend = 0;
  }
  LOBYTE(v11) = 5;
  std::vector<Texture>::_Tidy(&this->txCarSkins);
  v3 = this->btSessions._Myfirst == 0;
  v5 = &this->btSessions;
  LOBYTE(v11) = 4;
  if ( !v3 )
  {
    std::_Container_base0::_Orphan_all(&this->btSessions);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->btSessions._Mylast = 0;
    this->btSessions._Myend = 0;
  }
  v6 = this->bigFont._Rep;
  LOBYTE(v11) = 3;
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Weaks, 0xFFFFFFFF) )
        v6->_Delete_this(v6);
    }
  }
  v7 = this->blackFont._Rep;
  LOBYTE(v11) = 2;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Uses, 0xFFFFFFFF) )
    {
      v7->_Destroy(v7);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Weaks, 0xFFFFFFFF) )
        v7->_Delete_this(v7);
    }
  }
  v8 = this->dataFont._Rep;
  LOBYTE(v11) = 1;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Weaks, 0xFFFFFFFF) )
        v8->_Delete_this(v8);
    }
  }
  v9 = this->titleFont._Rep;
  LOBYTE(v11) = 0;
  if ( v9 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v9->_Uses, 0xFFFFFFFF) )
    {
      v9->_Destroy(v9);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v9->_Weaks) )
        v9->_Delete_this(v9);
    }
  }
  v11 = -1;
  ksgui::Control::~Control(this);
}
EscMenuTimeTable *EscMenuTimeTable::`vector deleting destructor'(EscMenuTimeTable *this, unsigned int a2)
{
  EscMenuTimeTable::~EscMenuTimeTable(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void EscMenuTimeTable::onVisibleChanged(EscMenuTimeTable *this, BOOL newValue)
{
  ksgui::Control **v3; // edi
  ksgui::Control **i; // esi

  if ( newValue )
  {
    EscMenuTimeTable::refreshSession(this);
    EscMenuTimeTable::refreshPlayer(this);
  }
  v3 = this->controls._Mylast;
  for ( i = this->controls._Myfirst; i != v3; ++i )
    (*i)->onVisibleChanged(*i, newValue);
}
void EscMenuTimeTable::refreshPlayer(EscMenuTimeTable *this)
{
  Sim *v2; // ecx
  int v3; // eax
  Sim *v4; // ecx
  CarAvatar *v5; // eax
  std::vector<Lap> *v6; // eax
  Lap *v7; // ebx
  int v8; // edi
  std::vector<unsigned int> *v9; // eax
  unsigned int v10; // ecx
  unsigned int *v11; // edx
  unsigned int v12; // ecx
  unsigned int *v13; // edx
  unsigned int v14; // ecx
  unsigned int *v15; // edx
  unsigned int v16; // ecx
  std::vector<Lap> playerLaps; // [esp+14h] [ebp-CCh] BYREF
  std::vector<Lap> v18; // [esp+20h] [ebp-C0h] BYREF
  OnSessionEndEvent result; // [esp+30h] [ebp-B0h] BYREF
  int v20; // [esp+DCh] [ebp-4h]

  playerLaps._Myfirst = 0;
  playerLaps._Mylast = 0;
  playerLaps._Myend = 0;
  v2 = this->sim;
  v20 = 0;
  v3 = RaceManager::getCurrentSessionIndex(v2->raceManager);
  v4 = this->sim;
  if ( this->sessionID == v3 )
  {
    v5 = Sim::getCar(v4, 0);
    v6 = RaceManager::getLaps(this->sim->raceManager, &v18, v5, 0);
    LOBYTE(v20) = 1;
    std::vector<Lap>::operator=(&playerLaps, v6);
    LOBYTE(v20) = 0;
    if ( v18._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&v18);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(v18._Myfirst, v18._Mylast);
      operator delete(v18._Myfirst);
    }
  }
  else
  {
    RaceManager::getSessionHistory(v4->raceManager, &result, &this->sessionID);
    LOBYTE(v20) = 2;
    if ( result.result.laps._Mylast - result.result.laps._Myfirst )
      std::vector<Lap>::operator=(&playerLaps, result.result.laps._Myfirst);
    OnSessionEndEvent::~OnSessionEndEvent(&result);
  }
  v7 = playerLaps._Myfirst;
  v8 = playerLaps._Mylast - playerLaps._Myfirst;
  if ( v8 )
  {
    v9 = &playerLaps._Myfirst->splits;
    do
    {
      v10 = this->playerBestlap;
      if ( (!v10 || (unsigned int *)v10 > v9[-1]._Myend) && LOBYTE(v9[1]._Mylast) )
        this->playerBestlap = (unsigned int)v9[-1]._Myend;
      v11 = v9->_Myfirst;
      if ( v9->_Mylast - v9->_Myfirst )
      {
        v12 = this->playerSplits[0];
        if ( !v12 || v12 > *v11 )
        {
          if ( LOBYTE(v9[1]._Mylast) )
            this->playerSplits[0] = *v11;
        }
      }
      v13 = v9->_Myfirst;
      if ( (unsigned int)(v9->_Mylast - v9->_Myfirst) > 1 )
      {
        v14 = this->playerSplits[1];
        if ( !v14 || v14 > v13[1] )
        {
          if ( LOBYTE(v9[1]._Mylast) )
            this->playerSplits[1] = v13[1];
        }
      }
      v15 = v9->_Myfirst;
      if ( (unsigned int)(v9->_Mylast - v9->_Myfirst) > 2 )
      {
        v16 = this->playerSplits[2];
        if ( !v16 || v16 > v15[2] )
        {
          if ( LOBYTE(v9[1]._Mylast) )
            this->playerSplits[2] = v15[2];
        }
      }
      v9 += 4;
      --v8;
    }
    while ( v8 );
  }
  v20 = -1;
  if ( v7 )
  {
    std::_Container_base0::_Orphan_all(&playerLaps);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(playerLaps._Myfirst, playerLaps._Mylast);
    operator delete(playerLaps._Myfirst);
  }
}
void EscMenuTimeTable::refreshSession(EscMenuTimeTable *this)
{
  EscMenuTimeTable *v1; // ebp
  int *v2; // esi
  unsigned int *v3; // eax
  unsigned int *i; // edi
  unsigned int *v5; // eax
  unsigned int *v6; // ecx
  unsigned int *v7; // eax
  unsigned int *j; // edx
  Sim *v9; // ecx
  unsigned int v10; // ebx
  Sim *v11; // ecx
  DriverInfo *v12; // eax
  Lap *v13; // edi
  Lap *v14; // esi
  unsigned int *v15; // ecx
  unsigned int v16; // edi
  unsigned int *v17; // ebx
  std::wstring *v18; // ebp
  int v19; // eax
  DriverInfo *v20; // eax
  unsigned int index; // [esp+14h] [ebp-C4h]
  Lap *v23; // [esp+20h] [ebp-B8h]
  OnSessionEndEvent result; // [esp+28h] [ebp-B0h] BYREF
  int v25; // [esp+D4h] [ebp-4h]

  v1 = this;
  v2 = &this->sessionID;
  RaceManager::getSessionHistory(this->sim->raceManager, &result, &this->sessionID);
  v3 = v1->bestSplits;
  v25 = 0;
  for ( i = &v1->bestlap; v3 != i; ++v3 )
    *v3 = 0;
  v5 = v1->selectedBestSplits;
  *i = 0;
  v6 = &v1->selectedBestlap;
  v1->updateDriver = 1;
  v1->selectedLapCount = 0;
  for ( v1->updateSelectedBest = 1; v5 != v6; ++v5 )
    *v5 = 0;
  v7 = v1->playerSplits;
  for ( j = &v1->playerBestlap; v7 != j; ++v7 )
    *v7 = 0;
  *v6 = 0;
  v9 = v1->sim;
  *j = 0;
  v1->currentLapPage = 0;
  if ( *v2 != RaceManager::getCurrentSessionIndex(v9->raceManager) )
  {
    v10 = 0;
    index = 0;
    if ( result.result.laps._Mylast - result.result.laps._Myfirst )
    {
      while ( 1 )
      {
        if ( (!*i || *i > result.result.bestLaps._Myfirst[v10].time) && result.result.bestLaps._Myfirst[v10].isValid )
        {
          v11 = v1->sim;
          *i = result.result.bestLaps._Myfirst[v10].time;
          v12 = &Sim::getCar(v11, v10)->driverInfo;
          if ( &v1->bestLapDriver != (std::wstring *)v12 )
            std::wstring::assign(&v1->bestLapDriver, &v12->name, 0, 0xFFFFFFFF);
          if ( !v10 )
            v1->playerBestlap = *i;
        }
        v13 = result.result.laps._Myfirst[v10]._Mylast;
        v14 = result.result.laps._Myfirst[v10]._Myfirst;
        v23 = v13;
        if ( v14 != v13 )
          break;
LABEL_31:
        i = &v1->bestlap;
        index = ++v10;
        if ( v10 >= result.result.laps._Mylast - result.result.laps._Myfirst )
          goto LABEL_32;
      }
      while ( 1 )
      {
        if ( v14->isValid )
        {
          v15 = v14->splits._Myfirst;
          if ( v14->splits._Mylast - v15 )
            break;
        }
LABEL_29:
        if ( ++v14 == v13 )
        {
          v10 = index;
          goto LABEL_31;
        }
      }
      v16 = 0;
      v17 = v1->bestSplits;
      v18 = v1->bestSplitsDrivers;
      v19 = -432 - (_DWORD)this;
      while ( 1 )
      {
        if ( !*v17 )
          goto LABEL_23;
        if ( *v17 > *(unsigned int *)((char *)v15 + (_DWORD)v17 + v19) )
          break;
LABEL_27:
        ++v16;
        v15 = v14->splits._Myfirst;
        ++v17;
        ++v18;
        v19 = -432 - (_DWORD)this;
        if ( v16 >= v14->splits._Mylast - v15 )
        {
          v13 = v23;
          v1 = this;
          goto LABEL_29;
        }
      }
      v19 = -432 - (_DWORD)this;
LABEL_23:
      *v17 = *(unsigned int *)((char *)v15 + (_DWORD)v17 + v19);
      v20 = &Sim::getCar(this->sim, index)->driverInfo;
      if ( v18 != (std::wstring *)v20 )
        std::wstring::assign(v18, &v20->name, 0, 0xFFFFFFFF);
      if ( !index )
        v17[4] = *v17;
      goto LABEL_27;
    }
  }
LABEL_32:
  SessionResult::~SessionResult(&result.result);
  if ( result.currentSession.name._Myres >= 8 )
    operator delete(result.currentSession.name._Bx._Ptr);
  result.currentSession.name._Myres = 7;
  result.currentSession.name._Mysize = 0;
  result.currentSession.name._Bx._Buf[0] = 0;
  if ( result.currentSession.spawSet._Myres >= 8 )
    operator delete(result.currentSession.spawSet._Bx._Ptr);
}
void EscMenuTimeTable::render(EscMenuTimeTable *this, float dt)
{
  EscMenuTimeTable *v2; // ebx
  unsigned int v3; // ebp
  EscMenuTimeTable_vtbl *v4; // eax
  float v5; // xmm1_4
  Sim *v6; // ecx
  int *v7; // esi
  Game *v8; // eax
  RaceManager *v9; // ecx
  Sim *v10; // ecx
  Sim *v11; // ecx
  unsigned int *v12; // ecx
  unsigned int *j; // eax
  int v14; // eax
  Sim *v15; // ecx
  unsigned int v16; // eax
  CarAvatar *v17; // eax
  std::vector<Lap> *v18; // eax
  OnSessionEndEvent *v19; // esi
  unsigned int v20; // esi
  unsigned int v21; // eax
  std::vector<Lap> *v22; // edi
  unsigned int v23; // esi
  unsigned int v24; // ebp
  int v25; // esi
  unsigned int v26; // edx
  int v27; // ecx
  unsigned int v28; // edx
  Lap *v29; // ecx
  unsigned int v30; // edx
  Lap *v31; // ecx
  unsigned int v32; // edx
  int v33; // ecx
  unsigned int v34; // eax
  int v35; // edx
  Sim *v36; // esi
  unsigned int v37; // eax
  unsigned int v38; // eax
  CarAvatar *v39; // eax
  Session *v40; // eax
  std::wstring *v41; // esi
  std::wstring *v42; // ecx
  std::wstring *v43; // esi
  std::wstring *v44; // eax
  std::wstring *v45; // ecx
  unsigned int v46; // edi
  int v47; // ebx
  int k; // ebp
  const std::wstring *v49; // eax
  Font *v50; // ecx
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // xmm0_4
  GLRenderer *v57; // esi
  const std::wstring *v58; // eax
  float v59; // xmm0_4
  Font *v60; // ecx
  const std::wstring *v61; // eax
  float v62; // xmm0_4
  Font *v63; // ecx
  const std::wstring *v64; // eax
  float v65; // xmm0_4
  Font *v66; // ecx
  const std::wstring *v67; // eax
  float v68; // xmm0_4
  Font *v69; // ecx
  const std::wstring *v70; // eax
  float v71; // xmm0_4
  Font *v72; // ecx
  const std::wstring *v73; // eax
  float v74; // xmm0_4
  Font *v75; // ecx
  int v76; // eax
  float v77; // xmm1_4
  const std::wstring *v78; // eax
  Font *v79; // ecx
  const std::wstring *v80; // eax
  Font *v81; // ecx
  const std::wstring *v82; // eax
  Font *v83; // ecx
  const std::wstring *v84; // eax
  Font *v85; // ecx
  Font *v86; // ecx
  CarAvatar *v87; // eax
  CarAvatar **v88; // eax
  const std::wstring *v89; // eax
  const std::wstring *v90; // eax
  Font *v91; // ecx
  const std::wstring *v92; // eax
  Font *v93; // ecx
  const std::wstring *v94; // eax
  Font *v95; // ecx
  unsigned int v96; // eax
  CarAvatar **v97; // eax
  const std::wstring *v98; // eax
  const std::wstring *v99; // eax
  Font *v100; // ecx
  const std::wstring *v101; // eax
  Font *v102; // ecx
  const std::wstring *v103; // eax
  Font *v104; // ecx
  Font *v105; // ecx
  float v106; // xmm0_4
  float v107; // xmm1_4
  float v108; // xmm0_4
  float v109; // xmm0_4
  float v110; // xmm0_4
  float v111; // xmm0_4
  float v112; // xmm0_4
  float v113; // xmm0_4
  const std::wstring *v114; // eax
  Font *v115; // ecx
  const std::wstring *v116; // eax
  Font *v117; // ecx
  const std::wstring *v118; // eax
  Font *v119; // ecx
  const std::wstring *v120; // eax
  const std::wstring *v121; // eax
  Font *v122; // ecx
  const std::wstring *v123; // eax
  Font *v124; // ecx
  const std::wstring *v125; // eax
  Font *v126; // ecx
  int v127; // eax
  std::vector<Lap> *v128; // edi
  int v129; // ecx
  int v130; // edx
  int v131; // ecx
  vec4f v132; // xmm0
  const std::wstring *v133; // eax
  Font *v134; // ecx
  Lap *v135; // ecx
  const std::wstring *v136; // eax
  Font *v137; // ecx
  unsigned int v138; // edx
  const std::wstring *v139; // eax
  Font *v140; // ecx
  unsigned int v141; // edx
  const std::wstring *v142; // eax
  Font *v143; // ecx
  const std::wstring *v144; // eax
  Font *v145; // ecx
  float *v146; // esi
  CarAvatar **v147; // eax
  char *v148; // ecx
  CarAvatar **v149; // ecx
  unsigned int v150; // ecx
  float v151; // xmm1_4
  float v152; // xmm0_4
  const std::wstring *v153; // eax
  float v154; // xmm0_4
  const std::wstring *v155; // eax
  int v156; // ebp
  Font *v157; // ecx
  unsigned int v158; // eax
  std::allocator<wchar_t> *v159; // eax
  int v160; // esi
  unsigned int v161; // esi
  Font *v162; // eax
  AudioEvent *v163; // esi
  AudioEvent *v164; // eax
  Font *v165; // eax
  int v166; // ecx
  int v167; // edx
  unsigned int v168; // eax
  unsigned int v169; // eax
  ksgui::Form *v170; // esi
  double v171; // st7
  float v172; // xmm0_4
  float r; // [esp+8h] [ebp-364h]
  float ra; // [esp+8h] [ebp-364h]
  const std::wstring *r_8; // [esp+10h] [ebp-35Ch]
  int r_12; // [esp+14h] [ebp-358h]
  int r_12a; // [esp+14h] [ebp-358h]
  int r_12b; // [esp+14h] [ebp-358h]
  int r_12c; // [esp+14h] [ebp-358h]
  int r_12d; // [esp+14h] [ebp-358h]
  int r_12e; // [esp+14h] [ebp-358h]
  int r_12f; // [esp+14h] [ebp-358h]
  int r_12g; // [esp+14h] [ebp-358h]
  int r_12h; // [esp+14h] [ebp-358h]
  wchar_t *r_12i; // [esp+14h] [ebp-358h]
  unsigned int a; // [esp+18h] [ebp-354h]
  float aa; // [esp+18h] [ebp-354h]
  __int64 v188; // [esp+1Ch] [ebp-350h]
  float v189; // [esp+24h] [ebp-348h]
  float y; // [esp+30h] [ebp-33Ch]
  float ya; // [esp+30h] [ebp-33Ch]
  float v192; // [esp+34h] [ebp-338h]
  int v193; // [esp+34h] [ebp-338h]
  int i; // [esp+38h] [ebp-334h] BYREF
  bool isGlobal[4]; // [esp+3Ch] [ebp-330h] BYREF
  ksgui::ksRect wrect; // [esp+40h] [ebp-32Ch] BYREF
  unsigned int v197; // [esp+50h] [ebp-31Ch]
  CarAvatar *_Keyval; // [esp+54h] [ebp-318h] BYREF
  GLRenderer *v199; // [esp+58h] [ebp-314h]
  CarAvatar *v200; // [esp+5Ch] [ebp-310h] BYREF
  unsigned int v201; // [esp+60h] [ebp-30Ch]
  int v202; // [esp+64h] [ebp-308h]
  Lap *_First; // [esp+68h] [ebp-304h]
  std::wstring _First_4; // [esp+6Ch] [ebp-300h] BYREF
  std::wstring v205; // [esp+84h] [ebp-2E8h] BYREF
  std::wstring v206; // [esp+9Ch] [ebp-2D0h] BYREF
  std::wstring s; // [esp+B4h] [ebp-2B8h] BYREF
  std::wstring sessionInfoName; // [esp+CCh] [ebp-2A0h] BYREF
  std::wstring v209; // [esp+E4h] [ebp-288h] BYREF
  std::wstring v210; // [esp+FCh] [ebp-270h] BYREF
  std::wstring v211; // [esp+114h] [ebp-258h] BYREF
  std::wstring v212; // [esp+12Ch] [ebp-240h] BYREF
  std::wstring v213; // [esp+144h] [ebp-228h] BYREF
  std::wstring v214; // [esp+15Ch] [ebp-210h] BYREF
  std::wstring v215; // [esp+174h] [ebp-1F8h] BYREF
  std::wstring v216; // [esp+18Ch] [ebp-1E0h] BYREF
  std::wstring v217; // [esp+1A4h] [ebp-1C8h] BYREF
  OnSessionEndEvent v218; // [esp+1BCh] [ebp-1B0h] BYREF
  OnSessionEndEvent result; // [esp+25Ch] [ebp-110h] BYREF
  DriverInfo driver; // [esp+2FCh] [ebp-70h] BYREF
  int v221; // [esp+368h] [ebp-4h]

  v2 = this;
  v200 = (CarAvatar *)this;
  v3 = 0;
  v197 = 0;
  v4 = this->__vftable;
  wrect.left = 0.0;
  wrect.top = 0.0;
  wrect.right = 1.0;
  wrect.bottom = 1.0;
  v4->getWorldRect(this, &wrect);
  v5 = v2->rect.top;
  wrect.left = (float)(v2->rect.left + 20.0) + wrect.left;
  wrect.top = (float)(v5 + 8.0) + wrect.top;
  if ( v2->nameX == 0.0 )
    v2->maxRows = (int)(float)((float)((float)(v2->rect.bottom - v5) - 287.5) * 0.032786883);
  v6 = v2->sim;
  v7 = &v2->sessionID;
  v8 = v6->game;
  v9 = v6->raceManager;
  v199 = v8->graphics->gl;
  if ( v2->sessionID > RaceManager::getCurrentSessionIndex(v9) )
  {
    *v7 = RaceManager::getCurrentSessionIndex(v2->sim->raceManager);
    EscMenuTimeTable::refreshSession(v2);
  }
  Session::Session(&result.currentSession);
  SessionResult::SessionResult(&result.result);
  v10 = v2->sim;
  v221 = 0;
  if ( v2->lastDriverIndex != Sim::getFocusedCarIndex(v10) )
  {
    v11 = v2->sim;
    v2->updateDriver = 1;
    v2->selectedLapCount = 0;
    v2->updateSelectedBest = 1;
    v2->lastDriverIndex = Sim::getFocusedCarIndex(v11);
    v12 = &v2->selectedBestlap;
    for ( j = v2->selectedBestSplits; j != v12; ++j )
      *j = 0;
    *v12 = 0;
    v2->currentLapPage = 0;
  }
  v14 = RaceManager::getCurrentSessionIndex(v2->sim->raceManager);
  v15 = v2->sim;
  if ( *v7 == v14 )
  {
    v16 = Sim::getFocusedCarIndex(v15);
    v17 = Sim::getCar(v2->sim, v16);
    v18 = RaceManager::getLaps(v2->sim->raceManager, (std::vector<Lap> *)&_First_4, v17, 0);
    LOBYTE(v221) = 1;
    std::vector<Lap>::operator=(&v2->selectedLaps, v18);
    LOBYTE(v221) = 0;
    if ( _First_4._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&_First_4);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(
        (Lap *)_First_4._Bx._Ptr,
        *(Lap **)&_First_4._Bx._Alias[4]);
      operator delete(_First_4._Bx._Ptr);
    }
  }
  else
  {
    v19 = RaceManager::getSessionHistory(v15->raceManager, &v218, &v2->sessionID);
    LOBYTE(v221) = 2;
    Session::operator=(&result.currentSession, &v19->currentSession);
    v19 = (OnSessionEndEvent *)((char *)v19 + 96);
    std::vector<std::vector<Lap>>::operator=(&result.result.laps, (const std::vector<std::vector<Lap>> *)v19);
    std::vector<Lap>::operator=(&result.result.bestLaps, (const std::vector<Lap> *)&v19->currentSession.durationMinutes);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)&result.result.positions,
      (const std::vector<unsigned int> *)&v19->currentSession.spawSet._Bx._Alias[4]);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)&result.result.lapCount,
      (const std::vector<unsigned int> *)&v19->currentSession.spawSet._Mysize);
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)&result.result.total,
      (const std::vector<unsigned int> *)&v19->currentSession.name._Bx._Alias[4]);
    LOBYTE(v221) = 0;
    OnSessionEndEvent::~OnSessionEndEvent(&v218);
    v20 = result.result.laps._Mylast - result.result.laps._Myfirst;
    if ( v20 > Sim::getFocusedCarIndex(v2->sim) )
    {
      v21 = Sim::getFocusedCarIndex(v2->sim);
      std::vector<Lap>::operator=(&v2->selectedLaps, &result.result.laps._Myfirst[v21]);
    }
  }
  v22 = &v2->selectedLaps;
  v23 = v2->selectedLapCount;
  if ( v23 != v2->selectedLaps._Mylast - v2->selectedLaps._Myfirst )
    v2->updateSelectedBest = 1;
  if ( v2->updateDriver || v2->updateSelectedBest )
  {
    if ( v23 < v2->selectedLaps._Mylast - v2->selectedLaps._Myfirst )
    {
      v24 = v23;
      v25 = v23;
      do
      {
        v26 = v2->selectedBestlap;
        if ( !v26 || (v27 = (int)&v22->_Myfirst[v25], v26 > *(_DWORD *)v27) )
        {
          v27 = (int)&v22->_Myfirst[v25];
          if ( *(_BYTE *)(v27 + 20) )
            v2->selectedBestlap = *(_DWORD *)v27;
        }
        if ( (*(_DWORD *)(v27 + 8) - *(_DWORD *)(v27 + 4)) >> 2 )
        {
          v28 = v2->selectedBestSplits[0];
          if ( !v28 || v28 > **(_DWORD **)(v27 + 4) )
          {
            if ( *(_BYTE *)(v27 + 20) )
              v2->selectedBestSplits[0] = **(_DWORD **)(v27 + 4);
          }
        }
        v29 = v22->_Myfirst;
        if ( (unsigned int)(v22->_Myfirst[v25].splits._Mylast - v22->_Myfirst[v25].splits._Myfirst) > 1 )
        {
          v30 = v2->selectedBestSplits[1];
          if ( (!v30 || v30 > v29[v25].splits._Myfirst[1]) && v29[v25].isValid )
            v2->selectedBestSplits[1] = v29[v25].splits._Myfirst[1];
        }
        v31 = v22->_Myfirst;
        if ( (unsigned int)(v22->_Myfirst[v25].splits._Mylast - v22->_Myfirst[v25].splits._Myfirst) > 2 )
        {
          v32 = v2->selectedBestSplits[2];
          if ( (!v32 || v32 > v31[v25].splits._Myfirst[2]) && v31[v25].isValid )
            v2->selectedBestSplits[2] = v31[v25].splits._Myfirst[2];
        }
        ++v24;
        ++v25;
      }
      while ( v24 < v2->selectedLaps._Mylast - v2->selectedLaps._Myfirst );
      v3 = v197;
    }
    v33 = (char *)v2->selectedLaps._Mylast - (char *)v2->selectedLaps._Myfirst;
    v2->updateDriver = 0;
    v2->updateSelectedBest = 0;
    v2->selectedLapCount = v33 / 48;
  }
  if ( v2->sessionID == RaceManager::getCurrentSessionIndex(v2->sim->raceManager) )
  {
    v34 = RaceManager::getBestLap(v2->sim->raceManager);
    v35 = 0;
    v2->bestlap = v34;
    i = 0;
    do
    {
      v36 = v2->sim;
      if ( v36->track->physicsTrack.sectorsNormalizedPositions._Mylast
         - v36->track->physicsTrack.sectorsNormalizedPositions._Myfirst > v35 )
      {
        isGlobal[3] = 1;
        v37 = RaceManager::getBestSplit(v36->raceManager, &i, &isGlobal[3], 0);
        v2->bestSplits[i] = v37;
        v35 = i;
      }
      i = ++v35;
    }
    while ( v35 < 3 );
  }
  v38 = Sim::getFocusedCarIndex(v2->sim);
  v39 = Sim::getCar(v2->sim, v38);
  DriverInfo::DriverInfo(&driver, &v39->driverInfo);
  LOBYTE(v221) = 3;
  GLRenderer::color4f(v199, colTitleBar_3.x, colTitleBar_3.y, colTitleBar_3.z, colTitleBar_3.w);
  GLRenderer::quad(v199, wrect.left, wrect.top, v2->tableWidth, 35.0, 0, 0);
  v40 = RaceManager::getSessionInfo(v2->sim->raceManager, &v218.currentSession, v2->sessionID);
  sessionInfoName._Myres = 7;
  sessionInfoName._Mysize = 0;
  v41 = &v40->name;
  sessionInfoName._Bx._Buf[0] = 0;
  if ( v40->name._Myres >= 8 )
  {
    sessionInfoName._Bx._Ptr = v41->_Bx._Ptr;
    v41->_Bx._Ptr = 0;
  }
  else if ( v40->name._Mysize != -1 )
  {
    _memmove(&sessionInfoName, &v40->name, 2 * (v40->name._Mysize + 1));
  }
  sessionInfoName._Mysize = v41->_Mysize;
  sessionInfoName._Myres = v41->_Myres;
  v41->_Myres = 7;
  v41->_Mysize = 0;
  v41->_Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( v218.currentSession.name._Myres >= 8 )
    operator delete(v218.currentSession.name._Bx._Ptr);
  v218.currentSession.name._Myres = 7;
  v218.currentSession.name._Mysize = 0;
  v218.currentSession.name._Bx._Buf[0] = 0;
  if ( v218.currentSession.spawSet._Myres >= 8 )
    operator delete(v218.currentSession.spawSet._Bx._Ptr);
  v42 = &sessionInfoName;
  v43 = &sessionInfoName;
  v218.currentSession.spawSet._Myres = 7;
  v218.currentSession.spawSet._Bx._Buf[0] = 0;
  if ( sessionInfoName._Myres >= 8 )
    v42 = (std::wstring *)sessionInfoName._Bx._Ptr;
  v218.currentSession.spawSet._Mysize = 0;
  if ( sessionInfoName._Myres >= 8 )
    v43 = (std::wstring *)sessionInfoName._Bx._Ptr;
  v44 = (std::wstring *)((char *)v42 + 2 * sessionInfoName._Mysize);
  v45 = &sessionInfoName;
  if ( sessionInfoName._Myres >= 8 )
    v45 = (std::wstring *)sessionInfoName._Bx._Ptr;
  if ( v45 != v44 )
  {
    v46 = (unsigned int)((char *)v44 - (char *)v45 + 1) >> 1;
    if ( v45 > v44 )
      v46 = 0;
    if ( v46 )
    {
      v47 = (char *)v45 - (char *)v43;
      for ( k = 0; k != v46; ++k )
      {
        v43->_Bx._Buf[0] = _toupper(*(unsigned __int16 *)((char *)v43->_Bx._Buf + v47));
        v43 = (std::wstring *)((char *)v43 + 2);
      }
      v2 = (EscMenuTimeTable *)v200;
      v3 = v197;
    }
  }
  Font::blitString(v2->bigFont._Ptr, wrect.left + 10.0, wrect.top, &driver.name, 1.0, eAlignLeft);
  v49 = acTranslate(&v205, &sessionInfoName);
  v50 = v2->bigFont._Ptr;
  LOBYTE(v221) = 5;
  Font::blitString(v50, (float)(v2->tableWidth + wrect.left) - 10.0, wrect.top, v49, 1.0, eAlignRight);
  LOBYTE(v221) = 4;
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v51 = v2->nameX;
  wrect.top = 55.0;
  if ( v51 == 0.0 )
  {
    v52 = wrect.left + 10.0;
    v2->nameX = wrect.left + 10.0;
    v53 = v52 + 180.0;
    v2->carX = v53;
    v54 = v53 + 80.0;
    v2->splitX[0] = v54;
    v55 = v54 + 60.0;
    v2->splitX[1] = v55;
    v56 = v55 + 60.0;
    v2->splitX[2] = v56;
    v2->bestlapX = v56 + 80.0;
  }
  v57 = v199;
  GLRenderer::color4f(v199, colTitleBar_3.x, colTitleBar_3.y, colTitleBar_3.z, colTitleBar_3.w);
  GLRenderer::quad(v57, wrect.left, wrect.top, v2->tableWidth, 20.0, 0, 0);
  Font::setColor(v2->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, L"DRIVER", 6u);
  LOBYTE(v221) = 6;
  v58 = acTranslate(&v206, &_First_4);
  v59 = v2->nameX;
  v60 = v2->titleFont._Ptr;
  LOBYTE(v221) = 7;
  Font::blitString(v60, v59, 56.0, v58, 1.0, eAlignLeft);
  if ( v206._Myres >= 8 )
    operator delete(v206._Bx._Ptr);
  v206._Myres = 7;
  v206._Mysize = 0;
  v206._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, L"CAR", 3u);
  LOBYTE(v221) = 8;
  v61 = acTranslate(&v206, &_First_4);
  v62 = v2->carX;
  v63 = v2->titleFont._Ptr;
  LOBYTE(v221) = 9;
  Font::blitString(v63, v62, 56.0, v61, 1.0, eAlignLeft);
  if ( v206._Myres >= 8 )
    operator delete(v206._Bx._Ptr);
  v206._Myres = 7;
  v206._Mysize = 0;
  v206._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, (const wchar_t *)&Str._Bx._Alias[4], 2u);
  LOBYTE(v221) = 10;
  v64 = acTranslate(&v206, &_First_4);
  v65 = v2->splitX[0];
  v66 = v2->titleFont._Ptr;
  LOBYTE(v221) = 11;
  Font::blitString(v66, v65, 56.0, v64, 1.0, eAlignRight);
  if ( v206._Myres >= 8 )
    operator delete(v206._Bx._Ptr);
  v206._Myres = 7;
  v206._Mysize = 0;
  v206._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, (const wchar_t *)&Str._Bx._Alias[12], 2u);
  LOBYTE(v221) = 12;
  v67 = acTranslate(&v206, &_First_4);
  v68 = v2->splitX[1];
  v69 = v2->titleFont._Ptr;
  LOBYTE(v221) = 13;
  Font::blitString(v69, v68, 56.0, v67, 1.0, eAlignRight);
  if ( v206._Myres >= 8 )
    operator delete(v206._Bx._Ptr);
  v206._Myres = 7;
  v206._Mysize = 0;
  v206._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, (const wchar_t *)&Str._Myres, 2u);
  LOBYTE(v221) = 14;
  v70 = acTranslate(&v206, &_First_4);
  v71 = v2->splitX[2];
  v72 = v2->titleFont._Ptr;
  LOBYTE(v221) = 15;
  Font::blitString(v72, v71, 56.0, v70, 1.0, eAlignRight);
  if ( v206._Myres >= 8 )
    operator delete(v206._Bx._Ptr);
  v206._Myres = 7;
  v206._Mysize = 0;
  v206._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, L"BESTLAP", 7u);
  LOBYTE(v221) = 16;
  v73 = acTranslate(&v206, &_First_4);
  v74 = v2->bestlapX;
  v75 = v2->titleFont._Ptr;
  LOBYTE(v221) = 17;
  Font::blitString(v75, v74, 56.0, v73, 1.0, eAlignRight);
  if ( v206._Myres >= 8 )
    operator delete(v206._Bx._Ptr);
  v206._Myres = 7;
  v206._Mysize = 0;
  v206._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  LOBYTE(v76) = 0;
  v77 = wrect.top + 20.0;
  i = 0;
  wrect.top = wrect.top + 20.0;
  do
  {
    y = v77 + 5.0;
    if ( (v76 & 1) == 0 )
      GLRenderer::color4f(v57, colDarkBar_3.x, colDarkBar_3.y, colDarkBar_3.z, colDarkBar_3.w);
    GLRenderer::color4f(v57, colDarkTransp_2.x, colDarkTransp_2.y, colDarkTransp_2.z, colDarkTransp_2.w);
    GLRenderer::quad(v57, wrect.left, wrect.top, v2->tableWidth, 30.5, 0, 0);
    if ( i )
    {
      if ( i == 1 )
      {
        GLRenderer::color4f(v57, colDarkBar_3.x, colDarkBar_3.y, colDarkBar_3.z, colDarkBar_3.w);
        GLRenderer::quad(v57, wrect.left, wrect.top, v2->tableWidth, 30.5, 0, 0);
        v86 = v2->dataFont._Ptr;
        _First_4._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
        Font::setColor(v86, (const vec4f *)&_First_4);
        v87 = Sim::getCar(v2->sim, 0);
        Font::blitString(v2->dataFont._Ptr, v2->nameX, y, &v87->driverInfo.name, 1.0, eAlignLeft);
        *(float *)&_Keyval = COERCE_FLOAT(Sim::getCar(v2->sim, 0));
        v88 = std::map<CarAvatar *,Texture>::operator[](&v2->skinTextures, &_Keyval);
        GraphicsManager::setTexture(v2->sim->game->graphics, 0, (const Texture *)v88);
        GLRenderer::color4f(v57, 1.0, 1.0, 1.0, 1.0);
        GLRenderer::quad(v57, v2->carX, wrect.top + 3.0, 21.0, 21.0, 1, 0);
        v89 = timeToSectorString(&v214, v2->playerSplits[0], 3);
        LOBYTE(v221) = 22;
        Font::blitString(v2->dataFont._Ptr, v2->splitX[0], y, v89, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v214._Myres >= 8 )
          operator delete(v214._Bx._Ptr);
        v214._Myres = 7;
        r_12c = v2->playerSplits[1];
        v214._Bx._Buf[0] = 0;
        v214._Mysize = 0;
        v90 = timeToSectorString(&v215, r_12c, 3);
        v91 = v2->dataFont._Ptr;
        LOBYTE(v221) = 23;
        Font::blitString(v91, v2->splitX[1], y, v90, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v215._Myres >= 8 )
          operator delete(v215._Bx._Ptr);
        v215._Myres = 7;
        r_12d = v2->playerSplits[2];
        v215._Bx._Buf[0] = 0;
        v215._Mysize = 0;
        v92 = timeToSectorString(&v212, r_12d, 3);
        v93 = v2->dataFont._Ptr;
        LOBYTE(v221) = 24;
        Font::blitString(v93, v2->splitX[2], y, v92, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v212._Myres >= 8 )
          operator delete(v212._Bx._Ptr);
        v212._Myres = 7;
        r_12e = v2->playerBestlap;
        v212._Bx._Buf[0] = 0;
        v212._Mysize = 0;
        v94 = timeToString(&v217, r_12e, 3);
        v95 = v2->dataFont._Ptr;
        LOBYTE(v221) = 25;
        Font::blitString(v95, v2->bestlapX, y, v94, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v217._Myres >= 8 )
          operator delete(v217._Bx._Ptr);
      }
      else if ( i == 2 )
      {
        GLRenderer::color4f(v57, 1.0, 0.0, 1.0, 0.69999999);
        GLRenderer::quad(v57, wrect.left, wrect.top, v2->tableWidth, 30.5, 0, 0);
        v78 = timeToSectorString(&v206, v2->bestSplits[0], 3);
        v79 = v2->blackFont._Ptr;
        LOBYTE(v221) = 26;
        Font::blitString(v79, v2->splitX[0], y, v78, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v206._Myres >= 8 )
          operator delete(v206._Bx._Ptr);
        v206._Myres = 7;
        r_12 = v2->bestSplits[1];
        v206._Bx._Buf[0] = 0;
        v206._Mysize = 0;
        v80 = timeToSectorString(&v211, r_12, 3);
        v81 = v2->blackFont._Ptr;
        LOBYTE(v221) = 27;
        Font::blitString(v81, v2->splitX[1], y, v80, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v211._Myres >= 8 )
          operator delete(v211._Bx._Ptr);
        v211._Myres = 7;
        r_12a = v2->bestSplits[2];
        v211._Bx._Buf[0] = 0;
        v211._Mysize = 0;
        v82 = timeToSectorString(&v213, r_12a, 3);
        v83 = v2->blackFont._Ptr;
        LOBYTE(v221) = 28;
        Font::blitString(v83, v2->splitX[2], y, v82, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v213._Myres >= 8 )
          operator delete(v213._Bx._Ptr);
        v213._Myres = 7;
        r_12b = v2->bestlap;
        v213._Bx._Buf[0] = 0;
        v213._Mysize = 0;
        v84 = timeToString(&v216, r_12b, 3);
        v85 = v2->blackFont._Ptr;
        LOBYTE(v221) = 29;
        Font::blitString(v85, v2->bestlapX, y, v84, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( v216._Myres >= 8 )
          operator delete(v216._Bx._Ptr);
      }
    }
    else
    {
      GLRenderer::color4f(v57, colDarkTransp_2.x, colDarkTransp_2.y, colDarkTransp_2.z, colDarkTransp_2.w);
      GLRenderer::quad(v57, wrect.left, wrect.top, v2->tableWidth, 30.5, 0, 0);
      Font::blitString(v2->dataFont._Ptr, v2->nameX, y, &driver.name, 1.0, eAlignLeft);
      v96 = Sim::getFocusedCarIndex(v2->sim);
      v200 = Sim::getCar(v2->sim, v96);
      v97 = std::map<CarAvatar *,Texture>::operator[](&v2->skinTextures, &v200);
      GraphicsManager::setTexture(v2->sim->game->graphics, 0, (const Texture *)v97);
      GLRenderer::color4f(v57, 1.0, 1.0, 1.0, 1.0);
      GLRenderer::quad(v57, v2->carX, wrect.top + 3.0, 21.0, 21.0, 1, 0);
      v98 = timeToSectorString(&v210, v2->selectedBestSplits[0], 3);
      LOBYTE(v221) = 18;
      Font::blitString(v2->dataFont._Ptr, v2->splitX[0], y, v98, 1.0, eAlignRight);
      LOBYTE(v221) = 4;
      if ( v210._Myres >= 8 )
        operator delete(v210._Bx._Ptr);
      v210._Myres = 7;
      r_12f = v2->selectedBestSplits[1];
      v210._Bx._Buf[0] = 0;
      v210._Mysize = 0;
      v99 = timeToSectorString(&v209, r_12f, 3);
      v100 = v2->dataFont._Ptr;
      LOBYTE(v221) = 19;
      Font::blitString(v100, v2->splitX[1], y, v99, 1.0, eAlignRight);
      LOBYTE(v221) = 4;
      if ( v209._Myres >= 8 )
        operator delete(v209._Bx._Ptr);
      v209._Myres = 7;
      r_12g = v2->selectedBestSplits[2];
      v209._Bx._Buf[0] = 0;
      v209._Mysize = 0;
      v101 = timeToSectorString(&v205, r_12g, 3);
      v102 = v2->dataFont._Ptr;
      LOBYTE(v221) = 20;
      Font::blitString(v102, v2->splitX[2], y, v101, 1.0, eAlignRight);
      LOBYTE(v221) = 4;
      if ( v205._Myres >= 8 )
        operator delete(v205._Bx._Ptr);
      v205._Myres = 7;
      r_12h = v2->selectedBestlap;
      v205._Bx._Buf[0] = 0;
      v205._Mysize = 0;
      v103 = timeToString(&s, r_12h, 3);
      v104 = v2->dataFont._Ptr;
      LOBYTE(v221) = 21;
      Font::blitString(v104, v2->bestlapX, y, v103, 1.0, eAlignRight);
      LOBYTE(v221) = 4;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
    }
    v77 = wrect.top + 30.5;
    v76 = i + 1;
    i = v76;
    wrect.top = wrect.top + 30.5;
  }
  while ( v76 < 3 );
  v105 = v2->dataFont._Ptr;
  _First_4._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
  Font::setColor(v105, (const vec4f *)&_First_4);
  v106 = v2->lapcountX;
  v107 = wrect.top + 20.0;
  wrect.top = wrect.top + 20.0;
  if ( v106 == 0.0 )
  {
    v108 = wrect.left + 30.0;
    v2->lapcountX = wrect.left + 30.0;
    v109 = v108 + 50.0;
    v2->compoundX = v109;
    v110 = v109 + 110.0;
    v2->laptimeX = v110;
    v111 = v110 + 80.0;
    v2->lapSplitX[0] = v111;
    v112 = v111 + 60.0;
    v2->lapSplitX[1] = v112;
    v113 = v112 + 60.0;
    v2->lapSplitX[2] = v113;
    v2->deltaX = v113 + 80.0;
  }
  v192 = v107 + 1.0;
  GLRenderer::color4f(v57, colTitleBar_3.x, colTitleBar_3.y, colTitleBar_3.z, colTitleBar_3.w);
  GLRenderer::quad(v57, wrect.left, wrect.top, v2->tableWidth, 20.0, 0, 0);
  Font::setColor(v2->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, L"LAP", 3u);
  LOBYTE(v221) = 30;
  v114 = acTranslate(&v205, &_First_4);
  v115 = v2->titleFont._Ptr;
  LOBYTE(v221) = 31;
  Font::blitString(v115, v2->lapcountX, v107 + 1.0, v114, 1.0, eAlignRight);
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v205._Myres = 7;
  v205._Mysize = 0;
  v205._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, L"TYRE", 4u);
  LOBYTE(v221) = 32;
  v116 = acTranslate(&v205, &_First_4);
  v117 = v2->titleFont._Ptr;
  LOBYTE(v221) = 33;
  Font::blitString(v117, v2->compoundX, v192, v116, 1.0, eAlignCenter);
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v205._Myres = 7;
  v205._Mysize = 0;
  v205._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, L"LAPTIME", 7u);
  LOBYTE(v221) = 34;
  v118 = acTranslate(&v205, &_First_4);
  v119 = v2->titleFont._Ptr;
  LOBYTE(v221) = 35;
  Font::blitString(v119, v2->laptimeX, v192, v118, 1.0, eAlignRight);
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v205._Myres = 7;
  v205._Mysize = 0;
  v205._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, (const wchar_t *)&Str._Bx._Alias[4], 2u);
  LOBYTE(v221) = 36;
  v120 = acTranslate(&v205, &_First_4);
  LOBYTE(v221) = 37;
  Font::blitString(v2->titleFont._Ptr, v2->lapSplitX[0], v192, v120, 1.0, eAlignRight);
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v205._Myres = 7;
  v205._Mysize = 0;
  v205._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, (const wchar_t *)&Str._Bx._Alias[12], 2u);
  LOBYTE(v221) = 38;
  v121 = acTranslate(&v205, &_First_4);
  v122 = v2->titleFont._Ptr;
  LOBYTE(v221) = 39;
  Font::blitString(v122, v2->lapSplitX[1], v192, v121, 1.0, eAlignRight);
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v205._Myres = 7;
  v205._Mysize = 0;
  v205._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, (const wchar_t *)&Str._Myres, 2u);
  LOBYTE(v221) = 40;
  v123 = acTranslate(&v205, &_First_4);
  v124 = v2->titleFont._Ptr;
  LOBYTE(v221) = 41;
  Font::blitString(v124, v2->lapSplitX[2], v192, v123, 1.0, eAlignRight);
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v205._Myres = 7;
  v205._Mysize = 0;
  v205._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  _First_4._Myres = 7;
  _First_4._Mysize = 0;
  _First_4._Bx._Buf[0] = 0;
  std::wstring::assign(&_First_4, L"Diff", 4u);
  LOBYTE(v221) = 42;
  v125 = acTranslate(&v205, &_First_4);
  v126 = v2->titleFont._Ptr;
  LOBYTE(v221) = 43;
  Font::blitString(v126, v2->deltaX, v192, v125, 1.0, eAlignRight);
  if ( v205._Myres >= 8 )
    operator delete(v205._Bx._Ptr);
  v205._Myres = 7;
  v205._Mysize = 0;
  v205._Bx._Buf[0] = 0;
  LOBYTE(v221) = 4;
  if ( _First_4._Myres >= 8 )
    operator delete(_First_4._Bx._Ptr);
  v127 = v2->currentLapPage;
  v128 = &v2->selectedLaps;
  v129 = v2->maxRows;
  v130 = v129 * (v127 + 1);
  v131 = v127 * v129;
  wrect.top = wrect.top + 20.0;
  v202 = v130;
  i = v131;
  ya = wrect.top + 5.0;
  if ( v131 >= (unsigned int)(v2->selectedLaps._Mylast - v2->selectedLaps._Myfirst) )
    goto LABEL_212;
  v193 = v131;
  while ( v131 != v202 )
  {
    if ( v131 % 2 )
      v132 = colDarkTransp_2;
    else
      v132 = colDarkBar_3;
    GLRenderer::color4f(v57, v132.x, v132.y, v132.z, v132.w);
    GLRenderer::quad(v57, wrect.left, wrect.top, v2->tableWidth, 30.5, 0, 0);
    v201 = i + 1;
    v133 = std::to_wstring(&s, i + 1);
    v134 = v2->dataFont._Ptr;
    LOBYTE(v221) = 44;
    Font::blitString(v134, v2->lapcountX, ya, v133, 1.0, eAlignRight);
    LOBYTE(v221) = 4;
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
    Font::blitString(v2->dataFont._Ptr, v2->compoundX, ya, &v128->_Myfirst[v193].compound, 1.0, eAlignRight);
    v135 = v128->_Myfirst;
    if ( v128->_Myfirst[v193].isValid || !v135[v193].time )
    {
      v138 = v2->bestlap;
      if ( v138 == v135[v193].time && v138 )
      {
        GLRenderer::color4f(v57, 1.0, 0.0, 1.0, 0.69999999);
        GLRenderer::quad(v57, v2->laptimeX - 74.0, ya, 76.0, 18.0, 0, 0);
        v139 = timeToString(&s, v128->_Myfirst[v193].time, 3);
        v140 = v2->blackFont._Ptr;
        LOBYTE(v221) = 46;
        Font::blitString(v140, v2->laptimeX, ya, v139, 1.0, eAlignRight);
      }
      else
      {
        v141 = v2->selectedBestlap;
        if ( v141 == v135[v193].time && v141 )
        {
          GLRenderer::color4f(v57, 0.0, 1.0, 0.0, 0.69999999);
          GLRenderer::quad(v57, v2->laptimeX - 74.0, ya, 76.0, 18.0, 0, 0);
          v142 = timeToString(&s, v128->_Myfirst[v193].time, 3);
          v143 = v2->blackFont._Ptr;
          LOBYTE(v221) = 47;
          Font::blitString(v143, v2->laptimeX, ya, v142, 1.0, eAlignRight);
        }
        else
        {
          v144 = timeToString(&s, v135[v193].time, 3);
          v145 = v2->dataFont._Ptr;
          LOBYTE(v221) = 48;
          Font::blitString(v145, v2->laptimeX, ya, v144, 1.0, eAlignRight);
        }
      }
    }
    else
    {
      GLRenderer::color4f(v57, 1.0, 0.0, 0.0, 0.69999999);
      GLRenderer::quad(v57, v2->laptimeX - 74.0, ya, 76.0, 18.0, 0, 0);
      v136 = timeToString(&s, v128->_Myfirst[v193].time, 3);
      v137 = v2->blackFont._Ptr;
      LOBYTE(v221) = 45;
      Font::blitString(v137, v2->laptimeX, ya, v136, 1.0, eAlignRight);
    }
    LOBYTE(v221) = 4;
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
    v200 = 0;
    v146 = v2->lapSplitX;
    _First = (Lap *)(-608 - (_DWORD)v2);
    do
    {
      if ( v128->_Myfirst[v193].splits._Mylast - v128->_Myfirst[v193].splits._Myfirst <= (unsigned int)v200 )
      {
        std::wstring::wstring(&s, L"---");
        LOBYTE(v221) = 53;
        r = *v146;
        v162 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v2->dataFont);
        Font::blitString(v162, r, ya, &s, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
        goto LABEL_202;
      }
      v147 = &_Keyval;
      v148 = (char *)v146 + (unsigned int)v128->_Myfirst[v193].splits._Myfirst;
      _Keyval = (CarAvatar *)999999;
      v149 = (CarAvatar **)&v148[(_DWORD)_First];
      if ( (unsigned int)*v149 <= 0xF423F )
        v147 = v149;
      v150 = *((_DWORD *)v146 - 44);
      v151 = (float)(unsigned int)*v147;
      *(float *)&_Keyval = v151;
      v152 = (float)v150;
      if ( v152 == v151 && v150 )
      {
        GLRenderer::color4f(v199, 1.0, 0.0, 1.0, 0.69999999);
        GLRenderer::quad(v199, *v146 - 54.0, ya, 56.0, 18.0, 0, 0);
        v153 = timeToSectorString(&s, (int)*(float *)&_Keyval, 3);
        LOBYTE(v221) = 49;
        goto LABEL_188;
      }
      v154 = (float)*((unsigned int *)v146 - 48);
      if ( v154 == v151 && *((_DWORD *)v146 - 48) )
      {
        GLRenderer::color4f(v199, 0.0, 1.0, 0.0, 0.69999999);
        GLRenderer::quad(v199, *v146 - 54.0, ya, 56.0, 18.0, 0, 0);
        v153 = timeToSectorString(&s, (int)*(float *)&_Keyval, 3);
        LOBYTE(v221) = 50;
LABEL_188:
        Font::blitString(v2->blackFont._Ptr, *v146, ya, v153, 1.0, eAlignRight);
        LOBYTE(v221) = 4;
        if ( s._Myres >= 8 )
          operator delete(s._Bx._Ptr);
        goto LABEL_202;
      }
      if ( v151 == 0.0 )
      {
        std::wstring::wstring(&v205, L"---");
        v221 = 52;
        v156 = v3 | 2;
      }
      else
      {
        v155 = timeToSectorString(&v209, (int)v151, 3);
        LOBYTE(v221) = 51;
        v156 = v3 | 1;
      }
      v157 = v2->dataFont._Ptr;
      v197 = v156;
      Font::blitString(v157, *v146, ya, v155, 1.0, eAlignRight);
      v158 = v156;
      if ( (v156 & 2) != 0 )
      {
        v158 = v156 & 0xFFFFFFFD;
        v197 = v156 & 0xFFFFFFFD;
        if ( v205._Myres >= 8 )
        {
          operator delete(v205._Bx._Ptr);
          v158 = v197;
        }
        v205._Myres = 7;
        v205._Mysize = 0;
        v205._Bx._Buf[0] = 0;
      }
      v221 = 4;
      if ( (v158 & 1) != 0 )
      {
        v197 = v158 & 0xFFFFFFFE;
        if ( v209._Myres >= 8 )
        {
          a = v209._Myres + 1;
          r_12i = v209._Bx._Ptr;
          v159 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                              (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&v209,
                                              (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&isGlobal[3]);
          std::allocator<wchar_t>::deallocate(v159, r_12i, a);
        }
        v209._Myres = 7;
        std::wstring::_Eos(&v209, 0);
      }
      v3 = v197;
LABEL_202:
      ++v146;
      v200 = (CarAvatar *)((char *)v200 + 1);
    }
    while ( (int)v200 < 3 );
    v160 = i;
    if ( i )
    {
      if ( std::vector<AudioEvent>::operator[]((std::vector<AudioEvent> *)&v2->selectedLaps, i)->path._Bx._Alias[0] )
      {
        v161 = v160 - 1;
        if ( i >= 1 )
        {
          while ( !std::vector<AudioEvent>::operator[]((std::vector<AudioEvent> *)&v2->selectedLaps, v161)->path._Bx._Alias[0] )
          {
            if ( (--v161 & 0x80000000) != 0 )
              goto LABEL_211;
          }
          v163 = std::vector<AudioEvent>::operator[]((std::vector<AudioEvent> *)&v2->selectedLaps, v161);
          v164 = std::vector<AudioEvent>::operator[]((std::vector<AudioEvent> *)&v2->selectedLaps, i);
          r_8 = timeToDiffString(&s, (char *)v164->engine - (char *)v163->engine, 3);
          LOBYTE(v221) = 54;
          ra = v2->deltaX;
          v165 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v2->dataFont);
          Font::blitString(v165, ra, ya, r_8, 1.0, eAlignRight);
          LOBYTE(v221) = 4;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
        }
      }
    }
LABEL_211:
    v166 = (char *)v2->selectedLaps._Mylast - (char *)v2->selectedLaps._Myfirst;
    ++v193;
    i = v201;
    v167 = (unsigned __int64)(715827883i64 * v166) >> 32;
    wrect.top = wrect.top + 30.5;
    v131 = v201;
    ya = wrect.top + 5.0;
    if ( v201 < (v167 >> 3) + ((unsigned int)v167 >> 31) )
    {
      v57 = v199;
      continue;
    }
    break;
  }
LABEL_212:
  v2->lapsButtonsTop = *std::max<float>(&wrect.top, &v2->lapsButtonsTop);
  v168 = std::vector<Lap>::size(&v2->selectedLaps);
  ksgui::Control::setVisible(v2->btLapNextPage, v168 > v2->maxRows);
  v169 = std::vector<Lap>::size(&v2->selectedLaps);
  ksgui::Control::setVisible(v2->btLapPreviousPage, v169 > v2->maxRows);
  ksgui::Form::setPosition((ksgui::Form *)v2->btLapNextPage, v2->tableWidth - 20.0, v2->lapsButtonsTop + 5.0);
  ksgui::Form::setPosition(
    (ksgui::Form *)v2->btLapPreviousPage,
    (float)((float)(v2->tableWidth - 20.0) - 40.0) - 10.0,
    v2->lapsButtonsTop + 5.0);
  GLRenderer::color4f(v199, &colDarkTransp_2);
  GLRenderer::quad(v199, wrect.left, v2->lapsButtonsTop, v2->tableWidth, 50.0, 0, 0);
  v170 = (ksgui::Form *)v2->btPrint;
  aa = v2->lapsButtonsTop + 15.0;
  v171 = ksgui::Control::getWidth(v170);
  v172 = v2->tableWidth;
  *(float *)&v201 = v171;
  ksgui::Form::setPosition(v170, (float)((float)(v172 - *(float *)&v201) * 0.5) + 20.0, aa);
  ksgui::Control::render(v2, (int)&v2->lapsButtonsTop, (int)v170, dt, v188, v189);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&sessionInfoName);
  SetupItemText::~SetupItemText(&driver);
  OnSessionEndEvent::~OnSessionEndEvent(&result);
}
