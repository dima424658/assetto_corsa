#include "quickmenupitstop.h"
void QuickMenuPitstop::QuickMenuPitstop(QuickMenuPitstop *this, Sim *isim)
{
  int v3; // ebx
  double v4; // st7
  bool v5; // cf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  const __m128i *v20; // eax
  const __m128i *v21; // eax
  const __m128i *v22; // eax
  const __m128i *v23; // eax
  const __m128i *v24; // eax
  const __m128i *v25; // eax
  int v26; // eax
  int v27; // eax
  wchar_t *v28; // esi
  int v29; // eax
  Font *v30; // eax
  volatile signed __int32 *v31; // esi
  wchar_t *v32; // esi
  int v33; // eax
  Font *v34; // eax
  volatile signed __int32 *v35; // esi
  std::wstring v36; // [esp-10h] [ebp-D4h] BYREF
  Game *v37; // [esp+8h] [ebp-BCh]
  int v38; // [esp+20h] [ebp-A4h]
  QuickMenuPitstop *v39; // [esp+24h] [ebp-A0h]
  std::wstring ifilename; // [esp+28h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+40h] [ebp-84h] BYREF
  std::wstring sect; // [esp+58h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+70h] [ebp-54h] BYREF
  int v44; // [esp+C0h] [ebp-4h]

  v3 = 0;
  v38 = 0;
  v39 = this;
  v37 = isim->game;
  v36._Myres = 7;
  v36._Mysize = 0;
  v36._Bx._Buf[0] = 0;
  std::wstring::assign(&v36, L"QUICK_MENU_PITSTOP", 0x12u);
  GameObject::GameObject(this, v36, v37);
  this->__vftable = (QuickMenuPitstop_vtbl *)&QuickMenuPitstop::`vftable';
  v44 = 0;
  this->items._Myfirst = 0;
  this->items._Mylast = 0;
  this->items._Myend = 0;
  this->STAY_IN_CAR = 0;
  this->pitstopPresets._Myfirst = 0;
  this->pitstopPresets._Mylast = 0;
  this->pitstopPresets._Myend = 0;
  this->sim = isim;
  this->root = 0;
  this->presetHeader = 0;
  this->presets._Myfirst = 0;
  this->presets._Mylast = 0;
  this->presets._Myend = 0;
  this->font._Ptr = 0;
  this->font._Rep = 0;
  this->headerFont._Ptr = 0;
  this->headerFont._Rep = 0;
  this->timer = 0.0;
  this->isVisible = 0;
  this->fuelIndex = 0;
  this->currentIndex = 0;
  this->currentPreset = 0;
  this->VISIBILITY_MAX_TIME = 3.0;
  this->PRESETS_COUNT = 3;
  this->AUTO_APP_ON_PITLANE = 0;
  this->HEADER_HEIGHT = 15.0;
  this->HEADER_FONT = 10.0;
  this->INTERLINE = 1.0;
  this->ITEM_HEIGHT = 20.0;
  this->ITEM_TITLE_WIDTH = 100.0;
  this->ITEM_VALUE_WIDTH = 100.0;
  this->SIZE_MULT = 1.0;
  this->OBJECT_POS_X = 0.0;
  this->OBJECT_POS_Y = 0.0;
  this->FORM_ALIGNMENT_H = 2;
  this->FORM_ALIGNMENT_V = 1;
  this->ITEM_FOREGROUND_UNSELECTED.x = 0.0;
  this->ITEM_FOREGROUND_UNSELECTED.y = 0.0;
  this->ITEM_FOREGROUND_UNSELECTED.z = 0.0;
  this->ITEM_FOREGROUND_UNSELECTED.w = 0.0;
  this->ITEM_BACKGROUND_UNSELECTED.x = 0.0;
  this->ITEM_BACKGROUND_UNSELECTED.y = 0.0;
  this->ITEM_BACKGROUND_UNSELECTED.z = 0.0;
  this->ITEM_BACKGROUND_UNSELECTED.w = 0.0;
  this->ITEM_FOREGROUND_SELECTED.x = 0.0;
  this->ITEM_FOREGROUND_SELECTED.y = 0.0;
  this->ITEM_FOREGROUND_SELECTED.z = 0.0;
  this->ITEM_FOREGROUND_SELECTED.w = 0.0;
  this->ITEM_BACKGROUND_SELECTED.x = 0.0;
  this->ITEM_BACKGROUND_SELECTED.y = 0.0;
  this->ITEM_BACKGROUND_SELECTED.z = 0.0;
  this->ITEM_BACKGROUND_SELECTED.w = 0.0;
  LOBYTE(v44) = 5;
  this->ITEM_FOREGROUND_HEADER.x = 0.0;
  this->ITEM_FOREGROUND_HEADER.y = 0.0;
  this->ITEM_FOREGROUND_HEADER.z = 0.0;
  this->ITEM_FOREGROUND_HEADER.w = 0.0;
  v37 = (Game *)"Loading pitstop.ini\n";
  this->ITEM_BACKGROUND_HEADER.x = 0.0;
  this->ITEM_BACKGROUND_HEADER.y = 0.0;
  this->ITEM_BACKGROUND_HEADER.z = 0.0;
  this->ITEM_BACKGROUND_HEADER.w = 0.0;
  _printf((const char *const)v37);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/pitstop.ini", 0x16u);
  LOBYTE(v44) = 6;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v44) = 8;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&ini, 1);
  if ( ini.ready )
  {
    sect._Myres = 7;
    sect._Mysize = 0;
    sect._Bx._Buf[0] = 0;
    std::wstring::assign(&sect, L"SETTINGS", 8u);
    LOBYTE(v44) = 9;
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"SIZE_MULT", 9u);
    LOBYTE(v44) = 10;
    v4 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    this->SIZE_MULT = v4;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"STAY_IN_CAR", 0xBu);
    LOBYTE(v44) = 11;
    v6 = INIReader::getInt(&ini, &sect, &ifilename);
    LOBYTE(v44) = 9;
    v5 = ifilename._Myres < 8;
    this->STAY_IN_CAR = v6 != 0;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"AUTO_APP_ON_PITLANE", 0x13u);
    LOBYTE(v44) = 12;
    v7 = INIReader::getInt(&ini, &sect, &ifilename);
    LOBYTE(v44) = 9;
    v5 = ifilename._Myres < 8;
    this->AUTO_APP_ON_PITLANE = v7 != 0;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"PRESETS_COUNT", 0xDu);
    LOBYTE(v44) = 13;
    v8 = INIReader::getInt(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    this->PRESETS_COUNT = v8;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"HEADER_HEIGHT", 0xDu);
    LOBYTE(v44) = 14;
    v9 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    this->HEADER_HEIGHT = v9;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"HEADER_FONT", 0xBu);
    LOBYTE(v44) = 15;
    v10 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    this->HEADER_FONT = v10;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"VISIBILITY_MAX_TIME", 0x13u);
    LOBYTE(v44) = 16;
    v11 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    this->VISIBILITY_MAX_TIME = v11;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"OBJECT_POS_X", 0xCu);
    LOBYTE(v44) = 17;
    v12 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    this->OBJECT_POS_X = v12;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"OBJECT_POS_Y", 0xCu);
    LOBYTE(v44) = 18;
    v13 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    this->OBJECT_POS_Y = v13;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"ITEM_HEIGHT", 0xBu);
    LOBYTE(v44) = 19;
    v14 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    v15 = v14 * this->SIZE_MULT;
    LOBYTE(v44) = 9;
    this->ITEM_HEIGHT = v15;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"ITEM_TITLE_WIDTH", 0x10u);
    LOBYTE(v44) = 20;
    v16 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    v17 = v16 * this->SIZE_MULT;
    LOBYTE(v44) = 9;
    this->ITEM_TITLE_WIDTH = v17;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"ITEM_VALUE_WIDTH", 0x10u);
    LOBYTE(v44) = 21;
    v18 = INIReader::getFloat(&ini, &sect, &ifilename);
    v5 = ifilename._Myres < 8;
    v19 = v18 * this->SIZE_MULT;
    LOBYTE(v44) = 9;
    this->ITEM_VALUE_WIDTH = v19;
    if ( !v5 )
      operator delete(ifilename._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ITEM_FOREGROUND_UNSELECTED", 0x1Au);
    LOBYTE(v44) = 22;
    v20 = (const __m128i *)INIReader::getFloat4(&ini, (vec4f *)&ifilename, &sect, &key);
    v5 = key._Myres < 8;
    LOBYTE(v44) = 9;
    this->ITEM_FOREGROUND_UNSELECTED = (vec4f)_mm_loadu_si128(v20);
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ITEM_BACKGROUND_UNSELECTED", 0x1Au);
    LOBYTE(v44) = 23;
    v21 = (const __m128i *)INIReader::getFloat4(&ini, (vec4f *)&ifilename, &sect, &key);
    v5 = key._Myres < 8;
    LOBYTE(v44) = 9;
    this->ITEM_BACKGROUND_UNSELECTED = (vec4f)_mm_loadu_si128(v21);
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ITEM_FOREGROUND_SELECTED", 0x18u);
    LOBYTE(v44) = 24;
    v22 = (const __m128i *)INIReader::getFloat4(&ini, (vec4f *)&ifilename, &sect, &key);
    v5 = key._Myres < 8;
    LOBYTE(v44) = 9;
    this->ITEM_FOREGROUND_SELECTED = (vec4f)_mm_loadu_si128(v22);
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ITEM_BACKGROUND_SELECTED", 0x18u);
    LOBYTE(v44) = 25;
    v23 = (const __m128i *)INIReader::getFloat4(&ini, (vec4f *)&ifilename, &sect, &key);
    v5 = key._Myres < 8;
    LOBYTE(v44) = 9;
    this->ITEM_BACKGROUND_SELECTED = (vec4f)_mm_loadu_si128(v23);
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"ITEM_FOREGROUND_HEADER");
    LOBYTE(v44) = 26;
    v24 = (const __m128i *)INIReader::getFloat4(&ini, (vec4f *)&ifilename, &sect, &key);
    v5 = key._Myres < 8;
    LOBYTE(v44) = 9;
    this->ITEM_FOREGROUND_HEADER = (vec4f)_mm_loadu_si128(v24);
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"ITEM_BACKGROUND_HEADER");
    LOBYTE(v44) = 27;
    v25 = (const __m128i *)INIReader::getFloat4(&ini, (vec4f *)&ifilename, &sect, &key);
    v5 = key._Myres < 8;
    LOBYTE(v44) = 9;
    this->ITEM_BACKGROUND_HEADER = (vec4f)_mm_loadu_si128(v25);
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"FORM_ALIGNMENT_H");
    LOBYTE(v44) = 28;
    v26 = INIReader::getInt(&ini, &sect, &key);
    v5 = key._Myres < 8;
    this->FORM_ALIGNMENT_H = v26;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"FORM_ALIGNMENT_V");
    LOBYTE(v44) = 29;
    v27 = INIReader::getInt(&ini, &sect, &key);
    v5 = key._Myres < 8;
    this->FORM_ALIGNMENT_V = v27;
    LOBYTE(v44) = 9;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    v28 = (wchar_t *)operator new(24);
    ifilename._Bx._Ptr = v28;
    LOBYTE(v44) = 30;
    if ( v28 )
    {
      std::wstring::wstring(&key, L"FONT_IS_BOLD");
      LOBYTE(v44) = 31;
      v3 = 1;
      v38 = 1;
      v29 = INIReader::getInt(&ini, &sect, &key);
      Font::Font((Font *)v28, eFontProportional, 12.0, 0, v29 != 0);
    }
    else
    {
      v30 = 0;
    }
    v44 = 32;
    *(_QWORD *)ifilename._Bx._Buf = 0i64;
    std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&ifilename, v30);
    std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&ifilename);
    v31 = *(volatile signed __int32 **)&ifilename._Bx._Alias[4];
    if ( *(_DWORD *)&ifilename._Bx._Alias[4] )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)&ifilename._Bx._Alias[4] + 4), 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v31)(v31);
        if ( !_InterlockedExchangeAdd(v31 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v31 + 4))(v31);
      }
    }
    v44 = 9;
    if ( (v3 & 1) != 0 )
    {
      v3 &= 0xFFFFFFFE;
      v38 = v3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    v32 = (wchar_t *)operator new(24);
    ifilename._Bx._Ptr = v32;
    LOBYTE(v44) = 33;
    if ( v32 )
    {
      std::wstring::wstring(&key, L"FONT_IS_BOLD");
      LOBYTE(v44) = 34;
      v3 |= 2u;
      v38 = v3;
      v33 = INIReader::getInt(&ini, &sect, &key);
      Font::Font((Font *)v32, eFontProportional, this->HEADER_FONT, 0, v33 != 0);
    }
    else
    {
      v34 = 0;
    }
    v44 = 35;
    *(_QWORD *)ifilename._Bx._Buf = 0i64;
    std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&ifilename, v34);
    std::shared_ptr<Font>::operator=(&this->headerFont, (std::shared_ptr<Font> *)&ifilename);
    v35 = *(volatile signed __int32 **)&ifilename._Bx._Alias[4];
    if ( *(_DWORD *)&ifilename._Bx._Alias[4] )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)&ifilename._Bx._Alias[4] + 4), 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v35)(v35);
        if ( !_InterlockedDecrement(v35 + 2) )
          (*(void (**)(volatile signed __int32 *))(*v35 + 4))(v35);
      }
    }
    v44 = 9;
    if ( (v3 & 2) != 0 && key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( sect._Myres >= 8 )
      operator delete(sect._Bx._Ptr);
  }
  LOBYTE(v44) = 5;
  INIReader::~INIReader(&ini);
}
void QuickMenuPitstop::~QuickMenuPitstop(QuickMenuPitstop *this)
{
  unsigned int v2; // ebp
  int v3; // edi
  ksgui::Label *v4; // ecx
  ksgui::Label *v5; // ecx
  ksgui::Label *v6; // ecx
  std::_Ref_count_base *v7; // ebp
  std::_Ref_count_base *v8; // ebp
  std::_Ref_count_base *v9; // ebp
  std::_Ref_count_base *v10; // ebp

  this->__vftable = (QuickMenuPitstop_vtbl *)&QuickMenuPitstop::`vftable';
  v2 = 0;
  if ( this->items._Mylast - this->items._Myfirst )
  {
    v3 = 0;
    do
    {
      v4 = this->items._Myfirst[v3].title;
      if ( v4 )
        ((void (*)(ksgui::Label *, int))v4->~Control)(v4, 1);
      v5 = this->items._Myfirst[v3].header;
      if ( v5 )
        ((void (*)(ksgui::Label *, int))v5->~Control)(v5, 1);
      v6 = this->items._Myfirst[v3].value;
      if ( v6 )
        ((void (*)(ksgui::Label *, int))v6->~Control)(v6, 1);
      ++v2;
      ++v3;
    }
    while ( v2 < this->items._Mylast - this->items._Myfirst );
  }
  v7 = this->font._Rep;
  this->font._Rep = 0;
  this->font._Ptr = 0;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Uses, 0xFFFFFFFF) )
    {
      v7->_Destroy(v7);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Weaks, 0xFFFFFFFF) )
        v7->_Delete_this(v7);
    }
  }
  v8 = this->headerFont._Rep;
  this->headerFont._Rep = 0;
  this->headerFont._Ptr = 0;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Weaks, 0xFFFFFFFF) )
        v8->_Delete_this(v8);
    }
  }
  v9 = this->headerFont._Rep;
  if ( v9 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v9->_Uses, 0xFFFFFFFF) )
    {
      v9->_Destroy(v9);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v9->_Weaks, 0xFFFFFFFF) )
        v9->_Delete_this(v9);
    }
  }
  v10 = this->font._Rep;
  if ( v10 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v10->_Uses, 0xFFFFFFFF) )
    {
      v10->_Destroy(v10);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v10->_Weaks) )
        v10->_Delete_this(v10);
    }
  }
  if ( this->presets._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->presets);
    operator delete(this->presets._Myfirst);
    this->presets._Myfirst = 0;
    this->presets._Mylast = 0;
    this->presets._Myend = 0;
  }
  if ( this->pitstopPresets._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->pitstopPresets);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
      (std::vector<unsigned char> *)this->pitstopPresets._Myfirst,
      (std::vector<unsigned char> *)this->pitstopPresets._Mylast);
    operator delete(this->pitstopPresets._Myfirst);
    this->pitstopPresets._Myfirst = 0;
    this->pitstopPresets._Mylast = 0;
    this->pitstopPresets._Myend = 0;
  }
  if ( this->items._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->items);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<QuickMenuPitstopItem>>>(
      this->items._Myfirst,
      this->items._Mylast);
    operator delete(this->items._Myfirst);
    this->items._Myfirst = 0;
    this->items._Mylast = 0;
    this->items._Myend = 0;
  }
  GameObject::~GameObject(this);
}
QuickMenuPitstop *QuickMenuPitstop::`vector deleting destructor'(QuickMenuPitstop *this, unsigned int a2)
{
  QuickMenuPitstop::~QuickMenuPitstop(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void QuickMenuPitstop::addHeader(QuickMenuPitstop *this, ksgui::Label *lbl, const std::wstring *title)
{
  std::_Ref_count_base *v4; // edx
  Font *v5; // ebx
  std::_Ref_count_base *v6; // esi
  ksgui::Label_vtbl *v7; // eax

  ((void (*)(ksgui::Label *, _DWORD, _DWORD))lbl->setSize)(
    lbl,
    this->ITEM_VALUE_WIDTH + this->ITEM_TITLE_WIDTH,
    LODWORD(this->HEADER_HEIGHT));
  ksgui::Form::setPosition((ksgui::Form *)lbl, 0.0, 0.0);
  v4 = this->headerFont._Rep;
  v5 = this->headerFont._Ptr;
  if ( v4 )
    _InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Uses, 1u);
  v6 = lbl->font._Rep;
  lbl->font._Rep = v4;
  lbl->font._Ptr = v5;
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  lbl->fontScale = this->SIZE_MULT;
  v7 = lbl->__vftable;
  lbl->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_FOREGROUND_HEADER);
  lbl->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_BACKGROUND_HEADER);
  v7->setText(lbl, title);
  this->root->addControl(this->root, lbl);
}
void QuickMenuPitstop::buildControls(QuickMenuPitstop *this, INIReader *carsetup)
{
  INIReader *v3; // ebp
  int v4; // ebx
  QuickMenuPitstopItem *v5; // esi
  ksgui::Control *v6; // eax
  Sim *v7; // eax
  std::vector<QuickMenuPitstopItem> *v8; // ebx
  QuickMenuPitstopItem *v9; // esi
  ksgui::Label *v10; // eax
  int v11; // ecx
  int v12; // esi
  ksgui::Label *v13; // eax
  float v14; // ebx
  std::wstring *v15; // eax
  ksgui::Label *v16; // eax
  ksgui::Label *v17; // ecx
  ksgui::Label **v18; // eax
  ksgui::Label **v19; // edx
  int v20; // esi
  ksgui::Label **v21; // ecx
  ksgui::Label **v22; // eax
  ksgui::Label **v23; // eax
  float v24; // xmm0_4
  ksgui::Label *v25; // esi
  ksgui::Label **v26; // eax
  QuickMenuPitstopItem *v27; // ecx
  int v28; // edx
  void *v29; // eax
  volatile signed __int32 *v30; // esi
  ksgui::Label *v31; // edx
  int *v32; // esi
  std::wstring *v33; // eax
  int v34; // edx
  QuickMenuPitstopItem *v35; // eax
  QuickMenuPitstopItem *v36; // eax
  QuickMenuPitstopItem *v37; // eax
  std::function<void __cdecl(int,int)> *v38; // esi
  std::function<void __cdecl(int,int)> *v39; // ecx
  ksgui::Label *v40; // esi
  ksgui::Label *v41; // eax
  ksgui::Label *v42; // ecx
  QuickMenuPitstopItem *v43; // eax
  QuickMenuPitstopItem *v44; // eax
  QuickMenuPitstopItem *v45; // eax
  QuickMenuPitstopItem *v46; // eax
  int v47; // esi
  CarAvatar *v48; // eax
  QuickMenuPitstopItem *v49; // ecx
  QuickMenuPitstopItem *v50; // eax
  QuickMenuPitstopItem *v51; // eax
  QuickMenuPitstopItem *v52; // ecx
  ksgui::Label *v53; // eax
  ksgui::Label *v54; // ecx
  QuickMenuPitstopItem *v55; // eax
  QuickMenuPitstopItem *v56; // eax
  QuickMenuPitstopItem *v57; // eax
  QuickMenuPitstopItem *v58; // eax
  QuickMenuPitstopItem *v59; // eax
  QuickMenuPitstopItem *v60; // eax
  QuickMenuPitstopItem *v61; // ecx
  QuickMenuPitstopItem *v62; // eax
  QuickMenuPitstopItem *v63; // eax
  QuickMenuPitstopItem *v64; // eax
  QuickMenuPitstopItem *v65; // eax
  QuickMenuPitstopItem *v66; // ecx
  QuickMenuPitstopItem *v67; // eax
  QuickMenuPitstopItem *v68; // eax
  QuickMenuPitstopItem *v69; // eax
  QuickMenuPitstopItem *v70; // eax
  QuickMenuPitstopItem *v71; // ecx
  QuickMenuPitstopItem *v72; // eax
  QuickMenuPitstopItem *v73; // eax
  QuickMenuPitstopItem *v74; // eax
  QuickMenuPitstopItem *v75; // eax
  QuickMenuPitstopItem *v76; // ecx
  std::wstring *v77; // eax
  std::wstring *v78; // eax
  char v79; // al
  QuickMenuPitstopItem *v80; // eax
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *v81; // eax
  QuickMenuPitstopItem *v82; // eax
  QuickMenuPitstopItem *v83; // eax
  QuickMenuPitstopItem *v84; // eax
  QuickMenuPitstopItem *v85; // eax
  float v86; // eax
  QuickMenuPitstopItem *v87; // eax
  ksgui::Label *v88; // esi
  ksgui::Label *v89; // eax
  ksgui::Label *v90; // esi
  QuickMenuPitstopItem *v91; // eax
  QuickMenuPitstopItem *v92; // eax
  std::wstring *v93; // eax
  std::wstring *v94; // eax
  bool v95; // al
  QuickMenuPitstopItem *v96; // eax
  QuickMenuPitstopItem *v97; // eax
  float v98; // esi
  int v99; // esi
  QuickMenuPitstopItem *v100; // eax
  QuickMenuPitstopItem *v101; // eax
  QuickMenuPitstopItem *v102; // eax
  float v103; // eax
  QuickMenuPitstopItem *v104; // eax
  float v105; // eax
  QuickMenuPitstopItem *v106; // eax
  QuickMenuPitstopItem *v107; // eax
  QuickMenuPitstopItem *v108; // eax
  QuickMenuPitstopItem *v109; // eax
  QuickMenuPitstopItem *v110; // eax
  QuickMenuPitstopItem *v111; // eax
  float v112; // eax
  QuickMenuPitstopItem *v113; // eax
  QuickMenuPitstopItem *v114; // eax
  QuickMenuPitstopItem *v115; // eax
  QuickMenuPitstopItem *v116; // eax
  QuickMenuPitstopItem *v117; // eax
  float v118; // eax
  QuickMenuPitstopItem *v119; // eax
  int v120; // ebp
  unsigned int i; // esi
  float v122; // esi
  QuickMenuPitstopItem *v123; // eax
  QuickMenuPitstopItem *v124; // eax
  unsigned int v125; // esi
  QuickMenuPitstopItem *v126; // eax
  float v127; // xmm0_4
  QuickMenuPitstopItem *v128; // eax
  QuickMenuPitstopItem *v129; // eax
  ksgui::Control *v130; // eax
  int v131; // eax
  int v132; // eax
  ksgui::Control *v133; // ecx
  double v134; // st7
  float v135; // xmm0_4
  __int64 v136; // rax
  int v137; // esi
  double v138; // st7
  int v139; // eax
  int v140; // eax
  ksgui::Control *v141; // ecx
  double v142; // st7
  float v143; // xmm0_4
  __int64 v144; // rax
  int v145; // esi
  double v146; // st7
  std::wstring left; // [esp+38h] [ebp-104h] BYREF
  float top; // [esp+50h] [ebp-ECh]
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<QuickMenuPitstopItem> > > v149; // [esp+68h] [ebp-D4h] BYREF
  float posY; // [esp+6Ch] [ebp-D0h]
  float posX; // [esp+70h] [ebp-CCh]
  int v152; // [esp+74h] [ebp-C8h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<QuickMenuPitstopItem> > > result; // [esp+78h] [ebp-C4h] BYREF
  ksgui::Label *v154; // [esp+7Ch] [ebp-C0h]
  float v155; // [esp+80h] [ebp-BCh]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v156; // [esp+84h] [ebp-B8h] BYREF
  ksgui::Label *v157; // [esp+88h] [ebp-B4h] BYREF
  std::wstring iname; // [esp+8Ch] [ebp-B0h] BYREF
  std::wstring sect; // [esp+A4h] [ebp-98h] BYREF
  std::vector<float> vect; // [esp+BCh] [ebp-80h] BYREF
  unsigned int v161; // [esp+D0h] [ebp-6Ch]
  QuickMenuPitstopItem v162; // [esp+D4h] [ebp-68h] BYREF
  int v163; // [esp+138h] [ebp-4h]

  v3 = carsetup;
  v4 = 0;
  v149._Ptr = (QuickMenuPitstopItem *)carsetup;
  posX = 0.0;
  v5 = (QuickMenuPitstopItem *)operator new(280);
  result._Ptr = v5;
  v6 = 0;
  v163 = 0;
  if ( v5 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"FORM_PITSTOP", 0xCu);
    v7 = this->sim;
    v4 = 1;
    LOBYTE(v163) = 1;
    LODWORD(posX) = 1;
    ksgui::Control::Control((ksgui::Control *)v5, &iname, v7->game->gui);
  }
  this->root = v6;
  v163 = -1;
  if ( (v4 & 1) != 0 )
  {
    LODWORD(posX) = v4 & 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v8 = &this->items;
  std::_Container_base0::_Orphan_all(&this->items);
  LODWORD(top) = (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<QuickMenuPitstopItem> > >)v149._Ptr;
  left._Myres = (unsigned int)&v152 + 2;
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<QuickMenuPitstopItem>>>(this->items._Myfirst, this->items._Mylast);
  this->items._Mylast = this->items._Myfirst;
  sect._Myres = 7;
  sect._Mysize = 0;
  sect._Bx._Buf[0] = 0;
  v163 = 3;
  if ( carsetup->ready )
  {
    v9 = (QuickMenuPitstopItem *)operator new(284);
    result._Ptr = v9;
    LOBYTE(v163) = 4;
    if ( v9 )
    {
      top = *(float *)&this->sim->game->gui;
      std::wstring::wstring(&left, L"QM_HEADER_PRESET");
      ksgui::Label::Label((ksgui::Label *)v9, left, (ksgui::GUI *)LODWORD(top));
    }
    else
    {
      v10 = 0;
    }
    this->presetHeader = v10;
    LOBYTE(v163) = 3;
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L" PRESETS", 8u);
    LOBYTE(v163) = 5;
    QuickMenuPitstop::addHeader(this, this->presetHeader, &iname);
    LOBYTE(v163) = 3;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    v11 = this->PRESETS_COUNT;
    v12 = 0;
    v13 = this->presetHeader;
    posY = 0.0;
    v155 = (float)(v13->rect.right - v13->rect.left) / (float)v11;
    if ( v11 > 0 )
    {
      v14 = posX;
      do
      {
        v154 = (ksgui::Label *)operator new(284);
        LOBYTE(v163) = 6;
        if ( v154 )
        {
          top = *(float *)&this->sim->game->gui;
          v15 = std::to_wstring(&iname, v12);
          LOBYTE(v163) = 7;
          LODWORD(v14) |= 2u;
          posX = v14;
          std::operator+<wchar_t>(&left, L"QM_PRESET_", v15);
          ksgui::Label::Label(v154, left, (ksgui::GUI *)LODWORD(top));
          v17 = v16;
          v154 = v16;
        }
        else
        {
          v17 = 0;
          v154 = 0;
        }
        v18 = this->presets._Mylast;
        v163 = 8;
        v157 = v17;
        if ( &v157 >= v18 || (v19 = this->presets._Myfirst, v12 = LODWORD(posY), v19 > &v157) )
        {
          if ( v18 == this->presets._Myend )
          {
            std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->presets, 1u);
            v17 = v154;
          }
          v22 = this->presets._Mylast;
          if ( v22 )
            *v22 = v17;
        }
        else
        {
          v20 = &v157 - v19;
          if ( v18 == this->presets._Myend )
            std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->presets, 1u);
          v21 = this->presets._Mylast;
          if ( v21 )
            *v21 = this->presets._Myfirst[v20];
          v12 = LODWORD(posY);
        }
        ++this->presets._Mylast;
        v163 = 3;
        if ( (LOBYTE(v14) & 2) != 0 )
        {
          LODWORD(v14) &= 0xFFFFFFFD;
          posX = v14;
          if ( iname._Myres >= 8 )
            operator delete(iname._Bx._Ptr);
        }
        v23 = this->presets._Myfirst;
        v24 = this->ITEM_HEIGHT;
        v25 = (ksgui::Label *)(4 * v12);
        v154 = v25;
        (*(void (**)(_DWORD, float, float))(**(_DWORD **)((char *)v23 + (_DWORD)v25) + 28))(
          *(ksgui::Label **)((char *)v23 + (_DWORD)v25),
          COERCE_FLOAT(LODWORD(v155)),
          COERCE_FLOAT(LODWORD(v24)));
        ksgui::Form::setPosition(
          *(ksgui::Form **)((char *)&v25->__vftable + (unsigned int)this->presets._Myfirst),
          (float)SLODWORD(posY) * v155,
          this->INTERLINE + this->HEADER_HEIGHT);
        v26 = this->presets._Myfirst;
        v27 = (QuickMenuPitstopItem *)this->font._Ptr;
        result._Ptr = v27;
        v28 = *(int *)((char *)v26 + (_DWORD)v25);
        v29 = this->font._Rep;
        v156.__this = (CarAudioFMOD *)v29;
        if ( v29 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)v29 + 1, 1u);
          v29 = v156.__this;
          v27 = result._Ptr;
        }
        v30 = *(volatile signed __int32 **)(v28 + 132);
        *(_DWORD *)(v28 + 132) = v29;
        *(_DWORD *)(v28 + 128) = v27;
        if ( v30 )
        {
          if ( !_InterlockedExchangeAdd(v30 + 1, 0xFFFFFFFF) )
          {
            (**(void (***)(volatile signed __int32 *))v30)(v30);
            if ( !_InterlockedExchangeAdd(v30 + 2, 0xFFFFFFFF) )
              (*(void (**)(volatile signed __int32 *))(*v30 + 4))(v30);
          }
        }
        v31 = v154;
        (*(ksgui::Label_vtbl **)((char *)&v154->__vftable + (unsigned int)this->presets._Myfirst))[1].setText = (void (*)(ksgui::Control *, const std::wstring *))2;
        (*(ksgui::Label_vtbl **)((char *)&v31->__vftable + (unsigned int)this->presets._Myfirst))[2].onMouseDown = (bool (*)(ksgui::Control *, const OnMouseDownEvent *))LODWORD(this->SIZE_MULT);
        v32 = *(int **)((char *)&v31->__vftable + (unsigned int)this->presets._Myfirst);
        ++LODWORD(posY);
        v33 = std::to_wstring(&iname, SLODWORD(posY));
        v34 = *v32;
        LOBYTE(v163) = 9;
        (*(void (**)(int *, std::wstring *))(v34 + 68))(v32, v33);
        LOBYTE(v163) = 3;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        this->root->addControl(
          this->root,
          *(ksgui::Control **)((char *)&v154->__vftable + (unsigned int)this->presets._Myfirst));
        v12 = LODWORD(posY);
      }
      while ( SLODWORD(posY) < this->PRESETS_COUNT );
      v3 = (INIReader *)v149._Ptr;
      v8 = &this->items;
    }
    QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
    LOBYTE(v163) = 10;
    std::vector<QuickMenuPitstopItem>::push_back(v8, v35);
    LOBYTE(v163) = 3;
    if ( v162.setupName._Myres >= 8 )
      operator delete(v162.setupName._Bx._Ptr);
    v162.setupName._Myres = 7;
    v162.setupName._Mysize = 0;
    v162.setupName._Bx._Buf[0] = 0;
    if ( v162.function._Impl )
      ((void (__stdcall *)(bool))v162.function._Impl->_Delete_this)(v162.function._Impl != (std::_Func_base<void,int,int> *)&v162.function);
    v36 = this->items._Mylast;
    top = 0.0;
    left._Myres = (unsigned int)&sect;
    v36[-1].index = 0;
    this->items._Mylast[-1].type = Fuel;
    this->items._Mylast[-1].componentIndex = -1;
    QuickMenuPitstop::buildItem(this, v3, this->items._Mylast - 1, (const std::wstring *)left._Myres, SLOBYTE(top));
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L" ADD LITERS", 0xBu);
    v37 = this->items._Mylast;
    LOBYTE(v163) = 11;
    v37[-1].title->setText(v37[-1].title, &iname);
    LOBYTE(v163) = 3;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    std::wstring::assign(&this->items._Mylast[-1].setupName, L"FUEL", 4u);
    v38 = &this->items._Mylast[-1].function;
    v39 = (std::function<void __cdecl(int,int)> *)v38->_Impl;
    if ( v39 )
    {
      (*((void (__stdcall **)(bool))v39->_Space._Pfn[0] + 4))(v39 != v38);
      v38->_Impl = 0;
    }
    v38->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_d53017526baa5e8466bed9ef23c6a568_,0>,std::allocator<std::_Func_class<void,int,int>>,void,int,int>::`vftable';
    v38->_Space._Pfn[1] = (void (__cdecl *)())this;
    LODWORD(top) = 284;
    v38->_Impl = (std::_Func_base<void,int,int> *)v38;
    *(float *)&v40 = COERCE_FLOAT(operator new(LODWORD(top)));
    v149._Ptr = (QuickMenuPitstopItem *)v40;
    LOBYTE(v163) = 12;
    if ( *(float *)&v40 == 0.0 )
    {
      v42 = 0;
    }
    else
    {
      top = *(float *)&this->sim->game->gui;
      left._Myres = 7;
      left._Mysize = 0;
      left._Bx._Buf[0] = 0;
      std::wstring::assign(&left, L"QM_HEADER_GENERAL", 0x11u);
      ksgui::Label::Label(v40, left, (ksgui::GUI *)LODWORD(top));
      v42 = v41;
    }
    v43 = this->items._Mylast;
    LODWORD(top) = 8;
    left._Myres = (unsigned int)L" GENERAL";
    LOBYTE(v163) = 3;
    v43[-1].header = v42;
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, (const wchar_t *)left._Myres, LODWORD(top));
    v44 = this->items._Mylast;
    LOBYTE(v163) = 13;
    QuickMenuPitstop::addHeader(this, v44[-1].header, &iname);
    LOBYTE(v163) = 3;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
    LOBYTE(v163) = 14;
    std::vector<QuickMenuPitstopItem>::push_back(v8, v45);
    LOBYTE(v163) = 3;
    if ( v162.setupName._Myres >= 8 )
      operator delete(v162.setupName._Bx._Ptr);
    v162.setupName._Myres = 7;
    v162.setupName._Mysize = 0;
    v162.setupName._Bx._Buf[0] = 0;
    if ( v162.function._Impl )
      ((void (__stdcall *)(bool))v162.function._Impl->_Delete_this)(v162.function._Impl != (std::_Func_base<void,int,int> *)&v162.function);
    v46 = this->items._Mylast;
    v47 = 2;
    top = 0.0;
    LODWORD(posY) = 2;
    v46[-1].index = 1;
    this->items._Mylast[-1].type = TyreCompound;
    this->items._Mylast[-1].componentIndex = -1;
    this->items._Mylast[-1].minValue = -1.0;
    v48 = Sim::getCar(this->sim, LODWORD(top));
    v49 = this->items._Mylast;
    top = 0.0;
    v49[-1].maxValue = (float)(unsigned int)(v48->physicsInfo.tyreCompounds._Mylast
                                           - v48->physicsInfo.tyreCompounds._Myfirst);
    QuickMenuPitstop::buildItem(this, v3, this->items._Mylast - 1, &sect, SLOBYTE(top));
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L" COMPOUND", 9u);
    v50 = this->items._Mylast;
    LOBYTE(v163) = 15;
    v50[-1].title->setText(v50[-1].title, &iname);
    LOBYTE(v163) = 3;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    std::wstring::assign(&this->items._Mylast[-1].setupName, L"COMPOUND", 8u);
    v51 = (QuickMenuPitstopItem *)((char *)this->items._Mylast - 72);
    v149._Ptr = v51;
    v52 = (QuickMenuPitstopItem *)v51->function._Space._Pfn[0];
    if ( v52 )
    {
      (*(void (__stdcall **)(bool))(v52->type + 16))(v52 != v51);
      v51 = v149._Ptr;
      v149._Ptr->function._Space._Pfn[0] = 0;
    }
    v51->type = (EQuickMenuPitstopType)&std::_Func_impl<std::_Callable_obj<_lambda_33f4ea2bbd8209a75a7fec47a315a437_,0>,std::allocator<std::_Func_class<void,int,int>>,void,int,int>::`vftable';
    v51->index = (int)this;
    LODWORD(top) = 284;
    v51->function._Space._Pfn[0] = (void (__cdecl *)())v51;
    *(float *)&v149._Ptr = COERCE_FLOAT(operator new(LODWORD(top)));
    LOBYTE(v163) = 16;
    if ( *(float *)&v149._Ptr == 0.0 )
    {
      v54 = 0;
    }
    else
    {
      top = *(float *)&this->sim->game->gui;
      std::wstring::wstring(&left, L"QM_HEADER_TYRE");
      ksgui::Label::Label((ksgui::Label *)v149._Ptr, left, (ksgui::GUI *)LODWORD(top));
      v54 = v53;
    }
    v55 = this->items._Mylast;
    LODWORD(top) = 6;
    left._Myres = (unsigned int)L" TYRES";
    LOBYTE(v163) = 3;
    v55[-1].header = v54;
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, (const wchar_t *)left._Myres, LODWORD(top));
    v56 = this->items._Mylast;
    LOBYTE(v163) = 17;
    QuickMenuPitstop::addHeader(this, v56[-1].header, &iname);
    LOBYTE(v163) = 3;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    std::wstring::assign(&sect, L"PRESSURE_LF", 0xBu);
    if ( INIReader::hasSection(v3, &sect) )
    {
      QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
      LOBYTE(v163) = 18;
      std::vector<QuickMenuPitstopItem>::push_back(v8, v57);
      LOBYTE(v163) = 3;
      QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
      v58 = this->items._Mylast;
      v47 = 3;
      LODWORD(top) = 1;
      left._Myres = (unsigned int)&sect;
      v58[-1].index = 2;
      v59 = this->items._Mylast;
      LODWORD(posY) = 3;
      v59[-1].type = TyrePressure;
      this->items._Mylast[-1].componentIndex = 0;
      QuickMenuPitstop::buildItem(this, v3, this->items._Mylast - 1, (const std::wstring *)left._Myres, SLOBYTE(top));
      v60 = (QuickMenuPitstopItem *)((char *)this->items._Mylast - 72);
      v149._Ptr = v60;
      v61 = (QuickMenuPitstopItem *)v60->function._Space._Pfn[0];
      if ( v61 )
      {
        (*(void (__stdcall **)(bool))(v61->type + 16))(v61 != v60);
        v60 = v149._Ptr;
        v149._Ptr->function._Space._Pfn[0] = 0;
      }
      v60->type = (EQuickMenuPitstopType)&std::_Func_impl<std::_Callable_obj<_lambda_339e2b52fe0881ecd336a803618d65c7_,0>,std::allocator<std::_Func_class<void,int,int>>,void,int,int>::`vftable';
      v60->index = (int)this;
      v60->function._Space._Pfn[0] = (void (__cdecl *)())v60;
    }
    std::wstring::assign(&sect, L"PRESSURE_RF", 0xBu);
    if ( INIReader::hasSection(v3, &sect) )
    {
      QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
      LOBYTE(v163) = 19;
      std::vector<QuickMenuPitstopItem>::push_back(v8, v62);
      LOBYTE(v163) = 3;
      QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
      v63 = this->items._Mylast;
      LODWORD(top) = 1;
      left._Myres = (unsigned int)&sect;
      v63[-1].index = v47++;
      v64 = this->items._Mylast;
      posY = *(float *)&v47;
      v64[-1].type = TyrePressure;
      this->items._Mylast[-1].componentIndex = 1;
      QuickMenuPitstop::buildItem(this, v3, this->items._Mylast - 1, (const std::wstring *)left._Myres, SLOBYTE(top));
      v65 = (QuickMenuPitstopItem *)((char *)this->items._Mylast - 72);
      v149._Ptr = v65;
      v66 = (QuickMenuPitstopItem *)v65->function._Space._Pfn[0];
      if ( v66 )
      {
        (*(void (__stdcall **)(bool))(v66->type + 16))(v66 != v65);
        v65 = v149._Ptr;
        v149._Ptr->function._Space._Pfn[0] = 0;
      }
      v65->type = (EQuickMenuPitstopType)&std::_Func_impl<std::_Callable_obj<_lambda_929eccb9419b250c016a190a9c0bb15e_,0>,std::allocator<std::_Func_class<void,int,int>>,void,int,int>::`vftable';
      v65->index = (int)this;
      v65->function._Space._Pfn[0] = (void (__cdecl *)())v65;
    }
    std::wstring::assign(&sect, L"PRESSURE_LR", 0xBu);
    if ( INIReader::hasSection(v3, &sect) )
    {
      QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
      LOBYTE(v163) = 20;
      std::vector<QuickMenuPitstopItem>::push_back(v8, v67);
      LOBYTE(v163) = 3;
      QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
      v68 = this->items._Mylast;
      LODWORD(top) = 1;
      left._Myres = (unsigned int)&sect;
      v68[-1].index = v47++;
      v69 = this->items._Mylast;
      posY = *(float *)&v47;
      v69[-1].type = TyrePressure;
      this->items._Mylast[-1].componentIndex = 2;
      QuickMenuPitstop::buildItem(this, v3, this->items._Mylast - 1, (const std::wstring *)left._Myres, SLOBYTE(top));
      v70 = (QuickMenuPitstopItem *)((char *)this->items._Mylast - 72);
      v149._Ptr = v70;
      v71 = (QuickMenuPitstopItem *)v70->function._Space._Pfn[0];
      if ( v71 )
      {
        (*(void (__stdcall **)(bool))(v71->type + 16))(v71 != v70);
        v70 = v149._Ptr;
        v149._Ptr->function._Space._Pfn[0] = 0;
      }
      v70->type = (EQuickMenuPitstopType)&std::_Func_impl<std::_Callable_obj<_lambda_b4813c6467fc23602a51b937b75ba2b6_,0>,std::allocator<std::_Func_class<void,int,int>>,void,int,int>::`vftable';
      v70->index = (int)this;
      v70->function._Space._Pfn[0] = (void (__cdecl *)())v70;
    }
    std::wstring::assign(&sect, L"PRESSURE_RR", 0xBu);
    if ( INIReader::hasSection(v3, &sect) )
    {
      QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
      LOBYTE(v163) = 21;
      std::vector<QuickMenuPitstopItem>::push_back(v8, v72);
      LOBYTE(v163) = 3;
      QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
      v73 = this->items._Mylast;
      LODWORD(top) = 1;
      left._Myres = (unsigned int)&sect;
      v73[-1].index = v47++;
      v74 = this->items._Mylast;
      posY = *(float *)&v47;
      v74[-1].type = TyrePressure;
      this->items._Mylast[-1].componentIndex = 3;
      QuickMenuPitstop::buildItem(this, v3, this->items._Mylast - 1, (const std::wstring *)left._Myres, SLOBYTE(top));
      v75 = (QuickMenuPitstopItem *)((char *)this->items._Mylast - 72);
      v149._Ptr = v75;
      v76 = (QuickMenuPitstopItem *)v75->function._Space._Pfn[0];
      if ( v76 )
      {
        (*(void (__stdcall **)(bool))(v76->type + 16))(v76 != v75);
        v75 = v149._Ptr;
        v149._Ptr->function._Space._Pfn[0] = 0;
      }
      v75->type = (EQuickMenuPitstopType)&std::_Func_impl<std::_Callable_obj<_lambda_bee8f630fa905108adf7290ed936a634_,0>,std::allocator<std::_Func_class<void,int,int>>,void,int,int>::`vftable';
      v75->index = (int)this;
      v75->function._Space._Pfn[0] = (void (__cdecl *)())v75;
    }
    LODWORD(posX) = 1;
    HIBYTE(v152) = 1;
    v77 = std::to_wstring((std::wstring *)&vect, 1);
    LOBYTE(v163) = 22;
    *(float *)&v78 = COERCE_FLOAT(std::operator+<wchar_t>(&iname, L"WING_", v77));
    v149._Ptr = (QuickMenuPitstopItem *)v78;
    if ( &sect != v78 )
    {
      if ( sect._Myres >= 8 )
      {
        operator delete(sect._Bx._Ptr);
        v78 = (std::wstring *)v149._Ptr;
      }
      sect._Myres = 7;
      sect._Bx._Buf[0] = 0;
      sect._Mysize = 0;
      std::wstring::_Assign_rv(&sect, v78);
    }
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    LOBYTE(v163) = 3;
    if ( v161 >= 8 )
      operator delete(vect._Myfirst);
    if ( INIReader::hasSection(v3, &sect) )
    {
      do
      {
        std::wstring::wstring(&iname, L"PITSTOP");
        LOBYTE(v163) = 23;
        v79 = INIReader::hasKey(v3, &sect, &iname);
        BYTE2(v152) = v79;
        LOBYTE(v163) = 3;
        if ( iname._Myres >= 8 )
        {
          operator delete(iname._Bx._Ptr);
          v79 = BYTE2(v152);
        }
        if ( v79 )
        {
          QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
          LOBYTE(v163) = 24;
          std::vector<QuickMenuPitstopItem>::push_back(v8, v80);
          LOBYTE(v163) = 3;
          QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
          v149._Ptr = v8->_Mylast;
          v81 = (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<QuickMenuPitstopItem>>>::operator-(
                                                                                                    &v149,
                                                                                                    &result,
                                                                                                    1);
          std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(v81)->name._Bx._Ptr = (wchar_t *)v47;
          LODWORD(posY) = v47 + 1;
          v82 = std::vector<QuickMenuPitstopItem>::back(v8);
          LODWORD(top) = L"PITSTOP";
          v82->type = Wing;
          std::wstring::wstring(&iname, (const wchar_t *)LODWORD(top));
          LOBYTE(v163) = 25;
          *(float *)&v149._Ptr = INIReader::getFloat(v3, &sect, &iname);
          v83 = std::vector<QuickMenuPitstopItem>::back(v8);
          LOBYTE(v163) = 3;
          v83->pitstopTime = *(float *)&v149._Ptr;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
          v84 = std::vector<QuickMenuPitstopItem>::back(v8);
          LODWORD(top) = 1;
          *(float *)&v84->componentIndex = posX;
          left._Myres = (unsigned int)&sect;
          v85 = std::vector<QuickMenuPitstopItem>::back(v8);
          QuickMenuPitstop::buildItem(this, v3, v85, (const std::wstring *)left._Myres, SLOBYTE(top));
          CommandItem::CommandItem(&v156, (CarAudioFMOD *)this);
          top = v86;
          v87 = std::vector<QuickMenuPitstopItem>::back(v8);
          std::function<void __cdecl (int,int)>::operator=<_lambda_51c48f54229e0c2ce9d0477f364cb39e_>(
            &v87->function,
            (QuickMenuPitstop::buildControls::__l31::<lambda_51c48f54229e0c2ce9d0477f364cb39e> *)LODWORD(top));
          if ( HIBYTE(v152) )
          {
            HIBYTE(v152) = 0;
            *(float *)&v88 = COERCE_FLOAT(operator new(284));
            v149._Ptr = (QuickMenuPitstopItem *)v88;
            LOBYTE(v163) = 26;
            if ( *(float *)&v88 == 0.0 )
            {
              v90 = 0;
            }
            else
            {
              top = *(float *)&this->sim->game->gui;
              std::wstring::wstring(&left, L"QM_HEADER_WINGS");
              ksgui::Label::Label(v88, left, (ksgui::GUI *)LODWORD(top));
              v90 = v89;
            }
            LOBYTE(v163) = 3;
            v91 = std::vector<QuickMenuPitstopItem>::back(v8);
            LODWORD(top) = L" WINGS";
            v91->header = v90;
            std::wstring::wstring(&iname, (const wchar_t *)LODWORD(top));
            LOBYTE(v163) = 27;
            LODWORD(top) = &iname;
            v92 = std::vector<QuickMenuPitstopItem>::back(v8);
            QuickMenuPitstop::addHeader(this, v92->header, (const std::wstring *)LODWORD(top));
            LOBYTE(v163) = 3;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
          }
        }
        ++LODWORD(posX);
        v93 = std::to_wstring((std::wstring *)&vect, SLODWORD(posX));
        LOBYTE(v163) = 28;
        v94 = std::operator+<wchar_t>(&iname, L"WING_", v93);
        std::wstring::operator=(&sect, v94);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
        LOBYTE(v163) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vect);
        v95 = INIReader::hasSection(v3, &sect);
        *(float *)&v47 = posY;
      }
      while ( v95 );
    }
    QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
    LOBYTE(v163) = 29;
    std::vector<QuickMenuPitstopItem>::push_back(v8, v96);
    LOBYTE(v163) = 3;
    QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
    v97 = std::vector<QuickMenuPitstopItem>::back(v8);
    v98 = posY;
    *(float *)&v97->index = posY;
    v99 = LODWORD(v98) + 1;
    std::vector<QuickMenuPitstopItem>::back(v8)->type = Repair;
    v100 = std::vector<QuickMenuPitstopItem>::back(v8);
    top = 0.0;
    v100->componentIndex = 0;
    left._Myres = (unsigned int)&sect;
    v101 = std::vector<QuickMenuPitstopItem>::back(v8);
    QuickMenuPitstop::buildItem(this, v3, v101, (const std::wstring *)left._Myres, SLOBYTE(top));
    std::wstring::wstring(&iname, L" BODY");
    LOBYTE(v163) = 30;
    v102 = std::vector<QuickMenuPitstopItem>::back(v8);
    v102->title->setText(v102->title, &iname);
    LOBYTE(v163) = 3;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v149,
      (CarAudioFMOD *)this);
    top = v103;
    v104 = std::vector<QuickMenuPitstopItem>::back(v8);
    std::function<void __cdecl (int,int)>::operator=<_lambda_aac3406c408e7a78650483508494cf93_>(
      &v104->function,
      (QuickMenuPitstop::buildControls::__l35::<lambda_aac3406c408e7a78650483508494cf93> *)LODWORD(top));
    *(float *)&v149._Ptr = COERCE_FLOAT(operator new(284));
    LOBYTE(v163) = 31;
    if ( *(float *)&v149._Ptr == 0.0 )
    {
      v155 = 0.0;
    }
    else
    {
      top = *(float *)&this->sim->game->gui;
      std::wstring::wstring(&left, L"QM_HEADER_REPAIR");
      ksgui::Label::Label((ksgui::Label *)v149._Ptr, left, (ksgui::GUI *)LODWORD(top));
      v155 = v105;
    }
    LOBYTE(v163) = 3;
    v106 = std::vector<QuickMenuPitstopItem>::back(v8);
    LODWORD(top) = L" REPAIR";
    *(float *)&v106->header = v155;
    std::wstring::wstring(&iname, (const wchar_t *)LODWORD(top));
    LOBYTE(v163) = 32;
    LODWORD(top) = &iname;
    v107 = std::vector<QuickMenuPitstopItem>::back(v8);
    QuickMenuPitstop::addHeader(this, v107->header, (const std::wstring *)LODWORD(top));
    LOBYTE(v163) = 3;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
    LOBYTE(v163) = 33;
    std::vector<QuickMenuPitstopItem>::push_back(v8, v108);
    LOBYTE(v163) = 3;
    QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
    std::vector<QuickMenuPitstopItem>::back(v8)->index = v99;
    std::vector<QuickMenuPitstopItem>::back(v8)->type = Repair;
    v109 = std::vector<QuickMenuPitstopItem>::back(v8);
    top = 0.0;
    v109->componentIndex = 1;
    left._Myres = (unsigned int)&sect;
    v110 = std::vector<QuickMenuPitstopItem>::back(v8);
    QuickMenuPitstop::buildItem(this, v3, v110, (const std::wstring *)left._Myres, SLOBYTE(top));
    std::wstring::wstring(&iname, L" SUSPENSION");
    LOBYTE(v163) = 34;
    v111 = std::vector<QuickMenuPitstopItem>::back(v8);
    v111->title->setText(v111->title, &iname);
    LOBYTE(v163) = 3;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v149,
      (CarAudioFMOD *)this);
    top = v112;
    v113 = std::vector<QuickMenuPitstopItem>::back(v8);
    std::function<void __cdecl (int,int)>::operator=<_lambda_111906c985dc3f91d324d6d322c03a43_>(
      &v113->function,
      (QuickMenuPitstop::buildControls::__l36::<lambda_111906c985dc3f91d324d6d322c03a43> *)LODWORD(top));
    QuickMenuPitstopItem::QuickMenuPitstopItem(&v162);
    LOBYTE(v163) = 35;
    std::vector<QuickMenuPitstopItem>::push_back(v8, v114);
    LOBYTE(v163) = 3;
    QuickMenuPitstopItem::~QuickMenuPitstopItem(&v162);
    std::vector<QuickMenuPitstopItem>::back(v8)->index = v99 + 1;
    std::vector<QuickMenuPitstopItem>::back(v8)->type = Repair;
    v115 = std::vector<QuickMenuPitstopItem>::back(v8);
    top = 0.0;
    v115->componentIndex = 2;
    left._Myres = (unsigned int)&sect;
    v116 = std::vector<QuickMenuPitstopItem>::back(v8);
    QuickMenuPitstop::buildItem(this, v3, v116, (const std::wstring *)left._Myres, SLOBYTE(top));
    std::wstring::wstring(&iname, L" ENGINE");
    LOBYTE(v163) = 36;
    v117 = std::vector<QuickMenuPitstopItem>::back(v8);
    v117->title->setText(v117->title, &iname);
    LOBYTE(v163) = 3;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&v149,
      (CarAudioFMOD *)this);
    top = v118;
    v119 = std::vector<QuickMenuPitstopItem>::back(v8);
    std::function<void __cdecl (int,int)>::operator=<_lambda_561aaa9d4c0aff1572e060fa7aafd1fd_>(
      &v119->function,
      (QuickMenuPitstop::buildControls::__l37::<lambda_561aaa9d4c0aff1572e060fa7aafd1fd> *)LODWORD(top));
  }
  v120 = 0;
  for ( posX = 0.0; v120 < this->PRESETS_COUNT; ++v120 )
  {
    std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&vect);
    LOBYTE(v163) = 37;
    for ( i = 0; i < std::vector<QuickMenuPitstopItem>::size(v8); ++i )
    {
      *(float *)&v149._Ptr = 0.0;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&vect, (int *)&v149);
    }
    std::vector<std::vector<float>>::push_back(&this->pitstopPresets, &vect);
    this->currentPreset = v120;
    v122 = 0.0;
    if ( std::vector<QuickMenuPitstopItem>::size(v8) )
    {
      do
      {
        top = 0.0;
        v123 = std::vector<QuickMenuPitstopItem>::operator[](v8, LODWORD(v122));
        if ( std::operator!=<void __cdecl (int,int)>(&v123->function) )
        {
          top = v122;
          left._Myres = 0;
          v124 = std::vector<QuickMenuPitstopItem>::operator[](v8, LODWORD(v122));
          std::_Func_class<void,int,int>::operator()(&v124->function, left._Myres, SLODWORD(top));
          if ( !v120 )
            QuickMenuPitstop::setLabels(this, SLODWORD(v122));
        }
        ++LODWORD(v122);
      }
      while ( LODWORD(v122) < std::vector<QuickMenuPitstopItem>::size(v8) );
    }
    LOBYTE(v163) = 3;
    std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&vect);
  }
  v125 = 0;
  for ( posY = (float)((float)(this->INTERLINE + this->HEADER_HEIGHT) + this->ITEM_HEIGHT) + this->INTERLINE;
        v125 < std::vector<QuickMenuPitstopItem>::size(v8);
        posY = (float)(this->INTERLINE + this->ITEM_HEIGHT) + posY )
  {
    v126 = std::vector<QuickMenuPitstopItem>::operator[](v8, v125);
    v127 = posY;
    if ( v126->header )
    {
      top = posY;
      left._Myres = 0;
      v128 = std::vector<QuickMenuPitstopItem>::operator[](v8, v125);
      ksgui::Form::setPosition((ksgui::Form *)v128->header, *(float *)&left._Myres, top);
      v127 = (float)(this->INTERLINE + this->HEADER_HEIGHT) + posY;
      posY = v127;
    }
    top = v127;
    v129 = std::vector<QuickMenuPitstopItem>::operator[](v8, v125);
    QuickMenuPitstopItem::setTop(v129, top);
    ++v125;
  }
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->root->setSize)(
    this->root,
    this->ITEM_VALUE_WIDTH + this->ITEM_TITLE_WIDTH,
    posY - (float)(this->INTERLINE + this->ITEM_HEIGHT));
  v130 = this->root;
  result._Ptr = 0;
  v130->drawBorder = 0;
  this->root->drawBackground = 0;
  v131 = this->FORM_ALIGNMENT_H;
  if ( v131 )
  {
    v132 = v131 - 1;
    if ( v132 )
    {
      if ( v132 != 1 )
        goto LABEL_125;
      v133 = this->root;
      *(float *)&v149._Ptr = (float)this->game->graphics->videoSettings.width - this->OBJECT_POS_X;
      v134 = ksgui::Control::getWidth(v133);
      posX = *(float *)&v149._Ptr - v134;
      v135 = posX;
    }
    else
    {
      v136 = this->game->graphics->videoSettings.width;
      v137 = ((int)v136 - HIDWORD(v136)) >> 1;
      v138 = ksgui::Control::getWidth(this->root);
      *(float *)&v149._Ptr = (float)v137;
      posX = (float)v137 - v138 * 0.5;
      v135 = posX;
    }
  }
  else
  {
    v135 = this->OBJECT_POS_X;
  }
  posX = v135;
LABEL_125:
  v139 = this->FORM_ALIGNMENT_V;
  if ( v139 )
  {
    v140 = v139 - 1;
    if ( v140 )
    {
      if ( v140 == 1 )
      {
        v141 = this->root;
        *(float *)&v149._Ptr = (float)this->game->graphics->videoSettings.height - this->OBJECT_POS_Y;
        v142 = ksgui::Control::getHeight(v141);
        posY = *(float *)&v149._Ptr - v142;
        v143 = posY;
      }
      else
      {
        v143 = *(float *)&result._Ptr;
      }
    }
    else
    {
      v144 = this->game->graphics->videoSettings.height;
      v145 = ((int)v144 - HIDWORD(v144)) >> 1;
      v146 = ksgui::Control::getHeight(this->root);
      *(float *)&v149._Ptr = (float)v145;
      posY = (float)v145 - v146 * 0.5;
      v143 = posY;
    }
  }
  else
  {
    v143 = this->OBJECT_POS_Y;
  }
  ksgui::Form::setPosition((ksgui::Form *)this->root, posX, v143);
  this->currentPreset = 0;
  QuickMenuPitstop::updateUI(this);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&sect);
}
void QuickMenuPitstop::buildItem(QuickMenuPitstop *this, INIReader *ini, QuickMenuPitstopItem *item, const std::wstring *sect, bool readIni)
{
  wchar_t *v6; // esi
  ksgui::Label *v7; // eax
  wchar_t *v8; // esi
  ksgui::Label *v9; // eax
  ksgui::Label *v10; // ecx
  float v11; // xmm0_4
  std::_Ref_count_base *v12; // eax
  const wchar_t *v13; // ecx
  ksgui::Label *v14; // edx
  volatile signed __int32 *v15; // esi
  std::wstring *v16; // eax
  std::wstring *v17; // ecx
  std::wstring *v18; // eax
  wchar_t *v19; // eax
  std::wstring *v20; // ecx
  INIReader *v21; // esi
  double v22; // st7
  bool v23; // cf
  double v24; // st7
  std::_Ref_count_base *v25; // edx
  ksgui::Label *v26; // ecx
  Font *v27; // ebp
  volatile signed __int32 *v28; // esi
  std::wstring v29; // [esp+0h] [ebp-ACh] BYREF
  float top; // [esp+18h] [ebp-94h]
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > _Dest; // [esp+30h] [ebp-7Ch] BYREF
  std::_Ref_count_base *v32; // [esp+34h] [ebp-78h]
  INIReader *v33; // [esp+38h] [ebp-74h]
  std::wstring v34; // [esp+3Ch] [ebp-70h] BYREF
  std::wstring key; // [esp+54h] [ebp-58h] BYREF
  std::wstring nname; // [esp+6Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+84h] [ebp-28h] BYREF
  int v38; // [esp+A8h] [ebp-4h]

  v33 = ini;
  v6 = (wchar_t *)operator new(284);
  _Dest._Ptr = v6;
  v38 = 0;
  if ( v6 )
  {
    top = *(float *)&this->sim->game->gui;
    std::operator+<wchar_t>(&v29, L"QM_TITLE_", sect);
    ksgui::Label::Label((ksgui::Label *)v6, v29, (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v7 = 0;
  }
  LODWORD(top) = 284;
  v38 = -1;
  item->title = v7;
  v8 = (wchar_t *)operator new(LODWORD(top));
  _Dest._Ptr = v8;
  v38 = 1;
  if ( v8 )
  {
    top = *(float *)&this->sim->game->gui;
    std::operator+<wchar_t>(&v29, L"QM_VALUE_", sect);
    ksgui::Label::Label((ksgui::Label *)v8, v29, (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v9 = 0;
  }
  v10 = item->title;
  item->value = v9;
  v11 = this->ITEM_HEIGHT;
  v38 = -1;
  ((void (*)(ksgui::Label *, _DWORD, float))v10->setSize)(
    v10,
    LODWORD(this->ITEM_TITLE_WIDTH),
    COERCE_FLOAT(LODWORD(v11)));
  ksgui::Form::setPosition((ksgui::Form *)item->title, 0.0, 0.0);
  v12 = this->font._Rep;
  v13 = (const wchar_t *)this->font._Ptr;
  v14 = item->title;
  v32 = v12;
  _Dest._Ptr = v13;
  if ( v12 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)&v12->_Uses, 1u);
    v12 = v32;
    v13 = _Dest._Ptr;
  }
  v15 = (volatile signed __int32 *)v14->font._Rep;
  v14->font._Rep = v12;
  v14->font._Ptr = (Font *)v13;
  if ( v15 )
  {
    if ( !_InterlockedExchangeAdd(v15 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v15)(v15);
      if ( !_InterlockedExchangeAdd(v15 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v15 + 4))(v15);
    }
  }
  item->title->fontScale = this->SIZE_MULT;
  if ( readIni )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"NAME", 4u);
    v38 = 2;
    v16 = INIReader::getString(v33, &result, sect, &key);
    LOBYTE(v38) = 3;
    std::operator+<wchar_t>(&nname, L" ", v16);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v38) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v17 = &nname;
    key._Bx._Buf[0] = 0;
    v18 = &nname;
    key._Myres = 7;
    if ( nname._Myres >= 8 )
      v18 = (std::wstring *)nname._Bx._Ptr;
    key._Mysize = 0;
    if ( nname._Myres >= 8 )
      v17 = (std::wstring *)nname._Bx._Ptr;
    _Dest._Ptr = (const wchar_t *)v18;
    v19 = &v17->_Bx._Buf[nname._Mysize];
    v20 = &nname;
    if ( nname._Myres >= 8 )
      v20 = (std::wstring *)nname._Bx._Ptr;
    if ( v20 != (std::wstring *)v19 )
      std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
        &_Dest,
        v20->_Bx._Buf,
        v19,
        _Dest,
        _toupper);
    item->title->setText(item->title, &nname);
    v34._Myres = 7;
    v34._Mysize = 0;
    v34._Bx._Buf[0] = 0;
    std::wstring::assign(&v34, L"MIN", 3u);
    v21 = v33;
    LOBYTE(v38) = 7;
    v22 = INIReader::getFloat(v33, sect, &v34);
    v23 = v34._Myres < 8;
    item->minValue = v22;
    LOBYTE(v38) = 6;
    if ( !v23 )
      operator delete(v34._Bx._Ptr);
    v34._Myres = 7;
    v34._Mysize = 0;
    v34._Bx._Buf[0] = 0;
    std::wstring::assign(&v34, L"MAX", 3u);
    LOBYTE(v38) = 8;
    v24 = INIReader::getFloat(v21, sect, &v34);
    v23 = v34._Myres < 8;
    item->maxValue = v24;
    LOBYTE(v38) = 6;
    if ( !v23 )
      operator delete(v34._Bx._Ptr);
    if ( &item->setupName != sect )
      std::wstring::assign(&item->setupName, sect, 0, 0xFFFFFFFF);
    v38 = -1;
    if ( nname._Myres >= 8 )
      operator delete(nname._Bx._Ptr);
  }
  ((void (*)(ksgui::Label *, _DWORD, _DWORD))item->value->setSize)(
    item->value,
    LODWORD(this->ITEM_VALUE_WIDTH),
    LODWORD(this->ITEM_HEIGHT));
  item->value->fontAlign = eAlignCenter;
  ksgui::Form::setPosition((ksgui::Form *)item->value, this->ITEM_TITLE_WIDTH, 0.0);
  v25 = this->font._Rep;
  v26 = item->value;
  v27 = this->font._Ptr;
  if ( v25 )
    _InterlockedExchangeAdd((volatile signed __int32 *)&v25->_Uses, 1u);
  v28 = (volatile signed __int32 *)v26->font._Rep;
  v26->font._Rep = v25;
  v26->font._Ptr = v27;
  if ( v28 )
  {
    if ( !_InterlockedExchangeAdd(v28 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v28)(v28);
      if ( !_InterlockedDecrement(v28 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v28 + 4))(v28);
    }
  }
  item->value->fontScale = this->SIZE_MULT;
  this->root->addControl(this->root, item->title);
  this->root->addControl(this->root, item->value);
}
void QuickMenuPitstop::getItemValues(QuickMenuPitstop *this, EQuickMenuPitstopType type, int componentIndex, QuickMenuPitstopItem *item)
{
  int v4; // ebp
  QuickMenuPitstopItem *v5; // edi
  int i; // esi

  v4 = 0;
  if ( this->items._Mylast - this->items._Myfirst )
  {
    v5 = this->items._Myfirst;
    for ( i = 0; v5[i].type != type || v5[i].componentIndex != componentIndex; ++i )
    {
      if ( ++v4 >= (unsigned int)(this->items._Mylast - v5) )
        return;
    }
    item->isFixed = v5[v4].isFixed;
    item->minValue = this->items._Myfirst[v4].minValue;
    item->maxValue = this->items._Myfirst[v4].maxValue;
  }
}
double QuickMenuPitstop::getMaxFuel(QuickMenuPitstop *this)
{
  return this->items._Myfirst[this->fuelIndex].maxValue;
}
double QuickMenuPitstop::getValue(QuickMenuPitstop *this, const QuickMenuPitstopItem *item)
{
  return this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[item->index];
}
double QuickMenuPitstop::getWingPitstopTime(QuickMenuPitstop *this, int componentIndex)
{
  int v2; // ebx
  QuickMenuPitstopItem *v3; // edi
  int i; // esi

  v2 = 0;
  if ( !(this->items._Mylast - this->items._Myfirst) )
    return 0.0;
  v3 = this->items._Myfirst;
  for ( i = 0; v3[i].type != Wing || v3[i].componentIndex != componentIndex; ++i )
  {
    if ( ++v2 >= (unsigned int)(this->items._Mylast - v3) )
      return 0.0;
  }
  return v3[v2].pitstopTime;
}
void QuickMenuPitstop::itemCompound(QuickMenuPitstop *this, const int direction, const int itemIndex)
{
  int v4; // esi
  bool v5; // sf
  CarAvatar *v6; // eax
  int v7; // ecx

  if ( direction )
  {
    v4 = (int)this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex];
    v5 = direction < 0;
    if ( direction > 0 )
    {
      v6 = Sim::getCar(this->sim, 0);
      v7 = (char *)v6->physicsInfo.tyreCompounds._Mylast - (char *)v6->physicsInfo.tyreCompounds._Myfirst;
      if ( v4 < (int)(((int)((unsigned __int64)(715827883i64 * v7) >> 32) >> 2)
                    + ((unsigned int)((unsigned __int64)(715827883i64 * v7) >> 32) >> 31)
                    - 1) )
      {
        ++v4;
        goto LABEL_10;
      }
      v5 = direction < 0;
    }
    if ( v5 && v4 >= 0 )
      --v4;
  }
  else
  {
    v4 = -1;
  }
LABEL_10:
  this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex] = (float)v4;
  QuickMenuPitstop::setLabels(this, itemIndex);
}
void QuickMenuPitstop::itemFuel(QuickMenuPitstop *this, const int direction, const int itemIndex)
{
  int v4; // edi
  QuickMenuPitstopItem *v5; // esi
  bool v6; // sf

  this->fuelIndex = itemIndex;
  if ( direction )
  {
    v4 = (int)this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex];
    v6 = direction < 0;
    if ( direction > 0 )
    {
      if ( (float)(this->items._Myfirst[itemIndex].maxValue - 1.0) >= (float)v4 )
      {
        ++v4;
        goto LABEL_10;
      }
      v6 = direction < 0;
    }
    if ( v6 && v4 > 0 )
      --v4;
  }
  else
  {
    v4 = 0;
    this->items._Myfirst[itemIndex].minValue = 0.0;
    v5 = &this->items._Myfirst[itemIndex];
    v5->maxValue = Sim::getCar(this->sim, 0)->physicsInfo.maxFuel;
  }
LABEL_10:
  this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex] = (float)v4;
  QuickMenuPitstop::setLabels(this, itemIndex);
}
void QuickMenuPitstop::itemPressure(QuickMenuPitstop *this, const int direction, const int itemIndex)
{
  CarAvatar *v4; // eax
  int v5; // edi
  int v6; // eax
  float v7; // xmm1_4
  QuickMenuPitstopItem *v8; // edx
  bool v9; // sf

  v4 = Sim::getCar(this->sim, 0);
  v5 = itemIndex;
  v6 = CarAvatar::getCurrentCompoundStaticPressure(v4, this->items._Myfirst[itemIndex].componentIndex);
  if ( direction )
  {
    v8 = this->items._Myfirst;
    if ( v8[v5].isFixed )
      return;
    v7 = (float)(int)this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex];
    v9 = direction < 0;
    if ( direction > 0 )
    {
      if ( v8[v5].maxValue > v7 )
      {
        v7 = v7 + 1.0;
        goto LABEL_11;
      }
      v9 = direction < 0;
    }
    if ( v9 && v7 > v8[v5].minValue )
      v7 = v7 - 1.0;
    goto LABEL_11;
  }
  v7 = (float)v6;
LABEL_11:
  this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex] = v7;
  QuickMenuPitstop::setLabels(this, itemIndex);
}
void QuickMenuPitstop::itemWing(QuickMenuPitstop *this, const int direction, const int itemIndex)
{
  CarAvatar *v4; // eax
  int v6; // edi
  float v7; // xmm2_4
  QuickMenuPitstopItem *v8; // edx
  bool v9; // sf
  float angle; // [esp+18h] [ebp+8h]

  v4 = Sim::getCar(this->sim, 0);
  v6 = itemIndex;
  angle = CarAvatar::getWingAngle(v4, this->items._Myfirst[itemIndex].componentIndex);
  if ( direction )
  {
    v8 = this->items._Myfirst;
    if ( v8[v6].isFixed )
      return;
    v7 = (float)(int)this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex];
    v9 = direction < 0;
    if ( direction > 0 )
    {
      if ( v8[v6].maxValue > (float)(v7 + angle) )
      {
        v7 = v7 + 1.0;
        goto LABEL_11;
      }
      v9 = direction < 0;
    }
    if ( v9 && (float)(v7 + angle) > v8[v6].minValue )
      v7 = v7 - 1.0;
    goto LABEL_11;
  }
  v7 = 0.0;
LABEL_11:
  this->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[itemIndex] = v7;
  QuickMenuPitstop::setLabels(this, itemIndex);
}
void QuickMenuPitstop::loadFixedSetup(QuickMenuPitstop *this, const std::wstring *path)
{
  bool v3; // cc
  float *v4; // ebx
  float *v5; // esi
  float *v6; // edi
  int v7; // eax
  int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // edi
  int v12; // esi
  unsigned int v13; // edi
  unsigned int v14; // esi
  unsigned int v15; // edi
  int v16; // ecx
  std::vector<std::vector<float>> *v17; // esi
  int v18; // edi
  unsigned int v19; // ebx
  int v20; // edi
  QuickMenuPitstopItem *v21; // ecx
  std::_Func_base<void,int,int> *v22; // ecx
  QuickMenuPitstopItem *v23; // ecx
  EQuickMenuPitstopType v24; // eax
  __int32 v25; // eax
  int v26; // eax
  std::wstring *v27; // edx
  float *v28; // esi
  QuickMenuPitstopItem *v29; // esi
  QuickMenuPitstopItem *v30; // esi
  QuickMenuPitstopItem *v31; // esi
  std::vector<float> vect; // [esp+14h] [ebp-D4h] BYREF
  unsigned int v33; // [esp+20h] [ebp-C8h] BYREF
  int v34; // [esp+24h] [ebp-C4h] BYREF
  int v35; // [esp+28h] [ebp-C0h]
  int v36; // [esp+30h] [ebp-B8h] BYREF
  std::wstring v37; // [esp+34h] [ebp-B4h] BYREF
  std::wstring key; // [esp+4Ch] [ebp-9Ch] BYREF
  std::wstring v39; // [esp+64h] [ebp-84h] BYREF
  std::wstring v40; // [esp+7Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+94h] [ebp-54h] BYREF
  int v42; // [esp+E4h] [ebp-4h]

  std::_Container_base0::_Orphan_all(&this->pitstopPresets);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
    (std::vector<unsigned char> *)this->pitstopPresets._Myfirst,
    (std::vector<unsigned char> *)this->pitstopPresets._Mylast);
  this->pitstopPresets._Mylast = this->pitstopPresets._Myfirst;
  INIReader::INIReader(&ini, path);
  v42 = 0;
  if ( !ini.ready )
    goto LABEL_59;
  v3 = this->PRESETS_COUNT <= 0;
  v35 = 0;
  if ( v3 )
    goto LABEL_59;
  do
  {
    v4 = 0;
    v5 = 0;
    v6 = 0;
    vect._Myfirst = 0;
    vect._Mylast = 0;
    vect._Myend = 0;
    LOBYTE(v42) = 1;
    v33 = 0;
    if ( this->items._Mylast - this->items._Myfirst )
    {
      v36 = 0;
      do
      {
        if ( &v36 >= (int *)v5 || v4 > (float *)&v36 )
        {
          if ( v5 == v6 && !(v6 - v5) )
          {
            v12 = v5 - v4;
            if ( v12 == 0x3FFFFFFF )
LABEL_60:
              std::_Xlength_error("vector<T> too long");
            v13 = v6 - v4;
            v14 = v12 + 1;
            if ( 0x3FFFFFFF - (v13 >> 1) >= v13 )
              v15 = (v13 >> 1) + v13;
            else
              v15 = 0;
            if ( v15 < v14 )
              v15 = v14;
            std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&vect, v15);
            v6 = vect._Myend;
            v5 = vect._Mylast;
            v4 = vect._Myfirst;
          }
          if ( !v5 )
            goto LABEL_31;
          *v5 = 0.0;
        }
        else
        {
          v7 = ((char *)&v36 - (char *)v4) >> 2;
          v34 = v7;
          if ( v5 == v6 )
          {
            if ( !(v6 - v5) )
            {
              v8 = v5 - v4;
              if ( v8 == 0x3FFFFFFF )
                goto LABEL_60;
              v9 = v6 - v4;
              v10 = v8 + 1;
              if ( 0x3FFFFFFF - (v9 >> 1) >= v9 )
                v11 = (v9 >> 1) + v9;
              else
                v11 = 0;
              if ( v11 < v10 )
                v11 = v10;
              std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&vect, v11);
              v6 = vect._Myend;
              v5 = vect._Mylast;
              v4 = vect._Myfirst;
            }
            v7 = v34;
          }
          if ( !v5 )
            goto LABEL_31;
          *v5 = v4[v7];
        }
        v6 = vect._Myend;
        v4 = vect._Myfirst;
        v5 = vect._Mylast;
LABEL_31:
        v16 = (char *)this->items._Mylast - (char *)this->items._Myfirst;
        ++v5;
        ++v33;
        vect._Mylast = v5;
      }
      while ( v33 < v16 / 88 );
    }
    v17 = &this->pitstopPresets;
    std::vector<std::vector<float>>::push_back(&this->pitstopPresets, &vect);
    v18 = v35;
    this->currentPreset = v35;
    v19 = 0;
    if ( !(this->items._Mylast - this->items._Myfirst) )
      goto LABEL_56;
    v20 = 0;
    do
    {
      v21 = this->items._Myfirst;
      if ( !v21[v20].function._Impl )
        goto LABEL_54;
      v34 = v19;
      v33 = 0;
      v22 = v21[v20].function._Impl;
      if ( !v22 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x5A6EDE);
      }
      v22->_Do_call(v22, (int *)&v33, &v34);
      v23 = this->items._Myfirst;
      v24 = v23[v20].type;
      if ( v24 == Fuel )
      {
        if ( !INIReader::hasSection(&ini, &v23[v20].setupName) )
          goto LABEL_52;
        v40._Myres = 7;
        v40._Mysize = 0;
        v40._Bx._Buf[0] = 0;
        std::wstring::assign(&v40, L"VALUE", 5u);
        v31 = this->items._Myfirst;
        LOBYTE(v42) = 2;
        v31[v20].maxValue = INIReader::getFloat(&ini, &v31[v20].setupName, &v40);
        LOBYTE(v42) = 1;
        if ( v40._Myres >= 8 )
          operator delete(v40._Bx._Ptr);
        goto LABEL_51;
      }
      v25 = v24 - 1;
      if ( !v25 )
      {
        if ( INIReader::hasSection(&ini, &v23[v20].setupName) )
        {
          this->items._Myfirst[v20].isFixed = 1;
          v17->_Myfirst[this->currentPreset]._Myfirst[v19] = 0.0;
        }
        goto LABEL_52;
      }
      if ( v25 == 2 && INIReader::hasSection(&ini, &v23[v20].setupName) )
      {
        this->items._Myfirst[v20].isFixed = 1;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"VALUE", 5u);
        v26 = this->currentPreset;
        v27 = &this->items._Myfirst->setupName;
        LOBYTE(v42) = 3;
        v28 = v17->_Myfirst[v26]._Myfirst;
        v28[v19] = INIReader::getFloat(&ini, (std::wstring *)((char *)v27 + v20 * 88), &key);
        LOBYTE(v42) = 1;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        v37._Myres = 7;
        v37._Mysize = 0;
        v37._Bx._Buf[0] = 0;
        std::wstring::assign(&v37, L"VALUE", 5u);
        v29 = this->items._Myfirst;
        LOBYTE(v42) = 4;
        v29[v20].minValue = INIReader::getFloat(&ini, &v29[v20].setupName, &v37);
        LOBYTE(v42) = 1;
        if ( v37._Myres >= 8 )
          operator delete(v37._Bx._Ptr);
        v37._Myres = 7;
        v37._Mysize = 0;
        v37._Bx._Buf[0] = 0;
        v39._Myres = 7;
        v39._Mysize = 0;
        v39._Bx._Buf[0] = 0;
        std::wstring::assign(&v39, L"VALUE", 5u);
        v30 = this->items._Myfirst;
        LOBYTE(v42) = 5;
        v30[v20].maxValue = INIReader::getFloat(&ini, &v30[v20].setupName, &v39);
        LOBYTE(v42) = 1;
        if ( v39._Myres >= 8 )
          operator delete(v39._Bx._Ptr);
LABEL_51:
        v17 = &this->pitstopPresets;
      }
LABEL_52:
      if ( !v35 )
        QuickMenuPitstop::setLabels(this, v19);
LABEL_54:
      ++v19;
      ++v20;
    }
    while ( v19 < this->items._Mylast - this->items._Myfirst );
    v18 = v35;
LABEL_56:
    LOBYTE(v42) = 0;
    if ( vect._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&vect);
      operator delete(vect._Myfirst);
      vect._Myfirst = 0;
      vect._Mylast = 0;
      vect._Myend = 0;
    }
    v35 = v18 + 1;
  }
  while ( v18 + 1 < this->PRESETS_COUNT );
LABEL_59:
  this->currentPreset = 0;
  v42 = -1;
  INIReader::~INIReader(&ini);
}
void QuickMenuPitstop::renderHUD(QuickMenuPitstop *this, float dt)
{
  Sim *v3; // ecx
  Sim *v4; // ecx
  EndSessionDisplayer *v5; // eax
  Sim *v6; // ecx
  CameraMode v7; // eax
  CarAvatar *v8; // eax
  float v9; // eax
  unsigned int v10; // edi
  float v11; // xmm0_4

  v3 = this->sim;
  if ( v3->escMenu->visible
    || v3->pauseMenu->visible
    || ReplayManager::isInReplaymode(v3->replayManager)
    || (v4 = this->sim, (v5 = v4->endSessionDisplayer) != 0) && v5->isActive
    || RaceManager::getCurrentSessionType(v4->raceManager) != Race
    && RaceManager::getCurrentSessionType(this->sim->raceManager) != Qualify
    && RaceManager::getCurrentSessionType(this->sim->raceManager) != Pratice
    || (v6 = this->sim, (v7 = v6->cameraManager->mode) != eCockpit) && v7 != eDrivable
    || !v6->gameScreen->appInteractionEnabled
    || Sim::getFocusedCarIndex(v6) )
  {
    this->timer = 0.0;
  }
  else
  {
    if ( this->AUTO_APP_ON_PITLANE )
    {
      v8 = Sim::getCar(this->sim, 0);
      if ( CarAvatar::isInPitlane(v8) )
      {
        v9 = this->VISIBILITY_MAX_TIME;
        this->isVisible = 1;
        this->timer = v9;
        QuickMenuPitstop::updateUI(this);
      }
    }
    if ( this->isVisible )
    {
      v10 = this->fuelIndex;
      if ( v10 < this->items._Mylast - this->items._Myfirst && this->items._Myfirst[v10].value->visible )
        QuickMenuPitstop::setLabels(this, this->fuelIndex);
      ((void (*)(ksgui::Control *, _DWORD))this->root->render)(this->root, LODWORD(dt));
    }
    v11 = this->timer;
    if ( v11 > 0.0 )
    {
      this->timer = v11 - dt;
      return;
    }
  }
  this->isVisible = 0;
}
void QuickMenuPitstop::resetControls(QuickMenuPitstop *this, const int itemIndex, float value)
{
  int v4; // edx
  int v5; // ecx

  v4 = 0;
  if ( this->PRESETS_COUNT > 0 )
  {
    v5 = 0;
    do
    {
      ++v5;
      ++v4;
      this->pitstopPresets._Myfirst[v5 - 1]._Myfirst[itemIndex] = value;
    }
    while ( v4 < this->PRESETS_COUNT );
  }
}
void QuickMenuPitstop::sendInput(QuickMenuPitstop *this, unsigned int key)
{
  bool v3; // zf
  unsigned int v4; // eax
  int v5; // edi
  QuickMenuPitstopItem *v6; // eax
  std::_Func_base<void,int,int> *v7; // ecx
  QuickMenuPitstopItem *v8; // eax
  int v9; // eax
  unsigned int v10; // edi
  int v11; // ecx
  unsigned int v12; // edi
  int v13; // ecx
  int v14; // [esp+4h] [ebp-4h] BYREF

  v3 = !this->isVisible;
  this->timer = this->VISIBILITY_MAX_TIME;
  if ( v3 )
  {
    this->isVisible = 1;
    this->currentIndex = -1;
    QuickMenuPitstop::updateUI(this);
    return;
  }
  v4 = key;
  v5 = this->currentIndex;
  if ( v5 < 0 )
  {
$LN78:
    if ( v4 == 37 )
    {
      v9 = this->currentPreset;
      if ( v9 > 0 )
      {
        v10 = 0;
        for ( this->currentPreset = v9 - 1; v10 < this->items._Mylast - this->items._Myfirst; ++v10 )
          QuickMenuPitstop::setLabels(this, v10);
      }
      goto LABEL_29;
    }
    if ( v4 == 39 )
    {
      v11 = this->currentPreset;
      if ( v11 < this->presets._Mylast - this->presets._Myfirst - 1 )
      {
        v12 = 0;
        for ( this->currentPreset = v11 + 1; v12 < this->items._Mylast - this->items._Myfirst; ++v12 )
          QuickMenuPitstop::setLabels(this, v12);
      }
      goto LABEL_29;
    }
    goto LABEL_23;
  }
  if ( key == 37 )
  {
    v6 = this->items._Myfirst;
    if ( v6[v5].function._Impl )
    {
      key = this->currentIndex;
      v14 = -1;
      v7 = v6[v5].function._Impl;
      if ( !v7 )
        std::_Xbad_function_call();
      goto $LN77_1;
    }
    goto LABEL_29;
  }
  if ( key == 39 )
  {
    v8 = this->items._Myfirst;
    if ( !v8[v5].function._Impl )
      goto LABEL_29;
    key = this->currentIndex;
    v14 = 1;
    v7 = v8[v5].function._Impl;
    if ( v7 )
    {
$LN77_1:
      v7->_Do_call(v7, &v14, (int *)&key);
      QuickMenuPitstop::updateUI(this);
      return;
    }
    std::_Xbad_function_call();
    goto $LN78;
  }
LABEL_23:
  if ( v4 == 38 )
  {
    if ( v5 >= 0 )
    {
      this->currentIndex = v5 - 1;
      QuickMenuPitstop::updateUI(this);
      return;
    }
  }
  else if ( v4 == 40 )
  {
    v13 = (char *)this->items._Mylast - (char *)this->items._Myfirst;
    if ( v5 < (int)(((int)((unsigned __int64)(780903145i64 * v13) >> 32) >> 4)
                  + ((unsigned int)((unsigned __int64)(780903145i64 * v13) >> 32) >> 31)
                  - 1) )
      this->currentIndex = v5 + 1;
  }
LABEL_29:
  QuickMenuPitstop::updateUI(this);
}
void QuickMenuPitstop::setLabels(QuickMenuPitstop *this, const int itemIndex)
{
  CarAvatar *v3; // ebp
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // edi
  float v7; // xmm0_4
  QuickMenuPitstopItem *v8; // eax
  Sim *v9; // ecx
  RaceEngineer *v10; // ecx
  Car *v11; // eax
  int v12; // eax
  unsigned int v13; // ebx
  int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  double v17; // st7
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v21; // ecx
  float v22; // xmm1_4
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  ksgui::Label *v26; // esi
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  ksgui::Label_vtbl *v30; // edx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v31; // ecx
  int *v32; // ebx
  int v33; // esi
  std::wstring *v34; // edi
  std::wstring *v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // eax
  std::wstring *v38; // eax
  std::wstring *v39; // eax
  int v40; // edx
  std::wstring *v41; // edi
  std::wstring *v42; // eax
  std::wstring *v43; // eax
  std::wstring *v44; // eax
  std::wstring *v45; // eax
  int v46; // edx
  int *v47; // esi
  std::wstring *v48; // eax
  int v49; // edx
  QuickMenuPitstopItem *v50; // eax
  int *v51; // esi
  std::wstring *v52; // eax
  int v53; // edx
  const wchar_t *v54; // ecx
  QuickMenuPitstopItem *v55; // eax
  float v56; // [esp+14h] [ebp-2D0h]
  float v57; // [esp+14h] [ebp-2D0h]
  float fuelSperimental; // [esp+18h] [ebp-2CCh]
  std::wstring laps; // [esp+1Ch] [ebp-2C8h] BYREF
  std::wstring v60; // [esp+34h] [ebp-2B0h] BYREF
  std::wstring v61; // [esp+4Ch] [ebp-298h] BYREF
  std::wstring v62; // [esp+64h] [ebp-280h] BYREF
  std::wstring v63; // [esp+7Ch] [ebp-268h] BYREF
  std::wstring v64; // [esp+94h] [ebp-250h] BYREF
  std::wstring result; // [esp+ACh] [ebp-238h] BYREF
  std::wstring v66; // [esp+C4h] [ebp-220h] BYREF
  std::wstring v67; // [esp+DCh] [ebp-208h] BYREF
  std::wstring v68; // [esp+F4h] [ebp-1F0h] BYREF
  std::wstring v69; // [esp+10Ch] [ebp-1D8h] BYREF
  std::wstring v70; // [esp+124h] [ebp-1C0h] BYREF
  std::wstring v71; // [esp+13Ch] [ebp-1A8h] BYREF
  std::wstring v72; // [esp+154h] [ebp-190h] BYREF
  std::wstring v73; // [esp+16Ch] [ebp-178h] BYREF
  std::wstring v74; // [esp+184h] [ebp-160h] BYREF
  std::wstring v75; // [esp+19Ch] [ebp-148h] BYREF
  std::wstring v76; // [esp+1B4h] [ebp-130h] BYREF
  std::wstring v77; // [esp+1CCh] [ebp-118h] BYREF
  std::wstring v78; // [esp+1E4h] [ebp-100h] BYREF
  std::wstring v79; // [esp+1FCh] [ebp-E8h] BYREF
  std::wstring v80; // [esp+214h] [ebp-D0h] BYREF
  std::wstring v81; // [esp+22Ch] [ebp-B8h] BYREF
  std::wstring v82; // [esp+244h] [ebp-A0h] BYREF
  std::wstring v83; // [esp+25Ch] [ebp-88h] BYREF
  Session session; // [esp+274h] [ebp-70h] BYREF
  int v85; // [esp+2E0h] [ebp-4h]

  v3 = Sim::getCar(this->sim, 0);
  v4 = this->currentPreset;
  if ( v4 < this->pitstopPresets._Mylast - this->pitstopPresets._Myfirst )
  {
    v5 = v4;
    v6 = itemIndex;
    v7 = this->pitstopPresets._Myfirst[v5]._Myfirst[itemIndex];
    v8 = this->items._Myfirst;
    v56 = v7;
    switch ( v8[itemIndex].type )
    {
      case Fuel:
        std::wstring::wstring(&laps, word_17BE9D8);
        v9 = this->sim;
        v85 = 0;
        RaceManager::getCurrentSession(v9->raceManager, &session);
        v10 = v3->raceEngineer._Myptr;
        LOBYTE(v85) = 1;
        if ( v10 && (session.sessionType == Race || session.sessionType == Qualify || session.sessionType == Pratice) )
        {
          v11 = RaceEngineer::getCar(v10);
          fuelSperimental = FuelLapEvaluator::getFuelPerLap(&v11->fuelLapEvaluator);
          if ( fuelSperimental > 0.0 )
          {
            v12 = RaceManager::getLapCount(this->sim->raceManager, v3);
            v13 = v12;
            if ( session.sessionType == Race && session.isTimedRace && v12 )
            {
              v14 = RaceManager::getSessionTotalTime(this->sim->raceManager, 0);
              v15 = this->items._Myfirst[v6].maxValue;
              if ( v7 <= v15 )
              {
                v15 = 0.0;
                if ( v7 >= 0.0 )
                  v15 = v7;
              }
              v16 = (float)v13;
              v17 = floor<int>((int)(float)((float)(v15 / fuelSperimental)
                                          * (float)((float)((float)((float)v14 * 0.001) * 0.016666668)
                                                  / (float)(v16 + v3->physicsState.normalizedSplinePosition))));
              v18 = std::to_wstring(&result, (int)v17);
              LOBYTE(v85) = 2;
              v19 = std::operator+<wchar_t>(&v79, L" (+", v18);
              LOBYTE(v85) = 3;
              v20 = std::operator+<wchar_t>(&v71, v19, L"Mins)");
              std::wstring::operator=(&laps, v20);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
              v21 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
            }
            else
            {
              v22 = this->items._Myfirst[v6].maxValue;
              if ( v7 <= v22 )
              {
                v22 = 0.0;
                if ( v7 >= 0.0 )
                  v22 = v7;
              }
              v23 = std::to_wstring(&v83, (int)(float)(v22 / fuelSperimental));
              LOBYTE(v85) = 4;
              v24 = std::operator+<wchar_t>(&v67, L" (+", v23);
              LOBYTE(v85) = 5;
              v25 = std::operator+<wchar_t>(&v75, v24, L"Laps)");
              std::wstring::operator=(&laps, v25);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v67);
              v21 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83;
            }
            LOBYTE(v85) = 1;
            std::wstring::~wstring(v21);
          }
        }
        v26 = this->items._Myfirst[v6].value;
        v27 = std::to_wstring(&v62, (int)v56);
        LOBYTE(v85) = 6;
        v28 = std::operator+<wchar_t>(&v77, L"+", v27);
        LOBYTE(v85) = 7;
        v29 = std::operator+<wchar_t>(&v69, v28, &laps);
        v30 = v26->__vftable;
        LOBYTE(v85) = 8;
        v30->setText(v26, v29);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        Session::~Session(&session);
        v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&laps;
        goto LABEL_31;
      case Wing:
        v32 = (int *)v8[v6].value;
        v33 = (int)v7;
        v57 = CarAvatar::getWingAngle(v3, v8[v6].componentIndex);
        if ( v7 < 0.0 )
        {
          v41 = std::to_wstring(&v78, v33 + (int)v57);
          v85 = 15;
          v42 = std::to_wstring(&v76, v33);
          LOBYTE(v85) = 16;
          v43 = std::operator+<wchar_t>(&v74, v42, L" (");
          LOBYTE(v85) = 17;
          v44 = std::operator+<wchar_t>(&v72, v43, v41);
          LOBYTE(v85) = 18;
          v45 = std::operator+<wchar_t>(&v70, v44, L")");
          v46 = *v32;
          LOBYTE(v85) = 19;
          (*(void (**)(int *, std::wstring *))(v46 + 68))(v32, v45);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76);
          v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78;
        }
        else
        {
          v34 = std::to_wstring(&v68, v33 + (int)v57);
          v85 = 9;
          v35 = std::to_wstring(&v66, v33);
          LOBYTE(v85) = 10;
          v36 = std::operator+<wchar_t>(&v64, L"+", v35);
          LOBYTE(v85) = 11;
          v37 = std::operator+<wchar_t>(&v63, v36, L" (");
          LOBYTE(v85) = 12;
          v38 = std::operator+<wchar_t>(&v73, v37, v34);
          LOBYTE(v85) = 13;
          v39 = std::operator+<wchar_t>(&v81, v38, L")");
          v40 = *v32;
          LOBYTE(v85) = 14;
          (*(void (**)(int *, std::wstring *))(v40 + 68))(v32, v39);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v81);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v64);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v66);
          v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68;
        }
        goto LABEL_31;
      case TyreCompound:
        if ( v7 < 0.0 )
        {
          std::wstring::wstring(&v60, L"NO CHANGE");
          v50 = this->items._Myfirst;
          v85 = 21;
          v50[v6].value->setText(v50[v6].value, &v60);
          v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v60;
        }
        else
        {
          v47 = (int *)v8[v6].value;
          v48 = CarAvatar::getTyreCompound(v3, &v80, (int)v7, 0);
          v49 = *v47;
          v85 = 20;
          (*(void (**)(int *, std::wstring *))(v49 + 68))(v47, v48);
          v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v80;
        }
        goto LABEL_31;
      case TyrePressure:
        v51 = (int *)v8[v6].value;
        v52 = std::to_wstring(&v82, (int)v7);
        v53 = *v51;
        v85 = 22;
        (*(void (**)(int *, std::wstring *))(v53 + 68))(v51, v52);
        v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v82;
        goto LABEL_31;
      case Repair:
        v54 = L"NO";
        if ( (int)v7 )
          v54 = L"YES";
        std::wstring::wstring(&v61, v54);
        v55 = this->items._Myfirst;
        v85 = 23;
        v55[v6].value->setText(v55[v6].value, &v61);
        v31 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61;
LABEL_31:
        std::wstring::~wstring(v31);
        break;
      default:
        return;
    }
  }
}
void QuickMenuPitstop::updateUI(QuickMenuPitstop *this)
{
  unsigned int i; // ecx
  unsigned int v3; // edi
  int v4; // ebx
  QuickMenuPitstopItem *v5; // ecx
  QuickMenuPitstopItem *v6; // ecx
  unsigned int j; // edi

  for ( i = 0; i < this->presets._Mylast - this->presets._Myfirst; ++i )
  {
    this->presets._Myfirst[i]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_BACKGROUND_UNSELECTED);
    this->presets._Myfirst[i]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_FOREGROUND_UNSELECTED);
    if ( i == this->currentPreset )
    {
      this->presets._Myfirst[i]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_BACKGROUND_SELECTED);
      this->presets._Myfirst[i]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_FOREGROUND_SELECTED);
    }
  }
  v3 = 0;
  if ( this->items._Mylast - this->items._Myfirst )
  {
    v4 = 0;
    do
    {
      v5 = &this->items._Myfirst[v4];
      v5->title->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_BACKGROUND_UNSELECTED);
      v5->title->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_FOREGROUND_UNSELECTED);
      v5->value->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_BACKGROUND_UNSELECTED);
      v5->value->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_FOREGROUND_UNSELECTED);
      if ( v3 == this->currentIndex )
      {
        v6 = &this->items._Myfirst[v4];
        v6->title->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_BACKGROUND_SELECTED);
        v6->title->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_FOREGROUND_SELECTED);
        v6->value->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_BACKGROUND_SELECTED);
        v6->value->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->ITEM_FOREGROUND_SELECTED);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->items._Mylast - this->items._Myfirst );
  }
  for ( j = 0; j < this->items._Mylast - this->items._Myfirst; ++j )
    QuickMenuPitstop::setLabels(this, j);
}
