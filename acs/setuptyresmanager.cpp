#include "setuptyresmanager.h"
void SetupTyresManager::resetToDefaultValues(SetupFuelManager *this)
{
  ksgui::Spinner *v2; // ecx

  v2 = this->fuelSpinner;
  if ( !v2->isReadOnly )
    ksgui::Spinner::setValue(v2, this->defaultValue);
  SetupTab::resetToDefaultValues(this);
}
void SetupTyresManager::SetupTyresManager(SetupTyresManager *this, CarAvatar *aCar)
{
  int v3; // ebx
  ksgui::Spinner *v4; // edi
  ksgui::Spinner *v5; // eax
  const std::wstring *v6; // eax
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  bool v9; // al
  int v10; // eax
  bool v11; // cf
  unsigned int v12; // ebx
  int v13; // edi
  std::wstring *v14; // eax
  int v15; // edi
  std::wstring *v16; // eax
  Event<ksgui::OnSpinnerValueChanged> *v17; // ecx
  _BYTE h[32]; // [esp-10h] [ebp-110h] BYREF
  char v19; // [esp+27h] [ebp-D9h]
  int v20; // [esp+28h] [ebp-D8h]
  ksgui::Spinner *v21; // [esp+2Ch] [ebp-D4h]
  SetupTyresManager *v22; // [esp+30h] [ebp-D0h]
  std::wstring section; // [esp+34h] [ebp-CCh] BYREF
  std::wstring result; // [esp+4Ch] [ebp-B4h] BYREF
  std::wstring text; // [esp+64h] [ebp-9Ch] BYREF
  std::wstring v26; // [esp+7Ch] [ebp-84h] BYREF
  std::wstring item; // [esp+94h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+ACh] [ebp-54h] BYREF
  int v29; // [esp+FCh] [ebp-4h]

  v3 = 0;
  v22 = this;
  v20 = 0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"TYRES", 5u);
  *(_DWORD *)&h[28] = aCar->sim;
  v29 = 0;
  *(_DWORD *)&h[24] = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&h[28] + 4) + 252);
  acTranslate((std::wstring *)h, &text);
  SetupTab::SetupTab(this, *(std::wstring *)h, *(ksgui::GUI **)&h[24], *(Sim **)&h[28]);
  LOBYTE(v29) = 2;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  this->__vftable = (SetupTyresManager_vtbl *)&SetupTyresManager::`vftable';
  *(_DWORD *)&h[28] = 1137180672;
  this->car = aCar;
  this->defaultCompoundIndex = 0;
  ksgui::Control::setSize(this, 450.0, *(float *)&h[28]);
  v4 = (ksgui::Spinner *)operator new(444);
  v21 = v4;
  v5 = 0;
  LOBYTE(v29) = 3;
  if ( v4 )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"Compound", 8u);
    LOBYTE(v29) = 4;
    v20 = 1;
    v6 = acTranslate(&result, &section);
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v3 = 3;
    v29 = 5;
    v20 = 3;
    ksgui::Spinner::Spinner(v4, v6, *(ksgui::GUI **)&h[20], 1, 0);
  }
  this->tyreSpinner = v5;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v29 = 2;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  v7 = std::operator+<wchar_t>(&v26, L"content/cars/", &this->car->unixName);
  LOBYTE(v29) = 8;
  v8 = std::operator+<wchar_t>(&item, v7, L"/data/tyres.ini");
  LOBYTE(v29) = 9;
  INIReader::INIReader(&ini, v8);
  if ( item._Myres >= 8 )
    operator delete(item._Bx._Ptr);
  item._Myres = 7;
  item._Mysize = 0;
  item._Bx._Buf[0] = 0;
  LOBYTE(v29) = 12;
  if ( v26._Myres >= 8 )
    operator delete(v26._Bx._Ptr);
  v26._Myres = 7;
  v26._Mysize = 0;
  v26._Bx._Buf[0] = 0;
  this->defaultCompoundIndex = 0;
  if ( !ini.ready )
    goto LABEL_18;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"COMPOUND_DEFAULT", 0x10u);
  LOBYTE(v29) = 13;
  v3 |= 4u;
  v20 = v3;
  v9 = INIReader::hasSection(&ini, &section);
  v19 = 1;
  if ( !v9 )
LABEL_18:
    v19 = 0;
  v29 = 12;
  if ( (v3 & 4) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v19 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"INDEX", 5u);
    LOBYTE(v29) = 14;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"COMPOUND_DEFAULT", 0x10u);
    LOBYTE(v29) = 15;
    v10 = INIReader::getInt(&ini, &section, &result);
    v11 = section._Myres < 8;
    this->defaultCompoundIndex = v10;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v29) = 12;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v12 = 0;
  if ( this->car->physicsInfo.tyreCompounds._Mylast - this->car->physicsInfo.tyreCompounds._Myfirst )
  {
    v13 = 0;
    do
    {
      v14 = this->car->physicsInfo.tyreCompounds._Myfirst;
      *(_DWORD *)&h[28] = 7;
      *(_DWORD *)&h[24] = 0;
      *(_WORD *)&h[8] = 0;
      std::wstring::assign((std::wstring *)&h[8], &v14[v13], 0, 0xFFFFFFFF);
      ksgui::Spinner::addItem(this->tyreSpinner, *(std::wstring *)&h[8]);
      ++v12;
      ++v13;
    }
    while ( v12 < this->car->physicsInfo.tyreCompounds._Mylast - this->car->physicsInfo.tyreCompounds._Myfirst );
  }
  if ( INIReader::crashAtError )
  {
    v15 = this->defaultCompoundIndex;
    if ( v15 < 0
      || v15 >= (unsigned int)(this->car->physicsInfo.tyreCompounds._Mylast
                             - this->car->physicsInfo.tyreCompounds._Myfirst) )
    {
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"Error COMPOUND_DEFAULT is <0 or > compound size", 0x2Fu);
      v16 = &section;
      LOBYTE(v29) = 16;
      if ( section._Myres >= 8 )
        v16 = (std::wstring *)section._Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v16->_Bx._Buf);
      ksGenerateCrash();
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
  }
  *(_DWORD *)&h[28] = this;
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_6244a6114f3f98b4fe0400fb27f86efc_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  v17 = &this->tyreSpinner->evOnValueChanged;
  LOBYTE(v29) = 12;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v17,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  ksgui::Spinner::setDrawArrows(this->tyreSpinner, 1);
  ((void (*)(ksgui::Spinner *, int, int))this->tyreSpinner->setSize)(
    this->tyreSpinner,
    1135542272,
    1101529088);
  ksgui::Spinner::setPosition(
    this->tyreSpinner,
    (float)((float)(this->rect.right - this->rect.left) * 0.5)
  - (float)((float)(this->tyreSpinner->rect.right - this->tyreSpinner->rect.left) * 0.5),
    100.0);
  ksgui::Control::addControl(this, this->tyreSpinner);
  LOBYTE(v29) = 2;
  INIReader::~INIReader(&ini);
}
SetupTyresManager *SetupTyresManager::`scalar deleting destructor'(SetupTyresManager *this, unsigned int a2)
{
  this->__vftable = (SetupTyresManager_vtbl *)&SetupTyresManager::`vftable';
  SetupTab::~SetupTab(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
std::wstring *SetupTyresManager::getStringToSave(SetupTyresManager *this, std::wstring *result)
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
  v3 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v11.gap10, "[TYRES]");
  std::wostream::operator<<(v3);
  v9 = ksgui::Spinner::getValue(this->tyreSpinner);
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
void SetupTyresManager::loadFromINI(SetupTyresManager *this, INIReader *ini, bool isFixed)
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
  std::wstring::assign(&section, L"TYRES", 5u);
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
    std::wstring::assign(&v8, L"TYRES", 5u);
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
    v6 = this->tyreSpinner;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    SetupTab::setValueToSpinner(this, v6, isFixed, v5);
  }
  else
  {
    this->tyreSpinner->isReadOnly = 0;
  }
  SetupTab::loadFromINI(this, ini, isFixed);
}
