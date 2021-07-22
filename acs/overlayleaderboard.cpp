#include "overlayleaderboard.h
void OverlayLeaderboard::OverlayLeaderboard(OverlayLeaderboard *this, Sim *aSim)
{
  std::vector<OverlayLeaderboard::DriverName> *v3; // esi
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  unsigned int v7; // ebx
  Font *v8; // eax
  Font *v9; // eax
  std::_Ref_count_base *v10; // edi
  Font *v11; // eax
  Font *v12; // eax
  std::_Ref_count_base *v13; // edi
  char v14; // bl
  OverlayLeaderboard::GapMode v15; // eax
  bool v16; // cf
  char v17; // bl
  int v18; // eax
  Sim *v19; // ecx
  unsigned int v20; // edx
  int v21; // eax
  Sim *v22; // ecx
  OverlayLeaderboard::DriverName *v23; // eax
  OverlayLeaderboard::DriverName *v24; // edi
  OverlayLeaderboard::DriverName *v25; // ebx
  int v26; // edi
  int v27; // ebx
  OverlayLeaderboard::DriverName *v28; // edi
  unsigned int v29; // ebx
  std::wstring *v30; // ecx
  std::wstring *v31; // eax
  OverlayLeaderboard::DriverName *v32; // edi
  Sim *v33; // eax
  std::wstring v34; // [esp-10h] [ebp-F8h] BYREF
  unsigned int v35; // [esp+8h] [ebp-E0h]
  std::shared_ptr<Font> _Right; // [esp+20h] [ebp-C8h] BYREF
  Font *v37; // [esp+28h] [ebp-C0h]
  OverlayLeaderboard::DriverName *v38; // [esp+2Ch] [ebp-BCh]
  OverlayLeaderboard *v39; // [esp+30h] [ebp-B8h]
  std::wstring key; // [esp+34h] [ebp-B4h] BYREF
  std::wstring section; // [esp+4Ch] [ebp-9Ch] BYREF
  OverlayLeaderboard::DriverName dName; // [esp+64h] [ebp-84h] BYREF
  INIReaderDocuments acINI; // [esp+94h] [ebp-54h] BYREF
  int v44; // [esp+E4h] [ebp-4h]

  v39 = this;
  v35 = (unsigned int)aSim->game;
  v34._Myres = 7;
  v34._Mysize = 0;
  v34._Bx._Buf[0] = 0;
  std::wstring::assign(&v34, L"TOP_OVERLAY_LEADERBOARD", 0x17u);
  GameObject::GameObject(this, v34, (Game *)v35);
  v44 = 0;
  this->__vftable = (OverlayLeaderboard_vtbl *)&OverlayLeaderboard::`vftable';
  this->gapDisplayMode = 3;
  Trigger::Trigger(&this->keySwitchMode);
  this->verticalLayout = 0;
  this->maxSectorsSize = 0.0;
  this->maxTimer = 10.0;
  this->backColor.x = 0.079999998;
  this->backColor.y = 0.079999998;
  this->backColor.z = 0.079999998;
  this->backColor.w = 0.80000001;
  this->timer = 0.0;
  this->sim = aSim;
  this->positionFont._Ptr = 0;
  this->positionFont._Rep = 0;
  this->nameFont._Ptr = 0;
  this->nameFont._Rep = 0;
  this->timeFont._Ptr = 0;
  this->timeFont._Rep = 0;
  this->selectedLaps._Myfirst = 0;
  this->selectedLaps._Mylast = 0;
  this->selectedLaps._Myend = 0;
  v3 = &this->driverNames;
  this->driverNames._Myfirst = 0;
  this->driverNames._Mylast = 0;
  this->driverNames._Myend = 0;
  LOBYTE(v44) = 6;
  v4 = (Font *)operator new(24);
  v37 = v4;
  LOBYTE(v44) = 7;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 30.0, 0, 1);
  else
    v5 = 0;
  LOBYTE(v44) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v5);
  std::shared_ptr<Font>::operator=(&this->positionFont, &_Right);
  v6 = _Right._Rep;
  v7 = -1;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Weaks, 0xFFFFFFFF) )
        v6->_Delete_this(v6);
    }
  }
  v8 = (Font *)operator new(24);
  v37 = v8;
  LOBYTE(v44) = 8;
  if ( v8 )
    Font::Font(v8, eFontMonospaced, 19.0, 0, 1);
  else
    v9 = 0;
  LOBYTE(v44) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v9);
  std::shared_ptr<Font>::operator=(&this->nameFont, &_Right);
  v10 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v10->_Destroy(v10);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v10->_Weaks, 0xFFFFFFFF) )
        v10->_Delete_this(v10);
    }
  }
  v11 = (Font *)operator new(24);
  v37 = v11;
  LOBYTE(v44) = 9;
  if ( v11 )
    Font::Font(v11, eFontMonospaced, 14.0, 0, 0);
  else
    v12 = 0;
  LOBYTE(v44) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v12);
  std::shared_ptr<Font>::operator=(&this->timeFont, &_Right);
  v13 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v13->_Destroy(v13);
      v7 = _InterlockedDecrement((volatile signed __int32 *)&v13->_Weaks);
      if ( !v7 )
        v13->_Delete_this(v13);
    }
  }
  v35 = 0;
  this->verticalLayout = 0;
  this->gapDisplayMode = Off;
  this->maxSectorsSize = 0.0;
  v34._Myres = 7;
  v34._Mysize = 0;
  v34._Bx._Buf[0] = 0;
  std::wstring::assign(&v34, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&acINI, v7, v34, v35);
  LOBYTE(v44) = 10;
  if ( acINI.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ACTIVE", 6u);
    LOBYTE(v44) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"OVERLAY_LEADERBOARD", 0x13u);
    LOBYTE(v44) = 12;
    v14 = INIReader::hasKey(&acINI, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v44) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v14 )
    {
      std::wstring::wstring(&section, L"ACTIVE");
      LOBYTE(v44) = 13;
      std::wstring::wstring(&key, L"OVERLAY_LEADERBOARD");
      LOBYTE(v44) = 14;
      v15 = INIReader::getInt(&acINI, &key, &section);
      v16 = key._Myres < 8;
      this->gapDisplayMode = v15;
      if ( !v16 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v44) = 10;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"VERTICAL", 8u);
    LOBYTE(v44) = 15;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"OVERLAY_LEADERBOARD", 0x13u);
    LOBYTE(v44) = 16;
    v17 = INIReader::hasKey(&acINI, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v44) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v17 )
    {
      std::wstring::wstring(&section, L"VERTICAL");
      LOBYTE(v44) = 17;
      std::wstring::wstring(&key, L"OVERLAY_LEADERBOARD");
      LOBYTE(v44) = 18;
      v18 = INIReader::getInt(&acINI, &key, &section);
      v16 = key._Myres < 8;
      this->verticalLayout = v18 != 0;
      if ( !v16 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
  }
  v19 = this->sim;
  if ( v19->microSectors->enabled )
    this->maxSectorsSize = 10.0;
  v20 = 0;
  v21 = v19->cars._Mylast - v19->cars._Myfirst;
  v37 = 0;
  if ( v21 )
  {
    do
    {
      dName.completeName._Myres = 7;
      dName.completeName._Mysize = 0;
      dName.completeName._Bx._Buf[0] = 0;
      dName.shortName._Myres = 7;
      dName.shortName._Mysize = 0;
      dName.shortName._Bx._Buf[0] = 0;
      v22 = this->sim;
      LOBYTE(v44) = 19;
      v23 = (OverlayLeaderboard::DriverName *)&Sim::getCar(v22, v20)->driverInfo;
      if ( &dName != v23 )
        std::wstring::assign(&dName.completeName, &v23->completeName, 0, 0xFFFFFFFF);
      v24 = (OverlayLeaderboard::DriverName *)OverlayLeaderboard::filterName(this, &key, &dName.completeName);
      if ( &dName.shortName != (std::wstring *)v24 )
      {
        if ( dName.shortName._Myres >= 8 )
          operator delete(dName.shortName._Bx._Ptr);
        dName.shortName._Myres = 7;
        dName.shortName._Mysize = 0;
        dName.shortName._Bx._Buf[0] = 0;
        if ( v24->completeName._Myres >= 8 )
        {
          dName.shortName._Bx._Ptr = v24->completeName._Bx._Ptr;
          v24->completeName._Bx._Ptr = 0;
        }
        else if ( v24->completeName._Mysize != -1 )
        {
          _memmove(&dName.shortName, v24, 2 * (v24->completeName._Mysize + 1));
        }
        dName.shortName._Mysize = v24->completeName._Mysize;
        dName.shortName._Myres = v24->completeName._Myres;
        v24->completeName._Myres = 7;
        v24->completeName._Mysize = 0;
        v24->completeName._Bx._Buf[0] = 0;
      }
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v25 = this->driverNames._Mylast;
      if ( &dName >= v25 || v3->_Myfirst > &dName )
      {
        if ( v25 == this->driverNames._Myend )
          std::vector<OverlayLeaderboard::DriverName>::_Reserve(&this->driverNames, 1u);
        v32 = this->driverNames._Mylast;
        _Right._Ptr = (Font *)v32;
        v38 = v32;
        LOBYTE(v44) = 22;
        if ( !v32 )
          goto LABEL_67;
        v32->completeName._Myres = 7;
        v35 = -1;
        v32->completeName._Mysize = 0;
        v34._Myres = 0;
        v32->completeName._Bx._Buf[0] = 0;
        std::wstring::assign(&v32->completeName, &dName.completeName, v34._Myres, v35);
        v30 = &v32->shortName;
        v32->shortName._Myres = 7;
        v32->shortName._Mysize = 0;
        v32->shortName._Bx._Buf[0] = 0;
        v31 = &dName.shortName;
        LOBYTE(v44) = 23;
      }
      else
      {
        v26 = &dName - v3->_Myfirst;
        if ( v25 == this->driverNames._Myend )
          std::vector<OverlayLeaderboard::DriverName>::_Reserve(&this->driverNames, 1u);
        v27 = v26;
        v28 = this->driverNames._Mylast;
        v29 = (unsigned int)&v3->_Myfirst[v27];
        v38 = v28;
        _Right._Ptr = (Font *)v28;
        LOBYTE(v44) = 20;
        if ( !v28 )
          goto LABEL_67;
        v28->completeName._Myres = 7;
        v35 = -1;
        v34._Myres = 0;
        v28->completeName._Mysize = 0;
        v34._Mysize = v29;
        v28->completeName._Bx._Buf[0] = 0;
        std::wstring::assign(&v28->completeName, (const std::wstring *)v34._Mysize, v34._Myres, v35);
        v30 = &v28->shortName;
        v28->shortName._Myres = 7;
        v28->shortName._Mysize = 0;
        v28->shortName._Bx._Buf[0] = 0;
        v31 = (std::wstring *)(v29 + 24);
        LOBYTE(v44) = 21;
      }
      std::wstring::assign(v30, v31, 0, 0xFFFFFFFF);
LABEL_67:
      ++this->driverNames._Mylast;
      if ( dName.shortName._Myres >= 8 )
        operator delete(dName.shortName._Bx._Ptr);
      dName.shortName._Myres = 7;
      dName.shortName._Mysize = 0;
      dName.shortName._Bx._Buf[0] = 0;
      if ( dName.completeName._Myres >= 8 )
        operator delete(dName.completeName._Bx._Ptr);
      v33 = this->sim;
      v20 = (unsigned int)&v37->scale + 1;
      v37 = (Font *)v20;
    }
    while ( v20 < v33->cars._Mylast - v33->cars._Myfirst );
  }
  LOBYTE(v44) = 6;
  INIReaderDocuments::~INIReaderDocuments(&acINI);
}
void OverlayLeaderboard::~OverlayLeaderboard(OverlayLeaderboard *this)
{
  std::vector<OverlayLeaderboard::DriverName> *v2; // edi
  std::vector<Lap> *v3; // edi
  std::_Ref_count_base *v4; // edi
  std::_Ref_count_base *v5; // edi
  std::_Ref_count_base *v6; // edi

  this->__vftable = (OverlayLeaderboard_vtbl *)&OverlayLeaderboard::`vftable';
  v2 = &this->driverNames;
  if ( this->driverNames._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->driverNames);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<OverlayLeaderboard::DriverName>>>(v2->_Myfirst, v2->_Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = &this->selectedLaps;
  if ( this->selectedLaps._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->selectedLaps);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(v3->_Myfirst, this->selectedLaps._Mylast);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->selectedLaps._Mylast = 0;
    this->selectedLaps._Myend = 0;
  }
  v4 = this->timeFont._Rep;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Uses, 0xFFFFFFFF) )
    {
      v4->_Destroy(v4);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Weaks, 0xFFFFFFFF) )
        v4->_Delete_this(v4);
    }
  }
  v5 = this->nameFont._Rep;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v5->_Uses, 0xFFFFFFFF) )
    {
      v5->_Destroy(v5);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v5->_Weaks, 0xFFFFFFFF) )
        v5->_Delete_this(v5);
    }
  }
  v6 = this->positionFont._Rep;
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->keySwitchMode);
  GameObject::~GameObject(this);
}
OverlayLeaderboard *OverlayLeaderboard::`scalar deleting destructor'(OverlayLeaderboard *this, unsigned int a2)
{
  OverlayLeaderboard::~OverlayLeaderboard(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void OverlayLeaderboard::drawCell(OverlayLeaderboard *this, const LeaderboardEntry *entry, int position, const std::wstring *time, float x, float y, SessionType ses_type)
{
  Game *v8; // eax
  const std::wstring *v9; // ebp
  Sim *v10; // ecx
  GLRenderer *v11; // esi
  bool v12; // zf
  vec4f *v13; // eax
  const std::wstring *v14; // eax
  Font *v15; // ecx
  DriverInfo *v16; // esi
  int v17; // ecx
  unsigned int v18; // eax
  OverlayLeaderboard::DriverName *v19; // ecx
  std::wstring *v20; // ebp
  CarAvatar *v21; // ecx
  std::wstring *v22; // esi
  DriverInfo *v23; // esi
  OverlayLeaderboard::DriverName *v24; // ecx
  CarAvatar *v25; // eax
  Font *v26; // ecx
  int v27; // eax
  OverlayLeaderboard::GapMode v28; // eax
  const std::wstring *v29; // eax
  Font *v30; // ecx
  Font *v31; // ecx
  const std::wstring *v32; // eax
  Font *v33; // ecx
  float v34; // xmm1_4
  GLRenderer *v35; // esi
  int v36; // eax
  vec4f width; // [esp+1Ch] [ebp-150h]
  float backColor; // [esp+44h] [ebp-128h]
  float backColor_4; // [esp+48h] [ebp-124h]
  float backColor_12; // [esp+50h] [ebp-11Ch]
  int v41; // [esp+58h] [ebp-114h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+5Ch] [ebp-110h] BYREF
  vec4f DEFAULT_BACKGROUND; // [esp+10Ch] [ebp-60h] BYREF
  vec4f PLAYER_BACKGROUND; // [esp+11Ch] [ebp-50h] BYREF
  std::wstring result; // [esp+12Ch] [ebp-40h] BYREF
  std::wstring text; // [esp+144h] [ebp-28h] BYREF
  int v47; // [esp+168h] [ebp-4h]

  v41 = 0;
  v8 = this->game;
  v9 = time;
  v10 = this->sim;
  PLAYER_BACKGROUND = (vec4f)_xmm;
  DEFAULT_BACKGROUND = (vec4f)_xmm;
  backColor_4 = (float)(x + 40.0) + 10.0;
  v11 = v8->graphics->gl;
  backColor_12 = (float)(x + 170.0) - 5.0;
  backColor = y + 20.0;
  v12 = entry->car == Sim::getCar(v10, 0);
  v13 = &PLAYER_BACKGROUND;
  if ( !v12 )
    v13 = &DEFAULT_BACKGROUND;
  GLRenderer::color4f(v11, v13);
  GLRenderer::quad(v11, x, y, 40.0, 40.0, 0, 0);
  *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(ws.gap68);
  v47 = 0;
  v41 = 1;
  std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
  v47 = 1;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v41 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&ws.gap10[8]);
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&ws.gap10[64] = 0;
  *(_DWORD *)&ws.gap10[68] = 0;
  v47 = 3;
  std::wostream::operator<<(ws.gap10, position);
  Font::setColor(this->positionFont._Ptr, 0.0, 0.0, 0.0, 1.0);
  v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ws, &result);
  v15 = this->positionFont._Ptr;
  LOBYTE(v47) = 4;
  Font::blitString(v15, x + 20.0, y, v14, 1.0, eAlignCenter);
  LOBYTE(v47) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v16 = &entry->car->driverInfo;
  v17 = CarAvatar::getGuid(entry->car);
  v18 = v16->name._Mysize;
  v19 = &this->driverNames._Myfirst[v17];
  if ( v16->name._Myres >= 8 )
    v16 = (DriverInfo *)v16->name._Bx._Ptr;
  if ( std::wstring::compare(&v19->completeName, 0, v19->completeName._Mysize, v16->name._Bx._Buf, v18) )
  {
    v20 = OverlayLeaderboard::filterName(this, &result, &entry->car->driverInfo.name);
    v21 = entry->car;
    LOBYTE(v47) = 5;
    v22 = &this->driverNames._Myfirst[CarAvatar::getGuid(v21)].shortName;
    if ( v22 != v20 )
    {
      if ( v22->_Myres >= 8 )
        operator delete(v22->_Bx._Ptr);
      v22->_Myres = 7;
      v22->_Mysize = 0;
      v22->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(v22, v20);
    }
    LOBYTE(v47) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v23 = &entry->car->driverInfo;
    v24 = &this->driverNames._Myfirst[CarAvatar::getGuid(entry->car)];
    if ( v24 != (OverlayLeaderboard::DriverName *)v23 )
      std::wstring::assign(&v24->completeName, &v23->name, 0, 0xFFFFFFFF);
    v9 = time;
  }
  v25 = Sim::getCar(this->sim, 0);
  v26 = this->nameFont._Ptr;
  if ( entry->car == v25 )
    Font::setColor(v26, 1.0, 0.80000001, 0.0, 1.0);
  else
    Font::setColor(v26, 1.0, 1.0, 1.0, 1.0);
  v27 = CarAvatar::getGuid(entry->car);
  Font::blitString(this->nameFont._Ptr, backColor_4, y, &this->driverNames._Myfirst[v27].shortName, 1.0, eAlignLeft);
  if ( ses_type == Race && ((v28 = this->gapDisplayMode, v28 == 2) || v28 == 3 && this->timer < 0.0) )
    Font::setColor(this->timeFont._Ptr, 1.0, 0.80000001, 0.0, 1.0);
  else
    Font::setColor(this->timeFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  if ( entry->car->isBlackFlagged )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Retired", 7u);
    LOBYTE(v47) = 6;
    v29 = acTranslate(&result, &text);
    v30 = this->timeFont._Ptr;
    LOBYTE(v47) = 7;
    Font::blitString(v30, backColor_4, backColor, v29, 1.0, eAlignLeft);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v47) = 3;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  else
  {
    if ( CarAvatar::isInPitlane(entry->car) )
    {
      std::wstring::wstring(&result, L" PIT");
      v31 = this->timeFont._Ptr;
      LOBYTE(v47) = 8;
      Font::blitString(v31, backColor_12, backColor, &result, 0.80000001, eAlignRight);
      LOBYTE(v47) = 3;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    else
    {
      v32 = CarAvatar::getCurrentCompoundShortName(entry->car, &result);
      v33 = this->timeFont._Ptr;
      LOBYTE(v47) = 9;
      Font::blitString(v33, backColor_12, backColor, v32, 0.80000001, eAlignRight);
      LOBYTE(v47) = 3;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    Font::blitString(this->timeFont._Ptr, backColor_4, backColor, v9, 1.0, eAlignLeft);
  }
  v34 = this->maxSectorsSize;
  if ( v34 > 0.0 )
  {
    v35 = this->game->graphics->gl;
    width = (vec4f)_mm_loadu_si128((const __m128i *)&this->backColor);
    v36 = CarAvatar::getGuid(entry->car);
    MicroSectors::drawSectors(this->sim->microSectors, v35, v36, x, y + 40.0, 169.0, v34, width);
  }
  v47 = -1;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v41 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&ws.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ws.gap68);
}
void OverlayLeaderboard::drawVerticalCell(OverlayLeaderboard *this, const LeaderboardEntry *entry, int position, const std::wstring *time, float x, float y, SessionType ses_type)
{
  int v8; // ebp
  GLRenderer *v9; // esi
  float v10; // xmm1_4
  GLRenderer *v11; // esi
  int v12; // eax
  DriverInfo *v13; // esi
  int v14; // ecx
  unsigned int v15; // eax
  OverlayLeaderboard::DriverName *v16; // ecx
  std::wstring *v17; // ebp
  CarAvatar *v18; // ecx
  std::wstring *v19; // esi
  DriverInfo *v20; // esi
  OverlayLeaderboard::DriverName *v21; // ecx
  CarAvatar *v22; // eax
  Font *v23; // ecx
  const std::wstring *v24; // eax
  Font *v25; // ecx
  int v26; // eax
  OverlayLeaderboard::GapMode v27; // eax
  Font *v28; // ecx
  Font *v29; // ecx
  const std::wstring *v30; // eax
  Font *v31; // ecx
  vec4f r; // [esp+10h] [ebp-138h]
  float v33; // [esp+38h] [ebp-110h]
  float v34; // [esp+3Ch] [ebp-10Ch]
  float v35; // [esp+40h] [ebp-108h]
  float v36; // [esp+44h] [ebp-104h]
  float v37; // [esp+54h] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+58h] [ebp-F0h] BYREF
  std::wstring s; // [esp+108h] [ebp-40h] BYREF
  std::wstring result; // [esp+120h] [ebp-28h] BYREF
  int v41; // [esp+144h] [ebp-4h]

  v8 = position;
  v9 = this->game->graphics->gl;
  v34 = y + 3.0;
  v35 = (float)(x + 170.0) + 5.0;
  v37 = (float)(x + 25.0) + 7.0;
  v36 = (float)(x + 170.0) - 22.0;
  v33 = y + 5.0;
  if ( position % 2 )
    GLRenderer::color4f(v9, 0.050000001, 0.050000001, 0.050000001, 0.80000001);
  else
    GLRenderer::color4f(v9, 0.1, 0.1, 0.1, 0.60000002);
  GLRenderer::quad(v9, x, y, 25.0, 25.0, 0, 0);
  GLRenderer::quad(v9, x + 26.0, y, 43.0, 25.0, 0, 0);
  GLRenderer::quad(v9, x + 70.0, y, 110.0, 25.0, 0, 0);
  v10 = this->maxSectorsSize;
  if ( v10 > 0.0 )
  {
    v11 = this->game->graphics->gl;
    r = (vec4f)_mm_loadu_si128((const __m128i *)&this->backColor);
    v12 = CarAvatar::getGuid(entry->car);
    MicroSectors::drawSectors(this->sim->microSectors, v11, v12, x, y + 25.0, 180.0, v10, r);
  }
  v13 = &entry->car->driverInfo;
  v14 = CarAvatar::getGuid(entry->car);
  v15 = v13->name._Mysize;
  v16 = &this->driverNames._Myfirst[v14];
  if ( v13->name._Myres >= 8 )
    v13 = (DriverInfo *)v13->name._Bx._Ptr;
  if ( std::wstring::compare(&v16->completeName, 0, v16->completeName._Mysize, v13->name._Bx._Buf, v15) )
  {
    v17 = OverlayLeaderboard::filterName(this, &result, &entry->car->driverInfo.name);
    v18 = entry->car;
    v41 = 0;
    v19 = &this->driverNames._Myfirst[CarAvatar::getGuid(v18)].shortName;
    if ( v19 != v17 )
    {
      if ( v19->_Myres >= 8 )
        operator delete(v19->_Bx._Ptr);
      v19->_Myres = 7;
      v19->_Mysize = 0;
      v19->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(v19, v17);
    }
    v41 = -1;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v20 = &entry->car->driverInfo;
    v21 = &this->driverNames._Myfirst[CarAvatar::getGuid(entry->car)];
    if ( v21 != (OverlayLeaderboard::DriverName *)v20 )
      std::wstring::assign(&v21->completeName, &v20->name, 0, 0xFFFFFFFF);
    v8 = position;
  }
  v22 = Sim::getCar(this->sim, 0);
  v23 = this->nameFont._Ptr;
  if ( entry->car == v22 )
    Font::setColor(v23, 1.0, 0.80000001, 0.0, 1.0);
  else
    Font::setColor(v23, 1.0, 1.0, 1.0, 1.0);
  *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(ws.gap68);
  v41 = 1;
  std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
  v41 = 2;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v37 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&ws.gap10[8]);
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&ws.gap10[64] = 0;
  *(_DWORD *)&ws.gap10[68] = 0;
  v41 = 4;
  std::wostream::operator<<(ws.gap10, v8);
  v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ws, &result);
  v25 = this->nameFont._Ptr;
  LOBYTE(v41) = 5;
  Font::blitString(v25, (float)(x + 7.0) + 5.0, v34, v24, 1.0, eAlignCenter);
  LOBYTE(v41) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v26 = CarAvatar::getGuid(entry->car);
  Font::blitString(this->nameFont._Ptr, v37, v34, &this->driverNames._Myfirst[v26].shortName, 1.0, eAlignLeft);
  if ( ses_type == Race && ((v27 = this->gapDisplayMode, v27 == 2) || v27 == 3 && this->timer < 0.0) )
    Font::setColor(this->timeFont._Ptr, 1.0, 0.80000001, 0.0, 1.0);
  else
    Font::setColor(this->timeFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  if ( entry->car->isBlackFlagged )
  {
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    std::wstring::assign(&s, L"Retired", 7u);
    v28 = this->timeFont._Ptr;
    LOBYTE(v41) = 6;
    Font::blitString(v28, v36, v33, &s, 1.0, eAlignRight);
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
  }
  else
  {
    if ( CarAvatar::isInPitlane(entry->car) )
    {
      std::wstring::wstring(&s, L" PIT");
      v29 = this->timeFont._Ptr;
      LOBYTE(v41) = 7;
      Font::blitString(v29, v35, v33, &s, 0.80000001, eAlignRight);
      LOBYTE(v41) = 4;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
    }
    else
    {
      v30 = CarAvatar::getCurrentCompoundShortName(entry->car, &s);
      v31 = this->timeFont._Ptr;
      LOBYTE(v41) = 8;
      Font::blitString(v31, v35, v33, v30, 0.80000001, eAlignRight);
      LOBYTE(v41) = 4;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
      s._Myres = 7;
      s._Mysize = 0;
      s._Bx._Buf[0] = 0;
    }
    Font::blitString(this->timeFont._Ptr, v36, v33, time, 1.0, eAlignRight);
  }
  v41 = -1;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v37 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&ws.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ws.gap68);
}
std::wstring *OverlayLeaderboard::filterName(OverlayLeaderboard *this, std::wstring *result, const std::wstring *originalName)
{
  std::wstring *v4; // esi
  std::wstring *v5; // esi
  std::wstring *v6; // esi
  std::wstring *v7; // esi
  unsigned int v8; // ecx
  std::wstring *v9; // esi
  std::wstring *v10; // edx
  wchar_t *v11; // eax
  std::wstring *v12; // ecx
  OverlayLeaderboard::DriverName *v13; // eax
  unsigned int v14; // ebp
  std::wstring *v15; // ebx
  int v16; // esi
  std::wstring *v17; // esi
  wchar_t *v18; // ecx
  wchar_t v19; // ax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v23; // [esp+18h] [ebp-60h] BYREF
  std::wstring *v24; // [esp+1Ch] [ebp-5Ch]
  std::wstring filtered; // [esp+20h] [ebp-58h] BYREF
  std::wstring seq; // [esp+38h] [ebp-40h] BYREF
  std::wstring v27; // [esp+50h] [ebp-28h] BYREF
  int v28; // [esp+74h] [ebp-4h]

  filtered._Bx._Buf[0] = 0;
  v28 = 0;
  v24 = result;
  filtered._Myres = 7;
  filtered._Mysize = 0;
  std::wstring::assign(&filtered, originalName, 0, 0xFFFFFFFF);
  v28 = 1;
  seq._Myres = 7;
  seq._Mysize = 0;
  seq._Bx._Buf[0] = 0;
  std::wstring::assign(&seq, L" ", 1u);
  LOBYTE(v28) = 2;
  v4 = filterRemovingFromSequence(&v27, &filtered, &seq);
  if ( &filtered != v4 )
  {
    if ( filtered._Myres >= 8 )
      operator delete(filtered._Bx._Ptr);
    filtered._Myres = 7;
    filtered._Mysize = 0;
    filtered._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&filtered, v4);
  }
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  LOBYTE(v28) = 1;
  if ( seq._Myres >= 8 )
    operator delete(seq._Bx._Ptr);
  seq._Myres = 7;
  seq._Mysize = 0;
  seq._Bx._Buf[0] = 0;
  std::wstring::assign(&seq, L".", 1u);
  LOBYTE(v28) = 3;
  v5 = filterRemovingFromSequence(&v27, &filtered, &seq);
  if ( &filtered != v5 )
  {
    if ( filtered._Myres >= 8 )
      operator delete(filtered._Bx._Ptr);
    filtered._Myres = 7;
    filtered._Mysize = 0;
    filtered._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&filtered, v5);
  }
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  LOBYTE(v28) = 1;
  if ( seq._Myres >= 8 )
    operator delete(seq._Bx._Ptr);
  seq._Myres = 7;
  seq._Mysize = 0;
  seq._Bx._Buf[0] = 0;
  std::wstring::assign(&seq, L"'", 1u);
  LOBYTE(v28) = 4;
  v6 = filterRemovingFromSequence(&v27, &filtered, &seq);
  if ( &filtered != v6 )
  {
    if ( filtered._Myres >= 8 )
      operator delete(filtered._Bx._Ptr);
    filtered._Myres = 7;
    filtered._Mysize = 0;
    filtered._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&filtered, v6);
  }
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  LOBYTE(v28) = 1;
  if ( seq._Myres >= 8 )
    operator delete(seq._Bx._Ptr);
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &filtered, 0, 0xFFFFFFFF);
  if ( result->_Mysize > 3 )
  {
    v7 = std::wstring::substr(result, &v27, 0, 3u);
    if ( result != v7 )
    {
      if ( result->_Myres >= 8 )
        operator delete(result->_Bx._Ptr);
      result->_Myres = 7;
      result->_Mysize = 0;
      result->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(result, v7);
    }
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
  }
  v8 = result->_Myres;
  if ( v8 < 8 )
    v9 = result;
  else
    v9 = (std::wstring *)result->_Bx._Ptr;
  if ( v8 < 8 )
    v10 = result;
  else
    v10 = (std::wstring *)result->_Bx._Ptr;
  v11 = &v10->_Bx._Buf[result->_Mysize];
  if ( v8 < 8 )
    v12 = result;
  else
    v12 = (std::wstring *)result->_Bx._Ptr;
  if ( v12 != (std::wstring *)v11 )
    std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
      &v23,
      v12->_Bx._Buf,
      v11,
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v9,
      _toupper);
  v13 = std::_Find_if<OverlayLeaderboard::DriverName *,_lambda_c6f1ae9e54357b5dfec37025f30fac03_>(
          this->driverNames._Myfirst,
          this->driverNames._Mylast,
          (OverlayLeaderboard::filterName::__l6::<lambda_c6f1ae9e54357b5dfec37025f30fac03>)result);
  if ( v13 != this->driverNames._Mylast )
  {
    v14 = 3;
    v15 = &v13->shortName;
    while ( 1 )
    {
      v16 = (int)(v15->_Myres < 8 ? v15 : v15->_Bx._Ptr);
      if ( *(_WORD *)(v16 + 4) != *std::wstring::operator[](result, 2u) || v14 >= filtered._Mysize )
        break;
      v17 = &filtered;
      if ( filtered._Myres >= 8 )
        v17 = (std::wstring *)filtered._Bx._Ptr;
      v18 = std::wstring::operator[](result, 2u);
      v19 = v17->_Bx._Buf[v14++];
      *v18 = v19;
    }
    v20 = result->_Myres < 8 ? result : result->_Bx._Ptr;
    if ( !std::wstring::compare(v15, 0, v15->_Mysize, v20->_Bx._Buf, result->_Mysize) )
    {
      if ( result->_Myres < 8 )
        v21 = result;
      else
        v21 = (std::wstring *)result->_Bx._Ptr;
      v21->_Bx._Buf[2] = 50;
    }
  }
  if ( filtered._Myres >= 8 )
    operator delete(filtered._Bx._Ptr);
  return result;
}
void OverlayLeaderboard::renderHUD(OverlayLeaderboard *this, float dt)
{
  Sim *v3; // ecx
  Sim *v4; // ecx
  EndSessionDisplayer *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  LeaderboardEntry *v9; // edi
  LeaderboardEntry *i; // esi
  OverlayLeaderboard *v11; // edi
  float v12; // xmm0_4
  Game *v13; // ecx
  ksgui::GUI *v14; // eax
  float v15; // xmm0_4
  GraphicsManager *v16; // eax
  GLRenderer *v17; // esi
  SessionType v18; // esi
  int v19; // eax
  const std::wstring *v20; // eax
  const std::wstring *v21; // eax
  Game *v22; // ecx
  float v23; // xmm0_4
  Sim *v24; // ecx
  CarAvatar *v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  int v28; // ecx
  SessionType v29; // ecx
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm3_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  int v35; // edx
  int v36; // esi
  OverlayLeaderboard::GapMode v37; // eax
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  bool v41; // cc
  std::wstring *v42; // eax
  int v43; // [esp+24h] [ebp-90h]
  float v44; // [esp+30h] [ebp-84h]
  std::vector<LeaderboardEntry> result; // [esp+34h] [ebp-80h] BYREF
  float v46; // [esp+40h] [ebp-74h]
  float v47; // [esp+44h] [ebp-70h]
  float width; // [esp+48h] [ebp-6Ch]
  SessionType ses_type; // [esp+4Ch] [ebp-68h]
  int v50; // [esp+50h] [ebp-64h]
  OverlayLeaderboard *v51; // [esp+54h] [ebp-60h]
  int position; // [esp+58h] [ebp-5Ch]
  float v53; // [esp+5Ch] [ebp-58h]
  std::vector<LeaderboardEntry> v54; // [esp+60h] [ebp-54h] BYREF
  int v55; // [esp+6Ch] [ebp-48h]
  char v56; // [esp+73h] [ebp-41h]
  std::wstring v57; // [esp+74h] [ebp-40h] BYREF
  std::wstring time; // [esp+8Ch] [ebp-28h] BYREF
  int v59; // [esp+B0h] [ebp-4h]

  v51 = this;
  if ( this->gapDisplayMode == Off )
    return;
  v3 = this->sim;
  if ( v3->escMenu->visible )
    return;
  if ( v3->pauseMenu->visible )
    return;
  if ( ReplayManager::isInReplaymode(v3->replayManager) )
    return;
  v4 = this->sim;
  v5 = v4->endSessionDisplayer;
  if ( v5 )
  {
    if ( v5->isActive )
      return;
  }
  v6 = this->timer - dt;
  v7 = this->maxTimer;
  LODWORD(v8) = LODWORD(this->maxTimer) ^ _xmm;
  this->timer = v6;
  if ( v8 > v6 )
    this->timer = v7;
  RaceManager::getLeaderboard(v4->raceManager, &result);
  v59 = 1;
  v54._Myfirst = 0;
  v54._Mylast = 0;
  v54._Myend = 0;
  v9 = result._Mylast;
  for ( i = result._Myfirst; i != v9; ++i )
  {
    if ( CarAvatar::isConnected(i->car) )
      std::vector<LeaderboardEntry>::push_back(&v54, i);
  }
  v11 = v51;
  v12 = FLOAT_40_0;
  if ( v51->verticalLayout )
    v12 = FLOAT_25_0;
  v13 = v51->game;
  v14 = v13->gui;
  v53 = v12 + v51->maxSectorsSize;
  v15 = v14->taskbar->rect.left - 1.0;
  v16 = v13->graphics;
  v17 = v16->gl;
  width = v15;
  v47 = (float)((float)v16->videoSettings.height - 150.0) - 200.0;
  GLRenderer::color4f(v17, &v51->backColor);
  if ( !v11->verticalLayout )
    GLRenderer::quad(
      v17,
      0.0,
      (float)v11->game->graphics->videoSettings.height - v53,
      width,
      v53 - v11->maxSectorsSize,
      0,
      0);
  v18 = RaceManager::getCurrentSessionType(v11->sim->raceManager);
  v19 = 0;
  ses_type = v18;
  v50 = 0;
  if ( v18 > Undefined )
  {
    if ( v18 <= Qualify )
    {
      v19 = (int)v54._Myfirst->bestLap;
      goto LABEL_22;
    }
    if ( v18 == Race )
    {
      v19 = (int)v54._Myfirst->totalTime;
LABEL_22:
      v50 = v19;
      goto LABEL_23;
    }
  }
LABEL_23:
  if ( v11->verticalLayout )
  {
    v20 = timeToString(&time, v19, 3);
    LOBYTE(v59) = 2;
    OverlayLeaderboard::drawVerticalCell(v11, v54._Myfirst, 1, v20, 1.0, 150.0, v18);
  }
  else
  {
    v21 = timeToString(&time, v19, 3);
    v22 = v11->game;
    LOBYTE(v59) = 3;
    OverlayLeaderboard::drawCell(v11, v54._Myfirst, 1, v21, 0.0, (float)v22->graphics->videoSettings.height - v53, v18);
  }
  LOBYTE(v59) = 1;
  if ( time._Myres >= 8 )
    operator delete(time._Bx._Ptr);
  if ( v11->verticalLayout )
    v23 = (float)(v47 - v53) / v53;
  else
    v23 = (float)(width - 170.0) * 0.0058823531;
  v24 = v11->sim;
  v55 = (int)(float)(v23 - 1.0);
  v25 = Sim::getCar(v24, 0);
  v26 = RaceManager::getCarLeaderboardPosition(v11->sim->raceManager, v25);
  v51 = (OverlayLeaderboard *)(v54._Mylast - v54._Myfirst - 1);
  v27 = v26 - 1 + v55 / 2;
  if ( v27 <= (int)v51 )
  {
    if ( v27 < 1 )
      v27 = 1;
  }
  else
  {
    v27 = v54._Mylast - v54._Myfirst - 1;
  }
  v28 = v27 - v55;
  if ( v27 - v55 <= v27 )
  {
    v27 -= v55;
    if ( v28 < 1 )
      v27 = 1;
  }
  v29 = ses_type;
  if ( ses_type == Pratice || (v56 = 0, ses_type == Qualify) )
    v56 = 1;
  if ( v27 <= (int)v51 )
  {
    v30 = v53;
    v31 = FLOAT_1_0;
    v32 = FLOAT_150_0;
    v33 = v53 + 1.0;
    position = v27 + 1;
    v34 = v53 + 150.0;
    v35 = 32 * v27;
    v55 = 32 * v27;
    v46 = v53 + 1.0;
    v43 = -1 - v27;
    v44 = v53 + 150.0;
    while ( 1 )
    {
      v36 = 0;
      if ( v29 > Undefined )
      {
        if ( v29 <= Qualify )
        {
          v36 = (int)*(double *)((char *)&v54._Myfirst->bestLap + v35) - v50;
        }
        else
        {
          if ( v29 != Race )
            goto LABEL_61;
          v37 = v11->gapDisplayMode;
          if ( v37 == On || v37 == 3 && v11->timer >= 0.0 )
          {
            if ( *(int *)((char *)&v54._Myfirst->laps + v35) != v54._Myfirst->laps )
              goto LABEL_61;
            v36 = (int)(*(double *)((char *)&v54._Myfirst->totalTime + v35) - (double)v50);
          }
          else
          {
            if ( v37 != 2 && (v37 != 3 || v11->timer >= 0.0)
              || *(int *)((char *)&v54._Myfirst->laps + v35) != *(_DWORD *)((char *)v54._Myfirst + v35 - 8) )
            {
              goto LABEL_61;
            }
            v36 = (int)(*(double *)((char *)&v54._Myfirst->totalTime + v35)
                      - *(double *)((char *)v54._Myfirst + v35 - 24));
          }
        }
        if ( v36 <= 99999999 )
        {
          if ( v36 < 0 )
            v36 = 0;
        }
        else
        {
          v36 = 99999999;
        }
      }
LABEL_61:
      v38 = (float)(v43 + position);
      v39 = (float)(v38 + v31) * 170.0;
      v40 = (float)((float)(v38 * v33) + v34) + v31;
      if ( v11->verticalLayout )
        v41 = (float)(v40 + v30) <= (float)(v47 + v32);
      else
        v41 = (float)(v39 + 170.0) <= width;
      if ( !v41 )
        break;
      if ( CarAvatar::isConnected(*(CarAvatar **)((char *)&v54._Myfirst->car + v35)) )
      {
        time._Myres = 7;
        time._Mysize = 0;
        time._Bx._Buf[0] = 0;
        LOBYTE(v59) = 4;
        if ( v56 )
          v42 = timeToDiff_Secs_3Millis(&v57, v36);
        else
          v42 = timeToDiffShort(&v57, v36);
        std::wstring::operator=(&time, v42);
        if ( v57._Myres >= 8 )
          operator delete(v57._Bx._Ptr);
        if ( v11->verticalLayout )
          OverlayLeaderboard::drawVerticalCell(
            v11,
            (const LeaderboardEntry *)((char *)v54._Myfirst + v55),
            position,
            &time,
            1.0,
            v40,
            ses_type);
        else
          OverlayLeaderboard::drawCell(
            v11,
            (const LeaderboardEntry *)((char *)v54._Myfirst + v55),
            position,
            &time,
            v39,
            (float)v11->game->graphics->videoSettings.height - v53,
            ses_type);
        LOBYTE(v59) = 1;
        if ( time._Myres >= 8 )
          operator delete(time._Bx._Ptr);
      }
      ++position;
      v35 = v55 + 32;
      v55 += 32;
      if ( position - 1 > (int)v51 )
        break;
      v32 = FLOAT_150_0;
      v30 = v53;
      v31 = FLOAT_1_0;
      v33 = v46;
      v34 = v44;
      v29 = ses_type;
    }
  }
  LOBYTE(v59) = 0;
  if ( v54._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v54);
    operator delete(v54._Myfirst);
    v54._Myfirst = 0;
    v54._Mylast = 0;
    v54._Myend = 0;
  }
  v59 = -1;
  if ( result._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&result);
    operator delete(result._Myfirst);
  }
}
void OverlayLeaderboard::shutdown(OverlayLeaderboard *this)
{
  std::wstring *v2; // eax
  std::wstring *v3; // ecx
  int v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // ecx
  OverlayLeaderboard::GapMode v7; // [esp+4h] [ebp-108h]
  BOOL v8; // [esp+4h] [ebp-108h]
  int v9; // [esp+18h] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+1Ch] [ebp-F0h] BYREF
  std::wstring path; // [esp+CCh] [ebp-40h] BYREF
  std::wstring result; // [esp+E4h] [ebp-28h] BYREF
  int v13; // [esp+108h] [ebp-4h]

  Path::getDocumentPath(&path);
  v13 = 0;
  std::wstring::append(&path, L"/Assetto Corsa/cfg/gameplay.ini", 0x1Fu);
  *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(ws.gap68);
  LOBYTE(v13) = 1;
  v9 = 1;
  std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
  v13 = 2;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v9 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&ws.gap10[8]);
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&ws.gap10[64] = 0;
  *(_DWORD *)&ws.gap10[68] = 0;
  v7 = this->gapDisplayMode;
  LOBYTE(v13) = 4;
  std::wostream::operator<<(ws.gap10, v7);
  v2 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ws, &result);
  v3 = &path;
  if ( path._Myres >= 8 )
    v3 = (std::wstring *)path._Bx._Ptr;
  if ( v2->_Myres >= 8 )
    v2 = (std::wstring *)v2->_Bx._Ptr;
  WritePrivateProfileStringW(L"OVERLAY_LEADERBOARD", L"ACTIVE", v2->_Bx._Buf, v3->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v13) = 0;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v9 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&ws.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ws.gap68);
  *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(ws.gap68);
  LOBYTE(v13) = 5;
  v9 = 3;
  std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
  v13 = 6;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v9 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&ws.gap10[8]);
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&ws.gap10[64] = 0;
  *(_DWORD *)&ws.gap10[68] = 0;
  v8 = this->verticalLayout;
  LOBYTE(v13) = 8;
  v4 = std::wostream::operator<<(ws.gap10, v8);
  std::ios_base::operator bool(v4 + *(_DWORD *)(*(_DWORD *)v4 + 4));
  v5 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ws, &result);
  v6 = &path;
  if ( path._Myres >= 8 )
    v6 = (std::wstring *)path._Bx._Ptr;
  if ( v5->_Myres >= 8 )
    v5 = (std::wstring *)v5->_Bx._Ptr;
  WritePrivateProfileStringW(L"OVERLAY_LEADERBOARD", L"VERTICAL", v5->_Bx._Buf, v6->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v13) = 0;
  *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v9 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
  *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&ws.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ws.gap68);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
}
void OverlayLeaderboard::update(OverlayLeaderboard *this, float dt)
{
  SHORT v3; // ax
  Sim *v4; // ecx
  Sim *v5; // ecx
  Sim *v6; // ecx
  Sim *v7; // ecx
  Sim *v8; // ecx
  Sim *v9; // ecx
  std::wstring v10; // [esp+8h] [ebp-130h] BYREF
  std::wstring v11; // [esp+20h] [ebp-118h] BYREF
  std::wstring v12; // [esp+38h] [ebp-100h] BYREF
  std::wstring v13; // [esp+50h] [ebp-E8h] BYREF
  std::wstring description; // [esp+68h] [ebp-D0h] BYREF
  std::wstring v15; // [esp+80h] [ebp-B8h] BYREF
  std::wstring imessage; // [esp+98h] [ebp-A0h] BYREF
  std::wstring v17; // [esp+B0h] [ebp-88h] BYREF
  std::wstring v18; // [esp+C8h] [ebp-70h] BYREF
  std::wstring v19; // [esp+E0h] [ebp-58h] BYREF
  std::wstring v20; // [esp+F8h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v21; // [esp+110h] [ebp-28h] BYREF
  int v22; // [esp+134h] [ebp-4h]

  v3 = GetAsyncKeyState(120);
  if ( Trigger::ignoreSubsequentTrue(&this->keySwitchMode, v3 != 0) )
  {
    switch ( this->gapDisplayMode )
    {
      case 0:
        this->gapDisplayMode = On;
        this->verticalLayout = 0;
        std::wstring::wstring(&v21.name, L"Showing difference from first");
        v22 = 8;
        std::wstring::wstring(&v19, L"Overlay Leaderboard");
        v8 = this->sim;
        LOBYTE(v22) = 9;
        SystemMessage::addMessage(v8->systemMessage, &v19, &v21.name, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v19);
        std::wstring::~wstring(&v21);
        break;
      case 1:
        this->gapDisplayMode = 2;
        std::wstring::wstring(&description, L"Showing difference from previous");
        v22 = 0;
        std::wstring::wstring(&imessage, L"Overlay Leaderboard");
        v4 = this->sim;
        LOBYTE(v22) = 1;
        SystemMessage::addMessage(v4->systemMessage, &imessage, &description, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&imessage);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
        break;
      case 2:
        this->gapDisplayMode = 3;
        std::wstring::wstring(&v12, L"Alternate mode");
        v22 = 2;
        std::wstring::wstring(&v18, L"Overlay Leaderboard");
        v5 = this->sim;
        LOBYTE(v22) = 3;
        SystemMessage::addMessage(v5->systemMessage, &v18, &v12, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v18);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v12);
        break;
      case 3:
        if ( this->verticalLayout )
        {
          this->gapDisplayMode = Off;
          this->verticalLayout = 0;
          std::wstring::wstring(&v13, L"Off");
          v22 = 4;
          std::wstring::wstring(&v20, L"Overlay Leaderboard");
          v6 = this->sim;
          LOBYTE(v22) = 5;
          SystemMessage::addMessage(v6->systemMessage, &v20, &v13, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v20);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v13);
        }
        else
        {
          this->gapDisplayMode = On;
          this->verticalLayout = 1;
          std::wstring::wstring(&v17, L"Showing difference from first");
          v22 = 6;
          std::wstring::wstring(&v15, L"Overlay Leaderboard");
          v7 = this->sim;
          LOBYTE(v22) = 7;
          SystemMessage::addMessage(v7->systemMessage, &v15, &v17, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v15);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v17);
        }
        break;
      default:
        this->gapDisplayMode = 3;
        std::wstring::wstring(&v11, L"Alternate mode");
        v22 = 10;
        std::wstring::wstring(&v10, L"Overlay Leaderboard");
        v9 = this->sim;
        LOBYTE(v22) = 11;
        SystemMessage::addMessage(v9->systemMessage, &v10, &v11, eDefault);
        if ( v10._Myres >= 8 )
          operator delete(v10._Bx._Ptr);
        v10._Myres = 7;
        v10._Mysize = 0;
        v10._Bx._Buf[0] = 0;
        if ( v11._Myres >= 8 )
          operator delete(v11._Bx._Ptr);
        break;
    }
  }
}
