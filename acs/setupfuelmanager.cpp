#include "setupfuelmanager.h"
void SetupFuelManager::SetupFuelManager(SetupFuelManager *this, CarAvatar *aCar)
{
  char v3; // bl
  Font *v4; // edi
  ksgui::Spinner *v5; // eax
  const std::wstring *v6; // eax
  RaceEngineer *v7; // ecx
  Car *v8; // eax
  ksgui::Spinner *v9; // ecx
  Event<ksgui::OnSpinnerValueChanged> *v10; // ecx
  Font *v11; // eax
  Font *v12; // eax
  std::_Ref_count_base *v13; // edi
  Font *v14; // edi
  ksgui::Label *v15; // eax
  ksgui::Label *v16; // ecx
  ksgui::Label_vtbl *v17; // eax
  ksgui::Label *v18; // eax
  ksgui::Label *v19; // eax
  ksgui::Label *v20; // ecx
  Font *v21; // edi
  ksgui::Label *v22; // eax
  ksgui::Label *v23; // ecx
  ksgui::Label_vtbl *v24; // eax
  ksgui::Label *v25; // eax
  ksgui::Label *v26; // eax
  ksgui::Label *v27; // ecx
  Font *v28; // edi
  ksgui::Label *v29; // eax
  ksgui::Label *v30; // ecx
  ksgui::Label_vtbl *v31; // eax
  ksgui::Label *v32; // eax
  ksgui::Label *v33; // eax
  ksgui::Label *v34; // ecx
  Font *v35; // edi
  ksgui::Label *v36; // eax
  ksgui::Label *v37; // ecx
  ksgui::Label_vtbl *v38; // eax
  ksgui::Label *v39; // eax
  ksgui::Label *v40; // eax
  ksgui::Label *v41; // ecx
  Font *v42; // edi
  ksgui::Label *v43; // eax
  ksgui::Label *v44; // ecx
  ksgui::Label_vtbl *v45; // eax
  ksgui::Label *v46; // eax
  ksgui::Label *v47; // eax
  ksgui::Label *v48; // ecx
  Font *v49; // eax
  Font *v50; // eax
  std::_Ref_count_base *v51; // edi
  _BYTE v52[28]; // [esp+30h] [ebp-84h] BYREF
  float h; // [esp+4Ch] [ebp-68h]
  std::shared_ptr<Font> _Right; // [esp+64h] [ebp-50h] BYREF
  int v55; // [esp+6Ch] [ebp-48h]
  SetupFuelManager *v56; // [esp+70h] [ebp-44h]
  std::wstring text; // [esp+74h] [ebp-40h] BYREF
  std::wstring result; // [esp+8Ch] [ebp-28h] BYREF
  int v59; // [esp+B0h] [ebp-4h]

  v3 = 0;
  v56 = this;
  v55 = 0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"FUEL", 4u);
  h = *(float *)&aCar->sim;
  v59 = 0;
  *(_DWORD *)&v52[24] = *(_DWORD *)(*(_DWORD *)(LODWORD(h) + 4) + 252);
  acTranslate((std::wstring *)v52, &text);
  SetupTab::SetupTab(this, *(std::wstring *)v52, *(ksgui::GUI **)&v52[24], (Sim *)LODWORD(h));
  LOBYTE(v59) = 2;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->__vftable = (SetupFuelManager_vtbl *)&SetupFuelManager::`vftable';
  this->car = aCar;
  this->defaultValue = 0;
  this->raceDurationMinutes = -1;
  this->raceIsTimed = 0;
  h = 0.0;
  this->raceText._Myres = 7;
  this->raceText._Mysize = 0;
  *(_DWORD *)&v52[24] = word_17BE9D8;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  this->raceText._Bx._Buf[0] = 0;
  std::wstring::assign(&this->raceText, *(const wchar_t **)&v52[24], LODWORD(h));
  LOBYTE(v59) = 3;
  this->pitTitle = 0;
  this->pitStartTitle = 0;
  this->pitStartValue = 0;
  h = 400.0;
  this->pitEndTitle = 0;
  this->pitEndValue = 0;
  ksgui::Control::setSize(this, 450.0, h);
  v4 = (Font *)operator new(444);
  _Right._Ptr = v4;
  v5 = 0;
  LOBYTE(v59) = 4;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Liters", 6u);
    LOBYTE(v59) = 5;
    v55 = 1;
    v6 = acTranslate(&result, &text);
    h = 0.0;
    *(_DWORD *)&v52[24] = 1;
    *(_DWORD *)&v52[20] = this->gui;
    v3 = 3;
    v59 = 6;
    v55 = 3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v4, v6, *(ksgui::GUI **)&v52[20], 1, 0);
  }
  this->fuelSpinner = v5;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v59 = 3;
  if ( (v3 & 1) != 0 && text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->fuelSpinner->minValue = 0;
  this->fuelSpinner->maxValue = (int)this->car->physicsInfo.maxFuel;
  this->fuelSpinner->step = 1;
  v7 = this->car->raceEngineer._Myptr;
  if ( v7 && RaceEngineer::getCar(v7) )
  {
    v8 = RaceEngineer::getCar(this->car->raceEngineer._Myptr);
    v9 = this->fuelSpinner;
    LODWORD(h) = (int)v8->requestedFuel;
    *(float *)&this->defaultValue = h;
    ksgui::Spinner::setValue(v9, SLODWORD(h));
    LODWORD(h) = this;
    *(_DWORD *)&v52[4] = &std::_Func_impl<std::_Callable_obj<_lambda_07dab914dc7d209f6d70749e1cdf3c57_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v52[8] = this;
    *(_DWORD *)&v52[20] = &v52[4];
    v10 = &this->fuelSpinner->evOnValueChanged;
    LOBYTE(v59) = 3;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)v10,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v52[4],
      this);
  }
  ksgui::Spinner::setDrawArrows(this->fuelSpinner, 1);
  ((void (*)(ksgui::Spinner *, int, int))this->fuelSpinner->setSize)(
    this->fuelSpinner,
    1127743488,
    1101529088);
  v11 = (Font *)operator new(24);
  _Right._Ptr = v11;
  LOBYTE(v59) = 10;
  if ( v11 )
    Font::Font(v11, eFontProportional, 12.0, 0, 0);
  else
    v12 = 0;
  LOBYTE(v59) = 3;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v12);
  std::shared_ptr<Font>::operator=(&this->fuelSpinner->font, &_Right);
  v13 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v13->_Destroy(v13);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v13->_Weaks, 0xFFFFFFFF) )
        v13->_Delete_this(v13);
    }
  }
  ksgui::Spinner::setPosition(
    this->fuelSpinner,
    (float)((float)(this->rect.right - this->rect.left) * 0.5)
  - (float)((float)(this->fuelSpinner->rect.right - this->fuelSpinner->rect.left) * 0.5),
    100.0);
  ksgui::Control::addControl(this, this->fuelSpinner);
  v14 = (Font *)operator new(284);
  _Right._Ptr = v14;
  LOBYTE(v59) = 11;
  if ( v14 )
  {
    h = *(float *)&this->sim->game->gui;
    *(_DWORD *)&v52[24] = 7;
    *(_DWORD *)&v52[20] = 0;
    *(_WORD *)&v52[4] = 0;
    std::wstring::assign((std::wstring *)&v52[4], L"SETUP_FUEL_MANAGER_PIT_TITLE", 0x1Cu);
    ksgui::Label::Label((ksgui::Label *)v14, *(std::wstring *)&v52[4], (ksgui::GUI *)LODWORD(h));
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  this->pitTitle = v16;
  v17 = v16->__vftable;
  LOBYTE(v59) = 3;
  ((void (*)(ksgui::Label *, int, int))v17->setSize)(v16, 1133379584, 1101529088);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->pitTitle,
    (float)((float)(this->rect.right - this->rect.left) * 0.5)
  - (float)((float)(this->pitTitle->rect.right - this->pitTitle->rect.left) * 0.5),
    258.0);
  v18 = this->pitTitle;
  LODWORD(h) = 10;
  *(_DWORD *)&v52[24] = L"PIT WINDOW";
  v18->foreColor = (vec4f)_xmm;
  v19 = this->pitTitle;
  text._Myres = 7;
  text._Mysize = 0;
  v19->fontAlign = eAlignCenter;
  this->pitTitle->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&colTitleBar_10);
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v52[24], LODWORD(h));
  LOBYTE(v59) = 12;
  LODWORD(h) = acTranslate(&result, &text);
  v20 = this->pitTitle;
  LOBYTE(v59) = 13;
  v20->setText(v20, (const std::wstring *)LODWORD(h));
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v59) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->pitTitle);
  v21 = (Font *)operator new(284);
  _Right._Ptr = v21;
  LOBYTE(v59) = 14;
  if ( v21 )
  {
    h = *(float *)&this->sim->game->gui;
    *(_DWORD *)&v52[24] = 7;
    *(_DWORD *)&v52[20] = 0;
    *(_WORD *)&v52[4] = 0;
    std::wstring::assign((std::wstring *)&v52[4], L"SETUP_FUEL_MANAGER_PITSTART_TITLE", 0x21u);
    ksgui::Label::Label((ksgui::Label *)v21, *(std::wstring *)&v52[4], (ksgui::GUI *)LODWORD(h));
    v23 = v22;
  }
  else
  {
    v23 = 0;
  }
  this->pitStartTitle = v23;
  v24 = v23->__vftable;
  LOBYTE(v59) = 3;
  ((void (*)(ksgui::Label *, int, int))v24->setSize)(v23, 1115684864, 1101529088);
  ksgui::Form::setPosition((ksgui::Form *)this->pitStartTitle, this->pitTitle->rect.left, 280.0);
  v25 = this->pitStartTitle;
  LODWORD(h) = 4;
  *(_DWORD *)&v52[24] = L"OPEN";
  v25->fontAlign = eAlignCenter;
  v26 = this->pitStartTitle;
  text._Myres = 7;
  text._Mysize = 0;
  v26->foreColor = (vec4f)_xmm;
  this->pitStartTitle->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&colTitleBar_10);
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v52[24], LODWORD(h));
  LOBYTE(v59) = 15;
  LODWORD(h) = acTranslate(&result, &text);
  v27 = this->pitStartTitle;
  LOBYTE(v59) = 16;
  v27->setText(v27, (const std::wstring *)LODWORD(h));
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v59) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->pitStartTitle);
  v28 = (Font *)operator new(284);
  _Right._Ptr = v28;
  LOBYTE(v59) = 17;
  if ( v28 )
  {
    h = *(float *)&this->sim->game->gui;
    *(_DWORD *)&v52[24] = 7;
    *(_DWORD *)&v52[20] = 0;
    *(_WORD *)&v52[4] = 0;
    std::wstring::assign((std::wstring *)&v52[4], L"SETUP_FUEL_MANAGER_PITSTART_VALUE", 0x21u);
    ksgui::Label::Label((ksgui::Label *)v28, *(std::wstring *)&v52[4], (ksgui::GUI *)LODWORD(h));
    v30 = v29;
  }
  else
  {
    v30 = 0;
  }
  this->pitStartValue = v30;
  v31 = v30->__vftable;
  LOBYTE(v59) = 3;
  ((void (*)(ksgui::Label *, int, int))v31->setSize)(v30, 1130102784, 1101529088);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->pitStartValue,
    (float)(this->pitStartTitle->rect.right - this->pitStartTitle->rect.left) + this->pitStartTitle->rect.left,
    280.0);
  v32 = this->pitStartValue;
  LODWORD(h) = 9;
  *(_DWORD *)&v52[24] = L"Minute 35";
  v32->fontAlign = eAlignCenter;
  v33 = this->pitStartValue;
  text._Myres = 7;
  text._Mysize = 0;
  v33->foreColor = (vec4f)_xmm;
  this->pitStartValue->backColor = (vec4f)_xmm;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v52[24], LODWORD(h));
  v34 = this->pitStartValue;
  LOBYTE(v59) = 18;
  v34->setText(v34, &text);
  LOBYTE(v59) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->pitStartValue);
  v35 = (Font *)operator new(284);
  _Right._Ptr = v35;
  LOBYTE(v59) = 19;
  if ( v35 )
  {
    h = *(float *)&this->sim->game->gui;
    *(_DWORD *)&v52[24] = 7;
    *(_DWORD *)&v52[20] = 0;
    *(_WORD *)&v52[4] = 0;
    std::wstring::assign((std::wstring *)&v52[4], L"SETUP_FUEL_MANAGER_PITEND_TITLE", 0x1Fu);
    ksgui::Label::Label((ksgui::Label *)v35, *(std::wstring *)&v52[4], (ksgui::GUI *)LODWORD(h));
    v37 = v36;
  }
  else
  {
    v37 = 0;
  }
  this->pitEndTitle = v37;
  v38 = v37->__vftable;
  LOBYTE(v59) = 3;
  ((void (*)(ksgui::Label *, int, int))v38->setSize)(v37, 1115684864, 1101529088);
  ksgui::Form::setPosition((ksgui::Form *)this->pitEndTitle, this->pitTitle->rect.left, 302.0);
  v39 = this->pitEndTitle;
  LODWORD(h) = 5;
  *(_DWORD *)&v52[24] = L"CLOSE";
  v39->fontAlign = eAlignCenter;
  v40 = this->pitEndTitle;
  text._Myres = 7;
  text._Mysize = 0;
  v40->foreColor = (vec4f)_xmm;
  this->pitEndTitle->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&colTitleBar_10);
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v52[24], LODWORD(h));
  LOBYTE(v59) = 20;
  LODWORD(h) = acTranslate(&result, &text);
  v41 = this->pitEndTitle;
  LOBYTE(v59) = 21;
  v41->setText(v41, (const std::wstring *)LODWORD(h));
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v59) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->pitEndTitle);
  v42 = (Font *)operator new(284);
  _Right._Ptr = v42;
  LOBYTE(v59) = 22;
  if ( v42 )
  {
    h = *(float *)&this->sim->game->gui;
    *(_DWORD *)&v52[24] = 7;
    *(_DWORD *)&v52[20] = 0;
    *(_WORD *)&v52[4] = 0;
    std::wstring::assign((std::wstring *)&v52[4], L"SETUP_FUEL_MANAGER_PITEND_VALUE", 0x1Fu);
    ksgui::Label::Label((ksgui::Label *)v42, *(std::wstring *)&v52[4], (ksgui::GUI *)LODWORD(h));
    v44 = v43;
  }
  else
  {
    v44 = 0;
  }
  this->pitEndValue = v44;
  v45 = v44->__vftable;
  LOBYTE(v59) = 3;
  ((void (*)(ksgui::Label *, int, int))v45->setSize)(v44, 1130102784, 1101529088);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->pitEndValue,
    (float)(this->pitEndTitle->rect.right - this->pitEndTitle->rect.left) + this->pitEndTitle->rect.left,
    302.0);
  v46 = this->pitEndValue;
  LODWORD(h) = 9;
  *(_DWORD *)&v52[24] = L"Minute 45";
  v46->fontAlign = eAlignCenter;
  v47 = this->pitEndValue;
  text._Myres = 7;
  text._Mysize = 0;
  v47->foreColor = (vec4f)_xmm;
  this->pitEndValue->backColor = (vec4f)_xmm;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v52[24], LODWORD(h));
  v48 = this->pitEndValue;
  LOBYTE(v59) = 23;
  v48->setText(v48, &text);
  LOBYTE(v59) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->pitEndValue);
  v49 = (Font *)operator new(24);
  _Right._Ptr = v49;
  LOBYTE(v59) = 24;
  if ( v49 )
    Font::Font(v49, eFontProportional, 18.0, 0, 0);
  else
    v50 = 0;
  LOBYTE(v59) = 3;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v50);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v51 = _Right._Rep;
  if ( _Right._Rep && !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
  {
    v51->_Destroy(v51);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v51->_Weaks) )
      ((void (*)(void))v51->_Delete_this)();
  }
}
SetupFuelManager *SetupFuelManager::`vector deleting destructor'(SetupFuelManager *this, unsigned int a2)
{
  this->__vftable = (SetupFuelManager_vtbl *)&SetupFuelManager::`vftable';
  if ( this->raceText._Myres >= 8 )
    operator delete(this->raceText._Bx._Ptr);
  this->raceText._Myres = 7;
  this->raceText._Mysize = 0;
  this->raceText._Bx._Buf[0] = 0;
  SetupTab::~SetupTab(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double SetupFuelManager::getSetupFuel(SetupFuelManager *this)
{
  return (double)ksgui::Spinner::getValue(this->fuelSpinner);
}
std::wstring *SetupFuelManager::getStringToSave(SetupFuelManager *this, std::wstring *result)
{
  std::wostream *v3; // eax
  std::wostream *v4; // eax
  int v5; // eax
  std::wstring *v6; // esi
  std::wstring *v7; // eax
  int v9; // [esp-4h] [ebp-10Ch]
  int v10; // [esp+14h] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v11; // [esp+18h] [ebp-F0h] BYREF
  std::wstring v12; // [esp+C8h] [ebp-40h] BYREF
  std::wstring v13; // [esp+E0h] [ebp-28h] BYREF
  int v14; // [esp+104h] [ebp-4h]

  *(_DWORD *)v11.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v11.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v11.gap68);
  v14 = 0;
  v10 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v11, &v11.gap10[8], 0);
  v14 = 1;
  *(_DWORD *)&v11.gap0[*(_DWORD *)(*(_DWORD *)v11.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v10 + *(_DWORD *)(*(_DWORD *)v11.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v11.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v11.gap10[8]);
  *(_DWORD *)&v11.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v11.gap10[64] = 0;
  *(_DWORD *)&v11.gap10[68] = 0;
  v14 = 3;
  v3 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v11.gap10, "[FUEL]");
  std::wostream::operator<<(v3);
  v9 = ksgui::Spinner::getValue(this->fuelSpinner);
  v4 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v11.gap10, "VALUE=");
  v5 = std::wostream::operator<<(v4, v9);
  std::wostream::operator<<(v5);
  v6 = SetupTab::getStringToSave(this, &v13);
  LOBYTE(v14) = 4;
  v7 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v11, &v12);
  LOBYTE(v14) = 5;
  std::operator+<wchar_t>(result, v7, v6);
  if ( v12._Myres >= 8 )
    operator delete(v12._Bx._Ptr);
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  v13._Myres = 7;
  v13._Bx._Buf[0] = 0;
  v13._Mysize = 0;
  v14 = -1;
  *(_DWORD *)&v11.gap0[*(_DWORD *)(*(_DWORD *)v11.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v10 + *(_DWORD *)(*(_DWORD *)v11.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v11.gap0 + 4) - 104;
  *(_DWORD *)&v11.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v11.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v11.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v11.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v11.gap68);
  return result;
}
bool SetupFuelManager::isFixedFuel(SetupFuelManager *this)
{
  return this->fuelSpinner->isReadOnly;
}
void SetupFuelManager::loadFromINI(SetupFuelManager *this, INIReader *ini, bool isFixed)
{
  bool v4; // al
  int v5; // ebp
  ksgui::Spinner *v6; // [esp-Ch] [ebp-78h]
  bool v7; // [esp+13h] [ebp-59h]
  std::wstring v8; // [esp+14h] [ebp-58h] BYREF
  std::wstring key; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring section; // [esp+44h] [ebp-28h] BYREF
  int v11; // [esp+68h] [ebp-4h]

  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FUEL", 4u);
  v11 = 0;
  v4 = INIReader::hasSection(ini, &section);
  v7 = v4;
  v11 = -1;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v4 = v7;
  }
  if ( v4 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"VALUE", 5u);
    v11 = 1;
    v8._Myres = 7;
    v8._Mysize = 0;
    v8._Bx._Buf[0] = 0;
    std::wstring::assign(&v8, L"FUEL", 4u);
    LOBYTE(v11) = 2;
    v5 = INIReader::getInt(ini, &v8, &key);
    if ( v8._Myres >= 8 )
      operator delete(v8._Bx._Ptr);
    v8._Myres = 7;
    v8._Mysize = 0;
    v8._Bx._Buf[0] = 0;
    v11 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    v6 = this->fuelSpinner;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    SetupTab::setValueToSpinner(this, v6, isFixed, v5);
  }
  else
  {
    this->fuelSpinner->isReadOnly = 0;
  }
  SetupTab::loadFromINI(this, ini, isFixed);
}
void SetupFuelManager::onVisibleChanged(SetupFuelManager *this, bool value)
{
  RaceEngineer *v3; // ecx
  Car *v4; // eax

  v3 = this->car->raceEngineer._Myptr;
  if ( v3 )
  {
    if ( RaceEngineer::getCar(v3) )
    {
      v4 = RaceEngineer::getCar(this->car->raceEngineer._Myptr);
      ksgui::Spinner::setValue(this->fuelSpinner, (int)v4->requestedFuel);
    }
  }
}
void __userpurge SetupFuelManager::render(SetupFuelManager *this@<ecx>, __int64 a2@<esi:edi>, float dt)
{
  int v3; // eax
  int v4; // ebx
  Car *v5; // eax
  const std::wstring *v6; // eax
  int v7; // ecx
  __m128 v8; // xmm1
  float v9; // xmm4_4
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  float v12; // xmm2_4
  ksgui::Spinner *v13; // ecx
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  int v16; // ecx
  const std::wstring *v17; // eax
  float v18; // xmm1_4
  Font *v19; // ecx
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  const std::wstring *v22; // eax
  float v23; // xmm1_4
  Font *v24; // ecx
  int v25; // ecx
  bool v26; // al
  std::wstring *v27; // esi
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  std::wstring *v31; // esi
  std::wstring *v32; // eax
  std::wstring *v33; // eax
  std::wstring *v34; // ebx
  unsigned __int16 v35; // ax
  std::wstring *v36; // eax
  std::wstring *v37; // eax
  int v38; // ecx
  unsigned __int16 v39; // ax
  std::wstring *v40; // eax
  std::wstring *v41; // eax
  int v42; // ecx
  int v43; // ecx
  unsigned __int16 v44; // ax
  std::wstring *v45; // eax
  std::wstring *v46; // eax
  std::wstring *v47; // eax
  int v48; // ecx
  int v49; // ecx
  unsigned __int16 v50; // ax
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  int v54; // ecx
  CarAvatar *v55; // [esp+20h] [ebp-1C8h]
  float value; // [esp+38h] [ebp-1B0h]
  float fuelSperimental; // [esp+3Ch] [ebp-1ACh]
  ksgui::ksRect aRect; // [esp+40h] [ebp-1A8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+50h] [ebp-198h] BYREF
  std::wstring text; // [esp+100h] [ebp-E8h] BYREF
  std::wstring v61; // [esp+118h] [ebp-D0h] BYREF
  std::wstring result; // [esp+130h] [ebp-B8h] BYREF
  std::wstring v63; // [esp+148h] [ebp-A0h] BYREF
  std::wstring v64; // [esp+160h] [ebp-88h] BYREF
  Session sessionInfo; // [esp+178h] [ebp-70h] BYREF
  int v66; // [esp+1E4h] [ebp-4h]

  LODWORD(a2) = this;
  SetupTab::render(this, a2, dt);
  *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(ws.gap68);
  v66 = 0;
  std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
  v66 = 1;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&aRect.bottom + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&ws.gap10[8]);
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&ws.gap10[64] = 0;
  *(_DWORD *)&ws.gap10[68] = 0;
  v3 = *(_DWORD *)(a2 + 316);
  v4 = 0;
  v66 = 3;
  v5 = RaceEngineer::getCar(*(RaceEngineer **)(v3 + 3672));
  fuelSperimental = FuelLapEvaluator::getFuelPerLap(&v5->fuelLapEvaluator);
  if ( fuelSperimental > 0.0 )
  {
    RaceManager::getCurrentSession(*(RaceManager **)(*(_DWORD *)(a2 + 312) + 224), &sessionInfo);
    v7 = *(_DWORD *)(a2 + 312);
    v55 = *(CarAvatar **)(a2 + 316);
    LOBYTE(v66) = 6;
    HIDWORD(a2) = RaceManager::getLapCount(*(RaceManager **)(v7 + 224), v55);
    if ( HIDWORD(a2) )
    {
      value = (float)RaceManager::getSessionTotalTime(*(RaceManager **)(*(_DWORD *)(a2 + 312) + 224), 0)
            / (float)((float)HIDWORD(a2) + *(float *)(*(_DWORD *)(a2 + 316) + 2200));
      v8.m128_f32[0] = FLOAT_8388608_0;
      v9 = (float)((float)((float)ksgui::Spinner::getValue(*(ksgui::Spinner **)(a2 + 320)) * 10.0) / fuelSperimental)
         * value;
      v10.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v9);
      v11.m128_i32[0] = LODWORD(v9) ^ LODWORD(FLOAT_N0_0) & LODWORD(v9);
      v11.m128_f32[0] = _mm_cmplt_ss(v11, v8).m128_f32[0];
      v12 = (float)(v9 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v11.m128_i32[0] | v10.m128_i32[0]))
          - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v11.m128_i32[0] | v10.m128_i32[0]);
      v11.m128_f32[0] = v12 - v9;
      v4 = (int)(float)((float)(v12 - COERCE_FLOAT(_mm_cmpgt_ss(v11, v10).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.1);
    }
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Estimated laps", 0xEu);
    LOBYTE(v66) = 7;
    HIDWORD(a2) = acTranslate(&result, &text);
    v13 = *(ksgui::Spinner **)(a2 + 320);
    LOBYTE(v66) = 8;
    ksgui::Spinner::getValue(v13);
    v14 = std::operator<<<wchar_t>((std::wostream *)ws.gap10, (const std::wstring *)HIDWORD(a2));
    v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v14, " : ");
    std::wostream::operator<<(v15);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    LOBYTE(v66) = 3;
    if ( sessionInfo.name._Myres >= 8 )
      operator delete(sessionInfo.name._Bx._Ptr);
    sessionInfo.name._Myres = 7;
    sessionInfo.name._Mysize = 0;
    sessionInfo.name._Bx._Buf[0] = 0;
    if ( sessionInfo.spawSet._Myres >= 8 )
      operator delete(sessionInfo.spawSet._Bx._Ptr);
  }
  else
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"To estimate fuel quantity complete at least two laps", 0x34u);
    LOBYTE(v66) = 4;
    v6 = acTranslate(&result, &text);
    LOBYTE(v66) = 5;
    std::operator<<<wchar_t>((std::wostream *)ws.gap10, v6);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v66) = 3;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  ksgui::Control::setVisible(*(ksgui::Control **)(a2 + 360), 0);
  v16 = *(_DWORD *)(a2 + 320);
  aRect.left = 0.0;
  aRect.top = 0.0;
  aRect.right = 1.0;
  aRect.bottom = 1.0;
  (*(void (**)(int, ksgui::ksRect *))(*(_DWORD *)v16 + 24))(v16, &aRect);
  v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ws, &v61);
  v18 = *(float *)(*(_DWORD *)(a2 + 320) + 32) - *(float *)(*(_DWORD *)(a2 + 320) + 28);
  v19 = *(Font **)(a2 + 128);
  LOBYTE(v66) = 9;
  Font::blitString(v19, (float)(v18 * 0.5) + (float)(aRect.left + 140.0), 200.0, v17, 1.0, eAlignCenter);
  LOBYTE(v66) = 3;
  if ( v61._Myres >= 8 )
    operator delete(v61._Bx._Ptr);
  if ( v4 > 0 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Estimated time", 0xEu);
    LOBYTE(v66) = 10;
    HIDWORD(a2) = timeToWString(&v61, v4, 0, 0);
    LOBYTE(v66) = 11;
    v20 = acTranslate(&v63, &text);
    LOBYTE(v66) = 12;
    v21 = std::operator+<wchar_t>(&v64, v20, L" : ");
    LOBYTE(v66) = 13;
    v22 = std::operator+<wchar_t>(&result, v21, (std::wstring *)HIDWORD(a2));
    v23 = *(float *)(*(_DWORD *)(a2 + 320) + 32) - *(float *)(*(_DWORD *)(a2 + 320) + 28);
    v24 = *(Font **)(a2 + 128);
    LOBYTE(v66) = 14;
    Font::blitString(v24, (float)(v23 * 0.5) + (float)(aRect.left + 140.0), 230.0, v22, 1.0, eAlignCenter);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v64._Myres >= 8 )
      operator delete(v64._Bx._Ptr);
    v64._Myres = 7;
    v64._Mysize = 0;
    v64._Bx._Buf[0] = 0;
    if ( v63._Myres >= 8 )
      operator delete(v63._Bx._Ptr);
    v63._Myres = 7;
    v63._Mysize = 0;
    v63._Bx._Buf[0] = 0;
    if ( v61._Myres >= 8 )
      operator delete(v61._Bx._Ptr);
    v61._Myres = 7;
    v61._Mysize = 0;
    v61._Bx._Buf[0] = 0;
    LOBYTE(v66) = 3;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  if ( *(_DWORD *)(a2 + 328) == -1 )
  {
    HIDWORD(a2) = 0;
    if ( RaceManager::getSessionCount(*(RaceManager **)(*(_DWORD *)(a2 + 312) + 224)) )
    {
      while ( 1 )
      {
        v25 = *(_DWORD *)(a2 + 312);
        *(_DWORD *)(a2 + 328) = 0;
        *(_BYTE *)(a2 + 332) = 0;
        RaceManager::getSessionInfo(*(RaceManager **)(v25 + 224), &sessionInfo, SHIDWORD(a2));
        LOBYTE(v66) = 15;
        if ( sessionInfo.sessionType == Race )
          break;
        LOBYTE(v66) = 3;
        if ( sessionInfo.name._Myres >= 8 )
          operator delete(sessionInfo.name._Bx._Ptr);
        sessionInfo.name._Myres = 7;
        sessionInfo.name._Mysize = 0;
        sessionInfo.name._Bx._Buf[0] = 0;
        if ( sessionInfo.spawSet._Myres >= 8 )
          operator delete(sessionInfo.spawSet._Bx._Ptr);
        ++HIDWORD(a2);
        if ( HIDWORD(a2) >= RaceManager::getSessionCount(*(RaceManager **)(*(_DWORD *)(a2 + 312) + 224)) )
          goto LABEL_59;
      }
      text._Myres = 7;
      text._Mysize = 0;
      *(_DWORD *)(a2 + 328) = (int)sessionInfo.durationMinutes;
      v26 = sessionInfo.isTimedRace;
      *(_BYTE *)(a2 + 332) = sessionInfo.isTimedRace;
      text._Bx._Buf[0] = 0;
      if ( v26 )
      {
        std::wstring::assign(&text, L"Race Time", 9u);
        LOBYTE(v66) = 16;
        v27 = timeToWString(&result, (int)(float)((float)(sessionInfo.durationMinutes * 60.0) * 1000.0), 0, 0);
        LOBYTE(v66) = 17;
        v28 = acTranslate(&v64, &text);
        LOBYTE(v66) = 18;
        v29 = std::operator+<wchar_t>(&v63, v28, L" ");
        LOBYTE(v66) = 19;
        v30 = std::operator+<wchar_t>(&v61, v29, v27);
      }
      else
      {
        std::wstring::assign(&text, L"Race Laps", 9u);
        LOBYTE(v66) = 20;
        v31 = std::to_wstring(&result, sessionInfo.laps);
        LOBYTE(v66) = 21;
        v32 = acTranslate(&v64, &text);
        LOBYTE(v66) = 22;
        v33 = std::operator+<wchar_t>(&v63, v32, L" ");
        LOBYTE(v66) = 23;
        v30 = std::operator+<wchar_t>(&v61, v33, v31);
      }
      v34 = v30;
      HIDWORD(a2) = a2 + 336;
      if ( (std::wstring *)(a2 + 336) != v30 )
      {
        if ( *(_DWORD *)(a2 + 356) >= 8u )
          operator delete(*(_DWORD *)HIDWORD(a2));
        *(_DWORD *)(a2 + 356) = 7;
        *(_DWORD *)(a2 + 352) = 0;
        *(_WORD *)HIDWORD(a2) = 0;
        std::wstring::_Assign_rv((std::wstring *)(a2 + 336), v34);
      }
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      v61._Myres = 7;
      v61._Bx._Buf[0] = 0;
      v61._Mysize = 0;
      if ( v63._Myres >= 8 )
        operator delete(v63._Bx._Ptr);
      v63._Myres = 7;
      v63._Bx._Buf[0] = 0;
      v63._Mysize = 0;
      if ( v64._Myres >= 8 )
        operator delete(v64._Bx._Ptr);
      v64._Myres = 7;
      v64._Bx._Buf[0] = 0;
      v64._Mysize = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      LOBYTE(v66) = 3;
      if ( sessionInfo.name._Myres >= 8 )
        operator delete(sessionInfo.name._Bx._Ptr);
      sessionInfo.name._Myres = 7;
      sessionInfo.name._Mysize = 0;
      sessionInfo.name._Bx._Buf[0] = 0;
      if ( sessionInfo.spawSet._Myres >= 8 )
        operator delete(sessionInfo.spawSet._Bx._Ptr);
    }
  }
LABEL_59:
  Font::blitString(
    *(Font **)(a2 + 128),
    (float)((float)(*(float *)(*(_DWORD *)(a2 + 320) + 32) - *(float *)(*(_DWORD *)(a2 + 320) + 28)) * 0.5)
  + (float)(aRect.left + 140.0),
    260.0,
    (const std::wstring *)(a2 + 336),
    1.0,
    eAlignCenter);
  if ( RaceManager::getPitWindowEnd(*(RaceManager **)(*(_DWORD *)(a2 + 312) + 224)) )
  {
    ksgui::Control::setVisible(*(ksgui::Control **)(a2 + 360), 1);
    if ( *(_BYTE *)(a2 + 332) )
    {
      v35 = RaceManager::getPitWindowStart(*(RaceManager **)(*(_DWORD *)(a2 + 312) + 224));
      v36 = std::to_wstring(&v63, *(_DWORD *)(a2 + 328) - v35);
      LOBYTE(v66) = 24;
      v37 = std::operator+<wchar_t>(&v61, v36, L" minutes left");
      v38 = *(_DWORD *)(a2 + 368);
      LOBYTE(v66) = 25;
      (*(void (**)(int, std::wstring *))(*(_DWORD *)v38 + 68))(v38, v37);
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      v61._Myres = 7;
      v61._Mysize = 0;
      v61._Bx._Buf[0] = 0;
      LOBYTE(v66) = 3;
      if ( v63._Myres >= 8 )
        operator delete(v63._Bx._Ptr);
      v39 = RaceManager::getPitWindowEnd(*(RaceManager **)(*(_DWORD *)(a2 + 312) + 224));
      v40 = std::to_wstring(&v63, *(_DWORD *)(a2 + 328) - v39);
      LOBYTE(v66) = 26;
      v41 = std::operator+<wchar_t>(&v61, v40, L" minutes left");
      v42 = *(_DWORD *)(a2 + 376);
      LOBYTE(v66) = 27;
      (*(void (**)(int, std::wstring *))(*(_DWORD *)v42 + 68))(v42, v41);
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      v61._Myres = 7;
      v61._Mysize = 0;
      v61._Bx._Buf[0] = 0;
      LOBYTE(v66) = 3;
      if ( v63._Myres >= 8 )
        operator delete(v63._Bx._Ptr);
    }
    else
    {
      std::wstring::wstring(&text, L"Lap");
      v43 = *(_DWORD *)(a2 + 312);
      LOBYTE(v66) = 28;
      v44 = RaceManager::getPitWindowStart(*(RaceManager **)(v43 + 224));
      HIDWORD(a2) = std::to_wstring(&result, v44);
      LOBYTE(v66) = 29;
      v45 = acTranslate(&v64, &text);
      LOBYTE(v66) = 30;
      v46 = std::operator+<wchar_t>(&v63, v45, L" ");
      LOBYTE(v66) = 31;
      v47 = std::operator+<wchar_t>(&v61, v46, (std::wstring *)HIDWORD(a2));
      v48 = *(_DWORD *)(a2 + 368);
      LOBYTE(v66) = 32;
      (*(void (**)(int, std::wstring *))(*(_DWORD *)v48 + 68))(v48, v47);
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      v61._Myres = 7;
      v61._Mysize = 0;
      v61._Bx._Buf[0] = 0;
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
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v66) = 3;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      std::wstring::wstring(&text, L"Lap");
      v49 = *(_DWORD *)(a2 + 312);
      LOBYTE(v66) = 33;
      v50 = RaceManager::getPitWindowEnd(*(RaceManager **)(v49 + 224));
      HIDWORD(a2) = std::to_wstring(&result, v50);
      LOBYTE(v66) = 34;
      v51 = acTranslate(&v64, &text);
      LOBYTE(v66) = 35;
      v52 = std::operator+<wchar_t>(&v63, v51, L" ");
      LOBYTE(v66) = 36;
      v53 = std::operator+<wchar_t>(&v61, v52, (std::wstring *)HIDWORD(a2));
      v54 = *(_DWORD *)(a2 + 376);
      LOBYTE(v66) = 37;
      (*(void (**)(int, std::wstring *))(*(_DWORD *)v54 + 68))(v54, v53);
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      v61._Myres = 7;
      v61._Mysize = 0;
      v61._Bx._Buf[0] = 0;
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
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v66) = 3;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      text._Myres = 7;
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
    }
  }
  LOBYTE(value) = *(_BYTE *)(*(_DWORD *)(a2 + 360) + 244);
  ksgui::Control::setVisible(*(ksgui::Control **)(a2 + 364), SLODWORD(value));
  LOBYTE(value) = *(_BYTE *)(*(_DWORD *)(a2 + 360) + 244);
  ksgui::Control::setVisible(*(ksgui::Control **)(a2 + 368), SLODWORD(value));
  LOBYTE(value) = *(_BYTE *)(*(_DWORD *)(a2 + 360) + 244);
  ksgui::Control::setVisible(*(ksgui::Control **)(a2 + 372), SLODWORD(value));
  LOBYTE(value) = *(_BYTE *)(*(_DWORD *)(a2 + 360) + 244);
  ksgui::Control::setVisible(*(ksgui::Control **)(a2 + 376), SLODWORD(value));
  v66 = -1;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&aRect.bottom + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&ws.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ws.gap68);
}
