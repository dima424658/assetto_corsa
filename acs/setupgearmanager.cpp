#include "setupgearmanager.h"
void SetupGearManager::SetupGearManager(SetupGearManager *this, CarAvatar *aCar)
{
  std::_Tree_node<std::pair<std::wstring const ,GearSetDef>,void *> *v3; // eax
  std::_Tree_node<std::pair<ksgui::Spinner * const,GearDef>,void *> *v4; // eax
  Font *v5; // eax
  Font *v6; // eax
  std::_Ref_count_base *v7; // esi
  std::wstring v8; // [esp-14h] [ebp-64h] BYREF
  float w; // [esp+4h] [ebp-4Ch]
  float h; // [esp+8h] [ebp-48h]
  std::shared_ptr<Font> _Right; // [esp+1Ch] [ebp-34h] BYREF
  SetupGearManager *v12; // [esp+24h] [ebp-2Ch]
  std::wstring text; // [esp+28h] [ebp-28h] BYREF
  int v14; // [esp+4Ch] [ebp-4h]

  v12 = this;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"GEARS", 5u);
  h = *(float *)&aCar->sim;
  v14 = 0;
  w = *(float *)(*(_DWORD *)(LODWORD(h) + 4) + 252);
  acTranslate(&v8, &text);
  SetupTab::SetupTab(this, v8, (ksgui::GUI *)LODWORD(w), (Sim *)LODWORD(h));
  LOBYTE(v14) = 2;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->__vftable = (SetupGearManager_vtbl *)&SetupGearManager::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  this->gearSets._Myhead = 0;
  this->gearSets._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,GearSetDef>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::vector<AudioEvent *> >> > *)&this->gearSets);
  this->gearSets._Myhead = v3;
  LOBYTE(v14) = 3;
  this->gears._Myhead = 0;
  this->gears._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<ksgui::Spinner * const,GearDef>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,AudioEngine::GUID>> > *)&this->gears);
  this->gears._Myhead = v4;
  this->defaultValues._Myfirst = 0;
  this->defaultValues._Mylast = 0;
  this->defaultValues._Myend = 0;
  LOBYTE(v14) = 5;
  this->car = aCar;
  this->gearSetSpinner = 0;
  ksgui::Control::setSize(this, 450.0, 600.0);
  v5 = (Font *)operator new(24);
  _Right._Ptr = v5;
  LOBYTE(v14) = 6;
  if ( v5 )
    Font::Font(v5, eFontProportional, 12.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v14) = 5;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v6);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v7 = _Right._Rep;
  if ( _Right._Rep && !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
  {
    v7->_Destroy(v7);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v7->_Weaks) )
      ((void (*)(void))v7->_Delete_this)();
  }
}
void SetupGearManager::~SetupGearManager(SetupGearManager *this)
{
  std::vector<int> *v2; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<ksgui::Spinner * const,GearDef> > > > result; // [esp+8h] [ebp-4h] BYREF

  v2 = &this->defaultValues;
  this->__vftable = (SetupGearManager_vtbl *)&SetupGearManager::`vftable';
  if ( this->defaultValues._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->defaultValues);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  std::_Tree<std::_Tmap_traits<ksgui::Spinner *,GearDef,std::less<ksgui::Spinner *>,std::allocator<std::pair<ksgui::Spinner * const,GearDef>>,0>>::erase(
    &this->gears,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<ksgui::Spinner * const,GearDef> > > >)this->gears._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<ksgui::Spinner * const,GearDef> > > >)this->gears._Myhead);
  operator delete(this->gears._Myhead);
  std::_Tree<std::_Tmap_traits<std::wstring,GearSetDef,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,GearSetDef>>,0>>::erase(
    &this->gearSets,
    (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,GearSetDef> > > > *)&result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,GearSetDef> > > >)this->gearSets._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,GearSetDef> > > >)this->gearSets._Myhead);
  operator delete(this->gearSets._Myhead);
  SetupTab::~SetupTab(this);
}
SetupGearManager *SetupGearManager::`scalar deleting destructor'(SetupGearManager *this, unsigned int a2)
{
  SetupGearManager::~SetupGearManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SetupGearManager::addGearSet(SetupGearManager *this, std::wstring name, GearSetDef gs)
{
  char v4; // bl
  ksgui::Spinner *v5; // edi
  ksgui::Spinner *v6; // eax
  ksgui::Spinner *v7; // eax
  Event<ksgui::OnSpinnerValueChanged> *v8; // ecx
  GearSetDef *v9; // eax
  _BYTE v10[28]; // [esp-8h] [ebp-64h] BYREF
  ksgui::Spinner *v11; // [esp+28h] [ebp-34h]
  char v12; // [esp+2Fh] [ebp-2Dh] BYREF
  int v13; // [esp+30h] [ebp-2Ch]
  std::wstring iname; // [esp+34h] [ebp-28h] BYREF
  int v15; // [esp+58h] [ebp-4h]

  v4 = 0;
  v13 = 0;
  v15 = 1;
  if ( !this->gearSetSpinner )
  {
    v5 = (ksgui::Spinner *)operator new(444);
    v11 = v5;
    LOBYTE(v15) = 2;
    if ( v5 )
    {
      std::wstring::wstring(&iname, L"GEAR_SETS");
      *(_DWORD *)&v10[24] = 0;
      v4 = 1;
      LOBYTE(v15) = 3;
      *(_DWORD *)&v10[20] = 1;
      *(_DWORD *)&v10[16] = this->gui;
      v13 = 1;
      ksgui::Spinner::Spinner(v5, &iname, *(ksgui::GUI **)&v10[16], 1, 0);
    }
    else
    {
      v6 = 0;
    }
    this->gearSetSpinner = v6;
    v15 = 1;
    if ( (v4 & 1) != 0 && iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    this->addControl(this, this->gearSetSpinner);
    ((void (*)(ksgui::Spinner *, int, int))this->gearSetSpinner->setSize)(
      this->gearSetSpinner,
      1127743488,
      1101529088);
    ksgui::Spinner::setPosition(
      this->gearSetSpinner,
      (float)((float)(this->rect.right - this->rect.left) * 0.5)
    - (float)((float)(this->gearSetSpinner->rect.right - this->gearSetSpinner->rect.left) * 0.5),
      100.0);
    v7 = this->gearSetSpinner;
    *(_DWORD *)&v10[24] = this;
    v7->drawUnderline = 1;
    *(_DWORD *)v10 = &std::_Func_impl<std::_Callable_obj<_lambda_0488e465f417cf176783f246f52fde28_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v10[4] = this;
    *(_DWORD *)&v10[16] = v10;
    v8 = &this->gearSetSpinner->evOnValueChanged;
    LOBYTE(v15) = 1;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)v8,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v10,
      *(void **)&v10[24]);
  }
  *(_DWORD *)&v10[24] = 7;
  *(_DWORD *)&v10[20] = 0;
  *(_WORD *)&v10[4] = 0;
  std::wstring::assign((std::wstring *)&v10[4], &name, 0, 0xFFFFFFFF);
  ksgui::Spinner::addItem(this->gearSetSpinner, *(std::wstring *)&v10[4]);
  v9 = std::map<std::wstring,GearSetDef>::operator[](&this->gearSets, &name);
  std::vector<GearDef>::operator=(&v9->gears, &gs.gears);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  v15 = -1;
  if ( gs.gears._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&gs);
    *(_DWORD *)&v10[24] = v11;
    *(_DWORD *)&v10[20] = &v12;
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<GearDef>>>(gs.gears._Myfirst, gs.gears._Mylast);
    operator delete(gs.gears._Myfirst);
  }
}
void SetupGearManager::addSetupItem(SetupGearManager *this, int absoluteGearIndex, const SetupItemText *item)
{
  ICollisionObject *v4; // eax
  int v5; // eax
  int v6; // esi
  Font *v7; // eax
  Font *v8; // eax
  std::_Ref_count_base *v9; // edi
  int v10; // eax
  double v11; // xmm0_8
  float v12; // xmm5_4
  __m128 v13; // xmm3
  float v14; // xmm2_4
  _BYTE v15[28]; // [esp-Ch] [ebp-68h] BYREF
  std::shared_ptr<Font> _Right; // [esp+28h] [ebp-34h] BYREF
  ICollisionObject *_Val; // [esp+30h] [ebp-2Ch] BYREF
  std::wstring helpText; // [esp+34h] [ebp-28h] BYREF
  int v19; // [esp+58h] [ebp-4h]

  v4 = (ICollisionObject *)operator new(444);
  _Val = v4;
  v19 = 0;
  if ( v4 )
  {
    ksgui::Spinner::Spinner((ksgui::Spinner *)v4, &item->displayName, this->gui, 1, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v19 = -1;
  _Val = (ICollisionObject *)v6;
  *(_DWORD *)&v15[24] = 7;
  *(_DWORD *)&v15[20] = 0;
  *(_WORD *)&v15[4] = 0;
  std::wstring::assign((std::wstring *)&v15[4], &item->displayName, 0, 0xFFFFFFFF);
  ksgui::Spinner::setLabelText((ksgui::Spinner *)v6, *(std::wstring *)&v15[4]);
  *(_DWORD *)&v15[24] = 24;
  *(_DWORD *)(v6 + 168) = 0;
  v7 = (Font *)operator new(*(_DWORD *)&v15[24]);
  _Right._Ptr = v7;
  v19 = 1;
  if ( v7 )
    Font::Font(v7, eFontProportional, 12.0, 0, 0);
  else
    v8 = 0;
  v19 = -1;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v8);
  std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)(v6 + 128), &_Right);
  v9 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v9->_Destroy(v9);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v9->_Weaks, 0xFFFFFFFF) )
        v9->_Delete_this(v9);
    }
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v6 + 28))(v6, 1127743488, 1101529088);
  if ( absoluteGearIndex < 0 )
    v10 = this->car->physicsInfo.maxGear;
  else
    v10 = absoluteGearIndex - 2;
  v11 = (double)(unsigned int)v10;
  v12 = (float)((float)((float)(unsigned int)v10 * 1.5) * 48.0) + 55.0;
  v13.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v12);
  LODWORD(v11) = LODWORD(v12) ^ LODWORD(FLOAT_N0_0) & LODWORD(v12);
  LODWORD(v14) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(
                                              (__m128)*(unsigned __int64 *)&v11,
                                              (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v12);
  *(float *)&v11 = (float)((float)(v12 + v14) - v14) - v12;
  ksgui::Spinner::setPosition(
    (ksgui::Spinner *)v6,
    135.0,
    (float)((float)(v12 + v14) - v14)
  - COERCE_FLOAT(_mm_cmpgt_ss((__m128)*(unsigned __int64 *)&v11, v13).m128_u32[0] & LODWORD(FLOAT_1_0)));
  *(_BYTE *)(v6 + 317) = 1;
  acLocaleGetSetupHelpText(&helpText, &item->helpKey);
  v19 = 2;
  if ( std::wstring::compare(&helpText, 0, helpText._Mysize, word_17BE9D8, 0) )
  {
    *(_DWORD *)&v15[24] = 7;
    *(_DWORD *)&v15[20] = 0;
    *(_WORD *)&v15[4] = 0;
    std::wstring::assign((std::wstring *)&v15[4], &helpText, 0, 0xFFFFFFFF);
    ksgui::PopOver::setText(*(ksgui::PopOver **)(v6 + 312), *(std::wstring *)&v15[4]);
    *(_DWORD *)&v15[24] = 7;
    *(_DWORD *)&v15[20] = 0;
    *(_WORD *)&v15[4] = 0;
    std::wstring::assign((std::wstring *)&v15[4], &item->displayName, 0, 0xFFFFFFFF);
    ksgui::PopOver::setLabelTitle(*(ksgui::PopOver **)(v6 + 312), *(std::wstring *)&v15[4]);
    *(_BYTE *)(v6 + 316) = 1;
  }
  else
  {
    *(_BYTE *)(v6 + 316) = 0;
  }
  SetupGearManager::populateSpinner(this, (unsigned int)this, absoluteGearIndex, (ksgui::Spinner *)v6, item);
  _Right._Ptr = (Font *)ksgui::Spinner::getValue((ksgui::Spinner *)v6);
  std::vector<CarAvatar *>::push_back(&this->defaultValues, (int *)&_Right);
  *(_DWORD *)v15 = &std::_Func_impl<std::_Callable_obj<_lambda_62bb50cacea067a8a5d5ee1d50fd74f9_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v15[4] = this;
  *(_DWORD *)&v15[16] = v15;
  LOBYTE(v19) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)(v6 + 300),
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v15,
    this);
  this->addControl(this, (ksgui::Control *)v6);
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->spinners, &_Val);
  if ( helpText._Myres >= 8 )
    operator delete(helpText._Bx._Ptr);
}
std::wstring *SetupGearManager::getStringMaxSpeed(SetupGearManager *this, std::wstring *result, unsigned int gear)
{
  const std::wstring *v4; // ecx
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  std::wostream *v8; // eax
  const char *v10; // [esp+8h] [ebp-114h]
  Speed speed; // [esp+20h] [ebp-FCh] BYREF
  int v12; // [esp+24h] [ebp-F8h]
  Speed v13; // [esp+28h] [ebp-F4h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v14; // [esp+2Ch] [ebp-F0h] BYREF
  int v15; // [esp+DCh] [ebp-40h]
  std::wstring text; // [esp+E4h] [ebp-38h] BYREF
  std::wstring v17; // [esp+FCh] [ebp-20h] BYREF
  int v18; // [esp+118h] [ebp-4h]

  v12 = 0;
  LODWORD(v13.value) = (Speed)result;
  *(_DWORD *)v14.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v14.gap68);
  *(_DWORD *)v14.gap0 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v14._Chcount, &v14.gap10[16], 0);
  *(_DWORD *)((char *)&v14._Chcount + *(_DWORD *)(LODWORD(v14._Chcount) + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v14.gap0[*(_DWORD *)(LODWORD(v14._Chcount) + 4) + 4] = *(_DWORD *)(LODWORD(v14._Chcount) + 4) - 104;
  std::wstreambuf::wstreambuf(&v14.gap10[16]);
  *(_DWORD *)&v14.gap10[16] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v14.gap10[72] = 0;
  *(_DWORD *)&v14.gap10[76] = 0;
  RaceEngineer::getMaxSpeedFromGear(this->car->raceEngineer._Myptr, &v13, gear);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Max speed gear", 0xEu);
  v4 = acTranslate(&v17, &text);
  v5 = std::operator<<<wchar_t>((std::wostream *)&v14.gap10[8], v4);
  v6 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v5, " ");
  v7 = (std::wostream *)std::wostream::operator<<(v6, gear + 1);
  v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v7, v10);
  std::wostream::operator<<(v8);
  if ( *(_DWORD *)&v17._Bx._Alias[12] >= 8u )
    operator delete(text._Mysize);
  LOBYTE(v18) = 5;
  LOWORD(text._Mysize) = 0;
  *(_QWORD *)&v17._Bx._Alias[8] = 0x700000000i64;
  if ( *(_DWORD *)&text._Bx._Alias[12] >= 8u )
    operator delete(v15);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v14, result);
  v12 = 3;
  LOBYTE(v18) = 4;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&speed);
  LOBYTE(v18) = 0;
  *(_DWORD *)&v14.gap0[*(_DWORD *)(*(_DWORD *)v14.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v13.value + *(_DWORD *)(*(_DWORD *)v14.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v14.gap0 + 4) - 104;
  *(_DWORD *)&v14.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v14.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v14.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v14.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v14.gap68);
  return result;
}
std::wstring *SetupGearManager::getStringToSave(SetupGearManager *this, std::wstring *result)
{
  std::wstring *v3; // ebp
  bool v4; // zf
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  int v7; // eax
  ksgui::Spinner **v8; // esi
  ksgui::Spinner **v9; // edi
  std::map<ksgui::Spinner *,GearDef> *v10; // ebp
  ksgui::Spinner *const *v11; // ebx
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  int v16; // eax
  int v17; // eax
  int v19; // [esp-4h] [ebp-110h]
  int v20; // [esp-4h] [ebp-110h]
  ksgui::Spinner *spinner; // [esp+1Ch] [ebp-F0h] BYREF
  std::wstring *v22; // [esp+20h] [ebp-ECh]
  int v23; // [esp+24h] [ebp-E8h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v24; // [esp+28h] [ebp-E4h] BYREF
  GearDef gear; // [esp+D8h] [ebp-34h] BYREF
  int v26; // [esp+108h] [ebp-4h]

  v3 = result;
  v22 = result;
  *(_DWORD *)v24.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v24.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v24.gap68);
  v26 = 0;
  v23 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v24, &v24.gap10[8], 0);
  v26 = 1;
  *(_DWORD *)&v24.gap0[*(_DWORD *)(*(_DWORD *)v24.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v23 + *(_DWORD *)(*(_DWORD *)v24.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v24.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v24.gap10[8]);
  *(_DWORD *)&v24.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v24.gap10[64] = 0;
  *(_DWORD *)&v24.gap10[68] = 0;
  v4 = this->gearSetSpinner == 0;
  v26 = 3;
  if ( !v4 )
  {
    v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v24.gap10, "[GEARSET]");
    std::wostream::operator<<(v5);
    v19 = ksgui::Spinner::getValue(this->gearSetSpinner);
    v6 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v24.gap10, "VALUE=");
    v7 = std::wostream::operator<<(v6, v19);
    std::wostream::operator<<(v7);
  }
  v8 = this->spinners._Myfirst;
  v9 = this->spinners._Mylast;
  if ( v8 != v9 )
  {
    v10 = &this->gears;
    do
    {
      spinner = *v8;
      v11 = std::map<ksgui::Spinner *,GearDef>::operator[](v10, &spinner);
      gear.setupManagerName._Myres = 7;
      gear.setupManagerName._Mysize = 0;
      gear.setupManagerName._Bx._Buf[0] = 0;
      std::wstring::assign(&gear.setupManagerName, (const std::wstring *)v11, 0, 0xFFFFFFFF);
      LOBYTE(v26) = 4;
      std::vector<unsigned int>::vector<unsigned int>(
        (std::vector<unsigned int> *)&gear.values,
        (const std::vector<unsigned int> *)v11 + 2);
      LOBYTE(v26) = 5;
      v12 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v24.gap10, "[");
      v13 = std::operator<<<wchar_t>(v12, &gear.setupManagerName);
      v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, "]");
      std::wostream::operator<<(v14);
      v20 = ksgui::Spinner::getValue(spinner);
      v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v24.gap10, "VALUE=");
      v16 = std::wostream::operator<<(v15, v20);
      std::wostream::operator<<(v16);
      LOBYTE(v26) = 3;
      if ( gear.values._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&gear.values);
        operator delete(gear.values._Myfirst);
        gear.values._Myfirst = 0;
        gear.values._Mylast = 0;
        gear.values._Myend = 0;
      }
      if ( gear.setupManagerName._Myres >= 8 )
        operator delete(gear.setupManagerName._Bx._Ptr);
      gear.setupManagerName._Myres = 7;
      ++v8;
      gear.setupManagerName._Mysize = 0;
      gear.setupManagerName._Bx._Buf[0] = 0;
    }
    while ( v8 != v9 );
    v3 = v22;
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v24, v3);
  v26 = -1;
  *(_DWORD *)&v24.gap0[*(_DWORD *)(*(_DWORD *)v24.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v23 + *(_DWORD *)(*(_DWORD *)v24.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v24.gap0 + 4) - 104;
  *(_DWORD *)&v24.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v24.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v24.gap10[8]) )
      std::wstreambuf::epptr(&v24.gap10[8]);
    else
      std::wstreambuf::egptr(&v24.gap10[8]);
    std::wstreambuf::eback(&v24.gap10[8]);
    v17 = std::wstreambuf::eback(&v24.gap10[8]);
    operator delete(v17);
  }
  std::wstreambuf::setg(&v24.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v24.gap10[8], 0, 0);
  *(_DWORD *)&v24.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v24.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v24.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v24.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v24.gap68);
  return v3;
}
void SetupGearManager::loadFromINI(SetupGearManager *this, INIReader *ini, bool isFixed)
{
  char v4; // bl
  int v5; // esi
  ksgui::Spinner **v6; // esi
  ksgui::Spinner **v7; // edi
  std::map<ksgui::Spinner *,GearDef> *v8; // ecx
  ksgui::Spinner *const *v9; // ebx
  INIReader *v10; // ebx
  int v11; // ebx
  char v12; // [esp+17h] [ebp-85h]
  ksgui::Spinner *spinner; // [esp+18h] [ebp-84h] BYREF
  INIReader *v14; // [esp+1Ch] [ebp-80h]
  std::wstring section; // [esp+20h] [ebp-7Ch] BYREF
  std::wstring key; // [esp+38h] [ebp-64h] BYREF
  std::wstring itemName; // [esp+50h] [ebp-4Ch] BYREF
  GearDef gear; // [esp+68h] [ebp-34h] BYREF
  int v19; // [esp+98h] [ebp-4h]

  v4 = 0;
  spinner = 0;
  v14 = ini;
  if ( !this->gearSetSpinner )
    goto LABEL_3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"GEARSET", 7u);
  v19 = 0;
  v4 = 1;
  spinner = (ksgui::Spinner *)1;
  v12 = 1;
  if ( !INIReader::hasSection(ini, &section) )
LABEL_3:
    v12 = 0;
  v19 = -1;
  if ( (v4 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v12 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"VALUE", 5u);
    v19 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GEARSET", 7u);
    LOBYTE(v19) = 2;
    v5 = INIReader::getInt(ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v19 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    SetupTab::setValueToSpinner(this, this->gearSetSpinner, isFixed, v5);
  }
  v6 = this->spinners._Myfirst;
  v7 = this->spinners._Mylast;
  if ( v6 != v7 )
  {
    v8 = &this->gears;
    do
    {
      spinner = *v6;
      v9 = std::map<ksgui::Spinner *,GearDef>::operator[](v8, &spinner);
      gear.setupManagerName._Myres = 7;
      gear.setupManagerName._Mysize = 0;
      gear.setupManagerName._Bx._Buf[0] = 0;
      std::wstring::assign(&gear.setupManagerName, (const std::wstring *)v9, 0, 0xFFFFFFFF);
      v19 = 3;
      std::vector<unsigned int>::vector<unsigned int>(
        (std::vector<unsigned int> *)&gear.values,
        (const std::vector<unsigned int> *)v9 + 2);
      v19 = 4;
      itemName._Bx._Buf[0] = 0;
      itemName._Myres = 7;
      itemName._Mysize = 0;
      std::wstring::assign(&itemName, &gear.setupManagerName, 0, 0xFFFFFFFF);
      v10 = v14;
      LOBYTE(v19) = 5;
      if ( INIReader::hasSection(v14, &itemName) )
      {
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"VALUE", 5u);
        LOBYTE(v19) = 6;
        v11 = INIReader::getInt(v10, &itemName, &key);
        LOBYTE(v19) = 5;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        SetupTab::setValueToSpinner(this, spinner, isFixed, v11);
      }
      else
      {
        spinner->isReadOnly = 0;
      }
      if ( itemName._Myres >= 8 )
        operator delete(itemName._Bx._Ptr);
      itemName._Myres = 7;
      itemName._Mysize = 0;
      itemName._Bx._Buf[0] = 0;
      v19 = -1;
      if ( gear.values._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&gear.values);
        operator delete(gear.values._Myfirst);
        gear.values._Myfirst = 0;
        gear.values._Mylast = 0;
        gear.values._Myend = 0;
      }
      if ( gear.setupManagerName._Myres >= 8 )
        operator delete(gear.setupManagerName._Bx._Ptr);
      ++v6;
      v8 = &this->gears;
    }
    while ( v6 != v7 );
  }
}
void __userpurge SetupGearManager::populateSpinner(SetupGearManager *this@<ecx>, unsigned int a2@<ebx>, int absoluteGearIndex, ksgui::Spinner *spinner, const SetupItemText *item)
{
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  std::vector<std::wstring> *v7; // eax
  std::wstring *v8; // eax
  bool v9; // cf
  int v10; // eax
  wchar_t v11; // ax
  std::wstring *v12; // edi
  std::wstring *i; // esi
  int v14; // ebp
  std::wstring *v15; // ebx
  std::wstring *v16; // eax
  const wchar_t *v17; // ebx
  unsigned int *v18; // ecx
  unsigned int *v19; // eax
  int v20; // ebx
  Car *v21; // eax
  float v22; // xmm0_4
  bool v23; // zf
  ksgui::Spinner **v24; // esi
  std::wstring *v25; // edi
  std::wstring *v26; // esi
  _BYTE v27[32]; // [esp-20h] [ebp-1E8h] BYREF
  std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > v28; // [esp+17h] [ebp-1B1h] BYREF
  float v29; // [esp+18h] [ebp-1B0h]
  std::vector<std::wstring> v30; // [esp+1Ch] [ebp-1ACh] BYREF
  ksgui::Spinner *v31; // [esp+28h] [ebp-1A0h] BYREF
  TyreTester v32; // [esp+2Fh] [ebp-199h] BYREF
  float v33; // [esp+30h] [ebp-198h] BYREF
  SetupGearManager *v34; // [esp+34h] [ebp-194h]
  std::vector<std::wstring> v35; // [esp+38h] [ebp-190h] BYREF
  wchar_t *v36; // [esp+44h] [ebp-184h] BYREF
  std::wifstream v37; // [esp+4Ch] [ebp-17Ch] BYREF
  std::wstring v38; // [esp+104h] [ebp-C4h] BYREF
  std::wstring v39; // [esp+11Ch] [ebp-ACh] BYREF
  std::vector<unsigned int> _Right; // [esp+134h] [ebp-94h] BYREF
  std::wstring splitter; // [esp+140h] [ebp-88h] BYREF
  std::vector<char> code; // [esp+158h] [ebp-70h] BYREF
  int v43; // [esp+168h] [ebp-60h]
  unsigned int v44; // [esp+16Ch] [ebp-5Ch]
  std::wstring sValue; // [esp+170h] [ebp-58h] BYREF
  std::wstring result; // [esp+188h] [ebp-40h] BYREF
  std::wstring acd; // [esp+1A0h] [ebp-28h] BYREF
  int v48; // [esp+1C4h] [ebp-4h]

  v34 = this;
  v31 = spinner;
  v5 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
  v48 = 0;
  std::operator+<wchar_t>(&acd, v5, L"/data.acd");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  *(_QWORD *)&v30._Myfirst = 0i64;
  v30._Myend = 0;
  LOBYTE(v48) = 3;
  if ( Path::fileExists(a2, &acd, 0) )
  {
    FolderEncrypter::FolderEncrypter(&v28);
    LOBYTE(v48) = 4;
    v6 = Path::getFileName(&splitter, &item->textFile);
    LOBYTE(v48) = 5;
    FolderEncrypter::decryptFile((FolderEncrypter *)&v28, &code, &acd, v6);
    LOBYTE(v48) = 7;
    if ( splitter._Myres >= 8 )
      operator delete(splitter._Bx._Ptr);
    splitter._Myres = 7;
    splitter._Bx._Buf[0] = 0;
    splitter._Mysize = 0;
    ksDecodeUtf8(&v38, &code);
    LOBYTE(v48) = 8;
    splitter._Myres = 7;
    splitter._Mysize = 0;
    splitter._Bx._Buf[0] = 0;
    std::wstring::assign(&splitter, L"\n", 1u);
    LOBYTE(v48) = 9;
    v7 = ksSplitString(&v35, &v38, &splitter);
    LOBYTE(v48) = 10;
    std::vector<std::wstring>::operator=(&v30, v7);
    LOBYTE(v48) = 9;
    if ( v35._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&v35);
      *(_DWORD *)&v27[28] = v36;
      *(_DWORD *)&v27[24] = &v32;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v35._Myfirst, v35._Mylast);
      operator delete(v35._Myfirst);
      *(_QWORD *)&v35._Myfirst = 0i64;
      v35._Myend = 0;
    }
    if ( splitter._Myres >= 8 )
      operator delete(splitter._Bx._Ptr);
    if ( v38._Myres >= 8 )
      operator delete(v38._Bx._Ptr);
    *(_QWORD *)&v38._Mysize = 0x700000000i64;
    v38._Bx._Buf[0] = 0;
    LOBYTE(v48) = 4;
    if ( code._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&code);
      operator delete(code._Myfirst);
      code._Myfirst = 0;
      code._Mylast = 0;
      code._Myend = 0;
    }
    LOBYTE(v48) = 3;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v28);
  }
  else
  {
    std::wifstream::wifstream(&v37, 1);
    LOBYTE(v48) = 11;
    v8 = Path::getPlatformSpecificPath(&v38, &item->textFile);
    v9 = v8->_Myres < 8;
    LOBYTE(v48) = 12;
    if ( !v9 )
      v8 = (std::wstring *)v8->_Bx._Ptr;
    v23 = std::wfilebuf::open((std::wfilebuf *)v37.gap10, v8->_Bx._Buf, 1, 64) == 0;
    *(_DWORD *)&v27[28] = 0;
    v10 = *(_DWORD *)(*(_DWORD *)v37.gap0 + 4);
    if ( v23 )
      std::wios::setstate((char *)&v37 + v10, 2, *(_DWORD *)&v27[28]);
    else
      std::wios::clear((char *)&v37 + v10, 0, *(_DWORD *)&v27[28]);
    LOBYTE(v48) = 11;
    if ( v38._Myres >= 8 )
      operator delete(v38._Bx._Ptr);
    while ( !std::ios_base::eof((std::ios_base *)&v37.gap0[*(_DWORD *)(*(_DWORD *)v37.gap0 + 4)]) )
    {
      *(_QWORD *)&v38._Mysize = 0x700000000i64;
      v38._Bx._Buf[0] = 0;
      LOBYTE(v48) = 13;
      v11 = std::wios::widen((char *)&v37 + *(_DWORD *)(*(_DWORD *)v37.gap0 + 4), 10);
      std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v37, &v38, v11);
      std::vector<std::wstring>::push_back(&v30, &v38);
      LOBYTE(v48) = 11;
      if ( v38._Myres >= 8 )
        operator delete(v38._Bx._Ptr);
    }
    std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&v37.gap64[12]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&v37.gap64[12]);
  }
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  _Right._Myfirst = 0;
  _Right._Mylast = 0;
  _Right._Myend = 0;
  LOBYTE(v48) = 14;
  if ( &v39 != &item->setupManagerVarName )
    std::wstring::assign(&v39, &item->setupManagerVarName, 0, 0xFFFFFFFF);
  v12 = v30._Mylast;
  for ( i = v30._Myfirst; i != v12; ++i )
  {
    v14 = std::wstring::find(i, L"|", 0, 1u);
    if ( v14 == -1 )
      break;
    sValue._Myres = 7;
    sValue._Mysize = 0;
    sValue._Bx._Buf[0] = 0;
    LOBYTE(v48) = 15;
    *(_QWORD *)&v38._Mysize = 0x700000000i64;
    v38._Bx._Buf[0] = 0;
    std::wstring::assign(&v38, L"/", 1u);
    LOBYTE(v48) = 16;
    v44 = 7;
    v43 = 0;
    LOWORD(code._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&code, L"//", 2u);
    LOBYTE(v48) = 17;
    *(_DWORD *)&v27[28] = &v38;
    *(_DWORD *)&v27[24] = &code;
    std::wstring::substr(i, (std::wstring *)v27, 0, v14);
    v15 = ksReplaceStringW(
            &splitter,
            *(std::wstring *)v27,
            *(const std::wstring **)&v27[24],
            *(const std::wstring **)&v27[28]);
    if ( &sValue != v15 )
    {
      if ( sValue._Myres >= 8 )
        operator delete(sValue._Bx._Ptr);
      sValue._Myres = 7;
      sValue._Mysize = 0;
      sValue._Bx._Buf[0] = 0;
      if ( v15->_Myres >= 8 )
      {
        sValue._Bx._Ptr = v15->_Bx._Ptr;
        v15->_Bx._Ptr = 0;
      }
      else if ( v15->_Mysize != -1 )
      {
        _memmove(&sValue, v15, 2 * (v15->_Mysize + 1));
      }
      sValue._Mysize = v15->_Mysize;
      sValue._Myres = v15->_Myres;
      v15->_Myres = 7;
      v15->_Mysize = 0;
      v15->_Bx._Buf[0] = 0;
    }
    if ( splitter._Myres >= 8 )
      operator delete(splitter._Bx._Ptr);
    splitter._Myres = 7;
    splitter._Mysize = 0;
    splitter._Bx._Buf[0] = 0;
    if ( v44 >= 8 )
      operator delete(code._Myfirst);
    v44 = 7;
    v43 = 0;
    LOWORD(code._Myfirst) = 0;
    LOBYTE(v48) = 15;
    if ( v38._Myres >= 8 )
      operator delete(v38._Bx._Ptr);
    v16 = std::wstring::substr(i, &v38, v14 + 1, i->_Mysize - v14);
    v17 = (const wchar_t *)v16;
    v9 = v16->_Myres < 8;
    LOBYTE(v48) = 18;
    if ( !v9 )
      v17 = v16->_Bx._Ptr;
    *__errno() = 0;
    v29 = _wcstod(v17, &v36);
    if ( v17 == v36 )
      goto $LN1356;
    if ( *__errno() == 34 )
    {
      std::_Xout_of_range("stof argument out of range");
$LN1356:
      std::_Xinvalid_argument("invalid stof argument");
      JUMPOUT(0x6640E8);
    }
    v33 = v29;
    LOBYTE(v48) = 15;
    if ( v38._Myres >= 8 )
      operator delete(v38._Bx._Ptr);
    *(_DWORD *)&v27[28] = 7;
    *(_DWORD *)&v27[24] = 0;
    *(_WORD *)&v27[8] = 0;
    std::wstring::assign((std::wstring *)&v27[8], &sValue, 0, 0xFFFFFFFF);
    ksgui::Spinner::addItem(v31, *(std::wstring *)&v27[8]);
    v18 = _Right._Mylast;
    if ( (unsigned int *)&v33 >= _Right._Mylast || (v19 = _Right._Myfirst, _Right._Myfirst > (unsigned int *)&v33) )
    {
      if ( _Right._Mylast == _Right._Myend )
      {
        std::vector<unsigned int>::_Reserve(&_Right, 1u);
        v18 = _Right._Mylast;
      }
      if ( !v18 )
        goto LABEL_62;
      *(float *)v18 = v29;
    }
    else
    {
      v20 = ((char *)&v33 - (char *)_Right._Myfirst) >> 2;
      if ( _Right._Mylast == _Right._Myend )
      {
        std::vector<unsigned int>::_Reserve(&_Right, 1u);
        v18 = _Right._Mylast;
        v19 = _Right._Myfirst;
      }
      if ( !v18 )
        goto LABEL_62;
      *v18 = v19[v20];
    }
    v18 = _Right._Mylast;
LABEL_62:
    _Right._Mylast = v18 + 1;
    v21 = RaceEngineer::getCar(v34->car->raceEngineer._Myptr);
    if ( absoluteGearIndex < 0 )
    {
      v23 = v29 == v21->drivetrain.finalRatio;
    }
    else
    {
      v22 = v21->drivetrain.gears._Myfirst[absoluteGearIndex].ratio;
      v23 = v29 == v22;
    }
    if ( v23 )
      ksgui::Spinner::setValue(v31, v31->maxValue);
    LOBYTE(v48) = 14;
    if ( sValue._Myres >= 8 )
      operator delete(sValue._Bx._Ptr);
  }
  v24 = (ksgui::Spinner **)std::map<ksgui::Spinner *,GearDef>::operator[](&v34->gears, &v31);
  if ( v24 != (ksgui::Spinner **)&v39 )
    std::wstring::assign((std::wstring *)v24, &v39, 0, 0xFFFFFFFF);
  std::vector<float>::operator=((std::vector<unsigned int> *)v24 + 2, &_Right);
  LOBYTE(v48) = 3;
  if ( _Right._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&_Right);
    operator delete(_Right._Myfirst);
    _Right._Myfirst = 0;
    _Right._Mylast = 0;
    _Right._Myend = 0;
  }
  if ( v39._Myres >= 8 )
    operator delete(v39._Bx._Ptr);
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  LOBYTE(v48) = 2;
  if ( v30._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v30);
    v25 = v30._Mylast;
    v26 = v30._Myfirst;
    if ( v30._Myfirst != v30._Mylast )
    {
      do
      {
        if ( v26->_Myres >= 8 )
          operator delete(v26->_Bx._Ptr);
        v26->_Myres = 7;
        v26->_Mysize = 0;
        v26->_Bx._Buf[0] = 0;
        ++v26;
      }
      while ( v26 != v25 );
      v26 = v30._Myfirst;
    }
    operator delete(v26);
    *(_QWORD *)&v30._Myfirst = 0i64;
    v30._Myend = 0;
  }
  if ( acd._Myres >= 8 )
    operator delete(acd._Bx._Ptr);
}
void __userpurge SetupGearManager::render(SetupGearManager *this@<ecx>, __int64 a2@<esi:edi>, float dt)
{
  int v3; // eax
  int v4; // eax
  __int64 v5; // rdi
  const std::wstring *v6; // eax
  Font *v7; // ecx
  int v8; // ecx
  std::wostream *v9; // eax
  std::wostream *v10; // eax
  std::wstring *v11; // eax
  Font *v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  __m128 v16; // xmm1
  float v17; // xmm3_4
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  float v20; // xmm4_4
  const std::wstring *v21; // eax
  Font *v22; // ecx
  __m128 v23; // xmm1
  float v24; // xmm3_4
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  float v27; // xmm4_4
  const std::wstring *v28; // eax
  Font *v29; // ecx
  const std::wstring *v30; // [esp+1Ch] [ebp-11Ch]
  vec2f pos; // [esp+38h] [ebp-100h] BYREF
  float v32; // [esp+40h] [ebp-F8h] BYREF
  int v33; // [esp+44h] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v34; // [esp+48h] [ebp-F0h] BYREF
  std::wstring result; // [esp+F8h] [ebp-40h] BYREF
  std::wstring text; // [esp+110h] [ebp-28h] BYREF
  int v37; // [esp+134h] [ebp-4h]

  LODWORD(a2) = this;
  v32 = 0.0;
  SetupTab::render(this, a2, dt);
  v3 = *(_DWORD *)a2;
  v32 = 0.0;
  v33 = 0;
  (*(void (**)(_DWORD, vec2f *, float *))(v3 + 16))(a2, &pos, &v32);
  v4 = *(_DWORD *)(a2 + 344);
  HIDWORD(a2) = 0;
  if ( *(_DWORD *)(a2 + 348) )
  {
    if ( *(int *)(v4 + 3388) > 0 )
    {
      do
      {
        v6 = SetupGearManager::getStringMaxSpeed((SetupGearManager *)v5, &result, HIDWORD(v5));
        v7 = *(Font **)(v5 + 128);
        v37 = 0;
        Font::blitString(
          v7,
          pos.x + 145.0,
          (float)((float)SHIDWORD(v5) * 50.0) + (float)(pos.y + 150.0),
          v6,
          1.0,
          eAlignLeft);
        v37 = -1;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        ++HIDWORD(v5);
      }
      while ( SHIDWORD(v5) < *(_DWORD *)(*(_DWORD *)(v5 + 344) + 3388) );
    }
    *(_DWORD *)v34.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v34.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v34.gap68);
    v37 = 1;
    LODWORD(v32) = 1;
    std::wiostream::basic_iostream<wchar_t>(&v34, &v34.gap10[8], 0);
    v37 = 2;
    *(_DWORD *)&v34.gap0[*(_DWORD *)(*(_DWORD *)v34.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v33 + *(_DWORD *)(*(_DWORD *)v34.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v34.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v34.gap10[8]);
    *(_DWORD *)&v34.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v34.gap10[64] = 0;
    *(_DWORD *)&v34.gap10[68] = 0;
    v37 = 4;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Final ratio", 0xBu);
    LOBYTE(v37) = 5;
    HIDWORD(v5) = acTranslate(&result, &text);
    v8 = *(_DWORD *)(v5 + 344);
    LOBYTE(v37) = 6;
    RaceEngineer::getCar(*(RaceEngineer **)(v8 + 3672));
    v9 = std::operator<<<wchar_t>((std::wostream *)v34.gap10, (const std::wstring *)HIDWORD(v5));
    v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v9, L" : ");
    std::wostream::operator<<(v10);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v37) = 4;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v34, &result);
    v12 = *(Font **)(v5 + 128);
    v30 = v11;
    v13 = *(_DWORD *)(v5 + 344);
    LOBYTE(v37) = 7;
    Font::blitString(
      v12,
      pos.x + 170.0,
      (float)((float)*(int *)(v13 + 3388) * 60.0) + (float)(pos.y + 150.0),
      v30,
      1.3,
      eAlignLeft);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v37 = -1;
    *(_DWORD *)&v34.gap0[*(_DWORD *)(*(_DWORD *)v34.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v33 + *(_DWORD *)(*(_DWORD *)v34.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v34.gap0 + 4) - 104;
    *(_DWORD *)&v34.gap10[8] = &std::wstringbuf::`vftable';
    if ( (v34.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v34.gap10[8]) )
        std::wstreambuf::epptr(&v34.gap10[8]);
      else
        std::wstreambuf::egptr(&v34.gap10[8]);
      std::wstreambuf::eback(&v34.gap10[8]);
      v14 = std::wstreambuf::eback(&v34.gap10[8]);
      operator delete(v14);
    }
    std::wstreambuf::setg(&v34.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v34.gap10[8], 0, 0);
    *(_DWORD *)&v34.gap10[68] &= 0xFFFFFFFE;
    *(_DWORD *)&v34.gap10[64] = 0;
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v34.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v34.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v34.gap68);
  }
  else
  {
    v15 = *(_DWORD *)(v4 + 3388);
    if ( v15 <= 7 )
    {
      if ( v15 > 0 )
      {
        v23.m128_f32[0] = FLOAT_8388608_0;
        do
        {
          v24 = (float)((float)((float)HIDWORD(v5) * 1.5) * 48.0) + 55.0;
          v25.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v24);
          v26.m128_i32[0] = LODWORD(v24) ^ LODWORD(FLOAT_N0_0) & LODWORD(v24);
          v26.m128_f32[0] = _mm_cmplt_ss(v26, v23).m128_f32[0];
          v27 = (float)(v24 + COERCE_FLOAT(v23.m128_i32[0] & v26.m128_i32[0] | v25.m128_i32[0]))
              - COERCE_FLOAT(v23.m128_i32[0] & v26.m128_i32[0] | v25.m128_i32[0]);
          v26.m128_f32[0] = v27 - v24;
          v32 = v27 - COERCE_FLOAT(_mm_cmpgt_ss(v26, v25).m128_u32[0] & LODWORD(FLOAT_1_0));
          v28 = SetupGearManager::getStringMaxSpeed((SetupGearManager *)v5, &text, HIDWORD(v5));
          v29 = *(Font **)(v5 + 128);
          v37 = 9;
          Font::blitString(v29, pos.x + 127.0, (float)(v32 + pos.y) + 27.0, v28, 1.3, eAlignLeft);
          v37 = -1;
          if ( text._Myres >= 8 )
            operator delete(text._Bx._Ptr);
          ++HIDWORD(v5);
          v23.m128_f32[0] = FLOAT_8388608_0;
        }
        while ( SHIDWORD(v5) < *(_DWORD *)(*(_DWORD *)(v5 + 344) + 3388) );
      }
    }
    else
    {
      v16.m128_f32[0] = FLOAT_8388608_0;
      do
      {
        v17 = (float)((float)((float)HIDWORD(v5) * 1.5) * 48.0) + 55.0;
        v18.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v17);
        v19.m128_i32[0] = LODWORD(v17) ^ LODWORD(FLOAT_N0_0) & LODWORD(v17);
        v19.m128_f32[0] = _mm_cmplt_ss(v19, v16).m128_f32[0];
        v20 = (float)(v17 + COERCE_FLOAT(v16.m128_i32[0] & v19.m128_i32[0] | v18.m128_i32[0]))
            - COERCE_FLOAT(v16.m128_i32[0] & v19.m128_i32[0] | v18.m128_i32[0]);
        v19.m128_f32[0] = v20 - v17;
        v32 = v20 - COERCE_FLOAT(_mm_cmpgt_ss(v19, v18).m128_u32[0] & LODWORD(FLOAT_1_0));
        v21 = SetupGearManager::getStringMaxSpeed((SetupGearManager *)v5, &result, HIDWORD(v5));
        v22 = *(Font **)(v5 + 128);
        v37 = 8;
        Font::blitString(v22, pos.x + 127.0, (float)((float)(v32 * 0.5) + pos.y) + 60.0, v21, 1.3, eAlignLeft);
        v37 = -1;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        ++HIDWORD(v5);
        v16.m128_f32[0] = FLOAT_8388608_0;
      }
      while ( SHIDWORD(v5) < *(_DWORD *)(*(_DWORD *)(v5 + 344) + 3388) );
    }
  }
}
void SetupGearManager::resetToDefaultValues(SetupGearManager *this)
{
  ksgui::Spinner *v2; // ecx
  unsigned int i; // edi
  ksgui::Spinner *v4; // ecx

  v2 = this->gearSetSpinner;
  if ( v2 && !v2->isReadOnly )
    ksgui::Spinner::setValue(v2, 0);
  for ( i = 0; i < this->spinners._Mylast - this->spinners._Myfirst; ++i )
  {
    v4 = this->spinners._Myfirst[i];
    if ( !v4->isReadOnly )
      ksgui::Spinner::setValue(v4, this->defaultValues._Myfirst[i]);
  }
  this->modifiedValues = 0;
}
