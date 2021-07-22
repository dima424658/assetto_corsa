#include "gamemode.h"
void GameMode::GameMode(GameMode *this, std::wstring name, Game *aGame)
{
  int v4; // ebx
  std::wstring *v5; // edi
  char v6; // al
  unsigned int v7; // ebx
  std::wostream *v8; // eax
  std::wostream *v9; // eax
  const std::wstring *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // esi
  const std::wstring *v13; // eax
  std::vector<char> *v14; // eax
  const std::wstring *v15; // eax
  bool v16; // al
  int v17; // esi
  std::wstring *v18; // eax
  std::wostream *v19; // eax
  std::vector<GameMode::ConditionDef> *v20; // ebp
  const std::wstring *v21; // eax
  bool v22; // bl
  const std::wstring *v23; // eax
  GameMode::ConditionDef *v24; // edi
  const std::wstring *v25; // eax
  const std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wostream *v28; // eax
  std::wstring v29; // [esp-1Ch] [ebp-410h] BYREF
  int v30; // [esp-4h] [ebp-3F8h]
  bool v31; // [esp+23h] [ebp-3D1h] BYREF
  int v32; // [esp+24h] [ebp-3D0h]
  std::vector<std::wstring> sections; // [esp+28h] [ebp-3CCh] BYREF
  std::vector<GameMode::ConditionDef> *v34; // [esp+34h] [ebp-3C0h]
  Game *v35; // [esp+38h] [ebp-3BCh]
  GameMode *v36; // [esp+3Ch] [ebp-3B8h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v37; // [esp+40h] [ebp-3B4h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ssINI; // [esp+F0h] [ebp-304h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v39; // [esp+1A0h] [ebp-254h] BYREF
  std::wstring key; // [esp+250h] [ebp-1A4h] BYREF
  std::wstring section; // [esp+268h] [ebp-18Ch] BYREF
  std::wstring v42; // [esp+280h] [ebp-174h] BYREF
  std::wstring v43; // [esp+298h] [ebp-15Ch] BYREF
  GameMode::ConditionDef condition; // [esp+2B0h] [ebp-144h] BYREF
  std::wstring result; // [esp+2E8h] [ebp-10Ch] BYREF
  std::wstring v46; // [esp+300h] [ebp-F4h] BYREF
  INIReader ini; // [esp+318h] [ebp-DCh] BYREF
  INIReader newINI; // [esp+35Ch] [ebp-98h] BYREF
  INIReaderDocuments documentsRaceINI; // [esp+3A0h] [ebp-54h] BYREF
  int v50; // [esp+3ECh] [ebp-8h]
  int v51; // [esp+3F0h] [ebp-4h]
  void *retaddr; // [esp+3F4h] [ebp+0h]

  v36 = this;
  v4 = 0;
  v35 = (Game *)this;
  v32 = 0;
  v30 = (int)aGame;
  v51 = 0;
  v29._Myres = 7;
  v29._Mysize = 0;
  v29._Bx._Buf[0] = 0;
  std::wstring::assign(&v29, &name, 0, 0xFFFFFFFF);
  GameObject::GameObject(this, v29, (Game *)v30);
  this->__vftable = (GameMode_vtbl *)&GameMode::`vftable';
  this->evOnTierCompleted.handlers._Myfirst = 0;
  this->evOnTierCompleted.handlers._Mylast = 0;
  this->evOnTierCompleted.handlers._Myend = 0;
  this->evOnLeaderboardScore.handlers._Myfirst = 0;
  this->evOnLeaderboardScore.handlers._Mylast = 0;
  this->evOnLeaderboardScore.handlers._Myend = 0;
  v5 = &this->guid;
  this->guid._Myres = 7;
  this->guid._Mysize = 0;
  this->guid._Bx._Buf[0] = 0;
  this->conditions._Myfirst = 0;
  v34 = &this->conditions;
  this->conditions._Mylast = 0;
  this->conditions._Myend = 0;
  v30 = 0;
  this->valid = 1;
  this->currentTier = -1;
  LOBYTE(v51) = 5;
  v29._Myres = 7;
  v29._Mysize = 0;
  v29._Bx._Buf[0] = 0;
  std::wstring::assign(&v29, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&documentsRaceINI, 0, v29, v30);
  LOBYTE(v51) = 6;
  INIReader::INIReader(&ini, &documentsRaceINI);
  LOBYTE(v51) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SPECIAL_EVENT", 0xDu);
  LOBYTE(v51) = 8;
  v6 = INIReader::hasSection(&ini, &section);
  v31 = v6;
  LOBYTE(v51) = 7;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v6 = v31;
  }
  if ( v6 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GUID", 4u);
    LOBYTE(v51) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SPECIAL_EVENT", 0xDu);
    LOBYTE(v51) = 10;
    v7 = INIReader::getInt(&ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v51) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    *(_DWORD *)v37.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v37.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v37.gap68);
    LOBYTE(retaddr) = 11;
    sections._Myfirst = (std::wstring *)8;
    std::wiostream::basic_iostream<wchar_t>(&v37.gap0[4], &v37.gap10[12], 0);
    v50 = 12;
    *(GameMode **)((char *)&v36 + (unsigned int)v36->game) = (GameMode *)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(char **)((char *)&v35 + (unsigned int)v36->game) = (char *)v36->game - 104;
    std::wstreambuf::wstreambuf(&v37.gap10[4]);
    *(_DWORD *)&v37.gap10[4] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v37.gap10[60] = 0;
    *(_DWORD *)&v37.gap10[64] = 0;
    v29._Myres = (unsigned int)".acd";
    v29._Mysize = v7;
    LOBYTE(v50) = 14;
    v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
           (std::wostream *)((char *)&v37._Chcount + 4),
           "system/data/se/SPECIAL_EVENT_");
    v9 = (std::wostream *)std::wostream::operator<<(v8, v29._Mysize);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v9, (const char *)v30);
    *(_DWORD *)ssINI.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)ssINI.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(ssINI.gap68);
    LOBYTE(v51) = 15;
    v32 = 24;
    std::wiostream::basic_iostream<wchar_t>(&ssINI, &ssINI.gap10[8], 0);
    v51 = 16;
    *(_DWORD *)&ssINI.gap0[*(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v37.gap68[*(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&ssINI.gap10[8]);
    *(_DWORD *)&ssINI.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&ssINI.gap10[64] = 0;
    *(_DWORD *)&ssINI.gap10[68] = 0;
    LOBYTE(v51) = 18;
    v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &result);
    LOBYTE(v51) = 19;
    v11 = Path::getFileNameWithoutExtension(&v42, v10);
    LOBYTE(v51) = 20;
    v12 = std::operator+<wchar_t>(&v43, L"ARUMBA_", v11);
    LOBYTE(v51) = 21;
    v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &v46);
    LOBYTE(v51) = 22;
    v14 = SimpleFileEncrypter::decryptFile((unsigned int)v5, (std::vector<char> *)&section, v13, v12);
    LOBYTE(v51) = 23;
    v15 = ksDecodeUtf8(&key, v14);
    LOBYTE(v51) = 24;
    std::operator<<<wchar_t>((std::wostream *)ssINI.gap10, v15);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v51) = 22;
    if ( section._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&section);
      operator delete(section._Bx._Ptr);
      *(_QWORD *)section._Bx._Buf = 0i64;
      *(_DWORD *)&section._Bx._Alias[8] = 0;
    }
    if ( v46._Myres >= 8 )
      operator delete(v46._Bx._Ptr);
    v46._Myres = 7;
    v46._Mysize = 0;
    v46._Bx._Buf[0] = 0;
    if ( v43._Myres >= 8 )
      operator delete(v43._Bx._Ptr);
    v43._Myres = 7;
    v43._Mysize = 0;
    v43._Bx._Buf[0] = 0;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    LOBYTE(v51) = 18;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    INIReader::INIReader(&newINI, &ssINI);
    sections._Myfirst = 0;
    sections._Mylast = 0;
    sections._Myend = 0;
    LOBYTE(v51) = 26;
    newINI.ready = 1;
    std::wstring::wstring(&v42, L"GUID");
    LOBYTE(v51) = 27;
    v32 = 25;
    std::wstring::wstring(&key, L"SPECIAL_EVENT");
    v51 = 28;
    v32 = 27;
    v31 = v7 == INIReader::getInt(&newINI, &key, &v42);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    v51 = 26;
    v4 = 24;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    if ( v31 )
      INIReader::operator=(&ini, &newINI);
    else
      _printf("NOT LOADING OFFICIAL SPECIAL EVENT : ENCRIPTED INI IS NOT READY");
    LOBYTE(v51) = 25;
    if ( sections._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&sections);
      v30 = (int)v35;
      v29._Myres = (unsigned int)&v31;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(sections._Myfirst, sections._Mylast);
      operator delete(sections._Myfirst);
      sections._Myfirst = 0;
      sections._Mylast = 0;
      sections._Myend = 0;
    }
    LOBYTE(v51) = 18;
    INIReader::~INIReader(&newINI);
    LOBYTE(v51) = 14;
    *(_DWORD *)&ssINI.gap0[*(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v37.gap68[*(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4) - 104;
    *(_DWORD *)&ssINI.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&ssINI.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ssINI.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ssINI.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ssINI.gap68);
    LOBYTE(v51) = 7;
    *(_DWORD *)&v37.gap0[*(_DWORD *)(*(_DWORD *)v37.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(GameMode **)((char *)&v36 + *(_DWORD *)(*(_DWORD *)v37.gap0 + 4)) = (GameMode *)(*(_DWORD *)(*(_DWORD *)v37.gap0
                                                                                                 + 4)
                                                                                     - 104);
    *(_DWORD *)&v37.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v37.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v37.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v37.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v37.gap68);
  }
  if ( !ini.ready )
    goto LABEL_32;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SPECIAL_EVENT", 0xDu);
  LOBYTE(v51) = 29;
  v4 |= 4u;
  v32 = v4;
  v16 = INIReader::hasSection(&ini, &key);
  v31 = 1;
  if ( !v16 )
LABEL_32:
    v31 = 0;
  v51 = 7;
  if ( (v4 & 4) != 0 )
  {
    v4 &= 0xFFFFFFFB;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( v31 )
  {
    key._Myres = 7;
    v17 = 0;
    key._Bx._Buf[0] = 0;
    key._Mysize = 0;
    std::wstring::assign(&key, L"GUID", 4u);
    LOBYTE(v51) = 30;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SPECIAL_EVENT", 0xDu);
    LOBYTE(v51) = 31;
    v18 = INIReader::getString(&ini, &v42, &section, &key);
    v32 = (int)v18;
    if ( v5 != v18 )
    {
      if ( this->guid._Myres >= 8 )
      {
        operator delete(v5->_Bx._Ptr);
        v18 = (std::wstring *)v32;
      }
      this->guid._Myres = 7;
      this->guid._Mysize = 0;
      v5->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->guid, v18);
    }
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v51) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    *(_DWORD *)v39.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v39.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v39.gap68);
    LOBYTE(v51) = 32;
    v32 = v4 | 0x20;
    std::wiostream::basic_iostream<wchar_t>(&v39, &v39.gap10[8], 0);
    v51 = 33;
    *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&ssINI.gap68[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v39.gap10[8]);
    *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v39.gap10[64] = 0;
    *(_DWORD *)&v39.gap10[68] = 0;
    v30 = 0;
    LOBYTE(v51) = 35;
    v19 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v39.gap10, "CONDITION_");
    std::wostream::operator<<(v19, v30);
    v20 = v34;
    while ( 1 )
    {
      v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &result);
      LOBYTE(v51) = 36;
      v22 = INIReader::hasSection(&ini, v21);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( !v22 )
        break;
      condition.type._Myres = 7;
      condition.type._Mysize = 0;
      condition.type._Bx._Buf[0] = 0;
      condition.name._Myres = 7;
      condition.name._Mysize = 0;
      condition.name._Bx._Buf[0] = 0;
      condition.objective = 0;
      condition.achieved = 0;
      LOBYTE(v51) = 37;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"TYPE", 4u);
      LOBYTE(v51) = 38;
      v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v43);
      LOBYTE(v51) = 39;
      v24 = (GameMode::ConditionDef *)INIReader::getString(&ini, &v42, v23, &key);
      if ( &condition != v24 )
      {
        if ( condition.type._Myres >= 8 )
          operator delete(condition.type._Bx._Ptr);
        condition.type._Myres = 7;
        condition.type._Mysize = 0;
        condition.type._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&condition.type, &v24->type);
      }
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v42._Myres = 7;
      v42._Mysize = 0;
      v42._Bx._Buf[0] = 0;
      if ( v43._Myres >= 8 )
        operator delete(v43._Bx._Ptr);
      v43._Myres = 7;
      v43._Mysize = 0;
      v43._Bx._Buf[0] = 0;
      LOBYTE(v51) = 37;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"OBJECTIVE", 9u);
      LOBYTE(v51) = 40;
      v25 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v42);
      LOBYTE(v51) = 41;
      condition.objective = INIReader::getInt(&ini, v25, &key);
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v42._Myres = 7;
      v42._Mysize = 0;
      v42._Bx._Buf[0] = 0;
      LOBYTE(v51) = 37;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      switch ( v17 )
      {
        case 0:
          std::wstring::assign(&condition.name, L"BRONZE");
          goto LABEL_72;
        case 1:
          std::wstring::assign(&condition.name, L"SILVER");
          goto LABEL_72;
        case 2:
          v30 = 4;
          v29._Myres = (unsigned int)L"GOLD";
          goto LABEL_71;
        case 3:
          v30 = 12;
          v29._Myres = (unsigned int)L"GOLDEN GLORY";
          goto LABEL_71;
        default:
          v30 = 5;
          v29._Myres = (unsigned int)L"MEDAL";
LABEL_71:
          std::wstring::assign(&condition.name, (const wchar_t *)v29._Myres, v30);
LABEL_72:
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"ACHIEVED", 8u);
          LOBYTE(v51) = 42;
          v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v42);
          LOBYTE(v51) = 43;
          condition.achieved = INIReader::getInt(&documentsRaceINI, v26, &key) > 0;
          if ( v42._Myres >= 8 )
            operator delete(v42._Bx._Ptr);
          v42._Myres = 7;
          v42._Mysize = 0;
          v42._Bx._Buf[0] = 0;
          LOBYTE(v51) = 37;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          std::vector<GameMode::ConditionDef>::push_back(v20, &condition);
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, word_17BE9D8, 0);
          LOBYTE(v51) = 44;
          std::wstringbuf::_Tidy((std::wstringbuf *)&v39.gap10[8]);
          v30 = *(_DWORD *)&v39.gap10[68];
          v27 = &section;
          v29._Myres = section._Mysize;
          if ( section._Myres >= 8 )
            v27 = (std::wstring *)section._Bx._Ptr;
          std::wstringbuf::_Init((std::wstringbuf *)&v39.gap10[8], v27->_Bx._Buf, v29._Myres, v30);
          LOBYTE(v51) = 37;
          if ( section._Myres >= 8 )
            operator delete(section._Bx._Ptr);
          v30 = ++v17;
          v28 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v39.gap10, "CONDITION_");
          std::wostream::operator<<(v28, v30);
          LOBYTE(v51) = 35;
          TrackData::~TrackData((ChatElement *)&condition);
          break;
      }
    }
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v39);
  }
  LOBYTE(v51) = 6;
  INIReader::~INIReader(&ini);
  LOBYTE(v51) = 5;
  INIReaderDocuments::~INIReaderDocuments(&documentsRaceINI);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void GameMode::~GameMode(GameMode *this)
{
  this->__vftable = (GameMode_vtbl *)&GameMode::`vftable';
  if ( this->conditions._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->conditions);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<GameMode::ConditionDef>>>(
      this->conditions._Myfirst,
      this->conditions._Mylast);
    operator delete(this->conditions._Myfirst);
    this->conditions._Myfirst = 0;
    this->conditions._Mylast = 0;
    this->conditions._Myend = 0;
  }
  if ( this->guid._Myres >= 8 )
    operator delete(this->guid._Bx._Ptr);
  this->guid._Myres = 7;
  this->guid._Mysize = 0;
  this->guid._Bx._Buf[0] = 0;
  if ( this->evOnLeaderboardScore.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnLeaderboardScore);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnLeaderboardScore,
      (Task *)this->evOnLeaderboardScore.handlers._Myfirst,
      (Task *)this->evOnLeaderboardScore.handlers._Mylast);
    operator delete(this->evOnLeaderboardScore.handlers._Myfirst);
    this->evOnLeaderboardScore.handlers._Myfirst = 0;
    this->evOnLeaderboardScore.handlers._Mylast = 0;
    this->evOnLeaderboardScore.handlers._Myend = 0;
  }
  if ( this->evOnTierCompleted.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnTierCompleted);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnTierCompleted,
      (Task *)this->evOnTierCompleted.handlers._Myfirst,
      (Task *)this->evOnTierCompleted.handlers._Mylast);
    operator delete(this->evOnTierCompleted.handlers._Myfirst);
    this->evOnTierCompleted.handlers._Myfirst = 0;
    this->evOnTierCompleted.handlers._Mylast = 0;
    this->evOnTierCompleted.handlers._Myend = 0;
  }
  GameObject::~GameObject(this);
}
GameMode *GameMode::`scalar deleting destructor'(GameMode *this, unsigned int a2)
{
  GameMode::~GameMode(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void GameMode::forceConditionAchieved(GameMode *this, int conditionIndex, bool achieved)
{
  if ( conditionIndex < (unsigned int)(this->conditions._Mylast - this->conditions._Myfirst) && conditionIndex >= 0 )
    this->conditions._Myfirst[conditionIndex].achieved = achieved;
}
void GameMode::setTier(GameMode *this, int aTier)
{
  int v3; // esi
  std::pair<void *,std::function<void __cdecl(SpecialEventAchievement const &)> > *v4; // esi
  std::_Func_base<void,SpecialEventAchievement const &> **v5; // edi
  std::wstring _Right; // [esp+10h] [ebp-44h] BYREF
  std::wstring v7; // [esp+28h] [ebp-2Ch] BYREF
  int v8; // [esp+40h] [ebp-14h]
  int v9; // [esp+50h] [ebp-4h]

  this->currentTier = aTier;
  _Right._Bx._Buf[0] = 0;
  _Right._Myres = 7;
  _Right._Mysize = 0;
  std::wstring::assign(&_Right, &this->guid, 0, 0xFFFFFFFF);
  v3 = this->currentTier;
  v9 = 0;
  v7._Bx._Buf[0] = 0;
  v7._Myres = 7;
  v7._Mysize = 0;
  std::wstring::assign(&v7, &_Right, 0, 0xFFFFFFFF);
  v8 = v3;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  _Right._Myres = 7;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  v4 = this->evOnTierCompleted.handlers._Myfirst;
  v9 = 1;
  if ( v4 != this->evOnTierCompleted.handlers._Mylast )
  {
    v5 = &v4->second._Impl;
    do
    {
      if ( !*v5 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x5B42D9);
      }
      (*v5)->_Do_call(*v5, (const SpecialEventAchievement *)&v7);
      ++v4;
      v5 += 8;
    }
    while ( v4 != this->evOnTierCompleted.handlers._Mylast );
  }
  if ( v7._Myres >= 8 )
    operator delete(v7._Bx._Ptr);
}
std::wstring *GameMode::getGUID(GameMode *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->guid, 0, 0xFFFFFFFF);
  return result;
}
